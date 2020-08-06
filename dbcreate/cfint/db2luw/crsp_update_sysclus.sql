--
--	@(#) dbcreate/cfint/db2luw/crsp_update_sysclus.sql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
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

create or replace procedure sp_update_sysclus(	\
	in argAuditClusterId bigint,	\
	in argAuditUserId varchar(36),	\
	in argAuditSessionId varchar(36),	\
	in secClusterId bigint,	\
	in secTenantId bigint,	\
	in argClassCode varchar(4),	\
	in argSingletonId integer,	\
	in argClusterId bigint,	\
	in argRevision integer )	\
dynamic result sets 1	\
language sql	\
begin	\
	declare oldSingletonId integer;	\
	declare oldClusterId bigint;	\
	declare oldRevision int;	\
	declare permissionFlag integer;	\
	declare retcursor cursor with return to client for	\
		select	\
				a014.sgltn_id as sgltn_id,	\
			a014.sys_clus_id as sys_clus_id,	\
			a014.revision as revision	\
		from cfinet213.sysclus as a014	\
		where	\
			a014.sgltn_id = argSingletonId;	\
	begin	\
		if( argClassCode = 'a014' )	\
		then	\
			set( permissionFlag ) = ( sp_is_system_user( argAuditUserId ) );	\
			if( permissionFlag = 0 )	\
			then	\
				call raise_application_error( -20001, 'Permission denied -- only system user can update SysCluster records' );	\
			end if;	\
		end if;	\
	\
		select	\
			sgltn_id,	\
			sys_clus_id,	\
			revision	\
		into	\
			oldSingletonId,	\
			oldClusterId,	\
			oldRevision	\
		from cfinet213.sysclus	\
		where	\
			sgltn_id = argSingletonId	\
		for update;	\
	\
		if argRevision != oldRevision	\
		then	\
			call raise_application_error( -20002, 'sp_update_sysclus() Data collision detected' );	\
		end if;	\
	\
		update cfinet213.sysclus	\
		set	\
			revision = argRevision + 1,	\
			sys_clus_id = argClusterId	\
		where	\
			sgltn_id = argSingletonId	\
		and revision = argRevision;	\
	\
		open retcursor;	\
	end;	\
end
