--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_secdev_by_useridx.pgsql
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
create or replace function cfinet213.sp_delete_secdev_by_useridx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argSecUserId varchar(36) )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
begin
	for cur in
		select
					a00a.secuserid as secuserid,
						a00a.devname as devname,
				a00a.revision as revision
		from cfinet213.SecDev as a00a
		where
				a00a.secuserid = argSecUserId
	loop
				select cfinet213.sp_delete_secdev( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.secuserid,
							cur.devname,
						cur.revision )
					into subret;
	end loop;
	return true;
end;
$$ language plpgsql;
