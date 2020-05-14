--
--	@(#) dbcreate/cfint/pgsql/crsp_create_mimetype.pgsql
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
create or replace function cfinet213.sp_create_mimetype(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argName varchar(128),
	argFileTypes varchar(128) )
returns setof cfinet213.type_mimetype_rec as $$
declare
	permissionFlag boolean;
	argMimeTypeId integer;
begin
	if( argClassCode = 'a103' )
	then
		select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can create MimeType records';
		end if;
	end if;

	select cfinet213.sp_next_mimetypeidgen()
	into argMimeTypeId;

	insert into cfinet213.mimetype(
		createdby,
		createdat,
		updatedby,
		updatedat,
		mimetypeid,
		safe_name,
		filetypes,
		revision )
	values (
		argAuditUserId,
		now(),
		argAuditUserId,
		now(),
		argMimeTypeId,
		argName,
		argFileTypes,
		1 );
	insert into cfinet213.MimeType_h (
			MimeTypeId,
			auditclusterid,
			auditsessionid,
			auditstamp,
			safe_name,
			FileTypes,
			revision,
			auditaction )
		select
			a103.MimeTypeId,
			argAuditClusterId,
			argAuditSessionId,
			now(),
			a103.safe_name,
			a103.FileTypes,
			a103.revision,
			0
		from cfinet213.MimeType as a103
		where
			a103.mimetypeid = argMimeTypeId;

	return query select
			a103.createdby,
			to_char( a103.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a103.updatedby,
			to_char( a103.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a103.mimetypeid as mimetypeid,
			a103.safe_name as safe_name,
			a103.filetypes as filetypes,
			a103.revision as revision
	from cfinet213.MimeType as a103
	where
			a103.mimetypeid = argMimeTypeId;

	return;
end;
$$ language plpgsql;
