--
--	@(#) dbcreate/cfint/oracle/crcrt_iso_cntrylng.plsql
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

create or replace procedure cfinet213.crt_iso_cntrylng(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argISOCtryId smallint,
	argISOLangId smallint ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.iso_cntrylng_h.auditstamp%type;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a006' )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	insert into cfinet213.iso_cntrylng(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ISOCtryId,
		ISOLangId,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argISOCtryId,
		argISOLangId,
		1 );
	insert into cfinet213.iso_cntrylng_h (
			ISOCtryId,
			ISOLangId,
			revision,
			auditclusterid,
			auditsessionid,
			auditaction,
			auditstamp )
		select
			a006.ISOCtryId as ISOCtryId,
			a006.ISOLangId as ISOLangId,
			a006.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			0,
			use_stamp
		from cfinet213.iso_cntrylng a006
		where
			a006.ISOCtryId = argISOCtryId
			and a006.ISOLangId = argISOLangId;

	open retCursor for select
			a006.createdby,
			to_char( a006.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a006.updatedby,
			to_char( a006.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a006.ISOCtryId as ISOCtryId,
			a006.ISOLangId as ISOLangId,
		a006.revision as revision
	from cfinet213.iso_cntrylng a006
	where
		a006.ISOCtryId = argISOCtryId
			and a006.ISOLangId = argISOLangId;
end crt_iso_cntrylng;
/

show errors procedure cfinet213.crt_iso_cntrylng;
