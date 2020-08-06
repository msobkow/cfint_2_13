#!/bin/bash
#
#	@(#) dbcreate/cfint/db2luw/crtbl_cfinet213.bash
#
#	org.msscf.msscf.CFInt
#
#	Copyright (c) 2020 Mark Stephen Sobkow
#	
#	MSS Code Factory CFInt 2.13 Internet Essentials
#	
#	Copyright 2020 Mark Stephen Sobkow
#	
#		This file is part of MSS Code Factory.
#	
#		MSS Code Factory is available under dual commercial license from Mark Stephen
#		Sobkow, or under the terms of the GNU General Public License, Version 3
#		or later.
#	
#	    MSS Code Factory is free software: you can redistribute it and/or modify
#	    it under the terms of the GNU General Public License as published by
#	    the Free Software Foundation, either version 3 of the License, or
#	    (at your option) any later version.
#	
#	    MSS Code Factory is distributed in the hope that it will be useful,
#	    but WITHOUT ANY WARRANTY; without even the implied warranty of
#	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	    GNU General Public License for more details.
#	
#	    You should have received a copy of the GNU General Public License
#	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
#	
#	Donations to support MSS Code Factory can be made at
#	https://www.paypal.com/paypalme2/MarkSobkow
#	
#	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
#
#	Manufactured by MSS Code Factory 2.12
#

echo "#	Running crtbl_cfinet213_idg16.sql..."
db2 -l db2output.log -f crtbl_cfinet213_idg16.sql
echo "#	Running crtbl_cfinet213_idg32.sql..."
db2 -l db2output.log -f crtbl_cfinet213_idg32.sql
echo "#	Running crtbl_cfinet213_idg64.sql..."
db2 -l db2output.log -f crtbl_cfinet213_idg64.sql
echo "#	Running crtbl_clus.sql..."
db2 -l db2output.log -f crtbl_clus.sql
echo "#	Running crtbl_clus_idg32.sql..."
db2 -l db2output.log -f crtbl_clus_idg32.sql
echo "#	Running crtbl_clus_idg64.sql..."
db2 -l db2output.log -f crtbl_clus_idg64.sql
echo "#	Running crtbl_secapp.sql..."
db2 -l db2output.log -f crtbl_secapp.sql
echo "#	Running crtbl_secform.sql..."
db2 -l db2output.log -f crtbl_secform.sql
echo "#	Running crtbl_secgrp.sql..."
db2 -l db2output.log -f crtbl_secgrp.sql
echo "#	Running crtbl_secgrpfrm.sql..."
db2 -l db2output.log -f crtbl_secgrpfrm.sql
echo "#	Running crtbl_secsess.sql..."
db2 -l db2output.log -f crtbl_secsess.sql
echo "#	Running crtbl_secuser.sql..."
db2 -l db2output.log -f crtbl_secuser.sql
echo "#	Running crtbl_tenant.sql..."
db2 -l db2output.log -f crtbl_tenant.sql
echo "#	Running crtbl_tenant_idg32.sql..."
db2 -l db2output.log -f crtbl_tenant_idg32.sql
echo "#	Running crtbl_tenant_idg64.sql..."
db2 -l db2output.log -f crtbl_tenant_idg64.sql
echo "#	Running crtbl_hostnode.sql..."
db2 -l db2output.log -f crtbl_hostnode.sql
echo "#	Running crtbl_iso_ccy.sql..."
db2 -l db2output.log -f crtbl_iso_ccy.sql
echo "#	Running crtbl_iso_cntry.sql..."
db2 -l db2output.log -f crtbl_iso_cntry.sql
echo "#	Running crtbl_iso_cntryccy.sql..."
db2 -l db2output.log -f crtbl_iso_cntryccy.sql
echo "#	Running crtbl_iso_cntrylng.sql..."
db2 -l db2output.log -f crtbl_iso_cntrylng.sql
echo "#	Running crtbl_iso_lang.sql..."
db2 -l db2output.log -f crtbl_iso_lang.sql
echo "#	Running crtbl_isotz.sql..."
db2 -l db2output.log -f crtbl_isotz.sql
echo "#	Running crtbl_licn.sql..."
db2 -l db2output.log -f crtbl_licn.sql
echo "#	Running crtbl_mjvrdef.sql..."
db2 -l db2output.log -f crtbl_mjvrdef.sql
echo "#	Running crtbl_mimetype.sql..."
db2 -l db2output.log -f crtbl_mimetype.sql
echo "#	Running crtbl_mnvrdef.sql..."
db2 -l db2output.log -f crtbl_mnvrdef.sql
echo "#	Running crtbl_secdev.sql..."
db2 -l db2output.log -f crtbl_secdev.sql
echo "#	Running crtbl_secinc.sql..."
db2 -l db2output.log -f crtbl_secinc.sql
echo "#	Running crtbl_secmemb.sql..."
db2 -l db2output.log -f crtbl_secmemb.sql
echo "#	Running crtbl_hostsvc.sql..."
db2 -l db2output.log -f crtbl_hostsvc.sql
echo "#	Running crtbl_svctype.sql..."
db2 -l db2output.log -f crtbl_svctype.sql
echo "#	Running crtbl_sprjdef.sql..."
db2 -l db2output.log -f crtbl_sprjdef.sql
echo "#	Running crtbl_sysclus.sql..."
db2 -l db2output.log -f crtbl_sysclus.sql
echo "#	Running crtbl_tsecgrp.sql..."
db2 -l db2output.log -f crtbl_tsecgrp.sql
echo "#	Running crtbl_tsecinc.sql..."
db2 -l db2output.log -f crtbl_tsecinc.sql
echo "#	Running crtbl_tsecmemb.sql..."
db2 -l db2output.log -f crtbl_tsecmemb.sql
echo "#	Running crtbl_tlddef.sql..."
db2 -l db2output.log -f crtbl_tlddef.sql
echo "#	Running crtbl_tdomdef.sql..."
db2 -l db2output.log -f crtbl_tdomdef.sql
echo "#	Running crtbl_tprjdef.sql..."
db2 -l db2output.log -f crtbl_tprjdef.sql
echo "#	Running crtbl_urlproto.sql..."
db2 -l db2output.log -f crtbl_urlproto.sql
echo "#	Running crtbl_clus_h.sql..."
db2 -l db2output.log -f crtbl_clus_h.sql
echo "#	Running crtbl_hostnode_h.sql..."
db2 -l db2output.log -f crtbl_hostnode_h.sql
echo "#	Running crtbl_iso_ccy_h.sql..."
db2 -l db2output.log -f crtbl_iso_ccy_h.sql
echo "#	Running crtbl_iso_cntry_h.sql..."
db2 -l db2output.log -f crtbl_iso_cntry_h.sql
echo "#	Running crtbl_iso_cntryccy_h.sql..."
db2 -l db2output.log -f crtbl_iso_cntryccy_h.sql
echo "#	Running crtbl_iso_cntrylng_h.sql..."
db2 -l db2output.log -f crtbl_iso_cntrylng_h.sql
echo "#	Running crtbl_iso_lang_h.sql..."
db2 -l db2output.log -f crtbl_iso_lang_h.sql
echo "#	Running crtbl_isotz_h.sql..."
db2 -l db2output.log -f crtbl_isotz_h.sql
echo "#	Running crtbl_mjvrdef_h.sql..."
db2 -l db2output.log -f crtbl_mjvrdef_h.sql
echo "#	Running crtbl_mimetype_h.sql..."
db2 -l db2output.log -f crtbl_mimetype_h.sql
echo "#	Running crtbl_mnvrdef_h.sql..."
db2 -l db2output.log -f crtbl_mnvrdef_h.sql
echo "#	Running crtbl_secapp_h.sql..."
db2 -l db2output.log -f crtbl_secapp_h.sql
echo "#	Running crtbl_secdev_h.sql..."
db2 -l db2output.log -f crtbl_secdev_h.sql
echo "#	Running crtbl_secform_h.sql..."
db2 -l db2output.log -f crtbl_secform_h.sql
echo "#	Running crtbl_secgrp_h.sql..."
db2 -l db2output.log -f crtbl_secgrp_h.sql
echo "#	Running crtbl_secgrpfrm_h.sql..."
db2 -l db2output.log -f crtbl_secgrpfrm_h.sql
echo "#	Running crtbl_secinc_h.sql..."
db2 -l db2output.log -f crtbl_secinc_h.sql
echo "#	Running crtbl_secmemb_h.sql..."
db2 -l db2output.log -f crtbl_secmemb_h.sql
echo "#	Running crtbl_secuser_h.sql..."
db2 -l db2output.log -f crtbl_secuser_h.sql
echo "#	Running crtbl_hostsvc_h.sql..."
db2 -l db2output.log -f crtbl_hostsvc_h.sql
echo "#	Running crtbl_svctype_h.sql..."
db2 -l db2output.log -f crtbl_svctype_h.sql
echo "#	Running crtbl_sprjdef_h.sql..."
db2 -l db2output.log -f crtbl_sprjdef_h.sql
echo "#	Running crtbl_tsecgrp_h.sql..."
db2 -l db2output.log -f crtbl_tsecgrp_h.sql
echo "#	Running crtbl_tsecinc_h.sql..."
db2 -l db2output.log -f crtbl_tsecinc_h.sql
echo "#	Running crtbl_tsecmemb_h.sql..."
db2 -l db2output.log -f crtbl_tsecmemb_h.sql
echo "#	Running crtbl_tenant_h.sql..."
db2 -l db2output.log -f crtbl_tenant_h.sql
echo "#	Running crtbl_tlddef_h.sql..."
db2 -l db2output.log -f crtbl_tlddef_h.sql
echo "#	Running crtbl_tdomdef_h.sql..."
db2 -l db2output.log -f crtbl_tdomdef_h.sql
echo "#	Running crtbl_tprjdef_h.sql..."
db2 -l db2output.log -f crtbl_tprjdef_h.sql
echo "#	Running crtbl_urlproto_h.sql..."
db2 -l db2output.log -f crtbl_urlproto_h.sql

