#!/bin/bash
#
#	@(#) dbcreate/cfint/mysql/crschema_cfinet213.bash
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

echo "Dropping any existing schema CFINet213 for $mysqluser"
echo "Dropping any existing schema CFINet213 for $mysqluser" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd --execute="drop schema cfinet213" >>$logfilename 2>&1

echo "Creating schema CFINet213 for $mysqluser"
echo "Creating schema CFINet213 $mysqluser" >>$logfilename
mysql -v -u $mysqluser --password=$mysqlpwd --execute="create schema cfinet213" >>$logfilename 2>&1


#
#	Create the database tables
#
if [ -f crtbl_cfinet213.bash ]; then
	echo "	Creating database tables ..."
	echo "" >>$logfilename
	echo "#" >>$logfilename
	echo "#	Executing script crtbl_cfinet213.bash" >>$logfilename
	echo "#" >>$logfilename
	./crtbl_cfinet213.bash -U $mysqluser -P $mysqlpwd -L $logfilename
fi

#
#	Create the database indexes
#
if [ -f cridx_cfinet213.bash ]; then
	echo "	Creating database indexes ..."
	echo "#" >>$logfilename
	echo "#	Executing script cridx_cfinet213.bash" >>$logfilename
	echo "#" >>$logfilename
	./cridx_cfinet213.bash -U $mysqluser -P $mysqlpwd -L $logfilename
fi

#
#	Create the database relations
#
if [ -f crrel_cfinet213.bash ]; then
	echo "	Creating database relations ..."
	echo "" >>$logfilename
	echo "#" >>$logfilename
	echo "#	Executing script crrel_cfinet213.bash" >>$logfilename
	echo "#" >>$logfilename
	./crrel_cfinet213.bash -U $mysqluser -P $mysqlpwd -L $logfilename
fi

#
#	Create the stored procedureds
#
if [ -f crprocs_cfinet213.bash ]; then
	echo "	Creating stored procedures..."
	echo "" >>$logfilename
	echo "#" >>$logfilename
	echo "#	Executing script crprocs_cfinet213.bash" >>$logfilename
	echo "#" >>$logfilename
	./crprocs_cfinet213.bash -U $mysqluser -P $mysqlpwd -L $logfilename
fi

#
#	Load initial data
#
if [ -f load_cfinet213.bash ]; then
	echo "	Loading initial data ..."
	echo "" >>$logfilename
	echo "#" >>$logfilename
	echo "#	Executing script load_cfinet213.bash" >>$logfilename
	echo "#" >>$logfilename
	./load_cfinet213.bash -U $mysqluser -P $mysqlpwd -L $logfilename
fi

#
#	Create the database triggers
#
if [ -f crtrg_cfinet213.bash ]; then
	echo "	Creating database triggers ..."
	echo "" >>$logfilename
	echo "#" >>$logfilename
	echo "#	Executing script crtrg_cfinet213.bash" >>$logfilename
	echo "#" >>$logfilename
	./crtrg_cfinet213.bash -U $mysqluser -P $mysqlpwd -L $logfilename
fi

exit 0

