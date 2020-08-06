// Description: C++18 base object instance implementation for CFInt ServiceType.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
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
#include <cfintobj/CFIntServiceTypeObj.hpp>

namespace cfint {

	const std::string CFIntServiceTypeObj::CLASS_NAME( "CFIntServiceTypeObj" );
	const classcode_t CFIntServiceTypeObj::CLASS_CODE = 0xa013L;

	int32_t CFIntServiceTypeObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int32_t CFIntServiceTypeObj::getRequiredServiceTypeId() {
		return( getPKey()->getRequiredServiceTypeId() );
	}

	const int32_t* CFIntServiceTypeObj::getRequiredServiceTypeIdReference() {
		return( getPKey()->getRequiredServiceTypeIdReference() );
	}

	const std::string& CFIntServiceTypeObj::getRequiredDescription() {
		return( getServiceTypeBuff()->getRequiredDescription() );
	}

	const std::string* CFIntServiceTypeObj::getRequiredDescriptionReference() {
		return( getServiceTypeBuff()->getRequiredDescriptionReference() );
	}


	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTypeObj::getOptionalChildrenDeployed( bool forceRead ) {
		std::vector<cfsec::ICFSecServiceObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getServiceTableObj()->readServiceByTypeIdx( getPKey()->getRequiredServiceTypeId(),
			forceRead );
		return( retval );
	}

	CFIntServiceTypeObj::CFIntServiceTypeObj()
	: ICFIntServiceTypeObj(),
	  ICFSecServiceTypeObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntServiceTypeObj::CFIntServiceTypeObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntServiceTypeObj(),
	  ICFSecServiceTypeObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntServiceTypeObj::~CFIntServiceTypeObj() {
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

	cfsec::CFSecServiceTypeBuff* CFIntServiceTypeObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecServiceTypeBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableServiceType()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredServiceTypeId() );
			}
		}
		return( buff );
	}

	void CFIntServiceTypeObj::setBuff( cfsec::CFSecServiceTypeBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntServiceTypeObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntServiceTypeObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntServiceTypeObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntServiceTypeObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntServiceTypeObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ServiceTypeId( "ServiceTypeId" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntServiceTypeObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntServiceTypeObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntServiceTypeObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntServiceTypeObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntServiceTypeObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_ServiceTypeId, CFIntServiceTypeObj::getRequiredServiceTypeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntServiceTypeObj::getRequiredDescription() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntServiceTypeObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredDescription() );
		return( objName );
	}

	const std::string CFIntServiceTypeObj::getGenDefName() {
		return( cfsec::CFSecServiceTypeBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntServiceTypeObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntServiceTypeObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntServiceTypeObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntServiceTypeObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntServiceTypeObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntServiceTypeObj::getObjQualifiedName() {
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

	std::string CFIntServiceTypeObj::getObjFullName() {
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

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeObj::realize() {
		cfsec::ICFSecServiceTypeObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getServiceTypeTableObj()->realizeServiceType(
			(cfsec::ICFSecServiceTypeObj*)this );
		return( dynamic_cast<cfsec::ICFSecServiceTypeObj*>( retobj ) );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeObj::read( bool forceRead ) {
		cfsec::ICFSecServiceTypeObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getServiceTypeTableObj()->readServiceTypeByIdIdx( getServiceTypeBuff()->getRequiredServiceTypeId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecServiceTypeObj*>( retobj ) );
	}

	cfsec::ICFSecServiceTypeTableObj* CFIntServiceTypeObj::getServiceTypeTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getServiceTypeTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntServiceTypeObj::getSchema() {
		return( schema );
	}

	void CFIntServiceTypeObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecServiceTypePKey* CFIntServiceTypeObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecServiceTypePKey();
		}
		return( pKey );
	}

	void CFIntServiceTypeObj::setPKey( cfsec::CFSecServiceTypePKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecServiceTypePKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntServiceTypeObj::getIsNew() {
		return( isNew );
	}

	void CFIntServiceTypeObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecServiceTypeEditObj* CFIntServiceTypeObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecServiceTypeObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getServiceTypeTableObj()->lockServiceType( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getServiceTypeTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecServiceTypeEditObj*>( edit ) );
	}

	void CFIntServiceTypeObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecServiceTypeEditObj* CFIntServiceTypeObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecServiceTypeEditObj* CFIntServiceTypeObj::getServiceTypeEdit() {
		return( dynamic_cast<cfsec::ICFSecServiceTypeEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntServiceTypeObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getServiceTypeBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntServiceTypeObj::getCreatedAt() {
		return( getServiceTypeBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntServiceTypeObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getServiceTypeBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntServiceTypeObj::getUpdatedAt() {
		return( getServiceTypeBuff()->getUpdatedAt() );
	}

	void CFIntServiceTypeObj::copyPKeyToBuff() {
		cfsec::CFSecServiceTypePKey* tablePKey = getPKey();
		cfsec::CFSecServiceTypeBuff* tableBuff = getServiceTypeEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredServiceTypeId( tablePKey->getRequiredServiceTypeId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntServiceTypeObj::copyBuffToPKey() {
		cfsec::CFSecServiceTypePKey* tablePKey = getPKey();
		cfsec::CFSecServiceTypeBuff* tableBuff = getServiceTypeBuff();
		tablePKey->setRequiredServiceTypeId( tableBuff->getRequiredServiceTypeId() );
	}

}
