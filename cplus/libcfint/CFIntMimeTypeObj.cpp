// Description: C++18 base object instance implementation for CFInt MimeType.

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
#include <cfintobj/CFIntMimeTypeObj.hpp>

namespace cfint {

	const std::string CFIntMimeTypeObj::CLASS_NAME( "CFIntMimeTypeObj" );
	const classcode_t CFIntMimeTypeObj::CLASS_CODE = 0xa103L;

	int32_t CFIntMimeTypeObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int32_t CFIntMimeTypeObj::getRequiredMimeTypeId() {
		return( getPKey()->getRequiredMimeTypeId() );
	}

	const int32_t* CFIntMimeTypeObj::getRequiredMimeTypeIdReference() {
		return( getPKey()->getRequiredMimeTypeIdReference() );
	}

	const std::string& CFIntMimeTypeObj::getRequiredName() {
		return( getMimeTypeBuff()->getRequiredName() );
	}

	const std::string* CFIntMimeTypeObj::getRequiredNameReference() {
		return( getMimeTypeBuff()->getRequiredNameReference() );
	}

	bool CFIntMimeTypeObj::isOptionalFileTypesNull() {
		return( getMimeTypeBuff()->isOptionalFileTypesNull() );
	}

	const std::string& CFIntMimeTypeObj::getOptionalFileTypesValue() {
		return( getMimeTypeBuff()->getOptionalFileTypesValue() );
	}

	const std::string* CFIntMimeTypeObj::getOptionalFileTypesReference() {
		return( getMimeTypeBuff()->getOptionalFileTypesReference() );
	}


	CFIntMimeTypeObj::CFIntMimeTypeObj()
	: ICFIntMimeTypeObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntMimeTypeObj::CFIntMimeTypeObj( cfint::ICFIntSchemaObj* argSchema )
	: ICFIntMimeTypeObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntMimeTypeObj::~CFIntMimeTypeObj() {
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

	cfint::CFIntMimeTypeBuff* CFIntMimeTypeObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfint::CFIntMimeTypeBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMimeType()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredMimeTypeId() );
			}
		}
		return( buff );
	}

	void CFIntMimeTypeObj::setBuff( cfint::CFIntMimeTypeBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntMimeTypeObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntMimeTypeObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntMimeTypeObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntMimeTypeObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMimeTypeObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_MimeTypeId( "MimeTypeId" );
		static const std::string S_Name( "Name" );
		static const std::string S_FileTypes( "FileTypes" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntMimeTypeObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntMimeTypeObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntMimeTypeObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntMimeTypeObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntMimeTypeObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_MimeTypeId, CFIntMimeTypeObj::getRequiredMimeTypeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntMimeTypeObj::getRequiredName() ) );
		if( ! CFIntMimeTypeObj::isOptionalFileTypesNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_FileTypes, CFIntMimeTypeObj::getOptionalFileTypesValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntMimeTypeObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntMimeTypeObj::getGenDefName() {
		return( cfint::CFIntMimeTypeBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntMimeTypeObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntMimeTypeObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntMimeTypeObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntMimeTypeObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntMimeTypeObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntMimeTypeObj::getObjQualifiedName() {
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

	std::string CFIntMimeTypeObj::getObjFullName() {
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

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeObj::realize() {
		cfint::ICFIntMimeTypeObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMimeTypeTableObj()->realizeMimeType(
			(cfint::ICFIntMimeTypeObj*)this );
		return( dynamic_cast<cfint::ICFIntMimeTypeObj*>( retobj ) );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeObj::read( bool forceRead ) {
		cfint::ICFIntMimeTypeObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMimeTypeTableObj()->readMimeTypeByIdIdx( getMimeTypeBuff()->getRequiredMimeTypeId(), forceRead );
		return( dynamic_cast<cfint::ICFIntMimeTypeObj*>( retobj ) );
	}

	cfint::ICFIntMimeTypeTableObj* CFIntMimeTypeObj::getMimeTypeTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMimeTypeTableObj() );
	}

	cfint::ICFIntSchemaObj* CFIntMimeTypeObj::getSchema() {
		return( schema );
	}

	void CFIntMimeTypeObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = value;
	}

	cfint::CFIntMimeTypePKey* CFIntMimeTypeObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfint::CFIntMimeTypePKey();
		}
		return( pKey );
	}

	void CFIntMimeTypeObj::setPKey( cfint::CFIntMimeTypePKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfint::CFIntMimeTypePKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntMimeTypeObj::getIsNew() {
		return( isNew );
	}

	void CFIntMimeTypeObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfint::ICFIntMimeTypeEditObj* CFIntMimeTypeObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfint::ICFIntMimeTypeObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMimeTypeTableObj()->lockMimeType( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getMimeTypeTableObj()->newEditInstance( this );
		return( dynamic_cast<cfint::ICFIntMimeTypeEditObj*>( edit ) );
	}

	void CFIntMimeTypeObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfint::ICFIntMimeTypeEditObj* CFIntMimeTypeObj::getEdit() {
		return( edit );
	}

	cfint::ICFIntMimeTypeEditObj* CFIntMimeTypeObj::getMimeTypeEdit() {
		return( dynamic_cast<cfint::ICFIntMimeTypeEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntMimeTypeObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getMimeTypeBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntMimeTypeObj::getCreatedAt() {
		return( getMimeTypeBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntMimeTypeObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getMimeTypeBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntMimeTypeObj::getUpdatedAt() {
		return( getMimeTypeBuff()->getUpdatedAt() );
	}

	void CFIntMimeTypeObj::copyPKeyToBuff() {
		cfint::CFIntMimeTypePKey* tablePKey = getPKey();
		cfint::CFIntMimeTypeBuff* tableBuff = getMimeTypeEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredMimeTypeId( tablePKey->getRequiredMimeTypeId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntMimeTypeObj::copyBuffToPKey() {
		cfint::CFIntMimeTypePKey* tablePKey = getPKey();
		cfint::CFIntMimeTypeBuff* tableBuff = getMimeTypeBuff();
		tablePKey->setRequiredMimeTypeId( tableBuff->getRequiredMimeTypeId() );
	}

}
