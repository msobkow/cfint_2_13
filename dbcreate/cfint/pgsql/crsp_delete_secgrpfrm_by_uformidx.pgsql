--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_secgrpfrm_by_uformidx.pgsql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--
create or replace function cfinet213.sp_delete_secgrpfrm_by_uformidx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	argSecGroupId integer,
	argSecFormId integer )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
begin
	select cfinet213.sp_is_system_user( argAuditUserId ) into subret;
	if( subret )
	then
		for cur in
			select
					a00d.clusid as clusid,
						a00d.secgrpfrmid as secgrpfrmid,
					a00d.revision as revision
			from cfinet213.SecGrpFrm as a00d
			where
					a00d.clusid = argClusterId
			and a00d.secgrpid = argSecGroupId
			and a00d.secfrmid = argSecFormId
		loop
				select cfinet213.sp_delete_secgrpfrm( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.clusterid,
							cur.secgroupformid,
						cur.revision )
					into subret;
		end loop;
	else
		for cur in
			select
					a00d.clusid as clusid,
						a00d.secgrpfrmid as secgrpfrmid,
					a00d.revision as revision
			from cfinet213.SecGrpFrm as a00d
			where
					a00d.clusid = argClusterId
			and a00d.secgrpid = argSecGroupId
			and a00d.secfrmid = argSecFormId
					and a00d.ClusId = secClusterId
		loop
				select cfinet213.sp_delete_secgrpfrm( argAuditClusterId,
						argAuditUserId,
						argAuditSessionId,
						secClusterId,
						secTenantId,
							cur.clusterid,
							cur.secgroupformid,
						cur.revision )
					into subret;
		end loop;
	end if;
	return true;
end;
$$ language plpgsql;
