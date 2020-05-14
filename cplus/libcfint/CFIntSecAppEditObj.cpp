// Description: C++18 edit object instance implementation for CFInt SecApp.

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
#include <cfintobj/CFIntSecAppObj.hpp>
#include <cfintobj/CFIntSecAppEditObj.hpp>


namespace cfint {

	const std::string CFIntSecAppEditObj::CLASS_NAME( "CFIntSecAppEditObj" );

	CFIntSecAppEditObj::CFIntSecAppEditObj( cfsec::ICFSecSecAppObj* argOrig )
	: ICFIntSecAppEditObj(),
	  ICFSecSecAppEditObj()
	{
		static const std::string S_ProcName( "CFIntSecAppEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecAppBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( origBuff->clone() );
	}

	CFIntSecAppEditObj::~CFIntSecAppEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntSecAppEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntSecAppEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecAppBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecAppEditObj::getCreatedAt() {
		return( getSecAppBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecAppEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecAppBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecAppEditObj::getUpdatedAt() {
		return( getSecAppBuff()->getUpdatedAt() );
	}

	void CFIntSecAppEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSecAppEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecAppEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecAppEditBuff()->setCreatedAt( value );
	}

	void CFIntSecAppEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSecAppEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecAppEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecAppEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntSecAppEditObj::getClassCode() const {
		return( cfsec::CFSecSecAppBuff::CLASS_CODE );
	}

	bool CFIntSecAppEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecAppEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecAppEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecAppId( "SecAppId" );
		static const std::string S_JEEMountName( "JEEMountName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecAppEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecAppEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecAppEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecAppEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecAppEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSecAppEditObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, CFIntSecAppEditObj::getRequiredSecAppId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_JEEMountName, CFIntSecAppEditObj::getRequiredJEEMountName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntSecAppEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntSecAppEditObj::setRequiredRevision( int32_t value ) {
		getSecAppEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntSecAppEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredJEEMountName() );
		return( objName );
	}

	const std::string CFIntSecAppEditObj::getGenDefName() {
		return( cfsec::CFSecSecAppBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecAppEditObj::getScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecAppEditObj::getObjScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecAppEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecAppEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecAppEditObj::getNamedObject( const std::string& objName ) {
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
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecFormTableObj()->readSecFormByLookupUJEEServletIdx( getRequiredClusterId(),
			getRequiredSecAppId(),
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

	std::string CFIntSecAppEditObj::getObjQualifiedName() {
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

	std::string CFIntSecAppEditObj::getObjFullName() {
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

	cfsec::ICFSecSecAppObj* CFIntSecAppEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecAppObj* retobj = getSchema()->getSecAppTableObj()->realizeSecApp( dynamic_cast<cfsec::ICFSecSecAppObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecAppObj* retval = getOrigAsSecApp()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppEditObj::create() {
		cfsec::ICFSecSecAppObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecApp()->getSchema() )->getSecAppTableObj()->createSecApp( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecAppEditObj* CFIntSecAppEditObj::update() {
		getSchema()->getSecAppTableObj()->updateSecApp( this );
		return( NULL );
	}

	cfsec::ICFSecSecAppEditObj* CFIntSecAppEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecAppTableObj()->deleteSecApp( this );
		return( NULL );
	}

	cfsec::ICFSecSecAppTableObj* CFIntSecAppEditObj::getSecAppTable() {
		return( orig->getSchema()->getSecAppTableObj() );
	}

	cfsec::ICFSecSecAppEditObj* CFIntSecAppEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecAppEditObj* CFIntSecAppEditObj::getSecAppEdit() {
		return( (cfsec::ICFSecSecAppEditObj*)this );
	}

	cfsec::ICFSecSecAppEditObj* CFIntSecAppEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntSecAppEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppEditObj::getOrigAsSecApp() {
		return( dynamic_cast<cfsec::ICFSecSecAppObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntSecAppEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecAppBuff* CFIntSecAppEditObj::getBuff() {
		return( buff );
	}

	void CFIntSecAppEditObj::setBuff( cfsec::CFSecSecAppBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecAppPKey* CFIntSecAppEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntSecAppEditObj::setPKey( cfsec::CFSecSecAppPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntSecAppEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntSecAppEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntSecAppEditObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFIntSecAppEditObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int32_t CFIntSecAppEditObj::getRequiredSecAppId() {
		return( getPKey()->getRequiredSecAppId() );
	}

	const int32_t* CFIntSecAppEditObj::getRequiredSecAppIdReference() {
		return( getPKey()->getRequiredSecAppIdReference() );
	}

	const std::string& CFIntSecAppEditObj::getRequiredJEEMountName() {
		return( getSecAppBuff()->getRequiredJEEMountName() );
	}

	const std::string* CFIntSecAppEditObj::getRequiredJEEMountNameReference() {
		return( getSecAppBuff()->getRequiredJEEMountNameReference() );
	}

	void CFIntSecAppEditObj::setRequiredJEEMountName( const std::string& value ) {
		if( getSecAppBuff()->getRequiredJEEMountName() != value ) {
			getSecAppEditBuff()->setRequiredJEEMountName( value );
		}
	}

	cfsec::ICFSecClusterObj* CFIntSecAppEditObj::getRequiredContainerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecApp()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFIntSecAppEditObj::setRequiredContainerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredId() );
				getSecAppEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	std::vector<cfsec::ICFSecSecFormObj*> CFIntSecAppEditObj::getOptionalComponentsForm( bool forceRead ) {
		std::vector<cfsec::ICFSecSecFormObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecApp()->getSchema() )->getSecFormTableObj()->readSecFormBySecAppIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecAppId(),
			forceRead );
		return( retval );
	}

	void CFIntSecAppEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecAppPKey* tablePKey = getPKey();
		cfsec::CFSecSecAppBuff* tableBuff = getSecAppEditBuff();
		tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
		tableBuff->setRequiredSecAppId( tablePKey->getRequiredSecAppId() );
	}

	void CFIntSecAppEditObj::copyBuffToPKey() {
		cfsec::CFSecSecAppPKey* tablePKey = getPKey();
		cfsec::CFSecSecAppBuff* tableBuff = getSecAppBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecAppId( tableBuff->getRequiredSecAppId() );
	}

	void CFIntSecAppEditObj::copyBuffToOrig() {
		cfsec::CFSecSecAppBuff* origBuff = getOrigAsSecApp()->getSecAppEditBuff();
		cfsec::CFSecSecAppBuff* myBuff = getSecAppBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntSecAppEditObj::copyOrigToBuff() {
		cfsec::CFSecSecAppBuff* origBuff = getOrigAsSecApp()->getSecAppBuff();
		cfsec::CFSecSecAppBuff* myBuff = getSecAppEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}