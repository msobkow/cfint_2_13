--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_secsess_by_ididx.pgsql
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
create or replace function cfinet213.sp_delete_secsess_by_ididx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argSecSessionId varchar(36) )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
begin
	for cur in
		select
					a010.secsessionid as secsessionid,
				a010.revision as revision
		from cfinet213.SecSess as a010
		where
				a010.secsessionid = argSecSessionId
	loop
				select cfinet213.sp_delete_secsess( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.secsessionid,
						cur.revision )
					into subret;
	end loop;
	return true;
end;
$$ language plpgsql;
