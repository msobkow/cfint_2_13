--
--	@(#) dbcreate/cfint/oracle/crdl_secformbysecappidx.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfinet213.dl_secformbysecappidx(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argSecAppId integer ) authid definer
is
	unrecognizedClassCode exception;
	permissionFlag integer;
	cursor cursSystem is
		select
			a00b.ClusterId as ClusterId,
			a00b.SecFormId as SecFormId,
				a00b.revision as revision
		from cfinet213.SecForm a00b
		where
				a00b.ClusterId = argClusterId
			and a00b.SecAppId = argSecAppId;
	cursor cursRestrict is
		select
			a00b.ClusterId as ClusterId,
			a00b.SecFormId as SecFormId,
				a00b.revision as revision
		from cfinet213.SecForm a00b
		where
				a00b.ClusterId = argClusterId
			and a00b.SecAppId = argSecAppId
				and a00b.ClusterId = secClusterId;
begin
	permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 1 )
	then
		for cur in cursSystem
		loop
			cfinet213.dl_secform( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.clusterid,
					cur.secformid,
					cur.revision );
		end loop;
	else
		for cur in cursRestrict
		loop
			cfinet213.dl_secform( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.clusterid,
					cur.secformid,
					cur.revision );
		end loop;
	end if;
end dl_secformbysecappidx;
/

show errors procedure cfinet213.dl_secformbysecappidx;
