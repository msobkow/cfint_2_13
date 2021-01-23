// Description: C++18 base object instance implementation for CFInt URLProtocol.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
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
#include <cfintobj/CFIntURLProtocolObj.hpp>

namespace cfint {

	const std::string CFIntURLProtocolObj::CLASS_NAME( "CFIntURLProtocolObj" );
	const classcode_t CFIntURLProtocolObj::CLASS_CODE = 0xa109L;

	int32_t CFIntURLProtocolObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int32_t CFIntURLProtocolObj::getRequiredURLProtocolId() {
		return( getPKey()->getRequiredURLProtocolId() );
	}

	const int32_t* CFIntURLProtocolObj::getRequiredURLProtocolIdReference() {
		return( getPKey()->getRequiredURLProtocolIdReference() );
	}

	const std::string& CFIntURLProtocolObj::getRequiredName() {
		return( getURLProtocolBuff()->getRequiredName() );
	}

	const std::string* CFIntURLProtocolObj::getRequiredNameReference() {
		return( getURLProtocolBuff()->getRequiredNameReference() );
	}

	const std::string& CFIntURLProtocolObj::getRequiredDescription() {
		return( getURLProtocolBuff()->getRequiredDescription() );
	}

	const std::string* CFIntURLProtocolObj::getRequiredDescriptionReference() {
		return( getURLProtocolBuff()->getRequiredDescriptionReference() );
	}

	const bool CFIntURLProtocolObj::getRequiredIsSecure() {
		return( getURLProtocolBuff()->getRequiredIsSecure() );
	}

	const bool* CFIntURLProtocolObj::getRequiredIsSecureReference() {
		return( getURLProtocolBuff()->getRequiredIsSecureReference() );
	}


	CFIntURLProtocolObj::CFIntURLProtocolObj()
	: ICFIntURLProtocolObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntURLProtocolObj::CFIntURLProtocolObj( cfint::ICFIntSchemaObj* argSchema )
	: ICFIntURLProtocolObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntURLProtocolObj::~CFIntURLProtocolObj() {
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

	cfint::CFIntURLProtocolBuff* CFIntURLProtocolObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfint::CFIntURLProtocolBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredURLProtocolId() );
			}
		}
		return( buff );
	}

	void CFIntURLProtocolObj::setBuff( cfint::CFIntURLProtocolBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntURLProtocolObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntURLProtocolObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntURLProtocolObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntURLProtocolObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntURLProtocolObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntURLProtocolObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntURLProtocolObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntURLProtocolObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntURLProtocolObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntURLProtocolObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_URLProtocolId, CFIntURLProtocolObj::getRequiredURLProtocolId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntURLProtocolObj::getRequiredName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntURLProtocolObj::getRequiredDescription() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsSecure, CFIntURLProtocolObj::getRequiredIsSecure() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntURLProtocolObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntURLProtocolObj::getGenDefName() {
		return( cfint::CFIntURLProtocolBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntURLProtocolObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntURLProtocolObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntURLProtocolObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntURLProtocolObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntURLProtocolObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntURLProtocolObj::getObjQualifiedName() {
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

	std::string CFIntURLProtocolObj::getObjFullName() {
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

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolObj::realize() {
		cfint::ICFIntURLProtocolObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getURLProtocolTableObj()->realizeURLProtocol(
			(cfint::ICFIntURLProtocolObj*)this );
		return( dynamic_cast<cfint::ICFIntURLProtocolObj*>( retobj ) );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolObj::read( bool forceRead ) {
		cfint::ICFIntURLProtocolObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getURLProtocolTableObj()->readURLProtocolByIdIdx( getURLProtocolBuff()->getRequiredURLProtocolId(), forceRead );
		return( dynamic_cast<cfint::ICFIntURLProtocolObj*>( retobj ) );
	}

	cfint::ICFIntURLProtocolTableObj* CFIntURLProtocolObj::getURLProtocolTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getURLProtocolTableObj() );
	}

	cfint::ICFIntSchemaObj* CFIntURLProtocolObj::getSchema() {
		return( schema );
	}

	void CFIntURLProtocolObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = value;
	}

	cfint::CFIntURLProtocolPKey* CFIntURLProtocolObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfint::CFIntURLProtocolPKey();
		}
		return( pKey );
	}

	void CFIntURLProtocolObj::setPKey( cfint::CFIntURLProtocolPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfint::CFIntURLProtocolPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntURLProtocolObj::getIsNew() {
		return( isNew );
	}

	void CFIntURLProtocolObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfint::ICFIntURLProtocolEditObj* CFIntURLProtocolObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfint::ICFIntURLProtocolObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getURLProtocolTableObj()->lockURLProtocol( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getURLProtocolTableObj()->newEditInstance( this );
		return( dynamic_cast<cfint::ICFIntURLProtocolEditObj*>( edit ) );
	}

	void CFIntURLProtocolObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfint::ICFIntURLProtocolEditObj* CFIntURLProtocolObj::getEdit() {
		return( edit );
	}

	cfint::ICFIntURLProtocolEditObj* CFIntURLProtocolObj::getURLProtocolEdit() {
		return( dynamic_cast<cfint::ICFIntURLProtocolEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntURLProtocolObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getURLProtocolBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntURLProtocolObj::getCreatedAt() {
		return( getURLProtocolBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntURLProtocolObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getURLProtocolBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntURLProtocolObj::getUpdatedAt() {
		return( getURLProtocolBuff()->getUpdatedAt() );
	}

	void CFIntURLProtocolObj::copyPKeyToBuff() {
		cfint::CFIntURLProtocolPKey* tablePKey = getPKey();
		cfint::CFIntURLProtocolBuff* tableBuff = getURLProtocolEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredURLProtocolId( tablePKey->getRequiredURLProtocolId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntURLProtocolObj::copyBuffToPKey() {
		cfint::CFIntURLProtocolPKey* tablePKey = getPKey();
		cfint::CFIntURLProtocolBuff* tableBuff = getURLProtocolBuff();
		tablePKey->setRequiredURLProtocolId( tableBuff->getRequiredURLProtocolId() );
	}

}
