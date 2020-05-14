--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_hostnode_by_udescridx.pgsql
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
create or replace function cfinet213.sp_delete_hostnode_by_udescridx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argDescription varchar(255) )
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
					a002.clusterid as clusterid,
						a002.hostnodeid as hostnodeid,
					a002.revision as revision
			from cfinet213.HostNode as a002
			where
					a002.clusterid = argClusterId
			and a002.description = argDescription
		loop
				select cfinet213.sp_delete_hostnode( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.clusterid,
							cur.hostnodeid,
						cur.revision )
					into subret;
		end loop;
	else
		for cur in
			select
					a002.clusterid as clusterid,
						a002.hostnodeid as hostnodeid,
					a002.revision as revision
			from cfinet213.HostNode as a002
			where
					a002.clusterid = argClusterId
			and a002.description = argDescription
					and a002.ClusterId = secClusterId
		loop
				select cfinet213.sp_delete_hostnode( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.clusterid,
							cur.hostnodeid,
						cur.revision )
					into subret;
		end loop;
	end if;
	return true;
end;
$$ language plpgsql;