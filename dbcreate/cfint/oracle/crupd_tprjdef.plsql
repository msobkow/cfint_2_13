--
--	@(#) dbcreate/cfint/oracle/crupd_tprjdef.plsql
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


create or replace procedure cfinet213.upd_tprjdef(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argTenantId numeric,
	argId numeric,
	argTopDomainId numeric,
	argsafe_name varchar2,
	argdescr varchar2,
	argRevision integer ) authid definer
is
	use_stamp cfinet213.tprjdef_h.auditstamp%type;
	oldTenantId numeric(22,0);
	oldId numeric(22,0);
	oldTopDomainId numeric(22,0);
	oldsafe_name varchar2(64);
	olddescr varchar2(1024);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a108' )
	then
		permissionFlag := cfinet213.sp_is_tenant_user( argTenantId,
			'UpdateTopProject',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			TenantId,
			Id,
			TopDomainId,
			safe_name,
			descr,
			revision
		into
			oldTenantId,
			oldId,
			oldTopDomainId,
			oldsafe_name,
			olddescr,
			oldRevision
		from cfinet213.tprjdef
		where
			TenantId = argTenantId
			and Id = argId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfinet213.tprjdef
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		TopDomainId = argTopDomainId,
		safe_name = argsafe_name,
		descr = argdescr
	where
		TenantId = argTenantId
		and Id = argId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfinet213.tprjdef_h (
			TenantId,
			Id,
			revision,
			auditclusterid,
			auditsessionid,
			TopDomainId,
			safe_name,
			descr,
			auditaction,
			auditstamp )
		select
			a108.TenantId as TenantId,
			a108.Id as Id,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a108.TopDomainId as TopDomainId,
			a108.safe_name as safe_name,
			a108.descr as descr,
			1,
			use_stamp
		from cfinet213.tprjdef a108
		where
			a108.TenantId = argTenantId
			and a108.Id = argId;

	open retCursor for select
			a108.createdby,
			to_char( a108.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a108.updatedby,
			to_char( a108.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a108.TenantId as TenantId,
			a108.Id as Id,
			a108.TopDomainId as TopDomainId,
			a108.safe_name as safe_name,
			a108.descr as descr,
		a108.revision as revision
	from cfinet213.tprjdef a108
	where
		a108.TenantId = argTenantId
			and a108.Id = argId;
end upd_tprjdef;

/

show errors procedure cfinet213.upd_tprjdef;
