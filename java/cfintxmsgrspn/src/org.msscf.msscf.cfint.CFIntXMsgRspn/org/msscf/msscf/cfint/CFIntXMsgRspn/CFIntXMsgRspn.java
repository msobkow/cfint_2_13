// Description: Java 11 XML SAX Request Message  for CFInt.

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

package org.msscf.msscf.cfint.CFIntXMsgRspn;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.net.URISyntaxException;
import java.net.URL;

import org.xml.sax.*;
import org.apache.commons.codec.binary.Base64;
import org.apache.xerces.xni.grammars.Grammar;

import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.Tip.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

public class CFIntXMsgRspn
	extends CFLibXmlCoreSaxParser
	implements ContentHandler,
		ICFTipResponseHandler
{

	// The namespace URI of the supported schema
	public final static String	SCHEMA_XMLNS = "uri://xsd/cfintrspn";

	// The source for loading the supported schema
	public final static String	SCHEMA_URI = "/opt/msscf/2.0.13/xsd/cfint-rspn.xsd";
	public final static String	SCHEMA_ROOT_URI = "/xsd/cfint-rqst.rspn";
	public final static String CFSEC_XMLNS = "uri://xsd/cfsecrspn";
	public final static String CFSEC_URI = "/opt/msscf/2.0.13/xsd/cfsec-rspn.xsd";
	public final static String CFSEC_ROOT_URI = "/xsd/cfsec-rspn.xsd";

	protected static Grammar myGrammar = null;

	// The schema instance to load in to

	private ICFIntSchemaObj schemaObj = null;
	private boolean deleted = false;
	private RuntimeException exceptionRaised = null;
	private Object lastObjectProcessed = null;
	private Object sortedListOfObjects = null;
	private String logContent = null;
	private boolean dataChanged = false;
	// Constructors

	public CFIntXMsgRspn() {
		super();
		setRootElementHandler( getSaxRspnRoot() );
		if( myGrammar == null ) {
			InputStream input;
			File file = new File( SCHEMA_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( SCHEMA_ROOT_URI );
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_ROOT_URI, input );
				}
			}
			file = new File( CFSEC_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					addToGrammarPool( CFSEC_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( CFSEC_ROOT_URI );
				if( input != null ) {
					addToGrammarPool( CFSEC_ROOT_URI, input );
				}
			}
		}
		initParser();
		setSchemaObj( null );
	}

	public CFIntXMsgRspn( CFIntSchemaObj schemaObj ) {
		super();
		setRootElementHandler( getSaxRspnRoot() );
		if( myGrammar == null ) {
			InputStream input;
			File file = new File( SCHEMA_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( SCHEMA_ROOT_URI );
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_ROOT_URI, input );
				}
			}
			file = new File( CFSEC_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					addToGrammarPool( CFSEC_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( CFSEC_ROOT_URI );
				if( input != null ) {
					addToGrammarPool( CFSEC_ROOT_URI, input );
				}
			}
		}
		initParser();
		setSchemaObj( schemaObj );
	}

	public CFIntXMsgRspn( ICFLibMessageLog logger ) {
		super( logger );
		setRootElementHandler( getSaxRspnRoot() );
		if( myGrammar == null ) {
			InputStream input;
			File file = new File( SCHEMA_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( SCHEMA_ROOT_URI );
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_ROOT_URI, input );
				}
			}
			file = new File( CFSEC_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					addToGrammarPool( CFSEC_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( CFSEC_ROOT_URI );
				if( input != null ) {
					addToGrammarPool( CFSEC_ROOT_URI, input );
				}
			}
		}
		initParser();
		setSchemaObj( null );
	}

	public CFIntXMsgRspn( CFIntSchemaObj schemaObj, ICFLibMessageLog logger ) {
		super( logger );
		setRootElementHandler( getSaxRspnRoot() );
		if( myGrammar == null ) {
			InputStream input;
			File file = new File( SCHEMA_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( SCHEMA_ROOT_URI );
				if( input != null ) {
					myGrammar = addToGrammarPool( SCHEMA_ROOT_URI, input );
				}
			}
			file = new File( CFSEC_URI );
			if( file.exists() ) {
				try {
					input = new FileInputStream( file );
				}
				catch( Exception e ) {
					input = null;
				}
				if( input != null ) {
					addToGrammarPool( CFSEC_URI, input );
				}
			}
			else {
				input = getClass().getResourceAsStream( CFSEC_ROOT_URI );
				if( input != null ) {
					addToGrammarPool( CFSEC_ROOT_URI, input );
				}
			}
		}
		initParser();
		setSchemaObj( schemaObj );
	}

	// Element  instances

	private CFIntXMsgRspnNoDataFound rspnNoDataFound = null;
	private CFIntXMsgRspnException rspnException = null;
	private CFIntXMsgRspnFileLoaded rspnFileLoaded = null;
	private CFIntXMsgRspnLoggedIn rspnLoggedIn = null;
	private CFIntXMsgRspnLoggedOut rspnLoggedOut = null;
	private CFIntXMsgRspnServerProcExecuted rspnServerProcExecuted = null;

	// Cluster Response s
	private CFIntXMsgRspnClusterRec rspnClusterRec = null;
	private CFIntXMsgRspnClusterCreated rspnClusterCreated = null;
	private CFIntXMsgRspnClusterReadSingle rspnClusterReadSingle = null;
	private CFIntXMsgRspnClusterReadList rspnClusterReadList = null;
	private CFIntXMsgRspnClusterLocked rspnClusterLocked = null;
	private CFIntXMsgRspnClusterUpdated rspnClusterUpdated = null;
	private CFIntXMsgRspnClusterDeleted rspnClusterDeleted = null;

	// HostNode Response s
	private CFIntXMsgRspnHostNodeRec rspnHostNodeRec = null;
	private CFIntXMsgRspnHostNodeCreated rspnHostNodeCreated = null;
	private CFIntXMsgRspnHostNodeReadSingle rspnHostNodeReadSingle = null;
	private CFIntXMsgRspnHostNodeReadList rspnHostNodeReadList = null;
	private CFIntXMsgRspnHostNodeLocked rspnHostNodeLocked = null;
	private CFIntXMsgRspnHostNodeUpdated rspnHostNodeUpdated = null;
	private CFIntXMsgRspnHostNodeDeleted rspnHostNodeDeleted = null;

	// ISOCcy Response s
	private CFIntXMsgRspnISOCcyRec rspnISOCcyRec = null;
	private CFIntXMsgRspnISOCcyCreated rspnISOCcyCreated = null;
	private CFIntXMsgRspnISOCcyReadSingle rspnISOCcyReadSingle = null;
	private CFIntXMsgRspnISOCcyReadList rspnISOCcyReadList = null;
	private CFIntXMsgRspnISOCcyLocked rspnISOCcyLocked = null;
	private CFIntXMsgRspnISOCcyUpdated rspnISOCcyUpdated = null;
	private CFIntXMsgRspnISOCcyDeleted rspnISOCcyDeleted = null;

	// ISOCtry Response s
	private CFIntXMsgRspnISOCtryRec rspnISOCtryRec = null;
	private CFIntXMsgRspnISOCtryCreated rspnISOCtryCreated = null;
	private CFIntXMsgRspnISOCtryReadSingle rspnISOCtryReadSingle = null;
	private CFIntXMsgRspnISOCtryReadList rspnISOCtryReadList = null;
	private CFIntXMsgRspnISOCtryLocked rspnISOCtryLocked = null;
	private CFIntXMsgRspnISOCtryUpdated rspnISOCtryUpdated = null;
	private CFIntXMsgRspnISOCtryDeleted rspnISOCtryDeleted = null;

	// ISOCtryCcy Response s
	private CFIntXMsgRspnISOCtryCcyRec rspnISOCtryCcyRec = null;
	private CFIntXMsgRspnISOCtryCcyCreated rspnISOCtryCcyCreated = null;
	private CFIntXMsgRspnISOCtryCcyReadSingle rspnISOCtryCcyReadSingle = null;
	private CFIntXMsgRspnISOCtryCcyReadList rspnISOCtryCcyReadList = null;
	private CFIntXMsgRspnISOCtryCcyLocked rspnISOCtryCcyLocked = null;
	private CFIntXMsgRspnISOCtryCcyUpdated rspnISOCtryCcyUpdated = null;
	private CFIntXMsgRspnISOCtryCcyDeleted rspnISOCtryCcyDeleted = null;

	// ISOCtryLang Response s
	private CFIntXMsgRspnISOCtryLangRec rspnISOCtryLangRec = null;
	private CFIntXMsgRspnISOCtryLangCreated rspnISOCtryLangCreated = null;
	private CFIntXMsgRspnISOCtryLangReadSingle rspnISOCtryLangReadSingle = null;
	private CFIntXMsgRspnISOCtryLangReadList rspnISOCtryLangReadList = null;
	private CFIntXMsgRspnISOCtryLangLocked rspnISOCtryLangLocked = null;
	private CFIntXMsgRspnISOCtryLangUpdated rspnISOCtryLangUpdated = null;
	private CFIntXMsgRspnISOCtryLangDeleted rspnISOCtryLangDeleted = null;

	// ISOLang Response s
	private CFIntXMsgRspnISOLangRec rspnISOLangRec = null;
	private CFIntXMsgRspnISOLangCreated rspnISOLangCreated = null;
	private CFIntXMsgRspnISOLangReadSingle rspnISOLangReadSingle = null;
	private CFIntXMsgRspnISOLangReadList rspnISOLangReadList = null;
	private CFIntXMsgRspnISOLangLocked rspnISOLangLocked = null;
	private CFIntXMsgRspnISOLangUpdated rspnISOLangUpdated = null;
	private CFIntXMsgRspnISOLangDeleted rspnISOLangDeleted = null;

	// ISOTZone Response s
	private CFIntXMsgRspnISOTZoneRec rspnISOTZoneRec = null;
	private CFIntXMsgRspnISOTZoneCreated rspnISOTZoneCreated = null;
	private CFIntXMsgRspnISOTZoneReadSingle rspnISOTZoneReadSingle = null;
	private CFIntXMsgRspnISOTZoneReadList rspnISOTZoneReadList = null;
	private CFIntXMsgRspnISOTZoneLocked rspnISOTZoneLocked = null;
	private CFIntXMsgRspnISOTZoneUpdated rspnISOTZoneUpdated = null;
	private CFIntXMsgRspnISOTZoneDeleted rspnISOTZoneDeleted = null;

	// License Response s
	private CFIntXMsgRspnLicenseRec rspnLicenseRec = null;
	private CFIntXMsgRspnLicenseCreated rspnLicenseCreated = null;
	private CFIntXMsgRspnLicenseReadSingle rspnLicenseReadSingle = null;
	private CFIntXMsgRspnLicenseReadList rspnLicenseReadList = null;
	private CFIntXMsgRspnLicenseLocked rspnLicenseLocked = null;
	private CFIntXMsgRspnLicenseUpdated rspnLicenseUpdated = null;
	private CFIntXMsgRspnLicenseDeleted rspnLicenseDeleted = null;

	// MajorVersion Response s
	private CFIntXMsgRspnMajorVersionRec rspnMajorVersionRec = null;
	private CFIntXMsgRspnMajorVersionCreated rspnMajorVersionCreated = null;
	private CFIntXMsgRspnMajorVersionReadSingle rspnMajorVersionReadSingle = null;
	private CFIntXMsgRspnMajorVersionReadList rspnMajorVersionReadList = null;
	private CFIntXMsgRspnMajorVersionLocked rspnMajorVersionLocked = null;
	private CFIntXMsgRspnMajorVersionUpdated rspnMajorVersionUpdated = null;
	private CFIntXMsgRspnMajorVersionDeleted rspnMajorVersionDeleted = null;

	// MimeType Response s
	private CFIntXMsgRspnMimeTypeRec rspnMimeTypeRec = null;
	private CFIntXMsgRspnMimeTypeCreated rspnMimeTypeCreated = null;
	private CFIntXMsgRspnMimeTypeReadSingle rspnMimeTypeReadSingle = null;
	private CFIntXMsgRspnMimeTypeReadList rspnMimeTypeReadList = null;
	private CFIntXMsgRspnMimeTypeLocked rspnMimeTypeLocked = null;
	private CFIntXMsgRspnMimeTypeUpdated rspnMimeTypeUpdated = null;
	private CFIntXMsgRspnMimeTypeDeleted rspnMimeTypeDeleted = null;

	// MinorVersion Response s
	private CFIntXMsgRspnMinorVersionRec rspnMinorVersionRec = null;
	private CFIntXMsgRspnMinorVersionCreated rspnMinorVersionCreated = null;
	private CFIntXMsgRspnMinorVersionReadSingle rspnMinorVersionReadSingle = null;
	private CFIntXMsgRspnMinorVersionReadList rspnMinorVersionReadList = null;
	private CFIntXMsgRspnMinorVersionLocked rspnMinorVersionLocked = null;
	private CFIntXMsgRspnMinorVersionUpdated rspnMinorVersionUpdated = null;
	private CFIntXMsgRspnMinorVersionDeleted rspnMinorVersionDeleted = null;

	// SecApp Response s
	private CFIntXMsgRspnSecAppRec rspnSecAppRec = null;
	private CFIntXMsgRspnSecAppCreated rspnSecAppCreated = null;
	private CFIntXMsgRspnSecAppReadSingle rspnSecAppReadSingle = null;
	private CFIntXMsgRspnSecAppReadList rspnSecAppReadList = null;
	private CFIntXMsgRspnSecAppLocked rspnSecAppLocked = null;
	private CFIntXMsgRspnSecAppUpdated rspnSecAppUpdated = null;
	private CFIntXMsgRspnSecAppDeleted rspnSecAppDeleted = null;

	// SecDevice Response s
	private CFIntXMsgRspnSecDeviceRec rspnSecDeviceRec = null;
	private CFIntXMsgRspnSecDeviceCreated rspnSecDeviceCreated = null;
	private CFIntXMsgRspnSecDeviceReadSingle rspnSecDeviceReadSingle = null;
	private CFIntXMsgRspnSecDeviceReadList rspnSecDeviceReadList = null;
	private CFIntXMsgRspnSecDeviceLocked rspnSecDeviceLocked = null;
	private CFIntXMsgRspnSecDeviceUpdated rspnSecDeviceUpdated = null;
	private CFIntXMsgRspnSecDeviceDeleted rspnSecDeviceDeleted = null;

	// SecForm Response s
	private CFIntXMsgRspnSecFormRec rspnSecFormRec = null;
	private CFIntXMsgRspnSecFormCreated rspnSecFormCreated = null;
	private CFIntXMsgRspnSecFormReadSingle rspnSecFormReadSingle = null;
	private CFIntXMsgRspnSecFormReadList rspnSecFormReadList = null;
	private CFIntXMsgRspnSecFormLocked rspnSecFormLocked = null;
	private CFIntXMsgRspnSecFormUpdated rspnSecFormUpdated = null;
	private CFIntXMsgRspnSecFormDeleted rspnSecFormDeleted = null;

	// SecGroup Response s
	private CFIntXMsgRspnSecGroupRec rspnSecGroupRec = null;
	private CFIntXMsgRspnSecGroupCreated rspnSecGroupCreated = null;
	private CFIntXMsgRspnSecGroupReadSingle rspnSecGroupReadSingle = null;
	private CFIntXMsgRspnSecGroupReadList rspnSecGroupReadList = null;
	private CFIntXMsgRspnSecGroupLocked rspnSecGroupLocked = null;
	private CFIntXMsgRspnSecGroupUpdated rspnSecGroupUpdated = null;
	private CFIntXMsgRspnSecGroupDeleted rspnSecGroupDeleted = null;

	// SecGroupForm Response s
	private CFIntXMsgRspnSecGroupFormRec rspnSecGroupFormRec = null;
	private CFIntXMsgRspnSecGroupFormCreated rspnSecGroupFormCreated = null;
	private CFIntXMsgRspnSecGroupFormReadSingle rspnSecGroupFormReadSingle = null;
	private CFIntXMsgRspnSecGroupFormReadList rspnSecGroupFormReadList = null;
	private CFIntXMsgRspnSecGroupFormLocked rspnSecGroupFormLocked = null;
	private CFIntXMsgRspnSecGroupFormUpdated rspnSecGroupFormUpdated = null;
	private CFIntXMsgRspnSecGroupFormDeleted rspnSecGroupFormDeleted = null;

	// SecGrpInc Response s
	private CFIntXMsgRspnSecGrpIncRec rspnSecGrpIncRec = null;
	private CFIntXMsgRspnSecGrpIncCreated rspnSecGrpIncCreated = null;
	private CFIntXMsgRspnSecGrpIncReadSingle rspnSecGrpIncReadSingle = null;
	private CFIntXMsgRspnSecGrpIncReadList rspnSecGrpIncReadList = null;
	private CFIntXMsgRspnSecGrpIncLocked rspnSecGrpIncLocked = null;
	private CFIntXMsgRspnSecGrpIncUpdated rspnSecGrpIncUpdated = null;
	private CFIntXMsgRspnSecGrpIncDeleted rspnSecGrpIncDeleted = null;

	// SecGrpMemb Response s
	private CFIntXMsgRspnSecGrpMembRec rspnSecGrpMembRec = null;
	private CFIntXMsgRspnSecGrpMembCreated rspnSecGrpMembCreated = null;
	private CFIntXMsgRspnSecGrpMembReadSingle rspnSecGrpMembReadSingle = null;
	private CFIntXMsgRspnSecGrpMembReadList rspnSecGrpMembReadList = null;
	private CFIntXMsgRspnSecGrpMembLocked rspnSecGrpMembLocked = null;
	private CFIntXMsgRspnSecGrpMembUpdated rspnSecGrpMembUpdated = null;
	private CFIntXMsgRspnSecGrpMembDeleted rspnSecGrpMembDeleted = null;

	// SecSession Response s
	private CFIntXMsgRspnSecSessionRec rspnSecSessionRec = null;
	private CFIntXMsgRspnSecSessionCreated rspnSecSessionCreated = null;
	private CFIntXMsgRspnSecSessionReadSingle rspnSecSessionReadSingle = null;
	private CFIntXMsgRspnSecSessionReadList rspnSecSessionReadList = null;
	private CFIntXMsgRspnSecSessionLocked rspnSecSessionLocked = null;
	private CFIntXMsgRspnSecSessionUpdated rspnSecSessionUpdated = null;
	private CFIntXMsgRspnSecSessionDeleted rspnSecSessionDeleted = null;

	// SecUser Response s
	private CFIntXMsgRspnSecUserRec rspnSecUserRec = null;
	private CFIntXMsgRspnSecUserCreated rspnSecUserCreated = null;
	private CFIntXMsgRspnSecUserReadSingle rspnSecUserReadSingle = null;
	private CFIntXMsgRspnSecUserReadList rspnSecUserReadList = null;
	private CFIntXMsgRspnSecUserLocked rspnSecUserLocked = null;
	private CFIntXMsgRspnSecUserUpdated rspnSecUserUpdated = null;
	private CFIntXMsgRspnSecUserDeleted rspnSecUserDeleted = null;

	// Service Response s
	private CFIntXMsgRspnServiceRec rspnServiceRec = null;
	private CFIntXMsgRspnServiceCreated rspnServiceCreated = null;
	private CFIntXMsgRspnServiceReadSingle rspnServiceReadSingle = null;
	private CFIntXMsgRspnServiceReadList rspnServiceReadList = null;
	private CFIntXMsgRspnServiceLocked rspnServiceLocked = null;
	private CFIntXMsgRspnServiceUpdated rspnServiceUpdated = null;
	private CFIntXMsgRspnServiceDeleted rspnServiceDeleted = null;

	// ServiceType Response s
	private CFIntXMsgRspnServiceTypeRec rspnServiceTypeRec = null;
	private CFIntXMsgRspnServiceTypeCreated rspnServiceTypeCreated = null;
	private CFIntXMsgRspnServiceTypeReadSingle rspnServiceTypeReadSingle = null;
	private CFIntXMsgRspnServiceTypeReadList rspnServiceTypeReadList = null;
	private CFIntXMsgRspnServiceTypeLocked rspnServiceTypeLocked = null;
	private CFIntXMsgRspnServiceTypeUpdated rspnServiceTypeUpdated = null;
	private CFIntXMsgRspnServiceTypeDeleted rspnServiceTypeDeleted = null;

	// SubProject Response s
	private CFIntXMsgRspnSubProjectRec rspnSubProjectRec = null;
	private CFIntXMsgRspnSubProjectCreated rspnSubProjectCreated = null;
	private CFIntXMsgRspnSubProjectReadSingle rspnSubProjectReadSingle = null;
	private CFIntXMsgRspnSubProjectReadList rspnSubProjectReadList = null;
	private CFIntXMsgRspnSubProjectLocked rspnSubProjectLocked = null;
	private CFIntXMsgRspnSubProjectUpdated rspnSubProjectUpdated = null;
	private CFIntXMsgRspnSubProjectDeleted rspnSubProjectDeleted = null;

	// SysCluster Response s
	private CFIntXMsgRspnSysClusterRec rspnSysClusterRec = null;
	private CFIntXMsgRspnSysClusterCreated rspnSysClusterCreated = null;
	private CFIntXMsgRspnSysClusterReadSingle rspnSysClusterReadSingle = null;
	private CFIntXMsgRspnSysClusterReadList rspnSysClusterReadList = null;
	private CFIntXMsgRspnSysClusterLocked rspnSysClusterLocked = null;
	private CFIntXMsgRspnSysClusterUpdated rspnSysClusterUpdated = null;
	private CFIntXMsgRspnSysClusterDeleted rspnSysClusterDeleted = null;

	// TSecGroup Response s
	private CFIntXMsgRspnTSecGroupRec rspnTSecGroupRec = null;
	private CFIntXMsgRspnTSecGroupCreated rspnTSecGroupCreated = null;
	private CFIntXMsgRspnTSecGroupReadSingle rspnTSecGroupReadSingle = null;
	private CFIntXMsgRspnTSecGroupReadList rspnTSecGroupReadList = null;
	private CFIntXMsgRspnTSecGroupLocked rspnTSecGroupLocked = null;
	private CFIntXMsgRspnTSecGroupUpdated rspnTSecGroupUpdated = null;
	private CFIntXMsgRspnTSecGroupDeleted rspnTSecGroupDeleted = null;

	// TSecGrpInc Response s
	private CFIntXMsgRspnTSecGrpIncRec rspnTSecGrpIncRec = null;
	private CFIntXMsgRspnTSecGrpIncCreated rspnTSecGrpIncCreated = null;
	private CFIntXMsgRspnTSecGrpIncReadSingle rspnTSecGrpIncReadSingle = null;
	private CFIntXMsgRspnTSecGrpIncReadList rspnTSecGrpIncReadList = null;
	private CFIntXMsgRspnTSecGrpIncLocked rspnTSecGrpIncLocked = null;
	private CFIntXMsgRspnTSecGrpIncUpdated rspnTSecGrpIncUpdated = null;
	private CFIntXMsgRspnTSecGrpIncDeleted rspnTSecGrpIncDeleted = null;

	// TSecGrpMemb Response s
	private CFIntXMsgRspnTSecGrpMembRec rspnTSecGrpMembRec = null;
	private CFIntXMsgRspnTSecGrpMembCreated rspnTSecGrpMembCreated = null;
	private CFIntXMsgRspnTSecGrpMembReadSingle rspnTSecGrpMembReadSingle = null;
	private CFIntXMsgRspnTSecGrpMembReadList rspnTSecGrpMembReadList = null;
	private CFIntXMsgRspnTSecGrpMembLocked rspnTSecGrpMembLocked = null;
	private CFIntXMsgRspnTSecGrpMembUpdated rspnTSecGrpMembUpdated = null;
	private CFIntXMsgRspnTSecGrpMembDeleted rspnTSecGrpMembDeleted = null;

	// Tenant Response s
	private CFIntXMsgRspnTenantRec rspnTenantRec = null;
	private CFIntXMsgRspnTenantCreated rspnTenantCreated = null;
	private CFIntXMsgRspnTenantReadSingle rspnTenantReadSingle = null;
	private CFIntXMsgRspnTenantReadList rspnTenantReadList = null;
	private CFIntXMsgRspnTenantLocked rspnTenantLocked = null;
	private CFIntXMsgRspnTenantUpdated rspnTenantUpdated = null;
	private CFIntXMsgRspnTenantDeleted rspnTenantDeleted = null;

	// Tld Response s
	private CFIntXMsgRspnTldRec rspnTldRec = null;
	private CFIntXMsgRspnTldCreated rspnTldCreated = null;
	private CFIntXMsgRspnTldReadSingle rspnTldReadSingle = null;
	private CFIntXMsgRspnTldReadList rspnTldReadList = null;
	private CFIntXMsgRspnTldLocked rspnTldLocked = null;
	private CFIntXMsgRspnTldUpdated rspnTldUpdated = null;
	private CFIntXMsgRspnTldDeleted rspnTldDeleted = null;

	// TopDomain Response s
	private CFIntXMsgRspnTopDomainRec rspnTopDomainRec = null;
	private CFIntXMsgRspnTopDomainCreated rspnTopDomainCreated = null;
	private CFIntXMsgRspnTopDomainReadSingle rspnTopDomainReadSingle = null;
	private CFIntXMsgRspnTopDomainReadList rspnTopDomainReadList = null;
	private CFIntXMsgRspnTopDomainLocked rspnTopDomainLocked = null;
	private CFIntXMsgRspnTopDomainUpdated rspnTopDomainUpdated = null;
	private CFIntXMsgRspnTopDomainDeleted rspnTopDomainDeleted = null;

	// TopProject Response s
	private CFIntXMsgRspnTopProjectRec rspnTopProjectRec = null;
	private CFIntXMsgRspnTopProjectCreated rspnTopProjectCreated = null;
	private CFIntXMsgRspnTopProjectReadSingle rspnTopProjectReadSingle = null;
	private CFIntXMsgRspnTopProjectReadList rspnTopProjectReadList = null;
	private CFIntXMsgRspnTopProjectLocked rspnTopProjectLocked = null;
	private CFIntXMsgRspnTopProjectUpdated rspnTopProjectUpdated = null;
	private CFIntXMsgRspnTopProjectDeleted rspnTopProjectDeleted = null;

	// URLProtocol Response s
	private CFIntXMsgRspnURLProtocolRec rspnURLProtocolRec = null;
	private CFIntXMsgRspnURLProtocolCreated rspnURLProtocolCreated = null;
	private CFIntXMsgRspnURLProtocolReadSingle rspnURLProtocolReadSingle = null;
	private CFIntXMsgRspnURLProtocolReadList rspnURLProtocolReadList = null;
	private CFIntXMsgRspnURLProtocolLocked rspnURLProtocolLocked = null;
	private CFIntXMsgRspnURLProtocolUpdated rspnURLProtocolUpdated = null;
	private CFIntXMsgRspnURLProtocolDeleted rspnURLProtocolDeleted = null;
	private CFIntSaxRspnRoot saxRoot = null;

	private CFIntSaxRspnDoc saxDoc = null;

	// Schema object accessors

	// SchemaObj accessors

	public ICFIntSchemaObj getSchemaObj() {
		return( schemaObj );
	}

	public void setSchemaObj( ICFIntSchemaObj value ) {
		schemaObj = value;
	}

	// Result accessors

	public String getLogContent() {
		return( logContent);
	}

	public void setLogContent( String value ) {
		logContent = value;
	}

	public boolean getDataChanged() {
		return( dataChanged);
	}

	public void setDataChanged( boolean value ) {
		dataChanged = value;
	}

	public boolean getDeleted() {
		return( deleted );
	}

	public void setDeleted( boolean flag ) {
		deleted = flag;
	}

	public RuntimeException getExceptionRaised() {
		return( exceptionRaised );
	}

	public void setExceptionRaised( RuntimeException obj ) {
		exceptionRaised = obj;
	}

	public Object getLastObjectProcessed() {
		return( lastObjectProcessed );
	}

	public void setLastObjectProcessed( Object obj ) {
		lastObjectProcessed = obj;
	}

	public Object getListOfObjects() {
		return( sortedListOfObjects );
	}

	public void setListOfObjects( Object obj ) {
		sortedListOfObjects = obj;
	}

	// Element  Resolver Factories

	protected CFIntXMsgRspnNoDataFound getRspnNoDataFound() {
		if( rspnNoDataFound == null ) {
			rspnNoDataFound = new CFIntXMsgRspnNoDataFound( this );
		}
		return( rspnNoDataFound );
	}

	protected CFIntXMsgRspnException getRspnException() {
		if( rspnException == null ) {
			rspnException = new CFIntXMsgRspnException( this );
		}
		return( rspnException );
	}

	protected CFIntXMsgRspnFileLoaded getRspnFileLoaded() {
		if( rspnFileLoaded == null ) {
			rspnFileLoaded = new CFIntXMsgRspnFileLoaded( this );
		}
		return( rspnFileLoaded );
	}

	protected CFIntXMsgRspnLoggedIn getRspnLoggedIn() {
		if( rspnLoggedIn == null ) {
			rspnLoggedIn = new CFIntXMsgRspnLoggedIn( this );
		}
		return( rspnLoggedIn );
	}

	protected CFIntXMsgRspnLoggedOut getRspnLoggedOut() {
		if( rspnLoggedOut == null ) {
			rspnLoggedOut = new CFIntXMsgRspnLoggedOut( this );
		}
		return( rspnLoggedOut );
	}

	protected CFIntXMsgRspnServerProcExecuted getRspnServerProcExecuted() {
		if( rspnServerProcExecuted == null ) {
			rspnServerProcExecuted = new CFIntXMsgRspnServerProcExecuted( this );
		}
		return( rspnServerProcExecuted );
	}

	// Cluster Response s

	protected CFIntXMsgRspnClusterRec getRspnClusterRec() {
		if( rspnClusterRec == null ) {
			rspnClusterRec = new CFIntXMsgRspnClusterRec( this );
		}
		return( rspnClusterRec );
	}

	protected CFIntXMsgRspnClusterCreated getRspnClusterCreated() {
		if( rspnClusterCreated == null ) {
			rspnClusterCreated = new CFIntXMsgRspnClusterCreated( this );
		}
		return( rspnClusterCreated );
	}

	protected CFIntXMsgRspnClusterReadSingle getRspnClusterReadSingle() {
		if( rspnClusterReadSingle == null ) {
			rspnClusterReadSingle = new CFIntXMsgRspnClusterReadSingle( this );
			rspnClusterReadSingle.addElementHandler( "Cluster", getRspnClusterRec() );
		}
		return( rspnClusterReadSingle );
	}

	protected CFIntXMsgRspnClusterReadList getRspnClusterReadList() {
		if( rspnClusterReadList == null ) {
			rspnClusterReadList = new CFIntXMsgRspnClusterReadList( this );
			rspnClusterReadList.addElementHandler( "Cluster", getRspnClusterRec() );
		}
		return( rspnClusterReadList );
	}

	protected CFIntXMsgRspnClusterLocked getRspnClusterLocked() {
		if( rspnClusterLocked == null ) {
			rspnClusterLocked = new CFIntXMsgRspnClusterLocked( this );
		}
		return( rspnClusterLocked );
	}

	protected CFIntXMsgRspnClusterUpdated getRspnClusterUpdated() {
		if( rspnClusterUpdated == null ) {
			rspnClusterUpdated = new CFIntXMsgRspnClusterUpdated( this );
		}
		return( rspnClusterUpdated );
	}

	protected CFIntXMsgRspnClusterDeleted getRspnClusterDeleted() {
		if( rspnClusterDeleted == null ) {
			rspnClusterDeleted = new CFIntXMsgRspnClusterDeleted( this );
		}
		return( rspnClusterDeleted );
	}

	// HostNode Response s

	protected CFIntXMsgRspnHostNodeRec getRspnHostNodeRec() {
		if( rspnHostNodeRec == null ) {
			rspnHostNodeRec = new CFIntXMsgRspnHostNodeRec( this );
		}
		return( rspnHostNodeRec );
	}

	protected CFIntXMsgRspnHostNodeCreated getRspnHostNodeCreated() {
		if( rspnHostNodeCreated == null ) {
			rspnHostNodeCreated = new CFIntXMsgRspnHostNodeCreated( this );
		}
		return( rspnHostNodeCreated );
	}

	protected CFIntXMsgRspnHostNodeReadSingle getRspnHostNodeReadSingle() {
		if( rspnHostNodeReadSingle == null ) {
			rspnHostNodeReadSingle = new CFIntXMsgRspnHostNodeReadSingle( this );
			rspnHostNodeReadSingle.addElementHandler( "HostNode", getRspnHostNodeRec() );
		}
		return( rspnHostNodeReadSingle );
	}

	protected CFIntXMsgRspnHostNodeReadList getRspnHostNodeReadList() {
		if( rspnHostNodeReadList == null ) {
			rspnHostNodeReadList = new CFIntXMsgRspnHostNodeReadList( this );
			rspnHostNodeReadList.addElementHandler( "HostNode", getRspnHostNodeRec() );
		}
		return( rspnHostNodeReadList );
	}

	protected CFIntXMsgRspnHostNodeLocked getRspnHostNodeLocked() {
		if( rspnHostNodeLocked == null ) {
			rspnHostNodeLocked = new CFIntXMsgRspnHostNodeLocked( this );
		}
		return( rspnHostNodeLocked );
	}

	protected CFIntXMsgRspnHostNodeUpdated getRspnHostNodeUpdated() {
		if( rspnHostNodeUpdated == null ) {
			rspnHostNodeUpdated = new CFIntXMsgRspnHostNodeUpdated( this );
		}
		return( rspnHostNodeUpdated );
	}

	protected CFIntXMsgRspnHostNodeDeleted getRspnHostNodeDeleted() {
		if( rspnHostNodeDeleted == null ) {
			rspnHostNodeDeleted = new CFIntXMsgRspnHostNodeDeleted( this );
		}
		return( rspnHostNodeDeleted );
	}

	// ISOCcy Response s

	protected CFIntXMsgRspnISOCcyRec getRspnISOCcyRec() {
		if( rspnISOCcyRec == null ) {
			rspnISOCcyRec = new CFIntXMsgRspnISOCcyRec( this );
		}
		return( rspnISOCcyRec );
	}

	protected CFIntXMsgRspnISOCcyCreated getRspnISOCcyCreated() {
		if( rspnISOCcyCreated == null ) {
			rspnISOCcyCreated = new CFIntXMsgRspnISOCcyCreated( this );
		}
		return( rspnISOCcyCreated );
	}

	protected CFIntXMsgRspnISOCcyReadSingle getRspnISOCcyReadSingle() {
		if( rspnISOCcyReadSingle == null ) {
			rspnISOCcyReadSingle = new CFIntXMsgRspnISOCcyReadSingle( this );
			rspnISOCcyReadSingle.addElementHandler( "ISOCcy", getRspnISOCcyRec() );
		}
		return( rspnISOCcyReadSingle );
	}

	protected CFIntXMsgRspnISOCcyReadList getRspnISOCcyReadList() {
		if( rspnISOCcyReadList == null ) {
			rspnISOCcyReadList = new CFIntXMsgRspnISOCcyReadList( this );
			rspnISOCcyReadList.addElementHandler( "ISOCcy", getRspnISOCcyRec() );
		}
		return( rspnISOCcyReadList );
	}

	protected CFIntXMsgRspnISOCcyLocked getRspnISOCcyLocked() {
		if( rspnISOCcyLocked == null ) {
			rspnISOCcyLocked = new CFIntXMsgRspnISOCcyLocked( this );
		}
		return( rspnISOCcyLocked );
	}

	protected CFIntXMsgRspnISOCcyUpdated getRspnISOCcyUpdated() {
		if( rspnISOCcyUpdated == null ) {
			rspnISOCcyUpdated = new CFIntXMsgRspnISOCcyUpdated( this );
		}
		return( rspnISOCcyUpdated );
	}

	protected CFIntXMsgRspnISOCcyDeleted getRspnISOCcyDeleted() {
		if( rspnISOCcyDeleted == null ) {
			rspnISOCcyDeleted = new CFIntXMsgRspnISOCcyDeleted( this );
		}
		return( rspnISOCcyDeleted );
	}

	// ISOCtry Response s

	protected CFIntXMsgRspnISOCtryRec getRspnISOCtryRec() {
		if( rspnISOCtryRec == null ) {
			rspnISOCtryRec = new CFIntXMsgRspnISOCtryRec( this );
		}
		return( rspnISOCtryRec );
	}

	protected CFIntXMsgRspnISOCtryCreated getRspnISOCtryCreated() {
		if( rspnISOCtryCreated == null ) {
			rspnISOCtryCreated = new CFIntXMsgRspnISOCtryCreated( this );
		}
		return( rspnISOCtryCreated );
	}

	protected CFIntXMsgRspnISOCtryReadSingle getRspnISOCtryReadSingle() {
		if( rspnISOCtryReadSingle == null ) {
			rspnISOCtryReadSingle = new CFIntXMsgRspnISOCtryReadSingle( this );
			rspnISOCtryReadSingle.addElementHandler( "ISOCtry", getRspnISOCtryRec() );
		}
		return( rspnISOCtryReadSingle );
	}

	protected CFIntXMsgRspnISOCtryReadList getRspnISOCtryReadList() {
		if( rspnISOCtryReadList == null ) {
			rspnISOCtryReadList = new CFIntXMsgRspnISOCtryReadList( this );
			rspnISOCtryReadList.addElementHandler( "ISOCtry", getRspnISOCtryRec() );
		}
		return( rspnISOCtryReadList );
	}

	protected CFIntXMsgRspnISOCtryLocked getRspnISOCtryLocked() {
		if( rspnISOCtryLocked == null ) {
			rspnISOCtryLocked = new CFIntXMsgRspnISOCtryLocked( this );
		}
		return( rspnISOCtryLocked );
	}

	protected CFIntXMsgRspnISOCtryUpdated getRspnISOCtryUpdated() {
		if( rspnISOCtryUpdated == null ) {
			rspnISOCtryUpdated = new CFIntXMsgRspnISOCtryUpdated( this );
		}
		return( rspnISOCtryUpdated );
	}

	protected CFIntXMsgRspnISOCtryDeleted getRspnISOCtryDeleted() {
		if( rspnISOCtryDeleted == null ) {
			rspnISOCtryDeleted = new CFIntXMsgRspnISOCtryDeleted( this );
		}
		return( rspnISOCtryDeleted );
	}

	// ISOCtryCcy Response s

	protected CFIntXMsgRspnISOCtryCcyRec getRspnISOCtryCcyRec() {
		if( rspnISOCtryCcyRec == null ) {
			rspnISOCtryCcyRec = new CFIntXMsgRspnISOCtryCcyRec( this );
		}
		return( rspnISOCtryCcyRec );
	}

	protected CFIntXMsgRspnISOCtryCcyCreated getRspnISOCtryCcyCreated() {
		if( rspnISOCtryCcyCreated == null ) {
			rspnISOCtryCcyCreated = new CFIntXMsgRspnISOCtryCcyCreated( this );
		}
		return( rspnISOCtryCcyCreated );
	}

	protected CFIntXMsgRspnISOCtryCcyReadSingle getRspnISOCtryCcyReadSingle() {
		if( rspnISOCtryCcyReadSingle == null ) {
			rspnISOCtryCcyReadSingle = new CFIntXMsgRspnISOCtryCcyReadSingle( this );
			rspnISOCtryCcyReadSingle.addElementHandler( "ISOCtryCcy", getRspnISOCtryCcyRec() );
		}
		return( rspnISOCtryCcyReadSingle );
	}

	protected CFIntXMsgRspnISOCtryCcyReadList getRspnISOCtryCcyReadList() {
		if( rspnISOCtryCcyReadList == null ) {
			rspnISOCtryCcyReadList = new CFIntXMsgRspnISOCtryCcyReadList( this );
			rspnISOCtryCcyReadList.addElementHandler( "ISOCtryCcy", getRspnISOCtryCcyRec() );
		}
		return( rspnISOCtryCcyReadList );
	}

	protected CFIntXMsgRspnISOCtryCcyLocked getRspnISOCtryCcyLocked() {
		if( rspnISOCtryCcyLocked == null ) {
			rspnISOCtryCcyLocked = new CFIntXMsgRspnISOCtryCcyLocked( this );
		}
		return( rspnISOCtryCcyLocked );
	}

	protected CFIntXMsgRspnISOCtryCcyUpdated getRspnISOCtryCcyUpdated() {
		if( rspnISOCtryCcyUpdated == null ) {
			rspnISOCtryCcyUpdated = new CFIntXMsgRspnISOCtryCcyUpdated( this );
		}
		return( rspnISOCtryCcyUpdated );
	}

	protected CFIntXMsgRspnISOCtryCcyDeleted getRspnISOCtryCcyDeleted() {
		if( rspnISOCtryCcyDeleted == null ) {
			rspnISOCtryCcyDeleted = new CFIntXMsgRspnISOCtryCcyDeleted( this );
		}
		return( rspnISOCtryCcyDeleted );
	}

	// ISOCtryLang Response s

	protected CFIntXMsgRspnISOCtryLangRec getRspnISOCtryLangRec() {
		if( rspnISOCtryLangRec == null ) {
			rspnISOCtryLangRec = new CFIntXMsgRspnISOCtryLangRec( this );
		}
		return( rspnISOCtryLangRec );
	}

	protected CFIntXMsgRspnISOCtryLangCreated getRspnISOCtryLangCreated() {
		if( rspnISOCtryLangCreated == null ) {
			rspnISOCtryLangCreated = new CFIntXMsgRspnISOCtryLangCreated( this );
		}
		return( rspnISOCtryLangCreated );
	}

	protected CFIntXMsgRspnISOCtryLangReadSingle getRspnISOCtryLangReadSingle() {
		if( rspnISOCtryLangReadSingle == null ) {
			rspnISOCtryLangReadSingle = new CFIntXMsgRspnISOCtryLangReadSingle( this );
			rspnISOCtryLangReadSingle.addElementHandler( "ISOCtryLang", getRspnISOCtryLangRec() );
		}
		return( rspnISOCtryLangReadSingle );
	}

	protected CFIntXMsgRspnISOCtryLangReadList getRspnISOCtryLangReadList() {
		if( rspnISOCtryLangReadList == null ) {
			rspnISOCtryLangReadList = new CFIntXMsgRspnISOCtryLangReadList( this );
			rspnISOCtryLangReadList.addElementHandler( "ISOCtryLang", getRspnISOCtryLangRec() );
		}
		return( rspnISOCtryLangReadList );
	}

	protected CFIntXMsgRspnISOCtryLangLocked getRspnISOCtryLangLocked() {
		if( rspnISOCtryLangLocked == null ) {
			rspnISOCtryLangLocked = new CFIntXMsgRspnISOCtryLangLocked( this );
		}
		return( rspnISOCtryLangLocked );
	}

	protected CFIntXMsgRspnISOCtryLangUpdated getRspnISOCtryLangUpdated() {
		if( rspnISOCtryLangUpdated == null ) {
			rspnISOCtryLangUpdated = new CFIntXMsgRspnISOCtryLangUpdated( this );
		}
		return( rspnISOCtryLangUpdated );
	}

	protected CFIntXMsgRspnISOCtryLangDeleted getRspnISOCtryLangDeleted() {
		if( rspnISOCtryLangDeleted == null ) {
			rspnISOCtryLangDeleted = new CFIntXMsgRspnISOCtryLangDeleted( this );
		}
		return( rspnISOCtryLangDeleted );
	}

	// ISOLang Response s

	protected CFIntXMsgRspnISOLangRec getRspnISOLangRec() {
		if( rspnISOLangRec == null ) {
			rspnISOLangRec = new CFIntXMsgRspnISOLangRec( this );
		}
		return( rspnISOLangRec );
	}

	protected CFIntXMsgRspnISOLangCreated getRspnISOLangCreated() {
		if( rspnISOLangCreated == null ) {
			rspnISOLangCreated = new CFIntXMsgRspnISOLangCreated( this );
		}
		return( rspnISOLangCreated );
	}

	protected CFIntXMsgRspnISOLangReadSingle getRspnISOLangReadSingle() {
		if( rspnISOLangReadSingle == null ) {
			rspnISOLangReadSingle = new CFIntXMsgRspnISOLangReadSingle( this );
			rspnISOLangReadSingle.addElementHandler( "ISOLang", getRspnISOLangRec() );
		}
		return( rspnISOLangReadSingle );
	}

	protected CFIntXMsgRspnISOLangReadList getRspnISOLangReadList() {
		if( rspnISOLangReadList == null ) {
			rspnISOLangReadList = new CFIntXMsgRspnISOLangReadList( this );
			rspnISOLangReadList.addElementHandler( "ISOLang", getRspnISOLangRec() );
		}
		return( rspnISOLangReadList );
	}

	protected CFIntXMsgRspnISOLangLocked getRspnISOLangLocked() {
		if( rspnISOLangLocked == null ) {
			rspnISOLangLocked = new CFIntXMsgRspnISOLangLocked( this );
		}
		return( rspnISOLangLocked );
	}

	protected CFIntXMsgRspnISOLangUpdated getRspnISOLangUpdated() {
		if( rspnISOLangUpdated == null ) {
			rspnISOLangUpdated = new CFIntXMsgRspnISOLangUpdated( this );
		}
		return( rspnISOLangUpdated );
	}

	protected CFIntXMsgRspnISOLangDeleted getRspnISOLangDeleted() {
		if( rspnISOLangDeleted == null ) {
			rspnISOLangDeleted = new CFIntXMsgRspnISOLangDeleted( this );
		}
		return( rspnISOLangDeleted );
	}

	// ISOTZone Response s

	protected CFIntXMsgRspnISOTZoneRec getRspnISOTZoneRec() {
		if( rspnISOTZoneRec == null ) {
			rspnISOTZoneRec = new CFIntXMsgRspnISOTZoneRec( this );
		}
		return( rspnISOTZoneRec );
	}

	protected CFIntXMsgRspnISOTZoneCreated getRspnISOTZoneCreated() {
		if( rspnISOTZoneCreated == null ) {
			rspnISOTZoneCreated = new CFIntXMsgRspnISOTZoneCreated( this );
		}
		return( rspnISOTZoneCreated );
	}

	protected CFIntXMsgRspnISOTZoneReadSingle getRspnISOTZoneReadSingle() {
		if( rspnISOTZoneReadSingle == null ) {
			rspnISOTZoneReadSingle = new CFIntXMsgRspnISOTZoneReadSingle( this );
			rspnISOTZoneReadSingle.addElementHandler( "ISOTZone", getRspnISOTZoneRec() );
		}
		return( rspnISOTZoneReadSingle );
	}

	protected CFIntXMsgRspnISOTZoneReadList getRspnISOTZoneReadList() {
		if( rspnISOTZoneReadList == null ) {
			rspnISOTZoneReadList = new CFIntXMsgRspnISOTZoneReadList( this );
			rspnISOTZoneReadList.addElementHandler( "ISOTZone", getRspnISOTZoneRec() );
		}
		return( rspnISOTZoneReadList );
	}

	protected CFIntXMsgRspnISOTZoneLocked getRspnISOTZoneLocked() {
		if( rspnISOTZoneLocked == null ) {
			rspnISOTZoneLocked = new CFIntXMsgRspnISOTZoneLocked( this );
		}
		return( rspnISOTZoneLocked );
	}

	protected CFIntXMsgRspnISOTZoneUpdated getRspnISOTZoneUpdated() {
		if( rspnISOTZoneUpdated == null ) {
			rspnISOTZoneUpdated = new CFIntXMsgRspnISOTZoneUpdated( this );
		}
		return( rspnISOTZoneUpdated );
	}

	protected CFIntXMsgRspnISOTZoneDeleted getRspnISOTZoneDeleted() {
		if( rspnISOTZoneDeleted == null ) {
			rspnISOTZoneDeleted = new CFIntXMsgRspnISOTZoneDeleted( this );
		}
		return( rspnISOTZoneDeleted );
	}

	// License Response s

	protected CFIntXMsgRspnLicenseRec getRspnLicenseRec() {
		if( rspnLicenseRec == null ) {
			rspnLicenseRec = new CFIntXMsgRspnLicenseRec( this );
		}
		return( rspnLicenseRec );
	}

	protected CFIntXMsgRspnLicenseCreated getRspnLicenseCreated() {
		if( rspnLicenseCreated == null ) {
			rspnLicenseCreated = new CFIntXMsgRspnLicenseCreated( this );
		}
		return( rspnLicenseCreated );
	}

	protected CFIntXMsgRspnLicenseReadSingle getRspnLicenseReadSingle() {
		if( rspnLicenseReadSingle == null ) {
			rspnLicenseReadSingle = new CFIntXMsgRspnLicenseReadSingle( this );
			rspnLicenseReadSingle.addElementHandler( "License", getRspnLicenseRec() );
		}
		return( rspnLicenseReadSingle );
	}

	protected CFIntXMsgRspnLicenseReadList getRspnLicenseReadList() {
		if( rspnLicenseReadList == null ) {
			rspnLicenseReadList = new CFIntXMsgRspnLicenseReadList( this );
			rspnLicenseReadList.addElementHandler( "License", getRspnLicenseRec() );
		}
		return( rspnLicenseReadList );
	}

	protected CFIntXMsgRspnLicenseLocked getRspnLicenseLocked() {
		if( rspnLicenseLocked == null ) {
			rspnLicenseLocked = new CFIntXMsgRspnLicenseLocked( this );
		}
		return( rspnLicenseLocked );
	}

	protected CFIntXMsgRspnLicenseUpdated getRspnLicenseUpdated() {
		if( rspnLicenseUpdated == null ) {
			rspnLicenseUpdated = new CFIntXMsgRspnLicenseUpdated( this );
		}
		return( rspnLicenseUpdated );
	}

	protected CFIntXMsgRspnLicenseDeleted getRspnLicenseDeleted() {
		if( rspnLicenseDeleted == null ) {
			rspnLicenseDeleted = new CFIntXMsgRspnLicenseDeleted( this );
		}
		return( rspnLicenseDeleted );
	}

	// MajorVersion Response s

	protected CFIntXMsgRspnMajorVersionRec getRspnMajorVersionRec() {
		if( rspnMajorVersionRec == null ) {
			rspnMajorVersionRec = new CFIntXMsgRspnMajorVersionRec( this );
		}
		return( rspnMajorVersionRec );
	}

	protected CFIntXMsgRspnMajorVersionCreated getRspnMajorVersionCreated() {
		if( rspnMajorVersionCreated == null ) {
			rspnMajorVersionCreated = new CFIntXMsgRspnMajorVersionCreated( this );
		}
		return( rspnMajorVersionCreated );
	}

	protected CFIntXMsgRspnMajorVersionReadSingle getRspnMajorVersionReadSingle() {
		if( rspnMajorVersionReadSingle == null ) {
			rspnMajorVersionReadSingle = new CFIntXMsgRspnMajorVersionReadSingle( this );
			rspnMajorVersionReadSingle.addElementHandler( "MajorVersion", getRspnMajorVersionRec() );
		}
		return( rspnMajorVersionReadSingle );
	}

	protected CFIntXMsgRspnMajorVersionReadList getRspnMajorVersionReadList() {
		if( rspnMajorVersionReadList == null ) {
			rspnMajorVersionReadList = new CFIntXMsgRspnMajorVersionReadList( this );
			rspnMajorVersionReadList.addElementHandler( "MajorVersion", getRspnMajorVersionRec() );
		}
		return( rspnMajorVersionReadList );
	}

	protected CFIntXMsgRspnMajorVersionLocked getRspnMajorVersionLocked() {
		if( rspnMajorVersionLocked == null ) {
			rspnMajorVersionLocked = new CFIntXMsgRspnMajorVersionLocked( this );
		}
		return( rspnMajorVersionLocked );
	}

	protected CFIntXMsgRspnMajorVersionUpdated getRspnMajorVersionUpdated() {
		if( rspnMajorVersionUpdated == null ) {
			rspnMajorVersionUpdated = new CFIntXMsgRspnMajorVersionUpdated( this );
		}
		return( rspnMajorVersionUpdated );
	}

	protected CFIntXMsgRspnMajorVersionDeleted getRspnMajorVersionDeleted() {
		if( rspnMajorVersionDeleted == null ) {
			rspnMajorVersionDeleted = new CFIntXMsgRspnMajorVersionDeleted( this );
		}
		return( rspnMajorVersionDeleted );
	}

	// MimeType Response s

	protected CFIntXMsgRspnMimeTypeRec getRspnMimeTypeRec() {
		if( rspnMimeTypeRec == null ) {
			rspnMimeTypeRec = new CFIntXMsgRspnMimeTypeRec( this );
		}
		return( rspnMimeTypeRec );
	}

	protected CFIntXMsgRspnMimeTypeCreated getRspnMimeTypeCreated() {
		if( rspnMimeTypeCreated == null ) {
			rspnMimeTypeCreated = new CFIntXMsgRspnMimeTypeCreated( this );
		}
		return( rspnMimeTypeCreated );
	}

	protected CFIntXMsgRspnMimeTypeReadSingle getRspnMimeTypeReadSingle() {
		if( rspnMimeTypeReadSingle == null ) {
			rspnMimeTypeReadSingle = new CFIntXMsgRspnMimeTypeReadSingle( this );
			rspnMimeTypeReadSingle.addElementHandler( "MimeType", getRspnMimeTypeRec() );
		}
		return( rspnMimeTypeReadSingle );
	}

	protected CFIntXMsgRspnMimeTypeReadList getRspnMimeTypeReadList() {
		if( rspnMimeTypeReadList == null ) {
			rspnMimeTypeReadList = new CFIntXMsgRspnMimeTypeReadList( this );
			rspnMimeTypeReadList.addElementHandler( "MimeType", getRspnMimeTypeRec() );
		}
		return( rspnMimeTypeReadList );
	}

	protected CFIntXMsgRspnMimeTypeLocked getRspnMimeTypeLocked() {
		if( rspnMimeTypeLocked == null ) {
			rspnMimeTypeLocked = new CFIntXMsgRspnMimeTypeLocked( this );
		}
		return( rspnMimeTypeLocked );
	}

	protected CFIntXMsgRspnMimeTypeUpdated getRspnMimeTypeUpdated() {
		if( rspnMimeTypeUpdated == null ) {
			rspnMimeTypeUpdated = new CFIntXMsgRspnMimeTypeUpdated( this );
		}
		return( rspnMimeTypeUpdated );
	}

	protected CFIntXMsgRspnMimeTypeDeleted getRspnMimeTypeDeleted() {
		if( rspnMimeTypeDeleted == null ) {
			rspnMimeTypeDeleted = new CFIntXMsgRspnMimeTypeDeleted( this );
		}
		return( rspnMimeTypeDeleted );
	}

	// MinorVersion Response s

	protected CFIntXMsgRspnMinorVersionRec getRspnMinorVersionRec() {
		if( rspnMinorVersionRec == null ) {
			rspnMinorVersionRec = new CFIntXMsgRspnMinorVersionRec( this );
		}
		return( rspnMinorVersionRec );
	}

	protected CFIntXMsgRspnMinorVersionCreated getRspnMinorVersionCreated() {
		if( rspnMinorVersionCreated == null ) {
			rspnMinorVersionCreated = new CFIntXMsgRspnMinorVersionCreated( this );
		}
		return( rspnMinorVersionCreated );
	}

	protected CFIntXMsgRspnMinorVersionReadSingle getRspnMinorVersionReadSingle() {
		if( rspnMinorVersionReadSingle == null ) {
			rspnMinorVersionReadSingle = new CFIntXMsgRspnMinorVersionReadSingle( this );
			rspnMinorVersionReadSingle.addElementHandler( "MinorVersion", getRspnMinorVersionRec() );
		}
		return( rspnMinorVersionReadSingle );
	}

	protected CFIntXMsgRspnMinorVersionReadList getRspnMinorVersionReadList() {
		if( rspnMinorVersionReadList == null ) {
			rspnMinorVersionReadList = new CFIntXMsgRspnMinorVersionReadList( this );
			rspnMinorVersionReadList.addElementHandler( "MinorVersion", getRspnMinorVersionRec() );
		}
		return( rspnMinorVersionReadList );
	}

	protected CFIntXMsgRspnMinorVersionLocked getRspnMinorVersionLocked() {
		if( rspnMinorVersionLocked == null ) {
			rspnMinorVersionLocked = new CFIntXMsgRspnMinorVersionLocked( this );
		}
		return( rspnMinorVersionLocked );
	}

	protected CFIntXMsgRspnMinorVersionUpdated getRspnMinorVersionUpdated() {
		if( rspnMinorVersionUpdated == null ) {
			rspnMinorVersionUpdated = new CFIntXMsgRspnMinorVersionUpdated( this );
		}
		return( rspnMinorVersionUpdated );
	}

	protected CFIntXMsgRspnMinorVersionDeleted getRspnMinorVersionDeleted() {
		if( rspnMinorVersionDeleted == null ) {
			rspnMinorVersionDeleted = new CFIntXMsgRspnMinorVersionDeleted( this );
		}
		return( rspnMinorVersionDeleted );
	}

	// SecApp Response s

	protected CFIntXMsgRspnSecAppRec getRspnSecAppRec() {
		if( rspnSecAppRec == null ) {
			rspnSecAppRec = new CFIntXMsgRspnSecAppRec( this );
		}
		return( rspnSecAppRec );
	}

	protected CFIntXMsgRspnSecAppCreated getRspnSecAppCreated() {
		if( rspnSecAppCreated == null ) {
			rspnSecAppCreated = new CFIntXMsgRspnSecAppCreated( this );
		}
		return( rspnSecAppCreated );
	}

	protected CFIntXMsgRspnSecAppReadSingle getRspnSecAppReadSingle() {
		if( rspnSecAppReadSingle == null ) {
			rspnSecAppReadSingle = new CFIntXMsgRspnSecAppReadSingle( this );
			rspnSecAppReadSingle.addElementHandler( "SecApp", getRspnSecAppRec() );
		}
		return( rspnSecAppReadSingle );
	}

	protected CFIntXMsgRspnSecAppReadList getRspnSecAppReadList() {
		if( rspnSecAppReadList == null ) {
			rspnSecAppReadList = new CFIntXMsgRspnSecAppReadList( this );
			rspnSecAppReadList.addElementHandler( "SecApp", getRspnSecAppRec() );
		}
		return( rspnSecAppReadList );
	}

	protected CFIntXMsgRspnSecAppLocked getRspnSecAppLocked() {
		if( rspnSecAppLocked == null ) {
			rspnSecAppLocked = new CFIntXMsgRspnSecAppLocked( this );
		}
		return( rspnSecAppLocked );
	}

	protected CFIntXMsgRspnSecAppUpdated getRspnSecAppUpdated() {
		if( rspnSecAppUpdated == null ) {
			rspnSecAppUpdated = new CFIntXMsgRspnSecAppUpdated( this );
		}
		return( rspnSecAppUpdated );
	}

	protected CFIntXMsgRspnSecAppDeleted getRspnSecAppDeleted() {
		if( rspnSecAppDeleted == null ) {
			rspnSecAppDeleted = new CFIntXMsgRspnSecAppDeleted( this );
		}
		return( rspnSecAppDeleted );
	}

	// SecDevice Response s

	protected CFIntXMsgRspnSecDeviceRec getRspnSecDeviceRec() {
		if( rspnSecDeviceRec == null ) {
			rspnSecDeviceRec = new CFIntXMsgRspnSecDeviceRec( this );
		}
		return( rspnSecDeviceRec );
	}

	protected CFIntXMsgRspnSecDeviceCreated getRspnSecDeviceCreated() {
		if( rspnSecDeviceCreated == null ) {
			rspnSecDeviceCreated = new CFIntXMsgRspnSecDeviceCreated( this );
		}
		return( rspnSecDeviceCreated );
	}

	protected CFIntXMsgRspnSecDeviceReadSingle getRspnSecDeviceReadSingle() {
		if( rspnSecDeviceReadSingle == null ) {
			rspnSecDeviceReadSingle = new CFIntXMsgRspnSecDeviceReadSingle( this );
			rspnSecDeviceReadSingle.addElementHandler( "SecDevice", getRspnSecDeviceRec() );
		}
		return( rspnSecDeviceReadSingle );
	}

	protected CFIntXMsgRspnSecDeviceReadList getRspnSecDeviceReadList() {
		if( rspnSecDeviceReadList == null ) {
			rspnSecDeviceReadList = new CFIntXMsgRspnSecDeviceReadList( this );
			rspnSecDeviceReadList.addElementHandler( "SecDevice", getRspnSecDeviceRec() );
		}
		return( rspnSecDeviceReadList );
	}

	protected CFIntXMsgRspnSecDeviceLocked getRspnSecDeviceLocked() {
		if( rspnSecDeviceLocked == null ) {
			rspnSecDeviceLocked = new CFIntXMsgRspnSecDeviceLocked( this );
		}
		return( rspnSecDeviceLocked );
	}

	protected CFIntXMsgRspnSecDeviceUpdated getRspnSecDeviceUpdated() {
		if( rspnSecDeviceUpdated == null ) {
			rspnSecDeviceUpdated = new CFIntXMsgRspnSecDeviceUpdated( this );
		}
		return( rspnSecDeviceUpdated );
	}

	protected CFIntXMsgRspnSecDeviceDeleted getRspnSecDeviceDeleted() {
		if( rspnSecDeviceDeleted == null ) {
			rspnSecDeviceDeleted = new CFIntXMsgRspnSecDeviceDeleted( this );
		}
		return( rspnSecDeviceDeleted );
	}

	// SecForm Response s

	protected CFIntXMsgRspnSecFormRec getRspnSecFormRec() {
		if( rspnSecFormRec == null ) {
			rspnSecFormRec = new CFIntXMsgRspnSecFormRec( this );
		}
		return( rspnSecFormRec );
	}

	protected CFIntXMsgRspnSecFormCreated getRspnSecFormCreated() {
		if( rspnSecFormCreated == null ) {
			rspnSecFormCreated = new CFIntXMsgRspnSecFormCreated( this );
		}
		return( rspnSecFormCreated );
	}

	protected CFIntXMsgRspnSecFormReadSingle getRspnSecFormReadSingle() {
		if( rspnSecFormReadSingle == null ) {
			rspnSecFormReadSingle = new CFIntXMsgRspnSecFormReadSingle( this );
			rspnSecFormReadSingle.addElementHandler( "SecForm", getRspnSecFormRec() );
		}
		return( rspnSecFormReadSingle );
	}

	protected CFIntXMsgRspnSecFormReadList getRspnSecFormReadList() {
		if( rspnSecFormReadList == null ) {
			rspnSecFormReadList = new CFIntXMsgRspnSecFormReadList( this );
			rspnSecFormReadList.addElementHandler( "SecForm", getRspnSecFormRec() );
		}
		return( rspnSecFormReadList );
	}

	protected CFIntXMsgRspnSecFormLocked getRspnSecFormLocked() {
		if( rspnSecFormLocked == null ) {
			rspnSecFormLocked = new CFIntXMsgRspnSecFormLocked( this );
		}
		return( rspnSecFormLocked );
	}

	protected CFIntXMsgRspnSecFormUpdated getRspnSecFormUpdated() {
		if( rspnSecFormUpdated == null ) {
			rspnSecFormUpdated = new CFIntXMsgRspnSecFormUpdated( this );
		}
		return( rspnSecFormUpdated );
	}

	protected CFIntXMsgRspnSecFormDeleted getRspnSecFormDeleted() {
		if( rspnSecFormDeleted == null ) {
			rspnSecFormDeleted = new CFIntXMsgRspnSecFormDeleted( this );
		}
		return( rspnSecFormDeleted );
	}

	// SecGroup Response s

	protected CFIntXMsgRspnSecGroupRec getRspnSecGroupRec() {
		if( rspnSecGroupRec == null ) {
			rspnSecGroupRec = new CFIntXMsgRspnSecGroupRec( this );
		}
		return( rspnSecGroupRec );
	}

	protected CFIntXMsgRspnSecGroupCreated getRspnSecGroupCreated() {
		if( rspnSecGroupCreated == null ) {
			rspnSecGroupCreated = new CFIntXMsgRspnSecGroupCreated( this );
		}
		return( rspnSecGroupCreated );
	}

	protected CFIntXMsgRspnSecGroupReadSingle getRspnSecGroupReadSingle() {
		if( rspnSecGroupReadSingle == null ) {
			rspnSecGroupReadSingle = new CFIntXMsgRspnSecGroupReadSingle( this );
			rspnSecGroupReadSingle.addElementHandler( "SecGroup", getRspnSecGroupRec() );
		}
		return( rspnSecGroupReadSingle );
	}

	protected CFIntXMsgRspnSecGroupReadList getRspnSecGroupReadList() {
		if( rspnSecGroupReadList == null ) {
			rspnSecGroupReadList = new CFIntXMsgRspnSecGroupReadList( this );
			rspnSecGroupReadList.addElementHandler( "SecGroup", getRspnSecGroupRec() );
		}
		return( rspnSecGroupReadList );
	}

	protected CFIntXMsgRspnSecGroupLocked getRspnSecGroupLocked() {
		if( rspnSecGroupLocked == null ) {
			rspnSecGroupLocked = new CFIntXMsgRspnSecGroupLocked( this );
		}
		return( rspnSecGroupLocked );
	}

	protected CFIntXMsgRspnSecGroupUpdated getRspnSecGroupUpdated() {
		if( rspnSecGroupUpdated == null ) {
			rspnSecGroupUpdated = new CFIntXMsgRspnSecGroupUpdated( this );
		}
		return( rspnSecGroupUpdated );
	}

	protected CFIntXMsgRspnSecGroupDeleted getRspnSecGroupDeleted() {
		if( rspnSecGroupDeleted == null ) {
			rspnSecGroupDeleted = new CFIntXMsgRspnSecGroupDeleted( this );
		}
		return( rspnSecGroupDeleted );
	}

	// SecGroupForm Response s

	protected CFIntXMsgRspnSecGroupFormRec getRspnSecGroupFormRec() {
		if( rspnSecGroupFormRec == null ) {
			rspnSecGroupFormRec = new CFIntXMsgRspnSecGroupFormRec( this );
		}
		return( rspnSecGroupFormRec );
	}

	protected CFIntXMsgRspnSecGroupFormCreated getRspnSecGroupFormCreated() {
		if( rspnSecGroupFormCreated == null ) {
			rspnSecGroupFormCreated = new CFIntXMsgRspnSecGroupFormCreated( this );
		}
		return( rspnSecGroupFormCreated );
	}

	protected CFIntXMsgRspnSecGroupFormReadSingle getRspnSecGroupFormReadSingle() {
		if( rspnSecGroupFormReadSingle == null ) {
			rspnSecGroupFormReadSingle = new CFIntXMsgRspnSecGroupFormReadSingle( this );
			rspnSecGroupFormReadSingle.addElementHandler( "SecGroupForm", getRspnSecGroupFormRec() );
		}
		return( rspnSecGroupFormReadSingle );
	}

	protected CFIntXMsgRspnSecGroupFormReadList getRspnSecGroupFormReadList() {
		if( rspnSecGroupFormReadList == null ) {
			rspnSecGroupFormReadList = new CFIntXMsgRspnSecGroupFormReadList( this );
			rspnSecGroupFormReadList.addElementHandler( "SecGroupForm", getRspnSecGroupFormRec() );
		}
		return( rspnSecGroupFormReadList );
	}

	protected CFIntXMsgRspnSecGroupFormLocked getRspnSecGroupFormLocked() {
		if( rspnSecGroupFormLocked == null ) {
			rspnSecGroupFormLocked = new CFIntXMsgRspnSecGroupFormLocked( this );
		}
		return( rspnSecGroupFormLocked );
	}

	protected CFIntXMsgRspnSecGroupFormUpdated getRspnSecGroupFormUpdated() {
		if( rspnSecGroupFormUpdated == null ) {
			rspnSecGroupFormUpdated = new CFIntXMsgRspnSecGroupFormUpdated( this );
		}
		return( rspnSecGroupFormUpdated );
	}

	protected CFIntXMsgRspnSecGroupFormDeleted getRspnSecGroupFormDeleted() {
		if( rspnSecGroupFormDeleted == null ) {
			rspnSecGroupFormDeleted = new CFIntXMsgRspnSecGroupFormDeleted( this );
		}
		return( rspnSecGroupFormDeleted );
	}

	// SecGrpInc Response s

	protected CFIntXMsgRspnSecGrpIncRec getRspnSecGrpIncRec() {
		if( rspnSecGrpIncRec == null ) {
			rspnSecGrpIncRec = new CFIntXMsgRspnSecGrpIncRec( this );
		}
		return( rspnSecGrpIncRec );
	}

	protected CFIntXMsgRspnSecGrpIncCreated getRspnSecGrpIncCreated() {
		if( rspnSecGrpIncCreated == null ) {
			rspnSecGrpIncCreated = new CFIntXMsgRspnSecGrpIncCreated( this );
		}
		return( rspnSecGrpIncCreated );
	}

	protected CFIntXMsgRspnSecGrpIncReadSingle getRspnSecGrpIncReadSingle() {
		if( rspnSecGrpIncReadSingle == null ) {
			rspnSecGrpIncReadSingle = new CFIntXMsgRspnSecGrpIncReadSingle( this );
			rspnSecGrpIncReadSingle.addElementHandler( "SecGrpInc", getRspnSecGrpIncRec() );
		}
		return( rspnSecGrpIncReadSingle );
	}

	protected CFIntXMsgRspnSecGrpIncReadList getRspnSecGrpIncReadList() {
		if( rspnSecGrpIncReadList == null ) {
			rspnSecGrpIncReadList = new CFIntXMsgRspnSecGrpIncReadList( this );
			rspnSecGrpIncReadList.addElementHandler( "SecGrpInc", getRspnSecGrpIncRec() );
		}
		return( rspnSecGrpIncReadList );
	}

	protected CFIntXMsgRspnSecGrpIncLocked getRspnSecGrpIncLocked() {
		if( rspnSecGrpIncLocked == null ) {
			rspnSecGrpIncLocked = new CFIntXMsgRspnSecGrpIncLocked( this );
		}
		return( rspnSecGrpIncLocked );
	}

	protected CFIntXMsgRspnSecGrpIncUpdated getRspnSecGrpIncUpdated() {
		if( rspnSecGrpIncUpdated == null ) {
			rspnSecGrpIncUpdated = new CFIntXMsgRspnSecGrpIncUpdated( this );
		}
		return( rspnSecGrpIncUpdated );
	}

	protected CFIntXMsgRspnSecGrpIncDeleted getRspnSecGrpIncDeleted() {
		if( rspnSecGrpIncDeleted == null ) {
			rspnSecGrpIncDeleted = new CFIntXMsgRspnSecGrpIncDeleted( this );
		}
		return( rspnSecGrpIncDeleted );
	}

	// SecGrpMemb Response s

	protected CFIntXMsgRspnSecGrpMembRec getRspnSecGrpMembRec() {
		if( rspnSecGrpMembRec == null ) {
			rspnSecGrpMembRec = new CFIntXMsgRspnSecGrpMembRec( this );
		}
		return( rspnSecGrpMembRec );
	}

	protected CFIntXMsgRspnSecGrpMembCreated getRspnSecGrpMembCreated() {
		if( rspnSecGrpMembCreated == null ) {
			rspnSecGrpMembCreated = new CFIntXMsgRspnSecGrpMembCreated( this );
		}
		return( rspnSecGrpMembCreated );
	}

	protected CFIntXMsgRspnSecGrpMembReadSingle getRspnSecGrpMembReadSingle() {
		if( rspnSecGrpMembReadSingle == null ) {
			rspnSecGrpMembReadSingle = new CFIntXMsgRspnSecGrpMembReadSingle( this );
			rspnSecGrpMembReadSingle.addElementHandler( "SecGrpMemb", getRspnSecGrpMembRec() );
		}
		return( rspnSecGrpMembReadSingle );
	}

	protected CFIntXMsgRspnSecGrpMembReadList getRspnSecGrpMembReadList() {
		if( rspnSecGrpMembReadList == null ) {
			rspnSecGrpMembReadList = new CFIntXMsgRspnSecGrpMembReadList( this );
			rspnSecGrpMembReadList.addElementHandler( "SecGrpMemb", getRspnSecGrpMembRec() );
		}
		return( rspnSecGrpMembReadList );
	}

	protected CFIntXMsgRspnSecGrpMembLocked getRspnSecGrpMembLocked() {
		if( rspnSecGrpMembLocked == null ) {
			rspnSecGrpMembLocked = new CFIntXMsgRspnSecGrpMembLocked( this );
		}
		return( rspnSecGrpMembLocked );
	}

	protected CFIntXMsgRspnSecGrpMembUpdated getRspnSecGrpMembUpdated() {
		if( rspnSecGrpMembUpdated == null ) {
			rspnSecGrpMembUpdated = new CFIntXMsgRspnSecGrpMembUpdated( this );
		}
		return( rspnSecGrpMembUpdated );
	}

	protected CFIntXMsgRspnSecGrpMembDeleted getRspnSecGrpMembDeleted() {
		if( rspnSecGrpMembDeleted == null ) {
			rspnSecGrpMembDeleted = new CFIntXMsgRspnSecGrpMembDeleted( this );
		}
		return( rspnSecGrpMembDeleted );
	}

	// SecSession Response s

	protected CFIntXMsgRspnSecSessionRec getRspnSecSessionRec() {
		if( rspnSecSessionRec == null ) {
			rspnSecSessionRec = new CFIntXMsgRspnSecSessionRec( this );
		}
		return( rspnSecSessionRec );
	}

	protected CFIntXMsgRspnSecSessionCreated getRspnSecSessionCreated() {
		if( rspnSecSessionCreated == null ) {
			rspnSecSessionCreated = new CFIntXMsgRspnSecSessionCreated( this );
		}
		return( rspnSecSessionCreated );
	}

	protected CFIntXMsgRspnSecSessionReadSingle getRspnSecSessionReadSingle() {
		if( rspnSecSessionReadSingle == null ) {
			rspnSecSessionReadSingle = new CFIntXMsgRspnSecSessionReadSingle( this );
			rspnSecSessionReadSingle.addElementHandler( "SecSession", getRspnSecSessionRec() );
		}
		return( rspnSecSessionReadSingle );
	}

	protected CFIntXMsgRspnSecSessionReadList getRspnSecSessionReadList() {
		if( rspnSecSessionReadList == null ) {
			rspnSecSessionReadList = new CFIntXMsgRspnSecSessionReadList( this );
			rspnSecSessionReadList.addElementHandler( "SecSession", getRspnSecSessionRec() );
		}
		return( rspnSecSessionReadList );
	}

	protected CFIntXMsgRspnSecSessionLocked getRspnSecSessionLocked() {
		if( rspnSecSessionLocked == null ) {
			rspnSecSessionLocked = new CFIntXMsgRspnSecSessionLocked( this );
		}
		return( rspnSecSessionLocked );
	}

	protected CFIntXMsgRspnSecSessionUpdated getRspnSecSessionUpdated() {
		if( rspnSecSessionUpdated == null ) {
			rspnSecSessionUpdated = new CFIntXMsgRspnSecSessionUpdated( this );
		}
		return( rspnSecSessionUpdated );
	}

	protected CFIntXMsgRspnSecSessionDeleted getRspnSecSessionDeleted() {
		if( rspnSecSessionDeleted == null ) {
			rspnSecSessionDeleted = new CFIntXMsgRspnSecSessionDeleted( this );
		}
		return( rspnSecSessionDeleted );
	}

	// SecUser Response s

	protected CFIntXMsgRspnSecUserRec getRspnSecUserRec() {
		if( rspnSecUserRec == null ) {
			rspnSecUserRec = new CFIntXMsgRspnSecUserRec( this );
		}
		return( rspnSecUserRec );
	}

	protected CFIntXMsgRspnSecUserCreated getRspnSecUserCreated() {
		if( rspnSecUserCreated == null ) {
			rspnSecUserCreated = new CFIntXMsgRspnSecUserCreated( this );
		}
		return( rspnSecUserCreated );
	}

	protected CFIntXMsgRspnSecUserReadSingle getRspnSecUserReadSingle() {
		if( rspnSecUserReadSingle == null ) {
			rspnSecUserReadSingle = new CFIntXMsgRspnSecUserReadSingle( this );
			rspnSecUserReadSingle.addElementHandler( "SecUser", getRspnSecUserRec() );
		}
		return( rspnSecUserReadSingle );
	}

	protected CFIntXMsgRspnSecUserReadList getRspnSecUserReadList() {
		if( rspnSecUserReadList == null ) {
			rspnSecUserReadList = new CFIntXMsgRspnSecUserReadList( this );
			rspnSecUserReadList.addElementHandler( "SecUser", getRspnSecUserRec() );
		}
		return( rspnSecUserReadList );
	}

	protected CFIntXMsgRspnSecUserLocked getRspnSecUserLocked() {
		if( rspnSecUserLocked == null ) {
			rspnSecUserLocked = new CFIntXMsgRspnSecUserLocked( this );
		}
		return( rspnSecUserLocked );
	}

	protected CFIntXMsgRspnSecUserUpdated getRspnSecUserUpdated() {
		if( rspnSecUserUpdated == null ) {
			rspnSecUserUpdated = new CFIntXMsgRspnSecUserUpdated( this );
		}
		return( rspnSecUserUpdated );
	}

	protected CFIntXMsgRspnSecUserDeleted getRspnSecUserDeleted() {
		if( rspnSecUserDeleted == null ) {
			rspnSecUserDeleted = new CFIntXMsgRspnSecUserDeleted( this );
		}
		return( rspnSecUserDeleted );
	}

	// Service Response s

	protected CFIntXMsgRspnServiceRec getRspnServiceRec() {
		if( rspnServiceRec == null ) {
			rspnServiceRec = new CFIntXMsgRspnServiceRec( this );
		}
		return( rspnServiceRec );
	}

	protected CFIntXMsgRspnServiceCreated getRspnServiceCreated() {
		if( rspnServiceCreated == null ) {
			rspnServiceCreated = new CFIntXMsgRspnServiceCreated( this );
		}
		return( rspnServiceCreated );
	}

	protected CFIntXMsgRspnServiceReadSingle getRspnServiceReadSingle() {
		if( rspnServiceReadSingle == null ) {
			rspnServiceReadSingle = new CFIntXMsgRspnServiceReadSingle( this );
			rspnServiceReadSingle.addElementHandler( "Service", getRspnServiceRec() );
		}
		return( rspnServiceReadSingle );
	}

	protected CFIntXMsgRspnServiceReadList getRspnServiceReadList() {
		if( rspnServiceReadList == null ) {
			rspnServiceReadList = new CFIntXMsgRspnServiceReadList( this );
			rspnServiceReadList.addElementHandler( "Service", getRspnServiceRec() );
		}
		return( rspnServiceReadList );
	}

	protected CFIntXMsgRspnServiceLocked getRspnServiceLocked() {
		if( rspnServiceLocked == null ) {
			rspnServiceLocked = new CFIntXMsgRspnServiceLocked( this );
		}
		return( rspnServiceLocked );
	}

	protected CFIntXMsgRspnServiceUpdated getRspnServiceUpdated() {
		if( rspnServiceUpdated == null ) {
			rspnServiceUpdated = new CFIntXMsgRspnServiceUpdated( this );
		}
		return( rspnServiceUpdated );
	}

	protected CFIntXMsgRspnServiceDeleted getRspnServiceDeleted() {
		if( rspnServiceDeleted == null ) {
			rspnServiceDeleted = new CFIntXMsgRspnServiceDeleted( this );
		}
		return( rspnServiceDeleted );
	}

	// ServiceType Response s

	protected CFIntXMsgRspnServiceTypeRec getRspnServiceTypeRec() {
		if( rspnServiceTypeRec == null ) {
			rspnServiceTypeRec = new CFIntXMsgRspnServiceTypeRec( this );
		}
		return( rspnServiceTypeRec );
	}

	protected CFIntXMsgRspnServiceTypeCreated getRspnServiceTypeCreated() {
		if( rspnServiceTypeCreated == null ) {
			rspnServiceTypeCreated = new CFIntXMsgRspnServiceTypeCreated( this );
		}
		return( rspnServiceTypeCreated );
	}

	protected CFIntXMsgRspnServiceTypeReadSingle getRspnServiceTypeReadSingle() {
		if( rspnServiceTypeReadSingle == null ) {
			rspnServiceTypeReadSingle = new CFIntXMsgRspnServiceTypeReadSingle( this );
			rspnServiceTypeReadSingle.addElementHandler( "ServiceType", getRspnServiceTypeRec() );
		}
		return( rspnServiceTypeReadSingle );
	}

	protected CFIntXMsgRspnServiceTypeReadList getRspnServiceTypeReadList() {
		if( rspnServiceTypeReadList == null ) {
			rspnServiceTypeReadList = new CFIntXMsgRspnServiceTypeReadList( this );
			rspnServiceTypeReadList.addElementHandler( "ServiceType", getRspnServiceTypeRec() );
		}
		return( rspnServiceTypeReadList );
	}

	protected CFIntXMsgRspnServiceTypeLocked getRspnServiceTypeLocked() {
		if( rspnServiceTypeLocked == null ) {
			rspnServiceTypeLocked = new CFIntXMsgRspnServiceTypeLocked( this );
		}
		return( rspnServiceTypeLocked );
	}

	protected CFIntXMsgRspnServiceTypeUpdated getRspnServiceTypeUpdated() {
		if( rspnServiceTypeUpdated == null ) {
			rspnServiceTypeUpdated = new CFIntXMsgRspnServiceTypeUpdated( this );
		}
		return( rspnServiceTypeUpdated );
	}

	protected CFIntXMsgRspnServiceTypeDeleted getRspnServiceTypeDeleted() {
		if( rspnServiceTypeDeleted == null ) {
			rspnServiceTypeDeleted = new CFIntXMsgRspnServiceTypeDeleted( this );
		}
		return( rspnServiceTypeDeleted );
	}

	// SubProject Response s

	protected CFIntXMsgRspnSubProjectRec getRspnSubProjectRec() {
		if( rspnSubProjectRec == null ) {
			rspnSubProjectRec = new CFIntXMsgRspnSubProjectRec( this );
		}
		return( rspnSubProjectRec );
	}

	protected CFIntXMsgRspnSubProjectCreated getRspnSubProjectCreated() {
		if( rspnSubProjectCreated == null ) {
			rspnSubProjectCreated = new CFIntXMsgRspnSubProjectCreated( this );
		}
		return( rspnSubProjectCreated );
	}

	protected CFIntXMsgRspnSubProjectReadSingle getRspnSubProjectReadSingle() {
		if( rspnSubProjectReadSingle == null ) {
			rspnSubProjectReadSingle = new CFIntXMsgRspnSubProjectReadSingle( this );
			rspnSubProjectReadSingle.addElementHandler( "SubProject", getRspnSubProjectRec() );
		}
		return( rspnSubProjectReadSingle );
	}

	protected CFIntXMsgRspnSubProjectReadList getRspnSubProjectReadList() {
		if( rspnSubProjectReadList == null ) {
			rspnSubProjectReadList = new CFIntXMsgRspnSubProjectReadList( this );
			rspnSubProjectReadList.addElementHandler( "SubProject", getRspnSubProjectRec() );
		}
		return( rspnSubProjectReadList );
	}

	protected CFIntXMsgRspnSubProjectLocked getRspnSubProjectLocked() {
		if( rspnSubProjectLocked == null ) {
			rspnSubProjectLocked = new CFIntXMsgRspnSubProjectLocked( this );
		}
		return( rspnSubProjectLocked );
	}

	protected CFIntXMsgRspnSubProjectUpdated getRspnSubProjectUpdated() {
		if( rspnSubProjectUpdated == null ) {
			rspnSubProjectUpdated = new CFIntXMsgRspnSubProjectUpdated( this );
		}
		return( rspnSubProjectUpdated );
	}

	protected CFIntXMsgRspnSubProjectDeleted getRspnSubProjectDeleted() {
		if( rspnSubProjectDeleted == null ) {
			rspnSubProjectDeleted = new CFIntXMsgRspnSubProjectDeleted( this );
		}
		return( rspnSubProjectDeleted );
	}

	// SysCluster Response s

	protected CFIntXMsgRspnSysClusterRec getRspnSysClusterRec() {
		if( rspnSysClusterRec == null ) {
			rspnSysClusterRec = new CFIntXMsgRspnSysClusterRec( this );
		}
		return( rspnSysClusterRec );
	}

	protected CFIntXMsgRspnSysClusterCreated getRspnSysClusterCreated() {
		if( rspnSysClusterCreated == null ) {
			rspnSysClusterCreated = new CFIntXMsgRspnSysClusterCreated( this );
		}
		return( rspnSysClusterCreated );
	}

	protected CFIntXMsgRspnSysClusterReadSingle getRspnSysClusterReadSingle() {
		if( rspnSysClusterReadSingle == null ) {
			rspnSysClusterReadSingle = new CFIntXMsgRspnSysClusterReadSingle( this );
			rspnSysClusterReadSingle.addElementHandler( "SysCluster", getRspnSysClusterRec() );
		}
		return( rspnSysClusterReadSingle );
	}

	protected CFIntXMsgRspnSysClusterReadList getRspnSysClusterReadList() {
		if( rspnSysClusterReadList == null ) {
			rspnSysClusterReadList = new CFIntXMsgRspnSysClusterReadList( this );
			rspnSysClusterReadList.addElementHandler( "SysCluster", getRspnSysClusterRec() );
		}
		return( rspnSysClusterReadList );
	}

	protected CFIntXMsgRspnSysClusterLocked getRspnSysClusterLocked() {
		if( rspnSysClusterLocked == null ) {
			rspnSysClusterLocked = new CFIntXMsgRspnSysClusterLocked( this );
		}
		return( rspnSysClusterLocked );
	}

	protected CFIntXMsgRspnSysClusterUpdated getRspnSysClusterUpdated() {
		if( rspnSysClusterUpdated == null ) {
			rspnSysClusterUpdated = new CFIntXMsgRspnSysClusterUpdated( this );
		}
		return( rspnSysClusterUpdated );
	}

	protected CFIntXMsgRspnSysClusterDeleted getRspnSysClusterDeleted() {
		if( rspnSysClusterDeleted == null ) {
			rspnSysClusterDeleted = new CFIntXMsgRspnSysClusterDeleted( this );
		}
		return( rspnSysClusterDeleted );
	}

	// TSecGroup Response s

	protected CFIntXMsgRspnTSecGroupRec getRspnTSecGroupRec() {
		if( rspnTSecGroupRec == null ) {
			rspnTSecGroupRec = new CFIntXMsgRspnTSecGroupRec( this );
		}
		return( rspnTSecGroupRec );
	}

	protected CFIntXMsgRspnTSecGroupCreated getRspnTSecGroupCreated() {
		if( rspnTSecGroupCreated == null ) {
			rspnTSecGroupCreated = new CFIntXMsgRspnTSecGroupCreated( this );
		}
		return( rspnTSecGroupCreated );
	}

	protected CFIntXMsgRspnTSecGroupReadSingle getRspnTSecGroupReadSingle() {
		if( rspnTSecGroupReadSingle == null ) {
			rspnTSecGroupReadSingle = new CFIntXMsgRspnTSecGroupReadSingle( this );
			rspnTSecGroupReadSingle.addElementHandler( "TSecGroup", getRspnTSecGroupRec() );
		}
		return( rspnTSecGroupReadSingle );
	}

	protected CFIntXMsgRspnTSecGroupReadList getRspnTSecGroupReadList() {
		if( rspnTSecGroupReadList == null ) {
			rspnTSecGroupReadList = new CFIntXMsgRspnTSecGroupReadList( this );
			rspnTSecGroupReadList.addElementHandler( "TSecGroup", getRspnTSecGroupRec() );
		}
		return( rspnTSecGroupReadList );
	}

	protected CFIntXMsgRspnTSecGroupLocked getRspnTSecGroupLocked() {
		if( rspnTSecGroupLocked == null ) {
			rspnTSecGroupLocked = new CFIntXMsgRspnTSecGroupLocked( this );
		}
		return( rspnTSecGroupLocked );
	}

	protected CFIntXMsgRspnTSecGroupUpdated getRspnTSecGroupUpdated() {
		if( rspnTSecGroupUpdated == null ) {
			rspnTSecGroupUpdated = new CFIntXMsgRspnTSecGroupUpdated( this );
		}
		return( rspnTSecGroupUpdated );
	}

	protected CFIntXMsgRspnTSecGroupDeleted getRspnTSecGroupDeleted() {
		if( rspnTSecGroupDeleted == null ) {
			rspnTSecGroupDeleted = new CFIntXMsgRspnTSecGroupDeleted( this );
		}
		return( rspnTSecGroupDeleted );
	}

	// TSecGrpInc Response s

	protected CFIntXMsgRspnTSecGrpIncRec getRspnTSecGrpIncRec() {
		if( rspnTSecGrpIncRec == null ) {
			rspnTSecGrpIncRec = new CFIntXMsgRspnTSecGrpIncRec( this );
		}
		return( rspnTSecGrpIncRec );
	}

	protected CFIntXMsgRspnTSecGrpIncCreated getRspnTSecGrpIncCreated() {
		if( rspnTSecGrpIncCreated == null ) {
			rspnTSecGrpIncCreated = new CFIntXMsgRspnTSecGrpIncCreated( this );
		}
		return( rspnTSecGrpIncCreated );
	}

	protected CFIntXMsgRspnTSecGrpIncReadSingle getRspnTSecGrpIncReadSingle() {
		if( rspnTSecGrpIncReadSingle == null ) {
			rspnTSecGrpIncReadSingle = new CFIntXMsgRspnTSecGrpIncReadSingle( this );
			rspnTSecGrpIncReadSingle.addElementHandler( "TSecGrpInc", getRspnTSecGrpIncRec() );
		}
		return( rspnTSecGrpIncReadSingle );
	}

	protected CFIntXMsgRspnTSecGrpIncReadList getRspnTSecGrpIncReadList() {
		if( rspnTSecGrpIncReadList == null ) {
			rspnTSecGrpIncReadList = new CFIntXMsgRspnTSecGrpIncReadList( this );
			rspnTSecGrpIncReadList.addElementHandler( "TSecGrpInc", getRspnTSecGrpIncRec() );
		}
		return( rspnTSecGrpIncReadList );
	}

	protected CFIntXMsgRspnTSecGrpIncLocked getRspnTSecGrpIncLocked() {
		if( rspnTSecGrpIncLocked == null ) {
			rspnTSecGrpIncLocked = new CFIntXMsgRspnTSecGrpIncLocked( this );
		}
		return( rspnTSecGrpIncLocked );
	}

	protected CFIntXMsgRspnTSecGrpIncUpdated getRspnTSecGrpIncUpdated() {
		if( rspnTSecGrpIncUpdated == null ) {
			rspnTSecGrpIncUpdated = new CFIntXMsgRspnTSecGrpIncUpdated( this );
		}
		return( rspnTSecGrpIncUpdated );
	}

	protected CFIntXMsgRspnTSecGrpIncDeleted getRspnTSecGrpIncDeleted() {
		if( rspnTSecGrpIncDeleted == null ) {
			rspnTSecGrpIncDeleted = new CFIntXMsgRspnTSecGrpIncDeleted( this );
		}
		return( rspnTSecGrpIncDeleted );
	}

	// TSecGrpMemb Response s

	protected CFIntXMsgRspnTSecGrpMembRec getRspnTSecGrpMembRec() {
		if( rspnTSecGrpMembRec == null ) {
			rspnTSecGrpMembRec = new CFIntXMsgRspnTSecGrpMembRec( this );
		}
		return( rspnTSecGrpMembRec );
	}

	protected CFIntXMsgRspnTSecGrpMembCreated getRspnTSecGrpMembCreated() {
		if( rspnTSecGrpMembCreated == null ) {
			rspnTSecGrpMembCreated = new CFIntXMsgRspnTSecGrpMembCreated( this );
		}
		return( rspnTSecGrpMembCreated );
	}

	protected CFIntXMsgRspnTSecGrpMembReadSingle getRspnTSecGrpMembReadSingle() {
		if( rspnTSecGrpMembReadSingle == null ) {
			rspnTSecGrpMembReadSingle = new CFIntXMsgRspnTSecGrpMembReadSingle( this );
			rspnTSecGrpMembReadSingle.addElementHandler( "TSecGrpMemb", getRspnTSecGrpMembRec() );
		}
		return( rspnTSecGrpMembReadSingle );
	}

	protected CFIntXMsgRspnTSecGrpMembReadList getRspnTSecGrpMembReadList() {
		if( rspnTSecGrpMembReadList == null ) {
			rspnTSecGrpMembReadList = new CFIntXMsgRspnTSecGrpMembReadList( this );
			rspnTSecGrpMembReadList.addElementHandler( "TSecGrpMemb", getRspnTSecGrpMembRec() );
		}
		return( rspnTSecGrpMembReadList );
	}

	protected CFIntXMsgRspnTSecGrpMembLocked getRspnTSecGrpMembLocked() {
		if( rspnTSecGrpMembLocked == null ) {
			rspnTSecGrpMembLocked = new CFIntXMsgRspnTSecGrpMembLocked( this );
		}
		return( rspnTSecGrpMembLocked );
	}

	protected CFIntXMsgRspnTSecGrpMembUpdated getRspnTSecGrpMembUpdated() {
		if( rspnTSecGrpMembUpdated == null ) {
			rspnTSecGrpMembUpdated = new CFIntXMsgRspnTSecGrpMembUpdated( this );
		}
		return( rspnTSecGrpMembUpdated );
	}

	protected CFIntXMsgRspnTSecGrpMembDeleted getRspnTSecGrpMembDeleted() {
		if( rspnTSecGrpMembDeleted == null ) {
			rspnTSecGrpMembDeleted = new CFIntXMsgRspnTSecGrpMembDeleted( this );
		}
		return( rspnTSecGrpMembDeleted );
	}

	// Tenant Response s

	protected CFIntXMsgRspnTenantRec getRspnTenantRec() {
		if( rspnTenantRec == null ) {
			rspnTenantRec = new CFIntXMsgRspnTenantRec( this );
		}
		return( rspnTenantRec );
	}

	protected CFIntXMsgRspnTenantCreated getRspnTenantCreated() {
		if( rspnTenantCreated == null ) {
			rspnTenantCreated = new CFIntXMsgRspnTenantCreated( this );
		}
		return( rspnTenantCreated );
	}

	protected CFIntXMsgRspnTenantReadSingle getRspnTenantReadSingle() {
		if( rspnTenantReadSingle == null ) {
			rspnTenantReadSingle = new CFIntXMsgRspnTenantReadSingle( this );
			rspnTenantReadSingle.addElementHandler( "Tenant", getRspnTenantRec() );
		}
		return( rspnTenantReadSingle );
	}

	protected CFIntXMsgRspnTenantReadList getRspnTenantReadList() {
		if( rspnTenantReadList == null ) {
			rspnTenantReadList = new CFIntXMsgRspnTenantReadList( this );
			rspnTenantReadList.addElementHandler( "Tenant", getRspnTenantRec() );
		}
		return( rspnTenantReadList );
	}

	protected CFIntXMsgRspnTenantLocked getRspnTenantLocked() {
		if( rspnTenantLocked == null ) {
			rspnTenantLocked = new CFIntXMsgRspnTenantLocked( this );
		}
		return( rspnTenantLocked );
	}

	protected CFIntXMsgRspnTenantUpdated getRspnTenantUpdated() {
		if( rspnTenantUpdated == null ) {
			rspnTenantUpdated = new CFIntXMsgRspnTenantUpdated( this );
		}
		return( rspnTenantUpdated );
	}

	protected CFIntXMsgRspnTenantDeleted getRspnTenantDeleted() {
		if( rspnTenantDeleted == null ) {
			rspnTenantDeleted = new CFIntXMsgRspnTenantDeleted( this );
		}
		return( rspnTenantDeleted );
	}

	// Tld Response s

	protected CFIntXMsgRspnTldRec getRspnTldRec() {
		if( rspnTldRec == null ) {
			rspnTldRec = new CFIntXMsgRspnTldRec( this );
		}
		return( rspnTldRec );
	}

	protected CFIntXMsgRspnTldCreated getRspnTldCreated() {
		if( rspnTldCreated == null ) {
			rspnTldCreated = new CFIntXMsgRspnTldCreated( this );
		}
		return( rspnTldCreated );
	}

	protected CFIntXMsgRspnTldReadSingle getRspnTldReadSingle() {
		if( rspnTldReadSingle == null ) {
			rspnTldReadSingle = new CFIntXMsgRspnTldReadSingle( this );
			rspnTldReadSingle.addElementHandler( "Tld", getRspnTldRec() );
		}
		return( rspnTldReadSingle );
	}

	protected CFIntXMsgRspnTldReadList getRspnTldReadList() {
		if( rspnTldReadList == null ) {
			rspnTldReadList = new CFIntXMsgRspnTldReadList( this );
			rspnTldReadList.addElementHandler( "Tld", getRspnTldRec() );
		}
		return( rspnTldReadList );
	}

	protected CFIntXMsgRspnTldLocked getRspnTldLocked() {
		if( rspnTldLocked == null ) {
			rspnTldLocked = new CFIntXMsgRspnTldLocked( this );
		}
		return( rspnTldLocked );
	}

	protected CFIntXMsgRspnTldUpdated getRspnTldUpdated() {
		if( rspnTldUpdated == null ) {
			rspnTldUpdated = new CFIntXMsgRspnTldUpdated( this );
		}
		return( rspnTldUpdated );
	}

	protected CFIntXMsgRspnTldDeleted getRspnTldDeleted() {
		if( rspnTldDeleted == null ) {
			rspnTldDeleted = new CFIntXMsgRspnTldDeleted( this );
		}
		return( rspnTldDeleted );
	}

	// TopDomain Response s

	protected CFIntXMsgRspnTopDomainRec getRspnTopDomainRec() {
		if( rspnTopDomainRec == null ) {
			rspnTopDomainRec = new CFIntXMsgRspnTopDomainRec( this );
		}
		return( rspnTopDomainRec );
	}

	protected CFIntXMsgRspnTopDomainCreated getRspnTopDomainCreated() {
		if( rspnTopDomainCreated == null ) {
			rspnTopDomainCreated = new CFIntXMsgRspnTopDomainCreated( this );
		}
		return( rspnTopDomainCreated );
	}

	protected CFIntXMsgRspnTopDomainReadSingle getRspnTopDomainReadSingle() {
		if( rspnTopDomainReadSingle == null ) {
			rspnTopDomainReadSingle = new CFIntXMsgRspnTopDomainReadSingle( this );
			rspnTopDomainReadSingle.addElementHandler( "TopDomain", getRspnTopDomainRec() );
		}
		return( rspnTopDomainReadSingle );
	}

	protected CFIntXMsgRspnTopDomainReadList getRspnTopDomainReadList() {
		if( rspnTopDomainReadList == null ) {
			rspnTopDomainReadList = new CFIntXMsgRspnTopDomainReadList( this );
			rspnTopDomainReadList.addElementHandler( "TopDomain", getRspnTopDomainRec() );
		}
		return( rspnTopDomainReadList );
	}

	protected CFIntXMsgRspnTopDomainLocked getRspnTopDomainLocked() {
		if( rspnTopDomainLocked == null ) {
			rspnTopDomainLocked = new CFIntXMsgRspnTopDomainLocked( this );
		}
		return( rspnTopDomainLocked );
	}

	protected CFIntXMsgRspnTopDomainUpdated getRspnTopDomainUpdated() {
		if( rspnTopDomainUpdated == null ) {
			rspnTopDomainUpdated = new CFIntXMsgRspnTopDomainUpdated( this );
		}
		return( rspnTopDomainUpdated );
	}

	protected CFIntXMsgRspnTopDomainDeleted getRspnTopDomainDeleted() {
		if( rspnTopDomainDeleted == null ) {
			rspnTopDomainDeleted = new CFIntXMsgRspnTopDomainDeleted( this );
		}
		return( rspnTopDomainDeleted );
	}

	// TopProject Response s

	protected CFIntXMsgRspnTopProjectRec getRspnTopProjectRec() {
		if( rspnTopProjectRec == null ) {
			rspnTopProjectRec = new CFIntXMsgRspnTopProjectRec( this );
		}
		return( rspnTopProjectRec );
	}

	protected CFIntXMsgRspnTopProjectCreated getRspnTopProjectCreated() {
		if( rspnTopProjectCreated == null ) {
			rspnTopProjectCreated = new CFIntXMsgRspnTopProjectCreated( this );
		}
		return( rspnTopProjectCreated );
	}

	protected CFIntXMsgRspnTopProjectReadSingle getRspnTopProjectReadSingle() {
		if( rspnTopProjectReadSingle == null ) {
			rspnTopProjectReadSingle = new CFIntXMsgRspnTopProjectReadSingle( this );
			rspnTopProjectReadSingle.addElementHandler( "TopProject", getRspnTopProjectRec() );
		}
		return( rspnTopProjectReadSingle );
	}

	protected CFIntXMsgRspnTopProjectReadList getRspnTopProjectReadList() {
		if( rspnTopProjectReadList == null ) {
			rspnTopProjectReadList = new CFIntXMsgRspnTopProjectReadList( this );
			rspnTopProjectReadList.addElementHandler( "TopProject", getRspnTopProjectRec() );
		}
		return( rspnTopProjectReadList );
	}

	protected CFIntXMsgRspnTopProjectLocked getRspnTopProjectLocked() {
		if( rspnTopProjectLocked == null ) {
			rspnTopProjectLocked = new CFIntXMsgRspnTopProjectLocked( this );
		}
		return( rspnTopProjectLocked );
	}

	protected CFIntXMsgRspnTopProjectUpdated getRspnTopProjectUpdated() {
		if( rspnTopProjectUpdated == null ) {
			rspnTopProjectUpdated = new CFIntXMsgRspnTopProjectUpdated( this );
		}
		return( rspnTopProjectUpdated );
	}

	protected CFIntXMsgRspnTopProjectDeleted getRspnTopProjectDeleted() {
		if( rspnTopProjectDeleted == null ) {
			rspnTopProjectDeleted = new CFIntXMsgRspnTopProjectDeleted( this );
		}
		return( rspnTopProjectDeleted );
	}

	// URLProtocol Response s

	protected CFIntXMsgRspnURLProtocolRec getRspnURLProtocolRec() {
		if( rspnURLProtocolRec == null ) {
			rspnURLProtocolRec = new CFIntXMsgRspnURLProtocolRec( this );
		}
		return( rspnURLProtocolRec );
	}

	protected CFIntXMsgRspnURLProtocolCreated getRspnURLProtocolCreated() {
		if( rspnURLProtocolCreated == null ) {
			rspnURLProtocolCreated = new CFIntXMsgRspnURLProtocolCreated( this );
		}
		return( rspnURLProtocolCreated );
	}

	protected CFIntXMsgRspnURLProtocolReadSingle getRspnURLProtocolReadSingle() {
		if( rspnURLProtocolReadSingle == null ) {
			rspnURLProtocolReadSingle = new CFIntXMsgRspnURLProtocolReadSingle( this );
			rspnURLProtocolReadSingle.addElementHandler( "URLProtocol", getRspnURLProtocolRec() );
		}
		return( rspnURLProtocolReadSingle );
	}

	protected CFIntXMsgRspnURLProtocolReadList getRspnURLProtocolReadList() {
		if( rspnURLProtocolReadList == null ) {
			rspnURLProtocolReadList = new CFIntXMsgRspnURLProtocolReadList( this );
			rspnURLProtocolReadList.addElementHandler( "URLProtocol", getRspnURLProtocolRec() );
		}
		return( rspnURLProtocolReadList );
	}

	protected CFIntXMsgRspnURLProtocolLocked getRspnURLProtocolLocked() {
		if( rspnURLProtocolLocked == null ) {
			rspnURLProtocolLocked = new CFIntXMsgRspnURLProtocolLocked( this );
		}
		return( rspnURLProtocolLocked );
	}

	protected CFIntXMsgRspnURLProtocolUpdated getRspnURLProtocolUpdated() {
		if( rspnURLProtocolUpdated == null ) {
			rspnURLProtocolUpdated = new CFIntXMsgRspnURLProtocolUpdated( this );
		}
		return( rspnURLProtocolUpdated );
	}

	protected CFIntXMsgRspnURLProtocolDeleted getRspnURLProtocolDeleted() {
		if( rspnURLProtocolDeleted == null ) {
			rspnURLProtocolDeleted = new CFIntXMsgRspnURLProtocolDeleted( this );
		}
		return( rspnURLProtocolDeleted );
	}

	// Root Element  Resolver Factory

	protected CFIntSaxRspnRoot getSaxRspnRoot() {
		if( saxRoot == null ) {
			saxRoot = new CFIntSaxRspnRoot( this );
			saxRoot.addElementHandler( "CFIntRspn", getSaxRspnDoc() );
			saxRoot.addElementHandler( "CFSecRspn", getSaxRspnDoc() );
		}
		return( saxRoot );
	}

	// Root Element 

	/*
	 *	CFIntSaxRspnRoot XML SAX Root Element  implementation
	 */
	public class CFIntSaxRspnRoot
		extends CFLibXmlCoreElementHandler
	{
		public CFIntSaxRspnRoot( CFIntXMsgRspn xmsgRspn ) {
			super( xmsgRspn );
		}

		public void startElement(
			String		uri,
			String		localName,
			String		qName,
			Attributes	attrs )
		throws SAXException
		{
		}

		public void endElement(
			String		uri,
			String		localName,
			String		qName )
		throws SAXException
		{
		}
	}

	// Document Element  Resolver Factory

	protected CFIntSaxRspnDoc getSaxRspnDoc() {
		if( saxDoc == null ) {
			saxDoc = new CFIntSaxRspnDoc( this );
			saxDoc.addElementHandler( "RspnNoDataFound", getRspnNoDataFound() );
			saxDoc.addElementHandler( "RspnException", getRspnException() );
			saxDoc.addElementHandler( "RspnFileLoaded", getRspnFileLoaded() );
			saxDoc.addElementHandler( "RspnLoggedIn", getRspnLoggedIn() );
			saxDoc.addElementHandler( "RspnLoggedOut", getRspnLoggedOut() );
			saxDoc.addElementHandler( "RspnServerProcExecuted", getRspnServerProcExecuted() );

			// Cluster Response s

			saxDoc.addElementHandler( "RspnClusterCreated", getRspnClusterCreated() );
			saxDoc.addElementHandler( "RspnClusterReadSingle", getRspnClusterReadSingle() );
			saxDoc.addElementHandler( "RspnClusterReadList", getRspnClusterReadList() );
			saxDoc.addElementHandler( "RspnClusterLocked", getRspnClusterLocked() );
			saxDoc.addElementHandler( "RspnClusterUpdated", getRspnClusterUpdated() );
			saxDoc.addElementHandler( "RspnClusterDeleted", getRspnClusterDeleted() );

			// HostNode Response s

			saxDoc.addElementHandler( "RspnHostNodeCreated", getRspnHostNodeCreated() );
			saxDoc.addElementHandler( "RspnHostNodeReadSingle", getRspnHostNodeReadSingle() );
			saxDoc.addElementHandler( "RspnHostNodeReadList", getRspnHostNodeReadList() );
			saxDoc.addElementHandler( "RspnHostNodeLocked", getRspnHostNodeLocked() );
			saxDoc.addElementHandler( "RspnHostNodeUpdated", getRspnHostNodeUpdated() );
			saxDoc.addElementHandler( "RspnHostNodeDeleted", getRspnHostNodeDeleted() );

			// ISOCcy Response s

			saxDoc.addElementHandler( "RspnISOCcyCreated", getRspnISOCcyCreated() );
			saxDoc.addElementHandler( "RspnISOCcyReadSingle", getRspnISOCcyReadSingle() );
			saxDoc.addElementHandler( "RspnISOCcyReadList", getRspnISOCcyReadList() );
			saxDoc.addElementHandler( "RspnISOCcyLocked", getRspnISOCcyLocked() );
			saxDoc.addElementHandler( "RspnISOCcyUpdated", getRspnISOCcyUpdated() );
			saxDoc.addElementHandler( "RspnISOCcyDeleted", getRspnISOCcyDeleted() );

			// ISOCtry Response s

			saxDoc.addElementHandler( "RspnISOCtryCreated", getRspnISOCtryCreated() );
			saxDoc.addElementHandler( "RspnISOCtryReadSingle", getRspnISOCtryReadSingle() );
			saxDoc.addElementHandler( "RspnISOCtryReadList", getRspnISOCtryReadList() );
			saxDoc.addElementHandler( "RspnISOCtryLocked", getRspnISOCtryLocked() );
			saxDoc.addElementHandler( "RspnISOCtryUpdated", getRspnISOCtryUpdated() );
			saxDoc.addElementHandler( "RspnISOCtryDeleted", getRspnISOCtryDeleted() );

			// ISOCtryCcy Response s

			saxDoc.addElementHandler( "RspnISOCtryCcyCreated", getRspnISOCtryCcyCreated() );
			saxDoc.addElementHandler( "RspnISOCtryCcyReadSingle", getRspnISOCtryCcyReadSingle() );
			saxDoc.addElementHandler( "RspnISOCtryCcyReadList", getRspnISOCtryCcyReadList() );
			saxDoc.addElementHandler( "RspnISOCtryCcyLocked", getRspnISOCtryCcyLocked() );
			saxDoc.addElementHandler( "RspnISOCtryCcyUpdated", getRspnISOCtryCcyUpdated() );
			saxDoc.addElementHandler( "RspnISOCtryCcyDeleted", getRspnISOCtryCcyDeleted() );

			// ISOCtryLang Response s

			saxDoc.addElementHandler( "RspnISOCtryLangCreated", getRspnISOCtryLangCreated() );
			saxDoc.addElementHandler( "RspnISOCtryLangReadSingle", getRspnISOCtryLangReadSingle() );
			saxDoc.addElementHandler( "RspnISOCtryLangReadList", getRspnISOCtryLangReadList() );
			saxDoc.addElementHandler( "RspnISOCtryLangLocked", getRspnISOCtryLangLocked() );
			saxDoc.addElementHandler( "RspnISOCtryLangUpdated", getRspnISOCtryLangUpdated() );
			saxDoc.addElementHandler( "RspnISOCtryLangDeleted", getRspnISOCtryLangDeleted() );

			// ISOLang Response s

			saxDoc.addElementHandler( "RspnISOLangCreated", getRspnISOLangCreated() );
			saxDoc.addElementHandler( "RspnISOLangReadSingle", getRspnISOLangReadSingle() );
			saxDoc.addElementHandler( "RspnISOLangReadList", getRspnISOLangReadList() );
			saxDoc.addElementHandler( "RspnISOLangLocked", getRspnISOLangLocked() );
			saxDoc.addElementHandler( "RspnISOLangUpdated", getRspnISOLangUpdated() );
			saxDoc.addElementHandler( "RspnISOLangDeleted", getRspnISOLangDeleted() );

			// ISOTZone Response s

			saxDoc.addElementHandler( "RspnISOTZoneCreated", getRspnISOTZoneCreated() );
			saxDoc.addElementHandler( "RspnISOTZoneReadSingle", getRspnISOTZoneReadSingle() );
			saxDoc.addElementHandler( "RspnISOTZoneReadList", getRspnISOTZoneReadList() );
			saxDoc.addElementHandler( "RspnISOTZoneLocked", getRspnISOTZoneLocked() );
			saxDoc.addElementHandler( "RspnISOTZoneUpdated", getRspnISOTZoneUpdated() );
			saxDoc.addElementHandler( "RspnISOTZoneDeleted", getRspnISOTZoneDeleted() );

			// License Response s

			saxDoc.addElementHandler( "RspnLicenseCreated", getRspnLicenseCreated() );
			saxDoc.addElementHandler( "RspnLicenseReadSingle", getRspnLicenseReadSingle() );
			saxDoc.addElementHandler( "RspnLicenseReadList", getRspnLicenseReadList() );
			saxDoc.addElementHandler( "RspnLicenseLocked", getRspnLicenseLocked() );
			saxDoc.addElementHandler( "RspnLicenseUpdated", getRspnLicenseUpdated() );
			saxDoc.addElementHandler( "RspnLicenseDeleted", getRspnLicenseDeleted() );

			// MajorVersion Response s

			saxDoc.addElementHandler( "RspnMajorVersionCreated", getRspnMajorVersionCreated() );
			saxDoc.addElementHandler( "RspnMajorVersionReadSingle", getRspnMajorVersionReadSingle() );
			saxDoc.addElementHandler( "RspnMajorVersionReadList", getRspnMajorVersionReadList() );
			saxDoc.addElementHandler( "RspnMajorVersionLocked", getRspnMajorVersionLocked() );
			saxDoc.addElementHandler( "RspnMajorVersionUpdated", getRspnMajorVersionUpdated() );
			saxDoc.addElementHandler( "RspnMajorVersionDeleted", getRspnMajorVersionDeleted() );

			// MimeType Response s

			saxDoc.addElementHandler( "RspnMimeTypeCreated", getRspnMimeTypeCreated() );
			saxDoc.addElementHandler( "RspnMimeTypeReadSingle", getRspnMimeTypeReadSingle() );
			saxDoc.addElementHandler( "RspnMimeTypeReadList", getRspnMimeTypeReadList() );
			saxDoc.addElementHandler( "RspnMimeTypeLocked", getRspnMimeTypeLocked() );
			saxDoc.addElementHandler( "RspnMimeTypeUpdated", getRspnMimeTypeUpdated() );
			saxDoc.addElementHandler( "RspnMimeTypeDeleted", getRspnMimeTypeDeleted() );

			// MinorVersion Response s

			saxDoc.addElementHandler( "RspnMinorVersionCreated", getRspnMinorVersionCreated() );
			saxDoc.addElementHandler( "RspnMinorVersionReadSingle", getRspnMinorVersionReadSingle() );
			saxDoc.addElementHandler( "RspnMinorVersionReadList", getRspnMinorVersionReadList() );
			saxDoc.addElementHandler( "RspnMinorVersionLocked", getRspnMinorVersionLocked() );
			saxDoc.addElementHandler( "RspnMinorVersionUpdated", getRspnMinorVersionUpdated() );
			saxDoc.addElementHandler( "RspnMinorVersionDeleted", getRspnMinorVersionDeleted() );

			// SecApp Response s

			saxDoc.addElementHandler( "RspnSecAppCreated", getRspnSecAppCreated() );
			saxDoc.addElementHandler( "RspnSecAppReadSingle", getRspnSecAppReadSingle() );
			saxDoc.addElementHandler( "RspnSecAppReadList", getRspnSecAppReadList() );
			saxDoc.addElementHandler( "RspnSecAppLocked", getRspnSecAppLocked() );
			saxDoc.addElementHandler( "RspnSecAppUpdated", getRspnSecAppUpdated() );
			saxDoc.addElementHandler( "RspnSecAppDeleted", getRspnSecAppDeleted() );

			// SecDevice Response s

			saxDoc.addElementHandler( "RspnSecDeviceCreated", getRspnSecDeviceCreated() );
			saxDoc.addElementHandler( "RspnSecDeviceReadSingle", getRspnSecDeviceReadSingle() );
			saxDoc.addElementHandler( "RspnSecDeviceReadList", getRspnSecDeviceReadList() );
			saxDoc.addElementHandler( "RspnSecDeviceLocked", getRspnSecDeviceLocked() );
			saxDoc.addElementHandler( "RspnSecDeviceUpdated", getRspnSecDeviceUpdated() );
			saxDoc.addElementHandler( "RspnSecDeviceDeleted", getRspnSecDeviceDeleted() );

			// SecForm Response s

			saxDoc.addElementHandler( "RspnSecFormCreated", getRspnSecFormCreated() );
			saxDoc.addElementHandler( "RspnSecFormReadSingle", getRspnSecFormReadSingle() );
			saxDoc.addElementHandler( "RspnSecFormReadList", getRspnSecFormReadList() );
			saxDoc.addElementHandler( "RspnSecFormLocked", getRspnSecFormLocked() );
			saxDoc.addElementHandler( "RspnSecFormUpdated", getRspnSecFormUpdated() );
			saxDoc.addElementHandler( "RspnSecFormDeleted", getRspnSecFormDeleted() );

			// SecGroup Response s

			saxDoc.addElementHandler( "RspnSecGroupCreated", getRspnSecGroupCreated() );
			saxDoc.addElementHandler( "RspnSecGroupReadSingle", getRspnSecGroupReadSingle() );
			saxDoc.addElementHandler( "RspnSecGroupReadList", getRspnSecGroupReadList() );
			saxDoc.addElementHandler( "RspnSecGroupLocked", getRspnSecGroupLocked() );
			saxDoc.addElementHandler( "RspnSecGroupUpdated", getRspnSecGroupUpdated() );
			saxDoc.addElementHandler( "RspnSecGroupDeleted", getRspnSecGroupDeleted() );

			// SecGroupForm Response s

			saxDoc.addElementHandler( "RspnSecGroupFormCreated", getRspnSecGroupFormCreated() );
			saxDoc.addElementHandler( "RspnSecGroupFormReadSingle", getRspnSecGroupFormReadSingle() );
			saxDoc.addElementHandler( "RspnSecGroupFormReadList", getRspnSecGroupFormReadList() );
			saxDoc.addElementHandler( "RspnSecGroupFormLocked", getRspnSecGroupFormLocked() );
			saxDoc.addElementHandler( "RspnSecGroupFormUpdated", getRspnSecGroupFormUpdated() );
			saxDoc.addElementHandler( "RspnSecGroupFormDeleted", getRspnSecGroupFormDeleted() );

			// SecGrpInc Response s

			saxDoc.addElementHandler( "RspnSecGrpIncCreated", getRspnSecGrpIncCreated() );
			saxDoc.addElementHandler( "RspnSecGrpIncReadSingle", getRspnSecGrpIncReadSingle() );
			saxDoc.addElementHandler( "RspnSecGrpIncReadList", getRspnSecGrpIncReadList() );
			saxDoc.addElementHandler( "RspnSecGrpIncLocked", getRspnSecGrpIncLocked() );
			saxDoc.addElementHandler( "RspnSecGrpIncUpdated", getRspnSecGrpIncUpdated() );
			saxDoc.addElementHandler( "RspnSecGrpIncDeleted", getRspnSecGrpIncDeleted() );

			// SecGrpMemb Response s

			saxDoc.addElementHandler( "RspnSecGrpMembCreated", getRspnSecGrpMembCreated() );
			saxDoc.addElementHandler( "RspnSecGrpMembReadSingle", getRspnSecGrpMembReadSingle() );
			saxDoc.addElementHandler( "RspnSecGrpMembReadList", getRspnSecGrpMembReadList() );
			saxDoc.addElementHandler( "RspnSecGrpMembLocked", getRspnSecGrpMembLocked() );
			saxDoc.addElementHandler( "RspnSecGrpMembUpdated", getRspnSecGrpMembUpdated() );
			saxDoc.addElementHandler( "RspnSecGrpMembDeleted", getRspnSecGrpMembDeleted() );

			// SecSession Response s

			saxDoc.addElementHandler( "RspnSecSessionCreated", getRspnSecSessionCreated() );
			saxDoc.addElementHandler( "RspnSecSessionReadSingle", getRspnSecSessionReadSingle() );
			saxDoc.addElementHandler( "RspnSecSessionReadList", getRspnSecSessionReadList() );
			saxDoc.addElementHandler( "RspnSecSessionLocked", getRspnSecSessionLocked() );
			saxDoc.addElementHandler( "RspnSecSessionUpdated", getRspnSecSessionUpdated() );
			saxDoc.addElementHandler( "RspnSecSessionDeleted", getRspnSecSessionDeleted() );

			// SecUser Response s

			saxDoc.addElementHandler( "RspnSecUserCreated", getRspnSecUserCreated() );
			saxDoc.addElementHandler( "RspnSecUserReadSingle", getRspnSecUserReadSingle() );
			saxDoc.addElementHandler( "RspnSecUserReadList", getRspnSecUserReadList() );
			saxDoc.addElementHandler( "RspnSecUserLocked", getRspnSecUserLocked() );
			saxDoc.addElementHandler( "RspnSecUserUpdated", getRspnSecUserUpdated() );
			saxDoc.addElementHandler( "RspnSecUserDeleted", getRspnSecUserDeleted() );

			// Service Response s

			saxDoc.addElementHandler( "RspnServiceCreated", getRspnServiceCreated() );
			saxDoc.addElementHandler( "RspnServiceReadSingle", getRspnServiceReadSingle() );
			saxDoc.addElementHandler( "RspnServiceReadList", getRspnServiceReadList() );
			saxDoc.addElementHandler( "RspnServiceLocked", getRspnServiceLocked() );
			saxDoc.addElementHandler( "RspnServiceUpdated", getRspnServiceUpdated() );
			saxDoc.addElementHandler( "RspnServiceDeleted", getRspnServiceDeleted() );

			// ServiceType Response s

			saxDoc.addElementHandler( "RspnServiceTypeCreated", getRspnServiceTypeCreated() );
			saxDoc.addElementHandler( "RspnServiceTypeReadSingle", getRspnServiceTypeReadSingle() );
			saxDoc.addElementHandler( "RspnServiceTypeReadList", getRspnServiceTypeReadList() );
			saxDoc.addElementHandler( "RspnServiceTypeLocked", getRspnServiceTypeLocked() );
			saxDoc.addElementHandler( "RspnServiceTypeUpdated", getRspnServiceTypeUpdated() );
			saxDoc.addElementHandler( "RspnServiceTypeDeleted", getRspnServiceTypeDeleted() );

			// SubProject Response s

			saxDoc.addElementHandler( "RspnSubProjectCreated", getRspnSubProjectCreated() );
			saxDoc.addElementHandler( "RspnSubProjectReadSingle", getRspnSubProjectReadSingle() );
			saxDoc.addElementHandler( "RspnSubProjectReadList", getRspnSubProjectReadList() );
			saxDoc.addElementHandler( "RspnSubProjectLocked", getRspnSubProjectLocked() );
			saxDoc.addElementHandler( "RspnSubProjectUpdated", getRspnSubProjectUpdated() );
			saxDoc.addElementHandler( "RspnSubProjectDeleted", getRspnSubProjectDeleted() );

			// SysCluster Response s

			saxDoc.addElementHandler( "RspnSysClusterCreated", getRspnSysClusterCreated() );
			saxDoc.addElementHandler( "RspnSysClusterReadSingle", getRspnSysClusterReadSingle() );
			saxDoc.addElementHandler( "RspnSysClusterReadList", getRspnSysClusterReadList() );
			saxDoc.addElementHandler( "RspnSysClusterLocked", getRspnSysClusterLocked() );
			saxDoc.addElementHandler( "RspnSysClusterUpdated", getRspnSysClusterUpdated() );
			saxDoc.addElementHandler( "RspnSysClusterDeleted", getRspnSysClusterDeleted() );

			// TSecGroup Response s

			saxDoc.addElementHandler( "RspnTSecGroupCreated", getRspnTSecGroupCreated() );
			saxDoc.addElementHandler( "RspnTSecGroupReadSingle", getRspnTSecGroupReadSingle() );
			saxDoc.addElementHandler( "RspnTSecGroupReadList", getRspnTSecGroupReadList() );
			saxDoc.addElementHandler( "RspnTSecGroupLocked", getRspnTSecGroupLocked() );
			saxDoc.addElementHandler( "RspnTSecGroupUpdated", getRspnTSecGroupUpdated() );
			saxDoc.addElementHandler( "RspnTSecGroupDeleted", getRspnTSecGroupDeleted() );

			// TSecGrpInc Response s

			saxDoc.addElementHandler( "RspnTSecGrpIncCreated", getRspnTSecGrpIncCreated() );
			saxDoc.addElementHandler( "RspnTSecGrpIncReadSingle", getRspnTSecGrpIncReadSingle() );
			saxDoc.addElementHandler( "RspnTSecGrpIncReadList", getRspnTSecGrpIncReadList() );
			saxDoc.addElementHandler( "RspnTSecGrpIncLocked", getRspnTSecGrpIncLocked() );
			saxDoc.addElementHandler( "RspnTSecGrpIncUpdated", getRspnTSecGrpIncUpdated() );
			saxDoc.addElementHandler( "RspnTSecGrpIncDeleted", getRspnTSecGrpIncDeleted() );

			// TSecGrpMemb Response s

			saxDoc.addElementHandler( "RspnTSecGrpMembCreated", getRspnTSecGrpMembCreated() );
			saxDoc.addElementHandler( "RspnTSecGrpMembReadSingle", getRspnTSecGrpMembReadSingle() );
			saxDoc.addElementHandler( "RspnTSecGrpMembReadList", getRspnTSecGrpMembReadList() );
			saxDoc.addElementHandler( "RspnTSecGrpMembLocked", getRspnTSecGrpMembLocked() );
			saxDoc.addElementHandler( "RspnTSecGrpMembUpdated", getRspnTSecGrpMembUpdated() );
			saxDoc.addElementHandler( "RspnTSecGrpMembDeleted", getRspnTSecGrpMembDeleted() );

			// Tenant Response s

			saxDoc.addElementHandler( "RspnTenantCreated", getRspnTenantCreated() );
			saxDoc.addElementHandler( "RspnTenantReadSingle", getRspnTenantReadSingle() );
			saxDoc.addElementHandler( "RspnTenantReadList", getRspnTenantReadList() );
			saxDoc.addElementHandler( "RspnTenantLocked", getRspnTenantLocked() );
			saxDoc.addElementHandler( "RspnTenantUpdated", getRspnTenantUpdated() );
			saxDoc.addElementHandler( "RspnTenantDeleted", getRspnTenantDeleted() );

			// Tld Response s

			saxDoc.addElementHandler( "RspnTldCreated", getRspnTldCreated() );
			saxDoc.addElementHandler( "RspnTldReadSingle", getRspnTldReadSingle() );
			saxDoc.addElementHandler( "RspnTldReadList", getRspnTldReadList() );
			saxDoc.addElementHandler( "RspnTldLocked", getRspnTldLocked() );
			saxDoc.addElementHandler( "RspnTldUpdated", getRspnTldUpdated() );
			saxDoc.addElementHandler( "RspnTldDeleted", getRspnTldDeleted() );

			// TopDomain Response s

			saxDoc.addElementHandler( "RspnTopDomainCreated", getRspnTopDomainCreated() );
			saxDoc.addElementHandler( "RspnTopDomainReadSingle", getRspnTopDomainReadSingle() );
			saxDoc.addElementHandler( "RspnTopDomainReadList", getRspnTopDomainReadList() );
			saxDoc.addElementHandler( "RspnTopDomainLocked", getRspnTopDomainLocked() );
			saxDoc.addElementHandler( "RspnTopDomainUpdated", getRspnTopDomainUpdated() );
			saxDoc.addElementHandler( "RspnTopDomainDeleted", getRspnTopDomainDeleted() );

			// TopProject Response s

			saxDoc.addElementHandler( "RspnTopProjectCreated", getRspnTopProjectCreated() );
			saxDoc.addElementHandler( "RspnTopProjectReadSingle", getRspnTopProjectReadSingle() );
			saxDoc.addElementHandler( "RspnTopProjectReadList", getRspnTopProjectReadList() );
			saxDoc.addElementHandler( "RspnTopProjectLocked", getRspnTopProjectLocked() );
			saxDoc.addElementHandler( "RspnTopProjectUpdated", getRspnTopProjectUpdated() );
			saxDoc.addElementHandler( "RspnTopProjectDeleted", getRspnTopProjectDeleted() );

			// URLProtocol Response s

			saxDoc.addElementHandler( "RspnURLProtocolCreated", getRspnURLProtocolCreated() );
			saxDoc.addElementHandler( "RspnURLProtocolReadSingle", getRspnURLProtocolReadSingle() );
			saxDoc.addElementHandler( "RspnURLProtocolReadList", getRspnURLProtocolReadList() );
			saxDoc.addElementHandler( "RspnURLProtocolLocked", getRspnURLProtocolLocked() );
			saxDoc.addElementHandler( "RspnURLProtocolUpdated", getRspnURLProtocolUpdated() );
			saxDoc.addElementHandler( "RspnURLProtocolDeleted", getRspnURLProtocolDeleted() );

		}
		return( saxDoc );
	}

	// Document Element 

	/*
	 *	CFIntSaxRspnDoc XML SAX Doc Element  implementation
	 */
	public class CFIntSaxRspnDoc
		extends CFLibXmlCoreElementHandler
	{
		public CFIntSaxRspnDoc( CFIntXMsgRspn xmsgRspn ) {
			super( xmsgRspn );
		}

		public void startElement(
			String		uri,
			String		localName,
			String		qName,
			Attributes	attrs )
		throws SAXException
		{
		}

		public void endElement(
			String		uri,
			String		localName,
			String		qName )
		throws SAXException
		{
		}
	}

	// Parse an XML string's contents

	public void parseStringContents( String str ) {
		deleted = false;
		exceptionRaised = null;
		lastObjectProcessed = null;
		sortedListOfObjects = null;
		logContent = null;
		dataChanged = false;
		super.parseStringContents( str );
	}

	// Parse a file

	public void parse( String url ) {
		deleted = false;
		exceptionRaised = null;
		lastObjectProcessed = null;
		sortedListOfObjects = null;
		logContent = null;
		dataChanged = false;
		super.parse( url );
	}

	public void parseFile( String url ) {
		deleted = false;
		exceptionRaised = null;
		lastObjectProcessed = null;
		sortedListOfObjects = null;
		logContent = null;
		dataChanged = false;
		super.parse( url );
	}
}
