--
--	@(#) dbcreate/cfint/pgsql/crsp_lock_tenant.pgsql
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

create or replace function cfinet213.sp_lock_tenant(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argId bigint )
returns setof cfinet213.type_tenant_rec as $$
begin
	return query select
			a015.createdby,
			to_char( a015.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a015.updatedby,
			to_char( a015.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a015.clusterid as clusterid,
			a015.id as id,
			a015.tenantname as tenantname,
			a015.revision as revision
	from cfinet213.tenant as a015
	where
			a015.id = argId
	for update;
	return;
end;
$$ language plpgsql;
