--
--	@(#) dbcreate/cfint/oracle/crcrt_tdomdef.plsql
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

create or replace procedure cfinet213.crt_tdomdef(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argTenantId numeric,
	argTldId numeric,
	argsafe_name varchar2,
	argdescr varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.tdomdef_h.auditstamp%type;
	permissionFlag integer;
	argId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a107' )
	then
		permissionFlag := cfinet213.sp_is_tenant_user( argTenantId,
			'CreateTopDomain',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argId := cfinet213.nxt_topdomainidgen( argTenantId );
	insert into cfinet213.tdomdef(
		createdby,
		createdat,
		updatedby,
		updatedat,
		TenantId,
		Id,
		TldId,
		safe_name,
		descr,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argTenantId,
		argId,
		argTldId,
		argsafe_name,
		argdescr,
		1 );
	insert into cfinet213.tdomdef_h (
			TenantId,
			Id,
			revision,
			auditclusterid,
			auditsessionid,
			TldId,
			safe_name,
			descr,
			auditaction,
			auditstamp )
		select
			a107.TenantId as TenantId,
			a107.Id as Id,
			a107.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a107.TldId as TldId,
			a107.safe_name as safe_name,
			a107.descr as descr,
			0,
			use_stamp
		from cfinet213.tdomdef a107
		where
			a107.TenantId = argTenantId
			and a107.Id = argId;

	open retCursor for select
			a107.createdby,
			to_char( a107.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a107.updatedby,
			to_char( a107.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a107.TenantId as TenantId,
			a107.Id as Id,
			a107.TldId as TldId,
			a107.safe_name as safe_name,
			a107.descr as descr,
		a107.revision as revision
	from cfinet213.tdomdef a107
	where
		a107.TenantId = argTenantId
			and a107.Id = argId;
end crt_tdomdef;
/

show errors procedure cfinet213.crt_tdomdef;
