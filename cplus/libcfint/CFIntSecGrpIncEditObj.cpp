// Description: C++18 edit object instance implementation for CFInt SecGrpInc.

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
#include <cfintobj/CFIntSecGrpIncObj.hpp>
#include <cfintobj/CFIntSecGrpIncEditObj.hpp>


namespace cfint {

	const std::string CFIntSecGrpIncEditObj::CLASS_NAME( "CFIntSecGrpIncEditObj" );

	CFIntSecGrpIncEditObj::CFIntSecGrpIncEditObj( cfsec::ICFSecSecGrpIncObj* argOrig )
	: ICFIntSecGrpIncEditObj(),
	  ICFSecSecGrpIncEditObj()
	{
		static const std::string S_ProcName( "CFIntSecGrpIncEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecGrpIncBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( origBuff->clone() );
	}

	CFIntSecGrpIncEditObj::~CFIntSecGrpIncEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntSecGrpIncEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGrpIncEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpIncBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGrpIncEditObj::getCreatedAt() {
		return( getSecGrpIncBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGrpIncEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGrpIncBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGrpIncEditObj::getUpdatedAt() {
		return( getSecGrpIncBuff()->getUpdatedAt() );
	}

	void CFIntSecGrpIncEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSecGrpIncEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecGrpIncEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecGrpIncEditBuff()->setCreatedAt( value );
	}

	void CFIntSecGrpIncEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSecGrpIncEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecGrpIncEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecGrpIncEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntSecGrpIncEditObj::getClassCode() const {
		return( cfsec::CFSecSecGrpIncBuff::CLASS_CODE );
	}

	bool CFIntSecGrpIncEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecGrpIncEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecGrpIncEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecGrpIncEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecGrpIncEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecGrpIncEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecGrpIncEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecGrpIncEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSecGrpIncEditObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SecGrpIncId, CFIntSecGrpIncEditObj::getRequiredSecGrpIncId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, CFIntSecGrpIncEditObj::getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_IncludeGroupId, CFIntSecGrpIncEditObj::getRequiredIncludeGroupId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntSecGrpIncEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntSecGrpIncEditObj::setRequiredRevision( int32_t value ) {
		getSecGrpIncEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntSecGrpIncEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int64_t val = getRequiredSecGrpIncId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFIntSecGrpIncEditObj::getGenDefName() {
		return( cfsec::CFSecSecGrpIncBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpIncEditObj::getScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpIncEditObj::getObjScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpIncEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecGrpIncEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecGrpIncEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecGrpIncEditObj::getObjQualifiedName() {
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

	std::string CFIntSecGrpIncEditObj::getObjFullName() {
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

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecGrpIncObj* retobj = getSchema()->getSecGrpIncTableObj()->realizeSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecGrpIncObj* retval = getOrigAsSecGrpInc()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncEditObj::create() {
		cfsec::ICFSecSecGrpIncObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGrpInc()->getSchema() )->getSecGrpIncTableObj()->createSecGrpInc( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecGrpIncEditObj* CFIntSecGrpIncEditObj::update() {
		getSchema()->getSecGrpIncTableObj()->updateSecGrpInc( this );
		return( NULL );
	}

	cfsec::ICFSecSecGrpIncEditObj* CFIntSecGrpIncEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecGrpIncTableObj()->deleteSecGrpInc( this );
		return( NULL );
	}

	cfsec::ICFSecSecGrpIncTableObj* CFIntSecGrpIncEditObj::getSecGrpIncTable() {
		return( orig->getSchema()->getSecGrpIncTableObj() );
	}

	cfsec::ICFSecSecGrpIncEditObj* CFIntSecGrpIncEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecGrpIncEditObj* CFIntSecGrpIncEditObj::getSecGrpIncEdit() {
		return( (cfsec::ICFSecSecGrpIncEditObj*)this );
	}

	cfsec::ICFSecSecGrpIncEditObj* CFIntSecGrpIncEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntSecGrpIncEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncEditObj::getOrigAsSecGrpInc() {
		return( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntSecGrpIncEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecGrpIncBuff* CFIntSecGrpIncEditObj::getBuff() {
		return( buff );
	}

	void CFIntSecGrpIncEditObj::setBuff( cfsec::CFSecSecGrpIncBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecGrpIncPKey* CFIntSecGrpIncEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntSecGrpIncEditObj::setPKey( cfsec::CFSecSecGrpIncPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntSecGrpIncEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntSecGrpIncEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntSecGrpIncEditObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFIntSecGrpIncEditObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int64_t CFIntSecGrpIncEditObj::getRequiredSecGrpIncId() {
		return( getPKey()->getRequiredSecGrpIncId() );
	}

	const int64_t* CFIntSecGrpIncEditObj::getRequiredSecGrpIncIdReference() {
		return( getPKey()->getRequiredSecGrpIncIdReference() );
	}

	const int32_t CFIntSecGrpIncEditObj::getRequiredSecGroupId() {
		return( getSecGrpIncBuff()->getRequiredSecGroupId() );
	}

	const int32_t* CFIntSecGrpIncEditObj::getRequiredSecGroupIdReference() {
		return( getSecGrpIncBuff()->getRequiredSecGroupIdReference() );
	}

	const int32_t CFIntSecGrpIncEditObj::getRequiredIncludeGroupId() {
		return( getSecGrpIncBuff()->getRequiredIncludeGroupId() );
	}

	const int32_t* CFIntSecGrpIncEditObj::getRequiredIncludeGroupIdReference() {
		return( getSecGrpIncBuff()->getRequiredIncludeGroupIdReference() );
	}

	cfsec::ICFSecClusterObj* CFIntSecGrpIncEditObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGrpInc()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFIntSecGrpIncEditObj::setRequiredOwnerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredId() );
				getSecGrpIncEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	cfsec::ICFSecSecGroupObj* CFIntSecGrpIncEditObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGrpInc()->getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGrpIncBuff()->getRequiredSecGroupId() );
		}
		return( retobj );
	}

	void CFIntSecGrpIncEditObj::setRequiredContainerGroup( cfsec::ICFSecSecGroupObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredClusterId() );
				getSecGrpIncEditBuff()->setRequiredClusterId( value->getRequiredClusterId() );
				getSecGrpIncEditBuff()->setRequiredSecGroupId( value->getRequiredSecGroupId() );
			}
		}

	cfsec::ICFSecSecGroupObj* CFIntSecGrpIncEditObj::getRequiredParentSubGroup( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGrpInc()->getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGrpIncBuff()->getRequiredIncludeGroupId() );
		}
		return( retobj );
	}

	void CFIntSecGrpIncEditObj::setRequiredParentSubGroup( cfsec::ICFSecSecGroupObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredClusterId() );
				getSecGrpIncEditBuff()->setRequiredClusterId( value->getRequiredClusterId() );
				getSecGrpIncEditBuff()->setRequiredIncludeGroupId( value->getRequiredSecGroupId() );
			}
			else {
			}
		}

	void CFIntSecGrpIncEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpIncBuff* tableBuff = getSecGrpIncEditBuff();
		tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
		tableBuff->setRequiredSecGrpIncId( tablePKey->getRequiredSecGrpIncId() );
	}

	void CFIntSecGrpIncEditObj::copyBuffToPKey() {
		cfsec::CFSecSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecSecGrpIncBuff* tableBuff = getSecGrpIncBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecGrpIncId( tableBuff->getRequiredSecGrpIncId() );
	}

	void CFIntSecGrpIncEditObj::copyBuffToOrig() {
		cfsec::CFSecSecGrpIncBuff* origBuff = getOrigAsSecGrpInc()->getSecGrpIncEditBuff();
		cfsec::CFSecSecGrpIncBuff* myBuff = getSecGrpIncBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntSecGrpIncEditObj::copyOrigToBuff() {
		cfsec::CFSecSecGrpIncBuff* origBuff = getOrigAsSecGrpInc()->getSecGrpIncBuff();
		cfsec::CFSecSecGrpIncBuff* myBuff = getSecGrpIncEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}