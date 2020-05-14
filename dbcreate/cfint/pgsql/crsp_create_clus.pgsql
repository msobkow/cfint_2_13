--
--	@(#) dbcreate/cfint/pgsql/crsp_create_clus.pgsql
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
create or replace function cfinet213.sp_create_clus(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argFullDomName varchar(192),
	argDescription varchar(128) )
returns setof cfinet213.type_clus_rec as $$
declare
	permissionFlag boolean;
	argId bigint;
begin
	if( argClassCode = 'a001' )
	then
		select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can create Cluster records';
		end if;
	end if;

	select cfinet213.sp_next_clusteridgen()
	into argId;

	insert into cfinet213.clus(
		createdby,
		createdat,
		updatedby,
		updatedat,
		id,
		fulldomname,
		description,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argId,
		argFullDomName,
		argDescription,
		1 );
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
			a001.revision,
			0
		from cfinet213.clus as a001
		where
			a001.id = argId;

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
			a001.id = argId;

	return;
end;
$$ language plpgsql;