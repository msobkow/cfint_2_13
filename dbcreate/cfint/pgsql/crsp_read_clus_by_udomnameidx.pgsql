--
--	@(#) dbcreate/cfint/pgsql/crsp_read_clus_by_udomnameidx.pgsql
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
create or replace function cfinet213.sp_read_clus_by_udomnameidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argFullDomName varchar(192) )
returns setof cfinet213.type_clus_rec as $$
begin
	return query select
			a001.createdby,
			to_char( a001.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a001.updatedby,
			to_char( a001.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a001.id as id,
			a001.fulldomname as fulldomname,
			a001.description as description,
			a001.revision as revision
	from cfinet213.clus as a001
	where
			a001.fulldomname = argFullDomName;
	return;
end
$$ language plpgsql;
