--
--	@(#) dbcreate/cfint/oracle/crdl_hostsvc.plsql
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

create or replace procedure cfinet213.dl_hostsvc(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argServiceId numeric,
	argRevision int ) authid definer
is
	use_stamp cfinet213.HostSvc_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldServiceId numeric(22,0);
	oldHostNodeId numeric(22,0);
	oldServiceTypeId integer;
	oldHostPort smallint;
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			ClusterId,
			ServiceId,
			HostNodeId,
			ServiceTypeId,
			HostPort,
			revision
		into
			oldClusterId,
			oldServiceId,
			oldHostNodeId,
			oldServiceTypeId,
			oldHostPort,
			oldRevision
		from cfinet213.HostSvc
		where
			ClusterId = argClusterId
			and ServiceId = argServiceId
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
		'DeleteService',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfinet213.HostSvc_h (
			ClusterId,
			ServiceId,
			revision,
			auditclusterid,
			auditsessionid,
			HostNodeId,
			ServiceTypeId,
			HostPort,
			auditaction,
			auditstamp )
		select
			a012.ClusterId as ClusterId,
			a012.ServiceId as ServiceId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a012.HostNodeId as HostNodeId,
			a012.ServiceTypeId as ServiceTypeId,
			a012.HostPort as HostPort,
			2,
			use_stamp
		from cfinet213.HostSvc a012
		where
			a012.ClusterId = argClusterId
			and a012.ServiceId = argServiceId;

	delete from cfinet213.HostSvc
	where
		ClusterId = argClusterId
		and ServiceId = argServiceId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_hostsvc;
/

show errors procedure cfinet213.dl_hostsvc;