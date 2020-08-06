--
--	@(#) dbcreate/cfint/pgsql/crsp_page_hostsvc_by_hostidx.pgsql
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
create or replace function cfinet213.sp_page_hostsvc_by_hostidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argHostNodeId bigint,
	priorClusterId bigint,
	priorServiceId bigint )
returns setof cfinet213.type_hostsvc_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfinet213.sp_is_cluster_user( secClusterId,
			'ReadService',
			argAuditUserId ),
		cfinet213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for ReadService';
	end if;
	if( isSystemUser )
	then
		if( ( priorClusterId is not null )and ( priorServiceId is not null ) )
		then
			return query select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.clusterid as clusterid,
			a012.serviceid as serviceid,
			a012.hostnodeid as hostnodeid,
			a012.servicetypeid as servicetypeid,
			a012.hostport as hostport,
				a012.revision as revision
			from cfinet213.HostSvc as a012
			where
				a012.clusterid = argClusterId
			and a012.hostnodeid = argHostNodeId
			and ( ( ( a012.ClusterId = priorClusterId )
					and ( a012.ServiceId < priorServiceId ) )
				or ( ( a012.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					ServiceId desc
			limit 25;
		else
			return query select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.clusterid as clusterid,
			a012.serviceid as serviceid,
			a012.hostnodeid as hostnodeid,
			a012.servicetypeid as servicetypeid,
			a012.hostport as hostport,
				a012.revision as revision
			from cfinet213.HostSvc as a012
			where
				a012.clusterid = argClusterId
			and a012.hostnodeid = argHostNodeId
				order by ClusterId desc,
					ServiceId desc
			limit 25;
		end if;
	else
		if( ( priorClusterId is not null )and ( priorServiceId is not null ) )
		then
			return query select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.clusterid as clusterid,
			a012.serviceid as serviceid,
			a012.hostnodeid as hostnodeid,
			a012.servicetypeid as servicetypeid,
			a012.hostport as hostport,
				a012.revision as revision
			from cfinet213.HostSvc as a012
			where
				a012.clusterid = argClusterId
			and a012.hostnodeid = argHostNodeId
				and a012.ClusterId = secClusterId
			and ( ( ( a012.ClusterId = priorClusterId )
					and ( a012.ServiceId < priorServiceId ) )
				or ( ( a012.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					ServiceId desc
			limit 25;
		else
			return query select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.clusterid as clusterid,
			a012.serviceid as serviceid,
			a012.hostnodeid as hostnodeid,
			a012.servicetypeid as servicetypeid,
			a012.hostport as hostport,
				a012.revision as revision
			from cfinet213.HostSvc as a012
			where
				a012.clusterid = argClusterId
			and a012.hostnodeid = argHostNodeId
				and a012.ClusterId = secClusterId
				order by ClusterId desc,
					ServiceId desc
			limit 25;
		end if;
	end if;
	return;
end
$$ language plpgsql;
