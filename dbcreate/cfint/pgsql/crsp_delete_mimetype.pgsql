--
--	@(#) dbcreate/cfint/pgsql/crsp_delete_mimetype.pgsql
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
create or replace function cfinet213.sp_delete_mimetype(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argMimeTypeId integer,
	argRevision int )
returns boolean as $$
declare
	RowsAffected integer;
	cur record;
	subret boolean;
	oldMimeTypeId integer;
	oldName varchar(128);
	oldFileTypes varchar(128);
	oldRevision int;
	permissionFlag boolean;
begin
		select
			MimeTypeId,
			safe_name,
			FileTypes,
			revision
		into
			oldMimeTypeId,
			oldName,
			oldFileTypes,
			oldRevision
		from cfinet213.MimeType
		where
			MimeTypeId = argMimeTypeId
		for update;

	select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
	if( permissionFlag = false )
	then
		raise exception 'Permission denied -- only system user can delete MimeType records';
	end if;

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
			argRevision + 1,
			2
		from cfinet213.MimeType as a103
		where
			a103.mimetypeid = argMimeTypeId;


	delete from cfinet213.MimeType
	where
		mimetypeid = argMimeTypeId;

	get diagnostics RowsAffected = row_count;
	if RowsAffected != 1 and RowsAffected != 0
	then
		raise exception 'sp_delete_mimetype() Expected to affect 1 MimeType, not %', RowsAffected;
	end if;

	return true;
end;
$$ language plpgsql;
