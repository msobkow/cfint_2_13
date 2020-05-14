--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_svctype.pgsql
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
create or replace function cfinet213.sp_delete_svctype(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argServiceTypeId integer,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldServiceTypeId integer;
	oldDescription varchar(50);
	oldRevision int;
	permissionFlag boolean;
begin
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

	select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete ServiceType records';
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
			2
		from cfinet213.SvcType as a013
		where
			a013.servicetypeid = argServiceTypeId;


	delete from cfinet213.SvcType
	where
		servicetypeid = argServiceTypeId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_svctype() Expected to affect 1 SvcType, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;