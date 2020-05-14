--
--	@(#) dbcreate/cfint/pgsql/crsp_update_mimetype.pgsql
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

create or replace function cfinet213.sp_update_mimetype(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argMimeTypeId integer,
	argName varchar(128),
	argFileTypes varchar(128),
	argRevision integer )
returns setof cfinet213.type_mimetype_rec as $$
declare
	RowsAffected integer;
	oldMimeTypeId integer;
	oldName varchar(128);
	oldFileTypes varchar(128);
	oldRevision int;
	permissionFlag boolean;
begin
	if( argClassCode = 'a103' )
	then
		select cfinet213.sp_is_system_user( argAuditUserId ) into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- only system user can update MimeType records';
		end if;
	end if;

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


	if argRevision != oldRevision
	then
		raise exception 'sp_update_mimetype() Data collision detected';
	end if;


	update cfinet213.MimeType
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = now(),
		safe_name = argName,
		filetypes = argFileTypes
	where
		MimeTypeId = argMimeTypeId
		and revision = oldRevision;

	get diagnostics RowsAffected = row_count;

	if RowsAffected != 1
	then
		raise exception 'sp_update_mimetype() Expected to affect one MimeType row, not %', RowsAffected;
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
			1
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
