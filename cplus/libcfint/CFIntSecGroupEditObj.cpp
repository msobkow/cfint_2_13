// Description: C++18 edit object instance implementation for CFInt SecGroup.

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
#include <cfintobj/CFIntSecGroupObj.hpp>
#include <cfintobj/CFIntSecGroupEditObj.hpp>


namespace cfint {

	const std::string CFIntSecGroupEditObj::CLASS_NAME( "CFIntSecGroupEditObj" );

	CFIntSecGroupEditObj::CFIntSecGroupEditObj( cfsec::ICFSecSecGroupObj* argOrig )
	: ICFIntSecGroupEditObj(),
	  ICFSecSecGroupEditObj()
	{
		static const std::string S_ProcName( "CFIntSecGroupEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecGroupBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( origBuff->clone() );
	}

	CFIntSecGroupEditObj::~CFIntSecGroupEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntSecGroupEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGroupEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGroupBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGroupEditObj::getCreatedAt() {
		return( getSecGroupBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGroupEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGroupBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGroupEditObj::getUpdatedAt() {
		return( getSecGroupBuff()->getUpdatedAt() );
	}

	void CFIntSecGroupEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSecGroupEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecGroupEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecGroupEditBuff()->setCreatedAt( value );
	}

	void CFIntSecGroupEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSecGroupEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecGroupEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecGroupEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntSecGroupEditObj::getClassCode() const {
		return( cfsec::CFSecSecGroupBuff::CLASS_CODE );
	}

	bool CFIntSecGroupEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecGroupEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecGroupEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_Name( "Name" );
		static const std::string S_IsVisible( "IsVisible" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecGroupEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecGroupEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecGroupEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecGroupEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecGroupEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSecGroupEditObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, CFIntSecGroupEditObj::getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntSecGroupEditObj::getRequiredName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsVisible, CFIntSecGroupEditObj::getRequiredIsVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntSecGroupEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntSecGroupEditObj::setRequiredRevision( int32_t value ) {
		getSecGroupEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntSecGroupEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntSecGroupEditObj::getGenDefName() {
		return( cfsec::CFSecSecGroupBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupEditObj::getScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupEditObj::getObjScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecGroupEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecGroupEditObj::getObjQualifiedName() {
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

	std::string CFIntSecGroupEditObj::getObjFullName() {
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

	cfsec::ICFSecSecGroupObj* CFIntSecGroupEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecGroupObj* retobj = getSchema()->getSecGroupTableObj()->realizeSecGroup( dynamic_cast<cfsec::ICFSecSecGroupObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retval = getOrigAsSecGroup()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupEditObj::create() {
		cfsec::ICFSecSecGroupObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGroup()->getSchema() )->getSecGroupTableObj()->createSecGroup( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecGroupEditObj* CFIntSecGroupEditObj::update() {
		getSchema()->getSecGroupTableObj()->updateSecGroup( this );
		return( NULL );
	}

	cfsec::ICFSecSecGroupEditObj* CFIntSecGroupEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecGroupTableObj()->deleteSecGroup( this );
		return( NULL );
	}

	cfsec::ICFSecSecGroupTableObj* CFIntSecGroupEditObj::getSecGroupTable() {
		return( orig->getSchema()->getSecGroupTableObj() );
	}

	cfsec::ICFSecSecGroupEditObj* CFIntSecGroupEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecGroupEditObj* CFIntSecGroupEditObj::getSecGroupEdit() {
		return( (cfsec::ICFSecSecGroupEditObj*)this );
	}

	cfsec::ICFSecSecGroupEditObj* CFIntSecGroupEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntSecGroupEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupEditObj::getOrigAsSecGroup() {
		return( dynamic_cast<cfsec::ICFSecSecGroupObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntSecGroupEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecGroupBuff* CFIntSecGroupEditObj::getBuff() {
		return( buff );
	}

	void CFIntSecGroupEditObj::setBuff( cfsec::CFSecSecGroupBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecGroupPKey* CFIntSecGroupEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntSecGroupEditObj::setPKey( cfsec::CFSecSecGroupPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntSecGroupEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntSecGroupEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntSecGroupEditObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFIntSecGroupEditObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int32_t CFIntSecGroupEditObj::getRequiredSecGroupId() {
		return( getPKey()->getRequiredSecGroupId() );
	}

	const int32_t* CFIntSecGroupEditObj::getRequiredSecGroupIdReference() {
		return( getPKey()->getRequiredSecGroupIdReference() );
	}

	const std::string& CFIntSecGroupEditObj::getRequiredName() {
		return( getSecGroupBuff()->getRequiredName() );
	}

	const std::string* CFIntSecGroupEditObj::getRequiredNameReference() {
		return( getSecGroupBuff()->getRequiredNameReference() );
	}

	void CFIntSecGroupEditObj::setRequiredName( const std::string& value ) {
		if( getSecGroupBuff()->getRequiredName() != value ) {
			getSecGroupEditBuff()->setRequiredName( value );
		}
	}

	const bool CFIntSecGroupEditObj::getRequiredIsVisible() {
		return( getSecGroupBuff()->getRequiredIsVisible() );
	}

	const bool* CFIntSecGroupEditObj::getRequiredIsVisibleReference() {
		return( getSecGroupBuff()->getRequiredIsVisibleReference() );
	}

	void CFIntSecGroupEditObj::setRequiredIsVisible( const bool value ) {
		if( getSecGroupBuff()->getRequiredIsVisible() != value ) {
			getSecGroupEditBuff()->setRequiredIsVisible( value );
		}
	}

	cfsec::ICFSecClusterObj* CFIntSecGroupEditObj::getRequiredContainerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGroup()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFIntSecGroupEditObj::setRequiredContainerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredId() );
				getSecGroupEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGroupEditObj::getOptionalComponentsInclude( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpIncObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGroup()->getSchema() )->getSecGrpIncTableObj()->readSecGrpIncByGroupIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFIntSecGroupEditObj::getOptionalComponentsMember( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpMembObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGroup()->getSchema() )->getSecGrpMembTableObj()->readSecGrpMembByGroupIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGroupEditObj::getRequiredChildrenIncByGroup( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpIncObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGroup()->getSchema() )->getSecGrpIncTableObj()->readSecGrpIncByIncludeIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFIntSecGroupEditObj::getOptionalComponentsForm( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGroupFormObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecGroup()->getSchema() )->getSecGroupFormTableObj()->readSecGroupFormByGroupIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	void CFIntSecGroupEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecSecGroupBuff* tableBuff = getSecGroupEditBuff();
		tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
		tableBuff->setRequiredSecGroupId( tablePKey->getRequiredSecGroupId() );
	}

	void CFIntSecGroupEditObj::copyBuffToPKey() {
		cfsec::CFSecSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecSecGroupBuff* tableBuff = getSecGroupBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecGroupId( tableBuff->getRequiredSecGroupId() );
	}

	void CFIntSecGroupEditObj::copyBuffToOrig() {
		cfsec::CFSecSecGroupBuff* origBuff = getOrigAsSecGroup()->getSecGroupEditBuff();
		cfsec::CFSecSecGroupBuff* myBuff = getSecGroupBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntSecGroupEditObj::copyOrigToBuff() {
		cfsec::CFSecSecGroupBuff* origBuff = getOrigAsSecGroup()->getSecGroupBuff();
		cfsec::CFSecSecGroupBuff* myBuff = getSecGroupEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
