// Description: C++18 edit object instance implementation for CFInt ISOLang.

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
#include <cfintobj/CFIntISOLangObj.hpp>
#include <cfintobj/CFIntISOLangEditObj.hpp>


namespace cfint {

	const std::string CFIntISOLangEditObj::CLASS_NAME( "CFIntISOLangEditObj" );

	CFIntISOLangEditObj::CFIntISOLangEditObj( cfsec::ICFSecISOLangObj* argOrig )
	: ICFIntISOLangEditObj(),
	  ICFSecISOLangEditObj()
	{
		static const std::string S_ProcName( "CFIntISOLangEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecISOLangBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecISOLangBuff*>( origBuff->clone() );
	}

	CFIntISOLangEditObj::~CFIntISOLangEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntISOLangEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntISOLangEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOLangBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOLangEditObj::getCreatedAt() {
		return( getISOLangBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntISOLangEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOLangBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOLangEditObj::getUpdatedAt() {
		return( getISOLangBuff()->getUpdatedAt() );
	}

	void CFIntISOLangEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getISOLangEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntISOLangEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOLangEditBuff()->setCreatedAt( value );
	}

	void CFIntISOLangEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getISOLangEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntISOLangEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOLangEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntISOLangEditObj::getClassCode() const {
		return( cfsec::CFSecISOLangBuff::CLASS_CODE );
	}

	bool CFIntISOLangEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntISOLangEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntISOLangEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntISOLangEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntISOLangEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntISOLangEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntISOLangEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntISOLangEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOLangId, CFIntISOLangEditObj::getRequiredISOLangId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6392Code, CFIntISOLangEditObj::getRequiredISO6392Code() ) );
		if( ! CFIntISOLangEditObj::isOptionalISO6391CodeNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_ISO6391Code, CFIntISOLangEditObj::getOptionalISO6391CodeValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EnglishName, CFIntISOLangEditObj::getRequiredEnglishName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntISOLangEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntISOLangEditObj::setRequiredRevision( int32_t value ) {
		getISOLangEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntISOLangEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredISO6392Code() );
		return( objName );
	}

	const std::string CFIntISOLangEditObj::getGenDefName() {
		return( cfsec::CFSecISOLangBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntISOLangEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOLangEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOLangEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntISOLangEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntISOLangEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntISOLangEditObj::getObjQualifiedName() {
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

	std::string CFIntISOLangEditObj::getObjFullName() {
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

	cfsec::ICFSecISOLangObj* CFIntISOLangEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecISOLangObj* retobj = getSchema()->getISOLangTableObj()->realizeISOLang( dynamic_cast<cfsec::ICFSecISOLangObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangEditObj::read( bool forceRead ) {
		cfsec::ICFSecISOLangObj* retval = getOrigAsISOLang()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangEditObj::create() {
		cfsec::ICFSecISOLangObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsISOLang()->getSchema() )->getISOLangTableObj()->createISOLang( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecISOLangEditObj* CFIntISOLangEditObj::update() {
		getSchema()->getISOLangTableObj()->updateISOLang( this );
		return( NULL );
	}

	cfsec::ICFSecISOLangEditObj* CFIntISOLangEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getISOLangTableObj()->deleteISOLang( this );
		return( NULL );
	}

	cfsec::ICFSecISOLangTableObj* CFIntISOLangEditObj::getISOLangTable() {
		return( orig->getSchema()->getISOLangTableObj() );
	}

	cfsec::ICFSecISOLangEditObj* CFIntISOLangEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecISOLangEditObj* CFIntISOLangEditObj::getISOLangEdit() {
		return( (cfsec::ICFSecISOLangEditObj*)this );
	}

	cfsec::ICFSecISOLangEditObj* CFIntISOLangEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntISOLangEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangEditObj::getOrigAsISOLang() {
		return( dynamic_cast<cfsec::ICFSecISOLangObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntISOLangEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecISOLangBuff* CFIntISOLangEditObj::getBuff() {
		return( buff );
	}

	void CFIntISOLangEditObj::setBuff( cfsec::CFSecISOLangBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecISOLangPKey* CFIntISOLangEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntISOLangEditObj::setPKey( cfsec::CFSecISOLangPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntISOLangEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntISOLangEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int16_t CFIntISOLangEditObj::getRequiredISOLangId() {
		return( getPKey()->getRequiredISOLangId() );
	}

	const int16_t* CFIntISOLangEditObj::getRequiredISOLangIdReference() {
		return( getPKey()->getRequiredISOLangIdReference() );
	}

	const std::string& CFIntISOLangEditObj::getRequiredISO6392Code() {
		return( getISOLangBuff()->getRequiredISO6392Code() );
	}

	const std::string* CFIntISOLangEditObj::getRequiredISO6392CodeReference() {
		return( getISOLangBuff()->getRequiredISO6392CodeReference() );
	}

	void CFIntISOLangEditObj::setRequiredISO6392Code( const std::string& value ) {
		if( getISOLangBuff()->getRequiredISO6392Code() != value ) {
			getISOLangEditBuff()->setRequiredISO6392Code( value );
		}
	}

	bool CFIntISOLangEditObj::isOptionalISO6391CodeNull() {
		return( getISOLangBuff()->isOptionalISO6391CodeNull() );
	}

	const std::string& CFIntISOLangEditObj::getOptionalISO6391CodeValue() {
		return( getISOLangBuff()->getOptionalISO6391CodeValue() );
	}

	const std::string* CFIntISOLangEditObj::getOptionalISO6391CodeReference() {
		return( getISOLangBuff()->getOptionalISO6391CodeReference() );
	}

	void CFIntISOLangEditObj::setOptionalISO6391CodeNull() {
		if( ! getISOLangBuff()->isOptionalISO6391CodeNull() ) {
			getISOLangEditBuff()->setOptionalISO6391CodeNull();
		}
	}

	void CFIntISOLangEditObj::setOptionalISO6391CodeValue( const std::string& value ) {
		if( getISOLangBuff()->isOptionalISO6391CodeNull() ) {
			getISOLangEditBuff()->setOptionalISO6391CodeValue( value );
		}
		else if( getISOLangBuff()->getOptionalISO6391CodeValue() != value ) {
			getISOLangEditBuff()->setOptionalISO6391CodeValue( value );
		}
	}

	const std::string& CFIntISOLangEditObj::getRequiredEnglishName() {
		return( getISOLangBuff()->getRequiredEnglishName() );
	}

	const std::string* CFIntISOLangEditObj::getRequiredEnglishNameReference() {
		return( getISOLangBuff()->getRequiredEnglishNameReference() );
	}

	void CFIntISOLangEditObj::setRequiredEnglishName( const std::string& value ) {
		if( getISOLangBuff()->getRequiredEnglishName() != value ) {
			getISOLangEditBuff()->setRequiredEnglishName( value );
		}
	}

	std::vector<cfsec::ICFSecISOCtryLangObj*> CFIntISOLangEditObj::getOptionalChildrenCtry( bool forceRead ) {
		std::vector<cfsec::ICFSecISOCtryLangObj*> retval;
		retval = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsISOLang()->getSchema() )->getISOCtryLangTableObj()->readISOCtryLangByLangIdx( getPKey()->getRequiredISOLangId(),
			forceRead );
		return( retval );
	}

	void CFIntISOLangEditObj::copyPKeyToBuff() {
		cfsec::CFSecISOLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOLangBuff* tableBuff = getISOLangEditBuff();
		tableBuff->setRequiredISOLangId( tablePKey->getRequiredISOLangId() );
	}

	void CFIntISOLangEditObj::copyBuffToPKey() {
		cfsec::CFSecISOLangPKey* tablePKey = getPKey();
		cfsec::CFSecISOLangBuff* tableBuff = getISOLangBuff();
		tablePKey->setRequiredISOLangId( tableBuff->getRequiredISOLangId() );
	}

	void CFIntISOLangEditObj::copyBuffToOrig() {
		cfsec::CFSecISOLangBuff* origBuff = getOrigAsISOLang()->getISOLangEditBuff();
		cfsec::CFSecISOLangBuff* myBuff = getISOLangBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntISOLangEditObj::copyOrigToBuff() {
		cfsec::CFSecISOLangBuff* origBuff = getOrigAsISOLang()->getISOLangBuff();
		cfsec::CFSecISOLangBuff* myBuff = getISOLangEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
