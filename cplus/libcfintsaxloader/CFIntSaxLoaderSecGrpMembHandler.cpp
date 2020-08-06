
// Description: C++18 XML SAX2 Element Handler implementation for SecGrpMemb

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

#include <cflib/ICFLibPublic.hpp>
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintsaxloader/CFIntSaxLoader.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSecGrpMembHandler.hpp>

using namespace std;

namespace cfint {

	const std::string CFIntSaxLoaderSecGrpMembHandler::CLASS_NAME( "CFIntSaxLoaderSecGrpMembHandler" );
	const std::string CFIntSaxLoaderSecGrpMembHandler::S_True( "true" );
	const std::string CFIntSaxLoaderSecGrpMembHandler::S_False( "false" );
	const std::string CFIntSaxLoaderSecGrpMembHandler::S_Yes( "yes" );
	const std::string CFIntSaxLoaderSecGrpMembHandler::S_No( "no" );
	const std::string CFIntSaxLoaderSecGrpMembHandler::S_0( "0" );
	const std::string CFIntSaxLoaderSecGrpMembHandler::S_1( "1" );

	CFIntSaxLoaderSecGrpMembHandler::CFIntSaxLoaderSecGrpMembHandler( cfint::CFIntSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFIntSaxLoaderSecGrpMembHandler::~CFIntSaxLoaderSecGrpMembHandler() {
	}

	void CFIntSaxLoaderSecGrpMembHandler::startElement (
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname,
		const xercesc::Attributes& attrs )
	{
		const static std::string S_ProcName( "startElement" );
		const static std::string S_SpecificallyId( "Id" );
		const static std::string S_Object( "object" );
		const static std::string S_Uri( "uri" );
		const static std::string S_LocalName( "localname" );
		const static std::string S_GetParser( "getParser()" );
		const static std::string S_GetParserGetSchemaObj( "getParser()->getSchemaObj()" );
		const static std::string S_SchemaLocation( "schemaLocation" );
		const static std::string S_SaxLoaderUseTenant( "saxLoader->useTenant" );
		const static std::string S_QName( "qname" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGrpMembId( "SecGrpMembId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_Cluster( "Cluster" );
		static const std::string S_Group( "Group" );
		static const std::string S_User( "User" );
		CFLIB_EXCEPTION_DECLINFO
		const XMLCh* xmlchLocalName = NULL;
		char* cLocalName = NULL;
		std::string* attrLocalName = NULL;
		const XMLCh* xmlchValue = NULL;
		char* cValue = NULL;
		std::string* cppValue = NULL;
		char* cUri = NULL;
		char* cQName = NULL;
		cflib::CFLibXmlCoreContext* curContext = NULL;
		cfint::CFIntSaxLoader* saxLoader = NULL;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum loaderBehaviour;
		cfint::ICFIntSchemaObj* schemaObj = NULL;
		cfsec::ICFSecSecGrpMembObj* tmpBuff = NULL;
		cfsec::ICFSecSecGrpMembEditObj* editBuff = NULL;
		cfsec::ICFSecSecGrpMembEditObj* editSecGrpMemb = NULL;
		cfsec::ICFSecSecGrpMembObj* origSecGrpMemb = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// SecGrpMemb Attributes
		std::string* attrUser = NULL;
		// SecGrpMemb References
		cfsec::ICFSecClusterObj* refCluster = NULL;
		cfsec::ICFSecSecGroupObj* refGroup = NULL;
		cfsec::ICFSecSecUserObj* refUser = NULL;
		try {
			if( ( uri == NULL ) || ( *uri == 0 ) ) {
				throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
					S_ProcName,
					1,
					S_Uri );
			}
			if( ( localname == NULL ) || ( *localname == 0 ) ) {
				throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
					S_ProcName,
					2,
					S_LocalName );
			}
			if( ( qname == NULL ) || ( *qname == 0 ) ) {
				throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
					S_ProcName,
					3,
					S_QName );
			}
			cUri = xercesc::XMLString::transcode( uri );
			cLocalName = xercesc::XMLString::transcode( localname );
			cQName = xercesc::XMLString::transcode( qname );
			std::string cppUri( cUri );
			std::string cppLocalName( cLocalName );
			std::string cppQName( cQName );
			xercesc::XMLString::release( &cUri );
			cUri = NULL;
			xercesc::XMLString::release( &cLocalName );
			cLocalName = NULL;
			xercesc::XMLString::release( &cQName );
			cQName = NULL;
			if( cppQName != cfsec::CFSecSecGrpMembBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecSecGrpMembBuff::GENDEFNAME + "'" );
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
			// Attribute Extraction
			size_t numAttrs;
			size_t idxAttr;
			saxLoader = dynamic_cast<cfint::CFIntSaxLoader*>( getParser() );
			if( saxLoader == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_GetParser );
			}

			schemaObj = dynamic_cast<cfint::ICFIntSchemaObj*>( saxLoader->getSchemaObj() );
			if( schemaObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_GetParserGetSchemaObj );
			}

			// Instantiate an edit buffer for the parsed information
			tmpBuff = schemaObj->getSecGrpMembTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecSecGrpMembEditObj*>( tmpBuff->beginEdit() );

			// Extract Attributes
			numAttrs = attrs.getLength();
			for( idxAttr = 0; idxAttr < numAttrs; idxAttr++ ) {
				if( attrLocalName != NULL ) {
					delete attrLocalName;
					attrLocalName = NULL;
				}
				if( cppValue != NULL ) {
					delete cppValue;
					cppValue = NULL;
				}
				xmlchLocalName = attrs.getLocalName( idxAttr );
				if( xmlchLocalName == NULL ) {
					continue;
				}
				cLocalName = xercesc::XMLString::transcode( xmlchLocalName );
				attrLocalName = new std::string( cLocalName );
				xercesc::XMLString::release( &cLocalName );
				cLocalName = NULL;
				xmlchValue = attrs.getValue( idxAttr );
				if( xmlchValue == NULL ) {
					cppValue = NULL;
				}
				else {
					cValue = xercesc::XMLString::transcode( xmlchValue );
					cppValue = new std::string( cValue );
					xercesc::XMLString::release( &cValue );
					cValue = NULL;
				}
				if( *attrLocalName == S_SpecificallyId ) {
					if( attrId != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrId = new std::string( *cppValue );
					}
				}
				else if( *attrLocalName == S_User ) {
					if( attrUser != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrUser = new std::string( *cppValue );
					}
					else {
						attrUser = NULL;
					}
				}
				else if( *attrLocalName == S_SchemaLocation ) {
					// ignored
				}
				else {
					throw cflib::CFLibUnrecognizedAttributeException( CLASS_NAME,
						S_ProcName,
						getParser()->getLocationInfo(),
						*attrLocalName );
				}
				if( cppValue != NULL ) {
					delete cppValue;
					cppValue = NULL;
				}
				if( attrLocalName != NULL ) {
					delete attrLocalName;
					attrLocalName = NULL;
				}
			}

			// Ensure that required attributes have values
			if( ( attrUser == NULL ) || ( attrUser->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_User );
			}

			// Save named attributes to context
			curContext = getParser()->getCurContext();
			if( curContext == NULL ) {
				static const std::string S_CurContext( "getParser()->getCurContext" );
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_CurContext );
			}
			if( attrId != NULL ) {
				curContext->putNamedTag( S_SpecificallyId, *attrId );
			}
			if( attrUser != NULL ) {
				curContext->putNamedTag( S_User, *attrUser );
			}

			// Convert string attributes to native C++18 types
			// and apply the converted attributes to the editBuff

			cflib::CFLibNullableInt32 natId;
			if( ( attrId != NULL ) && ( attrId->length() > 0 ) ) {
				natId = cflib::CFLibXmlUtil::evalInt32( *attrId );
			}
			else {
				natId.setNull();
			}
			// Get the scope/container object

			parentContext = curContext->getPrevContext();
			if( parentContext != NULL ) {
				scopeObj = parentContext->getObj();
			}
			else {
				scopeObj = NULL;
			}

			// Resolve and apply required Container reference

			if( scopeObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					"scopeObj" );
			}
			else if( scopeObj->implementsClassCode( cfsec::CFSecSecGroupBuff::CLASS_CODE ) ) {
				refGroup = dynamic_cast<cfsec::ICFSecSecGroupObj*>( scopeObj );
				editBuff->setRequiredContainerGroup( refGroup );
			refCluster = editBuff->getRequiredOwnerCluster();
			}
			else {
				throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFIntSecGroupObj" );
			}

			// Resolve and apply Owner reference

			if( refCluster == NULL ) {
				if( scopeObj->implementsClassCode( cfsec::CFSecClusterBuff::CLASS_CODE ) ) {
					refCluster = dynamic_cast<cfsec::ICFSecClusterObj*>( scopeObj );
					editBuff->setRequiredOwnerCluster( refCluster );
				}
				else {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Owner<Cluster>" );
				}
			}

			// Lookup refUser by key name value attr
			if( ( attrUser != NULL ) && ( attrUser->length() > 0 ) ) {
				refUser = schemaObj->getSecUserTableObj()->readSecUserByULoginIdx( *attrUser );
				if( refUser == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Resolve User reference named \"" + *attrUser + "\" to table SecUser" );
				}
			}
			else {
				refUser = NULL;
			}
			editBuff->setRequiredParentUser( refUser );

			editSecGrpMemb = editBuff;
			editBuff = NULL;
			origSecGrpMemb = dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( editSecGrpMemb->create() );
			editSecGrpMemb = NULL;
			tmpBuff = NULL;

			curContext->setObj( origSecGrpMemb );

		}
		CFLIB_EXCEPTION_CATCH_FALLTHROUGH

cleanup:
		if( attrLocalName != NULL ) {
			delete attrLocalName;
			attrLocalName = NULL;
		}

		if( cppValue != NULL ) {
			delete cppValue;
			cppValue = NULL;
		}

		if( attrUser != NULL ) {
			delete attrUser;
			attrUser = NULL;
		}

		if( editSecGrpMemb != NULL ) {
			editSecGrpMemb->endEdit();
			editSecGrpMemb = NULL;
		}

		if( editBuff != NULL ) {
			editBuff->endEdit();
			editBuff = NULL;
		}

		if( tmpBuff != NULL ) {
			if( tmpBuff->getIsNew() ) {
				delete tmpBuff;
			}
			tmpBuff = NULL;
		}

		CFLIB_EXCEPTION_RETHROW_SAXEXCEPTION
	}

	void CFIntSaxLoaderSecGrpMembHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
