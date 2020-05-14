--
--	@(#) dbcreate/cfint/db2luw/crsp_delete_urlproto.sql
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
