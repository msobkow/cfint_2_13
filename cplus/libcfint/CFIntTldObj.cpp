// Description: C++18 base object instance implementation for CFInt Tld.

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
#include <cfintobj/CFIntTldObj.hpp>

namespace cfint {

	const std::string CFIntTldObj::CLASS_NAME( "CFIntTldObj" );
	const classcode_t CFIntTldObj::CLASS_CODE = 0xa106L;

	int32_t CFIntTldObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntTldObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntTldObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntTldObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntTldObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const std::string& CFIntTldObj::getRequiredName() {
		return( getTldBuff()->getRequiredName() );
	}

	const std::string* CFIntTldObj::getRequiredNameReference() {
		return( getTldBuff()->getRequiredNameReference() );
	}

	bool CFIntTldObj::isOptionalDescriptionNull() {
		return( getTldBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntTldObj::getOptionalDescriptionValue() {
		return( getTldBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntTldObj::getOptionalDescriptionReference() {
		return( getTldBuff()->getOptionalDescriptionReference() );
	}


	cfsec::ICFSecTenantObj* CFIntTldObj::getRequiredContainerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfint::ICFIntTopDomainObj*> CFIntTldObj::getOptionalComponentsTopDomain( bool forceRead ) {
		std::vector<cfint::ICFIntTopDomainObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopDomainTableObj()->readTopDomainByTldIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	CFIntTldObj::CFIntTldObj()
	: ICFIntTldObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntTldObj::CFIntTldObj( cfint::ICFIntSchemaObj* argSchema )
	: ICFIntTldObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntTldObj::~CFIntTldObj() {
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

	cfint::CFIntTldBuff* CFIntTldObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfint::CFIntTldBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredTenantId(),
						getPKey()->getRequiredId() );
			}
		}
		return( buff );
	}

	void CFIntTldObj::setBuff( cfint::CFIntTldBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntTldObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntTldObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntTldObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntTldBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntTldObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTldObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntTldObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntTldObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntTldObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntTldObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntTldObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntTldObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntTldObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntTldObj::getRequiredName() ) );
		if( ! CFIntTldObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntTldObj::getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntTldObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntTldObj::getGenDefName() {
		return( cfint::CFIntTldBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntTldObj::getScope() {
		cfsec::ICFSecTenantObj* scope = getRequiredContainerTenant();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTldObj::getObjScope() {
		cfsec::ICFSecTenantObj* scope = getRequiredContainerTenant();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTldObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntTldObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntTldObj::getNamedObject( const std::string& objName ) {
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
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopDomainTableObj()->readTopDomainByLookupNameIdx( getRequiredTenantId(),
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

	std::string CFIntTldObj::getObjQualifiedName() {
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

	std::string CFIntTldObj::getObjFullName() {
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

	cfint::ICFIntTldObj* CFIntTldObj::realize() {
		cfint::ICFIntTldObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTldTableObj()->realizeTld(
			(cfint::ICFIntTldObj*)this );
		return( dynamic_cast<cfint::ICFIntTldObj*>( retobj ) );
	}

	cfint::ICFIntTldObj* CFIntTldObj::read( bool forceRead ) {
		cfint::ICFIntTldObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTldTableObj()->readTldByIdIdx( getTldBuff()->getRequiredTenantId(),
		getTldBuff()->getRequiredId(), forceRead );
		return( dynamic_cast<cfint::ICFIntTldObj*>( retobj ) );
	}

	cfint::ICFIntTldTableObj* CFIntTldObj::getTldTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTldTableObj() );
	}

	cfint::ICFIntSchemaObj* CFIntTldObj::getSchema() {
		return( schema );
	}

	void CFIntTldObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = value;
	}

	cfint::CFIntTldPKey* CFIntTldObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfint::CFIntTldPKey();
		}
		return( pKey );
	}

	void CFIntTldObj::setPKey( cfint::CFIntTldPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfint::CFIntTldPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntTldObj::getIsNew() {
		return( isNew );
	}

	void CFIntTldObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfint::ICFIntTldEditObj* CFIntTldObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfint::ICFIntTldObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTldTableObj()->lockTld( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTldTableObj()->newEditInstance( this );
		return( dynamic_cast<cfint::ICFIntTldEditObj*>( edit ) );
	}

	void CFIntTldObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfint::ICFIntTldEditObj* CFIntTldObj::getEdit() {
		return( edit );
	}

	cfint::ICFIntTldEditObj* CFIntTldObj::getTldEdit() {
		return( dynamic_cast<cfint::ICFIntTldEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntTldObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTldBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntTldObj::getCreatedAt() {
		return( getTldBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntTldObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTldBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntTldObj::getUpdatedAt() {
		return( getTldBuff()->getUpdatedAt() );
	}

	void CFIntTldObj::copyPKeyToBuff() {
		cfint::CFIntTldPKey* tablePKey = getPKey();
		cfint::CFIntTldBuff* tableBuff = getTldEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
			tableBuff->setRequiredId( tablePKey->getRequiredId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntTldObj::copyBuffToPKey() {
		cfint::CFIntTldPKey* tablePKey = getPKey();
		cfint::CFIntTldBuff* tableBuff = getTldBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

}
