--
--	@(#) dbcreate/cfint/oracle/crcrt_isotz.plsql
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

create or replace procedure cfinet213.crt_isotz(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argIso8601 varchar2,
	argTZName varchar2,
	argTZHourOffset smallint,
	argTZMinOffset smallint,
	argDescription varchar2,
	argVisible char ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.ISOTz_h.auditstamp%type;
	permissionFlag integer;
	argISOTZoneId smallint;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a008' )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argISOTZoneId := cfinet213.nxt_isotzoneidgen();
	insert into cfinet213.isotz(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ISOTZoneId,
		Iso8601,
		TZName,
		TZHourOffset,
		TZMinOffset,
		Description,
		Visible,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argISOTZoneId,
		argIso8601,
		argTZName,
		argTZHourOffset,
		argTZMinOffset,
		argDescription,
		argVisible,
		1 );
	insert into cfinet213.ISOTz_h (
			ISOTZoneId,
			revision,
			auditclusterid,
			auditsessionid,
			Iso8601,
			TZName,
			TZHourOffset,
			TZMinOffset,
			Description,
			Visible,
			auditaction,
			auditstamp )
		select
			a008.ISOTZoneId as ISOTZoneId,
			a008.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a008.Iso8601 as Iso8601,
			a008.TZName as TZName,
			a008.TZHourOffset as TZHourOffset,
			a008.TZMinOffset as TZMinOffset,
			a008.Description as Description,
			a008.Visible as Visible,
			0,
			use_stamp
		from cfinet213.ISOTz a008
		where
			a008.ISOTZoneId = argISOTZoneId;

	open retCursor for select
			a008.createdby,
			to_char( a008.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a008.updatedby,
			to_char( a008.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a008.ISOTZoneId as ISOTZoneId,
			a008.Iso8601 as Iso8601,
			a008.TZName as TZName,
			a008.TZHourOffset as TZHourOffset,
			a008.TZMinOffset as TZMinOffset,
			a008.Description as Description,
			a008.Visible as Visible,
		a008.revision as revision
	from cfinet213.ISOTz a008
	where
		a008.ISOTZoneId = argISOTZoneId;
end crt_isotz;
/

show errors procedure cfinet213.crt_isotz;
