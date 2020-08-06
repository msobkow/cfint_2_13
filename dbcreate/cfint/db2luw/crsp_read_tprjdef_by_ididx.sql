--
--	@(#) dbcreate/cfint/db2luw/crsp_read_tprjdef_by_ididx.sql
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
create or replace procedure sp_read_tprjdef_by_ididx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argTenantId bigint,	\
	in argId bigint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a108.createdby as createdby,	\
				to_char( a108.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a108.updatedby as updatedby,	\
				to_char( a108.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a108.tenantid as tenantid,	\
			a108.id as id,	\
			a108.topdomainid as topdomainid,	\
			a108.safe_name as safe_name,	\
			a108.descr as descr,	\
			a108.revision as revision	\
		from cfinet213.tprjdef as a108	\
		where	\
			a108.tenantid = argTenantId	\
		and a108.id = argId;	\
	declare usercurs cursor with return to client for	\
		select	\
				a108.createdby as createdby,	\
				to_char( a108.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a108.updatedby as updatedby,	\
				to_char( a108.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a108.tenantid as tenantid,	\
			a108.id as id,	\
			a108.topdomainid as topdomainid,	\
			a108.safe_name as safe_name,	\
			a108.descr as descr,	\
			a108.revision as revision	\
		from cfinet213.tprjdef as a108	\
		where	\
			a108.tenantid = argTenantId	\
		and a108.id = argId	\
			and ( a108.TenantId = secTenantId );	\
	begin	\
		set( permissionFlag ) = ( sp_is_tenant_user( secTenantId,	\
				'ReadTopProject',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for ReadTopProject' );	\
		end if;	\
		set( isSystemUser ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( isSystemUser = 1 )	\
		then	\
			open syscurs;	\
		else	\
			open usercurs;	\
		end if;	\
	end;	\
end