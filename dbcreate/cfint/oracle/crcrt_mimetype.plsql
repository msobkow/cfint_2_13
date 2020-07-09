--
--	@(#) dbcreate/cfint/oracle/crcrt_mimetype.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfinet213.crt_mimetype(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argsafe_name varchar2,
	argFileTypes varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.MimeType_h.auditstamp%type;
	permissionFlag integer;
	argMimeTypeId integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a103' )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argMimeTypeId := cfinet213.nxt_mimetypeidgen();
	insert into cfinet213.mimetype(
		createdby,
		createdat,
		updatedby,
		updatedat,
		MimeTypeId,
		safe_name,
		FileTypes,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argMimeTypeId,
		argsafe_name,
		argFileTypes,
		1 );
	insert into cfinet213.MimeType_h (
			MimeTypeId,
			revision,
			auditclusterid,
			auditsessionid,
			safe_name,
			FileTypes,
			auditaction,
			auditstamp )
		select
			a103.MimeTypeId as MimeTypeId,
			a103.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a103.safe_name as safe_name,
			a103.FileTypes as FileTypes,
			0,
			use_stamp
		from cfinet213.MimeType a103
		where
			a103.MimeTypeId = argMimeTypeId;

	open retCursor for select
			a103.createdby,
			to_char( a103.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a103.updatedby,
			to_char( a103.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a103.MimeTypeId as MimeTypeId,
			a103.safe_name as safe_name,
			a103.FileTypes as FileTypes,
		a103.revision as revision
	from cfinet213.MimeType a103
	where
		a103.MimeTypeId = argMimeTypeId;
end crt_mimetype;
/

show errors procedure cfinet213.crt_mimetype;
