--
--	@(#) dbcreate/cfint/oracle/crdl_mimetypebyididx.plsql
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

create or replace procedure cfinet213.dl_mimetypebyididx(
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argMimeTypeId integer ) authid definer
is
	unrecognizedClassCode exception;
	permissionFlag integer;
	cursor cursNormal is
		select
			a103.MimeTypeId as MimeTypeId,
				a103.revision as revision
		from cfinet213.MimeType a103
		where
				a103.MimeTypeId = argMimeTypeId;
begin
	for cur in cursNormal
	loop
			cfinet213.dl_mimetype( argAuditClusterId,
					argAuditUserId,
					argAuditSessionId,
					secClusterId,
					secTenantId,
					cur.mimetypeid,
					cur.revision );
	end loop;
end dl_mimetypebyididx;
/

show errors procedure cfinet213.dl_mimetypebyididx;
