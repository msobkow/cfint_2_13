--
--	@(#) dbcreate/cfint/oracle/crcrt_iso_cntryccy.plsql
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

create or replace procedure cfinet213.crt_iso_cntryccy(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argISOCtryId smallint,
	argISOCcyId smallint ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.iso_cntryccy_h.auditstamp%type;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a005' )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	insert into cfinet213.iso_cntryccy(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ISOCtryId,
		ISOCcyId,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argISOCtryId,
		argISOCcyId,
		1 );
	insert into cfinet213.iso_cntryccy_h (
			ISOCtryId,
			ISOCcyId,
			revision,
			auditclusterid,
			auditsessionid,
			auditaction,
			auditstamp )
		select
			a005.ISOCtryId as ISOCtryId,
			a005.ISOCcyId as ISOCcyId,
			a005.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			0,
			use_stamp
		from cfinet213.iso_cntryccy a005
		where
			a005.ISOCtryId = argISOCtryId
			and a005.ISOCcyId = argISOCcyId;

	open retCursor for select
			a005.createdby,
			to_char( a005.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a005.updatedby,
			to_char( a005.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a005.ISOCtryId as ISOCtryId,
			a005.ISOCcyId as ISOCcyId,
		a005.revision as revision
	from cfinet213.iso_cntryccy a005
	where
		a005.ISOCtryId = argISOCtryId
			and a005.ISOCcyId = argISOCcyId;
end crt_iso_cntryccy;
/

show errors procedure cfinet213.crt_iso_cntryccy;
