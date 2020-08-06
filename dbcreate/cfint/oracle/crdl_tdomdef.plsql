--
--	@(#) dbcreate/cfint/oracle/crdl_tdomdef.plsql
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

create or replace procedure cfinet213.dl_tdomdef(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argTenantId numeric,
	argId numeric,
	argRevision int ) authid definer
is
	use_stamp cfinet213.tdomdef_h.auditstamp%type;
	oldTenantId numeric(22,0);
	oldId numeric(22,0);
	oldTldId numeric(22,0);
	oldsafe_name varchar2(64);
	olddescr varchar2(1024);
	oldRevision integer;
	cursor cursDelSubDomTopProject is
		select
			a108.TenantId,
			a108.Id
		from cfinet213.tdomdef a107
			inner join cfinet213.tprjdef a108 on
				a107.TenantId = a108.TenantId
				and a107.Id = a108.TopDomainId
		where
			a107.TenantId = argTenantId
			and a107.Id = argId;
	cursor cursDelTopDomLicense is
		select
			a101.TenantId,
			a101.Id
		from cfinet213.tdomdef a107
			inner join cfinet213.licn a101 on
				a107.TenantId = a101.TenantId
				and a107.Id = a101.TopDomainId
		where
			a107.TenantId = argTenantId
			and a107.Id = argId;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			TenantId,
			Id,
			TldId,
			safe_name,
			descr,
			revision
		into
			oldTenantId,
			oldId,
			oldTldId,
			oldsafe_name,
			olddescr,
			oldRevision
		from cfinet213.tdomdef
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
		'DeleteTopDomain',
		argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

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
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a107.TldId as TldId,
			a107.safe_name as safe_name,
			a107.descr as descr,
			2,
			use_stamp
		from cfinet213.tdomdef a107
		where
			a107.TenantId = argTenantId
			and a107.Id = argId;

	for cur in cursDelSubDomTopProject
	loop
		cfinet213.dl_tprjdefbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.Id );
	end loop;
	for cur in cursDelTopDomLicense
	loop
		cfinet213.dl_licnbyididx( argAuditClusterId,
				argAuditUserId,
				argAuditSessionId,
				secClusterId,
				secTenantId,
				cur.TenantId,
				cur.Id );
	end loop;
	delete from cfinet213.tdomdef
	where
		TenantId = argTenantId
		and Id = argId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_tdomdef;
/

show errors procedure cfinet213.dl_tdomdef;
