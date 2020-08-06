--
--	@(#) dbcreate/cfint/oracle/crcrt_secform.plsql
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

create or replace procedure cfinet213.crt_secform(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argClusterId numeric,
	argSecAppId integer,
	argJEEServletMapName varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.SecForm_h.auditstamp%type;
	permissionFlag integer;
	argSecFormId integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a00b' )
	then
		permissionFlag := cfinet213.sp_is_cluster_user( argClusterId,
			'CreateSecForm',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argSecFormId := cfinet213.nxt_secformidgen( argClusterId );
	insert into cfinet213.secform(
		createdby,
		createdat,
		updatedby,
		updatedat,
		ClusterId,
		SecFormId,
		SecAppId,
		JEEServletMapName,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argClusterId,
		argSecFormId,
		argSecAppId,
		argJEEServletMapName,
		1 );
	insert into cfinet213.SecForm_h (
			ClusterId,
			SecFormId,
			revision,
			auditclusterid,
			auditsessionid,
			SecAppId,
			JEEServletMapName,
			auditaction,
			auditstamp )
		select
			a00b.ClusterId as ClusterId,
			a00b.SecFormId as SecFormId,
			a00b.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a00b.SecAppId as SecAppId,
			a00b.JEEServletMapName as JEEServletMapName,
			0,
			use_stamp
		from cfinet213.SecForm a00b
		where
			a00b.ClusterId = argClusterId
			and a00b.SecFormId = argSecFormId;

	open retCursor for select
			a00b.createdby,
			to_char( a00b.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a00b.updatedby,
			to_char( a00b.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a00b.ClusterId as ClusterId,
			a00b.SecFormId as SecFormId,
			a00b.SecAppId as SecAppId,
			a00b.JEEServletMapName as JEEServletMapName,
		a00b.revision as revision
	from cfinet213.SecForm a00b
	where
		a00b.ClusterId = argClusterId
			and a00b.SecFormId = argSecFormId;
end crt_secform;
/

show errors procedure cfinet213.crt_secform;