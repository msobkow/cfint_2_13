--
--	@(#) dbcreate/cfint/oracle/crupd_licn.plsql
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


create or replace procedure cfinet213.upd_licn(
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
	argEmbeddedText clob,
	argFullTxt clob,
	argRevision integer ) authid definer
is
	oldTenantId numeric(22,0);
	oldId numeric(22,0);
	oldTopDomainId numeric(22,0);
	oldsafe_name varchar2(64);
	olddescr varchar2(1024);
	oldEmbeddedText clob;
	oldFullTxt clob;
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	if( argClassCode = 'a101' )
	then
		permissionFlag := cfinet213.sp_is_tenant_user( argTenantId,
			'UpdateLicense',
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
			EmbeddedText,
			FullTxt,
			revision
		into
			oldTenantId,
			oldId,
			oldTopDomainId,
			oldsafe_name,
			olddescr,
			oldEmbeddedText,
			oldFullTxt,
			oldRevision
		from cfinet213.licn
		where
			TenantId = argTenantId
			and Id = argId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfinet213.licn
	set
		revision = argRevision + 1,
		TopDomainId = argTopDomainId,
		safe_name = argsafe_name,
		descr = argdescr,
		EmbeddedText = argEmbeddedText,
		FullTxt = argFullTxt
	where
		TenantId = argTenantId
		and Id = argId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	open retCursor for select
			a101.TenantId as TenantId,
			a101.Id as Id,
			a101.TopDomainId as TopDomainId,
			a101.safe_name as safe_name,
			a101.descr as descr,
			a101.EmbeddedText as EmbeddedText,
			a101.FullTxt as FullTxt,
		a101.revision as revision
	from cfinet213.licn a101
	where
		a101.TenantId = argTenantId
			and a101.Id = argId;
end upd_licn;

/

show errors procedure cfinet213.upd_licn;
