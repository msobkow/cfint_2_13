@echo off
REM
REM	@(#) dbcreate/cfint/mysql/crtbl_cfinet213.bat
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

REM
REM	Initialize locals
REM

SET mysqlpwd=""
SET mysqluser=""
SET logfilename=$GenFileBaseName$.log
SET TK_DUALCASE_IN_CASE_STATEMENTS=true

IF NOT "%1" == "" SET mysqluser=%1
IF NOT "%2" == "" SET mysqlpwd=%2
IF NOT "%3" == "" SET logfilename=%3

REM
REM	Validate parameters
REM

IF "%mysqluser%" == "" (
	ECHO ERROR: MySQL DBA login not specified as argument 1
	PAUSE
	EXIT
)

IF "%mysqlpwd%" == "" (
	ECHO ERROR: Password must be specified as argument 2 >&2
	PAUSE
	EXIT
)

echo crtbl_cfinet213_idg16.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_cfinet213_idg16.mysql >>%logfilename% 2>&1
echo crtbl_cfinet213_idg32.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_cfinet213_idg32.mysql >>%logfilename% 2>&1
echo crtbl_cfinet213_idg64.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_cfinet213_idg64.mysql >>%logfilename% 2>&1
echo crtbl_clus.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_clus.mysql >>%logfilename% 2>&1
echo crtbl_clus_idg32.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_clus_idg32.mysql >>%logfilename% 2>&1
echo crtbl_clus_idg64.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_clus_idg64.mysql >>%logfilename% 2>&1
echo crtbl_secapp.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secapp.mysql >>%logfilename% 2>&1
echo crtbl_secform.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secform.mysql >>%logfilename% 2>&1
echo crtbl_secgrp.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secgrp.mysql >>%logfilename% 2>&1
echo crtbl_secgrpfrm.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secgrpfrm.mysql >>%logfilename% 2>&1
echo crtbl_secsess.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secsess.mysql >>%logfilename% 2>&1
echo crtbl_secuser.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secuser.mysql >>%logfilename% 2>&1
echo crtbl_tenant.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tenant.mysql >>%logfilename% 2>&1
echo crtbl_tenant_idg32.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tenant_idg32.mysql >>%logfilename% 2>&1
echo crtbl_tenant_idg64.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tenant_idg64.mysql >>%logfilename% 2>&1
echo crtbl_hostnode.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_hostnode.mysql >>%logfilename% 2>&1
echo crtbl_iso_ccy.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_ccy.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntry.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntry.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntryccy.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntryccy.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntrylng.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntrylng.mysql >>%logfilename% 2>&1
echo crtbl_iso_lang.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_lang.mysql >>%logfilename% 2>&1
echo crtbl_isotz.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_isotz.mysql >>%logfilename% 2>&1
echo crtbl_licn.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_licn.mysql >>%logfilename% 2>&1
echo crtbl_mjvrdef.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_mjvrdef.mysql >>%logfilename% 2>&1
echo crtbl_mimetype.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_mimetype.mysql >>%logfilename% 2>&1
echo crtbl_mnvrdef.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_mnvrdef.mysql >>%logfilename% 2>&1
echo crtbl_secdev.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secdev.mysql >>%logfilename% 2>&1
echo crtbl_secinc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secinc.mysql >>%logfilename% 2>&1
echo crtbl_secmemb.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secmemb.mysql >>%logfilename% 2>&1
echo crtbl_hostsvc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_hostsvc.mysql >>%logfilename% 2>&1
echo crtbl_svctype.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_svctype.mysql >>%logfilename% 2>&1
echo crtbl_sprjdef.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_sprjdef.mysql >>%logfilename% 2>&1
echo crtbl_sysclus.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_sysclus.mysql >>%logfilename% 2>&1
echo crtbl_tsecgrp.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecgrp.mysql >>%logfilename% 2>&1
echo crtbl_tsecinc.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecinc.mysql >>%logfilename% 2>&1
echo crtbl_tsecmemb.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecmemb.mysql >>%logfilename% 2>&1
echo crtbl_tlddef.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tlddef.mysql >>%logfilename% 2>&1
echo crtbl_tdomdef.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tdomdef.mysql >>%logfilename% 2>&1
echo crtbl_tprjdef.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tprjdef.mysql >>%logfilename% 2>&1
echo crtbl_urlproto.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_urlproto.mysql >>%logfilename% 2>&1
echo crtbl_clus_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_clus_h.mysql >>%logfilename% 2>&1
echo crtbl_hostnode_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_hostnode_h.mysql >>%logfilename% 2>&1
echo crtbl_iso_ccy_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_ccy_h.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntry_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntry_h.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntryccy_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntryccy_h.mysql >>%logfilename% 2>&1
echo crtbl_iso_cntrylng_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_cntrylng_h.mysql >>%logfilename% 2>&1
echo crtbl_iso_lang_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_iso_lang_h.mysql >>%logfilename% 2>&1
echo crtbl_isotz_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_isotz_h.mysql >>%logfilename% 2>&1
echo crtbl_mjvrdef_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_mjvrdef_h.mysql >>%logfilename% 2>&1
echo crtbl_mimetype_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_mimetype_h.mysql >>%logfilename% 2>&1
echo crtbl_mnvrdef_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_mnvrdef_h.mysql >>%logfilename% 2>&1
echo crtbl_secapp_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secapp_h.mysql >>%logfilename% 2>&1
echo crtbl_secdev_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secdev_h.mysql >>%logfilename% 2>&1
echo crtbl_secform_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secform_h.mysql >>%logfilename% 2>&1
echo crtbl_secgrp_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secgrp_h.mysql >>%logfilename% 2>&1
echo crtbl_secgrpfrm_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secgrpfrm_h.mysql >>%logfilename% 2>&1
echo crtbl_secinc_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secinc_h.mysql >>%logfilename% 2>&1
echo crtbl_secmemb_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secmemb_h.mysql >>%logfilename% 2>&1
echo crtbl_secuser_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_secuser_h.mysql >>%logfilename% 2>&1
echo crtbl_hostsvc_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_hostsvc_h.mysql >>%logfilename% 2>&1
echo crtbl_svctype_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_svctype_h.mysql >>%logfilename% 2>&1
echo crtbl_sprjdef_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_sprjdef_h.mysql >>%logfilename% 2>&1
echo crtbl_tsecgrp_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecgrp_h.mysql >>%logfilename% 2>&1
echo crtbl_tsecinc_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecinc_h.mysql >>%logfilename% 2>&1
echo crtbl_tsecmemb_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tsecmemb_h.mysql >>%logfilename% 2>&1
echo crtbl_tenant_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tenant_h.mysql >>%logfilename% 2>&1
echo crtbl_tlddef_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tlddef_h.mysql >>%logfilename% 2>&1
echo crtbl_tdomdef_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tdomdef_h.mysql >>%logfilename% 2>&1
echo crtbl_tprjdef_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_tprjdef_h.mysql >>%logfilename% 2>&1
echo crtbl_urlproto_h.mysql >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% < crtbl_urlproto_h.mysql >>%logfilename% 2>&1

