// Description: C++18 edit object instance implementation for CFInt ISOTZone.

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
#include <cfintobj/CFIntISOTZoneObj.hpp>
#include <cfintobj/CFIntISOTZoneEditObj.hpp>


namespace cfint {

	const std::string CFIntISOTZoneEditObj::CLASS_NAME( "CFIntISOTZoneEditObj" );

	CFIntISOTZoneEditObj::CFIntISOTZoneEditObj( cfsec::ICFSecISOTZoneObj* argOrig )
	: ICFIntISOTZoneEditObj(),
	  ICFSecISOTZoneEditObj()
	{
		static const std::string S_ProcName( "CFIntISOTZoneEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecISOTZoneBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( origBuff->clone() );
	}

	CFIntISOTZoneEditObj::~CFIntISOTZoneEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntISOTZoneEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntISOTZoneEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOTZoneBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOTZoneEditObj::getCreatedAt() {
		return( getISOTZoneBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntISOTZoneEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getISOTZoneBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntISOTZoneEditObj::getUpdatedAt() {
		return( getISOTZoneBuff()->getUpdatedAt() );
	}

	void CFIntISOTZoneEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getISOTZoneEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntISOTZoneEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOTZoneEditBuff()->setCreatedAt( value );
	}

	void CFIntISOTZoneEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getISOTZoneEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntISOTZoneEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getISOTZoneEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntISOTZoneEditObj::getClassCode() const {
		return( cfsec::CFSecISOTZoneBuff::CLASS_CODE );
	}

	bool CFIntISOTZoneEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntISOTZoneEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntISOTZoneEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntISOTZoneEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntISOTZoneEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntISOTZoneEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntISOTZoneEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntISOTZoneEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_ISOTZoneId, CFIntISOTZoneEditObj::getRequiredISOTZoneId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Iso8601, CFIntISOTZoneEditObj::getRequiredIso8601() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_TZName, CFIntISOTZoneEditObj::getRequiredTZName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZHourOffset, CFIntISOTZoneEditObj::getRequiredTZHourOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_TZMinOffset, CFIntISOTZoneEditObj::getRequiredTZMinOffset() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntISOTZoneEditObj::getRequiredDescription() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_Visible, CFIntISOTZoneEditObj::getRequiredVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntISOTZoneEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntISOTZoneEditObj::setRequiredRevision( int32_t value ) {
		getISOTZoneEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntISOTZoneEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredTZName() );
		return( objName );
	}

	const std::string CFIntISOTZoneEditObj::getGenDefName() {
		return( cfsec::CFSecISOTZoneBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntISOTZoneEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOTZoneEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntISOTZoneEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntISOTZoneEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntISOTZoneEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntISOTZoneEditObj::getObjQualifiedName() {
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

	std::string CFIntISOTZoneEditObj::getObjFullName() {
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

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecISOTZoneObj* retobj = getSchema()->getISOTZoneTableObj()->realizeISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneEditObj::read( bool forceRead ) {
		cfsec::ICFSecISOTZoneObj* retval = getOrigAsISOTZone()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneEditObj::create() {
		cfsec::ICFSecISOTZoneObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsISOTZone()->getSchema() )->getISOTZoneTableObj()->createISOTZone( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecISOTZoneEditObj* CFIntISOTZoneEditObj::update() {
		getSchema()->getISOTZoneTableObj()->updateISOTZone( this );
		return( NULL );
	}

	cfsec::ICFSecISOTZoneEditObj* CFIntISOTZoneEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getISOTZoneTableObj()->deleteISOTZone( this );
		return( NULL );
	}

	cfsec::ICFSecISOTZoneTableObj* CFIntISOTZoneEditObj::getISOTZoneTable() {
		return( orig->getSchema()->getISOTZoneTableObj() );
	}

	cfsec::ICFSecISOTZoneEditObj* CFIntISOTZoneEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecISOTZoneEditObj* CFIntISOTZoneEditObj::getISOTZoneEdit() {
		return( (cfsec::ICFSecISOTZoneEditObj*)this );
	}

	cfsec::ICFSecISOTZoneEditObj* CFIntISOTZoneEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntISOTZoneEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneEditObj::getOrigAsISOTZone() {
		return( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntISOTZoneEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecISOTZoneBuff* CFIntISOTZoneEditObj::getBuff() {
		return( buff );
	}

	void CFIntISOTZoneEditObj::setBuff( cfsec::CFSecISOTZoneBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecISOTZonePKey* CFIntISOTZoneEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntISOTZoneEditObj::setPKey( cfsec::CFSecISOTZonePKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntISOTZoneEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntISOTZoneEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int16_t CFIntISOTZoneEditObj::getRequiredISOTZoneId() {
		return( getPKey()->getRequiredISOTZoneId() );
	}

	const int16_t* CFIntISOTZoneEditObj::getRequiredISOTZoneIdReference() {
		return( getPKey()->getRequiredISOTZoneIdReference() );
	}

	const std::string& CFIntISOTZoneEditObj::getRequiredIso8601() {
		return( getISOTZoneBuff()->getRequiredIso8601() );
	}

	const std::string* CFIntISOTZoneEditObj::getRequiredIso8601Reference() {
		return( getISOTZoneBuff()->getRequiredIso8601Reference() );
	}

	void CFIntISOTZoneEditObj::setRequiredIso8601( const std::string& value ) {
		if( getISOTZoneBuff()->getRequiredIso8601() != value ) {
			getISOTZoneEditBuff()->setRequiredIso8601( value );
		}
	}

	const std::string& CFIntISOTZoneEditObj::getRequiredTZName() {
		return( getISOTZoneBuff()->getRequiredTZName() );
	}

	const std::string* CFIntISOTZoneEditObj::getRequiredTZNameReference() {
		return( getISOTZoneBuff()->getRequiredTZNameReference() );
	}

	void CFIntISOTZoneEditObj::setRequiredTZName( const std::string& value ) {
		if( getISOTZoneBuff()->getRequiredTZName() != value ) {
			getISOTZoneEditBuff()->setRequiredTZName( value );
		}
	}

	const int16_t CFIntISOTZoneEditObj::getRequiredTZHourOffset() {
		return( getISOTZoneBuff()->getRequiredTZHourOffset() );
	}

	const int16_t* CFIntISOTZoneEditObj::getRequiredTZHourOffsetReference() {
		return( getISOTZoneBuff()->getRequiredTZHourOffsetReference() );
	}

	void CFIntISOTZoneEditObj::setRequiredTZHourOffset( const int16_t value ) {
		if( getISOTZoneBuff()->getRequiredTZHourOffset() != value ) {
			getISOTZoneEditBuff()->setRequiredTZHourOffset( value );
		}
	}

	const int16_t CFIntISOTZoneEditObj::getRequiredTZMinOffset() {
		return( getISOTZoneBuff()->getRequiredTZMinOffset() );
	}

	const int16_t* CFIntISOTZoneEditObj::getRequiredTZMinOffsetReference() {
		return( getISOTZoneBuff()->getRequiredTZMinOffsetReference() );
	}

	void CFIntISOTZoneEditObj::setRequiredTZMinOffset( const int16_t value ) {
		if( getISOTZoneBuff()->getRequiredTZMinOffset() != value ) {
			getISOTZoneEditBuff()->setRequiredTZMinOffset( value );
		}
	}

	const std::string& CFIntISOTZoneEditObj::getRequiredDescription() {
		return( getISOTZoneBuff()->getRequiredDescription() );
	}

	const std::string* CFIntISOTZoneEditObj::getRequiredDescriptionReference() {
		return( getISOTZoneBuff()->getRequiredDescriptionReference() );
	}

	void CFIntISOTZoneEditObj::setRequiredDescription( const std::string& value ) {
		if( getISOTZoneBuff()->getRequiredDescription() != value ) {
			getISOTZoneEditBuff()->setRequiredDescription( value );
		}
	}

	const bool CFIntISOTZoneEditObj::getRequiredVisible() {
		return( getISOTZoneBuff()->getRequiredVisible() );
	}

	const bool* CFIntISOTZoneEditObj::getRequiredVisibleReference() {
		return( getISOTZoneBuff()->getRequiredVisibleReference() );
	}

	void CFIntISOTZoneEditObj::setRequiredVisible( const bool value ) {
		if( getISOTZoneBuff()->getRequiredVisible() != value ) {
			getISOTZoneEditBuff()->setRequiredVisible( value );
		}
	}

	void CFIntISOTZoneEditObj::copyPKeyToBuff() {
		cfsec::CFSecISOTZonePKey* tablePKey = getPKey();
		cfsec::CFSecISOTZoneBuff* tableBuff = getISOTZoneEditBuff();
		tableBuff->setRequiredISOTZoneId( tablePKey->getRequiredISOTZoneId() );
	}

	void CFIntISOTZoneEditObj::copyBuffToPKey() {
		cfsec::CFSecISOTZonePKey* tablePKey = getPKey();
		cfsec::CFSecISOTZoneBuff* tableBuff = getISOTZoneBuff();
		tablePKey->setRequiredISOTZoneId( tableBuff->getRequiredISOTZoneId() );
	}

	void CFIntISOTZoneEditObj::copyBuffToOrig() {
		cfsec::CFSecISOTZoneBuff* origBuff = getOrigAsISOTZone()->getISOTZoneEditBuff();
		cfsec::CFSecISOTZoneBuff* myBuff = getISOTZoneBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntISOTZoneEditObj::copyOrigToBuff() {
		cfsec::CFSecISOTZoneBuff* origBuff = getOrigAsISOTZone()->getISOTZoneBuff();
		cfsec::CFSecISOTZoneBuff* myBuff = getISOTZoneEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
