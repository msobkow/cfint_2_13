// Description: C++18 base object instance implementation for CFInt License.

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

using namespace std;

#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintobj/CFIntLicenseObj.hpp>

namespace cfint {

	const std::string CFIntLicenseObj::CLASS_NAME( "CFIntLicenseObj" );
	const classcode_t CFIntLicenseObj::CLASS_CODE = 0xa101L;

	int32_t CFIntLicenseObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntLicenseObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntLicenseObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntLicenseObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntLicenseObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const int64_t CFIntLicenseObj::getRequiredTopDomainId() {
		return( getLicenseBuff()->getRequiredTopDomainId() );
	}

	const int64_t* CFIntLicenseObj::getRequiredTopDomainIdReference() {
		return( getLicenseBuff()->getRequiredTopDomainIdReference() );
	}

	const std::string& CFIntLicenseObj::getRequiredName() {
		return( getLicenseBuff()->getRequiredName() );
	}

	const std::string* CFIntLicenseObj::getRequiredNameReference() {
		return( getLicenseBuff()->getRequiredNameReference() );
	}

	bool CFIntLicenseObj::isOptionalDescriptionNull() {
		return( getLicenseBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntLicenseObj::getOptionalDescriptionValue() {
		return( getLicenseBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntLicenseObj::getOptionalDescriptionReference() {
		return( getLicenseBuff()->getOptionalDescriptionReference() );
	}

	bool CFIntLicenseObj::isOptionalEmbeddedTextNull() {
		return( getLicenseBuff()->isOptionalEmbeddedTextNull() );
	}

	const std::string& CFIntLicenseObj::getOptionalEmbeddedTextValue() {
		return( getLicenseBuff()->getOptionalEmbeddedTextValue() );
	}

	const std::string* CFIntLicenseObj::getOptionalEmbeddedTextReference() {
		return( getLicenseBuff()->getOptionalEmbeddedTextReference() );
	}

	bool CFIntLicenseObj::isOptionalFullTextNull() {
		return( getLicenseBuff()->isOptionalFullTextNull() );
	}

	const std::string& CFIntLicenseObj::getOptionalFullTextValue() {
		return( getLicenseBuff()->getOptionalFullTextValue() );
	}

	const std::string* CFIntLicenseObj::getOptionalFullTextReference() {
		return( getLicenseBuff()->getOptionalFullTextReference() );
	}


	cfsec::ICFSecTenantObj* CFIntLicenseObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId(), forceRead );
		}
		return( retobj );
	}

	cfint::ICFIntTopDomainObj* CFIntLicenseObj::getRequiredContainerTopDomain( bool forceRead ) {
		cfint::ICFIntTopDomainObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopDomainTableObj()->readTopDomainByIdIdx( getPKey()->getRequiredTenantId(),
					getLicenseBuff()->getRequiredTopDomainId(), forceRead );
		}
		return( retobj );
	}

	CFIntLicenseObj::CFIntLicenseObj()
	: ICFIntLicenseObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntLicenseObj::CFIntLicenseObj( cfint::ICFIntSchemaObj* argSchema )
	: ICFIntLicenseObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntLicenseObj::~CFIntLicenseObj() {
		schema = NULL;
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}
		if( pKey != NULL ) {
			delete pKey;
			pKey = NULL;
		}

	}

	cfint::CFIntLicenseBuff* CFIntLicenseObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfint::CFIntLicenseBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredTenantId(),
						getPKey()->getRequiredId() );
			}
		}
		return( buff );
	}

	void CFIntLicenseObj::setBuff( cfint::CFIntLicenseBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntLicenseObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntLicenseObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntLicenseObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntLicenseBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntLicenseObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntLicenseObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_TopDomainId( "TopDomainId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		static const std::string S_EmbeddedText( "EmbeddedText" );
		static const std::string S_FullText( "FullText" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntLicenseObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntLicenseObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntLicenseObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopDomainId, CFIntLicenseObj::getRequiredTopDomainId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntLicenseObj::getRequiredName() ) );
		if( ! CFIntLicenseObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntLicenseObj::getOptionalDescriptionValue() ) );
		}
		if( ! CFIntLicenseObj::isOptionalEmbeddedTextNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EmbeddedText, CFIntLicenseObj::getOptionalEmbeddedTextValue() ) );
		}
		if( ! CFIntLicenseObj::isOptionalFullTextNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_FullText, CFIntLicenseObj::getOptionalFullTextValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntLicenseObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntLicenseObj::getGenDefName() {
		return( cfint::CFIntLicenseBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntLicenseObj::getScope() {
		cfint::ICFIntTopDomainObj* scope = getRequiredContainerTopDomain();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntLicenseObj::getObjScope() {
		cfint::ICFIntTopDomainObj* scope = getRequiredContainerTopDomain();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntLicenseObj::getObjQualifier( const classcode_t* qualifyingClass ) {
		cflib::ICFLibAnyObj* container = this;
		if( qualifyingClass != NULL ) {
			while( container != NULL ) {
				if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					break;
				}
				else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
					break;
				}
				else if( container->implementsClassCode( *qualifyingClass ) ) {
					break;
				}
				container = container->getObjScope();
			}
		}
		else {
			while( container != NULL ) {
				if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					break;
				}
				else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
					break;
				}
				container = container->getObjScope();
			}
		}
		return( container );
	}

	cflib::ICFLibAnyObj* CFIntLicenseObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntLicenseObj::getNamedObject( const std::string& objName ) {
		std::string nextName;
		std::string remainingName;
		cflib::ICFLibAnyObj* subObj = NULL;
		cflib::ICFLibAnyObj* retObj;
		int32_t nextDot = objName.find( '.' );
		if( nextDot >= 0 ) {
			nextName = objName.substr( 0, nextDot );
			remainingName = objName.substr( nextDot + 1 );
		}
		else {
			nextName.clear();
			nextName.append( objName );
			remainingName.clear();
		}
		if( remainingName.length() <= 0 ) {
			retObj = subObj;
		}
		else if( subObj == NULL ) {
			retObj = NULL;
		}
		else {
			retObj = subObj->getNamedObject( remainingName );
		}
		return( retObj );
	}

	std::string CFIntLicenseObj::getObjQualifiedName() {
		const static std::string S_Dot( "." );
		std::string qualName( getObjName() );
		cflib::ICFLibAnyObj* container = getObjScope();
		std::string containerName;
		std::string buildName;
		while( container != NULL ) {
			if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
				container = NULL;
			}
			else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
				container = NULL;
			}
			else if( container->implementsClassCode( cfsec::CFSecTenantBuff::CLASS_CODE ) ) {
				container = NULL;
			}
			else {
				containerName = container->getObjName();
				buildName.clear();
				buildName.append( containerName );
				buildName.append( S_Dot );
				buildName.append( qualName );
				qualName.clear();
				qualName.append( buildName );
				container = container->getObjScope();
			}
		}
		return( qualName );
	}

	std::string CFIntLicenseObj::getObjFullName() {
		const static std::string S_Dot( "." );
		std::string fullName = getObjName();
		cflib::ICFLibAnyObj* container = getObjScope();
		std::string containerName;
		std::string buildName;
		while( container != NULL ) {
			if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
				container = NULL;
			}
			else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
				container = NULL;
			}
			else {
				containerName = container->getObjName();
				buildName.clear();
				buildName.append( containerName );
				buildName.append( S_Dot );
				buildName.append( fullName );
				fullName.clear();
				fullName.append( buildName );
				container = container->getObjScope();
			}
		}
		return( fullName );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseObj::realize() {
		cfint::ICFIntLicenseObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getLicenseTableObj()->realizeLicense(
			(cfint::ICFIntLicenseObj*)this );
		return( dynamic_cast<cfint::ICFIntLicenseObj*>( retobj ) );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseObj::read( bool forceRead ) {
		cfint::ICFIntLicenseObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getLicenseTableObj()->readLicenseByIdIdx( getLicenseBuff()->getRequiredTenantId(),
		getLicenseBuff()->getRequiredId(), forceRead );
		return( dynamic_cast<cfint::ICFIntLicenseObj*>( retobj ) );
	}

	cfint::ICFIntLicenseTableObj* CFIntLicenseObj::getLicenseTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getLicenseTableObj() );
	}

	cfint::ICFIntSchemaObj* CFIntLicenseObj::getSchema() {
		return( schema );
	}

	void CFIntLicenseObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = value;
	}

	cfint::CFIntLicensePKey* CFIntLicenseObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfint::CFIntLicensePKey();
		}
		return( pKey );
	}

	void CFIntLicenseObj::setPKey( cfint::CFIntLicensePKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfint::CFIntLicensePKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntLicenseObj::getIsNew() {
		return( isNew );
	}

	void CFIntLicenseObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfint::ICFIntLicenseEditObj* CFIntLicenseObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfint::ICFIntLicenseObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getLicenseTableObj()->lockLicense( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getLicenseTableObj()->newEditInstance( this );
		return( dynamic_cast<cfint::ICFIntLicenseEditObj*>( edit ) );
	}

	void CFIntLicenseObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfint::ICFIntLicenseEditObj* CFIntLicenseObj::getEdit() {
		return( edit );
	}

	cfint::ICFIntLicenseEditObj* CFIntLicenseObj::getLicenseEdit() {
		return( dynamic_cast<cfint::ICFIntLicenseEditObj*>( edit ) );
	}

	void CFIntLicenseObj::copyPKeyToBuff() {
		cfint::CFIntLicensePKey* tablePKey = getPKey();
		cfint::CFIntLicenseBuff* tableBuff = getLicenseEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
			tableBuff->setRequiredId( tablePKey->getRequiredId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntLicenseObj::copyBuffToPKey() {
		cfint::CFIntLicensePKey* tablePKey = getPKey();
		cfint::CFIntLicenseBuff* tableBuff = getLicenseBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

}
