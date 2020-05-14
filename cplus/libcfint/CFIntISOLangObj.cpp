// Description: C++18 base object instance implementation for CFInt ISOLang.

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
#include <cfintobj/CFIntISOLangObj.hpp>

namespace cfint {

	const std::string CFIntISOLangObj::CLASS_NAME( "CFIntISOLangObj" );
	const classcode_t CFIntISOLangObj::CLASS_CODE = 0xa007L;

	int32_t CFIntISOLangObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int16_t CFIntISOLangObj::getRequiredISOLangId() {
		return( getPKey()->getRequiredISOLangId() );
	}

	const int16_t* CFIntISOLangObj::getRequiredISOLangIdReference() {
		return( getPKey()->getRequiredISOLangIdReference() );
	}

	const std::string& CFIntISOLangObj::getRequiredISO6392Code() {
		return( getISOLangBuff()->getRequiredISO6392Code() );
	}

	const std::string* CFIntISOLangObj::getRequiredISO6392CodeReference() {
		return( getISOLangBuff()->getRequiredISO6392CodeReference() );
	}

	bool CFIntISOLangObj::isOptionalISO6391CodeNull() {
		return( getISOLangBuff()->isOptionalISO6391CodeNull() );
	}

	const std::string& CFIntISOLangObj::getOptionalISO6391CodeValue() {
		return( getISOLangBuff()->getOptionalISO6391CodeValue() );
	}

	const std::string* CFIntISOLangObj::getOptionalISO6391CodeReference() {
		return( getISOLangBuff()->getOptionalISO6391CodeReference() );
	}

	const std::string& CFIntISOLangObj::getRequiredEnglishName() {
		return( getISOLangBuff()->getRequiredEnglishName() );
	}

	const std::string* CFIntISOLangObj::getRequiredEnglishNameReference() {
		return( getISOLangBuff()->getRequiredEnglishNameReference() );
	}


	std::vector<cfsec::ICFSecISOCtryLangObj*> CFIntISOLangObj::getOptionalChildrenCtry( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryLangObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryLangTableObj()->readISOCtryLangByLangIdx( getPKey()->getRequiredISOLangId(),
			forceRead );
		return( retval );
	}

	CFIntISOLangObj::CFIntISOLangObj()
	: ICFIntISOLangObj(),
	  ICFSecISOLangObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOLangObj::CFIntISOLangObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntISOLangObj(),
	  ICFSecISOLangObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOLangObj::~CFIntISOLangObj() {
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

	cfsec::CFSecISOLangBuff* CFIntISOLangObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecISOLangBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredISOLangId() );
			}
		}
		return( buff );
	}

	void CFIntISOLangObj::setBuff( cfsec::CFSecISOLangBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntISOLangObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntISOLangObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntISOLangObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntISOLangObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntISOLangObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOLangId( "ISOLangId" );
		static const std::string S_ISO6392Code( "ISO6392Code" );
		static const std::string S_ISO6391Code( "ISO6391Code" );
		static const std::string S_EnglishName( "EnglishName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntISOLangObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntISOLangObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntISOLangObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntISOLangObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntISOLangObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, CFIntISOLangObj::getRequiredISOLangId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6392Code, CFIntISOLangObj::getRequiredISO6392Code() ) );
		if( ! CFIntISOLangObj::isOptionalISO6391CodeNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6391Code, CFIntISOLangObj::getOptionalISO6391CodeValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EnglishName, CFIntISOLangObj::getRequiredEnglishName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntISOLangObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredISO6392Code() );
		return( objName );
	}

	const std::string CFIntISOLangObj::getGenDefName() {
		return( cfsec::CFSecISOLangBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntISOLangObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOLangObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOLangObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntISOLangObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntISOLangObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntISOLangObj::getObjQualifiedName() {
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

	std::string CFIntISOLangObj::getObjFullName() {
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

	cfsec::ICFSecISOLangObj* CFIntISOLangObj::realize() {
		cfsec::ICFSecISOLangObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOLangTableObj()->realizeISOLang(
			(cfsec::ICFSecISOLangObj*)this );
		return( dynamic_cast<cfsec::ICFSecISOLangObj*>( retobj ) );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangObj::read( bool forceRead ) {
		cfsec::ICFSecISOLangObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOLangTableObj()->readISOLangByIdIdx( getISOLangBuff()->getRequiredISOLangId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecISOLangObj*>( retobj ) );
	}

	cfsec::ICFSecISOLangTableObj* CFIntISOLangObj::getISOLangTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOLangTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntISOLangObj::getSchema() {
		return( schema );
	}

	void CFIntISOLangObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecISOLangPKey* CFIntISOLangObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecISOLangPKey();
		}
		return( pKey );
	}

	void CFIntISOLangObj::setPKey( cfsec::CFSecISOLangPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecISOLangPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntISOLangObj::getIsNew() {
		return( isNew );
	}

	void CFIntISOLangObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecISOLangEditObj* CFIntISOLangObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecISOLangObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOLangTableObj()->lockISOLang( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOLangTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecISOLangEditObj*>( edit ) );
	}

	void CFIntISOLangObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecISOLangEditObj* CFIntISOLangObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecISOLangEditObj* CFIntISOLangObj::getISOLangEdit() {
		return( dynamic_cast<cfsec::ICFSecISOLangEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntISOLangObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOLangBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOLangObj::getCreatedAt() {
		return( getISOLangBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntISOLangObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOLangBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOLangObj::getUpdatedAt() {
		return( getISOLangBuff()->getUpdatedAt() );
	}

	void CFIntISOLangObj::copyPKeyToBuff() {
		cfsec::CFSecISOLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOLangBuff* tableBuff = getISOLangEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredISOLangId( tablePKey->getRequiredISOLangId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntISOLangObj::copyBuffToPKey() {
		cfsec::CFSecISOLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOLangBuff* tableBuff = getISOLangBuff();
		tablePKey->setRequiredISOLangId( tableBuff->getRequiredISOLangId() );
	}

}
