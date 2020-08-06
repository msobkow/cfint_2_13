--
--	@(#) dbcreate/cfint/db2luw/crsp_update_mnvrdef.sql
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

create or replace procedure sp_update_mnvrdef(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argTenantId bigint,	\
	in argId bigint,	\
	in argMajorVersionId bigint,	\
	in argName varchar(64),	\
	in argDescription varchar(1024),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldTenantId bigint;	\
	declare oldId bigint;	\
	declare oldMajorVersionId bigint;	\
	declare oldName varchar(64);	\
	declare oldDescription varchar(1024);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a104.createdby as createdby,	\
				to_char( a104.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a104.updatedby as updatedby,	\
				to_char( a104.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a104.tenantid as tenantid,	\
			a104.id as id,	\
			a104.majorversionid as majorversionid,	\
			a104.safe_name as safe_name,	\
			a104.descr as descr,	\
			a104.revision as revision	\
		from cfinet213.mnvrdef as a104	\
		where	\
			a104.tenantid = argTenantId	\
		and a104.id = argId;	\
	begin	\
		if( argClassCode = 'a104' )	\
		then	\
			set( permissionFlag ) = ( sp_is_tenant_user( argTenantId,	\
					'UpdateMinorVersion',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for UpdateMinorVersion' );	\
			end if;	\
		end if;	\
	\
		select	\
			TenantId,	\
			Id,	\
			MajorVersionId,	\
			safe_name,	\
			descr,	\
			revision	\
		into	\
			oldTenantId,	\
			oldId,	\
			oldMajorVersionId,	\
			oldName,	\
			oldDescription,	\
			oldRevision	\
		from cfinet213.mnvrdef	\
		where	\
			TenantId = argTenantId	\
			and Id = argId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_mnvrdef() Data collision detected' );	\
		end if;	\
	\
		update cfinet213.mnvrdef	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			majorversionid = argMajorVersionId,	\
			safe_name = argName,	\
			descr = argDescription	\
		where	\
			tenantid = argTenantId	\
		and id = argId	\
		and revision = argRevision;	\
	\
		insert into cfinet213.mnvrdef_h (	\
				tenantid,	\
				id,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				majorversionid,	\
				safe_name,	\
				descr,	\
			revision,	\
			auditaction )	\
		select	\
				a104.tenantid,	\
				a104.id,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a104.majorversionid,	\
				a104.safe_name,	\
				a104.descr,	\
			a104.revision,	\
			2	\
		from cfinet213.mnvrdef as a104	\
		where	\
			a104.tenantid = argTenantId	\
		and a104.id = argId;	\
	\
		open retcursor;	\
	end;	\
end
