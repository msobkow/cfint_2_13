--
--	@(#) dbcreate/cfint/pgsql/crsp_update_iso_ccy.pgsql
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

create or replace function cfinet213.sp_update_iso_ccy(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argISOCcyId smallint,
	argISOCode varchar(3),
	argName varchar(64),
	argUnitSymbol varchar(4),
	argPrecis smallint,
	argRevision integer )
returns setof cfinet213.type_iso_ccy_rec as $$
declare
	RowsAffected integer;
	oldISOCcyId smallint;
	oldISOCode varchar(3);
	oldName varchar(64);
	oldUnitSymbol varchar(4);
	oldPrecis smallint;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a003' )
	then
		select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update ISOCcy records';
		end if;
	end if;

		select
			ISOCcyId,
			iso_code,
			ccy_name,
			unit_symbol,
			precis,
			revision
		into
			oldISOCcyId,
			oldISOCode,
			oldName,
			oldUnitSymbol,
			oldPrecis,
			oldRevision
		from cfinet213.iso_ccy
		where
			ISOCcyId = argISOCcyId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_iso_ccy() Data collision detected';
	end if;


	update cfinet213.iso_ccy
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		iso_code = argISOCode,
		ccy_name = argName,
		unit_symbol = argUnitSymbol,
		precis = argPrecis
	where
		ISOCcyId = argISOCcyId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_iso_ccy() Expected to affect one iso_ccy row, not %', RowsAffected;
	end if;


	insert into cfinet213.iso_ccy_h (
			ISOCcyId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			iso_code,
			ccy_name,
			unit_symbol,
			precis,
			revision,
			auditaction )
		select
			a003.ISOCcyId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a003.iso_code,
			a003.ccy_name,
			a003.unit_symbol,
			a003.precis,
			argRevision + 1,
			1
		from cfinet213.iso_ccy as a003
		where
			a003.isoccyid = argISOCcyId;
	return query select
			a003.createdby,
			to_char( a003.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a003.updatedby,
			to_char( a003.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a003.isoccyid as isoccyid,
			a003.iso_code as iso_code,
			a003.ccy_name as ccy_name,
			a003.unit_symbol as unit_symbol,
			a003.precis as precis,
		a003.revision as revision
	from cfinet213.iso_ccy as a003
	where
		a003.isoccyid = argISOCcyId;

	return;
end;
$$ language plpgsql;
