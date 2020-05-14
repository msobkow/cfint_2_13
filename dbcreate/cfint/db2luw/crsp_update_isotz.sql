--
--	@(#) dbcreate/cfint/db2luw/crsp_update_isotz.sql
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

create or replace procedure sp_update_isotz(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argISOTZoneId smallint,	\
	in argIso8601 varchar(6),	\
	in argTZName varchar(64),	\
	in argTZHourOffset smallint,	\
	in argTZMinOffset smallint,	\
	in argDescription varchar(128),	\
	in argVisible char(1),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldISOTZoneId smallint;	\
	declare oldIso8601 varchar(6);	\
	declare oldTZName varchar(64);	\
	declare oldTZHourOffset smallint;	\
	declare oldTZMinOffset smallint;	\
	declare oldDescription varchar(128);	\
	declare oldVisible char(1);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a008.createdby as createdby,	\
				to_char( a008.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a008.updatedby as updatedby,	\
				to_char( a008.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a008.isotzoneid as isotzoneid,	\
			a008.iso8601 as iso8601,	\
			a008.tzname as tzname,	\
			a008.tzhouroffset as tzhouroffset,	\
			a008.tzminoffset as tzminoffset,	\
			a008.description as description,	\
			a008.visible as visible,	\
			a008.revision as revision	\
		from cfinet213.ISOTz as a008	\
		where	\
			a008.isotzoneid = argISOTZoneId;	\
	begin	\
		if( argClassCode = 'a008' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can update ISOTZone records' );	\
			end if;	\
		end if;	\
	\
		select	\
			ISOTZoneId,	\
			Iso8601,	\
			TZName,	\
			TZHourOffset,	\
			TZMinOffset,	\
			Description,	\
			Visible,	\
			revision	\
		into	\
			oldISOTZoneId,	\
			oldIso8601,	\
			oldTZName,	\
			oldTZHourOffset,	\
			oldTZMinOffset,	\
			oldDescription,	\
			oldVisible,	\
			oldRevision	\
		from cfinet213.ISOTz	\
		where	\
			ISOTZoneId = argISOTZoneId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_isotz() Data collision detected' );	\
		end if;	\
	\
		update cfinet213.ISOTz	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			iso8601 = argIso8601,	\
			tzname = argTZName,	\
			tzhouroffset = argTZHourOffset,	\
			tzminoffset = argTZMinOffset,	\
			description = argDescription,	\
			visible = argVisible	\
		where	\
			isotzoneid = argISOTZoneId	\
		and revision = argRevision;	\
	\
		insert into cfinet213.ISOTz_h (	\
				isotzoneid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				iso8601,	\
				tzname,	\
				tzhouroffset,	\
				tzminoffset,	\
				description,	\
				visible,	\
			revision,	\
			auditaction )	\
		select	\
				a008.isotzoneid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a008.iso8601,	\
				a008.tzname,	\
				a008.tzhouroffset,	\
				a008.tzminoffset,	\
				a008.description,	\
				a008.visible,	\
			a008.revision,	\
			2	\
		from cfinet213.ISOTz as a008	\
		where	\
			a008.isotzoneid = argISOTZoneId;	\
	\
		open retcursor;	\
	end;	\
end