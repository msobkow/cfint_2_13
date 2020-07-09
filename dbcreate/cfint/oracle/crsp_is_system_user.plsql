--
--	@(#) dbcreate/cfint/oracle/crsp_is_system_user.plsql
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
alter session set plsql_warnings = 'ENABLE:ALL';
/

create or replace function cfinet213.sp_is_system_user(
	argSecUserId varchar )
return integer authid definer
is
	retval integer;
	cursor curs is
		select
			susr.secuserid as secuserid
		from cfinet213.SecUser susr
		where
				susr.secuserid = argSecUserId
			and susr.login_id = 'system';
begin
	retval := 0;
	for cur in curs
	loop
		retval := 1;
		exit;
	end loop;
	return retval;
end sp_is_system_user;
/

show errors function cfinet213.sp_is_system_user;
