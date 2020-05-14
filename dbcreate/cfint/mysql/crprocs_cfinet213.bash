#!/bin/bash
#
#	@(#) dbcreate/cfint/mysql/crprocs_cfinet213.bash
#
#	com.github.msobkow.CFInt
#
#	Copyright (c) 2020 Mark Stephen Sobkow
#	
#	This file is part of MSS Code Factory.
#	
#	Licensed under the Apache License, Version 2.0 (the "License");
#	you may not use this file except in compliance with the License.
#	You may obtain a copy of the License at
#	
#	    http://www.apache.org/licenses/LICENSE-2.0
#	
#	Unless required by applicable law or agreed to in writing, software
#	distributed under the License is distributed on an "AS IS" BASIS,
#	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#	See the License for the specific language governing permissions and
#	limitations under the License.
#	
#	Donations to support MSS Code Factory can be made at
#	https://www.paypal.com/paypalme2/MarkSobkow
#
#	Manufactured by MSS Code Factory 2.12
#

#
#	Initialize locals
#
mysqlpwd=""
mysqluser=""
logfilename=""
parmerrors=""
TK_DUALCASE_IN_CASE_STATEMENTS=true

#
#	Parse the command line options
#
while [ -n "$1" ]
do
	case "$1" in

		-L)
			shift
			logfilename=$1
			shift
			;;

		-P)
			shift
			mysqlpwd=$1
			shift
			;;

		-U)
			shift
			mysqluser=$1
			shift
			;;

		*)
			echo >&2 "ERROR: Option $1 not recognized."
			shift
			parmerrors="Y"
			;;
	esac
done

#
#	Validate parameters
#

if [ "$mysqluser" = "" ]; then
	echo >&2 "ERROR: MySQL user must be specified with '-U username'"
	parmerrors="Y"
fi

if [ "$mysqlpwd" = "" ]; then
	echo >&2 "ERROR: Password must be specified with '-P password'"
	parmerrors="Y"
fi

if [ "$parmerrors" != "" ]; then
	echo >&2 "ABORT: Cannot continue"
	exit 1
fi

if [ "$logfilename" = "" ]; then
	logfilename=`date +'$GenFileBaseName$-%Y%m%d_%Hh%M.log'`
	echo "" >$logfilename
fi

echo "crsp_next_isoccyidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_isoccyidgen.mysql >>$logfilename 2>&1
echo "crsp_next_isoctryidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_isoctryidgen.mysql >>$logfilename 2>&1
echo "crsp_next_isolangidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_isolangidgen.mysql >>$logfilename 2>&1
echo "crsp_next_isotzoneidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_isotzoneidgen.mysql >>$logfilename 2>&1
echo "crsp_next_servicetypeidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_servicetypeidgen.mysql >>$logfilename 2>&1
echo "crsp_next_mimetypeidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_mimetypeidgen.mysql >>$logfilename 2>&1
echo "crsp_next_urlprotocolidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_urlprotocolidgen.mysql >>$logfilename 2>&1
echo "crsp_next_clusteridgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_clusteridgen.mysql >>$logfilename 2>&1
echo "crsp_next_tenantidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_tenantidgen.mysql >>$logfilename 2>&1
echo "crsp_next_secappidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_secappidgen.mysql >>$logfilename 2>&1
echo "crsp_next_secformidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_secformidgen.mysql >>$logfilename 2>&1
echo "crsp_next_secgroupidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_secgroupidgen.mysql >>$logfilename 2>&1
echo "crsp_next_hostnodeidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_hostnodeidgen.mysql >>$logfilename 2>&1
echo "crsp_next_secgroupformidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_secgroupformidgen.mysql >>$logfilename 2>&1
echo "crsp_next_secgrpincidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_secgrpincidgen.mysql >>$logfilename 2>&1
echo "crsp_next_secgrpmembidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_secgrpmembidgen.mysql >>$logfilename 2>&1
echo "crsp_next_serviceidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_serviceidgen.mysql >>$logfilename 2>&1
echo "crsp_next_tsecgroupidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_tsecgroupidgen.mysql >>$logfilename 2>&1
echo "crsp_next_tsecgrpincidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_tsecgrpincidgen.mysql >>$logfilename 2>&1
echo "crsp_next_tsecgrpmembidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_tsecgrpmembidgen.mysql >>$logfilename 2>&1
echo "crsp_next_licenseidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_licenseidgen.mysql >>$logfilename 2>&1
echo "crsp_next_majorversionidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_majorversionidgen.mysql >>$logfilename 2>&1
echo "crsp_next_minorversionidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_minorversionidgen.mysql >>$logfilename 2>&1
echo "crsp_next_subprojectidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_subprojectidgen.mysql >>$logfilename 2>&1
echo "crsp_next_tldidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_tldidgen.mysql >>$logfilename 2>&1
echo "crsp_next_topdomainidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_topdomainidgen.mysql >>$logfilename 2>&1
echo "crsp_next_topprojectidgen.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_next_topprojectidgen.mysql >>$logfilename 2>&1
echo "crsp_bootstrap.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_bootstrap.mysql >>$logfilename 2>&1
echo "crsp_is_system_user.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_is_system_user.mysql >>$logfilename 2>&1
echo "crsp_is_cluster_user.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_is_cluster_user.mysql >>$logfilename 2>&1
echo "crsp_is_tenant_user.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_is_tenant_user.mysql >>$logfilename 2>&1
echo "crsp_create_clus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_clus.mysql >>$logfilename 2>&1
echo "crsp_lock_clus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_clus.mysql >>$logfilename 2>&1
echo "crsp_read_clus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_clus.mysql >>$logfilename 2>&1
echo "crsp_read_clus_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_clus_all.mysql >>$logfilename 2>&1
echo "crsp_page_clus_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_clus_all.mysql >>$logfilename 2>&1
echo "crsp_read_clus_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_clus_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_clus_by_udomnameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_clus_by_udomnameidx.mysql >>$logfilename 2>&1
echo "crsp_read_clus_by_udescridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_clus_by_udescridx.mysql >>$logfilename 2>&1
echo "crsp_update_clus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_clus.mysql >>$logfilename 2>&1
echo "crsp_delete_clus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_clus.mysql >>$logfilename 2>&1

echo "crsp_create_hostnode.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_hostnode.mysql >>$logfilename 2>&1
echo "crsp_lock_hostnode.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_hostnode.mysql >>$logfilename 2>&1
echo "crsp_read_hostnode.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostnode.mysql >>$logfilename 2>&1
echo "crsp_read_hostnode_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostnode_all.mysql >>$logfilename 2>&1
echo "crsp_page_hostnode_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_hostnode_all.mysql >>$logfilename 2>&1
echo "crsp_read_hostnode_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostnode_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_hostnode_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostnode_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_page_hostnode_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_hostnode_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_read_hostnode_by_udescridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostnode_by_udescridx.mysql >>$logfilename 2>&1
echo "crsp_read_hostnode_by_hostnameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostnode_by_hostnameidx.mysql >>$logfilename 2>&1
echo "crsp_update_hostnode.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_hostnode.mysql >>$logfilename 2>&1
echo "crsp_delete_hostnode.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostnode.mysql >>$logfilename 2>&1

echo "crsp_create_iso_ccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_iso_ccy.mysql >>$logfilename 2>&1
echo "crsp_lock_iso_ccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_iso_ccy.mysql >>$logfilename 2>&1
echo "crsp_read_iso_ccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_ccy.mysql >>$logfilename 2>&1
echo "crsp_read_iso_ccy_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_ccy_all.mysql >>$logfilename 2>&1
echo "crsp_read_iso_ccy_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_ccy_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_iso_ccy_by_ccycdidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_ccy_by_ccycdidx.mysql >>$logfilename 2>&1
echo "crsp_read_iso_ccy_by_ccynmidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_ccy_by_ccynmidx.mysql >>$logfilename 2>&1
echo "crsp_update_iso_ccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_iso_ccy.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_ccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_ccy.mysql >>$logfilename 2>&1

echo "crsp_create_iso_cntry.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_iso_cntry.mysql >>$logfilename 2>&1
echo "crsp_lock_iso_cntry.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_iso_cntry.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntry.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntry.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntry_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntry_all.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntry_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntry_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntry_by_isocodeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntry_by_isocodeidx.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntry_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntry_by_nameidx.mysql >>$logfilename 2>&1
echo "crsp_update_iso_cntry.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_iso_cntry.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_cntry.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntry.mysql >>$logfilename 2>&1

echo "crsp_create_iso_cntryccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_iso_cntryccy.mysql >>$logfilename 2>&1
echo "crsp_lock_iso_cntryccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_iso_cntryccy.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntryccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntryccy.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntryccy_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntryccy_all.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntryccy_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntryccy_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntryccy_by_ctryidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntryccy_by_ctryidx.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntryccy_by_ccyidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntryccy_by_ccyidx.mysql >>$logfilename 2>&1
echo "crsp_update_iso_cntryccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_iso_cntryccy.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_cntryccy.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntryccy.mysql >>$logfilename 2>&1

echo "crsp_create_iso_cntrylng.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_iso_cntrylng.mysql >>$logfilename 2>&1
echo "crsp_lock_iso_cntrylng.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_iso_cntrylng.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntrylng.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntrylng.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntrylng_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntrylng_all.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntrylng_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntrylng_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntrylng_by_ctryidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntrylng_by_ctryidx.mysql >>$logfilename 2>&1
echo "crsp_read_iso_cntrylng_by_langidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_cntrylng_by_langidx.mysql >>$logfilename 2>&1
echo "crsp_update_iso_cntrylng.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_iso_cntrylng.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_cntrylng.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntrylng.mysql >>$logfilename 2>&1

echo "crsp_create_iso_lang.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_iso_lang.mysql >>$logfilename 2>&1
echo "crsp_lock_iso_lang.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_iso_lang.mysql >>$logfilename 2>&1
echo "crsp_read_iso_lang.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_lang.mysql >>$logfilename 2>&1
echo "crsp_read_iso_lang_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_lang_all.mysql >>$logfilename 2>&1
echo "crsp_read_iso_lang_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_lang_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_iso_lang_by_code3idx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_lang_by_code3idx.mysql >>$logfilename 2>&1
echo "crsp_read_iso_lang_by_code2idx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_iso_lang_by_code2idx.mysql >>$logfilename 2>&1
echo "crsp_update_iso_lang.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_iso_lang.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_lang.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_lang.mysql >>$logfilename 2>&1

echo "crsp_create_isotz.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_isotz.mysql >>$logfilename 2>&1
echo "crsp_lock_isotz.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_isotz.mysql >>$logfilename 2>&1
echo "crsp_read_isotz.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_isotz.mysql >>$logfilename 2>&1
echo "crsp_read_isotz_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_isotz_all.mysql >>$logfilename 2>&1
echo "crsp_read_isotz_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_isotz_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_isotz_by_offsetidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_isotz_by_offsetidx.mysql >>$logfilename 2>&1
echo "crsp_read_isotz_by_utznameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_isotz_by_utznameidx.mysql >>$logfilename 2>&1
echo "crsp_read_isotz_by_iso8601idx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_isotz_by_iso8601idx.mysql >>$logfilename 2>&1
echo "crsp_update_isotz.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_isotz.mysql >>$logfilename 2>&1
echo "crsp_delete_isotz.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_isotz.mysql >>$logfilename 2>&1

echo "crsp_create_licn.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_licn.mysql >>$logfilename 2>&1
echo "crsp_lock_licn.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_licn.mysql >>$logfilename 2>&1
echo "crsp_read_licn.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_licn.mysql >>$logfilename 2>&1
echo "crsp_read_licn_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_licn_all.mysql >>$logfilename 2>&1
echo "crsp_read_licn_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_licn_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_licn_by_licntenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_licn_by_licntenantidx.mysql >>$logfilename 2>&1
echo "crsp_read_licn_by_domainidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_licn_by_domainidx.mysql >>$logfilename 2>&1
echo "crsp_read_licn_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_licn_by_unameidx.mysql >>$logfilename 2>&1
echo "crsp_update_licn.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_licn.mysql >>$logfilename 2>&1
echo "crsp_delete_licn.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_licn.mysql >>$logfilename 2>&1

echo "crsp_create_mjvrdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_mjvrdef.mysql >>$logfilename 2>&1
echo "crsp_lock_mjvrdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_mjvrdef.mysql >>$logfilename 2>&1
echo "crsp_read_mjvrdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mjvrdef.mysql >>$logfilename 2>&1
echo "crsp_read_mjvrdef_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mjvrdef_all.mysql >>$logfilename 2>&1
echo "crsp_read_mjvrdef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mjvrdef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_mjvrdef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mjvrdef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_read_mjvrdef_by_subprojectidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mjvrdef_by_subprojectidx.mysql >>$logfilename 2>&1
echo "crsp_read_mjvrdef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mjvrdef_by_nameidx.mysql >>$logfilename 2>&1
echo "crsp_update_mjvrdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_mjvrdef.mysql >>$logfilename 2>&1
echo "crsp_delete_mjvrdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mjvrdef.mysql >>$logfilename 2>&1

echo "crsp_create_mimetype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_mimetype.mysql >>$logfilename 2>&1
echo "crsp_lock_mimetype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_mimetype.mysql >>$logfilename 2>&1
echo "crsp_read_mimetype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mimetype.mysql >>$logfilename 2>&1
echo "crsp_read_mimetype_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mimetype_all.mysql >>$logfilename 2>&1
echo "crsp_read_mimetype_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mimetype_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_mimetype_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mimetype_by_unameidx.mysql >>$logfilename 2>&1
echo "crsp_update_mimetype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_mimetype.mysql >>$logfilename 2>&1
echo "crsp_delete_mimetype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mimetype.mysql >>$logfilename 2>&1

echo "crsp_create_mnvrdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_mnvrdef.mysql >>$logfilename 2>&1
echo "crsp_lock_mnvrdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_mnvrdef.mysql >>$logfilename 2>&1
echo "crsp_read_mnvrdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mnvrdef.mysql >>$logfilename 2>&1
echo "crsp_read_mnvrdef_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mnvrdef_all.mysql >>$logfilename 2>&1
echo "crsp_read_mnvrdef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mnvrdef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_mnvrdef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mnvrdef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_read_mnvrdef_by_majorveridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mnvrdef_by_majorveridx.mysql >>$logfilename 2>&1
echo "crsp_read_mnvrdef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_mnvrdef_by_nameidx.mysql >>$logfilename 2>&1
echo "crsp_update_mnvrdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_mnvrdef.mysql >>$logfilename 2>&1
echo "crsp_delete_mnvrdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mnvrdef.mysql >>$logfilename 2>&1

echo "crsp_create_secapp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_secapp.mysql >>$logfilename 2>&1
echo "crsp_lock_secapp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_secapp.mysql >>$logfilename 2>&1
echo "crsp_read_secapp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secapp.mysql >>$logfilename 2>&1
echo "crsp_read_secapp_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secapp_all.mysql >>$logfilename 2>&1
echo "crsp_page_secapp_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secapp_all.mysql >>$logfilename 2>&1
echo "crsp_read_secapp_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secapp_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_secapp_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secapp_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_page_secapp_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secapp_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_read_secapp_by_ujeemountidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secapp_by_ujeemountidx.mysql >>$logfilename 2>&1
echo "crsp_update_secapp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_secapp.mysql >>$logfilename 2>&1
echo "crsp_delete_secapp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secapp.mysql >>$logfilename 2>&1

echo "crsp_create_secdev.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_secdev.mysql >>$logfilename 2>&1
echo "crsp_lock_secdev.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_secdev.mysql >>$logfilename 2>&1
echo "crsp_read_secdev.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secdev.mysql >>$logfilename 2>&1
echo "crsp_read_secdev_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secdev_all.mysql >>$logfilename 2>&1
echo "crsp_page_secdev_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secdev_all.mysql >>$logfilename 2>&1
echo "crsp_read_secdev_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secdev_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_secdev_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secdev_by_nameidx.mysql >>$logfilename 2>&1
echo "crsp_read_secdev_by_useridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secdev_by_useridx.mysql >>$logfilename 2>&1
echo "crsp_page_secdev_by_useridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secdev_by_useridx.mysql >>$logfilename 2>&1
echo "crsp_update_secdev.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_secdev.mysql >>$logfilename 2>&1
echo "crsp_delete_secdev.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secdev.mysql >>$logfilename 2>&1

echo "crsp_create_secform.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_secform.mysql >>$logfilename 2>&1
echo "crsp_lock_secform.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_secform.mysql >>$logfilename 2>&1
echo "crsp_read_secform.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secform.mysql >>$logfilename 2>&1
echo "crsp_read_secform_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secform_all.mysql >>$logfilename 2>&1
echo "crsp_page_secform_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secform_all.mysql >>$logfilename 2>&1
echo "crsp_read_secform_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secform_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_secform_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secform_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_page_secform_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secform_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_read_secform_by_secappidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secform_by_secappidx.mysql >>$logfilename 2>&1
echo "crsp_page_secform_by_secappidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secform_by_secappidx.mysql >>$logfilename 2>&1
echo "crsp_read_secform_by_ujeeservletidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secform_by_ujeeservletidx.mysql >>$logfilename 2>&1
echo "crsp_update_secform.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_secform.mysql >>$logfilename 2>&1
echo "crsp_delete_secform.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secform.mysql >>$logfilename 2>&1

echo "crsp_create_secgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_secgrp.mysql >>$logfilename 2>&1
echo "crsp_lock_secgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_secgrp.mysql >>$logfilename 2>&1
echo "crsp_read_secgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrp.mysql >>$logfilename 2>&1
echo "crsp_read_secgrp_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrp_all.mysql >>$logfilename 2>&1
echo "crsp_read_secgrp_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrp_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_secgrp_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrp_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_read_secgrp_by_clustervisidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrp_by_clustervisidx.mysql >>$logfilename 2>&1
echo "crsp_read_secgrp_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrp_by_unameidx.mysql >>$logfilename 2>&1
echo "crsp_update_secgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_secgrp.mysql >>$logfilename 2>&1
echo "crsp_delete_secgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrp.mysql >>$logfilename 2>&1

echo "crsp_create_secgrpfrm.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_secgrpfrm.mysql >>$logfilename 2>&1
echo "crsp_lock_secgrpfrm.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_secgrpfrm.mysql >>$logfilename 2>&1
echo "crsp_read_secgrpfrm.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrpfrm.mysql >>$logfilename 2>&1
echo "crsp_read_secgrpfrm_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrpfrm_all.mysql >>$logfilename 2>&1
echo "crsp_page_secgrpfrm_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secgrpfrm_all.mysql >>$logfilename 2>&1
echo "crsp_read_secgrpfrm_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrpfrm_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_secgrpfrm_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrpfrm_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_page_secgrpfrm_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secgrpfrm_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_read_secgrpfrm_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrpfrm_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_page_secgrpfrm_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secgrpfrm_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_read_secgrpfrm_by_appidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrpfrm_by_appidx.mysql >>$logfilename 2>&1
echo "crsp_page_secgrpfrm_by_appidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secgrpfrm_by_appidx.mysql >>$logfilename 2>&1
echo "crsp_read_secgrpfrm_by_formidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrpfrm_by_formidx.mysql >>$logfilename 2>&1
echo "crsp_page_secgrpfrm_by_formidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secgrpfrm_by_formidx.mysql >>$logfilename 2>&1
echo "crsp_read_secgrpfrm_by_uformidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secgrpfrm_by_uformidx.mysql >>$logfilename 2>&1
echo "crsp_update_secgrpfrm.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_secgrpfrm.mysql >>$logfilename 2>&1
echo "crsp_delete_secgrpfrm.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrpfrm.mysql >>$logfilename 2>&1

echo "crsp_create_secinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_secinc.mysql >>$logfilename 2>&1
echo "crsp_lock_secinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_secinc.mysql >>$logfilename 2>&1
echo "crsp_read_secinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secinc.mysql >>$logfilename 2>&1
echo "crsp_read_secinc_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secinc_all.mysql >>$logfilename 2>&1
echo "crsp_page_secinc_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secinc_all.mysql >>$logfilename 2>&1
echo "crsp_read_secinc_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secinc_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_secinc_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secinc_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_page_secinc_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secinc_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_read_secinc_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secinc_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_page_secinc_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secinc_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_read_secinc_by_includeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secinc_by_includeidx.mysql >>$logfilename 2>&1
echo "crsp_page_secinc_by_includeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secinc_by_includeidx.mysql >>$logfilename 2>&1
echo "crsp_read_secinc_by_uincludeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secinc_by_uincludeidx.mysql >>$logfilename 2>&1
echo "crsp_update_secinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_secinc.mysql >>$logfilename 2>&1
echo "crsp_delete_secinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secinc.mysql >>$logfilename 2>&1

echo "crsp_create_secmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_secmemb.mysql >>$logfilename 2>&1
echo "crsp_lock_secmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_secmemb.mysql >>$logfilename 2>&1
echo "crsp_read_secmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secmemb.mysql >>$logfilename 2>&1
echo "crsp_read_secmemb_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secmemb_all.mysql >>$logfilename 2>&1
echo "crsp_page_secmemb_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secmemb_all.mysql >>$logfilename 2>&1
echo "crsp_read_secmemb_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secmemb_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_secmemb_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secmemb_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_page_secmemb_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secmemb_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_read_secmemb_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secmemb_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_page_secmemb_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secmemb_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_read_secmemb_by_useridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secmemb_by_useridx.mysql >>$logfilename 2>&1
echo "crsp_page_secmemb_by_useridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secmemb_by_useridx.mysql >>$logfilename 2>&1
echo "crsp_read_secmemb_by_uuseridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secmemb_by_uuseridx.mysql >>$logfilename 2>&1
echo "crsp_update_secmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_secmemb.mysql >>$logfilename 2>&1
echo "crsp_delete_secmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secmemb.mysql >>$logfilename 2>&1

echo "crsp_create_secsess.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_secsess.mysql >>$logfilename 2>&1
echo "crsp_lock_secsess.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_secsess.mysql >>$logfilename 2>&1
echo "crsp_read_secsess.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secsess.mysql >>$logfilename 2>&1
echo "crsp_read_secsess_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secsess_all.mysql >>$logfilename 2>&1
echo "crsp_page_secsess_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secsess_all.mysql >>$logfilename 2>&1
echo "crsp_read_secsess_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secsess_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_secsess_by_secuseridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secsess_by_secuseridx.mysql >>$logfilename 2>&1
echo "crsp_page_secsess_by_secuseridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secsess_by_secuseridx.mysql >>$logfilename 2>&1
echo "crsp_read_secsess_by_secdevidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secsess_by_secdevidx.mysql >>$logfilename 2>&1
echo "crsp_page_secsess_by_secdevidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secsess_by_secdevidx.mysql >>$logfilename 2>&1
echo "crsp_read_secsess_by_startidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secsess_by_startidx.mysql >>$logfilename 2>&1
echo "crsp_read_secsess_by_finishidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secsess_by_finishidx.mysql >>$logfilename 2>&1
echo "crsp_page_secsess_by_finishidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secsess_by_finishidx.mysql >>$logfilename 2>&1
echo "crsp_read_secsess_by_secproxyidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secsess_by_secproxyidx.mysql >>$logfilename 2>&1
echo "crsp_page_secsess_by_secproxyidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secsess_by_secproxyidx.mysql >>$logfilename 2>&1
echo "crsp_update_secsess.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_secsess.mysql >>$logfilename 2>&1
echo "crsp_delete_secsess.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secsess.mysql >>$logfilename 2>&1

echo "crsp_create_secuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_secuser.mysql >>$logfilename 2>&1
echo "crsp_lock_secuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_secuser.mysql >>$logfilename 2>&1
echo "crsp_read_secuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secuser.mysql >>$logfilename 2>&1
echo "crsp_read_secuser_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secuser_all.mysql >>$logfilename 2>&1
echo "crsp_page_secuser_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secuser_all.mysql >>$logfilename 2>&1
echo "crsp_read_secuser_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secuser_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_secuser_by_uloginidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secuser_by_uloginidx.mysql >>$logfilename 2>&1
echo "crsp_read_secuser_by_emconfidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secuser_by_emconfidx.mysql >>$logfilename 2>&1
echo "crsp_page_secuser_by_emconfidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secuser_by_emconfidx.mysql >>$logfilename 2>&1
echo "crsp_read_secuser_by_pwdresetidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secuser_by_pwdresetidx.mysql >>$logfilename 2>&1
echo "crsp_page_secuser_by_pwdresetidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secuser_by_pwdresetidx.mysql >>$logfilename 2>&1
echo "crsp_read_secuser_by_defdevidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_secuser_by_defdevidx.mysql >>$logfilename 2>&1
echo "crsp_page_secuser_by_defdevidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_secuser_by_defdevidx.mysql >>$logfilename 2>&1
echo "crsp_update_secuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_secuser.mysql >>$logfilename 2>&1
echo "crsp_delete_secuser.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secuser.mysql >>$logfilename 2>&1

echo "crsp_create_hostsvc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_hostsvc.mysql >>$logfilename 2>&1
echo "crsp_lock_hostsvc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_hostsvc.mysql >>$logfilename 2>&1
echo "crsp_read_hostsvc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostsvc.mysql >>$logfilename 2>&1
echo "crsp_read_hostsvc_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostsvc_all.mysql >>$logfilename 2>&1
echo "crsp_page_hostsvc_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_hostsvc_all.mysql >>$logfilename 2>&1
echo "crsp_read_hostsvc_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostsvc_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_hostsvc_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostsvc_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_page_hostsvc_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_hostsvc_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_read_hostsvc_by_hostidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostsvc_by_hostidx.mysql >>$logfilename 2>&1
echo "crsp_page_hostsvc_by_hostidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_hostsvc_by_hostidx.mysql >>$logfilename 2>&1
echo "crsp_read_hostsvc_by_typeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostsvc_by_typeidx.mysql >>$logfilename 2>&1
echo "crsp_page_hostsvc_by_typeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_hostsvc_by_typeidx.mysql >>$logfilename 2>&1
echo "crsp_read_hostsvc_by_utypeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostsvc_by_utypeidx.mysql >>$logfilename 2>&1
echo "crsp_read_hostsvc_by_uhostportidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_hostsvc_by_uhostportidx.mysql >>$logfilename 2>&1
echo "crsp_update_hostsvc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_hostsvc.mysql >>$logfilename 2>&1
echo "crsp_delete_hostsvc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostsvc.mysql >>$logfilename 2>&1

echo "crsp_create_svctype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_svctype.mysql >>$logfilename 2>&1
echo "crsp_lock_svctype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_svctype.mysql >>$logfilename 2>&1
echo "crsp_read_svctype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_svctype.mysql >>$logfilename 2>&1
echo "crsp_read_svctype_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_svctype_all.mysql >>$logfilename 2>&1
echo "crsp_read_svctype_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_svctype_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_svctype_by_udescridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_svctype_by_udescridx.mysql >>$logfilename 2>&1
echo "crsp_update_svctype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_svctype.mysql >>$logfilename 2>&1
echo "crsp_delete_svctype.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_svctype.mysql >>$logfilename 2>&1

echo "crsp_create_sprjdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_sprjdef.mysql >>$logfilename 2>&1
echo "crsp_lock_sprjdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_sprjdef.mysql >>$logfilename 2>&1
echo "crsp_read_sprjdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_sprjdef.mysql >>$logfilename 2>&1
echo "crsp_read_sprjdef_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_sprjdef_all.mysql >>$logfilename 2>&1
echo "crsp_read_sprjdef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_sprjdef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_sprjdef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_sprjdef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_read_sprjdef_by_topprojectidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_sprjdef_by_topprojectidx.mysql >>$logfilename 2>&1
echo "crsp_read_sprjdef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_sprjdef_by_nameidx.mysql >>$logfilename 2>&1
echo "crsp_update_sprjdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_sprjdef.mysql >>$logfilename 2>&1
echo "crsp_delete_sprjdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_sprjdef.mysql >>$logfilename 2>&1

echo "crsp_create_sysclus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_sysclus.mysql >>$logfilename 2>&1
echo "crsp_lock_sysclus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_sysclus.mysql >>$logfilename 2>&1
echo "crsp_read_sysclus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_sysclus.mysql >>$logfilename 2>&1
echo "crsp_read_sysclus_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_sysclus_all.mysql >>$logfilename 2>&1
echo "crsp_read_sysclus_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_sysclus_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_sysclus_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_sysclus_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_update_sysclus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_sysclus.mysql >>$logfilename 2>&1
echo "crsp_delete_sysclus.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_sysclus.mysql >>$logfilename 2>&1

echo "crsp_create_tsecgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_tsecgrp.mysql >>$logfilename 2>&1
echo "crsp_lock_tsecgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_tsecgrp.mysql >>$logfilename 2>&1
echo "crsp_read_tsecgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecgrp.mysql >>$logfilename 2>&1
echo "crsp_read_tsecgrp_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecgrp_all.mysql >>$logfilename 2>&1
echo "crsp_read_tsecgrp_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecgrp_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_tsecgrp_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecgrp_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_read_tsecgrp_by_tenantvisidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecgrp_by_tenantvisidx.mysql >>$logfilename 2>&1
echo "crsp_read_tsecgrp_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecgrp_by_unameidx.mysql >>$logfilename 2>&1
echo "crsp_update_tsecgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_tsecgrp.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecgrp.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecgrp.mysql >>$logfilename 2>&1

echo "crsp_create_tsecinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_tsecinc.mysql >>$logfilename 2>&1
echo "crsp_lock_tsecinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_tsecinc.mysql >>$logfilename 2>&1
echo "crsp_read_tsecinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecinc.mysql >>$logfilename 2>&1
echo "crsp_read_tsecinc_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecinc_all.mysql >>$logfilename 2>&1
echo "crsp_page_tsecinc_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_tsecinc_all.mysql >>$logfilename 2>&1
echo "crsp_read_tsecinc_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecinc_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_tsecinc_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecinc_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_page_tsecinc_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_tsecinc_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_read_tsecinc_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecinc_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_page_tsecinc_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_tsecinc_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_read_tsecinc_by_includeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecinc_by_includeidx.mysql >>$logfilename 2>&1
echo "crsp_page_tsecinc_by_includeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_tsecinc_by_includeidx.mysql >>$logfilename 2>&1
echo "crsp_read_tsecinc_by_uincludeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecinc_by_uincludeidx.mysql >>$logfilename 2>&1
echo "crsp_update_tsecinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_tsecinc.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecinc.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecinc.mysql >>$logfilename 2>&1

echo "crsp_create_tsecmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_tsecmemb.mysql >>$logfilename 2>&1
echo "crsp_lock_tsecmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_tsecmemb.mysql >>$logfilename 2>&1
echo "crsp_read_tsecmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecmemb.mysql >>$logfilename 2>&1
echo "crsp_read_tsecmemb_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecmemb_all.mysql >>$logfilename 2>&1
echo "crsp_page_tsecmemb_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_tsecmemb_all.mysql >>$logfilename 2>&1
echo "crsp_read_tsecmemb_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecmemb_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_tsecmemb_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecmemb_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_page_tsecmemb_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_tsecmemb_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_read_tsecmemb_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecmemb_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_page_tsecmemb_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_tsecmemb_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_read_tsecmemb_by_useridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecmemb_by_useridx.mysql >>$logfilename 2>&1
echo "crsp_page_tsecmemb_by_useridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_tsecmemb_by_useridx.mysql >>$logfilename 2>&1
echo "crsp_read_tsecmemb_by_uuseridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tsecmemb_by_uuseridx.mysql >>$logfilename 2>&1
echo "crsp_update_tsecmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_tsecmemb.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecmemb.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecmemb.mysql >>$logfilename 2>&1

echo "crsp_create_tenant.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_tenant.mysql >>$logfilename 2>&1
echo "crsp_lock_tenant.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_tenant.mysql >>$logfilename 2>&1
echo "crsp_read_tenant.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tenant.mysql >>$logfilename 2>&1
echo "crsp_read_tenant_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tenant_all.mysql >>$logfilename 2>&1
echo "crsp_page_tenant_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_tenant_all.mysql >>$logfilename 2>&1
echo "crsp_read_tenant_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tenant_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_tenant_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tenant_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_page_tenant_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_page_tenant_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_read_tenant_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tenant_by_unameidx.mysql >>$logfilename 2>&1
echo "crsp_update_tenant.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_tenant.mysql >>$logfilename 2>&1
echo "crsp_delete_tenant.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tenant.mysql >>$logfilename 2>&1

echo "crsp_create_tlddef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_tlddef.mysql >>$logfilename 2>&1
echo "crsp_lock_tlddef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_tlddef.mysql >>$logfilename 2>&1
echo "crsp_read_tlddef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tlddef.mysql >>$logfilename 2>&1
echo "crsp_read_tlddef_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tlddef_all.mysql >>$logfilename 2>&1
echo "crsp_read_tlddef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tlddef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_tlddef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tlddef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_read_tlddef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tlddef_by_nameidx.mysql >>$logfilename 2>&1
echo "crsp_update_tlddef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_tlddef.mysql >>$logfilename 2>&1
echo "crsp_delete_tlddef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tlddef.mysql >>$logfilename 2>&1

echo "crsp_create_tdomdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_tdomdef.mysql >>$logfilename 2>&1
echo "crsp_lock_tdomdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_tdomdef.mysql >>$logfilename 2>&1
echo "crsp_read_tdomdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tdomdef.mysql >>$logfilename 2>&1
echo "crsp_read_tdomdef_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tdomdef_all.mysql >>$logfilename 2>&1
echo "crsp_read_tdomdef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tdomdef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_tdomdef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tdomdef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_read_tdomdef_by_tldidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tdomdef_by_tldidx.mysql >>$logfilename 2>&1
echo "crsp_read_tdomdef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tdomdef_by_nameidx.mysql >>$logfilename 2>&1
echo "crsp_update_tdomdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_tdomdef.mysql >>$logfilename 2>&1
echo "crsp_delete_tdomdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tdomdef.mysql >>$logfilename 2>&1

echo "crsp_create_tprjdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_tprjdef.mysql >>$logfilename 2>&1
echo "crsp_lock_tprjdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_tprjdef.mysql >>$logfilename 2>&1
echo "crsp_read_tprjdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tprjdef.mysql >>$logfilename 2>&1
echo "crsp_read_tprjdef_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tprjdef_all.mysql >>$logfilename 2>&1
echo "crsp_read_tprjdef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tprjdef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_tprjdef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tprjdef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_read_tprjdef_by_topdomainidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tprjdef_by_topdomainidx.mysql >>$logfilename 2>&1
echo "crsp_read_tprjdef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_tprjdef_by_nameidx.mysql >>$logfilename 2>&1
echo "crsp_update_tprjdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_tprjdef.mysql >>$logfilename 2>&1
echo "crsp_delete_tprjdef.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tprjdef.mysql >>$logfilename 2>&1

echo "crsp_create_urlproto.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_create_urlproto.mysql >>$logfilename 2>&1
echo "crsp_lock_urlproto.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_lock_urlproto.mysql >>$logfilename 2>&1
echo "crsp_read_urlproto.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_urlproto.mysql >>$logfilename 2>&1
echo "crsp_read_urlproto_all.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_urlproto_all.mysql >>$logfilename 2>&1
echo "crsp_read_urlproto_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_urlproto_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_read_urlproto_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_urlproto_by_unameidx.mysql >>$logfilename 2>&1
echo "crsp_read_urlproto_by_issecureidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_read_urlproto_by_issecureidx.mysql >>$logfilename 2>&1
echo "crsp_update_urlproto.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_update_urlproto.mysql >>$logfilename 2>&1
echo "crsp_delete_urlproto.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_urlproto.mysql >>$logfilename 2>&1

echo "crsp_delete_clus_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_clus_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_clus_by_udomnameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_clus_by_udomnameidx.mysql >>$logfilename 2>&1
echo "crsp_delete_clus_by_udescridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_clus_by_udescridx.mysql >>$logfilename 2>&1

echo "crsp_delete_hostnode_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostnode_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_hostnode_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostnode_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_delete_hostnode_by_udescridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostnode_by_udescridx.mysql >>$logfilename 2>&1
echo "crsp_delete_hostnode_by_hostnameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostnode_by_hostnameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_iso_ccy_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_ccy_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_ccy_by_ccycdidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_ccy_by_ccycdidx.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_ccy_by_ccynmidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_ccy_by_ccynmidx.mysql >>$logfilename 2>&1

echo "crsp_delete_iso_cntry_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntry_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_cntry_by_isocodeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntry_by_isocodeidx.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_cntry_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntry_by_nameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_iso_cntryccy_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntryccy_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_cntryccy_by_ctryidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntryccy_by_ctryidx.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_cntryccy_by_ccyidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntryccy_by_ccyidx.mysql >>$logfilename 2>&1

echo "crsp_delete_iso_cntrylng_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntrylng_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_cntrylng_by_ctryidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntrylng_by_ctryidx.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_cntrylng_by_langidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_cntrylng_by_langidx.mysql >>$logfilename 2>&1

echo "crsp_delete_iso_lang_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_lang_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_lang_by_code3idx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_lang_by_code3idx.mysql >>$logfilename 2>&1
echo "crsp_delete_iso_lang_by_code2idx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_iso_lang_by_code2idx.mysql >>$logfilename 2>&1

echo "crsp_delete_isotz_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_isotz_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_isotz_by_offsetidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_isotz_by_offsetidx.mysql >>$logfilename 2>&1
echo "crsp_delete_isotz_by_utznameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_isotz_by_utznameidx.mysql >>$logfilename 2>&1
echo "crsp_delete_isotz_by_iso8601idx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_isotz_by_iso8601idx.mysql >>$logfilename 2>&1

echo "crsp_delete_licn_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_licn_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_licn_by_licntenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_licn_by_licntenantidx.mysql >>$logfilename 2>&1
echo "crsp_delete_licn_by_domainidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_licn_by_domainidx.mysql >>$logfilename 2>&1
echo "crsp_delete_licn_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_licn_by_unameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_mjvrdef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mjvrdef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_mjvrdef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mjvrdef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_delete_mjvrdef_by_subprojectidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mjvrdef_by_subprojectidx.mysql >>$logfilename 2>&1
echo "crsp_delete_mjvrdef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mjvrdef_by_nameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_mimetype_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mimetype_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_mimetype_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mimetype_by_unameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_mnvrdef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mnvrdef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_mnvrdef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mnvrdef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_delete_mnvrdef_by_majorveridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mnvrdef_by_majorveridx.mysql >>$logfilename 2>&1
echo "crsp_delete_mnvrdef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_mnvrdef_by_nameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_secapp_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secapp_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_secapp_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secapp_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_delete_secapp_by_ujeemountidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secapp_by_ujeemountidx.mysql >>$logfilename 2>&1

echo "crsp_delete_secdev_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secdev_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_secdev_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secdev_by_nameidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secdev_by_useridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secdev_by_useridx.mysql >>$logfilename 2>&1

echo "crsp_delete_secform_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secform_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_secform_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secform_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_delete_secform_by_secappidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secform_by_secappidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secform_by_ujeeservletidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secform_by_ujeeservletidx.mysql >>$logfilename 2>&1

echo "crsp_delete_secgrp_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrp_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_secgrp_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrp_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_delete_secgrp_by_clustervisidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrp_by_clustervisidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secgrp_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrp_by_unameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_secgrpfrm_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrpfrm_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_secgrpfrm_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrpfrm_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_delete_secgrpfrm_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrpfrm_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secgrpfrm_by_appidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrpfrm_by_appidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secgrpfrm_by_formidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrpfrm_by_formidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secgrpfrm_by_uformidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secgrpfrm_by_uformidx.mysql >>$logfilename 2>&1

echo "crsp_delete_secinc_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secinc_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_secinc_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secinc_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_delete_secinc_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secinc_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secinc_by_includeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secinc_by_includeidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secinc_by_uincludeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secinc_by_uincludeidx.mysql >>$logfilename 2>&1

echo "crsp_delete_secmemb_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secmemb_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_secmemb_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secmemb_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_delete_secmemb_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secmemb_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secmemb_by_useridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secmemb_by_useridx.mysql >>$logfilename 2>&1
echo "crsp_delete_secmemb_by_uuseridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secmemb_by_uuseridx.mysql >>$logfilename 2>&1

echo "crsp_delete_secsess_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secsess_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_secsess_by_secuseridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secsess_by_secuseridx.mysql >>$logfilename 2>&1
echo "crsp_delete_secsess_by_secdevidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secsess_by_secdevidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secsess_by_startidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secsess_by_startidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secsess_by_finishidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secsess_by_finishidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secsess_by_secproxyidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secsess_by_secproxyidx.mysql >>$logfilename 2>&1

echo "crsp_delete_secuser_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secuser_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_secuser_by_uloginidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secuser_by_uloginidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secuser_by_emconfidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secuser_by_emconfidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secuser_by_pwdresetidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secuser_by_pwdresetidx.mysql >>$logfilename 2>&1
echo "crsp_delete_secuser_by_defdevidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_secuser_by_defdevidx.mysql >>$logfilename 2>&1

echo "crsp_delete_hostsvc_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostsvc_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_hostsvc_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostsvc_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_delete_hostsvc_by_hostidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostsvc_by_hostidx.mysql >>$logfilename 2>&1
echo "crsp_delete_hostsvc_by_typeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostsvc_by_typeidx.mysql >>$logfilename 2>&1
echo "crsp_delete_hostsvc_by_utypeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostsvc_by_utypeidx.mysql >>$logfilename 2>&1
echo "crsp_delete_hostsvc_by_uhostportidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_hostsvc_by_uhostportidx.mysql >>$logfilename 2>&1

echo "crsp_delete_svctype_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_svctype_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_svctype_by_udescridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_svctype_by_udescridx.mysql >>$logfilename 2>&1

echo "crsp_delete_sprjdef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_sprjdef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_sprjdef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_sprjdef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_delete_sprjdef_by_topprojectidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_sprjdef_by_topprojectidx.mysql >>$logfilename 2>&1
echo "crsp_delete_sprjdef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_sprjdef_by_nameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_sysclus_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_sysclus_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_sysclus_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_sysclus_by_clusteridx.mysql >>$logfilename 2>&1

echo "crsp_delete_tsecgrp_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecgrp_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecgrp_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecgrp_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecgrp_by_tenantvisidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecgrp_by_tenantvisidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecgrp_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecgrp_by_unameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_tsecinc_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecinc_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecinc_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecinc_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecinc_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecinc_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecinc_by_includeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecinc_by_includeidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecinc_by_uincludeidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecinc_by_uincludeidx.mysql >>$logfilename 2>&1

echo "crsp_delete_tsecmemb_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecmemb_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecmemb_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecmemb_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecmemb_by_groupidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecmemb_by_groupidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecmemb_by_useridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecmemb_by_useridx.mysql >>$logfilename 2>&1
echo "crsp_delete_tsecmemb_by_uuseridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tsecmemb_by_uuseridx.mysql >>$logfilename 2>&1

echo "crsp_delete_tenant_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tenant_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_tenant_by_clusteridx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tenant_by_clusteridx.mysql >>$logfilename 2>&1
echo "crsp_delete_tenant_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tenant_by_unameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_tlddef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tlddef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_tlddef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tlddef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tlddef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tlddef_by_nameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_tdomdef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tdomdef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_tdomdef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tdomdef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tdomdef_by_tldidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tdomdef_by_tldidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tdomdef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tdomdef_by_nameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_tprjdef_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tprjdef_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_tprjdef_by_tenantidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tprjdef_by_tenantidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tprjdef_by_topdomainidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tprjdef_by_topdomainidx.mysql >>$logfilename 2>&1
echo "crsp_delete_tprjdef_by_nameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_tprjdef_by_nameidx.mysql >>$logfilename 2>&1

echo "crsp_delete_urlproto_by_ididx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_urlproto_by_ididx.mysql >>$logfilename 2>&1
echo "crsp_delete_urlproto_by_unameidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_urlproto_by_unameidx.mysql >>$logfilename 2>&1
echo "crsp_delete_urlproto_by_issecureidx.mysql" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd < crsp_delete_urlproto_by_issecureidx.mysql >>$logfilename 2>&1

