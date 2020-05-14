--
--	@(#) dbcreate/cfint/pgsql/crsp_update_urlproto.pgsql
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

create or replace function cfinet213.sp_update_urlproto(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argURLProtocolId integer,
	argName varchar(16),
	argDescription varchar(50),
	argIsSecure boolean,
	argRevision integer )
returns setof cfinet213.type_urlproto_rec as $$
declare
	RowsAffected integer;
	oldURLProtocolId integer;
	oldName varchar(16);
	oldDescription varchar(50);
	oldIsSecure boolean;
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a109' )
	then
		select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update URLProtocol records';
		end if;
	end if;

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


	if argRevision != oldRevision
	then
		raise exception 'sp_update_urlproto() Data collision detected';
	end if;


	update cfinet213.URLProto
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		safe_name = argName,
		description = argDescription,
		issecure = argIsSecure
	where
		URLProtocolId = argURLProtocolId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_urlproto() Expected to affect one URLProto row, not %', RowsAffected;
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
			1
		from cfinet213.URLProto as a109
		where
			a109.urlprotocolid = argURLProtocolId;
	return query select
			a109.createdby,
			to_char( a109.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a109.updatedby,
			to_char( a109.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a109.urlprotocolid as urlprotocolid,
			a109.safe_name as safe_name,
			a109.description as description,
			a109.issecure as issecure,
		a109.revision as revision
	from cfinet213.URLProto as a109
	where
		a109.urlprotocolid = argURLProtocolId;

	return;
end;
$$ language plpgsql;
