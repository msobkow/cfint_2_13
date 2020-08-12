
// Description: Java 11 XML SAX Element Handler for ISOLang

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
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

package org.msscf.msscf.cfint.v2_13.cfint.CFIntSaxLoader;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/*
 *	CFIntSaxLoaderISOLangParse XML SAX Element Handler implementation
 *	for ISOLang.
 */
public class CFIntSaxLoaderISOLang
	extends CFLibXmlCoreElementHandler
{
	public CFIntSaxLoaderISOLang( CFIntSaxLoader saxLoader ) {
		super( saxLoader );
	}

	public void startElement(
		String		uri,
		String		localName,
		String		qName,
		Attributes	attrs )
	throws SAXException
	{
		final String S_ProcName = "startElement";
		ICFIntISOLangObj origBuff = null;
		ICFIntISOLangEditObj editBuff = null;
		// Common XML Attributes
		String attrId = null;
		// ISOLang Attributes
		String attrISO6392Code = null;
		String attrISO6391Code = null;
		String attrEnglishName = null;
		// ISOLang References
		// Attribute Extraction
		String attrLocalName;
		int numAttrs;
		int idxAttr;
		final String S_LocalName = "LocalName";
		try {
			assert qName.equals( "ISOLang" );

			CFIntSaxLoader saxLoader = (CFIntSaxLoader)getParser();
			if( saxLoader == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"getParser()" );
			}

			ICFIntSchemaObj schemaObj = saxLoader.getSchemaObj();
			if( schemaObj == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"getParser().getSchemaObj()" );
			}

			// Instantiate an edit buffer for the parsed information
			origBuff = (ICFIntISOLangObj)schemaObj.getISOLangTableObj().newInstance();
			editBuff = (ICFIntISOLangEditObj)origBuff.beginEdit();

			// Extract Attributes
			numAttrs = attrs.getLength();
			for( idxAttr = 0; idxAttr < numAttrs; idxAttr++ ) {
				attrLocalName = attrs.getLocalName( idxAttr );
				if( attrLocalName.equals( "Id" ) ) {
					if( attrId != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrId = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "ISO6392Code" ) ) {
					if( attrISO6392Code != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrISO6392Code = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "ISO6391Code" ) ) {
					if( attrISO6391Code != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrISO6391Code = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "EnglishName" ) ) {
					if( attrEnglishName != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrEnglishName = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "schemaLocation" ) ) {
					// ignored
				}
				else {
					throw new CFLibUnrecognizedAttributeException( getClass(),
						S_ProcName,
						getParser().getLocationInfo(),
						attrLocalName );
				}
			}

			// Ensure that required attributes have values
			if( attrISO6392Code == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"ISO6392Code" );
			}
			if( attrEnglishName == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"EnglishName" );
			}

			// Save named attributes to context
			CFLibXmlCoreContext curContext = getParser().getCurContext();
			curContext.putNamedValue( "Id", attrId );
			curContext.putNamedValue( "ISO6392Code", attrISO6392Code );
			curContext.putNamedValue( "ISO6391Code", attrISO6391Code );
			curContext.putNamedValue( "EnglishName", attrEnglishName );

			// Convert string attributes to native Java types
			// and apply the converted attributes to the editBuff.

			Integer natId;
			if( ( attrId != null ) && ( attrId.length() > 0 ) ) {
				natId = Integer.valueOf( Integer.parseInt( attrId ) );
			}
			else {
				natId = null;
			}
			String natISO6392Code = attrISO6392Code;
			editBuff.setRequiredISO6392Code( natISO6392Code );

			String natISO6391Code = attrISO6391Code;
			editBuff.setOptionalISO6391Code( natISO6391Code );

			String natEnglishName = attrEnglishName;
			editBuff.setRequiredEnglishName( natEnglishName );

			// Get the scope/container object

			CFLibXmlCoreContext parentContext = curContext.getPrevContext();
			Object scopeObj;
			if( parentContext != null ) {
				scopeObj = parentContext.getNamedValue( "Object" );
			}
			else {
				scopeObj = null;
			}

			CFIntSaxLoader.LoaderBehaviourEnum loaderBehaviour = saxLoader.getISOLangLoaderBehaviour();
			ICFIntISOLangEditObj editISOLang = null;
			ICFIntISOLangObj origISOLang = (ICFIntISOLangObj)schemaObj.getISOLangTableObj().readISOLangByCode3Idx( editBuff.getRequiredISO6392Code() );
			if( origISOLang == null ) {
				editISOLang = editBuff;
			}
			else {
				switch( loaderBehaviour ) {
					case Insert:
						break;
					case Update:
						editISOLang = (ICFIntISOLangEditObj)origISOLang.beginEdit();
						editISOLang.setRequiredISO6392Code( editBuff.getRequiredISO6392Code() );
						editISOLang.setOptionalISO6391Code( editBuff.getOptionalISO6391Code() );
						editISOLang.setRequiredEnglishName( editBuff.getRequiredEnglishName() );
						break;
					case Replace:
						editISOLang = (ICFIntISOLangEditObj)origISOLang.beginEdit();
						editISOLang.deleteInstance();
						editISOLang = null;
						origISOLang = null;
						editISOLang = editBuff;
						break;
				}
			}

			if( editISOLang != null ) {
				if( origISOLang != null ) {
					editISOLang.update();
				}
				else {
					origISOLang = (ICFIntISOLangObj)editISOLang.create();
				}
				editISOLang = null;
			}

			curContext.putNamedValue( "Object", origISOLang );
		}
		catch( RuntimeException e ) {
			throw new SAXException( "Near " + getParser().getLocationInfo() + ": Caught and rethrew " + e.getClass().getName() + " - " + e.getMessage(),
				e );
		}
		catch( Error e ) {
			throw new SAXException( "Near " + getParser().getLocationInfo() + ": Caught and rethrew " + e.getClass().getName() + " - " + e.getMessage() );
		}
	}

	public void endElement(
		String		uri,
		String		localName,
		String		qName )
	throws SAXException
	{
	}
}
