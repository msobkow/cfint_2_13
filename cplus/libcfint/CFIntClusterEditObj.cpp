// Description: C++18 edit object instance implementation for CFInt Cluster.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintobj/CFIntClusterObj.hpp>
#include <cfintobj/CFIntClusterEditObj.hpp>


namespace cfint {

	const std::string CFIntClusterEditObj::CLASS_NAME( "CFIntClusterEditObj" );

	CFIntClusterEditObj::CFIntClusterEditObj( cfsec::ICFSecClusterObj* argOrig )
	: ICFIntClusterEditObj(),
	  ICFSecClusterEditObj()
	{
		static const std::string S_ProcName( "CFIntClusterEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecClusterBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecClusterBuff*>( origBuff->clone() );
	}

	CFIntClusterEditObj::~CFIntClusterEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntClusterEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntClusterEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getClusterBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntClusterEditObj::getCreatedAt() {
		return( getClusterBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntClusterEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getClusterBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntClusterEditObj::getUpdatedAt() {
		return( getClusterBuff()->getUpdatedAt() );
	}

	void CFIntClusterEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getClusterEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntClusterEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getClusterEditBuff()->setCreatedAt( value );
	}

	void CFIntClusterEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getClusterEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntClusterEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getClusterEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntClusterEditObj::getClassCode() const {
		return( cfsec::CFSecClusterBuff::CLASS_CODE );
	}

	bool CFIntClusterEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecClusterBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntClusterEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntClusterEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_Id( "Id" );
		static const std::string S_FullDomName( "FullDomName" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntClusterEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntClusterEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntClusterEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntClusterEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntClusterEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntClusterEditObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_FullDomName, CFIntClusterEditObj::getRequiredFullDomName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntClusterEditObj::getRequiredDescription() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntClusterEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntClusterEditObj::setRequiredRevision( int32_t value ) {
		getClusterEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntClusterEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredFullDomName() );
		return( objName );
	}

	const std::string CFIntClusterEditObj::getGenDefName() {
		return( cfsec::CFSecClusterBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntClusterEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntClusterEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntClusterEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntClusterEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntClusterEditObj::getNamedObject( const std::string& objName ) {
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
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getHostNodeTableObj()->readHostNodeByLookupHostNameIdx( getRequiredId(),
				nextName,
				false );
		}
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByLookupUNameIdx( getRequiredId(),
				nextName,
				false );
		}
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecAppTableObj()->readSecAppByLookupUJEEMountIdx( getRequiredId(),
				nextName,
				false );
		}
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByLookupUNameIdx( getRequiredId(),
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

	std::string CFIntClusterEditObj::getObjQualifiedName() {
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

	std::string CFIntClusterEditObj::getObjFullName() {
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

	cfsec::ICFSecClusterObj* CFIntClusterEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecClusterObj* retobj = getSchema()->getClusterTableObj()->realizeCluster( dynamic_cast<cfsec::ICFSecClusterObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecClusterObj* CFIntClusterEditObj::read( bool forceRead ) {
		cfsec::ICFSecClusterObj* retval = getOrigAsCluster()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecClusterObj* CFIntClusterEditObj::create() {
		cfsec::ICFSecClusterObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsCluster()->getSchema() )->getClusterTableObj()->createCluster( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecClusterEditObj* CFIntClusterEditObj::update() {
		getSchema()->getClusterTableObj()->updateCluster( this );
		return( NULL );
	}

	cfsec::ICFSecClusterEditObj* CFIntClusterEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getClusterTableObj()->deleteCluster( this );
		return( NULL );
	}

	cfsec::ICFSecClusterTableObj* CFIntClusterEditObj::getClusterTable() {
		return( orig->getSchema()->getClusterTableObj() );
	}

	cfsec::ICFSecClusterEditObj* CFIntClusterEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecClusterEditObj* CFIntClusterEditObj::getClusterEdit() {
		return( (cfsec::ICFSecClusterEditObj*)this );
	}

	cfsec::ICFSecClusterEditObj* CFIntClusterEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntClusterEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecClusterObj* CFIntClusterEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecClusterObj* CFIntClusterEditObj::getOrigAsCluster() {
		return( dynamic_cast<cfsec::ICFSecClusterObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntClusterEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecClusterBuff* CFIntClusterEditObj::getBuff() {
		return( buff );
	}

	void CFIntClusterEditObj::setBuff( cfsec::CFSecClusterBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecClusterPKey* CFIntClusterEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntClusterEditObj::setPKey( cfsec::CFSecClusterPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntClusterEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntClusterEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntClusterEditObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntClusterEditObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const std::string& CFIntClusterEditObj::getRequiredFullDomName() {
		return( getClusterBuff()->getRequiredFullDomName() );
	}

	const std::string* CFIntClusterEditObj::getRequiredFullDomNameReference() {
		return( getClusterBuff()->getRequiredFullDomNameReference() );
	}

	void CFIntClusterEditObj::setRequiredFullDomName( const std::string& value ) {
		if( getClusterBuff()->getRequiredFullDomName() != value ) {
			getClusterEditBuff()->setRequiredFullDomName( value );
		}
	}

	const std::string& CFIntClusterEditObj::getRequiredDescription() {
		return( getClusterBuff()->getRequiredDescription() );
	}

	const std::string* CFIntClusterEditObj::getRequiredDescriptionReference() {
		return( getClusterBuff()->getRequiredDescriptionReference() );
	}

	void CFIntClusterEditObj::setRequiredDescription( const std::string& value ) {
		if( getClusterBuff()->getRequiredDescription() != value ) {
			getClusterEditBuff()->setRequiredDescription( value );
		}
	}

	std::vector<cfsec::ICFSecHostNodeObj*> CFIntClusterEditObj::getOptionalComponentsHostNode( bool forceRead ) {
		std::vector<cfsec::ICFSecHostNodeObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsCluster()->getSchema() )->getHostNodeTableObj()->readHostNodeByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTenantObj*> CFIntClusterEditObj::getOptionalComponentsTenant( bool forceRead ) {
		std::vector<cfsec::ICFSecTenantObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsCluster()->getSchema() )->getTenantTableObj()->readTenantByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecAppObj*> CFIntClusterEditObj::getOptionalComponentsSecApp( bool forceRead ) {
		std::vector<cfsec::ICFSecSecAppObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsCluster()->getSchema() )->getSecAppTableObj()->readSecAppByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGroupObj*> CFIntClusterEditObj::getOptionalComponentsSecGroup( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGroupObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsCluster()->getSchema() )->getSecGroupTableObj()->readSecGroupByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSysClusterObj*> CFIntClusterEditObj::getOptionalComponentsSysCluster( bool forceRead ) {
		std::vector<cfsec::ICFSecSysClusterObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsCluster()->getSchema() )->getSysClusterTableObj()->readSysClusterByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	void CFIntClusterEditObj::copyPKeyToBuff() {
		cfsec::CFSecClusterPKey* tablePKey = getPKey();
		cfsec::CFSecClusterBuff* tableBuff = getClusterEditBuff();
		tableBuff->setRequiredId( tablePKey->getRequiredId() );
	}

	void CFIntClusterEditObj::copyBuffToPKey() {
		cfsec::CFSecClusterPKey* tablePKey = getPKey();
		cfsec::CFSecClusterBuff* tableBuff = getClusterBuff();
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

	void CFIntClusterEditObj::copyBuffToOrig() {
		cfsec::CFSecClusterBuff* origBuff = getOrigAsCluster()->getClusterEditBuff();
		cfsec::CFSecClusterBuff* myBuff = getClusterBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntClusterEditObj::copyOrigToBuff() {
		cfsec::CFSecClusterBuff* origBuff = getOrigAsCluster()->getClusterBuff();
		cfsec::CFSecClusterBuff* myBuff = getClusterEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
