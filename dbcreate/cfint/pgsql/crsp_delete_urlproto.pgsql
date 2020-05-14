--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_urlproto.pgsql
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
create or replace function cfinet213.sp_delete_urlproto(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argURLProtocolId integer,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldURLProtocolId integer;
	oldName varchar(16);
	oldDescription varchar(50);
	oldIsSecure boolean;
	oldRevision int;
	permissionFlag boolean;
begin
		select
			URLProtocolId,
			safe_name,
			Description,
			IsSecure,
			revision
		into
			oldURLProtocolId,
			oldName,
			oldDescription,
			oldIsSecure,
			oldRevision
		from cfinet213.URLProto
		where
			URLProtocolId = argURLProtocolId
		for update;

	select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete URLProtocol records';
	end if;

	insert into cfinet213.URLProto_h (
			URLProtocolId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			safe_name,
			Description,
			IsSecure,
			revision,
			auditaction )
		select
			a109.URLProtocolId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a109.safe_name,
			a109.Description,
			a109.IsSecure,
			argRevision + 1,
			2
		from cfinet213.URLProto as a109
		where
			a109.urlprotocolid = argURLProtocolId;


	delete from cfinet213.URLProto
	where
		urlprotocolid = argURLProtocolId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_urlproto() Expected to affect 1 URLProto, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
