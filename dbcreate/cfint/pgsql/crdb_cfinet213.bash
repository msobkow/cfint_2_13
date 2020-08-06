#!/bin/bash
#
#	@(#) dbcreate/cfint/pgsql/crdb_cfinet213.bash
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
pgdatadir=""
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

		-D)
			shift
			pgdatadir=$1
			shift
			;;

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
	echo >&2 "WARNING: Postgres DBA login not specified with '-U username', using default 'postgres'"
fi

if [ "${pgpwd}" = "" ]; then
	echo >&2 "ERROR: Password must be specified with '-P password'"
	parmerrors="Y"
fi

if [ "${pghost}" = "" ]; then
	echo >&2 "ERROR: Server hostname must be specified with '-H hostname'"
	parmerrors="Y"
fi

if [ "${pgdatadir}" = "" ]; then
	echo >&2 "WARNING: Database data directory was not specified with '-D directory', tablespaces will not be created"
fi

if [ "$parmerrors" != "" ]; then
	echo >&2 "ABORT: Cannot continue"
	exit 1
fi

if [ "${logfilename}" = "" ]; then
	logfilename=`date +'crdb_cfinet213-%Y%m%d_%Hh%M.log'`
	echo "" >${logfilename}
fi

export PGPASSWORD="${pgpwd}"

if [ "${pgport}" != "" ]; then
	export PGPORT="--port=${pgport} "
	export PASSPGPORT="-p ${pgport} "
else
	export PGPORT=""
	export PASSPGPORT=""
fi


#
#	Create the tablespaces
#

if [ "${pgdatadir}" != "" ]; then

	need_dirs="N"

	if [ ! -d ${pgdatadir} ]; then
		need_dirs="Y"
	fi

	if [ ! -d ${pgdatadir}/cfinet213_data1 ]; then
		need_dirs="Y"
	fi

	if [ ! -d ${pgdatadir}/cfinet213_idx1 ]; then
		need_dirs="Y"
	fi

	if [ "${need_dirs}" = "Y" ]; then
		echo "Creating tablespace directories" | tee -a ${logfilename}

		if [ "${OS}" != "Windows_NT" ]; then
			su ${pguser} --command="mkdir ${pgdatadir} ${pgdatadir}/cfinet213_data1 ${pgdatadir}/cfinet213_idx1"
		else
			runas /user:${COMPUTERNAME}\\${pguser} "mkdir ${pgdatadir} ${pgdatadir}/cfinet213_data1 ${pgdatadir}/cfinet213_idx1"
		fi
	fi

	echo "" | tee -a ${logfilename}
	echo "Creating tablespaces cfinet213_data1 and cfinet213_idx1" | tee -a ${logfilename}
	psql -h ${pghost} ${PGPORT} -d template1 -U ${pguser} -a -e -c "create tablespace cfinet213_data1 location '${pgdatadir}/cfinet213_data1'" >>${logfilename} 2>&1

	psql -h ${pghost} ${PGPORT} -d template1 -U ${pguser} -a -e -c "create tablespace cfinet213_idx1 location '${pgdatadir}/cfinet213_idx1'" >>${logfilename} 2>&1

fi


#
#	Recreate the database instance
#
echo "Recreating database cfinet213 ..." | tee -a ${logfilename}

echo "" >>${logfilename}
echo "#" >>${logfilename}
echo "#	Drop database cfinet213" >>${logfilename}
echo "#" >>${logfilename}

psql -h ${pghost} ${PGPORT} -d template1 -U ${pguser} -a -e -c "drop database cfinet213" >>${logfilename} 2>&1

echo "" >>${logfilename}
echo "#" >>${logfilename}
echo "#	Create database cfinet213" >>${logfilename}
echo "#" >>${logfilename}

psql -h ${pghost} ${PGPORT} -d template1 -U ${pguser} -a -e -c "create database cfinet213 tablespace cfinet213_data1" >>${logfilename} 2>&1

./crschema_cfinet213.bash -H ${pghost} ${PASSPGPORT} -d cfinet213 -U ${pguser} -P ${pgpwd} -L ${logfilename}
