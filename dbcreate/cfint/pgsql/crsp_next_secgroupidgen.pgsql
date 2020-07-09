--
--	@(#) dbcreate/cfint/pgsql/crsp_next_secgroupidgen.pgsql
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

create or replace function cfinet213.sp_next_secgroupidgen(
	argId bigint )
returns int as $$
declare
	SliceId smallint = 109;
	NextId int;
begin
	if not exists (
		select *
		from cfinet213.clus_idg32
		where slice_id = SliceId
			and id = argId )
	then
		insert into cfinet213.clus_idg32 (
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
	from cfinet213.clus_idg32
	where slice_id = SliceId
		and id = argId
	for update;

	update cfinet213.clus_idg32
	set next_id = NextId + 1
	where slice_id = SliceId
		and id = argId;

	return NextId;
end;
$$ language plpgsql;
