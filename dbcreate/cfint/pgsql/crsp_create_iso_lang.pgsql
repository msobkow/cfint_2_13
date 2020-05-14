--
--	@(#) dbcreate/cfint/pgsql/crsp_create_iso_lang.pgsql
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
create or replace function cfinet213.sp_create_iso_lang(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argISO6392Code varchar(3),
	argISO6391Code varchar(2),
	argEnglishName varchar(64) )
returns setof cfinet213.type_iso_lang_rec as $$
declare
	permissionFlag boolean;
	argISOLangId smallint;
begin
	if( argClassCode = 'a007' )
	then
		select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can create ISOLang records';
		end if;
	end if;

	select cfinet213.sp_next_isolangidgen()
	into argISOLangId;

	insert into cfinet213.iso_lang(
		createdby,
		createdat,
		updatedby,
		updatedat,
		isolangid,
		iso_code3,
		iso_code2,
		eng_name,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argISOLangId,
		argISO6392Code,
		argISO6391Code,
		argEnglishName,
		1 );
	insert into cfinet213.iso_lang_h (
			ISOLangId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			iso_code3,
			iso_code2,
			eng_name,
			revision,
			auditaction )
		select
			a007.ISOLangId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a007.iso_code3,
			a007.iso_code2,
			a007.eng_name,
			a007.revision,
			0
		from cfinet213.iso_lang as a007
		where
			a007.isolangid = argISOLangId;

	return query select
			a007.createdby,
			to_char( a007.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a007.updatedby,
			to_char( a007.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a007.isolangid as isolangid,
			a007.iso_code3 as iso_code3,
			a007.iso_code2 as iso_code2,
			a007.eng_name as eng_name,
			a007.revision as revision
	from cfinet213.iso_lang as a007
	where
			a007.isolangid = argISOLangId;

	return;
end;
$$ language plpgsql;
