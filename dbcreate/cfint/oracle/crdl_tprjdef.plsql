--
--	@(#) dbcreate/cfint/oracle/crdl_tprjdef.plsql
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

create or replace procedure cfinet213.dl_tprjdef(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argId numeric,
	argRevision int ) authid definer
is
	use_stamp cfinet213.tprjdef_h.auditstamp%type;
	oldTenantId numeric(22,0);
	oldId numeric(22,0);
	oldTopDomainId numeric(22,0);
	oldsafe_name varchar2(64);
	olddescr varchar2(1024);
	oldRevision integer;
	cursor cursDelTopPrjSubProject is
		select
			a105.TenantId,
			a105.Id
		from cfinet213.tprjdef a108
			inner join cfinet213.sprjdef a105 on
				a108.TenantId = a105.TenantId
				and a108.Id = a105.TopProjectId
		where
			a108.TenantId = argTenantId
			and a108.Id = argId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
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

	if( oldTenantId != secTenantId )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	permissionFlag := cfinet213.sp_is_tenant_user( oldTenantId,
		'DeleteTopProject',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
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
			2,
			use_stamp
		from cfinet213.tprjdef a108
		where
			a108.TenantId = argTenantId
			and a108.Id = argId;

	for cur in cursDelTopPrjSubProject
	loop
		cfinet213.dl_sprjdefbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.Id );
	end loop;
	delete from cfinet213.tprjdef
	where
		TenantId = argTenantId
		and Id = argId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_tprjdef;
/

show errors procedure cfinet213.dl_tprjdef;
