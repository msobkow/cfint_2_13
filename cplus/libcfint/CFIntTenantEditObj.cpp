// Description: C++18 edit object instance implementation for CFInt Tenant.

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
#include <cfintobj/CFIntTenantObj.hpp>
#include <cfintobj/CFIntTenantEditObj.hpp>


namespace cfint {

	const std::string CFIntTenantEditObj::CLASS_NAME( "CFIntTenantEditObj" );

	CFIntTenantEditObj::CFIntTenantEditObj( cfsec::ICFSecTenantObj* argOrig )
	: ICFIntTenantEditObj(),
	  ICFSecTenantEditObj()
	{
		static const std::string S_ProcName( "CFIntTenantEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecTenantBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecTenantBuff*>( origBuff->clone() );
	}

	CFIntTenantEditObj::~CFIntTenantEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntTenantEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntTenantEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTenantBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntTenantEditObj::getCreatedAt() {
		return( getTenantBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntTenantEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTenantBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntTenantEditObj::getUpdatedAt() {
		return( getTenantBuff()->getUpdatedAt() );
	}

	void CFIntTenantEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getTenantEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTenantEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getTenantEditBuff()->setCreatedAt( value );
	}

	void CFIntTenantEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getTenantEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTenantEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getTenantEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntTenantEditObj::getClassCode() const {
		return( cfsec::CFSecTenantBuff::CLASS_CODE );
	}

	bool CFIntTenantEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecTenantBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntTenantEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTenantEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_Id( "Id" );
		static const std::string S_TenantName( "TenantName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntTenantEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntTenantEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntTenantEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntTenantEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntTenantEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntTenantEditObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntTenantEditObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_TenantName, CFIntTenantEditObj::getRequiredTenantName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntTenantEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntTenantEditObj::setRequiredRevision( int32_t value ) {
		getTenantEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntTenantEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredTenantName() );
		return( objName );
	}

	const std::string CFIntTenantEditObj::getGenDefName() {
		return( cfsec::CFSecTenantBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntTenantEditObj::getScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTenantEditObj::getObjScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTenantEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntTenantEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntTenantEditObj::getNamedObject( const std::string& objName ) {
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
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTldTableObj()->readTldByLookupNameIdx( getRequiredId(),
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

	std::string CFIntTenantEditObj::getObjQualifiedName() {
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

	std::string CFIntTenantEditObj::getObjFullName() {
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

	cfsec::ICFSecTenantObj* CFIntTenantEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecTenantObj* retobj = getSchema()->getTenantTableObj()->realizeTenant( dynamic_cast<cfsec::ICFSecTenantObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecTenantObj* CFIntTenantEditObj::read( bool forceRead ) {
		cfsec::ICFSecTenantObj* retval = getOrigAsTenant()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecTenantObj* CFIntTenantEditObj::create() {
		cfsec::ICFSecTenantObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTenant()->getSchema() )->getTenantTableObj()->createTenant( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecTenantEditObj* CFIntTenantEditObj::update() {
		getSchema()->getTenantTableObj()->updateTenant( this );
		return( NULL );
	}

	cfsec::ICFSecTenantEditObj* CFIntTenantEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getTenantTableObj()->deleteTenant( this );
		return( NULL );
	}

	cfsec::ICFSecTenantTableObj* CFIntTenantEditObj::getTenantTable() {
		return( orig->getSchema()->getTenantTableObj() );
	}

	cfsec::ICFSecTenantEditObj* CFIntTenantEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecTenantEditObj* CFIntTenantEditObj::getTenantEdit() {
		return( (cfsec::ICFSecTenantEditObj*)this );
	}

	cfsec::ICFSecTenantEditObj* CFIntTenantEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntTenantEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecTenantObj* CFIntTenantEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecTenantObj* CFIntTenantEditObj::getOrigAsTenant() {
		return( dynamic_cast<cfsec::ICFSecTenantObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntTenantEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecTenantBuff* CFIntTenantEditObj::getBuff() {
		return( buff );
	}

	void CFIntTenantEditObj::setBuff( cfsec::CFSecTenantBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecTenantPKey* CFIntTenantEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntTenantEditObj::setPKey( cfsec::CFSecTenantPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntTenantEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntTenantEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntTenantEditObj::getRequiredClusterId() {
		return( getTenantBuff()->getRequiredClusterId() );
	}

	const int64_t* CFIntTenantEditObj::getRequiredClusterIdReference() {
		return( getTenantBuff()->getRequiredClusterIdReference() );
	}

	const int64_t CFIntTenantEditObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntTenantEditObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const std::string& CFIntTenantEditObj::getRequiredTenantName() {
		return( getTenantBuff()->getRequiredTenantName() );
	}

	const std::string* CFIntTenantEditObj::getRequiredTenantNameReference() {
		return( getTenantBuff()->getRequiredTenantNameReference() );
	}

	void CFIntTenantEditObj::setRequiredTenantName( const std::string& value ) {
		if( getTenantBuff()->getRequiredTenantName() != value ) {
			getTenantEditBuff()->setRequiredTenantName( value );
		}
	}

	cfsec::ICFSecClusterObj* CFIntTenantEditObj::getRequiredContainerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTenant()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getTenantBuff()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFIntTenantEditObj::setRequiredContainerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getTenantEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	std::vector<cfsec::ICFSecTSecGroupObj*> CFIntTenantEditObj::getOptionalComponentsTSecGroup( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGroupObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTenant()->getSchema() )->getTSecGroupTableObj()->readTSecGroupByTenantIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfint::ICFIntTldObj*> CFIntTenantEditObj::getOptionalComponentsTld( bool forceRead ) {
		std::vector<cfint::ICFIntTldObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTenant()->getSchema() )->getTldTableObj()->readTldByTenantIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	void CFIntTenantEditObj::copyPKeyToBuff() {
		cfsec::CFSecTenantPKey* tablePKey = getPKey();
		cfsec::CFSecTenantBuff* tableBuff = getTenantEditBuff();
		tableBuff->setRequiredId( tablePKey->getRequiredId() );
	}

	void CFIntTenantEditObj::copyBuffToPKey() {
		cfsec::CFSecTenantPKey* tablePKey = getPKey();
		cfsec::CFSecTenantBuff* tableBuff = getTenantBuff();
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

	void CFIntTenantEditObj::copyBuffToOrig() {
		cfsec::CFSecTenantBuff* origBuff = getOrigAsTenant()->getTenantEditBuff();
		cfsec::CFSecTenantBuff* myBuff = getTenantBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntTenantEditObj::copyOrigToBuff() {
		cfsec::CFSecTenantBuff* origBuff = getOrigAsTenant()->getTenantBuff();
		cfsec::CFSecTenantBuff* myBuff = getTenantEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
