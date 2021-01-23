// Description: C++18 base object instance implementation for CFInt SubProject.

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
#include <cfintobj/CFIntSubProjectObj.hpp>

namespace cfint {

	const std::string CFIntSubProjectObj::CLASS_NAME( "CFIntSubProjectObj" );
	const classcode_t CFIntSubProjectObj::CLASS_CODE = 0xa105L;

	int32_t CFIntSubProjectObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntSubProjectObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntSubProjectObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntSubProjectObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntSubProjectObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const int64_t CFIntSubProjectObj::getRequiredTopProjectId() {
		return( getSubProjectBuff()->getRequiredTopProjectId() );
	}

	const int64_t* CFIntSubProjectObj::getRequiredTopProjectIdReference() {
		return( getSubProjectBuff()->getRequiredTopProjectIdReference() );
	}

	const std::string& CFIntSubProjectObj::getRequiredName() {
		return( getSubProjectBuff()->getRequiredName() );
	}

	const std::string* CFIntSubProjectObj::getRequiredNameReference() {
		return( getSubProjectBuff()->getRequiredNameReference() );
	}

	bool CFIntSubProjectObj::isOptionalDescriptionNull() {
		return( getSubProjectBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntSubProjectObj::getOptionalDescriptionValue() {
		return( getSubProjectBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntSubProjectObj::getOptionalDescriptionReference() {
		return( getSubProjectBuff()->getOptionalDescriptionReference() );
	}


	cfsec::ICFSecTenantObj* CFIntSubProjectObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId(), forceRead );
		}
		return( retobj );
	}

	cfint::ICFIntTopProjectObj* CFIntSubProjectObj::getRequiredContainerParentTPrj( bool forceRead ) {
		cfint::ICFIntTopProjectObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopProjectTableObj()->readTopProjectByIdIdx( getPKey()->getRequiredTenantId(),
					getSubProjectBuff()->getRequiredTopProjectId(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfint::ICFIntMajorVersionObj*> CFIntSubProjectObj::getOptionalComponentsMajorVer( bool forceRead ) {
		std::vector<cfint::ICFIntMajorVersionObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMajorVersionTableObj()->readMajorVersionBySubProjectIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	CFIntSubProjectObj::CFIntSubProjectObj()
	: ICFIntSubProjectObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSubProjectObj::CFIntSubProjectObj( cfint::ICFIntSchemaObj* argSchema )
	: ICFIntSubProjectObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSubProjectObj::~CFIntSubProjectObj() {
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

	cfint::CFIntSubProjectBuff* CFIntSubProjectObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfint::CFIntSubProjectBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredTenantId(),
						getPKey()->getRequiredId() );
			}
		}
		return( buff );
	}

	void CFIntSubProjectObj::setBuff( cfint::CFIntSubProjectBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntSubProjectObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSubProjectObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntSubProjectObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntSubProjectBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSubProjectObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSubProjectObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSubProjectObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSubProjectObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSubProjectObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSubProjectObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSubProjectObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntSubProjectObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntSubProjectObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopProjectId, CFIntSubProjectObj::getRequiredTopProjectId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntSubProjectObj::getRequiredName() ) );
		if( ! CFIntSubProjectObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntSubProjectObj::getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntSubProjectObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntSubProjectObj::getGenDefName() {
		return( cfint::CFIntSubProjectBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSubProjectObj::getScope() {
		cfint::ICFIntTopProjectObj* scope = getRequiredContainerParentTPrj();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSubProjectObj::getObjScope() {
		cfint::ICFIntTopProjectObj* scope = getRequiredContainerParentTPrj();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSubProjectObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSubProjectObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSubProjectObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSubProjectObj::getObjQualifiedName() {
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

	std::string CFIntSubProjectObj::getObjFullName() {
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

	cfint::ICFIntSubProjectObj* CFIntSubProjectObj::realize() {
		cfint::ICFIntSubProjectObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSubProjectTableObj()->realizeSubProject(
			(cfint::ICFIntSubProjectObj*)this );
		return( dynamic_cast<cfint::ICFIntSubProjectObj*>( retobj ) );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectObj::read( bool forceRead ) {
		cfint::ICFIntSubProjectObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSubProjectTableObj()->readSubProjectByIdIdx( getSubProjectBuff()->getRequiredTenantId(),
		getSubProjectBuff()->getRequiredId(), forceRead );
		return( dynamic_cast<cfint::ICFIntSubProjectObj*>( retobj ) );
	}

	cfint::ICFIntSubProjectTableObj* CFIntSubProjectObj::getSubProjectTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSubProjectTableObj() );
	}

	cfint::ICFIntSchemaObj* CFIntSubProjectObj::getSchema() {
		return( schema );
	}

	void CFIntSubProjectObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = value;
	}

	cfint::CFIntSubProjectPKey* CFIntSubProjectObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfint::CFIntSubProjectPKey();
		}
		return( pKey );
	}

	void CFIntSubProjectObj::setPKey( cfint::CFIntSubProjectPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfint::CFIntSubProjectPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntSubProjectObj::getIsNew() {
		return( isNew );
	}

	void CFIntSubProjectObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfint::ICFIntSubProjectEditObj* CFIntSubProjectObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfint::ICFIntSubProjectObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSubProjectTableObj()->lockSubProject( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSubProjectTableObj()->newEditInstance( this );
		return( dynamic_cast<cfint::ICFIntSubProjectEditObj*>( edit ) );
	}

	void CFIntSubProjectObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfint::ICFIntSubProjectEditObj* CFIntSubProjectObj::getEdit() {
		return( edit );
	}

	cfint::ICFIntSubProjectEditObj* CFIntSubProjectObj::getSubProjectEdit() {
		return( dynamic_cast<cfint::ICFIntSubProjectEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntSubProjectObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSubProjectBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSubProjectObj::getCreatedAt() {
		return( getSubProjectBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSubProjectObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSubProjectBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSubProjectObj::getUpdatedAt() {
		return( getSubProjectBuff()->getUpdatedAt() );
	}

	void CFIntSubProjectObj::copyPKeyToBuff() {
		cfint::CFIntSubProjectPKey* tablePKey = getPKey();
		cfint::CFIntSubProjectBuff* tableBuff = getSubProjectEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
			tableBuff->setRequiredId( tablePKey->getRequiredId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntSubProjectObj::copyBuffToPKey() {
		cfint::CFIntSubProjectPKey* tablePKey = getPKey();
		cfint::CFIntSubProjectBuff* tableBuff = getSubProjectBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

}
