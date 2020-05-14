
// Description: Java 11 XMsg Server Application Listener

/*
 *	com.github.msobkow.CFInt
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

package com.github.msobkow.cfint.CFIntXMsgSrvWar;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.security.*;
import java.security.cert.Certificate;
import java.security.cert.CertificateException;
import java.util.Date;
import java.util.Properties;

import javax.mail.*;
import javax.mail.internet.*;
import javax.naming.*;
import javax.servlet.*;
import javax.servlet.annotation.WebListener;

import com.sun.mail.smtp.SMTPTransport;

import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.Tip.CFTipServerInfo;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfint.CFInt.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFIntObj.*;

/**
 * Application Lifecycle Listener implementation class CFIntPgSqlWARApplicationListener
 *
 */
@WebListener
public class CFIntXMsgSrvWarApplicationListener implements ServletContextListener {
	protected String smtpUsername = null;
	protected String smtpPassword = null;
	protected volatile static PublicKey publicKey = null;
	protected volatile static PrivateKey privateKey = null;

	/**
	 * Default constructor. 
	 */
	public CFIntXMsgSrvWarApplicationListener() {
	}

	@Override
	public void contextDestroyed(ServletContextEvent arg0) {
	}

	private volatile static CFTipServerInfo serverInfo = null;

	public static CFTipServerInfo getServerInfo() {
		final String S_ProcName = "getServerInfo";
		if( serverInfo == null ) {
			serverInfo = new CFTipServerInfo();
			serverInfo.setSchemaName( "CFInt" );
			serverInfo.setSchemaDescr( "CFInt database instance" );
			serverInfo.addAltSchema( "CFSec", "CFSec database instance" );
			if( privateKey != null ) {
				try {
					serverInfo.setServerKeys( publicKey, privateKey );
				}
				catch( Exception e ) {
					throw new CFLibRuntimeException( CFIntXMsgSrvWarApplicationListener.class,
						S_ProcName,
						"Caught " + e.getClass().getName() + " -- " + e.getMessage(),
						e );
				}
			}
		}
		return( serverInfo );
	}

	public static PublicKey getPublicKey() {
		return( publicKey );
	}

	public static PrivateKey getPrivateKey() {
		return( privateKey );
	}

	@Override
	public void contextInitialized(ServletContextEvent arg0) {
		final String S_ProcName = "contextInitialized";

		Properties props = System.getProperties();
		if( null == CFIntSchemaPool.getSchemaPool() ) {
			try {
				Context ctx = new InitialContext();
				String poolClassName = (String)ctx.lookup( "java:comp/env/CFIntPoolClass");
				if( ( poolClassName == null ) || ( poolClassName.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"JNDI lookup for CFIntPoolClass" );
				}

				Class<?> poolClass = Class.forName( poolClassName );
				if( poolClass == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"CFIntPoolClass \"" + poolClassName + "\" not found." );
				}

				Object obj = null;
				try {
					obj = poolClass.getDeclaredConstructor().newInstance();
				}
				catch( InvocationTargetException e ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Mapped InvocationTargetException poolClass declared constructor threw an exception",
						e );
				}
				catch( NoSuchMethodException e ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Mapped NoSuchMethodException poolClass has no declared constructor",
						e );
				}
				if( obj instanceof CFIntSchemaPool ) {
					CFIntSchemaPool newPool = (CFIntSchemaPool)obj;
					newPool.setConfigurationFile( null );
					newPool.setJndiName( "java:comp/env/CFIntConnection" );
					CFIntSchemaPool.setSchemaPool( newPool );
				}
				else {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Problems constructing an instance of " + poolClassName );
				}

				String smtpHost = (String)ctx.lookup( "java:comp/env/CFIntSmtpHost");
				if( ( smtpHost == null ) || ( smtpHost.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"JNDI lookup for CFIntSmtpHost" );
				}
				props.setProperty( "mail.smtp.host", smtpHost );

				String smtpStartTLS = (String)ctx.lookup( "java:comp/env/CFIntSmtpStartTLS");
				if( ( smtpHost == null ) || ( smtpHost.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"JNDI lookup for CFIntSmtpStartTLS" );
				}
				props.setProperty( "mail.smtp.starttls.enable", smtpStartTLS );

				String smtpSocketFactoryClass = (String)ctx.lookup( "java:comp/env/CFIntSmtpSocketFactoryClass");
				if( ( smtpSocketFactoryClass == null ) || ( smtpSocketFactoryClass.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"JNDI lookup for CFIntSmtpSocketFactoryClass" );
				}
				props.setProperty( "mail.smtp.socketFactory.class", smtpSocketFactoryClass );

				props.setProperty( "mail.smtp.socketFactory.fallback", "false" );

				String smtpPort = (String)ctx.lookup( "java:comp/env/CFIntSmtpPort");
				if( ( smtpPort == null ) || ( smtpPort.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"JNDI lookup for CFIntSmtpPort" );
				}
				props.setProperty( "mail.smtp.port", smtpPort );
				props.setProperty( "mail.smtp.socketFactory.port", smtpPort );

				props.setProperty( "mail.smtps.auth", "true" );

				props.put( "mail.smtps.quitwait", "false" );

				String smtpEmailFrom = (String)ctx.lookup( "java:comp/env/CFIntSmtpEmailFrom");
				if( ( smtpEmailFrom == null ) || ( smtpEmailFrom.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"JNDI lookup for CFIntSmtpEmailFrom" );
				}

				smtpUsername = (String)ctx.lookup( "java:comp/env/CFIntSmtpUsername");
				if( ( smtpUsername == null ) || ( smtpUsername.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"JNDI lookup for CFIntSmtpUsername" );
				}

				smtpPassword = (String)ctx.lookup( "java:comp/env/CFIntSmtpPassword");
				if( ( smtpPassword == null ) || ( smtpPassword.length() <= 0 ) ) {
					throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"JNDI lookup for CFIntSmtpPassword" );
				}

				String serverKeyStore;
				try {
					serverKeyStore = (String)ctx.lookup( "java:comp/env/CFIntServerKeyStore");
				}
				catch( NamingException e ) {
					serverKeyStore = null;
				}

				String keyStorePassword;
				try {
					keyStorePassword = (String)ctx.lookup( "java:comp/env/CFIntKeyStorePassword");
				}
				catch( NamingException e ) {
					keyStorePassword = null;
				}

				String keyName;
				try {
					keyName = (String)ctx.lookup( "java:comp/env/CFIntKeyName");
				}
				catch( NamingException e ) {
					keyName = null;
				}

				String keyPassword;
				try {
					keyPassword = (String)ctx.lookup( "java:comp/env/CFIntKeyPassword");
				}
				catch( NamingException e ) {
					keyPassword = null;
				}

				if( ( ( serverKeyStore != null ) && ( serverKeyStore.length() > 0 ) )
				 && ( keyStorePassword != null )
				 && ( ( keyName != null ) && ( keyName.length() > 0 ) )
				 && ( keyPassword != null ) )
				{
					KeyStore keyStore = null;
					File keystoreFile = new File( serverKeyStore );
					if( ! keystoreFile.exists() ) {
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"CFIntServerKeyStore file \"" + serverKeyStore + "\" does not exist." );
					}
					else if( ! keystoreFile.isFile() ) {
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"CFIntServerKeyStore file \"" + serverKeyStore + "\" is not a file." );
					}
					else if( ! keystoreFile.canRead() ) {
						throw new CFLibUsageException( getClass(),
							S_ProcName,
							"Permission denied attempting to read CFIntServerKeyStore file \"" + serverKeyStore + "\"." );
					}

					try {
						keyStore = KeyStore.getInstance( "jceks" );
						char[] caPassword = keyStorePassword.toCharArray();
						FileInputStream input = new FileInputStream( serverKeyStore );
						keyStore.load( input, caPassword );
						input.close();
						Certificate publicKeyCertificate = keyStore.getCertificate( keyName );
						if( publicKeyCertificate == null ) {
							throw new CFLibUsageException( getClass(),
								S_ProcName,
								"Could not read CFIntKeyName \"" + keyName + "\" from CFIntServerKeyStore file \"" + serverKeyStore + "\"." );
						}
						publicKey = publicKeyCertificate.getPublicKey();
						char[] caKeyPassword = keyPassword.toCharArray();
						Key key = keyStore.getKey( keyName, caKeyPassword );
						if( key instanceof PrivateKey ) {
							privateKey = (PrivateKey)key;
						}
						else {
							throw new CFLibUnsupportedClassException( getClass(),
								S_ProcName,
								"key",
								key,
								"PrivateKey" );
						}

						getServerInfo();
					}
					catch( CertificateException x ) {
						publicKey = null;
						privateKey = null;
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Could not open keystore due to CertificateException -- " + x.getMessage(),
							x );
					}
					catch( IOException x ) {
						publicKey = null;
						privateKey = null;
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Could not open keystore due to IOException -- " + x.getMessage(),
							x );
					}
					catch( KeyStoreException x ) {
						publicKey = null;
						privateKey = null;
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Could not open keystore due to KeyStoreException -- " + x.getMessage(),
							x );
					}
					catch( NoSuchAlgorithmException x ) {
						publicKey = null;
						privateKey = null;
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Could not open keystore due to NoSuchAlgorithmException -- " + x.getMessage(),
							x );
					}
					catch( UnrecoverableKeyException x ) {
						publicKey = null;
						privateKey = null;
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Could not access key due to UnrecoverableKeyException -- " + x.getMessage(),
							x );
					}
					catch( RuntimeException x ) {
						publicKey = null;
						privateKey = null;
						throw x;
					}
				}
				else if( ( serverKeyStore != null )
				 || ( keyStorePassword != null )
				 || ( keyName != null )
				 || ( keyPassword != null ) )
				{
					publicKey = null;
					privateKey = null;
					throw new CFLibUsageException( getClass(),
						S_ProcName,
						"All or none of CFIntServerKeyStore, "
							+ "CFIntKeyStorePassword, "
							+ "CFIntKeyName, and "
							+ "CFIntKeyPassword must be configured" );
				}
				else {
					getServerInfo();
					try {
						serverInfo.initServerKeys();
					}
					catch( Exception x ) {
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Caught " + x.getClass().getName() + " during initServerKeys() -- " + x.getMessage(),
							x );
					}
				}
			}
			catch( ClassNotFoundException e ) {
				publicKey = null;
				privateKey = null;
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught ClassNotFoundException -- " + e.getMessage(),
					e );
			}
			catch( IllegalAccessException e ) {
				publicKey = null;
				privateKey = null;
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught IllegalAccessException trying to construct newInstance() -- " + e.getMessage(),
					e );
			}
			catch( InstantiationException e ) {
				publicKey = null;
				privateKey = null;
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught InstantiationException trying to construct newInstance() -- " + e.getMessage(),
					e );
			}
			catch( NamingException e ) {
				publicKey = null;
				privateKey = null;
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught NamingException -- " + e.getMessage(),
					e );
			}
		}
	}
}