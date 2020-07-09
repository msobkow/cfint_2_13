--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_clus.pgsql
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
create or replace function cfinet213.sp_delete_clus(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argId bigint,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldId bigint;
	oldFullDomName varchar(192);
	oldDescription varchar(128);
	oldRevision int;
	permissionFlag boolean;
begin
		select
			Id,
			FullDomName,
			Description,
			revision
		into
			oldId,
			oldFullDomName,
			oldDescription,
			oldRevision
		from cfinet213.clus
		where
			Id = argId
		for update;

	select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete Cluster records';
	end if;

	insert into cfinet213.clus_h (
			Id,
			auditclusterid,
			auditsessionid,
			auditstamp,
			FullDomName,
			Description,
			revision,
			auditaction )
		select
			a001.Id,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a001.FullDomName,
			a001.Description,
			argRevision + 1,
			2
		from cfinet213.clus as a001
		where
			a001.id = argId;

	for cur in
		select
			a00d.ClusId,
			a00d.SecGrpFrmId
		from cfinet213.clus as a001
			inner join cfinet213.secgrp a00c on 
				a001.Id = a00c.ClusterId
			inner join cfinet213.secgrpfrm a00d on 
				a00c.ClusterId = a00d.ClusId
				and a00c.SecGroupId = a00d.SecGrpId
		where
			a001.Id = argId
	loop
		select cfinet213.sp_delete_secgrpfrm_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGroupFormId )
			into subret;
	end loop;

	for cur in
		select
			a00e.ClusId,
			a00e.SecGrpIncId
		from cfinet213.clus as a001
			inner join cfinet213.secgrp a00c on 
				a001.Id = a00c.ClusterId
			inner join cfinet213.secinc a00e on 
				a00c.ClusterId = a00e.ClusId
				and a00c.SecGroupId = a00e.IncGrpId
		where
			a001.Id = argId
	loop
		select cfinet213.sp_delete_secinc_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGrpIncId )
			into subret;
	end loop;

	for cur in
		select
			a00f.ClusterId,
			a00f.SecGrpMembId
		from cfinet213.clus as a001
			inner join cfinet213.secgrp a00c on 
				a001.Id = a00c.ClusterId
			inner join cfinet213.secmemb a00f on 
				a00c.ClusterId = a00f.ClusterId
				and a00c.SecGroupId = a00f.SecGroupId
		where
			a001.Id = argId
	loop
		select cfinet213.sp_delete_secmemb_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGrpMembId )
			into subret;
	end loop;

	for cur in
		select
			a00e.ClusId,
			a00e.SecGrpIncId
		from cfinet213.clus as a001
			inner join cfinet213.secgrp a00c on 
				a001.Id = a00c.ClusterId
			inner join cfinet213.secinc a00e on 
				a00c.ClusterId = a00e.ClusId
				and a00c.SecGroupId = a00e.SecGrpId
		where
			a001.Id = argId
	loop
		select cfinet213.sp_delete_secinc_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGrpIncId )
			into subret;
	end loop;

	for cur in
		select
			a00c.ClusterId,
			a00c.SecGroupId
		from cfinet213.clus as a001
			inner join cfinet213.secgrp a00c on 
				a001.Id = a00c.ClusterId
		where
			a001.Id = argId
	loop
		select cfinet213.sp_delete_secgrp_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecGroupId )
			into subret;
	end loop;

	for cur in
		select
			a00b.ClusterId,
			a00b.SecFormId
		from cfinet213.clus as a001
			inner join cfinet213.secapp a009 on 
				a001.Id = a009.ClusterId
			inner join cfinet213.secform a00b on 
				a009.ClusterId = a00b.ClusterId
				and a009.SecAppId = a00b.SecAppId
		where
			a001.Id = argId
	loop
		select cfinet213.sp_delete_secform_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecFormId )
			into subret;
	end loop;

	for cur in
		select
			a009.ClusterId,
			a009.SecAppId
		from cfinet213.clus as a001
			inner join cfinet213.secapp a009 on 
				a001.Id = a009.ClusterId
		where
			a001.Id = argId
	loop
		select cfinet213.sp_delete_secapp_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.SecAppId )
			into subret;
	end loop;

	for cur in
		select
			a015.Id
		from cfinet213.clus as a001
			inner join cfinet213.tenant a015 on 
				a001.Id = a015.ClusterId
		where
			a001.Id = argId
	loop
		select cfinet213.sp_delete_tenant_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.Id )
			into subret;
	end loop;

	for cur in
		select
			a002.ClusterId,
			a002.HostNodeId
		from cfinet213.clus as a001
			inner join cfinet213.hostnode a002 on 
				a001.Id = a002.ClusterId
		where
			a001.Id = argId
	loop
		select cfinet213.sp_delete_hostnode_by_ididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.ClusterId,
				cur.HostNodeId )
			into subret;
	end loop;


	delete from cfinet213.clus
	where
		id = argId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_clus() Expected to affect 1 clus, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
