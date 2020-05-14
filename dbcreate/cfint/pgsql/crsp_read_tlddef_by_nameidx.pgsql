--
--	@(#) dbcreate/cfint/pgsql/crsp_read_tlddef_by_nameidx.pgsql
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
create or replace function cfinet213.sp_read_tlddef_by_nameidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argName varchar(64) )
returns setof cfinet213.type_tlddef_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfinet213.sp_is_tenant_user( secTenantId,
			'ReadTld',
			argAuditUserId ),
		cfinet213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for ReadTld';
	end if;
	if( isSystemUser )
	then
		return query select
			a106.createdby,
			to_char( a106.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a106.updatedby,
			to_char( a106.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a106.tenantid as tenantid,
			a106.id as id,
			a106.safe_name as safe_name,
			a106.descr as descr,
			a106.revision as revision
		from cfinet213.tlddef as a106
		where
			a106.tenantid = argTenantId
			and a106.safe_name = argName;
	else
		return query select
			a106.createdby,
			to_char( a106.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a106.updatedby,
			to_char( a106.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a106.tenantid as tenantid,
			a106.id as id,
			a106.safe_name as safe_name,
			a106.descr as descr,
			a106.revision as revision
		from cfinet213.tlddef as a106
		where
			a106.tenantid = argTenantId
			and a106.safe_name = argName
			and a106.TenantId = secTenantId;
	end if;
	return;
end
$$ language plpgsql;
