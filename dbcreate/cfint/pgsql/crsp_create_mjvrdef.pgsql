--
--	@(#) dbcreate/cfint/pgsql/crsp_create_mjvrdef.pgsql
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
create or replace function cfinet213.sp_create_mjvrdef(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argSubProjectId bigint,
	argName varchar(64),
	argDescription varchar(1024) )
returns setof cfinet213.type_mjvrdef_rec as $$
declare
	permissionFlag boolean;
	argId bigint;
begin
	if( argClassCode = 'a102' )
	then
		select cfinet213.sp_is_tenant_user( argTenantId,
			'CreateMajorVersion',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for CreateMajorVersion';
		end if;
	end if;

	select cfinet213.sp_next_majorversionidgen( argTenantId )
	into argId;

	insert into cfinet213.mjvrdef(
		createdby,
		createdat,
		updatedby,
		updatedat,
		tenantid,
		id,
		subprojectid,
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
		argSubProjectId,
		argName,
		argDescription,
		1 );
	insert into cfinet213.mjvrdef_h (
			TenantId,
			Id,
			auditclusterid,
			auditsessionid,
			auditstamp,
			SubProjectId,
			safe_name,
			descr,
			revision,
			auditaction )
		select
			a102.TenantId,
			a102.Id,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a102.SubProjectId,
			a102.safe_name,
			a102.descr,
			a102.revision,
			0
		from cfinet213.mjvrdef as a102
		where
			a102.tenantid = argTenantId
			and a102.id = argId;

	return query select
			a102.createdby,
			to_char( a102.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a102.updatedby,
			to_char( a102.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a102.tenantid as tenantid,
			a102.id as id,
			a102.subprojectid as subprojectid,
			a102.safe_name as safe_name,
			a102.descr as descr,
			a102.revision as revision
	from cfinet213.mjvrdef as a102
	where
			a102.tenantid = argTenantId
			and a102.id = argId;

	return;
end;
$$ language plpgsql;
