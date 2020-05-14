// Description: C++18 base object instance implementation for CFInt ISOCtryLang.

/*
 *	com.github.msobkow.CFInt
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
#include <cfintobj/CFIntISOCtryLangObj.hpp>

namespace cfint {

	const std::string CFIntISOCtryLangObj::CLASS_NAME( "CFIntISOCtryLangObj" );
	const classcode_t CFIntISOCtryLangObj::CLASS_CODE = 0xa006L;

	int32_t CFIntISOCtryLangObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int16_t CFIntISOCtryLangObj::getRequiredISOCtryId() {
		return( getPKey()->getRequiredISOCtryId() );
	}

	const int16_t* CFIntISOCtryLangObj::getRequiredISOCtryIdReference() {
		return( getPKey()->getRequiredISOCtryIdReference() );
	}

	const int16_t CFIntISOCtryLangObj::getRequiredISOLangId() {
		return( getPKey()->getRequiredISOLangId() );
	}

	const int16_t* CFIntISOCtryLangObj::getRequiredISOLangIdReference() {
		return( getPKey()->getRequiredISOLangIdReference() );
	}


	cfsec::ICFSecISOCtryObj* CFIntISOCtryLangObj::getRequiredContainerCtry( bool forceRead ) {
		cfsec::ICFSecISOCtryObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryTableObj()->readISOCtryByIdIdx( getPKey()->getRequiredISOCtryId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecISOLangObj* CFIntISOCtryLangObj::getRequiredParentLang( bool forceRead ) {
		cfsec::ICFSecISOLangObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOLangTableObj()->readISOLangByIdIdx( getPKey()->getRequiredISOLangId(), forceRead );
		}
		return( retobj );
	}

	CFIntISOCtryLangObj::CFIntISOCtryLangObj()
	: ICFIntISOCtryLangObj(),
	  ICFSecISOCtryLangObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOCtryLangObj::CFIntISOCtryLangObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntISOCtryLangObj(),
	  ICFSecISOCtryLangObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOCtryLangObj::~CFIntISOCtryLangObj() {
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

	cfsec::CFSecISOCtryLangBuff* CFIntISOCtryLangObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecISOCtryLangBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCtryLang()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredISOCtryId(),
						getPKey()->getRequiredISOLangId() );
			}
		}
		return( buff );
	}

	void CFIntISOCtryLangObj::setBuff( cfsec::CFSecISOCtryLangBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntISOCtryLangObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntISOCtryLangObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntISOCtryLangObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntISOCtryLangObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntISOCtryLangObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOLangId( "ISOLangId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntISOCtryLangObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntISOCtryLangObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntISOCtryLangObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntISOCtryLangObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntISOCtryLangObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, CFIntISOCtryLangObj::getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, CFIntISOCtryLangObj::getRequiredISOLangId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntISOCtryLangObj::getObjName() {
		std::string objName( CLASS_NAME );
		int16_t val = getRequiredISOLangId();
		objName = cflib::CFLibXmlUtil::formatInt16( val );
		return( objName );
	}

	const std::string CFIntISOCtryLangObj::getGenDefName() {
		return( cfsec::CFSecISOCtryLangBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryLangObj::getScope() {
		cfsec::ICFSecISOCtryObj* scope = getRequiredContainerCtry();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryLangObj::getObjScope() {
		cfsec::ICFSecISOCtryObj* scope = getRequiredContainerCtry();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryLangObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntISOCtryLangObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryLangObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntISOCtryLangObj::getObjQualifiedName() {
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

	std::string CFIntISOCtryLangObj::getObjFullName() {
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

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangObj::realize() {
		cfsec::ICFSecISOCtryLangObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryLangTableObj()->realizeISOCtryLang(
			(cfsec::ICFSecISOCtryLangObj*)this );
		return( dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( retobj ) );
	}

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangObj::read( bool forceRead ) {
		cfsec::ICFSecISOCtryLangObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryLangTableObj()->readISOCtryLangByIdIdx( getISOCtryLangBuff()->getRequiredISOCtryId(),
		getISOCtryLangBuff()->getRequiredISOLangId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( retobj ) );
	}

	cfsec::ICFSecISOCtryLangTableObj* CFIntISOCtryLangObj::getISOCtryLangTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryLangTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntISOCtryLangObj::getSchema() {
		return( schema );
	}

	void CFIntISOCtryLangObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecISOCtryLangPKey* CFIntISOCtryLangObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecISOCtryLangPKey();
		}
		return( pKey );
	}

	void CFIntISOCtryLangObj::setPKey( cfsec::CFSecISOCtryLangPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecISOCtryLangPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntISOCtryLangObj::getIsNew() {
		return( isNew );
	}

	void CFIntISOCtryLangObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecISOCtryLangEditObj* CFIntISOCtryLangObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecISOCtryLangObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryLangTableObj()->lockISOCtryLang( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryLangTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecISOCtryLangEditObj*>( edit ) );
	}

	void CFIntISOCtryLangObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecISOCtryLangEditObj* CFIntISOCtryLangObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFIntISOCtryLangObj::getISOCtryLangEdit() {
		return( dynamic_cast<cfsec::ICFSecISOCtryLangEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCtryLangObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryLangBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCtryLangObj::getCreatedAt() {
		return( getISOCtryLangBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCtryLangObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryLangBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCtryLangObj::getUpdatedAt() {
		return( getISOCtryLangBuff()->getUpdatedAt() );
	}

	void CFIntISOCtryLangObj::copyPKeyToBuff() {
		cfsec::CFSecISOCtryLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryLangBuff* tableBuff = getISOCtryLangEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredISOCtryId( tablePKey->getRequiredISOCtryId() );
			tableBuff->setRequiredISOLangId( tablePKey->getRequiredISOLangId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntISOCtryLangObj::copyBuffToPKey() {
		cfsec::CFSecISOCtryLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryLangBuff* tableBuff = getISOCtryLangBuff();
		tablePKey->setRequiredISOCtryId( tableBuff->getRequiredISOCtryId() );
		tablePKey->setRequiredISOLangId( tableBuff->getRequiredISOLangId() );
	}

}
