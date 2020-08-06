@ECHO OFF
REM	@(#) dbcreate/cfint/mssql/crdb_cfinet213.bat
REM
REM	org.msscf.msscf.CFInt
REM
REM	Copyright (c) 2020 Mark Stephen Sobkow
REM	
REM	MSS Code Factory CFInt 2.13 Internet Essentials
REM	
REM	Copyright 2020 Mark Stephen Sobkow
REM	
REM		This file is part of MSS Code Factory.
REM	
REM		MSS Code Factory is available under dual commercial license from Mark Stephen
REM		Sobkow, or under the terms of the GNU General Public License, Version 3
REM		or later.
REM	
REM	    MSS Code Factory is free software: you can redistribute it and/or modify
REM	    it under the terms of the GNU General Public License as published by
REM	    the Free Software Foundation, either version 3 of the License, or
REM	    (at your option) any later version.
REM	
REM	    MSS Code Factory is distributed in the hope that it will be useful,
REM	    but WITHOUT ANY WARRANTY; without even the implied warranty of
REM	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM	    GNU General Public License for more details.
REM	
REM	    You should have received a copy of the GNU General Public License
REM	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
REM	
REM	Donations to support MSS Code Factory can be made at
REM	https://www.paypal.com/paypalme2/MarkSobkow
REM	
REM	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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

if exist %logfilename% (
	DEL %logfilename%
)


REM
REM	Drop the database, if it exists
REM
if exist drdb_cfinet213.tsql (
	echo 	Dropping any existing database 'cfinet213' ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script drdb_cfinet213.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <drdb_cfinet213.tsql >>%logfilename%
)

REM
REM	Create the database owner
REM
if exist crdb_owner.tsql (
	echo 	Creating database owner 'cfinet213' ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_owner.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_owner.tsql >>%logfilename%
)

REM
REM	Create the database logins
REM
if exist crdb_logins.tsql (
	echo 	Creating database logins ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_logins.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_logins.tsql >>%logfilename%
)

REM
REM	Create the database groups
REM
if exist crdb_groups.tsql (
	echo 	Creating database groups ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_groups.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_groups.tsql >>%logfilename%
)

REM
REM	Create the database roles
REM
if exist crdb_roles.tsql (
	echo 	Creating database roles ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_roles.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_roles.tsql >>%logfilename%
)

REM
REM	Create the database users
REM
if exist crdb_users.tsql (
	echo 	Creating database users ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_users.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_users.tsql >>%logfilename%
)

REM
REM	Create the database defaults
REM
if exist crdb_defaults.tsql (
	echo 	Creating database defaults ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_defaults.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_defaults.tsql >>%logfilename%
)

REM
REM	Create the database
REM
if exist crdb_cfinet213.tsql (
	echo 	Creating database cfinet213 ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_cfinet213.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_cfinet213.tsql >>%logfilename%
)

REM
REM	Create the database rules
REM
if exist crdb_rules.tsql (
	echo 	Creating database rules ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_rules.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_rules.tsql >>%logfilename%
)

REM
REM	Create the database types
REM
if exist crdb_types.tsql (
	echo 	Creating database types ...
	echo REM >>%logfilename%
	echo REM	Executing SQL script crdb_types.tsql >>%logfilename%
	echo REM >>%logfilename%
	%cmddb% <crdb_types.tsql >>%logfilename%
)

REM
REM	Create the database tables
REM
if exist crtbl_cfinet213.bat (
	echo 	Creating database tables ...
	echo REM >>%logfilename%
	echo REM	Executing script crtbl_cfinet213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL crtbl_cfinet213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

REM
REM	Create the database indexes
REM
if exist cridx_cfinet213.bat (
	echo 	Creating database indexes ...
	echo REM >>%logfilename%
	echo REM	Executing script cridx_cfinet213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL cridx_cfinet213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

REM
REM	Create the database relations
REM
if exist crrel_cfinet213.bat (
	echo 	Creating database relations ...
	echo REM >>%logfilename%
	echo REM	Executing script crrel_cfinet213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL crrel_cfinet213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

REM
REM	Create the database stored procedures
REM
if exist crprocs_cfinet213.bat (
	echo 	Creating database stored procedures ...
	echo REM >>%logfilename%
	echo REM	Executing script crprocs_cfinet213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL crprocs_cfinet213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

REM
REM	Load initial data
REM
if exist load_cfinet213.bat (
	echo 	Loading initial data ...
	echo REM >>%logfilename%
	echo REM	Executing script load_cfinet213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL load_cfinet213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

REM
REM	Create the database triggers
REM
if exist crtrg_cfinet213.bat (
	echo 	Creating database triggers ...
	echo REM >>%logfilename%
	echo REM	Executing script crtrg_cfinet213.bat >>%logfilename%
	echo REM >>%logfilename%
	CALL crtrg_cfinet213.bat %mssqlsrv% %mssqluser% %mssqlpwd% %logfilename%
)

PAUSE