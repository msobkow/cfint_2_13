--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_sprjdef.pgsql
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
