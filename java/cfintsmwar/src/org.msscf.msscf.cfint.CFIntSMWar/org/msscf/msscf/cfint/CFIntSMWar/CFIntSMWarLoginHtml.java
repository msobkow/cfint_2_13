
// Description: Java 11 Sec Manager Login Servlet

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
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import javax.sql.DataSource;

import org.apache.commons.codec.binary.Base64;

import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/**
 * Servlet implementation class CFIntSMWarLoginHtml
 */
@WebServlet("/CFIntSMWarLoginHtml")
public class CFIntSMWarLoginHtml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFIntSMWarLoginHtml() {
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
			out.println( "<form method=\"post\" formaction=\"CFIntSMWarLoginHtml\">" );
			out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
			out.println( "<H2 style=\"text-align:center\">Please log in or create a new account.</H2>" );
			out.println( "<p>" );
			out.println( "<center>" );
			out.println( "<table style=\"width:60%\">" );
			out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
			out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
			out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
			out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarCreateNewAccountHtml\">Create new account</A></td></tr>" );
			out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarRequestResetPasswordHtml\">Request an Password Reset</A></td></tr>" );
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
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarLoginHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Login id or password is invalid.  Permission denied." );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Please log in or create a new account." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:60%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"/CFIntSMWarCreateNewAccountHtml\">Create new account</A></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarRequestResetPasswordHtml\">Request an Password Reset</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			ICFSecSecUserObj authenticatingUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( loginId, true );
			if( authenticatingUser == null ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarLoginHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Login id or password is invalid.  Permission denied." );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Please log in or create a new account." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:60%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"/CFIntSMWarCreateNewAccountHtml\">Create new account</A></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarRequestResetPasswordHtml\">Request an Password Reset</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			ICFSecSecDeviceObj defDev = authenticatingUser.getOptionalLookupDefDev( true );

			if( null != authenticatingUser.getOptionalPasswordResetUuid() ) {

				sendPasswordResetEMail( request, authenticatingUser, resolvedCluster );

				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarLoginHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Password Reset email has been resent." );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Please use the links in the password reset email to set a new Password or to cancel the request before trying to log in again." );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Please log in or create a new account." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:60%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"/CFIntSMWarCreateNewAccountHtml\">Create new account</A></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarRequestResetPasswordHtml\">Request an Password Reset</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			String password = (String)request.getParameter( "Password" );
			if( password == null ) {
				password = "";
			}

			MessageDigest msgDigest = MessageDigest.getInstance( "SHA-512" );
			msgDigest.update( password.getBytes( "UTF-8" ) );
			byte[] hash = msgDigest.digest();
			byte[] encodedHash = Base64.encodeBase64( hash );
			msgDigest.update( encodedHash );
			hash = msgDigest.digest();
			byte encodedDoubleHash[] = Base64.encodeBase64( hash );
			String hashedAndEncodedPassword = new String( encodedDoubleHash );

			if( ! hashedAndEncodedPassword.equals( authenticatingUser.getRequiredPasswordHash() ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarLoginHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Login id or password is invalid.  Permission denied." );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Please log in or create a new account." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:60%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"/CFIntSMWarCreateNewAccountHtml\">Create new account</A></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarRequestResetPasswordHtml\">Request an Password Reset</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			if( null != authenticatingUser.getOptionalEMailConfirmUuid() ) {

				sendConfirmationEMail( defDev, request, authenticatingUser, resolvedCluster );

				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarLoginHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "EMail address "
					+	( ( defDev != null )
							? "sec "
							: "" )
					+	" of login id has not been confirmed.  The "
					+	( ( defDev != null )
							? "encrypted "
							: "" )
					+	"confirmation email has been resent." );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Please log in or create a new account." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:60%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"/CFIntSMWarCreateNewAccountHtml\">Create new account</A></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarRequestResetPasswordHtml\">Request an Password Reset</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );

				return;
			}

			ICFSecTenantObj systemTenant = schemaObj.getTenantTableObj().readTenantByUNameIdx( resolvedCluster.getRequiredId(), "system" );
			ICFSecSecSessionObj systemSession = schemaObj.getSecSessionTableObj().newInstance();
			ICFSecSecSessionEditObj editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
			editSystemSession.setRequiredContainerSecUser( authenticatingUser );
			editSystemSession.setRequiredStart( Calendar.getInstance() );
			systemSession = editSystemSession.create();
			editSystemSession = null;

			auth = new CFSecAuthorization();
			auth.setSecCluster( resolvedCluster );
			auth.setSecTenant( systemTenant );
			auth.setSecSession( systemSession );
			schemaObj.setAuthorization( auth );

			schemaObj.commit();

			response.sendRedirect( "CFIntSMWarSecMainHtml" );
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
		ICFSecSecDeviceObj defDev,
		HttpServletRequest request,
		ICFSecSecUserObj confirmUser,
		ICFSecClusterObj cluster )
	throws
		IOException,
		MessagingException,
		NamingException
	{
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
			+	"You requested a new account for " + confirmUser.getRequiredEMailAddress() + " with " + clusterDescription + ".\n"
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

	protected void sendPasswordResetEMail(
		HttpServletRequest request,
		ICFSecSecUserObj resetUser,
		ICFSecClusterObj cluster )
	throws
		IOException,
		MessagingException,
		NamingException
	{
		String clusterDescription = cluster.getRequiredDescription();

		String thisURI = request.getScheme()
			+	"://"
			+	request.getServerName()
			+	":"
			+	request.getServerPort()
			+	request.getRequestURI().toString();
		int lastSlash = thisURI.lastIndexOf( '/' );
		String baseURI = thisURI.substring( 0, lastSlash );
		UUID resetUUID = resetUser.getOptionalPasswordResetUuid();

		String msgBody =
				"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">\n"
			+	"<HTML>\n"
			+	"<BODY>\n"
			+	"<p>\n"
			+	"You requested a password reset for " + resetUser.getRequiredEMailAddress() + " used for accessing " + clusterDescription + ".\n"
			+	"<p>"
			+	"Please click on the following link to reset your password:<br>\n"
			+	"<A HRef=\"" + baseURI + "/CFIntSMWarResetPasswordHtml?ResetUUID=" + resetUUID.toString() + "\">"
			+		 baseURI + "/CFIntSMWarResetPasswordHtml?ResetUUID=" + resetUUID.toString() + "</A>\n"
			+	"<p>"
			+	"Or click on the following link to cancel the reset request:<br>\n"
			+	"<A HRef=\"" + baseURI + "/CFIntSMWarCancelResetPasswordHtml?ResetUUID=" + resetUUID.toString() + "\">"
			+		 baseURI + "/CFIntSMWarCancelResetPasswordHtml?ResetUUID=" + resetUUID.toString() + "</A>\n"
			+	"</BODY>\n"
			+	"</HTML>\n";

		CFIntSMWarUtil warUtil = new CFIntSMWarUtil();
		warUtil.sendEMailToUser( resetUser,
			"You requested a password reset for your account with " + clusterDescription + "?",
			msgBody );
	}
}
