--
--	@(#) dbcreate/cfint/oracle/crlck_tsecgrp.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/


create or replace procedure cfinet213.lck_tsecgrp(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argTSecGroupId integer ) authid definer
is
	permissionFlag integer;
	isSystemUser integer;
	permissionDenied exception;
begin
	permissionFlag := cfinet213.sp_is_tenant_user( secTenantId,
			'ReadTSecGroup',
			argAuditUserId );
	isSystemUser := cfinet213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;
	if( isSystemUser = 1 )
	then
		open retCursor for select
			a016.createdby,
			to_char( a016.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a016.updatedby,
			to_char( a016.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a016.TenantId as TenantId,
			a016.TSecGroupId as TSecGroupId,
			a016.safe_name as safe_name,
			a016.IsVisible as IsVisible,
			a016.revision as revision
		from cfinet213.TSecGrp a016
		where
			a016.TenantId = argTenantId
			and a016.TSecGroupId = argTSecGroupId
		for update;
	else
		open retCursor for select
			a016.createdby,
			to_char( a016.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a016.updatedby,
			to_char( a016.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a016.TenantId as TenantId,
			a016.TSecGroupId as TSecGroupId,
			a016.safe_name as safe_name,
			a016.IsVisible as IsVisible,
			a016.revision as revision
		from cfinet213.TSecGrp a016
		where
			a016.TenantId = argTenantId
			and a016.TSecGroupId = argTSecGroupId
			and a016.TenantId = secTenantId
		for update;
	end if;
end lck_tsecgrp;
/

show errors procedure cfinet213.lck_tsecgrp;
