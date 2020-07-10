// Description: Java 11 XML SAX Loader CLI persisting as MS SQL Server Developer Edition for CFInt.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	This file is part of MSS Code Factory.
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	    http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *
 *	Manufactured by MSS Code Factory 2.12
 */

package org.msscf.msscf.cfint.CFIntSaxMSSqlLdr;

import org.apache.log4j.*;
import java.io.File;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.*;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;
import org.msscf.msscf.cfint.CFIntMSSql.*;
import org.msscf.msscf.cfint.CFIntSaxLoader.*;

public class CFIntSaxMSSqlLdr
	extends CFIntSaxLdr
{
	private static ICFLibMessageLog log = new CFLibConsoleMessageLog();

	// Constructors

	public CFIntSaxMSSqlLdr() {
		super( log );
	}

	// main() entry point

	public static void main( String args[] ) {
		final String S_ProcName = "CFIntSaxMSSqlLdr.main() ";
		initConsoleLog();
		int numArgs = args.length;
		if( numArgs >= 2 ) {
			String homeDirName = System.getProperty( "HOME" );
			if( homeDirName == null ) {
				homeDirName = System.getProperty( "user.home" );
				if( homeDirName == null ) {
					log.message( S_ProcName + "ERROR: Home directory not set" );
					return;
				}
			}
			File homeDir = new File( homeDirName );
			if( ! homeDir.exists() ) {
				log.message( S_ProcName + "ERROR: Home directory \"" + homeDirName + "\" does not exist" );
				return;
			}
			if( ! homeDir.isDirectory() ) {
				log.message( S_ProcName + "ERROR: Home directory \"" + homeDirName + "\" is not a directory" );
				return;
			}

			InetAddress localHost;
			try {
				localHost = InetAddress.getLocalHost();
			}
			catch( UnknownHostException e ) {
				localHost = null;
			}
			if( localHost == null ) {
				log.message( S_ProcName + "ERROR: LocalHost is null" );
				return;
			}

			String hostName = localHost.getHostName();
			if( ( hostName == null ) || ( hostName.length() <= 0 ) ) {
				log.message( "ERROR: LocalHost.HostName is null or empty" );
				return;
			}

			String userName = System.getProperty( "user.name" );
			if( ( userName == null ) || ( userName.length() <= 0 ) ) {
				log.message( "ERROR: System property \"user.name\" returned a null or empty string" );
				return;
			}

			boolean fastExit = false;

			// Load or create the client configuration file for resolving device keys
			CFIntClientConfigurationFile cFIntClientConfig = new CFIntClientConfigurationFile();
			String cFIntClientConfigFileName = homeDir.getPath() + File.separator + ".cfdbtestclientrc";
			cFIntClientConfig.setFileName( cFIntClientConfigFileName );
			File cFIntClientConfigFile = new File( cFIntClientConfigFileName );
			if( ! cFIntClientConfigFile.exists() ) {
				String cFIntKeyStoreFileName = homeDir.getPath() + File.separator + ".msscfjceks";
				cFIntClientConfig.setKeyStore( cFIntKeyStoreFileName );
				String deviceName = hostName.replaceAll( "[^\\w]", "_" ).toLowerCase()
				 	+ "-"
				 	+ userName.replaceAll( "[^\\w]", "_" ).toLowerCase();
				cFIntClientConfig.setDeviceName( deviceName );
				cFIntClientConfig.save();
				log.message( S_ProcName + "INFO: Created CFInt client configuration file " + cFIntClientConfigFileName );
				fastExit = true;
			}
			if( ! cFIntClientConfigFile.isFile() ) {
				log.message( S_ProcName + "ERROR: Proposed client configuration file " + cFIntClientConfigFileName + " is not a file." );
				fastExit = true;
			}
			if( ! cFIntClientConfigFile.canRead() ) {
				log.message( S_ProcName + "ERROR: Permission denied attempting to read client configuration file " + cFIntClientConfigFileName );
				fastExit = true;
			}
			cFIntClientConfig.load();

			// Load MSSql-specific configuration file for connecting to database
			CFIntConfigurationFile cFIntConfig = new CFIntConfigurationFile();
			String cFIntConfigFileName = homeDir.getPath() + File.separator + ".cFIntmssqlrc";
			cFIntConfig.setFileName( cFIntConfigFileName );
			File cFIntConfigFile = new File( cFIntConfigFileName );
			if( ! cFIntConfigFile.exists() ) {
				cFIntConfig.setDbServer( hostName );
				cFIntConfig.setNetServerPort( 1433 );
				cFIntConfig.setDbDatabase( "cfinet213" );
				cFIntConfig.setDbUserName( userName );
				cFIntConfig.setDbPassword( "ChangeMe!" );
				cFIntConfig.save();
				log.message( S_ProcName + "INFO: Created CFInt mssql configuration file " + cFIntConfigFileName );
				fastExit = true;
			}

			if( ! cFIntConfigFile.isFile() ) {
				log.message( S_ProcName + "ERROR: Proposed mssql configuration file " + cFIntConfigFileName + " is not a file." );
				fastExit = true;
			}
			if( ! cFIntConfigFile.canRead() ) {
				log.message( S_ProcName + "ERROR: Permission denied attempting to read mssql configuration file " + cFIntConfigFileName );
				fastExit = true;
			}
			cFIntConfig.load();

			// If either configuration file was created, return
			if( fastExit ) {
				return;
			}

			// Configure logging
			Properties sysProps = System.getProperties();
			sysProps.setProperty( "log4j.rootCategory", "WARN" );
			sysProps.setProperty( "org.apache.commons.logging.Log", "org.apache.commons.logging.impl.Log4JLogger" );

			Logger httpLogger = Logger.getLogger( CFIntSaxMSSqlLdr.class );
			httpLogger.setLevel( Level.WARN );

			CFIntSaxLdr cli = new CFIntSaxMSSqlLdr();
			CFIntSaxLoader loader = cli.getSaxLoader();

			applyLoaderOptions( loader, args[0] );
			if( numArgs >= 5 ) {
				cli.evaluateRemainingArgs( args, 5 );
			}
			else {
				cli.evaluateRemainingArgs( args, 2 );
			}

			String useClusterName;
			String useTenantName;
			String useSecUserName;
			if( numArgs >= 5 ) {
				useClusterName = new String( args[2] );
				useTenantName = new String( args[3] );
				useSecUserName = new String( args[4] );
			}
			else {
				useClusterName = new String( "default" );
				useTenantName = new String( "system" );
				useSecUserName = new String( "system" );
			}

			ICFIntSchema cFIntSchema = new CFIntMSSqlSchema();
			cFIntSchema.setConfigurationFile( cFIntConfig );
			cFIntSchema.connect( "system", "system", cFIntConfig.getDbUserName(), cFIntConfig.getDbPassword() );
			cFIntSchema.rollback();
			cFIntSchema.beginTransaction();

			ICFIntSchemaObj cFIntSchemaObj = new CFIntSchemaObj();
			cFIntSchemaObj.setBackingStore( cFIntSchema );
			String url = args[1];

			loader.setSchemaObj( cFIntSchemaObj );

			ICFSecClusterObj cFIntUseCluster = null;
			if( useClusterName.equals( "default" ) ) {
				List<ICFSecSysClusterObj> cFIntSysClusterList = cFIntSchemaObj.getSysClusterTableObj().readAllSysCluster();
				Iterator<ICFSecSysClusterObj> cFIntSysClusterIter = cFIntSysClusterList.iterator();
				ICFSecSysClusterObj cFIntSysClusterObj = null;
				while( cFIntSysClusterIter.hasNext() ) {
					cFIntSysClusterObj = cFIntSysClusterIter.next();
					break;
				}
				if( cFIntSysClusterObj == null ) {
					log.message( S_ProcName + "WARN: Could not find a SysCluster instance in the database, defaulting to system cluster" );
					useClusterName = new String( "system" );
					cFIntUseCluster = cFIntSchemaObj.getClusterTableObj().readClusterByUDomNameIdx( useClusterName );
					if( cFIntUseCluster == null ) {
						log.message( S_ProcName + "ERROR: Could not resolve system cluster" );
						fastExit = true;
					}
				}
				else {
					cFIntUseCluster = cFIntSysClusterObj.getRequiredContainerCluster();
					if( cFIntUseCluster == null ) {
						log.message( S_ProcName + "ERROR: Could not resolve SysCluster.RequiredContainerCluster" );
						fastExit = true;
					}
					else {
						useClusterName = cFIntUseCluster.getRequiredFullDomName();
					}
				}
			}
			else {
				cFIntUseCluster = cFIntSchemaObj.getClusterTableObj().readClusterByUDomNameIdx( useClusterName );
				if( cFIntUseCluster == null ) {
					log.message( S_ProcName + "ERROR: Could not resolve Cluster \"" + useClusterName + "\"" );
					fastExit = true;
				}
			}

			ICFSecTenantObj cFIntUseTenant = null;
			if( cFIntUseCluster != null ) {
				cFIntUseTenant = cFIntSchemaObj.getTenantTableObj().readTenantByUNameIdx( cFIntUseCluster.getRequiredId(), useTenantName );
				if( cFIntUseTenant == null ) {
					log.message( S_ProcName + "ERROR: Could not resolve Tenant \"" + cFIntUseCluster.getRequiredFullDomName() + "." + useTenantName + "\"" );
					fastExit = true;
				}
			}
			else {
				log.message( S_ProcName + "WARN: Cannot resolve Tenant \"" + useTenantName + "\" without a cluster" );
				fastExit = true;
			}

			ICFSecSecUserObj cFIntSecUserSystem = cFIntSchemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );
			if( cFIntSecUserSystem == null ) {
				log.message( S_ProcName + "ERROR: Could not resolve SecUser login \"system\"" );
				fastExit = true;
			}

			ICFSecSecUserObj cFIntUseSecUser = null;
			cFIntUseSecUser = cFIntSchemaObj.getSecUserTableObj().readSecUserByULoginIdx( useSecUserName );
			if( cFIntUseSecUser == null ) {
				log.message( S_ProcName + "ERROR: Could not resolve SecUser login \"" + useSecUserName + "\"" );
				fastExit = true;
			}

			cFIntSchema.commit();
			cFIntSchema.disconnect( false );

			// If any required data could not be resolved, return
			if( fastExit ) {
				return;
			}

			cFIntSchema.connect( useClusterName, useTenantName, cFIntConfig.getDbUserName(), cFIntConfig.getDbPassword() );

			cFIntUseCluster = cFIntSchemaObj.getClusterTableObj().readClusterByUDomNameIdx( useClusterName );
			if( cFIntUseCluster == null ) {
				log.message( S_ProcName + "ERROR: Could not resolve Cluster \"" + useClusterName + "\"" );
				fastExit = true;
			}

			if( cFIntUseCluster != null ) {
				cFIntUseTenant = cFIntSchemaObj.getTenantTableObj().readTenantByUNameIdx( cFIntUseCluster.getRequiredId(), useTenantName );
				if( cFIntUseTenant == null ) {
					log.message( S_ProcName + "ERROR: Could not resolve Tenant \"" + cFIntUseCluster.getRequiredFullDomName() + "." + useTenantName + "\"" );
					fastExit = true;
				}
			}
			else {
				log.message( S_ProcName + "WARN: Cannot resolve Tenant \"" + useTenantName + "\" without a Cluster" );
				cFIntUseTenant = null;
			}

			cFIntUseSecUser = cFIntSchemaObj.getSecUserTableObj().readSecUserByULoginIdx( useSecUserName );
			if( cFIntUseSecUser == null ) {
				log.message( S_ProcName + "ERROR: Could not resolve SecUser login \"" + useSecUserName + "\"" );
				fastExit = true;
			}

			// If any data could not be resolved, rollback, disconnect, and return
			if( fastExit ) {
				cFIntSchema.rollback();
				cFIntSchema.disconnect( false );
				return;
			}

			cFIntSchema.commit();

			cFIntSchema.beginTransaction();

			cFIntSchemaObj.setSecCluster( cFIntUseCluster );
			cFIntSchemaObj.setSecTenant( cFIntUseTenant );
			cFIntSchemaObj.setSecUser( cFIntUseSecUser );


			CFSecAuthorization auth = new CFSecAuthorization();
			auth.setSecCluster( cFIntUseCluster );
			auth.setSecTenant( cFIntUseTenant );
			cFIntSchemaObj.setAuthorization( auth );

			cli.setClusterName( useClusterName );
			cli.setTenantName( useTenantName );
			cli.setSecUserName( useSecUserName );

			ICFSecSecSessionObj cFIntSecSession = cli.getSecSessionObj();
			cFIntSchemaObj.setSecSession( cFIntSecSession );
			auth.setSecSession( cFIntSecSession );

			loader.setUseCluster( cFIntUseCluster );
			loader.setUseTenant( cFIntUseTenant );

			cFIntSchema.commit();

			try {
				cFIntSchema.beginTransaction();
				loader.parseFile( url );
				cFIntSchema.commit();
				cFIntSchemaObj.logout();
				cFIntSchema.disconnect( false );
			}
			catch( Exception e ) {
				log.message( S_ProcName + "EXCEPTION: Could not parse XML file \"" + url + "\": " + e.getMessage() );
				e.printStackTrace( System.out );
			}
			catch( Error e ) {
				log.message( S_ProcName + "ERROR: Could not parse XML file \"" + url + "\": " + e.getMessage() );
				e.printStackTrace( System.out );
			}
			finally {
				if( cFIntSchema.isConnected() ) {
					try {
						cFIntSchema.rollback();
					}
					catch( Exception e ) {
					}
					catch( Error e ) {
					}
					try {
						cFIntSchemaObj.logout();
					}
					catch( Exception e ) {
					}
					catch( Error e ) {
					}
					try {
						cFIntSchema.disconnect( false );
					}
					catch( Exception e ) {
					}
					catch( Error e ) {
					}
				}
			}
		}
		else {
			log.message( S_ProcName + "ERROR: Expected at least two argument specifying the loader options and the name of the XML file to parse.  The first argument may be empty." );
		}
	}

	// Initialize the console log

	protected static void initConsoleLog() {
//		Layout layout = new PatternLayout(
//				"%d{ISO8601}"		// Start with a timestamp
//			+	" %-5p"				// Include the severity
//			+	" %C.%M"			// pkg.class.method()
//			+	" %F[%L]"			// File[lineNumber]
//			+	": %m\n" );			// Message text
//		BasicConfigurator.configure( new ConsoleAppender( layout, "System.out" ) );
	}

	// Evaluate remaining arguments

	public void evaluateRemainingArgs( String[] args, int consumed ) {
		// There are no extra arguments for a database instance
		if( args.length > consumed ) {
			log.message( "CFIntSaxMSSqlLdr.evaluateRemainingArgs() WARNING No extra arguments are expected for a RAM database instance, but "
				+ Integer.toString( args.length - consumed )
				+ " extra arguments were specified.  Extra arguments ignored." );
		}
	}

}
