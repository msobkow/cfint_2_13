--
--	@(#) dbcreate/cfint/db2luw/crsp_read_svctype.sql
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
create or replace procedure sp_read_svctype(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argServiceTypeId integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare permissionFlag integer;	\
	declare isSystemUser integer;	\
	declare syscurs cursor with return to client for	\
		select	\
				a013.createdby as createdby,	\
				to_char( a013.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a013.updatedby as updatedby,	\
				to_char( a013.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a013.servicetypeid as servicetypeid,	\
			a013.description as description,	\
			a013.revision as revision	\
		from cfinet213.SvcType as a013	\
		where	\
			a013.servicetypeid = argServiceTypeId;	\
	declare usercurs cursor with return to client for	\
		select	\
				a013.createdby as createdby,	\
				to_char( a013.createdat, 'YYYY-MM-DD-HH24.MI.SS' ) as createdat,	\
				a013.updatedby as updatedby,	\
				to_char( a013.updatedat, 'YYYY-MM-DD-HH24.MI.SS' ) as updatedat,	\
			a013.servicetypeid as servicetypeid,	\
			a013.description as description,	\
			a013.revision as revision	\
		from cfinet213.SvcType as a013	\
		where	\
			a013.servicetypeid = argServiceTypeId;	\
	begin	\
		open syscurs;	\
	end;	\
end
