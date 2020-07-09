--
--	@(#) dbcreate/cfint/oracle/crcrt_sprjdef.plsql
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

create or replace procedure cfinet213.crt_sprjdef(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argTenantId numeric,
	argTopProjectId numeric,
	argsafe_name varchar2,
	argdescr varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.sprjdef_h.auditstamp%type;
	permissionFlag integer;
	argId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a105' )
	then
		permissionFlag := cfinet213.sp_is_tenant_user( argTenantId,
			'CreateSubProject',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argId := cfinet213.nxt_subprojectidgen( argTenantId );
	insert into cfinet213.sprjdef(
		createdby,
		createdat,
		updatedby,
		updatedat,
		TenantId,
		Id,
		TopProjectId,
		safe_name,
		descr,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argTenantId,
		argId,
		argTopProjectId,
		argsafe_name,
		argdescr,
		1 );
	insert into cfinet213.sprjdef_h (
			TenantId,
			Id,
			revision,
			auditclusterid,
			auditsessionid,
			TopProjectId,
			safe_name,
			descr,
			auditaction,
			auditstamp )
		select
			a105.TenantId as TenantId,
			a105.Id as Id,
			a105.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a105.TopProjectId as TopProjectId,
			a105.safe_name as safe_name,
			a105.descr as descr,
			0,
			use_stamp
		from cfinet213.sprjdef a105
		where
			a105.TenantId = argTenantId
			and a105.Id = argId;

	open retCursor for select
			a105.createdby,
			to_char( a105.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a105.updatedby,
			to_char( a105.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a105.TenantId as TenantId,
			a105.Id as Id,
			a105.TopProjectId as TopProjectId,
			a105.safe_name as safe_name,
			a105.descr as descr,
		a105.revision as revision
	from cfinet213.sprjdef a105
	where
		a105.TenantId = argTenantId
			and a105.Id = argId;
end crt_sprjdef;
/

show errors procedure cfinet213.crt_sprjdef;
