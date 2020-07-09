--
--	@(#) dbcreate/cfint/oracle/crdl_mimetype.plsql
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

create or replace procedure cfinet213.dl_mimetype(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argMimeTypeId integer,
	argRevision int ) authid definer
is
	use_stamp cfinet213.MimeType_h.auditstamp%type;
	oldMimeTypeId integer;
	oldsafe_name varchar2(128);
	oldFileTypes varchar2(128);
	oldRevision integer;
	permissionFlag integer;
	permissionDenied exception;
	dataCollision exception;
	dataUpdateFailed exception;
begin
	use_stamp := systimestamp;
		select
			MimeTypeId,
			safe_name,
			FileTypes,
			revision
		into
			oldMimeTypeId,
			oldsafe_name,
			oldFileTypes,
			oldRevision
		from cfinet213.MimeType
		where
			MimeTypeId = argMimeTypeId
		for update;

	permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
	if( permissionFlag = 0 )
	then
		raise permissionDenied;
	end if;

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
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a103.safe_name as safe_name,
			a103.FileTypes as FileTypes,
			2,
			use_stamp
		from cfinet213.MimeType a103
		where
			a103.MimeTypeId = argMimeTypeId;

	delete from cfinet213.MimeType
	where
		MimeTypeId = argMimeTypeId;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;

end dl_mimetype;
/

show errors procedure cfinet213.dl_mimetype;
