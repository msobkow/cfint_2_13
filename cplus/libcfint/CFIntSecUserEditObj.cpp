// Description: C++18 edit object instance implementation for CFInt SecUser.

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
#include <cfintobj/CFIntSecUserObj.hpp>
#include <cfintobj/CFIntSecUserEditObj.hpp>


namespace cfint {

	const std::string CFIntSecUserEditObj::CLASS_NAME( "CFIntSecUserEditObj" );

	CFIntSecUserEditObj::CFIntSecUserEditObj( cfsec::ICFSecSecUserObj* argOrig )
	: ICFIntSecUserEditObj(),
	  ICFSecSecUserEditObj()
	{
		static const std::string S_ProcName( "CFIntSecUserEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecUserBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecUserBuff*>( origBuff->clone() );
	}

	CFIntSecUserEditObj::~CFIntSecUserEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntSecUserEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntSecUserEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecUserBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecUserEditObj::getCreatedAt() {
		return( getSecUserBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecUserEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecUserBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecUserEditObj::getUpdatedAt() {
		return( getSecUserBuff()->getUpdatedAt() );
	}

	void CFIntSecUserEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSecUserEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecUserEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecUserEditBuff()->setCreatedAt( value );
	}

	void CFIntSecUserEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSecUserEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecUserEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecUserEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntSecUserEditObj::getClassCode() const {
		return( cfsec::CFSecSecUserBuff::CLASS_CODE );
	}

	bool CFIntSecUserEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecUserEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecUserEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_LoginId( "LoginId" );
		static const std::string S_EMailAddress( "EMailAddress" );
		static const std::string S_EMailConfirmUuid( "EMailConfirmUuid" );
		static const std::string S_DfltDevUserId( "DfltDevUserId" );
		static const std::string S_DfltDevName( "DfltDevName" );
		static const std::string S_PasswordHash( "PasswordHash" );
		static const std::string S_PasswordResetUuid( "PasswordResetUuid" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecUserEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecUserEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecUserEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecUserEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecUserEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFIntSecUserEditObj::getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_LoginId, CFIntSecUserEditObj::getRequiredLoginId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EMailAddress, CFIntSecUserEditObj::getRequiredEMailAddress() ) );
		if( ! CFIntSecUserEditObj::isOptionalEMailConfirmUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_EMailConfirmUuid, CFIntSecUserEditObj::getOptionalEMailConfirmUuidValue() ) );
		}
		if( ! CFIntSecUserEditObj::isOptionalDfltDevUserIdNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_DfltDevUserId, CFIntSecUserEditObj::getOptionalDfltDevUserIdValue() ) );
		}
		if( ! CFIntSecUserEditObj::isOptionalDfltDevNameNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_DfltDevName, CFIntSecUserEditObj::getOptionalDfltDevNameValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_PasswordHash, CFIntSecUserEditObj::getRequiredPasswordHash() ) );
		if( ! CFIntSecUserEditObj::isOptionalPasswordResetUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_PasswordResetUuid, CFIntSecUserEditObj::getOptionalPasswordResetUuidValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntSecUserEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntSecUserEditObj::setRequiredRevision( int32_t value ) {
		getSecUserEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntSecUserEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredLoginId() );
		return( objName );
	}

	const std::string CFIntSecUserEditObj::getGenDefName() {
		return( cfsec::CFSecSecUserBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecUserEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntSecUserEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntSecUserEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecUserEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecUserEditObj::getNamedObject( const std::string& objName ) {
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
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecDeviceTableObj()->readSecDeviceByLookupNameIdx( getRequiredSecUserId(),
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

	std::string CFIntSecUserEditObj::getObjQualifiedName() {
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

	std::string CFIntSecUserEditObj::getObjFullName() {
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

	cfsec::ICFSecSecUserObj* CFIntSecUserEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecUserObj* retobj = getSchema()->getSecUserTableObj()->realizeSecUser( dynamic_cast<cfsec::ICFSecSecUserObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecUserObj* CFIntSecUserEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retval = getOrigAsSecUser()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecUserObj* CFIntSecUserEditObj::create() {
		cfsec::ICFSecSecUserObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecUserTableObj()->createSecUser( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecUserEditObj* CFIntSecUserEditObj::update() {
		getSchema()->getSecUserTableObj()->updateSecUser( this );
		return( NULL );
	}

	cfsec::ICFSecSecUserEditObj* CFIntSecUserEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecUserTableObj()->deleteSecUser( this );
		return( NULL );
	}

	cfsec::ICFSecSecUserTableObj* CFIntSecUserEditObj::getSecUserTable() {
		return( orig->getSchema()->getSecUserTableObj() );
	}

	cfsec::ICFSecSecUserEditObj* CFIntSecUserEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecUserEditObj* CFIntSecUserEditObj::getSecUserEdit() {
		return( (cfsec::ICFSecSecUserEditObj*)this );
	}

	cfsec::ICFSecSecUserEditObj* CFIntSecUserEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntSecUserEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecUserObj* CFIntSecUserEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecUserObj* CFIntSecUserEditObj::getOrigAsSecUser() {
		return( dynamic_cast<cfsec::ICFSecSecUserObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntSecUserEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecUserBuff* CFIntSecUserEditObj::getBuff() {
		return( buff );
	}

	void CFIntSecUserEditObj::setBuff( cfsec::CFSecSecUserBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecUserPKey* CFIntSecUserEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntSecUserEditObj::setPKey( cfsec::CFSecSecUserPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntSecUserEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntSecUserEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const uuid_ptr_t CFIntSecUserEditObj::getRequiredSecUserId() {
		return( getPKey()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFIntSecUserEditObj::getRequiredSecUserIdReference() {
		return( getPKey()->getRequiredSecUserIdReference() );
	}

	const std::string& CFIntSecUserEditObj::getRequiredLoginId() {
		return( getSecUserBuff()->getRequiredLoginId() );
	}

	const std::string* CFIntSecUserEditObj::getRequiredLoginIdReference() {
		return( getSecUserBuff()->getRequiredLoginIdReference() );
	}

	void CFIntSecUserEditObj::setRequiredLoginId( const std::string& value ) {
		if( getSecUserBuff()->getRequiredLoginId() != value ) {
			getSecUserEditBuff()->setRequiredLoginId( value );
		}
	}

	const std::string& CFIntSecUserEditObj::getRequiredEMailAddress() {
		return( getSecUserBuff()->getRequiredEMailAddress() );
	}

	const std::string* CFIntSecUserEditObj::getRequiredEMailAddressReference() {
		return( getSecUserBuff()->getRequiredEMailAddressReference() );
	}

	void CFIntSecUserEditObj::setRequiredEMailAddress( const std::string& value ) {
		if( getSecUserBuff()->getRequiredEMailAddress() != value ) {
			getSecUserEditBuff()->setRequiredEMailAddress( value );
		}
	}

	bool CFIntSecUserEditObj::isOptionalEMailConfirmUuidNull() {
		return( getSecUserBuff()->isOptionalEMailConfirmUuidNull() );
	}

	const uuid_ptr_t CFIntSecUserEditObj::getOptionalEMailConfirmUuidValue() {
		return( getSecUserBuff()->getOptionalEMailConfirmUuidValue() );
	}

	const uuid_ptr_t CFIntSecUserEditObj::getOptionalEMailConfirmUuidReference() {
		return( getSecUserBuff()->getOptionalEMailConfirmUuidReference() );
	}

	void CFIntSecUserEditObj::setOptionalEMailConfirmUuidNull() {
		if( ! getSecUserBuff()->isOptionalEMailConfirmUuidNull() ) {
			getSecUserEditBuff()->setOptionalEMailConfirmUuidNull();
		}
	}

	void CFIntSecUserEditObj::setOptionalEMailConfirmUuidValue( const uuid_ptr_t value ) {
		if( getSecUserBuff()->isOptionalEMailConfirmUuidNull() ) {
			getSecUserEditBuff()->setOptionalEMailConfirmUuidValue( value );
		}
		else if( getSecUserBuff()->getOptionalEMailConfirmUuidValue() != value ) {
			getSecUserEditBuff()->setOptionalEMailConfirmUuidValue( value );
		}
	}

	bool CFIntSecUserEditObj::isOptionalDfltDevUserIdNull() {
		return( getSecUserBuff()->isOptionalDfltDevUserIdNull() );
	}

	const uuid_ptr_t CFIntSecUserEditObj::getOptionalDfltDevUserIdValue() {
		return( getSecUserBuff()->getOptionalDfltDevUserIdValue() );
	}

	const uuid_ptr_t CFIntSecUserEditObj::getOptionalDfltDevUserIdReference() {
		return( getSecUserBuff()->getOptionalDfltDevUserIdReference() );
	}

	bool CFIntSecUserEditObj::isOptionalDfltDevNameNull() {
		return( getSecUserBuff()->isOptionalDfltDevNameNull() );
	}

	const std::string& CFIntSecUserEditObj::getOptionalDfltDevNameValue() {
		return( getSecUserBuff()->getOptionalDfltDevNameValue() );
	}

	const std::string* CFIntSecUserEditObj::getOptionalDfltDevNameReference() {
		return( getSecUserBuff()->getOptionalDfltDevNameReference() );
	}

	const std::string& CFIntSecUserEditObj::getRequiredPasswordHash() {
		return( getSecUserBuff()->getRequiredPasswordHash() );
	}

	const std::string* CFIntSecUserEditObj::getRequiredPasswordHashReference() {
		return( getSecUserBuff()->getRequiredPasswordHashReference() );
	}

	void CFIntSecUserEditObj::setRequiredPasswordHash( const std::string& value ) {
		if( getSecUserBuff()->getRequiredPasswordHash() != value ) {
			getSecUserEditBuff()->setRequiredPasswordHash( value );
		}
	}

	bool CFIntSecUserEditObj::isOptionalPasswordResetUuidNull() {
		return( getSecUserBuff()->isOptionalPasswordResetUuidNull() );
	}

	const uuid_ptr_t CFIntSecUserEditObj::getOptionalPasswordResetUuidValue() {
		return( getSecUserBuff()->getOptionalPasswordResetUuidValue() );
	}

	const uuid_ptr_t CFIntSecUserEditObj::getOptionalPasswordResetUuidReference() {
		return( getSecUserBuff()->getOptionalPasswordResetUuidReference() );
	}

	void CFIntSecUserEditObj::setOptionalPasswordResetUuidNull() {
		if( ! getSecUserBuff()->isOptionalPasswordResetUuidNull() ) {
			getSecUserEditBuff()->setOptionalPasswordResetUuidNull();
		}
	}

	void CFIntSecUserEditObj::setOptionalPasswordResetUuidValue( const uuid_ptr_t value ) {
		if( getSecUserBuff()->isOptionalPasswordResetUuidNull() ) {
			getSecUserEditBuff()->setOptionalPasswordResetUuidValue( value );
		}
		else if( getSecUserBuff()->getOptionalPasswordResetUuidValue() != value ) {
			getSecUserEditBuff()->setOptionalPasswordResetUuidValue( value );
		}
	}

	std::vector<cfsec::ICFSecSecDeviceObj*> CFIntSecUserEditObj::getOptionalComponentsSecDev( bool forceRead ) {
		std::vector<cfsec::ICFSecSecDeviceObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecDeviceTableObj()->readSecDeviceByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecUserEditObj::getOptionalLookupDefDev( bool forceRead ) {
		cfsec::ICFSecSecDeviceObj* retobj = NULL;
		bool anyMissing = false;

			if( getSecUserBuff()->isOptionalDfltDevUserIdNull() ) {
				anyMissing = true;
			}
			if( getSecUserBuff()->isOptionalDfltDevNameNull() ) {
				anyMissing = true;
			}		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecDeviceTableObj()->readSecDeviceByIdIdx( getSecUserBuff()->getOptionalDfltDevUserIdValue(),
					getSecUserBuff()->getOptionalDfltDevNameValue() );
		}
		return( retobj );
	}

	void CFIntSecUserEditObj::setOptionalLookupDefDev( cfsec::ICFSecSecDeviceObj* value ) {
			
			if( value != NULL ) {
				getSecUserEditBuff()->setOptionalDfltDevUserIdValue( value->getRequiredSecUserId() );
				getSecUserEditBuff()->setOptionalDfltDevNameValue( value->getRequiredDevName() );
			}
			else {
				getSecUserEditBuff()->setOptionalDfltDevUserIdNull();
				getSecUserEditBuff()->setOptionalDfltDevNameNull();
			}
		}

	std::vector<cfsec::ICFSecSecSessionObj*> CFIntSecUserEditObj::getOptionalComponentsSecSess( bool forceRead ) {
		std::vector<cfsec::ICFSecSecSessionObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecSessionTableObj()->readSecSessionBySecUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFIntSecUserEditObj::getOptionalChildrenSecProxy( bool forceRead ) {
		std::vector<cfsec::ICFSecSecSessionObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecSessionTableObj()->readSecSessionBySecProxyIdx( getPKey()->getRequiredSecUserIdReference(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFIntSecUserEditObj::getOptionalChildrenSecGrpMemb( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpMembObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecUser()->getSchema() )->getSecGrpMembTableObj()->readSecGrpMembByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFIntSecUserEditObj::getOptionalChildrenTSecGrpMemb( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpMembObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecUser()->getSchema() )->getTSecGrpMembTableObj()->readTSecGrpMembByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	void CFIntSecUserEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecUserPKey* tablePKey = getPKey();
		cfsec::CFSecSecUserBuff* tableBuff = getSecUserEditBuff();
		tableBuff->setRequiredSecUserId( tablePKey->getRequiredSecUserId() );
	}

	void CFIntSecUserEditObj::copyBuffToPKey() {
		cfsec::CFSecSecUserPKey* tablePKey = getPKey();
		cfsec::CFSecSecUserBuff* tableBuff = getSecUserBuff();
		tablePKey->setRequiredSecUserId( tableBuff->getRequiredSecUserId() );
	}

	void CFIntSecUserEditObj::copyBuffToOrig() {
		cfsec::CFSecSecUserBuff* origBuff = getOrigAsSecUser()->getSecUserEditBuff();
		cfsec::CFSecSecUserBuff* myBuff = getSecUserBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntSecUserEditObj::copyOrigToBuff() {
		cfsec::CFSecSecUserBuff* origBuff = getOrigAsSecUser()->getSecUserBuff();
		cfsec::CFSecSecUserBuff* myBuff = getSecUserEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
