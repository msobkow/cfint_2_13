--
--	@(#) dbcreate/cfint/pgsql/crsp_read_tdomdef_by_tldidx.pgsql
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
create or replace function cfinet213.sp_read_tdomdef_by_tldidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argTldId bigint )
returns setof cfinet213.type_tdomdef_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfinet213.sp_is_tenant_user( secTenantId,
			'ReadTopDomain',
			argAuditUserId ),
		cfinet213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for ReadTopDomain';
	end if;
	if( isSystemUser )
	then
		return query select
			a107.createdby,
			to_char( a107.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a107.updatedby,
			to_char( a107.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a107.tenantid as tenantid,
			a107.id as id,
			a107.tldid as tldid,
			a107.safe_name as safe_name,
			a107.descr as descr,
			a107.revision as revision
		from cfinet213.tdomdef as a107
		where
			a107.tenantid = argTenantId
			and a107.tldid = argTldId
				order by TenantId desc,
					Id desc;
	else
		return query select
			a107.createdby,
			to_char( a107.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a107.updatedby,
			to_char( a107.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a107.tenantid as tenantid,
			a107.id as id,
			a107.tldid as tldid,
			a107.safe_name as safe_name,
			a107.descr as descr,
			a107.revision as revision
		from cfinet213.tdomdef as a107
		where
			a107.tenantid = argTenantId
			and a107.tldid = argTldId
			and a107.TenantId = secTenantId
				order by TenantId desc,
					Id desc;
	end if;
	return;
end
$$ language plpgsql;
