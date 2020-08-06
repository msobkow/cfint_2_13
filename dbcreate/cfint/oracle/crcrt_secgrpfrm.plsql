--
--	@(#) dbcreate/cfint/oracle/crcrt_secgrpfrm.plsql
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

create or replace procedure cfinet213.crt_secgrpfrm(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusId numeric,
	argSecGrpId integer,
	argSecAppId integer,
	argSecFrmId integer ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.SecGrpFrm_h.auditstamp%type;
	permissionFlag integer;
	argSecGrpFrmId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00d' )
	then
		permissionFlag := cfinet213.sp_is_cluster_user( argClusId,
			'CreateSecGroupForm',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argSecGrpFrmId := cfinet213.nxt_secgroupformidgen( argClusId );
	insert into cfinet213.secgrpfrm(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ClusId,
		SecGrpFrmId,
		SecGrpId,
		SecAppId,
		SecFrmId,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argClusId,
		argSecGrpFrmId,
		argSecGrpId,
		argSecAppId,
		argSecFrmId,
		1 );
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
			a00d.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00d.SecGrpId as SecGrpId,
			a00d.SecAppId as SecAppId,
			a00d.SecFrmId as SecFrmId,
			0,
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
end crt_secgrpfrm;
/

show errors procedure cfinet213.crt_secgrpfrm;
