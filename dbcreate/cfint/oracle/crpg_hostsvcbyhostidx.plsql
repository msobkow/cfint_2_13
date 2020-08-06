--
--	@(#) dbcreate/cfint/oracle/crpg_hostsvcbyhostidx.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfinet213.pg_hostsvcbyhostidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argHostNodeId numeric,
	priorClusterId numeric,
	priorServiceId numeric ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfinet213.sp_is_cluster_user( secClusterId,
			'ReadService',
			argAuditUserId );
	isSystemUser := cfinet213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( ( isSystemUser = 1 ) and ( ( priorClusterId is not null )and ( priorServiceId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.ClusterId as ClusterId,
			a012.ServiceId as ServiceId,
			a012.HostNodeId as HostNodeId,
			a012.ServiceTypeId as ServiceTypeId,
			a012.HostPort as HostPort,
					a012.revision as revision
				from cfinet213.HostSvc a012
				where
					a012.ClusterId = argClusterId
			and a012.HostNodeId = argHostNodeId
			and ( ( ( a012.ClusterId = priorClusterId )
					and ( a012.ServiceId < priorServiceId ) )
				or ( ( a012.ClusterId < priorClusterId ) ) )
		order by ClusterId desc,
			ServiceId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 1 ) and ( not ( ( priorClusterId is not null )and ( priorServiceId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.ClusterId as ClusterId,
			a012.ServiceId as ServiceId,
			a012.HostNodeId as HostNodeId,
			a012.ServiceTypeId as ServiceTypeId,
			a012.HostPort as HostPort,
					a012.revision as revision
				from cfinet213.HostSvc a012
				where
					a012.ClusterId = argClusterId
			and a012.HostNodeId = argHostNodeId
		order by ClusterId desc,
			ServiceId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( ( priorClusterId is not null )and ( priorServiceId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.ClusterId as ClusterId,
			a012.ServiceId as ServiceId,
			a012.HostNodeId as HostNodeId,
			a012.ServiceTypeId as ServiceTypeId,
			a012.HostPort as HostPort,
					a012.revision as revision
				from cfinet213.HostSvc a012
				where
					a012.ClusterId = argClusterId
			and a012.HostNodeId = argHostNodeId
					and a012.ClusterId = secClusterId
			and ( ( ( a012.ClusterId = priorClusterId )
					and ( a012.ServiceId < priorServiceId ) )
				or ( ( a012.ClusterId < priorClusterId ) ) )
		order by ClusterId desc,
			ServiceId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( not ( ( priorClusterId is not null )and ( priorServiceId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a012.createdby,
			to_char( a012.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a012.updatedby,
			to_char( a012.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a012.ClusterId as ClusterId,
			a012.ServiceId as ServiceId,
			a012.HostNodeId as HostNodeId,
			a012.ServiceTypeId as ServiceTypeId,
			a012.HostPort as HostPort,
					a012.revision as revision
				from cfinet213.HostSvc a012
				where
					a012.ClusterId = argClusterId
			and a012.HostNodeId = argHostNodeId
					and a012.ClusterId = secClusterId
		order by ClusterId desc,
			ServiceId desc
			) where ROWNUM <= 25;
	end if;
end pg_hostsvcbyhostidx;
/

show errors procedure cfinet213.pg_hostsvcbyhostidx;