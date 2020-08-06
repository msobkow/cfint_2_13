
// Description: Java 11 Sec Manager Create New Account Servlet

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

package org.msscf.msscf.cfint.CFIntSMWar;

import java.io.IOException;
import java.io.PrintWriter;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Calendar;
import java.util.Date;
import java.util.Properties;
import java.util.UUID;

import javax.mail.*;
import javax.mail.internet.*;
import javax.naming.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/**
 * Servlet implementation class CFIntSMWarCreateNewAccountHtml
 */
@WebServlet("/CFIntSMWarCreateNewAccountHtml")
public class CFIntSMWarCreateNewAccountHtml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFIntSMWarCreateNewAccountHtml() {
		super();
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		final String S_ProcName="doGet";
		ICFIntSchemaObj schemaObj;
		HttpSession sess = request.getSession( false );
		if( sess == null ) {
			sess = request.getSession( true );
			schemaObj = new CFIntSchemaPooledObj();
			sess.setAttribute( "SchemaObj", schemaObj );
		}
		else {
			schemaObj = (ICFIntSchemaObj)sess.getAttribute( "SchemaObj" );
			if( schemaObj == null ) {
				schemaObj = new CFIntSchemaPooledObj();
				sess.setAttribute( "SchemaObj", schemaObj );
			}
		}

		ICFIntSchema dbSchema = null;
		try {
			CFSecAuthorization auth = schemaObj.getAuthorization();
			if( auth != null ) {
				response.sendRedirect( "CFIntSMWarSecMainHtml" );
				return;
			}

			dbSchema = (ICFIntSchema)CFIntSchemaPool.getSchemaPool().getInstance();
			schemaObj.setBackingStore( dbSchema );
			schemaObj.beginTransaction();
			ICFSecSecUserObj systemUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );
			String passwordHash = systemUser.getRequiredPasswordHash();
			if( ( passwordHash == null ) || ( passwordHash.length() <= 0 ) || passwordHash.equals( "bootstrap" ) ) {
				response.sendRedirect( "CFIntSMWarSetSystemPasswordHtml" );
				return;
			}

			ICFSecSysClusterObj sysCluster = schemaObj.getSysClusterTableObj().readSysClusterByIdIdx( 1, false );
			if( sysCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"sysCluster" );
			}

			ICFSecClusterObj resolvedCluster = sysCluster.getRequiredContainerCluster();
			if( resolvedCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					"resolvedCluster" );
			}
			String clusterDomName = resolvedCluster.getRequiredFullDomName();
			String clusterDescription = resolvedCluster.getRequiredDescription();

			response.setContentType( "text/html" );
			PrintWriter out = response.getWriter();
			out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
			out.println( "<HTML>" );
			out.println( "<BODY>" );
			out.println( "<form method=\"post\" formaction=\"CFIntSMWarCreateNewAccountHtml\">" );
			out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
			out.println( "<H2 style=\"text-align:center\">Create New Account</H2>" );
			out.println( "<p>" );
			out.println( "<center>" );
			out.println( "<table style=\"width:75%\">" );
			out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
			out.println( "<tr><th style=\"text-align:left\">EMail Address:</th><td><input type=\"text\" name=\"EMailAddress\"/></td></tr>");
			out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
			out.println( "<tr><th style=\"text-align:left\">Confirm Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
			out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Create Account</button></td></tr>" );
			out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\">You may now <A HRef=\"CFIntSMWarLoginHtml\">log in</A> to the " + clusterDescription + " Sec Manager</td></tr>" );
			out.println( "</table>" );
			out.println( "</center>" );
			out.println( "</form>" );
			out.println( "</BODY>" );
			out.println( "</HTML>" );
		}
		catch( RuntimeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught RuntimeException -- " + e.getMessage(),
				e );
		}
		finally {
			if( dbSchema != null ) {
				try {
					if( schemaObj.isTransactionOpen() ) { 
						schemaObj.rollback();
					}
				}
				catch( RuntimeException e ) {
				}
				schemaObj.setBackingStore( null );
				CFIntSchemaPool.getSchemaPool().releaseInstance( dbSchema );
			}
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		final String S_ProcName = "doPost";

		ICFIntSchemaObj schemaObj;
		HttpSession sess = request.getSession( false );
		if( sess == null ) {
			sess = request.getSession( true );
			schemaObj = new CFIntSchemaPooledObj();
			sess.setAttribute( "SchemaObj", schemaObj );
		}
		else {
			schemaObj = (ICFIntSchemaObj)sess.getAttribute( "SchemaObj" );
			if( schemaObj == null ) {
				schemaObj = new CFIntSchemaPooledObj();
				sess.setAttribute( "SchemaObj", schemaObj );
			}
		}

		ICFIntSchema dbSchema = null;
		try {
			CFSecAuthorization auth = schemaObj.getAuthorization();
			if( auth != null ) {
				response.sendRedirect( "CFIntSMWarSecMainHtml" );
				return;
			}

			dbSchema = (ICFIntSchema)CFIntSchemaPool.getSchemaPool().getInstance();
			schemaObj.setBackingStore( dbSchema );
			schemaObj.beginTransaction();
			ICFSecSecUserObj systemUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );
			String passwordHash = systemUser.getRequiredPasswordHash();
			if( ( passwordHash == null ) || ( passwordHash.length() <= 0 ) || passwordHash.equals( "bootstrap" ) ) {
				response.sendRedirect( "CFIntSMWarSetSystemPasswordHtml" );
				return;
			}

			ICFSecClusterObj resolvedCluster;
			ICFSecSysClusterObj sysCluster = schemaObj.getSysClusterTableObj().readSysClusterByIdIdx( 1, false );
			if( sysCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"sysCluster" );
			}
			resolvedCluster = sysCluster.getRequiredContainerCluster();
			if( resolvedCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					"resolvedCluster" );
			}
			String clusterDomName = resolvedCluster.getRequiredFullDomName();
			String clusterDescription = resolvedCluster.getRequiredDescription();

			String loginId = (String)request.getParameter( "LoginId" );
			if( ( loginId == null ) || ( loginId.length() <= 0 ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarCreateNewAccountHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Login Id must be specified." );
				out.println( "<H2 style=\"text-align:center\">Create New Account</H2>" );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:75%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">EMail Address:</th><td><input type=\"text\" name=\"EMailAddress\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Confirm Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Create Account</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Back to " + clusterDescription + " Sec Manager Login</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			String emailAddress = (String)request.getParameter( "EMailAddress" );
			if( ( emailAddress == null ) || ( emailAddress.length() <= 0 ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarCreateNewAccountHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "EMail Address must be specified." );
				out.println( "<H2 style=\"text-align:center\">Create New Account</H2>" );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:75%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">EMail Address:</th><td><input type=\"text\" name=\"EMailAddress\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Confirm Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Create Account</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Back to " + clusterDescription + " Sec Manager Login</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			ICFSecSecUserObj existingUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( loginId, true );
			if( existingUser != null ) {

				if( null != existingUser.getOptionalEMailConfirmUuid() ) {
					sendConfirmationEMail( request, existingUser, resolvedCluster );
				}

				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarCreateNewAccountHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );

				if( null != existingUser.getOptionalEMailConfirmUuid() ) {
					out.println( "User id \"" + loginId + "\" has already been registered.  The confirmation email has been resent." );
				}
				else {
					out.println( "User id \"" + loginId + "\" is already in use." );
				}

				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:75%\">" );
				if( null == existingUser.getOptionalEMailConfirmUuid() ) {
					out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
					out.println( "<tr><th style=\"text-align:left\">EMail Address:</th><td><input type=\"text\" name=\"EMailAddress\"/></td></tr>");
					out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
					out.println( "<tr><th style=\"text-align:left\">Confirm Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
					out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Create Account</button></td></tr>" );
				}
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Back to " + clusterDescription + " Sec Manager Login</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );

				return;
			}

			String password = (String)request.getParameter( "Password" );
			if( ( password == null ) || ( password.length() <= 0 ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarCreateNewAccountHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Password must be specified." );
				out.println( "<H2 style=\"text-align:center\">Create New Account</H2>" );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:75%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">EMail Address:</th><td><input type=\"text\" name=\"EMailAddress\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Confirm Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Create Account</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Back to " + clusterDescription + " Sec Manager Login</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			String confirmPassword = (String)request.getParameter( "ConfirmPassword" );
			if( ( confirmPassword == null ) || ( confirmPassword.length() <= 0 ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarCreateNewAccountHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Confirmation Password must be specified." );
				out.println( "<H2 style=\"text-align:center\">Create New Account</H2>" );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:75%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">EMail Address:</th><td><input type=\"text\" name=\"EMailAddress\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Confirm Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Create Account</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Back to " + clusterDescription + " Sec Manager Login</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			if( ! confirmPassword.equals( password ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarCreateNewAccountHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Password and Confirmation Password do not match." );
				out.println( "<H2 style=\"text-align:center\">Create New Account</H2>" );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:75%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">EMail Address:</th><td><input type=\"text\" name=\"EMailAddress\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Confirm Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Create Account</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Back to " + clusterDescription + " Sec Manager Login</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			MessageDigest msgDigest = MessageDigest.getInstance( "SHA-512" );
			msgDigest.update( password.getBytes( "UTF-8" ) );
			byte[] hash = msgDigest.digest();
			byte[] encodedHash = Base64.encodeBase64( hash );
			msgDigest.update( encodedHash );
			hash = msgDigest.digest();
			encodedHash = Base64.encodeBase64( hash );
			String hashedAndEncodedPassword = new String( encodedHash );

			ICFSecClusterObj systemCluster = schemaObj.getClusterTableObj().readClusterByUDomNameIdx( "system" );
			ICFSecTenantObj systemTenant = schemaObj.getTenantTableObj().readTenantByUNameIdx( systemCluster.getRequiredId(), "system" );
			ICFSecSecSessionObj systemSession = schemaObj.getSecSessionTableObj().newInstance();
			ICFSecSecSessionEditObj editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
			editSystemSession.setRequiredContainerSecUser( systemUser );
			editSystemSession.setRequiredStart( Calendar.getInstance() );
			systemSession = editSystemSession.create();
			editSystemSession = null;

			auth = new CFSecAuthorization();
			auth.setSecCluster( systemCluster );
			auth.setSecTenant( systemTenant );
			auth.setSecSession( systemSession );
			schemaObj.setAuthorization( auth );

			ICFSecSecUserObj newUser = schemaObj.getSecUserTableObj().newInstance();
			ICFSecSecUserEditObj editUser = (ICFSecSecUserEditObj)newUser.beginEdit();
			editUser.setRequiredLoginId( loginId );
			editUser.setRequiredEMailAddress( emailAddress );
			editUser.setRequiredPasswordHash( hashedAndEncodedPassword );
			editUser.setOptionalEMailConfirmUuid( UUID.randomUUID() );
			newUser = editUser.create();
			editUser = null;

			editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
			editSystemSession.setOptionalFinish( Calendar.getInstance() );
			editSystemSession.update();
			editSystemSession = null;

			schemaObj.commit();

			schemaObj.setAuthorization( null );

			sendConfirmationEMail( request, newUser, resolvedCluster );

			response.sendRedirect( "CFIntSMWarLoginHtml" );
		}
		catch( AddressException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught AddressException -- " + e.getMessage(),
				e );
		}
		catch( MessagingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught MessagingException -- " + e.getMessage(),
				e );
		}
		catch( NamingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NamingException -- " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException -- " + e.getMessage(),
				e );
		}
		catch( RuntimeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught RuntimeException -- " + e.getMessage(),
				e );
		}
		finally {
			if( dbSchema != null ) {
				try {
					if( schemaObj.isTransactionOpen() ) { 
						schemaObj.rollback();
					}
				}
				catch( RuntimeException e ) {
				}
				schemaObj.setBackingStore( null );
				CFIntSchemaPool.getSchemaPool().releaseInstance( dbSchema );
			}
		}
	}

	protected void sendConfirmationEMail(
		HttpServletRequest request,
		ICFSecSecUserObj confirmUser,
		ICFSecClusterObj cluster )
	throws
		IOException,
		MessagingException,
		NamingException
	{
		final String S_ProcName = "sendConfirmationEMail";

		Properties props = System.getProperties();
		String clusterDescription = cluster.getRequiredDescription();

		String thisURI = request.getScheme()
			+	"://"
			+	request.getServerName()
			+	":"
			+	request.getServerPort()
			+	request.getRequestURI().toString();
		int lastSlash = thisURI.lastIndexOf( '/' );
		String baseURI = thisURI.substring( 0, lastSlash );
		UUID confirmationUUID = confirmUser.getOptionalEMailConfirmUuid();

		String msgBody =
				"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">\n"
			+	"<HTML>\n"
			+	"<BODY>\n"
			+	"<p>\n"
			+	"You requested a new account for login " + confirmUser.getRequiredLoginId() + " with " + clusterDescription + ".\n"
			+	"<p>"
			+	"Please click on the following link to confirm your email address:<br>\n"
			+	"<A HRef=\"" + baseURI + "/CFIntSMWarConfirmEMailAddressHtml?ConfirmationUUID=" + confirmationUUID.toString() + "\">"
			+		 baseURI + "/CFIntSMWarConfirmEMailAddressHtml?ConfirmationUUID=" + confirmationUUID.toString() + "</A>\n"
			+	"<p>"
			+	"Or click on the following link to cancel the request for a new account:<br>\n"
			+	"<A HRef=\"" + baseURI + "/CFIntSMWarCancelEMailAddressHtml?ConfirmationUUID=" + confirmationUUID.toString() + "\">"
			+		 baseURI + "/CFIntSMWarCancelEMailAddressHtml?ConfirmationUUID=" + confirmationUUID.toString() + "</A>\n"
			+	"</BODY>\n"
			+	"</HTML>\n";

		CFIntSMWarUtil warUtil = new CFIntSMWarUtil();
		warUtil.sendEMailToUser( confirmUser,
			"You requested an account with " + clusterDescription + "?",
			msgBody );
	}
}
