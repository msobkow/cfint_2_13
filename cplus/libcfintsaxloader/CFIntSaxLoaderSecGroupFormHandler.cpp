
// Description: C++18 XML SAX2 Element Handler implementation for SecGroupForm

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
#include <cfintsaxloader/CFIntSaxLoaderSecGroupFormHandler.hpp>

using namespace std;

namespace cfint {

	const std::string CFIntSaxLoaderSecGroupFormHandler::CLASS_NAME( "CFIntSaxLoaderSecGroupFormHandler" );
	const std::string CFIntSaxLoaderSecGroupFormHandler::S_True( "true" );
	const std::string CFIntSaxLoaderSecGroupFormHandler::S_False( "false" );
	const std::string CFIntSaxLoaderSecGroupFormHandler::S_Yes( "yes" );
	const std::string CFIntSaxLoaderSecGroupFormHandler::S_No( "no" );
	const std::string CFIntSaxLoaderSecGroupFormHandler::S_0( "0" );
	const std::string CFIntSaxLoaderSecGroupFormHandler::S_1( "1" );

	CFIntSaxLoaderSecGroupFormHandler::CFIntSaxLoaderSecGroupFormHandler( cfint::CFIntSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFIntSaxLoaderSecGroupFormHandler::~CFIntSaxLoaderSecGroupFormHandler() {
	}

	void CFIntSaxLoaderSecGroupFormHandler::startElement (
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
		static const std::string S_SecGroupFormId( "SecGroupFormId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_SecAppId( "SecAppId" );
		static const std::string S_SecFormId( "SecFormId" );
		static const std::string S_Cluster( "Cluster" );
		static const std::string S_Group( "Group" );
		static const std::string S_App( "App" );
		static const std::string S_Form( "Form" );
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
		cfsec::ICFSecSecGroupFormObj* tmpBuff = NULL;
		cfsec::ICFSecSecGroupFormEditObj* editBuff = NULL;
		cfsec::ICFSecSecGroupFormEditObj* editSecGroupForm = NULL;
		cfsec::ICFSecSecGroupFormObj* origSecGroupForm = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// SecGroupForm Attributes
		std::string* attrApp = NULL;
		std::string* attrForm = NULL;
		// SecGroupForm References
		cfsec::ICFSecClusterObj* refCluster = NULL;
		cfsec::ICFSecSecGroupObj* refGroup = NULL;
		cfsec::ICFSecSecAppObj* refApp = NULL;
		cfsec::ICFSecSecFormObj* refForm = NULL;
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
			if( cppQName != cfsec::CFSecSecGroupFormBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfsec::CFSecSecGroupFormBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getSecGroupFormTableObj()->newInstance();
			editBuff = dynamic_cast<cfsec::ICFSecSecGroupFormEditObj*>( tmpBuff->beginEdit() );

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
				else if( *attrLocalName == S_App ) {
					if( attrApp != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrApp = new std::string( *cppValue );
					}
					else {
						attrApp = NULL;
					}
				}
				else if( *attrLocalName == S_Form ) {
					if( attrForm != NULL ) {
						throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
							S_ProcName,
							*attrLocalName );
					}
					if( cppValue != NULL ) {
						attrForm = new std::string( *cppValue );
					}
					else {
						attrForm = NULL;
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
			if( ( attrApp == NULL ) || ( attrApp->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_App );
			}
			if( ( attrForm == NULL ) || ( attrForm->length() <= 0 ) ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Form );
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
			if( attrApp != NULL ) {
				curContext->putNamedTag( S_App, *attrApp );
			}
			if( attrForm != NULL ) {
				curContext->putNamedTag( S_Form, *attrForm );
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

			// Lookup refApp by key name value attr
			if( ( attrApp != NULL ) && ( attrApp->length() > 0 ) ) {
				refApp = schemaObj->getSecAppTableObj()->readSecAppByUJEEMountIdx( editBuff->getRequiredClusterId(),
					*attrApp );
				if( refApp == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Resolve App reference named \"" + *attrApp + "\" to table SecApp" );
				}
			}
			else {
				refApp = NULL;
			}
			editBuff->setRequiredParentApp( refApp );

			// Lookup refForm by key name value attr
			if( ( attrForm != NULL ) && ( attrForm->length() > 0 ) ) {
				refForm = schemaObj->getSecFormTableObj()->readSecFormByUJEEServletIdx( editBuff->getRequiredClusterId(),
					editBuff->getRequiredSecAppId(),
					*attrForm );
				if( refForm == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Resolve Form reference named \"" + *attrForm + "\" to table SecForm" );
				}
			}
			else {
				refForm = NULL;
			}
			editBuff->setRequiredParentForm( refForm );

			editSecGroupForm = editBuff;
			editBuff = NULL;
			origSecGroupForm = dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( editSecGroupForm->create() );
			editSecGroupForm = NULL;
			tmpBuff = NULL;

			curContext->setObj( origSecGroupForm );

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

		if( attrApp != NULL ) {
			delete attrApp;
			attrApp = NULL;
		}

		if( attrForm != NULL ) {
			delete attrForm;
			attrForm = NULL;
		}

		if( editSecGroupForm != NULL ) {
			editSecGroupForm->endEdit();
			editSecGroupForm = NULL;
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

	void CFIntSaxLoaderSecGroupFormHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}