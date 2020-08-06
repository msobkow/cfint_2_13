--
--	@(#) dbcreate/cfint/db2luw/crsp_update_tlddef.sql
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

create or replace procedure sp_update_tlddef(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argTenantId bigint,	\
	in argId bigint,	\
	in argName varchar(64),	\
	in argDescription varchar(1024),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldTenantId bigint;	\
	declare oldId bigint;	\
	declare oldName varchar(64);	\
	declare oldDescription varchar(1024);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a106.createdby as createdby,	\
				to_char( a106.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a106.updatedby as updatedby,	\
				to_char( a106.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a106.tenantid as tenantid,	\
			a106.id as id,	\
			a106.safe_name as safe_name,	\
			a106.descr as descr,	\
			a106.revision as revision	\
		from cfinet213.tlddef as a106	\
		where	\
			a106.tenantid = argTenantId	\
		and a106.id = argId;	\
	begin	\
		if( argClassCode = 'a106' )	\
		then	\
			set( permissionFlag ) = ( sp_is_tenant_user( argTenantId,	\
					'UpdateTld',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for UpdateTld' );	\
			end if;	\
		end if;	\
	\
		select	\
			TenantId,	\
			Id,	\
			safe_name,	\
			descr,	\
			revision	\
		into	\
			oldTenantId,	\
			oldId,	\
			oldName,	\
			oldDescription,	\
			oldRevision	\
		from cfinet213.tlddef	\
		where	\
			TenantId = argTenantId	\
			and Id = argId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_tlddef() Data collision detected' );	\
		end if;	\
	\
		update cfinet213.tlddef	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			safe_name = argName,	\
			descr = argDescription	\
		where	\
			tenantid = argTenantId	\
		and id = argId	\
		and revision = argRevision;	\
	\
		insert into cfinet213.tlddef_h (	\
				tenantid,	\
				id,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				safe_name,	\
				descr,	\
			revision,	\
			auditaction )	\
		select	\
				a106.tenantid,	\
				a106.id,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a106.safe_name,	\
				a106.descr,	\
			a106.revision,	\
			2	\
		from cfinet213.tlddef as a106	\
		where	\
			a106.tenantid = argTenantId	\
		and a106.id = argId;	\
	\
		open retcursor;	\
	end;	\
end
