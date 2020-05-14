#!/bin/bash
#
#	@(#) dbcreate/cfint/pgsql/crseq_cfinet213.bash
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

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crseq_isoccyidgenseq.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crseq_isoctryidgenseq.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crseq_isolangidgenseq.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crseq_isotzoneidgenseq.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crseq_servicetypeidgenseq.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crseq_mimetypeidgenseq.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crseq_urlprotoidgenseq.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crseq_clusteridgenseq.pgsql >>${logfilename} 2>&1
psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -f crseq_tenantidgenseq.pgsql >>${logfilename} 2>&1

