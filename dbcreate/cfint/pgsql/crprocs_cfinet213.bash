#!/bin/bash
#
#	@(#) dbcreate/cfint/pgsql/crprocs_cfinet213.bash
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

#
#	Initialize locals
#
pgdb=""
pghost=""
pgport=""
pgpwd=""
pgsrv=""
pguser=""
logfilename=""
parmerrors=""
TK_DUALCASE_IN_CASE_STATEMENTS=true

#
#	Parse the command line options
#
while [ -n "$1" ]
do
	case "$1" in

		-d)
			shift
			pgdb=$1
			shift
			;;

		-L)
			shift
			logfilename=$1
			shift
			;;

		-H)
			shift
			pghost=$1
			shift
			;;

		-p)
			shift
			pgport=$1
			shift
			;;

		-P)
			shift
			pgpwd=$1
			shift
			;;

		-S)
			shift
			pgsrv=$1
			shift
			;;

		-U)
			shift
			pguser=$1
			shift
			;;

		*)
			echo >&2 "ERROR: Option $1 not recognized."
			parmerrors="Y"
			shift
			;;
	esac
done

#
#	Validate parameters
#

if [ "${pguser}" = "" ]; then
	echo >&2 "ERROR: User must be specified with '-U username'"
	parmerrors="Y"
fi

if [ "${pgpwd}" = "" ]; then
	echo >&2 "ERROR: Password must be specified with '-P password'"
	parmerrors="Y"
fi

if [ "${pghost}" = "" ]; then
	echo >&2 "ERROR: Server host name must be specified with '-H hostname'"
	parmerrors="Y"
fi

if [ "${pgdb}" = "" ]; then
	echo >&2 "ERROR: Database name must be specified with '-d dbname'"
	parmerrors="Y"
fi

if [ "${parmerrors}" != "" ]; then
	echo >&2 "ABORT: Cannot continue"
	exit 1
fi

if [ "${logfilename}" = "" ]; then
	logfilename=`date +'$GenFileBaseName$-%Y%m%d_%Hh%M.log'`
	echo "" >$logfilename
fi

export PGPASSWORD="${pgpwd}"

if [ "${pgport}" != "" ]; then
	export PGPORT="--port=${pgport} "
	export PASSPGPORT="-p ${pgport} "
else
	export PGPORT=""
	export PASSPGPORT=""
fi

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_is_system_user.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_is_cluster_user.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_is_tenant_user.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_isoccyidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_isoctryidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_isolangidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_isotzoneidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_servicetypeidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_mimetypeidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_urlprotocolidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_clusteridgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_tenantidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_secappidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_secformidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_secgroupidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_hostnodeidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_secgroupformidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_secgrpincidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_secgrpmembidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_serviceidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_tsecgroupidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_tsecgrpincidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_tsecgrpmembidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_licenseidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_majorversionidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_minorversionidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_subprojectidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_tldidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_topdomainidgen.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_next_topprojectidgen.pgsql >>$logfilename 2>&1


psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_clus.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_clus.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_clus.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_clus_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_clus_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_clus_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_clus_by_udomnameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_clus_by_udescridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_clus.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_clus.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_hostnode.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_hostnode.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostnode.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostnode_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_hostnode_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostnode_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_hostnode_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostnode_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostnode_by_udescridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostnode_by_hostnameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_hostnode.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostnode.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_iso_ccy.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_iso_ccy.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_ccy.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_ccy_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_ccy_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_ccy_by_ccycdidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_ccy_by_ccynmidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_iso_ccy.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_ccy.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_iso_cntry.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_iso_cntry.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntry.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntry_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntry_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntry_by_isocodeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntry_by_nameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_iso_cntry.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntry.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_iso_cntryccy.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_iso_cntryccy.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntryccy.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntryccy_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntryccy_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntryccy_by_ctryidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntryccy_by_ccyidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_iso_cntryccy.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntryccy.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_iso_cntrylng.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_iso_cntrylng.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntrylng.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntrylng_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntrylng_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntrylng_by_ctryidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_cntrylng_by_langidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_iso_cntrylng.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntrylng.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_iso_lang.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_iso_lang.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_lang.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_lang_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_lang_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_lang_by_code3idx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_iso_lang_by_code2idx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_iso_lang.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_lang.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_isotz.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_isotz.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_isotz.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_isotz_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_isotz_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_isotz_by_offsetidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_isotz_by_utznameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_isotz_by_iso8601idx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_isotz.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_isotz.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_licn.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_licn.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_licn.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_licn_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_licn_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_licn_by_licntenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_licn_by_domainidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_licn_by_unameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_licn.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_licn.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_mjvrdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_mjvrdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mjvrdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mjvrdef_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mjvrdef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mjvrdef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mjvrdef_by_subprojectidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mjvrdef_by_nameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_mjvrdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mjvrdef.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_mimetype.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_mimetype.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mimetype.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mimetype_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mimetype_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mimetype_by_unameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_mimetype.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mimetype.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_mnvrdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_mnvrdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mnvrdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mnvrdef_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mnvrdef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mnvrdef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mnvrdef_by_majorveridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_mnvrdef_by_nameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_mnvrdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mnvrdef.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_secapp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_secapp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secapp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secapp_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secapp_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secapp_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secapp_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secapp_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secapp_by_ujeemountidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_secapp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secapp.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_secdev.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_secdev.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secdev.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secdev_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secdev_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secdev_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secdev_by_nameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secdev_by_useridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secdev_by_useridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_secdev.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secdev.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_secform.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_secform.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secform.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secform_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secform_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secform_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secform_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secform_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secform_by_secappidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secform_by_secappidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secform_by_ujeeservletidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_secform.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secform.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_secgrp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_secgrp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrp_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrp_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrp_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrp_by_clustervisidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrp_by_unameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_secgrp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrp.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_secgrpfrm.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_secgrpfrm.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrpfrm.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrpfrm_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secgrpfrm_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrpfrm_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secgrpfrm_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrpfrm_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secgrpfrm_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrpfrm_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secgrpfrm_by_appidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrpfrm_by_appidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secgrpfrm_by_formidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrpfrm_by_formidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secgrpfrm_by_uformidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_secgrpfrm.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrpfrm.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_secinc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_secinc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secinc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secinc_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secinc_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secinc_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secinc_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secinc_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secinc_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secinc_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secinc_by_includeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secinc_by_includeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secinc_by_uincludeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_secinc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secinc.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_secmemb.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_secmemb.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secmemb.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secmemb_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secmemb_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secmemb_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secmemb_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secmemb_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secmemb_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secmemb_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secmemb_by_useridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secmemb_by_useridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secmemb_by_uuseridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_secmemb.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secmemb.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_secsess.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_secsess.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secsess.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secsess_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secsess_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secsess_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secsess_by_secuseridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secsess_by_secuseridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secsess_by_secdevidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secsess_by_secdevidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secsess_by_startidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secsess_by_finishidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secsess_by_finishidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secsess_by_secproxyidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secsess_by_secproxyidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_secsess.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secsess.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_secuser.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_secuser.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secuser.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secuser_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secuser_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secuser_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secuser_by_uloginidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secuser_by_emconfidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secuser_by_emconfidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secuser_by_pwdresetidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secuser_by_pwdresetidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_secuser_by_defdevidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_secuser_by_defdevidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_secuser.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secuser.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_hostsvc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_hostsvc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostsvc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostsvc_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_hostsvc_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostsvc_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_hostsvc_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostsvc_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_hostsvc_by_hostidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostsvc_by_hostidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_hostsvc_by_typeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostsvc_by_typeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostsvc_by_utypeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_hostsvc_by_uhostportidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_hostsvc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostsvc.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_svctype.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_svctype.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_svctype.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_svctype_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_svctype_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_svctype_by_udescridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_svctype.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_svctype.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_sprjdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_sprjdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_sprjdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_sprjdef_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_sprjdef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_sprjdef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_sprjdef_by_topprojectidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_sprjdef_by_nameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_sprjdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_sprjdef.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_sysclus.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_sysclus.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_sysclus.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_sysclus_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_sysclus_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_sysclus_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_sysclus.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_sysclus.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_tsecgrp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_tsecgrp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecgrp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecgrp_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecgrp_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecgrp_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecgrp_by_tenantvisidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecgrp_by_unameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_tsecgrp.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecgrp.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_tsecinc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_tsecinc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecinc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecinc_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_tsecinc_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecinc_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_tsecinc_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecinc_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_tsecinc_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecinc_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_tsecinc_by_includeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecinc_by_includeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecinc_by_uincludeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_tsecinc.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecinc.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_tsecmemb.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_tsecmemb.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecmemb.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecmemb_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_tsecmemb_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecmemb_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_tsecmemb_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecmemb_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_tsecmemb_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecmemb_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_tsecmemb_by_useridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecmemb_by_useridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tsecmemb_by_uuseridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_tsecmemb.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecmemb.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_tenant.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_tenant.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tenant.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tenant_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_tenant_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tenant_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_page_tenant_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tenant_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tenant_by_unameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_tenant.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tenant.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_tlddef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_tlddef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tlddef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tlddef_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tlddef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tlddef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tlddef_by_nameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_tlddef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tlddef.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_tdomdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_tdomdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tdomdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tdomdef_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tdomdef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tdomdef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tdomdef_by_tldidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tdomdef_by_nameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_tdomdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tdomdef.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_tprjdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_tprjdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tprjdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tprjdef_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tprjdef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tprjdef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tprjdef_by_topdomainidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_tprjdef_by_nameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_tprjdef.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tprjdef.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_create_urlproto.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_lock_urlproto.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_urlproto.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_urlproto_all.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_urlproto_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_urlproto_by_unameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_read_urlproto_by_issecureidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_update_urlproto.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_urlproto.pgsql >>$logfilename 2>&1


psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_clus_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_clus_by_udomnameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_clus_by_udescridx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostnode_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostnode_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostnode_by_udescridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostnode_by_hostnameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_ccy_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_ccy_by_ccycdidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_ccy_by_ccynmidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntry_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntry_by_isocodeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntry_by_nameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntryccy_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntryccy_by_ctryidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntryccy_by_ccyidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntrylng_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntrylng_by_ctryidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_cntrylng_by_langidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_lang_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_lang_by_code3idx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_iso_lang_by_code2idx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_isotz_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_isotz_by_offsetidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_isotz_by_utznameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_isotz_by_iso8601idx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_licn_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_licn_by_licntenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_licn_by_domainidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_licn_by_unameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mjvrdef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mjvrdef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mjvrdef_by_subprojectidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mjvrdef_by_nameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mimetype_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mimetype_by_unameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mnvrdef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mnvrdef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mnvrdef_by_majorveridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_mnvrdef_by_nameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secapp_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secapp_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secapp_by_ujeemountidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secdev_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secdev_by_nameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secdev_by_useridx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secform_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secform_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secform_by_secappidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secform_by_ujeeservletidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrp_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrp_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrp_by_clustervisidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrp_by_unameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrpfrm_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrpfrm_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrpfrm_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrpfrm_by_appidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrpfrm_by_formidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secgrpfrm_by_uformidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secinc_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secinc_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secinc_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secinc_by_includeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secinc_by_uincludeidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secmemb_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secmemb_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secmemb_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secmemb_by_useridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secmemb_by_uuseridx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secsess_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secsess_by_secuseridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secsess_by_secdevidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secsess_by_startidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secsess_by_finishidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secsess_by_secproxyidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secuser_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secuser_by_uloginidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secuser_by_emconfidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secuser_by_pwdresetidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_secuser_by_defdevidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostsvc_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostsvc_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostsvc_by_hostidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostsvc_by_typeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostsvc_by_utypeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_hostsvc_by_uhostportidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_svctype_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_svctype_by_udescridx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_sprjdef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_sprjdef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_sprjdef_by_topprojectidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_sprjdef_by_nameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_sysclus_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_sysclus_by_clusteridx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecgrp_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecgrp_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecgrp_by_tenantvisidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecgrp_by_unameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecinc_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecinc_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecinc_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecinc_by_includeidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecinc_by_uincludeidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecmemb_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecmemb_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecmemb_by_groupidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecmemb_by_useridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tsecmemb_by_uuseridx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tenant_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tenant_by_clusteridx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tenant_by_unameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tlddef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tlddef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tlddef_by_nameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tdomdef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tdomdef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tdomdef_by_tldidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tdomdef_by_nameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tprjdef_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tprjdef_by_tenantidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tprjdef_by_topdomainidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_tprjdef_by_nameidx.pgsql >>$logfilename 2>&1

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_urlproto_by_ididx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_urlproto_by_unameidx.pgsql >>$logfilename 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_delete_urlproto_by_issecureidx.pgsql >>$logfilename 2>&1


psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crsp_bootstrap.pgsql >>$logfilename 2>&1

