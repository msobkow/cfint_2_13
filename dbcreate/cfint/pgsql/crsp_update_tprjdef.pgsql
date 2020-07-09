--
--	@(#) dbcreate/cfint/pgsql/crsp_update_tprjdef.pgsql
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

create or replace function cfinet213.sp_update_tprjdef(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argId bigint,
	argTopDomainId bigint,
	argName varchar(64),
	argDescription varchar(1024),
	argRevision integer )
returns setof cfinet213.type_tprjdef_rec as $$
declare
	RowsAffected integer;
	oldTenantId bigint;
	oldId bigint;
	oldTopDomainId bigint;
	oldName varchar(64);
	oldDescription varchar(1024);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a108' )
	then
		select cfinet213.sp_is_tenant_user( argTenantId,
			'UpdateTopProject',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for UpdateTopProject';
		end if;
	end if;

		select
			TenantId,
			Id,
			TopDomainId,
			safe_name,
			descr,
			revision
		into
			oldTenantId,
			oldId,
			oldTopDomainId,
			oldName,
			oldDescription,
			oldRevision
		from cfinet213.tprjdef
		where
			TenantId = argTenantId
			and Id = argId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_tprjdef() Data collision detected';
	end if;


	update cfinet213.tprjdef
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		topdomainid = argTopDomainId,
		safe_name = argName,
		descr = argDescription
	where
		TenantId = argTenantId
			and Id = argId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_tprjdef() Expected to affect one tprjdef row, not %', RowsAffected;
	end if;


	insert into cfinet213.tprjdef_h (
			TenantId,
			Id,
			auditclusterid,
			auditsessionid,
			auditstamp,
			TopDomainId,
			safe_name,
			descr,
			revision,
			auditaction )
		select
			a108.TenantId,
			a108.Id,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a108.TopDomainId,
			a108.safe_name,
			a108.descr,
			argRevision + 1,
			1
		from cfinet213.tprjdef as a108
		where
			a108.tenantid = argTenantId
			and a108.id = argId;
	return query select
			a108.createdby,
			to_char( a108.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a108.updatedby,
			to_char( a108.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a108.tenantid as tenantid,
			a108.id as id,
			a108.topdomainid as topdomainid,
			a108.safe_name as safe_name,
			a108.descr as descr,
		a108.revision as revision
	from cfinet213.tprjdef as a108
	where
		a108.tenantid = argTenantId
			and a108.id = argId;

	return;
end;
$$ language plpgsql;
