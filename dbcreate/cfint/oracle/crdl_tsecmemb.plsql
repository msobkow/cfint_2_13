--
--	@(#) dbcreate/cfint/oracle/crdl_tsecmemb.plsql
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

create or replace procedure cfinet213.dl_tsecmemb(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argTSecGrpMembId numeric,
	argRevision int ) authid definer
is
	use_stamp cfinet213.TSecMemb_h.auditstamp%type;
	oldTenantId numeric(22,0);
	oldTSecGrpMembId numeric(22,0);
	oldTSecGroupId integer;
	oldSecUserId varchar2(36);
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			TenantId,
			TSecGrpMembId,
			TSecGroupId,
			SecUserId,
			revision
		into
			oldTenantId,
			oldTSecGrpMembId,
			oldTSecGroupId,
			oldSecUserId,
			oldRevision
		from cfinet213.TSecMemb
		where
			TenantId = argTenantId
			and TSecGrpMembId = argTSecGrpMembId
		for update;

	if( oldTenantId != secTenantId )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfinet213.sp_is_tenant_user( oldTenantId,
		'DeleteTSecGrpMemb',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfinet213.TSecMemb_h (
			TenantId,
			TSecGrpMembId,
			revision,
			auditclusterid,
			auditsessionid,
			TSecGroupId,
			SecUserId,
			auditaction,
			auditstamp )
		select
			a018.TenantId as TenantId,
			a018.TSecGrpMembId as TSecGrpMembId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a018.TSecGroupId as TSecGroupId,
			a018.SecUserId as SecUserId,
			2,
			use_stamp
		from cfinet213.TSecMemb a018
		where
			a018.TenantId = argTenantId
			and a018.TSecGrpMembId = argTSecGrpMembId;

	delete from cfinet213.TSecMemb
	where
		TenantId = argTenantId
		and TSecGrpMembId = argTSecGrpMembId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_tsecmemb;
/

show errors procedure cfinet213.dl_tsecmemb;
