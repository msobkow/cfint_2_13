// Description: C++18 base object instance implementation for CFInt ISOCtry.

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
#include <cfintobj/CFIntISOCtryObj.hpp>

namespace cfint {

	const std::string CFIntISOCtryObj::CLASS_NAME( "CFIntISOCtryObj" );
	const classcode_t CFIntISOCtryObj::CLASS_CODE = 0xa004L;

	int32_t CFIntISOCtryObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int16_t CFIntISOCtryObj::getRequiredISOCtryId() {
		return( getPKey()->getRequiredISOCtryId() );
	}

	const int16_t* CFIntISOCtryObj::getRequiredISOCtryIdReference() {
		return( getPKey()->getRequiredISOCtryIdReference() );
	}

	const std::string& CFIntISOCtryObj::getRequiredISOCode() {
		return( getISOCtryBuff()->getRequiredISOCode() );
	}

	const std::string* CFIntISOCtryObj::getRequiredISOCodeReference() {
		return( getISOCtryBuff()->getRequiredISOCodeReference() );
	}

	const std::string& CFIntISOCtryObj::getRequiredName() {
		return( getISOCtryBuff()->getRequiredName() );
	}

	const std::string* CFIntISOCtryObj::getRequiredNameReference() {
		return( getISOCtryBuff()->getRequiredNameReference() );
	}


	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFIntISOCtryObj::getOptionalComponentsCcy( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryCcyObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryCcyTableObj()->readISOCtryCcyByCtryIdx( getPKey()->getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecISOCtryLangObj*> CFIntISOCtryObj::getOptionalComponentsLang( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryLangObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryLangTableObj()->readISOCtryLangByCtryIdx( getPKey()->getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	CFIntISOCtryObj::CFIntISOCtryObj()
	: ICFIntISOCtryObj(),
	  ICFSecISOCtryObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOCtryObj::CFIntISOCtryObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntISOCtryObj(),
	  ICFSecISOCtryObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOCtryObj::~CFIntISOCtryObj() {
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

	cfsec::CFSecISOCtryBuff* CFIntISOCtryObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecISOCtryBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCtry()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredISOCtryId() );
			}
		}
		return( buff );
	}

	void CFIntISOCtryObj::setBuff( cfsec::CFSecISOCtryBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntISOCtryObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntISOCtryObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntISOCtryObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntISOCtryObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntISOCtryObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOCode( "ISOCode" );
		static const std::string S_Name( "Name" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntISOCtryObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntISOCtryObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntISOCtryObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntISOCtryObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntISOCtryObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, CFIntISOCtryObj::getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISOCode, CFIntISOCtryObj::getRequiredISOCode() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntISOCtryObj::getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntISOCtryObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredISOCode() );
		return( objName );
	}

	const std::string CFIntISOCtryObj::getGenDefName() {
		return( cfsec::CFSecISOCtryBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntISOCtryObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntISOCtryObj::getObjQualifiedName() {
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

	std::string CFIntISOCtryObj::getObjFullName() {
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

	cfsec::ICFSecISOCtryObj* CFIntISOCtryObj::realize() {
		cfsec::ICFSecISOCtryObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryTableObj()->realizeISOCtry(
			(cfsec::ICFSecISOCtryObj*)this );
		return( dynamic_cast<cfsec::ICFSecISOCtryObj*>( retobj ) );
	}

	cfsec::ICFSecISOCtryObj* CFIntISOCtryObj::read( bool forceRead ) {
		cfsec::ICFSecISOCtryObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryTableObj()->readISOCtryByIdIdx( getISOCtryBuff()->getRequiredISOCtryId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecISOCtryObj*>( retobj ) );
	}

	cfsec::ICFSecISOCtryTableObj* CFIntISOCtryObj::getISOCtryTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntISOCtryObj::getSchema() {
		return( schema );
	}

	void CFIntISOCtryObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecISOCtryPKey* CFIntISOCtryObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecISOCtryPKey();
		}
		return( pKey );
	}

	void CFIntISOCtryObj::setPKey( cfsec::CFSecISOCtryPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecISOCtryPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntISOCtryObj::getIsNew() {
		return( isNew );
	}

	void CFIntISOCtryObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecISOCtryEditObj* CFIntISOCtryObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecISOCtryObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryTableObj()->lockISOCtry( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecISOCtryEditObj*>( edit ) );
	}

	void CFIntISOCtryObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecISOCtryEditObj* CFIntISOCtryObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecISOCtryEditObj* CFIntISOCtryObj::getISOCtryEdit() {
		return( dynamic_cast<cfsec::ICFSecISOCtryEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCtryObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCtryObj::getCreatedAt() {
		return( getISOCtryBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCtryObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCtryObj::getUpdatedAt() {
		return( getISOCtryBuff()->getUpdatedAt() );
	}

	void CFIntISOCtryObj::copyPKeyToBuff() {
		cfsec::CFSecISOCtryPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryBuff* tableBuff = getISOCtryEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredISOCtryId( tablePKey->getRequiredISOCtryId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntISOCtryObj::copyBuffToPKey() {
		cfsec::CFSecISOCtryPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryBuff* tableBuff = getISOCtryBuff();
		tablePKey->setRequiredISOCtryId( tableBuff->getRequiredISOCtryId() );
	}

}
