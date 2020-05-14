--
--	@(#) dbcreate/cfint/db2luw/crsp_delete_tprjdef.sql
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
create or replace procedure sp_delete_tprjdef(	\
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
	declare oldTopDomainId bigint;	\
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
			TopDomainId,	\
			safe_name,	\
			descr,	\
			revision	\
		into	\
			oldTenantId,	\
			oldId,	\
			oldTopDomainId,	\
			oldName,	\
			oldDescription,	\
			oldRevision	\
		from cfinet213.tprjdef	\
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
				'DeleteTopProject',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for DeleteTopProject' );	\
		end if;	\
	\
	\
		for cur as	\
			select	\
				a105.tenantid as tenantid,	\
				a105.id as id	\
			from cfinet213.tprjdef as a108	\
				inner join cfinet213.sprjdef a105 on 	\
					a108.tenantid = a105.tenantid	\
					and a108.id = a105.topprojectid	\
			where	\
				a108.tenantid = argTenantId	\
				and a108.id = argId	\
		do	\
			call sp_delete_sprjdef_by_ididx( argAuditClusterId,	\
					argAuditUserId,	\
					argAuditSessionId,	\
					secClusterId,	\
					secTenantId,	\
					tenantid,	\
					id );	\
		end for;	\
	\
		insert into cfinet213.tprjdef_h (	\
				tenantid,	\
				id,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				topdomainid,	\
				safe_name,	\
				descr,	\
			revision,	\
			auditaction )	\
		select	\
				a108.tenantid,	\
				a108.id,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a108.topdomainid,	\
				a108.safe_name,	\
				a108.descr,	\
			a108.revision + 1,	\
			2	\
		from cfinet213.tprjdef as a108	\
		where	\
			a108.tenantid = argTenantId	\
		and a108.id = argId;	\
	\
		delete from cfinet213.tprjdef	\
		where	\
			tenantid = argTenantId	\
			and id = argId;	\
	\
		open retcursor;	\
	end;	\
end
