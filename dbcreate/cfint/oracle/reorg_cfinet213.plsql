--
--	@(#) dbcreate/cfint/oracle/reorg_cfinet213.plsql
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
REORG TABLE cfinet213.clus index cfinet213.cluster_pk;
REORG TABLE cfinet213.HostNode index cfinet213.HostNode_pidx;
REORG TABLE cfinet213.iso_ccy index cfinet213.isocurrency_pk;
REORG TABLE cfinet213.iso_cntry index cfinet213.isocountry_pk;
REORG TABLE cfinet213.iso_cntryccy index cfinet213.isocountryccy_pk;
REORG TABLE cfinet213.iso_cntrylng index cfinet213.isocountrylang_pk;
REORG TABLE cfinet213.iso_lang index cfinet213.isolang_pk;
REORG TABLE cfinet213.ISOTz index cfinet213.ITz_pidx;
REORG TABLE cfinet213.licn index cfinet213.lic_pk;
REORG TABLE cfinet213.mjvrdef index cfinet213.mjvrdef_pk;
REORG TABLE cfinet213.MimeType index cfinet213.MimeType_pidx;
REORG TABLE cfinet213.mnvrdef index cfinet213.mnvrdef_pk;
REORG TABLE cfinet213.SecApp index cfinet213.SecApp_pidx;
REORG TABLE cfinet213.SecDev index cfinet213.SecDev_pidx;
REORG TABLE cfinet213.SecForm index cfinet213.SecForm_pidx;
REORG TABLE cfinet213.SecGrp index cfinet213.SecGroup_pidx;
REORG TABLE cfinet213.SecGrpFrm index cfinet213.SecGroupForm_pidx;
REORG TABLE cfinet213.SecInc index cfinet213.SecInclude_pidx;
REORG TABLE cfinet213.SecMemb index cfinet213.SecMember_pidx;
REORG TABLE cfinet213.SecSess index cfinet213.Session_pidx;
REORG TABLE cfinet213.SecUser index cfinet213.SecUser_pidx;
REORG TABLE cfinet213.HostSvc index cfinet213.Service_pidx;
REORG TABLE cfinet213.SvcType index cfinet213.ServiceType_pidx;
REORG TABLE cfinet213.sprjdef index cfinet213.sprjdef_pk;
REORG TABLE cfinet213.sysclus index cfinet213.syscluster_pk;
REORG TABLE cfinet213.TSecGrp index cfinet213.TSecGroup_pidx;
REORG TABLE cfinet213.TSecInc index cfinet213.TSecInclude_pidx;
REORG TABLE cfinet213.TSecMemb index cfinet213.TSecMember_pidx;
REORG TABLE cfinet213.tenant index cfinet213.tenant_pk;
REORG TABLE cfinet213.tlddef index cfinet213.tlddef_pk;
REORG TABLE cfinet213.tdomdef index cfinet213.tdomdef_pk;
REORG TABLE cfinet213.tprjdef index cfinet213.tprjdef_pk;
REORG TABLE cfinet213.URLProto index cfinet213.URLProto_pidx;

