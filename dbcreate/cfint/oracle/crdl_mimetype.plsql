--
--	@(#) dbcreate/cfint/oracle/crdl_mimetype.plsql
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
