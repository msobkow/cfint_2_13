// Description: C++18 edit object instance implementation for CFInt ISOCtry.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintobj/CFIntISOCtryObj.hpp>
#include <cfintobj/CFIntISOCtryEditObj.hpp>


namespace cfint {

	const std::string CFIntISOCtryEditObj::CLASS_NAME( "CFIntISOCtryEditObj" );

	CFIntISOCtryEditObj::CFIntISOCtryEditObj( cfsec::ICFSecISOCtryObj* argOrig )
	: ICFIntISOCtryEditObj(),
	  ICFSecISOCtryEditObj()
	{
		static const std::string S_ProcName( "CFIntISOCtryEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecISOCtryBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecISOCtryBuff*>( origBuff->clone() );
	}

	CFIntISOCtryEditObj::~CFIntISOCtryEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntISOCtryEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCtryEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCtryEditObj::getCreatedAt() {
		return( getISOCtryBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntISOCtryEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOCtryBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOCtryEditObj::getUpdatedAt() {
		return( getISOCtryBuff()->getUpdatedAt() );
	}

	void CFIntISOCtryEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getISOCtryEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntISOCtryEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCtryEditBuff()->setCreatedAt( value );
	}

	void CFIntISOCtryEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getISOCtryEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntISOCtryEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOCtryEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntISOCtryEditObj::getClassCode() const {
		return( cfsec::CFSecISOCtryBuff::CLASS_CODE );
	}

	bool CFIntISOCtryEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOCtryBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntISOCtryEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntISOCtryEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntISOCtryEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntISOCtryEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntISOCtryEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntISOCtryEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntISOCtryEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOCtryId, CFIntISOCtryEditObj::getRequiredISOCtryId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISOCode, CFIntISOCtryEditObj::getRequiredISOCode() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntISOCtryEditObj::getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntISOCtryEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntISOCtryEditObj::setRequiredRevision( int32_t value ) {
		getISOCtryEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntISOCtryEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredISOCode() );
		return( objName );
	}

	const std::string CFIntISOCtryEditObj::getGenDefName() {
		return( cfsec::CFSecISOCtryBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntISOCtryEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntISOCtryEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntISOCtryEditObj::getObjQualifiedName() {
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

	std::string CFIntISOCtryEditObj::getObjFullName() {
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

	cfsec::ICFSecISOCtryObj* CFIntISOCtryEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecISOCtryObj* retobj = getSchema()->getISOCtryTableObj()->realizeISOCtry( dynamic_cast<cfsec::ICFSecISOCtryObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecISOCtryObj* CFIntISOCtryEditObj::read( bool forceRead ) {
		cfsec::ICFSecISOCtryObj* retval = getOrigAsISOCtry()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecISOCtryObj* CFIntISOCtryEditObj::create() {
		cfsec::ICFSecISOCtryObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsISOCtry()->getSchema() )->getISOCtryTableObj()->createISOCtry( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecISOCtryEditObj* CFIntISOCtryEditObj::update() {
		getSchema()->getISOCtryTableObj()->updateISOCtry( this );
		return( NULL );
	}

	cfsec::ICFSecISOCtryEditObj* CFIntISOCtryEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getISOCtryTableObj()->deleteISOCtry( this );
		return( NULL );
	}

	cfsec::ICFSecISOCtryTableObj* CFIntISOCtryEditObj::getISOCtryTable() {
		return( orig->getSchema()->getISOCtryTableObj() );
	}

	cfsec::ICFSecISOCtryEditObj* CFIntISOCtryEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecISOCtryEditObj* CFIntISOCtryEditObj::getISOCtryEdit() {
		return( (cfsec::ICFSecISOCtryEditObj*)this );
	}

	cfsec::ICFSecISOCtryEditObj* CFIntISOCtryEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntISOCtryEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecISOCtryObj* CFIntISOCtryEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecISOCtryObj* CFIntISOCtryEditObj::getOrigAsISOCtry() {
		return( dynamic_cast<cfsec::ICFSecISOCtryObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntISOCtryEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecISOCtryBuff* CFIntISOCtryEditObj::getBuff() {
		return( buff );
	}

	void CFIntISOCtryEditObj::setBuff( cfsec::CFSecISOCtryBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecISOCtryPKey* CFIntISOCtryEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntISOCtryEditObj::setPKey( cfsec::CFSecISOCtryPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntISOCtryEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntISOCtryEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int16_t CFIntISOCtryEditObj::getRequiredISOCtryId() {
		return( getPKey()->getRequiredISOCtryId() );
	}

	const int16_t* CFIntISOCtryEditObj::getRequiredISOCtryIdReference() {
		return( getPKey()->getRequiredISOCtryIdReference() );
	}

	const std::string& CFIntISOCtryEditObj::getRequiredISOCode() {
		return( getISOCtryBuff()->getRequiredISOCode() );
	}

	const std::string* CFIntISOCtryEditObj::getRequiredISOCodeReference() {
		return( getISOCtryBuff()->getRequiredISOCodeReference() );
	}

	void CFIntISOCtryEditObj::setRequiredISOCode( const std::string& value ) {
		if( getISOCtryBuff()->getRequiredISOCode() != value ) {
			getISOCtryEditBuff()->setRequiredISOCode( value );
		}
	}

	const std::string& CFIntISOCtryEditObj::getRequiredName() {
		return( getISOCtryBuff()->getRequiredName() );
	}

	const std::string* CFIntISOCtryEditObj::getRequiredNameReference() {
		return( getISOCtryBuff()->getRequiredNameReference() );
	}

	void CFIntISOCtryEditObj::setRequiredName( const std::string& value ) {
		if( getISOCtryBuff()->getRequiredName() != value ) {
			getISOCtryEditBuff()->setRequiredName( value );
		}
	}

	std::vector<cfsec::ICFSecISOCtryCcyObj*> CFIntISOCtryEditObj::getOptionalComponentsCcy( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryCcyObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsISOCtry()->getSchema() )->getISOCtryCcyTableObj()->readISOCtryCcyByCtryIdx( getPKey()->getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecISOCtryLangObj*> CFIntISOCtryEditObj::getOptionalComponentsLang( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryLangObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsISOCtry()->getSchema() )->getISOCtryLangTableObj()->readISOCtryLangByCtryIdx( getPKey()->getRequiredISOCtryId(),
			forceRead );
		return( retval );
	}

	void CFIntISOCtryEditObj::copyPKeyToBuff() {
		cfsec::CFSecISOCtryPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryBuff* tableBuff = getISOCtryEditBuff();
		tableBuff->setRequiredISOCtryId( tablePKey->getRequiredISOCtryId() );
	}

	void CFIntISOCtryEditObj::copyBuffToPKey() {
		cfsec::CFSecISOCtryPKey* tablePKey = getPKey();
		cfsec::CFSecISOCtryBuff* tableBuff = getISOCtryBuff();
		tablePKey->setRequiredISOCtryId( tableBuff->getRequiredISOCtryId() );
	}

	void CFIntISOCtryEditObj::copyBuffToOrig() {
		cfsec::CFSecISOCtryBuff* origBuff = getOrigAsISOCtry()->getISOCtryEditBuff();
		cfsec::CFSecISOCtryBuff* myBuff = getISOCtryBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntISOCtryEditObj::copyOrigToBuff() {
		cfsec::CFSecISOCtryBuff* origBuff = getOrigAsISOCtry()->getISOCtryBuff();
		cfsec::CFSecISOCtryBuff* myBuff = getISOCtryEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
