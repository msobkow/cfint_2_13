--
--	@(#) dbcreate/cfint/pgsql/crsp_update_svctype.pgsql
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

create or replace function cfinet213.sp_update_svctype(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argServiceTypeId integer,
	argDescription varchar(50),
	argRevision integer )
returns setof cfinet213.type_svctype_rec as $$
declare
	RowsAffected integer;
	oldServiceTypeId integer;
	oldDescription varchar(50);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a013' )
	then
		select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update ServiceType records';
		end if;
	end if;

		select
			ServiceTypeId,
			Description,
			revision
		into
			oldServiceTypeId,
			oldDescription,
			oldRevision
		from cfinet213.SvcType
		where
			ServiceTypeId = argServiceTypeId
		for update;


	if argRevision != oldRevision
	then
		raise exception 'sp_update_svctype() Data collision detected';
	end if;


	update cfinet213.SvcType
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		description = argDescription
	where
		ServiceTypeId = argServiceTypeId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_svctype() Expected to affect one SvcType row, not %', RowsAffected;
	end if;


	insert into cfinet213.SvcType_h (
			ServiceTypeId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			Description,
			revision,
			auditaction )
		select
			a013.ServiceTypeId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a013.Description,
			argRevision + 1,
			1
		from cfinet213.SvcType as a013
		where
			a013.servicetypeid = argServiceTypeId;
	return query select
			a013.createdby,
			to_char( a013.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a013.updatedby,
			to_char( a013.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a013.servicetypeid as servicetypeid,
			a013.description as description,
		a013.revision as revision
	from cfinet213.SvcType as a013
	where
		a013.servicetypeid = argServiceTypeId;

	return;
end;
$$ language plpgsql;