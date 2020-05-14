--
--	@(#) dbcreate/cfint/pgsql/crsp_read_mnvrdef_all.pgsql
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
create or replace function cfinet213.sp_read_mnvrdef_all(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint )
returns setof cfinet213.type_mnvrdef_rec as $$
declare
	permissionFlag boolean;
	isSystemUser boolean;
begin
	select cfinet213.sp_is_tenant_user( secTenantId,
			'ReadMinorVersion',
			argAuditUserId ),
		cfinet213.sp_is_system_user( argAuditUserId )
	into permissionFlag, isSystemUser;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- User not found in tenant TSecGroup for ReadMinorVersion';
	end if;
	if( isSystemUser )
	then
		return query select
			a104.createdby,
			to_char( a104.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a104.updatedby,
			to_char( a104.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a104.tenantid as tenantid,
			a104.id as id,
			a104.majorversionid as majorversionid,
			a104.safe_name as safe_name,
			a104.descr as descr,
			a104.revision as revision
		from cfinet213.mnvrdef as a104
				order by TenantId desc,
					Id desc;
	else
		return query select
			a104.createdby,
			to_char( a104.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a104.updatedby,
			to_char( a104.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a104.tenantid as tenantid,
			a104.id as id,
			a104.majorversionid as majorversionid,
			a104.safe_name as safe_name,
			a104.descr as descr,
			a104.revision as revision
		from cfinet213.mnvrdef as a104
		where
			a104.TenantId = secTenantId
				order by TenantId desc,
					Id desc;
	end if;
	return;
end;
$$ language plpgsql;
