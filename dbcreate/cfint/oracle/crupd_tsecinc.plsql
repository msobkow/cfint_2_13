--
--	@(#) dbcreate/cfint/oracle/crupd_tsecinc.plsql
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


create or replace procedure cfinet213.upd_tsecinc(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argTenantId numeric,
	argTSecGrpIncId numeric,
	argTSecGrpId integer,
	argIncGrpId integer,
	argRevision integer ) authid definer
is
	use_stamp cfinet213.TSecInc_h.auditstamp%type;
	oldTenantId numeric(22,0);
	oldTSecGrpIncId numeric(22,0);
	oldTSecGrpId integer;
	oldIncGrpId integer;
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a017' )
	then
		permissionFlag := cfinet213.sp_is_tenant_user( argTenantId,
			'UpdateTSecGrpInc',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			TenantId,
			TSecGrpIncId,
			TSecGrpId,
			IncGrpId,
			revision
		into
			oldTenantId,
			oldTSecGrpIncId,
			oldTSecGrpId,
			oldIncGrpId,
			oldRevision
		from cfinet213.TSecInc
		where
			TenantId = argTenantId
			and TSecGrpIncId = argTSecGrpIncId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfinet213.TSecInc
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		TSecGrpId = argTSecGrpId,
		IncGrpId = argIncGrpId
	where
		TenantId = argTenantId
		and TSecGrpIncId = argTSecGrpIncId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfinet213.TSecInc_h (
			TenantId,
			TSecGrpIncId,
			revision,
			auditclusterid,
			auditsessionid,
			TSecGrpId,
			IncGrpId,
			auditaction,
			auditstamp )
		select
			a017.TenantId as TenantId,
			a017.TSecGrpIncId as TSecGrpIncId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a017.TSecGrpId as TSecGrpId,
			a017.IncGrpId as IncGrpId,
			1,
			use_stamp
		from cfinet213.TSecInc a017
		where
			a017.TenantId = argTenantId
			and a017.TSecGrpIncId = argTSecGrpIncId;

	open retCursor for select
			a017.createdby,
			to_char( a017.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a017.updatedby,
			to_char( a017.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a017.TenantId as TenantId,
			a017.TSecGrpIncId as TSecGrpIncId,
			a017.TSecGrpId as TSecGrpId,
			a017.IncGrpId as IncGrpId,
		a017.revision as revision
	from cfinet213.TSecInc a017
	where
		a017.TenantId = argTenantId
			and a017.TSecGrpIncId = argTSecGrpIncId;
end upd_tsecinc;

/

show errors procedure cfinet213.upd_tsecinc;