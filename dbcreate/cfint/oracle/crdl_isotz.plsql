--
--	@(#) dbcreate/cfint/oracle/crdl_isotz.plsql
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

create or replace procedure cfinet213.dl_isotz(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argISOTZoneId smallint,
	argRevision int ) authid definer
is
	use_stamp cfinet213.ISOTz_h.auditstamp%type;
	oldISOTZoneId smallint;
	oldIso8601 varchar2(6);
	oldTZName varchar2(64);
	oldTZHourOffset smallint;
	oldTZMinOffset smallint;
	oldDescription varchar2(128);
	oldVisible char(1);
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			ISOTZoneId,
			Iso8601,
			TZName,
			TZHourOffset,
			TZMinOffset,
			Description,
			Visible,
			revision
		into
			oldISOTZoneId,
			oldIso8601,
			oldTZName,
			oldTZHourOffset,
			oldTZMinOffset,
			oldDescription,
			oldVisible,
			oldRevision
		from cfinet213.ISOTz
		where
			ISOTZoneId = argISOTZoneId
		for update;

	permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

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
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a008.Iso8601 as Iso8601,
			a008.TZName as TZName,
			a008.TZHourOffset as TZHourOffset,
			a008.TZMinOffset as TZMinOffset,
			a008.Description as Description,
			a008.Visible as Visible,
			2,
			use_stamp
		from cfinet213.ISOTz a008
		where
			a008.ISOTZoneId = argISOTZoneId;

	delete from cfinet213.ISOTz
	where
		ISOTZoneId = argISOTZoneId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_isotz;
/

show errors procedure cfinet213.dl_isotz;
