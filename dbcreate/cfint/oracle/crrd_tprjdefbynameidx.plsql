--
--	@(#) dbcreate/cfint/oracle/crrd_tprjdefbynameidx.plsql
--
--	com.github.msobkow.CFInt
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

create or replace procedure cfinet213.rd_tprjdefbynameidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argTopDomainId numeric,
	argsafe_name varchar2 ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfinet213.sp_is_tenant_user( secTenantId,
			'ReadTopProject',
			argAuditUserId );
	isSystemUser := cfinet213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( isSystemUser = 1 )
	then
		open retCursor for select
			a108.createdby,
			to_char( a108.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a108.updatedby,
			to_char( a108.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a108.TenantId as TenantId,
			a108.Id as Id,
			a108.TopDomainId as TopDomainId,
			a108.safe_name as safe_name,
			a108.descr as descr,
			a108.revision as revision
		from cfinet213.tprjdef a108
		where
			a108.TenantId = argTenantId
			and a108.TopDomainId = argTopDomainId
			and a108.safe_name = argsafe_name;
	else
		open retCursor for select
			a108.createdby,
			to_char( a108.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a108.updatedby,
			to_char( a108.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a108.TenantId as TenantId,
			a108.Id as Id,
			a108.TopDomainId as TopDomainId,
			a108.safe_name as safe_name,
			a108.descr as descr,
			a108.revision as revision
		from cfinet213.tprjdef a108
		where
			a108.TenantId = argTenantId
			and a108.TopDomainId = argTopDomainId
			and a108.safe_name = argsafe_name
			and a108.TenantId = secTenantId;
	end if;
end rd_tprjdefbynameidx;
/

show errors procedure cfinet213.rd_tprjdefbynameidx;
