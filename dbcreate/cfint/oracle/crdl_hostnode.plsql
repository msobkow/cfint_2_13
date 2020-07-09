--
--	@(#) dbcreate/cfint/oracle/crdl_hostnode.plsql
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

create or replace procedure cfinet213.dl_hostnode(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argHostNodeId numeric,
	argRevision int ) authid definer
is
	use_stamp cfinet213.HostNode_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldHostNodeId numeric(22,0);
	oldDescription varchar2(255);
	oldHostName varchar2(192);
	oldRevision integer;
	cursor cursDelServices is
		select
			a012.ClusterId,
			a012.ServiceId
		from cfinet213.HostNode a002
			inner join cfinet213.hostsvc a012 on
				a002.ClusterId = a012.ClusterId
				and a002.HostNodeId = a012.HostNodeId
		where
			a002.ClusterId = argClusterId
			and a002.HostNodeId = argHostNodeId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			ClusterId,
			HostNodeId,
			Description,
			HostName,
			revision
		into
			oldClusterId,
			oldHostNodeId,
			oldDescription,
			oldHostName,
			oldRevision
		from cfinet213.HostNode
		where
			ClusterId = argClusterId
			and HostNodeId = argHostNodeId
		for update;

	if( oldClusterId != secClusterId )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfinet213.sp_is_cluster_user( oldClusterId,
		'DeleteHostNode',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfinet213.HostNode_h (
			ClusterId,
			HostNodeId,
			revision,
			auditclusterid,
			auditsessionid,
			Description,
			HostName,
			auditaction,
			auditstamp )
		select
			a002.ClusterId as ClusterId,
			a002.HostNodeId as HostNodeId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a002.Description as Description,
			a002.HostName as HostName,
			2,
			use_stamp
		from cfinet213.HostNode a002
		where
			a002.ClusterId = argClusterId
			and a002.HostNodeId = argHostNodeId;

	for cur in cursDelServices
	loop
		cfinet213.dl_hostsvcbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.ServiceId );
	end loop;
	delete from cfinet213.HostNode
	where
		ClusterId = argClusterId
		and HostNodeId = argHostNodeId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_hostnode;
/

show errors procedure cfinet213.dl_hostnode;
