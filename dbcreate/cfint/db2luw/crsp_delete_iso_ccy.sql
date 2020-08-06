--
--	@(#) dbcreate/cfint/db2luw/crsp_delete_iso_ccy.sql
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
create or replace procedure sp_delete_iso_ccy(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argISOCcyId smallint,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldISOCcyId smallint;	\
	declare oldISOCode varchar(3);	\
	declare oldName varchar(64);	\
	declare oldUnitSymbol varchar(4);	\
	declare oldPrecis smallint;	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			ISOCcyId,	\
			iso_code,	\
			ccy_name,	\
			unit_symbol,	\
			precis,	\
			revision	\
		into	\
			oldISOCcyId,	\
			oldISOCode,	\
			oldName,	\
			oldUnitSymbol,	\
			oldPrecis,	\
			oldRevision	\
		from cfinet213.iso_ccy	\
		where	\
			ISOCcyId = argISOCcyId	\
		for update;	\
	\
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete ISOCcy records' );	\
		end if;	\
	\
	\
		insert into cfinet213.iso_ccy_h (	\
				isoccyid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				iso_code,	\
				ccy_name,	\
				unit_symbol,	\
				precis,	\
			revision,	\
			auditaction )	\
		select	\
				a003.isoccyid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a003.iso_code,	\
				a003.ccy_name,	\
				a003.unit_symbol,	\
				a003.precis,	\
			a003.revision + 1,	\
			2	\
		from cfinet213.iso_ccy as a003	\
		where	\
			a003.isoccyid = argISOCcyId;	\
	\
		delete from cfinet213.iso_ccy	\
		where	\
			isoccyid = argISOCcyId;	\
	\
		open retcursor;	\
	end;	\
end
