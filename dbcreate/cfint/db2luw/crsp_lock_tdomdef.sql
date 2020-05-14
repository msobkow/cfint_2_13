--
--	@(#) dbcreate/cfint/db2luw/crsp_lock_tdomdef.sql
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

create or replace procedure sp_lock_tdomdef(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argTenantId bigint,	\
	in argId bigint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
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
		and a107.id = argId	\
		for update;	\
	declare usercurs cursor with return to client for	\
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
		and a107.id = argId	\
			and ( a107.TenantId = secTenantId )	\
		for update;	\
	begin	\
		set( permissionFlag ) = ( sp_is_tenant_user( secTenantId,	\
				'UpdateTopDomain',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for UpdateTopDomain' );	\
		end if;	\
		set( isSystemUser ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( isSystemUser = 1 )	\
		then	\
			open syscurs;	\
		else	\
			open usercurs;	\
		end if;	\
	end;	\
end
