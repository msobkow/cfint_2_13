
// Description: C++18 XML SAX2 Element Handler implementation for URLProtocol

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

#include <cflib/ICFLibPublic.hpp>
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintsaxloader/CFIntSaxLoader.hpp>
#include <cfintsaxloader/CFIntSaxLoaderURLProtocolHandler.hpp>

using namespace std;

namespace cfint {

	const std::string CFIntSaxLoaderURLProtocolHandler::CLASS_NAME( "CFIntSaxLoaderURLProtocolHandler" );
	const std::string CFIntSaxLoaderURLProtocolHandler::S_True( "true" );
	const std::string CFIntSaxLoaderURLProtocolHandler::S_False( "false" );
	const std::string CFIntSaxLoaderURLProtocolHandler::S_Yes( "yes" );
	const std::string CFIntSaxLoaderURLProtocolHandler::S_No( "no" );
	const std::string CFIntSaxLoaderURLProtocolHandler::S_0( "0" );
	const std::string CFIntSaxLoaderURLProtocolHandler::S_1( "1" );

	CFIntSaxLoaderURLProtocolHandler::CFIntSaxLoaderURLProtocolHandler( cfint::CFIntSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFIntSaxLoaderURLProtocolHandler::~CFIntSaxLoaderURLProtocolHandler() {
	}

	void CFIntSaxLoaderURLProtocolHandler::startElement (
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
		static const std::string S_URLProtocolId( "URLProtocolId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		static const std::string S_IsSecure( "IsSecure" );
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
		cfint::ICFIntURLProtocolObj* tmpBuff = NULL;
		cfint::ICFIntURLProtocolEditObj* editBuff = NULL;
		cfint::ICFIntURLProtocolEditObj* editURLProtocol = NULL;
		cfint::ICFIntURLProtocolObj* origURLProtocol = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// URLProtocol Attributes
		std::string* attrName = NULL;
		std::string* attrDescription = NULL;
		std::string* attrIsSecure = NULL;
		// URLProtocol References
		std::string* natName = NULL;
		std::string* natDescription = NULL;
		bool natIsSecure;
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
			if( cppQName != cfint::CFIntURLProtocolBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfint::CFIntURLProtocolBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getURLProtocolTableObj()->newInstance();
			editBuff = dynamic_cast<cfint::ICFIntURLProtocolEditObj*>( tmpBuff->beginEdit() );

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
				else if( *attrLocalName == S_Name ) {
					if( attrName != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrName = new std::string( *cppValue );
					}
					else {
						attrName = NULL;
					}
				}
				else if( *attrLocalName == S_Description ) {
					if( attrDescription != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrDescription = new std::string( *cppValue );
					}
					else {
						attrDescription = NULL;
					}
				}
				else if( *attrLocalName == S_IsSecure ) {
					if( attrIsSecure != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrIsSecure = new std::string( *cppValue );
					}
					else {
						attrIsSecure = NULL;
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
			if( attrName == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Name );
			}
			if( attrDescription == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Description );
			}
			if( ( attrIsSecure == NULL ) || ( attrIsSecure->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_IsSecure );
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
			if( attrName != NULL ) {
				curContext->putNamedTag( S_Name, *attrName );
			}
			if( attrDescription != NULL ) {
				curContext->putNamedTag( S_Description, *attrDescription );
			}
			if( attrIsSecure != NULL ) {
				curContext->putNamedTag( S_IsSecure, *attrIsSecure );
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
			if( attrName != NULL ) {
				natName = new std::string( *attrName );
			}
			else {
				natName = NULL;
			}
			if( natName == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Name );
			}
			editBuff->setRequiredName( *natName );

			if( attrDescription != NULL ) {
				natDescription = new std::string( *attrDescription );
			}
			else {
				natDescription = NULL;
			}
			if( natDescription == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Description );
			}
			editBuff->setRequiredDescription( *natDescription );

			if( ( *attrIsSecure == S_True ) || ( *attrIsSecure == S_Yes ) || ( *attrIsSecure == S_1 ) ) {
				natIsSecure = true;
			}
			else if( ( *attrIsSecure == S_False ) || ( *attrIsSecure == S_No ) || ( *attrIsSecure == S_0 ) ) {
				natIsSecure = false;
			}
			else {
				throw cflib::CFLibInvalidArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_IsSecure,
					*attrIsSecure );
			}
			editBuff->setRequiredIsSecure( natIsSecure );

			// Get the scope/container object

			parentContext = curContext->getPrevContext();
			if( parentContext != NULL ) {
				scopeObj = parentContext->getObj();
			}
			else {
				scopeObj = NULL;
			}

			loaderBehaviour = saxLoader->getURLProtocolLoaderBehaviour();
			origURLProtocol = dynamic_cast<cfint::ICFIntURLProtocolObj*>( schemaObj->getURLProtocolTableObj()->readURLProtocolByUNameIdx( editBuff->getRequiredName() ) );
			if( origURLProtocol == NULL ) {
				editURLProtocol = editBuff;
				editBuff = NULL;
			}
			else {
				switch( loaderBehaviour ) {
					case cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert:
						editURLProtocol = NULL;
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update:
						editURLProtocol = dynamic_cast<cfint::ICFIntURLProtocolEditObj*>( origURLProtocol->beginEdit() );
						editURLProtocol->setRequiredName( editBuff->getRequiredName() );
						editURLProtocol->setRequiredDescription( editBuff->getRequiredDescription() );
						editURLProtocol->setRequiredIsSecure( editBuff->getRequiredIsSecure() );
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace:
						editURLProtocol = dynamic_cast<cfint::ICFIntURLProtocolEditObj*>( origURLProtocol->beginEdit() );
						editURLProtocol->deleteInstance();
						editURLProtocol = NULL;
						origURLProtocol = NULL;
						editURLProtocol = editBuff;
						editBuff = NULL;
						break;
				}
			}

			if( editURLProtocol != NULL ) {
				if( origURLProtocol != NULL ) {
					editURLProtocol->update();
				}
				else {
					origURLProtocol = dynamic_cast<cfint::ICFIntURLProtocolObj*>( editURLProtocol->create() );
				}
				editURLProtocol = NULL;
			}

			if( ! tmpBuff->getIsNew() ) {
				tmpBuff = NULL;
			}

			curContext->setObj( origURLProtocol );

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

		if( natName != NULL ) {
			delete natName;
			natName = NULL;
		}

		if( natDescription != NULL ) {
			delete natDescription;
			natDescription = NULL;
		}

		if( attrName != NULL ) {
			delete attrName;
			attrName = NULL;
		}

		if( attrDescription != NULL ) {
			delete attrDescription;
			attrDescription = NULL;
		}

		if( attrIsSecure != NULL ) {
			delete attrIsSecure;
			attrIsSecure = NULL;
		}

		if( editURLProtocol != NULL ) {
			editURLProtocol->endEdit();
			editURLProtocol = NULL;
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

	void CFIntSaxLoaderURLProtocolHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
