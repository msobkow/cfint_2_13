--
--	@(#) dbcreate/cfint/oracle/crcrt_licn.plsql
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

create or replace procedure cfinet213.crt_licn(
	retCursor out sys_refcursor,
	argAuditClusterId numeric,
	argAuditUserId varchar,
	argAuditSessionId varchar,
	secClusterId numeric,
	secTenantId numeric,
	argClassCode varchar2,
	argTenantId numeric,
	argTopDomainId numeric,
	argsafe_name varchar2,
	argdescr varchar2,
	argEmbeddedText clob,
	argFullTxt clob ) authid definer
is
	permissionDenied exception;
	permissionFlag integer;
	argId numeric;
begin
	if( argClassCode = 'a101' )
	then
		permissionFlag := cfinet213.sp_is_tenant_user( argTenantId,
			'CreateLicense',
			argAuditUserId );
		if( permissionFlag = 0 )
		then
			raise permissionDenied;
		end if;
	end if;

	argId := cfinet213.nxt_licenseidgen( argTenantId );
	insert into cfinet213.licn(
		TenantId,
		Id,
		TopDomainId,
		safe_name,
		descr,
		EmbeddedText,
		FullTxt,
		revision )
	values (
		argTenantId,
		argId,
		argTopDomainId,
		argsafe_name,
		argdescr,
		argEmbeddedText,
		argFullTxt,
		1 );
	open retCursor for select
			a101.TenantId as TenantId,
			a101.Id as Id,
			a101.TopDomainId as TopDomainId,
			a101.safe_name as safe_name,
			a101.descr as descr,
			a101.EmbeddedText as EmbeddedText,
			a101.FullTxt as FullTxt,
		a101.revision as revision
	from cfinet213.licn a101
	where
		a101.TenantId = argTenantId
			and a101.Id = argId;
end crt_licn;
/

show errors procedure cfinet213.crt_licn;