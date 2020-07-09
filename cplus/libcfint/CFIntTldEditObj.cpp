// Description: C++18 edit object instance implementation for CFInt Tld.

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
#include <cfintobj/CFIntTldObj.hpp>
#include <cfintobj/CFIntTldEditObj.hpp>


namespace cfint {

	const std::string CFIntTldEditObj::CLASS_NAME( "CFIntTldEditObj" );

	CFIntTldEditObj::CFIntTldEditObj( cfint::ICFIntTldObj* argOrig )
	: ICFIntTldEditObj()
	{
		static const std::string S_ProcName( "CFIntTldEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfint::CFIntTldBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfint::CFIntTldBuff*>( origBuff->clone() );
	}

	CFIntTldEditObj::~CFIntTldEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntTldEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntTldEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTldBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntTldEditObj::getCreatedAt() {
		return( getTldBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntTldEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTldBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntTldEditObj::getUpdatedAt() {
		return( getTldBuff()->getUpdatedAt() );
	}

	void CFIntTldEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getTldEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTldEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getTldEditBuff()->setCreatedAt( value );
	}

	void CFIntTldEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getTldEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTldEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getTldEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntTldEditObj::getClassCode() const {
		return( cfint::CFIntTldBuff::CLASS_CODE );
	}

	bool CFIntTldEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntTldBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntTldEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTldEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntTldEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntTldEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntTldEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntTldEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntTldEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntTldEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntTldEditObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntTldEditObj::getRequiredName() ) );
		if( ! CFIntTldEditObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntTldEditObj::getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntTldEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntTldEditObj::setRequiredRevision( int32_t value ) {
		getTldEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntTldEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntTldEditObj::getGenDefName() {
		return( cfint::CFIntTldBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntTldEditObj::getScope() {
		cfsec::ICFSecTenantObj* scope = getRequiredContainerTenant();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTldEditObj::getObjScope() {
		cfsec::ICFSecTenantObj* scope = getRequiredContainerTenant();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTldEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntTldEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntTldEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntTldEditObj::getObjQualifiedName() {
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

	std::string CFIntTldEditObj::getObjFullName() {
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

	cfint::ICFIntTldObj* CFIntTldEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfint::ICFIntTldObj* retobj = getSchema()->getTldTableObj()->realizeTld( dynamic_cast<cfint::ICFIntTldObj*>( this ) );
		return( retobj );
	}

	cfint::ICFIntTldObj* CFIntTldEditObj::read( bool forceRead ) {
		cfint::ICFIntTldObj* retval = getOrigAsTld()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfint::ICFIntTldObj* CFIntTldEditObj::create() {
		cfint::ICFIntTldObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTld()->getSchema() )->getTldTableObj()->createTld( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfint::ICFIntTldEditObj* CFIntTldEditObj::update() {
		getSchema()->getTldTableObj()->updateTld( this );
		return( NULL );
	}

	cfint::ICFIntTldEditObj* CFIntTldEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getTldTableObj()->deleteTld( this );
		return( NULL );
	}

	cfint::ICFIntTldTableObj* CFIntTldEditObj::getTldTable() {
		return( orig->getSchema()->getTldTableObj() );
	}

	cfint::ICFIntTldEditObj* CFIntTldEditObj::getEdit() {
		return( this );
	}

	cfint::ICFIntTldEditObj* CFIntTldEditObj::getTldEdit() {
		return( (cfint::ICFIntTldEditObj*)this );
	}

	cfint::ICFIntTldEditObj* CFIntTldEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntTldEditObj::endEdit() {
		orig->endEdit();
	}

	cfint::ICFIntTldObj* CFIntTldEditObj::getOrig() {
		return( orig );
	}

	cfint::ICFIntTldObj* CFIntTldEditObj::getOrigAsTld() {
		return( dynamic_cast<cfint::ICFIntTldObj*>( orig ) );
	}

	cfint::ICFIntSchemaObj* CFIntTldEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfint::CFIntTldBuff* CFIntTldEditObj::getBuff() {
		return( buff );
	}

	void CFIntTldEditObj::setBuff( cfint::CFIntTldBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfint::CFIntTldPKey* CFIntTldEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntTldEditObj::setPKey( cfint::CFIntTldPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntTldEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntTldEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntTldEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntTldEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntTldEditObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntTldEditObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const std::string& CFIntTldEditObj::getRequiredName() {
		return( getTldBuff()->getRequiredName() );
	}

	const std::string* CFIntTldEditObj::getRequiredNameReference() {
		return( getTldBuff()->getRequiredNameReference() );
	}

	void CFIntTldEditObj::setRequiredName( const std::string& value ) {
		if( getTldBuff()->getRequiredName() != value ) {
			getTldEditBuff()->setRequiredName( value );
		}
	}

	bool CFIntTldEditObj::isOptionalDescriptionNull() {
		return( getTldBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntTldEditObj::getOptionalDescriptionValue() {
		return( getTldBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntTldEditObj::getOptionalDescriptionReference() {
		return( getTldBuff()->getOptionalDescriptionReference() );
	}

	void CFIntTldEditObj::setOptionalDescriptionNull() {
		if( ! getTldBuff()->isOptionalDescriptionNull() ) {
			getTldEditBuff()->setOptionalDescriptionNull();
		}
	}

	void CFIntTldEditObj::setOptionalDescriptionValue( const std::string& value ) {
		if( getTldBuff()->isOptionalDescriptionNull() ) {
			getTldEditBuff()->setOptionalDescriptionValue( value );
		}
		else if( getTldBuff()->getOptionalDescriptionValue() != value ) {
			getTldEditBuff()->setOptionalDescriptionValue( value );
		}
	}

	cfsec::ICFSecTenantObj* CFIntTldEditObj::getRequiredContainerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTld()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFIntTldEditObj::setRequiredContainerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getTldEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	std::vector<cfint::ICFIntTopDomainObj*> CFIntTldEditObj::getOptionalComponentsTopDomain( bool forceRead ) {
		std::vector<cfint::ICFIntTopDomainObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTld()->getSchema() )->getTopDomainTableObj()->readTopDomainByTldIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	void CFIntTldEditObj::copyPKeyToBuff() {
		cfint::CFIntTldPKey* tablePKey = getPKey();
		cfint::CFIntTldBuff* tableBuff = getTldEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredId( tablePKey->getRequiredId() );
	}

	void CFIntTldEditObj::copyBuffToPKey() {
		cfint::CFIntTldPKey* tablePKey = getPKey();
		cfint::CFIntTldBuff* tableBuff = getTldBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

	void CFIntTldEditObj::copyBuffToOrig() {
		cfint::CFIntTldBuff* origBuff = getOrigAsTld()->getTldEditBuff();
		cfint::CFIntTldBuff* myBuff = getTldBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntTldEditObj::copyOrigToBuff() {
		cfint::CFIntTldBuff* origBuff = getOrigAsTld()->getTldBuff();
		cfint::CFIntTldBuff* myBuff = getTldEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
