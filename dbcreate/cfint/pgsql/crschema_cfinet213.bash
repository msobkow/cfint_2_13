#!/bin/bash
#
#	@(#) dbcreate/cfint/pgsql/crschema_cfinet213.bash
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

echo "Dropping old schema cfinet213 for ${pguser}"
echo "Dropping old schema cfinet213 for ${pguser}" >>${logfilename}

psql -h ${pghost} ${PGPORT} -U ${pguser} -a -e -c "drop schema cfinet213" >>${logfilename} 2>&1

echo "Creating schema CFINet213 in database ${pgdb} for ${pguser}"
echo "Creating schema CFINet213 in database ${pgdb} for ${pguser}" >>${logfilename}

psql -h ${pghost} ${PGPORT} -d ${pgdb} -U ${pguser} -a -e -c "create schema cfinet213" >>${logfilename} 2>&1


#
#	Create the database tables
#
if [ -f ./crtbl_cfinet213.bash ]; then
	echo "	Creating database tables ..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crtbl_cfinet213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crtbl_cfinet213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the database indexes
#
if [ -f ./cridx_cfinet213.bash ]; then
	echo "	Creating database indexes ..."
	echo "#" >>${logfilename}
	echo "#	Executing script cridx_cfinet213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./cridx_cfinet213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the database relations
#
if [ -f ./crrel_cfinet213.bash ]; then
	echo "	Creating database relations ..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crrel_cfinet213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crrel_cfinet213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the database sequences
#
if [ -f ./crseq_cfinet213.bash ]; then
	echo "	Creating database sequences..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crseq_cfinet213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crseq_cfinet213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the return record types for the stored procedures
#
if [ -f ./crtypes_cfinet213.bash ]; then
	echo "	Creating database types..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crtypes_cfinet213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crtypes_cfinet213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the stored procedures
#
if [ -f ./crprocs_cfinet213.bash ]; then
	echo "	Creating stored procedures..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crprocs_cfinet213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crprocs_cfinet213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Load initial data
#
if [ -f ./load_cfinet213.bash ]; then
	echo "	Loading initial data ..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script load_cfinet213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./load_cfinet213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

#
#	Create the database triggers
#
if [ -f ./crtrg_cfinet213.bash ]; then
	echo "	Creating database triggers ..."
	echo "" >>${logfilename}
	echo "#" >>${logfilename}
	echo "#	Executing script crtrg_cfinet213.bash" >>${logfilename}
	echo "#" >>${logfilename}
	./crtrg_cfinet213.bash -H ${pghost} ${PASSPGPORT} -d ${pgdb} -U ${pguser} -P ${pgpwd} -L ${logfilename}
fi

exit 0

