--
--	@(#) dbcreate/cfint/pgsql/crsp_update_sprjdef.pgsql
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

create or replace function cfinet213.sp_update_sprjdef(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argId bigint,
	argTopProjectId bigint,
	argName varchar(64),
	argDescription varchar(1024),
	argRevision integer )
returns setof cfinet213.type_sprjdef_rec as $$
declare
	RowsAffected integer;
	oldTenantId bigint;
	oldId bigint;
	oldTopProjectId bigint;
	oldName varchar(64);
	oldDescription varchar(1024);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a105' )
	then
		select cfinet213.sp_is_tenant_user( argTenantId,
			'UpdateSubProject',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for UpdateSubProject';
		end if;
	end if;

		select
			TenantId,
			Id,
			TopProjectId,
			safe_name,
			descr,
			revision
		into
			oldTenantId,
			oldId,
			oldTopProjectId,
			oldName,
			oldDescription,
			oldRevision
		from cfinet213.sprjdef
		where
			TenantId = argTenantId
			and Id = argId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_sprjdef() Data collision detected';
	end if;


	update cfinet213.sprjdef
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		topprojectid = argTopProjectId,
		safe_name = argName,
		descr = argDescription
	where
		TenantId = argTenantId
			and Id = argId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_sprjdef() Expected to affect one sprjdef row, not %', RowsAffected;
	end if;


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
			argRevision + 1,
			1
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
