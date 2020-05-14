--
--	@(#) dbcreate/cfint/oracle/crupd_urlproto.plsql
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


create or replace procedure cfinet213.upd_urlproto(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argURLProtocolId integer,
	argsafe_name varchar2,
	argDescription varchar2,
	argIsSecure char,
	argRevision integer ) authid definer
is
	use_stamp cfinet213.URLProto_h.auditstamp%type;
	oldURLProtocolId integer;
	oldsafe_name varchar2(16);
	oldDescription varchar2(50);
	oldIsSecure char(1);
	oldRevision integer;
	dataCollision exception;
	dataUpdateFailed exception;
	permissionDenied exception;
	permissionFlag integer;
begin
	use_stamp := systimestamp;
	if( argClassCode = 'a109' )
	then
		permissionFlag := cfinet213.sp_is_system_user( argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

		select
			URLProtocolId,
			safe_name,
			Description,
			IsSecure,
			revision
		into
			oldURLProtocolId,
			oldsafe_name,
			oldDescription,
			oldIsSecure,
			oldRevision
		from cfinet213.URLProto
		where
			URLProtocolId = argURLProtocolId
		for update;

	if argRevision != oldRevision
	then
		raise dataCollision;
	end if;

	update cfinet213.URLProto
	set
		revision = argRevision + 1,
		updatedby = argAuditUserId,
		updatedat = use_stamp,
		safe_name = argsafe_name,
		Description = argDescription,
		IsSecure = argIsSecure
	where
		URLProtocolId = argURLProtocolId
		and revision = argRevision;

	if sql%rowcount != 1 then
		raise dataUpdateFailed;
	end if;


	insert into cfinet213.URLProto_h (
			URLProtocolId,
			revision,
			auditclusterid,
			auditsessionid,
			safe_name,
			Description,
			IsSecure,
			auditaction,
			auditstamp )
		select
			a109.URLProtocolId as URLProtocolId,
			argRevision + 1 as revision,
			argAuditClusterId,
			argAuditSessionId,
			a109.safe_name as safe_name,
			a109.Description as Description,
			a109.IsSecure as IsSecure,
			1,
			use_stamp
		from cfinet213.URLProto a109
		where
			a109.URLProtocolId = argURLProtocolId;

	open retCursor for select
			a109.createdby,
			to_char( a109.createdat, 'YYYY-MM-DD HH24:MI:SS' ) as createdat,
			a109.updatedby,
			to_char( a109.updatedat, 'YYYY-MM-DD HH24:MI:SS' ) as updatedat,
			a109.URLProtocolId as URLProtocolId,
			a109.safe_name as safe_name,
			a109.Description as Description,
			a109.IsSecure as IsSecure,
		a109.revision as revision
	from cfinet213.URLProto a109
	where
		a109.URLProtocolId = argURLProtocolId;
end upd_urlproto;

/

show errors procedure cfinet213.upd_urlproto;
