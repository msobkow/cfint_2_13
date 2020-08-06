--
--	@(#) dbcreate/cfint/oracle/crnxt_subprojectidgen.plsql
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

create or replace function cfinet213.nxt_subprojectidgen(
	argId numeric )
return numeric authid definer
is
	SliceId smallint := 204;
	NextId numeric(22,0);
	CountEm integer;
begin
	select count(*)
	into CountEm
	from cfinet213.tenant_idg64
	where slice_id = SliceId
			and id = argId;

	if CountEm < 1 then
		insert into cfinet213.tenant_idg64 (
			id,
			slice_id,
			next_id )
		values (
			argId,
			SliceId,
			1 );
	end if;

	select next_id
	into NextId
	from cfinet213.tenant_idg64
	where slice_id = SliceId
		and id = argId
	for update;

	update cfinet213.tenant_idg64
	set next_id = NextId + 1
	where slice_id = SliceId
		and id = argId;

	return NextId;
end nxt_subprojectidgen;
/

show errors function cfinet213.nxt_subprojectidgen;