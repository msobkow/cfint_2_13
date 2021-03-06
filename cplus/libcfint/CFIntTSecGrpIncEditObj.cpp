// Description: C++18 edit object instance implementation for CFInt TSecGrpInc.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintobj/CFIntTSecGrpIncObj.hpp>
#include <cfintobj/CFIntTSecGrpIncEditObj.hpp>


namespace cfint {

	const std::string CFIntTSecGrpIncEditObj::CLASS_NAME( "CFIntTSecGrpIncEditObj" );

	CFIntTSecGrpIncEditObj::CFIntTSecGrpIncEditObj( cfsec::ICFSecTSecGrpIncObj* argOrig )
	: ICFIntTSecGrpIncEditObj(),
	  ICFSecTSecGrpIncEditObj()
	{
		static const std::string S_ProcName( "CFIntTSecGrpIncEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecTSecGrpIncBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecTSecGrpIncBuff*>( origBuff->clone() );
	}

	CFIntTSecGrpIncEditObj::~CFIntTSecGrpIncEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntTSecGrpIncEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntTSecGrpIncEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpIncBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntTSecGrpIncEditObj::getCreatedAt() {
		return( getTSecGrpIncBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntTSecGrpIncEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGrpIncBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntTSecGrpIncEditObj::getUpdatedAt() {
		return( getTSecGrpIncBuff()->getUpdatedAt() );
	}

	void CFIntTSecGrpIncEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getTSecGrpIncEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTSecGrpIncEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGrpIncEditBuff()->setCreatedAt( value );
	}

	void CFIntTSecGrpIncEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getTSecGrpIncEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTSecGrpIncEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGrpIncEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntTSecGrpIncEditObj::getClassCode() const {
		return( cfsec::CFSecTSecGrpIncBuff::CLASS_CODE );
	}

	bool CFIntTSecGrpIncEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecTSecGrpIncBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntTSecGrpIncEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTSecGrpIncEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGrpIncId( "TSecGrpIncId" );
		static const std::string S_TSecGroupId( "TSecGroupId" );
		static const std::string S_IncludeGroupId( "IncludeGroupId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntTSecGrpIncEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntTSecGrpIncEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntTSecGrpIncEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntTSecGrpIncEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntTSecGrpIncEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntTSecGrpIncEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TSecGrpIncId, CFIntTSecGrpIncEditObj::getRequiredTSecGrpIncId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_TSecGroupId, CFIntTSecGrpIncEditObj::getRequiredTSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_IncludeGroupId, CFIntTSecGrpIncEditObj::getRequiredIncludeGroupId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntTSecGrpIncEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntTSecGrpIncEditObj::setRequiredRevision( int32_t value ) {
		getTSecGrpIncEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntTSecGrpIncEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int64_t val = getRequiredTSecGrpIncId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFIntTSecGrpIncEditObj::getGenDefName() {
		return( cfsec::CFSecTSecGrpIncBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntTSecGrpIncEditObj::getScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTSecGrpIncEditObj::getObjScope() {
		cfsec::ICFSecTSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTSecGrpIncEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntTSecGrpIncEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntTSecGrpIncEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntTSecGrpIncEditObj::getObjQualifiedName() {
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

	std::string CFIntTSecGrpIncEditObj::getObjFullName() {
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

	cfsec::ICFSecTSecGrpIncObj* CFIntTSecGrpIncEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecTSecGrpIncObj* retobj = getSchema()->getTSecGrpIncTableObj()->realizeTSecGrpInc( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecTSecGrpIncObj* CFIntTSecGrpIncEditObj::read( bool forceRead ) {
		cfsec::ICFSecTSecGrpIncObj* retval = getOrigAsTSecGrpInc()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecTSecGrpIncObj* CFIntTSecGrpIncEditObj::create() {
		cfsec::ICFSecTSecGrpIncObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGrpInc()->getSchema() )->getTSecGrpIncTableObj()->createTSecGrpInc( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFIntTSecGrpIncEditObj::update() {
		getSchema()->getTSecGrpIncTableObj()->updateTSecGrpInc( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFIntTSecGrpIncEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getTSecGrpIncTableObj()->deleteTSecGrpInc( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGrpIncTableObj* CFIntTSecGrpIncEditObj::getTSecGrpIncTable() {
		return( orig->getSchema()->getTSecGrpIncTableObj() );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFIntTSecGrpIncEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFIntTSecGrpIncEditObj::getTSecGrpIncEdit() {
		return( (cfsec::ICFSecTSecGrpIncEditObj*)this );
	}

	cfsec::ICFSecTSecGrpIncEditObj* CFIntTSecGrpIncEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntTSecGrpIncEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecTSecGrpIncObj* CFIntTSecGrpIncEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecTSecGrpIncObj* CFIntTSecGrpIncEditObj::getOrigAsTSecGrpInc() {
		return( dynamic_cast<cfsec::ICFSecTSecGrpIncObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntTSecGrpIncEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecTSecGrpIncBuff* CFIntTSecGrpIncEditObj::getBuff() {
		return( buff );
	}

	void CFIntTSecGrpIncEditObj::setBuff( cfsec::CFSecTSecGrpIncBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecTSecGrpIncPKey* CFIntTSecGrpIncEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntTSecGrpIncEditObj::setPKey( cfsec::CFSecTSecGrpIncPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntTSecGrpIncEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntTSecGrpIncEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntTSecGrpIncEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntTSecGrpIncEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntTSecGrpIncEditObj::getRequiredTSecGrpIncId() {
		return( getPKey()->getRequiredTSecGrpIncId() );
	}

	const int64_t* CFIntTSecGrpIncEditObj::getRequiredTSecGrpIncIdReference() {
		return( getPKey()->getRequiredTSecGrpIncIdReference() );
	}

	const int32_t CFIntTSecGrpIncEditObj::getRequiredTSecGroupId() {
		return( getTSecGrpIncBuff()->getRequiredTSecGroupId() );
	}

	const int32_t* CFIntTSecGrpIncEditObj::getRequiredTSecGroupIdReference() {
		return( getTSecGrpIncBuff()->getRequiredTSecGroupIdReference() );
	}

	const int32_t CFIntTSecGrpIncEditObj::getRequiredIncludeGroupId() {
		return( getTSecGrpIncBuff()->getRequiredIncludeGroupId() );
	}

	const int32_t* CFIntTSecGrpIncEditObj::getRequiredIncludeGroupIdReference() {
		return( getTSecGrpIncBuff()->getRequiredIncludeGroupIdReference() );
	}

	cfsec::ICFSecTenantObj* CFIntTSecGrpIncEditObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGrpInc()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFIntTSecGrpIncEditObj::setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getTSecGrpIncEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	cfsec::ICFSecTSecGroupObj* CFIntTSecGrpIncEditObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGrpInc()->getSchema() )->getTSecGroupTableObj()->readTSecGroupByIdIdx( getPKey()->getRequiredTenantId(),
					getTSecGrpIncBuff()->getRequiredTSecGroupId() );
		}
		return( retobj );
	}

	void CFIntTSecGrpIncEditObj::setRequiredContainerGroup( cfsec::ICFSecTSecGroupObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredTenantId() );
				getTSecGrpIncEditBuff()->setRequiredTenantId( value->getRequiredTenantId() );
				getTSecGrpIncEditBuff()->setRequiredTSecGroupId( value->getRequiredTSecGroupId() );
			}
		}

	cfsec::ICFSecTSecGroupObj* CFIntTSecGrpIncEditObj::getRequiredParentSubGroup( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGrpInc()->getSchema() )->getTSecGroupTableObj()->readTSecGroupByIdIdx( getPKey()->getRequiredTenantId(),
					getTSecGrpIncBuff()->getRequiredIncludeGroupId() );
		}
		return( retobj );
	}

	void CFIntTSecGrpIncEditObj::setRequiredParentSubGroup( cfsec::ICFSecTSecGroupObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredTenantId() );
				getTSecGrpIncEditBuff()->setRequiredTenantId( value->getRequiredTenantId() );
				getTSecGrpIncEditBuff()->setRequiredIncludeGroupId( value->getRequiredTSecGroupId() );
			}
			else {
			}
		}

	void CFIntTSecGrpIncEditObj::copyPKeyToBuff() {
		cfsec::CFSecTSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpIncBuff* tableBuff = getTSecGrpIncEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredTSecGrpIncId( tablePKey->getRequiredTSecGrpIncId() );
	}

	void CFIntTSecGrpIncEditObj::copyBuffToPKey() {
		cfsec::CFSecTSecGrpIncPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGrpIncBuff* tableBuff = getTSecGrpIncBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredTSecGrpIncId( tableBuff->getRequiredTSecGrpIncId() );
	}

	void CFIntTSecGrpIncEditObj::copyBuffToOrig() {
		cfsec::CFSecTSecGrpIncBuff* origBuff = getOrigAsTSecGrpInc()->getTSecGrpIncEditBuff();
		cfsec::CFSecTSecGrpIncBuff* myBuff = getTSecGrpIncBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntTSecGrpIncEditObj::copyOrigToBuff() {
		cfsec::CFSecTSecGrpIncBuff* origBuff = getOrigAsTSecGrpInc()->getTSecGrpIncBuff();
		cfsec::CFSecTSecGrpIncBuff* myBuff = getTSecGrpIncEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
