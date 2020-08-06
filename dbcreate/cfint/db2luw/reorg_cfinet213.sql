--
--	@(#) dbcreate/cfint/db2luw/reorg_cfinet213.sql
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
REORG TABLE CFINet213.clus index CFINet213.cluster_pk
REORG TABLE CFINet213.HostNode index CFINet213.HostNode_pidx
REORG TABLE CFINet213.iso_ccy index CFINet213.isocurrency_pk
REORG TABLE CFINet213.iso_cntry index CFINet213.isocountry_pk
REORG TABLE CFINet213.iso_cntryccy index CFINet213.isocountryccy_pk
REORG TABLE CFINet213.iso_cntrylng index CFINet213.isocountrylang_pk
REORG TABLE CFINet213.iso_lang index CFINet213.isolang_pk
REORG TABLE CFINet213.ISOTz index CFINet213.ITz_pidx
REORG TABLE CFINet213.licn index CFINet213.lic_pk
REORG TABLE CFINet213.mjvrdef index CFINet213.mjvrdef_pk
REORG TABLE CFINet213.MimeType index CFINet213.MimeType_pidx
REORG TABLE CFINet213.mnvrdef index CFINet213.mnvrdef_pk
REORG TABLE CFINet213.SecApp index CFINet213.SecApp_pidx
REORG TABLE CFINet213.SecDev index CFINet213.SecDev_pidx
REORG TABLE CFINet213.SecForm index CFINet213.SecForm_pidx
REORG TABLE CFINet213.SecGrp index CFINet213.SecGroup_pidx
REORG TABLE CFINet213.SecGrpFrm index CFINet213.SecGroupForm_pidx
REORG TABLE CFINet213.SecInc index CFINet213.SecInclude_pidx
REORG TABLE CFINet213.SecMemb index CFINet213.SecMember_pidx
REORG TABLE CFINet213.SecSess index CFINet213.Session_pidx
REORG TABLE CFINet213.SecUser index CFINet213.SecUser_pidx
REORG TABLE CFINet213.HostSvc index CFINet213.Service_pidx
REORG TABLE CFINet213.SvcType index CFINet213.ServiceType_pidx
REORG TABLE CFINet213.sprjdef index CFINet213.sprjdef_pk
REORG TABLE CFINet213.sysclus index CFINet213.syscluster_pk
REORG TABLE CFINet213.TSecGrp index CFINet213.TSecGroup_pidx
REORG TABLE CFINet213.TSecInc index CFINet213.TSecInclude_pidx
REORG TABLE CFINet213.TSecMemb index CFINet213.TSecMember_pidx
REORG TABLE CFINet213.tenant index CFINet213.tenant_pk
REORG TABLE CFINet213.tlddef index CFINet213.tlddef_pk
REORG TABLE CFINet213.tdomdef index CFINet213.tdomdef_pk
REORG TABLE CFINet213.tprjdef index CFINet213.tprjdef_pk
REORG TABLE CFINet213.URLProto index CFINet213.URLProto_pidx

commit
