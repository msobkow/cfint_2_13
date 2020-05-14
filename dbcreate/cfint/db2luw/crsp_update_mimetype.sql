--
--	@(#) dbcreate/cfint/db2luw/crsp_update_mimetype.sql
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

create or replace procedure sp_update_mimetype(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argMimeTypeId integer,	\
	in argName varchar(128),	\
	in argFileTypes varchar(128),	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldMimeTypeId integer;	\
	declare oldName varchar(128);	\
	declare oldFileTypes varchar(128);	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a103.createdby as createdby,	\
				to_char( a103.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a103.updatedby as updatedby,	\
				to_char( a103.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a103.mimetypeid as mimetypeid,	\
			a103.safe_name as safe_name,	\
			a103.filetypes as filetypes,	\
			a103.revision as revision	\
		from cfinet213.MimeType as a103	\
		where	\
			a103.mimetypeid = argMimeTypeId;	\
	begin	\
		if( argClassCode = 'a103' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can update MimeType records' );	\
			end if;	\
		end if;	\
	\
		select	\
			MimeTypeId,	\
			safe_name,	\
			FileTypes,	\
			revision	\
		into	\
			oldMimeTypeId,	\
			oldName,	\
			oldFileTypes,	\
			oldRevision	\
		from cfinet213.MimeType	\
		where	\
			MimeTypeId = argMimeTypeId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_mimetype() Data collision detected' );	\
		end if;	\
	\
		update cfinet213.MimeType	\
		set	\
			revision = argRevision + 1,	\
			updatedby = argAuditUserId,	\
			updatedat = current timestamp,	\
			safe_name = argName,	\
			filetypes = argFileTypes	\
		where	\
			mimetypeid = argMimeTypeId	\
		and revision = argRevision;	\
	\
		insert into cfinet213.MimeType_h (	\
				mimetypeid,	\
			auditclusterid,	\
			auditsessionid,	\
			auditstamp,	\
				safe_name,	\
				filetypes,	\
			revision,	\
			auditaction )	\
		select	\
				a103.mimetypeid,	\
			argAuditClusterId,	\
			argAuditSessionId,	\
			current timestamp,	\
				a103.safe_name,	\
				a103.filetypes,	\
			a103.revision,	\
			2	\
		from cfinet213.MimeType as a103	\
		where	\
			a103.mimetypeid = argMimeTypeId;	\
	\
		open retcursor;	\
	end;	\
end
