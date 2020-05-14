--
--	@(#) dbcreate/cfint/oracle/crdl_secgrpbyunameidx.plsql
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

create or replace procedure cfinet213.dl_secgrpbyunameidx(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argsafe_name varchar2 ) authid definer
is
	unrecognizedClassCode exception;
	permissionFlag integer;
	cursor cursSystem is
		select
			a00c.ClusterId as ClusterId,
			a00c.SecGroupId as SecGroupId,
				a00c.revision as revision
		from cfinet213.SecGrp a00c
		where
				a00c.ClusterId = argClusterId
			and a00c.safe_name = argsafe_name;
	cursor cursRestrict is
		select
			a00c.ClusterId as ClusterId,
			a00c.SecGroupId as SecGroupId,
				a00c.revision as revision
		from cfinet213.SecGrp a00c
		where
				a00c.ClusterId = argClusterId
			and a00c.safe_name = argsafe_name
				and a00c.ClusterId = secClusterId;
begin
	permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 1 )
	then
		for cur in cursSystem
		loop
			cfinet213.dl_secgrp( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.clusterid,
					cur.secgroupid,
					cur.revision );
		end loop;
	else
		for cur in cursRestrict
		loop
			cfinet213.dl_secgrp( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.clusterid,
					cur.secgroupid,
					cur.revision );
		end loop;
	end if;
end dl_secgrpbyunameidx;
/

show errors procedure cfinet213.dl_secgrpbyunameidx;