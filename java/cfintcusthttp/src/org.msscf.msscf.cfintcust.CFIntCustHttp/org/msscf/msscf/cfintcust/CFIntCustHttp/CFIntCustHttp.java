// Description: Java 13 Cust JavaFX Client-Server GUI persisting via HTTP.

/*
 *	MSS Code Factory Int Cust JavaFX GUI HTTP Client
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
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
 */

package org.msscf.msscf.cfintcust.CFIntCustHttp;

import org.apache.log4j.*;

import java.io.File;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Properties;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.CFConsole;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfint.CFIntJavaFX.CFIntJavaFXSchema;
import org.msscf.msscf.cfint.CFIntJavaFX.ICFIntJavaFXSchema;
import org.msscf.msscf.cfint.CFIntObj.*;
import org.msscf.msscf.cfint.CFIntXMsgClnt.*;
import org.msscf.msscf.cfintcust.CFIntCust.CFIntCustMainPane;
import org.msscf.msscf.cfintcust.CFIntCust.CFIntCustSchema;
import org.msscf.msscf.cfintcust.CFIntCust.ICFIntCustSchema;

public class CFIntCustHttp
extends Application
{
	private static ICFLibMessageLog log = new CFLibConsoleMessageLog();
	protected static ICFIntSchemaObj schema = null;
	protected static ICFIntCustSchema custSchema = null;

	protected static CFIntXMsgClntHttpSchema httpClientSchema = null;

	// Constructors

	public CFIntCustHttp() {
	}

	@Override public void start( Stage stage ) {

		//CFIntCustMainWindow mainWindow = new CFIntCustMainWindow( custSchema );

		//mainWindow.requestFocus();

		CFIntCustMainPane mainPane = new CFIntCustMainPane( custSchema );
		mainPane.setCustSchema( custSchema );
		Scene scene = new Scene( mainPane );

		stage.setTitle( "Code Factory Int Cust JavaFX HTTP Client" );
		stage.setMinHeight( 900.0 );
		stage.setMinWidth( 700.0 );
		stage.setScene( scene );
		stage.sizeToScene();
		stage.show();
		stage.requestFocus();
	}

	// Accessors

	public static ICFIntCustSchema getCustSchema() {
		return( custSchema );
	}

	public static void setCustSchema( ICFIntCustSchema argSchema ) {
		custSchema = argSchema;
	}

	// CFIntXMsgClntHttpSchema accessors are needed to complete the wiring of the direct request invoker instance
	// that has been bound by the main() to a PostgreSQL persistance implementation.

	public static CFIntXMsgClntHttpSchema getXMsgClntHttpSchema() {
		return( httpClientSchema );
	}

	public static void setXMsgClntHttpSchema( CFIntXMsgClntHttpSchema invoker ) {
		httpClientSchema = invoker;
	}

	public static ICFIntSchemaObj getSchema() {
		return( schema );
	}

	public static void setSchema( ICFIntSchemaObj argSchema ) {
		schema = argSchema;
	}

	// main() entry point

	public static void main( String args[] ) {
		final String S_ProcName = "CFIntCustHttp.main() ";
		initConsoleLog();

		if( args.length >= 1 ) {
			if( args[0].equals( "trace" ) ) {
				CFConsole.setLogExceptionsToSystem( true );
			}
			else if( args[0].equals( "notrace" ) ) {
				CFConsole.setLogExceptionsToSystem( false );
			}
			else {
				log.message( S_ProcName + "ERROR: Argument if specified must be either \"trace\" or \"notrace\"" );
				return;
			}
		}
		else {
			CFConsole.setLogExceptionsToSystem( false );
		}

		boolean fastExit = false;

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

		CFIntClientConfigurationFile cFAccClientConfig = new CFIntClientConfigurationFile();
		String cFAccClientConfigFileName = homeDir.getPath() + File.separator + ".cfintclientrc";
		cFAccClientConfig.setFileName( cFAccClientConfigFileName );
		File cFAccClientConfigFile = new File( cFAccClientConfigFileName );
		if( ! cFAccClientConfigFile.exists() ) {
			String cFAccKeyStoreFileName = homeDir.getPath() + File.separator + ".msscfjceks";
			cFAccClientConfig.setKeyStore( cFAccKeyStoreFileName );
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
			cFAccClientConfig.setDeviceName( deviceName );
			cFAccClientConfig.save();
			log.message( S_ProcName + "INFO: Created CFInt client configuration file " + cFAccClientConfigFileName );
			fastExit = true;
		}
		if( ! cFAccClientConfigFile.isFile() ) {
			log.message( S_ProcName + "ERROR: Proposed client configuration file " + cFAccClientConfigFileName + " is not a file." );
			fastExit = true;
		}
		if( ! cFAccClientConfigFile.canRead() ) {
			log.message( S_ProcName + "ERROR: Permission denied attempting to read client configuration file " + cFAccClientConfigFileName );
			fastExit = true;
		}
		cFAccClientConfig.load();

		if( fastExit ) {
			return;
		}

		// Configure logging
		Properties sysProps = System.getProperties();
		sysProps.setProperty( "log4j.rootCategory", "WARN" );
		sysProps.setProperty( "org.apache.commons.logging.Log", "org.apache.commons.logging.impl.Log4JLogger" );

		Logger httpLogger = Logger.getLogger( CFIntCustHttp.class );
		httpLogger.setLevel( Level.WARN );

		// The Invoker and it's implementation
		CFIntXMsgClntHttpSchema invoker = new CFIntXMsgClntHttpSchema();

		// And now for the client side cache implementation that invokes it
		ICFIntSchemaObj clientSchemaObj = new CFIntSchemaObj() {
			public void logout() {
				CFIntXMsgClntHttpSchema invoker = (CFIntXMsgClntHttpSchema)getBackingStore();
				try {
					invoker.logout( getAuthorization() );
				}
				catch( RuntimeException e ) {
				}
				setAuthorization( null );
			}
		};
		clientSchemaObj.setBackingStore( invoker );
		// And stitch the response handler to reference our client instance
		invoker.setResponseHandlerSchemaObj( clientSchemaObj );
		// And now we can stitch together the CLI to the SAX loader code
		CFIntCustHttp cli = new CFIntCustHttp();
		cli.setXMsgClntHttpSchema( invoker );
		cli.setSchema( clientSchemaObj );

		ICFIntCustSchema myCustSchema = new CFIntCustSchema();
		myCustSchema.setClientConfigurationFile( cFAccClientConfig );
		myCustSchema.setSchema( clientSchemaObj );
		myCustSchema.setClusterName( "system" );
		myCustSchema.setTenantName( "system" );
		myCustSchema.setSecUserName( "system" );
		cli.setCustSchema( myCustSchema );

		ICFIntJavaFXSchema javafxSchema = new CFIntJavaFXSchema();
		javafxSchema.setSchema( clientSchemaObj );
		myCustSchema.setJavaFXSchema( javafxSchema );

		Application.launch( args );
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

}
