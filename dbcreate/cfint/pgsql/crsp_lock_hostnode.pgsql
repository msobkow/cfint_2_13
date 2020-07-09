--
--	@(#) dbcreate/cfint/pgsql/crsp_lock_hostnode.pgsql
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

create or replace function cfinet213.sp_lock_hostnode(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argHostNodeId bigint )
returns setof cfinet213.type_hostnode_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfinet213.sp_is_cluster_user( secClusterId,
			'ReadHostNode',
			argAuditUserId ),
		cfinet213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for ReadHostNode';
	end if;
	if( isSystemUser )
	then
		return query select
			a002.createdby,
			to_char( a002.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a002.updatedby,
			to_char( a002.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a002.clusterid as clusterid,
			a002.hostnodeid as hostnodeid,
			a002.description as description,
			a002.hostname as hostname,
			a002.revision as revision
		from cfinet213.HostNode as a002
		where
			a002.clusterid = argClusterId
			and a002.hostnodeid = argHostNodeId
		for update;
	else
		return query select
			a002.createdby,
			to_char( a002.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a002.updatedby,
			to_char( a002.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a002.clusterid as clusterid,
			a002.hostnodeid as hostnodeid,
			a002.description as description,
			a002.hostname as hostname,
			a002.revision as revision
		from cfinet213.HostNode as a002
		where
			a002.clusterid = argClusterId
			and a002.hostnodeid = argHostNodeId
			and a002.ClusterId = secClusterId
		for update;
	end if;
	return;
end;
$$ language plpgsql;
