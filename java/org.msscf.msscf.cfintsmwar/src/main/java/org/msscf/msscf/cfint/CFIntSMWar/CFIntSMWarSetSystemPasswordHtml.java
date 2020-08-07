
// Description: Java 11 Sec Manager Set System Password Servlet

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

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/**
 * Servlet implementation class CFIntSMWarSetSystemPasswordHtml
 */
@WebServlet("/CFIntSMWarSetSystemPasswordHtml")
public class CFIntSMWarSetSystemPasswordHtml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFIntSMWarSetSystemPasswordHtml() {
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
				response.sendRedirect( "CFIntSMWarLoginHtml" );
				return;
			}
		}

		ICFIntSchema dbSchema = null;
		try {
			CFSecAuthorization auth = schemaObj.getAuthorization();
			if( auth != null ) {
				response.sendRedirect( "CFIntSMWarSecMainHtml" );
			}
			else {
				dbSchema = (ICFIntSchema)CFIntSchemaPool.getSchemaPool().getInstance();
				schemaObj.setBackingStore( dbSchema );
				schemaObj.beginTransaction();
				ICFSecSecUserObj systemUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );
				String passwordHash = systemUser.getRequiredPasswordHash();
				if( ( passwordHash != null ) && ( passwordHash.length() > 0 ) && ( ! passwordHash.equals( "bootstrap" ) ) ) {
					response.sendRedirect( "CFIntSMWarLoginHtml" );
				}
				else {
					ICFSecClusterObj resolvedCluster;
					String resolvedClusterDescription;
					ICFSecSysClusterObj sysCluster = schemaObj.getSysClusterTableObj().readSysClusterByIdIdx( 1, false );
					if( sysCluster == null ) {
						resolvedCluster = null;
						resolvedClusterDescription = null;
					}
					else {
						resolvedCluster = sysCluster.getRequiredContainerCluster();
						if( resolvedCluster == null ) {
							throw new CFLibNullArgumentException( getClass(),
								S_ProcName,
								"resolvedCluster" );
						}
						resolvedClusterDescription = resolvedCluster.getRequiredDescription();
					}

					response.setContentType( "text/html" );
					PrintWriter out = response.getWriter();
					out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
					out.println( "<HTML>" );
					out.println( "<BODY>" );
					out.println( "<form method=\"post\" formaction=\"CFIntSMWarSetSystemPasswordHtml\">" );
					out.println( "<H1 style=\"text-align:center\">" + (( resolvedClusterDescription == null ) ? "" : resolvedClusterDescription ) + " Sec Manager</H1>" );
					out.println( "<H2 style=\"text-align:center\">Please initialize the \"system\" password and cluster details.</H2>" );
					out.println( "<p>" );
					out.println( "<center>" );
					out.println( "<table style=\"width:60%\">" );
					out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
					out.println( "<tr><th style=\"text-align:left\">Confirm Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
					out.println( "<tr><th style=\"text-align:left\">Cluster Domain Name:</th><td><input name=\"ClusterDomName\"/></td></tr>" );
					out.println( "<tr><th style=\"text-align:left\">Cluster Description:</th><td><input name=\"ClusterDescription\"/></td></tr>" );
					out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
					out.println( "</table>" );
					out.println( "</center>" );
					out.println( "</form>" );
					out.println( "</BODY>" );
					out.println( "</HTML>" );
				}
			}
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
				response.sendRedirect( "CFIntSMWarLoginHtml" );
				return;
			}
		}

		ICFIntSchema dbSchema = null;
		try {
			CFSecAuthorization auth = schemaObj.getAuthorization();
			if( auth != null ) {
				response.sendRedirect( "CFIntSMWarSecMainHtml" );
			}
			else {
				dbSchema = (ICFIntSchema)CFIntSchemaPool.getSchemaPool().getInstance();
				schemaObj.setBackingStore( dbSchema );
				schemaObj.beginTransaction();
				ICFSecSecUserObj systemUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );
				String passwordHash = systemUser.getRequiredPasswordHash();
				if( ( passwordHash != null ) && ( passwordHash.length() > 0 ) && ( ! passwordHash.equals( "bootstrap" ) )  ) {
					response.sendRedirect( "CFIntSMWarLoginHtml" );
				}
				else {
					ICFSecClusterObj resolvedCluster;
					String resolvedClusterDomName;
					String resolvedClusterDescription;
					ICFSecSysClusterObj sysCluster = schemaObj.getSysClusterTableObj().readSysClusterByIdIdx( 1, false );
					if( sysCluster == null ) {
						resolvedCluster = null;
						resolvedClusterDomName = (String)request.getParameter( "ClusterDomName" );
						resolvedClusterDescription = (String)request.getParameter( "ClusterDescription" );
					}
					else {
						resolvedCluster = sysCluster.getRequiredContainerCluster();
						if( resolvedCluster == null ) {
							throw new CFLibNullArgumentException( getClass(),
								S_ProcName,
								"resolvedCluster" );
						}
						resolvedClusterDomName = resolvedCluster.getRequiredFullDomName();
						resolvedClusterDescription = resolvedCluster.getRequiredDescription();
					}

					String password = (String)request.getParameter( "Password" );
					if( password == null ) {
						password = "";
					}
					String confirmPassword = (String)request.getParameter( "ConfirmPassword" );
					if( confirmPassword == null ) {
						confirmPassword = "";
					}
					response.setContentType( "text/html" );
					PrintWriter out = response.getWriter();
					if( password.length() <= 0 ) { 
						out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
						out.println( "<HTML>" );
						out.println( "<BODY>" );
						out.println( "<form method=\"post\" formaction=\"CFIntSMWarSetSystemPasswordHtml\">" );
						out.println( "<H1 style=\"text-align:center\">" + (( resolvedClusterDescription == null ) ? "" : resolvedClusterDescription ) + " Sec Manager</H1>" );
						out.println( "<H2 style=\"text-align:center\">Please initialize the \"system\" password and cluster details.</H2>" );
						out.println( "<p>" );
						out.println( "<center>" );
						out.println( "<table style=\"width:60%\">" );
						out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
						out.println( "<tr><th style=\"text-align:left\">Confirm Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
						out.println( "<tr><th style=\"text-align:left\">Cluster Domain Name:</th><td><input name=\"ClusterDomName\"/></td></tr>" );
						out.println( "<tr><th style=\"text-align:left\">Cluster Description:</th><td><input name=\"ClusterDescription\"/></td></tr>" );
						out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
						out.println( "</table>" );
						out.println( "</center>" );
						out.println( "</form>" );
						out.println( "</BODY>" );
						out.println( "</HTML>" );
					}
					else if( ! password.equals( confirmPassword ) ) { 
						out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
						out.println( "<HTML>" );
						out.println( "<BODY>" );
						out.println( "<form method=\"post\" formaction=\"CFIntSMWarSetSystemPasswordHtml\">" );
						out.println( "<H1 style=\"text-align:center\">" + (( resolvedClusterDescription == null ) ? "" : resolvedClusterDescription ) + " Sec Manager</H1>" );
						out.println( "<H2 style=\"text-align:center\">Please initialize the \"system\" password and cluster details.</H2>" );
						out.println( "<p>" );
						out.println( "<center>" );
						out.println( "<table style=\"width:60%\">" );
						out.println( "<tr><th style=\"text-align:left\">Password:</th><td><input type=\"password\" name=\"Password\"/></td></tr>");
						out.println( "<tr><th style=\"text-align:left\">Confirm Password:</th><td><input type=\"password\" name=\"ConfirmPassword\"/></td></tr>");
						out.println( "<tr><th style=\"text-align:left\">Cluster Domain Name:</th><td><input name=\"ClusterDomName\"/></td></tr>" );
						out.println( "<tr><th style=\"text-align:left\">Cluster Description:</th><td><input name=\"ClusterDescription\"/></td></tr>" );
						out.println( "<tr><td colspan=\"2\" style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Ok</button></td></tr>" );
						out.println( "</table>" );
						out.println( "</center>" );
						out.println( "</form>" );
						out.println( "</BODY>" );
						out.println( "</HTML>" );
					}
					else {
						MessageDigest msgDigest = MessageDigest.getInstance( "SHA-512" );
						msgDigest.update( password.getBytes( "UTF-8" ) );
						byte[] hash = msgDigest.digest();
						byte[] encodedHash = Base64.encodeBase64( hash );
						msgDigest.update( encodedHash );
						hash = msgDigest.digest();
						encodedHash = Base64.encodeBase64( hash );
						String hashedAndEncodedPassword = new String( encodedHash );

						// Need to temporarily "log in" as system.system to set the password
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

						if( resolvedCluster == null ) {
							ICFSecClusterObj cluster = schemaObj.getClusterTableObj().newInstance();
							ICFSecClusterEditObj editCluster = cluster.beginEdit();
							editCluster.setRequiredFullDomName( resolvedClusterDomName );
							editCluster.setRequiredDescription( resolvedClusterDescription );
							cluster = editCluster.create();
							editCluster = null;

							resolvedCluster = cluster;

							ICFSecTenantObj tenant = schemaObj.getTenantTableObj().newInstance();
							ICFSecTenantEditObj editTenant = tenant.beginEdit();
							editTenant.setRequiredContainerCluster( cluster );
							editTenant.setRequiredTenantName( "system" );
							tenant = editTenant.create();
							editTenant = null;

							sysCluster = schemaObj.getSysClusterTableObj().newInstance();
							ICFSecSysClusterEditObj editSysCluster = sysCluster.beginEdit();
							editSysCluster.setRequiredContainerCluster( resolvedCluster );
							editSysCluster.setRequiredSingletonId( 1 );
							sysCluster = editSysCluster.create();
							editSysCluster = null;
						}

						ICFSecSecUserEditObj editSystemUser = (ICFSecSecUserEditObj)systemUser.beginEdit();
						editSystemUser.setRequiredPasswordHash( hashedAndEncodedPassword );
						editSystemUser.update();
						editSystemUser = null;

						editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
						editSystemSession.setOptionalFinish( Calendar.getInstance() );
						editSystemSession.update();
						editSystemSession = null;

						schemaObj.commit();

						schemaObj.setAuthorization( null );

						out.println( "<H1 style=\"text-align:center\">" + (( resolvedClusterDescription == null ) ? "" : resolvedClusterDescription ) + " Sec Manager</H1>" );
						out.println( "<H2 style=\"text-align:center\">Password set.</H2>" );
						out.println( "<p style=\"text-align:center\">" );
						out.println( "You may now <A HRef=\"CFIntSMWarLoginHtml\">log in to the sec manager.</A>" );
					}
				}
			}
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