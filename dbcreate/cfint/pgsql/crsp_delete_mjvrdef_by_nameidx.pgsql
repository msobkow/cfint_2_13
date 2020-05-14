--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_mjvrdef_by_nameidx.pgsql
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
create or replace function cfinet213.sp_delete_mjvrdef_by_nameidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argTenantId bigint,
	argSubProjectId bigint,
	argName varchar(64) )
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
					a102.tenantid as tenantid,
						a102.id as id,
					a102.revision as revision
			from cfinet213.mjvrdef as a102
			where
					a102.tenantid = argTenantId
			and a102.subprojectid = argSubProjectId
			and a102.safe_name = argName
		loop
				select cfinet213.sp_delete_mjvrdef( argAuditClusterId,
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
					a102.tenantid as tenantid,
						a102.id as id,
					a102.revision as revision
			from cfinet213.mjvrdef as a102
			where
					a102.tenantid = argTenantId
			and a102.subprojectid = argSubProjectId
			and a102.safe_name = argName
					and a102.TenantId = secTenantId
		loop
				select cfinet213.sp_delete_mjvrdef( argAuditClusterId,
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
