
// Description: Java 11 XML SAX Element Handler for ISOTZone

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow mark.sobkow@gmail.com
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

package org.msscf.msscf.v2_13.cfint.CFIntSaxLoader;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;
import org.msscf.msscf.v2_13.cfint.CFInt.*;
import org.msscf.msscf.v2_13.cfsec.CFSecObj.*;
import org.msscf.msscf.v2_13.cfint.CFIntObj.*;

/*
 *	CFIntSaxLoaderISOTZoneParse XML SAX Element Handler implementation
 *	for ISOTZone.
 */
public class CFIntSaxLoaderISOTZone
	extends CFLibXmlCoreElementHandler
{
	public CFIntSaxLoaderISOTZone( CFIntSaxLoader saxLoader ) {
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
		ICFIntISOTZoneObj origBuff = null;
		ICFIntISOTZoneEditObj editBuff = null;
		// Common XML Attributes
		String attrId = null;
		// ISOTZone Attributes
		String attrIso8601 = null;
		String attrTZName = null;
		String attrTZHourOffset = null;
		String attrTZMinOffset = null;
		String attrDescription = null;
		String attrVisible = null;
		// ISOTZone References
		// Attribute Extraction
		String attrLocalName;
		int numAttrs;
		int idxAttr;
		final String S_LocalName = "LocalName";
		try {
			assert qName.equals( "ISOTZone" );

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
			origBuff = (ICFIntISOTZoneObj)schemaObj.getISOTZoneTableObj().newInstance();
			editBuff = (ICFIntISOTZoneEditObj)origBuff.beginEdit();

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
				else if( attrLocalName.equals( "Iso8601" ) ) {
					if( attrIso8601 != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrIso8601 = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "TZName" ) ) {
					if( attrTZName != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrTZName = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "TZHourOffset" ) ) {
					if( attrTZHourOffset != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrTZHourOffset = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "TZMinOffset" ) ) {
					if( attrTZMinOffset != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrTZMinOffset = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "Description" ) ) {
					if( attrDescription != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrDescription = attrs.getValue( idxAttr );
				}
				else if( attrLocalName.equals( "Visible" ) ) {
					if( attrVisible != null ) {
						throw new CFLibUniqueIndexViolationException( getClass(),
							S_ProcName,
							S_LocalName,
							attrLocalName );
					}
					attrVisible = attrs.getValue( idxAttr );
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
			if( attrIso8601 == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"Iso8601" );
			}
			if( attrTZName == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"TZName" );
			}
			if( ( attrTZHourOffset == null ) || ( attrTZHourOffset.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"TZHourOffset" );
			}
			if( ( attrTZMinOffset == null ) || ( attrTZMinOffset.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"TZMinOffset" );
			}
			if( attrDescription == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"Description" );
			}
			if( ( attrVisible == null ) || ( attrVisible.length() <= 0 ) ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"Visible" );
			}

			// Save named attributes to context
			CFLibXmlCoreContext curContext = getParser().getCurContext();
			curContext.putNamedValue( "Id", attrId );
			curContext.putNamedValue( "Iso8601", attrIso8601 );
			curContext.putNamedValue( "TZName", attrTZName );
			curContext.putNamedValue( "TZHourOffset", attrTZHourOffset );
			curContext.putNamedValue( "TZMinOffset", attrTZMinOffset );
			curContext.putNamedValue( "Description", attrDescription );
			curContext.putNamedValue( "Visible", attrVisible );

			// Convert string attributes to native Java types
			// and apply the converted attributes to the editBuff.

			Integer natId;
			if( ( attrId != null ) && ( attrId.length() > 0 ) ) {
				natId = Integer.valueOf( Integer.parseInt( attrId ) );
			}
			else {
				natId = null;
			}
			String natIso8601 = attrIso8601;
			editBuff.setRequiredIso8601( natIso8601 );

			String natTZName = attrTZName;
			editBuff.setRequiredTZName( natTZName );

			short natTZHourOffset = Short.parseShort( attrTZHourOffset );
			editBuff.setRequiredTZHourOffset( natTZHourOffset );

			short natTZMinOffset = Short.parseShort( attrTZMinOffset );
			editBuff.setRequiredTZMinOffset( natTZMinOffset );

			String natDescription = attrDescription;
			editBuff.setRequiredDescription( natDescription );

			boolean natVisible;
			if( attrVisible.equals( "true" ) || attrVisible.equals( "yes" ) || attrVisible.equals( "1" ) ) {
				natVisible = true;
			}
			else if( attrVisible.equals( "false" ) || attrVisible.equals( "no" ) || attrVisible.equals( "0" ) ) {
				natVisible = false;
			}
			else {
				throw new CFLibUsageException( getClass(),
					S_ProcName,
					"Unexpected Visible value, must be one of true, false, yes, no, 1, or 0, not \"" + attrVisible + "\"" );
			}
			editBuff.setRequiredVisible( natVisible );

			// Get the scope/container object

			CFLibXmlCoreContext parentContext = curContext.getPrevContext();
			Object scopeObj;
			if( parentContext != null ) {
				scopeObj = parentContext.getNamedValue( "Object" );
			}
			else {
				scopeObj = null;
			}

			CFIntSaxLoader.LoaderBehaviourEnum loaderBehaviour = saxLoader.getISOTZoneLoaderBehaviour();
			ICFIntISOTZoneEditObj editISOTZone = null;
			ICFIntISOTZoneObj origISOTZone = (ICFIntISOTZoneObj)schemaObj.getISOTZoneTableObj().readISOTZoneByUTZNameIdx( editBuff.getRequiredTZName() );
			if( origISOTZone == null ) {
				editISOTZone = editBuff;
			}
			else {
				switch( loaderBehaviour ) {
					case Insert:
						break;
					case Update:
						editISOTZone = (ICFIntISOTZoneEditObj)origISOTZone.beginEdit();
						editISOTZone.setRequiredIso8601( editBuff.getRequiredIso8601() );
						editISOTZone.setRequiredTZName( editBuff.getRequiredTZName() );
						editISOTZone.setRequiredTZHourOffset( editBuff.getRequiredTZHourOffset() );
						editISOTZone.setRequiredTZMinOffset( editBuff.getRequiredTZMinOffset() );
						editISOTZone.setRequiredDescription( editBuff.getRequiredDescription() );
						editISOTZone.setRequiredVisible( editBuff.getRequiredVisible() );
						break;
					case Replace:
						editISOTZone = (ICFIntISOTZoneEditObj)origISOTZone.beginEdit();
						editISOTZone.deleteInstance();
						editISOTZone = null;
						origISOTZone = null;
						editISOTZone = editBuff;
						break;
				}
			}

			if( editISOTZone != null ) {
				if( origISOTZone != null ) {
					editISOTZone.update();
				}
				else {
					origISOTZone = (ICFIntISOTZoneObj)editISOTZone.create();
				}
				editISOTZone = null;
			}

			curContext.putNamedValue( "Object", origISOTZone );
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
