--
--	@(#) dbcreate/cfint/db2luw/crsp_is_cluster_user.sql
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
create or replace function sp_is_cluster_user(	\
	argClusterId bigint,	\
	argSecGroupName varchar(64),	\
	argSecUserId varchar(36) )	\
returns integer \
language sql	\
begin	\
	declare retval integer default 0;	\
  begin	\
	set( retval ) = ( 0 );	\
	for row as	\
				select	\
					susr.secuserid	\
				from cfinet213.SecUser as susr	\
				where	\
						susr.secuserid = argSecUserId	\
					and susr.login_id = 'system'	\
			union	\
				select	\
					smemb1.secuserid	\
				from cfinet213.SecGrp sgrp1	\
					inner join cfinet213.SecMemb smemb1 on	\
						smemb1.clusterid = sgrp1.clusterid	\
						and smemb1.secgroupid = sgrp1.secgroupid	\
				where	\
						sgrp1.clusterid = argClusterId	\
					and sgrp1.safe_name = argSecGroupName	\
					and smemb1.secuserid = argSecUserId	\
			union	\
				select	\
					smemb2.secuserid	\
				from cfinet213.SecGrp sgrp2	\
					inner join cfinet213.SecInc sinc2a on	\
						sinc2a.clusid = sgrp2.clusterid	\
						and sinc2a.secgrpid = sgrp2.secgroupid	\
					inner join cfinet213.SecMemb smemb2 on	\
						smemb2.clusterid = sinc2a.clusid	\
						and smemb2.secgroupid = sinc2a.incgrpid	\
				where	\
						sgrp2.clusterid = argClusterId	\
					and sgrp2.safe_name = argSecGroupName	\
					and smemb2.secuserid = argSecUserId	\
			union	\
				select	\
					smemb3.secuserid	\
				from cfinet213.SecGrp sgrp3	\
					inner join cfinet213.SecInc sinc3a on	\
						sinc3a.clusid = sgrp3.clusterid	\
						and sinc3a.secgrpid = sgrp3.secgroupid	\
					inner join cfinet213.SecInc sinc3b on	\
						sinc3b.clusid = sinc3a.clusid	\
						and sinc3b.secgrpid = sinc3a.incgrpid	\
					inner join cfinet213.SecMemb smemb3 on	\
						smemb3.clusterid = sinc3b.clusid	\
						and smemb3.secgroupid = sinc3b.incgrpid	\
				where	\
						sgrp3.clusterid = argClusterId	\
					and sgrp3.safe_name = argSecGroupName	\
					and smemb3.secuserid = argSecUserId	\
			union	\
				select	\
					smemb4.secuserid	\
				from cfinet213.SecGrp sgrp4	\
					inner join cfinet213.SecInc sinc4a on	\
						sinc4a.clusid = sgrp4.clusterid	\
						and sinc4a.secgrpid = sgrp4.secgroupid	\
					inner join cfinet213.SecInc sinc4b on	\
						sinc4b.clusid = sinc4a.clusid	\
						and sinc4b.secgrpid = sinc4a.incgrpid	\
					inner join cfinet213.SecInc sinc4c on	\
						sinc4c.clusid = sinc4b.clusid	\
						and sinc4c.secgrpid = sinc4b.incgrpid	\
					inner join cfinet213.SecMemb smemb4 on	\
						smemb4.clusterid = sinc4c.clusid	\
						and smemb4.secgroupid = sinc4c.incgrpid	\
				where	\
						sgrp4.clusterid = argClusterId	\
					and sgrp4.safe_name = argSecGroupName	\
					and smemb4.secuserid = argSecUserId	\
			union	\
				select	\
					smemb5.secuserid	\
				from cfinet213.SecGrp sgrp5	\
					inner join cfinet213.SecInc sinc5a on	\
						sinc5a.clusid = sgrp5.clusterid	\
						and sinc5a.secgrpid = sgrp5.secgroupid	\
					inner join cfinet213.SecInc sinc5b on	\
						sinc5b.clusid = sinc5a.clusid	\
						and sinc5b.secgrpid = sinc5a.incgrpid	\
					inner join cfinet213.SecInc sinc5c on	\
						sinc5c.clusid = sinc5b.clusid	\
						and sinc5c.secgrpid = sinc5b.incgrpid	\
					inner join cfinet213.SecInc sinc5d on	\
						sinc5d.clusid = sinc5c.clusid	\
						and sinc5d.secgrpid = sinc5c.incgrpid	\
					inner join cfinet213.SecMemb smemb5 on	\
						smemb5.clusterid = sinc5d.clusid	\
						and smemb5.secgroupid = sinc5d.incgrpid	\
				where	\
						sgrp5.clusterid = argClusterId	\
					and sgrp5.safe_name = argSecGroupName	\
					and smemb5.secuserid = argSecUserId	\
			union	\
				select	\
					smemb6.secuserid	\
				from cfinet213.SecGrp sgrp6	\
					inner join cfinet213.SecInc sinc6a on	\
						sinc6a.clusid = sgrp6.clusterid	\
						and sinc6a.secgrpid = sgrp6.secgroupid	\
					inner join cfinet213.SecInc sinc6b on	\
						sinc6b.clusid = sinc6a.clusid	\
						and sinc6b.secgrpid = sinc6a.incgrpid	\
					inner join cfinet213.SecInc sinc6c on	\
						sinc6c.clusid = sinc6b.clusid	\
						and sinc6c.secgrpid = sinc6b.incgrpid	\
					inner join cfinet213.SecInc sinc6d on	\
						sinc6d.clusid = sinc6c.clusid	\
						and sinc6d.secgrpid = sinc6c.incgrpid	\
					inner join cfinet213.SecInc sinc6e on	\
						sinc6e.clusid = sinc6d.clusid	\
						and sinc6e.secgrpid = sinc6d.incgrpid	\
					inner join cfinet213.SecMemb smemb6 on	\
						smemb6.clusterid = sinc6e.clusid	\
						and smemb6.secgroupid = sinc6e.incgrpid	\
				where	\
						sgrp6.clusterid = argClusterId	\
					and sgrp6.safe_name = argSecGroupName	\
					and smemb6.secuserid = argSecUserId	\
			union	\
				select	\
					smemb7.secuserid	\
				from cfinet213.SecGrp sgrp7	\
					inner join cfinet213.SecInc sinc7a on	\
						sinc7a.clusid = sgrp7.clusterid	\
						and sinc7a.secgrpid = sgrp7.secgroupid	\
					inner join cfinet213.SecInc sinc7b on	\
						sinc7b.clusid = sinc7a.clusid	\
						and sinc7b.secgrpid = sinc7a.incgrpid	\
					inner join cfinet213.SecInc sinc7c on	\
						sinc7c.clusid = sinc7b.clusid	\
						and sinc7c.secgrpid = sinc7b.incgrpid	\
					inner join cfinet213.SecInc sinc7d on	\
						sinc7d.clusid = sinc7c.clusid	\
						and sinc7d.secgrpid = sinc7c.incgrpid	\
					inner join cfinet213.SecInc sinc7e on	\
						sinc7e.clusid = sinc7d.clusid	\
						and sinc7e.secgrpid = sinc7d.incgrpid	\
					inner join cfinet213.SecInc sinc7f on	\
						sinc7f.clusid = sinc7e.clusid	\
						and sinc7f.secgrpid = sinc7e.incgrpid	\
					inner join cfinet213.SecMemb smemb7 on	\
						smemb7.clusterid = sinc7f.clusid	\
						and smemb7.secgroupid = sinc7f.incgrpid	\
				where	\
						sgrp7.clusterid = argClusterId	\
					and sgrp7.safe_name = argSecGroupName	\
					and smemb7.secuserid = argSecUserId	\
			union	\
				select	\
					smemb8.secuserid	\
				from cfinet213.SecGrp sgrp8	\
					inner join cfinet213.SecInc sinc8a on	\
						sinc8a.clusid = sgrp8.clusterid	\
						and sinc8a.secgrpid = sgrp8.secgroupid	\
					inner join cfinet213.SecInc sinc8b on	\
						sinc8b.clusid = sinc8a.clusid	\
						and sinc8b.secgrpid = sinc8a.incgrpid	\
					inner join cfinet213.SecInc sinc8c on	\
						sinc8c.clusid = sinc8b.clusid	\
						and sinc8c.secgrpid = sinc8b.incgrpid	\
					inner join cfinet213.SecInc sinc8d on	\
						sinc8d.clusid = sinc8c.clusid	\
						and sinc8d.secgrpid = sinc8c.incgrpid	\
					inner join cfinet213.SecInc sinc8e on	\
						sinc8e.clusid = sinc8d.clusid	\
						and sinc8e.secgrpid = sinc8d.incgrpid	\
					inner join cfinet213.SecInc sinc8f on	\
						sinc8f.clusid = sinc8e.clusid	\
						and sinc8f.secgrpid = sinc8e.incgrpid	\
					inner join cfinet213.SecInc sinc8g on	\
						sinc8g.clusid = sinc8f.clusid	\
						and sinc8g.secgrpid = sinc8f.incgrpid	\
					inner join cfinet213.SecMemb smemb8 on	\
						smemb8.clusterid = sinc8g.clusid	\
						and smemb8.secgroupid = sinc8g.incgrpid	\
				where	\
						sgrp8.clusterid = argClusterId	\
					and sgrp8.safe_name = argSecGroupName	\
					and smemb8.secuserid = argSecUserId	\
	do	\
		set( retval ) = ( 1 );	\
		return retval;	\
	end for;	\
	return retval;	\
  end;	\
end