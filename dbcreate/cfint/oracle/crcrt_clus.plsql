--
--	@(#) dbcreate/cfint/oracle/crcrt_clus.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace procedure cfinet213.crt_clus(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argFullDomName varchar2,
	argDescription varchar2 ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.clus_h.auditstamp%type;
	permissionFlag integer;
	argId numeric;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a001' )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argId := cfinet213.nxt_clusteridgen();
	insert into cfinet213.clus(
		createdby,
		createdat,
		updatedby,
		updatedat,
		Id,
		FullDomName,
		Description,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argId,
		argFullDomName,
		argDescription,
		1 );
	insert into cfinet213.clus_h (
			Id,
			revision,
			auditclusterid,
			auditsessionid,
			FullDomName,
			Description,
			auditaction,
			auditstamp )
		select
			a001.Id as Id,
			a001.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a001.FullDomName as FullDomName,
			a001.Description as Description,
			0,
			use_stamp
		from cfinet213.clus a001
		where
			a001.Id = argId;

	open retCursor for select
			a001.createdby,
			to_char( a001.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a001.updatedby,
			to_char( a001.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a001.Id as Id,
			a001.FullDomName as FullDomName,
			a001.Description as Description,
		a001.revision as revision
	from cfinet213.clus a001
	where
		a001.Id = argId;
end crt_clus;
/

show errors procedure cfinet213.crt_clus;
