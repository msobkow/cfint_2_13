--
--	@(#) dbcreate/cfint/db2luw/crsp_read_mjvrdef.sql
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
create or replace procedure sp_read_mjvrdef(	\
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
				a102.createdby as createdby,	\
				to_char( a102.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a102.updatedby as updatedby,	\
				to_char( a102.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a102.tenantid as tenantid,	\
			a102.id as id,	\
			a102.subprojectid as subprojectid,	\
			a102.safe_name as safe_name,	\
			a102.descr as descr,	\
			a102.revision as revision	\
		from cfinet213.mjvrdef as a102	\
		where	\
			a102.tenantid = argTenantId	\
		and a102.id = argId;	\
	declare usercurs cursor with return to client for	\
		select	\
				a102.createdby as createdby,	\
				to_char( a102.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a102.updatedby as updatedby,	\
				to_char( a102.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a102.tenantid as tenantid,	\
			a102.id as id,	\
			a102.subprojectid as subprojectid,	\
			a102.safe_name as safe_name,	\
			a102.descr as descr,	\
			a102.revision as revision	\
		from cfinet213.mjvrdef as a102	\
		where	\
			a102.tenantid = argTenantId	\
		and a102.id = argId	\
			and ( a102.TenantId = secTenantId );	\
	begin	\
		set( permissionFlag ) = ( sp_is_tenant_user( secTenantId,	\
				'ReadMajorVersion',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for ReadMajorVersion' );	\
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