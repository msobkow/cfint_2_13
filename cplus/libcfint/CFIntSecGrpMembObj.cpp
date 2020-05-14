// Description: C++18 base object instance implementation for CFInt SecGrpMemb.

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
#include <cfintobj/CFIntSecGrpMembObj.hpp>

namespace cfint {

	const std::string CFIntSecGrpMembObj::CLASS_NAME( "CFIntSecGrpMembObj" );
	const classcode_t CFIntSecGrpMembObj::CLASS_CODE = 0xa00fL;

	int32_t CFIntSecGrpMembObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntSecGrpMembObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFIntSecGrpMembObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int64_t CFIntSecGrpMembObj::getRequiredSecGrpMembId() {
		return( getPKey()->getRequiredSecGrpMembId() );
	}

	const int64_t* CFIntSecGrpMembObj::getRequiredSecGrpMembIdReference() {
		return( getPKey()->getRequiredSecGrpMembIdReference() );
	}

	const int32_t CFIntSecGrpMembObj::getRequiredSecGroupId() {
		return( getSecGrpMembBuff()->getRequiredSecGroupId() );
	}

	const int32_t* CFIntSecGrpMembObj::getRequiredSecGroupIdReference() {
		return( getSecGrpMembBuff()->getRequiredSecGroupIdReference() );
	}

	const uuid_ptr_t CFIntSecGrpMembObj::getRequiredSecUserId() {
		return( getSecGrpMembBuff()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFIntSecGrpMembObj::getRequiredSecUserIdReference() {
		return( getSecGrpMembBuff()->getRequiredSecUserIdReference() );
	}


	cfsec::ICFSecClusterObj* CFIntSecGrpMembObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGrpMembObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGrpMembBuff()->getRequiredSecGroupId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGrpMembObj::getRequiredParentUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpMembBuff()->getRequiredSecUserId(), forceRead );
		}
		return( retobj );
	}

	CFIntSecGrpMembObj::CFIntSecGrpMembObj()
	: ICFIntSecGrpMembObj(),
	  ICFSecSecGrpMembObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecGrpMembObj::CFIntSecGrpMembObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntSecGrpMembObj(),
	  ICFSecSecGrpMembObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecGrpMembObj::~CFIntSecGrpMembObj() {
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

	cfsec::CFSecSecGrpMembBuff* CFIntSecGrpMembObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecGrpMembBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpMemb()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredClusterId(),
						getPKey()->getRequiredSecGrpMembId() );
			}
		}
		return( buff );
	}

	void CFIntSecGrpMembObj::setBuff( cfsec::CFSecSecGrpMembBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntSecGrpMembObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSecGrpMembObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntSecGrpMembObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecGrpMembObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecGrpMembObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGrpMembId( "SecGrpMembId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_SecUserId( "SecUserId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecGrpMembObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecGrpMembObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecGrpMembObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecGrpMembObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecGrpMembObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSecGrpMembObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SecGrpMembId, CFIntSecGrpMembObj::getRequiredSecGrpMembId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, CFIntSecGrpMembObj::getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFIntSecGrpMembObj::getRequiredSecUserId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntSecGrpMembObj::getObjName() {
		std::string objName( CLASS_NAME );
		int64_t val = getRequiredSecGrpMembId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFIntSecGrpMembObj::getGenDefName() {
		return( cfsec::CFSecSecGrpMembBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpMembObj::getScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpMembObj::getObjScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpMembObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecGrpMembObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpMembObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecGrpMembObj::getObjQualifiedName() {
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

	std::string CFIntSecGrpMembObj::getObjFullName() {
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

	cfsec::ICFSecSecGrpMembObj* CFIntSecGrpMembObj::realize() {
		cfsec::ICFSecSecGrpMembObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpMembTableObj()->realizeSecGrpMemb(
			(cfsec::ICFSecSecGrpMembObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( retobj ) );
	}

	cfsec::ICFSecSecGrpMembObj* CFIntSecGrpMembObj::read( bool forceRead ) {
		cfsec::ICFSecSecGrpMembObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpMembTableObj()->readSecGrpMembByIdIdx( getSecGrpMembBuff()->getRequiredClusterId(),
		getSecGrpMembBuff()->getRequiredSecGrpMembId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( retobj ) );
	}

	cfsec::ICFSecSecGrpMembTableObj* CFIntSecGrpMembObj::getSecGrpMembTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpMembTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntSecGrpMembObj::getSchema() {
		return( schema );
	}

	void CFIntSecGrpMembObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecGrpMembPKey* CFIntSecGrpMembObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecGrpMembPKey();
		}
		return( pKey );
	}

	void CFIntSecGrpMembObj::setPKey( cfsec::CFSecSecGrpMembPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecGrpMembPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntSecGrpMembObj::getIsNew() {
		return( isNew );
	}

	void CFIntSecGrpMembObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecGrpMembEditObj* CFIntSecGrpMembObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecGrpMembObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpMembTableObj()->lockSecGrpMemb( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpMembTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecGrpMembEditObj*>( edit ) );
	}

	void CFIntSecGrpMembObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecGrpMembEditObj* CFIntSecGrpMembObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFIntSecGrpMembObj::getSecGrpMembEdit() {
		return( dynamic_cast<cfsec::ICFSecSecGrpMembEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGrpMembObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpMembBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGrpMembObj::getCreatedAt() {
		return( getSecGrpMembBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGrpMembObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpMembBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGrpMembObj::getUpdatedAt() {
		return( getSecGrpMembBuff()->getUpdatedAt() );
	}

	void CFIntSecGrpMembObj::copyPKeyToBuff() {
		cfsec::CFSecSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpMembBuff* tableBuff = getSecGrpMembEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
			tableBuff->setRequiredSecGrpMembId( tablePKey->getRequiredSecGrpMembId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntSecGrpMembObj::copyBuffToPKey() {
		cfsec::CFSecSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpMembBuff* tableBuff = getSecGrpMembBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecGrpMembId( tableBuff->getRequiredSecGrpMembId() );
	}

}
