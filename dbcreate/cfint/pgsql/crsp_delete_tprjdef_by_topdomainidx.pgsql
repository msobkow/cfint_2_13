--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_tprjdef_by_topdomainidx.pgsql
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
create or replace function cfinet213.sp_delete_tprjdef_by_topdomainidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argTopDomainId bigint )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
begin
	select cfinet213.sp_is_system_user( argAuditUserId ) into subret;
	if( subret )
	then
		for cur in
			select
					a108.tenantid as tenantid,
						a108.id as id,
					a108.revision as revision
			from cfinet213.tprjdef as a108
			where
					a108.tenantid = argTenantId
			and a108.topdomainid = argTopDomainId
		loop
				select cfinet213.sp_delete_tprjdef( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.tenantid,
							cur.id,
						cur.revision )
					into subret;
		end loop;
	else
		for cur in
			select
					a108.tenantid as tenantid,
						a108.id as id,
					a108.revision as revision
			from cfinet213.tprjdef as a108
			where
					a108.tenantid = argTenantId
			and a108.topdomainid = argTopDomainId
					and a108.TenantId = secTenantId
		loop
				select cfinet213.sp_delete_tprjdef( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.tenantid,
							cur.id,
						cur.revision )
					into subret;
		end loop;
	end if;
	return true;
end;
$$ language plpgsql;
