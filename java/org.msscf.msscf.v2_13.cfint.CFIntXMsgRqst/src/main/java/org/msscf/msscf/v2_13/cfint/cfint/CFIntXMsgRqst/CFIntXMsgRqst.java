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

package org.msscf.msscf.v2_13.cfint.cfint.CFIntXMsgRqst;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.net.URISyntaxException;
import java.net.URL;

import org.xml.sax.*;
import org.apache.commons.codec.binary.Base64;
import org.apache.xerces.xni.grammars.Grammar;

import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cflib.CFLib.Tip.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;
import org.msscf.msscf.v2_13.cfint.cfint.CFIntXMsg.CFIntXMsgSchemaMessageFormatter;

public class CFIntXMsgRqst
	extends CFLibXmlCoreSaxParser
	implements ContentHandler,
		ICFTipRequestHandler,
		ICFTipThrowableFormatter
{

	// The namespace URI of the supported schema
	public final static String	SCHEMA_XMLNS = "uri://xsd/cfintrqst";

	// The source for loading the supported schema
	public final static String	SCHEMA_URI = "/opt/msscf/2.0.13/xsd/cfint-rqst.xsd";
	public final static String	SCHEMA_ROOT_URI = "/xsd/cfint-rqst.xsd";
	public final static String CFSEC_XMLNS = "uri://xsd/cfsecrqst";
	public final static String CFSEC_URI = "/opt/msscf/2.0.13/xsd/cfsec-rqst.xsd";
	public final static String CFSEC_ROOT_URI = "/xsd/cfsec-rqst.xsd";

	protected static Grammar myGrammar = null;

	private CFIntXMsgSchemaMessageFormatter schemaMessageFormatter = new CFIntXMsgSchemaMessageFormatter();
	private ICFIntSchemaObj schemaObj = null;
	private CFTipEnvelopeHandler envelope = null;
	private StringBuffer response = new StringBuffer();
	private boolean caughtException = false;
	// Constructors

	public CFIntXMsgRqst() {
		super();
		setRootElementHandler( getSaxRqstRoot() );
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

	public CFIntXMsgRqst( ICFIntSchemaObj schemaObj ) {
		super();
		setRootElementHandler( getSaxRqstRoot() );
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

	public CFIntXMsgRqst( ICFLibMessageLog logger ) {
		super( logger );
		setRootElementHandler( getSaxRqstRoot() );
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

	public CFIntXMsgRqst( ICFIntSchemaObj schemaObj, ICFLibMessageLog logger ) {
		super( logger );
		setRootElementHandler( getSaxRqstRoot() );
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

	// Accessors for formatter

	public CFIntXMsgSchemaMessageFormatter getSchemaMessageFormatter() {
		return( schemaMessageFormatter );
	}

	// Accessors for envelope handler

	public CFTipEnvelopeHandler getEnvelope() {
		return( envelope );
	}

	public void setEnvelope( CFTipEnvelopeHandler value ) {
		envelope = value;
		if( envelope != null ) {
			envelope.setThrowableFormatter( this );
		}
	}


	// Satisfy ICFLibThrowableFormatter

	public String formatResponseThrowable( Throwable t ) {
		String response = schemaMessageFormatter.formatRspnXmlPreamble() + "\n"
				+	"\t" + CFIntXMsgSchemaMessageFormatter.formatRspnException( "\n\t\t\t\t", t )
				+	"\n"
				+	schemaMessageFormatter.formatRspnXmlPostamble();
		return( response );
	}

	// Accessors for invoker

	public String getResponse() {
		String retval = response.toString();
		return( retval );
	}

	public void resetResponse() {
		response = new StringBuffer();
		caughtException = false;
	}

	public void appendResponse( String str ) {
		response.append( str );
	}

	public boolean getCaughtException() {
		return( caughtException );
	}

	public void setCaughtException( boolean value ) {
		caughtException = value;
	}

	// Element  instances

	// Cluster Request s

	private CFIntXMsgRqstClusterCreate rqstClusterCreate = null;
	private CFIntXMsgRqstClusterRead rqstClusterRead = null;
	private CFIntXMsgRqstClusterLock rqstClusterLock = null;
	private CFIntXMsgRqstClusterUpdate rqstClusterUpdate = null;
	private CFIntXMsgRqstClusterDelete rqstClusterDelete = null;
	private CFIntXMsgRqstClusterReadAll rqstClusterReadAll = null;
	private CFIntXMsgRqstClusterPageAll rqstClusterPageAll = null;
	private CFIntXMsgRqstClusterRdByUDomNameIdx rqstClusterRdByUDomNameIdx = null;
	private CFIntXMsgRqstClusterRdByUDescrIdx rqstClusterRdByUDescrIdx = null;
	private CFIntXMsgRqstClusterDelByIdIdx rqstClusterDelByIdIdx = null;
	private CFIntXMsgRqstClusterDelByUDomNameIdx rqstClusterDelByUDomNameIdx = null;
	private CFIntXMsgRqstClusterDelByUDescrIdx rqstClusterDelByUDescrIdx = null;
	// HostNode Request s

	private CFIntXMsgRqstHostNodeCreate rqstHostNodeCreate = null;
	private CFIntXMsgRqstHostNodeRead rqstHostNodeRead = null;
	private CFIntXMsgRqstHostNodeLock rqstHostNodeLock = null;
	private CFIntXMsgRqstHostNodeUpdate rqstHostNodeUpdate = null;
	private CFIntXMsgRqstHostNodeDelete rqstHostNodeDelete = null;
	private CFIntXMsgRqstHostNodeReadAll rqstHostNodeReadAll = null;
	private CFIntXMsgRqstHostNodePageAll rqstHostNodePageAll = null;
	private CFIntXMsgRqstHostNodeRdByClusterIdx rqstHostNodeRdByClusterIdx = null;
	private CFIntXMsgRqstHostNodeRdByUDescrIdx rqstHostNodeRdByUDescrIdx = null;
	private CFIntXMsgRqstHostNodeRdByHostNameIdx rqstHostNodeRdByHostNameIdx = null;
	private CFIntXMsgRqstHostNodePageByClusterIdx rqstHostNodePageByClusterIdx = null;
	private CFIntXMsgRqstHostNodeDelByIdIdx rqstHostNodeDelByIdIdx = null;
	private CFIntXMsgRqstHostNodeDelByClusterIdx rqstHostNodeDelByClusterIdx = null;
	private CFIntXMsgRqstHostNodeDelByUDescrIdx rqstHostNodeDelByUDescrIdx = null;
	private CFIntXMsgRqstHostNodeDelByHostNameIdx rqstHostNodeDelByHostNameIdx = null;
	// ISOCcy Request s

	private CFIntXMsgRqstISOCcyCreate rqstISOCcyCreate = null;
	private CFIntXMsgRqstISOCcyRead rqstISOCcyRead = null;
	private CFIntXMsgRqstISOCcyLock rqstISOCcyLock = null;
	private CFIntXMsgRqstISOCcyUpdate rqstISOCcyUpdate = null;
	private CFIntXMsgRqstISOCcyDelete rqstISOCcyDelete = null;
	private CFIntXMsgRqstISOCcyReadAll rqstISOCcyReadAll = null;
	private CFIntXMsgRqstISOCcyRdByCcyCdIdx rqstISOCcyRdByCcyCdIdx = null;
	private CFIntXMsgRqstISOCcyRdByCcyNmIdx rqstISOCcyRdByCcyNmIdx = null;
	private CFIntXMsgRqstISOCcyDelByIdIdx rqstISOCcyDelByIdIdx = null;
	private CFIntXMsgRqstISOCcyDelByCcyCdIdx rqstISOCcyDelByCcyCdIdx = null;
	private CFIntXMsgRqstISOCcyDelByCcyNmIdx rqstISOCcyDelByCcyNmIdx = null;
	// ISOCtry Request s

	private CFIntXMsgRqstISOCtryCreate rqstISOCtryCreate = null;
	private CFIntXMsgRqstISOCtryRead rqstISOCtryRead = null;
	private CFIntXMsgRqstISOCtryLock rqstISOCtryLock = null;
	private CFIntXMsgRqstISOCtryUpdate rqstISOCtryUpdate = null;
	private CFIntXMsgRqstISOCtryDelete rqstISOCtryDelete = null;
	private CFIntXMsgRqstISOCtryReadAll rqstISOCtryReadAll = null;
	private CFIntXMsgRqstISOCtryRdByISOCodeIdx rqstISOCtryRdByISOCodeIdx = null;
	private CFIntXMsgRqstISOCtryRdByNameIdx rqstISOCtryRdByNameIdx = null;
	private CFIntXMsgRqstISOCtryDelByIdIdx rqstISOCtryDelByIdIdx = null;
	private CFIntXMsgRqstISOCtryDelByISOCodeIdx rqstISOCtryDelByISOCodeIdx = null;
	private CFIntXMsgRqstISOCtryDelByNameIdx rqstISOCtryDelByNameIdx = null;
	// ISOCtryCcy Request s

	private CFIntXMsgRqstISOCtryCcyCreate rqstISOCtryCcyCreate = null;
	private CFIntXMsgRqstISOCtryCcyRead rqstISOCtryCcyRead = null;
	private CFIntXMsgRqstISOCtryCcyLock rqstISOCtryCcyLock = null;
	private CFIntXMsgRqstISOCtryCcyUpdate rqstISOCtryCcyUpdate = null;
	private CFIntXMsgRqstISOCtryCcyDelete rqstISOCtryCcyDelete = null;
	private CFIntXMsgRqstISOCtryCcyReadAll rqstISOCtryCcyReadAll = null;
	private CFIntXMsgRqstISOCtryCcyRdByCtryIdx rqstISOCtryCcyRdByCtryIdx = null;
	private CFIntXMsgRqstISOCtryCcyRdByCcyIdx rqstISOCtryCcyRdByCcyIdx = null;
	private CFIntXMsgRqstISOCtryCcyDelByIdIdx rqstISOCtryCcyDelByIdIdx = null;
	private CFIntXMsgRqstISOCtryCcyDelByCtryIdx rqstISOCtryCcyDelByCtryIdx = null;
	private CFIntXMsgRqstISOCtryCcyDelByCcyIdx rqstISOCtryCcyDelByCcyIdx = null;
	// ISOCtryLang Request s

	private CFIntXMsgRqstISOCtryLangCreate rqstISOCtryLangCreate = null;
	private CFIntXMsgRqstISOCtryLangRead rqstISOCtryLangRead = null;
	private CFIntXMsgRqstISOCtryLangLock rqstISOCtryLangLock = null;
	private CFIntXMsgRqstISOCtryLangUpdate rqstISOCtryLangUpdate = null;
	private CFIntXMsgRqstISOCtryLangDelete rqstISOCtryLangDelete = null;
	private CFIntXMsgRqstISOCtryLangReadAll rqstISOCtryLangReadAll = null;
	private CFIntXMsgRqstISOCtryLangRdByCtryIdx rqstISOCtryLangRdByCtryIdx = null;
	private CFIntXMsgRqstISOCtryLangRdByLangIdx rqstISOCtryLangRdByLangIdx = null;
	private CFIntXMsgRqstISOCtryLangDelByIdIdx rqstISOCtryLangDelByIdIdx = null;
	private CFIntXMsgRqstISOCtryLangDelByCtryIdx rqstISOCtryLangDelByCtryIdx = null;
	private CFIntXMsgRqstISOCtryLangDelByLangIdx rqstISOCtryLangDelByLangIdx = null;
	// ISOLang Request s

	private CFIntXMsgRqstISOLangCreate rqstISOLangCreate = null;
	private CFIntXMsgRqstISOLangRead rqstISOLangRead = null;
	private CFIntXMsgRqstISOLangLock rqstISOLangLock = null;
	private CFIntXMsgRqstISOLangUpdate rqstISOLangUpdate = null;
	private CFIntXMsgRqstISOLangDelete rqstISOLangDelete = null;
	private CFIntXMsgRqstISOLangReadAll rqstISOLangReadAll = null;
	private CFIntXMsgRqstISOLangRdByCode3Idx rqstISOLangRdByCode3Idx = null;
	private CFIntXMsgRqstISOLangRdByCode2Idx rqstISOLangRdByCode2Idx = null;
	private CFIntXMsgRqstISOLangDelByIdIdx rqstISOLangDelByIdIdx = null;
	private CFIntXMsgRqstISOLangDelByCode3Idx rqstISOLangDelByCode3Idx = null;
	private CFIntXMsgRqstISOLangDelByCode2Idx rqstISOLangDelByCode2Idx = null;
	// ISOTZone Request s

	private CFIntXMsgRqstISOTZoneCreate rqstISOTZoneCreate = null;
	private CFIntXMsgRqstISOTZoneRead rqstISOTZoneRead = null;
	private CFIntXMsgRqstISOTZoneLock rqstISOTZoneLock = null;
	private CFIntXMsgRqstISOTZoneUpdate rqstISOTZoneUpdate = null;
	private CFIntXMsgRqstISOTZoneDelete rqstISOTZoneDelete = null;
	private CFIntXMsgRqstISOTZoneReadAll rqstISOTZoneReadAll = null;
	private CFIntXMsgRqstISOTZoneRdByOffsetIdx rqstISOTZoneRdByOffsetIdx = null;
	private CFIntXMsgRqstISOTZoneRdByUTZNameIdx rqstISOTZoneRdByUTZNameIdx = null;
	private CFIntXMsgRqstISOTZoneRdByIso8601Idx rqstISOTZoneRdByIso8601Idx = null;
	private CFIntXMsgRqstISOTZoneDelByIdIdx rqstISOTZoneDelByIdIdx = null;
	private CFIntXMsgRqstISOTZoneDelByOffsetIdx rqstISOTZoneDelByOffsetIdx = null;
	private CFIntXMsgRqstISOTZoneDelByUTZNameIdx rqstISOTZoneDelByUTZNameIdx = null;
	private CFIntXMsgRqstISOTZoneDelByIso8601Idx rqstISOTZoneDelByIso8601Idx = null;
	// License Request s

	private CFIntXMsgRqstLicenseCreate rqstLicenseCreate = null;
	private CFIntXMsgRqstLicenseRead rqstLicenseRead = null;
	private CFIntXMsgRqstLicenseLock rqstLicenseLock = null;
	private CFIntXMsgRqstLicenseUpdate rqstLicenseUpdate = null;
	private CFIntXMsgRqstLicenseDelete rqstLicenseDelete = null;
	private CFIntXMsgRqstLicenseReadAll rqstLicenseReadAll = null;
	private CFIntXMsgRqstLicenseRdByLicnTenantIdx rqstLicenseRdByLicnTenantIdx = null;
	private CFIntXMsgRqstLicenseRdByDomainIdx rqstLicenseRdByDomainIdx = null;
	private CFIntXMsgRqstLicenseRdByUNameIdx rqstLicenseRdByUNameIdx = null;
	private CFIntXMsgRqstLicenseDelByIdIdx rqstLicenseDelByIdIdx = null;
	private CFIntXMsgRqstLicenseDelByLicnTenantIdx rqstLicenseDelByLicnTenantIdx = null;
	private CFIntXMsgRqstLicenseDelByDomainIdx rqstLicenseDelByDomainIdx = null;
	private CFIntXMsgRqstLicenseDelByUNameIdx rqstLicenseDelByUNameIdx = null;
	// MajorVersion Request s

	private CFIntXMsgRqstMajorVersionCreate rqstMajorVersionCreate = null;
	private CFIntXMsgRqstMajorVersionRead rqstMajorVersionRead = null;
	private CFIntXMsgRqstMajorVersionLock rqstMajorVersionLock = null;
	private CFIntXMsgRqstMajorVersionUpdate rqstMajorVersionUpdate = null;
	private CFIntXMsgRqstMajorVersionDelete rqstMajorVersionDelete = null;
	private CFIntXMsgRqstMajorVersionReadAll rqstMajorVersionReadAll = null;
	private CFIntXMsgRqstMajorVersionRdByTenantIdx rqstMajorVersionRdByTenantIdx = null;
	private CFIntXMsgRqstMajorVersionRdBySubProjectIdx rqstMajorVersionRdBySubProjectIdx = null;
	private CFIntXMsgRqstMajorVersionRdByNameIdx rqstMajorVersionRdByNameIdx = null;
	private CFIntXMsgRqstMajorVersionDelByIdIdx rqstMajorVersionDelByIdIdx = null;
	private CFIntXMsgRqstMajorVersionDelByTenantIdx rqstMajorVersionDelByTenantIdx = null;
	private CFIntXMsgRqstMajorVersionDelBySubProjectIdx rqstMajorVersionDelBySubProjectIdx = null;
	private CFIntXMsgRqstMajorVersionDelByNameIdx rqstMajorVersionDelByNameIdx = null;
	// MimeType Request s

	private CFIntXMsgRqstMimeTypeCreate rqstMimeTypeCreate = null;
	private CFIntXMsgRqstMimeTypeRead rqstMimeTypeRead = null;
	private CFIntXMsgRqstMimeTypeLock rqstMimeTypeLock = null;
	private CFIntXMsgRqstMimeTypeUpdate rqstMimeTypeUpdate = null;
	private CFIntXMsgRqstMimeTypeDelete rqstMimeTypeDelete = null;
	private CFIntXMsgRqstMimeTypeReadAll rqstMimeTypeReadAll = null;
	private CFIntXMsgRqstMimeTypeRdByUNameIdx rqstMimeTypeRdByUNameIdx = null;
	private CFIntXMsgRqstMimeTypeDelByIdIdx rqstMimeTypeDelByIdIdx = null;
	private CFIntXMsgRqstMimeTypeDelByUNameIdx rqstMimeTypeDelByUNameIdx = null;
	// MinorVersion Request s

	private CFIntXMsgRqstMinorVersionCreate rqstMinorVersionCreate = null;
	private CFIntXMsgRqstMinorVersionRead rqstMinorVersionRead = null;
	private CFIntXMsgRqstMinorVersionLock rqstMinorVersionLock = null;
	private CFIntXMsgRqstMinorVersionUpdate rqstMinorVersionUpdate = null;
	private CFIntXMsgRqstMinorVersionDelete rqstMinorVersionDelete = null;
	private CFIntXMsgRqstMinorVersionReadAll rqstMinorVersionReadAll = null;
	private CFIntXMsgRqstMinorVersionRdByTenantIdx rqstMinorVersionRdByTenantIdx = null;
	private CFIntXMsgRqstMinorVersionRdByMajorVerIdx rqstMinorVersionRdByMajorVerIdx = null;
	private CFIntXMsgRqstMinorVersionRdByNameIdx rqstMinorVersionRdByNameIdx = null;
	private CFIntXMsgRqstMinorVersionDelByIdIdx rqstMinorVersionDelByIdIdx = null;
	private CFIntXMsgRqstMinorVersionDelByTenantIdx rqstMinorVersionDelByTenantIdx = null;
	private CFIntXMsgRqstMinorVersionDelByMajorVerIdx rqstMinorVersionDelByMajorVerIdx = null;
	private CFIntXMsgRqstMinorVersionDelByNameIdx rqstMinorVersionDelByNameIdx = null;
	// SecApp Request s

	private CFIntXMsgRqstSecAppCreate rqstSecAppCreate = null;
	private CFIntXMsgRqstSecAppRead rqstSecAppRead = null;
	private CFIntXMsgRqstSecAppLock rqstSecAppLock = null;
	private CFIntXMsgRqstSecAppUpdate rqstSecAppUpdate = null;
	private CFIntXMsgRqstSecAppDelete rqstSecAppDelete = null;
	private CFIntXMsgRqstSecAppReadAll rqstSecAppReadAll = null;
	private CFIntXMsgRqstSecAppPageAll rqstSecAppPageAll = null;
	private CFIntXMsgRqstSecAppRdByClusterIdx rqstSecAppRdByClusterIdx = null;
	private CFIntXMsgRqstSecAppRdByUJEEMountIdx rqstSecAppRdByUJEEMountIdx = null;
	private CFIntXMsgRqstSecAppPageByClusterIdx rqstSecAppPageByClusterIdx = null;
	private CFIntXMsgRqstSecAppDelByIdIdx rqstSecAppDelByIdIdx = null;
	private CFIntXMsgRqstSecAppDelByClusterIdx rqstSecAppDelByClusterIdx = null;
	private CFIntXMsgRqstSecAppDelByUJEEMountIdx rqstSecAppDelByUJEEMountIdx = null;
	// SecDevice Request s

	private CFIntXMsgRqstSecDeviceCreate rqstSecDeviceCreate = null;
	private CFIntXMsgRqstSecDeviceRead rqstSecDeviceRead = null;
	private CFIntXMsgRqstSecDeviceLock rqstSecDeviceLock = null;
	private CFIntXMsgRqstSecDeviceUpdate rqstSecDeviceUpdate = null;
	private CFIntXMsgRqstSecDeviceDelete rqstSecDeviceDelete = null;
	private CFIntXMsgRqstSecDeviceReadAll rqstSecDeviceReadAll = null;
	private CFIntXMsgRqstSecDevicePageAll rqstSecDevicePageAll = null;
	private CFIntXMsgRqstSecDeviceRdByNameIdx rqstSecDeviceRdByNameIdx = null;
	private CFIntXMsgRqstSecDeviceRdByUserIdx rqstSecDeviceRdByUserIdx = null;
	private CFIntXMsgRqstSecDevicePageByUserIdx rqstSecDevicePageByUserIdx = null;
	private CFIntXMsgRqstSecDeviceDelByIdIdx rqstSecDeviceDelByIdIdx = null;
	private CFIntXMsgRqstSecDeviceDelByNameIdx rqstSecDeviceDelByNameIdx = null;
	private CFIntXMsgRqstSecDeviceDelByUserIdx rqstSecDeviceDelByUserIdx = null;
	// SecForm Request s

	private CFIntXMsgRqstSecFormCreate rqstSecFormCreate = null;
	private CFIntXMsgRqstSecFormRead rqstSecFormRead = null;
	private CFIntXMsgRqstSecFormLock rqstSecFormLock = null;
	private CFIntXMsgRqstSecFormUpdate rqstSecFormUpdate = null;
	private CFIntXMsgRqstSecFormDelete rqstSecFormDelete = null;
	private CFIntXMsgRqstSecFormReadAll rqstSecFormReadAll = null;
	private CFIntXMsgRqstSecFormPageAll rqstSecFormPageAll = null;
	private CFIntXMsgRqstSecFormRdByClusterIdx rqstSecFormRdByClusterIdx = null;
	private CFIntXMsgRqstSecFormRdBySecAppIdx rqstSecFormRdBySecAppIdx = null;
	private CFIntXMsgRqstSecFormRdByUJEEServletIdx rqstSecFormRdByUJEEServletIdx = null;
	private CFIntXMsgRqstSecFormPageByClusterIdx rqstSecFormPageByClusterIdx = null;
	private CFIntXMsgRqstSecFormPageBySecAppIdx rqstSecFormPageBySecAppIdx = null;
	private CFIntXMsgRqstSecFormDelByIdIdx rqstSecFormDelByIdIdx = null;
	private CFIntXMsgRqstSecFormDelByClusterIdx rqstSecFormDelByClusterIdx = null;
	private CFIntXMsgRqstSecFormDelBySecAppIdx rqstSecFormDelBySecAppIdx = null;
	private CFIntXMsgRqstSecFormDelByUJEEServletIdx rqstSecFormDelByUJEEServletIdx = null;
	// SecGroup Request s

	private CFIntXMsgRqstSecGroupCreate rqstSecGroupCreate = null;
	private CFIntXMsgRqstSecGroupRead rqstSecGroupRead = null;
	private CFIntXMsgRqstSecGroupLock rqstSecGroupLock = null;
	private CFIntXMsgRqstSecGroupUpdate rqstSecGroupUpdate = null;
	private CFIntXMsgRqstSecGroupDelete rqstSecGroupDelete = null;
	private CFIntXMsgRqstSecGroupReadAll rqstSecGroupReadAll = null;
	private CFIntXMsgRqstSecGroupRdByClusterIdx rqstSecGroupRdByClusterIdx = null;
	private CFIntXMsgRqstSecGroupRdByClusterVisIdx rqstSecGroupRdByClusterVisIdx = null;
	private CFIntXMsgRqstSecGroupRdByUNameIdx rqstSecGroupRdByUNameIdx = null;
	private CFIntXMsgRqstSecGroupDelByIdIdx rqstSecGroupDelByIdIdx = null;
	private CFIntXMsgRqstSecGroupDelByClusterIdx rqstSecGroupDelByClusterIdx = null;
	private CFIntXMsgRqstSecGroupDelByClusterVisIdx rqstSecGroupDelByClusterVisIdx = null;
	private CFIntXMsgRqstSecGroupDelByUNameIdx rqstSecGroupDelByUNameIdx = null;
	// SecGroupForm Request s

	private CFIntXMsgRqstSecGroupFormCreate rqstSecGroupFormCreate = null;
	private CFIntXMsgRqstSecGroupFormRead rqstSecGroupFormRead = null;
	private CFIntXMsgRqstSecGroupFormLock rqstSecGroupFormLock = null;
	private CFIntXMsgRqstSecGroupFormUpdate rqstSecGroupFormUpdate = null;
	private CFIntXMsgRqstSecGroupFormDelete rqstSecGroupFormDelete = null;
	private CFIntXMsgRqstSecGroupFormReadAll rqstSecGroupFormReadAll = null;
	private CFIntXMsgRqstSecGroupFormPageAll rqstSecGroupFormPageAll = null;
	private CFIntXMsgRqstSecGroupFormRdByClusterIdx rqstSecGroupFormRdByClusterIdx = null;
	private CFIntXMsgRqstSecGroupFormRdByGroupIdx rqstSecGroupFormRdByGroupIdx = null;
	private CFIntXMsgRqstSecGroupFormRdByAppIdx rqstSecGroupFormRdByAppIdx = null;
	private CFIntXMsgRqstSecGroupFormRdByFormIdx rqstSecGroupFormRdByFormIdx = null;
	private CFIntXMsgRqstSecGroupFormRdByUFormIdx rqstSecGroupFormRdByUFormIdx = null;
	private CFIntXMsgRqstSecGroupFormPageByClusterIdx rqstSecGroupFormPageByClusterIdx = null;
	private CFIntXMsgRqstSecGroupFormPageByGroupIdx rqstSecGroupFormPageByGroupIdx = null;
	private CFIntXMsgRqstSecGroupFormPageByAppIdx rqstSecGroupFormPageByAppIdx = null;
	private CFIntXMsgRqstSecGroupFormPageByFormIdx rqstSecGroupFormPageByFormIdx = null;
	private CFIntXMsgRqstSecGroupFormDelByIdIdx rqstSecGroupFormDelByIdIdx = null;
	private CFIntXMsgRqstSecGroupFormDelByClusterIdx rqstSecGroupFormDelByClusterIdx = null;
	private CFIntXMsgRqstSecGroupFormDelByGroupIdx rqstSecGroupFormDelByGroupIdx = null;
	private CFIntXMsgRqstSecGroupFormDelByAppIdx rqstSecGroupFormDelByAppIdx = null;
	private CFIntXMsgRqstSecGroupFormDelByFormIdx rqstSecGroupFormDelByFormIdx = null;
	private CFIntXMsgRqstSecGroupFormDelByUFormIdx rqstSecGroupFormDelByUFormIdx = null;
	// SecGrpInc Request s

	private CFIntXMsgRqstSecGrpIncCreate rqstSecGrpIncCreate = null;
	private CFIntXMsgRqstSecGrpIncRead rqstSecGrpIncRead = null;
	private CFIntXMsgRqstSecGrpIncLock rqstSecGrpIncLock = null;
	private CFIntXMsgRqstSecGrpIncUpdate rqstSecGrpIncUpdate = null;
	private CFIntXMsgRqstSecGrpIncDelete rqstSecGrpIncDelete = null;
	private CFIntXMsgRqstSecGrpIncReadAll rqstSecGrpIncReadAll = null;
	private CFIntXMsgRqstSecGrpIncPageAll rqstSecGrpIncPageAll = null;
	private CFIntXMsgRqstSecGrpIncRdByClusterIdx rqstSecGrpIncRdByClusterIdx = null;
	private CFIntXMsgRqstSecGrpIncRdByGroupIdx rqstSecGrpIncRdByGroupIdx = null;
	private CFIntXMsgRqstSecGrpIncRdByIncludeIdx rqstSecGrpIncRdByIncludeIdx = null;
	private CFIntXMsgRqstSecGrpIncRdByUIncludeIdx rqstSecGrpIncRdByUIncludeIdx = null;
	private CFIntXMsgRqstSecGrpIncPageByClusterIdx rqstSecGrpIncPageByClusterIdx = null;
	private CFIntXMsgRqstSecGrpIncPageByGroupIdx rqstSecGrpIncPageByGroupIdx = null;
	private CFIntXMsgRqstSecGrpIncPageByIncludeIdx rqstSecGrpIncPageByIncludeIdx = null;
	private CFIntXMsgRqstSecGrpIncDelByIdIdx rqstSecGrpIncDelByIdIdx = null;
	private CFIntXMsgRqstSecGrpIncDelByClusterIdx rqstSecGrpIncDelByClusterIdx = null;
	private CFIntXMsgRqstSecGrpIncDelByGroupIdx rqstSecGrpIncDelByGroupIdx = null;
	private CFIntXMsgRqstSecGrpIncDelByIncludeIdx rqstSecGrpIncDelByIncludeIdx = null;
	private CFIntXMsgRqstSecGrpIncDelByUIncludeIdx rqstSecGrpIncDelByUIncludeIdx = null;
	// SecGrpMemb Request s

	private CFIntXMsgRqstSecGrpMembCreate rqstSecGrpMembCreate = null;
	private CFIntXMsgRqstSecGrpMembRead rqstSecGrpMembRead = null;
	private CFIntXMsgRqstSecGrpMembLock rqstSecGrpMembLock = null;
	private CFIntXMsgRqstSecGrpMembUpdate rqstSecGrpMembUpdate = null;
	private CFIntXMsgRqstSecGrpMembDelete rqstSecGrpMembDelete = null;
	private CFIntXMsgRqstSecGrpMembReadAll rqstSecGrpMembReadAll = null;
	private CFIntXMsgRqstSecGrpMembPageAll rqstSecGrpMembPageAll = null;
	private CFIntXMsgRqstSecGrpMembRdByClusterIdx rqstSecGrpMembRdByClusterIdx = null;
	private CFIntXMsgRqstSecGrpMembRdByGroupIdx rqstSecGrpMembRdByGroupIdx = null;
	private CFIntXMsgRqstSecGrpMembRdByUserIdx rqstSecGrpMembRdByUserIdx = null;
	private CFIntXMsgRqstSecGrpMembRdByUUserIdx rqstSecGrpMembRdByUUserIdx = null;
	private CFIntXMsgRqstSecGrpMembPageByClusterIdx rqstSecGrpMembPageByClusterIdx = null;
	private CFIntXMsgRqstSecGrpMembPageByGroupIdx rqstSecGrpMembPageByGroupIdx = null;
	private CFIntXMsgRqstSecGrpMembPageByUserIdx rqstSecGrpMembPageByUserIdx = null;
	private CFIntXMsgRqstSecGrpMembDelByIdIdx rqstSecGrpMembDelByIdIdx = null;
	private CFIntXMsgRqstSecGrpMembDelByClusterIdx rqstSecGrpMembDelByClusterIdx = null;
	private CFIntXMsgRqstSecGrpMembDelByGroupIdx rqstSecGrpMembDelByGroupIdx = null;
	private CFIntXMsgRqstSecGrpMembDelByUserIdx rqstSecGrpMembDelByUserIdx = null;
	private CFIntXMsgRqstSecGrpMembDelByUUserIdx rqstSecGrpMembDelByUUserIdx = null;
	// SecSession Request s

	private CFIntXMsgRqstSecSessionCreate rqstSecSessionCreate = null;
	private CFIntXMsgRqstSecSessionRead rqstSecSessionRead = null;
	private CFIntXMsgRqstSecSessionLock rqstSecSessionLock = null;
	private CFIntXMsgRqstSecSessionUpdate rqstSecSessionUpdate = null;
	private CFIntXMsgRqstSecSessionDelete rqstSecSessionDelete = null;
	private CFIntXMsgRqstSecSessionReadAll rqstSecSessionReadAll = null;
	private CFIntXMsgRqstSecSessionPageAll rqstSecSessionPageAll = null;
	private CFIntXMsgRqstSecSessionRdBySecUserIdx rqstSecSessionRdBySecUserIdx = null;
	private CFIntXMsgRqstSecSessionRdBySecDevIdx rqstSecSessionRdBySecDevIdx = null;
	private CFIntXMsgRqstSecSessionRdByStartIdx rqstSecSessionRdByStartIdx = null;
	private CFIntXMsgRqstSecSessionRdByFinishIdx rqstSecSessionRdByFinishIdx = null;
	private CFIntXMsgRqstSecSessionRdBySecProxyIdx rqstSecSessionRdBySecProxyIdx = null;
	private CFIntXMsgRqstSecSessionPageBySecUserIdx rqstSecSessionPageBySecUserIdx = null;
	private CFIntXMsgRqstSecSessionPageBySecDevIdx rqstSecSessionPageBySecDevIdx = null;
	private CFIntXMsgRqstSecSessionPageByFinishIdx rqstSecSessionPageByFinishIdx = null;
	private CFIntXMsgRqstSecSessionPageBySecProxyIdx rqstSecSessionPageBySecProxyIdx = null;
	private CFIntXMsgRqstSecSessionDelByIdIdx rqstSecSessionDelByIdIdx = null;
	private CFIntXMsgRqstSecSessionDelBySecUserIdx rqstSecSessionDelBySecUserIdx = null;
	private CFIntXMsgRqstSecSessionDelBySecDevIdx rqstSecSessionDelBySecDevIdx = null;
	private CFIntXMsgRqstSecSessionDelByStartIdx rqstSecSessionDelByStartIdx = null;
	private CFIntXMsgRqstSecSessionDelByFinishIdx rqstSecSessionDelByFinishIdx = null;
	private CFIntXMsgRqstSecSessionDelBySecProxyIdx rqstSecSessionDelBySecProxyIdx = null;
	// SecUser Request s

	private CFIntXMsgRqstSecUserCreate rqstSecUserCreate = null;
	private CFIntXMsgRqstSecUserRead rqstSecUserRead = null;
	private CFIntXMsgRqstSecUserLock rqstSecUserLock = null;
	private CFIntXMsgRqstSecUserUpdate rqstSecUserUpdate = null;
	private CFIntXMsgRqstSecUserDelete rqstSecUserDelete = null;
	private CFIntXMsgRqstSecUserReadAll rqstSecUserReadAll = null;
	private CFIntXMsgRqstSecUserPageAll rqstSecUserPageAll = null;
	private CFIntXMsgRqstSecUserRdByULoginIdx rqstSecUserRdByULoginIdx = null;
	private CFIntXMsgRqstSecUserRdByEMConfIdx rqstSecUserRdByEMConfIdx = null;
	private CFIntXMsgRqstSecUserRdByPwdResetIdx rqstSecUserRdByPwdResetIdx = null;
	private CFIntXMsgRqstSecUserRdByDefDevIdx rqstSecUserRdByDefDevIdx = null;
	private CFIntXMsgRqstSecUserPageByEMConfIdx rqstSecUserPageByEMConfIdx = null;
	private CFIntXMsgRqstSecUserPageByPwdResetIdx rqstSecUserPageByPwdResetIdx = null;
	private CFIntXMsgRqstSecUserPageByDefDevIdx rqstSecUserPageByDefDevIdx = null;
	private CFIntXMsgRqstSecUserDelByIdIdx rqstSecUserDelByIdIdx = null;
	private CFIntXMsgRqstSecUserDelByULoginIdx rqstSecUserDelByULoginIdx = null;
	private CFIntXMsgRqstSecUserDelByEMConfIdx rqstSecUserDelByEMConfIdx = null;
	private CFIntXMsgRqstSecUserDelByPwdResetIdx rqstSecUserDelByPwdResetIdx = null;
	private CFIntXMsgRqstSecUserDelByDefDevIdx rqstSecUserDelByDefDevIdx = null;
	// Service Request s

	private CFIntXMsgRqstServiceCreate rqstServiceCreate = null;
	private CFIntXMsgRqstServiceRead rqstServiceRead = null;
	private CFIntXMsgRqstServiceLock rqstServiceLock = null;
	private CFIntXMsgRqstServiceUpdate rqstServiceUpdate = null;
	private CFIntXMsgRqstServiceDelete rqstServiceDelete = null;
	private CFIntXMsgRqstServiceReadAll rqstServiceReadAll = null;
	private CFIntXMsgRqstServicePageAll rqstServicePageAll = null;
	private CFIntXMsgRqstServiceRdByClusterIdx rqstServiceRdByClusterIdx = null;
	private CFIntXMsgRqstServiceRdByHostIdx rqstServiceRdByHostIdx = null;
	private CFIntXMsgRqstServiceRdByTypeIdx rqstServiceRdByTypeIdx = null;
	private CFIntXMsgRqstServiceRdByUTypeIdx rqstServiceRdByUTypeIdx = null;
	private CFIntXMsgRqstServiceRdByUHostPortIdx rqstServiceRdByUHostPortIdx = null;
	private CFIntXMsgRqstServicePageByClusterIdx rqstServicePageByClusterIdx = null;
	private CFIntXMsgRqstServicePageByHostIdx rqstServicePageByHostIdx = null;
	private CFIntXMsgRqstServicePageByTypeIdx rqstServicePageByTypeIdx = null;
	private CFIntXMsgRqstServiceDelByIdIdx rqstServiceDelByIdIdx = null;
	private CFIntXMsgRqstServiceDelByClusterIdx rqstServiceDelByClusterIdx = null;
	private CFIntXMsgRqstServiceDelByHostIdx rqstServiceDelByHostIdx = null;
	private CFIntXMsgRqstServiceDelByTypeIdx rqstServiceDelByTypeIdx = null;
	private CFIntXMsgRqstServiceDelByUTypeIdx rqstServiceDelByUTypeIdx = null;
	private CFIntXMsgRqstServiceDelByUHostPortIdx rqstServiceDelByUHostPortIdx = null;
	// ServiceType Request s

	private CFIntXMsgRqstServiceTypeCreate rqstServiceTypeCreate = null;
	private CFIntXMsgRqstServiceTypeRead rqstServiceTypeRead = null;
	private CFIntXMsgRqstServiceTypeLock rqstServiceTypeLock = null;
	private CFIntXMsgRqstServiceTypeUpdate rqstServiceTypeUpdate = null;
	private CFIntXMsgRqstServiceTypeDelete rqstServiceTypeDelete = null;
	private CFIntXMsgRqstServiceTypeReadAll rqstServiceTypeReadAll = null;
	private CFIntXMsgRqstServiceTypeRdByUDescrIdx rqstServiceTypeRdByUDescrIdx = null;
	private CFIntXMsgRqstServiceTypeDelByIdIdx rqstServiceTypeDelByIdIdx = null;
	private CFIntXMsgRqstServiceTypeDelByUDescrIdx rqstServiceTypeDelByUDescrIdx = null;
	// SubProject Request s

	private CFIntXMsgRqstSubProjectCreate rqstSubProjectCreate = null;
	private CFIntXMsgRqstSubProjectRead rqstSubProjectRead = null;
	private CFIntXMsgRqstSubProjectLock rqstSubProjectLock = null;
	private CFIntXMsgRqstSubProjectUpdate rqstSubProjectUpdate = null;
	private CFIntXMsgRqstSubProjectDelete rqstSubProjectDelete = null;
	private CFIntXMsgRqstSubProjectReadAll rqstSubProjectReadAll = null;
	private CFIntXMsgRqstSubProjectRdByTenantIdx rqstSubProjectRdByTenantIdx = null;
	private CFIntXMsgRqstSubProjectRdByTopProjectIdx rqstSubProjectRdByTopProjectIdx = null;
	private CFIntXMsgRqstSubProjectRdByNameIdx rqstSubProjectRdByNameIdx = null;
	private CFIntXMsgRqstSubProjectDelByIdIdx rqstSubProjectDelByIdIdx = null;
	private CFIntXMsgRqstSubProjectDelByTenantIdx rqstSubProjectDelByTenantIdx = null;
	private CFIntXMsgRqstSubProjectDelByTopProjectIdx rqstSubProjectDelByTopProjectIdx = null;
	private CFIntXMsgRqstSubProjectDelByNameIdx rqstSubProjectDelByNameIdx = null;
	// SysCluster Request s

	private CFIntXMsgRqstSysClusterCreate rqstSysClusterCreate = null;
	private CFIntXMsgRqstSysClusterRead rqstSysClusterRead = null;
	private CFIntXMsgRqstSysClusterLock rqstSysClusterLock = null;
	private CFIntXMsgRqstSysClusterUpdate rqstSysClusterUpdate = null;
	private CFIntXMsgRqstSysClusterDelete rqstSysClusterDelete = null;
	private CFIntXMsgRqstSysClusterReadAll rqstSysClusterReadAll = null;
	private CFIntXMsgRqstSysClusterRdByClusterIdx rqstSysClusterRdByClusterIdx = null;
	private CFIntXMsgRqstSysClusterDelByIdIdx rqstSysClusterDelByIdIdx = null;
	private CFIntXMsgRqstSysClusterDelByClusterIdx rqstSysClusterDelByClusterIdx = null;
	// TSecGroup Request s

	private CFIntXMsgRqstTSecGroupCreate rqstTSecGroupCreate = null;
	private CFIntXMsgRqstTSecGroupRead rqstTSecGroupRead = null;
	private CFIntXMsgRqstTSecGroupLock rqstTSecGroupLock = null;
	private CFIntXMsgRqstTSecGroupUpdate rqstTSecGroupUpdate = null;
	private CFIntXMsgRqstTSecGroupDelete rqstTSecGroupDelete = null;
	private CFIntXMsgRqstTSecGroupReadAll rqstTSecGroupReadAll = null;
	private CFIntXMsgRqstTSecGroupRdByTenantIdx rqstTSecGroupRdByTenantIdx = null;
	private CFIntXMsgRqstTSecGroupRdByTenantVisIdx rqstTSecGroupRdByTenantVisIdx = null;
	private CFIntXMsgRqstTSecGroupRdByUNameIdx rqstTSecGroupRdByUNameIdx = null;
	private CFIntXMsgRqstTSecGroupDelByIdIdx rqstTSecGroupDelByIdIdx = null;
	private CFIntXMsgRqstTSecGroupDelByTenantIdx rqstTSecGroupDelByTenantIdx = null;
	private CFIntXMsgRqstTSecGroupDelByTenantVisIdx rqstTSecGroupDelByTenantVisIdx = null;
	private CFIntXMsgRqstTSecGroupDelByUNameIdx rqstTSecGroupDelByUNameIdx = null;
	// TSecGrpInc Request s

	private CFIntXMsgRqstTSecGrpIncCreate rqstTSecGrpIncCreate = null;
	private CFIntXMsgRqstTSecGrpIncRead rqstTSecGrpIncRead = null;
	private CFIntXMsgRqstTSecGrpIncLock rqstTSecGrpIncLock = null;
	private CFIntXMsgRqstTSecGrpIncUpdate rqstTSecGrpIncUpdate = null;
	private CFIntXMsgRqstTSecGrpIncDelete rqstTSecGrpIncDelete = null;
	private CFIntXMsgRqstTSecGrpIncReadAll rqstTSecGrpIncReadAll = null;
	private CFIntXMsgRqstTSecGrpIncPageAll rqstTSecGrpIncPageAll = null;
	private CFIntXMsgRqstTSecGrpIncRdByTenantIdx rqstTSecGrpIncRdByTenantIdx = null;
	private CFIntXMsgRqstTSecGrpIncRdByGroupIdx rqstTSecGrpIncRdByGroupIdx = null;
	private CFIntXMsgRqstTSecGrpIncRdByIncludeIdx rqstTSecGrpIncRdByIncludeIdx = null;
	private CFIntXMsgRqstTSecGrpIncRdByUIncludeIdx rqstTSecGrpIncRdByUIncludeIdx = null;
	private CFIntXMsgRqstTSecGrpIncPageByTenantIdx rqstTSecGrpIncPageByTenantIdx = null;
	private CFIntXMsgRqstTSecGrpIncPageByGroupIdx rqstTSecGrpIncPageByGroupIdx = null;
	private CFIntXMsgRqstTSecGrpIncPageByIncludeIdx rqstTSecGrpIncPageByIncludeIdx = null;
	private CFIntXMsgRqstTSecGrpIncDelByIdIdx rqstTSecGrpIncDelByIdIdx = null;
	private CFIntXMsgRqstTSecGrpIncDelByTenantIdx rqstTSecGrpIncDelByTenantIdx = null;
	private CFIntXMsgRqstTSecGrpIncDelByGroupIdx rqstTSecGrpIncDelByGroupIdx = null;
	private CFIntXMsgRqstTSecGrpIncDelByIncludeIdx rqstTSecGrpIncDelByIncludeIdx = null;
	private CFIntXMsgRqstTSecGrpIncDelByUIncludeIdx rqstTSecGrpIncDelByUIncludeIdx = null;
	// TSecGrpMemb Request s

	private CFIntXMsgRqstTSecGrpMembCreate rqstTSecGrpMembCreate = null;
	private CFIntXMsgRqstTSecGrpMembRead rqstTSecGrpMembRead = null;
	private CFIntXMsgRqstTSecGrpMembLock rqstTSecGrpMembLock = null;
	private CFIntXMsgRqstTSecGrpMembUpdate rqstTSecGrpMembUpdate = null;
	private CFIntXMsgRqstTSecGrpMembDelete rqstTSecGrpMembDelete = null;
	private CFIntXMsgRqstTSecGrpMembReadAll rqstTSecGrpMembReadAll = null;
	private CFIntXMsgRqstTSecGrpMembPageAll rqstTSecGrpMembPageAll = null;
	private CFIntXMsgRqstTSecGrpMembRdByTenantIdx rqstTSecGrpMembRdByTenantIdx = null;
	private CFIntXMsgRqstTSecGrpMembRdByGroupIdx rqstTSecGrpMembRdByGroupIdx = null;
	private CFIntXMsgRqstTSecGrpMembRdByUserIdx rqstTSecGrpMembRdByUserIdx = null;
	private CFIntXMsgRqstTSecGrpMembRdByUUserIdx rqstTSecGrpMembRdByUUserIdx = null;
	private CFIntXMsgRqstTSecGrpMembPageByTenantIdx rqstTSecGrpMembPageByTenantIdx = null;
	private CFIntXMsgRqstTSecGrpMembPageByGroupIdx rqstTSecGrpMembPageByGroupIdx = null;
	private CFIntXMsgRqstTSecGrpMembPageByUserIdx rqstTSecGrpMembPageByUserIdx = null;
	private CFIntXMsgRqstTSecGrpMembDelByIdIdx rqstTSecGrpMembDelByIdIdx = null;
	private CFIntXMsgRqstTSecGrpMembDelByTenantIdx rqstTSecGrpMembDelByTenantIdx = null;
	private CFIntXMsgRqstTSecGrpMembDelByGroupIdx rqstTSecGrpMembDelByGroupIdx = null;
	private CFIntXMsgRqstTSecGrpMembDelByUserIdx rqstTSecGrpMembDelByUserIdx = null;
	private CFIntXMsgRqstTSecGrpMembDelByUUserIdx rqstTSecGrpMembDelByUUserIdx = null;
	// Tenant Request s

	private CFIntXMsgRqstTenantCreate rqstTenantCreate = null;
	private CFIntXMsgRqstTenantRead rqstTenantRead = null;
	private CFIntXMsgRqstTenantLock rqstTenantLock = null;
	private CFIntXMsgRqstTenantUpdate rqstTenantUpdate = null;
	private CFIntXMsgRqstTenantDelete rqstTenantDelete = null;
	private CFIntXMsgRqstTenantReadAll rqstTenantReadAll = null;
	private CFIntXMsgRqstTenantPageAll rqstTenantPageAll = null;
	private CFIntXMsgRqstTenantRdByClusterIdx rqstTenantRdByClusterIdx = null;
	private CFIntXMsgRqstTenantRdByUNameIdx rqstTenantRdByUNameIdx = null;
	private CFIntXMsgRqstTenantPageByClusterIdx rqstTenantPageByClusterIdx = null;
	private CFIntXMsgRqstTenantDelByIdIdx rqstTenantDelByIdIdx = null;
	private CFIntXMsgRqstTenantDelByClusterIdx rqstTenantDelByClusterIdx = null;
	private CFIntXMsgRqstTenantDelByUNameIdx rqstTenantDelByUNameIdx = null;
	// Tld Request s

	private CFIntXMsgRqstTldCreate rqstTldCreate = null;
	private CFIntXMsgRqstTldRead rqstTldRead = null;
	private CFIntXMsgRqstTldLock rqstTldLock = null;
	private CFIntXMsgRqstTldUpdate rqstTldUpdate = null;
	private CFIntXMsgRqstTldDelete rqstTldDelete = null;
	private CFIntXMsgRqstTldReadAll rqstTldReadAll = null;
	private CFIntXMsgRqstTldRdByTenantIdx rqstTldRdByTenantIdx = null;
	private CFIntXMsgRqstTldRdByNameIdx rqstTldRdByNameIdx = null;
	private CFIntXMsgRqstTldDelByIdIdx rqstTldDelByIdIdx = null;
	private CFIntXMsgRqstTldDelByTenantIdx rqstTldDelByTenantIdx = null;
	private CFIntXMsgRqstTldDelByNameIdx rqstTldDelByNameIdx = null;
	// TopDomain Request s

	private CFIntXMsgRqstTopDomainCreate rqstTopDomainCreate = null;
	private CFIntXMsgRqstTopDomainRead rqstTopDomainRead = null;
	private CFIntXMsgRqstTopDomainLock rqstTopDomainLock = null;
	private CFIntXMsgRqstTopDomainUpdate rqstTopDomainUpdate = null;
	private CFIntXMsgRqstTopDomainDelete rqstTopDomainDelete = null;
	private CFIntXMsgRqstTopDomainReadAll rqstTopDomainReadAll = null;
	private CFIntXMsgRqstTopDomainRdByTenantIdx rqstTopDomainRdByTenantIdx = null;
	private CFIntXMsgRqstTopDomainRdByTldIdx rqstTopDomainRdByTldIdx = null;
	private CFIntXMsgRqstTopDomainRdByNameIdx rqstTopDomainRdByNameIdx = null;
	private CFIntXMsgRqstTopDomainDelByIdIdx rqstTopDomainDelByIdIdx = null;
	private CFIntXMsgRqstTopDomainDelByTenantIdx rqstTopDomainDelByTenantIdx = null;
	private CFIntXMsgRqstTopDomainDelByTldIdx rqstTopDomainDelByTldIdx = null;
	private CFIntXMsgRqstTopDomainDelByNameIdx rqstTopDomainDelByNameIdx = null;
	// TopProject Request s

	private CFIntXMsgRqstTopProjectCreate rqstTopProjectCreate = null;
	private CFIntXMsgRqstTopProjectRead rqstTopProjectRead = null;
	private CFIntXMsgRqstTopProjectLock rqstTopProjectLock = null;
	private CFIntXMsgRqstTopProjectUpdate rqstTopProjectUpdate = null;
	private CFIntXMsgRqstTopProjectDelete rqstTopProjectDelete = null;
	private CFIntXMsgRqstTopProjectReadAll rqstTopProjectReadAll = null;
	private CFIntXMsgRqstTopProjectRdByTenantIdx rqstTopProjectRdByTenantIdx = null;
	private CFIntXMsgRqstTopProjectRdByTopDomainIdx rqstTopProjectRdByTopDomainIdx = null;
	private CFIntXMsgRqstTopProjectRdByNameIdx rqstTopProjectRdByNameIdx = null;
	private CFIntXMsgRqstTopProjectDelByIdIdx rqstTopProjectDelByIdIdx = null;
	private CFIntXMsgRqstTopProjectDelByTenantIdx rqstTopProjectDelByTenantIdx = null;
	private CFIntXMsgRqstTopProjectDelByTopDomainIdx rqstTopProjectDelByTopDomainIdx = null;
	private CFIntXMsgRqstTopProjectDelByNameIdx rqstTopProjectDelByNameIdx = null;
	// URLProtocol Request s

	private CFIntXMsgRqstURLProtocolCreate rqstURLProtocolCreate = null;
	private CFIntXMsgRqstURLProtocolRead rqstURLProtocolRead = null;
	private CFIntXMsgRqstURLProtocolLock rqstURLProtocolLock = null;
	private CFIntXMsgRqstURLProtocolUpdate rqstURLProtocolUpdate = null;
	private CFIntXMsgRqstURLProtocolDelete rqstURLProtocolDelete = null;
	private CFIntXMsgRqstURLProtocolReadAll rqstURLProtocolReadAll = null;
	private CFIntXMsgRqstURLProtocolRdByUNameIdx rqstURLProtocolRdByUNameIdx = null;
	private CFIntXMsgRqstURLProtocolRdByIsSecureIdx rqstURLProtocolRdByIsSecureIdx = null;
	private CFIntXMsgRqstURLProtocolDelByIdIdx rqstURLProtocolDelByIdIdx = null;
	private CFIntXMsgRqstURLProtocolDelByUNameIdx rqstURLProtocolDelByUNameIdx = null;
	private CFIntXMsgRqstURLProtocolDelByIsSecureIdx rqstURLProtocolDelByIsSecureIdx = null;
	private CFIntSaxRqstRoot saxRoot = null;

	private CFIntSaxRqstDoc saxDoc = null;

	private CFIntXMsgRqstFileImport rqstFileImport = null;
	private CFIntXMsgRqstLogIn rqstLogIn = null;
	private CFIntXMsgRqstLogOut rqstLogOut = null;
	// Schema object accessors

	// SchemaObj accessors

	public ICFIntSchemaObj getSchemaObj() {
		return( schemaObj );
	}

	public void setSchemaObj( ICFIntSchemaObj value ) {
		schemaObj = value;
	}

	// Element  Resolver Factories

	// Cluster Request  Factories

	protected CFIntXMsgRqstClusterCreate getRqstClusterCreate() {
		if( rqstClusterCreate == null ) {
			rqstClusterCreate = new CFIntXMsgRqstClusterCreate( this );
		}
		return( rqstClusterCreate );
	}

	protected CFIntXMsgRqstClusterRead getRqstClusterRead() {
		if( rqstClusterRead == null ) {
			rqstClusterRead = new CFIntXMsgRqstClusterRead( this );
		}
		return( rqstClusterRead );
	}

	protected CFIntXMsgRqstClusterLock getRqstClusterLock() {
		if( rqstClusterLock == null ) {
			rqstClusterLock = new CFIntXMsgRqstClusterLock( this );
		}
		return( rqstClusterLock );
	}

	protected CFIntXMsgRqstClusterUpdate getRqstClusterUpdate() {
		if( rqstClusterUpdate == null ) {
			rqstClusterUpdate = new CFIntXMsgRqstClusterUpdate( this );
		}
		return( rqstClusterUpdate );
	}

	protected CFIntXMsgRqstClusterDelete getRqstClusterDelete() {
		if( rqstClusterDelete == null ) {
			rqstClusterDelete = new CFIntXMsgRqstClusterDelete( this );
		}
		return( rqstClusterDelete );
	}

	protected CFIntXMsgRqstClusterReadAll getRqstClusterReadAll() {
		if( rqstClusterReadAll == null ) {
			rqstClusterReadAll = new CFIntXMsgRqstClusterReadAll( this );
		}
		return( rqstClusterReadAll );
	}

	protected CFIntXMsgRqstClusterPageAll getRqstClusterPageAll() {
		if( rqstClusterPageAll == null ) {
			rqstClusterPageAll = new CFIntXMsgRqstClusterPageAll( this );
		}
		return( rqstClusterPageAll );
	}

	protected CFIntXMsgRqstClusterRdByUDomNameIdx getRqstClusterRdByUDomNameIdx() {
		if( rqstClusterRdByUDomNameIdx == null ) {
			rqstClusterRdByUDomNameIdx = new CFIntXMsgRqstClusterRdByUDomNameIdx( this );
		}
		return( rqstClusterRdByUDomNameIdx );
	}

	protected CFIntXMsgRqstClusterRdByUDescrIdx getRqstClusterRdByUDescrIdx() {
		if( rqstClusterRdByUDescrIdx == null ) {
			rqstClusterRdByUDescrIdx = new CFIntXMsgRqstClusterRdByUDescrIdx( this );
		}
		return( rqstClusterRdByUDescrIdx );
	}

	protected CFIntXMsgRqstClusterDelByUDomNameIdx getRqstClusterDelByUDomNameIdx() {
		if( rqstClusterDelByUDomNameIdx == null ) {
			rqstClusterDelByUDomNameIdx = new CFIntXMsgRqstClusterDelByUDomNameIdx( this );
		}
		return( rqstClusterDelByUDomNameIdx );
	}

	protected CFIntXMsgRqstClusterDelByUDescrIdx getRqstClusterDelByUDescrIdx() {
		if( rqstClusterDelByUDescrIdx == null ) {
			rqstClusterDelByUDescrIdx = new CFIntXMsgRqstClusterDelByUDescrIdx( this );
		}
		return( rqstClusterDelByUDescrIdx );
	}

	// HostNode Request  Factories

	protected CFIntXMsgRqstHostNodeCreate getRqstHostNodeCreate() {
		if( rqstHostNodeCreate == null ) {
			rqstHostNodeCreate = new CFIntXMsgRqstHostNodeCreate( this );
		}
		return( rqstHostNodeCreate );
	}

	protected CFIntXMsgRqstHostNodeRead getRqstHostNodeRead() {
		if( rqstHostNodeRead == null ) {
			rqstHostNodeRead = new CFIntXMsgRqstHostNodeRead( this );
		}
		return( rqstHostNodeRead );
	}

	protected CFIntXMsgRqstHostNodeLock getRqstHostNodeLock() {
		if( rqstHostNodeLock == null ) {
			rqstHostNodeLock = new CFIntXMsgRqstHostNodeLock( this );
		}
		return( rqstHostNodeLock );
	}

	protected CFIntXMsgRqstHostNodeUpdate getRqstHostNodeUpdate() {
		if( rqstHostNodeUpdate == null ) {
			rqstHostNodeUpdate = new CFIntXMsgRqstHostNodeUpdate( this );
		}
		return( rqstHostNodeUpdate );
	}

	protected CFIntXMsgRqstHostNodeDelete getRqstHostNodeDelete() {
		if( rqstHostNodeDelete == null ) {
			rqstHostNodeDelete = new CFIntXMsgRqstHostNodeDelete( this );
		}
		return( rqstHostNodeDelete );
	}

	protected CFIntXMsgRqstHostNodeReadAll getRqstHostNodeReadAll() {
		if( rqstHostNodeReadAll == null ) {
			rqstHostNodeReadAll = new CFIntXMsgRqstHostNodeReadAll( this );
		}
		return( rqstHostNodeReadAll );
	}

	protected CFIntXMsgRqstHostNodePageAll getRqstHostNodePageAll() {
		if( rqstHostNodePageAll == null ) {
			rqstHostNodePageAll = new CFIntXMsgRqstHostNodePageAll( this );
		}
		return( rqstHostNodePageAll );
	}

	protected CFIntXMsgRqstHostNodeRdByClusterIdx getRqstHostNodeRdByClusterIdx() {
		if( rqstHostNodeRdByClusterIdx == null ) {
			rqstHostNodeRdByClusterIdx = new CFIntXMsgRqstHostNodeRdByClusterIdx( this );
		}
		return( rqstHostNodeRdByClusterIdx );
	}

	protected CFIntXMsgRqstHostNodeRdByUDescrIdx getRqstHostNodeRdByUDescrIdx() {
		if( rqstHostNodeRdByUDescrIdx == null ) {
			rqstHostNodeRdByUDescrIdx = new CFIntXMsgRqstHostNodeRdByUDescrIdx( this );
		}
		return( rqstHostNodeRdByUDescrIdx );
	}

	protected CFIntXMsgRqstHostNodeRdByHostNameIdx getRqstHostNodeRdByHostNameIdx() {
		if( rqstHostNodeRdByHostNameIdx == null ) {
			rqstHostNodeRdByHostNameIdx = new CFIntXMsgRqstHostNodeRdByHostNameIdx( this );
		}
		return( rqstHostNodeRdByHostNameIdx );
	}

	protected CFIntXMsgRqstHostNodePageByClusterIdx getRqstHostNodePageByClusterIdx() {
		if( rqstHostNodePageByClusterIdx == null ) {
			rqstHostNodePageByClusterIdx = new CFIntXMsgRqstHostNodePageByClusterIdx( this );
		}
		return( rqstHostNodePageByClusterIdx );
	}

	protected CFIntXMsgRqstHostNodeDelByClusterIdx getRqstHostNodeDelByClusterIdx() {
		if( rqstHostNodeDelByClusterIdx == null ) {
			rqstHostNodeDelByClusterIdx = new CFIntXMsgRqstHostNodeDelByClusterIdx( this );
		}
		return( rqstHostNodeDelByClusterIdx );
	}

	protected CFIntXMsgRqstHostNodeDelByUDescrIdx getRqstHostNodeDelByUDescrIdx() {
		if( rqstHostNodeDelByUDescrIdx == null ) {
			rqstHostNodeDelByUDescrIdx = new CFIntXMsgRqstHostNodeDelByUDescrIdx( this );
		}
		return( rqstHostNodeDelByUDescrIdx );
	}

	protected CFIntXMsgRqstHostNodeDelByHostNameIdx getRqstHostNodeDelByHostNameIdx() {
		if( rqstHostNodeDelByHostNameIdx == null ) {
			rqstHostNodeDelByHostNameIdx = new CFIntXMsgRqstHostNodeDelByHostNameIdx( this );
		}
		return( rqstHostNodeDelByHostNameIdx );
	}

	// ISOCcy Request  Factories

	protected CFIntXMsgRqstISOCcyCreate getRqstISOCcyCreate() {
		if( rqstISOCcyCreate == null ) {
			rqstISOCcyCreate = new CFIntXMsgRqstISOCcyCreate( this );
		}
		return( rqstISOCcyCreate );
	}

	protected CFIntXMsgRqstISOCcyRead getRqstISOCcyRead() {
		if( rqstISOCcyRead == null ) {
			rqstISOCcyRead = new CFIntXMsgRqstISOCcyRead( this );
		}
		return( rqstISOCcyRead );
	}

	protected CFIntXMsgRqstISOCcyLock getRqstISOCcyLock() {
		if( rqstISOCcyLock == null ) {
			rqstISOCcyLock = new CFIntXMsgRqstISOCcyLock( this );
		}
		return( rqstISOCcyLock );
	}

	protected CFIntXMsgRqstISOCcyUpdate getRqstISOCcyUpdate() {
		if( rqstISOCcyUpdate == null ) {
			rqstISOCcyUpdate = new CFIntXMsgRqstISOCcyUpdate( this );
		}
		return( rqstISOCcyUpdate );
	}

	protected CFIntXMsgRqstISOCcyDelete getRqstISOCcyDelete() {
		if( rqstISOCcyDelete == null ) {
			rqstISOCcyDelete = new CFIntXMsgRqstISOCcyDelete( this );
		}
		return( rqstISOCcyDelete );
	}

	protected CFIntXMsgRqstISOCcyReadAll getRqstISOCcyReadAll() {
		if( rqstISOCcyReadAll == null ) {
			rqstISOCcyReadAll = new CFIntXMsgRqstISOCcyReadAll( this );
		}
		return( rqstISOCcyReadAll );
	}

	protected CFIntXMsgRqstISOCcyRdByCcyCdIdx getRqstISOCcyRdByCcyCdIdx() {
		if( rqstISOCcyRdByCcyCdIdx == null ) {
			rqstISOCcyRdByCcyCdIdx = new CFIntXMsgRqstISOCcyRdByCcyCdIdx( this );
		}
		return( rqstISOCcyRdByCcyCdIdx );
	}

	protected CFIntXMsgRqstISOCcyRdByCcyNmIdx getRqstISOCcyRdByCcyNmIdx() {
		if( rqstISOCcyRdByCcyNmIdx == null ) {
			rqstISOCcyRdByCcyNmIdx = new CFIntXMsgRqstISOCcyRdByCcyNmIdx( this );
		}
		return( rqstISOCcyRdByCcyNmIdx );
	}

	protected CFIntXMsgRqstISOCcyDelByCcyCdIdx getRqstISOCcyDelByCcyCdIdx() {
		if( rqstISOCcyDelByCcyCdIdx == null ) {
			rqstISOCcyDelByCcyCdIdx = new CFIntXMsgRqstISOCcyDelByCcyCdIdx( this );
		}
		return( rqstISOCcyDelByCcyCdIdx );
	}

	protected CFIntXMsgRqstISOCcyDelByCcyNmIdx getRqstISOCcyDelByCcyNmIdx() {
		if( rqstISOCcyDelByCcyNmIdx == null ) {
			rqstISOCcyDelByCcyNmIdx = new CFIntXMsgRqstISOCcyDelByCcyNmIdx( this );
		}
		return( rqstISOCcyDelByCcyNmIdx );
	}

	// ISOCtry Request  Factories

	protected CFIntXMsgRqstISOCtryCreate getRqstISOCtryCreate() {
		if( rqstISOCtryCreate == null ) {
			rqstISOCtryCreate = new CFIntXMsgRqstISOCtryCreate( this );
		}
		return( rqstISOCtryCreate );
	}

	protected CFIntXMsgRqstISOCtryRead getRqstISOCtryRead() {
		if( rqstISOCtryRead == null ) {
			rqstISOCtryRead = new CFIntXMsgRqstISOCtryRead( this );
		}
		return( rqstISOCtryRead );
	}

	protected CFIntXMsgRqstISOCtryLock getRqstISOCtryLock() {
		if( rqstISOCtryLock == null ) {
			rqstISOCtryLock = new CFIntXMsgRqstISOCtryLock( this );
		}
		return( rqstISOCtryLock );
	}

	protected CFIntXMsgRqstISOCtryUpdate getRqstISOCtryUpdate() {
		if( rqstISOCtryUpdate == null ) {
			rqstISOCtryUpdate = new CFIntXMsgRqstISOCtryUpdate( this );
		}
		return( rqstISOCtryUpdate );
	}

	protected CFIntXMsgRqstISOCtryDelete getRqstISOCtryDelete() {
		if( rqstISOCtryDelete == null ) {
			rqstISOCtryDelete = new CFIntXMsgRqstISOCtryDelete( this );
		}
		return( rqstISOCtryDelete );
	}

	protected CFIntXMsgRqstISOCtryReadAll getRqstISOCtryReadAll() {
		if( rqstISOCtryReadAll == null ) {
			rqstISOCtryReadAll = new CFIntXMsgRqstISOCtryReadAll( this );
		}
		return( rqstISOCtryReadAll );
	}

	protected CFIntXMsgRqstISOCtryRdByISOCodeIdx getRqstISOCtryRdByISOCodeIdx() {
		if( rqstISOCtryRdByISOCodeIdx == null ) {
			rqstISOCtryRdByISOCodeIdx = new CFIntXMsgRqstISOCtryRdByISOCodeIdx( this );
		}
		return( rqstISOCtryRdByISOCodeIdx );
	}

	protected CFIntXMsgRqstISOCtryRdByNameIdx getRqstISOCtryRdByNameIdx() {
		if( rqstISOCtryRdByNameIdx == null ) {
			rqstISOCtryRdByNameIdx = new CFIntXMsgRqstISOCtryRdByNameIdx( this );
		}
		return( rqstISOCtryRdByNameIdx );
	}

	protected CFIntXMsgRqstISOCtryDelByISOCodeIdx getRqstISOCtryDelByISOCodeIdx() {
		if( rqstISOCtryDelByISOCodeIdx == null ) {
			rqstISOCtryDelByISOCodeIdx = new CFIntXMsgRqstISOCtryDelByISOCodeIdx( this );
		}
		return( rqstISOCtryDelByISOCodeIdx );
	}

	protected CFIntXMsgRqstISOCtryDelByNameIdx getRqstISOCtryDelByNameIdx() {
		if( rqstISOCtryDelByNameIdx == null ) {
			rqstISOCtryDelByNameIdx = new CFIntXMsgRqstISOCtryDelByNameIdx( this );
		}
		return( rqstISOCtryDelByNameIdx );
	}

	// ISOCtryCcy Request  Factories

	protected CFIntXMsgRqstISOCtryCcyCreate getRqstISOCtryCcyCreate() {
		if( rqstISOCtryCcyCreate == null ) {
			rqstISOCtryCcyCreate = new CFIntXMsgRqstISOCtryCcyCreate( this );
		}
		return( rqstISOCtryCcyCreate );
	}

	protected CFIntXMsgRqstISOCtryCcyRead getRqstISOCtryCcyRead() {
		if( rqstISOCtryCcyRead == null ) {
			rqstISOCtryCcyRead = new CFIntXMsgRqstISOCtryCcyRead( this );
		}
		return( rqstISOCtryCcyRead );
	}

	protected CFIntXMsgRqstISOCtryCcyLock getRqstISOCtryCcyLock() {
		if( rqstISOCtryCcyLock == null ) {
			rqstISOCtryCcyLock = new CFIntXMsgRqstISOCtryCcyLock( this );
		}
		return( rqstISOCtryCcyLock );
	}

	protected CFIntXMsgRqstISOCtryCcyUpdate getRqstISOCtryCcyUpdate() {
		if( rqstISOCtryCcyUpdate == null ) {
			rqstISOCtryCcyUpdate = new CFIntXMsgRqstISOCtryCcyUpdate( this );
		}
		return( rqstISOCtryCcyUpdate );
	}

	protected CFIntXMsgRqstISOCtryCcyDelete getRqstISOCtryCcyDelete() {
		if( rqstISOCtryCcyDelete == null ) {
			rqstISOCtryCcyDelete = new CFIntXMsgRqstISOCtryCcyDelete( this );
		}
		return( rqstISOCtryCcyDelete );
	}

	protected CFIntXMsgRqstISOCtryCcyReadAll getRqstISOCtryCcyReadAll() {
		if( rqstISOCtryCcyReadAll == null ) {
			rqstISOCtryCcyReadAll = new CFIntXMsgRqstISOCtryCcyReadAll( this );
		}
		return( rqstISOCtryCcyReadAll );
	}

	protected CFIntXMsgRqstISOCtryCcyRdByCtryIdx getRqstISOCtryCcyRdByCtryIdx() {
		if( rqstISOCtryCcyRdByCtryIdx == null ) {
			rqstISOCtryCcyRdByCtryIdx = new CFIntXMsgRqstISOCtryCcyRdByCtryIdx( this );
		}
		return( rqstISOCtryCcyRdByCtryIdx );
	}

	protected CFIntXMsgRqstISOCtryCcyRdByCcyIdx getRqstISOCtryCcyRdByCcyIdx() {
		if( rqstISOCtryCcyRdByCcyIdx == null ) {
			rqstISOCtryCcyRdByCcyIdx = new CFIntXMsgRqstISOCtryCcyRdByCcyIdx( this );
		}
		return( rqstISOCtryCcyRdByCcyIdx );
	}

	protected CFIntXMsgRqstISOCtryCcyDelByCtryIdx getRqstISOCtryCcyDelByCtryIdx() {
		if( rqstISOCtryCcyDelByCtryIdx == null ) {
			rqstISOCtryCcyDelByCtryIdx = new CFIntXMsgRqstISOCtryCcyDelByCtryIdx( this );
		}
		return( rqstISOCtryCcyDelByCtryIdx );
	}

	protected CFIntXMsgRqstISOCtryCcyDelByCcyIdx getRqstISOCtryCcyDelByCcyIdx() {
		if( rqstISOCtryCcyDelByCcyIdx == null ) {
			rqstISOCtryCcyDelByCcyIdx = new CFIntXMsgRqstISOCtryCcyDelByCcyIdx( this );
		}
		return( rqstISOCtryCcyDelByCcyIdx );
	}

	// ISOCtryLang Request  Factories

	protected CFIntXMsgRqstISOCtryLangCreate getRqstISOCtryLangCreate() {
		if( rqstISOCtryLangCreate == null ) {
			rqstISOCtryLangCreate = new CFIntXMsgRqstISOCtryLangCreate( this );
		}
		return( rqstISOCtryLangCreate );
	}

	protected CFIntXMsgRqstISOCtryLangRead getRqstISOCtryLangRead() {
		if( rqstISOCtryLangRead == null ) {
			rqstISOCtryLangRead = new CFIntXMsgRqstISOCtryLangRead( this );
		}
		return( rqstISOCtryLangRead );
	}

	protected CFIntXMsgRqstISOCtryLangLock getRqstISOCtryLangLock() {
		if( rqstISOCtryLangLock == null ) {
			rqstISOCtryLangLock = new CFIntXMsgRqstISOCtryLangLock( this );
		}
		return( rqstISOCtryLangLock );
	}

	protected CFIntXMsgRqstISOCtryLangUpdate getRqstISOCtryLangUpdate() {
		if( rqstISOCtryLangUpdate == null ) {
			rqstISOCtryLangUpdate = new CFIntXMsgRqstISOCtryLangUpdate( this );
		}
		return( rqstISOCtryLangUpdate );
	}

	protected CFIntXMsgRqstISOCtryLangDelete getRqstISOCtryLangDelete() {
		if( rqstISOCtryLangDelete == null ) {
			rqstISOCtryLangDelete = new CFIntXMsgRqstISOCtryLangDelete( this );
		}
		return( rqstISOCtryLangDelete );
	}

	protected CFIntXMsgRqstISOCtryLangReadAll getRqstISOCtryLangReadAll() {
		if( rqstISOCtryLangReadAll == null ) {
			rqstISOCtryLangReadAll = new CFIntXMsgRqstISOCtryLangReadAll( this );
		}
		return( rqstISOCtryLangReadAll );
	}

	protected CFIntXMsgRqstISOCtryLangRdByCtryIdx getRqstISOCtryLangRdByCtryIdx() {
		if( rqstISOCtryLangRdByCtryIdx == null ) {
			rqstISOCtryLangRdByCtryIdx = new CFIntXMsgRqstISOCtryLangRdByCtryIdx( this );
		}
		return( rqstISOCtryLangRdByCtryIdx );
	}

	protected CFIntXMsgRqstISOCtryLangRdByLangIdx getRqstISOCtryLangRdByLangIdx() {
		if( rqstISOCtryLangRdByLangIdx == null ) {
			rqstISOCtryLangRdByLangIdx = new CFIntXMsgRqstISOCtryLangRdByLangIdx( this );
		}
		return( rqstISOCtryLangRdByLangIdx );
	}

	protected CFIntXMsgRqstISOCtryLangDelByCtryIdx getRqstISOCtryLangDelByCtryIdx() {
		if( rqstISOCtryLangDelByCtryIdx == null ) {
			rqstISOCtryLangDelByCtryIdx = new CFIntXMsgRqstISOCtryLangDelByCtryIdx( this );
		}
		return( rqstISOCtryLangDelByCtryIdx );
	}

	protected CFIntXMsgRqstISOCtryLangDelByLangIdx getRqstISOCtryLangDelByLangIdx() {
		if( rqstISOCtryLangDelByLangIdx == null ) {
			rqstISOCtryLangDelByLangIdx = new CFIntXMsgRqstISOCtryLangDelByLangIdx( this );
		}
		return( rqstISOCtryLangDelByLangIdx );
	}

	// ISOLang Request  Factories

	protected CFIntXMsgRqstISOLangCreate getRqstISOLangCreate() {
		if( rqstISOLangCreate == null ) {
			rqstISOLangCreate = new CFIntXMsgRqstISOLangCreate( this );
		}
		return( rqstISOLangCreate );
	}

	protected CFIntXMsgRqstISOLangRead getRqstISOLangRead() {
		if( rqstISOLangRead == null ) {
			rqstISOLangRead = new CFIntXMsgRqstISOLangRead( this );
		}
		return( rqstISOLangRead );
	}

	protected CFIntXMsgRqstISOLangLock getRqstISOLangLock() {
		if( rqstISOLangLock == null ) {
			rqstISOLangLock = new CFIntXMsgRqstISOLangLock( this );
		}
		return( rqstISOLangLock );
	}

	protected CFIntXMsgRqstISOLangUpdate getRqstISOLangUpdate() {
		if( rqstISOLangUpdate == null ) {
			rqstISOLangUpdate = new CFIntXMsgRqstISOLangUpdate( this );
		}
		return( rqstISOLangUpdate );
	}

	protected CFIntXMsgRqstISOLangDelete getRqstISOLangDelete() {
		if( rqstISOLangDelete == null ) {
			rqstISOLangDelete = new CFIntXMsgRqstISOLangDelete( this );
		}
		return( rqstISOLangDelete );
	}

	protected CFIntXMsgRqstISOLangReadAll getRqstISOLangReadAll() {
		if( rqstISOLangReadAll == null ) {
			rqstISOLangReadAll = new CFIntXMsgRqstISOLangReadAll( this );
		}
		return( rqstISOLangReadAll );
	}

	protected CFIntXMsgRqstISOLangRdByCode3Idx getRqstISOLangRdByCode3Idx() {
		if( rqstISOLangRdByCode3Idx == null ) {
			rqstISOLangRdByCode3Idx = new CFIntXMsgRqstISOLangRdByCode3Idx( this );
		}
		return( rqstISOLangRdByCode3Idx );
	}

	protected CFIntXMsgRqstISOLangRdByCode2Idx getRqstISOLangRdByCode2Idx() {
		if( rqstISOLangRdByCode2Idx == null ) {
			rqstISOLangRdByCode2Idx = new CFIntXMsgRqstISOLangRdByCode2Idx( this );
		}
		return( rqstISOLangRdByCode2Idx );
	}

	protected CFIntXMsgRqstISOLangDelByCode3Idx getRqstISOLangDelByCode3Idx() {
		if( rqstISOLangDelByCode3Idx == null ) {
			rqstISOLangDelByCode3Idx = new CFIntXMsgRqstISOLangDelByCode3Idx( this );
		}
		return( rqstISOLangDelByCode3Idx );
	}

	protected CFIntXMsgRqstISOLangDelByCode2Idx getRqstISOLangDelByCode2Idx() {
		if( rqstISOLangDelByCode2Idx == null ) {
			rqstISOLangDelByCode2Idx = new CFIntXMsgRqstISOLangDelByCode2Idx( this );
		}
		return( rqstISOLangDelByCode2Idx );
	}

	// ISOTZone Request  Factories

	protected CFIntXMsgRqstISOTZoneCreate getRqstISOTZoneCreate() {
		if( rqstISOTZoneCreate == null ) {
			rqstISOTZoneCreate = new CFIntXMsgRqstISOTZoneCreate( this );
		}
		return( rqstISOTZoneCreate );
	}

	protected CFIntXMsgRqstISOTZoneRead getRqstISOTZoneRead() {
		if( rqstISOTZoneRead == null ) {
			rqstISOTZoneRead = new CFIntXMsgRqstISOTZoneRead( this );
		}
		return( rqstISOTZoneRead );
	}

	protected CFIntXMsgRqstISOTZoneLock getRqstISOTZoneLock() {
		if( rqstISOTZoneLock == null ) {
			rqstISOTZoneLock = new CFIntXMsgRqstISOTZoneLock( this );
		}
		return( rqstISOTZoneLock );
	}

	protected CFIntXMsgRqstISOTZoneUpdate getRqstISOTZoneUpdate() {
		if( rqstISOTZoneUpdate == null ) {
			rqstISOTZoneUpdate = new CFIntXMsgRqstISOTZoneUpdate( this );
		}
		return( rqstISOTZoneUpdate );
	}

	protected CFIntXMsgRqstISOTZoneDelete getRqstISOTZoneDelete() {
		if( rqstISOTZoneDelete == null ) {
			rqstISOTZoneDelete = new CFIntXMsgRqstISOTZoneDelete( this );
		}
		return( rqstISOTZoneDelete );
	}

	protected CFIntXMsgRqstISOTZoneReadAll getRqstISOTZoneReadAll() {
		if( rqstISOTZoneReadAll == null ) {
			rqstISOTZoneReadAll = new CFIntXMsgRqstISOTZoneReadAll( this );
		}
		return( rqstISOTZoneReadAll );
	}

	protected CFIntXMsgRqstISOTZoneRdByOffsetIdx getRqstISOTZoneRdByOffsetIdx() {
		if( rqstISOTZoneRdByOffsetIdx == null ) {
			rqstISOTZoneRdByOffsetIdx = new CFIntXMsgRqstISOTZoneRdByOffsetIdx( this );
		}
		return( rqstISOTZoneRdByOffsetIdx );
	}

	protected CFIntXMsgRqstISOTZoneRdByUTZNameIdx getRqstISOTZoneRdByUTZNameIdx() {
		if( rqstISOTZoneRdByUTZNameIdx == null ) {
			rqstISOTZoneRdByUTZNameIdx = new CFIntXMsgRqstISOTZoneRdByUTZNameIdx( this );
		}
		return( rqstISOTZoneRdByUTZNameIdx );
	}

	protected CFIntXMsgRqstISOTZoneRdByIso8601Idx getRqstISOTZoneRdByIso8601Idx() {
		if( rqstISOTZoneRdByIso8601Idx == null ) {
			rqstISOTZoneRdByIso8601Idx = new CFIntXMsgRqstISOTZoneRdByIso8601Idx( this );
		}
		return( rqstISOTZoneRdByIso8601Idx );
	}

	protected CFIntXMsgRqstISOTZoneDelByOffsetIdx getRqstISOTZoneDelByOffsetIdx() {
		if( rqstISOTZoneDelByOffsetIdx == null ) {
			rqstISOTZoneDelByOffsetIdx = new CFIntXMsgRqstISOTZoneDelByOffsetIdx( this );
		}
		return( rqstISOTZoneDelByOffsetIdx );
	}

	protected CFIntXMsgRqstISOTZoneDelByUTZNameIdx getRqstISOTZoneDelByUTZNameIdx() {
		if( rqstISOTZoneDelByUTZNameIdx == null ) {
			rqstISOTZoneDelByUTZNameIdx = new CFIntXMsgRqstISOTZoneDelByUTZNameIdx( this );
		}
		return( rqstISOTZoneDelByUTZNameIdx );
	}

	protected CFIntXMsgRqstISOTZoneDelByIso8601Idx getRqstISOTZoneDelByIso8601Idx() {
		if( rqstISOTZoneDelByIso8601Idx == null ) {
			rqstISOTZoneDelByIso8601Idx = new CFIntXMsgRqstISOTZoneDelByIso8601Idx( this );
		}
		return( rqstISOTZoneDelByIso8601Idx );
	}

	// License Request  Factories

	protected CFIntXMsgRqstLicenseCreate getRqstLicenseCreate() {
		if( rqstLicenseCreate == null ) {
			rqstLicenseCreate = new CFIntXMsgRqstLicenseCreate( this );
		}
		return( rqstLicenseCreate );
	}

	protected CFIntXMsgRqstLicenseRead getRqstLicenseRead() {
		if( rqstLicenseRead == null ) {
			rqstLicenseRead = new CFIntXMsgRqstLicenseRead( this );
		}
		return( rqstLicenseRead );
	}

	protected CFIntXMsgRqstLicenseLock getRqstLicenseLock() {
		if( rqstLicenseLock == null ) {
			rqstLicenseLock = new CFIntXMsgRqstLicenseLock( this );
		}
		return( rqstLicenseLock );
	}

	protected CFIntXMsgRqstLicenseUpdate getRqstLicenseUpdate() {
		if( rqstLicenseUpdate == null ) {
			rqstLicenseUpdate = new CFIntXMsgRqstLicenseUpdate( this );
		}
		return( rqstLicenseUpdate );
	}

	protected CFIntXMsgRqstLicenseDelete getRqstLicenseDelete() {
		if( rqstLicenseDelete == null ) {
			rqstLicenseDelete = new CFIntXMsgRqstLicenseDelete( this );
		}
		return( rqstLicenseDelete );
	}

	protected CFIntXMsgRqstLicenseReadAll getRqstLicenseReadAll() {
		if( rqstLicenseReadAll == null ) {
			rqstLicenseReadAll = new CFIntXMsgRqstLicenseReadAll( this );
		}
		return( rqstLicenseReadAll );
	}

	protected CFIntXMsgRqstLicenseRdByLicnTenantIdx getRqstLicenseRdByLicnTenantIdx() {
		if( rqstLicenseRdByLicnTenantIdx == null ) {
			rqstLicenseRdByLicnTenantIdx = new CFIntXMsgRqstLicenseRdByLicnTenantIdx( this );
		}
		return( rqstLicenseRdByLicnTenantIdx );
	}

	protected CFIntXMsgRqstLicenseRdByDomainIdx getRqstLicenseRdByDomainIdx() {
		if( rqstLicenseRdByDomainIdx == null ) {
			rqstLicenseRdByDomainIdx = new CFIntXMsgRqstLicenseRdByDomainIdx( this );
		}
		return( rqstLicenseRdByDomainIdx );
	}

	protected CFIntXMsgRqstLicenseRdByUNameIdx getRqstLicenseRdByUNameIdx() {
		if( rqstLicenseRdByUNameIdx == null ) {
			rqstLicenseRdByUNameIdx = new CFIntXMsgRqstLicenseRdByUNameIdx( this );
		}
		return( rqstLicenseRdByUNameIdx );
	}

	protected CFIntXMsgRqstLicenseDelByLicnTenantIdx getRqstLicenseDelByLicnTenantIdx() {
		if( rqstLicenseDelByLicnTenantIdx == null ) {
			rqstLicenseDelByLicnTenantIdx = new CFIntXMsgRqstLicenseDelByLicnTenantIdx( this );
		}
		return( rqstLicenseDelByLicnTenantIdx );
	}

	protected CFIntXMsgRqstLicenseDelByDomainIdx getRqstLicenseDelByDomainIdx() {
		if( rqstLicenseDelByDomainIdx == null ) {
			rqstLicenseDelByDomainIdx = new CFIntXMsgRqstLicenseDelByDomainIdx( this );
		}
		return( rqstLicenseDelByDomainIdx );
	}

	protected CFIntXMsgRqstLicenseDelByUNameIdx getRqstLicenseDelByUNameIdx() {
		if( rqstLicenseDelByUNameIdx == null ) {
			rqstLicenseDelByUNameIdx = new CFIntXMsgRqstLicenseDelByUNameIdx( this );
		}
		return( rqstLicenseDelByUNameIdx );
	}

	// MajorVersion Request  Factories

	protected CFIntXMsgRqstMajorVersionCreate getRqstMajorVersionCreate() {
		if( rqstMajorVersionCreate == null ) {
			rqstMajorVersionCreate = new CFIntXMsgRqstMajorVersionCreate( this );
		}
		return( rqstMajorVersionCreate );
	}

	protected CFIntXMsgRqstMajorVersionRead getRqstMajorVersionRead() {
		if( rqstMajorVersionRead == null ) {
			rqstMajorVersionRead = new CFIntXMsgRqstMajorVersionRead( this );
		}
		return( rqstMajorVersionRead );
	}

	protected CFIntXMsgRqstMajorVersionLock getRqstMajorVersionLock() {
		if( rqstMajorVersionLock == null ) {
			rqstMajorVersionLock = new CFIntXMsgRqstMajorVersionLock( this );
		}
		return( rqstMajorVersionLock );
	}

	protected CFIntXMsgRqstMajorVersionUpdate getRqstMajorVersionUpdate() {
		if( rqstMajorVersionUpdate == null ) {
			rqstMajorVersionUpdate = new CFIntXMsgRqstMajorVersionUpdate( this );
		}
		return( rqstMajorVersionUpdate );
	}

	protected CFIntXMsgRqstMajorVersionDelete getRqstMajorVersionDelete() {
		if( rqstMajorVersionDelete == null ) {
			rqstMajorVersionDelete = new CFIntXMsgRqstMajorVersionDelete( this );
		}
		return( rqstMajorVersionDelete );
	}

	protected CFIntXMsgRqstMajorVersionReadAll getRqstMajorVersionReadAll() {
		if( rqstMajorVersionReadAll == null ) {
			rqstMajorVersionReadAll = new CFIntXMsgRqstMajorVersionReadAll( this );
		}
		return( rqstMajorVersionReadAll );
	}

	protected CFIntXMsgRqstMajorVersionRdByTenantIdx getRqstMajorVersionRdByTenantIdx() {
		if( rqstMajorVersionRdByTenantIdx == null ) {
			rqstMajorVersionRdByTenantIdx = new CFIntXMsgRqstMajorVersionRdByTenantIdx( this );
		}
		return( rqstMajorVersionRdByTenantIdx );
	}

	protected CFIntXMsgRqstMajorVersionRdBySubProjectIdx getRqstMajorVersionRdBySubProjectIdx() {
		if( rqstMajorVersionRdBySubProjectIdx == null ) {
			rqstMajorVersionRdBySubProjectIdx = new CFIntXMsgRqstMajorVersionRdBySubProjectIdx( this );
		}
		return( rqstMajorVersionRdBySubProjectIdx );
	}

	protected CFIntXMsgRqstMajorVersionRdByNameIdx getRqstMajorVersionRdByNameIdx() {
		if( rqstMajorVersionRdByNameIdx == null ) {
			rqstMajorVersionRdByNameIdx = new CFIntXMsgRqstMajorVersionRdByNameIdx( this );
		}
		return( rqstMajorVersionRdByNameIdx );
	}

	protected CFIntXMsgRqstMajorVersionDelByTenantIdx getRqstMajorVersionDelByTenantIdx() {
		if( rqstMajorVersionDelByTenantIdx == null ) {
			rqstMajorVersionDelByTenantIdx = new CFIntXMsgRqstMajorVersionDelByTenantIdx( this );
		}
		return( rqstMajorVersionDelByTenantIdx );
	}

	protected CFIntXMsgRqstMajorVersionDelBySubProjectIdx getRqstMajorVersionDelBySubProjectIdx() {
		if( rqstMajorVersionDelBySubProjectIdx == null ) {
			rqstMajorVersionDelBySubProjectIdx = new CFIntXMsgRqstMajorVersionDelBySubProjectIdx( this );
		}
		return( rqstMajorVersionDelBySubProjectIdx );
	}

	protected CFIntXMsgRqstMajorVersionDelByNameIdx getRqstMajorVersionDelByNameIdx() {
		if( rqstMajorVersionDelByNameIdx == null ) {
			rqstMajorVersionDelByNameIdx = new CFIntXMsgRqstMajorVersionDelByNameIdx( this );
		}
		return( rqstMajorVersionDelByNameIdx );
	}

	// MimeType Request  Factories

	protected CFIntXMsgRqstMimeTypeCreate getRqstMimeTypeCreate() {
		if( rqstMimeTypeCreate == null ) {
			rqstMimeTypeCreate = new CFIntXMsgRqstMimeTypeCreate( this );
		}
		return( rqstMimeTypeCreate );
	}

	protected CFIntXMsgRqstMimeTypeRead getRqstMimeTypeRead() {
		if( rqstMimeTypeRead == null ) {
			rqstMimeTypeRead = new CFIntXMsgRqstMimeTypeRead( this );
		}
		return( rqstMimeTypeRead );
	}

	protected CFIntXMsgRqstMimeTypeLock getRqstMimeTypeLock() {
		if( rqstMimeTypeLock == null ) {
			rqstMimeTypeLock = new CFIntXMsgRqstMimeTypeLock( this );
		}
		return( rqstMimeTypeLock );
	}

	protected CFIntXMsgRqstMimeTypeUpdate getRqstMimeTypeUpdate() {
		if( rqstMimeTypeUpdate == null ) {
			rqstMimeTypeUpdate = new CFIntXMsgRqstMimeTypeUpdate( this );
		}
		return( rqstMimeTypeUpdate );
	}

	protected CFIntXMsgRqstMimeTypeDelete getRqstMimeTypeDelete() {
		if( rqstMimeTypeDelete == null ) {
			rqstMimeTypeDelete = new CFIntXMsgRqstMimeTypeDelete( this );
		}
		return( rqstMimeTypeDelete );
	}

	protected CFIntXMsgRqstMimeTypeReadAll getRqstMimeTypeReadAll() {
		if( rqstMimeTypeReadAll == null ) {
			rqstMimeTypeReadAll = new CFIntXMsgRqstMimeTypeReadAll( this );
		}
		return( rqstMimeTypeReadAll );
	}

	protected CFIntXMsgRqstMimeTypeRdByUNameIdx getRqstMimeTypeRdByUNameIdx() {
		if( rqstMimeTypeRdByUNameIdx == null ) {
			rqstMimeTypeRdByUNameIdx = new CFIntXMsgRqstMimeTypeRdByUNameIdx( this );
		}
		return( rqstMimeTypeRdByUNameIdx );
	}

	protected CFIntXMsgRqstMimeTypeDelByUNameIdx getRqstMimeTypeDelByUNameIdx() {
		if( rqstMimeTypeDelByUNameIdx == null ) {
			rqstMimeTypeDelByUNameIdx = new CFIntXMsgRqstMimeTypeDelByUNameIdx( this );
		}
		return( rqstMimeTypeDelByUNameIdx );
	}

	// MinorVersion Request  Factories

	protected CFIntXMsgRqstMinorVersionCreate getRqstMinorVersionCreate() {
		if( rqstMinorVersionCreate == null ) {
			rqstMinorVersionCreate = new CFIntXMsgRqstMinorVersionCreate( this );
		}
		return( rqstMinorVersionCreate );
	}

	protected CFIntXMsgRqstMinorVersionRead getRqstMinorVersionRead() {
		if( rqstMinorVersionRead == null ) {
			rqstMinorVersionRead = new CFIntXMsgRqstMinorVersionRead( this );
		}
		return( rqstMinorVersionRead );
	}

	protected CFIntXMsgRqstMinorVersionLock getRqstMinorVersionLock() {
		if( rqstMinorVersionLock == null ) {
			rqstMinorVersionLock = new CFIntXMsgRqstMinorVersionLock( this );
		}
		return( rqstMinorVersionLock );
	}

	protected CFIntXMsgRqstMinorVersionUpdate getRqstMinorVersionUpdate() {
		if( rqstMinorVersionUpdate == null ) {
			rqstMinorVersionUpdate = new CFIntXMsgRqstMinorVersionUpdate( this );
		}
		return( rqstMinorVersionUpdate );
	}

	protected CFIntXMsgRqstMinorVersionDelete getRqstMinorVersionDelete() {
		if( rqstMinorVersionDelete == null ) {
			rqstMinorVersionDelete = new CFIntXMsgRqstMinorVersionDelete( this );
		}
		return( rqstMinorVersionDelete );
	}

	protected CFIntXMsgRqstMinorVersionReadAll getRqstMinorVersionReadAll() {
		if( rqstMinorVersionReadAll == null ) {
			rqstMinorVersionReadAll = new CFIntXMsgRqstMinorVersionReadAll( this );
		}
		return( rqstMinorVersionReadAll );
	}

	protected CFIntXMsgRqstMinorVersionRdByTenantIdx getRqstMinorVersionRdByTenantIdx() {
		if( rqstMinorVersionRdByTenantIdx == null ) {
			rqstMinorVersionRdByTenantIdx = new CFIntXMsgRqstMinorVersionRdByTenantIdx( this );
		}
		return( rqstMinorVersionRdByTenantIdx );
	}

	protected CFIntXMsgRqstMinorVersionRdByMajorVerIdx getRqstMinorVersionRdByMajorVerIdx() {
		if( rqstMinorVersionRdByMajorVerIdx == null ) {
			rqstMinorVersionRdByMajorVerIdx = new CFIntXMsgRqstMinorVersionRdByMajorVerIdx( this );
		}
		return( rqstMinorVersionRdByMajorVerIdx );
	}

	protected CFIntXMsgRqstMinorVersionRdByNameIdx getRqstMinorVersionRdByNameIdx() {
		if( rqstMinorVersionRdByNameIdx == null ) {
			rqstMinorVersionRdByNameIdx = new CFIntXMsgRqstMinorVersionRdByNameIdx( this );
		}
		return( rqstMinorVersionRdByNameIdx );
	}

	protected CFIntXMsgRqstMinorVersionDelByTenantIdx getRqstMinorVersionDelByTenantIdx() {
		if( rqstMinorVersionDelByTenantIdx == null ) {
			rqstMinorVersionDelByTenantIdx = new CFIntXMsgRqstMinorVersionDelByTenantIdx( this );
		}
		return( rqstMinorVersionDelByTenantIdx );
	}

	protected CFIntXMsgRqstMinorVersionDelByMajorVerIdx getRqstMinorVersionDelByMajorVerIdx() {
		if( rqstMinorVersionDelByMajorVerIdx == null ) {
			rqstMinorVersionDelByMajorVerIdx = new CFIntXMsgRqstMinorVersionDelByMajorVerIdx( this );
		}
		return( rqstMinorVersionDelByMajorVerIdx );
	}

	protected CFIntXMsgRqstMinorVersionDelByNameIdx getRqstMinorVersionDelByNameIdx() {
		if( rqstMinorVersionDelByNameIdx == null ) {
			rqstMinorVersionDelByNameIdx = new CFIntXMsgRqstMinorVersionDelByNameIdx( this );
		}
		return( rqstMinorVersionDelByNameIdx );
	}

	// SecApp Request  Factories

	protected CFIntXMsgRqstSecAppCreate getRqstSecAppCreate() {
		if( rqstSecAppCreate == null ) {
			rqstSecAppCreate = new CFIntXMsgRqstSecAppCreate( this );
		}
		return( rqstSecAppCreate );
	}

	protected CFIntXMsgRqstSecAppRead getRqstSecAppRead() {
		if( rqstSecAppRead == null ) {
			rqstSecAppRead = new CFIntXMsgRqstSecAppRead( this );
		}
		return( rqstSecAppRead );
	}

	protected CFIntXMsgRqstSecAppLock getRqstSecAppLock() {
		if( rqstSecAppLock == null ) {
			rqstSecAppLock = new CFIntXMsgRqstSecAppLock( this );
		}
		return( rqstSecAppLock );
	}

	protected CFIntXMsgRqstSecAppUpdate getRqstSecAppUpdate() {
		if( rqstSecAppUpdate == null ) {
			rqstSecAppUpdate = new CFIntXMsgRqstSecAppUpdate( this );
		}
		return( rqstSecAppUpdate );
	}

	protected CFIntXMsgRqstSecAppDelete getRqstSecAppDelete() {
		if( rqstSecAppDelete == null ) {
			rqstSecAppDelete = new CFIntXMsgRqstSecAppDelete( this );
		}
		return( rqstSecAppDelete );
	}

	protected CFIntXMsgRqstSecAppReadAll getRqstSecAppReadAll() {
		if( rqstSecAppReadAll == null ) {
			rqstSecAppReadAll = new CFIntXMsgRqstSecAppReadAll( this );
		}
		return( rqstSecAppReadAll );
	}

	protected CFIntXMsgRqstSecAppPageAll getRqstSecAppPageAll() {
		if( rqstSecAppPageAll == null ) {
			rqstSecAppPageAll = new CFIntXMsgRqstSecAppPageAll( this );
		}
		return( rqstSecAppPageAll );
	}

	protected CFIntXMsgRqstSecAppRdByClusterIdx getRqstSecAppRdByClusterIdx() {
		if( rqstSecAppRdByClusterIdx == null ) {
			rqstSecAppRdByClusterIdx = new CFIntXMsgRqstSecAppRdByClusterIdx( this );
		}
		return( rqstSecAppRdByClusterIdx );
	}

	protected CFIntXMsgRqstSecAppRdByUJEEMountIdx getRqstSecAppRdByUJEEMountIdx() {
		if( rqstSecAppRdByUJEEMountIdx == null ) {
			rqstSecAppRdByUJEEMountIdx = new CFIntXMsgRqstSecAppRdByUJEEMountIdx( this );
		}
		return( rqstSecAppRdByUJEEMountIdx );
	}

	protected CFIntXMsgRqstSecAppPageByClusterIdx getRqstSecAppPageByClusterIdx() {
		if( rqstSecAppPageByClusterIdx == null ) {
			rqstSecAppPageByClusterIdx = new CFIntXMsgRqstSecAppPageByClusterIdx( this );
		}
		return( rqstSecAppPageByClusterIdx );
	}

	protected CFIntXMsgRqstSecAppDelByClusterIdx getRqstSecAppDelByClusterIdx() {
		if( rqstSecAppDelByClusterIdx == null ) {
			rqstSecAppDelByClusterIdx = new CFIntXMsgRqstSecAppDelByClusterIdx( this );
		}
		return( rqstSecAppDelByClusterIdx );
	}

	protected CFIntXMsgRqstSecAppDelByUJEEMountIdx getRqstSecAppDelByUJEEMountIdx() {
		if( rqstSecAppDelByUJEEMountIdx == null ) {
			rqstSecAppDelByUJEEMountIdx = new CFIntXMsgRqstSecAppDelByUJEEMountIdx( this );
		}
		return( rqstSecAppDelByUJEEMountIdx );
	}

	// SecDevice Request  Factories

	protected CFIntXMsgRqstSecDeviceCreate getRqstSecDeviceCreate() {
		if( rqstSecDeviceCreate == null ) {
			rqstSecDeviceCreate = new CFIntXMsgRqstSecDeviceCreate( this );
		}
		return( rqstSecDeviceCreate );
	}

	protected CFIntXMsgRqstSecDeviceRead getRqstSecDeviceRead() {
		if( rqstSecDeviceRead == null ) {
			rqstSecDeviceRead = new CFIntXMsgRqstSecDeviceRead( this );
		}
		return( rqstSecDeviceRead );
	}

	protected CFIntXMsgRqstSecDeviceLock getRqstSecDeviceLock() {
		if( rqstSecDeviceLock == null ) {
			rqstSecDeviceLock = new CFIntXMsgRqstSecDeviceLock( this );
		}
		return( rqstSecDeviceLock );
	}

	protected CFIntXMsgRqstSecDeviceUpdate getRqstSecDeviceUpdate() {
		if( rqstSecDeviceUpdate == null ) {
			rqstSecDeviceUpdate = new CFIntXMsgRqstSecDeviceUpdate( this );
		}
		return( rqstSecDeviceUpdate );
	}

	protected CFIntXMsgRqstSecDeviceDelete getRqstSecDeviceDelete() {
		if( rqstSecDeviceDelete == null ) {
			rqstSecDeviceDelete = new CFIntXMsgRqstSecDeviceDelete( this );
		}
		return( rqstSecDeviceDelete );
	}

	protected CFIntXMsgRqstSecDeviceReadAll getRqstSecDeviceReadAll() {
		if( rqstSecDeviceReadAll == null ) {
			rqstSecDeviceReadAll = new CFIntXMsgRqstSecDeviceReadAll( this );
		}
		return( rqstSecDeviceReadAll );
	}

	protected CFIntXMsgRqstSecDevicePageAll getRqstSecDevicePageAll() {
		if( rqstSecDevicePageAll == null ) {
			rqstSecDevicePageAll = new CFIntXMsgRqstSecDevicePageAll( this );
		}
		return( rqstSecDevicePageAll );
	}

	protected CFIntXMsgRqstSecDeviceRdByNameIdx getRqstSecDeviceRdByNameIdx() {
		if( rqstSecDeviceRdByNameIdx == null ) {
			rqstSecDeviceRdByNameIdx = new CFIntXMsgRqstSecDeviceRdByNameIdx( this );
		}
		return( rqstSecDeviceRdByNameIdx );
	}

	protected CFIntXMsgRqstSecDeviceRdByUserIdx getRqstSecDeviceRdByUserIdx() {
		if( rqstSecDeviceRdByUserIdx == null ) {
			rqstSecDeviceRdByUserIdx = new CFIntXMsgRqstSecDeviceRdByUserIdx( this );
		}
		return( rqstSecDeviceRdByUserIdx );
	}

	protected CFIntXMsgRqstSecDevicePageByUserIdx getRqstSecDevicePageByUserIdx() {
		if( rqstSecDevicePageByUserIdx == null ) {
			rqstSecDevicePageByUserIdx = new CFIntXMsgRqstSecDevicePageByUserIdx( this );
		}
		return( rqstSecDevicePageByUserIdx );
	}

	protected CFIntXMsgRqstSecDeviceDelByNameIdx getRqstSecDeviceDelByNameIdx() {
		if( rqstSecDeviceDelByNameIdx == null ) {
			rqstSecDeviceDelByNameIdx = new CFIntXMsgRqstSecDeviceDelByNameIdx( this );
		}
		return( rqstSecDeviceDelByNameIdx );
	}

	protected CFIntXMsgRqstSecDeviceDelByUserIdx getRqstSecDeviceDelByUserIdx() {
		if( rqstSecDeviceDelByUserIdx == null ) {
			rqstSecDeviceDelByUserIdx = new CFIntXMsgRqstSecDeviceDelByUserIdx( this );
		}
		return( rqstSecDeviceDelByUserIdx );
	}

	// SecForm Request  Factories

	protected CFIntXMsgRqstSecFormCreate getRqstSecFormCreate() {
		if( rqstSecFormCreate == null ) {
			rqstSecFormCreate = new CFIntXMsgRqstSecFormCreate( this );
		}
		return( rqstSecFormCreate );
	}

	protected CFIntXMsgRqstSecFormRead getRqstSecFormRead() {
		if( rqstSecFormRead == null ) {
			rqstSecFormRead = new CFIntXMsgRqstSecFormRead( this );
		}
		return( rqstSecFormRead );
	}

	protected CFIntXMsgRqstSecFormLock getRqstSecFormLock() {
		if( rqstSecFormLock == null ) {
			rqstSecFormLock = new CFIntXMsgRqstSecFormLock( this );
		}
		return( rqstSecFormLock );
	}

	protected CFIntXMsgRqstSecFormUpdate getRqstSecFormUpdate() {
		if( rqstSecFormUpdate == null ) {
			rqstSecFormUpdate = new CFIntXMsgRqstSecFormUpdate( this );
		}
		return( rqstSecFormUpdate );
	}

	protected CFIntXMsgRqstSecFormDelete getRqstSecFormDelete() {
		if( rqstSecFormDelete == null ) {
			rqstSecFormDelete = new CFIntXMsgRqstSecFormDelete( this );
		}
		return( rqstSecFormDelete );
	}

	protected CFIntXMsgRqstSecFormReadAll getRqstSecFormReadAll() {
		if( rqstSecFormReadAll == null ) {
			rqstSecFormReadAll = new CFIntXMsgRqstSecFormReadAll( this );
		}
		return( rqstSecFormReadAll );
	}

	protected CFIntXMsgRqstSecFormPageAll getRqstSecFormPageAll() {
		if( rqstSecFormPageAll == null ) {
			rqstSecFormPageAll = new CFIntXMsgRqstSecFormPageAll( this );
		}
		return( rqstSecFormPageAll );
	}

	protected CFIntXMsgRqstSecFormRdByClusterIdx getRqstSecFormRdByClusterIdx() {
		if( rqstSecFormRdByClusterIdx == null ) {
			rqstSecFormRdByClusterIdx = new CFIntXMsgRqstSecFormRdByClusterIdx( this );
		}
		return( rqstSecFormRdByClusterIdx );
	}

	protected CFIntXMsgRqstSecFormRdBySecAppIdx getRqstSecFormRdBySecAppIdx() {
		if( rqstSecFormRdBySecAppIdx == null ) {
			rqstSecFormRdBySecAppIdx = new CFIntXMsgRqstSecFormRdBySecAppIdx( this );
		}
		return( rqstSecFormRdBySecAppIdx );
	}

	protected CFIntXMsgRqstSecFormRdByUJEEServletIdx getRqstSecFormRdByUJEEServletIdx() {
		if( rqstSecFormRdByUJEEServletIdx == null ) {
			rqstSecFormRdByUJEEServletIdx = new CFIntXMsgRqstSecFormRdByUJEEServletIdx( this );
		}
		return( rqstSecFormRdByUJEEServletIdx );
	}

	protected CFIntXMsgRqstSecFormPageByClusterIdx getRqstSecFormPageByClusterIdx() {
		if( rqstSecFormPageByClusterIdx == null ) {
			rqstSecFormPageByClusterIdx = new CFIntXMsgRqstSecFormPageByClusterIdx( this );
		}
		return( rqstSecFormPageByClusterIdx );
	}

	protected CFIntXMsgRqstSecFormPageBySecAppIdx getRqstSecFormPageBySecAppIdx() {
		if( rqstSecFormPageBySecAppIdx == null ) {
			rqstSecFormPageBySecAppIdx = new CFIntXMsgRqstSecFormPageBySecAppIdx( this );
		}
		return( rqstSecFormPageBySecAppIdx );
	}

	protected CFIntXMsgRqstSecFormDelByClusterIdx getRqstSecFormDelByClusterIdx() {
		if( rqstSecFormDelByClusterIdx == null ) {
			rqstSecFormDelByClusterIdx = new CFIntXMsgRqstSecFormDelByClusterIdx( this );
		}
		return( rqstSecFormDelByClusterIdx );
	}

	protected CFIntXMsgRqstSecFormDelBySecAppIdx getRqstSecFormDelBySecAppIdx() {
		if( rqstSecFormDelBySecAppIdx == null ) {
			rqstSecFormDelBySecAppIdx = new CFIntXMsgRqstSecFormDelBySecAppIdx( this );
		}
		return( rqstSecFormDelBySecAppIdx );
	}

	protected CFIntXMsgRqstSecFormDelByUJEEServletIdx getRqstSecFormDelByUJEEServletIdx() {
		if( rqstSecFormDelByUJEEServletIdx == null ) {
			rqstSecFormDelByUJEEServletIdx = new CFIntXMsgRqstSecFormDelByUJEEServletIdx( this );
		}
		return( rqstSecFormDelByUJEEServletIdx );
	}

	// SecGroup Request  Factories

	protected CFIntXMsgRqstSecGroupCreate getRqstSecGroupCreate() {
		if( rqstSecGroupCreate == null ) {
			rqstSecGroupCreate = new CFIntXMsgRqstSecGroupCreate( this );
		}
		return( rqstSecGroupCreate );
	}

	protected CFIntXMsgRqstSecGroupRead getRqstSecGroupRead() {
		if( rqstSecGroupRead == null ) {
			rqstSecGroupRead = new CFIntXMsgRqstSecGroupRead( this );
		}
		return( rqstSecGroupRead );
	}

	protected CFIntXMsgRqstSecGroupLock getRqstSecGroupLock() {
		if( rqstSecGroupLock == null ) {
			rqstSecGroupLock = new CFIntXMsgRqstSecGroupLock( this );
		}
		return( rqstSecGroupLock );
	}

	protected CFIntXMsgRqstSecGroupUpdate getRqstSecGroupUpdate() {
		if( rqstSecGroupUpdate == null ) {
			rqstSecGroupUpdate = new CFIntXMsgRqstSecGroupUpdate( this );
		}
		return( rqstSecGroupUpdate );
	}

	protected CFIntXMsgRqstSecGroupDelete getRqstSecGroupDelete() {
		if( rqstSecGroupDelete == null ) {
			rqstSecGroupDelete = new CFIntXMsgRqstSecGroupDelete( this );
		}
		return( rqstSecGroupDelete );
	}

	protected CFIntXMsgRqstSecGroupReadAll getRqstSecGroupReadAll() {
		if( rqstSecGroupReadAll == null ) {
			rqstSecGroupReadAll = new CFIntXMsgRqstSecGroupReadAll( this );
		}
		return( rqstSecGroupReadAll );
	}

	protected CFIntXMsgRqstSecGroupRdByClusterIdx getRqstSecGroupRdByClusterIdx() {
		if( rqstSecGroupRdByClusterIdx == null ) {
			rqstSecGroupRdByClusterIdx = new CFIntXMsgRqstSecGroupRdByClusterIdx( this );
		}
		return( rqstSecGroupRdByClusterIdx );
	}

	protected CFIntXMsgRqstSecGroupRdByClusterVisIdx getRqstSecGroupRdByClusterVisIdx() {
		if( rqstSecGroupRdByClusterVisIdx == null ) {
			rqstSecGroupRdByClusterVisIdx = new CFIntXMsgRqstSecGroupRdByClusterVisIdx( this );
		}
		return( rqstSecGroupRdByClusterVisIdx );
	}

	protected CFIntXMsgRqstSecGroupRdByUNameIdx getRqstSecGroupRdByUNameIdx() {
		if( rqstSecGroupRdByUNameIdx == null ) {
			rqstSecGroupRdByUNameIdx = new CFIntXMsgRqstSecGroupRdByUNameIdx( this );
		}
		return( rqstSecGroupRdByUNameIdx );
	}

	protected CFIntXMsgRqstSecGroupDelByClusterIdx getRqstSecGroupDelByClusterIdx() {
		if( rqstSecGroupDelByClusterIdx == null ) {
			rqstSecGroupDelByClusterIdx = new CFIntXMsgRqstSecGroupDelByClusterIdx( this );
		}
		return( rqstSecGroupDelByClusterIdx );
	}

	protected CFIntXMsgRqstSecGroupDelByClusterVisIdx getRqstSecGroupDelByClusterVisIdx() {
		if( rqstSecGroupDelByClusterVisIdx == null ) {
			rqstSecGroupDelByClusterVisIdx = new CFIntXMsgRqstSecGroupDelByClusterVisIdx( this );
		}
		return( rqstSecGroupDelByClusterVisIdx );
	}

	protected CFIntXMsgRqstSecGroupDelByUNameIdx getRqstSecGroupDelByUNameIdx() {
		if( rqstSecGroupDelByUNameIdx == null ) {
			rqstSecGroupDelByUNameIdx = new CFIntXMsgRqstSecGroupDelByUNameIdx( this );
		}
		return( rqstSecGroupDelByUNameIdx );
	}

	// SecGroupForm Request  Factories

	protected CFIntXMsgRqstSecGroupFormCreate getRqstSecGroupFormCreate() {
		if( rqstSecGroupFormCreate == null ) {
			rqstSecGroupFormCreate = new CFIntXMsgRqstSecGroupFormCreate( this );
		}
		return( rqstSecGroupFormCreate );
	}

	protected CFIntXMsgRqstSecGroupFormRead getRqstSecGroupFormRead() {
		if( rqstSecGroupFormRead == null ) {
			rqstSecGroupFormRead = new CFIntXMsgRqstSecGroupFormRead( this );
		}
		return( rqstSecGroupFormRead );
	}

	protected CFIntXMsgRqstSecGroupFormLock getRqstSecGroupFormLock() {
		if( rqstSecGroupFormLock == null ) {
			rqstSecGroupFormLock = new CFIntXMsgRqstSecGroupFormLock( this );
		}
		return( rqstSecGroupFormLock );
	}

	protected CFIntXMsgRqstSecGroupFormUpdate getRqstSecGroupFormUpdate() {
		if( rqstSecGroupFormUpdate == null ) {
			rqstSecGroupFormUpdate = new CFIntXMsgRqstSecGroupFormUpdate( this );
		}
		return( rqstSecGroupFormUpdate );
	}

	protected CFIntXMsgRqstSecGroupFormDelete getRqstSecGroupFormDelete() {
		if( rqstSecGroupFormDelete == null ) {
			rqstSecGroupFormDelete = new CFIntXMsgRqstSecGroupFormDelete( this );
		}
		return( rqstSecGroupFormDelete );
	}

	protected CFIntXMsgRqstSecGroupFormReadAll getRqstSecGroupFormReadAll() {
		if( rqstSecGroupFormReadAll == null ) {
			rqstSecGroupFormReadAll = new CFIntXMsgRqstSecGroupFormReadAll( this );
		}
		return( rqstSecGroupFormReadAll );
	}

	protected CFIntXMsgRqstSecGroupFormPageAll getRqstSecGroupFormPageAll() {
		if( rqstSecGroupFormPageAll == null ) {
			rqstSecGroupFormPageAll = new CFIntXMsgRqstSecGroupFormPageAll( this );
		}
		return( rqstSecGroupFormPageAll );
	}

	protected CFIntXMsgRqstSecGroupFormRdByClusterIdx getRqstSecGroupFormRdByClusterIdx() {
		if( rqstSecGroupFormRdByClusterIdx == null ) {
			rqstSecGroupFormRdByClusterIdx = new CFIntXMsgRqstSecGroupFormRdByClusterIdx( this );
		}
		return( rqstSecGroupFormRdByClusterIdx );
	}

	protected CFIntXMsgRqstSecGroupFormRdByGroupIdx getRqstSecGroupFormRdByGroupIdx() {
		if( rqstSecGroupFormRdByGroupIdx == null ) {
			rqstSecGroupFormRdByGroupIdx = new CFIntXMsgRqstSecGroupFormRdByGroupIdx( this );
		}
		return( rqstSecGroupFormRdByGroupIdx );
	}

	protected CFIntXMsgRqstSecGroupFormRdByAppIdx getRqstSecGroupFormRdByAppIdx() {
		if( rqstSecGroupFormRdByAppIdx == null ) {
			rqstSecGroupFormRdByAppIdx = new CFIntXMsgRqstSecGroupFormRdByAppIdx( this );
		}
		return( rqstSecGroupFormRdByAppIdx );
	}

	protected CFIntXMsgRqstSecGroupFormRdByFormIdx getRqstSecGroupFormRdByFormIdx() {
		if( rqstSecGroupFormRdByFormIdx == null ) {
			rqstSecGroupFormRdByFormIdx = new CFIntXMsgRqstSecGroupFormRdByFormIdx( this );
		}
		return( rqstSecGroupFormRdByFormIdx );
	}

	protected CFIntXMsgRqstSecGroupFormRdByUFormIdx getRqstSecGroupFormRdByUFormIdx() {
		if( rqstSecGroupFormRdByUFormIdx == null ) {
			rqstSecGroupFormRdByUFormIdx = new CFIntXMsgRqstSecGroupFormRdByUFormIdx( this );
		}
		return( rqstSecGroupFormRdByUFormIdx );
	}

	protected CFIntXMsgRqstSecGroupFormPageByClusterIdx getRqstSecGroupFormPageByClusterIdx() {
		if( rqstSecGroupFormPageByClusterIdx == null ) {
			rqstSecGroupFormPageByClusterIdx = new CFIntXMsgRqstSecGroupFormPageByClusterIdx( this );
		}
		return( rqstSecGroupFormPageByClusterIdx );
	}

	protected CFIntXMsgRqstSecGroupFormPageByGroupIdx getRqstSecGroupFormPageByGroupIdx() {
		if( rqstSecGroupFormPageByGroupIdx == null ) {
			rqstSecGroupFormPageByGroupIdx = new CFIntXMsgRqstSecGroupFormPageByGroupIdx( this );
		}
		return( rqstSecGroupFormPageByGroupIdx );
	}

	protected CFIntXMsgRqstSecGroupFormPageByAppIdx getRqstSecGroupFormPageByAppIdx() {
		if( rqstSecGroupFormPageByAppIdx == null ) {
			rqstSecGroupFormPageByAppIdx = new CFIntXMsgRqstSecGroupFormPageByAppIdx( this );
		}
		return( rqstSecGroupFormPageByAppIdx );
	}

	protected CFIntXMsgRqstSecGroupFormPageByFormIdx getRqstSecGroupFormPageByFormIdx() {
		if( rqstSecGroupFormPageByFormIdx == null ) {
			rqstSecGroupFormPageByFormIdx = new CFIntXMsgRqstSecGroupFormPageByFormIdx( this );
		}
		return( rqstSecGroupFormPageByFormIdx );
	}

	protected CFIntXMsgRqstSecGroupFormDelByClusterIdx getRqstSecGroupFormDelByClusterIdx() {
		if( rqstSecGroupFormDelByClusterIdx == null ) {
			rqstSecGroupFormDelByClusterIdx = new CFIntXMsgRqstSecGroupFormDelByClusterIdx( this );
		}
		return( rqstSecGroupFormDelByClusterIdx );
	}

	protected CFIntXMsgRqstSecGroupFormDelByGroupIdx getRqstSecGroupFormDelByGroupIdx() {
		if( rqstSecGroupFormDelByGroupIdx == null ) {
			rqstSecGroupFormDelByGroupIdx = new CFIntXMsgRqstSecGroupFormDelByGroupIdx( this );
		}
		return( rqstSecGroupFormDelByGroupIdx );
	}

	protected CFIntXMsgRqstSecGroupFormDelByAppIdx getRqstSecGroupFormDelByAppIdx() {
		if( rqstSecGroupFormDelByAppIdx == null ) {
			rqstSecGroupFormDelByAppIdx = new CFIntXMsgRqstSecGroupFormDelByAppIdx( this );
		}
		return( rqstSecGroupFormDelByAppIdx );
	}

	protected CFIntXMsgRqstSecGroupFormDelByFormIdx getRqstSecGroupFormDelByFormIdx() {
		if( rqstSecGroupFormDelByFormIdx == null ) {
			rqstSecGroupFormDelByFormIdx = new CFIntXMsgRqstSecGroupFormDelByFormIdx( this );
		}
		return( rqstSecGroupFormDelByFormIdx );
	}

	protected CFIntXMsgRqstSecGroupFormDelByUFormIdx getRqstSecGroupFormDelByUFormIdx() {
		if( rqstSecGroupFormDelByUFormIdx == null ) {
			rqstSecGroupFormDelByUFormIdx = new CFIntXMsgRqstSecGroupFormDelByUFormIdx( this );
		}
		return( rqstSecGroupFormDelByUFormIdx );
	}

	// SecGrpInc Request  Factories

	protected CFIntXMsgRqstSecGrpIncCreate getRqstSecGrpIncCreate() {
		if( rqstSecGrpIncCreate == null ) {
			rqstSecGrpIncCreate = new CFIntXMsgRqstSecGrpIncCreate( this );
		}
		return( rqstSecGrpIncCreate );
	}

	protected CFIntXMsgRqstSecGrpIncRead getRqstSecGrpIncRead() {
		if( rqstSecGrpIncRead == null ) {
			rqstSecGrpIncRead = new CFIntXMsgRqstSecGrpIncRead( this );
		}
		return( rqstSecGrpIncRead );
	}

	protected CFIntXMsgRqstSecGrpIncLock getRqstSecGrpIncLock() {
		if( rqstSecGrpIncLock == null ) {
			rqstSecGrpIncLock = new CFIntXMsgRqstSecGrpIncLock( this );
		}
		return( rqstSecGrpIncLock );
	}

	protected CFIntXMsgRqstSecGrpIncUpdate getRqstSecGrpIncUpdate() {
		if( rqstSecGrpIncUpdate == null ) {
			rqstSecGrpIncUpdate = new CFIntXMsgRqstSecGrpIncUpdate( this );
		}
		return( rqstSecGrpIncUpdate );
	}

	protected CFIntXMsgRqstSecGrpIncDelete getRqstSecGrpIncDelete() {
		if( rqstSecGrpIncDelete == null ) {
			rqstSecGrpIncDelete = new CFIntXMsgRqstSecGrpIncDelete( this );
		}
		return( rqstSecGrpIncDelete );
	}

	protected CFIntXMsgRqstSecGrpIncReadAll getRqstSecGrpIncReadAll() {
		if( rqstSecGrpIncReadAll == null ) {
			rqstSecGrpIncReadAll = new CFIntXMsgRqstSecGrpIncReadAll( this );
		}
		return( rqstSecGrpIncReadAll );
	}

	protected CFIntXMsgRqstSecGrpIncPageAll getRqstSecGrpIncPageAll() {
		if( rqstSecGrpIncPageAll == null ) {
			rqstSecGrpIncPageAll = new CFIntXMsgRqstSecGrpIncPageAll( this );
		}
		return( rqstSecGrpIncPageAll );
	}

	protected CFIntXMsgRqstSecGrpIncRdByClusterIdx getRqstSecGrpIncRdByClusterIdx() {
		if( rqstSecGrpIncRdByClusterIdx == null ) {
			rqstSecGrpIncRdByClusterIdx = new CFIntXMsgRqstSecGrpIncRdByClusterIdx( this );
		}
		return( rqstSecGrpIncRdByClusterIdx );
	}

	protected CFIntXMsgRqstSecGrpIncRdByGroupIdx getRqstSecGrpIncRdByGroupIdx() {
		if( rqstSecGrpIncRdByGroupIdx == null ) {
			rqstSecGrpIncRdByGroupIdx = new CFIntXMsgRqstSecGrpIncRdByGroupIdx( this );
		}
		return( rqstSecGrpIncRdByGroupIdx );
	}

	protected CFIntXMsgRqstSecGrpIncRdByIncludeIdx getRqstSecGrpIncRdByIncludeIdx() {
		if( rqstSecGrpIncRdByIncludeIdx == null ) {
			rqstSecGrpIncRdByIncludeIdx = new CFIntXMsgRqstSecGrpIncRdByIncludeIdx( this );
		}
		return( rqstSecGrpIncRdByIncludeIdx );
	}

	protected CFIntXMsgRqstSecGrpIncRdByUIncludeIdx getRqstSecGrpIncRdByUIncludeIdx() {
		if( rqstSecGrpIncRdByUIncludeIdx == null ) {
			rqstSecGrpIncRdByUIncludeIdx = new CFIntXMsgRqstSecGrpIncRdByUIncludeIdx( this );
		}
		return( rqstSecGrpIncRdByUIncludeIdx );
	}

	protected CFIntXMsgRqstSecGrpIncPageByClusterIdx getRqstSecGrpIncPageByClusterIdx() {
		if( rqstSecGrpIncPageByClusterIdx == null ) {
			rqstSecGrpIncPageByClusterIdx = new CFIntXMsgRqstSecGrpIncPageByClusterIdx( this );
		}
		return( rqstSecGrpIncPageByClusterIdx );
	}

	protected CFIntXMsgRqstSecGrpIncPageByGroupIdx getRqstSecGrpIncPageByGroupIdx() {
		if( rqstSecGrpIncPageByGroupIdx == null ) {
			rqstSecGrpIncPageByGroupIdx = new CFIntXMsgRqstSecGrpIncPageByGroupIdx( this );
		}
		return( rqstSecGrpIncPageByGroupIdx );
	}

	protected CFIntXMsgRqstSecGrpIncPageByIncludeIdx getRqstSecGrpIncPageByIncludeIdx() {
		if( rqstSecGrpIncPageByIncludeIdx == null ) {
			rqstSecGrpIncPageByIncludeIdx = new CFIntXMsgRqstSecGrpIncPageByIncludeIdx( this );
		}
		return( rqstSecGrpIncPageByIncludeIdx );
	}

	protected CFIntXMsgRqstSecGrpIncDelByClusterIdx getRqstSecGrpIncDelByClusterIdx() {
		if( rqstSecGrpIncDelByClusterIdx == null ) {
			rqstSecGrpIncDelByClusterIdx = new CFIntXMsgRqstSecGrpIncDelByClusterIdx( this );
		}
		return( rqstSecGrpIncDelByClusterIdx );
	}

	protected CFIntXMsgRqstSecGrpIncDelByGroupIdx getRqstSecGrpIncDelByGroupIdx() {
		if( rqstSecGrpIncDelByGroupIdx == null ) {
			rqstSecGrpIncDelByGroupIdx = new CFIntXMsgRqstSecGrpIncDelByGroupIdx( this );
		}
		return( rqstSecGrpIncDelByGroupIdx );
	}

	protected CFIntXMsgRqstSecGrpIncDelByIncludeIdx getRqstSecGrpIncDelByIncludeIdx() {
		if( rqstSecGrpIncDelByIncludeIdx == null ) {
			rqstSecGrpIncDelByIncludeIdx = new CFIntXMsgRqstSecGrpIncDelByIncludeIdx( this );
		}
		return( rqstSecGrpIncDelByIncludeIdx );
	}

	protected CFIntXMsgRqstSecGrpIncDelByUIncludeIdx getRqstSecGrpIncDelByUIncludeIdx() {
		if( rqstSecGrpIncDelByUIncludeIdx == null ) {
			rqstSecGrpIncDelByUIncludeIdx = new CFIntXMsgRqstSecGrpIncDelByUIncludeIdx( this );
		}
		return( rqstSecGrpIncDelByUIncludeIdx );
	}

	// SecGrpMemb Request  Factories

	protected CFIntXMsgRqstSecGrpMembCreate getRqstSecGrpMembCreate() {
		if( rqstSecGrpMembCreate == null ) {
			rqstSecGrpMembCreate = new CFIntXMsgRqstSecGrpMembCreate( this );
		}
		return( rqstSecGrpMembCreate );
	}

	protected CFIntXMsgRqstSecGrpMembRead getRqstSecGrpMembRead() {
		if( rqstSecGrpMembRead == null ) {
			rqstSecGrpMembRead = new CFIntXMsgRqstSecGrpMembRead( this );
		}
		return( rqstSecGrpMembRead );
	}

	protected CFIntXMsgRqstSecGrpMembLock getRqstSecGrpMembLock() {
		if( rqstSecGrpMembLock == null ) {
			rqstSecGrpMembLock = new CFIntXMsgRqstSecGrpMembLock( this );
		}
		return( rqstSecGrpMembLock );
	}

	protected CFIntXMsgRqstSecGrpMembUpdate getRqstSecGrpMembUpdate() {
		if( rqstSecGrpMembUpdate == null ) {
			rqstSecGrpMembUpdate = new CFIntXMsgRqstSecGrpMembUpdate( this );
		}
		return( rqstSecGrpMembUpdate );
	}

	protected CFIntXMsgRqstSecGrpMembDelete getRqstSecGrpMembDelete() {
		if( rqstSecGrpMembDelete == null ) {
			rqstSecGrpMembDelete = new CFIntXMsgRqstSecGrpMembDelete( this );
		}
		return( rqstSecGrpMembDelete );
	}

	protected CFIntXMsgRqstSecGrpMembReadAll getRqstSecGrpMembReadAll() {
		if( rqstSecGrpMembReadAll == null ) {
			rqstSecGrpMembReadAll = new CFIntXMsgRqstSecGrpMembReadAll( this );
		}
		return( rqstSecGrpMembReadAll );
	}

	protected CFIntXMsgRqstSecGrpMembPageAll getRqstSecGrpMembPageAll() {
		if( rqstSecGrpMembPageAll == null ) {
			rqstSecGrpMembPageAll = new CFIntXMsgRqstSecGrpMembPageAll( this );
		}
		return( rqstSecGrpMembPageAll );
	}

	protected CFIntXMsgRqstSecGrpMembRdByClusterIdx getRqstSecGrpMembRdByClusterIdx() {
		if( rqstSecGrpMembRdByClusterIdx == null ) {
			rqstSecGrpMembRdByClusterIdx = new CFIntXMsgRqstSecGrpMembRdByClusterIdx( this );
		}
		return( rqstSecGrpMembRdByClusterIdx );
	}

	protected CFIntXMsgRqstSecGrpMembRdByGroupIdx getRqstSecGrpMembRdByGroupIdx() {
		if( rqstSecGrpMembRdByGroupIdx == null ) {
			rqstSecGrpMembRdByGroupIdx = new CFIntXMsgRqstSecGrpMembRdByGroupIdx( this );
		}
		return( rqstSecGrpMembRdByGroupIdx );
	}

	protected CFIntXMsgRqstSecGrpMembRdByUserIdx getRqstSecGrpMembRdByUserIdx() {
		if( rqstSecGrpMembRdByUserIdx == null ) {
			rqstSecGrpMembRdByUserIdx = new CFIntXMsgRqstSecGrpMembRdByUserIdx( this );
		}
		return( rqstSecGrpMembRdByUserIdx );
	}

	protected CFIntXMsgRqstSecGrpMembRdByUUserIdx getRqstSecGrpMembRdByUUserIdx() {
		if( rqstSecGrpMembRdByUUserIdx == null ) {
			rqstSecGrpMembRdByUUserIdx = new CFIntXMsgRqstSecGrpMembRdByUUserIdx( this );
		}
		return( rqstSecGrpMembRdByUUserIdx );
	}

	protected CFIntXMsgRqstSecGrpMembPageByClusterIdx getRqstSecGrpMembPageByClusterIdx() {
		if( rqstSecGrpMembPageByClusterIdx == null ) {
			rqstSecGrpMembPageByClusterIdx = new CFIntXMsgRqstSecGrpMembPageByClusterIdx( this );
		}
		return( rqstSecGrpMembPageByClusterIdx );
	}

	protected CFIntXMsgRqstSecGrpMembPageByGroupIdx getRqstSecGrpMembPageByGroupIdx() {
		if( rqstSecGrpMembPageByGroupIdx == null ) {
			rqstSecGrpMembPageByGroupIdx = new CFIntXMsgRqstSecGrpMembPageByGroupIdx( this );
		}
		return( rqstSecGrpMembPageByGroupIdx );
	}

	protected CFIntXMsgRqstSecGrpMembPageByUserIdx getRqstSecGrpMembPageByUserIdx() {
		if( rqstSecGrpMembPageByUserIdx == null ) {
			rqstSecGrpMembPageByUserIdx = new CFIntXMsgRqstSecGrpMembPageByUserIdx( this );
		}
		return( rqstSecGrpMembPageByUserIdx );
	}

	protected CFIntXMsgRqstSecGrpMembDelByClusterIdx getRqstSecGrpMembDelByClusterIdx() {
		if( rqstSecGrpMembDelByClusterIdx == null ) {
			rqstSecGrpMembDelByClusterIdx = new CFIntXMsgRqstSecGrpMembDelByClusterIdx( this );
		}
		return( rqstSecGrpMembDelByClusterIdx );
	}

	protected CFIntXMsgRqstSecGrpMembDelByGroupIdx getRqstSecGrpMembDelByGroupIdx() {
		if( rqstSecGrpMembDelByGroupIdx == null ) {
			rqstSecGrpMembDelByGroupIdx = new CFIntXMsgRqstSecGrpMembDelByGroupIdx( this );
		}
		return( rqstSecGrpMembDelByGroupIdx );
	}

	protected CFIntXMsgRqstSecGrpMembDelByUserIdx getRqstSecGrpMembDelByUserIdx() {
		if( rqstSecGrpMembDelByUserIdx == null ) {
			rqstSecGrpMembDelByUserIdx = new CFIntXMsgRqstSecGrpMembDelByUserIdx( this );
		}
		return( rqstSecGrpMembDelByUserIdx );
	}

	protected CFIntXMsgRqstSecGrpMembDelByUUserIdx getRqstSecGrpMembDelByUUserIdx() {
		if( rqstSecGrpMembDelByUUserIdx == null ) {
			rqstSecGrpMembDelByUUserIdx = new CFIntXMsgRqstSecGrpMembDelByUUserIdx( this );
		}
		return( rqstSecGrpMembDelByUUserIdx );
	}

	// SecSession Request  Factories

	protected CFIntXMsgRqstSecSessionCreate getRqstSecSessionCreate() {
		if( rqstSecSessionCreate == null ) {
			rqstSecSessionCreate = new CFIntXMsgRqstSecSessionCreate( this );
		}
		return( rqstSecSessionCreate );
	}

	protected CFIntXMsgRqstSecSessionRead getRqstSecSessionRead() {
		if( rqstSecSessionRead == null ) {
			rqstSecSessionRead = new CFIntXMsgRqstSecSessionRead( this );
		}
		return( rqstSecSessionRead );
	}

	protected CFIntXMsgRqstSecSessionLock getRqstSecSessionLock() {
		if( rqstSecSessionLock == null ) {
			rqstSecSessionLock = new CFIntXMsgRqstSecSessionLock( this );
		}
		return( rqstSecSessionLock );
	}

	protected CFIntXMsgRqstSecSessionUpdate getRqstSecSessionUpdate() {
		if( rqstSecSessionUpdate == null ) {
			rqstSecSessionUpdate = new CFIntXMsgRqstSecSessionUpdate( this );
		}
		return( rqstSecSessionUpdate );
	}

	protected CFIntXMsgRqstSecSessionDelete getRqstSecSessionDelete() {
		if( rqstSecSessionDelete == null ) {
			rqstSecSessionDelete = new CFIntXMsgRqstSecSessionDelete( this );
		}
		return( rqstSecSessionDelete );
	}

	protected CFIntXMsgRqstSecSessionReadAll getRqstSecSessionReadAll() {
		if( rqstSecSessionReadAll == null ) {
			rqstSecSessionReadAll = new CFIntXMsgRqstSecSessionReadAll( this );
		}
		return( rqstSecSessionReadAll );
	}

	protected CFIntXMsgRqstSecSessionPageAll getRqstSecSessionPageAll() {
		if( rqstSecSessionPageAll == null ) {
			rqstSecSessionPageAll = new CFIntXMsgRqstSecSessionPageAll( this );
		}
		return( rqstSecSessionPageAll );
	}

	protected CFIntXMsgRqstSecSessionRdBySecUserIdx getRqstSecSessionRdBySecUserIdx() {
		if( rqstSecSessionRdBySecUserIdx == null ) {
			rqstSecSessionRdBySecUserIdx = new CFIntXMsgRqstSecSessionRdBySecUserIdx( this );
		}
		return( rqstSecSessionRdBySecUserIdx );
	}

	protected CFIntXMsgRqstSecSessionRdBySecDevIdx getRqstSecSessionRdBySecDevIdx() {
		if( rqstSecSessionRdBySecDevIdx == null ) {
			rqstSecSessionRdBySecDevIdx = new CFIntXMsgRqstSecSessionRdBySecDevIdx( this );
		}
		return( rqstSecSessionRdBySecDevIdx );
	}

	protected CFIntXMsgRqstSecSessionRdByStartIdx getRqstSecSessionRdByStartIdx() {
		if( rqstSecSessionRdByStartIdx == null ) {
			rqstSecSessionRdByStartIdx = new CFIntXMsgRqstSecSessionRdByStartIdx( this );
		}
		return( rqstSecSessionRdByStartIdx );
	}

	protected CFIntXMsgRqstSecSessionRdByFinishIdx getRqstSecSessionRdByFinishIdx() {
		if( rqstSecSessionRdByFinishIdx == null ) {
			rqstSecSessionRdByFinishIdx = new CFIntXMsgRqstSecSessionRdByFinishIdx( this );
		}
		return( rqstSecSessionRdByFinishIdx );
	}

	protected CFIntXMsgRqstSecSessionRdBySecProxyIdx getRqstSecSessionRdBySecProxyIdx() {
		if( rqstSecSessionRdBySecProxyIdx == null ) {
			rqstSecSessionRdBySecProxyIdx = new CFIntXMsgRqstSecSessionRdBySecProxyIdx( this );
		}
		return( rqstSecSessionRdBySecProxyIdx );
	}

	protected CFIntXMsgRqstSecSessionPageBySecUserIdx getRqstSecSessionPageBySecUserIdx() {
		if( rqstSecSessionPageBySecUserIdx == null ) {
			rqstSecSessionPageBySecUserIdx = new CFIntXMsgRqstSecSessionPageBySecUserIdx( this );
		}
		return( rqstSecSessionPageBySecUserIdx );
	}

	protected CFIntXMsgRqstSecSessionPageBySecDevIdx getRqstSecSessionPageBySecDevIdx() {
		if( rqstSecSessionPageBySecDevIdx == null ) {
			rqstSecSessionPageBySecDevIdx = new CFIntXMsgRqstSecSessionPageBySecDevIdx( this );
		}
		return( rqstSecSessionPageBySecDevIdx );
	}

	protected CFIntXMsgRqstSecSessionPageByFinishIdx getRqstSecSessionPageByFinishIdx() {
		if( rqstSecSessionPageByFinishIdx == null ) {
			rqstSecSessionPageByFinishIdx = new CFIntXMsgRqstSecSessionPageByFinishIdx( this );
		}
		return( rqstSecSessionPageByFinishIdx );
	}

	protected CFIntXMsgRqstSecSessionPageBySecProxyIdx getRqstSecSessionPageBySecProxyIdx() {
		if( rqstSecSessionPageBySecProxyIdx == null ) {
			rqstSecSessionPageBySecProxyIdx = new CFIntXMsgRqstSecSessionPageBySecProxyIdx( this );
		}
		return( rqstSecSessionPageBySecProxyIdx );
	}

	protected CFIntXMsgRqstSecSessionDelBySecUserIdx getRqstSecSessionDelBySecUserIdx() {
		if( rqstSecSessionDelBySecUserIdx == null ) {
			rqstSecSessionDelBySecUserIdx = new CFIntXMsgRqstSecSessionDelBySecUserIdx( this );
		}
		return( rqstSecSessionDelBySecUserIdx );
	}

	protected CFIntXMsgRqstSecSessionDelBySecDevIdx getRqstSecSessionDelBySecDevIdx() {
		if( rqstSecSessionDelBySecDevIdx == null ) {
			rqstSecSessionDelBySecDevIdx = new CFIntXMsgRqstSecSessionDelBySecDevIdx( this );
		}
		return( rqstSecSessionDelBySecDevIdx );
	}

	protected CFIntXMsgRqstSecSessionDelByStartIdx getRqstSecSessionDelByStartIdx() {
		if( rqstSecSessionDelByStartIdx == null ) {
			rqstSecSessionDelByStartIdx = new CFIntXMsgRqstSecSessionDelByStartIdx( this );
		}
		return( rqstSecSessionDelByStartIdx );
	}

	protected CFIntXMsgRqstSecSessionDelByFinishIdx getRqstSecSessionDelByFinishIdx() {
		if( rqstSecSessionDelByFinishIdx == null ) {
			rqstSecSessionDelByFinishIdx = new CFIntXMsgRqstSecSessionDelByFinishIdx( this );
		}
		return( rqstSecSessionDelByFinishIdx );
	}

	protected CFIntXMsgRqstSecSessionDelBySecProxyIdx getRqstSecSessionDelBySecProxyIdx() {
		if( rqstSecSessionDelBySecProxyIdx == null ) {
			rqstSecSessionDelBySecProxyIdx = new CFIntXMsgRqstSecSessionDelBySecProxyIdx( this );
		}
		return( rqstSecSessionDelBySecProxyIdx );
	}

	// SecUser Request  Factories

	protected CFIntXMsgRqstSecUserCreate getRqstSecUserCreate() {
		if( rqstSecUserCreate == null ) {
			rqstSecUserCreate = new CFIntXMsgRqstSecUserCreate( this );
		}
		return( rqstSecUserCreate );
	}

	protected CFIntXMsgRqstSecUserRead getRqstSecUserRead() {
		if( rqstSecUserRead == null ) {
			rqstSecUserRead = new CFIntXMsgRqstSecUserRead( this );
		}
		return( rqstSecUserRead );
	}

	protected CFIntXMsgRqstSecUserLock getRqstSecUserLock() {
		if( rqstSecUserLock == null ) {
			rqstSecUserLock = new CFIntXMsgRqstSecUserLock( this );
		}
		return( rqstSecUserLock );
	}

	protected CFIntXMsgRqstSecUserUpdate getRqstSecUserUpdate() {
		if( rqstSecUserUpdate == null ) {
			rqstSecUserUpdate = new CFIntXMsgRqstSecUserUpdate( this );
		}
		return( rqstSecUserUpdate );
	}

	protected CFIntXMsgRqstSecUserDelete getRqstSecUserDelete() {
		if( rqstSecUserDelete == null ) {
			rqstSecUserDelete = new CFIntXMsgRqstSecUserDelete( this );
		}
		return( rqstSecUserDelete );
	}

	protected CFIntXMsgRqstSecUserReadAll getRqstSecUserReadAll() {
		if( rqstSecUserReadAll == null ) {
			rqstSecUserReadAll = new CFIntXMsgRqstSecUserReadAll( this );
		}
		return( rqstSecUserReadAll );
	}

	protected CFIntXMsgRqstSecUserPageAll getRqstSecUserPageAll() {
		if( rqstSecUserPageAll == null ) {
			rqstSecUserPageAll = new CFIntXMsgRqstSecUserPageAll( this );
		}
		return( rqstSecUserPageAll );
	}

	protected CFIntXMsgRqstSecUserRdByULoginIdx getRqstSecUserRdByULoginIdx() {
		if( rqstSecUserRdByULoginIdx == null ) {
			rqstSecUserRdByULoginIdx = new CFIntXMsgRqstSecUserRdByULoginIdx( this );
		}
		return( rqstSecUserRdByULoginIdx );
	}

	protected CFIntXMsgRqstSecUserRdByEMConfIdx getRqstSecUserRdByEMConfIdx() {
		if( rqstSecUserRdByEMConfIdx == null ) {
			rqstSecUserRdByEMConfIdx = new CFIntXMsgRqstSecUserRdByEMConfIdx( this );
		}
		return( rqstSecUserRdByEMConfIdx );
	}

	protected CFIntXMsgRqstSecUserRdByPwdResetIdx getRqstSecUserRdByPwdResetIdx() {
		if( rqstSecUserRdByPwdResetIdx == null ) {
			rqstSecUserRdByPwdResetIdx = new CFIntXMsgRqstSecUserRdByPwdResetIdx( this );
		}
		return( rqstSecUserRdByPwdResetIdx );
	}

	protected CFIntXMsgRqstSecUserRdByDefDevIdx getRqstSecUserRdByDefDevIdx() {
		if( rqstSecUserRdByDefDevIdx == null ) {
			rqstSecUserRdByDefDevIdx = new CFIntXMsgRqstSecUserRdByDefDevIdx( this );
		}
		return( rqstSecUserRdByDefDevIdx );
	}

	protected CFIntXMsgRqstSecUserPageByEMConfIdx getRqstSecUserPageByEMConfIdx() {
		if( rqstSecUserPageByEMConfIdx == null ) {
			rqstSecUserPageByEMConfIdx = new CFIntXMsgRqstSecUserPageByEMConfIdx( this );
		}
		return( rqstSecUserPageByEMConfIdx );
	}

	protected CFIntXMsgRqstSecUserPageByPwdResetIdx getRqstSecUserPageByPwdResetIdx() {
		if( rqstSecUserPageByPwdResetIdx == null ) {
			rqstSecUserPageByPwdResetIdx = new CFIntXMsgRqstSecUserPageByPwdResetIdx( this );
		}
		return( rqstSecUserPageByPwdResetIdx );
	}

	protected CFIntXMsgRqstSecUserPageByDefDevIdx getRqstSecUserPageByDefDevIdx() {
		if( rqstSecUserPageByDefDevIdx == null ) {
			rqstSecUserPageByDefDevIdx = new CFIntXMsgRqstSecUserPageByDefDevIdx( this );
		}
		return( rqstSecUserPageByDefDevIdx );
	}

	protected CFIntXMsgRqstSecUserDelByULoginIdx getRqstSecUserDelByULoginIdx() {
		if( rqstSecUserDelByULoginIdx == null ) {
			rqstSecUserDelByULoginIdx = new CFIntXMsgRqstSecUserDelByULoginIdx( this );
		}
		return( rqstSecUserDelByULoginIdx );
	}

	protected CFIntXMsgRqstSecUserDelByEMConfIdx getRqstSecUserDelByEMConfIdx() {
		if( rqstSecUserDelByEMConfIdx == null ) {
			rqstSecUserDelByEMConfIdx = new CFIntXMsgRqstSecUserDelByEMConfIdx( this );
		}
		return( rqstSecUserDelByEMConfIdx );
	}

	protected CFIntXMsgRqstSecUserDelByPwdResetIdx getRqstSecUserDelByPwdResetIdx() {
		if( rqstSecUserDelByPwdResetIdx == null ) {
			rqstSecUserDelByPwdResetIdx = new CFIntXMsgRqstSecUserDelByPwdResetIdx( this );
		}
		return( rqstSecUserDelByPwdResetIdx );
	}

	protected CFIntXMsgRqstSecUserDelByDefDevIdx getRqstSecUserDelByDefDevIdx() {
		if( rqstSecUserDelByDefDevIdx == null ) {
			rqstSecUserDelByDefDevIdx = new CFIntXMsgRqstSecUserDelByDefDevIdx( this );
		}
		return( rqstSecUserDelByDefDevIdx );
	}

	// Service Request  Factories

	protected CFIntXMsgRqstServiceCreate getRqstServiceCreate() {
		if( rqstServiceCreate == null ) {
			rqstServiceCreate = new CFIntXMsgRqstServiceCreate( this );
		}
		return( rqstServiceCreate );
	}

	protected CFIntXMsgRqstServiceRead getRqstServiceRead() {
		if( rqstServiceRead == null ) {
			rqstServiceRead = new CFIntXMsgRqstServiceRead( this );
		}
		return( rqstServiceRead );
	}

	protected CFIntXMsgRqstServiceLock getRqstServiceLock() {
		if( rqstServiceLock == null ) {
			rqstServiceLock = new CFIntXMsgRqstServiceLock( this );
		}
		return( rqstServiceLock );
	}

	protected CFIntXMsgRqstServiceUpdate getRqstServiceUpdate() {
		if( rqstServiceUpdate == null ) {
			rqstServiceUpdate = new CFIntXMsgRqstServiceUpdate( this );
		}
		return( rqstServiceUpdate );
	}

	protected CFIntXMsgRqstServiceDelete getRqstServiceDelete() {
		if( rqstServiceDelete == null ) {
			rqstServiceDelete = new CFIntXMsgRqstServiceDelete( this );
		}
		return( rqstServiceDelete );
	}

	protected CFIntXMsgRqstServiceReadAll getRqstServiceReadAll() {
		if( rqstServiceReadAll == null ) {
			rqstServiceReadAll = new CFIntXMsgRqstServiceReadAll( this );
		}
		return( rqstServiceReadAll );
	}

	protected CFIntXMsgRqstServicePageAll getRqstServicePageAll() {
		if( rqstServicePageAll == null ) {
			rqstServicePageAll = new CFIntXMsgRqstServicePageAll( this );
		}
		return( rqstServicePageAll );
	}

	protected CFIntXMsgRqstServiceRdByClusterIdx getRqstServiceRdByClusterIdx() {
		if( rqstServiceRdByClusterIdx == null ) {
			rqstServiceRdByClusterIdx = new CFIntXMsgRqstServiceRdByClusterIdx( this );
		}
		return( rqstServiceRdByClusterIdx );
	}

	protected CFIntXMsgRqstServiceRdByHostIdx getRqstServiceRdByHostIdx() {
		if( rqstServiceRdByHostIdx == null ) {
			rqstServiceRdByHostIdx = new CFIntXMsgRqstServiceRdByHostIdx( this );
		}
		return( rqstServiceRdByHostIdx );
	}

	protected CFIntXMsgRqstServiceRdByTypeIdx getRqstServiceRdByTypeIdx() {
		if( rqstServiceRdByTypeIdx == null ) {
			rqstServiceRdByTypeIdx = new CFIntXMsgRqstServiceRdByTypeIdx( this );
		}
		return( rqstServiceRdByTypeIdx );
	}

	protected CFIntXMsgRqstServiceRdByUTypeIdx getRqstServiceRdByUTypeIdx() {
		if( rqstServiceRdByUTypeIdx == null ) {
			rqstServiceRdByUTypeIdx = new CFIntXMsgRqstServiceRdByUTypeIdx( this );
		}
		return( rqstServiceRdByUTypeIdx );
	}

	protected CFIntXMsgRqstServiceRdByUHostPortIdx getRqstServiceRdByUHostPortIdx() {
		if( rqstServiceRdByUHostPortIdx == null ) {
			rqstServiceRdByUHostPortIdx = new CFIntXMsgRqstServiceRdByUHostPortIdx( this );
		}
		return( rqstServiceRdByUHostPortIdx );
	}

	protected CFIntXMsgRqstServicePageByClusterIdx getRqstServicePageByClusterIdx() {
		if( rqstServicePageByClusterIdx == null ) {
			rqstServicePageByClusterIdx = new CFIntXMsgRqstServicePageByClusterIdx( this );
		}
		return( rqstServicePageByClusterIdx );
	}

	protected CFIntXMsgRqstServicePageByHostIdx getRqstServicePageByHostIdx() {
		if( rqstServicePageByHostIdx == null ) {
			rqstServicePageByHostIdx = new CFIntXMsgRqstServicePageByHostIdx( this );
		}
		return( rqstServicePageByHostIdx );
	}

	protected CFIntXMsgRqstServicePageByTypeIdx getRqstServicePageByTypeIdx() {
		if( rqstServicePageByTypeIdx == null ) {
			rqstServicePageByTypeIdx = new CFIntXMsgRqstServicePageByTypeIdx( this );
		}
		return( rqstServicePageByTypeIdx );
	}

	protected CFIntXMsgRqstServiceDelByClusterIdx getRqstServiceDelByClusterIdx() {
		if( rqstServiceDelByClusterIdx == null ) {
			rqstServiceDelByClusterIdx = new CFIntXMsgRqstServiceDelByClusterIdx( this );
		}
		return( rqstServiceDelByClusterIdx );
	}

	protected CFIntXMsgRqstServiceDelByHostIdx getRqstServiceDelByHostIdx() {
		if( rqstServiceDelByHostIdx == null ) {
			rqstServiceDelByHostIdx = new CFIntXMsgRqstServiceDelByHostIdx( this );
		}
		return( rqstServiceDelByHostIdx );
	}

	protected CFIntXMsgRqstServiceDelByTypeIdx getRqstServiceDelByTypeIdx() {
		if( rqstServiceDelByTypeIdx == null ) {
			rqstServiceDelByTypeIdx = new CFIntXMsgRqstServiceDelByTypeIdx( this );
		}
		return( rqstServiceDelByTypeIdx );
	}

	protected CFIntXMsgRqstServiceDelByUTypeIdx getRqstServiceDelByUTypeIdx() {
		if( rqstServiceDelByUTypeIdx == null ) {
			rqstServiceDelByUTypeIdx = new CFIntXMsgRqstServiceDelByUTypeIdx( this );
		}
		return( rqstServiceDelByUTypeIdx );
	}

	protected CFIntXMsgRqstServiceDelByUHostPortIdx getRqstServiceDelByUHostPortIdx() {
		if( rqstServiceDelByUHostPortIdx == null ) {
			rqstServiceDelByUHostPortIdx = new CFIntXMsgRqstServiceDelByUHostPortIdx( this );
		}
		return( rqstServiceDelByUHostPortIdx );
	}

	// ServiceType Request  Factories

	protected CFIntXMsgRqstServiceTypeCreate getRqstServiceTypeCreate() {
		if( rqstServiceTypeCreate == null ) {
			rqstServiceTypeCreate = new CFIntXMsgRqstServiceTypeCreate( this );
		}
		return( rqstServiceTypeCreate );
	}

	protected CFIntXMsgRqstServiceTypeRead getRqstServiceTypeRead() {
		if( rqstServiceTypeRead == null ) {
			rqstServiceTypeRead = new CFIntXMsgRqstServiceTypeRead( this );
		}
		return( rqstServiceTypeRead );
	}

	protected CFIntXMsgRqstServiceTypeLock getRqstServiceTypeLock() {
		if( rqstServiceTypeLock == null ) {
			rqstServiceTypeLock = new CFIntXMsgRqstServiceTypeLock( this );
		}
		return( rqstServiceTypeLock );
	}

	protected CFIntXMsgRqstServiceTypeUpdate getRqstServiceTypeUpdate() {
		if( rqstServiceTypeUpdate == null ) {
			rqstServiceTypeUpdate = new CFIntXMsgRqstServiceTypeUpdate( this );
		}
		return( rqstServiceTypeUpdate );
	}

	protected CFIntXMsgRqstServiceTypeDelete getRqstServiceTypeDelete() {
		if( rqstServiceTypeDelete == null ) {
			rqstServiceTypeDelete = new CFIntXMsgRqstServiceTypeDelete( this );
		}
		return( rqstServiceTypeDelete );
	}

	protected CFIntXMsgRqstServiceTypeReadAll getRqstServiceTypeReadAll() {
		if( rqstServiceTypeReadAll == null ) {
			rqstServiceTypeReadAll = new CFIntXMsgRqstServiceTypeReadAll( this );
		}
		return( rqstServiceTypeReadAll );
	}

	protected CFIntXMsgRqstServiceTypeRdByUDescrIdx getRqstServiceTypeRdByUDescrIdx() {
		if( rqstServiceTypeRdByUDescrIdx == null ) {
			rqstServiceTypeRdByUDescrIdx = new CFIntXMsgRqstServiceTypeRdByUDescrIdx( this );
		}
		return( rqstServiceTypeRdByUDescrIdx );
	}

	protected CFIntXMsgRqstServiceTypeDelByUDescrIdx getRqstServiceTypeDelByUDescrIdx() {
		if( rqstServiceTypeDelByUDescrIdx == null ) {
			rqstServiceTypeDelByUDescrIdx = new CFIntXMsgRqstServiceTypeDelByUDescrIdx( this );
		}
		return( rqstServiceTypeDelByUDescrIdx );
	}

	// SubProject Request  Factories

	protected CFIntXMsgRqstSubProjectCreate getRqstSubProjectCreate() {
		if( rqstSubProjectCreate == null ) {
			rqstSubProjectCreate = new CFIntXMsgRqstSubProjectCreate( this );
		}
		return( rqstSubProjectCreate );
	}

	protected CFIntXMsgRqstSubProjectRead getRqstSubProjectRead() {
		if( rqstSubProjectRead == null ) {
			rqstSubProjectRead = new CFIntXMsgRqstSubProjectRead( this );
		}
		return( rqstSubProjectRead );
	}

	protected CFIntXMsgRqstSubProjectLock getRqstSubProjectLock() {
		if( rqstSubProjectLock == null ) {
			rqstSubProjectLock = new CFIntXMsgRqstSubProjectLock( this );
		}
		return( rqstSubProjectLock );
	}

	protected CFIntXMsgRqstSubProjectUpdate getRqstSubProjectUpdate() {
		if( rqstSubProjectUpdate == null ) {
			rqstSubProjectUpdate = new CFIntXMsgRqstSubProjectUpdate( this );
		}
		return( rqstSubProjectUpdate );
	}

	protected CFIntXMsgRqstSubProjectDelete getRqstSubProjectDelete() {
		if( rqstSubProjectDelete == null ) {
			rqstSubProjectDelete = new CFIntXMsgRqstSubProjectDelete( this );
		}
		return( rqstSubProjectDelete );
	}

	protected CFIntXMsgRqstSubProjectReadAll getRqstSubProjectReadAll() {
		if( rqstSubProjectReadAll == null ) {
			rqstSubProjectReadAll = new CFIntXMsgRqstSubProjectReadAll( this );
		}
		return( rqstSubProjectReadAll );
	}

	protected CFIntXMsgRqstSubProjectRdByTenantIdx getRqstSubProjectRdByTenantIdx() {
		if( rqstSubProjectRdByTenantIdx == null ) {
			rqstSubProjectRdByTenantIdx = new CFIntXMsgRqstSubProjectRdByTenantIdx( this );
		}
		return( rqstSubProjectRdByTenantIdx );
	}

	protected CFIntXMsgRqstSubProjectRdByTopProjectIdx getRqstSubProjectRdByTopProjectIdx() {
		if( rqstSubProjectRdByTopProjectIdx == null ) {
			rqstSubProjectRdByTopProjectIdx = new CFIntXMsgRqstSubProjectRdByTopProjectIdx( this );
		}
		return( rqstSubProjectRdByTopProjectIdx );
	}

	protected CFIntXMsgRqstSubProjectRdByNameIdx getRqstSubProjectRdByNameIdx() {
		if( rqstSubProjectRdByNameIdx == null ) {
			rqstSubProjectRdByNameIdx = new CFIntXMsgRqstSubProjectRdByNameIdx( this );
		}
		return( rqstSubProjectRdByNameIdx );
	}

	protected CFIntXMsgRqstSubProjectDelByTenantIdx getRqstSubProjectDelByTenantIdx() {
		if( rqstSubProjectDelByTenantIdx == null ) {
			rqstSubProjectDelByTenantIdx = new CFIntXMsgRqstSubProjectDelByTenantIdx( this );
		}
		return( rqstSubProjectDelByTenantIdx );
	}

	protected CFIntXMsgRqstSubProjectDelByTopProjectIdx getRqstSubProjectDelByTopProjectIdx() {
		if( rqstSubProjectDelByTopProjectIdx == null ) {
			rqstSubProjectDelByTopProjectIdx = new CFIntXMsgRqstSubProjectDelByTopProjectIdx( this );
		}
		return( rqstSubProjectDelByTopProjectIdx );
	}

	protected CFIntXMsgRqstSubProjectDelByNameIdx getRqstSubProjectDelByNameIdx() {
		if( rqstSubProjectDelByNameIdx == null ) {
			rqstSubProjectDelByNameIdx = new CFIntXMsgRqstSubProjectDelByNameIdx( this );
		}
		return( rqstSubProjectDelByNameIdx );
	}

	// SysCluster Request  Factories

	protected CFIntXMsgRqstSysClusterCreate getRqstSysClusterCreate() {
		if( rqstSysClusterCreate == null ) {
			rqstSysClusterCreate = new CFIntXMsgRqstSysClusterCreate( this );
		}
		return( rqstSysClusterCreate );
	}

	protected CFIntXMsgRqstSysClusterRead getRqstSysClusterRead() {
		if( rqstSysClusterRead == null ) {
			rqstSysClusterRead = new CFIntXMsgRqstSysClusterRead( this );
		}
		return( rqstSysClusterRead );
	}

	protected CFIntXMsgRqstSysClusterLock getRqstSysClusterLock() {
		if( rqstSysClusterLock == null ) {
			rqstSysClusterLock = new CFIntXMsgRqstSysClusterLock( this );
		}
		return( rqstSysClusterLock );
	}

	protected CFIntXMsgRqstSysClusterUpdate getRqstSysClusterUpdate() {
		if( rqstSysClusterUpdate == null ) {
			rqstSysClusterUpdate = new CFIntXMsgRqstSysClusterUpdate( this );
		}
		return( rqstSysClusterUpdate );
	}

	protected CFIntXMsgRqstSysClusterDelete getRqstSysClusterDelete() {
		if( rqstSysClusterDelete == null ) {
			rqstSysClusterDelete = new CFIntXMsgRqstSysClusterDelete( this );
		}
		return( rqstSysClusterDelete );
	}

	protected CFIntXMsgRqstSysClusterReadAll getRqstSysClusterReadAll() {
		if( rqstSysClusterReadAll == null ) {
			rqstSysClusterReadAll = new CFIntXMsgRqstSysClusterReadAll( this );
		}
		return( rqstSysClusterReadAll );
	}

	protected CFIntXMsgRqstSysClusterRdByClusterIdx getRqstSysClusterRdByClusterIdx() {
		if( rqstSysClusterRdByClusterIdx == null ) {
			rqstSysClusterRdByClusterIdx = new CFIntXMsgRqstSysClusterRdByClusterIdx( this );
		}
		return( rqstSysClusterRdByClusterIdx );
	}

	protected CFIntXMsgRqstSysClusterDelByClusterIdx getRqstSysClusterDelByClusterIdx() {
		if( rqstSysClusterDelByClusterIdx == null ) {
			rqstSysClusterDelByClusterIdx = new CFIntXMsgRqstSysClusterDelByClusterIdx( this );
		}
		return( rqstSysClusterDelByClusterIdx );
	}

	// TSecGroup Request  Factories

	protected CFIntXMsgRqstTSecGroupCreate getRqstTSecGroupCreate() {
		if( rqstTSecGroupCreate == null ) {
			rqstTSecGroupCreate = new CFIntXMsgRqstTSecGroupCreate( this );
		}
		return( rqstTSecGroupCreate );
	}

	protected CFIntXMsgRqstTSecGroupRead getRqstTSecGroupRead() {
		if( rqstTSecGroupRead == null ) {
			rqstTSecGroupRead = new CFIntXMsgRqstTSecGroupRead( this );
		}
		return( rqstTSecGroupRead );
	}

	protected CFIntXMsgRqstTSecGroupLock getRqstTSecGroupLock() {
		if( rqstTSecGroupLock == null ) {
			rqstTSecGroupLock = new CFIntXMsgRqstTSecGroupLock( this );
		}
		return( rqstTSecGroupLock );
	}

	protected CFIntXMsgRqstTSecGroupUpdate getRqstTSecGroupUpdate() {
		if( rqstTSecGroupUpdate == null ) {
			rqstTSecGroupUpdate = new CFIntXMsgRqstTSecGroupUpdate( this );
		}
		return( rqstTSecGroupUpdate );
	}

	protected CFIntXMsgRqstTSecGroupDelete getRqstTSecGroupDelete() {
		if( rqstTSecGroupDelete == null ) {
			rqstTSecGroupDelete = new CFIntXMsgRqstTSecGroupDelete( this );
		}
		return( rqstTSecGroupDelete );
	}

	protected CFIntXMsgRqstTSecGroupReadAll getRqstTSecGroupReadAll() {
		if( rqstTSecGroupReadAll == null ) {
			rqstTSecGroupReadAll = new CFIntXMsgRqstTSecGroupReadAll( this );
		}
		return( rqstTSecGroupReadAll );
	}

	protected CFIntXMsgRqstTSecGroupRdByTenantIdx getRqstTSecGroupRdByTenantIdx() {
		if( rqstTSecGroupRdByTenantIdx == null ) {
			rqstTSecGroupRdByTenantIdx = new CFIntXMsgRqstTSecGroupRdByTenantIdx( this );
		}
		return( rqstTSecGroupRdByTenantIdx );
	}

	protected CFIntXMsgRqstTSecGroupRdByTenantVisIdx getRqstTSecGroupRdByTenantVisIdx() {
		if( rqstTSecGroupRdByTenantVisIdx == null ) {
			rqstTSecGroupRdByTenantVisIdx = new CFIntXMsgRqstTSecGroupRdByTenantVisIdx( this );
		}
		return( rqstTSecGroupRdByTenantVisIdx );
	}

	protected CFIntXMsgRqstTSecGroupRdByUNameIdx getRqstTSecGroupRdByUNameIdx() {
		if( rqstTSecGroupRdByUNameIdx == null ) {
			rqstTSecGroupRdByUNameIdx = new CFIntXMsgRqstTSecGroupRdByUNameIdx( this );
		}
		return( rqstTSecGroupRdByUNameIdx );
	}

	protected CFIntXMsgRqstTSecGroupDelByTenantIdx getRqstTSecGroupDelByTenantIdx() {
		if( rqstTSecGroupDelByTenantIdx == null ) {
			rqstTSecGroupDelByTenantIdx = new CFIntXMsgRqstTSecGroupDelByTenantIdx( this );
		}
		return( rqstTSecGroupDelByTenantIdx );
	}

	protected CFIntXMsgRqstTSecGroupDelByTenantVisIdx getRqstTSecGroupDelByTenantVisIdx() {
		if( rqstTSecGroupDelByTenantVisIdx == null ) {
			rqstTSecGroupDelByTenantVisIdx = new CFIntXMsgRqstTSecGroupDelByTenantVisIdx( this );
		}
		return( rqstTSecGroupDelByTenantVisIdx );
	}

	protected CFIntXMsgRqstTSecGroupDelByUNameIdx getRqstTSecGroupDelByUNameIdx() {
		if( rqstTSecGroupDelByUNameIdx == null ) {
			rqstTSecGroupDelByUNameIdx = new CFIntXMsgRqstTSecGroupDelByUNameIdx( this );
		}
		return( rqstTSecGroupDelByUNameIdx );
	}

	// TSecGrpInc Request  Factories

	protected CFIntXMsgRqstTSecGrpIncCreate getRqstTSecGrpIncCreate() {
		if( rqstTSecGrpIncCreate == null ) {
			rqstTSecGrpIncCreate = new CFIntXMsgRqstTSecGrpIncCreate( this );
		}
		return( rqstTSecGrpIncCreate );
	}

	protected CFIntXMsgRqstTSecGrpIncRead getRqstTSecGrpIncRead() {
		if( rqstTSecGrpIncRead == null ) {
			rqstTSecGrpIncRead = new CFIntXMsgRqstTSecGrpIncRead( this );
		}
		return( rqstTSecGrpIncRead );
	}

	protected CFIntXMsgRqstTSecGrpIncLock getRqstTSecGrpIncLock() {
		if( rqstTSecGrpIncLock == null ) {
			rqstTSecGrpIncLock = new CFIntXMsgRqstTSecGrpIncLock( this );
		}
		return( rqstTSecGrpIncLock );
	}

	protected CFIntXMsgRqstTSecGrpIncUpdate getRqstTSecGrpIncUpdate() {
		if( rqstTSecGrpIncUpdate == null ) {
			rqstTSecGrpIncUpdate = new CFIntXMsgRqstTSecGrpIncUpdate( this );
		}
		return( rqstTSecGrpIncUpdate );
	}

	protected CFIntXMsgRqstTSecGrpIncDelete getRqstTSecGrpIncDelete() {
		if( rqstTSecGrpIncDelete == null ) {
			rqstTSecGrpIncDelete = new CFIntXMsgRqstTSecGrpIncDelete( this );
		}
		return( rqstTSecGrpIncDelete );
	}

	protected CFIntXMsgRqstTSecGrpIncReadAll getRqstTSecGrpIncReadAll() {
		if( rqstTSecGrpIncReadAll == null ) {
			rqstTSecGrpIncReadAll = new CFIntXMsgRqstTSecGrpIncReadAll( this );
		}
		return( rqstTSecGrpIncReadAll );
	}

	protected CFIntXMsgRqstTSecGrpIncPageAll getRqstTSecGrpIncPageAll() {
		if( rqstTSecGrpIncPageAll == null ) {
			rqstTSecGrpIncPageAll = new CFIntXMsgRqstTSecGrpIncPageAll( this );
		}
		return( rqstTSecGrpIncPageAll );
	}

	protected CFIntXMsgRqstTSecGrpIncRdByTenantIdx getRqstTSecGrpIncRdByTenantIdx() {
		if( rqstTSecGrpIncRdByTenantIdx == null ) {
			rqstTSecGrpIncRdByTenantIdx = new CFIntXMsgRqstTSecGrpIncRdByTenantIdx( this );
		}
		return( rqstTSecGrpIncRdByTenantIdx );
	}

	protected CFIntXMsgRqstTSecGrpIncRdByGroupIdx getRqstTSecGrpIncRdByGroupIdx() {
		if( rqstTSecGrpIncRdByGroupIdx == null ) {
			rqstTSecGrpIncRdByGroupIdx = new CFIntXMsgRqstTSecGrpIncRdByGroupIdx( this );
		}
		return( rqstTSecGrpIncRdByGroupIdx );
	}

	protected CFIntXMsgRqstTSecGrpIncRdByIncludeIdx getRqstTSecGrpIncRdByIncludeIdx() {
		if( rqstTSecGrpIncRdByIncludeIdx == null ) {
			rqstTSecGrpIncRdByIncludeIdx = new CFIntXMsgRqstTSecGrpIncRdByIncludeIdx( this );
		}
		return( rqstTSecGrpIncRdByIncludeIdx );
	}

	protected CFIntXMsgRqstTSecGrpIncRdByUIncludeIdx getRqstTSecGrpIncRdByUIncludeIdx() {
		if( rqstTSecGrpIncRdByUIncludeIdx == null ) {
			rqstTSecGrpIncRdByUIncludeIdx = new CFIntXMsgRqstTSecGrpIncRdByUIncludeIdx( this );
		}
		return( rqstTSecGrpIncRdByUIncludeIdx );
	}

	protected CFIntXMsgRqstTSecGrpIncPageByTenantIdx getRqstTSecGrpIncPageByTenantIdx() {
		if( rqstTSecGrpIncPageByTenantIdx == null ) {
			rqstTSecGrpIncPageByTenantIdx = new CFIntXMsgRqstTSecGrpIncPageByTenantIdx( this );
		}
		return( rqstTSecGrpIncPageByTenantIdx );
	}

	protected CFIntXMsgRqstTSecGrpIncPageByGroupIdx getRqstTSecGrpIncPageByGroupIdx() {
		if( rqstTSecGrpIncPageByGroupIdx == null ) {
			rqstTSecGrpIncPageByGroupIdx = new CFIntXMsgRqstTSecGrpIncPageByGroupIdx( this );
		}
		return( rqstTSecGrpIncPageByGroupIdx );
	}

	protected CFIntXMsgRqstTSecGrpIncPageByIncludeIdx getRqstTSecGrpIncPageByIncludeIdx() {
		if( rqstTSecGrpIncPageByIncludeIdx == null ) {
			rqstTSecGrpIncPageByIncludeIdx = new CFIntXMsgRqstTSecGrpIncPageByIncludeIdx( this );
		}
		return( rqstTSecGrpIncPageByIncludeIdx );
	}

	protected CFIntXMsgRqstTSecGrpIncDelByTenantIdx getRqstTSecGrpIncDelByTenantIdx() {
		if( rqstTSecGrpIncDelByTenantIdx == null ) {
			rqstTSecGrpIncDelByTenantIdx = new CFIntXMsgRqstTSecGrpIncDelByTenantIdx( this );
		}
		return( rqstTSecGrpIncDelByTenantIdx );
	}

	protected CFIntXMsgRqstTSecGrpIncDelByGroupIdx getRqstTSecGrpIncDelByGroupIdx() {
		if( rqstTSecGrpIncDelByGroupIdx == null ) {
			rqstTSecGrpIncDelByGroupIdx = new CFIntXMsgRqstTSecGrpIncDelByGroupIdx( this );
		}
		return( rqstTSecGrpIncDelByGroupIdx );
	}

	protected CFIntXMsgRqstTSecGrpIncDelByIncludeIdx getRqstTSecGrpIncDelByIncludeIdx() {
		if( rqstTSecGrpIncDelByIncludeIdx == null ) {
			rqstTSecGrpIncDelByIncludeIdx = new CFIntXMsgRqstTSecGrpIncDelByIncludeIdx( this );
		}
		return( rqstTSecGrpIncDelByIncludeIdx );
	}

	protected CFIntXMsgRqstTSecGrpIncDelByUIncludeIdx getRqstTSecGrpIncDelByUIncludeIdx() {
		if( rqstTSecGrpIncDelByUIncludeIdx == null ) {
			rqstTSecGrpIncDelByUIncludeIdx = new CFIntXMsgRqstTSecGrpIncDelByUIncludeIdx( this );
		}
		return( rqstTSecGrpIncDelByUIncludeIdx );
	}

	// TSecGrpMemb Request  Factories

	protected CFIntXMsgRqstTSecGrpMembCreate getRqstTSecGrpMembCreate() {
		if( rqstTSecGrpMembCreate == null ) {
			rqstTSecGrpMembCreate = new CFIntXMsgRqstTSecGrpMembCreate( this );
		}
		return( rqstTSecGrpMembCreate );
	}

	protected CFIntXMsgRqstTSecGrpMembRead getRqstTSecGrpMembRead() {
		if( rqstTSecGrpMembRead == null ) {
			rqstTSecGrpMembRead = new CFIntXMsgRqstTSecGrpMembRead( this );
		}
		return( rqstTSecGrpMembRead );
	}

	protected CFIntXMsgRqstTSecGrpMembLock getRqstTSecGrpMembLock() {
		if( rqstTSecGrpMembLock == null ) {
			rqstTSecGrpMembLock = new CFIntXMsgRqstTSecGrpMembLock( this );
		}
		return( rqstTSecGrpMembLock );
	}

	protected CFIntXMsgRqstTSecGrpMembUpdate getRqstTSecGrpMembUpdate() {
		if( rqstTSecGrpMembUpdate == null ) {
			rqstTSecGrpMembUpdate = new CFIntXMsgRqstTSecGrpMembUpdate( this );
		}
		return( rqstTSecGrpMembUpdate );
	}

	protected CFIntXMsgRqstTSecGrpMembDelete getRqstTSecGrpMembDelete() {
		if( rqstTSecGrpMembDelete == null ) {
			rqstTSecGrpMembDelete = new CFIntXMsgRqstTSecGrpMembDelete( this );
		}
		return( rqstTSecGrpMembDelete );
	}

	protected CFIntXMsgRqstTSecGrpMembReadAll getRqstTSecGrpMembReadAll() {
		if( rqstTSecGrpMembReadAll == null ) {
			rqstTSecGrpMembReadAll = new CFIntXMsgRqstTSecGrpMembReadAll( this );
		}
		return( rqstTSecGrpMembReadAll );
	}

	protected CFIntXMsgRqstTSecGrpMembPageAll getRqstTSecGrpMembPageAll() {
		if( rqstTSecGrpMembPageAll == null ) {
			rqstTSecGrpMembPageAll = new CFIntXMsgRqstTSecGrpMembPageAll( this );
		}
		return( rqstTSecGrpMembPageAll );
	}

	protected CFIntXMsgRqstTSecGrpMembRdByTenantIdx getRqstTSecGrpMembRdByTenantIdx() {
		if( rqstTSecGrpMembRdByTenantIdx == null ) {
			rqstTSecGrpMembRdByTenantIdx = new CFIntXMsgRqstTSecGrpMembRdByTenantIdx( this );
		}
		return( rqstTSecGrpMembRdByTenantIdx );
	}

	protected CFIntXMsgRqstTSecGrpMembRdByGroupIdx getRqstTSecGrpMembRdByGroupIdx() {
		if( rqstTSecGrpMembRdByGroupIdx == null ) {
			rqstTSecGrpMembRdByGroupIdx = new CFIntXMsgRqstTSecGrpMembRdByGroupIdx( this );
		}
		return( rqstTSecGrpMembRdByGroupIdx );
	}

	protected CFIntXMsgRqstTSecGrpMembRdByUserIdx getRqstTSecGrpMembRdByUserIdx() {
		if( rqstTSecGrpMembRdByUserIdx == null ) {
			rqstTSecGrpMembRdByUserIdx = new CFIntXMsgRqstTSecGrpMembRdByUserIdx( this );
		}
		return( rqstTSecGrpMembRdByUserIdx );
	}

	protected CFIntXMsgRqstTSecGrpMembRdByUUserIdx getRqstTSecGrpMembRdByUUserIdx() {
		if( rqstTSecGrpMembRdByUUserIdx == null ) {
			rqstTSecGrpMembRdByUUserIdx = new CFIntXMsgRqstTSecGrpMembRdByUUserIdx( this );
		}
		return( rqstTSecGrpMembRdByUUserIdx );
	}

	protected CFIntXMsgRqstTSecGrpMembPageByTenantIdx getRqstTSecGrpMembPageByTenantIdx() {
		if( rqstTSecGrpMembPageByTenantIdx == null ) {
			rqstTSecGrpMembPageByTenantIdx = new CFIntXMsgRqstTSecGrpMembPageByTenantIdx( this );
		}
		return( rqstTSecGrpMembPageByTenantIdx );
	}

	protected CFIntXMsgRqstTSecGrpMembPageByGroupIdx getRqstTSecGrpMembPageByGroupIdx() {
		if( rqstTSecGrpMembPageByGroupIdx == null ) {
			rqstTSecGrpMembPageByGroupIdx = new CFIntXMsgRqstTSecGrpMembPageByGroupIdx( this );
		}
		return( rqstTSecGrpMembPageByGroupIdx );
	}

	protected CFIntXMsgRqstTSecGrpMembPageByUserIdx getRqstTSecGrpMembPageByUserIdx() {
		if( rqstTSecGrpMembPageByUserIdx == null ) {
			rqstTSecGrpMembPageByUserIdx = new CFIntXMsgRqstTSecGrpMembPageByUserIdx( this );
		}
		return( rqstTSecGrpMembPageByUserIdx );
	}

	protected CFIntXMsgRqstTSecGrpMembDelByTenantIdx getRqstTSecGrpMembDelByTenantIdx() {
		if( rqstTSecGrpMembDelByTenantIdx == null ) {
			rqstTSecGrpMembDelByTenantIdx = new CFIntXMsgRqstTSecGrpMembDelByTenantIdx( this );
		}
		return( rqstTSecGrpMembDelByTenantIdx );
	}

	protected CFIntXMsgRqstTSecGrpMembDelByGroupIdx getRqstTSecGrpMembDelByGroupIdx() {
		if( rqstTSecGrpMembDelByGroupIdx == null ) {
			rqstTSecGrpMembDelByGroupIdx = new CFIntXMsgRqstTSecGrpMembDelByGroupIdx( this );
		}
		return( rqstTSecGrpMembDelByGroupIdx );
	}

	protected CFIntXMsgRqstTSecGrpMembDelByUserIdx getRqstTSecGrpMembDelByUserIdx() {
		if( rqstTSecGrpMembDelByUserIdx == null ) {
			rqstTSecGrpMembDelByUserIdx = new CFIntXMsgRqstTSecGrpMembDelByUserIdx( this );
		}
		return( rqstTSecGrpMembDelByUserIdx );
	}

	protected CFIntXMsgRqstTSecGrpMembDelByUUserIdx getRqstTSecGrpMembDelByUUserIdx() {
		if( rqstTSecGrpMembDelByUUserIdx == null ) {
			rqstTSecGrpMembDelByUUserIdx = new CFIntXMsgRqstTSecGrpMembDelByUUserIdx( this );
		}
		return( rqstTSecGrpMembDelByUUserIdx );
	}

	// Tenant Request  Factories

	protected CFIntXMsgRqstTenantCreate getRqstTenantCreate() {
		if( rqstTenantCreate == null ) {
			rqstTenantCreate = new CFIntXMsgRqstTenantCreate( this );
		}
		return( rqstTenantCreate );
	}

	protected CFIntXMsgRqstTenantRead getRqstTenantRead() {
		if( rqstTenantRead == null ) {
			rqstTenantRead = new CFIntXMsgRqstTenantRead( this );
		}
		return( rqstTenantRead );
	}

	protected CFIntXMsgRqstTenantLock getRqstTenantLock() {
		if( rqstTenantLock == null ) {
			rqstTenantLock = new CFIntXMsgRqstTenantLock( this );
		}
		return( rqstTenantLock );
	}

	protected CFIntXMsgRqstTenantUpdate getRqstTenantUpdate() {
		if( rqstTenantUpdate == null ) {
			rqstTenantUpdate = new CFIntXMsgRqstTenantUpdate( this );
		}
		return( rqstTenantUpdate );
	}

	protected CFIntXMsgRqstTenantDelete getRqstTenantDelete() {
		if( rqstTenantDelete == null ) {
			rqstTenantDelete = new CFIntXMsgRqstTenantDelete( this );
		}
		return( rqstTenantDelete );
	}

	protected CFIntXMsgRqstTenantReadAll getRqstTenantReadAll() {
		if( rqstTenantReadAll == null ) {
			rqstTenantReadAll = new CFIntXMsgRqstTenantReadAll( this );
		}
		return( rqstTenantReadAll );
	}

	protected CFIntXMsgRqstTenantPageAll getRqstTenantPageAll() {
		if( rqstTenantPageAll == null ) {
			rqstTenantPageAll = new CFIntXMsgRqstTenantPageAll( this );
		}
		return( rqstTenantPageAll );
	}

	protected CFIntXMsgRqstTenantRdByClusterIdx getRqstTenantRdByClusterIdx() {
		if( rqstTenantRdByClusterIdx == null ) {
			rqstTenantRdByClusterIdx = new CFIntXMsgRqstTenantRdByClusterIdx( this );
		}
		return( rqstTenantRdByClusterIdx );
	}

	protected CFIntXMsgRqstTenantRdByUNameIdx getRqstTenantRdByUNameIdx() {
		if( rqstTenantRdByUNameIdx == null ) {
			rqstTenantRdByUNameIdx = new CFIntXMsgRqstTenantRdByUNameIdx( this );
		}
		return( rqstTenantRdByUNameIdx );
	}

	protected CFIntXMsgRqstTenantPageByClusterIdx getRqstTenantPageByClusterIdx() {
		if( rqstTenantPageByClusterIdx == null ) {
			rqstTenantPageByClusterIdx = new CFIntXMsgRqstTenantPageByClusterIdx( this );
		}
		return( rqstTenantPageByClusterIdx );
	}

	protected CFIntXMsgRqstTenantDelByClusterIdx getRqstTenantDelByClusterIdx() {
		if( rqstTenantDelByClusterIdx == null ) {
			rqstTenantDelByClusterIdx = new CFIntXMsgRqstTenantDelByClusterIdx( this );
		}
		return( rqstTenantDelByClusterIdx );
	}

	protected CFIntXMsgRqstTenantDelByUNameIdx getRqstTenantDelByUNameIdx() {
		if( rqstTenantDelByUNameIdx == null ) {
			rqstTenantDelByUNameIdx = new CFIntXMsgRqstTenantDelByUNameIdx( this );
		}
		return( rqstTenantDelByUNameIdx );
	}

	// Tld Request  Factories

	protected CFIntXMsgRqstTldCreate getRqstTldCreate() {
		if( rqstTldCreate == null ) {
			rqstTldCreate = new CFIntXMsgRqstTldCreate( this );
		}
		return( rqstTldCreate );
	}

	protected CFIntXMsgRqstTldRead getRqstTldRead() {
		if( rqstTldRead == null ) {
			rqstTldRead = new CFIntXMsgRqstTldRead( this );
		}
		return( rqstTldRead );
	}

	protected CFIntXMsgRqstTldLock getRqstTldLock() {
		if( rqstTldLock == null ) {
			rqstTldLock = new CFIntXMsgRqstTldLock( this );
		}
		return( rqstTldLock );
	}

	protected CFIntXMsgRqstTldUpdate getRqstTldUpdate() {
		if( rqstTldUpdate == null ) {
			rqstTldUpdate = new CFIntXMsgRqstTldUpdate( this );
		}
		return( rqstTldUpdate );
	}

	protected CFIntXMsgRqstTldDelete getRqstTldDelete() {
		if( rqstTldDelete == null ) {
			rqstTldDelete = new CFIntXMsgRqstTldDelete( this );
		}
		return( rqstTldDelete );
	}

	protected CFIntXMsgRqstTldReadAll getRqstTldReadAll() {
		if( rqstTldReadAll == null ) {
			rqstTldReadAll = new CFIntXMsgRqstTldReadAll( this );
		}
		return( rqstTldReadAll );
	}

	protected CFIntXMsgRqstTldRdByTenantIdx getRqstTldRdByTenantIdx() {
		if( rqstTldRdByTenantIdx == null ) {
			rqstTldRdByTenantIdx = new CFIntXMsgRqstTldRdByTenantIdx( this );
		}
		return( rqstTldRdByTenantIdx );
	}

	protected CFIntXMsgRqstTldRdByNameIdx getRqstTldRdByNameIdx() {
		if( rqstTldRdByNameIdx == null ) {
			rqstTldRdByNameIdx = new CFIntXMsgRqstTldRdByNameIdx( this );
		}
		return( rqstTldRdByNameIdx );
	}

	protected CFIntXMsgRqstTldDelByTenantIdx getRqstTldDelByTenantIdx() {
		if( rqstTldDelByTenantIdx == null ) {
			rqstTldDelByTenantIdx = new CFIntXMsgRqstTldDelByTenantIdx( this );
		}
		return( rqstTldDelByTenantIdx );
	}

	protected CFIntXMsgRqstTldDelByNameIdx getRqstTldDelByNameIdx() {
		if( rqstTldDelByNameIdx == null ) {
			rqstTldDelByNameIdx = new CFIntXMsgRqstTldDelByNameIdx( this );
		}
		return( rqstTldDelByNameIdx );
	}

	// TopDomain Request  Factories

	protected CFIntXMsgRqstTopDomainCreate getRqstTopDomainCreate() {
		if( rqstTopDomainCreate == null ) {
			rqstTopDomainCreate = new CFIntXMsgRqstTopDomainCreate( this );
		}
		return( rqstTopDomainCreate );
	}

	protected CFIntXMsgRqstTopDomainRead getRqstTopDomainRead() {
		if( rqstTopDomainRead == null ) {
			rqstTopDomainRead = new CFIntXMsgRqstTopDomainRead( this );
		}
		return( rqstTopDomainRead );
	}

	protected CFIntXMsgRqstTopDomainLock getRqstTopDomainLock() {
		if( rqstTopDomainLock == null ) {
			rqstTopDomainLock = new CFIntXMsgRqstTopDomainLock( this );
		}
		return( rqstTopDomainLock );
	}

	protected CFIntXMsgRqstTopDomainUpdate getRqstTopDomainUpdate() {
		if( rqstTopDomainUpdate == null ) {
			rqstTopDomainUpdate = new CFIntXMsgRqstTopDomainUpdate( this );
		}
		return( rqstTopDomainUpdate );
	}

	protected CFIntXMsgRqstTopDomainDelete getRqstTopDomainDelete() {
		if( rqstTopDomainDelete == null ) {
			rqstTopDomainDelete = new CFIntXMsgRqstTopDomainDelete( this );
		}
		return( rqstTopDomainDelete );
	}

	protected CFIntXMsgRqstTopDomainReadAll getRqstTopDomainReadAll() {
		if( rqstTopDomainReadAll == null ) {
			rqstTopDomainReadAll = new CFIntXMsgRqstTopDomainReadAll( this );
		}
		return( rqstTopDomainReadAll );
	}

	protected CFIntXMsgRqstTopDomainRdByTenantIdx getRqstTopDomainRdByTenantIdx() {
		if( rqstTopDomainRdByTenantIdx == null ) {
			rqstTopDomainRdByTenantIdx = new CFIntXMsgRqstTopDomainRdByTenantIdx( this );
		}
		return( rqstTopDomainRdByTenantIdx );
	}

	protected CFIntXMsgRqstTopDomainRdByTldIdx getRqstTopDomainRdByTldIdx() {
		if( rqstTopDomainRdByTldIdx == null ) {
			rqstTopDomainRdByTldIdx = new CFIntXMsgRqstTopDomainRdByTldIdx( this );
		}
		return( rqstTopDomainRdByTldIdx );
	}

	protected CFIntXMsgRqstTopDomainRdByNameIdx getRqstTopDomainRdByNameIdx() {
		if( rqstTopDomainRdByNameIdx == null ) {
			rqstTopDomainRdByNameIdx = new CFIntXMsgRqstTopDomainRdByNameIdx( this );
		}
		return( rqstTopDomainRdByNameIdx );
	}

	protected CFIntXMsgRqstTopDomainDelByTenantIdx getRqstTopDomainDelByTenantIdx() {
		if( rqstTopDomainDelByTenantIdx == null ) {
			rqstTopDomainDelByTenantIdx = new CFIntXMsgRqstTopDomainDelByTenantIdx( this );
		}
		return( rqstTopDomainDelByTenantIdx );
	}

	protected CFIntXMsgRqstTopDomainDelByTldIdx getRqstTopDomainDelByTldIdx() {
		if( rqstTopDomainDelByTldIdx == null ) {
			rqstTopDomainDelByTldIdx = new CFIntXMsgRqstTopDomainDelByTldIdx( this );
		}
		return( rqstTopDomainDelByTldIdx );
	}

	protected CFIntXMsgRqstTopDomainDelByNameIdx getRqstTopDomainDelByNameIdx() {
		if( rqstTopDomainDelByNameIdx == null ) {
			rqstTopDomainDelByNameIdx = new CFIntXMsgRqstTopDomainDelByNameIdx( this );
		}
		return( rqstTopDomainDelByNameIdx );
	}

	// TopProject Request  Factories

	protected CFIntXMsgRqstTopProjectCreate getRqstTopProjectCreate() {
		if( rqstTopProjectCreate == null ) {
			rqstTopProjectCreate = new CFIntXMsgRqstTopProjectCreate( this );
		}
		return( rqstTopProjectCreate );
	}

	protected CFIntXMsgRqstTopProjectRead getRqstTopProjectRead() {
		if( rqstTopProjectRead == null ) {
			rqstTopProjectRead = new CFIntXMsgRqstTopProjectRead( this );
		}
		return( rqstTopProjectRead );
	}

	protected CFIntXMsgRqstTopProjectLock getRqstTopProjectLock() {
		if( rqstTopProjectLock == null ) {
			rqstTopProjectLock = new CFIntXMsgRqstTopProjectLock( this );
		}
		return( rqstTopProjectLock );
	}

	protected CFIntXMsgRqstTopProjectUpdate getRqstTopProjectUpdate() {
		if( rqstTopProjectUpdate == null ) {
			rqstTopProjectUpdate = new CFIntXMsgRqstTopProjectUpdate( this );
		}
		return( rqstTopProjectUpdate );
	}

	protected CFIntXMsgRqstTopProjectDelete getRqstTopProjectDelete() {
		if( rqstTopProjectDelete == null ) {
			rqstTopProjectDelete = new CFIntXMsgRqstTopProjectDelete( this );
		}
		return( rqstTopProjectDelete );
	}

	protected CFIntXMsgRqstTopProjectReadAll getRqstTopProjectReadAll() {
		if( rqstTopProjectReadAll == null ) {
			rqstTopProjectReadAll = new CFIntXMsgRqstTopProjectReadAll( this );
		}
		return( rqstTopProjectReadAll );
	}

	protected CFIntXMsgRqstTopProjectRdByTenantIdx getRqstTopProjectRdByTenantIdx() {
		if( rqstTopProjectRdByTenantIdx == null ) {
			rqstTopProjectRdByTenantIdx = new CFIntXMsgRqstTopProjectRdByTenantIdx( this );
		}
		return( rqstTopProjectRdByTenantIdx );
	}

	protected CFIntXMsgRqstTopProjectRdByTopDomainIdx getRqstTopProjectRdByTopDomainIdx() {
		if( rqstTopProjectRdByTopDomainIdx == null ) {
			rqstTopProjectRdByTopDomainIdx = new CFIntXMsgRqstTopProjectRdByTopDomainIdx( this );
		}
		return( rqstTopProjectRdByTopDomainIdx );
	}

	protected CFIntXMsgRqstTopProjectRdByNameIdx getRqstTopProjectRdByNameIdx() {
		if( rqstTopProjectRdByNameIdx == null ) {
			rqstTopProjectRdByNameIdx = new CFIntXMsgRqstTopProjectRdByNameIdx( this );
		}
		return( rqstTopProjectRdByNameIdx );
	}

	protected CFIntXMsgRqstTopProjectDelByTenantIdx getRqstTopProjectDelByTenantIdx() {
		if( rqstTopProjectDelByTenantIdx == null ) {
			rqstTopProjectDelByTenantIdx = new CFIntXMsgRqstTopProjectDelByTenantIdx( this );
		}
		return( rqstTopProjectDelByTenantIdx );
	}

	protected CFIntXMsgRqstTopProjectDelByTopDomainIdx getRqstTopProjectDelByTopDomainIdx() {
		if( rqstTopProjectDelByTopDomainIdx == null ) {
			rqstTopProjectDelByTopDomainIdx = new CFIntXMsgRqstTopProjectDelByTopDomainIdx( this );
		}
		return( rqstTopProjectDelByTopDomainIdx );
	}

	protected CFIntXMsgRqstTopProjectDelByNameIdx getRqstTopProjectDelByNameIdx() {
		if( rqstTopProjectDelByNameIdx == null ) {
			rqstTopProjectDelByNameIdx = new CFIntXMsgRqstTopProjectDelByNameIdx( this );
		}
		return( rqstTopProjectDelByNameIdx );
	}

	// URLProtocol Request  Factories

	protected CFIntXMsgRqstURLProtocolCreate getRqstURLProtocolCreate() {
		if( rqstURLProtocolCreate == null ) {
			rqstURLProtocolCreate = new CFIntXMsgRqstURLProtocolCreate( this );
		}
		return( rqstURLProtocolCreate );
	}

	protected CFIntXMsgRqstURLProtocolRead getRqstURLProtocolRead() {
		if( rqstURLProtocolRead == null ) {
			rqstURLProtocolRead = new CFIntXMsgRqstURLProtocolRead( this );
		}
		return( rqstURLProtocolRead );
	}

	protected CFIntXMsgRqstURLProtocolLock getRqstURLProtocolLock() {
		if( rqstURLProtocolLock == null ) {
			rqstURLProtocolLock = new CFIntXMsgRqstURLProtocolLock( this );
		}
		return( rqstURLProtocolLock );
	}

	protected CFIntXMsgRqstURLProtocolUpdate getRqstURLProtocolUpdate() {
		if( rqstURLProtocolUpdate == null ) {
			rqstURLProtocolUpdate = new CFIntXMsgRqstURLProtocolUpdate( this );
		}
		return( rqstURLProtocolUpdate );
	}

	protected CFIntXMsgRqstURLProtocolDelete getRqstURLProtocolDelete() {
		if( rqstURLProtocolDelete == null ) {
			rqstURLProtocolDelete = new CFIntXMsgRqstURLProtocolDelete( this );
		}
		return( rqstURLProtocolDelete );
	}

	protected CFIntXMsgRqstURLProtocolReadAll getRqstURLProtocolReadAll() {
		if( rqstURLProtocolReadAll == null ) {
			rqstURLProtocolReadAll = new CFIntXMsgRqstURLProtocolReadAll( this );
		}
		return( rqstURLProtocolReadAll );
	}

	protected CFIntXMsgRqstURLProtocolRdByUNameIdx getRqstURLProtocolRdByUNameIdx() {
		if( rqstURLProtocolRdByUNameIdx == null ) {
			rqstURLProtocolRdByUNameIdx = new CFIntXMsgRqstURLProtocolRdByUNameIdx( this );
		}
		return( rqstURLProtocolRdByUNameIdx );
	}

	protected CFIntXMsgRqstURLProtocolRdByIsSecureIdx getRqstURLProtocolRdByIsSecureIdx() {
		if( rqstURLProtocolRdByIsSecureIdx == null ) {
			rqstURLProtocolRdByIsSecureIdx = new CFIntXMsgRqstURLProtocolRdByIsSecureIdx( this );
		}
		return( rqstURLProtocolRdByIsSecureIdx );
	}

	protected CFIntXMsgRqstURLProtocolDelByUNameIdx getRqstURLProtocolDelByUNameIdx() {
		if( rqstURLProtocolDelByUNameIdx == null ) {
			rqstURLProtocolDelByUNameIdx = new CFIntXMsgRqstURLProtocolDelByUNameIdx( this );
		}
		return( rqstURLProtocolDelByUNameIdx );
	}

	protected CFIntXMsgRqstURLProtocolDelByIsSecureIdx getRqstURLProtocolDelByIsSecureIdx() {
		if( rqstURLProtocolDelByIsSecureIdx == null ) {
			rqstURLProtocolDelByIsSecureIdx = new CFIntXMsgRqstURLProtocolDelByIsSecureIdx( this );
		}
		return( rqstURLProtocolDelByIsSecureIdx );
	}

	protected CFIntXMsgRqstFileImport getRqstFileImport() {
		if( rqstFileImport == null ) {
			rqstFileImport = new CFIntXMsgRqstFileImport( this );
		}
		return( rqstFileImport );
	}

	protected CFIntXMsgRqstLogIn getRqstLogIn() {
		if( rqstLogIn == null ) {
			rqstLogIn = new CFIntXMsgRqstLogIn( this );
		}
		return( rqstLogIn );
	}

	protected CFIntXMsgRqstLogOut getRqstLogOut() {
		if( rqstLogOut == null ) {
			rqstLogOut = new CFIntXMsgRqstLogOut( this );
		}
		return( rqstLogOut );
	}

	// Root Element  Resolver Factory

	protected CFIntSaxRqstRoot getSaxRqstRoot() {
		if( saxRoot == null ) {
			saxRoot = new CFIntSaxRqstRoot( this );
			saxRoot.addElementHandler( "CFIntRqst", getSaxRqstDoc() );
			saxRoot.addElementHandler( "CFSecRqst", getSaxRqstDoc() );
		}
		return( saxRoot );
	}

	// Root Element 

	/*
	 *	CFIntSaxRqstRoot XML SAX Root Element  implementation
	 */
	public class CFIntSaxRqstRoot
		extends CFLibXmlCoreElementHandler
	{
		public CFIntSaxRqstRoot( CFIntXMsgRqst xmsgRqst ) {
			super( xmsgRqst );
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

	protected void addClusterToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstClusterCreate", getRqstClusterCreate() );
			saxDoc.addElementHandler( "RqstClusterRead", getRqstClusterRead() );
			saxDoc.addElementHandler( "RqstClusterLock", getRqstClusterLock() );
			saxDoc.addElementHandler( "RqstClusterUpdate", getRqstClusterUpdate() );
			saxDoc.addElementHandler( "RqstClusterDelete", getRqstClusterDelete() );
			saxDoc.addElementHandler( "RqstClusterReadAll", getRqstClusterReadAll() );
			saxDoc.addElementHandler( "RqstClusterPageAll", getRqstClusterPageAll() );
			saxDoc.addElementHandler( "RqstClusterRdByUDomNameIdx", getRqstClusterRdByUDomNameIdx() );
			saxDoc.addElementHandler( "RqstClusterRdByUDescrIdx", getRqstClusterRdByUDescrIdx() );
			saxDoc.addElementHandler( "RqstClusterDelByUDomNameIdx", getRqstClusterDelByUDomNameIdx() );
			saxDoc.addElementHandler( "RqstClusterDelByUDescrIdx", getRqstClusterDelByUDescrIdx() );
	}

	protected void addHostNodeToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstHostNodeCreate", getRqstHostNodeCreate() );
			saxDoc.addElementHandler( "RqstHostNodeRead", getRqstHostNodeRead() );
			saxDoc.addElementHandler( "RqstHostNodeLock", getRqstHostNodeLock() );
			saxDoc.addElementHandler( "RqstHostNodeUpdate", getRqstHostNodeUpdate() );
			saxDoc.addElementHandler( "RqstHostNodeDelete", getRqstHostNodeDelete() );
			saxDoc.addElementHandler( "RqstHostNodeReadAll", getRqstHostNodeReadAll() );
			saxDoc.addElementHandler( "RqstHostNodePageAll", getRqstHostNodePageAll() );
			saxDoc.addElementHandler( "RqstHostNodeRdByClusterIdx", getRqstHostNodeRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstHostNodeRdByUDescrIdx", getRqstHostNodeRdByUDescrIdx() );
			saxDoc.addElementHandler( "RqstHostNodeRdByHostNameIdx", getRqstHostNodeRdByHostNameIdx() );
			saxDoc.addElementHandler( "RqstHostNodePageByClusterIdx", getRqstHostNodePageByClusterIdx() );
			saxDoc.addElementHandler( "RqstHostNodeDelByClusterIdx", getRqstHostNodeDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstHostNodeDelByUDescrIdx", getRqstHostNodeDelByUDescrIdx() );
			saxDoc.addElementHandler( "RqstHostNodeDelByHostNameIdx", getRqstHostNodeDelByHostNameIdx() );
	}

	protected void addISOCcyToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOCcyCreate", getRqstISOCcyCreate() );
			saxDoc.addElementHandler( "RqstISOCcyRead", getRqstISOCcyRead() );
			saxDoc.addElementHandler( "RqstISOCcyLock", getRqstISOCcyLock() );
			saxDoc.addElementHandler( "RqstISOCcyUpdate", getRqstISOCcyUpdate() );
			saxDoc.addElementHandler( "RqstISOCcyDelete", getRqstISOCcyDelete() );
			saxDoc.addElementHandler( "RqstISOCcyReadAll", getRqstISOCcyReadAll() );
			saxDoc.addElementHandler( "RqstISOCcyRdByCcyCdIdx", getRqstISOCcyRdByCcyCdIdx() );
			saxDoc.addElementHandler( "RqstISOCcyRdByCcyNmIdx", getRqstISOCcyRdByCcyNmIdx() );
			saxDoc.addElementHandler( "RqstISOCcyDelByCcyCdIdx", getRqstISOCcyDelByCcyCdIdx() );
			saxDoc.addElementHandler( "RqstISOCcyDelByCcyNmIdx", getRqstISOCcyDelByCcyNmIdx() );
	}

	protected void addISOCtryToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOCtryCreate", getRqstISOCtryCreate() );
			saxDoc.addElementHandler( "RqstISOCtryRead", getRqstISOCtryRead() );
			saxDoc.addElementHandler( "RqstISOCtryLock", getRqstISOCtryLock() );
			saxDoc.addElementHandler( "RqstISOCtryUpdate", getRqstISOCtryUpdate() );
			saxDoc.addElementHandler( "RqstISOCtryDelete", getRqstISOCtryDelete() );
			saxDoc.addElementHandler( "RqstISOCtryReadAll", getRqstISOCtryReadAll() );
			saxDoc.addElementHandler( "RqstISOCtryRdByISOCodeIdx", getRqstISOCtryRdByISOCodeIdx() );
			saxDoc.addElementHandler( "RqstISOCtryRdByNameIdx", getRqstISOCtryRdByNameIdx() );
			saxDoc.addElementHandler( "RqstISOCtryDelByISOCodeIdx", getRqstISOCtryDelByISOCodeIdx() );
			saxDoc.addElementHandler( "RqstISOCtryDelByNameIdx", getRqstISOCtryDelByNameIdx() );
	}

	protected void addISOCtryCcyToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOCtryCcyCreate", getRqstISOCtryCcyCreate() );
			saxDoc.addElementHandler( "RqstISOCtryCcyRead", getRqstISOCtryCcyRead() );
			saxDoc.addElementHandler( "RqstISOCtryCcyLock", getRqstISOCtryCcyLock() );
			saxDoc.addElementHandler( "RqstISOCtryCcyUpdate", getRqstISOCtryCcyUpdate() );
			saxDoc.addElementHandler( "RqstISOCtryCcyDelete", getRqstISOCtryCcyDelete() );
			saxDoc.addElementHandler( "RqstISOCtryCcyReadAll", getRqstISOCtryCcyReadAll() );
			saxDoc.addElementHandler( "RqstISOCtryCcyRdByCtryIdx", getRqstISOCtryCcyRdByCtryIdx() );
			saxDoc.addElementHandler( "RqstISOCtryCcyRdByCcyIdx", getRqstISOCtryCcyRdByCcyIdx() );
			saxDoc.addElementHandler( "RqstISOCtryCcyDelByCtryIdx", getRqstISOCtryCcyDelByCtryIdx() );
			saxDoc.addElementHandler( "RqstISOCtryCcyDelByCcyIdx", getRqstISOCtryCcyDelByCcyIdx() );
	}

	protected void addISOCtryLangToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOCtryLangCreate", getRqstISOCtryLangCreate() );
			saxDoc.addElementHandler( "RqstISOCtryLangRead", getRqstISOCtryLangRead() );
			saxDoc.addElementHandler( "RqstISOCtryLangLock", getRqstISOCtryLangLock() );
			saxDoc.addElementHandler( "RqstISOCtryLangUpdate", getRqstISOCtryLangUpdate() );
			saxDoc.addElementHandler( "RqstISOCtryLangDelete", getRqstISOCtryLangDelete() );
			saxDoc.addElementHandler( "RqstISOCtryLangReadAll", getRqstISOCtryLangReadAll() );
			saxDoc.addElementHandler( "RqstISOCtryLangRdByCtryIdx", getRqstISOCtryLangRdByCtryIdx() );
			saxDoc.addElementHandler( "RqstISOCtryLangRdByLangIdx", getRqstISOCtryLangRdByLangIdx() );
			saxDoc.addElementHandler( "RqstISOCtryLangDelByCtryIdx", getRqstISOCtryLangDelByCtryIdx() );
			saxDoc.addElementHandler( "RqstISOCtryLangDelByLangIdx", getRqstISOCtryLangDelByLangIdx() );
	}

	protected void addISOLangToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOLangCreate", getRqstISOLangCreate() );
			saxDoc.addElementHandler( "RqstISOLangRead", getRqstISOLangRead() );
			saxDoc.addElementHandler( "RqstISOLangLock", getRqstISOLangLock() );
			saxDoc.addElementHandler( "RqstISOLangUpdate", getRqstISOLangUpdate() );
			saxDoc.addElementHandler( "RqstISOLangDelete", getRqstISOLangDelete() );
			saxDoc.addElementHandler( "RqstISOLangReadAll", getRqstISOLangReadAll() );
			saxDoc.addElementHandler( "RqstISOLangRdByCode3Idx", getRqstISOLangRdByCode3Idx() );
			saxDoc.addElementHandler( "RqstISOLangRdByCode2Idx", getRqstISOLangRdByCode2Idx() );
			saxDoc.addElementHandler( "RqstISOLangDelByCode3Idx", getRqstISOLangDelByCode3Idx() );
			saxDoc.addElementHandler( "RqstISOLangDelByCode2Idx", getRqstISOLangDelByCode2Idx() );
	}

	protected void addISOTZoneToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstISOTZoneCreate", getRqstISOTZoneCreate() );
			saxDoc.addElementHandler( "RqstISOTZoneRead", getRqstISOTZoneRead() );
			saxDoc.addElementHandler( "RqstISOTZoneLock", getRqstISOTZoneLock() );
			saxDoc.addElementHandler( "RqstISOTZoneUpdate", getRqstISOTZoneUpdate() );
			saxDoc.addElementHandler( "RqstISOTZoneDelete", getRqstISOTZoneDelete() );
			saxDoc.addElementHandler( "RqstISOTZoneReadAll", getRqstISOTZoneReadAll() );
			saxDoc.addElementHandler( "RqstISOTZoneRdByOffsetIdx", getRqstISOTZoneRdByOffsetIdx() );
			saxDoc.addElementHandler( "RqstISOTZoneRdByUTZNameIdx", getRqstISOTZoneRdByUTZNameIdx() );
			saxDoc.addElementHandler( "RqstISOTZoneRdByIso8601Idx", getRqstISOTZoneRdByIso8601Idx() );
			saxDoc.addElementHandler( "RqstISOTZoneDelByOffsetIdx", getRqstISOTZoneDelByOffsetIdx() );
			saxDoc.addElementHandler( "RqstISOTZoneDelByUTZNameIdx", getRqstISOTZoneDelByUTZNameIdx() );
			saxDoc.addElementHandler( "RqstISOTZoneDelByIso8601Idx", getRqstISOTZoneDelByIso8601Idx() );
	}

	protected void addLicenseToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstLicenseCreate", getRqstLicenseCreate() );
			saxDoc.addElementHandler( "RqstLicenseRead", getRqstLicenseRead() );
			saxDoc.addElementHandler( "RqstLicenseLock", getRqstLicenseLock() );
			saxDoc.addElementHandler( "RqstLicenseUpdate", getRqstLicenseUpdate() );
			saxDoc.addElementHandler( "RqstLicenseDelete", getRqstLicenseDelete() );
			saxDoc.addElementHandler( "RqstLicenseReadAll", getRqstLicenseReadAll() );
			saxDoc.addElementHandler( "RqstLicenseRdByLicnTenantIdx", getRqstLicenseRdByLicnTenantIdx() );
			saxDoc.addElementHandler( "RqstLicenseRdByDomainIdx", getRqstLicenseRdByDomainIdx() );
			saxDoc.addElementHandler( "RqstLicenseRdByUNameIdx", getRqstLicenseRdByUNameIdx() );
			saxDoc.addElementHandler( "RqstLicenseDelByLicnTenantIdx", getRqstLicenseDelByLicnTenantIdx() );
			saxDoc.addElementHandler( "RqstLicenseDelByDomainIdx", getRqstLicenseDelByDomainIdx() );
			saxDoc.addElementHandler( "RqstLicenseDelByUNameIdx", getRqstLicenseDelByUNameIdx() );
	}

	protected void addMajorVersionToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstMajorVersionCreate", getRqstMajorVersionCreate() );
			saxDoc.addElementHandler( "RqstMajorVersionRead", getRqstMajorVersionRead() );
			saxDoc.addElementHandler( "RqstMajorVersionLock", getRqstMajorVersionLock() );
			saxDoc.addElementHandler( "RqstMajorVersionUpdate", getRqstMajorVersionUpdate() );
			saxDoc.addElementHandler( "RqstMajorVersionDelete", getRqstMajorVersionDelete() );
			saxDoc.addElementHandler( "RqstMajorVersionReadAll", getRqstMajorVersionReadAll() );
			saxDoc.addElementHandler( "RqstMajorVersionRdByTenantIdx", getRqstMajorVersionRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstMajorVersionRdBySubProjectIdx", getRqstMajorVersionRdBySubProjectIdx() );
			saxDoc.addElementHandler( "RqstMajorVersionRdByNameIdx", getRqstMajorVersionRdByNameIdx() );
			saxDoc.addElementHandler( "RqstMajorVersionDelByTenantIdx", getRqstMajorVersionDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstMajorVersionDelBySubProjectIdx", getRqstMajorVersionDelBySubProjectIdx() );
			saxDoc.addElementHandler( "RqstMajorVersionDelByNameIdx", getRqstMajorVersionDelByNameIdx() );
	}

	protected void addMimeTypeToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstMimeTypeCreate", getRqstMimeTypeCreate() );
			saxDoc.addElementHandler( "RqstMimeTypeRead", getRqstMimeTypeRead() );
			saxDoc.addElementHandler( "RqstMimeTypeLock", getRqstMimeTypeLock() );
			saxDoc.addElementHandler( "RqstMimeTypeUpdate", getRqstMimeTypeUpdate() );
			saxDoc.addElementHandler( "RqstMimeTypeDelete", getRqstMimeTypeDelete() );
			saxDoc.addElementHandler( "RqstMimeTypeReadAll", getRqstMimeTypeReadAll() );
			saxDoc.addElementHandler( "RqstMimeTypeRdByUNameIdx", getRqstMimeTypeRdByUNameIdx() );
			saxDoc.addElementHandler( "RqstMimeTypeDelByUNameIdx", getRqstMimeTypeDelByUNameIdx() );
	}

	protected void addMinorVersionToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstMinorVersionCreate", getRqstMinorVersionCreate() );
			saxDoc.addElementHandler( "RqstMinorVersionRead", getRqstMinorVersionRead() );
			saxDoc.addElementHandler( "RqstMinorVersionLock", getRqstMinorVersionLock() );
			saxDoc.addElementHandler( "RqstMinorVersionUpdate", getRqstMinorVersionUpdate() );
			saxDoc.addElementHandler( "RqstMinorVersionDelete", getRqstMinorVersionDelete() );
			saxDoc.addElementHandler( "RqstMinorVersionReadAll", getRqstMinorVersionReadAll() );
			saxDoc.addElementHandler( "RqstMinorVersionRdByTenantIdx", getRqstMinorVersionRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstMinorVersionRdByMajorVerIdx", getRqstMinorVersionRdByMajorVerIdx() );
			saxDoc.addElementHandler( "RqstMinorVersionRdByNameIdx", getRqstMinorVersionRdByNameIdx() );
			saxDoc.addElementHandler( "RqstMinorVersionDelByTenantIdx", getRqstMinorVersionDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstMinorVersionDelByMajorVerIdx", getRqstMinorVersionDelByMajorVerIdx() );
			saxDoc.addElementHandler( "RqstMinorVersionDelByNameIdx", getRqstMinorVersionDelByNameIdx() );
	}

	protected void addSecAppToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecAppCreate", getRqstSecAppCreate() );
			saxDoc.addElementHandler( "RqstSecAppRead", getRqstSecAppRead() );
			saxDoc.addElementHandler( "RqstSecAppLock", getRqstSecAppLock() );
			saxDoc.addElementHandler( "RqstSecAppUpdate", getRqstSecAppUpdate() );
			saxDoc.addElementHandler( "RqstSecAppDelete", getRqstSecAppDelete() );
			saxDoc.addElementHandler( "RqstSecAppReadAll", getRqstSecAppReadAll() );
			saxDoc.addElementHandler( "RqstSecAppPageAll", getRqstSecAppPageAll() );
			saxDoc.addElementHandler( "RqstSecAppRdByClusterIdx", getRqstSecAppRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecAppRdByUJEEMountIdx", getRqstSecAppRdByUJEEMountIdx() );
			saxDoc.addElementHandler( "RqstSecAppPageByClusterIdx", getRqstSecAppPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecAppDelByClusterIdx", getRqstSecAppDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecAppDelByUJEEMountIdx", getRqstSecAppDelByUJEEMountIdx() );
	}

	protected void addSecDeviceToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecDeviceCreate", getRqstSecDeviceCreate() );
			saxDoc.addElementHandler( "RqstSecDeviceRead", getRqstSecDeviceRead() );
			saxDoc.addElementHandler( "RqstSecDeviceLock", getRqstSecDeviceLock() );
			saxDoc.addElementHandler( "RqstSecDeviceUpdate", getRqstSecDeviceUpdate() );
			saxDoc.addElementHandler( "RqstSecDeviceDelete", getRqstSecDeviceDelete() );
			saxDoc.addElementHandler( "RqstSecDeviceReadAll", getRqstSecDeviceReadAll() );
			saxDoc.addElementHandler( "RqstSecDevicePageAll", getRqstSecDevicePageAll() );
			saxDoc.addElementHandler( "RqstSecDeviceRdByNameIdx", getRqstSecDeviceRdByNameIdx() );
			saxDoc.addElementHandler( "RqstSecDeviceRdByUserIdx", getRqstSecDeviceRdByUserIdx() );
			saxDoc.addElementHandler( "RqstSecDevicePageByUserIdx", getRqstSecDevicePageByUserIdx() );
			saxDoc.addElementHandler( "RqstSecDeviceDelByNameIdx", getRqstSecDeviceDelByNameIdx() );
			saxDoc.addElementHandler( "RqstSecDeviceDelByUserIdx", getRqstSecDeviceDelByUserIdx() );
	}

	protected void addSecFormToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecFormCreate", getRqstSecFormCreate() );
			saxDoc.addElementHandler( "RqstSecFormRead", getRqstSecFormRead() );
			saxDoc.addElementHandler( "RqstSecFormLock", getRqstSecFormLock() );
			saxDoc.addElementHandler( "RqstSecFormUpdate", getRqstSecFormUpdate() );
			saxDoc.addElementHandler( "RqstSecFormDelete", getRqstSecFormDelete() );
			saxDoc.addElementHandler( "RqstSecFormReadAll", getRqstSecFormReadAll() );
			saxDoc.addElementHandler( "RqstSecFormPageAll", getRqstSecFormPageAll() );
			saxDoc.addElementHandler( "RqstSecFormRdByClusterIdx", getRqstSecFormRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecFormRdBySecAppIdx", getRqstSecFormRdBySecAppIdx() );
			saxDoc.addElementHandler( "RqstSecFormRdByUJEEServletIdx", getRqstSecFormRdByUJEEServletIdx() );
			saxDoc.addElementHandler( "RqstSecFormPageByClusterIdx", getRqstSecFormPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecFormPageBySecAppIdx", getRqstSecFormPageBySecAppIdx() );
			saxDoc.addElementHandler( "RqstSecFormDelByClusterIdx", getRqstSecFormDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecFormDelBySecAppIdx", getRqstSecFormDelBySecAppIdx() );
			saxDoc.addElementHandler( "RqstSecFormDelByUJEEServletIdx", getRqstSecFormDelByUJEEServletIdx() );
	}

	protected void addSecGroupToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecGroupCreate", getRqstSecGroupCreate() );
			saxDoc.addElementHandler( "RqstSecGroupRead", getRqstSecGroupRead() );
			saxDoc.addElementHandler( "RqstSecGroupLock", getRqstSecGroupLock() );
			saxDoc.addElementHandler( "RqstSecGroupUpdate", getRqstSecGroupUpdate() );
			saxDoc.addElementHandler( "RqstSecGroupDelete", getRqstSecGroupDelete() );
			saxDoc.addElementHandler( "RqstSecGroupReadAll", getRqstSecGroupReadAll() );
			saxDoc.addElementHandler( "RqstSecGroupRdByClusterIdx", getRqstSecGroupRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGroupRdByClusterVisIdx", getRqstSecGroupRdByClusterVisIdx() );
			saxDoc.addElementHandler( "RqstSecGroupRdByUNameIdx", getRqstSecGroupRdByUNameIdx() );
			saxDoc.addElementHandler( "RqstSecGroupDelByClusterIdx", getRqstSecGroupDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGroupDelByClusterVisIdx", getRqstSecGroupDelByClusterVisIdx() );
			saxDoc.addElementHandler( "RqstSecGroupDelByUNameIdx", getRqstSecGroupDelByUNameIdx() );
	}

	protected void addSecGroupFormToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecGroupFormCreate", getRqstSecGroupFormCreate() );
			saxDoc.addElementHandler( "RqstSecGroupFormRead", getRqstSecGroupFormRead() );
			saxDoc.addElementHandler( "RqstSecGroupFormLock", getRqstSecGroupFormLock() );
			saxDoc.addElementHandler( "RqstSecGroupFormUpdate", getRqstSecGroupFormUpdate() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelete", getRqstSecGroupFormDelete() );
			saxDoc.addElementHandler( "RqstSecGroupFormReadAll", getRqstSecGroupFormReadAll() );
			saxDoc.addElementHandler( "RqstSecGroupFormPageAll", getRqstSecGroupFormPageAll() );
			saxDoc.addElementHandler( "RqstSecGroupFormRdByClusterIdx", getRqstSecGroupFormRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormRdByGroupIdx", getRqstSecGroupFormRdByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormRdByAppIdx", getRqstSecGroupFormRdByAppIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormRdByFormIdx", getRqstSecGroupFormRdByFormIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormRdByUFormIdx", getRqstSecGroupFormRdByUFormIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormPageByClusterIdx", getRqstSecGroupFormPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormPageByGroupIdx", getRqstSecGroupFormPageByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormPageByAppIdx", getRqstSecGroupFormPageByAppIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormPageByFormIdx", getRqstSecGroupFormPageByFormIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelByClusterIdx", getRqstSecGroupFormDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelByGroupIdx", getRqstSecGroupFormDelByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelByAppIdx", getRqstSecGroupFormDelByAppIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelByFormIdx", getRqstSecGroupFormDelByFormIdx() );
			saxDoc.addElementHandler( "RqstSecGroupFormDelByUFormIdx", getRqstSecGroupFormDelByUFormIdx() );
	}

	protected void addSecGrpIncToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecGrpIncCreate", getRqstSecGrpIncCreate() );
			saxDoc.addElementHandler( "RqstSecGrpIncRead", getRqstSecGrpIncRead() );
			saxDoc.addElementHandler( "RqstSecGrpIncLock", getRqstSecGrpIncLock() );
			saxDoc.addElementHandler( "RqstSecGrpIncUpdate", getRqstSecGrpIncUpdate() );
			saxDoc.addElementHandler( "RqstSecGrpIncDelete", getRqstSecGrpIncDelete() );
			saxDoc.addElementHandler( "RqstSecGrpIncReadAll", getRqstSecGrpIncReadAll() );
			saxDoc.addElementHandler( "RqstSecGrpIncPageAll", getRqstSecGrpIncPageAll() );
			saxDoc.addElementHandler( "RqstSecGrpIncRdByClusterIdx", getRqstSecGrpIncRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncRdByGroupIdx", getRqstSecGrpIncRdByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncRdByIncludeIdx", getRqstSecGrpIncRdByIncludeIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncRdByUIncludeIdx", getRqstSecGrpIncRdByUIncludeIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncPageByClusterIdx", getRqstSecGrpIncPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncPageByGroupIdx", getRqstSecGrpIncPageByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncPageByIncludeIdx", getRqstSecGrpIncPageByIncludeIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncDelByClusterIdx", getRqstSecGrpIncDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncDelByGroupIdx", getRqstSecGrpIncDelByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncDelByIncludeIdx", getRqstSecGrpIncDelByIncludeIdx() );
			saxDoc.addElementHandler( "RqstSecGrpIncDelByUIncludeIdx", getRqstSecGrpIncDelByUIncludeIdx() );
	}

	protected void addSecGrpMembToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecGrpMembCreate", getRqstSecGrpMembCreate() );
			saxDoc.addElementHandler( "RqstSecGrpMembRead", getRqstSecGrpMembRead() );
			saxDoc.addElementHandler( "RqstSecGrpMembLock", getRqstSecGrpMembLock() );
			saxDoc.addElementHandler( "RqstSecGrpMembUpdate", getRqstSecGrpMembUpdate() );
			saxDoc.addElementHandler( "RqstSecGrpMembDelete", getRqstSecGrpMembDelete() );
			saxDoc.addElementHandler( "RqstSecGrpMembReadAll", getRqstSecGrpMembReadAll() );
			saxDoc.addElementHandler( "RqstSecGrpMembPageAll", getRqstSecGrpMembPageAll() );
			saxDoc.addElementHandler( "RqstSecGrpMembRdByClusterIdx", getRqstSecGrpMembRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembRdByGroupIdx", getRqstSecGrpMembRdByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembRdByUserIdx", getRqstSecGrpMembRdByUserIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembRdByUUserIdx", getRqstSecGrpMembRdByUUserIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembPageByClusterIdx", getRqstSecGrpMembPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembPageByGroupIdx", getRqstSecGrpMembPageByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembPageByUserIdx", getRqstSecGrpMembPageByUserIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembDelByClusterIdx", getRqstSecGrpMembDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembDelByGroupIdx", getRqstSecGrpMembDelByGroupIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembDelByUserIdx", getRqstSecGrpMembDelByUserIdx() );
			saxDoc.addElementHandler( "RqstSecGrpMembDelByUUserIdx", getRqstSecGrpMembDelByUUserIdx() );
	}

	protected void addSecSessionToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecSessionCreate", getRqstSecSessionCreate() );
			saxDoc.addElementHandler( "RqstSecSessionRead", getRqstSecSessionRead() );
			saxDoc.addElementHandler( "RqstSecSessionLock", getRqstSecSessionLock() );
			saxDoc.addElementHandler( "RqstSecSessionUpdate", getRqstSecSessionUpdate() );
			saxDoc.addElementHandler( "RqstSecSessionDelete", getRqstSecSessionDelete() );
			saxDoc.addElementHandler( "RqstSecSessionReadAll", getRqstSecSessionReadAll() );
			saxDoc.addElementHandler( "RqstSecSessionPageAll", getRqstSecSessionPageAll() );
			saxDoc.addElementHandler( "RqstSecSessionRdBySecUserIdx", getRqstSecSessionRdBySecUserIdx() );
			saxDoc.addElementHandler( "RqstSecSessionRdBySecDevIdx", getRqstSecSessionRdBySecDevIdx() );
			saxDoc.addElementHandler( "RqstSecSessionRdByStartIdx", getRqstSecSessionRdByStartIdx() );
			saxDoc.addElementHandler( "RqstSecSessionRdByFinishIdx", getRqstSecSessionRdByFinishIdx() );
			saxDoc.addElementHandler( "RqstSecSessionRdBySecProxyIdx", getRqstSecSessionRdBySecProxyIdx() );
			saxDoc.addElementHandler( "RqstSecSessionPageBySecUserIdx", getRqstSecSessionPageBySecUserIdx() );
			saxDoc.addElementHandler( "RqstSecSessionPageBySecDevIdx", getRqstSecSessionPageBySecDevIdx() );
			saxDoc.addElementHandler( "RqstSecSessionPageByFinishIdx", getRqstSecSessionPageByFinishIdx() );
			saxDoc.addElementHandler( "RqstSecSessionPageBySecProxyIdx", getRqstSecSessionPageBySecProxyIdx() );
			saxDoc.addElementHandler( "RqstSecSessionDelBySecUserIdx", getRqstSecSessionDelBySecUserIdx() );
			saxDoc.addElementHandler( "RqstSecSessionDelBySecDevIdx", getRqstSecSessionDelBySecDevIdx() );
			saxDoc.addElementHandler( "RqstSecSessionDelByStartIdx", getRqstSecSessionDelByStartIdx() );
			saxDoc.addElementHandler( "RqstSecSessionDelByFinishIdx", getRqstSecSessionDelByFinishIdx() );
			saxDoc.addElementHandler( "RqstSecSessionDelBySecProxyIdx", getRqstSecSessionDelBySecProxyIdx() );
	}

	protected void addSecUserToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSecUserCreate", getRqstSecUserCreate() );
			saxDoc.addElementHandler( "RqstSecUserRead", getRqstSecUserRead() );
			saxDoc.addElementHandler( "RqstSecUserLock", getRqstSecUserLock() );
			saxDoc.addElementHandler( "RqstSecUserUpdate", getRqstSecUserUpdate() );
			saxDoc.addElementHandler( "RqstSecUserDelete", getRqstSecUserDelete() );
			saxDoc.addElementHandler( "RqstSecUserReadAll", getRqstSecUserReadAll() );
			saxDoc.addElementHandler( "RqstSecUserPageAll", getRqstSecUserPageAll() );
			saxDoc.addElementHandler( "RqstSecUserRdByULoginIdx", getRqstSecUserRdByULoginIdx() );
			saxDoc.addElementHandler( "RqstSecUserRdByEMConfIdx", getRqstSecUserRdByEMConfIdx() );
			saxDoc.addElementHandler( "RqstSecUserRdByPwdResetIdx", getRqstSecUserRdByPwdResetIdx() );
			saxDoc.addElementHandler( "RqstSecUserRdByDefDevIdx", getRqstSecUserRdByDefDevIdx() );
			saxDoc.addElementHandler( "RqstSecUserPageByEMConfIdx", getRqstSecUserPageByEMConfIdx() );
			saxDoc.addElementHandler( "RqstSecUserPageByPwdResetIdx", getRqstSecUserPageByPwdResetIdx() );
			saxDoc.addElementHandler( "RqstSecUserPageByDefDevIdx", getRqstSecUserPageByDefDevIdx() );
			saxDoc.addElementHandler( "RqstSecUserDelByULoginIdx", getRqstSecUserDelByULoginIdx() );
			saxDoc.addElementHandler( "RqstSecUserDelByEMConfIdx", getRqstSecUserDelByEMConfIdx() );
			saxDoc.addElementHandler( "RqstSecUserDelByPwdResetIdx", getRqstSecUserDelByPwdResetIdx() );
			saxDoc.addElementHandler( "RqstSecUserDelByDefDevIdx", getRqstSecUserDelByDefDevIdx() );
	}

	protected void addServiceToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstServiceCreate", getRqstServiceCreate() );
			saxDoc.addElementHandler( "RqstServiceRead", getRqstServiceRead() );
			saxDoc.addElementHandler( "RqstServiceLock", getRqstServiceLock() );
			saxDoc.addElementHandler( "RqstServiceUpdate", getRqstServiceUpdate() );
			saxDoc.addElementHandler( "RqstServiceDelete", getRqstServiceDelete() );
			saxDoc.addElementHandler( "RqstServiceReadAll", getRqstServiceReadAll() );
			saxDoc.addElementHandler( "RqstServicePageAll", getRqstServicePageAll() );
			saxDoc.addElementHandler( "RqstServiceRdByClusterIdx", getRqstServiceRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstServiceRdByHostIdx", getRqstServiceRdByHostIdx() );
			saxDoc.addElementHandler( "RqstServiceRdByTypeIdx", getRqstServiceRdByTypeIdx() );
			saxDoc.addElementHandler( "RqstServiceRdByUTypeIdx", getRqstServiceRdByUTypeIdx() );
			saxDoc.addElementHandler( "RqstServiceRdByUHostPortIdx", getRqstServiceRdByUHostPortIdx() );
			saxDoc.addElementHandler( "RqstServicePageByClusterIdx", getRqstServicePageByClusterIdx() );
			saxDoc.addElementHandler( "RqstServicePageByHostIdx", getRqstServicePageByHostIdx() );
			saxDoc.addElementHandler( "RqstServicePageByTypeIdx", getRqstServicePageByTypeIdx() );
			saxDoc.addElementHandler( "RqstServiceDelByClusterIdx", getRqstServiceDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstServiceDelByHostIdx", getRqstServiceDelByHostIdx() );
			saxDoc.addElementHandler( "RqstServiceDelByTypeIdx", getRqstServiceDelByTypeIdx() );
			saxDoc.addElementHandler( "RqstServiceDelByUTypeIdx", getRqstServiceDelByUTypeIdx() );
			saxDoc.addElementHandler( "RqstServiceDelByUHostPortIdx", getRqstServiceDelByUHostPortIdx() );
	}

	protected void addServiceTypeToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstServiceTypeCreate", getRqstServiceTypeCreate() );
			saxDoc.addElementHandler( "RqstServiceTypeRead", getRqstServiceTypeRead() );
			saxDoc.addElementHandler( "RqstServiceTypeLock", getRqstServiceTypeLock() );
			saxDoc.addElementHandler( "RqstServiceTypeUpdate", getRqstServiceTypeUpdate() );
			saxDoc.addElementHandler( "RqstServiceTypeDelete", getRqstServiceTypeDelete() );
			saxDoc.addElementHandler( "RqstServiceTypeReadAll", getRqstServiceTypeReadAll() );
			saxDoc.addElementHandler( "RqstServiceTypeRdByUDescrIdx", getRqstServiceTypeRdByUDescrIdx() );
			saxDoc.addElementHandler( "RqstServiceTypeDelByUDescrIdx", getRqstServiceTypeDelByUDescrIdx() );
	}

	protected void addSubProjectToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSubProjectCreate", getRqstSubProjectCreate() );
			saxDoc.addElementHandler( "RqstSubProjectRead", getRqstSubProjectRead() );
			saxDoc.addElementHandler( "RqstSubProjectLock", getRqstSubProjectLock() );
			saxDoc.addElementHandler( "RqstSubProjectUpdate", getRqstSubProjectUpdate() );
			saxDoc.addElementHandler( "RqstSubProjectDelete", getRqstSubProjectDelete() );
			saxDoc.addElementHandler( "RqstSubProjectReadAll", getRqstSubProjectReadAll() );
			saxDoc.addElementHandler( "RqstSubProjectRdByTenantIdx", getRqstSubProjectRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstSubProjectRdByTopProjectIdx", getRqstSubProjectRdByTopProjectIdx() );
			saxDoc.addElementHandler( "RqstSubProjectRdByNameIdx", getRqstSubProjectRdByNameIdx() );
			saxDoc.addElementHandler( "RqstSubProjectDelByTenantIdx", getRqstSubProjectDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstSubProjectDelByTopProjectIdx", getRqstSubProjectDelByTopProjectIdx() );
			saxDoc.addElementHandler( "RqstSubProjectDelByNameIdx", getRqstSubProjectDelByNameIdx() );
	}

	protected void addSysClusterToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstSysClusterCreate", getRqstSysClusterCreate() );
			saxDoc.addElementHandler( "RqstSysClusterRead", getRqstSysClusterRead() );
			saxDoc.addElementHandler( "RqstSysClusterLock", getRqstSysClusterLock() );
			saxDoc.addElementHandler( "RqstSysClusterUpdate", getRqstSysClusterUpdate() );
			saxDoc.addElementHandler( "RqstSysClusterDelete", getRqstSysClusterDelete() );
			saxDoc.addElementHandler( "RqstSysClusterReadAll", getRqstSysClusterReadAll() );
			saxDoc.addElementHandler( "RqstSysClusterRdByClusterIdx", getRqstSysClusterRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstSysClusterDelByClusterIdx", getRqstSysClusterDelByClusterIdx() );
	}

	protected void addTSecGroupToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstTSecGroupCreate", getRqstTSecGroupCreate() );
			saxDoc.addElementHandler( "RqstTSecGroupRead", getRqstTSecGroupRead() );
			saxDoc.addElementHandler( "RqstTSecGroupLock", getRqstTSecGroupLock() );
			saxDoc.addElementHandler( "RqstTSecGroupUpdate", getRqstTSecGroupUpdate() );
			saxDoc.addElementHandler( "RqstTSecGroupDelete", getRqstTSecGroupDelete() );
			saxDoc.addElementHandler( "RqstTSecGroupReadAll", getRqstTSecGroupReadAll() );
			saxDoc.addElementHandler( "RqstTSecGroupRdByTenantIdx", getRqstTSecGroupRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGroupRdByTenantVisIdx", getRqstTSecGroupRdByTenantVisIdx() );
			saxDoc.addElementHandler( "RqstTSecGroupRdByUNameIdx", getRqstTSecGroupRdByUNameIdx() );
			saxDoc.addElementHandler( "RqstTSecGroupDelByTenantIdx", getRqstTSecGroupDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGroupDelByTenantVisIdx", getRqstTSecGroupDelByTenantVisIdx() );
			saxDoc.addElementHandler( "RqstTSecGroupDelByUNameIdx", getRqstTSecGroupDelByUNameIdx() );
	}

	protected void addTSecGrpIncToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstTSecGrpIncCreate", getRqstTSecGrpIncCreate() );
			saxDoc.addElementHandler( "RqstTSecGrpIncRead", getRqstTSecGrpIncRead() );
			saxDoc.addElementHandler( "RqstTSecGrpIncLock", getRqstTSecGrpIncLock() );
			saxDoc.addElementHandler( "RqstTSecGrpIncUpdate", getRqstTSecGrpIncUpdate() );
			saxDoc.addElementHandler( "RqstTSecGrpIncDelete", getRqstTSecGrpIncDelete() );
			saxDoc.addElementHandler( "RqstTSecGrpIncReadAll", getRqstTSecGrpIncReadAll() );
			saxDoc.addElementHandler( "RqstTSecGrpIncPageAll", getRqstTSecGrpIncPageAll() );
			saxDoc.addElementHandler( "RqstTSecGrpIncRdByTenantIdx", getRqstTSecGrpIncRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncRdByGroupIdx", getRqstTSecGrpIncRdByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncRdByIncludeIdx", getRqstTSecGrpIncRdByIncludeIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncRdByUIncludeIdx", getRqstTSecGrpIncRdByUIncludeIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncPageByTenantIdx", getRqstTSecGrpIncPageByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncPageByGroupIdx", getRqstTSecGrpIncPageByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncPageByIncludeIdx", getRqstTSecGrpIncPageByIncludeIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncDelByTenantIdx", getRqstTSecGrpIncDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncDelByGroupIdx", getRqstTSecGrpIncDelByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncDelByIncludeIdx", getRqstTSecGrpIncDelByIncludeIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpIncDelByUIncludeIdx", getRqstTSecGrpIncDelByUIncludeIdx() );
	}

	protected void addTSecGrpMembToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstTSecGrpMembCreate", getRqstTSecGrpMembCreate() );
			saxDoc.addElementHandler( "RqstTSecGrpMembRead", getRqstTSecGrpMembRead() );
			saxDoc.addElementHandler( "RqstTSecGrpMembLock", getRqstTSecGrpMembLock() );
			saxDoc.addElementHandler( "RqstTSecGrpMembUpdate", getRqstTSecGrpMembUpdate() );
			saxDoc.addElementHandler( "RqstTSecGrpMembDelete", getRqstTSecGrpMembDelete() );
			saxDoc.addElementHandler( "RqstTSecGrpMembReadAll", getRqstTSecGrpMembReadAll() );
			saxDoc.addElementHandler( "RqstTSecGrpMembPageAll", getRqstTSecGrpMembPageAll() );
			saxDoc.addElementHandler( "RqstTSecGrpMembRdByTenantIdx", getRqstTSecGrpMembRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembRdByGroupIdx", getRqstTSecGrpMembRdByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembRdByUserIdx", getRqstTSecGrpMembRdByUserIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembRdByUUserIdx", getRqstTSecGrpMembRdByUUserIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembPageByTenantIdx", getRqstTSecGrpMembPageByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembPageByGroupIdx", getRqstTSecGrpMembPageByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembPageByUserIdx", getRqstTSecGrpMembPageByUserIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembDelByTenantIdx", getRqstTSecGrpMembDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembDelByGroupIdx", getRqstTSecGrpMembDelByGroupIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembDelByUserIdx", getRqstTSecGrpMembDelByUserIdx() );
			saxDoc.addElementHandler( "RqstTSecGrpMembDelByUUserIdx", getRqstTSecGrpMembDelByUUserIdx() );
	}

	protected void addTenantToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstTenantCreate", getRqstTenantCreate() );
			saxDoc.addElementHandler( "RqstTenantRead", getRqstTenantRead() );
			saxDoc.addElementHandler( "RqstTenantLock", getRqstTenantLock() );
			saxDoc.addElementHandler( "RqstTenantUpdate", getRqstTenantUpdate() );
			saxDoc.addElementHandler( "RqstTenantDelete", getRqstTenantDelete() );
			saxDoc.addElementHandler( "RqstTenantReadAll", getRqstTenantReadAll() );
			saxDoc.addElementHandler( "RqstTenantPageAll", getRqstTenantPageAll() );
			saxDoc.addElementHandler( "RqstTenantRdByClusterIdx", getRqstTenantRdByClusterIdx() );
			saxDoc.addElementHandler( "RqstTenantRdByUNameIdx", getRqstTenantRdByUNameIdx() );
			saxDoc.addElementHandler( "RqstTenantPageByClusterIdx", getRqstTenantPageByClusterIdx() );
			saxDoc.addElementHandler( "RqstTenantDelByClusterIdx", getRqstTenantDelByClusterIdx() );
			saxDoc.addElementHandler( "RqstTenantDelByUNameIdx", getRqstTenantDelByUNameIdx() );
	}

	protected void addTldToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstTldCreate", getRqstTldCreate() );
			saxDoc.addElementHandler( "RqstTldRead", getRqstTldRead() );
			saxDoc.addElementHandler( "RqstTldLock", getRqstTldLock() );
			saxDoc.addElementHandler( "RqstTldUpdate", getRqstTldUpdate() );
			saxDoc.addElementHandler( "RqstTldDelete", getRqstTldDelete() );
			saxDoc.addElementHandler( "RqstTldReadAll", getRqstTldReadAll() );
			saxDoc.addElementHandler( "RqstTldRdByTenantIdx", getRqstTldRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstTldRdByNameIdx", getRqstTldRdByNameIdx() );
			saxDoc.addElementHandler( "RqstTldDelByTenantIdx", getRqstTldDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstTldDelByNameIdx", getRqstTldDelByNameIdx() );
	}

	protected void addTopDomainToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstTopDomainCreate", getRqstTopDomainCreate() );
			saxDoc.addElementHandler( "RqstTopDomainRead", getRqstTopDomainRead() );
			saxDoc.addElementHandler( "RqstTopDomainLock", getRqstTopDomainLock() );
			saxDoc.addElementHandler( "RqstTopDomainUpdate", getRqstTopDomainUpdate() );
			saxDoc.addElementHandler( "RqstTopDomainDelete", getRqstTopDomainDelete() );
			saxDoc.addElementHandler( "RqstTopDomainReadAll", getRqstTopDomainReadAll() );
			saxDoc.addElementHandler( "RqstTopDomainRdByTenantIdx", getRqstTopDomainRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstTopDomainRdByTldIdx", getRqstTopDomainRdByTldIdx() );
			saxDoc.addElementHandler( "RqstTopDomainRdByNameIdx", getRqstTopDomainRdByNameIdx() );
			saxDoc.addElementHandler( "RqstTopDomainDelByTenantIdx", getRqstTopDomainDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstTopDomainDelByTldIdx", getRqstTopDomainDelByTldIdx() );
			saxDoc.addElementHandler( "RqstTopDomainDelByNameIdx", getRqstTopDomainDelByNameIdx() );
	}

	protected void addTopProjectToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstTopProjectCreate", getRqstTopProjectCreate() );
			saxDoc.addElementHandler( "RqstTopProjectRead", getRqstTopProjectRead() );
			saxDoc.addElementHandler( "RqstTopProjectLock", getRqstTopProjectLock() );
			saxDoc.addElementHandler( "RqstTopProjectUpdate", getRqstTopProjectUpdate() );
			saxDoc.addElementHandler( "RqstTopProjectDelete", getRqstTopProjectDelete() );
			saxDoc.addElementHandler( "RqstTopProjectReadAll", getRqstTopProjectReadAll() );
			saxDoc.addElementHandler( "RqstTopProjectRdByTenantIdx", getRqstTopProjectRdByTenantIdx() );
			saxDoc.addElementHandler( "RqstTopProjectRdByTopDomainIdx", getRqstTopProjectRdByTopDomainIdx() );
			saxDoc.addElementHandler( "RqstTopProjectRdByNameIdx", getRqstTopProjectRdByNameIdx() );
			saxDoc.addElementHandler( "RqstTopProjectDelByTenantIdx", getRqstTopProjectDelByTenantIdx() );
			saxDoc.addElementHandler( "RqstTopProjectDelByTopDomainIdx", getRqstTopProjectDelByTopDomainIdx() );
			saxDoc.addElementHandler( "RqstTopProjectDelByNameIdx", getRqstTopProjectDelByNameIdx() );
	}

	protected void addURLProtocolToSaxRqstDoc( CFIntSaxRqstDoc saxDoc ) {

			saxDoc.addElementHandler( "RqstURLProtocolCreate", getRqstURLProtocolCreate() );
			saxDoc.addElementHandler( "RqstURLProtocolRead", getRqstURLProtocolRead() );
			saxDoc.addElementHandler( "RqstURLProtocolLock", getRqstURLProtocolLock() );
			saxDoc.addElementHandler( "RqstURLProtocolUpdate", getRqstURLProtocolUpdate() );
			saxDoc.addElementHandler( "RqstURLProtocolDelete", getRqstURLProtocolDelete() );
			saxDoc.addElementHandler( "RqstURLProtocolReadAll", getRqstURLProtocolReadAll() );
			saxDoc.addElementHandler( "RqstURLProtocolRdByUNameIdx", getRqstURLProtocolRdByUNameIdx() );
			saxDoc.addElementHandler( "RqstURLProtocolRdByIsSecureIdx", getRqstURLProtocolRdByIsSecureIdx() );
			saxDoc.addElementHandler( "RqstURLProtocolDelByUNameIdx", getRqstURLProtocolDelByUNameIdx() );
			saxDoc.addElementHandler( "RqstURLProtocolDelByIsSecureIdx", getRqstURLProtocolDelByIsSecureIdx() );
	}

	protected CFIntSaxRqstDoc getSaxRqstDoc() {
		if( saxDoc == null ) {
			saxDoc = new CFIntSaxRqstDoc( this );

			addClusterToSaxRqstDoc( saxDoc );
			addHostNodeToSaxRqstDoc( saxDoc );
			addISOCcyToSaxRqstDoc( saxDoc );
			addISOCtryToSaxRqstDoc( saxDoc );
			addISOCtryCcyToSaxRqstDoc( saxDoc );
			addISOCtryLangToSaxRqstDoc( saxDoc );
			addISOLangToSaxRqstDoc( saxDoc );
			addISOTZoneToSaxRqstDoc( saxDoc );
			addLicenseToSaxRqstDoc( saxDoc );
			addMajorVersionToSaxRqstDoc( saxDoc );
			addMimeTypeToSaxRqstDoc( saxDoc );
			addMinorVersionToSaxRqstDoc( saxDoc );
			addSecAppToSaxRqstDoc( saxDoc );
			addSecDeviceToSaxRqstDoc( saxDoc );
			addSecFormToSaxRqstDoc( saxDoc );
			addSecGroupToSaxRqstDoc( saxDoc );
			addSecGroupFormToSaxRqstDoc( saxDoc );
			addSecGrpIncToSaxRqstDoc( saxDoc );
			addSecGrpMembToSaxRqstDoc( saxDoc );
			addSecSessionToSaxRqstDoc( saxDoc );
			addSecUserToSaxRqstDoc( saxDoc );
			addServiceToSaxRqstDoc( saxDoc );
			addServiceTypeToSaxRqstDoc( saxDoc );
			addSubProjectToSaxRqstDoc( saxDoc );
			addSysClusterToSaxRqstDoc( saxDoc );
			addTSecGroupToSaxRqstDoc( saxDoc );
			addTSecGrpIncToSaxRqstDoc( saxDoc );
			addTSecGrpMembToSaxRqstDoc( saxDoc );
			addTenantToSaxRqstDoc( saxDoc );
			addTldToSaxRqstDoc( saxDoc );
			addTopDomainToSaxRqstDoc( saxDoc );
			addTopProjectToSaxRqstDoc( saxDoc );
			addURLProtocolToSaxRqstDoc( saxDoc );
			saxDoc.addElementHandler( "RqstFileImport", getRqstFileImport() );
			saxDoc.addElementHandler( "RqstLogIn", getRqstLogIn() );
			saxDoc.addElementHandler( "RqstLogOut", getRqstLogOut() );		}
		return( saxDoc );
	}

	// Document Element 

	/*
	 *	CFIntSaxRqstDoc XML SAX Doc Element  implementation
	 */
	public class CFIntSaxRqstDoc
		extends CFLibXmlCoreElementHandler
	{
		public CFIntSaxRqstDoc( CFIntXMsgRqst xmsgRqst ) {
			super( xmsgRqst );
		}

		public void startElement(
			String		uri,
			String		localName,
			String		qName,
			Attributes	attrs )
		throws SAXException
		{
			String effSchemaName;
			if( qName.endsWith( "Rqst" ) ) {
				effSchemaName = qName.substring( 0, qName.length() - 4 );
			}
			else {
				effSchemaName = "CFInt";
			}
			CFIntXMsgRqst xmsgRqst = ((CFIntXMsgRqst)getParser());
			CFIntXMsgSchemaMessageFormatter schemaFormatter = xmsgRqst.getSchemaMessageFormatter();
			schemaFormatter.setMessageNamespace( effSchemaName );
		}

		public void endElement(
			String		uri,
			String		localName,
			String		qName )
		throws SAXException
		{
		}
	}

	// Parse XML string contents

	public void parseStringContents( String str ) {
		final String S_ProcName = "parseStringContents";
		resetResponse();
		CFSecAuthorization auth = schemaObj.getAuthorization();
		if( ( auth != null ) && schemaObj.isTransactionOpen() ) {
			try {
				schemaObj.rollback();
			}
			catch( RuntimeException x ) {
			}
		}
		boolean transactionOpened = false;
		try {
			if( auth != null ) {
				transactionOpened = schemaObj.beginTransaction();
			}
			else {
				transactionOpened = false;
			}

			super.parseStringContents( str );

			// If the request was a logout or login the authorization will have changed
			auth = schemaObj.getAuthorization();
			if( auth != null ) {
				try {
					if( caughtException ) {
						schemaObj.rollback();
					}
					else {
						schemaObj.commit();
					}
				}
				catch( RuntimeException e ) {
				}
			}

			transactionOpened = false;
		}
		catch( CFLibArgumentOverflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentRangeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentUnderflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibCollisionDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDbException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDependentsDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibEmptyArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibInvalidArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibMustOverrideException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotImplementedYetException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotSupportedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNullArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibPrimaryKeyNotNewException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibStaleCacheDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUniqueIndexViolationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnrecognizedAttributeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnresolvedRelationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnsupportedClassException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUsageException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibRuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( RuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
		catch( Exception e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
	}

	// Parse a URL

	public void parse( String url ) {
		final String S_ProcName = "parse";
		resetResponse();
		if( schemaObj.isTransactionOpen() ) {
			try {
				schemaObj.rollback();
			}
			catch( RuntimeException x ) {
			}
		}
		boolean transactionOpened = false;
		try {
			transactionOpened = schemaObj.beginTransaction();

			super.parse( url );

			if( caughtException ) {
				schemaObj.rollback();
			}
			else {
				schemaObj.commit();
			}

			transactionOpened = false;
		}
		catch( CFLibArgumentOverflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentRangeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentUnderflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibCollisionDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDbException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDependentsDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibEmptyArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibInvalidArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibMustOverrideException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotImplementedYetException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotSupportedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNullArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibPrimaryKeyNotNewException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibStaleCacheDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUniqueIndexViolationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnrecognizedAttributeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnresolvedRelationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnsupportedClassException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUsageException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibRuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( RuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
		catch( Exception e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
	}

	// Parse a file

	public void parseFile( String url ) {
		final String S_ProcName = "parseFile";
		resetResponse();
		if( schemaObj.isTransactionOpen() ) {
			try {
				schemaObj.rollback();
			}
			catch( RuntimeException x ) {
			}
		}
		boolean transactionOpened = false;
		try {
			transactionOpened = schemaObj.beginTransaction();

			super.parse( url );

			if( caughtException ) {
				schemaObj.rollback();
			}
			else {
				schemaObj.commit();
			}

			transactionOpened = false;
		}
		catch( CFLibArgumentOverflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentRangeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentUnderflowException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibCollisionDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDbException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibDependentsDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibEmptyArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibInvalidArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibMustOverrideException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotImplementedYetException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNotSupportedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibNullArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibPrimaryKeyNotNewException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibStaleCacheDetectedException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUniqueIndexViolationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnrecognizedAttributeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnresolvedRelationException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUnsupportedClassException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibUsageException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibArgumentException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( CFLibRuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw e;
		}
		catch( RuntimeException e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
		catch( Exception e ) {
			if( transactionOpened ) {
				try {
					schemaObj.rollback();
				}
				catch( RuntimeException x ) {
				}
				transactionOpened = false;
			}
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				e.getMessage(),
				e );
		}
	}
}
