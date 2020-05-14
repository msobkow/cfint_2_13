@echo off
REM
REM	@(#) dbcreate/cfint/mysql/crschema_cfinet213.bat
$ScriptLicenseBat$
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

echo Dropping any existing schema CFINet213 for %mysqluser%
echo Dropping any existing schema CFINet213 for %mysqluser% >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% --execute="drop schema cfinet213" >>%logfilename% 2>&1

echo Creating schema CFINet213 for %mysqluser%
echo Creating schema CFINet213 %mysqluser% >>%logfilename%
mysql -v -u %mysqluser% --password=%mysqlpwd% --execute="create schema cfinet213" >>%logfilename% 2>&1


REM
REM	Create the database tables
REM
echo 	Creating database tables ...
echo  >>%logfilename%
echo # >>%logfilename%
echo #	Executing script crtbl_cfinet213.bash >>%logfilename%
echo # >>%logfilename%
call crtbl_cfinet213.bat %mysqluser% %mysqlpwd% %logfilename%

REM
REM	Create the database indexes
REM
echo 	Creating database indexes ...
echo # >>%logfilename%
echo #	Executing script cridx_cfinet213.bash >>%logfilename%
echo # >>%logfilename%
call cridx_cfinet213.bat %mysqluser% %mysqlpwd% %logfilename%

REM
REM	Create the database relations
REM
echo 	Creating database relations ...
echo  >>%logfilename%
echo # >>%logfilename%
echo #	Executing script crrel_cfinet213.bash >>%logfilename%
echo # >>%logfilename%
call crrel_cfinet213.bat %mysqluser% %mysqlpwd% %logfilename%

REM
REM	Create the stored procedureds
REM
echo 	Creating stored procedures...
echo  >>%logfilename%
echo # >>%logfilename%
echo #	Executing script crprocs_cfinet213.bash >>%logfilename%
echo # >>%logfilename%
call crprocs_cfinet213.bat %mysqluser% %mysqlpwd% %logfilename%

pause
