--
--	@(#) dbcreate/cfint/db2luw/crsp_next_secappidgen.sql
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
create or replace procedure sp_next_secappidgen(	\
	in argId bigint,	\
	out NextId int )	\
modifies sql data	\
language sql	\
begin	\
	begin atomic	\
		if not exists (	\
			select *	\
			from cfinet213.clus_idg32	\
			where slice_id = 107	\
				and id = argId )	\
		then	\
			insert into cfinet213.clus_idg32 (	\
				id,	\
				slice_id,	\
				next_id )	\
			values (	\
				argId,	\
				107,	\
				1 );	\
		end if;	\
	\
		select next_id	\
		into NextId	\
		from cfinet213.clus_idg32	\
		where slice_id = 107	\
			and id = argId	\
		for update;	\
	\
		update cfinet213.clus_idg32	\
		set next_id = NextId + 1	\
		where slice_id = 107	\
			and id = argId;	\
	end;	\
end
