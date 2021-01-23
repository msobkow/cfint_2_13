// Description: C++18 edit object instance implementation for CFInt MinorVersion.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
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
#include <cfintobj/CFIntMinorVersionObj.hpp>
#include <cfintobj/CFIntMinorVersionEditObj.hpp>


namespace cfint {

	const std::string CFIntMinorVersionEditObj::CLASS_NAME( "CFIntMinorVersionEditObj" );

	CFIntMinorVersionEditObj::CFIntMinorVersionEditObj( cfint::ICFIntMinorVersionObj* argOrig )
	: ICFIntMinorVersionEditObj()
	{
		static const std::string S_ProcName( "CFIntMinorVersionEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfint::CFIntMinorVersionBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfint::CFIntMinorVersionBuff*>( origBuff->clone() );
	}

	CFIntMinorVersionEditObj::~CFIntMinorVersionEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntMinorVersionEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntMinorVersionEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getMinorVersionBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntMinorVersionEditObj::getCreatedAt() {
		return( getMinorVersionBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntMinorVersionEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getMinorVersionBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntMinorVersionEditObj::getUpdatedAt() {
		return( getMinorVersionBuff()->getUpdatedAt() );
	}

	void CFIntMinorVersionEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getMinorVersionEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntMinorVersionEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getMinorVersionEditBuff()->setCreatedAt( value );
	}

	void CFIntMinorVersionEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getMinorVersionEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntMinorVersionEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getMinorVersionEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntMinorVersionEditObj::getClassCode() const {
		return( cfint::CFIntMinorVersionBuff::CLASS_CODE );
	}

	bool CFIntMinorVersionEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntMinorVersionBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntMinorVersionEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMinorVersionEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_MajorVersionId( "MajorVersionId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntMinorVersionEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntMinorVersionEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntMinorVersionEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntMinorVersionEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntMinorVersionEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntMinorVersionEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntMinorVersionEditObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_MajorVersionId, CFIntMinorVersionEditObj::getRequiredMajorVersionId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntMinorVersionEditObj::getRequiredName() ) );
		if( ! CFIntMinorVersionEditObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntMinorVersionEditObj::getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntMinorVersionEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntMinorVersionEditObj::setRequiredRevision( int32_t value ) {
		getMinorVersionEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntMinorVersionEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntMinorVersionEditObj::getGenDefName() {
		return( cfint::CFIntMinorVersionBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntMinorVersionEditObj::getScope() {
		cfint::ICFIntMajorVersionObj* scope = getRequiredContainerParentMajVer();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntMinorVersionEditObj::getObjScope() {
		cfint::ICFIntMajorVersionObj* scope = getRequiredContainerParentMajVer();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntMinorVersionEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntMinorVersionEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntMinorVersionEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntMinorVersionEditObj::getObjQualifiedName() {
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

	std::string CFIntMinorVersionEditObj::getObjFullName() {
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

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfint::ICFIntMinorVersionObj* retobj = getSchema()->getMinorVersionTableObj()->realizeMinorVersion( dynamic_cast<cfint::ICFIntMinorVersionObj*>( this ) );
		return( retobj );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionEditObj::read( bool forceRead ) {
		cfint::ICFIntMinorVersionObj* retval = getOrigAsMinorVersion()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionEditObj::create() {
		cfint::ICFIntMinorVersionObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsMinorVersion()->getSchema() )->getMinorVersionTableObj()->createMinorVersion( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfint::ICFIntMinorVersionEditObj* CFIntMinorVersionEditObj::update() {
		getSchema()->getMinorVersionTableObj()->updateMinorVersion( this );
		return( NULL );
	}

	cfint::ICFIntMinorVersionEditObj* CFIntMinorVersionEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getMinorVersionTableObj()->deleteMinorVersion( this );
		return( NULL );
	}

	cfint::ICFIntMinorVersionTableObj* CFIntMinorVersionEditObj::getMinorVersionTable() {
		return( orig->getSchema()->getMinorVersionTableObj() );
	}

	cfint::ICFIntMinorVersionEditObj* CFIntMinorVersionEditObj::getEdit() {
		return( this );
	}

	cfint::ICFIntMinorVersionEditObj* CFIntMinorVersionEditObj::getMinorVersionEdit() {
		return( (cfint::ICFIntMinorVersionEditObj*)this );
	}

	cfint::ICFIntMinorVersionEditObj* CFIntMinorVersionEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntMinorVersionEditObj::endEdit() {
		orig->endEdit();
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionEditObj::getOrig() {
		return( orig );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionEditObj::getOrigAsMinorVersion() {
		return( dynamic_cast<cfint::ICFIntMinorVersionObj*>( orig ) );
	}

	cfint::ICFIntSchemaObj* CFIntMinorVersionEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfint::CFIntMinorVersionBuff* CFIntMinorVersionEditObj::getBuff() {
		return( buff );
	}

	void CFIntMinorVersionEditObj::setBuff( cfint::CFIntMinorVersionBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfint::CFIntMinorVersionPKey* CFIntMinorVersionEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntMinorVersionEditObj::setPKey( cfint::CFIntMinorVersionPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntMinorVersionEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntMinorVersionEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntMinorVersionEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntMinorVersionEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntMinorVersionEditObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntMinorVersionEditObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const int64_t CFIntMinorVersionEditObj::getRequiredMajorVersionId() {
		return( getMinorVersionBuff()->getRequiredMajorVersionId() );
	}

	const int64_t* CFIntMinorVersionEditObj::getRequiredMajorVersionIdReference() {
		return( getMinorVersionBuff()->getRequiredMajorVersionIdReference() );
	}

	const std::string& CFIntMinorVersionEditObj::getRequiredName() {
		return( getMinorVersionBuff()->getRequiredName() );
	}

	const std::string* CFIntMinorVersionEditObj::getRequiredNameReference() {
		return( getMinorVersionBuff()->getRequiredNameReference() );
	}

	void CFIntMinorVersionEditObj::setRequiredName( const std::string& value ) {
		if( getMinorVersionBuff()->getRequiredName() != value ) {
			getMinorVersionEditBuff()->setRequiredName( value );
		}
	}

	bool CFIntMinorVersionEditObj::isOptionalDescriptionNull() {
		return( getMinorVersionBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntMinorVersionEditObj::getOptionalDescriptionValue() {
		return( getMinorVersionBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntMinorVersionEditObj::getOptionalDescriptionReference() {
		return( getMinorVersionBuff()->getOptionalDescriptionReference() );
	}

	void CFIntMinorVersionEditObj::setOptionalDescriptionNull() {
		if( ! getMinorVersionBuff()->isOptionalDescriptionNull() ) {
			getMinorVersionEditBuff()->setOptionalDescriptionNull();
		}
	}

	void CFIntMinorVersionEditObj::setOptionalDescriptionValue( const std::string& value ) {
		if( getMinorVersionBuff()->isOptionalDescriptionNull() ) {
			getMinorVersionEditBuff()->setOptionalDescriptionValue( value );
		}
		else if( getMinorVersionBuff()->getOptionalDescriptionValue() != value ) {
			getMinorVersionEditBuff()->setOptionalDescriptionValue( value );
		}
	}

	cfsec::ICFSecTenantObj* CFIntMinorVersionEditObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsMinorVersion()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFIntMinorVersionEditObj::setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getMinorVersionEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	cfint::ICFIntMajorVersionObj* CFIntMinorVersionEditObj::getRequiredContainerParentMajVer( bool forceRead ) {
		cfint::ICFIntMajorVersionObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsMinorVersion()->getSchema() )->getMajorVersionTableObj()->readMajorVersionByIdIdx( getPKey()->getRequiredTenantId(),
					getMinorVersionBuff()->getRequiredMajorVersionId() );
		}
		return( retobj );
	}

	void CFIntMinorVersionEditObj::setRequiredContainerParentMajVer( cfint::ICFIntMajorVersionObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredTenantId() );
				getMinorVersionEditBuff()->setRequiredTenantId( value->getRequiredTenantId() );
				getMinorVersionEditBuff()->setRequiredMajorVersionId( value->getRequiredId() );
			}
		}

	void CFIntMinorVersionEditObj::copyPKeyToBuff() {
		cfint::CFIntMinorVersionPKey* tablePKey = getPKey();
		cfint::CFIntMinorVersionBuff* tableBuff = getMinorVersionEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredId( tablePKey->getRequiredId() );
	}

	void CFIntMinorVersionEditObj::copyBuffToPKey() {
		cfint::CFIntMinorVersionPKey* tablePKey = getPKey();
		cfint::CFIntMinorVersionBuff* tableBuff = getMinorVersionBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

	void CFIntMinorVersionEditObj::copyBuffToOrig() {
		cfint::CFIntMinorVersionBuff* origBuff = getOrigAsMinorVersion()->getMinorVersionEditBuff();
		cfint::CFIntMinorVersionBuff* myBuff = getMinorVersionBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntMinorVersionEditObj::copyOrigToBuff() {
		cfint::CFIntMinorVersionBuff* origBuff = getOrigAsMinorVersion()->getMinorVersionBuff();
		cfint::CFIntMinorVersionBuff* myBuff = getMinorVersionEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
