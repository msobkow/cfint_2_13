// Description: C++18 edit object instance implementation for CFInt SubProject.

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
#include <cfintobj/CFIntSubProjectObj.hpp>
#include <cfintobj/CFIntSubProjectEditObj.hpp>


namespace cfint {

	const std::string CFIntSubProjectEditObj::CLASS_NAME( "CFIntSubProjectEditObj" );

	CFIntSubProjectEditObj::CFIntSubProjectEditObj( cfint::ICFIntSubProjectObj* argOrig )
	: ICFIntSubProjectEditObj()
	{
		static const std::string S_ProcName( "CFIntSubProjectEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfint::CFIntSubProjectBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfint::CFIntSubProjectBuff*>( origBuff->clone() );
	}

	CFIntSubProjectEditObj::~CFIntSubProjectEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntSubProjectEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntSubProjectEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSubProjectBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSubProjectEditObj::getCreatedAt() {
		return( getSubProjectBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSubProjectEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSubProjectBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSubProjectEditObj::getUpdatedAt() {
		return( getSubProjectBuff()->getUpdatedAt() );
	}

	void CFIntSubProjectEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSubProjectEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSubProjectEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSubProjectEditBuff()->setCreatedAt( value );
	}

	void CFIntSubProjectEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSubProjectEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSubProjectEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSubProjectEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntSubProjectEditObj::getClassCode() const {
		return( cfint::CFIntSubProjectBuff::CLASS_CODE );
	}

	bool CFIntSubProjectEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntSubProjectBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSubProjectEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSubProjectEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_TopProjectId( "TopProjectId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSubProjectEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSubProjectEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSubProjectEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSubProjectEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSubProjectEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntSubProjectEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntSubProjectEditObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopProjectId, CFIntSubProjectEditObj::getRequiredTopProjectId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntSubProjectEditObj::getRequiredName() ) );
		if( ! CFIntSubProjectEditObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntSubProjectEditObj::getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntSubProjectEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntSubProjectEditObj::setRequiredRevision( int32_t value ) {
		getSubProjectEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntSubProjectEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntSubProjectEditObj::getGenDefName() {
		return( cfint::CFIntSubProjectBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSubProjectEditObj::getScope() {
		cfint::ICFIntTopProjectObj* scope = getRequiredContainerParentTPrj();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSubProjectEditObj::getObjScope() {
		cfint::ICFIntTopProjectObj* scope = getRequiredContainerParentTPrj();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSubProjectEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSubProjectEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSubProjectEditObj::getNamedObject( const std::string& objName ) {
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
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMajorVersionTableObj()->readMajorVersionByLookupNameIdx( getRequiredTenantId(),
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

	std::string CFIntSubProjectEditObj::getObjQualifiedName() {
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

	std::string CFIntSubProjectEditObj::getObjFullName() {
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

	cfint::ICFIntSubProjectObj* CFIntSubProjectEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfint::ICFIntSubProjectObj* retobj = getSchema()->getSubProjectTableObj()->realizeSubProject( dynamic_cast<cfint::ICFIntSubProjectObj*>( this ) );
		return( retobj );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectEditObj::read( bool forceRead ) {
		cfint::ICFIntSubProjectObj* retval = getOrigAsSubProject()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectEditObj::create() {
		cfint::ICFIntSubProjectObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSubProject()->getSchema() )->getSubProjectTableObj()->createSubProject( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfint::ICFIntSubProjectEditObj* CFIntSubProjectEditObj::update() {
		getSchema()->getSubProjectTableObj()->updateSubProject( this );
		return( NULL );
	}

	cfint::ICFIntSubProjectEditObj* CFIntSubProjectEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSubProjectTableObj()->deleteSubProject( this );
		return( NULL );
	}

	cfint::ICFIntSubProjectTableObj* CFIntSubProjectEditObj::getSubProjectTable() {
		return( orig->getSchema()->getSubProjectTableObj() );
	}

	cfint::ICFIntSubProjectEditObj* CFIntSubProjectEditObj::getEdit() {
		return( this );
	}

	cfint::ICFIntSubProjectEditObj* CFIntSubProjectEditObj::getSubProjectEdit() {
		return( (cfint::ICFIntSubProjectEditObj*)this );
	}

	cfint::ICFIntSubProjectEditObj* CFIntSubProjectEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntSubProjectEditObj::endEdit() {
		orig->endEdit();
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectEditObj::getOrig() {
		return( orig );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectEditObj::getOrigAsSubProject() {
		return( dynamic_cast<cfint::ICFIntSubProjectObj*>( orig ) );
	}

	cfint::ICFIntSchemaObj* CFIntSubProjectEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfint::CFIntSubProjectBuff* CFIntSubProjectEditObj::getBuff() {
		return( buff );
	}

	void CFIntSubProjectEditObj::setBuff( cfint::CFIntSubProjectBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfint::CFIntSubProjectPKey* CFIntSubProjectEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntSubProjectEditObj::setPKey( cfint::CFIntSubProjectPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntSubProjectEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntSubProjectEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntSubProjectEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntSubProjectEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntSubProjectEditObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntSubProjectEditObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const int64_t CFIntSubProjectEditObj::getRequiredTopProjectId() {
		return( getSubProjectBuff()->getRequiredTopProjectId() );
	}

	const int64_t* CFIntSubProjectEditObj::getRequiredTopProjectIdReference() {
		return( getSubProjectBuff()->getRequiredTopProjectIdReference() );
	}

	const std::string& CFIntSubProjectEditObj::getRequiredName() {
		return( getSubProjectBuff()->getRequiredName() );
	}

	const std::string* CFIntSubProjectEditObj::getRequiredNameReference() {
		return( getSubProjectBuff()->getRequiredNameReference() );
	}

	void CFIntSubProjectEditObj::setRequiredName( const std::string& value ) {
		if( getSubProjectBuff()->getRequiredName() != value ) {
			getSubProjectEditBuff()->setRequiredName( value );
		}
	}

	bool CFIntSubProjectEditObj::isOptionalDescriptionNull() {
		return( getSubProjectBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntSubProjectEditObj::getOptionalDescriptionValue() {
		return( getSubProjectBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntSubProjectEditObj::getOptionalDescriptionReference() {
		return( getSubProjectBuff()->getOptionalDescriptionReference() );
	}

	void CFIntSubProjectEditObj::setOptionalDescriptionNull() {
		if( ! getSubProjectBuff()->isOptionalDescriptionNull() ) {
			getSubProjectEditBuff()->setOptionalDescriptionNull();
		}
	}

	void CFIntSubProjectEditObj::setOptionalDescriptionValue( const std::string& value ) {
		if( getSubProjectBuff()->isOptionalDescriptionNull() ) {
			getSubProjectEditBuff()->setOptionalDescriptionValue( value );
		}
		else if( getSubProjectBuff()->getOptionalDescriptionValue() != value ) {
			getSubProjectEditBuff()->setOptionalDescriptionValue( value );
		}
	}

	cfsec::ICFSecTenantObj* CFIntSubProjectEditObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSubProject()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFIntSubProjectEditObj::setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getSubProjectEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	cfint::ICFIntTopProjectObj* CFIntSubProjectEditObj::getRequiredContainerParentTPrj( bool forceRead ) {
		cfint::ICFIntTopProjectObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSubProject()->getSchema() )->getTopProjectTableObj()->readTopProjectByIdIdx( getPKey()->getRequiredTenantId(),
					getSubProjectBuff()->getRequiredTopProjectId() );
		}
		return( retobj );
	}

	void CFIntSubProjectEditObj::setRequiredContainerParentTPrj( cfint::ICFIntTopProjectObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredTenantId() );
				getSubProjectEditBuff()->setRequiredTenantId( value->getRequiredTenantId() );
				getSubProjectEditBuff()->setRequiredTopProjectId( value->getRequiredId() );
			}
		}

	std::vector<cfint::ICFIntMajorVersionObj*> CFIntSubProjectEditObj::getOptionalComponentsMajorVer( bool forceRead ) {
		std::vector<cfint::ICFIntMajorVersionObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSubProject()->getSchema() )->getMajorVersionTableObj()->readMajorVersionBySubProjectIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	void CFIntSubProjectEditObj::copyPKeyToBuff() {
		cfint::CFIntSubProjectPKey* tablePKey = getPKey();
		cfint::CFIntSubProjectBuff* tableBuff = getSubProjectEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredId( tablePKey->getRequiredId() );
	}

	void CFIntSubProjectEditObj::copyBuffToPKey() {
		cfint::CFIntSubProjectPKey* tablePKey = getPKey();
		cfint::CFIntSubProjectBuff* tableBuff = getSubProjectBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

	void CFIntSubProjectEditObj::copyBuffToOrig() {
		cfint::CFIntSubProjectBuff* origBuff = getOrigAsSubProject()->getSubProjectEditBuff();
		cfint::CFIntSubProjectBuff* myBuff = getSubProjectBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntSubProjectEditObj::copyOrigToBuff() {
		cfint::CFIntSubProjectBuff* origBuff = getOrigAsSubProject()->getSubProjectBuff();
		cfint::CFIntSubProjectBuff* myBuff = getSubProjectEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
