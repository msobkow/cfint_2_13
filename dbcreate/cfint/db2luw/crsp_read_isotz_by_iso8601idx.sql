--
--	@(#) dbcreate/cfint/db2luw/crsp_read_isotz_by_iso8601idx.sql
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
create or replace procedure sp_read_isotz_by_iso8601idx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argIso8601 varchar(6) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
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
			a008.iso8601 = argIso8601	\
		order by ISOTZoneId desc;	\
	declare usercurs cursor with return to client for	\
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
			a008.iso8601 = argIso8601	\
		order by ISOTZoneId desc;	\
	begin	\
		open syscurs;	\
	end;	\
end