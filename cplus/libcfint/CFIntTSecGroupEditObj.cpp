// Description: C++18 edit object instance implementation for CFInt TSecGroup.

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
#include <cfintobj/CFIntTSecGroupObj.hpp>
#include <cfintobj/CFIntTSecGroupEditObj.hpp>


namespace cfint {

	const std::string CFIntTSecGroupEditObj::CLASS_NAME( "CFIntTSecGroupEditObj" );

	CFIntTSecGroupEditObj::CFIntTSecGroupEditObj( cfsec::ICFSecTSecGroupObj* argOrig )
	: ICFIntTSecGroupEditObj(),
	  ICFSecTSecGroupEditObj()
	{
		static const std::string S_ProcName( "CFIntTSecGroupEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecTSecGroupBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecTSecGroupBuff*>( origBuff->clone() );
	}

	CFIntTSecGroupEditObj::~CFIntTSecGroupEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntTSecGroupEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntTSecGroupEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGroupBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntTSecGroupEditObj::getCreatedAt() {
		return( getTSecGroupBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntTSecGroupEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTSecGroupBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntTSecGroupEditObj::getUpdatedAt() {
		return( getTSecGroupBuff()->getUpdatedAt() );
	}

	void CFIntTSecGroupEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getTSecGroupEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTSecGroupEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGroupEditBuff()->setCreatedAt( value );
	}

	void CFIntTSecGroupEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getTSecGroupEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTSecGroupEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getTSecGroupEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntTSecGroupEditObj::getClassCode() const {
		return( cfsec::CFSecTSecGroupBuff::CLASS_CODE );
	}

	bool CFIntTSecGroupEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecTSecGroupBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntTSecGroupEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTSecGroupEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TSecGroupId( "TSecGroupId" );
		static const std::string S_Name( "Name" );
		static const std::string S_IsVisible( "IsVisible" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntTSecGroupEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntTSecGroupEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntTSecGroupEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntTSecGroupEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntTSecGroupEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntTSecGroupEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_TSecGroupId, CFIntTSecGroupEditObj::getRequiredTSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntTSecGroupEditObj::getRequiredName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsVisible, CFIntTSecGroupEditObj::getRequiredIsVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntTSecGroupEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntTSecGroupEditObj::setRequiredRevision( int32_t value ) {
		getTSecGroupEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntTSecGroupEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntTSecGroupEditObj::getGenDefName() {
		return( cfsec::CFSecTSecGroupBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntTSecGroupEditObj::getScope() {
		cfsec::ICFSecTenantObj* scope = getRequiredContainerTenant();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTSecGroupEditObj::getObjScope() {
		cfsec::ICFSecTenantObj* scope = getRequiredContainerTenant();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTSecGroupEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntTSecGroupEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntTSecGroupEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntTSecGroupEditObj::getObjQualifiedName() {
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

	std::string CFIntTSecGroupEditObj::getObjFullName() {
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

	cfsec::ICFSecTSecGroupObj* CFIntTSecGroupEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecTSecGroupObj* retobj = getSchema()->getTSecGroupTableObj()->realizeTSecGroup( dynamic_cast<cfsec::ICFSecTSecGroupObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecTSecGroupObj* CFIntTSecGroupEditObj::read( bool forceRead ) {
		cfsec::ICFSecTSecGroupObj* retval = getOrigAsTSecGroup()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecTSecGroupObj* CFIntTSecGroupEditObj::create() {
		cfsec::ICFSecTSecGroupObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGroup()->getSchema() )->getTSecGroupTableObj()->createTSecGroup( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecTSecGroupEditObj* CFIntTSecGroupEditObj::update() {
		getSchema()->getTSecGroupTableObj()->updateTSecGroup( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGroupEditObj* CFIntTSecGroupEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getTSecGroupTableObj()->deleteTSecGroup( this );
		return( NULL );
	}

	cfsec::ICFSecTSecGroupTableObj* CFIntTSecGroupEditObj::getTSecGroupTable() {
		return( orig->getSchema()->getTSecGroupTableObj() );
	}

	cfsec::ICFSecTSecGroupEditObj* CFIntTSecGroupEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecTSecGroupEditObj* CFIntTSecGroupEditObj::getTSecGroupEdit() {
		return( (cfsec::ICFSecTSecGroupEditObj*)this );
	}

	cfsec::ICFSecTSecGroupEditObj* CFIntTSecGroupEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntTSecGroupEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecTSecGroupObj* CFIntTSecGroupEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecTSecGroupObj* CFIntTSecGroupEditObj::getOrigAsTSecGroup() {
		return( dynamic_cast<cfsec::ICFSecTSecGroupObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntTSecGroupEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecTSecGroupBuff* CFIntTSecGroupEditObj::getBuff() {
		return( buff );
	}

	void CFIntTSecGroupEditObj::setBuff( cfsec::CFSecTSecGroupBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecTSecGroupPKey* CFIntTSecGroupEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntTSecGroupEditObj::setPKey( cfsec::CFSecTSecGroupPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntTSecGroupEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntTSecGroupEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntTSecGroupEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntTSecGroupEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int32_t CFIntTSecGroupEditObj::getRequiredTSecGroupId() {
		return( getPKey()->getRequiredTSecGroupId() );
	}

	const int32_t* CFIntTSecGroupEditObj::getRequiredTSecGroupIdReference() {
		return( getPKey()->getRequiredTSecGroupIdReference() );
	}

	const std::string& CFIntTSecGroupEditObj::getRequiredName() {
		return( getTSecGroupBuff()->getRequiredName() );
	}

	const std::string* CFIntTSecGroupEditObj::getRequiredNameReference() {
		return( getTSecGroupBuff()->getRequiredNameReference() );
	}

	void CFIntTSecGroupEditObj::setRequiredName( const std::string& value ) {
		if( getTSecGroupBuff()->getRequiredName() != value ) {
			getTSecGroupEditBuff()->setRequiredName( value );
		}
	}

	const bool CFIntTSecGroupEditObj::getRequiredIsVisible() {
		return( getTSecGroupBuff()->getRequiredIsVisible() );
	}

	const bool* CFIntTSecGroupEditObj::getRequiredIsVisibleReference() {
		return( getTSecGroupBuff()->getRequiredIsVisibleReference() );
	}

	void CFIntTSecGroupEditObj::setRequiredIsVisible( const bool value ) {
		if( getTSecGroupBuff()->getRequiredIsVisible() != value ) {
			getTSecGroupEditBuff()->setRequiredIsVisible( value );
		}
	}

	cfsec::ICFSecTenantObj* CFIntTSecGroupEditObj::getRequiredContainerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGroup()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFIntTSecGroupEditObj::setRequiredContainerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getTSecGroupEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFIntTSecGroupEditObj::getOptionalComponentsInclude( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpIncObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGroup()->getSchema() )->getTSecGrpIncTableObj()->readTSecGrpIncByGroupIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTSecGrpMembObj*> CFIntTSecGroupEditObj::getOptionalComponentsMember( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpMembObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGroup()->getSchema() )->getTSecGrpMembTableObj()->readTSecGrpMembByGroupIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTSecGrpIncObj*> CFIntTSecGroupEditObj::getRequiredChildrenIncByGroup( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGrpIncObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTSecGroup()->getSchema() )->getTSecGrpIncTableObj()->readTSecGrpIncByIncludeIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredTSecGroupId(),
			forceRead );
		return( retval );
	}

	void CFIntTSecGroupEditObj::copyPKeyToBuff() {
		cfsec::CFSecTSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGroupBuff* tableBuff = getTSecGroupEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredTSecGroupId( tablePKey->getRequiredTSecGroupId() );
	}

	void CFIntTSecGroupEditObj::copyBuffToPKey() {
		cfsec::CFSecTSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecTSecGroupBuff* tableBuff = getTSecGroupBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredTSecGroupId( tableBuff->getRequiredTSecGroupId() );
	}

	void CFIntTSecGroupEditObj::copyBuffToOrig() {
		cfsec::CFSecTSecGroupBuff* origBuff = getOrigAsTSecGroup()->getTSecGroupEditBuff();
		cfsec::CFSecTSecGroupBuff* myBuff = getTSecGroupBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntTSecGroupEditObj::copyOrigToBuff() {
		cfsec::CFSecTSecGroupBuff* origBuff = getOrigAsTSecGroup()->getTSecGroupBuff();
		cfsec::CFSecTSecGroupBuff* myBuff = getTSecGroupEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
