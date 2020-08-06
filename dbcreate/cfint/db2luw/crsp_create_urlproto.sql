--
--	@(#) dbcreate/cfint/db2luw/crsp_create_urlproto.sql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFInt 2.13 Internet Essentials
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
create or replace procedure sp_create_urlproto(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argName varchar(16),	\
	in argDescription varchar(50),	\
	in argIsSecure char(1) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
		declare argURLProtocolId integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a109.createdby as createdby,	\
				to_char( a109.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a109.updatedby as updatedby,	\
				to_char( a109.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a109.urlprotocolid as urlprotocolid,	\
			a109.safe_name as safe_name,	\
			a109.description as description,	\
			a109.issecure as issecure,	\
			a109.revision as revision	\
		from cfinet213.URLProto as a109	\
		where	\
			a109.urlprotocolid = argURLProtocolId;	\
	begin	\
		if( argClassCode = 'a109' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can create URLProtocol records' );	\
			end if;	\
		end if;	\
		call sp_next_urlprotocolidgen( argURLProtocolId );	\
		insert into cfinet213.urlproto(	\
			createdby,	\
			createdat,	\
			updatedby,	\
			updatedat,	\
			urlprotocolid,	\
			safe_name,	\
			description,	\
			issecure,	\
			revision )	\
		values (	\
			argAuditUserId,	\
			current timestamp,	\
			argAuditUserId,	\
			current timestamp,	\
			argURLProtocolId,	\
			argName,	\
			argDescription,	\
			argIsSecure,	\
			1 );	\
	\
		insert into cfinet213.urlproto_h (	\
				urlprotocolid,	\
				auditclusterid,	\
				auditsessionid,	\
				auditstamp,	\
				safe_name,	\
				description,	\
				issecure,	\
				revision,	\
				auditaction )	\
		select	\
				a109.urlprotocolid,	\
				argAuditClusterId,	\
				argAuditSessionId,	\
				current timestamp,	\
				a109.safe_name,	\
				a109.description,	\
				a109.issecure,	\
				a109.revision,	\
				0	\
		from cfinet213.URLProto as a109	\
		where	\
				a109.urlprotocolid = argURLProtocolId;	\
	\
		open retcursor;	\
	end;	\
end