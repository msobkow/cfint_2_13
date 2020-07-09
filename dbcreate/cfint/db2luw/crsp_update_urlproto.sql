--
--	@(#) dbcreate/cfint/db2luw/crsp_update_urlproto.sql
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

create or replace procedure sp_update_urlproto(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argURLProtocolId integer,	\
	in argName varchar(16),	\
	in argDescription varchar(50),	\
	in argIsSecure char(1),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldURLProtocolId integer;	\
	declare oldName varchar(16);	\
	declare oldDescription varchar(50);	\
	declare oldIsSecure char(1);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
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
				call raise_application_error( -20001, 'Permission denied -- only system user can update URLProtocol records' );	\
			end if;	\
		end if;	\
	\
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
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_urlproto() Data collision detected' );	\
		end if;	\
	\
		update cfinet213.URLProto	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			safe_name = argName,	\
			description = argDescription,	\
			issecure = argIsSecure	\
		where	\
			urlprotocolid = argURLProtocolId	\
		and revision = argRevision;	\
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
			a109.revision,	\
			2	\
		from cfinet213.URLProto as a109	\
		where	\
			a109.urlprotocolid = argURLProtocolId;	\
	\
		open retcursor;	\
	end;	\
end
