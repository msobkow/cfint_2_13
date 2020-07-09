--
--	@(#) dbcreate/cfint/db2luw/crsp_create_sprjdef.sql
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
create or replace procedure sp_create_sprjdef(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argTenantId bigint,	\
	in argTopProjectId bigint,	\
	in argName varchar(64),	\
	in argDescription varchar(1024) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argId bigint;	\
	declare retcursor cursor with return to client for	\
		select	\
				a105.createdby as createdby,	\
				to_char( a105.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a105.updatedby as updatedby,	\
				to_char( a105.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a105.tenantid as tenantid,	\
			a105.id as id,	\
			a105.topprojectid as topprojectid,	\
			a105.safe_name as safe_name,	\
			a105.descr as descr,	\
			a105.revision as revision	\
		from cfinet213.sprjdef as a105	\
		where	\
			a105.tenantid = argTenantId	\
		and a105.id = argId;	\
	begin	\
		if( argClassCode = 'a105' )	\
		then	\
			set( permissionFlag ) = ( sp_is_tenant_user( argTenantId,	\
					'CreateSubProject',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for CreateSubProject' );	\
			end if;	\
		end if;	\
	\
		call sp_next_subprojectidgen( argTenantId,	\
			argId );	\
		insert into cfinet213.sprjdef(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			tenantid,	\
			id,	\
			topprojectid,	\
			safe_name,	\
			descr,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argTenantId,	\
			argId,	\
			argTopProjectId,	\
			argName,	\
			argDescription,	\
			1 );	\
	\
		insert into cfinet213.sprjdef_h (	\
				tenantid,	\
				id,	\
				auditclusterid,	\
				auditsessionid,	\
				auditstamp,	\
				topprojectid,	\
				safe_name,	\
				descr,	\
				revision,	\
				auditaction )	\
		select	\
				a105.tenantid,	\
				a105.id,	\
				argAuditClusterId,	\
				argAuditSessionId,	\
				current timestamp,	\
				a105.topprojectid,	\
				a105.safe_name,	\
				a105.descr,	\
				a105.revision,	\
				0	\
		from cfinet213.sprjdef as a105	\
		where	\
				a105.tenantid = argTenantId	\
		and a105.id = argId;	\
	\
		open retcursor;	\
	end;	\
end
