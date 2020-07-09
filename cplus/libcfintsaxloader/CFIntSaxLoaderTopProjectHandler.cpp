
// Description: C++18 XML SAX2 Element Handler implementation for TopProject

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
#include <cfintsaxloader/CFIntSaxLoaderTopProjectHandler.hpp>

using namespace std;

namespace cfint {

	const std::string CFIntSaxLoaderTopProjectHandler::CLASS_NAME( "CFIntSaxLoaderTopProjectHandler" );
	const std::string CFIntSaxLoaderTopProjectHandler::S_True( "true" );
	const std::string CFIntSaxLoaderTopProjectHandler::S_False( "false" );
	const std::string CFIntSaxLoaderTopProjectHandler::S_Yes( "yes" );
	const std::string CFIntSaxLoaderTopProjectHandler::S_No( "no" );
	const std::string CFIntSaxLoaderTopProjectHandler::S_0( "0" );
	const std::string CFIntSaxLoaderTopProjectHandler::S_1( "1" );

	CFIntSaxLoaderTopProjectHandler::CFIntSaxLoaderTopProjectHandler( cfint::CFIntSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFIntSaxLoaderTopProjectHandler::~CFIntSaxLoaderTopProjectHandler() {
	}

	void CFIntSaxLoaderTopProjectHandler::startElement (
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
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_TopDomainId( "TopDomainId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		static const std::string S_Tenant( "Tenant" );
		static const std::string S_ParentSDom( "ParentSDom" );
		static const std::string S_SubProject( "SubProject" );
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
		cfint::ICFIntTopProjectObj* tmpBuff = NULL;
		cfint::ICFIntTopProjectEditObj* editBuff = NULL;
		cfint::ICFIntTopProjectEditObj* editTopProject = NULL;
		cfint::ICFIntTopProjectObj* origTopProject = NULL;
		cflib::CFLibXmlCoreContext* parentContext = NULL;
		cflib::ICFLibAnyObj* scopeObj = NULL;
		// Common XML Attributes
		std::string* attrId = NULL;
		// TopProject Attributes
		std::string* attrName = NULL;
		std::string* attrDescription = NULL;
		// TopProject References
		cfsec::ICFSecTenantObj* refTenant = NULL;
		cfint::ICFIntTopDomainObj* refParentSDom = NULL;
		std::string* natName = NULL;
		std::string* natDescription = NULL;
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
			if( cppQName != cfint::CFIntTopProjectBuff::GENDEFNAME ) {
				std::string Msg( "Expected QName to be '" + cfint::CFIntTopProjectBuff::GENDEFNAME + "'" );
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
			tmpBuff = schemaObj->getTopProjectTableObj()->newInstance();
			editBuff = dynamic_cast<cfint::ICFIntTopProjectEditObj*>( tmpBuff->beginEdit() );

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
			if( natDescription != NULL ) {
				editBuff->setOptionalDescriptionValue( *natDescription );
			}
			else {
				editBuff->setOptionalDescriptionNull();
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
			else if( scopeObj->implementsClassCode( cfint::CFIntTopDomainBuff::CLASS_CODE ) ) {
				refParentSDom = dynamic_cast<cfint::ICFIntTopDomainObj*>( scopeObj );
				editBuff->setRequiredContainerParentSDom( refParentSDom );
			refTenant = editBuff->getRequiredOwnerTenant();
			}
			else {
				throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
					S_ProcName,
					"scopeObj",
					scopeObj,
					"ICFIntTopDomainObj" );
			}

			// Resolve and apply Owner reference

			if( refTenant == NULL ) {
				if( scopeObj->implementsClassCode( cfsec::CFSecTenantBuff::CLASS_CODE ) ) {
					refTenant = dynamic_cast<cfsec::ICFSecTenantObj*>( scopeObj );
					editBuff->setRequiredOwnerTenant( refTenant );
				}
				else {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"Owner<Tenant>" );
				}
			}

			loaderBehaviour = saxLoader->getTopProjectLoaderBehaviour();
			origTopProject = dynamic_cast<cfint::ICFIntTopProjectObj*>( schemaObj->getTopProjectTableObj()->readTopProjectByNameIdx( refTenant->getRequiredId(),
			refParentSDom->getRequiredId(),
			editBuff->getRequiredName() ) );
			if( origTopProject == NULL ) {
				editTopProject = editBuff;
				editBuff = NULL;
			}
			else {
				switch( loaderBehaviour ) {
					case cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert:
						editTopProject = NULL;
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update:
						editTopProject = dynamic_cast<cfint::ICFIntTopProjectEditObj*>( origTopProject->beginEdit() );
						editTopProject->setRequiredName( editBuff->getRequiredName() );
						if( editBuff->isOptionalDescriptionNull() ) {
							editTopProject->setOptionalDescriptionNull();
						}
						else {
							editTopProject->setOptionalDescriptionValue( editBuff->getOptionalDescriptionValue() );
						}
						editBuff->endEdit();
						editBuff = NULL;
						break;
					case cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace:
						editTopProject = dynamic_cast<cfint::ICFIntTopProjectEditObj*>( origTopProject->beginEdit() );
						editTopProject->deleteInstance();
						editTopProject = NULL;
						origTopProject = NULL;
						editTopProject = editBuff;
						editBuff = NULL;
						break;
				}
			}

			if( editTopProject != NULL ) {
				if( origTopProject != NULL ) {
					editTopProject->update();
				}
				else {
					origTopProject = dynamic_cast<cfint::ICFIntTopProjectObj*>( editTopProject->create() );
				}
				editTopProject = NULL;
			}

			if( ! tmpBuff->getIsNew() ) {
				tmpBuff = NULL;
			}

			curContext->setObj( origTopProject );

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

		if( editTopProject != NULL ) {
			editTopProject->endEdit();
			editTopProject = NULL;
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

	void CFIntSaxLoaderTopProjectHandler::endElement(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}
}
