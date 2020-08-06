--
--	@(#) dbcreate/cfint/oracle/crcrt_tenant.plsql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
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

create or replace procedure cfinet213.crt_tenant(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argTenantName varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.tenant_h.auditstamp%type;
	permissionFlag integer;
	argId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a015' )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argId := cfinet213.nxt_tenantidgen();
	insert into cfinet213.tenant(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ClusterId,
		Id,
		TenantName,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argClusterId,
		argId,
		argTenantName,
		1 );
	insert into cfinet213.tenant_h (
			Id,
			revision,
			auditclusterid,
			auditsessionid,
			ClusterId,
			TenantName,
			auditaction,
			auditstamp )
		select
			a015.Id as Id,
			a015.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a015.ClusterId as ClusterId,
			a015.TenantName as TenantName,
			0,
			use_stamp
		from cfinet213.tenant a015
		where
			a015.Id = argId;

	open retCursor for select
			a015.createdby,
			to_char( a015.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a015.updatedby,
			to_char( a015.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a015.ClusterId as ClusterId,
			a015.Id as Id,
			a015.TenantName as TenantName,
		a015.revision as revision
	from cfinet213.tenant a015
	where
		a015.Id = argId;
end crt_tenant;
/

show errors procedure cfinet213.crt_tenant;
