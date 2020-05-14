--
--	@(#) dbcreate/cfint/oracle/crupd_tsecmemb.plsql
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


create or replace procedure cfinet213.upd_tsecmemb(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argTenantId numeric,
	argTSecGrpMembId numeric,
	argTSecGroupId integer,
	argSecUserId varchar2,
	argRevision integer ) authid definer
is
	use_stamp cfinet213.TSecMemb_h.auditstamp%type;
	oldTenantId numeric(22,0);
	oldTSecGrpMembId numeric(22,0);
	oldTSecGroupId integer;
	oldSecUserId varchar2(36);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a018' )
	then
		permissionFlag := cfinet213.sp_is_tenant_user( argTenantId,
			'UpdateTSecGrpMemb',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			TenantId,
			TSecGrpMembId,
			TSecGroupId,
			SecUserId,
			revision
		into
			oldTenantId,
			oldTSecGrpMembId,
			oldTSecGroupId,
			oldSecUserId,
			oldRevision
		from cfinet213.TSecMemb
		where
			TenantId = argTenantId
			and TSecGrpMembId = argTSecGrpMembId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfinet213.TSecMemb
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		TSecGroupId = argTSecGroupId,
		SecUserId = argSecUserId
	where
		TenantId = argTenantId
		and TSecGrpMembId = argTSecGrpMembId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfinet213.TSecMemb_h (
			TenantId,
			TSecGrpMembId,
			revision,
			auditclusterid,
			auditsessionid,
			TSecGroupId,
			SecUserId,
			auditaction,
			auditstamp )
		select
			a018.TenantId as TenantId,
			a018.TSecGrpMembId as TSecGrpMembId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a018.TSecGroupId as TSecGroupId,
			a018.SecUserId as SecUserId,
			1,
			use_stamp
		from cfinet213.TSecMemb a018
		where
			a018.TenantId = argTenantId
			and a018.TSecGrpMembId = argTSecGrpMembId;

	open retCursor for select
			a018.createdby,
			to_char( a018.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a018.updatedby,
			to_char( a018.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a018.TenantId as TenantId,
			a018.TSecGrpMembId as TSecGrpMembId,
			a018.TSecGroupId as TSecGroupId,
			a018.SecUserId as SecUserId,
		a018.revision as revision
	from cfinet213.TSecMemb a018
	where
		a018.TenantId = argTenantId
			and a018.TSecGrpMembId = argTSecGrpMembId;
end upd_tsecmemb;

/

show errors procedure cfinet213.upd_tsecmemb;