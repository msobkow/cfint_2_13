--
--	@(#) dbcreate/cfint/db2luw/crsp_delete_urlproto.sql
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
create or replace procedure sp_delete_urlproto(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argURLProtocolId integer,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldURLProtocolId integer;	\
	declare oldName varchar(16);	\
	declare oldDescription varchar(50);	\
	declare oldIsSecure char(1);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
		select	\
			URLProtocolId,	\
			safe_name,	\
			Description,	\
			IsSecure,	\
			revision	\
		into	\
			oldURLProtocolId,	\
			oldName,	\
			oldDescription,	\
			oldIsSecure,	\
			oldRevision	\
		from cfinet213.URLProto	\
		where	\
			URLProtocolId = argURLProtocolId	\
		for update;	\
	\
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete URLProtocol records' );	\
		end if;	\
	\
	\
		insert into cfinet213.URLProto_h (	\
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
			a109.revision + 1,	\
			2	\
		from cfinet213.URLProto as a109	\
		where	\
			a109.urlprotocolid = argURLProtocolId;	\
	\
		delete from cfinet213.URLProto	\
		where	\
			urlprotocolid = argURLProtocolId;	\
	\
		open retcursor;	\
	end;	\
end
