// Description: C++18 base object instance implementation for CFInt TopProject.

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
#include <cfintobj/CFIntTopProjectObj.hpp>

namespace cfint {

	const std::string CFIntTopProjectObj::CLASS_NAME( "CFIntTopProjectObj" );
	const classcode_t CFIntTopProjectObj::CLASS_CODE = 0xa108L;

	int32_t CFIntTopProjectObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntTopProjectObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntTopProjectObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntTopProjectObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntTopProjectObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const int64_t CFIntTopProjectObj::getRequiredTopDomainId() {
		return( getTopProjectBuff()->getRequiredTopDomainId() );
	}

	const int64_t* CFIntTopProjectObj::getRequiredTopDomainIdReference() {
		return( getTopProjectBuff()->getRequiredTopDomainIdReference() );
	}

	const std::string& CFIntTopProjectObj::getRequiredName() {
		return( getTopProjectBuff()->getRequiredName() );
	}

	const std::string* CFIntTopProjectObj::getRequiredNameReference() {
		return( getTopProjectBuff()->getRequiredNameReference() );
	}

	bool CFIntTopProjectObj::isOptionalDescriptionNull() {
		return( getTopProjectBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntTopProjectObj::getOptionalDescriptionValue() {
		return( getTopProjectBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntTopProjectObj::getOptionalDescriptionReference() {
		return( getTopProjectBuff()->getOptionalDescriptionReference() );
	}


	cfsec::ICFSecTenantObj* CFIntTopProjectObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId(), forceRead );
		}
		return( retobj );
	}

	cfint::ICFIntTopDomainObj* CFIntTopProjectObj::getRequiredContainerParentSDom( bool forceRead ) {
		cfint::ICFIntTopDomainObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopDomainTableObj()->readTopDomainByIdIdx( getPKey()->getRequiredTenantId(),
					getTopProjectBuff()->getRequiredTopDomainId(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfint::ICFIntSubProjectObj*> CFIntTopProjectObj::getOptionalComponentsSubProject( bool forceRead ) {
		std::vector<cfint::ICFIntSubProjectObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSubProjectTableObj()->readSubProjectByTopProjectIdx( getPKey()->getRequiredTenantId(),
					getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	CFIntTopProjectObj::CFIntTopProjectObj()
	: ICFIntTopProjectObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntTopProjectObj::CFIntTopProjectObj( cfint::ICFIntSchemaObj* argSchema )
	: ICFIntTopProjectObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntTopProjectObj::~CFIntTopProjectObj() {
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

	cfint::CFIntTopProjectBuff* CFIntTopProjectObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfint::CFIntTopProjectBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredTenantId(),
						getPKey()->getRequiredId() );
			}
		}
		return( buff );
	}

	void CFIntTopProjectObj::setBuff( cfint::CFIntTopProjectBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntTopProjectObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntTopProjectObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntTopProjectObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntTopProjectObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTopProjectObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntTopProjectObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntTopProjectObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntTopProjectObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntTopProjectObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntTopProjectObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntTopProjectObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntTopProjectObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopDomainId, CFIntTopProjectObj::getRequiredTopDomainId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntTopProjectObj::getRequiredName() ) );
		if( ! CFIntTopProjectObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntTopProjectObj::getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntTopProjectObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntTopProjectObj::getGenDefName() {
		return( cfint::CFIntTopProjectBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntTopProjectObj::getScope() {
		cfint::ICFIntTopDomainObj* scope = getRequiredContainerParentSDom();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTopProjectObj::getObjScope() {
		cfint::ICFIntTopDomainObj* scope = getRequiredContainerParentSDom();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTopProjectObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntTopProjectObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntTopProjectObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntTopProjectObj::getObjQualifiedName() {
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

	std::string CFIntTopProjectObj::getObjFullName() {
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

	cfint::ICFIntTopProjectObj* CFIntTopProjectObj::realize() {
		cfint::ICFIntTopProjectObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopProjectTableObj()->realizeTopProject(
			(cfint::ICFIntTopProjectObj*)this );
		return( dynamic_cast<cfint::ICFIntTopProjectObj*>( retobj ) );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectObj::read( bool forceRead ) {
		cfint::ICFIntTopProjectObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopProjectTableObj()->readTopProjectByIdIdx( getTopProjectBuff()->getRequiredTenantId(),
		getTopProjectBuff()->getRequiredId(), forceRead );
		return( dynamic_cast<cfint::ICFIntTopProjectObj*>( retobj ) );
	}

	cfint::ICFIntTopProjectTableObj* CFIntTopProjectObj::getTopProjectTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopProjectTableObj() );
	}

	cfint::ICFIntSchemaObj* CFIntTopProjectObj::getSchema() {
		return( schema );
	}

	void CFIntTopProjectObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = value;
	}

	cfint::CFIntTopProjectPKey* CFIntTopProjectObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfint::CFIntTopProjectPKey();
		}
		return( pKey );
	}

	void CFIntTopProjectObj::setPKey( cfint::CFIntTopProjectPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfint::CFIntTopProjectPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntTopProjectObj::getIsNew() {
		return( isNew );
	}

	void CFIntTopProjectObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfint::ICFIntTopProjectEditObj* CFIntTopProjectObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfint::ICFIntTopProjectObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopProjectTableObj()->lockTopProject( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTopProjectTableObj()->newEditInstance( this );
		return( dynamic_cast<cfint::ICFIntTopProjectEditObj*>( edit ) );
	}

	void CFIntTopProjectObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfint::ICFIntTopProjectEditObj* CFIntTopProjectObj::getEdit() {
		return( edit );
	}

	cfint::ICFIntTopProjectEditObj* CFIntTopProjectObj::getTopProjectEdit() {
		return( dynamic_cast<cfint::ICFIntTopProjectEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntTopProjectObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTopProjectBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntTopProjectObj::getCreatedAt() {
		return( getTopProjectBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntTopProjectObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTopProjectBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntTopProjectObj::getUpdatedAt() {
		return( getTopProjectBuff()->getUpdatedAt() );
	}

	void CFIntTopProjectObj::copyPKeyToBuff() {
		cfint::CFIntTopProjectPKey* tablePKey = getPKey();
		cfint::CFIntTopProjectBuff* tableBuff = getTopProjectEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
			tableBuff->setRequiredId( tablePKey->getRequiredId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntTopProjectObj::copyBuffToPKey() {
		cfint::CFIntTopProjectPKey* tablePKey = getPKey();
		cfint::CFIntTopProjectBuff* tableBuff = getTopProjectBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

}
