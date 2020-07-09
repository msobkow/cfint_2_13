--
--	@(#) dbcreate/cfint/pgsql/crsp_create_licn.pgsql
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
create or replace function cfinet213.sp_create_licn(
	argAuditClusterId bigint,
	argAuditUserId varchar(36),
	argAuditSessionId varchar(36),
	secClusterId bigint,
	secTenantId bigint,
	argClassCode varchar(4),
	argTenantId bigint,
	argTopDomainId bigint,
	argName varchar(64),
	argDescription varchar(1024),
	argEmbeddedText text,
	argFullText text )
returns setof cfinet213.type_licn_rec as $$
declare
	permissionFlag boolean;
	argId bigint;
begin
	if( argClassCode = 'a101' )
	then
		select cfinet213.sp_is_tenant_user( argTenantId,
			'CreateLicense',
			argAuditUserId )
		into permissionFlag;
		if( permissionFlag = false )
		then
			raise exception 'Permission denied -- User not found in tenant TSecGroup for CreateLicense';
		end if;
	end if;

	select cfinet213.sp_next_licenseidgen( argTenantId )
	into argId;

	insert into cfinet213.licn(
		tenantid,
		id,
		topdomainid,
		safe_name,
		descr,
		embeddedtext,
		fulltxt,
		revision )
	values (
		argTenantId,
		argId,
		argTopDomainId,
		argName,
		argDescription,
		argEmbeddedText,
		argFullText,
		1 );

	return query select
			a101.tenantid as tenantid,
			a101.id as id,
			a101.topdomainid as topdomainid,
			a101.safe_name as safe_name,
			a101.descr as descr,
			a101.embeddedtext as embeddedtext,
			a101.fulltxt as fulltxt,
			a101.revision as revision
	from cfinet213.licn as a101
	where
			a101.tenantid = argTenantId
			and a101.id = argId;

	return;
end;
$$ language plpgsql;
