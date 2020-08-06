// Description: C++18 base object instance implementation for CFInt SecGroupForm.

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
#include <cfintobj/CFIntSecGroupFormObj.hpp>

namespace cfint {

	const std::string CFIntSecGroupFormObj::CLASS_NAME( "CFIntSecGroupFormObj" );
	const classcode_t CFIntSecGroupFormObj::CLASS_CODE = 0xa00dL;

	int32_t CFIntSecGroupFormObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntSecGroupFormObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFIntSecGroupFormObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int64_t CFIntSecGroupFormObj::getRequiredSecGroupFormId() {
		return( getPKey()->getRequiredSecGroupFormId() );
	}

	const int64_t* CFIntSecGroupFormObj::getRequiredSecGroupFormIdReference() {
		return( getPKey()->getRequiredSecGroupFormIdReference() );
	}

	const int32_t CFIntSecGroupFormObj::getRequiredSecGroupId() {
		return( getSecGroupFormBuff()->getRequiredSecGroupId() );
	}

	const int32_t* CFIntSecGroupFormObj::getRequiredSecGroupIdReference() {
		return( getSecGroupFormBuff()->getRequiredSecGroupIdReference() );
	}

	const int32_t CFIntSecGroupFormObj::getRequiredSecAppId() {
		return( getSecGroupFormBuff()->getRequiredSecAppId() );
	}

	const int32_t* CFIntSecGroupFormObj::getRequiredSecAppIdReference() {
		return( getSecGroupFormBuff()->getRequiredSecAppIdReference() );
	}

	const int32_t CFIntSecGroupFormObj::getRequiredSecFormId() {
		return( getSecGroupFormBuff()->getRequiredSecFormId() );
	}

	const int32_t* CFIntSecGroupFormObj::getRequiredSecFormIdReference() {
		return( getSecGroupFormBuff()->getRequiredSecFormIdReference() );
	}


	cfsec::ICFSecClusterObj* CFIntSecGroupFormObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupFormObj::getRequiredContainerGroup( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGroupFormBuff()->getRequiredSecGroupId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecAppObj* CFIntSecGroupFormObj::getRequiredParentApp( bool forceRead ) {
		cfsec::ICFSecSecAppObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecAppTableObj()->readSecAppByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGroupFormBuff()->getRequiredSecAppId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecFormObj* CFIntSecGroupFormObj::getRequiredParentForm( bool forceRead ) {
		cfsec::ICFSecSecFormObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecFormTableObj()->readSecFormByIdIdx( getPKey()->getRequiredClusterId(),
					getSecGroupFormBuff()->getRequiredSecFormId(), forceRead );
		}
		return( retobj );
	}

	CFIntSecGroupFormObj::CFIntSecGroupFormObj()
	: ICFIntSecGroupFormObj(),
	  ICFSecSecGroupFormObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecGroupFormObj::CFIntSecGroupFormObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntSecGroupFormObj(),
	  ICFSecSecGroupFormObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecGroupFormObj::~CFIntSecGroupFormObj() {
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

	cfsec::CFSecSecGroupFormBuff* CFIntSecGroupFormObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecGroupFormBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroupForm()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredClusterId(),
						getPKey()->getRequiredSecGroupFormId() );
			}
		}
		return( buff );
	}

	void CFIntSecGroupFormObj::setBuff( cfsec::CFSecSecGroupFormBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntSecGroupFormObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSecGroupFormObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntSecGroupFormObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecGroupFormObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecGroupFormObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGroupFormId( "SecGroupFormId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_SecAppId( "SecAppId" );
		static const std::string S_SecFormId( "SecFormId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecGroupFormObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecGroupFormObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecGroupFormObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecGroupFormObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecGroupFormObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSecGroupFormObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SecGroupFormId, CFIntSecGroupFormObj::getRequiredSecGroupFormId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, CFIntSecGroupFormObj::getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, CFIntSecGroupFormObj::getRequiredSecAppId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecFormId, CFIntSecGroupFormObj::getRequiredSecFormId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntSecGroupFormObj::getObjName() {
		std::string objName( CLASS_NAME );
		int64_t val = getRequiredSecGroupFormId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFIntSecGroupFormObj::getGenDefName() {
		return( cfsec::CFSecSecGroupFormBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupFormObj::getScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupFormObj::getObjScope() {
		cfsec::ICFSecSecGroupObj* scope = getRequiredContainerGroup();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupFormObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecGroupFormObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupFormObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecGroupFormObj::getObjQualifiedName() {
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

	std::string CFIntSecGroupFormObj::getObjFullName() {
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

	cfsec::ICFSecSecGroupFormObj* CFIntSecGroupFormObj::realize() {
		cfsec::ICFSecSecGroupFormObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupFormTableObj()->realizeSecGroupForm(
			(cfsec::ICFSecSecGroupFormObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( retobj ) );
	}

	cfsec::ICFSecSecGroupFormObj* CFIntSecGroupFormObj::read( bool forceRead ) {
		cfsec::ICFSecSecGroupFormObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupFormTableObj()->readSecGroupFormByIdIdx( getSecGroupFormBuff()->getRequiredClusterId(),
		getSecGroupFormBuff()->getRequiredSecGroupFormId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecGroupFormObj*>( retobj ) );
	}

	cfsec::ICFSecSecGroupFormTableObj* CFIntSecGroupFormObj::getSecGroupFormTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupFormTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntSecGroupFormObj::getSchema() {
		return( schema );
	}

	void CFIntSecGroupFormObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecGroupFormPKey* CFIntSecGroupFormObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecGroupFormPKey();
		}
		return( pKey );
	}

	void CFIntSecGroupFormObj::setPKey( cfsec::CFSecSecGroupFormPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecGroupFormPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntSecGroupFormObj::getIsNew() {
		return( isNew );
	}

	void CFIntSecGroupFormObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecGroupFormEditObj* CFIntSecGroupFormObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecGroupFormObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupFormTableObj()->lockSecGroupForm( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupFormTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecGroupFormEditObj*>( edit ) );
	}

	void CFIntSecGroupFormObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecGroupFormEditObj* CFIntSecGroupFormObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecGroupFormEditObj* CFIntSecGroupFormObj::getSecGroupFormEdit() {
		return( dynamic_cast<cfsec::ICFSecSecGroupFormEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGroupFormObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGroupFormBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGroupFormObj::getCreatedAt() {
		return( getSecGroupFormBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGroupFormObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGroupFormBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGroupFormObj::getUpdatedAt() {
		return( getSecGroupFormBuff()->getUpdatedAt() );
	}

	void CFIntSecGroupFormObj::copyPKeyToBuff() {
		cfsec::CFSecSecGroupFormPKey* tablePKey = getPKey();
		cfsec::CFSecSecGroupFormBuff* tableBuff = getSecGroupFormEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
			tableBuff->setRequiredSecGroupFormId( tablePKey->getRequiredSecGroupFormId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntSecGroupFormObj::copyBuffToPKey() {
		cfsec::CFSecSecGroupFormPKey* tablePKey = getPKey();
		cfsec::CFSecSecGroupFormBuff* tableBuff = getSecGroupFormBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecGroupFormId( tableBuff->getRequiredSecGroupFormId() );
	}

}
