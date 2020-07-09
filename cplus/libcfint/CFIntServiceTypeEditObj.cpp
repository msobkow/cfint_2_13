// Description: C++18 edit object instance implementation for CFInt ServiceType.

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
#include <cfintobj/CFIntServiceTypeObj.hpp>
#include <cfintobj/CFIntServiceTypeEditObj.hpp>


namespace cfint {

	const std::string CFIntServiceTypeEditObj::CLASS_NAME( "CFIntServiceTypeEditObj" );

	CFIntServiceTypeEditObj::CFIntServiceTypeEditObj( cfsec::ICFSecServiceTypeObj* argOrig )
	: ICFIntServiceTypeEditObj(),
	  ICFSecServiceTypeEditObj()
	{
		static const std::string S_ProcName( "CFIntServiceTypeEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecServiceTypeBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( origBuff->clone() );
	}

	CFIntServiceTypeEditObj::~CFIntServiceTypeEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntServiceTypeEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntServiceTypeEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getServiceTypeBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntServiceTypeEditObj::getCreatedAt() {
		return( getServiceTypeBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntServiceTypeEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getServiceTypeBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntServiceTypeEditObj::getUpdatedAt() {
		return( getServiceTypeBuff()->getUpdatedAt() );
	}

	void CFIntServiceTypeEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getServiceTypeEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntServiceTypeEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getServiceTypeEditBuff()->setCreatedAt( value );
	}

	void CFIntServiceTypeEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getServiceTypeEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntServiceTypeEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getServiceTypeEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntServiceTypeEditObj::getClassCode() const {
		return( cfsec::CFSecServiceTypeBuff::CLASS_CODE );
	}

	bool CFIntServiceTypeEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntServiceTypeEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntServiceTypeEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ServiceTypeId( "ServiceTypeId" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntServiceTypeEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntServiceTypeEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntServiceTypeEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntServiceTypeEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntServiceTypeEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_ServiceTypeId, CFIntServiceTypeEditObj::getRequiredServiceTypeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntServiceTypeEditObj::getRequiredDescription() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntServiceTypeEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntServiceTypeEditObj::setRequiredRevision( int32_t value ) {
		getServiceTypeEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntServiceTypeEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredDescription() );
		return( objName );
	}

	const std::string CFIntServiceTypeEditObj::getGenDefName() {
		return( cfsec::CFSecServiceTypeBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntServiceTypeEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntServiceTypeEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntServiceTypeEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntServiceTypeEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntServiceTypeEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntServiceTypeEditObj::getObjQualifiedName() {
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

	std::string CFIntServiceTypeEditObj::getObjFullName() {
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

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecServiceTypeObj* retobj = getSchema()->getServiceTypeTableObj()->realizeServiceType( dynamic_cast<cfsec::ICFSecServiceTypeObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeEditObj::read( bool forceRead ) {
		cfsec::ICFSecServiceTypeObj* retval = getOrigAsServiceType()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeEditObj::create() {
		cfsec::ICFSecServiceTypeObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsServiceType()->getSchema() )->getServiceTypeTableObj()->createServiceType( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecServiceTypeEditObj* CFIntServiceTypeEditObj::update() {
		getSchema()->getServiceTypeTableObj()->updateServiceType( this );
		return( NULL );
	}

	cfsec::ICFSecServiceTypeEditObj* CFIntServiceTypeEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getServiceTypeTableObj()->deleteServiceType( this );
		return( NULL );
	}

	cfsec::ICFSecServiceTypeTableObj* CFIntServiceTypeEditObj::getServiceTypeTable() {
		return( orig->getSchema()->getServiceTypeTableObj() );
	}

	cfsec::ICFSecServiceTypeEditObj* CFIntServiceTypeEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecServiceTypeEditObj* CFIntServiceTypeEditObj::getServiceTypeEdit() {
		return( (cfsec::ICFSecServiceTypeEditObj*)this );
	}

	cfsec::ICFSecServiceTypeEditObj* CFIntServiceTypeEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntServiceTypeEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeEditObj::getOrigAsServiceType() {
		return( dynamic_cast<cfsec::ICFSecServiceTypeObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntServiceTypeEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecServiceTypeBuff* CFIntServiceTypeEditObj::getBuff() {
		return( buff );
	}

	void CFIntServiceTypeEditObj::setBuff( cfsec::CFSecServiceTypeBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecServiceTypePKey* CFIntServiceTypeEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntServiceTypeEditObj::setPKey( cfsec::CFSecServiceTypePKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntServiceTypeEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntServiceTypeEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int32_t CFIntServiceTypeEditObj::getRequiredServiceTypeId() {
		return( getPKey()->getRequiredServiceTypeId() );
	}

	const int32_t* CFIntServiceTypeEditObj::getRequiredServiceTypeIdReference() {
		return( getPKey()->getRequiredServiceTypeIdReference() );
	}

	const std::string& CFIntServiceTypeEditObj::getRequiredDescription() {
		return( getServiceTypeBuff()->getRequiredDescription() );
	}

	const std::string* CFIntServiceTypeEditObj::getRequiredDescriptionReference() {
		return( getServiceTypeBuff()->getRequiredDescriptionReference() );
	}

	void CFIntServiceTypeEditObj::setRequiredDescription( const std::string& value ) {
		if( getServiceTypeBuff()->getRequiredDescription() != value ) {
			getServiceTypeEditBuff()->setRequiredDescription( value );
		}
	}

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTypeEditObj::getOptionalChildrenDeployed( bool forceRead ) {
		std::vector<cfsec::ICFSecServiceObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsServiceType()->getSchema() )->getServiceTableObj()->readServiceByTypeIdx( getPKey()->getRequiredServiceTypeId(),
			forceRead );
		return( retval );
	}

	void CFIntServiceTypeEditObj::copyPKeyToBuff() {
		cfsec::CFSecServiceTypePKey* tablePKey = getPKey();
		cfsec::CFSecServiceTypeBuff* tableBuff = getServiceTypeEditBuff();
		tableBuff->setRequiredServiceTypeId( tablePKey->getRequiredServiceTypeId() );
	}

	void CFIntServiceTypeEditObj::copyBuffToPKey() {
		cfsec::CFSecServiceTypePKey* tablePKey = getPKey();
		cfsec::CFSecServiceTypeBuff* tableBuff = getServiceTypeBuff();
		tablePKey->setRequiredServiceTypeId( tableBuff->getRequiredServiceTypeId() );
	}

	void CFIntServiceTypeEditObj::copyBuffToOrig() {
		cfsec::CFSecServiceTypeBuff* origBuff = getOrigAsServiceType()->getServiceTypeEditBuff();
		cfsec::CFSecServiceTypeBuff* myBuff = getServiceTypeBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntServiceTypeEditObj::copyOrigToBuff() {
		cfsec::CFSecServiceTypeBuff* origBuff = getOrigAsServiceType()->getServiceTypeBuff();
		cfsec::CFSecServiceTypeBuff* myBuff = getServiceTypeEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
