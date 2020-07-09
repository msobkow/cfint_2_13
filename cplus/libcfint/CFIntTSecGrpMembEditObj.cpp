// Description: C++18 edit object instance implementation for CFInt TSecGrpMemb.

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
#include <cfintobj/CFIntTSecGrpMembObj.hpp>
#include <cfintobj/CFIntTSecGrpMembEditObj.hpp>


namespace cfint {

	const std::string CFIntTSecGrpMembEditObj::CLASS_NAME( "CFIntTSecGrpMembEditObj" );

	CFIntTSecGrpMembEditObj::CFIntTSecGrpMembEditObj( cfsec::ICFSecTSecGrpMembObj* argOrig )
	: ICFIntTSecGrpMembEditObj(),
	  ICFSecTSecGrpMembEditObj()
	{
		static const std::string S_ProcName( "CFIntTSecGrpMembEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecTSecGrpMembBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecTSecGrpMembBuff*>( origBuff->clone() );
	}

	CFIntTSecGrpMembEditObj::~CFIntTSecGrpMembEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntTSecGrpMembEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntTSecGrpMembEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpMembBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntTSecGrpMembEditObj::getCreatedAt() {
		return( getTSecGrpMembBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntTSecGrpMembEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpMembBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntTSecGrpMembEditObj::getUpdatedAt() {
		return( getTSecGrpMembBuff()->getUpdatedAt() );
	}

	void CFIntTSecGrpMembEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getTSecGrpMembEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTSecGrpMembEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGrpMembEditBuff()->setCreatedAt( value );
	}

	void CFIntTSecGrpMembEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getTSecGrpMembEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTSecGrpMembEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGrpMembEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntTSecGrpMembEditObj::getClassCode() const {
		return( cfsec::CFSecTSecGrpMembBuff::CLASS_CODE );
	}

	bool CFIntTSecGrpMembEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecTSecGrpMembBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntTSecGrpMembEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTSecGrpMembEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGrpMembId( "TSecGrpMembId" );
		static const std::string S_TSecGroupId( "TSecGroupId" );
		static const std::string S_SecUserId( "SecUserId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntTSecGrpMembEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntTSecGrpMembEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntTSecGrpMembEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntTSecGrpMembEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntTSecGrpMembEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntTSecGrpMembEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TSecGrpMembId, CFIntTSecGrpMembEditObj::getRequiredTSecGrpMembId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_TSecGroupId, CFIntTSecGrpMembEditObj::getRequiredTSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFIntTSecGrpMembEditObj::getRequiredSecUserId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntTSecGrpMembEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntTSecGrpMembEditObj::setRequiredRevision( int32_t value ) {
		getTSecGrpMembEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntTSecGrpMembEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int64_t val = getRequiredTSecGrpMembId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFIntTSecGrpMembEditObj::getGenDefName() {
		return( cfsec::CFSecTSecGrpMembBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntTSecGrpMembEditObj::getScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTSecGrpMembEditObj::getObjScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTSecGrpMembEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntTSecGrpMembEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntTSecGrpMembEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntTSecGrpMembEditObj::getObjQualifiedName() {
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

	std::string CFIntTSecGrpMembEditObj::getObjFullName() {
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

	cfsec::ICFSecTSecGrpMembObj* CFIntTSecGrpMembEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecTSecGrpMembObj* retobj = getSchema()->getTSecGrpMembTableObj()->realizeTSecGrpMemb( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecTSecGrpMembObj* CFIntTSecGrpMembEditObj::read( bool forceRead ) {
		cfsec::ICFSecTSecGrpMembObj* retval = getOrigAsTSecGrpMemb()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecTSecGrpMembObj* CFIntTSecGrpMembEditObj::create() {
		cfsec::ICFSecTSecGrpMembObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGrpMemb()->getSchema() )->getTSecGrpMembTableObj()->createTSecGrpMemb( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFIntTSecGrpMembEditObj::update() {
		getSchema()->getTSecGrpMembTableObj()->updateTSecGrpMemb( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFIntTSecGrpMembEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getTSecGrpMembTableObj()->deleteTSecGrpMemb( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGrpMembTableObj* CFIntTSecGrpMembEditObj::getTSecGrpMembTable() {
		return( orig->getSchema()->getTSecGrpMembTableObj() );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFIntTSecGrpMembEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFIntTSecGrpMembEditObj::getTSecGrpMembEdit() {
		return( (cfsec::ICFSecTSecGrpMembEditObj*)this );
	}

	cfsec::ICFSecTSecGrpMembEditObj* CFIntTSecGrpMembEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntTSecGrpMembEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecTSecGrpMembObj* CFIntTSecGrpMembEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecTSecGrpMembObj* CFIntTSecGrpMembEditObj::getOrigAsTSecGrpMemb() {
		return( dynamic_cast<cfsec::ICFSecTSecGrpMembObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntTSecGrpMembEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecTSecGrpMembBuff* CFIntTSecGrpMembEditObj::getBuff() {
		return( buff );
	}

	void CFIntTSecGrpMembEditObj::setBuff( cfsec::CFSecTSecGrpMembBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecTSecGrpMembPKey* CFIntTSecGrpMembEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntTSecGrpMembEditObj::setPKey( cfsec::CFSecTSecGrpMembPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntTSecGrpMembEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntTSecGrpMembEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntTSecGrpMembEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntTSecGrpMembEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntTSecGrpMembEditObj::getRequiredTSecGrpMembId() {
		return( getPKey()->getRequiredTSecGrpMembId() );
	}

	const int64_t* CFIntTSecGrpMembEditObj::getRequiredTSecGrpMembIdReference() {
		return( getPKey()->getRequiredTSecGrpMembIdReference() );
	}

	const int32_t CFIntTSecGrpMembEditObj::getRequiredTSecGroupId() {
		return( getTSecGrpMembBuff()->getRequiredTSecGroupId() );
	}

	const int32_t* CFIntTSecGrpMembEditObj::getRequiredTSecGroupIdReference() {
		return( getTSecGrpMembBuff()->getRequiredTSecGroupIdReference() );
	}

	const uuid_ptr_t CFIntTSecGrpMembEditObj::getRequiredSecUserId() {
		return( getTSecGrpMembBuff()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFIntTSecGrpMembEditObj::getRequiredSecUserIdReference() {
		return( getTSecGrpMembBuff()->getRequiredSecUserIdReference() );
	}

	cfsec::ICFSecTenantObj* CFIntTSecGrpMembEditObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGrpMemb()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFIntTSecGrpMembEditObj::setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getTSecGrpMembEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	cfsec::ICFSecTSecGroupObj* CFIntTSecGrpMembEditObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGrpMemb()->getSchema() )->getTSecGroupTableObj()->readTSecGroupByIdIdx( getPKey()->getRequiredTenantId(),
					getTSecGrpMembBuff()->getRequiredTSecGroupId() );
		}
		return( retobj );
	}

	void CFIntTSecGrpMembEditObj::setRequiredContainerGroup( cfsec::ICFSecTSecGroupObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredTenantId() );
				getTSecGrpMembEditBuff()->setRequiredTenantId( value->getRequiredTenantId() );
				getTSecGrpMembEditBuff()->setRequiredTSecGroupId( value->getRequiredTSecGroupId() );
			}
		}

	cfsec::ICFSecSecUserObj* CFIntTSecGrpMembEditObj::getRequiredParentUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGrpMemb()->getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpMembBuff()->getRequiredSecUserId() );
		}
		return( retobj );
	}

	void CFIntTSecGrpMembEditObj::setRequiredParentUser( cfsec::ICFSecSecUserObj* value ) {
			
			if( value != NULL ) {
				getTSecGrpMembEditBuff()->setRequiredSecUserId( value->getRequiredSecUserId() );
			}
			else {
			}
		}

	void CFIntTSecGrpMembEditObj::copyPKeyToBuff() {
		cfsec::CFSecTSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpMembBuff* tableBuff = getTSecGrpMembEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredTSecGrpMembId( tablePKey->getRequiredTSecGrpMembId() );
	}

	void CFIntTSecGrpMembEditObj::copyBuffToPKey() {
		cfsec::CFSecTSecGrpMembPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpMembBuff* tableBuff = getTSecGrpMembBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredTSecGrpMembId( tableBuff->getRequiredTSecGrpMembId() );
	}

	void CFIntTSecGrpMembEditObj::copyBuffToOrig() {
		cfsec::CFSecTSecGrpMembBuff* origBuff = getOrigAsTSecGrpMemb()->getTSecGrpMembEditBuff();
		cfsec::CFSecTSecGrpMembBuff* myBuff = getTSecGrpMembBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntTSecGrpMembEditObj::copyOrigToBuff() {
		cfsec::CFSecTSecGrpMembBuff* origBuff = getOrigAsTSecGrpMemb()->getTSecGrpMembBuff();
		cfsec::CFSecTSecGrpMembBuff* myBuff = getTSecGrpMembEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
