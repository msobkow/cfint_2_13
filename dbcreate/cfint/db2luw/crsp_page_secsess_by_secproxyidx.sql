--
--	@(#) dbcreate/cfint/db2luw/crsp_page_secsess_by_secproxyidx.sql
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
create or replace procedure sp_page_secsess_by_secproxyidx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argSecProxyId varchar(36),	\
	in priorSecSessionId varchar(36) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a010.secsessionid as secsessionid,	\
			a010.secuserid as secuserid,	\
			a010.secdevname as secdevname,	\
			to_char( a010.start_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as start_ts,	\
			to_char( a010.finish_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as finish_ts,	\
			a010.secproxyid as secproxyid,	\
			a010.revision as revision	\
		from cfinet213.SecSess as a010	\
		where	\
			( ( ( argSecProxyId is null ) and ( a010.secproxyid is null ) )	\
				or ( ( argSecProxyId is not null ) and ( a010.secproxyid = argSecProxyId ) ) )	\
		order by SecSessionId desc	\
		fetch first 25 rows only;	\
	declare syspage cursor with return to client for	\
		select	\
				a010.secsessionid as secsessionid,	\
			a010.secuserid as secuserid,	\
			a010.secdevname as secdevname,	\
			to_char( a010.start_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as start_ts,	\
			to_char( a010.finish_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as finish_ts,	\
			a010.secproxyid as secproxyid,	\
			a010.revision as revision	\
		from cfinet213.SecSess as a010	\
		where	\
			( ( ( argSecProxyId is null ) and ( a010.secproxyid is null ) )	\
				or ( ( argSecProxyId is not null ) and ( a010.secproxyid = argSecProxyId ) ) )	\
			and ( ( ( a010.SecSessionId < priorSecSessionId ) ) )	\
		order by SecSessionId desc	\
		fetch first 25 rows only;	\
	declare usercurs cursor with return to client for	\
		select	\
				a010.secsessionid as secsessionid,	\
			a010.secuserid as secuserid,	\
			a010.secdevname as secdevname,	\
			to_char( a010.start_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as start_ts,	\
			to_char( a010.finish_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as finish_ts,	\
			a010.secproxyid as secproxyid,	\
			a010.revision as revision	\
		from cfinet213.SecSess as a010	\
		where	\
			( ( ( argSecProxyId is null ) and ( a010.secproxyid is null ) )	\
				or ( ( argSecProxyId is not null ) and ( a010.secproxyid = argSecProxyId ) ) )	\
		order by SecSessionId desc	\
		fetch first 25 rows only;	\
	declare userpage cursor with return to client for	\
		select	\
				a010.secsessionid as secsessionid,	\
			a010.secuserid as secuserid,	\
			a010.secdevname as secdevname,	\
			to_char( a010.start_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as start_ts,	\
			to_char( a010.finish_ts, 'YYYY-MM-DD-HH24.MI.SS' ) as finish_ts,	\
			a010.secproxyid as secproxyid,	\
			a010.revision as revision	\
		from cfinet213.SecSess as a010	\
		where	\
			( ( ( argSecProxyId is null ) and ( a010.secproxyid is null ) )	\
				or ( ( argSecProxyId is not null ) and ( a010.secproxyid = argSecProxyId ) ) )	\
			and ( ( ( a010.SecSessionId < priorSecSessionId ) ) )	\
		order by SecSessionId desc	\
		fetch first 25 rows only;	\
	begin	\
		if( ( priorSecSessionId is not null ) )	\
		then	\
			open syspage;	\
		end if;	\
		if( not ( ( priorSecSessionId is not null ) ) )	\
		then	\
			open syscurs;	\
		end if;	\
	end;	\
end
