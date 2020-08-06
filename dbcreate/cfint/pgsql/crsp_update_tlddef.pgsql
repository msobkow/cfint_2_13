--
--	@(#) dbcreate/cfint/pgsql/crsp_update_tlddef.pgsql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFInt 2.13 Internet Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--

create or replace function cfinet213.sp_update_tlddef(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argId bigint,
	argName varchar(64),
	argDescription varchar(1024),
	argRevision integer )
returns setof cfinet213.type_tlddef_rec as $$
declare
	RowsAffected integer;
	oldTenantId bigint;
	oldId bigint;
	oldName varchar(64);
	oldDescription varchar(1024);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a106' )
	then
		select cfinet213.sp_is_tenant_user( argTenantId,
			'UpdateTld',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for UpdateTld';
		end if;
	end if;

		select
			TenantId,
			Id,
			safe_name,
			descr,
			revision
		into
			oldTenantId,
			oldId,
			oldName,
			oldDescription,
			oldRevision
		from cfinet213.tlddef
		where
			TenantId = argTenantId
			and Id = argId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_tlddef() Data collision detected';
	end if;


	update cfinet213.tlddef
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		safe_name = argName,
		descr = argDescription
	where
		TenantId = argTenantId
			and Id = argId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_tlddef() Expected to affect one tlddef row, not %', RowsAffected;
	end if;


	insert into cfinet213.tlddef_h (
			TenantId,
			Id,
			auditclusterid,
			auditsessionid,
			auditstamp,
			safe_name,
			descr,
			revision,
			auditaction )
		select
			a106.TenantId,
			a106.Id,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a106.safe_name,
			a106.descr,
			argRevision + 1,
			1
		from cfinet213.tlddef as a106
		where
			a106.tenantid = argTenantId
			and a106.id = argId;
	return query select
			a106.createdby,
			to_char( a106.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a106.updatedby,
			to_char( a106.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a106.tenantid as tenantid,
			a106.id as id,
			a106.safe_name as safe_name,
			a106.descr as descr,
		a106.revision as revision
	from cfinet213.tlddef as a106
	where
		a106.tenantid = argTenantId
			and a106.id = argId;

	return;
end;
$$ language plpgsql;
