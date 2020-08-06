--
--	@(#) dbcreate/cfint/oracle/crpg_secsessbyfinishidx.plsql
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

create or replace procedure cfinet213.pg_secsessbyfinishidx(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argSecUserId varchar2,
	argfinish_ts timestamp,
	priorSecSessionId varchar2 ) authid definer
is
begin
	if( ( priorSecSessionId is not null ) )
	then
		open retCursor for
			select * from (
				select
			a010.SecSessionId as SecSessionId,
			a010.SecUserId as SecUserId,
			a010.SecDevName as SecDevName,
			to_char( a010.start_ts, 'YYYY-MM-DD HH24:MI:SS' ) as start_ts,
			to_char( a010.finish_ts, 'YYYY-MM-DD HH24:MI:SS' ) as finish_ts,
			a010.SecProxyId as SecProxyId,
					a010.revision as revision
				from cfinet213.SecSess a010
				where
					a010.SecUserId = argSecUserId
			and ( ( ( argfinish_ts is null ) and ( a010.finish_ts is null ) )
				or ( ( argfinish_ts is not null ) and ( a010.finish_ts = argfinish_ts ) ) )
			and ( ( ( a010.SecSessionId < priorSecSessionId ) ) )
		order by SecSessionId desc
			) where ROWNUM <= 25;
	end if;
	if( not ( ( priorSecSessionId is not null ) ) )
	then
		open retCursor for
			select * from (
				select
			a010.SecSessionId as SecSessionId,
			a010.SecUserId as SecUserId,
			a010.SecDevName as SecDevName,
			to_char( a010.start_ts, 'YYYY-MM-DD HH24:MI:SS' ) as start_ts,
			to_char( a010.finish_ts, 'YYYY-MM-DD HH24:MI:SS' ) as finish_ts,
			a010.SecProxyId as SecProxyId,
					a010.revision as revision
				from cfinet213.SecSess a010
				where
					a010.SecUserId = argSecUserId
			and ( ( ( argfinish_ts is null ) and ( a010.finish_ts is null ) )
				or ( ( argfinish_ts is not null ) and ( a010.finish_ts = argfinish_ts ) ) )
		order by SecSessionId desc
			) where ROWNUM <= 25;
	end if;
end pg_secsessbyfinishidx;
/

show errors procedure cfinet213.pg_secsessbyfinishidx;