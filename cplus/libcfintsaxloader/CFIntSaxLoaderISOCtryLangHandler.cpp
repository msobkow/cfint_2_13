
// Description: C++18 XML SAX2 Element Handler implementation for ISOCtryLang

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

#include <cflib/ICFLibPublic.hpp>
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintsaxloader/CFIntSaxLoader.hpp>
#include <cfintsaxloader/CFIntSaxLoaderISOCtryLangHandler.hpp>

using namespace std;

namespace cfint {

	const std::string CFIntSaxLoaderISOCtryLangHandler::CLASS_NAME( "CFIntSaxLoaderISOCtryLangHandler" );
	const std::string CFIntSaxLoaderISOCtryLangHandler::S_True( "true" );
	const std::string CFIntSaxLoaderISOCtryLangHandler::S_False( "false" );
	const std::string CFIntSaxLoaderISOCtryLangHandler::S_Yes( "yes" );
	const std::string CFIntSaxLoaderISOCtryLangHandler::S_No( "no" );
	const std::string CFIntSaxLoaderISOCtryLangHandler::S_0( "0" );
	const std::string CFIntSaxLoaderISOCtryLangHandler::S_1( "1" );

	CFIntSaxLoaderISOCtryLangHandler::CFIntSaxLoaderISOCtryLangHandler( cfint::CFIntSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFIntSaxLoaderISOCtryLangHandler::~CFIntSaxLoaderISOCtryLangHandler() {
	}

	void CFIntSaxLoaderISOCtryLangHandler::startElement (
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
		static const std::string S_ISOLangId( "ISOLangId" );
		static const std::string S_Ctry( "Ctry" );
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
		cfsec::ICFSecISOCtryLangObj* tmpBuff = NULL;
		cfsec::ICFSecISOCtryLangEditObj* editBuff = NULL;
		cfsec::ICFSecISOCtryLangEditObj* editISOCtryLang = NULL;
		cfsec::ICFSecISOCtryLangObj* origISOCtryLang = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// ISOCtryLang Attributes
		std::string* attrLang = NULL;
		// ISOCtryLang References
		cfsec::ICFSecISOCtryObj* refCtry = NULL;
		cfsec::ICFSecISOLangObj* refLang = NULL;
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
			if( cppQName != cfsec::CFSecISOCtryLangBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecISOCtryLangBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getISOCtryLangTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecISOCtryLangEditObj*>( tmpBuff->beginEdit() );

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
				else if( *attrLocalName == S_Lang ) {
					if( attrLang != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrLang = new std::string( *cppValue );
					}
					else {
						attrLang = NULL;
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
			if( ( attrLang == NULL ) || ( attrLang->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Lang );
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
			if( attrLang != NULL ) {
				curContext->putNamedTag( S_Lang, *attrLang );
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
			else if( scopeObj->implementsClassCode( cfsec::CFSecISOCtryBuff::CLASS_CODE ) ) {
				refCtry = dynamic_cast<cfsec::ICFSecISOCtryObj*>( scopeObj );
				editBuff->setRequiredContainerCtry( refCtry );
			}
			else {
				throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFIntISOCtryObj" );
			}

			// Lookup refLang by key name value attr
			if( ( attrLang != NULL ) && ( attrLang->length() > 0 ) ) {
				refLang = schemaObj->getISOLangTableObj()->readISOLangByCode3Idx( *attrLang );
				if( refLang == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Resolve Lang reference named \"" + *attrLang + "\" to table ISOLang" );
				}
			}
			else {
				refLang = NULL;
			}
			editBuff->setRequiredParentLang( refLang );

			editISOCtryLang = editBuff;
			editBuff = NULL;
			origISOCtryLang = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( editISOCtryLang->create() );
			editISOCtryLang = NULL;
			tmpBuff = NULL;

			curContext->setObj( origISOCtryLang );

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

		if( attrLang != NULL ) {
			delete attrLang;
			attrLang = NULL;
		}

		if( editISOCtryLang != NULL ) {
			editISOCtryLang->endEdit();
			editISOCtryLang = NULL;
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

	void CFIntSaxLoaderISOCtryLangHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
