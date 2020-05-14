--
--	@(#) dbcreate/cfint/oracle/crcrt_urlproto.plsql
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

create or replace procedure cfinet213.crt_urlproto(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argsafe_name varchar2,
	argDescription varchar2,
	argIsSecure char ) authid definer
is
	permissionDenied exception;
	use_stamp cfinet213.URLProto_h.auditstamp%type;
	permissionFlag integer;
	argURLProtocolId integer;
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

	argURLProtocolId := cfinet213.nxt_urlprotocolidgen();
	insert into cfinet213.urlproto(
		createdby,
		createdat,
		updatedby,
		updatedat,
		URLProtocolId,
		safe_name,
		Description,
		IsSecure,
		revision )
	values (
		argAuditUserId,
		use_stamp,
		argAuditUserId,
		use_stamp,
		argURLProtocolId,
		argsafe_name,
		argDescription,
		argIsSecure,
		1 );
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
			a109.revision as revision,
			argAuditClusterId,
			argAuditSessionId,
			a109.safe_name as safe_name,
			a109.Description as Description,
			a109.IsSecure as IsSecure,
			0,
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
end crt_urlproto;
/

show errors procedure cfinet213.crt_urlproto;
