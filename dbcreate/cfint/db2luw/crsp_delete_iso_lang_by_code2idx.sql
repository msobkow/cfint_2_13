--
--	@(#) dbcreate/cfint/db2luw/crsp_delete_iso_lang_by_code2idx.sql
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
create or replace procedure sp_delete_iso_lang_by_code2idx(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argISO6391Code varchar(2) )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
begin 	\
		for cur as	\
			select	\
					a007.isolangid as isolangid,	\
				a007.revision as revision	\
			from cfinet213.iso_lang as a007	\
			where	\
				( ( ( argISO6391Code is null ) and ( a007.iso_code2 is null ) )	\
				or ( ( argISO6391Code is not null ) and ( a007.iso_code2 = argISO6391Code ) ) )	\
		do	\
			call sp_delete_iso_lang( argAuditClusterId,	\
							argAuditUserId,	\
							argAuditSessionId,	\
							secClusterId,	\
							secTenantId,	\
							isolangid,	\
							revision );	\
		end for;	\
		open retcursor;	\
	end;	\
end