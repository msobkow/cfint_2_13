// Description: C++18 edit object instance implementation for CFInt MimeType.

/*
 *	org.msscf.msscf.CFInt
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
#include <cfintobj/CFIntMimeTypeObj.hpp>
#include <cfintobj/CFIntMimeTypeEditObj.hpp>


namespace cfint {

	const std::string CFIntMimeTypeEditObj::CLASS_NAME( "CFIntMimeTypeEditObj" );

	CFIntMimeTypeEditObj::CFIntMimeTypeEditObj( cfint::ICFIntMimeTypeObj* argOrig )
	: ICFIntMimeTypeEditObj()
	{
		static const std::string S_ProcName( "CFIntMimeTypeEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfint::CFIntMimeTypeBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( origBuff->clone() );
	}

	CFIntMimeTypeEditObj::~CFIntMimeTypeEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntMimeTypeEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntMimeTypeEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getMimeTypeBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntMimeTypeEditObj::getCreatedAt() {
		return( getMimeTypeBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntMimeTypeEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getMimeTypeBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntMimeTypeEditObj::getUpdatedAt() {
		return( getMimeTypeBuff()->getUpdatedAt() );
	}

	void CFIntMimeTypeEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getMimeTypeEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntMimeTypeEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getMimeTypeEditBuff()->setCreatedAt( value );
	}

	void CFIntMimeTypeEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getMimeTypeEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntMimeTypeEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getMimeTypeEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntMimeTypeEditObj::getClassCode() const {
		return( cfint::CFIntMimeTypeBuff::CLASS_CODE );
	}

	bool CFIntMimeTypeEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntMimeTypeEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMimeTypeEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_MimeTypeId( "MimeTypeId" );
		static const std::string S_Name( "Name" );
		static const std::string S_FileTypes( "FileTypes" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntMimeTypeEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntMimeTypeEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntMimeTypeEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntMimeTypeEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntMimeTypeEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_MimeTypeId, CFIntMimeTypeEditObj::getRequiredMimeTypeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntMimeTypeEditObj::getRequiredName() ) );
		if( ! CFIntMimeTypeEditObj::isOptionalFileTypesNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_FileTypes, CFIntMimeTypeEditObj::getOptionalFileTypesValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntMimeTypeEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntMimeTypeEditObj::setRequiredRevision( int32_t value ) {
		getMimeTypeEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntMimeTypeEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntMimeTypeEditObj::getGenDefName() {
		return( cfint::CFIntMimeTypeBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntMimeTypeEditObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntMimeTypeEditObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntMimeTypeEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntMimeTypeEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntMimeTypeEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntMimeTypeEditObj::getObjQualifiedName() {
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

	std::string CFIntMimeTypeEditObj::getObjFullName() {
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

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfint::ICFIntMimeTypeObj* retobj = getSchema()->getMimeTypeTableObj()->realizeMimeType( dynamic_cast<cfint::ICFIntMimeTypeObj*>( this ) );
		return( retobj );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeEditObj::read( bool forceRead ) {
		cfint::ICFIntMimeTypeObj* retval = getOrigAsMimeType()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeEditObj::create() {
		cfint::ICFIntMimeTypeObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsMimeType()->getSchema() )->getMimeTypeTableObj()->createMimeType( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfint::ICFIntMimeTypeEditObj* CFIntMimeTypeEditObj::update() {
		getSchema()->getMimeTypeTableObj()->updateMimeType( this );
		return( NULL );
	}

	cfint::ICFIntMimeTypeEditObj* CFIntMimeTypeEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getMimeTypeTableObj()->deleteMimeType( this );
		return( NULL );
	}

	cfint::ICFIntMimeTypeTableObj* CFIntMimeTypeEditObj::getMimeTypeTable() {
		return( orig->getSchema()->getMimeTypeTableObj() );
	}

	cfint::ICFIntMimeTypeEditObj* CFIntMimeTypeEditObj::getEdit() {
		return( this );
	}

	cfint::ICFIntMimeTypeEditObj* CFIntMimeTypeEditObj::getMimeTypeEdit() {
		return( (cfint::ICFIntMimeTypeEditObj*)this );
	}

	cfint::ICFIntMimeTypeEditObj* CFIntMimeTypeEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntMimeTypeEditObj::endEdit() {
		orig->endEdit();
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeEditObj::getOrig() {
		return( orig );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeEditObj::getOrigAsMimeType() {
		return( dynamic_cast<cfint::ICFIntMimeTypeObj*>( orig ) );
	}

	cfint::ICFIntSchemaObj* CFIntMimeTypeEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfint::CFIntMimeTypeBuff* CFIntMimeTypeEditObj::getBuff() {
		return( buff );
	}

	void CFIntMimeTypeEditObj::setBuff( cfint::CFIntMimeTypeBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfint::CFIntMimeTypePKey* CFIntMimeTypeEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntMimeTypeEditObj::setPKey( cfint::CFIntMimeTypePKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntMimeTypeEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntMimeTypeEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int32_t CFIntMimeTypeEditObj::getRequiredMimeTypeId() {
		return( getPKey()->getRequiredMimeTypeId() );
	}

	const int32_t* CFIntMimeTypeEditObj::getRequiredMimeTypeIdReference() {
		return( getPKey()->getRequiredMimeTypeIdReference() );
	}

	const std::string& CFIntMimeTypeEditObj::getRequiredName() {
		return( getMimeTypeBuff()->getRequiredName() );
	}

	const std::string* CFIntMimeTypeEditObj::getRequiredNameReference() {
		return( getMimeTypeBuff()->getRequiredNameReference() );
	}

	void CFIntMimeTypeEditObj::setRequiredName( const std::string& value ) {
		if( getMimeTypeBuff()->getRequiredName() != value ) {
			getMimeTypeEditBuff()->setRequiredName( value );
		}
	}

	bool CFIntMimeTypeEditObj::isOptionalFileTypesNull() {
		return( getMimeTypeBuff()->isOptionalFileTypesNull() );
	}

	const std::string& CFIntMimeTypeEditObj::getOptionalFileTypesValue() {
		return( getMimeTypeBuff()->getOptionalFileTypesValue() );
	}

	const std::string* CFIntMimeTypeEditObj::getOptionalFileTypesReference() {
		return( getMimeTypeBuff()->getOptionalFileTypesReference() );
	}

	void CFIntMimeTypeEditObj::setOptionalFileTypesNull() {
		if( ! getMimeTypeBuff()->isOptionalFileTypesNull() ) {
			getMimeTypeEditBuff()->setOptionalFileTypesNull();
		}
	}

	void CFIntMimeTypeEditObj::setOptionalFileTypesValue( const std::string& value ) {
		if( getMimeTypeBuff()->isOptionalFileTypesNull() ) {
			getMimeTypeEditBuff()->setOptionalFileTypesValue( value );
		}
		else if( getMimeTypeBuff()->getOptionalFileTypesValue() != value ) {
			getMimeTypeEditBuff()->setOptionalFileTypesValue( value );
		}
	}

	void CFIntMimeTypeEditObj::copyPKeyToBuff() {
		cfint::CFIntMimeTypePKey* tablePKey = getPKey();
		cfint::CFIntMimeTypeBuff* tableBuff = getMimeTypeEditBuff();
		tableBuff->setRequiredMimeTypeId( tablePKey->getRequiredMimeTypeId() );
	}

	void CFIntMimeTypeEditObj::copyBuffToPKey() {
		cfint::CFIntMimeTypePKey* tablePKey = getPKey();
		cfint::CFIntMimeTypeBuff* tableBuff = getMimeTypeBuff();
		tablePKey->setRequiredMimeTypeId( tableBuff->getRequiredMimeTypeId() );
	}

	void CFIntMimeTypeEditObj::copyBuffToOrig() {
		cfint::CFIntMimeTypeBuff* origBuff = getOrigAsMimeType()->getMimeTypeEditBuff();
		cfint::CFIntMimeTypeBuff* myBuff = getMimeTypeBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntMimeTypeEditObj::copyOrigToBuff() {
		cfint::CFIntMimeTypeBuff* origBuff = getOrigAsMimeType()->getMimeTypeBuff();
		cfint::CFIntMimeTypeBuff* myBuff = getMimeTypeEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
