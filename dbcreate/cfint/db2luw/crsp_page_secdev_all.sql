--
--	@(#) dbcreate/cfint/db2luw/crsp_page_secdev_all.sql
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
create or replace procedure sp_page_secdev_all(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in priorSecUserId varchar(36),	\
	in priorDevName varchar(127) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a00a.createdby as createdby,	\
				to_char( a00a.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00a.updatedby as updatedby,	\
				to_char( a00a.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00a.secuserid as secuserid,	\
			a00a.devname as devname,	\
			a00a.pubkey as pubkey,	\
			a00a.revision as revision	\
		from cfinet213.SecDev as a00a	\
		order by SecUserId desc,	\
			DevName desc	\
		fetch first 25 rows only;	\
	declare syspage cursor with return to client for	\
		select	\
				a00a.createdby as createdby,	\
				to_char( a00a.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00a.updatedby as updatedby,	\
				to_char( a00a.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00a.secuserid as secuserid,	\
			a00a.devname as devname,	\
			a00a.pubkey as pubkey,	\
			a00a.revision as revision	\
		from cfinet213.SecDev as a00a	\
		where ( ( ( a00a.SecUserId = priorSecUserId )	\
					and ( a00a.DevName < priorDevName ) )	\
				or ( ( a00a.SecUserId < priorSecUserId ) ) )	\
		order by SecUserId desc,	\
			DevName desc	\
		fetch first 25 rows only;	\
	declare usercurs cursor with return to client for	\
		select	\
				a00a.createdby as createdby,	\
				to_char( a00a.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00a.updatedby as updatedby,	\
				to_char( a00a.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00a.secuserid as secuserid,	\
			a00a.devname as devname,	\
			a00a.pubkey as pubkey,	\
			a00a.revision as revision	\
		from cfinet213.SecDev as a00a	\
		order by SecUserId desc,	\
			DevName desc	\
		fetch first 25 rows only;	\
	declare userpage cursor with return to client for	\
		select	\
				a00a.createdby as createdby,	\
				to_char( a00a.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a00a.updatedby as updatedby,	\
				to_char( a00a.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a00a.secuserid as secuserid,	\
			a00a.devname as devname,	\
			a00a.pubkey as pubkey,	\
			a00a.revision as revision	\
		from cfinet213.SecDev as a00a	\
		where ( ( ( a00a.SecUserId = priorSecUserId )	\
					and ( a00a.DevName < priorDevName ) )	\
				or ( ( a00a.SecUserId < priorSecUserId ) ) )	\
		order by SecUserId desc,	\
			DevName desc	\
		fetch first 25 rows only;	\
	begin	\
		if( ( priorSecUserId is not null ) and ( priorDevName is not null ) )	\
		then	\
			open syspage;	\
		end if;	\
		if( not ( ( priorSecUserId is not null ) and ( priorDevName is not null ) ) )	\
		then	\
			open syscurs;	\
		end if;	\
	end;	\
end
