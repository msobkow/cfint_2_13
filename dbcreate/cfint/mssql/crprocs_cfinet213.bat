@ECHO OFF
REM	@(#) dbcreate/cfint/mssql/crprocs_cfinet213.bat
REM
REM	org.msscf.msscf.CFInt
REM
REM	Copyright (c) 2020 Mark Stephen Sobkow
REM	
REM	This file is part of MSS Code Factory.
REM	
REM	Licensed under the Apache License, Version 2.0 (the "License");
REM	you may not use this file except in compliance with the License.
REM	You may obtain a copy of the License at
REM	
REM	    http://www.apache.org/licenses/LICENSE-2.0
REM	
REM	Unless required by applicable law or agreed to in writing, software
REM	distributed under the License is distributed on an "AS IS" BASIS,
REM	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
REM	See the License for the specific language governing permissions and
REM	limitations under the License.
REM	
REM	Donations to support MSS Code Factory can be made at
REM	https://www.paypal.com/paypalme2/MarkSobkow
REM
REM Manufactured by MSS Code Factory 2.12
REM

REM	Initialize locals
SET mssqlpwd=""
SET mssqlsrv=""
SET mssqluser=""
SET logfilename=$GenFileBaseName$.log

IF NOT "%1" == "" SET mssqlsrv=%1
IF NOT "%2" == "" SET mssqluser=%2
IF NOT "%3" == "" SET mssqlpwd=%3
IF NOT "%4" == "" SET logfilename=%4

IF "%mssqluser%" == "" (
	ECHO "ERROR: User must be specified as second argument"
	PAUSE
	EXIT
)

IF "%mssqlpwd%" == "" (
	ECHO "ERROR: Password must be specified as third argument"
	PAUSE
	EXIT
)

IF "%mssqlsrv%" == "" (
	ECHO "ERROR: Server must be specified as first argument"
	PAUSE
	EXIT
)

SET cmddb=sqlcmd -S %mssqlsrv% -U %mssqluser% -P %mssqlpwd% -e

%cmddb% <crsp_is_system_user.tsql >>%logfilename%
%cmddb% <crsp_is_cluster_user.tsql >>%logfilename%
%cmddb% <crsp_is_tenant_user.tsql >>%logfilename%
%cmddb% <crsp_next_isoccyidgen.tsql >>%logfilename%
%cmddb% <crsp_next_isoctryidgen.tsql >>%logfilename%
%cmddb% <crsp_next_isolangidgen.tsql >>%logfilename%
%cmddb% <crsp_next_isotzoneidgen.tsql >>%logfilename%
%cmddb% <crsp_next_servicetypeidgen.tsql >>%logfilename%
%cmddb% <crsp_next_mimetypeidgen.tsql >>%logfilename%
%cmddb% <crsp_next_urlprotocolidgen.tsql >>%logfilename%
%cmddb% <crsp_next_clusteridgen.tsql >>%logfilename%
%cmddb% <crsp_next_tenantidgen.tsql >>%logfilename%

%cmddb% <crsp_selnext_isoccyidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_isoctryidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_isolangidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_isotzoneidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_servicetypeidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_mimetypeidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_urlprotocolidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_clusteridgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_tenantidgen.tsql >>%logfilename%
%cmddb% <crsp_next_clus_secappidgen.tsql >>%logfilename%
%cmddb% <crsp_next_clus_secformidgen.tsql >>%logfilename%
%cmddb% <crsp_next_clus_secgroupidgen.tsql >>%logfilename%
%cmddb% <crsp_next_clus_hostnodeidgen.tsql >>%logfilename%
%cmddb% <crsp_next_clus_secgroupformidgen.tsql >>%logfilename%
%cmddb% <crsp_next_clus_secgrpincidgen.tsql >>%logfilename%
%cmddb% <crsp_next_clus_secgrpmembidgen.tsql >>%logfilename%
%cmddb% <crsp_next_clus_serviceidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_clus_secappidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_clus_secformidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_clus_secgroupidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_clus_hostnodeidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_clus_secgroupformidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_clus_secgrpincidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_clus_secgrpmembidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_clus_serviceidgen.tsql >>%logfilename%




























%cmddb% <crsp_next_tenant_tsecgroupidgen.tsql >>%logfilename%
%cmddb% <crsp_next_tenant_tsecgrpincidgen.tsql >>%logfilename%
%cmddb% <crsp_next_tenant_tsecgrpmembidgen.tsql >>%logfilename%
%cmddb% <crsp_next_tenant_licenseidgen.tsql >>%logfilename%
%cmddb% <crsp_next_tenant_majorversionidgen.tsql >>%logfilename%
%cmddb% <crsp_next_tenant_minorversionidgen.tsql >>%logfilename%
%cmddb% <crsp_next_tenant_subprojectidgen.tsql >>%logfilename%
%cmddb% <crsp_next_tenant_tldidgen.tsql >>%logfilename%
%cmddb% <crsp_next_tenant_topdomainidgen.tsql >>%logfilename%
%cmddb% <crsp_next_tenant_topprojectidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_tenant_tsecgroupidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_tenant_tsecgrpincidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_tenant_tsecgrpmembidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_tenant_licenseidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_tenant_majorversionidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_tenant_minorversionidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_tenant_subprojectidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_tenant_tldidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_tenant_topdomainidgen.tsql >>%logfilename%
%cmddb% <crsp_selnext_tenant_topprojectidgen.tsql >>%logfilename%






%cmddb% <crsp_bootstrap.tsql >>%logfilename%


%cmddb% <crsp_create_clus.tsql >>%logfilename%
%cmddb% <crsp_lock_clus.tsql >>%logfilename%
%cmddb% <crsp_read_clus.tsql >>%logfilename%
%cmddb% <crsp_read_clus_all.tsql >>%logfilename%
%cmddb% <crsp_read_clus_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_clus_by_udomnameidx.tsql >>%logfilename%
%cmddb% <crsp_read_clus_by_udescridx.tsql >>%logfilename%
%cmddb% <crsp_update_clus.tsql >>%logfilename%
%cmddb% <crsp_delete_clus.tsql >>%logfilename%

%cmddb% <crsp_create_hostnode.tsql >>%logfilename%
%cmddb% <crsp_lock_hostnode.tsql >>%logfilename%
%cmddb% <crsp_read_hostnode.tsql >>%logfilename%
%cmddb% <crsp_read_hostnode_all.tsql >>%logfilename%
%cmddb% <crsp_read_hostnode_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_hostnode_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_read_hostnode_by_udescridx.tsql >>%logfilename%
%cmddb% <crsp_read_hostnode_by_hostnameidx.tsql >>%logfilename%
%cmddb% <crsp_update_hostnode.tsql >>%logfilename%
%cmddb% <crsp_delete_hostnode.tsql >>%logfilename%

%cmddb% <crsp_create_iso_ccy.tsql >>%logfilename%
%cmddb% <crsp_lock_iso_ccy.tsql >>%logfilename%
%cmddb% <crsp_read_iso_ccy.tsql >>%logfilename%
%cmddb% <crsp_read_iso_ccy_all.tsql >>%logfilename%
%cmddb% <crsp_read_iso_ccy_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_iso_ccy_by_ccycdidx.tsql >>%logfilename%
%cmddb% <crsp_read_iso_ccy_by_ccynmidx.tsql >>%logfilename%
%cmddb% <crsp_update_iso_ccy.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_ccy.tsql >>%logfilename%

%cmddb% <crsp_create_iso_cntry.tsql >>%logfilename%
%cmddb% <crsp_lock_iso_cntry.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntry.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntry_all.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntry_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntry_by_isocodeidx.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntry_by_nameidx.tsql >>%logfilename%
%cmddb% <crsp_update_iso_cntry.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_cntry.tsql >>%logfilename%

%cmddb% <crsp_create_iso_cntryccy.tsql >>%logfilename%
%cmddb% <crsp_lock_iso_cntryccy.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntryccy.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntryccy_all.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntryccy_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntryccy_by_ctryidx.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntryccy_by_ccyidx.tsql >>%logfilename%
%cmddb% <crsp_update_iso_cntryccy.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_cntryccy.tsql >>%logfilename%

%cmddb% <crsp_create_iso_cntrylng.tsql >>%logfilename%
%cmddb% <crsp_lock_iso_cntrylng.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntrylng.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntrylng_all.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntrylng_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntrylng_by_ctryidx.tsql >>%logfilename%
%cmddb% <crsp_read_iso_cntrylng_by_langidx.tsql >>%logfilename%
%cmddb% <crsp_update_iso_cntrylng.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_cntrylng.tsql >>%logfilename%

%cmddb% <crsp_create_iso_lang.tsql >>%logfilename%
%cmddb% <crsp_lock_iso_lang.tsql >>%logfilename%
%cmddb% <crsp_read_iso_lang.tsql >>%logfilename%
%cmddb% <crsp_read_iso_lang_all.tsql >>%logfilename%
%cmddb% <crsp_read_iso_lang_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_iso_lang_by_code3idx.tsql >>%logfilename%
%cmddb% <crsp_read_iso_lang_by_code2idx.tsql >>%logfilename%
%cmddb% <crsp_update_iso_lang.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_lang.tsql >>%logfilename%

%cmddb% <crsp_create_isotz.tsql >>%logfilename%
%cmddb% <crsp_lock_isotz.tsql >>%logfilename%
%cmddb% <crsp_read_isotz.tsql >>%logfilename%
%cmddb% <crsp_read_isotz_all.tsql >>%logfilename%
%cmddb% <crsp_read_isotz_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_isotz_by_offsetidx.tsql >>%logfilename%
%cmddb% <crsp_read_isotz_by_utznameidx.tsql >>%logfilename%
%cmddb% <crsp_read_isotz_by_iso8601idx.tsql >>%logfilename%
%cmddb% <crsp_update_isotz.tsql >>%logfilename%
%cmddb% <crsp_delete_isotz.tsql >>%logfilename%

%cmddb% <crsp_lock_licn.tsql >>%logfilename%
%cmddb% <crsp_read_licn.tsql >>%logfilename%
%cmddb% <crsp_read_licn_all.tsql >>%logfilename%
%cmddb% <crsp_read_licn_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_licn_by_licntenantidx.tsql >>%logfilename%
%cmddb% <crsp_read_licn_by_domainidx.tsql >>%logfilename%
%cmddb% <crsp_read_licn_by_unameidx.tsql >>%logfilename%
%cmddb% <crsp_delete_licn.tsql >>%logfilename%

%cmddb% <crsp_create_mjvrdef.tsql >>%logfilename%
%cmddb% <crsp_lock_mjvrdef.tsql >>%logfilename%
%cmddb% <crsp_read_mjvrdef.tsql >>%logfilename%
%cmddb% <crsp_read_mjvrdef_all.tsql >>%logfilename%
%cmddb% <crsp_read_mjvrdef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_mjvrdef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_read_mjvrdef_by_subprojectidx.tsql >>%logfilename%
%cmddb% <crsp_read_mjvrdef_by_nameidx.tsql >>%logfilename%
%cmddb% <crsp_update_mjvrdef.tsql >>%logfilename%
%cmddb% <crsp_delete_mjvrdef.tsql >>%logfilename%

%cmddb% <crsp_create_mimetype.tsql >>%logfilename%
%cmddb% <crsp_lock_mimetype.tsql >>%logfilename%
%cmddb% <crsp_read_mimetype.tsql >>%logfilename%
%cmddb% <crsp_read_mimetype_all.tsql >>%logfilename%
%cmddb% <crsp_read_mimetype_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_mimetype_by_unameidx.tsql >>%logfilename%
%cmddb% <crsp_update_mimetype.tsql >>%logfilename%
%cmddb% <crsp_delete_mimetype.tsql >>%logfilename%

%cmddb% <crsp_create_mnvrdef.tsql >>%logfilename%
%cmddb% <crsp_lock_mnvrdef.tsql >>%logfilename%
%cmddb% <crsp_read_mnvrdef.tsql >>%logfilename%
%cmddb% <crsp_read_mnvrdef_all.tsql >>%logfilename%
%cmddb% <crsp_read_mnvrdef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_mnvrdef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_read_mnvrdef_by_majorveridx.tsql >>%logfilename%
%cmddb% <crsp_read_mnvrdef_by_nameidx.tsql >>%logfilename%
%cmddb% <crsp_update_mnvrdef.tsql >>%logfilename%
%cmddb% <crsp_delete_mnvrdef.tsql >>%logfilename%

%cmddb% <crsp_create_secapp.tsql >>%logfilename%
%cmddb% <crsp_lock_secapp.tsql >>%logfilename%
%cmddb% <crsp_read_secapp.tsql >>%logfilename%
%cmddb% <crsp_read_secapp_all.tsql >>%logfilename%
%cmddb% <crsp_read_secapp_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_secapp_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_read_secapp_by_ujeemountidx.tsql >>%logfilename%
%cmddb% <crsp_update_secapp.tsql >>%logfilename%
%cmddb% <crsp_delete_secapp.tsql >>%logfilename%

%cmddb% <crsp_lock_secdev.tsql >>%logfilename%
%cmddb% <crsp_read_secdev.tsql >>%logfilename%
%cmddb% <crsp_read_secdev_all.tsql >>%logfilename%
%cmddb% <crsp_read_secdev_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_secdev_by_nameidx.tsql >>%logfilename%
%cmddb% <crsp_read_secdev_by_useridx.tsql >>%logfilename%
%cmddb% <crsp_delete_secdev.tsql >>%logfilename%

%cmddb% <crsp_create_secform.tsql >>%logfilename%
%cmddb% <crsp_lock_secform.tsql >>%logfilename%
%cmddb% <crsp_read_secform.tsql >>%logfilename%
%cmddb% <crsp_read_secform_all.tsql >>%logfilename%
%cmddb% <crsp_read_secform_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_secform_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_read_secform_by_secappidx.tsql >>%logfilename%
%cmddb% <crsp_read_secform_by_ujeeservletidx.tsql >>%logfilename%
%cmddb% <crsp_update_secform.tsql >>%logfilename%
%cmddb% <crsp_delete_secform.tsql >>%logfilename%

%cmddb% <crsp_create_secgrp.tsql >>%logfilename%
%cmddb% <crsp_lock_secgrp.tsql >>%logfilename%
%cmddb% <crsp_read_secgrp.tsql >>%logfilename%
%cmddb% <crsp_read_secgrp_all.tsql >>%logfilename%
%cmddb% <crsp_read_secgrp_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_secgrp_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_read_secgrp_by_clustervisidx.tsql >>%logfilename%
%cmddb% <crsp_read_secgrp_by_unameidx.tsql >>%logfilename%
%cmddb% <crsp_update_secgrp.tsql >>%logfilename%
%cmddb% <crsp_delete_secgrp.tsql >>%logfilename%

%cmddb% <crsp_create_secgrpfrm.tsql >>%logfilename%
%cmddb% <crsp_lock_secgrpfrm.tsql >>%logfilename%
%cmddb% <crsp_read_secgrpfrm.tsql >>%logfilename%
%cmddb% <crsp_read_secgrpfrm_all.tsql >>%logfilename%
%cmddb% <crsp_read_secgrpfrm_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_secgrpfrm_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_read_secgrpfrm_by_groupidx.tsql >>%logfilename%
%cmddb% <crsp_read_secgrpfrm_by_appidx.tsql >>%logfilename%
%cmddb% <crsp_read_secgrpfrm_by_formidx.tsql >>%logfilename%
%cmddb% <crsp_read_secgrpfrm_by_uformidx.tsql >>%logfilename%
%cmddb% <crsp_update_secgrpfrm.tsql >>%logfilename%
%cmddb% <crsp_delete_secgrpfrm.tsql >>%logfilename%

%cmddb% <crsp_create_secinc.tsql >>%logfilename%
%cmddb% <crsp_lock_secinc.tsql >>%logfilename%
%cmddb% <crsp_read_secinc.tsql >>%logfilename%
%cmddb% <crsp_read_secinc_all.tsql >>%logfilename%
%cmddb% <crsp_read_secinc_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_secinc_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_read_secinc_by_groupidx.tsql >>%logfilename%
%cmddb% <crsp_read_secinc_by_includeidx.tsql >>%logfilename%
%cmddb% <crsp_read_secinc_by_uincludeidx.tsql >>%logfilename%
%cmddb% <crsp_update_secinc.tsql >>%logfilename%
%cmddb% <crsp_delete_secinc.tsql >>%logfilename%

%cmddb% <crsp_create_secmemb.tsql >>%logfilename%
%cmddb% <crsp_lock_secmemb.tsql >>%logfilename%
%cmddb% <crsp_read_secmemb.tsql >>%logfilename%
%cmddb% <crsp_read_secmemb_all.tsql >>%logfilename%
%cmddb% <crsp_read_secmemb_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_secmemb_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_read_secmemb_by_groupidx.tsql >>%logfilename%
%cmddb% <crsp_read_secmemb_by_useridx.tsql >>%logfilename%
%cmddb% <crsp_read_secmemb_by_uuseridx.tsql >>%logfilename%
%cmddb% <crsp_update_secmemb.tsql >>%logfilename%
%cmddb% <crsp_delete_secmemb.tsql >>%logfilename%

%cmddb% <crsp_create_secsess.tsql >>%logfilename%
%cmddb% <crsp_lock_secsess.tsql >>%logfilename%
%cmddb% <crsp_read_secsess.tsql >>%logfilename%
%cmddb% <crsp_read_secsess_all.tsql >>%logfilename%
%cmddb% <crsp_read_secsess_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_secsess_by_secuseridx.tsql >>%logfilename%
%cmddb% <crsp_read_secsess_by_secdevidx.tsql >>%logfilename%
%cmddb% <crsp_read_secsess_by_startidx.tsql >>%logfilename%
%cmddb% <crsp_read_secsess_by_finishidx.tsql >>%logfilename%
%cmddb% <crsp_read_secsess_by_secproxyidx.tsql >>%logfilename%
%cmddb% <crsp_update_secsess.tsql >>%logfilename%
%cmddb% <crsp_delete_secsess.tsql >>%logfilename%

%cmddb% <crsp_create_secuser.tsql >>%logfilename%
%cmddb% <crsp_lock_secuser.tsql >>%logfilename%
%cmddb% <crsp_read_secuser.tsql >>%logfilename%
%cmddb% <crsp_read_secuser_all.tsql >>%logfilename%
%cmddb% <crsp_read_secuser_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_secuser_by_uloginidx.tsql >>%logfilename%
%cmddb% <crsp_read_secuser_by_emconfidx.tsql >>%logfilename%
%cmddb% <crsp_read_secuser_by_pwdresetidx.tsql >>%logfilename%
%cmddb% <crsp_read_secuser_by_defdevidx.tsql >>%logfilename%
%cmddb% <crsp_update_secuser.tsql >>%logfilename%
%cmddb% <crsp_delete_secuser.tsql >>%logfilename%

%cmddb% <crsp_create_hostsvc.tsql >>%logfilename%
%cmddb% <crsp_lock_hostsvc.tsql >>%logfilename%
%cmddb% <crsp_read_hostsvc.tsql >>%logfilename%
%cmddb% <crsp_read_hostsvc_all.tsql >>%logfilename%
%cmddb% <crsp_read_hostsvc_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_hostsvc_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_read_hostsvc_by_hostidx.tsql >>%logfilename%
%cmddb% <crsp_read_hostsvc_by_typeidx.tsql >>%logfilename%
%cmddb% <crsp_read_hostsvc_by_utypeidx.tsql >>%logfilename%
%cmddb% <crsp_read_hostsvc_by_uhostportidx.tsql >>%logfilename%
%cmddb% <crsp_update_hostsvc.tsql >>%logfilename%
%cmddb% <crsp_delete_hostsvc.tsql >>%logfilename%

%cmddb% <crsp_create_svctype.tsql >>%logfilename%
%cmddb% <crsp_lock_svctype.tsql >>%logfilename%
%cmddb% <crsp_read_svctype.tsql >>%logfilename%
%cmddb% <crsp_read_svctype_all.tsql >>%logfilename%
%cmddb% <crsp_read_svctype_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_svctype_by_udescridx.tsql >>%logfilename%
%cmddb% <crsp_update_svctype.tsql >>%logfilename%
%cmddb% <crsp_delete_svctype.tsql >>%logfilename%

%cmddb% <crsp_create_sprjdef.tsql >>%logfilename%
%cmddb% <crsp_lock_sprjdef.tsql >>%logfilename%
%cmddb% <crsp_read_sprjdef.tsql >>%logfilename%
%cmddb% <crsp_read_sprjdef_all.tsql >>%logfilename%
%cmddb% <crsp_read_sprjdef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_sprjdef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_read_sprjdef_by_topprojectidx.tsql >>%logfilename%
%cmddb% <crsp_read_sprjdef_by_nameidx.tsql >>%logfilename%
%cmddb% <crsp_update_sprjdef.tsql >>%logfilename%
%cmddb% <crsp_delete_sprjdef.tsql >>%logfilename%

%cmddb% <crsp_create_sysclus.tsql >>%logfilename%
%cmddb% <crsp_lock_sysclus.tsql >>%logfilename%
%cmddb% <crsp_read_sysclus.tsql >>%logfilename%
%cmddb% <crsp_read_sysclus_all.tsql >>%logfilename%
%cmddb% <crsp_read_sysclus_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_sysclus_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_update_sysclus.tsql >>%logfilename%
%cmddb% <crsp_delete_sysclus.tsql >>%logfilename%

%cmddb% <crsp_create_tsecgrp.tsql >>%logfilename%
%cmddb% <crsp_lock_tsecgrp.tsql >>%logfilename%
%cmddb% <crsp_read_tsecgrp.tsql >>%logfilename%
%cmddb% <crsp_read_tsecgrp_all.tsql >>%logfilename%
%cmddb% <crsp_read_tsecgrp_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_tsecgrp_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_read_tsecgrp_by_tenantvisidx.tsql >>%logfilename%
%cmddb% <crsp_read_tsecgrp_by_unameidx.tsql >>%logfilename%
%cmddb% <crsp_update_tsecgrp.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecgrp.tsql >>%logfilename%

%cmddb% <crsp_create_tsecinc.tsql >>%logfilename%
%cmddb% <crsp_lock_tsecinc.tsql >>%logfilename%
%cmddb% <crsp_read_tsecinc.tsql >>%logfilename%
%cmddb% <crsp_read_tsecinc_all.tsql >>%logfilename%
%cmddb% <crsp_read_tsecinc_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_tsecinc_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_read_tsecinc_by_groupidx.tsql >>%logfilename%
%cmddb% <crsp_read_tsecinc_by_includeidx.tsql >>%logfilename%
%cmddb% <crsp_read_tsecinc_by_uincludeidx.tsql >>%logfilename%
%cmddb% <crsp_update_tsecinc.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecinc.tsql >>%logfilename%

%cmddb% <crsp_create_tsecmemb.tsql >>%logfilename%
%cmddb% <crsp_lock_tsecmemb.tsql >>%logfilename%
%cmddb% <crsp_read_tsecmemb.tsql >>%logfilename%
%cmddb% <crsp_read_tsecmemb_all.tsql >>%logfilename%
%cmddb% <crsp_read_tsecmemb_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_tsecmemb_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_read_tsecmemb_by_groupidx.tsql >>%logfilename%
%cmddb% <crsp_read_tsecmemb_by_useridx.tsql >>%logfilename%
%cmddb% <crsp_read_tsecmemb_by_uuseridx.tsql >>%logfilename%
%cmddb% <crsp_update_tsecmemb.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecmemb.tsql >>%logfilename%

%cmddb% <crsp_create_tenant.tsql >>%logfilename%
%cmddb% <crsp_lock_tenant.tsql >>%logfilename%
%cmddb% <crsp_read_tenant.tsql >>%logfilename%
%cmddb% <crsp_read_tenant_all.tsql >>%logfilename%
%cmddb% <crsp_read_tenant_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_tenant_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_read_tenant_by_unameidx.tsql >>%logfilename%
%cmddb% <crsp_update_tenant.tsql >>%logfilename%
%cmddb% <crsp_delete_tenant.tsql >>%logfilename%

%cmddb% <crsp_create_tlddef.tsql >>%logfilename%
%cmddb% <crsp_lock_tlddef.tsql >>%logfilename%
%cmddb% <crsp_read_tlddef.tsql >>%logfilename%
%cmddb% <crsp_read_tlddef_all.tsql >>%logfilename%
%cmddb% <crsp_read_tlddef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_tlddef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_read_tlddef_by_nameidx.tsql >>%logfilename%
%cmddb% <crsp_update_tlddef.tsql >>%logfilename%
%cmddb% <crsp_delete_tlddef.tsql >>%logfilename%

%cmddb% <crsp_create_tdomdef.tsql >>%logfilename%
%cmddb% <crsp_lock_tdomdef.tsql >>%logfilename%
%cmddb% <crsp_read_tdomdef.tsql >>%logfilename%
%cmddb% <crsp_read_tdomdef_all.tsql >>%logfilename%
%cmddb% <crsp_read_tdomdef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_tdomdef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_read_tdomdef_by_tldidx.tsql >>%logfilename%
%cmddb% <crsp_read_tdomdef_by_nameidx.tsql >>%logfilename%
%cmddb% <crsp_update_tdomdef.tsql >>%logfilename%
%cmddb% <crsp_delete_tdomdef.tsql >>%logfilename%

%cmddb% <crsp_create_tprjdef.tsql >>%logfilename%
%cmddb% <crsp_lock_tprjdef.tsql >>%logfilename%
%cmddb% <crsp_read_tprjdef.tsql >>%logfilename%
%cmddb% <crsp_read_tprjdef_all.tsql >>%logfilename%
%cmddb% <crsp_read_tprjdef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_tprjdef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_read_tprjdef_by_topdomainidx.tsql >>%logfilename%
%cmddb% <crsp_read_tprjdef_by_nameidx.tsql >>%logfilename%
%cmddb% <crsp_update_tprjdef.tsql >>%logfilename%
%cmddb% <crsp_delete_tprjdef.tsql >>%logfilename%

%cmddb% <crsp_create_urlproto.tsql >>%logfilename%
%cmddb% <crsp_lock_urlproto.tsql >>%logfilename%
%cmddb% <crsp_read_urlproto.tsql >>%logfilename%
%cmddb% <crsp_read_urlproto_all.tsql >>%logfilename%
%cmddb% <crsp_read_urlproto_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_read_urlproto_by_unameidx.tsql >>%logfilename%
%cmddb% <crsp_read_urlproto_by_issecureidx.tsql >>%logfilename%
%cmddb% <crsp_update_urlproto.tsql >>%logfilename%
%cmddb% <crsp_delete_urlproto.tsql >>%logfilename%


%cmddb% <crsp_delete_clus_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_clus_by_udomnameidx.tsql >>%logfilename%
%cmddb% <crsp_delete_clus_by_udescridx.tsql >>%logfilename%

%cmddb% <crsp_delete_hostnode_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_hostnode_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_delete_hostnode_by_udescridx.tsql >>%logfilename%
%cmddb% <crsp_delete_hostnode_by_hostnameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_iso_ccy_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_ccy_by_ccycdidx.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_ccy_by_ccynmidx.tsql >>%logfilename%

%cmddb% <crsp_delete_iso_cntry_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_cntry_by_isocodeidx.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_cntry_by_nameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_iso_cntryccy_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_cntryccy_by_ctryidx.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_cntryccy_by_ccyidx.tsql >>%logfilename%

%cmddb% <crsp_delete_iso_cntrylng_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_cntrylng_by_ctryidx.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_cntrylng_by_langidx.tsql >>%logfilename%

%cmddb% <crsp_delete_iso_lang_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_lang_by_code3idx.tsql >>%logfilename%
%cmddb% <crsp_delete_iso_lang_by_code2idx.tsql >>%logfilename%

%cmddb% <crsp_delete_isotz_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_isotz_by_offsetidx.tsql >>%logfilename%
%cmddb% <crsp_delete_isotz_by_utznameidx.tsql >>%logfilename%
%cmddb% <crsp_delete_isotz_by_iso8601idx.tsql >>%logfilename%

%cmddb% <crsp_delete_licn_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_licn_by_licntenantidx.tsql >>%logfilename%
%cmddb% <crsp_delete_licn_by_domainidx.tsql >>%logfilename%
%cmddb% <crsp_delete_licn_by_unameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_mjvrdef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_mjvrdef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_delete_mjvrdef_by_subprojectidx.tsql >>%logfilename%
%cmddb% <crsp_delete_mjvrdef_by_nameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_mimetype_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_mimetype_by_unameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_mnvrdef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_mnvrdef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_delete_mnvrdef_by_majorveridx.tsql >>%logfilename%
%cmddb% <crsp_delete_mnvrdef_by_nameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_secapp_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_secapp_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_delete_secapp_by_ujeemountidx.tsql >>%logfilename%

%cmddb% <crsp_delete_secdev_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_secdev_by_nameidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secdev_by_useridx.tsql >>%logfilename%

%cmddb% <crsp_delete_secform_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_secform_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_delete_secform_by_secappidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secform_by_ujeeservletidx.tsql >>%logfilename%

%cmddb% <crsp_delete_secgrp_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_secgrp_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_delete_secgrp_by_clustervisidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secgrp_by_unameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_secgrpfrm_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_secgrpfrm_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_delete_secgrpfrm_by_groupidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secgrpfrm_by_appidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secgrpfrm_by_formidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secgrpfrm_by_uformidx.tsql >>%logfilename%

%cmddb% <crsp_delete_secinc_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_secinc_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_delete_secinc_by_groupidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secinc_by_includeidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secinc_by_uincludeidx.tsql >>%logfilename%

%cmddb% <crsp_delete_secmemb_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_secmemb_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_delete_secmemb_by_groupidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secmemb_by_useridx.tsql >>%logfilename%
%cmddb% <crsp_delete_secmemb_by_uuseridx.tsql >>%logfilename%

%cmddb% <crsp_delete_secsess_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_secsess_by_secuseridx.tsql >>%logfilename%
%cmddb% <crsp_delete_secsess_by_secdevidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secsess_by_startidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secsess_by_finishidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secsess_by_secproxyidx.tsql >>%logfilename%

%cmddb% <crsp_delete_secuser_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_secuser_by_uloginidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secuser_by_emconfidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secuser_by_pwdresetidx.tsql >>%logfilename%
%cmddb% <crsp_delete_secuser_by_defdevidx.tsql >>%logfilename%

%cmddb% <crsp_delete_hostsvc_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_hostsvc_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_delete_hostsvc_by_hostidx.tsql >>%logfilename%
%cmddb% <crsp_delete_hostsvc_by_typeidx.tsql >>%logfilename%
%cmddb% <crsp_delete_hostsvc_by_utypeidx.tsql >>%logfilename%
%cmddb% <crsp_delete_hostsvc_by_uhostportidx.tsql >>%logfilename%

%cmddb% <crsp_delete_svctype_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_svctype_by_udescridx.tsql >>%logfilename%

%cmddb% <crsp_delete_sprjdef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_sprjdef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_delete_sprjdef_by_topprojectidx.tsql >>%logfilename%
%cmddb% <crsp_delete_sprjdef_by_nameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_sysclus_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_sysclus_by_clusteridx.tsql >>%logfilename%

%cmddb% <crsp_delete_tsecgrp_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecgrp_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecgrp_by_tenantvisidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecgrp_by_unameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_tsecinc_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecinc_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecinc_by_groupidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecinc_by_includeidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecinc_by_uincludeidx.tsql >>%logfilename%

%cmddb% <crsp_delete_tsecmemb_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecmemb_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecmemb_by_groupidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecmemb_by_useridx.tsql >>%logfilename%
%cmddb% <crsp_delete_tsecmemb_by_uuseridx.tsql >>%logfilename%

%cmddb% <crsp_delete_tenant_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_tenant_by_clusteridx.tsql >>%logfilename%
%cmddb% <crsp_delete_tenant_by_unameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_tlddef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_tlddef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tlddef_by_nameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_tdomdef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_tdomdef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tdomdef_by_tldidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tdomdef_by_nameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_tprjdef_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_tprjdef_by_tenantidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tprjdef_by_topdomainidx.tsql >>%logfilename%
%cmddb% <crsp_delete_tprjdef_by_nameidx.tsql >>%logfilename%

%cmddb% <crsp_delete_urlproto_by_ididx.tsql >>%logfilename%
%cmddb% <crsp_delete_urlproto_by_unameidx.tsql >>%logfilename%
%cmddb% <crsp_delete_urlproto_by_issecureidx.tsql >>%logfilename%


