--
--	@(#) dbcreate/cfint/db2luw/crsp_read_sprjdef_by_topprojectidx.sql
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
create or replace procedure sp_read_sprjdef_by_topprojectidx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argTenantId bigint,	\
	in argTopProjectId bigint )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
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
		and a105.topprojectid = argTopProjectId	\
		order by TenantId desc,	\
			Id desc;	\
	declare usercurs cursor with return to client for	\
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
		and a105.topprojectid = argTopProjectId	\
			and ( a105.TenantId = secTenantId )	\
		order by TenantId desc,	\
			Id desc;	\
	begin	\
		set( permissionFlag ) = ( sp_is_tenant_user( secTenantId,	\
				'ReadSubProject',	\
				argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20003, 'Permission denied -- User not found in tenant TSecGroup for ReadSubProject' );	\
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
