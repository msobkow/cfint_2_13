// Description: C++18 base object instance implementation for CFInt ISOCcy.

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
#include <cfintobj/CFIntISOCcyObj.hpp>

namespace cfint {

	const std::string CFIntISOCcyObj::CLASS_NAME( "CFIntISOCcyObj" );
	const classcode_t CFIntISOCcyObj::CLASS_CODE = 0xa003L;

	int32_t CFIntISOCcyObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int16_t CFIntISOCcyObj::getRequiredISOCcyId() {
		return( getPKey()->getRequiredISOCcyId() );
	}

	const int16_t* CFIntISOCcyObj::getRequiredISOCcyIdReference() {
		return( getPKey()->getRequiredISOCcyIdReference() );
	}

	const std::string& CFIntISOCcyObj::getRequiredISOCode() {
		return( getISOCcyBuff()->getRequiredISOCode() );
	}

	const std::string* CFIntISOCcyObj::getRequiredISOCodeReference() {
		return( getISOCcyBuff()->getRequiredISOCodeReference() );
	}

	const std::string& CFIntISOCcyObj::getRequiredName() {
		return( getISOCcyBuff()->getRequiredName() );
	}

	const std::string* CFIntISOCcyObj::getRequiredNameReference() {
		return( getISOCcyBuff()->getRequiredNameReference() );
	}

	bool CFIntISOCcyObj::isOptionalUnitSymbolNull() {
		return( getISOCcyBuff()->isOptionalUnitSymbolNull() );
	}

	const std::string& CFIntISOCcyObj::getOptionalUnitSymbolValue() {
		return( getISOCcyBuff()->getOptionalUnitSymbolValue() );
	}

	const std::string* CFIntISOCcyObj::getOptionalUnitSymbolReference() {
		return( getISOCcyBuff()->getOptionalUnitSymbolReference() );
	}

	const int16_t CFIntISOCcyObj::getRequiredPrecis() {
		return( getISOCcyBuff()->getRequiredPrecis() );
	}

	const int16_t* CFIntISOCcyObj::getRequiredPrecisReference() {
		return( getISOCcyBuff()->getRequiredPrecisReference() );
	}


	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFIntISOCcyObj::getOptionalChildrenCtry( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryCcyObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryCcyTableObj()->readISOCtryCcyByCcyIdx( getPKey()->getRequiredISOCcyId(),
			forceRead );
		return( retval );
	}

	CFIntISOCcyObj::CFIntISOCcyObj()
	: ICFIntISOCcyObj(),
	  ICFSecISOCcyObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOCcyObj::CFIntISOCcyObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntISOCcyObj(),
	  ICFSecISOCcyObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOCcyObj::~CFIntISOCcyObj() {
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

	cfsec::CFSecISOCcyBuff* CFIntISOCcyObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecISOCcyBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredISOCcyId() );
			}
		}
		return( buff );
	}

	void CFIntISOCcyObj::setBuff( cfsec::CFSecISOCcyBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntISOCcyObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntISOCcyObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntISOCcyObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntISOCcyObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntISOCcyObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCcyId( "ISOCcyId" );
		static const std::string S_ISOCode( "ISOCode" );
		static const std::string S_Name( "Name" );
		static const std::string S_UnitSymbol( "UnitSymbol" );
		static const std::string S_Precis( "Precis" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntISOCcyObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntISOCcyObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntISOCcyObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntISOCcyObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntISOCcyObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCcyId, CFIntISOCcyObj::getRequiredISOCcyId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISOCode, CFIntISOCcyObj::getRequiredISOCode() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntISOCcyObj::getRequiredName() ) );
		if( ! CFIntISOCcyObj::isOptionalUnitSymbolNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UnitSymbol, CFIntISOCcyObj::getOptionalUnitSymbolValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_Precis, CFIntISOCcyObj::getRequiredPrecis() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntISOCcyObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredISOCode() );
		return( objName );
	}

	const std::string CFIntISOCcyObj::getGenDefName() {
		return( cfsec::CFSecISOCcyBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntISOCcyObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOCcyObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOCcyObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntISOCcyObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntISOCcyObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntISOCcyObj::getObjQualifiedName() {
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

	std::string CFIntISOCcyObj::getObjFullName() {
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

	cfsec::ICFSecISOCcyObj* CFIntISOCcyObj::realize() {
		cfsec::ICFSecISOCcyObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCcyTableObj()->realizeISOCcy(
			(cfsec::ICFSecISOCcyObj*)this );
		return( dynamic_cast<cfsec::ICFSecISOCcyObj*>( retobj ) );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyObj::read( bool forceRead ) {
		cfsec::ICFSecISOCcyObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCcyTableObj()->readISOCcyByIdIdx( getISOCcyBuff()->getRequiredISOCcyId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecISOCcyObj*>( retobj ) );
	}

	cfsec::ICFSecISOCcyTableObj* CFIntISOCcyObj::getISOCcyTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCcyTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntISOCcyObj::getSchema() {
		return( schema );
	}

	void CFIntISOCcyObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecISOCcyPKey* CFIntISOCcyObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecISOCcyPKey();
		}
		return( pKey );
	}

	void CFIntISOCcyObj::setPKey( cfsec::CFSecISOCcyPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecISOCcyPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntISOCcyObj::getIsNew() {
		return( isNew );
	}

	void CFIntISOCcyObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecISOCcyEditObj* CFIntISOCcyObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecISOCcyObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCcyTableObj()->lockISOCcy( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCcyTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecISOCcyEditObj*>( edit ) );
	}

	void CFIntISOCcyObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecISOCcyEditObj* CFIntISOCcyObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecISOCcyEditObj* CFIntISOCcyObj::getISOCcyEdit() {
		return( dynamic_cast<cfsec::ICFSecISOCcyEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCcyObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCcyBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCcyObj::getCreatedAt() {
		return( getISOCcyBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCcyObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCcyBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCcyObj::getUpdatedAt() {
		return( getISOCcyBuff()->getUpdatedAt() );
	}

	void CFIntISOCcyObj::copyPKeyToBuff() {
		cfsec::CFSecISOCcyPKey* tablePKey = getPKey();
		cfsec::CFSecISOCcyBuff* tableBuff = getISOCcyEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredISOCcyId( tablePKey->getRequiredISOCcyId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntISOCcyObj::copyBuffToPKey() {
		cfsec::CFSecISOCcyPKey* tablePKey = getPKey();
		cfsec::CFSecISOCcyBuff* tableBuff = getISOCcyBuff();
		tablePKey->setRequiredISOCcyId( tableBuff->getRequiredISOCcyId() );
	}

}
