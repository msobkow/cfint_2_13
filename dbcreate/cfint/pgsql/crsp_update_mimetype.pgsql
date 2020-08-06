--
--	@(#) dbcreate/cfint/pgsql/crsp_update_mimetype.pgsql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFInt 2.13 Internet Essentials
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
