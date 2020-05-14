--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_iso_cntryccy_by_ctryidx.pgsql
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
create or replace function cfinet213.sp_delete_iso_cntryccy_by_ctryidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argISOCtryId smallint )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
begin
	for cur in
		select
					a005.isoctryid as isoctryid,
						a005.isoccyid as isoccyid,
				a005.revision as revision
		from cfinet213.iso_cntryccy as a005
		where
				a005.isoctryid = argISOCtryId
	loop
				select cfinet213.sp_delete_iso_cntryccy( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.isoctryid,
							cur.isoccyid,
						cur.revision )
					into subret;
	end loop;
	return true;
end;
$$ language plpgsql;
