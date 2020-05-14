// Description: C++18 base object instance implementation for CFInt SecUser.

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

namespace cfint {

	const std::string CFIntSecUserObj::CLASS_NAME( "CFIntSecUserObj" );
	const classcode_t CFIntSecUserObj::CLASS_CODE = 0xa011L;

	int32_t CFIntSecUserObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const uuid_ptr_t CFIntSecUserObj::getRequiredSecUserId() {
		return( getPKey()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFIntSecUserObj::getRequiredSecUserIdReference() {
		return( getPKey()->getRequiredSecUserIdReference() );
	}

	const std::string& CFIntSecUserObj::getRequiredLoginId() {
		return( getSecUserBuff()->getRequiredLoginId() );
	}

	const std::string* CFIntSecUserObj::getRequiredLoginIdReference() {
		return( getSecUserBuff()->getRequiredLoginIdReference() );
	}

	const std::string& CFIntSecUserObj::getRequiredEMailAddress() {
		return( getSecUserBuff()->getRequiredEMailAddress() );
	}

	const std::string* CFIntSecUserObj::getRequiredEMailAddressReference() {
		return( getSecUserBuff()->getRequiredEMailAddressReference() );
	}

	bool CFIntSecUserObj::isOptionalEMailConfirmUuidNull() {
		return( getSecUserBuff()->isOptionalEMailConfirmUuidNull() );
	}

	const uuid_ptr_t CFIntSecUserObj::getOptionalEMailConfirmUuidValue() {
		return( getSecUserBuff()->getOptionalEMailConfirmUuidValue() );
	}

	const uuid_ptr_t CFIntSecUserObj::getOptionalEMailConfirmUuidReference() {
		return( getSecUserBuff()->getOptionalEMailConfirmUuidReference() );
	}

	bool CFIntSecUserObj::isOptionalDfltDevUserIdNull() {
		return( getSecUserBuff()->isOptionalDfltDevUserIdNull() );
	}

	const uuid_ptr_t CFIntSecUserObj::getOptionalDfltDevUserIdValue() {
		return( getSecUserBuff()->getOptionalDfltDevUserIdValue() );
	}

	const uuid_ptr_t CFIntSecUserObj::getOptionalDfltDevUserIdReference() {
		return( getSecUserBuff()->getOptionalDfltDevUserIdReference() );
	}

	bool CFIntSecUserObj::isOptionalDfltDevNameNull() {
		return( getSecUserBuff()->isOptionalDfltDevNameNull() );
	}

	const std::string& CFIntSecUserObj::getOptionalDfltDevNameValue() {
		return( getSecUserBuff()->getOptionalDfltDevNameValue() );
	}

	const std::string* CFIntSecUserObj::getOptionalDfltDevNameReference() {
		return( getSecUserBuff()->getOptionalDfltDevNameReference() );
	}

	const std::string& CFIntSecUserObj::getRequiredPasswordHash() {
		return( getSecUserBuff()->getRequiredPasswordHash() );
	}

	const std::string* CFIntSecUserObj::getRequiredPasswordHashReference() {
		return( getSecUserBuff()->getRequiredPasswordHashReference() );
	}

	bool CFIntSecUserObj::isOptionalPasswordResetUuidNull() {
		return( getSecUserBuff()->isOptionalPasswordResetUuidNull() );
	}

	const uuid_ptr_t CFIntSecUserObj::getOptionalPasswordResetUuidValue() {
		return( getSecUserBuff()->getOptionalPasswordResetUuidValue() );
	}

	const uuid_ptr_t CFIntSecUserObj::getOptionalPasswordResetUuidReference() {
		return( getSecUserBuff()->getOptionalPasswordResetUuidReference() );
	}


	std::vector<cfsec::ICFSecSecDeviceObj*> CFIntSecUserObj::getOptionalComponentsSecDev( bool forceRead ) {
		std::vector<cfsec::ICFSecSecDeviceObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecDeviceTableObj()->readSecDeviceByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecUserObj::getOptionalLookupDefDev( bool forceRead ) {
		cfsec::ICFSecSecDeviceObj* retobj = NULL;
		bool anyMissing = false;
			if( getSecUserBuff()->isOptionalDfltDevUserIdNull() ) {
				anyMissing = true;
			}
			if( getSecUserBuff()->isOptionalDfltDevNameNull() ) {
				anyMissing = true;
			}
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecDeviceTableObj()->readSecDeviceByIdIdx( getSecUserBuff()->getOptionalDfltDevUserIdValue(),
					getSecUserBuff()->getOptionalDfltDevNameValue(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFIntSecUserObj::getOptionalComponentsSecSess( bool forceRead ) {
		std::vector<cfsec::ICFSecSecSessionObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecSessionTableObj()->readSecSessionBySecUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecSessionObj*> CFIntSecUserObj::getOptionalChildrenSecProxy( bool forceRead ) {
		std::vector<cfsec::ICFSecSecSessionObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecSessionTableObj()->readSecSessionBySecProxyIdx( getPKey()->getRequiredSecUserIdReference(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFIntSecUserObj::getOptionalChildrenSecGrpMemb( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpMembObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpMembTableObj()->readSecGrpMembByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFIntSecUserObj::getOptionalChildrenTSecGrpMemb( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpMembObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTSecGrpMembTableObj()->readTSecGrpMembByUserIdx( getPKey()->getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	CFIntSecUserObj::CFIntSecUserObj()
	: ICFIntSecUserObj(),
	  ICFSecSecUserObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecUserObj::CFIntSecUserObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntSecUserObj(),
	  ICFSecSecUserObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecUserObj::~CFIntSecUserObj() {
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

	cfsec::CFSecSecUserBuff* CFIntSecUserObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecUserBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecUser()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredSecUserId() );
			}
		}
		return( buff );
	}

	void CFIntSecUserObj::setBuff( cfsec::CFSecSecUserBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntSecUserObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSecUserObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntSecUserObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecUserBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecUserObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecUserObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecUserObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecUserObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecUserObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecUserObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecUserObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFIntSecUserObj::getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_LoginId, CFIntSecUserObj::getRequiredLoginId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EMailAddress, CFIntSecUserObj::getRequiredEMailAddress() ) );
		if( ! CFIntSecUserObj::isOptionalEMailConfirmUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_EMailConfirmUuid, CFIntSecUserObj::getOptionalEMailConfirmUuidValue() ) );
		}
		if( ! CFIntSecUserObj::isOptionalDfltDevUserIdNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_DfltDevUserId, CFIntSecUserObj::getOptionalDfltDevUserIdValue() ) );
		}
		if( ! CFIntSecUserObj::isOptionalDfltDevNameNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_DfltDevName, CFIntSecUserObj::getOptionalDfltDevNameValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_PasswordHash, CFIntSecUserObj::getRequiredPasswordHash() ) );
		if( ! CFIntSecUserObj::isOptionalPasswordResetUuidNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_PasswordResetUuid, CFIntSecUserObj::getOptionalPasswordResetUuidValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntSecUserObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredLoginId() );
		return( objName );
	}

	const std::string CFIntSecUserObj::getGenDefName() {
		return( cfsec::CFSecSecUserBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecUserObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntSecUserObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntSecUserObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecUserObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecUserObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecUserObj::getObjQualifiedName() {
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

	std::string CFIntSecUserObj::getObjFullName() {
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

	cfsec::ICFSecSecUserObj* CFIntSecUserObj::realize() {
		cfsec::ICFSecSecUserObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->realizeSecUser(
			(cfsec::ICFSecSecUserObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecUserObj*>( retobj ) );
	}

	cfsec::ICFSecSecUserObj* CFIntSecUserObj::read( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecUserBuff()->getRequiredSecUserId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecUserObj*>( retobj ) );
	}

	cfsec::ICFSecSecUserTableObj* CFIntSecUserObj::getSecUserTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntSecUserObj::getSchema() {
		return( schema );
	}

	void CFIntSecUserObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecUserPKey* CFIntSecUserObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecUserPKey();
		}
		return( pKey );
	}

	void CFIntSecUserObj::setPKey( cfsec::CFSecSecUserPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecUserPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntSecUserObj::getIsNew() {
		return( isNew );
	}

	void CFIntSecUserObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecUserEditObj* CFIntSecUserObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecUserObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->lockSecUser( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecUserEditObj*>( edit ) );
	}

	void CFIntSecUserObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecUserEditObj* CFIntSecUserObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecUserEditObj* CFIntSecUserObj::getSecUserEdit() {
		return( dynamic_cast<cfsec::ICFSecSecUserEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntSecUserObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecUserBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecUserObj::getCreatedAt() {
		return( getSecUserBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecUserObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecUserBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecUserObj::getUpdatedAt() {
		return( getSecUserBuff()->getUpdatedAt() );
	}

	void CFIntSecUserObj::copyPKeyToBuff() {
		cfsec::CFSecSecUserPKey* tablePKey = getPKey();
		cfsec::CFSecSecUserBuff* tableBuff = getSecUserEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredSecUserId( tablePKey->getRequiredSecUserId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntSecUserObj::copyBuffToPKey() {
		cfsec::CFSecSecUserPKey* tablePKey = getPKey();
		cfsec::CFSecSecUserBuff* tableBuff = getSecUserBuff();
		tablePKey->setRequiredSecUserId( tableBuff->getRequiredSecUserId() );
	}

}
