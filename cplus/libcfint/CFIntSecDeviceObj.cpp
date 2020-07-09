// Description: C++18 base object instance implementation for CFInt SecDevice.

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
#include <cfintobj/CFIntSecDeviceObj.hpp>

namespace cfint {

	const std::string CFIntSecDeviceObj::CLASS_NAME( "CFIntSecDeviceObj" );
	const classcode_t CFIntSecDeviceObj::CLASS_CODE = 0xa00aL;

	int32_t CFIntSecDeviceObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const uuid_ptr_t CFIntSecDeviceObj::getRequiredSecUserId() {
		return( getPKey()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFIntSecDeviceObj::getRequiredSecUserIdReference() {
		return( getPKey()->getRequiredSecUserIdReference() );
	}

	const std::string& CFIntSecDeviceObj::getRequiredDevName() {
		return( getPKey()->getRequiredDevName() );
	}

	const std::string* CFIntSecDeviceObj::getRequiredDevNameReference() {
		return( getPKey()->getRequiredDevNameReference() );
	}

	bool CFIntSecDeviceObj::isOptionalPubKeyNull() {
		return( getSecDeviceBuff()->isOptionalPubKeyNull() );
	}

	const std::string& CFIntSecDeviceObj::getOptionalPubKeyValue() {
		return( getSecDeviceBuff()->getOptionalPubKeyValue() );
	}

	const std::string* CFIntSecDeviceObj::getOptionalPubKeyReference() {
		return( getSecDeviceBuff()->getOptionalPubKeyReference() );
	}


	cfsec::ICFSecSecUserObj* CFIntSecDeviceObj::getRequiredContainerSecUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getPKey()->getRequiredSecUserId(), forceRead );
		}
		return( retobj );
	}

	CFIntSecDeviceObj::CFIntSecDeviceObj()
	: ICFIntSecDeviceObj(),
	  ICFSecSecDeviceObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecDeviceObj::CFIntSecDeviceObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntSecDeviceObj(),
	  ICFSecSecDeviceObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecDeviceObj::~CFIntSecDeviceObj() {
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

	cfsec::CFSecSecDeviceBuff* CFIntSecDeviceObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecDeviceBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredSecUserId(),
						getPKey()->getRequiredDevName() );
			}
		}
		return( buff );
	}

	void CFIntSecDeviceObj::setBuff( cfsec::CFSecSecDeviceBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntSecDeviceObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSecDeviceObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntSecDeviceObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecDeviceObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecDeviceObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_DevName( "DevName" );
		static const std::string S_PubKey( "PubKey" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecDeviceObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecDeviceObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecDeviceObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecDeviceObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecDeviceObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFIntSecDeviceObj::getRequiredSecUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_DevName, CFIntSecDeviceObj::getRequiredDevName() ) );
		if( ! CFIntSecDeviceObj::isOptionalPubKeyNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_PubKey, CFIntSecDeviceObj::getOptionalPubKeyValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntSecDeviceObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredDevName() );
		return( objName );
	}

	const std::string CFIntSecDeviceObj::getGenDefName() {
		return( cfsec::CFSecSecDeviceBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecDeviceObj::getScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecDeviceObj::getObjScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecDeviceObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecDeviceObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecDeviceObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecDeviceObj::getObjQualifiedName() {
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

	std::string CFIntSecDeviceObj::getObjFullName() {
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

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceObj::realize() {
		cfsec::ICFSecSecDeviceObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecDeviceTableObj()->realizeSecDevice(
			(cfsec::ICFSecSecDeviceObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecDeviceObj*>( retobj ) );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceObj::read( bool forceRead ) {
		cfsec::ICFSecSecDeviceObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecDeviceTableObj()->readSecDeviceByIdIdx( getSecDeviceBuff()->getRequiredSecUserId(),
		getSecDeviceBuff()->getRequiredDevName(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecDeviceObj*>( retobj ) );
	}

	cfsec::ICFSecSecDeviceTableObj* CFIntSecDeviceObj::getSecDeviceTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecDeviceTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntSecDeviceObj::getSchema() {
		return( schema );
	}

	void CFIntSecDeviceObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecDevicePKey* CFIntSecDeviceObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecDevicePKey();
		}
		return( pKey );
	}

	void CFIntSecDeviceObj::setPKey( cfsec::CFSecSecDevicePKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecDevicePKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntSecDeviceObj::getIsNew() {
		return( isNew );
	}

	void CFIntSecDeviceObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecDeviceEditObj* CFIntSecDeviceObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecDeviceObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecDeviceTableObj()->lockSecDevice( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecDeviceTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecDeviceEditObj*>( edit ) );
	}

	void CFIntSecDeviceObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecDeviceEditObj* CFIntSecDeviceObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecDeviceEditObj* CFIntSecDeviceObj::getSecDeviceEdit() {
		return( dynamic_cast<cfsec::ICFSecSecDeviceEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntSecDeviceObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecDeviceBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecDeviceObj::getCreatedAt() {
		return( getSecDeviceBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecDeviceObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecDeviceBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecDeviceObj::getUpdatedAt() {
		return( getSecDeviceBuff()->getUpdatedAt() );
	}

	void CFIntSecDeviceObj::copyPKeyToBuff() {
		cfsec::CFSecSecDevicePKey* tablePKey = getPKey();
		cfsec::CFSecSecDeviceBuff* tableBuff = getSecDeviceEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredSecUserId( tablePKey->getRequiredSecUserId() );
			tableBuff->setRequiredDevName( tablePKey->getRequiredDevName() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntSecDeviceObj::copyBuffToPKey() {
		cfsec::CFSecSecDevicePKey* tablePKey = getPKey();
		cfsec::CFSecSecDeviceBuff* tableBuff = getSecDeviceBuff();
		tablePKey->setRequiredSecUserId( tableBuff->getRequiredSecUserId() );
		tablePKey->setRequiredDevName( tableBuff->getRequiredDevName() );
	}

}
