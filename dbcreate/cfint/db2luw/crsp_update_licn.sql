--
--	@(#) dbcreate/cfint/db2luw/crsp_update_licn.sql
--
--	com.github.msobkow.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	This file is part of MSS Code Factory.
--	
--	Licensed under the Apache License, Version 2.0 (the "License");
--	you may not use this file except in compliance with the License.
--	You may obtain a copy of the License at
--	
--	    http://www.apache.org/licenses/LICENSE-2.0
--	
--	Unless required by applicable law or agreed to in writing, software
--	distributed under the License is distributed on an "AS IS" BASIS,
--	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
--	See the License for the specific language governing permissions and
--	limitations under the License.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
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
