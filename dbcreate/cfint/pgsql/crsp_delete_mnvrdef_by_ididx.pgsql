--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_mnvrdef_by_ididx.pgsql
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
create or replace function cfinet213.sp_delete_mnvrdef_by_ididx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argId bigint )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
begin
	select cfinet213.sp_is_system_user( argAuditUserId ) into subret;
	if( subret )
	then
		for cur in
			select
					a104.tenantid as tenantid,
						a104.id as id,
					a104.revision as revision
			from cfinet213.mnvrdef as a104
			where
					a104.tenantid = argTenantId
			and a104.id = argId
		loop
				select cfinet213.sp_delete_mnvrdef( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.tenantid,
							cur.id,
						cur.revision )
					into subret;
		end loop;
	else
		for cur in
			select
					a104.tenantid as tenantid,
						a104.id as id,
					a104.revision as revision
			from cfinet213.mnvrdef as a104
			where
					a104.tenantid = argTenantId
			and a104.id = argId
					and a104.TenantId = secTenantId
		loop
				select cfinet213.sp_delete_mnvrdef( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.tenantid,
							cur.id,
						cur.revision )
					into subret;
		end loop;
	end if;
	return true;
end;
$$ language plpgsql;
