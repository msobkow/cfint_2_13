// Description: C++18 edit object instance implementation for CFInt ISOCtryLang.

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
#include <cfintobj/CFIntISOCtryLangEditObj.hpp>


namespace cfint {

	const std::string CFIntISOCtryLangEditObj::CLASS_NAME( "CFIntISOCtryLangEditObj" );

	CFIntISOCtryLangEditObj::CFIntISOCtryLangEditObj( cfsec::ICFSecISOCtryLangObj* argOrig )
	: ICFIntISOCtryLangEditObj(),
	  ICFSecISOCtryLangEditObj()
	{
		static const std::string S_ProcName( "CFIntISOCtryLangEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecISOCtryLangBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( origBuff->clone() );
	}

	CFIntISOCtryLangEditObj::~CFIntISOCtryLangEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntISOCtryLangEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCtryLangEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryLangBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCtryLangEditObj::getCreatedAt() {
		return( getISOCtryLangBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCtryLangEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryLangBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCtryLangEditObj::getUpdatedAt() {
		return( getISOCtryLangBuff()->getUpdatedAt() );
	}

	void CFIntISOCtryLangEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getISOCtryLangEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntISOCtryLangEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCtryLangEditBuff()->setCreatedAt( value );
	}

	void CFIntISOCtryLangEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getISOCtryLangEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntISOCtryLangEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCtryLangEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntISOCtryLangEditObj::getClassCode() const {
		return( cfsec::CFSecISOCtryLangBuff::CLASS_CODE );
	}

	bool CFIntISOCtryLangEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntISOCtryLangEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntISOCtryLangEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOCtryId( "ISOCtryId" );
		static const std::string S_ISOLangId( "ISOLangId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntISOCtryLangEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntISOCtryLangEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntISOCtryLangEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntISOCtryLangEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntISOCtryLangEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, CFIntISOCtryLangEditObj::getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, CFIntISOCtryLangEditObj::getRequiredISOLangId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntISOCtryLangEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntISOCtryLangEditObj::setRequiredRevision( int32_t value ) {
		getISOCtryLangEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntISOCtryLangEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int16_t val = getRequiredISOLangId();
		objName = cflib::CFLibXmlUtil::formatInt16( val );
		return( objName );
	}

	const std::string CFIntISOCtryLangEditObj::getGenDefName() {
		return( cfsec::CFSecISOCtryLangBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryLangEditObj::getScope() {
		cfsec::ICFSecISOCtryObj* scope = getRequiredContainerCtry();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryLangEditObj::getObjScope() {
		cfsec::ICFSecISOCtryObj* scope = getRequiredContainerCtry();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryLangEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntISOCtryLangEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryLangEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntISOCtryLangEditObj::getObjQualifiedName() {
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

	std::string CFIntISOCtryLangEditObj::getObjFullName() {
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

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecISOCtryLangObj* retobj = getSchema()->getISOCtryLangTableObj()->realizeISOCtryLang( dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangEditObj::read( bool forceRead ) {
		cfsec::ICFSecISOCtryLangObj* retval = getOrigAsISOCtryLang()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangEditObj::create() {
		cfsec::ICFSecISOCtryLangObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsISOCtryLang()->getSchema() )->getISOCtryLangTableObj()->createISOCtryLang( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFIntISOCtryLangEditObj::update() {
		getSchema()->getISOCtryLangTableObj()->updateISOCtryLang( this );
		return( NULL );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFIntISOCtryLangEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getISOCtryLangTableObj()->deleteISOCtryLang( this );
		return( NULL );
	}

	cfsec::ICFSecISOCtryLangTableObj* CFIntISOCtryLangEditObj::getISOCtryLangTable() {
		return( orig->getSchema()->getISOCtryLangTableObj() );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFIntISOCtryLangEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFIntISOCtryLangEditObj::getISOCtryLangEdit() {
		return( (cfsec::ICFSecISOCtryLangEditObj*)this );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFIntISOCtryLangEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntISOCtryLangEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangEditObj::getOrigAsISOCtryLang() {
		return( dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntISOCtryLangEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecISOCtryLangBuff* CFIntISOCtryLangEditObj::getBuff() {
		return( buff );
	}

	void CFIntISOCtryLangEditObj::setBuff( cfsec::CFSecISOCtryLangBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecISOCtryLangPKey* CFIntISOCtryLangEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntISOCtryLangEditObj::setPKey( cfsec::CFSecISOCtryLangPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntISOCtryLangEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntISOCtryLangEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int16_t CFIntISOCtryLangEditObj::getRequiredISOCtryId() {
		return( getPKey()->getRequiredISOCtryId() );
	}

	const int16_t* CFIntISOCtryLangEditObj::getRequiredISOCtryIdReference() {
		return( getPKey()->getRequiredISOCtryIdReference() );
	}

	const int16_t CFIntISOCtryLangEditObj::getRequiredISOLangId() {
		return( getPKey()->getRequiredISOLangId() );
	}

	const int16_t* CFIntISOCtryLangEditObj::getRequiredISOLangIdReference() {
		return( getPKey()->getRequiredISOLangIdReference() );
	}

	cfsec::ICFSecISOCtryObj* CFIntISOCtryLangEditObj::getRequiredContainerCtry( bool forceRead ) {
		cfsec::ICFSecISOCtryObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsISOCtryLang()->getSchema() )->getISOCtryTableObj()->readISOCtryByIdIdx( getPKey()->getRequiredISOCtryId() );
		}
		return( retobj );
	}

	void CFIntISOCtryLangEditObj::setRequiredContainerCtry( cfsec::ICFSecISOCtryObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredISOCtryId
( value->getRequiredISOCtryId() );
				getISOCtryLangEditBuff()->setRequiredISOCtryId( value->getRequiredISOCtryId() );
			}
		}

	cfsec::ICFSecISOLangObj* CFIntISOCtryLangEditObj::getRequiredParentLang( bool forceRead ) {
		cfsec::ICFSecISOLangObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsISOCtryLang()->getSchema() )->getISOLangTableObj()->readISOLangByIdIdx( getPKey()->getRequiredISOLangId() );
		}
		return( retobj );
	}

	void CFIntISOCtryLangEditObj::setRequiredParentLang( cfsec::ICFSecISOLangObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredISOLangId
( value->getRequiredISOLangId() );
				getISOCtryLangEditBuff()->setRequiredISOLangId( value->getRequiredISOLangId() );
			}
			else {
			}
		}

	void CFIntISOCtryLangEditObj::copyPKeyToBuff() {
		cfsec::CFSecISOCtryLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryLangBuff* tableBuff = getISOCtryLangEditBuff();
		tableBuff->setRequiredISOCtryId( tablePKey->getRequiredISOCtryId() );
		tableBuff->setRequiredISOLangId( tablePKey->getRequiredISOLangId() );
	}

	void CFIntISOCtryLangEditObj::copyBuffToPKey() {
		cfsec::CFSecISOCtryLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryLangBuff* tableBuff = getISOCtryLangBuff();
		tablePKey->setRequiredISOCtryId( tableBuff->getRequiredISOCtryId() );
		tablePKey->setRequiredISOLangId( tableBuff->getRequiredISOLangId() );
	}

	void CFIntISOCtryLangEditObj::copyBuffToOrig() {
		cfsec::CFSecISOCtryLangBuff* origBuff = getOrigAsISOCtryLang()->getISOCtryLangEditBuff();
		cfsec::CFSecISOCtryLangBuff* myBuff = getISOCtryLangBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntISOCtryLangEditObj::copyOrigToBuff() {
		cfsec::CFSecISOCtryLangBuff* origBuff = getOrigAsISOCtryLang()->getISOCtryLangBuff();
		cfsec::CFSecISOCtryLangBuff* myBuff = getISOCtryLangEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
