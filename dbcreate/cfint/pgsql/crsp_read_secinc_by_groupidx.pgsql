--
--	@(#) dbcreate/cfint/pgsql/crsp_read_secinc_by_groupidx.pgsql
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
create or replace function cfinet213.sp_read_secinc_by_groupidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argSecGroupId integer )
returns setof cfinet213.type_secinc_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfinet213.sp_is_cluster_user( secClusterId,
			'ReadSecGrpInc',
			argAuditUserId ),
		cfinet213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for ReadSecGrpInc';
	end if;
	if( isSystemUser )
	then
		return query select
			a00e.createdby,
			to_char( a00e.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00e.updatedby,
			to_char( a00e.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00e.clusid as clusid,
			a00e.secgrpincid as secgrpincid,
			a00e.secgrpid as secgrpid,
			a00e.incgrpid as incgrpid,
			a00e.revision as revision
		from cfinet213.SecInc as a00e
		where
			a00e.clusid = argClusterId
			and a00e.secgrpid = argSecGroupId
				order by ClusId desc,
					SecGrpIncId desc;
	else
		return query select
			a00e.createdby,
			to_char( a00e.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00e.updatedby,
			to_char( a00e.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00e.clusid as clusid,
			a00e.secgrpincid as secgrpincid,
			a00e.secgrpid as secgrpid,
			a00e.incgrpid as incgrpid,
			a00e.revision as revision
		from cfinet213.SecInc as a00e
		where
			a00e.clusid = argClusterId
			and a00e.secgrpid = argSecGroupId
			and a00e.ClusId = secClusterId
				order by ClusId desc,
					SecGrpIncId desc;
	end if;
	return;
end
$$ language plpgsql;