// Description: C++18 base object instance implementation for CFInt MinorVersion.

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
#include <cfintobj/CFIntMinorVersionObj.hpp>

namespace cfint {

	const std::string CFIntMinorVersionObj::CLASS_NAME( "CFIntMinorVersionObj" );
	const classcode_t CFIntMinorVersionObj::CLASS_CODE = 0xa104L;

	int32_t CFIntMinorVersionObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntMinorVersionObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntMinorVersionObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntMinorVersionObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntMinorVersionObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const int64_t CFIntMinorVersionObj::getRequiredMajorVersionId() {
		return( getMinorVersionBuff()->getRequiredMajorVersionId() );
	}

	const int64_t* CFIntMinorVersionObj::getRequiredMajorVersionIdReference() {
		return( getMinorVersionBuff()->getRequiredMajorVersionIdReference() );
	}

	const std::string& CFIntMinorVersionObj::getRequiredName() {
		return( getMinorVersionBuff()->getRequiredName() );
	}

	const std::string* CFIntMinorVersionObj::getRequiredNameReference() {
		return( getMinorVersionBuff()->getRequiredNameReference() );
	}

	bool CFIntMinorVersionObj::isOptionalDescriptionNull() {
		return( getMinorVersionBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntMinorVersionObj::getOptionalDescriptionValue() {
		return( getMinorVersionBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntMinorVersionObj::getOptionalDescriptionReference() {
		return( getMinorVersionBuff()->getOptionalDescriptionReference() );
	}


	cfsec::ICFSecTenantObj* CFIntMinorVersionObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId(), forceRead );
		}
		return( retobj );
	}

	cfint::ICFIntMajorVersionObj* CFIntMinorVersionObj::getRequiredContainerParentMajVer( bool forceRead ) {
		cfint::ICFIntMajorVersionObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMajorVersionTableObj()->readMajorVersionByIdIdx( getPKey()->getRequiredTenantId(),
					getMinorVersionBuff()->getRequiredMajorVersionId(), forceRead );
		}
		return( retobj );
	}

	CFIntMinorVersionObj::CFIntMinorVersionObj()
	: ICFIntMinorVersionObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntMinorVersionObj::CFIntMinorVersionObj( cfint::ICFIntSchemaObj* argSchema )
	: ICFIntMinorVersionObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntMinorVersionObj::~CFIntMinorVersionObj() {
		schema = NULL;
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}
		if( pKey != NULL ) {
			delete pKey;
			pKey = NULL;
		}

	}

	cfint::CFIntMinorVersionBuff* CFIntMinorVersionObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfint::CFIntMinorVersionBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredTenantId(),
						getPKey()->getRequiredId() );
			}
		}
		return( buff );
	}

	void CFIntMinorVersionObj::setBuff( cfint::CFIntMinorVersionBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntMinorVersionObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntMinorVersionObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntMinorVersionObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntMinorVersionBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntMinorVersionObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMinorVersionObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntMinorVersionObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntMinorVersionObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntMinorVersionObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntMinorVersionObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntMinorVersionObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntMinorVersionObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntMinorVersionObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_MajorVersionId, CFIntMinorVersionObj::getRequiredMajorVersionId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntMinorVersionObj::getRequiredName() ) );
		if( ! CFIntMinorVersionObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntMinorVersionObj::getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntMinorVersionObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntMinorVersionObj::getGenDefName() {
		return( cfint::CFIntMinorVersionBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntMinorVersionObj::getScope() {
		cfint::ICFIntMajorVersionObj* scope = getRequiredContainerParentMajVer();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntMinorVersionObj::getObjScope() {
		cfint::ICFIntMajorVersionObj* scope = getRequiredContainerParentMajVer();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntMinorVersionObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntMinorVersionObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntMinorVersionObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntMinorVersionObj::getObjQualifiedName() {
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

	std::string CFIntMinorVersionObj::getObjFullName() {
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

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionObj::realize() {
		cfint::ICFIntMinorVersionObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMinorVersionTableObj()->realizeMinorVersion(
			(cfint::ICFIntMinorVersionObj*)this );
		return( dynamic_cast<cfint::ICFIntMinorVersionObj*>( retobj ) );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionObj::read( bool forceRead ) {
		cfint::ICFIntMinorVersionObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMinorVersionTableObj()->readMinorVersionByIdIdx( getMinorVersionBuff()->getRequiredTenantId(),
		getMinorVersionBuff()->getRequiredId(), forceRead );
		return( dynamic_cast<cfint::ICFIntMinorVersionObj*>( retobj ) );
	}

	cfint::ICFIntMinorVersionTableObj* CFIntMinorVersionObj::getMinorVersionTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMinorVersionTableObj() );
	}

	cfint::ICFIntSchemaObj* CFIntMinorVersionObj::getSchema() {
		return( schema );
	}

	void CFIntMinorVersionObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = value;
	}

	cfint::CFIntMinorVersionPKey* CFIntMinorVersionObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfint::CFIntMinorVersionPKey();
		}
		return( pKey );
	}

	void CFIntMinorVersionObj::setPKey( cfint::CFIntMinorVersionPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfint::CFIntMinorVersionPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntMinorVersionObj::getIsNew() {
		return( isNew );
	}

	void CFIntMinorVersionObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfint::ICFIntMinorVersionEditObj* CFIntMinorVersionObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfint::ICFIntMinorVersionObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMinorVersionTableObj()->lockMinorVersion( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMinorVersionTableObj()->newEditInstance( this );
		return( dynamic_cast<cfint::ICFIntMinorVersionEditObj*>( edit ) );
	}

	void CFIntMinorVersionObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfint::ICFIntMinorVersionEditObj* CFIntMinorVersionObj::getEdit() {
		return( edit );
	}

	cfint::ICFIntMinorVersionEditObj* CFIntMinorVersionObj::getMinorVersionEdit() {
		return( dynamic_cast<cfint::ICFIntMinorVersionEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntMinorVersionObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getMinorVersionBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntMinorVersionObj::getCreatedAt() {
		return( getMinorVersionBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntMinorVersionObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getMinorVersionBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntMinorVersionObj::getUpdatedAt() {
		return( getMinorVersionBuff()->getUpdatedAt() );
	}

	void CFIntMinorVersionObj::copyPKeyToBuff() {
		cfint::CFIntMinorVersionPKey* tablePKey = getPKey();
		cfint::CFIntMinorVersionBuff* tableBuff = getMinorVersionEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
			tableBuff->setRequiredId( tablePKey->getRequiredId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntMinorVersionObj::copyBuffToPKey() {
		cfint::CFIntMinorVersionPKey* tablePKey = getPKey();
		cfint::CFIntMinorVersionBuff* tableBuff = getMinorVersionBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

}
