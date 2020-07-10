// Description: Java 11 XML SAX Loader CLI persisting as PostgreSQL for CFInt.

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

package org.msscf.msscf.cfint.CFIntSaxPgSqlLdr;

import org.apache.log4j.*;
import java.io.File;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Properties;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfint.CFIntPgSql.*;
import org.msscf.msscf.cfint.CFIntSaxLoader.*;

public class CFIntSaxPgSqlLdr
	extends CFIntSaxLdr
{
	private static ICFLibMessageLog log = new CFLibConsoleMessageLog();

	// Constructors

	public CFIntSaxPgSqlLdr() {
		super( log );
	}

	// main() entry point

	public static void main( String args[] ) {
		final String S_ProcName = "CFIntSaxPgSqlLdr.main() ";
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
			CFIntConfigurationFile cFIntConfig = new CFIntConfigurationFile();
			String cFIntConfigFileName = homeDir.getPath() + File.separator + ".cfintpgsqlrc";
			cFIntConfig.setFileName( cFIntConfigFileName );
			File cFIntConfigFile = new File( cFIntConfigFileName );
			if( ! cFIntConfigFile.exists() ) {
				cFIntConfig.setDbServer( "127.0.0.1" );
				cFIntConfig.setDbPort( 5432 );
				cFIntConfig.setDbDatabase( "CFINet213" );
				cFIntConfig.setDbUserName( "postgres" );
				cFIntConfig.setDbPassword( "edit-me-please" );
				cFIntConfig.save();
				log.message( S_ProcName + "INFO: Created configuration file " + cFIntConfigFileName + ", please edit configuration and restart." );
				return;
			}
			if( ! cFIntConfigFile.isFile() ) {
				log.message( S_ProcName + "ERROR: Proposed configuration file " + cFIntConfigFileName + " is not a file." );
				return;
			}
			if( ! cFIntConfigFile.canRead() ) {
				log.message( S_ProcName + "ERROR: Permission denied attempting to read configuration file " + cFIntConfigFileName );
				return;
			}
			cFIntConfig.load();
			boolean fastExit = false;
			CFIntClientConfigurationFile cFDbTestClientConfig = new CFIntClientConfigurationFile();
			String cFDbTestClientConfigFileName = homeDir.getPath() + File.separator + ".cfdbtestclientrc";
			cFDbTestClientConfig.setFileName( cFDbTestClientConfigFileName );
			File cFDbTestClientConfigFile = new File( cFDbTestClientConfigFileName );
			if( ! cFDbTestClientConfigFile.exists() ) {
				String cFDbTestKeyStoreFileName = homeDir.getPath() + File.separator + ".msscfjceks";
				cFDbTestClientConfig.setKeyStore( cFDbTestKeyStoreFileName );
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
					log.message( "ERROR: user.name is null or empty" );
					return;
				}
				String deviceName = hostName.replaceAll( "[^\\w]", "_" ).toLowerCase()
					+ "-"
					+ userName.replaceAll( "[^\\w]", "_" ).toLowerCase();
				cFDbTestClientConfig.setDeviceName( deviceName );
				cFDbTestClientConfig.save();
				log.message( S_ProcName + "INFO: Created CFInt client configuration file " + cFDbTestClientConfigFileName );
				fastExit = true;
			}
			if( ! cFDbTestClientConfigFile.isFile() ) {
				log.message( S_ProcName + "ERROR: Proposed client configuration file " + cFDbTestClientConfigFileName + " is not a file." );
				fastExit = true;
			}
			if( ! cFDbTestClientConfigFile.canRead() ) {
				log.message( S_ProcName + "ERROR: Permission denied attempting to read client configuration file " + cFDbTestClientConfigFileName );
				fastExit = true;
			}
			cFDbTestClientConfig.load();

			if( fastExit ) {
				return;
			}

			// Configure logging
			Properties sysProps = System.getProperties();
			sysProps.setProperty( "log4j.rootCategory", "WARN" );
			sysProps.setProperty( "org.apache.commons.logging.Log", "org.apache.commons.logging.impl.Log4JLogger" );

			Logger httpLogger = Logger.getLogger( CFIntSaxPgSqlLdr.class );
			httpLogger.setLevel( Level.WARN );

			ICFIntSchema cFIntSchema = new CFIntPgSqlSchema();
			cFIntSchema.setConfigurationFile( cFIntConfig );
			ICFIntSchemaObj cFIntSchemaObj = new CFIntSchemaObj();
			cFIntSchemaObj.setBackingStore( cFIntSchema );
			CFIntSaxLdr cli = new CFIntSaxPgSqlLdr();
			CFIntSaxLoader loader = cli.getSaxLoader();
			loader.setSchemaObj( cFIntSchemaObj );
			cFIntSchema.connect();
			String url = args[1];
			if( numArgs >= 5 ) {
				cli.setClusterName( args[2] );
				cli.setTenantName( args[3] );
				cli.setSecUserName( args[4] );
			}
			else {
				cli.setClusterName( "default" );
				cli.setTenantName( "system" );
				cli.setSecUserName( "system" );
			}
			loader.setUseCluster( cli.getClusterObj() );
			loader.setUseTenant( cli.getTenantObj() );
			try {
				cFIntSchema.beginTransaction();
				cFIntSchemaObj.setSecCluster( cli.getClusterObj() );
				cFIntSchemaObj.setSecTenant( cli.getTenantObj() );
				cFIntSchemaObj.setSecUser( cli.getSecUserObj() );
				cFIntSchemaObj.setSecSession( cli.getSecSessionObj() );
				CFSecAuthorization auth = new CFSecAuthorization();
				auth.setSecCluster( cFIntSchemaObj.getSecCluster() );
				auth.setSecTenant( cFIntSchemaObj.getSecTenant() );
				auth.setSecSession( cFIntSchemaObj.getSecSession() );
				cFIntSchemaObj.setAuthorization( auth );
				applyLoaderOptions( loader, args[0] );
				if( numArgs >= 5 ) {
					cli.evaluateRemainingArgs( args, 5 );
				}
				else {
					cli.evaluateRemainingArgs( args, 2 );
				}
				loader.parseFile( url );
				cFIntSchema.commit();
				cFIntSchema.disconnect( true );
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
					cFIntSchema.rollback();
					cFIntSchema.disconnect( false );
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
		// There are no extra arguments for the PostgreSQL database instance
		if( args.length > consumed ) {
			log.message( "CFIntSaxPgSqlLdr.evaluateRemainingArgs() WARNING No extra arguments are expected for a RAM database instance, but "
				+ Integer.toString( args.length - consumed )
				+ " extra arguments were specified.  Extra arguments ignored." );
		}
	}

}
