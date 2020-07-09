--
--	@(#) dbcreate/cfint/oracle/crrd_mjvrdefbysubprojectidx.plsql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	This file is part of MSS Code Factory.
--	
--	Licensed under the Apache License, Version 2.0 (the "License");
--	you may not use this file except in compliance with the License.
--	You may obtain a copy of the License at
--	
--	    http://www.apache.org/licenses/LICENSE-2.0
--	
--	Unless required by applicable law or agreed to in writing, software
--	distributed under the License is distributed on an "AS IS" BASIS,
--	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
--	See the License for the specific language governing permissions and
--	limitations under the License.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--
--	Manufactured by MSS Code Factory 2.12
--
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfinet213.rd_mjvrdefbysubprojectidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argSubProjectId numeric ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfinet213.sp_is_tenant_user( secTenantId,
			'ReadMajorVersion',
			argAuditUserId );
	isSystemUser := cfinet213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( isSystemUser = 1 )
	then
		open retCursor for select
			a102.createdby,
			to_char( a102.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a102.updatedby,
			to_char( a102.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a102.TenantId as TenantId,
			a102.Id as Id,
			a102.SubProjectId as SubProjectId,
			a102.safe_name as safe_name,
			a102.descr as descr,
			a102.revision as revision
		from cfinet213.mjvrdef a102
		where
			a102.TenantId = argTenantId
			and a102.SubProjectId = argSubProjectId
		order by TenantId desc,
			Id desc;
	else
		open retCursor for select
			a102.createdby,
			to_char( a102.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a102.updatedby,
			to_char( a102.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a102.TenantId as TenantId,
			a102.Id as Id,
			a102.SubProjectId as SubProjectId,
			a102.safe_name as safe_name,
			a102.descr as descr,
			a102.revision as revision
		from cfinet213.mjvrdef a102
		where
			a102.TenantId = argTenantId
			and a102.SubProjectId = argSubProjectId
			and a102.TenantId = secTenantId
		order by TenantId desc,
			Id desc;
	end if;
end rd_mjvrdefbysubprojectidx;
/

show errors procedure cfinet213.rd_mjvrdefbysubprojectidx;
