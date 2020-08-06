--
--	@(#) dbcreate/cfint/oracle/crupd_mnvrdef.plsql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFInt 2.13 Internet Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--
alter session set plsql_warnings = 'ENABLE:ALL';
/


create or replace procedure cfinet213.upd_mnvrdef(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argTenantId numeric,
	argId numeric,
	argMajorVersionId numeric,
	argsafe_name varchar2,
	argdescr varchar2,
	argRevision integer ) authid definer
is
	use_stamp cfinet213.mnvrdef_h.auditstamp%type;
	oldTenantId numeric(22,0);
	oldId numeric(22,0);
	oldMajorVersionId numeric(22,0);
	oldsafe_name varchar2(64);
	olddescr varchar2(1024);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a104' )
	then
		permissionFlag := cfinet213.sp_is_tenant_user( argTenantId,
			'UpdateMinorVersion',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			TenantId,
			Id,
			MajorVersionId,
			safe_name,
			descr,
			revision
		into
			oldTenantId,
			oldId,
			oldMajorVersionId,
			oldsafe_name,
			olddescr,
			oldRevision
		from cfinet213.mnvrdef
		where
			TenantId = argTenantId
			and Id = argId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfinet213.mnvrdef
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		MajorVersionId = argMajorVersionId,
		safe_name = argsafe_name,
		descr = argdescr
	where
		TenantId = argTenantId
		and Id = argId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfinet213.mnvrdef_h (
			TenantId,
			Id,
			revision,
			auditclusterid,
			auditsessionid,
			MajorVersionId,
			safe_name,
			descr,
			auditaction,
			auditstamp )
		select
			a104.TenantId as TenantId,
			a104.Id as Id,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a104.MajorVersionId as MajorVersionId,
			a104.safe_name as safe_name,
			a104.descr as descr,
			1,
			use_stamp
		from cfinet213.mnvrdef a104
		where
			a104.TenantId = argTenantId
			and a104.Id = argId;

	open retCursor for select
			a104.createdby,
			to_char( a104.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a104.updatedby,
			to_char( a104.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a104.TenantId as TenantId,
			a104.Id as Id,
			a104.MajorVersionId as MajorVersionId,
			a104.safe_name as safe_name,
			a104.descr as descr,
		a104.revision as revision
	from cfinet213.mnvrdef a104
	where
		a104.TenantId = argTenantId
			and a104.Id = argId;
end upd_mnvrdef;

/

show errors procedure cfinet213.upd_mnvrdef;
