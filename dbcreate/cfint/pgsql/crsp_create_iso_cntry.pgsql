--
--	@(#) dbcreate/cfint/pgsql/crsp_create_iso_cntry.pgsql
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
create or replace function cfinet213.sp_create_iso_cntry(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argISOCode varchar(2),
	argName varchar(64) )
returns setof cfinet213.type_iso_cntry_rec as $$
declare
	permissionFlag boolean;
	argISOCtryId smallint;
begin
	if( argClassCode = 'a004' )
	then
		select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can create ISOCtry records';
		end if;
	end if;

	select cfinet213.sp_next_isoctryidgen()
	into argISOCtryId;

	insert into cfinet213.iso_cntry(
		createdby,
		createdat,
		updatedby,
		updatedat,
		isoctryid,
		iso_code,
		country_name,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argISOCtryId,
		argISOCode,
		argName,
		1 );
	insert into cfinet213.iso_cntry_h (
			ISOCtryId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			iso_code,
			country_name,
			revision,
			auditaction )
		select
			a004.ISOCtryId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a004.iso_code,
			a004.country_name,
			a004.revision,
			0
		from cfinet213.iso_cntry as a004
		where
			a004.isoctryid = argISOCtryId;

	return query select
			a004.createdby,
			to_char( a004.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a004.updatedby,
			to_char( a004.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a004.isoctryid as isoctryid,
			a004.iso_code as iso_code,
			a004.country_name as country_name,
			a004.revision as revision
	from cfinet213.iso_cntry as a004
	where
			a004.isoctryid = argISOCtryId;

	return;
end;
$$ language plpgsql;
