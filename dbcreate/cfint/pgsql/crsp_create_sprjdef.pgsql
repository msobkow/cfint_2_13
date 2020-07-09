--
--	@(#) dbcreate/cfint/pgsql/crsp_create_sprjdef.pgsql
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
create or replace function cfinet213.sp_create_sprjdef(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argTopProjectId bigint,
	argName varchar(64),
	argDescription varchar(1024) )
returns setof cfinet213.type_sprjdef_rec as $$
declare
	permissionFlag boolean;
	argId bigint;
begin
	if( argClassCode = 'a105' )
	then
		select cfinet213.sp_is_tenant_user( argTenantId,
			'CreateSubProject',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for CreateSubProject';
		end if;
	end if;

	select cfinet213.sp_next_subprojectidgen( argTenantId )
	into argId;

	insert into cfinet213.sprjdef(
		createdby,
		createdat,
		updatedby,
		updatedat,
		tenantid,
		id,
		topprojectid,
		safe_name,
		descr,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argTenantId,
		argId,
		argTopProjectId,
		argName,
		argDescription,
		1 );
	insert into cfinet213.sprjdef_h (
			TenantId,
			Id,
			auditclusterid,
			auditsessionid,
			auditstamp,
			TopProjectId,
			safe_name,
			descr,
			revision,
			auditaction )
		select
			a105.TenantId,
			a105.Id,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a105.TopProjectId,
			a105.safe_name,
			a105.descr,
			a105.revision,
			0
		from cfinet213.sprjdef as a105
		where
			a105.tenantid = argTenantId
			and a105.id = argId;

	return query select
			a105.createdby,
			to_char( a105.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a105.updatedby,
			to_char( a105.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a105.tenantid as tenantid,
			a105.id as id,
			a105.topprojectid as topprojectid,
			a105.safe_name as safe_name,
			a105.descr as descr,
			a105.revision as revision
	from cfinet213.sprjdef as a105
	where
			a105.tenantid = argTenantId
			and a105.id = argId;

	return;
end;
$$ language plpgsql;
