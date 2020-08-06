--
--	@(#) dbcreate/cfint/pgsql/crsp_read_licn_by_unameidx.pgsql
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
create or replace function cfinet213.sp_read_licn_by_unameidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argTopDomainId bigint,
	argName varchar(64) )
returns setof cfinet213.type_licn_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfinet213.sp_is_tenant_user( secTenantId,
			'ReadLicense',
			argAuditUserId ),
		cfinet213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for ReadLicense';
	end if;
	if( isSystemUser )
	then
		return query select
			a101.tenantid as tenantid,
			a101.id as id,
			a101.topdomainid as topdomainid,
			a101.safe_name as safe_name,
			a101.descr as descr,
			a101.embeddedtext as embeddedtext,
			a101.fulltxt as fulltxt,
			a101.revision as revision
		from cfinet213.licn as a101
		where
			a101.tenantid = argTenantId
			and a101.topdomainid = argTopDomainId
			and a101.safe_name = argName;
	else
		return query select
			a101.tenantid as tenantid,
			a101.id as id,
			a101.topdomainid as topdomainid,
			a101.safe_name as safe_name,
			a101.descr as descr,
			a101.embeddedtext as embeddedtext,
			a101.fulltxt as fulltxt,
			a101.revision as revision
		from cfinet213.licn as a101
		where
			a101.tenantid = argTenantId
			and a101.topdomainid = argTopDomainId
			and a101.safe_name = argName
			and a101.TenantId = secTenantId;
	end if;
	return;
end
$$ language plpgsql;
