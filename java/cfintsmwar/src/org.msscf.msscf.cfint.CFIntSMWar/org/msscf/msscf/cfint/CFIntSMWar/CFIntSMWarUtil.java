
// Description: Java 11 Sec Manager Utilities

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

package org.msscf.msscf.cfint.CFIntSMWar;

import java.io.*;
import java.security.*;
import java.util.*;

import javax.mail.*;
import javax.mail.internet.*;
import javax.naming.*;

import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

public class CFIntSMWarUtil {
	private static final long serialVersionUID = 1L;

	protected String smtpUsername = null;
	protected String smtpPassword = null;

	public CFIntSMWarUtil() {
		super();
	}

	public void sendEMailToUser(
		ICFSecSecUserObj toUser,
		String msgSubject,
		String msgBody )
	throws
		IOException,
		MessagingException,
		NamingException
	{

		final String S_ProcName = "sendEMailToUser";

		Properties props = System.getProperties();

		Context ctx = new InitialContext();

		String smtpHost = (String)ctx.lookup( "java:comp/env/CFIntSmtpHost");
		if( ( smtpHost == null ) || ( smtpHost.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"JNDI lookup for CFIntSmtpHost" );
		}

		String smtpStrPort = (String)ctx.lookup( "java:comp/env/CFIntSmtpPort");
		if( ( smtpStrPort == null ) || ( smtpStrPort.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"JNDI lookup for CFIntSmtpPort" );
		}

		int smtpPort = Integer.parseInt( smtpStrPort );

		String smtpEnableSMTPS = (String)ctx.lookup( "java:comp/env/CFIntSmtpEnableSMTPS");
		if( ( smtpEnableSMTPS == null ) || ( smtpEnableSMTPS.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"JNDI lookup for CFIntSmtpEnableSMTPS" );
		}

		boolean enableSMTPS;
		if( smtpEnableSMTPS.equals( "true" ) ) {
			enableSMTPS = true;
		}
		else if( smtpEnableSMTPS.equals( "false" ) ) {
			enableSMTPS = false;
		}
		else {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"CFIntSmtpEnableSMTPS must be true or false, not \"" + smtpEnableSMTPS + "\"" );
		}

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

		Session emailSess = Session.getInstance( props,
			new Authenticator() {
				protected PasswordAuthentication getPasswordAuthentication() {
					return new PasswordAuthentication( smtpUsername, smtpPassword );
				}
			} );

		MimeMessage msg = new MimeMessage( emailSess );
		msg.setFrom( new InternetAddress( smtpEmailFrom ) );
		InternetAddress mailTo[] = InternetAddress.parse( toUser.getRequiredEMailAddress(), false );
		msg.setRecipient( Message.RecipientType.TO, mailTo[0] );
		msg.setSubject( ( msgSubject != null ) ? msgSubject : "No subject" );
		msg.setSentDate( new Date() );
		msg.setContent( msgBody, "text/html" );
		msg.saveChanges();

		if( enableSMTPS ) {
			// As per suggestion fromm http://stackoverflow.com/questions/10005937/javamail-sender-address-rejected-access-denied
			Transport transport = emailSess.getTransport( "smtps" );
			transport.connect( smtpHost, smtpPort, smtpUsername, smtpPassword );
			transport.sendMessage( msg, msg.getAllRecipients() );
			transport.close();
		}
		else {
			Transport.send( msg );
		}
	}

}
