
// Description: Java 11 Sec Manager Change Password Servlet

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
import java.util.Iterator;
import java.util.Properties;
import java.util.UUID;

import javax.mail.*;
import javax.mail.internet.*;
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
 * Servlet implementation class CFIntSMWarChangePasswordHtml
 */
@WebServlet("/CFIntSMWarChangePasswordHtml")
public class CFIntSMWarChangePasswordHtml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFIntSMWarChangePasswordHtml() {
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
			if( auth == null ) {
				response.sendRedirect( "CFIntSMWarLoginHtml" );
				return;
			}

			dbSchema = (ICFIntSchema)CFIntSchemaPool.getSchemaPool().getInstance();
			schemaObj.setBackingStore( dbSchema );
			schemaObj.beginTransaction();
			ICFSecSecUserObj secUser = schemaObj.getSecUserTableObj().readSecUserByIdIdx( auth.getSecUserId() );
			if( secUser == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"secUser" );
			}

			ICFSecClusterObj secCluster = schemaObj.getClusterTableObj().readClusterByIdIdx( auth.getSecClusterId() );
			if( secCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"secCluster" );
			}
			String clusterDescription = secCluster.getRequiredDescription();

			response.setContentType( "text/html" );
			PrintWriter out = response.getWriter();
			out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
			out.println( "<HTML>" );
			out.println( "<BODY>" );
			out.println( "<form method=\"post\" formaction=\"CFIntSMWarChangePasswordHtml\">" );
			out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
			out.println( "<H2 style=\"text-align:center\">Change Password for " + secUser.getRequiredEMailAddress() + "</H2>" );
			out.println( "<p>" );
			out.println( "<center>" );
			out.println( "<table style=\"width:75%\">" );
			out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\" readonly=\"true\" value=\"" + secUser.getRequiredEMailAddress() + "\"/></td></tr>");
			out.println( "<tr><th style=\"text-align:left\">Old Password:</th><td><input type=\"password\" name=\"OldPassword\"/></td></tr>");
			out.println( "<tr><th style=\"text-align:left\">New Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
			out.println( "<tr><th style=\"text-align:left\">Confirm New Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
			out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
			out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Take me to the " + secCluster.getRequiredDescription() + " Sec Manager Login</A></td></tr>" );
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
			if( auth == null ) {
				response.sendRedirect( "CFIntSMWarLoginHtml" );
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

			ICFSecSecUserObj secUser = schemaObj.getSecUserTableObj().readSecUserByIdIdx( auth.getSecUserId() );
			if( secUser == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"secUser" );
			}

			ICFSecClusterObj secCluster = schemaObj.getClusterTableObj().readClusterByIdIdx( auth.getSecClusterId() );
			if( secCluster == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"secCluster" );
			}
			String clusterDescription = secCluster.getRequiredDescription();

			String oldPassword = (String)request.getParameter( "OldPassword" );
			if( ( oldPassword == null ) || ( oldPassword.length() <= 0 ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarChangePasswordHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Old Password must be specified." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:75%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\" readonly=\"true\" value=\"" + secUser.getRequiredEMailAddress() + "\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Old Password:</th><td><input type=\"password\" name=\"OldPassword\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">New Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Confirm New Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Take me to the " + secCluster.getRequiredDescription() + " Sec Manager Login</A></td></tr>" );
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
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarChangePasswordHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "New Password must be specified." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:75%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\" readonly=\"true\" value=\"" + secUser.getRequiredEMailAddress() + "\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Old Password:</th><td><input type=\"password\" name=\"OldPassword\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">New Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Confirm New Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Take me to the " + secCluster.getRequiredDescription() + " Sec Manager Login</A></td></tr>" );
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
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarChangePasswordHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Confirm New Password must be specified." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:75%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\" readonly=\"true\" value=\"" + secUser.getRequiredEMailAddress() + "\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Old Password:</th><td><input type=\"password\" name=\"OldPassword\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">New Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Confirm New Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Take me to the " + secCluster.getRequiredDescription() + " Sec Manager Login</A></td></tr>" );
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
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarChangePasswordHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "New Password and Confirm New Password do not match." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:75%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\" readonly=\"true\" value=\"" + secUser.getRequiredEMailAddress() + "\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Old Password:</th><td><input type=\"password\" name=\"OldPassword\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">New Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Confirm New Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Take me to the " + secCluster.getRequiredDescription() + " Sec Manager Login</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			MessageDigest msgDigest = MessageDigest.getInstance( "SHA-512" );
			msgDigest.update( oldPassword.getBytes( "UTF-8" ) );
			byte[] hash = msgDigest.digest();
			byte[] encodedHash = Base64.encodeBase64( hash );
			msgDigest.update( encodedHash );
			hash = msgDigest.digest();
			encodedHash = Base64.encodeBase64( hash );
			String oldHashedAndEncodedPassword = new String( encodedHash );

			if( ! oldHashedAndEncodedPassword.equals( secUser.getRequiredPasswordHash() ) ) {
				response.setContentType( "text/html" );
				PrintWriter out = response.getWriter();
				out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
				out.println( "<HTML>" );
				out.println( "<BODY>" );
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarChangePasswordHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">ERROR</H2>" );
				out.println( "<p style=\"text-align:center\">" );
				out.println( "Old Password is invalid." );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:75%\">" );
				out.println( "<tr><th style=\"text-align:left\">Login Id:</th><td><input type=\"text\" name=\"LoginId\" readonly=\"true\" value=\"" + secUser.getRequiredEMailAddress() + "\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Old Password:</th><td><input type=\"password\" name=\"OldPassword\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">New Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
				out.println( "<tr><th style=\"text-align:left\">Confirm New Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
				out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
				out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Take me to the " + secCluster.getRequiredDescription() + " Sec Manager Login</A></td></tr>" );
				out.println( "</table>" );
				out.println( "</center>" );
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
				return;
			}

			msgDigest.update( password.getBytes( "UTF-8" ) );
			hash = msgDigest.digest();
			encodedHash = Base64.encodeBase64( hash );
			msgDigest.update( encodedHash );
			hash = msgDigest.digest();
			encodedHash = Base64.encodeBase64( hash );
			String newHashedAndEncodedPassword = new String( encodedHash );

			ICFSecClusterObj systemCluster = schemaObj.getClusterTableObj().readClusterByUDomNameIdx( "system" );
			ICFSecTenantObj systemTenant = schemaObj.getTenantTableObj().readTenantByUNameIdx( systemCluster.getRequiredId(), "system" );
			ICFSecSecSessionObj systemSession = schemaObj.getSecSessionTableObj().newInstance();
			ICFSecSecSessionEditObj editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
			editSystemSession.setRequiredContainerSecUser( systemUser );
			editSystemSession.setRequiredStart( Calendar.getInstance() );
			systemSession = editSystemSession.create();
			editSystemSession = null;

			CFSecAuthorization oldAuth = schemaObj.getAuthorization();

			auth = new CFSecAuthorization();
			auth.setSecCluster( systemCluster );
			auth.setSecTenant( systemTenant );
			auth.setSecSession( systemSession );
			schemaObj.setAuthorization( auth );

			ICFSecSecUserEditObj editSecUser = secUser.beginEdit();
			editSecUser.setRequiredPasswordHash( newHashedAndEncodedPassword );
			editSecUser.update();
			editSecUser = null;

			editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
			editSystemSession.setOptionalFinish( Calendar.getInstance() );
			editSystemSession.update();
			editSystemSession = null;

			schemaObj.commit();

			schemaObj.setAuthorization( oldAuth );

			response.setContentType( "text/html" );
			PrintWriter out = response.getWriter();
			out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
			out.println( "<HTML>" );
			out.println( "<BODY>" );
			out.println( "<form method=\"post\" formaction=\"CFIntSMWarChangePasswordHtml\">" );
			out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
			out.println( "<H2 style=\"text-align:center\">Password Set.</H2>" );
			out.println( "<p>" );
			out.println( "<center>" );
			out.println( "<table style=\"width:75%\">" );
			out.println( "<tr><td colSpan=\"2\" style=\"text-align:center\"><A HRef=\"CFIntSMWarLoginHtml\">Take me back to the " + secCluster.getRequiredDescription() + " Sec Manager Main page</A></td></tr>" );
			out.println( "</table>" );
			out.println( "</center>" );
			out.println( "</form>" );
			out.println( "</BODY>" );
			out.println( "</HTML>" );
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
}
