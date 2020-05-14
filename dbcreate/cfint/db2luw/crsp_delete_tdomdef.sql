--
--	@(#) dbcreate/cfint/db2luw/crsp_delete_tdomdef.sql
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
create or replace procedure sp_delete_tdomdef(	\
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
	declare oldTldId bigint;	\
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
				'DeleteTopDomain',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for DeleteTopDomain' );	\
		end if;	\
	\
	\
		for cur as	\
			select	\
				a108.tenantid as tenantid,	\
				a108.id as id	\
			from cfinet213.tdomdef as a107	\
				inner join cfinet213.tprjdef a108 on 	\
					a107.tenantid = a108.tenantid	\
					and a107.id = a108.topdomainid	\
			where	\
				a107.tenantid = argTenantId	\
				and a107.id = argId	\
		do	\
			call sp_delete_tprjdef_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					id );	\
		end for;	\
	\
		for cur as	\
			select	\
				a101.tenantid as tenantid,	\
				a101.id as id	\
			from cfinet213.tdomdef as a107	\
				inner join cfinet213.licn a101 on 	\
					a107.tenantid = a101.tenantid	\
					and a107.id = a101.topdomainid	\
			where	\
				a107.tenantid = argTenantId	\
				and a107.id = argId	\
		do	\
			call sp_delete_licn_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					id );	\
		end for;	\
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
			a107.revision + 1,	\
			2	\
		from cfinet213.tdomdef as a107	\
		where	\
			a107.tenantid = argTenantId	\
		and a107.id = argId;	\
	\
		delete from cfinet213.tdomdef	\
		where	\
			tenantid = argTenantId	\
			and id = argId;	\
	\
		open retcursor;	\
	end;	\
end
