// Description: C++18 edit object instance implementation for CFInt SecForm.

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
#include <cfintobj/CFIntSecFormObj.hpp>
#include <cfintobj/CFIntSecFormEditObj.hpp>


namespace cfint {

	const std::string CFIntSecFormEditObj::CLASS_NAME( "CFIntSecFormEditObj" );

	CFIntSecFormEditObj::CFIntSecFormEditObj( cfsec::ICFSecSecFormObj* argOrig )
	: ICFIntSecFormEditObj(),
	  ICFSecSecFormEditObj()
	{
		static const std::string S_ProcName( "CFIntSecFormEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecFormBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( origBuff->clone() );
	}

	CFIntSecFormEditObj::~CFIntSecFormEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntSecFormEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntSecFormEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecFormBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecFormEditObj::getCreatedAt() {
		return( getSecFormBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecFormEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecFormBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecFormEditObj::getUpdatedAt() {
		return( getSecFormBuff()->getUpdatedAt() );
	}

	void CFIntSecFormEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getSecFormEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecFormEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecFormEditBuff()->setCreatedAt( value );
	}

	void CFIntSecFormEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getSecFormEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntSecFormEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getSecFormEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntSecFormEditObj::getClassCode() const {
		return( cfsec::CFSecSecFormBuff::CLASS_CODE );
	}

	bool CFIntSecFormEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecFormEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecFormEditObj" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecFormEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecFormEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecFormEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecFormEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecFormEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSecFormEditObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecFormId, CFIntSecFormEditObj::getRequiredSecFormId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecAppId, CFIntSecFormEditObj::getRequiredSecAppId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_JEEServletMapName, CFIntSecFormEditObj::getRequiredJEEServletMapName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntSecFormEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntSecFormEditObj::setRequiredRevision( int32_t value ) {
		getSecFormEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntSecFormEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredJEEServletMapName() );
		return( objName );
	}

	const std::string CFIntSecFormEditObj::getGenDefName() {
		return( cfsec::CFSecSecFormBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecFormEditObj::getScope() {
		cfsec::ICFSecSecAppObj* scope = getRequiredContainerApplication();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecFormEditObj::getObjScope() {
		cfsec::ICFSecSecAppObj* scope = getRequiredContainerApplication();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecFormEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecFormEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecFormEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecFormEditObj::getObjQualifiedName() {
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

	std::string CFIntSecFormEditObj::getObjFullName() {
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

	cfsec::ICFSecSecFormObj* CFIntSecFormEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecFormObj* retobj = getSchema()->getSecFormTableObj()->realizeSecForm( dynamic_cast<cfsec::ICFSecSecFormObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecFormObj* retval = getOrigAsSecForm()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormEditObj::create() {
		cfsec::ICFSecSecFormObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecForm()->getSchema() )->getSecFormTableObj()->createSecForm( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecFormEditObj* CFIntSecFormEditObj::update() {
		getSchema()->getSecFormTableObj()->updateSecForm( this );
		return( NULL );
	}

	cfsec::ICFSecSecFormEditObj* CFIntSecFormEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecFormTableObj()->deleteSecForm( this );
		return( NULL );
	}

	cfsec::ICFSecSecFormTableObj* CFIntSecFormEditObj::getSecFormTable() {
		return( orig->getSchema()->getSecFormTableObj() );
	}

	cfsec::ICFSecSecFormEditObj* CFIntSecFormEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecFormEditObj* CFIntSecFormEditObj::getSecFormEdit() {
		return( (cfsec::ICFSecSecFormEditObj*)this );
	}

	cfsec::ICFSecSecFormEditObj* CFIntSecFormEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntSecFormEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormEditObj::getOrigAsSecForm() {
		return( dynamic_cast<cfsec::ICFSecSecFormObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntSecFormEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecFormBuff* CFIntSecFormEditObj::getBuff() {
		return( buff );
	}

	void CFIntSecFormEditObj::setBuff( cfsec::CFSecSecFormBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecFormPKey* CFIntSecFormEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntSecFormEditObj::setPKey( cfsec::CFSecSecFormPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntSecFormEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntSecFormEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntSecFormEditObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFIntSecFormEditObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int32_t CFIntSecFormEditObj::getRequiredSecFormId() {
		return( getPKey()->getRequiredSecFormId() );
	}

	const int32_t* CFIntSecFormEditObj::getRequiredSecFormIdReference() {
		return( getPKey()->getRequiredSecFormIdReference() );
	}

	const int32_t CFIntSecFormEditObj::getRequiredSecAppId() {
		return( getSecFormBuff()->getRequiredSecAppId() );
	}

	const int32_t* CFIntSecFormEditObj::getRequiredSecAppIdReference() {
		return( getSecFormBuff()->getRequiredSecAppIdReference() );
	}

	const std::string& CFIntSecFormEditObj::getRequiredJEEServletMapName() {
		return( getSecFormBuff()->getRequiredJEEServletMapName() );
	}

	const std::string* CFIntSecFormEditObj::getRequiredJEEServletMapNameReference() {
		return( getSecFormBuff()->getRequiredJEEServletMapNameReference() );
	}

	void CFIntSecFormEditObj::setRequiredJEEServletMapName( const std::string& value ) {
		if( getSecFormBuff()->getRequiredJEEServletMapName() != value ) {
			getSecFormEditBuff()->setRequiredJEEServletMapName( value );
		}
	}

	cfsec::ICFSecClusterObj* CFIntSecFormEditObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecForm()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFIntSecFormEditObj::setRequiredOwnerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredId() );
				getSecFormEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	cfsec::ICFSecSecAppObj* CFIntSecFormEditObj::getRequiredContainerApplication( bool forceRead ) {
		cfsec::ICFSecSecAppObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecForm()->getSchema() )->getSecAppTableObj()->readSecAppByIdIdx( getPKey()->getRequiredClusterId(),
					getSecFormBuff()->getRequiredSecAppId() );
		}
		return( retobj );
	}

	void CFIntSecFormEditObj::setRequiredContainerApplication( cfsec::ICFSecSecAppObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredClusterId() );
				getSecFormEditBuff()->setRequiredClusterId( value->getRequiredClusterId() );
				getSecFormEditBuff()->setRequiredSecAppId( value->getRequiredSecAppId() );
			}
		}

	void CFIntSecFormEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecFormPKey* tablePKey = getPKey();
		cfsec::CFSecSecFormBuff* tableBuff = getSecFormEditBuff();
		tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
		tableBuff->setRequiredSecFormId( tablePKey->getRequiredSecFormId() );
	}

	void CFIntSecFormEditObj::copyBuffToPKey() {
		cfsec::CFSecSecFormPKey* tablePKey = getPKey();
		cfsec::CFSecSecFormBuff* tableBuff = getSecFormBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecFormId( tableBuff->getRequiredSecFormId() );
	}

	void CFIntSecFormEditObj::copyBuffToOrig() {
		cfsec::CFSecSecFormBuff* origBuff = getOrigAsSecForm()->getSecFormEditBuff();
		cfsec::CFSecSecFormBuff* myBuff = getSecFormBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntSecFormEditObj::copyOrigToBuff() {
		cfsec::CFSecSecFormBuff* origBuff = getOrigAsSecForm()->getSecFormBuff();
		cfsec::CFSecSecFormBuff* myBuff = getSecFormEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
