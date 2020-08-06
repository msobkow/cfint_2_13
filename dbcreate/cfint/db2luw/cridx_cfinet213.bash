#!/bin/bash
#
#	@(#) dbcreate/cfint/db2luw/cridx_cfinet213.bash
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

echo "#	cridx_cluster_xufdname.sql ..."
db2 -l db2output.log -f cridx_cluster_xufdname.sql
echo "#	cridx_cluster_xudescr.sql ..."
db2 -l db2output.log -f cridx_cluster_xudescr.sql
echo "#	cridx_hostnode_xcluster.sql ..."
db2 -l db2output.log -f cridx_hostnode_xcluster.sql
echo "#	cridx_hostnode_xudsc.sql ..."
db2 -l db2output.log -f cridx_hostnode_xudsc.sql
echo "#	cridx_hostnode_xhnm.sql ..."
db2 -l db2output.log -f cridx_hostnode_xhnm.sql
echo "#	cridx_isocurrency_xcode.sql ..."
db2 -l db2output.log -f cridx_isocurrency_xcode.sql
echo "#	cridx_isocurrency_xuname.sql ..."
db2 -l db2output.log -f cridx_isocurrency_xuname.sql
echo "#	cridx_isocountry_xcode.sql ..."
db2 -l db2output.log -f cridx_isocountry_xcode.sql
echo "#	cridx_isocountry_xuname.sql ..."
db2 -l db2output.log -f cridx_isocountry_xuname.sql
echo "#	cridx_isocountryccy_xcountry.sql ..."
db2 -l db2output.log -f cridx_isocountryccy_xcountry.sql
echo "#	cridx_isocountryccy_xccy.sql ..."
db2 -l db2output.log -f cridx_isocountryccy_xccy.sql
echo "#	cridx_isocountrylang_xcountry.sql ..."
db2 -l db2output.log -f cridx_isocountrylang_xcountry.sql
echo "#	cridx_isocountrylang_xlang.sql ..."
db2 -l db2output.log -f cridx_isocountrylang_xlang.sql
echo "#	cridx_isolang_x6392.sql ..."
db2 -l db2output.log -f cridx_isolang_x6392.sql
echo "#	cridx_isolang_x6391.sql ..."
db2 -l db2output.log -f cridx_isolang_x6391.sql
echo "#	cridx_itz_xoffset.sql ..."
db2 -l db2output.log -f cridx_itz_xoffset.sql
echo "#	cridx_itz_xuname.sql ..."
db2 -l db2output.log -f cridx_itz_xuname.sql
echo "#	cridx_itz_xiso.sql ..."
db2 -l db2output.log -f cridx_itz_xiso.sql
echo "#	cridx_lic_xtenant.sql ..."
db2 -l db2output.log -f cridx_lic_xtenant.sql
echo "#	cridx_lic_xtdom.sql ..."
db2 -l db2output.log -f cridx_lic_xtdom.sql
echo "#	cridx_lic_xuname.sql ..."
db2 -l db2output.log -f cridx_lic_xuname.sql
echo "#	cridx_mjvrdef_xtenant.sql ..."
db2 -l db2output.log -f cridx_mjvrdef_xtenant.sql
echo "#	cridx_mjvrdef_xsprj.sql ..."
db2 -l db2output.log -f cridx_mjvrdef_xsprj.sql
echo "#	cridx_mjvrdef_unameidx.sql ..."
db2 -l db2output.log -f cridx_mjvrdef_unameidx.sql
echo "#	cridx_mimetype_xuname.sql ..."
db2 -l db2output.log -f cridx_mimetype_xuname.sql
echo "#	cridx_mnvrdef_xtenant.sql ..."
db2 -l db2output.log -f cridx_mnvrdef_xtenant.sql
echo "#	cridx_mnvrdef_xmjvr.sql ..."
db2 -l db2output.log -f cridx_mnvrdef_xmjvr.sql
echo "#	cridx_mnvrdef_unameidx.sql ..."
db2 -l db2output.log -f cridx_mnvrdef_unameidx.sql
echo "#	cridx_secapp_xcluster.sql ..."
db2 -l db2output.log -f cridx_secapp_xcluster.sql
echo "#	cridx_secapp_xujeemnt.sql ..."
db2 -l db2output.log -f cridx_secapp_xujeemnt.sql
echo "#	cridx_secdev_nameidx.sql ..."
db2 -l db2output.log -f cridx_secdev_nameidx.sql
echo "#	cridx_secdev_usridx.sql ..."
db2 -l db2output.log -f cridx_secdev_usridx.sql
echo "#	cridx_secform_xcluster.sql ..."
db2 -l db2output.log -f cridx_secform_xcluster.sql
echo "#	cridx_secform_xsecapp.sql ..."
db2 -l db2output.log -f cridx_secform_xsecapp.sql
echo "#	cridx_secform_xujeesvlt.sql ..."
db2 -l db2output.log -f cridx_secform_xujeesvlt.sql
echo "#	cridx_secgroup_xcluster.sql ..."
db2 -l db2output.log -f cridx_secgroup_xcluster.sql
echo "#	cridx_secgroup_xclustervis.sql ..."
db2 -l db2output.log -f cridx_secgroup_xclustervis.sql
echo "#	cridx_secgroup_xuname.sql ..."
db2 -l db2output.log -f cridx_secgroup_xuname.sql
echo "#	cridx_secgroupform_xcluster.sql ..."
db2 -l db2output.log -f cridx_secgroupform_xcluster.sql
echo "#	cridx_secgroupform_xgroup.sql ..."
db2 -l db2output.log -f cridx_secgroupform_xgroup.sql
echo "#	cridx_secgroupform_xapp.sql ..."
db2 -l db2output.log -f cridx_secgroupform_xapp.sql
echo "#	cridx_secgroupform_xform.sql ..."
db2 -l db2output.log -f cridx_secgroupform_xform.sql
echo "#	cridx_secgroupform_xuform.sql ..."
db2 -l db2output.log -f cridx_secgroupform_xuform.sql
echo "#	cridx_secinclude_xcluster.sql ..."
db2 -l db2output.log -f cridx_secinclude_xcluster.sql
echo "#	cridx_secinclude_xgroup.sql ..."
db2 -l db2output.log -f cridx_secinclude_xgroup.sql
echo "#	cridx_secinclude_xinc.sql ..."
db2 -l db2output.log -f cridx_secinclude_xinc.sql
echo "#	cridx_secinclude_xuinc.sql ..."
db2 -l db2output.log -f cridx_secinclude_xuinc.sql
echo "#	cridx_secmember_xcluster.sql ..."
db2 -l db2output.log -f cridx_secmember_xcluster.sql
echo "#	cridx_secmember_xgroup.sql ..."
db2 -l db2output.log -f cridx_secmember_xgroup.sql
echo "#	cridx_secmember_xuser.sql ..."
db2 -l db2output.log -f cridx_secmember_xuser.sql
echo "#	cridx_secmember_xuuser.sql ..."
db2 -l db2output.log -f cridx_secmember_xuuser.sql
echo "#	cridx_session_xsecuser.sql ..."
db2 -l db2output.log -f cridx_session_xsecuser.sql
echo "#	cridx_session_xsecdev.sql ..."
db2 -l db2output.log -f cridx_session_xsecdev.sql
echo "#	cridx_session_xstart.sql ..."
db2 -l db2output.log -f cridx_session_xstart.sql
echo "#	cridx_session_xfnsh.sql ..."
db2 -l db2output.log -f cridx_session_xfnsh.sql
echo "#	cridx_session_xproxy.sql ..."
db2 -l db2output.log -f cridx_session_xproxy.sql
echo "#	cridx_secuser_xulogin.sql ..."
db2 -l db2output.log -f cridx_secuser_xulogin.sql
echo "#	cridx_secuser_xemconf.sql ..."
db2 -l db2output.log -f cridx_secuser_xemconf.sql
echo "#	cridx_secuser_xpwdrst.sql ..."
db2 -l db2output.log -f cridx_secuser_xpwdrst.sql
echo "#	cridx_secuser_defdevidx.sql ..."
db2 -l db2output.log -f cridx_secuser_defdevidx.sql
echo "#	cridx_service_xcluster.sql ..."
db2 -l db2output.log -f cridx_service_xcluster.sql
echo "#	cridx_service_xhost.sql ..."
db2 -l db2output.log -f cridx_service_xhost.sql
echo "#	cridx_service_xtype.sql ..."
db2 -l db2output.log -f cridx_service_xtype.sql
echo "#	cridx_service_xutype.sql ..."
db2 -l db2output.log -f cridx_service_xutype.sql
echo "#	cridx_service_xuhpt.sql ..."
db2 -l db2output.log -f cridx_service_xuhpt.sql
echo "#	cridx_servicetype_xudsc.sql ..."
db2 -l db2output.log -f cridx_servicetype_xudsc.sql
echo "#	cridx_sprjdef_xtenant.sql ..."
db2 -l db2output.log -f cridx_sprjdef_xtenant.sql
echo "#	cridx_sprjdef_xtprj.sql ..."
db2 -l db2output.log -f cridx_sprjdef_xtprj.sql
echo "#	cridx_sprjdef_unameidx.sql ..."
db2 -l db2output.log -f cridx_sprjdef_unameidx.sql
echo "#	cridx_sysclus_xclus.sql ..."
db2 -l db2output.log -f cridx_sysclus_xclus.sql
echo "#	cridx_tsecgroup_xtenant.sql ..."
db2 -l db2output.log -f cridx_tsecgroup_xtenant.sql
echo "#	cridx_tsecgroup_xtenantvis.sql ..."
db2 -l db2output.log -f cridx_tsecgroup_xtenantvis.sql
echo "#	cridx_tsecgroup_xuname.sql ..."
db2 -l db2output.log -f cridx_tsecgroup_xuname.sql
echo "#	cridx_tsecinclude_xtenant.sql ..."
db2 -l db2output.log -f cridx_tsecinclude_xtenant.sql
echo "#	cridx_tsecinclude_xgroup.sql ..."
db2 -l db2output.log -f cridx_tsecinclude_xgroup.sql
echo "#	cridx_tsecinclude_xinc.sql ..."
db2 -l db2output.log -f cridx_tsecinclude_xinc.sql
echo "#	cridx_tsecinclude_xuinc.sql ..."
db2 -l db2output.log -f cridx_tsecinclude_xuinc.sql
echo "#	cridx_tsecmember_xtenant.sql ..."
db2 -l db2output.log -f cridx_tsecmember_xtenant.sql
echo "#	cridx_tsecmember_xgroup.sql ..."
db2 -l db2output.log -f cridx_tsecmember_xgroup.sql
echo "#	cridx_tsecmember_xuser.sql ..."
db2 -l db2output.log -f cridx_tsecmember_xuser.sql
echo "#	cridx_tsecmember_xuuser.sql ..."
db2 -l db2output.log -f cridx_tsecmember_xuuser.sql
echo "#	cridx_tenant_xcluster.sql ..."
db2 -l db2output.log -f cridx_tenant_xcluster.sql
echo "#	cridx_tenant_xuname.sql ..."
db2 -l db2output.log -f cridx_tenant_xuname.sql
echo "#	cridx_tlddef_xtenant.sql ..."
db2 -l db2output.log -f cridx_tlddef_xtenant.sql
echo "#	cridx_tlddef_unameidx.sql ..."
db2 -l db2output.log -f cridx_tlddef_unameidx.sql
echo "#	cridx_tdomdef_xtenant.sql ..."
db2 -l db2output.log -f cridx_tdomdef_xtenant.sql
echo "#	cridx_tdomdef_xtld.sql ..."
db2 -l db2output.log -f cridx_tdomdef_xtld.sql
echo "#	cridx_tdomdef_unameidx.sql ..."
db2 -l db2output.log -f cridx_tdomdef_unameidx.sql
echo "#	cridx_tprjdef_xtenant.sql ..."
db2 -l db2output.log -f cridx_tprjdef_xtenant.sql
echo "#	cridx_tprjdef_xsdom.sql ..."
db2 -l db2output.log -f cridx_tprjdef_xsdom.sql
echo "#	cridx_tprjdef_unameidx.sql ..."
db2 -l db2output.log -f cridx_tprjdef_unameidx.sql
echo "#	cridx_urlproto_xuname.sql ..."
db2 -l db2output.log -f cridx_urlproto_xuname.sql
echo "#	cridx_urlproto_xsecure.sql ..."
db2 -l db2output.log -f cridx_urlproto_xsecure.sql
