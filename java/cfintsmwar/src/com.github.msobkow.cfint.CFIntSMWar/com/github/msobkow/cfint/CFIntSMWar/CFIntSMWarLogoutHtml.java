
// Description: Java 11 Sec Manager Logout Servlet

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
 * Servlet implementation class CFIntSMWarLoginHtml
 */
@WebServlet("/CFIntSMWarLogoutHtml")
public class CFIntSMWarLogoutHtml extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CFIntSMWarLogoutHtml() {
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
				out.println( "<form method=\"post\" formaction=\"CFIntSMWarLogoutHtml\">" );
				out.println( "<H1 style=\"text-align:center\">" + clusterDescription + " Sec Manager</H1>" );
				out.println( "<H2 style=\"text-align:center\">Are you sure you want to log out from "
						+ secUser.getRequiredEMailAddress()
						+ "?</H2>" );
				out.println( "<table style=\"width:60%\">" );
				out.println( "<tr><td style=\"text-align:center\"><button type=\"submit\" name=\"Ok\"\">Yes, log out</button></td><td style=\"text-align:center\"><button type=\"button\" name=\"Cancel\"\" onclick=\"window.location.href='CFIntSMWarSecMainHtml'\">Continue Session</button></td></tr>" );
				out.println( "<p>" );
				out.println( "</table>" );
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
				ICFSecSecSessionObj secSession = schemaObj.getSecSessionTableObj().readSecSessionByIdIdx( auth.getSecSessionId() );
				if( secSession == null ) {
					schemaObj.setAuthorization( null );
					schemaObj.minimizeMemory();
					response.sendRedirect( "CFIntSMWarLoginHtml" );
				}
				else {

					ICFSecSecUserObj systemUser = schemaObj.getSecUserTableObj().readSecUserByULoginIdx( "system" );

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

					ICFSecSecSessionEditObj editSecSession = (ICFSecSecSessionEditObj)secSession.beginEdit();
					if( editSecSession.getOptionalFinish() == null ) {
						editSecSession.setOptionalFinish( Calendar.getInstance() );
					}

					editSecSession.update();
					editSecSession = null;

					editSystemSession = systemSession.beginEdit();
					editSystemSession.setOptionalFinish( Calendar.getInstance() );
					editSystemSession.update();
					editSystemSession = null;

					schemaObj.commit();
					schemaObj.setAuthorization( null );
					schemaObj.minimizeMemory();
					response.sendRedirect( "CFIntSMWarLoginHtml" );
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
			sess.setAttribute( "SchemaObj", null );
		}
	}
}