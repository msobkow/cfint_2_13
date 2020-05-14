
// Description: Java 11 Sec Manager Application Listener

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

package com.github.msobkow.cfint.CFIntSMWar;

import java.lang.reflect.InvocationTargetException;
import java.security.Security;
import java.util.Date;
import java.util.Properties;

import javax.mail.*;
import javax.mail.internet.*;
import javax.naming.*;
import javax.servlet.*;
import javax.servlet.annotation.WebListener;

import com.sun.mail.smtp.SMTPTransport;

import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfint.CFInt.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFIntObj.*;

/**
 * Application Lifecycle Listener implementation class CFIntPgSqlWARApplicationListener
 *
 */
@WebListener
public class CFIntSMWarApplicationListener implements ServletContextListener {
	protected String smtpUsername = null;
	protected String smtpPassword = null;

	/**
	 * Default constructor. 
	 */
	public CFIntSMWarApplicationListener() {
	}

	@Override
	public void contextDestroyed(ServletContextEvent arg0) {
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

			}
			catch( ClassNotFoundException e ) {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught ClassNotFoundException -- " + e.getMessage(),
					e );
			}
			catch( IllegalAccessException e ) {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught IllegalAccessException trying to construct newInstance() -- " + e.getMessage(),
					e );
			}
			catch( InstantiationException e ) {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught InstantiationException trying to construct newInstance() -- " + e.getMessage(),
					e );
			}
			catch( NamingException e ) {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Caught NamingException -- " + e.getMessage(),
					e );
			}
		}
	}
}