// Description: C++18 edit object instance implementation for CFInt TopDomain.

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
#include <cfintobj/CFIntTopDomainEditObj.hpp>


namespace cfint {

	const std::string CFIntTopDomainEditObj::CLASS_NAME( "CFIntTopDomainEditObj" );

	CFIntTopDomainEditObj::CFIntTopDomainEditObj( cfint::ICFIntTopDomainObj* argOrig )
	: ICFIntTopDomainEditObj()
	{
		static const std::string S_ProcName( "CFIntTopDomainEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfint::CFIntTopDomainBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfint::CFIntTopDomainBuff*>( origBuff->clone() );
	}

	CFIntTopDomainEditObj::~CFIntTopDomainEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntTopDomainEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntTopDomainEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTopDomainBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntTopDomainEditObj::getCreatedAt() {
		return( getTopDomainBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntTopDomainEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTopDomainBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntTopDomainEditObj::getUpdatedAt() {
		return( getTopDomainBuff()->getUpdatedAt() );
	}

	void CFIntTopDomainEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getTopDomainEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTopDomainEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getTopDomainEditBuff()->setCreatedAt( value );
	}

	void CFIntTopDomainEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getTopDomainEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTopDomainEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getTopDomainEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntTopDomainEditObj::getClassCode() const {
		return( cfint::CFIntTopDomainBuff::CLASS_CODE );
	}

	bool CFIntTopDomainEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntTopDomainBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntTopDomainEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTopDomainEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntTopDomainEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntTopDomainEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntTopDomainEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntTopDomainEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntTopDomainEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntTopDomainEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntTopDomainEditObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TldId, CFIntTopDomainEditObj::getRequiredTldId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntTopDomainEditObj::getRequiredName() ) );
		if( ! CFIntTopDomainEditObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntTopDomainEditObj::getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntTopDomainEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntTopDomainEditObj::setRequiredRevision( int32_t value ) {
		getTopDomainEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntTopDomainEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntTopDomainEditObj::getGenDefName() {
		return( cfint::CFIntTopDomainBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntTopDomainEditObj::getScope() {
		cfint::ICFIntTldObj* scope = getRequiredContainerParentTld();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTopDomainEditObj::getObjScope() {
		cfint::ICFIntTldObj* scope = getRequiredContainerParentTld();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTopDomainEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntTopDomainEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntTopDomainEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntTopDomainEditObj::getObjQualifiedName() {
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

	std::string CFIntTopDomainEditObj::getObjFullName() {
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

	cfint::ICFIntTopDomainObj* CFIntTopDomainEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfint::ICFIntTopDomainObj* retobj = getSchema()->getTopDomainTableObj()->realizeTopDomain( dynamic_cast<cfint::ICFIntTopDomainObj*>( this ) );
		return( retobj );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainEditObj::read( bool forceRead ) {
		cfint::ICFIntTopDomainObj* retval = getOrigAsTopDomain()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainEditObj::create() {
		cfint::ICFIntTopDomainObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTopDomain()->getSchema() )->getTopDomainTableObj()->createTopDomain( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfint::ICFIntTopDomainEditObj* CFIntTopDomainEditObj::update() {
		getSchema()->getTopDomainTableObj()->updateTopDomain( this );
		return( NULL );
	}

	cfint::ICFIntTopDomainEditObj* CFIntTopDomainEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getTopDomainTableObj()->deleteTopDomain( this );
		return( NULL );
	}

	cfint::ICFIntTopDomainTableObj* CFIntTopDomainEditObj::getTopDomainTable() {
		return( orig->getSchema()->getTopDomainTableObj() );
	}

	cfint::ICFIntTopDomainEditObj* CFIntTopDomainEditObj::getEdit() {
		return( this );
	}

	cfint::ICFIntTopDomainEditObj* CFIntTopDomainEditObj::getTopDomainEdit() {
		return( (cfint::ICFIntTopDomainEditObj*)this );
	}

	cfint::ICFIntTopDomainEditObj* CFIntTopDomainEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntTopDomainEditObj::endEdit() {
		orig->endEdit();
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainEditObj::getOrig() {
		return( orig );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainEditObj::getOrigAsTopDomain() {
		return( dynamic_cast<cfint::ICFIntTopDomainObj*>( orig ) );
	}

	cfint::ICFIntSchemaObj* CFIntTopDomainEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfint::CFIntTopDomainBuff* CFIntTopDomainEditObj::getBuff() {
		return( buff );
	}

	void CFIntTopDomainEditObj::setBuff( cfint::CFIntTopDomainBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfint::CFIntTopDomainPKey* CFIntTopDomainEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntTopDomainEditObj::setPKey( cfint::CFIntTopDomainPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntTopDomainEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntTopDomainEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntTopDomainEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntTopDomainEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntTopDomainEditObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntTopDomainEditObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const int64_t CFIntTopDomainEditObj::getRequiredTldId() {
		return( getTopDomainBuff()->getRequiredTldId() );
	}

	const int64_t* CFIntTopDomainEditObj::getRequiredTldIdReference() {
		return( getTopDomainBuff()->getRequiredTldIdReference() );
	}

	const std::string& CFIntTopDomainEditObj::getRequiredName() {
		return( getTopDomainBuff()->getRequiredName() );
	}

	const std::string* CFIntTopDomainEditObj::getRequiredNameReference() {
		return( getTopDomainBuff()->getRequiredNameReference() );
	}

	void CFIntTopDomainEditObj::setRequiredName( const std::string& value ) {
		if( getTopDomainBuff()->getRequiredName() != value ) {
			getTopDomainEditBuff()->setRequiredName( value );
		}
	}

	bool CFIntTopDomainEditObj::isOptionalDescriptionNull() {
		return( getTopDomainBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntTopDomainEditObj::getOptionalDescriptionValue() {
		return( getTopDomainBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntTopDomainEditObj::getOptionalDescriptionReference() {
		return( getTopDomainBuff()->getOptionalDescriptionReference() );
	}

	void CFIntTopDomainEditObj::setOptionalDescriptionNull() {
		if( ! getTopDomainBuff()->isOptionalDescriptionNull() ) {
			getTopDomainEditBuff()->setOptionalDescriptionNull();
		}
	}

	void CFIntTopDomainEditObj::setOptionalDescriptionValue( const std::string& value ) {
		if( getTopDomainBuff()->isOptionalDescriptionNull() ) {
			getTopDomainEditBuff()->setOptionalDescriptionValue( value );
		}
		else if( getTopDomainBuff()->getOptionalDescriptionValue() != value ) {
			getTopDomainEditBuff()->setOptionalDescriptionValue( value );
		}
	}

	cfsec::ICFSecTenantObj* CFIntTopDomainEditObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTopDomain()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFIntTopDomainEditObj::setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getTopDomainEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	cfint::ICFIntTldObj* CFIntTopDomainEditObj::getRequiredContainerParentTld( bool forceRead ) {
		cfint::ICFIntTldObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTopDomain()->getSchema() )->getTldTableObj()->readTldByIdIdx( getPKey()->getRequiredTenantId(),
					getTopDomainBuff()->getRequiredTldId() );
		}
		return( retobj );
	}

	void CFIntTopDomainEditObj::setRequiredContainerParentTld( cfint::ICFIntTldObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredTenantId() );
				getTopDomainEditBuff()->setRequiredTenantId( value->getRequiredTenantId() );
				getTopDomainEditBuff()->setRequiredTldId( value->getRequiredId() );
			}
		}

	std::vector<cfint::ICFIntLicenseObj*> CFIntTopDomainEditObj::getOptionalComponentsLicense( bool forceRead ) {
		std::vector<cfint::ICFIntLicenseObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTopDomain()->getSchema() )->getLicenseTableObj()->readLicenseByDomainIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfint::ICFIntTopProjectObj*> CFIntTopDomainEditObj::getOptionalComponentsTopProject( bool forceRead ) {
		std::vector<cfint::ICFIntTopProjectObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTopDomain()->getSchema() )->getTopProjectTableObj()->readTopProjectByTopDomainIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	void CFIntTopDomainEditObj::copyPKeyToBuff() {
		cfint::CFIntTopDomainPKey* tablePKey = getPKey();
		cfint::CFIntTopDomainBuff* tableBuff = getTopDomainEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredId( tablePKey->getRequiredId() );
	}

	void CFIntTopDomainEditObj::copyBuffToPKey() {
		cfint::CFIntTopDomainPKey* tablePKey = getPKey();
		cfint::CFIntTopDomainBuff* tableBuff = getTopDomainBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

	void CFIntTopDomainEditObj::copyBuffToOrig() {
		cfint::CFIntTopDomainBuff* origBuff = getOrigAsTopDomain()->getTopDomainEditBuff();
		cfint::CFIntTopDomainBuff* myBuff = getTopDomainBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntTopDomainEditObj::copyOrigToBuff() {
		cfint::CFIntTopDomainBuff* origBuff = getOrigAsTopDomain()->getTopDomainBuff();
		cfint::CFIntTopDomainBuff* myBuff = getTopDomainEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
