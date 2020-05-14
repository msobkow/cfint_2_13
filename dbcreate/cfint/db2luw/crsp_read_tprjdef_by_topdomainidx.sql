--
--	@(#) dbcreate/cfint/db2luw/crsp_read_tprjdef_by_topdomainidx.sql
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
create or replace procedure sp_read_tprjdef_by_topdomainidx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argTenantId bigint,	\
	in argTopDomainId bigint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a108.createdby as createdby,	\
				to_char( a108.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a108.updatedby as updatedby,	\
				to_char( a108.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a108.tenantid as tenantid,	\
			a108.id as id,	\
			a108.topdomainid as topdomainid,	\
			a108.safe_name as safe_name,	\
			a108.descr as descr,	\
			a108.revision as revision	\
		from cfinet213.tprjdef as a108	\
		where	\
			a108.tenantid = argTenantId	\
		and a108.topdomainid = argTopDomainId	\
		order by TenantId desc,	\
			Id desc;	\
	declare usercurs cursor with return to client for	\
		select	\
				a108.createdby as createdby,	\
				to_char( a108.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a108.updatedby as updatedby,	\
				to_char( a108.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a108.tenantid as tenantid,	\
			a108.id as id,	\
			a108.topdomainid as topdomainid,	\
			a108.safe_name as safe_name,	\
			a108.descr as descr,	\
			a108.revision as revision	\
		from cfinet213.tprjdef as a108	\
		where	\
			a108.tenantid = argTenantId	\
		and a108.topdomainid = argTopDomainId	\
			and ( a108.TenantId = secTenantId )	\
		order by TenantId desc,	\
			Id desc;	\
	begin	\
		set( permissionFlag ) = ( sp_is_tenant_user( secTenantId,	\
				'ReadTopProject',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for ReadTopProject' );	\
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