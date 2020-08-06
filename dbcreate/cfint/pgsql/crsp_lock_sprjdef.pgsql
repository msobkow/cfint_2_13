--
--	@(#) dbcreate/cfint/pgsql/crsp_lock_sprjdef.pgsql
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

create or replace function cfinet213.sp_lock_sprjdef(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argId bigint )
returns setof cfinet213.type_sprjdef_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfinet213.sp_is_tenant_user( secTenantId,
			'ReadSubProject',
			argAuditUserId ),
		cfinet213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for ReadSubProject';
	end if;
	if( isSystemUser )
	then
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
			and a105.id = argId
		for update;
	else
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
			and a105.id = argId
			and a105.TenantId = secTenantId
		for update;
	end if;
	return;
end;
$$ language plpgsql;
