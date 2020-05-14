// Description: C++18 edit object instance implementation for CFInt TopProject.

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
#include <cfintobj/CFIntTopProjectObj.hpp>
#include <cfintobj/CFIntTopProjectEditObj.hpp>


namespace cfint {

	const std::string CFIntTopProjectEditObj::CLASS_NAME( "CFIntTopProjectEditObj" );

	CFIntTopProjectEditObj::CFIntTopProjectEditObj( cfint::ICFIntTopProjectObj* argOrig )
	: ICFIntTopProjectEditObj()
	{
		static const std::string S_ProcName( "CFIntTopProjectEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfint::CFIntTopProjectBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( origBuff->clone() );
	}

	CFIntTopProjectEditObj::~CFIntTopProjectEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntTopProjectEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntTopProjectEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTopProjectBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntTopProjectEditObj::getCreatedAt() {
		return( getTopProjectBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntTopProjectEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTopProjectBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntTopProjectEditObj::getUpdatedAt() {
		return( getTopProjectBuff()->getUpdatedAt() );
	}

	void CFIntTopProjectEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getTopProjectEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTopProjectEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getTopProjectEditBuff()->setCreatedAt( value );
	}

	void CFIntTopProjectEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getTopProjectEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntTopProjectEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getTopProjectEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntTopProjectEditObj::getClassCode() const {
		return( cfint::CFIntTopProjectBuff::CLASS_CODE );
	}

	bool CFIntTopProjectEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntTopProjectEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTopProjectEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_TopDomainId( "TopDomainId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntTopProjectEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntTopProjectEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntTopProjectEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntTopProjectEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntTopProjectEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntTopProjectEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntTopProjectEditObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopDomainId, CFIntTopProjectEditObj::getRequiredTopDomainId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntTopProjectEditObj::getRequiredName() ) );
		if( ! CFIntTopProjectEditObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntTopProjectEditObj::getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntTopProjectEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntTopProjectEditObj::setRequiredRevision( int32_t value ) {
		getTopProjectEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntTopProjectEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntTopProjectEditObj::getGenDefName() {
		return( cfint::CFIntTopProjectBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntTopProjectEditObj::getScope() {
		cfint::ICFIntTopDomainObj* scope = getRequiredContainerParentSDom();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTopProjectEditObj::getObjScope() {
		cfint::ICFIntTopDomainObj* scope = getRequiredContainerParentSDom();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTopProjectEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntTopProjectEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntTopProjectEditObj::getNamedObject( const std::string& objName ) {
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
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSubProjectTableObj()->readSubProjectByLookupNameIdx( getRequiredTenantId(),
			getRequiredId(),
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

	std::string CFIntTopProjectEditObj::getObjQualifiedName() {
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
			else if( container->implementsClassCode( cfsec::CFSecTenantBuff::CLASS_CODE ) ) {
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

	std::string CFIntTopProjectEditObj::getObjFullName() {
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

	cfint::ICFIntTopProjectObj* CFIntTopProjectEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfint::ICFIntTopProjectObj* retobj = getSchema()->getTopProjectTableObj()->realizeTopProject( dynamic_cast<cfint::ICFIntTopProjectObj*>( this ) );
		return( retobj );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectEditObj::read( bool forceRead ) {
		cfint::ICFIntTopProjectObj* retval = getOrigAsTopProject()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectEditObj::create() {
		cfint::ICFIntTopProjectObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTopProject()->getSchema() )->getTopProjectTableObj()->createTopProject( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfint::ICFIntTopProjectEditObj* CFIntTopProjectEditObj::update() {
		getSchema()->getTopProjectTableObj()->updateTopProject( this );
		return( NULL );
	}

	cfint::ICFIntTopProjectEditObj* CFIntTopProjectEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getTopProjectTableObj()->deleteTopProject( this );
		return( NULL );
	}

	cfint::ICFIntTopProjectTableObj* CFIntTopProjectEditObj::getTopProjectTable() {
		return( orig->getSchema()->getTopProjectTableObj() );
	}

	cfint::ICFIntTopProjectEditObj* CFIntTopProjectEditObj::getEdit() {
		return( this );
	}

	cfint::ICFIntTopProjectEditObj* CFIntTopProjectEditObj::getTopProjectEdit() {
		return( (cfint::ICFIntTopProjectEditObj*)this );
	}

	cfint::ICFIntTopProjectEditObj* CFIntTopProjectEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntTopProjectEditObj::endEdit() {
		orig->endEdit();
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectEditObj::getOrig() {
		return( orig );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectEditObj::getOrigAsTopProject() {
		return( dynamic_cast<cfint::ICFIntTopProjectObj*>( orig ) );
	}

	cfint::ICFIntSchemaObj* CFIntTopProjectEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfint::CFIntTopProjectBuff* CFIntTopProjectEditObj::getBuff() {
		return( buff );
	}

	void CFIntTopProjectEditObj::setBuff( cfint::CFIntTopProjectBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfint::CFIntTopProjectPKey* CFIntTopProjectEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntTopProjectEditObj::setPKey( cfint::CFIntTopProjectPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntTopProjectEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntTopProjectEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntTopProjectEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntTopProjectEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntTopProjectEditObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntTopProjectEditObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const int64_t CFIntTopProjectEditObj::getRequiredTopDomainId() {
		return( getTopProjectBuff()->getRequiredTopDomainId() );
	}

	const int64_t* CFIntTopProjectEditObj::getRequiredTopDomainIdReference() {
		return( getTopProjectBuff()->getRequiredTopDomainIdReference() );
	}

	const std::string& CFIntTopProjectEditObj::getRequiredName() {
		return( getTopProjectBuff()->getRequiredName() );
	}

	const std::string* CFIntTopProjectEditObj::getRequiredNameReference() {
		return( getTopProjectBuff()->getRequiredNameReference() );
	}

	void CFIntTopProjectEditObj::setRequiredName( const std::string& value ) {
		if( getTopProjectBuff()->getRequiredName() != value ) {
			getTopProjectEditBuff()->setRequiredName( value );
		}
	}

	bool CFIntTopProjectEditObj::isOptionalDescriptionNull() {
		return( getTopProjectBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntTopProjectEditObj::getOptionalDescriptionValue() {
		return( getTopProjectBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntTopProjectEditObj::getOptionalDescriptionReference() {
		return( getTopProjectBuff()->getOptionalDescriptionReference() );
	}

	void CFIntTopProjectEditObj::setOptionalDescriptionNull() {
		if( ! getTopProjectBuff()->isOptionalDescriptionNull() ) {
			getTopProjectEditBuff()->setOptionalDescriptionNull();
		}
	}

	void CFIntTopProjectEditObj::setOptionalDescriptionValue( const std::string& value ) {
		if( getTopProjectBuff()->isOptionalDescriptionNull() ) {
			getTopProjectEditBuff()->setOptionalDescriptionValue( value );
		}
		else if( getTopProjectBuff()->getOptionalDescriptionValue() != value ) {
			getTopProjectEditBuff()->setOptionalDescriptionValue( value );
		}
	}

	cfsec::ICFSecTenantObj* CFIntTopProjectEditObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTopProject()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFIntTopProjectEditObj::setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getTopProjectEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	cfint::ICFIntTopDomainObj* CFIntTopProjectEditObj::getRequiredContainerParentSDom( bool forceRead ) {
		cfint::ICFIntTopDomainObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTopProject()->getSchema() )->getTopDomainTableObj()->readTopDomainByIdIdx( getPKey()->getRequiredTenantId(),
					getTopProjectBuff()->getRequiredTopDomainId() );
		}
		return( retobj );
	}

	void CFIntTopProjectEditObj::setRequiredContainerParentSDom( cfint::ICFIntTopDomainObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredTenantId() );
				getTopProjectEditBuff()->setRequiredTenantId( value->getRequiredTenantId() );
				getTopProjectEditBuff()->setRequiredTopDomainId( value->getRequiredId() );
			}
		}

	std::vector<cfint::ICFIntSubProjectObj*> CFIntTopProjectEditObj::getOptionalComponentsSubProject( bool forceRead ) {
		std::vector<cfint::ICFIntSubProjectObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsTopProject()->getSchema() )->getSubProjectTableObj()->readSubProjectByTopProjectIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	void CFIntTopProjectEditObj::copyPKeyToBuff() {
		cfint::CFIntTopProjectPKey* tablePKey = getPKey();
		cfint::CFIntTopProjectBuff* tableBuff = getTopProjectEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredId( tablePKey->getRequiredId() );
	}

	void CFIntTopProjectEditObj::copyBuffToPKey() {
		cfint::CFIntTopProjectPKey* tablePKey = getPKey();
		cfint::CFIntTopProjectBuff* tableBuff = getTopProjectBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

	void CFIntTopProjectEditObj::copyBuffToOrig() {
		cfint::CFIntTopProjectBuff* origBuff = getOrigAsTopProject()->getTopProjectEditBuff();
		cfint::CFIntTopProjectBuff* myBuff = getTopProjectBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntTopProjectEditObj::copyOrigToBuff() {
		cfint::CFIntTopProjectBuff* origBuff = getOrigAsTopProject()->getTopProjectBuff();
		cfint::CFIntTopProjectBuff* myBuff = getTopProjectEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
