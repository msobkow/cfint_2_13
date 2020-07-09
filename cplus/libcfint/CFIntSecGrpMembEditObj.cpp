// Description: C++18 edit object instance implementation for CFInt SecGrpMemb.

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
#include <cfintobj/CFIntSecGrpMembObj.hpp>
#include <cfintobj/CFIntSecGrpMembEditObj.hpp>


namespace cfint {

	const std::string CFIntSecGrpMembEditObj::CLASS_NAME( "CFIntSecGrpMembEditObj" );

	CFIntSecGrpMembEditObj::CFIntSecGrpMembEditObj( cfsec::ICFSecSecGrpMembObj* argOrig )
	: ICFIntSecGrpMembEditObj(),
	  ICFSecSecGrpMembEditObj()
	{
		static const std::string S_ProcName( "CFIntSecGrpMembEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecGrpMembBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecGrpMembBuff*>( origBuff->clone() );
	}

	CFIntSecGrpMembEditObj::~CFIntSecGrpMembEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntSecGrpMembEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGrpMembEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpMembBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGrpMembEditObj::getCreatedAt() {
		return( getSecGrpMembBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGrpMembEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpMembBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGrpMembEditObj::getUpdatedAt() {
		return( getSecGrpMembBuff()->getUpdatedAt() );
	}

	void CFIntSecGrpMembEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSecGrpMembEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecGrpMembEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecGrpMembEditBuff()->setCreatedAt( value );
	}

	void CFIntSecGrpMembEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSecGrpMembEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecGrpMembEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecGrpMembEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntSecGrpMembEditObj::getClassCode() const {
		return( cfsec::CFSecSecGrpMembBuff::CLASS_CODE );
	}

	bool CFIntSecGrpMembEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecGrpMembBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecGrpMembEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecGrpMembEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecGrpMembEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecGrpMembEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecGrpMembEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecGrpMembEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecGrpMembEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSecGrpMembEditObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SecGrpMembId, CFIntSecGrpMembEditObj::getRequiredSecGrpMembId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, CFIntSecGrpMembEditObj::getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFIntSecGrpMembEditObj::getRequiredSecUserId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntSecGrpMembEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntSecGrpMembEditObj::setRequiredRevision( int32_t value ) {
		getSecGrpMembEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntSecGrpMembEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int64_t val = getRequiredSecGrpMembId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFIntSecGrpMembEditObj::getGenDefName() {
		return( cfsec::CFSecSecGrpMembBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpMembEditObj::getScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpMembEditObj::getObjScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpMembEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecGrpMembEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpMembEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecGrpMembEditObj::getObjQualifiedName() {
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

	std::string CFIntSecGrpMembEditObj::getObjFullName() {
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

	cfsec::ICFSecSecGrpMembObj* CFIntSecGrpMembEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecGrpMembObj* retobj = getSchema()->getSecGrpMembTableObj()->realizeSecGrpMemb( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecGrpMembObj* CFIntSecGrpMembEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecGrpMembObj* retval = getOrigAsSecGrpMemb()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecGrpMembObj* CFIntSecGrpMembEditObj::create() {
		cfsec::ICFSecSecGrpMembObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGrpMemb()->getSchema() )->getSecGrpMembTableObj()->createSecGrpMemb( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFIntSecGrpMembEditObj::update() {
		getSchema()->getSecGrpMembTableObj()->updateSecGrpMemb( this );
		return( NULL );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFIntSecGrpMembEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecGrpMembTableObj()->deleteSecGrpMemb( this );
		return( NULL );
	}

	cfsec::ICFSecSecGrpMembTableObj* CFIntSecGrpMembEditObj::getSecGrpMembTable() {
		return( orig->getSchema()->getSecGrpMembTableObj() );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFIntSecGrpMembEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFIntSecGrpMembEditObj::getSecGrpMembEdit() {
		return( (cfsec::ICFSecSecGrpMembEditObj*)this );
	}

	cfsec::ICFSecSecGrpMembEditObj* CFIntSecGrpMembEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntSecGrpMembEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecGrpMembObj* CFIntSecGrpMembEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecGrpMembObj* CFIntSecGrpMembEditObj::getOrigAsSecGrpMemb() {
		return( dynamic_cast<cfsec::ICFSecSecGrpMembObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntSecGrpMembEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecGrpMembBuff* CFIntSecGrpMembEditObj::getBuff() {
		return( buff );
	}

	void CFIntSecGrpMembEditObj::setBuff( cfsec::CFSecSecGrpMembBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecGrpMembPKey* CFIntSecGrpMembEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntSecGrpMembEditObj::setPKey( cfsec::CFSecSecGrpMembPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntSecGrpMembEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntSecGrpMembEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntSecGrpMembEditObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFIntSecGrpMembEditObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int64_t CFIntSecGrpMembEditObj::getRequiredSecGrpMembId() {
		return( getPKey()->getRequiredSecGrpMembId() );
	}

	const int64_t* CFIntSecGrpMembEditObj::getRequiredSecGrpMembIdReference() {
		return( getPKey()->getRequiredSecGrpMembIdReference() );
	}

	const int32_t CFIntSecGrpMembEditObj::getRequiredSecGroupId() {
		return( getSecGrpMembBuff()->getRequiredSecGroupId() );
	}

	const int32_t* CFIntSecGrpMembEditObj::getRequiredSecGroupIdReference() {
		return( getSecGrpMembBuff()->getRequiredSecGroupIdReference() );
	}

	const uuid_ptr_t CFIntSecGrpMembEditObj::getRequiredSecUserId() {
		return( getSecGrpMembBuff()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFIntSecGrpMembEditObj::getRequiredSecUserIdReference() {
		return( getSecGrpMembBuff()->getRequiredSecUserIdReference() );
	}

	cfsec::ICFSecClusterObj* CFIntSecGrpMembEditObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGrpMemb()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFIntSecGrpMembEditObj::setRequiredOwnerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredId() );
				getSecGrpMembEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	cfsec::ICFSecSecGroupObj* CFIntSecGrpMembEditObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGrpMemb()->getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGrpMembBuff()->getRequiredSecGroupId() );
		}
		return( retobj );
	}

	void CFIntSecGrpMembEditObj::setRequiredContainerGroup( cfsec::ICFSecSecGroupObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredClusterId() );
				getSecGrpMembEditBuff()->setRequiredClusterId( value->getRequiredClusterId() );
				getSecGrpMembEditBuff()->setRequiredSecGroupId( value->getRequiredSecGroupId() );
			}
		}

	cfsec::ICFSecSecUserObj* CFIntSecGrpMembEditObj::getRequiredParentUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGrpMemb()->getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpMembBuff()->getRequiredSecUserId() );
		}
		return( retobj );
	}

	void CFIntSecGrpMembEditObj::setRequiredParentUser( cfsec::ICFSecSecUserObj* value ) {
			
			if( value != NULL ) {
				getSecGrpMembEditBuff()->setRequiredSecUserId( value->getRequiredSecUserId() );
			}
			else {
			}
		}

	void CFIntSecGrpMembEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpMembBuff* tableBuff = getSecGrpMembEditBuff();
		tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
		tableBuff->setRequiredSecGrpMembId( tablePKey->getRequiredSecGrpMembId() );
	}

	void CFIntSecGrpMembEditObj::copyBuffToPKey() {
		cfsec::CFSecSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpMembBuff* tableBuff = getSecGrpMembBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecGrpMembId( tableBuff->getRequiredSecGrpMembId() );
	}

	void CFIntSecGrpMembEditObj::copyBuffToOrig() {
		cfsec::CFSecSecGrpMembBuff* origBuff = getOrigAsSecGrpMemb()->getSecGrpMembEditBuff();
		cfsec::CFSecSecGrpMembBuff* myBuff = getSecGrpMembBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntSecGrpMembEditObj::copyOrigToBuff() {
		cfsec::CFSecSecGrpMembBuff* origBuff = getOrigAsSecGrpMemb()->getSecGrpMembBuff();
		cfsec::CFSecSecGrpMembBuff* myBuff = getSecGrpMembEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
