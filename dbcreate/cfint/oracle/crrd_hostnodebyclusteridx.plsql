--
--	@(#) dbcreate/cfint/oracle/crrd_hostnodebyclusteridx.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfinet213.rd_hostnodebyclusteridx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric ) authid definer
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
	if( isSystemUser = 1 )
	then
		open retCursor for select
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
			HostNodeId desc;
	else
		open retCursor for select
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
			HostNodeId desc;
	end if;
end rd_hostnodebyclusteridx;
/

show errors procedure cfinet213.rd_hostnodebyclusteridx;
