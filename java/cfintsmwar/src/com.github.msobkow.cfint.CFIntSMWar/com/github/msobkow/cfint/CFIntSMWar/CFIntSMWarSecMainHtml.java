
// Description: Java 11 Sec Manager Sec Main Servlet

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

import java.io.IOException;
import java.io.PrintWriter;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Calendar;
import java.util.Iterator;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

import org.apache.commons.codec.binary.Base64;

import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfint.CFInt.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFIntObj.*;

/**
 * Servlet implementation class CFIntSMWarSecMainHtml
 */
@WebServlet("/CFIntSMWarSecMainHtml")
public class CFIntSMWarSecMainHtml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFIntSMWarSecMainHtml() {
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
			if( auth == null ) {
				response.sendRedirect( "CFIntSMWarLoginHtml" );
			}
			else {
				dbSchema = (ICFIntSchema)CFIntSchemaPool.getSchemaPool().getInstance();
				schemaObj.setBackingStore( dbSchema );
				schemaObj.beginTransaction();
				ICFSecSecUserObj secUser = schemaObj.getSecUserTableObj().readSecUserByIdIdx( auth.getSecUserId() );

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
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarSecMainHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">Logged in as "
						+ secUser.getRequiredEMailAddress()
						+ "</H2>" );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:70%\">" );
				out.println( "<tr><th style=\"text-align:center\">Device Name (* is default device)</th><th style=\"text-align:center\">Click to Make Default</th><th style=\"text-align:center\">Click to Delete</th></tr>" );
				ICFSecSecDeviceObj defDev = secUser.getOptionalLookupDefDev( true );
				ICFSecSecDeviceObj secDev;
				Iterator<ICFSecSecDeviceObj> iterDev = secUser.getOptionalComponentsSecDev( true ).iterator();
				while( iterDev.hasNext() ) {
					secDev = iterDev.next();
					out.println(
						"<tr><td>"
							+ ( ( secDev == defDev )
									? "(*) "
									: "" )
							+ secDev.getRequiredDevName()
						+ "</td><td>"
							+ ( ( secDev != defDev )
									? "<A HRef=\"CFIntSMWarMakeDefaultDeviceHtml?DeviceName="
										+ secDev.getRequiredDevName()
										+ "\">Make Default</A>"
									: "" )
						+ "</td><td>"
							+ ( ( secDev != defDev )
									? "<A HRef=\"CFIntSMWarDeleteDeviceHtml?DeviceName="
										+ secDev.getRequiredDevName()
										+ "\">Delete</A>"
									: "" )
						+ "</td></tr>" );
				}
				out.println( "</table>" );
				out.println( "</center>" );
				iterDev = secUser.getOptionalComponentsSecDev( true ).iterator();
				if( ! iterDev.hasNext() ) {
					out.println( "<p style=\"text-align:center\">" );
					out.println( "You must <A HRef=\"CFIntSMWarAddDeviceHtml\">Add A Default Device</A> before doing anything else." );
				}
				else {
					out.println( "<p style=\"text-align:center\"><button type=\"button\" name=\"AddDevice\"\" onclick=\"window.location.href='CFIntSMWarChangePasswordHtml'\">Change Password</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"AddDevice\"\" onclick=\"window.location.href='CFIntSMWarAddDeviceHtml'\">Add Device</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Logout\"\" onclick=\"window.location.href='CFIntSMWarLogoutHtml'\">Log Out</button>" );
				}
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
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
			if( auth == null ) {
				response.sendRedirect( "CFIntSMWarLoginHtml" );
			}
			else {
				dbSchema = (ICFIntSchema)CFIntSchemaPool.getSchemaPool().getInstance();
				schemaObj.setBackingStore( dbSchema );
				schemaObj.beginTransaction();
				ICFSecSecUserObj secUser = schemaObj.getSecUserTableObj().readSecUserByIdIdx( auth.getSecUserId() );

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
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarSecMainHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">Logged in as "
					+ secUser.getRequiredEMailAddress()
					+ "</H2>" );
				out.println( "<p style=\"text-align:center\"><A HRef=\"CFIntSMWarChangePasswordHtml\">Change Password</A>" );
				out.println( "<p>" );
				out.println( "<center>" );
				out.println( "<table style=\"width:70%\">" );
				out.println( "<tr><th style=\"text-align:center\">Device Name (* is default device)</th><th style=\"text-align:center\">Click to Make Default</th><th style=\"text-align:center\">Click to Delete</th></tr>" );
				ICFSecSecDeviceObj defDev = secUser.getOptionalLookupDefDev( true );
				ICFSecSecDeviceObj secDev;
				Iterator<ICFSecSecDeviceObj> iterDev = secUser.getOptionalComponentsSecDev( true ).iterator();
				while( iterDev.hasNext() ) {
					secDev = iterDev.next();
					out.println(
						"<tr><td>"
							+ ( ( secDev == defDev )
									? "(*) "
									: "" )
							+ secDev.getRequiredDevName()
						+ "</td><td>"
							+ ( ( secDev != defDev )
									? "<A HRef=\"CFIntSMWarMakeDefaultDeviceHtml?DeviceName="
										+ secDev.getRequiredDevName()
										+ "\">Make Default</A>"
									: "" )
						+ "</td><td>"
							+ ( ( secDev != defDev )
									? "<A HRef=\"CFIntSMWarDeleteDeviceHtml?DeviceName="
										+ secDev.getRequiredDevName()
										+ "\">Delete</A>"
									: "" )
						+ "</td></tr>" );
				}
				out.println( "</table>" );
				out.println( "</center>" );
				iterDev = secUser.getOptionalComponentsSecDev().iterator();
				if( ! iterDev.hasNext() ) {
					out.println( "<p style=\"text-align:center\">" );
					out.println( "You must <A HRef=\"CFIntSMWarAddDeviceHtml\">Add A Default Device</A> before doing anything else." );
				}
				else {
					out.println( "<p style=\"text-align:center\"><button type=\"button\" name=\"AddDevice\"\" onclick=\"window.location.href='CFIntSMWarChangePasswordHtml'\">Change Password</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"AddDevice\"\" onclick=\"window.location.href='CFIntSMWarAddDeviceHtml'\">Add Device</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Logout\"\" onclick=\"window.location.href='CFIntSMWarLogoutHtml'\">Log Out</button>" );
				}
				out.println( "</form>" );
				out.println( "</BODY>" );
				out.println( "</HTML>" );
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
}
