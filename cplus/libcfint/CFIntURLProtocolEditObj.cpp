// Description: C++18 edit object instance implementation for CFInt URLProtocol.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
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
#include <cfintobj/CFIntURLProtocolObj.hpp>
#include <cfintobj/CFIntURLProtocolEditObj.hpp>


namespace cfint {

	const std::string CFIntURLProtocolEditObj::CLASS_NAME( "CFIntURLProtocolEditObj" );

	CFIntURLProtocolEditObj::CFIntURLProtocolEditObj( cfint::ICFIntURLProtocolObj* argOrig )
	: ICFIntURLProtocolEditObj()
	{
		static const std::string S_ProcName( "CFIntURLProtocolEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfint::CFIntURLProtocolBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( origBuff->clone() );
	}

	CFIntURLProtocolEditObj::~CFIntURLProtocolEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntURLProtocolEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntURLProtocolEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getURLProtocolBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntURLProtocolEditObj::getCreatedAt() {
		return( getURLProtocolBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntURLProtocolEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getURLProtocolBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntURLProtocolEditObj::getUpdatedAt() {
		return( getURLProtocolBuff()->getUpdatedAt() );
	}

	void CFIntURLProtocolEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getURLProtocolEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntURLProtocolEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getURLProtocolEditBuff()->setCreatedAt( value );
	}

	void CFIntURLProtocolEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getURLProtocolEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntURLProtocolEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getURLProtocolEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntURLProtocolEditObj::getClassCode() const {
		return( cfint::CFIntURLProtocolBuff::CLASS_CODE );
	}

	bool CFIntURLProtocolEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntURLProtocolEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntURLProtocolEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_URLProtocolId( "URLProtocolId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		static const std::string S_IsSecure( "IsSecure" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntURLProtocolEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntURLProtocolEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntURLProtocolEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntURLProtocolEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntURLProtocolEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_URLProtocolId, CFIntURLProtocolEditObj::getRequiredURLProtocolId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntURLProtocolEditObj::getRequiredName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntURLProtocolEditObj::getRequiredDescription() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsSecure, CFIntURLProtocolEditObj::getRequiredIsSecure() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntURLProtocolEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntURLProtocolEditObj::setRequiredRevision( int32_t value ) {
		getURLProtocolEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntURLProtocolEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntURLProtocolEditObj::getGenDefName() {
		return( cfint::CFIntURLProtocolBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntURLProtocolEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntURLProtocolEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntURLProtocolEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntURLProtocolEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntURLProtocolEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntURLProtocolEditObj::getObjQualifiedName() {
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

	std::string CFIntURLProtocolEditObj::getObjFullName() {
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

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfint::ICFIntURLProtocolObj* retobj = getSchema()->getURLProtocolTableObj()->realizeURLProtocol( dynamic_cast<cfint::ICFIntURLProtocolObj*>( this ) );
		return( retobj );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolEditObj::read( bool forceRead ) {
		cfint::ICFIntURLProtocolObj* retval = getOrigAsURLProtocol()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolEditObj::create() {
		cfint::ICFIntURLProtocolObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsURLProtocol()->getSchema() )->getURLProtocolTableObj()->createURLProtocol( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfint::ICFIntURLProtocolEditObj* CFIntURLProtocolEditObj::update() {
		getSchema()->getURLProtocolTableObj()->updateURLProtocol( this );
		return( NULL );
	}

	cfint::ICFIntURLProtocolEditObj* CFIntURLProtocolEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getURLProtocolTableObj()->deleteURLProtocol( this );
		return( NULL );
	}

	cfint::ICFIntURLProtocolTableObj* CFIntURLProtocolEditObj::getURLProtocolTable() {
		return( orig->getSchema()->getURLProtocolTableObj() );
	}

	cfint::ICFIntURLProtocolEditObj* CFIntURLProtocolEditObj::getEdit() {
		return( this );
	}

	cfint::ICFIntURLProtocolEditObj* CFIntURLProtocolEditObj::getURLProtocolEdit() {
		return( (cfint::ICFIntURLProtocolEditObj*)this );
	}

	cfint::ICFIntURLProtocolEditObj* CFIntURLProtocolEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntURLProtocolEditObj::endEdit() {
		orig->endEdit();
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolEditObj::getOrig() {
		return( orig );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolEditObj::getOrigAsURLProtocol() {
		return( dynamic_cast<cfint::ICFIntURLProtocolObj*>( orig ) );
	}

	cfint::ICFIntSchemaObj* CFIntURLProtocolEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfint::CFIntURLProtocolBuff* CFIntURLProtocolEditObj::getBuff() {
		return( buff );
	}

	void CFIntURLProtocolEditObj::setBuff( cfint::CFIntURLProtocolBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfint::CFIntURLProtocolPKey* CFIntURLProtocolEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntURLProtocolEditObj::setPKey( cfint::CFIntURLProtocolPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntURLProtocolEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntURLProtocolEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int32_t CFIntURLProtocolEditObj::getRequiredURLProtocolId() {
		return( getPKey()->getRequiredURLProtocolId() );
	}

	const int32_t* CFIntURLProtocolEditObj::getRequiredURLProtocolIdReference() {
		return( getPKey()->getRequiredURLProtocolIdReference() );
	}

	const std::string& CFIntURLProtocolEditObj::getRequiredName() {
		return( getURLProtocolBuff()->getRequiredName() );
	}

	const std::string* CFIntURLProtocolEditObj::getRequiredNameReference() {
		return( getURLProtocolBuff()->getRequiredNameReference() );
	}

	void CFIntURLProtocolEditObj::setRequiredName( const std::string& value ) {
		if( getURLProtocolBuff()->getRequiredName() != value ) {
			getURLProtocolEditBuff()->setRequiredName( value );
		}
	}

	const std::string& CFIntURLProtocolEditObj::getRequiredDescription() {
		return( getURLProtocolBuff()->getRequiredDescription() );
	}

	const std::string* CFIntURLProtocolEditObj::getRequiredDescriptionReference() {
		return( getURLProtocolBuff()->getRequiredDescriptionReference() );
	}

	void CFIntURLProtocolEditObj::setRequiredDescription( const std::string& value ) {
		if( getURLProtocolBuff()->getRequiredDescription() != value ) {
			getURLProtocolEditBuff()->setRequiredDescription( value );
		}
	}

	const bool CFIntURLProtocolEditObj::getRequiredIsSecure() {
		return( getURLProtocolBuff()->getRequiredIsSecure() );
	}

	const bool* CFIntURLProtocolEditObj::getRequiredIsSecureReference() {
		return( getURLProtocolBuff()->getRequiredIsSecureReference() );
	}

	void CFIntURLProtocolEditObj::setRequiredIsSecure( const bool value ) {
		if( getURLProtocolBuff()->getRequiredIsSecure() != value ) {
			getURLProtocolEditBuff()->setRequiredIsSecure( value );
		}
	}

	void CFIntURLProtocolEditObj::copyPKeyToBuff() {
		cfint::CFIntURLProtocolPKey* tablePKey = getPKey();
		cfint::CFIntURLProtocolBuff* tableBuff = getURLProtocolEditBuff();
		tableBuff->setRequiredURLProtocolId( tablePKey->getRequiredURLProtocolId() );
	}

	void CFIntURLProtocolEditObj::copyBuffToPKey() {
		cfint::CFIntURLProtocolPKey* tablePKey = getPKey();
		cfint::CFIntURLProtocolBuff* tableBuff = getURLProtocolBuff();
		tablePKey->setRequiredURLProtocolId( tableBuff->getRequiredURLProtocolId() );
	}

	void CFIntURLProtocolEditObj::copyBuffToOrig() {
		cfint::CFIntURLProtocolBuff* origBuff = getOrigAsURLProtocol()->getURLProtocolEditBuff();
		cfint::CFIntURLProtocolBuff* myBuff = getURLProtocolBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntURLProtocolEditObj::copyOrigToBuff() {
		cfint::CFIntURLProtocolBuff* origBuff = getOrigAsURLProtocol()->getURLProtocolBuff();
		cfint::CFIntURLProtocolBuff* myBuff = getURLProtocolEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
