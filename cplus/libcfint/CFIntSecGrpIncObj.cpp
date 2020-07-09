// Description: C++18 base object instance implementation for CFInt SecGrpInc.

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
#include <cfintobj/CFIntSecGrpIncObj.hpp>

namespace cfint {

	const std::string CFIntSecGrpIncObj::CLASS_NAME( "CFIntSecGrpIncObj" );
	const classcode_t CFIntSecGrpIncObj::CLASS_CODE = 0xa00eL;

	int32_t CFIntSecGrpIncObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntSecGrpIncObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFIntSecGrpIncObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int64_t CFIntSecGrpIncObj::getRequiredSecGrpIncId() {
		return( getPKey()->getRequiredSecGrpIncId() );
	}

	const int64_t* CFIntSecGrpIncObj::getRequiredSecGrpIncIdReference() {
		return( getPKey()->getRequiredSecGrpIncIdReference() );
	}

	const int32_t CFIntSecGrpIncObj::getRequiredSecGroupId() {
		return( getSecGrpIncBuff()->getRequiredSecGroupId() );
	}

	const int32_t* CFIntSecGrpIncObj::getRequiredSecGroupIdReference() {
		return( getSecGrpIncBuff()->getRequiredSecGroupIdReference() );
	}

	const int32_t CFIntSecGrpIncObj::getRequiredIncludeGroupId() {
		return( getSecGrpIncBuff()->getRequiredIncludeGroupId() );
	}

	const int32_t* CFIntSecGrpIncObj::getRequiredIncludeGroupIdReference() {
		return( getSecGrpIncBuff()->getRequiredIncludeGroupIdReference() );
	}


	cfsec::ICFSecClusterObj* CFIntSecGrpIncObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGrpIncObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGrpIncBuff()->getRequiredSecGroupId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGrpIncObj::getRequiredParentSubGroup( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGrpIncBuff()->getRequiredIncludeGroupId(), forceRead );
		}
		return( retobj );
	}

	CFIntSecGrpIncObj::CFIntSecGrpIncObj()
	: ICFIntSecGrpIncObj(),
	  ICFSecSecGrpIncObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecGrpIncObj::CFIntSecGrpIncObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntSecGrpIncObj(),
	  ICFSecSecGrpIncObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecGrpIncObj::~CFIntSecGrpIncObj() {
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

	cfsec::CFSecSecGrpIncBuff* CFIntSecGrpIncObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecGrpIncBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredClusterId(),
						getPKey()->getRequiredSecGrpIncId() );
			}
		}
		return( buff );
	}

	void CFIntSecGrpIncObj::setBuff( cfsec::CFSecSecGrpIncBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntSecGrpIncObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSecGrpIncObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntSecGrpIncObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecGrpIncObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecGrpIncObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGrpIncId( "SecGrpIncId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_IncludeGroupId( "IncludeGroupId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecGrpIncObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecGrpIncObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecGrpIncObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecGrpIncObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecGrpIncObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSecGrpIncObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SecGrpIncId, CFIntSecGrpIncObj::getRequiredSecGrpIncId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, CFIntSecGrpIncObj::getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_IncludeGroupId, CFIntSecGrpIncObj::getRequiredIncludeGroupId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntSecGrpIncObj::getObjName() {
		std::string objName( CLASS_NAME );
		int64_t val = getRequiredSecGrpIncId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFIntSecGrpIncObj::getGenDefName() {
		return( cfsec::CFSecSecGrpIncBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpIncObj::getScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpIncObj::getObjScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpIncObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecGrpIncObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpIncObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecGrpIncObj::getObjQualifiedName() {
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

	std::string CFIntSecGrpIncObj::getObjFullName() {
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

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncObj::realize() {
		cfsec::ICFSecSecGrpIncObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->realizeSecGrpInc(
			(cfsec::ICFSecSecGrpIncObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( retobj ) );
	}

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncObj::read( bool forceRead ) {
		cfsec::ICFSecSecGrpIncObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->readSecGrpIncByIdIdx( getSecGrpIncBuff()->getRequiredClusterId(),
		getSecGrpIncBuff()->getRequiredSecGrpIncId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( retobj ) );
	}

	cfsec::ICFSecSecGrpIncTableObj* CFIntSecGrpIncObj::getSecGrpIncTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpIncTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntSecGrpIncObj::getSchema() {
		return( schema );
	}

	void CFIntSecGrpIncObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecGrpIncPKey* CFIntSecGrpIncObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecGrpIncPKey();
		}
		return( pKey );
	}

	void CFIntSecGrpIncObj::setPKey( cfsec::CFSecSecGrpIncPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecGrpIncPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntSecGrpIncObj::getIsNew() {
		return( isNew );
	}

	void CFIntSecGrpIncObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecGrpIncEditObj* CFIntSecGrpIncObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecGrpIncObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->lockSecGrpInc( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecGrpIncEditObj*>( edit ) );
	}

	void CFIntSecGrpIncObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecGrpIncEditObj* CFIntSecGrpIncObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecGrpIncEditObj* CFIntSecGrpIncObj::getSecGrpIncEdit() {
		return( dynamic_cast<cfsec::ICFSecSecGrpIncEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGrpIncObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpIncBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGrpIncObj::getCreatedAt() {
		return( getSecGrpIncBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGrpIncObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpIncBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGrpIncObj::getUpdatedAt() {
		return( getSecGrpIncBuff()->getUpdatedAt() );
	}

	void CFIntSecGrpIncObj::copyPKeyToBuff() {
		cfsec::CFSecSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpIncBuff* tableBuff = getSecGrpIncEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
			tableBuff->setRequiredSecGrpIncId( tablePKey->getRequiredSecGrpIncId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntSecGrpIncObj::copyBuffToPKey() {
		cfsec::CFSecSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpIncBuff* tableBuff = getSecGrpIncBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecGrpIncId( tableBuff->getRequiredSecGrpIncId() );
	}

}
