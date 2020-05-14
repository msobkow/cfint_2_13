// Description: C++18 base object instance implementation for CFInt TopDomain.

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

using namespace std;

#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintobj/CFIntTopDomainObj.hpp>

namespace cfint {

	const std::string CFIntTopDomainObj::CLASS_NAME( "CFIntTopDomainObj" );
	const classcode_t CFIntTopDomainObj::CLASS_CODE = 0xa107L;

	int32_t CFIntTopDomainObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntTopDomainObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntTopDomainObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntTopDomainObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntTopDomainObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const int64_t CFIntTopDomainObj::getRequiredTldId() {
		return( getTopDomainBuff()->getRequiredTldId() );
	}

	const int64_t* CFIntTopDomainObj::getRequiredTldIdReference() {
		return( getTopDomainBuff()->getRequiredTldIdReference() );
	}

	const std::string& CFIntTopDomainObj::getRequiredName() {
		return( getTopDomainBuff()->getRequiredName() );
	}

	const std::string* CFIntTopDomainObj::getRequiredNameReference() {
		return( getTopDomainBuff()->getRequiredNameReference() );
	}

	bool CFIntTopDomainObj::isOptionalDescriptionNull() {
		return( getTopDomainBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntTopDomainObj::getOptionalDescriptionValue() {
		return( getTopDomainBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntTopDomainObj::getOptionalDescriptionReference() {
		return( getTopDomainBuff()->getOptionalDescriptionReference() );
	}


	cfsec::ICFSecTenantObj* CFIntTopDomainObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId(), forceRead );
		}
		return( retobj );
	}

	cfint::ICFIntTldObj* CFIntTopDomainObj::getRequiredContainerParentTld( bool forceRead ) {
		cfint::ICFIntTldObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTldTableObj()->readTldByIdIdx( getPKey()->getRequiredTenantId(),
					getTopDomainBuff()->getRequiredTldId(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfint::ICFIntLicenseObj*> CFIntTopDomainObj::getOptionalComponentsLicense( bool forceRead ) {
		std::vector<cfint::ICFIntLicenseObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getLicenseTableObj()->readLicenseByDomainIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfint::ICFIntTopProjectObj*> CFIntTopDomainObj::getOptionalComponentsTopProject( bool forceRead ) {
		std::vector<cfint::ICFIntTopProjectObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopProjectTableObj()->readTopProjectByTopDomainIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	CFIntTopDomainObj::CFIntTopDomainObj()
	: ICFIntTopDomainObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntTopDomainObj::CFIntTopDomainObj( cfint::ICFIntSchemaObj* argSchema )
	: ICFIntTopDomainObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntTopDomainObj::~CFIntTopDomainObj() {
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

	cfint::CFIntTopDomainBuff* CFIntTopDomainObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfint::CFIntTopDomainBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredTenantId(),
						getPKey()->getRequiredId() );
			}
		}
		return( buff );
	}

	void CFIntTopDomainObj::setBuff( cfint::CFIntTopDomainBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntTopDomainObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntTopDomainObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntTopDomainObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntTopDomainBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntTopDomainObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTopDomainObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_TldId( "TldId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntTopDomainObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntTopDomainObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntTopDomainObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntTopDomainObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntTopDomainObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntTopDomainObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntTopDomainObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TldId, CFIntTopDomainObj::getRequiredTldId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntTopDomainObj::getRequiredName() ) );
		if( ! CFIntTopDomainObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntTopDomainObj::getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntTopDomainObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntTopDomainObj::getGenDefName() {
		return( cfint::CFIntTopDomainBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntTopDomainObj::getScope() {
		cfint::ICFIntTldObj* scope = getRequiredContainerParentTld();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTopDomainObj::getObjScope() {
		cfint::ICFIntTldObj* scope = getRequiredContainerParentTld();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTopDomainObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntTopDomainObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntTopDomainObj::getNamedObject( const std::string& objName ) {
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
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getLicenseTableObj()->readLicenseByLookupUNameIdx( getRequiredTenantId(),
			getRequiredId(),
				nextName,
				false );
		}
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopProjectTableObj()->readTopProjectByLookupNameIdx( getRequiredTenantId(),
			getRequiredId(),
				nextName,
				false );
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

	std::string CFIntTopDomainObj::getObjQualifiedName() {
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

	std::string CFIntTopDomainObj::getObjFullName() {
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

	cfint::ICFIntTopDomainObj* CFIntTopDomainObj::realize() {
		cfint::ICFIntTopDomainObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopDomainTableObj()->realizeTopDomain(
			(cfint::ICFIntTopDomainObj*)this );
		return( dynamic_cast<cfint::ICFIntTopDomainObj*>( retobj ) );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainObj::read( bool forceRead ) {
		cfint::ICFIntTopDomainObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopDomainTableObj()->readTopDomainByIdIdx( getTopDomainBuff()->getRequiredTenantId(),
		getTopDomainBuff()->getRequiredId(), forceRead );
		return( dynamic_cast<cfint::ICFIntTopDomainObj*>( retobj ) );
	}

	cfint::ICFIntTopDomainTableObj* CFIntTopDomainObj::getTopDomainTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopDomainTableObj() );
	}

	cfint::ICFIntSchemaObj* CFIntTopDomainObj::getSchema() {
		return( schema );
	}

	void CFIntTopDomainObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = value;
	}

	cfint::CFIntTopDomainPKey* CFIntTopDomainObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfint::CFIntTopDomainPKey();
		}
		return( pKey );
	}

	void CFIntTopDomainObj::setPKey( cfint::CFIntTopDomainPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfint::CFIntTopDomainPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntTopDomainObj::getIsNew() {
		return( isNew );
	}

	void CFIntTopDomainObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfint::ICFIntTopDomainEditObj* CFIntTopDomainObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfint::ICFIntTopDomainObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopDomainTableObj()->lockTopDomain( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopDomainTableObj()->newEditInstance( this );
		return( dynamic_cast<cfint::ICFIntTopDomainEditObj*>( edit ) );
	}

	void CFIntTopDomainObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfint::ICFIntTopDomainEditObj* CFIntTopDomainObj::getEdit() {
		return( edit );
	}

	cfint::ICFIntTopDomainEditObj* CFIntTopDomainObj::getTopDomainEdit() {
		return( dynamic_cast<cfint::ICFIntTopDomainEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntTopDomainObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTopDomainBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntTopDomainObj::getCreatedAt() {
		return( getTopDomainBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntTopDomainObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTopDomainBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntTopDomainObj::getUpdatedAt() {
		return( getTopDomainBuff()->getUpdatedAt() );
	}

	void CFIntTopDomainObj::copyPKeyToBuff() {
		cfint::CFIntTopDomainPKey* tablePKey = getPKey();
		cfint::CFIntTopDomainBuff* tableBuff = getTopDomainEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
			tableBuff->setRequiredId( tablePKey->getRequiredId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntTopDomainObj::copyBuffToPKey() {
		cfint::CFIntTopDomainPKey* tablePKey = getPKey();
		cfint::CFIntTopDomainBuff* tableBuff = getTopDomainBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

}
