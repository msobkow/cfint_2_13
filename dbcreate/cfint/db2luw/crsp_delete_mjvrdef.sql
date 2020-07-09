--
--	@(#) dbcreate/cfint/db2luw/crsp_delete_mjvrdef.sql
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
create or replace procedure sp_delete_mjvrdef(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argTenantId bigint,	\
	in argId bigint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldTenantId bigint;	\
	declare oldId bigint;	\
	declare oldSubProjectId bigint;	\
	declare oldName varchar(64);	\
	declare oldDescription varchar(1024);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			TenantId,	\
			Id,	\
			SubProjectId,	\
			safe_name,	\
			descr,	\
			revision	\
		into	\
			oldTenantId,	\
			oldId,	\
			oldSubProjectId,	\
			oldName,	\
			oldDescription,	\
			oldRevision	\
		from cfinet213.mjvrdef	\
		where	\
			TenantId = argTenantId	\
			and Id = argId	\
		for update;	\
	\
		if( oldTenantId != secTenantId )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20003, 'Permission denied -- Data is not owned by logged in tenant' );	\
			end if;	\
		end if;	\
	\
		set( permissionFlag ) = ( sp_is_tenant_user( oldTenantId,	\
				'DeleteMajorVersion',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for DeleteMajorVersion' );	\
		end if;	\
	\
	\
		for cur as	\
			select	\
				a104.tenantid as tenantid,	\
				a104.id as id	\
			from cfinet213.mjvrdef as a102	\
				inner join cfinet213.mnvrdef a104 on 	\
					a102.tenantid = a104.tenantid	\
					and a102.id = a104.majorversionid	\
			where	\
				a102.tenantid = argTenantId	\
				and a102.id = argId	\
		do	\
			call sp_delete_mnvrdef_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					id );	\
		end for;	\
	\
		insert into cfinet213.mjvrdef_h (	\
				tenantid,	\
				id,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				subprojectid,	\
				safe_name,	\
				descr,	\
			revision,	\
			auditaction )	\
		select	\
				a102.tenantid,	\
				a102.id,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a102.subprojectid,	\
				a102.safe_name,	\
				a102.descr,	\
			a102.revision + 1,	\
			2	\
		from cfinet213.mjvrdef as a102	\
		where	\
			a102.tenantid = argTenantId	\
		and a102.id = argId;	\
	\
		delete from cfinet213.mjvrdef	\
		where	\
			tenantid = argTenantId	\
			and id = argId;	\
	\
		open retcursor;	\
	end;	\
end
