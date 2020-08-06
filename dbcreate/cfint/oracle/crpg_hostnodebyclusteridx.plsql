--
--	@(#) dbcreate/cfint/oracle/crpg_hostnodebyclusteridx.plsql
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

create or replace procedure cfinet213.pg_hostnodebyclusteridx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	priorClusterId numeric,
	priorHostNodeId numeric ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfinet213.sp_is_cluster_user( secClusterId,
			'ReadHostNode',
			argAuditUserId );
	isSystemUser := cfinet213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( ( isSystemUser = 1 ) and ( ( priorClusterId is not null )and ( priorHostNodeId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a002.createdby,
			to_char( a002.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a002.updatedby,
			to_char( a002.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a002.ClusterId as ClusterId,
			a002.HostNodeId as HostNodeId,
			a002.Description as Description,
			a002.HostName as HostName,
					a002.revision as revision
				from cfinet213.HostNode a002
				where
					a002.ClusterId = argClusterId
			and ( ( ( a002.ClusterId = priorClusterId )
					and ( a002.HostNodeId < priorHostNodeId ) )
				or ( ( a002.ClusterId < priorClusterId ) ) )
		order by ClusterId desc,
			HostNodeId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 1 ) and ( not ( ( priorClusterId is not null )and ( priorHostNodeId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a002.createdby,
			to_char( a002.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a002.updatedby,
			to_char( a002.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a002.ClusterId as ClusterId,
			a002.HostNodeId as HostNodeId,
			a002.Description as Description,
			a002.HostName as HostName,
					a002.revision as revision
				from cfinet213.HostNode a002
				where
					a002.ClusterId = argClusterId
		order by ClusterId desc,
			HostNodeId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( ( priorClusterId is not null )and ( priorHostNodeId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a002.createdby,
			to_char( a002.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a002.updatedby,
			to_char( a002.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a002.ClusterId as ClusterId,
			a002.HostNodeId as HostNodeId,
			a002.Description as Description,
			a002.HostName as HostName,
					a002.revision as revision
				from cfinet213.HostNode a002
				where
					a002.ClusterId = argClusterId
					and a002.ClusterId = secClusterId
			and ( ( ( a002.ClusterId = priorClusterId )
					and ( a002.HostNodeId < priorHostNodeId ) )
				or ( ( a002.ClusterId < priorClusterId ) ) )
		order by ClusterId desc,
			HostNodeId desc
			) where ROWNUM <= 25;
	end if;
	if( ( isSystemUser = 0 ) and ( not ( ( priorClusterId is not null )and ( priorHostNodeId is not null ) ) ) )
	then
		open retCursor for
			select * from (
				select
			a002.createdby,
			to_char( a002.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a002.updatedby,
			to_char( a002.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a002.ClusterId as ClusterId,
			a002.HostNodeId as HostNodeId,
			a002.Description as Description,
			a002.HostName as HostName,
					a002.revision as revision
				from cfinet213.HostNode a002
				where
					a002.ClusterId = argClusterId
					and a002.ClusterId = secClusterId
		order by ClusterId desc,
			HostNodeId desc
			) where ROWNUM <= 25;
	end if;
end pg_hostnodebyclusteridx;
/

show errors procedure cfinet213.pg_hostnodebyclusteridx;