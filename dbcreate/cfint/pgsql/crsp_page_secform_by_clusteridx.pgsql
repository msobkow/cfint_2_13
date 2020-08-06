--
--	@(#) dbcreate/cfint/pgsql/crsp_page_secform_by_clusteridx.pgsql
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
create or replace function cfinet213.sp_page_secform_by_clusteridx(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClusterId bigint,
	priorClusterId bigint,
	priorSecFormId integer )
returns setof cfinet213.type_secform_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfinet213.sp_is_cluster_user( secClusterId,
			'ReadSecForm',
			argAuditUserId ),
		cfinet213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in cluster SecGroup for ReadSecForm';
	end if;
	if( isSystemUser )
	then
		if( ( priorClusterId is not null )and ( priorSecFormId is not null ) )
		then
			return query select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.clusterid as clusterid,
			a00b.secformid as secformid,
			a00b.secappid as secappid,
			a00b.jeeservletmapname as jeeservletmapname,
				a00b.revision as revision
			from cfinet213.SecForm as a00b
			where
				a00b.clusterid = argClusterId
			and ( ( ( a00b.ClusterId = priorClusterId )
					and ( a00b.SecFormId < priorSecFormId ) )
				or ( ( a00b.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					SecFormId desc
			limit 25;
		else
			return query select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.clusterid as clusterid,
			a00b.secformid as secformid,
			a00b.secappid as secappid,
			a00b.jeeservletmapname as jeeservletmapname,
				a00b.revision as revision
			from cfinet213.SecForm as a00b
			where
				a00b.clusterid = argClusterId
				order by ClusterId desc,
					SecFormId desc
			limit 25;
		end if;
	else
		if( ( priorClusterId is not null )and ( priorSecFormId is not null ) )
		then
			return query select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.clusterid as clusterid,
			a00b.secformid as secformid,
			a00b.secappid as secappid,
			a00b.jeeservletmapname as jeeservletmapname,
				a00b.revision as revision
			from cfinet213.SecForm as a00b
			where
				a00b.clusterid = argClusterId
				and a00b.ClusterId = secClusterId
			and ( ( ( a00b.ClusterId = priorClusterId )
					and ( a00b.SecFormId < priorSecFormId ) )
				or ( ( a00b.ClusterId < priorClusterId ) ) )
				order by ClusterId desc,
					SecFormId desc
			limit 25;
		else
			return query select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.clusterid as clusterid,
			a00b.secformid as secformid,
			a00b.secappid as secappid,
			a00b.jeeservletmapname as jeeservletmapname,
				a00b.revision as revision
			from cfinet213.SecForm as a00b
			where
				a00b.clusterid = argClusterId
				and a00b.ClusterId = secClusterId
				order by ClusterId desc,
					SecFormId desc
			limit 25;
		end if;
	end if;
	return;
end
$$ language plpgsql;
