// Description: C++18 base object instance implementation for CFInt ISOCtryCcy.

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
#include <cfintobj/CFIntISOCtryCcyObj.hpp>

namespace cfint {

	const std::string CFIntISOCtryCcyObj::CLASS_NAME( "CFIntISOCtryCcyObj" );
	const classcode_t CFIntISOCtryCcyObj::CLASS_CODE = 0xa005L;

	int32_t CFIntISOCtryCcyObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int16_t CFIntISOCtryCcyObj::getRequiredISOCtryId() {
		return( getPKey()->getRequiredISOCtryId() );
	}

	const int16_t* CFIntISOCtryCcyObj::getRequiredISOCtryIdReference() {
		return( getPKey()->getRequiredISOCtryIdReference() );
	}

	const int16_t CFIntISOCtryCcyObj::getRequiredISOCcyId() {
		return( getPKey()->getRequiredISOCcyId() );
	}

	const int16_t* CFIntISOCtryCcyObj::getRequiredISOCcyIdReference() {
		return( getPKey()->getRequiredISOCcyIdReference() );
	}


	cfsec::ICFSecISOCtryObj* CFIntISOCtryCcyObj::getRequiredContainerCtry( bool forceRead ) {
		cfsec::ICFSecISOCtryObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryTableObj()->readISOCtryByIdIdx( getPKey()->getRequiredISOCtryId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCtryCcyObj::getRequiredParentCcy( bool forceRead ) {
		cfsec::ICFSecISOCcyObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCcyTableObj()->readISOCcyByIdIdx( getPKey()->getRequiredISOCcyId(), forceRead );
		}
		return( retobj );
	}

	CFIntISOCtryCcyObj::CFIntISOCtryCcyObj()
	: ICFIntISOCtryCcyObj(),
	  ICFSecISOCtryCcyObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOCtryCcyObj::CFIntISOCtryCcyObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntISOCtryCcyObj(),
	  ICFSecISOCtryCcyObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOCtryCcyObj::~CFIntISOCtryCcyObj() {
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

	cfsec::CFSecISOCtryCcyBuff* CFIntISOCtryCcyObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecISOCtryCcyBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCtryCcy()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredISOCtryId(),
						getPKey()->getRequiredISOCcyId() );
			}
		}
		return( buff );
	}

	void CFIntISOCtryCcyObj::setBuff( cfsec::CFSecISOCtryCcyBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntISOCtryCcyObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntISOCtryCcyObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntISOCtryCcyObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCtryCcyBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntISOCtryCcyObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntISOCtryCcyObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOCcyId( "ISOCcyId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntISOCtryCcyObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntISOCtryCcyObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntISOCtryCcyObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntISOCtryCcyObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntISOCtryCcyObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, CFIntISOCtryCcyObj::getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCcyId, CFIntISOCtryCcyObj::getRequiredISOCcyId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntISOCtryCcyObj::getObjName() {
		std::string objName( CLASS_NAME );
		int16_t val = getRequiredISOCcyId();
		objName = cflib::CFLibXmlUtil::formatInt16( val );
		return( objName );
	}

	const std::string CFIntISOCtryCcyObj::getGenDefName() {
		return( cfsec::CFSecISOCtryCcyBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryCcyObj::getScope() {
		cfsec::ICFSecISOCtryObj* scope = getRequiredContainerCtry();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryCcyObj::getObjScope() {
		cfsec::ICFSecISOCtryObj* scope = getRequiredContainerCtry();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryCcyObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntISOCtryCcyObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryCcyObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntISOCtryCcyObj::getObjQualifiedName() {
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

	std::string CFIntISOCtryCcyObj::getObjFullName() {
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

	cfsec::ICFSecISOCtryCcyObj* CFIntISOCtryCcyObj::realize() {
		cfsec::ICFSecISOCtryCcyObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryCcyTableObj()->realizeISOCtryCcy(
			(cfsec::ICFSecISOCtryCcyObj*)this );
		return( dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( retobj ) );
	}

	cfsec::ICFSecISOCtryCcyObj* CFIntISOCtryCcyObj::read( bool forceRead ) {
		cfsec::ICFSecISOCtryCcyObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryCcyTableObj()->readISOCtryCcyByIdIdx( getISOCtryCcyBuff()->getRequiredISOCtryId(),
		getISOCtryCcyBuff()->getRequiredISOCcyId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecISOCtryCcyObj*>( retobj ) );
	}

	cfsec::ICFSecISOCtryCcyTableObj* CFIntISOCtryCcyObj::getISOCtryCcyTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryCcyTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntISOCtryCcyObj::getSchema() {
		return( schema );
	}

	void CFIntISOCtryCcyObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecISOCtryCcyPKey* CFIntISOCtryCcyObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecISOCtryCcyPKey();
		}
		return( pKey );
	}

	void CFIntISOCtryCcyObj::setPKey( cfsec::CFSecISOCtryCcyPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecISOCtryCcyPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntISOCtryCcyObj::getIsNew() {
		return( isNew );
	}

	void CFIntISOCtryCcyObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecISOCtryCcyEditObj* CFIntISOCtryCcyObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecISOCtryCcyObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryCcyTableObj()->lockISOCtryCcy( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOCtryCcyTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecISOCtryCcyEditObj*>( edit ) );
	}

	void CFIntISOCtryCcyObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecISOCtryCcyEditObj* CFIntISOCtryCcyObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecISOCtryCcyEditObj* CFIntISOCtryCcyObj::getISOCtryCcyEdit() {
		return( dynamic_cast<cfsec::ICFSecISOCtryCcyEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCtryCcyObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryCcyBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCtryCcyObj::getCreatedAt() {
		return( getISOCtryCcyBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCtryCcyObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryCcyBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCtryCcyObj::getUpdatedAt() {
		return( getISOCtryCcyBuff()->getUpdatedAt() );
	}

	void CFIntISOCtryCcyObj::copyPKeyToBuff() {
		cfsec::CFSecISOCtryCcyPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryCcyBuff* tableBuff = getISOCtryCcyEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredISOCtryId( tablePKey->getRequiredISOCtryId() );
			tableBuff->setRequiredISOCcyId( tablePKey->getRequiredISOCcyId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntISOCtryCcyObj::copyBuffToPKey() {
		cfsec::CFSecISOCtryCcyPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryCcyBuff* tableBuff = getISOCtryCcyBuff();
		tablePKey->setRequiredISOCtryId( tableBuff->getRequiredISOCtryId() );
		tablePKey->setRequiredISOCcyId( tableBuff->getRequiredISOCcyId() );
	}

}
