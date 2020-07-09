--
--	@(#) dbcreate/cfint/oracle/crdl_secform.plsql
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

create or replace procedure cfinet213.dl_secform(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClusterId numeric,
	argSecFormId integer,
	argRevision int ) authid definer
is
	use_stamp cfinet213.SecForm_h.auditstamp%type;
	oldClusterId numeric(22,0);
	oldSecFormId integer;
	oldSecAppId integer;
	oldJEEServletMapName varchar2(192);
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			ClusterId,
			SecFormId,
			SecAppId,
			JEEServletMapName,
			revision
		into
			oldClusterId,
			oldSecFormId,
			oldSecAppId,
			oldJEEServletMapName,
			oldRevision
		from cfinet213.SecForm
		where
			ClusterId = argClusterId
			and SecFormId = argSecFormId
		for update;

	if( oldClusterId != secClusterId )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfinet213.sp_is_cluster_user( oldClusterId,
		'DeleteSecForm',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfinet213.SecForm_h (
			ClusterId,
			SecFormId,
			revision,
			auditclusterid,
			auditsessionid,
			SecAppId,
			JEEServletMapName,
			auditaction,
			auditstamp )
		select
			a00b.ClusterId as ClusterId,
			a00b.SecFormId as SecFormId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00b.SecAppId as SecAppId,
			a00b.JEEServletMapName as JEEServletMapName,
			2,
			use_stamp
		from cfinet213.SecForm a00b
		where
			a00b.ClusterId = argClusterId
			and a00b.SecFormId = argSecFormId;

	delete from cfinet213.SecForm
	where
		ClusterId = argClusterId
		and SecFormId = argSecFormId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_secform;
/

show errors procedure cfinet213.dl_secform;
