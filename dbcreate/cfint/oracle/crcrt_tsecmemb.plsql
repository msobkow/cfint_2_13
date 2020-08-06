--
--	@(#) dbcreate/cfint/oracle/crcrt_tsecmemb.plsql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
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

create or replace procedure cfinet213.crt_tsecmemb(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argTenantId numeric,
	argTSecGroupId integer,
	argSecUserId varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.TSecMemb_h.auditstamp%type;
	permissionFlag integer;
	argTSecGrpMembId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a018' )
	then
		permissionFlag := cfinet213.sp_is_tenant_user( argTenantId,
			'CreateTSecGrpMemb',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argTSecGrpMembId := cfinet213.nxt_tsecgrpmembidgen( argTenantId );
	insert into cfinet213.tsecmemb(
		createdby,
		createdat,
		updatedby,
		updatedat,
		TenantId,
		TSecGrpMembId,
		TSecGroupId,
		SecUserId,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argTenantId,
		argTSecGrpMembId,
		argTSecGroupId,
		argSecUserId,
		1 );
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
			a018.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a018.TSecGroupId as TSecGroupId,
			a018.SecUserId as SecUserId,
			0,
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
end crt_tsecmemb;
/

show errors procedure cfinet213.crt_tsecmemb;
