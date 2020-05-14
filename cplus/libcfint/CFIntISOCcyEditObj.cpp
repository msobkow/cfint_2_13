// Description: C++18 edit object instance implementation for CFInt ISOCcy.

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
#include <cfintobj/CFIntISOCcyObj.hpp>
#include <cfintobj/CFIntISOCcyEditObj.hpp>


namespace cfint {

	const std::string CFIntISOCcyEditObj::CLASS_NAME( "CFIntISOCcyEditObj" );

	CFIntISOCcyEditObj::CFIntISOCcyEditObj( cfsec::ICFSecISOCcyObj* argOrig )
	: ICFIntISOCcyEditObj(),
	  ICFSecISOCcyEditObj()
	{
		static const std::string S_ProcName( "CFIntISOCcyEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecISOCcyBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( origBuff->clone() );
	}

	CFIntISOCcyEditObj::~CFIntISOCcyEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntISOCcyEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCcyEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCcyBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCcyEditObj::getCreatedAt() {
		return( getISOCcyBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCcyEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCcyBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCcyEditObj::getUpdatedAt() {
		return( getISOCcyBuff()->getUpdatedAt() );
	}

	void CFIntISOCcyEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getISOCcyEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntISOCcyEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCcyEditBuff()->setCreatedAt( value );
	}

	void CFIntISOCcyEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getISOCcyEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntISOCcyEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCcyEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntISOCcyEditObj::getClassCode() const {
		return( cfsec::CFSecISOCcyBuff::CLASS_CODE );
	}

	bool CFIntISOCcyEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntISOCcyEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntISOCcyEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntISOCcyEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntISOCcyEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntISOCcyEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntISOCcyEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntISOCcyEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCcyId, CFIntISOCcyEditObj::getRequiredISOCcyId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISOCode, CFIntISOCcyEditObj::getRequiredISOCode() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntISOCcyEditObj::getRequiredName() ) );
		if( ! CFIntISOCcyEditObj::isOptionalUnitSymbolNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UnitSymbol, CFIntISOCcyEditObj::getOptionalUnitSymbolValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_Precis, CFIntISOCcyEditObj::getRequiredPrecis() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntISOCcyEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntISOCcyEditObj::setRequiredRevision( int32_t value ) {
		getISOCcyEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntISOCcyEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredISOCode() );
		return( objName );
	}

	const std::string CFIntISOCcyEditObj::getGenDefName() {
		return( cfsec::CFSecISOCcyBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntISOCcyEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOCcyEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOCcyEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntISOCcyEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntISOCcyEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntISOCcyEditObj::getObjQualifiedName() {
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

	std::string CFIntISOCcyEditObj::getObjFullName() {
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

	cfsec::ICFSecISOCcyObj* CFIntISOCcyEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecISOCcyObj* retobj = getSchema()->getISOCcyTableObj()->realizeISOCcy( dynamic_cast<cfsec::ICFSecISOCcyObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyEditObj::read( bool forceRead ) {
		cfsec::ICFSecISOCcyObj* retval = getOrigAsISOCcy()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyEditObj::create() {
		cfsec::ICFSecISOCcyObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsISOCcy()->getSchema() )->getISOCcyTableObj()->createISOCcy( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecISOCcyEditObj* CFIntISOCcyEditObj::update() {
		getSchema()->getISOCcyTableObj()->updateISOCcy( this );
		return( NULL );
	}

	cfsec::ICFSecISOCcyEditObj* CFIntISOCcyEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getISOCcyTableObj()->deleteISOCcy( this );
		return( NULL );
	}

	cfsec::ICFSecISOCcyTableObj* CFIntISOCcyEditObj::getISOCcyTable() {
		return( orig->getSchema()->getISOCcyTableObj() );
	}

	cfsec::ICFSecISOCcyEditObj* CFIntISOCcyEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecISOCcyEditObj* CFIntISOCcyEditObj::getISOCcyEdit() {
		return( (cfsec::ICFSecISOCcyEditObj*)this );
	}

	cfsec::ICFSecISOCcyEditObj* CFIntISOCcyEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntISOCcyEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyEditObj::getOrigAsISOCcy() {
		return( dynamic_cast<cfsec::ICFSecISOCcyObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntISOCcyEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecISOCcyBuff* CFIntISOCcyEditObj::getBuff() {
		return( buff );
	}

	void CFIntISOCcyEditObj::setBuff( cfsec::CFSecISOCcyBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecISOCcyPKey* CFIntISOCcyEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntISOCcyEditObj::setPKey( cfsec::CFSecISOCcyPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntISOCcyEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntISOCcyEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int16_t CFIntISOCcyEditObj::getRequiredISOCcyId() {
		return( getPKey()->getRequiredISOCcyId() );
	}

	const int16_t* CFIntISOCcyEditObj::getRequiredISOCcyIdReference() {
		return( getPKey()->getRequiredISOCcyIdReference() );
	}

	const std::string& CFIntISOCcyEditObj::getRequiredISOCode() {
		return( getISOCcyBuff()->getRequiredISOCode() );
	}

	const std::string* CFIntISOCcyEditObj::getRequiredISOCodeReference() {
		return( getISOCcyBuff()->getRequiredISOCodeReference() );
	}

	void CFIntISOCcyEditObj::setRequiredISOCode( const std::string& value ) {
		if( getISOCcyBuff()->getRequiredISOCode() != value ) {
			getISOCcyEditBuff()->setRequiredISOCode( value );
		}
	}

	const std::string& CFIntISOCcyEditObj::getRequiredName() {
		return( getISOCcyBuff()->getRequiredName() );
	}

	const std::string* CFIntISOCcyEditObj::getRequiredNameReference() {
		return( getISOCcyBuff()->getRequiredNameReference() );
	}

	void CFIntISOCcyEditObj::setRequiredName( const std::string& value ) {
		if( getISOCcyBuff()->getRequiredName() != value ) {
			getISOCcyEditBuff()->setRequiredName( value );
		}
	}

	bool CFIntISOCcyEditObj::isOptionalUnitSymbolNull() {
		return( getISOCcyBuff()->isOptionalUnitSymbolNull() );
	}

	const std::string& CFIntISOCcyEditObj::getOptionalUnitSymbolValue() {
		return( getISOCcyBuff()->getOptionalUnitSymbolValue() );
	}

	const std::string* CFIntISOCcyEditObj::getOptionalUnitSymbolReference() {
		return( getISOCcyBuff()->getOptionalUnitSymbolReference() );
	}

	void CFIntISOCcyEditObj::setOptionalUnitSymbolNull() {
		if( ! getISOCcyBuff()->isOptionalUnitSymbolNull() ) {
			getISOCcyEditBuff()->setOptionalUnitSymbolNull();
		}
	}

	void CFIntISOCcyEditObj::setOptionalUnitSymbolValue( const std::string& value ) {
		if( getISOCcyBuff()->isOptionalUnitSymbolNull() ) {
			getISOCcyEditBuff()->setOptionalUnitSymbolValue( value );
		}
		else if( getISOCcyBuff()->getOptionalUnitSymbolValue() != value ) {
			getISOCcyEditBuff()->setOptionalUnitSymbolValue( value );
		}
	}

	const int16_t CFIntISOCcyEditObj::getRequiredPrecis() {
		return( getISOCcyBuff()->getRequiredPrecis() );
	}

	const int16_t* CFIntISOCcyEditObj::getRequiredPrecisReference() {
		return( getISOCcyBuff()->getRequiredPrecisReference() );
	}

	void CFIntISOCcyEditObj::setRequiredPrecis( const int16_t value ) {
		if( getISOCcyBuff()->getRequiredPrecis() != value ) {
			getISOCcyEditBuff()->setRequiredPrecis( value );
		}
	}

	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFIntISOCcyEditObj::getOptionalChildrenCtry( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryCcyObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsISOCcy()->getSchema() )->getISOCtryCcyTableObj()->readISOCtryCcyByCcyIdx( getPKey()->getRequiredISOCcyId(),
			forceRead );
		return( retval );
	}

	void CFIntISOCcyEditObj::copyPKeyToBuff() {
		cfsec::CFSecISOCcyPKey* tablePKey = getPKey();
		cfsec::CFSecISOCcyBuff* tableBuff = getISOCcyEditBuff();
		tableBuff->setRequiredISOCcyId( tablePKey->getRequiredISOCcyId() );
	}

	void CFIntISOCcyEditObj::copyBuffToPKey() {
		cfsec::CFSecISOCcyPKey* tablePKey = getPKey();
		cfsec::CFSecISOCcyBuff* tableBuff = getISOCcyBuff();
		tablePKey->setRequiredISOCcyId( tableBuff->getRequiredISOCcyId() );
	}

	void CFIntISOCcyEditObj::copyBuffToOrig() {
		cfsec::CFSecISOCcyBuff* origBuff = getOrigAsISOCcy()->getISOCcyEditBuff();
		cfsec::CFSecISOCcyBuff* myBuff = getISOCcyBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntISOCcyEditObj::copyOrigToBuff() {
		cfsec::CFSecISOCcyBuff* origBuff = getOrigAsISOCcy()->getISOCcyBuff();
		cfsec::CFSecISOCcyBuff* myBuff = getISOCcyEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
