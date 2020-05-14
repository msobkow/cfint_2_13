--
--	@(#) dbcreate/cfint/oracle/crdl_mjvrdef.plsql
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

create or replace procedure cfinet213.dl_mjvrdef(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argId numeric,
	argRevision int ) authid definer
is
	use_stamp cfinet213.mjvrdef_h.auditstamp%type;
	oldTenantId numeric(22,0);
	oldId numeric(22,0);
	oldSubProjectId numeric(22,0);
	oldsafe_name varchar2(64);
	olddescr varchar2(1024);
	oldRevision integer;
	cursor cursDelMajVerMinVersion is
		select
			a104.TenantId,
			a104.Id
		from cfinet213.mjvrdef a102
			inner join cfinet213.mnvrdef a104 on
				a102.TenantId = a104.TenantId
				and a102.Id = a104.MajorVersionId
		where
			a102.TenantId = argTenantId
			and a102.Id = argId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			TenantId,
			Id,
			SubProjectId,
			safe_name,
			descr,
			revision
		into
			oldTenantId,
			oldId,
			oldSubProjectId,
			oldsafe_name,
			olddescr,
			oldRevision
		from cfinet213.mjvrdef
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
		'DeleteMajorVersion',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

	insert into cfinet213.mjvrdef_h (
			TenantId,
			Id,
			revision,
			auditclusterid,
			auditsessionid,
			SubProjectId,
			safe_name,
			descr,
			auditaction,
			auditstamp )
		select
			a102.TenantId as TenantId,
			a102.Id as Id,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a102.SubProjectId as SubProjectId,
			a102.safe_name as safe_name,
			a102.descr as descr,
			2,
			use_stamp
		from cfinet213.mjvrdef a102
		where
			a102.TenantId = argTenantId
			and a102.Id = argId;

	for cur in cursDelMajVerMinVersion
	loop
		cfinet213.dl_mnvrdefbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.Id );
	end loop;
	delete from cfinet213.mjvrdef
	where
		TenantId = argTenantId
		and Id = argId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_mjvrdef;
/

show errors procedure cfinet213.dl_mjvrdef;
