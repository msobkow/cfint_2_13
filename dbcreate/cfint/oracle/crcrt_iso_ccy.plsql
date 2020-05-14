--
--	@(#) dbcreate/cfint/oracle/crcrt_iso_ccy.plsql
--
--	com.github.msobkow.CFInt
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

create or replace procedure cfinet213.crt_iso_ccy(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argiso_code varchar2,
	argccy_name varchar2,
	argunit_symbol varchar2,
	argprecis smallint ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.iso_ccy_h.auditstamp%type;
	permissionFlag integer;
	argISOCcyId smallint;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a003' )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argISOCcyId := cfinet213.nxt_isoccyidgen();
	insert into cfinet213.iso_ccy(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ISOCcyId,
		iso_code,
		ccy_name,
		unit_symbol,
		precis,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argISOCcyId,
		argiso_code,
		argccy_name,
		argunit_symbol,
		argprecis,
		1 );
	insert into cfinet213.iso_ccy_h (
			ISOCcyId,
			revision,
			auditclusterid,
			auditsessionid,
			iso_code,
			ccy_name,
			unit_symbol,
			precis,
			auditaction,
			auditstamp )
		select
			a003.ISOCcyId as ISOCcyId,
			a003.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a003.iso_code as iso_code,
			a003.ccy_name as ccy_name,
			a003.unit_symbol as unit_symbol,
			a003.precis as precis,
			0,
			use_stamp
		from cfinet213.iso_ccy a003
		where
			a003.ISOCcyId = argISOCcyId;

	open retCursor for select
			a003.createdby,
			to_char( a003.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a003.updatedby,
			to_char( a003.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a003.ISOCcyId as ISOCcyId,
			a003.iso_code as iso_code,
			a003.ccy_name as ccy_name,
			a003.unit_symbol as unit_symbol,
			a003.precis as precis,
		a003.revision as revision
	from cfinet213.iso_ccy a003
	where
		a003.ISOCcyId = argISOCcyId;
end crt_iso_ccy;
/

show errors procedure cfinet213.crt_iso_ccy;
