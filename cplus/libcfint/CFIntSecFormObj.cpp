// Description: C++18 base object instance implementation for CFInt SecForm.

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
#include <cfintobj/CFIntSecFormObj.hpp>

namespace cfint {

	const std::string CFIntSecFormObj::CLASS_NAME( "CFIntSecFormObj" );
	const classcode_t CFIntSecFormObj::CLASS_CODE = 0xa00bL;

	int32_t CFIntSecFormObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntSecFormObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFIntSecFormObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int32_t CFIntSecFormObj::getRequiredSecFormId() {
		return( getPKey()->getRequiredSecFormId() );
	}

	const int32_t* CFIntSecFormObj::getRequiredSecFormIdReference() {
		return( getPKey()->getRequiredSecFormIdReference() );
	}

	const int32_t CFIntSecFormObj::getRequiredSecAppId() {
		return( getSecFormBuff()->getRequiredSecAppId() );
	}

	const int32_t* CFIntSecFormObj::getRequiredSecAppIdReference() {
		return( getSecFormBuff()->getRequiredSecAppIdReference() );
	}

	const std::string& CFIntSecFormObj::getRequiredJEEServletMapName() {
		return( getSecFormBuff()->getRequiredJEEServletMapName() );
	}

	const std::string* CFIntSecFormObj::getRequiredJEEServletMapNameReference() {
		return( getSecFormBuff()->getRequiredJEEServletMapNameReference() );
	}


	cfsec::ICFSecClusterObj* CFIntSecFormObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecAppObj* CFIntSecFormObj::getRequiredContainerApplication( bool forceRead ) {
		cfsec::ICFSecSecAppObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecAppTableObj()->readSecAppByIdIdx( getPKey()->getRequiredClusterId(),
					getSecFormBuff()->getRequiredSecAppId(), forceRead );
		}
		return( retobj );
	}

	CFIntSecFormObj::CFIntSecFormObj()
	: ICFIntSecFormObj(),
	  ICFSecSecFormObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecFormObj::CFIntSecFormObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntSecFormObj(),
	  ICFSecSecFormObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecFormObj::~CFIntSecFormObj() {
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

	cfsec::CFSecSecFormBuff* CFIntSecFormObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecFormBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredClusterId(),
						getPKey()->getRequiredSecFormId() );
			}
		}
		return( buff );
	}

	void CFIntSecFormObj::setBuff( cfsec::CFSecSecFormBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntSecFormObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSecFormObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntSecFormObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecFormObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecFormObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecFormId( "SecFormId" );
		static const std::string S_SecAppId( "SecAppId" );
		static const std::string S_JEEServletMapName( "JEEServletMapName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecFormObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecFormObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecFormObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecFormObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecFormObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSecFormObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecFormId, CFIntSecFormObj::getRequiredSecFormId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, CFIntSecFormObj::getRequiredSecAppId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_JEEServletMapName, CFIntSecFormObj::getRequiredJEEServletMapName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntSecFormObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredJEEServletMapName() );
		return( objName );
	}

	const std::string CFIntSecFormObj::getGenDefName() {
		return( cfsec::CFSecSecFormBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecFormObj::getScope() {
		cfsec::ICFSecSecAppObj* scope = getRequiredContainerApplication();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecFormObj::getObjScope() {
		cfsec::ICFSecSecAppObj* scope = getRequiredContainerApplication();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecFormObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecFormObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecFormObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecFormObj::getObjQualifiedName() {
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

	std::string CFIntSecFormObj::getObjFullName() {
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

	cfsec::ICFSecSecFormObj* CFIntSecFormObj::realize() {
		cfsec::ICFSecSecFormObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecFormTableObj()->realizeSecForm(
			(cfsec::ICFSecSecFormObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecFormObj*>( retobj ) );
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormObj::read( bool forceRead ) {
		cfsec::ICFSecSecFormObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecFormTableObj()->readSecFormByIdIdx( getSecFormBuff()->getRequiredClusterId(),
		getSecFormBuff()->getRequiredSecFormId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecFormObj*>( retobj ) );
	}

	cfsec::ICFSecSecFormTableObj* CFIntSecFormObj::getSecFormTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecFormTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntSecFormObj::getSchema() {
		return( schema );
	}

	void CFIntSecFormObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecFormPKey* CFIntSecFormObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecFormPKey();
		}
		return( pKey );
	}

	void CFIntSecFormObj::setPKey( cfsec::CFSecSecFormPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecFormPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntSecFormObj::getIsNew() {
		return( isNew );
	}

	void CFIntSecFormObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecFormEditObj* CFIntSecFormObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecFormObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecFormTableObj()->lockSecForm( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecFormTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecFormEditObj*>( edit ) );
	}

	void CFIntSecFormObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecFormEditObj* CFIntSecFormObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecFormEditObj* CFIntSecFormObj::getSecFormEdit() {
		return( dynamic_cast<cfsec::ICFSecSecFormEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntSecFormObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecFormBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecFormObj::getCreatedAt() {
		return( getSecFormBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecFormObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecFormBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecFormObj::getUpdatedAt() {
		return( getSecFormBuff()->getUpdatedAt() );
	}

	void CFIntSecFormObj::copyPKeyToBuff() {
		cfsec::CFSecSecFormPKey* tablePKey = getPKey();
		cfsec::CFSecSecFormBuff* tableBuff = getSecFormEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
			tableBuff->setRequiredSecFormId( tablePKey->getRequiredSecFormId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntSecFormObj::copyBuffToPKey() {
		cfsec::CFSecSecFormPKey* tablePKey = getPKey();
		cfsec::CFSecSecFormBuff* tableBuff = getSecFormBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecFormId( tableBuff->getRequiredSecFormId() );
	}

}
