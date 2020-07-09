--
--	@(#) dbcreate/cfint/pgsql/crsp_update_mnvrdef.pgsql
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

create or replace function cfinet213.sp_update_mnvrdef(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argId bigint,
	argMajorVersionId bigint,
	argName varchar(64),
	argDescription varchar(1024),
	argRevision integer )
returns setof cfinet213.type_mnvrdef_rec as $$
declare
	RowsAffected integer;
	oldTenantId bigint;
	oldId bigint;
	oldMajorVersionId bigint;
	oldName varchar(64);
	oldDescription varchar(1024);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a104' )
	then
		select cfinet213.sp_is_tenant_user( argTenantId,
			'UpdateMinorVersion',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for UpdateMinorVersion';
		end if;
	end if;

		select
			TenantId,
			Id,
			MajorVersionId,
			safe_name,
			descr,
			revision
		into
			oldTenantId,
			oldId,
			oldMajorVersionId,
			oldName,
			oldDescription,
			oldRevision
		from cfinet213.mnvrdef
		where
			TenantId = argTenantId
			and Id = argId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_mnvrdef() Data collision detected';
	end if;


	update cfinet213.mnvrdef
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		majorversionid = argMajorVersionId,
		safe_name = argName,
		descr = argDescription
	where
		TenantId = argTenantId
			and Id = argId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_mnvrdef() Expected to affect one mnvrdef row, not %', RowsAffected;
	end if;


	insert into cfinet213.mnvrdef_h (
			TenantId,
			Id,
			auditclusterid,
			auditsessionid,
			auditstamp,
			MajorVersionId,
			safe_name,
			descr,
			revision,
			auditaction )
		select
			a104.TenantId,
			a104.Id,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a104.MajorVersionId,
			a104.safe_name,
			a104.descr,
			argRevision + 1,
			1
		from cfinet213.mnvrdef as a104
		where
			a104.tenantid = argTenantId
			and a104.id = argId;
	return query select
			a104.createdby,
			to_char( a104.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a104.updatedby,
			to_char( a104.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a104.tenantid as tenantid,
			a104.id as id,
			a104.majorversionid as majorversionid,
			a104.safe_name as safe_name,
			a104.descr as descr,
		a104.revision as revision
	from cfinet213.mnvrdef as a104
	where
		a104.tenantid = argTenantId
			and a104.id = argId;

	return;
end;
$$ language plpgsql;
