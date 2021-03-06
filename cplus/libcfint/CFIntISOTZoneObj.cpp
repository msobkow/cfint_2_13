// Description: C++18 base object instance implementation for CFInt ISOTZone.

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
#include <cfintobj/CFIntISOTZoneObj.hpp>

namespace cfint {

	const std::string CFIntISOTZoneObj::CLASS_NAME( "CFIntISOTZoneObj" );
	const classcode_t CFIntISOTZoneObj::CLASS_CODE = 0xa008L;

	int32_t CFIntISOTZoneObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int16_t CFIntISOTZoneObj::getRequiredISOTZoneId() {
		return( getPKey()->getRequiredISOTZoneId() );
	}

	const int16_t* CFIntISOTZoneObj::getRequiredISOTZoneIdReference() {
		return( getPKey()->getRequiredISOTZoneIdReference() );
	}

	const std::string& CFIntISOTZoneObj::getRequiredIso8601() {
		return( getISOTZoneBuff()->getRequiredIso8601() );
	}

	const std::string* CFIntISOTZoneObj::getRequiredIso8601Reference() {
		return( getISOTZoneBuff()->getRequiredIso8601Reference() );
	}

	const std::string& CFIntISOTZoneObj::getRequiredTZName() {
		return( getISOTZoneBuff()->getRequiredTZName() );
	}

	const std::string* CFIntISOTZoneObj::getRequiredTZNameReference() {
		return( getISOTZoneBuff()->getRequiredTZNameReference() );
	}

	const int16_t CFIntISOTZoneObj::getRequiredTZHourOffset() {
		return( getISOTZoneBuff()->getRequiredTZHourOffset() );
	}

	const int16_t* CFIntISOTZoneObj::getRequiredTZHourOffsetReference() {
		return( getISOTZoneBuff()->getRequiredTZHourOffsetReference() );
	}

	const int16_t CFIntISOTZoneObj::getRequiredTZMinOffset() {
		return( getISOTZoneBuff()->getRequiredTZMinOffset() );
	}

	const int16_t* CFIntISOTZoneObj::getRequiredTZMinOffsetReference() {
		return( getISOTZoneBuff()->getRequiredTZMinOffsetReference() );
	}

	const std::string& CFIntISOTZoneObj::getRequiredDescription() {
		return( getISOTZoneBuff()->getRequiredDescription() );
	}

	const std::string* CFIntISOTZoneObj::getRequiredDescriptionReference() {
		return( getISOTZoneBuff()->getRequiredDescriptionReference() );
	}

	const bool CFIntISOTZoneObj::getRequiredVisible() {
		return( getISOTZoneBuff()->getRequiredVisible() );
	}

	const bool* CFIntISOTZoneObj::getRequiredVisibleReference() {
		return( getISOTZoneBuff()->getRequiredVisibleReference() );
	}


	CFIntISOTZoneObj::CFIntISOTZoneObj()
	: ICFIntISOTZoneObj(),
	  ICFSecISOTZoneObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOTZoneObj::CFIntISOTZoneObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntISOTZoneObj(),
	  ICFSecISOTZoneObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntISOTZoneObj::~CFIntISOTZoneObj() {
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

	cfsec::CFSecISOTZoneBuff* CFIntISOTZoneObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecISOTZoneBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredISOTZoneId() );
			}
		}
		return( buff );
	}

	void CFIntISOTZoneObj::setBuff( cfsec::CFSecISOTZoneBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntISOTZoneObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntISOTZoneObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntISOTZoneObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntISOTZoneObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntISOTZoneObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ISOTZoneId( "ISOTZoneId" );
		static const std::string S_Iso8601( "Iso8601" );
		static const std::string S_TZName( "TZName" );
		static const std::string S_TZHourOffset( "TZHourOffset" );
		static const std::string S_TZMinOffset( "TZMinOffset" );
		static const std::string S_Description( "Description" );
		static const std::string S_Visible( "Visible" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntISOTZoneObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntISOTZoneObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntISOTZoneObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntISOTZoneObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntISOTZoneObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOTZoneId, CFIntISOTZoneObj::getRequiredISOTZoneId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Iso8601, CFIntISOTZoneObj::getRequiredIso8601() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_TZName, CFIntISOTZoneObj::getRequiredTZName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZHourOffset, CFIntISOTZoneObj::getRequiredTZHourOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZMinOffset, CFIntISOTZoneObj::getRequiredTZMinOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntISOTZoneObj::getRequiredDescription() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_Visible, CFIntISOTZoneObj::getRequiredVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntISOTZoneObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredTZName() );
		return( objName );
	}

	const std::string CFIntISOTZoneObj::getGenDefName() {
		return( cfsec::CFSecISOTZoneBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntISOTZoneObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOTZoneObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOTZoneObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntISOTZoneObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntISOTZoneObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntISOTZoneObj::getObjQualifiedName() {
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

	std::string CFIntISOTZoneObj::getObjFullName() {
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

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneObj::realize() {
		cfsec::ICFSecISOTZoneObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOTZoneTableObj()->realizeISOTZone(
			(cfsec::ICFSecISOTZoneObj*)this );
		return( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( retobj ) );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneObj::read( bool forceRead ) {
		cfsec::ICFSecISOTZoneObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOTZoneTableObj()->readISOTZoneByIdIdx( getISOTZoneBuff()->getRequiredISOTZoneId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( retobj ) );
	}

	cfsec::ICFSecISOTZoneTableObj* CFIntISOTZoneObj::getISOTZoneTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOTZoneTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntISOTZoneObj::getSchema() {
		return( schema );
	}

	void CFIntISOTZoneObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecISOTZonePKey* CFIntISOTZoneObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecISOTZonePKey();
		}
		return( pKey );
	}

	void CFIntISOTZoneObj::setPKey( cfsec::CFSecISOTZonePKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecISOTZonePKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntISOTZoneObj::getIsNew() {
		return( isNew );
	}

	void CFIntISOTZoneObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecISOTZoneEditObj* CFIntISOTZoneObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecISOTZoneObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOTZoneTableObj()->lockISOTZone( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getISOTZoneTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( edit ) );
	}

	void CFIntISOTZoneObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecISOTZoneEditObj* CFIntISOTZoneObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecISOTZoneEditObj* CFIntISOTZoneObj::getISOTZoneEdit() {
		return( dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntISOTZoneObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOTZoneBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOTZoneObj::getCreatedAt() {
		return( getISOTZoneBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntISOTZoneObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOTZoneBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOTZoneObj::getUpdatedAt() {
		return( getISOTZoneBuff()->getUpdatedAt() );
	}

	void CFIntISOTZoneObj::copyPKeyToBuff() {
		cfsec::CFSecISOTZonePKey* tablePKey = getPKey();
		cfsec::CFSecISOTZoneBuff* tableBuff = getISOTZoneEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredISOTZoneId( tablePKey->getRequiredISOTZoneId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntISOTZoneObj::copyBuffToPKey() {
		cfsec::CFSecISOTZonePKey* tablePKey = getPKey();
		cfsec::CFSecISOTZoneBuff* tableBuff = getISOTZoneBuff();
		tablePKey->setRequiredISOTZoneId( tableBuff->getRequiredISOTZoneId() );
	}

}
