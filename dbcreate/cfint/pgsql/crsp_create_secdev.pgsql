--
--	@(#) dbcreate/cfint/pgsql/crsp_create_secdev.pgsql
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
create or replace function cfinet213.sp_create_secdev(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argSecUserId varchar(36),
	argDevName varchar(127),
	argPubKey text )
returns setof cfinet213.type_secdev_rec as $$
declare
	permissionFlag boolean;
begin
	if( argClassCode = 'a00a' )
	then
		select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can create SecDevice records';
		end if;
	end if;

	insert into cfinet213.secdev(
		createdby,
		createdat,
		updatedby,
		updatedat,
		secuserid,
		devname,
		pubkey,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argSecUserId,
		argDevName,
		argPubKey,
		1 );
	insert into cfinet213.SecDev_h (
			SecUserId,
			DevName,
			auditclusterid,
			auditsessionid,
			auditstamp,
			PubKey,
			revision,
			auditaction )
		select
			a00a.SecUserId,
			a00a.DevName,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a00a.PubKey,
			a00a.revision,
			0
		from cfinet213.SecDev as a00a
		where
			a00a.secuserid = argSecUserId
			and a00a.devname = argDevName;

	return query select
			a00a.createdby,
			to_char( a00a.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00a.updatedby,
			to_char( a00a.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00a.secuserid as secuserid,
			a00a.devname as devname,
			a00a.pubkey as pubkey,
			a00a.revision as revision
	from cfinet213.SecDev as a00a
	where
			a00a.secuserid = argSecUserId
			and a00a.devname = argDevName;

	return;
end;
$$ language plpgsql;
