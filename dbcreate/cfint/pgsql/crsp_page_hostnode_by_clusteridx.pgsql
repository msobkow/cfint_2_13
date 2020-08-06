--
--	@(#) dbcreate/cfint/pgsql/crsp_page_hostnode_by_clusteridx.pgsql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--
create or replace function cfinet213.sp_page_hostnode_by_clusteridx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	priorClusterId bigint,
	priorHostNodeId bigint )
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
		if( ( priorClusterId is not null )and ( priorHostNodeId is not null ) )
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
			and ( ( ( a002.ClusterId = priorClusterId )
					and ( a002.HostNodeId < priorHostNodeId ) )
				or ( ( a002.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					HostNodeId desc
			limit 25;
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
				order by ClusterId desc,
					HostNodeId desc
			limit 25;
		end if;
	else
		if( ( priorClusterId is not null )and ( priorHostNodeId is not null ) )
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
				and a002.ClusterId = secClusterId
			and ( ( ( a002.ClusterId = priorClusterId )
					and ( a002.HostNodeId < priorHostNodeId ) )
				or ( ( a002.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					HostNodeId desc
			limit 25;
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
				and a002.ClusterId = secClusterId
				order by ClusterId desc,
					HostNodeId desc
			limit 25;
		end if;
	end if;
	return;
end
$$ language plpgsql;
