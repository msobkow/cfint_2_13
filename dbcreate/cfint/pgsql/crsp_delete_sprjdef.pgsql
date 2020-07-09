--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_sprjdef.pgsql
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
create or replace function cfinet213.sp_delete_sprjdef(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argId bigint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldTenantId bigint;
	oldId bigint;
	oldTopProjectId bigint;
	oldName varchar(64);
	oldDescription varchar(1024);
	oldRevision int;
	permissionFlag boolean;
begin
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

	if( oldTenantId != secTenantId )
	then
		select cfinet213.sp_is_system_user( argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- Data is not owned by logged in tenant';
		end if;
	end if;

	select cfinet213.sp_is_tenant_user( oldTenantId,
		'DeleteSubProject',
		argAuditUserId )
	into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for DeleteSubProject';
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
			2
		from cfinet213.sprjdef as a105
		where
			a105.tenantid = argTenantId
			and a105.id = argId;

	for cur in
		select
			a102.TenantId,
			a102.Id
		from cfinet213.sprjdef as a105
			inner join cfinet213.mjvrdef a102 on 
				a105.TenantId = a102.TenantId
				and a105.Id = a102.SubProjectId
		where
			a105.TenantId = argTenantId
			and a105.Id = argId
	loop
		select cfinet213.sp_delete_mjvrdef_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.Id )
			into subret;
	end loop;


	delete from cfinet213.sprjdef
	where
		tenantid = argTenantId
		and id = argId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_sprjdef() Expected to affect 1 sprjdef, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
