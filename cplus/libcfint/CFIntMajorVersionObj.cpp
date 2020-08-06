// Description: C++18 base object instance implementation for CFInt MajorVersion.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
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
#include <cfintobj/CFIntMajorVersionObj.hpp>

namespace cfint {

	const std::string CFIntMajorVersionObj::CLASS_NAME( "CFIntMajorVersionObj" );
	const classcode_t CFIntMajorVersionObj::CLASS_CODE = 0xa102L;

	int32_t CFIntMajorVersionObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntMajorVersionObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntMajorVersionObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntMajorVersionObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntMajorVersionObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const int64_t CFIntMajorVersionObj::getRequiredSubProjectId() {
		return( getMajorVersionBuff()->getRequiredSubProjectId() );
	}

	const int64_t* CFIntMajorVersionObj::getRequiredSubProjectIdReference() {
		return( getMajorVersionBuff()->getRequiredSubProjectIdReference() );
	}

	const std::string& CFIntMajorVersionObj::getRequiredName() {
		return( getMajorVersionBuff()->getRequiredName() );
	}

	const std::string* CFIntMajorVersionObj::getRequiredNameReference() {
		return( getMajorVersionBuff()->getRequiredNameReference() );
	}

	bool CFIntMajorVersionObj::isOptionalDescriptionNull() {
		return( getMajorVersionBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntMajorVersionObj::getOptionalDescriptionValue() {
		return( getMajorVersionBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntMajorVersionObj::getOptionalDescriptionReference() {
		return( getMajorVersionBuff()->getOptionalDescriptionReference() );
	}


	cfsec::ICFSecTenantObj* CFIntMajorVersionObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId(), forceRead );
		}
		return( retobj );
	}

	cfint::ICFIntSubProjectObj* CFIntMajorVersionObj::getRequiredContainerParentSPrj( bool forceRead ) {
		cfint::ICFIntSubProjectObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSubProjectTableObj()->readSubProjectByIdIdx( getPKey()->getRequiredTenantId(),
					getMajorVersionBuff()->getRequiredSubProjectId(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfint::ICFIntMinorVersionObj*> CFIntMajorVersionObj::getOptionalComponentsMinorVer( bool forceRead ) {
		std::vector<cfint::ICFIntMinorVersionObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMinorVersionTableObj()->readMinorVersionByMajorVerIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	CFIntMajorVersionObj::CFIntMajorVersionObj()
	: ICFIntMajorVersionObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntMajorVersionObj::CFIntMajorVersionObj( cfint::ICFIntSchemaObj* argSchema )
	: ICFIntMajorVersionObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntMajorVersionObj::~CFIntMajorVersionObj() {
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

	cfint::CFIntMajorVersionBuff* CFIntMajorVersionObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfint::CFIntMajorVersionBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredTenantId(),
						getPKey()->getRequiredId() );
			}
		}
		return( buff );
	}

	void CFIntMajorVersionObj::setBuff( cfint::CFIntMajorVersionBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntMajorVersionObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntMajorVersionObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntMajorVersionObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntMajorVersionObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMajorVersionObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_SubProjectId( "SubProjectId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntMajorVersionObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntMajorVersionObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntMajorVersionObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntMajorVersionObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntMajorVersionObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntMajorVersionObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntMajorVersionObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SubProjectId, CFIntMajorVersionObj::getRequiredSubProjectId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntMajorVersionObj::getRequiredName() ) );
		if( ! CFIntMajorVersionObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntMajorVersionObj::getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntMajorVersionObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntMajorVersionObj::getGenDefName() {
		return( cfint::CFIntMajorVersionBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntMajorVersionObj::getScope() {
		cfint::ICFIntSubProjectObj* scope = getRequiredContainerParentSPrj();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntMajorVersionObj::getObjScope() {
		cfint::ICFIntSubProjectObj* scope = getRequiredContainerParentSPrj();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntMajorVersionObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntMajorVersionObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntMajorVersionObj::getNamedObject( const std::string& objName ) {
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
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMinorVersionTableObj()->readMinorVersionByLookupNameIdx( getRequiredTenantId(),
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

	std::string CFIntMajorVersionObj::getObjQualifiedName() {
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

	std::string CFIntMajorVersionObj::getObjFullName() {
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

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionObj::realize() {
		cfint::ICFIntMajorVersionObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMajorVersionTableObj()->realizeMajorVersion(
			(cfint::ICFIntMajorVersionObj*)this );
		return( dynamic_cast<cfint::ICFIntMajorVersionObj*>( retobj ) );
	}

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionObj::read( bool forceRead ) {
		cfint::ICFIntMajorVersionObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMajorVersionTableObj()->readMajorVersionByIdIdx( getMajorVersionBuff()->getRequiredTenantId(),
		getMajorVersionBuff()->getRequiredId(), forceRead );
		return( dynamic_cast<cfint::ICFIntMajorVersionObj*>( retobj ) );
	}

	cfint::ICFIntMajorVersionTableObj* CFIntMajorVersionObj::getMajorVersionTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMajorVersionTableObj() );
	}

	cfint::ICFIntSchemaObj* CFIntMajorVersionObj::getSchema() {
		return( schema );
	}

	void CFIntMajorVersionObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = value;
	}

	cfint::CFIntMajorVersionPKey* CFIntMajorVersionObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfint::CFIntMajorVersionPKey();
		}
		return( pKey );
	}

	void CFIntMajorVersionObj::setPKey( cfint::CFIntMajorVersionPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfint::CFIntMajorVersionPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntMajorVersionObj::getIsNew() {
		return( isNew );
	}

	void CFIntMajorVersionObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfint::ICFIntMajorVersionEditObj* CFIntMajorVersionObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfint::ICFIntMajorVersionObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMajorVersionTableObj()->lockMajorVersion( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMajorVersionTableObj()->newEditInstance( this );
		return( dynamic_cast<cfint::ICFIntMajorVersionEditObj*>( edit ) );
	}

	void CFIntMajorVersionObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfint::ICFIntMajorVersionEditObj* CFIntMajorVersionObj::getEdit() {
		return( edit );
	}

	cfint::ICFIntMajorVersionEditObj* CFIntMajorVersionObj::getMajorVersionEdit() {
		return( dynamic_cast<cfint::ICFIntMajorVersionEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntMajorVersionObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getMajorVersionBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntMajorVersionObj::getCreatedAt() {
		return( getMajorVersionBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntMajorVersionObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getMajorVersionBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntMajorVersionObj::getUpdatedAt() {
		return( getMajorVersionBuff()->getUpdatedAt() );
	}

	void CFIntMajorVersionObj::copyPKeyToBuff() {
		cfint::CFIntMajorVersionPKey* tablePKey = getPKey();
		cfint::CFIntMajorVersionBuff* tableBuff = getMajorVersionEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
			tableBuff->setRequiredId( tablePKey->getRequiredId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntMajorVersionObj::copyBuffToPKey() {
		cfint::CFIntMajorVersionPKey* tablePKey = getPKey();
		cfint::CFIntMajorVersionBuff* tableBuff = getMajorVersionBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

}
