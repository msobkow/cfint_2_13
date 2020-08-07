
// Description: Java 11 Sec Manager Make Default Device Servlet

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
import java.util.Calendar;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/**
 * Servlet implementation class CFIntSMWarLoginHtml
 */
@WebServlet("/CFIntSMWarMakeDefaultDeviceHtml")
public class CFIntSMWarMakeDefaultDeviceHtml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFIntSMWarMakeDefaultDeviceHtml() {
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

		CFSecAuthorization auth = schemaObj.getAuthorization();
		if( auth == null ) {
			response.sendRedirect( "CFIntSMWarLoginHtml" );
			return;
		}

		String deviceName = request.getParameter( "DeviceName" );
		if( ( deviceName == null ) || ( deviceName.length() <= 0 ) ) {
			response.sendRedirect( "CFIntSMWarSecMainHtml" );
			return;
		}

		ICFIntSchema dbSchema = null;
		try {
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

			String thisURI = request.getScheme()
				+	"://"
				+	request.getServerName()
				+	":"
				+	request.getServerPort()
				+	request.getRequestURI().toString();
			int lastSlash = thisURI.lastIndexOf( '/' );
			String baseURI = thisURI.substring( 0, lastSlash );

			response.setContentType( "text/html" );
			PrintWriter out = response.getWriter();
			out.println( "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">" );
			out.println( "<HTML>" );
			out.println( "<BODY>" );
			out.println( "<form method=\"post\" formaction=\"CFIntSMWarDeleteDeviceHtml\">" );
			out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
			out.println( "<H2 style=\"text-align:center\">Make device "
					+ deviceName
					+ " the default for "
					+ secUser.getRequiredEMailAddress()
					+ "</H2>" );
			out.println( "<p style=\"text-align:center\">" );
			out.println( "Are you sure you want to make the following device your default?" );
			out.println( "<table style=\"width:90%\">" );
			out.println( "<tr><th style=\"text-align:left\">Device Name:</th><td><input disabled type=\"text\" name=\"DeviceName\" value=\"" + deviceName + "\"/></td></tr>");
			out.println( "</table>" );
			out.println( "<p style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Make Default</button>&nbsp;&nbsp;&nbsp;&nbsp;<button type=\"button\" name=\"Cancel\"\" onclick=\"window.location.href='CFIntSMWarSecMainHtml'\">Cancel</button>" );
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
				response.sendRedirect( "CFIntSMWarLoginHtml" );
				return;
			}
		}

		CFSecAuthorization auth = schemaObj.getAuthorization();
		if( auth == null ) {
			response.sendRedirect( "CFIntSMWarLoginHtml" );
			return;
		}

		String deviceName = request.getParameter( "DeviceName" );
		if( ( deviceName == null ) || ( deviceName.length() <= 0 ) ) {
			response.sendRedirect( "CFIntSMWarSecMainHtml" );
			return;
		}

		ICFIntSchema dbSchema = null;
		try {
			dbSchema = (ICFIntSchema)CFIntSchemaPool.getSchemaPool().getInstance();
			schemaObj.setBackingStore( dbSchema );
			schemaObj.beginTransaction();
			ICFSecSecUserObj secUser = schemaObj.getSecUserTableObj().readSecUserByIdIdx( auth.getSecUserId() );
			ICFSecSecDeviceObj secDev = schemaObj.getSecDeviceTableObj().readSecDeviceByIdIdx( secUser.getRequiredSecUserId(), deviceName );
			if( secDev == null ) {
				response.sendRedirect( "CFIntSMWarSecMainHtml" );
				return;
			}

			if( secDev == secUser.getOptionalLookupDefDev() ) {
				response.sendRedirect( "CFIntSMWarSecMainHtml" );
				return;
			}

			ICFSecClusterObj systemCluster = schemaObj.getClusterTableObj().readClusterByUDomNameIdx( "system" );
			ICFSecTenantObj systemTenant = schemaObj.getTenantTableObj().readTenantByUNameIdx( systemCluster.getRequiredId(), "system" );
			ICFSecSecUserObj systemUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );
			ICFSecSecSessionObj systemSession = schemaObj.getSecSessionTableObj().newInstance();
			ICFSecSecSessionEditObj editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
			editSystemSession.setRequiredContainerSecUser( systemUser );
			editSystemSession.setRequiredStart( Calendar.getInstance() );
			systemSession = editSystemSession.create();
			editSystemSession = null;

			CFSecAuthorization secAuth = new CFSecAuthorization();
			secAuth.setSecCluster( systemCluster );
			secAuth.setSecTenant( systemTenant );
			secAuth.setSecSession( systemSession );
			schemaObj.setAuthorization( secAuth );

			ICFSecSecUserEditObj editSecUser = secUser.beginEdit();
			editSecUser.setOptionalLookupDefDev( secDev );
			editSecUser.update();
			editSecUser = null;

			editSystemSession = (ICFSecSecSessionEditObj)systemSession.beginEdit();
			editSystemSession.setOptionalFinish( Calendar.getInstance() );
			editSystemSession.update();
			editSystemSession = null;

			schemaObj.commit();

			schemaObj.setAuthorization( auth );

			response.sendRedirect( "CFIntSMWarSecMainHtml" );
		}
		catch( RuntimeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught RuntimeException -- " + e.getMessage(),
				e );
		}
		finally {
			schemaObj.setAuthorization( auth );
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