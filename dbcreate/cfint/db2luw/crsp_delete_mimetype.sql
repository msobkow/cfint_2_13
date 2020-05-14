--
--	@(#) dbcreate/cfint/db2luw/crsp_delete_mimetype.sql
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
create or replace procedure sp_delete_mimetype(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argMimeTypeId integer,	\
	in argRevision int )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldMimeTypeId integer;	\
	declare oldName varchar(128);	\
	declare oldFileTypes varchar(128);	\
	declare oldRevision int;	\
	declare subret boolean;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select 1 from sysibm.sysdummy1;	\
	begin	\
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
		set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
		if( permissionFlag = 0 )	\
		then	\
			call raise_application_error( -20001, 'Permission denied -- only system user can delete MimeType records' );	\
		end if;	\
	\
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
			a103.revision + 1,	\
			2	\
		from cfinet213.MimeType as a103	\
		where	\
			a103.mimetypeid = argMimeTypeId;	\
	\
		delete from cfinet213.MimeType	\
		where	\
			mimetypeid = argMimeTypeId;	\
	\
		open retcursor;	\
	end;	\
end
