--
--	@(#) dbcreate/cfint/db2luw/crsp_update_tdomdef.sql
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

create or replace procedure sp_update_tdomdef(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argTenantId bigint,	\
	in argId bigint,	\
	in argTldId bigint,	\
	in argName varchar(64),	\
	in argDescription varchar(1024),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldTenantId bigint;	\
	declare oldId bigint;	\
	declare oldTldId bigint;	\
	declare oldName varchar(64);	\
	declare oldDescription varchar(1024);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a107.createdby as createdby,	\
				to_char( a107.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a107.updatedby as updatedby,	\
				to_char( a107.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a107.tenantid as tenantid,	\
			a107.id as id,	\
			a107.tldid as tldid,	\
			a107.safe_name as safe_name,	\
			a107.descr as descr,	\
			a107.revision as revision	\
		from cfinet213.tdomdef as a107	\
		where	\
			a107.tenantid = argTenantId	\
		and a107.id = argId;	\
	begin	\
		if( argClassCode = 'a107' )	\
		then	\
			set( permissionFlag ) = ( sp_is_tenant_user( argTenantId,	\
					'UpdateTopDomain',	\
					argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for UpdateTopDomain' );	\
			end if;	\
		end if;	\
	\
		select	\
			TenantId,	\
			Id,	\
			TldId,	\
			safe_name,	\
			descr,	\
			revision	\
		into	\
			oldTenantId,	\
			oldId,	\
			oldTldId,	\
			oldName,	\
			oldDescription,	\
			oldRevision	\
		from cfinet213.tdomdef	\
		where	\
			TenantId = argTenantId	\
			and Id = argId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_tdomdef() Data collision detected' );	\
		end if;	\
	\
		update cfinet213.tdomdef	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			tldid = argTldId,	\
			safe_name = argName,	\
			descr = argDescription	\
		where	\
			tenantid = argTenantId	\
		and id = argId	\
		and revision = argRevision;	\
	\
		insert into cfinet213.tdomdef_h (	\
				tenantid,	\
				id,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				tldid,	\
				safe_name,	\
				descr,	\
			revision,	\
			auditaction )	\
		select	\
				a107.tenantid,	\
				a107.id,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a107.tldid,	\
				a107.safe_name,	\
				a107.descr,	\
			a107.revision,	\
			2	\
		from cfinet213.tdomdef as a107	\
		where	\
			a107.tenantid = argTenantId	\
		and a107.id = argId;	\
	\
		open retcursor;	\
	end;	\
end
