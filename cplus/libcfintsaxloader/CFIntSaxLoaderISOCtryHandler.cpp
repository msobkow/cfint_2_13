
// Description: C++18 XML SAX2 Element Handler implementation for ISOCtry

/*
 *	org.msscf.msscf.CFInt
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

#include <cflib/ICFLibPublic.hpp>
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintsaxloader/CFIntSaxLoader.hpp>
#include <cfintsaxloader/CFIntSaxLoaderISOCtryHandler.hpp>

using namespace std;

namespace cfint {

	const std::string CFIntSaxLoaderISOCtryHandler::CLASS_NAME( "CFIntSaxLoaderISOCtryHandler" );
	const std::string CFIntSaxLoaderISOCtryHandler::S_True( "true" );
	const std::string CFIntSaxLoaderISOCtryHandler::S_False( "false" );
	const std::string CFIntSaxLoaderISOCtryHandler::S_Yes( "yes" );
	const std::string CFIntSaxLoaderISOCtryHandler::S_No( "no" );
	const std::string CFIntSaxLoaderISOCtryHandler::S_0( "0" );
	const std::string CFIntSaxLoaderISOCtryHandler::S_1( "1" );

	CFIntSaxLoaderISOCtryHandler::CFIntSaxLoaderISOCtryHandler( cfint::CFIntSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFIntSaxLoaderISOCtryHandler::~CFIntSaxLoaderISOCtryHandler() {
	}

	void CFIntSaxLoaderISOCtryHandler::startElement (
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
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOCode( "ISOCode" );
		static const std::string S_Name( "Name" );
		static const std::string S_Ccy( "Ccy" );
		static const std::string S_Lang( "Lang" );
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
		cfsec::ICFSecISOCtryObj* tmpBuff = NULL;
		cfsec::ICFSecISOCtryEditObj* editBuff = NULL;
		cfsec::ICFSecISOCtryEditObj* editISOCtry = NULL;
		cfsec::ICFSecISOCtryObj* origISOCtry = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// ISOCtry Attributes
		std::string* attrISOCode = NULL;
		std::string* attrName = NULL;
		// ISOCtry References
		std::string* natISOCode = NULL;
		std::string* natName = NULL;
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
			if( cppQName != cfsec::CFSecISOCtryBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecISOCtryBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getISOCtryTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecISOCtryEditObj*>( tmpBuff->beginEdit() );

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
				else if( *attrLocalName == S_ISOCode ) {
					if( attrISOCode != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrISOCode = new std::string( *cppValue );
					}
					else {
						attrISOCode = NULL;
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
			if( attrISOCode == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ISOCode );
			}
			if( attrName == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Name );
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
			if( attrISOCode != NULL ) {
				curContext->putNamedTag( S_ISOCode, *attrISOCode );
			}
			if( attrName != NULL ) {
				curContext->putNamedTag( S_Name, *attrName );
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
			if( attrISOCode != NULL ) {
				natISOCode = new std::string( *attrISOCode );
			}
			else {
				natISOCode = NULL;
			}
			if( natISOCode == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ISOCode );
			}
			editBuff->setRequiredISOCode( *natISOCode );

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

			// Get the scope/container object

			parentContext = curContext->getPrevContext();
			if( parentContext != NULL ) {
				scopeObj = parentContext->getObj();
			}
			else {
				scopeObj = NULL;
			}

			loaderBehaviour = saxLoader->getISOCtryLoaderBehaviour();
			origISOCtry = dynamic_cast<cfsec::ICFSecISOCtryObj*>( schemaObj->getISOCtryTableObj()->readISOCtryByISOCodeIdx( editBuff->getRequiredISOCode() ) );
			if( origISOCtry == NULL ) {
				editISOCtry = editBuff;
				editBuff = NULL;
			}
			else {
				switch( loaderBehaviour ) {
					case cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert:
						editISOCtry = NULL;
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update:
						editISOCtry = dynamic_cast<cfsec::ICFSecISOCtryEditObj*>( origISOCtry->beginEdit() );
						editISOCtry->setRequiredISOCode( editBuff->getRequiredISOCode() );
						editISOCtry->setRequiredName( editBuff->getRequiredName() );
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace:
						editISOCtry = dynamic_cast<cfsec::ICFSecISOCtryEditObj*>( origISOCtry->beginEdit() );
						editISOCtry->deleteInstance();
						editISOCtry = NULL;
						origISOCtry = NULL;
						editISOCtry = editBuff;
						editBuff = NULL;
						break;
				}
			}

			if( editISOCtry != NULL ) {
				if( origISOCtry != NULL ) {
					editISOCtry->update();
				}
				else {
					origISOCtry = dynamic_cast<cfsec::ICFSecISOCtryObj*>( editISOCtry->create() );
				}
				editISOCtry = NULL;
			}

			if( ! tmpBuff->getIsNew() ) {
				tmpBuff = NULL;
			}

			curContext->setObj( origISOCtry );

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

		if( natISOCode != NULL ) {
			delete natISOCode;
			natISOCode = NULL;
		}

		if( natName != NULL ) {
			delete natName;
			natName = NULL;
		}

		if( attrISOCode != NULL ) {
			delete attrISOCode;
			attrISOCode = NULL;
		}

		if( attrName != NULL ) {
			delete attrName;
			attrName = NULL;
		}

		if( editISOCtry != NULL ) {
			editISOCtry->endEdit();
			editISOCtry = NULL;
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

	void CFIntSaxLoaderISOCtryHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
