--
--	@(#) dbcreate/cfint/db2luw/crsp_update_licn.sql
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

create or replace procedure sp_update_licn(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argTenantId bigint,	\
	in argId bigint,	\
	in argTopDomainId bigint,	\
	in argName varchar(64),	\
	in argDescription varchar(1024),	\
	in argEmbeddedText clob(8000),	\
	in argFullText clob(8000),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldTenantId bigint;	\
	declare oldId bigint;	\
	declare oldTopDomainId bigint;	\
	declare oldName varchar(64);	\
	declare oldDescription varchar(1024);	\
	declare oldEmbeddedText clob(8000);	\
	declare oldFullText clob(8000);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a101.tenantid as tenantid,	\
			a101.id as id,	\
			a101.topdomainid as topdomainid,	\
			a101.safe_name as safe_name,	\
			a101.descr as descr,	\
			a101.embeddedtext as embeddedtext,	\
			a101.fulltxt as fulltxt,	\
			a101.revision as revision	\
		from cfinet213.licn as a101	\
		where	\
			a101.tenantid = argTenantId	\
		and a101.id = argId;	\
	begin	\
		if( argClassCode = 'a101' )	\
		then	\
			set( permissionFlag ) = ( sp_is_tenant_user( argTenantId,	\
					'UpdateLicense',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for UpdateLicense' );	\
			end if;	\
		end if;	\
	\
		select	\
			TenantId,	\
			Id,	\
			TopDomainId,	\
			safe_name,	\
			descr,	\
			EmbeddedText,	\
			FullTxt,	\
			revision	\
		into	\
			oldTenantId,	\
			oldId,	\
			oldTopDomainId,	\
			oldName,	\
			oldDescription,	\
			oldEmbeddedText,	\
			oldFullText,	\
			oldRevision	\
		from cfinet213.licn	\
		where	\
			TenantId = argTenantId	\
			and Id = argId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_licn() Data collision detected' );	\
		end if;	\
	\
		update cfinet213.licn	\
		set	\
			revision = argRevision + 1,	\
			topdomainid = argTopDomainId,	\
			safe_name = argName,	\
			descr = argDescription,	\
			embeddedtext = argEmbeddedText,	\
			fulltxt = argFullText	\
		where	\
			tenantid = argTenantId	\
		and id = argId	\
		and revision = argRevision;	\
	\
		open retcursor;	\
	end;	\
end
