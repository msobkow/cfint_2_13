--
--	@(#) dbcreate/cfint/db2luw/crsp_create_licn.sql
--
--	org.msscf.msscf.CFInt
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
create or replace procedure sp_create_licn(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argTenantId bigint,	\
	in argTopDomainId bigint,	\
	in argName varchar(64),	\
	in argDescription varchar(1024),	\
	in argEmbeddedText clob(8000),	\
	in argFullText clob(8000) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argId bigint;	\
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
					'CreateLicense',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for CreateLicense' );	\
			end if;	\
		end if;	\
	\
		call sp_next_licenseidgen( argTenantId,	\
			argId );	\
		insert into cfinet213.licn(	\
			tenantid,	\
			id,	\
			topdomainid,	\
			safe_name,	\
			descr,	\
			embeddedtext,	\
			fulltxt,	\
			revision )	\
		values (	\
			argTenantId,	\
			argId,	\
			argTopDomainId,	\
			argName,	\
			argDescription,	\
			argEmbeddedText,	\
			argFullText,	\
			1 );	\
	\
		open retcursor;	\
	end;	\
end
