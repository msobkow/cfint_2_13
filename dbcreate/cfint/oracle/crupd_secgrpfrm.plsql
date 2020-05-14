--
--	@(#) dbcreate/cfint/oracle/crupd_secgrpfrm.plsql
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


create or replace procedure cfinet213.upd_secgrpfrm(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusId numeric,
	argSecGrpFrmId numeric,
	argSecGrpId integer,
	argSecAppId integer,
	argSecFrmId integer,
	argRevision integer ) authid definer
is
	use_stamp cfinet213.SecGrpFrm_h.auditstamp%type;
	oldClusId numeric(22,0);
	oldSecGrpFrmId numeric(22,0);
	oldSecGrpId integer;
	oldSecAppId integer;
	oldSecFrmId integer;
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00d' )
	then
		permissionFlag := cfinet213.sp_is_cluster_user( argClusId,
			'UpdateSecGroupForm',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			ClusId,
			SecGrpFrmId,
			SecGrpId,
			SecAppId,
			SecFrmId,
			revision
		into
			oldClusId,
			oldSecGrpFrmId,
			oldSecGrpId,
			oldSecAppId,
			oldSecFrmId,
			oldRevision
		from cfinet213.SecGrpFrm
		where
			ClusId = argClusId
			and SecGrpFrmId = argSecGrpFrmId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfinet213.SecGrpFrm
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		SecGrpId = argSecGrpId,
		SecAppId = argSecAppId,
		SecFrmId = argSecFrmId
	where
		ClusId = argClusId
		and SecGrpFrmId = argSecGrpFrmId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfinet213.SecGrpFrm_h (
			ClusId,
			SecGrpFrmId,
			revision,
			auditclusterid,
			auditsessionid,
			SecGrpId,
			SecAppId,
			SecFrmId,
			auditaction,
			auditstamp )
		select
			a00d.ClusId as ClusId,
			a00d.SecGrpFrmId as SecGrpFrmId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
			1,
			use_stamp
		from cfinet213.SecGrpFrm a00d
		where
			a00d.ClusId = argClusId
			and a00d.SecGrpFrmId = argSecGrpFrmId;

	open retCursor for select
			a00d.createdby,
			to_char( a00d.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00d.updatedby,
			to_char( a00d.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00d.ClusId as ClusId,
			a00d.SecGrpFrmId as SecGrpFrmId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
		a00d.revision as revision
	from cfinet213.SecGrpFrm a00d
	where
		a00d.ClusId = argClusId
			and a00d.SecGrpFrmId = argSecGrpFrmId;
end upd_secgrpfrm;

/

show errors procedure cfinet213.upd_secgrpfrm;
