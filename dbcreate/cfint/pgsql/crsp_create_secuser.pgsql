--
--	@(#) dbcreate/cfint/pgsql/crsp_create_secuser.pgsql
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
create or replace function cfinet213.sp_create_secuser(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argSecUserId varchar(36),
	argLoginId varchar(32),
	argEMailAddress varchar(192),
	argEMailConfirmUuid varchar(36),
	argDfltDevUserId varchar(36),
	argDfltDevName varchar(127),
	argPasswordHash varchar(256),
	argPasswordResetUuid varchar(36) )
returns setof cfinet213.type_secuser_rec as $$
declare
	permissionFlag boolean;
begin
	if( argClassCode = 'a011' )
	then
		select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can create SecUser records';
		end if;
	end if;

	insert into cfinet213.secuser(
		createdby,
		createdat,
		updatedby,
		updatedat,
		secuserid,
		login_id,
		email_addr,
		em_confuuid,
		defdevuserid,
		defdevname,
		pwd_hash,
		pwdrstuuid,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argSecUserId,
		argLoginId,
		argEMailAddress,
		argEMailConfirmUuid,
		argDfltDevUserId,
		argDfltDevName,
		argPasswordHash,
		argPasswordResetUuid,
		1 );
	insert into cfinet213.SecUser_h (
			SecUserId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			login_id,
			email_addr,
			em_confuuid,
			DefDevUserId,
			DefDevName,
			pwd_hash,
			pwdrstuuid,
			revision,
			auditaction )
		select
			a011.SecUserId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a011.login_id,
			a011.email_addr,
			a011.em_confuuid,
			a011.DefDevUserId,
			a011.DefDevName,
			a011.pwd_hash,
			a011.pwdrstuuid,
			a011.revision,
			0
		from cfinet213.SecUser as a011
		where
			a011.secuserid = argSecUserId;

	return query select
			a011.createdby,
			to_char( a011.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a011.updatedby,
			to_char( a011.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a011.secuserid as secuserid,
			a011.login_id as login_id,
			a011.email_addr as email_addr,
			a011.em_confuuid as em_confuuid,
			a011.defdevuserid as defdevuserid,
			a011.defdevname as defdevname,
			a011.pwd_hash as pwd_hash,
			a011.pwdrstuuid as pwdrstuuid,
			a011.revision as revision
	from cfinet213.SecUser as a011
	where
			a011.secuserid = argSecUserId;

	return;
end;
$$ language plpgsql;
