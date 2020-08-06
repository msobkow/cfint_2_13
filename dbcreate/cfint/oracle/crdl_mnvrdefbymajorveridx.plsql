--
--	@(#) dbcreate/cfint/oracle/crdl_mnvrdefbymajorveridx.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfinet213.dl_mnvrdefbymajorveridx(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argMajorVersionId numeric ) authid definer
is
	unrecognizedClassCode exception;
	permissionFlag integer;
	cursor cursSystem is
		select
			a104.TenantId as TenantId,
			a104.Id as Id,
				a104.revision as revision
		from cfinet213.mnvrdef a104
		where
				a104.TenantId = argTenantId
			and a104.MajorVersionId = argMajorVersionId;
	cursor cursRestrict is
		select
			a104.TenantId as TenantId,
			a104.Id as Id,
				a104.revision as revision
		from cfinet213.mnvrdef a104
		where
				a104.TenantId = argTenantId
			and a104.MajorVersionId = argMajorVersionId
				and a104.TenantId = secTenantId;
begin
	permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 1 )
	then
		for cur in cursSystem
		loop
			cfinet213.dl_mnvrdef( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.tenantid,
					cur.id,
					cur.revision );
		end loop;
	else
		for cur in cursRestrict
		loop
			cfinet213.dl_mnvrdef( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.tenantid,
					cur.id,
					cur.revision );
		end loop;
	end if;
end dl_mnvrdefbymajorveridx;
/

show errors procedure cfinet213.dl_mnvrdefbymajorveridx;
