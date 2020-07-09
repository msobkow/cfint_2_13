--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_tdomdef.pgsql
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
create or replace function cfinet213.sp_delete_tdomdef(
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
	oldTldId bigint;
	oldName varchar(64);
	oldDescription varchar(1024);
	oldRevision int;
	permissionFlag boolean;
begin
		select
			TenantId,
			Id,
			TldId,
			safe_name,
			descr,
			revision
		into
			oldTenantId,
			oldId,
			oldTldId,
			oldName,
			oldDescription,
			oldRevision
		from cfinet213.tdomdef
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
		'DeleteTopDomain',
		argAuditUserId )
	into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for DeleteTopDomain';
	end if;

	insert into cfinet213.tdomdef_h (
			TenantId,
			Id,
			auditclusterid,
			auditsessionid,
			auditstamp,
			TldId,
			safe_name,
			descr,
			revision,
			auditaction )
		select
			a107.TenantId,
			a107.Id,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a107.TldId,
			a107.safe_name,
			a107.descr,
			argRevision + 1,
			2
		from cfinet213.tdomdef as a107
		where
			a107.tenantid = argTenantId
			and a107.id = argId;

	for cur in
		select
			a108.TenantId,
			a108.Id
		from cfinet213.tdomdef as a107
			inner join cfinet213.tprjdef a108 on 
				a107.TenantId = a108.TenantId
				and a107.Id = a108.TopDomainId
		where
			a107.TenantId = argTenantId
			and a107.Id = argId
	loop
		select cfinet213.sp_delete_tprjdef_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.Id )
			into subret;
	end loop;

	for cur in
		select
			a101.TenantId,
			a101.Id
		from cfinet213.tdomdef as a107
			inner join cfinet213.licn a101 on 
				a107.TenantId = a101.TenantId
				and a107.Id = a101.TopDomainId
		where
			a107.TenantId = argTenantId
			and a107.Id = argId
	loop
		select cfinet213.sp_delete_licn_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.Id )
			into subret;
	end loop;


	delete from cfinet213.tdomdef
	where
		tenantid = argTenantId
		and id = argId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_tdomdef() Expected to affect 1 tdomdef, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
