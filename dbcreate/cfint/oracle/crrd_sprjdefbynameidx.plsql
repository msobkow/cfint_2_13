--
--	@(#) dbcreate/cfint/oracle/crrd_sprjdefbynameidx.plsql
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

create or replace procedure cfinet213.rd_sprjdefbynameidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argTopProjectId numeric,
	argsafe_name varchar2 ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfinet213.sp_is_tenant_user( secTenantId,
			'ReadSubProject',
			argAuditUserId );
	isSystemUser := cfinet213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( isSystemUser = 1 )
	then
		open retCursor for select
			a105.createdby,
			to_char( a105.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a105.updatedby,
			to_char( a105.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a105.TenantId as TenantId,
			a105.Id as Id,
			a105.TopProjectId as TopProjectId,
			a105.safe_name as safe_name,
			a105.descr as descr,
			a105.revision as revision
		from cfinet213.sprjdef a105
		where
			a105.TenantId = argTenantId
			and a105.TopProjectId = argTopProjectId
			and a105.safe_name = argsafe_name;
	else
		open retCursor for select
			a105.createdby,
			to_char( a105.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a105.updatedby,
			to_char( a105.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a105.TenantId as TenantId,
			a105.Id as Id,
			a105.TopProjectId as TopProjectId,
			a105.safe_name as safe_name,
			a105.descr as descr,
			a105.revision as revision
		from cfinet213.sprjdef a105
		where
			a105.TenantId = argTenantId
			and a105.TopProjectId = argTopProjectId
			and a105.safe_name = argsafe_name
			and a105.TenantId = secTenantId;
	end if;
end rd_sprjdefbynameidx;
/

show errors procedure cfinet213.rd_sprjdefbynameidx;
