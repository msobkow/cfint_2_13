--
--	@(#) dbcreate/cfint/pgsql/crsp_create_tsecgrp.pgsql
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
create or replace function cfinet213.sp_create_tsecgrp(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argName varchar(64),
	argIsVisible boolean )
returns setof cfinet213.type_tsecgrp_rec as $$
declare
	permissionFlag boolean;
	argTSecGroupId integer;
begin
	if( argClassCode = 'a016' )
	then
		select cfinet213.sp_is_tenant_user( argTenantId,
			'CreateTSecGroup',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for CreateTSecGroup';
		end if;
	end if;

	select cfinet213.sp_next_tsecgroupidgen( argTenantId )
	into argTSecGroupId;

	insert into cfinet213.tsecgrp(
		createdby,
		createdat,
		updatedby,
		updatedat,
		tenantid,
		tsecgroupid,
		safe_name,
		isvisible,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argTenantId,
		argTSecGroupId,
		argName,
		argIsVisible,
		1 );
	insert into cfinet213.TSecGrp_h (
			TenantId,
			TSecGroupId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			safe_name,
			IsVisible,
			revision,
			auditaction )
		select
			a016.TenantId,
			a016.TSecGroupId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a016.safe_name,
			a016.IsVisible,
			a016.revision,
			0
		from cfinet213.TSecGrp as a016
		where
			a016.tenantid = argTenantId
			and a016.tsecgroupid = argTSecGroupId;

	return query select
			a016.createdby,
			to_char( a016.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a016.updatedby,
			to_char( a016.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a016.tenantid as tenantid,
			a016.tsecgroupid as tsecgroupid,
			a016.safe_name as safe_name,
			a016.isvisible as isvisible,
			a016.revision as revision
	from cfinet213.TSecGrp as a016
	where
			a016.tenantid = argTenantId
			and a016.tsecgroupid = argTSecGroupId;

	return;
end;
$$ language plpgsql;
