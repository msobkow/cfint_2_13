--
--	@(#) dbcreate/cfint/pgsql/crsp_read_urlproto_by_ididx.pgsql
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
create or replace function cfinet213.sp_read_urlproto_by_ididx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argURLProtocolId integer )
returns setof cfinet213.type_urlproto_rec as $$
begin
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
end
$$ language plpgsql;
