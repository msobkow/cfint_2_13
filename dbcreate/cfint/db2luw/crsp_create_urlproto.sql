--
--	@(#) dbcreate/cfint/db2luw/crsp_create_urlproto.sql
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
