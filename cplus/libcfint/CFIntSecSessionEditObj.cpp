// Description: C++18 edit object instance implementation for CFInt SecSession.

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
#include <cfintobj/CFIntSecSessionObj.hpp>
#include <cfintobj/CFIntSecSessionEditObj.hpp>


namespace cfint {

	const std::string CFIntSecSessionEditObj::CLASS_NAME( "CFIntSecSessionEditObj" );

	CFIntSecSessionEditObj::CFIntSecSessionEditObj( cfsec::ICFSecSecSessionObj* argOrig )
	: ICFIntSecSessionEditObj(),
	  ICFSecSecSessionEditObj()
	{
		static const std::string S_ProcName( "CFIntSecSessionEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSecSessionBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( origBuff->clone() );
	}

	CFIntSecSessionEditObj::~CFIntSecSessionEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntSecSessionEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSecSessionEditObj::getClassCode() const {
		return( cfsec::CFSecSecSessionBuff::CLASS_CODE );
	}

	bool CFIntSecSessionEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecSessionEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecSessionEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_SecSessionId( "SecSessionId" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_SecDevName( "SecDevName" );
		static const std::string S_Start( "Start" );
		static const std::string S_Finish( "Finish" );
		static const std::string S_SecProxyId( "SecProxyId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecSessionEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecSessionId, CFIntSecSessionEditObj::getRequiredSecSessionId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFIntSecSessionEditObj::getRequiredSecUserId() ) );
		if( ! CFIntSecSessionEditObj::isOptionalSecDevNameNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_SecDevName, CFIntSecSessionEditObj::getOptionalSecDevNameValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredTimestamp( &S_Space, S_Start, CFIntSecSessionEditObj::getRequiredStart() ) );
		if( ! CFIntSecSessionEditObj::isOptionalFinishNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredTimestamp( &S_Space, S_Finish, CFIntSecSessionEditObj::getOptionalFinishValue() ) );
		}
		if( ! CFIntSecSessionEditObj::isOptionalSecProxyIdNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecProxyId, CFIntSecSessionEditObj::getOptionalSecProxyIdValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntSecSessionEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntSecSessionEditObj::setRequiredRevision( int32_t value ) {
		getSecSessionEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntSecSessionEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		const uuid_ptr_t val = getRequiredSecSessionId();
		objName = cflib::CFLibXmlUtil::formatUuid( val );
		return( objName );
	}

	const std::string CFIntSecSessionEditObj::getGenDefName() {
		return( cfsec::CFSecSecSessionBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecSessionEditObj::getScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecSessionEditObj::getObjScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecSessionEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecSessionEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecSessionEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecSessionEditObj::getObjQualifiedName() {
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

	std::string CFIntSecSessionEditObj::getObjFullName() {
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

	cfsec::ICFSecSecSessionObj* CFIntSecSessionEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSecSessionObj* retobj = getSchema()->getSecSessionTableObj()->realizeSecSession( dynamic_cast<cfsec::ICFSecSecSessionObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSecSessionObj* CFIntSecSessionEditObj::read( bool forceRead ) {
		cfsec::ICFSecSecSessionObj* retval = getOrigAsSecSession()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSecSessionObj* CFIntSecSessionEditObj::create() {
		cfsec::ICFSecSecSessionObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecSession()->getSchema() )->getSecSessionTableObj()->createSecSession( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSecSessionEditObj* CFIntSecSessionEditObj::update() {
		getSchema()->getSecSessionTableObj()->updateSecSession( this );
		return( NULL );
	}

	cfsec::ICFSecSecSessionEditObj* CFIntSecSessionEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSecSessionTableObj()->deleteSecSession( this );
		return( NULL );
	}

	cfsec::ICFSecSecSessionTableObj* CFIntSecSessionEditObj::getSecSessionTable() {
		return( orig->getSchema()->getSecSessionTableObj() );
	}

	cfsec::ICFSecSecSessionEditObj* CFIntSecSessionEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSecSessionEditObj* CFIntSecSessionEditObj::getSecSessionEdit() {
		return( (cfsec::ICFSecSecSessionEditObj*)this );
	}

	cfsec::ICFSecSecSessionEditObj* CFIntSecSessionEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntSecSessionEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSecSessionObj* CFIntSecSessionEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSecSessionObj* CFIntSecSessionEditObj::getOrigAsSecSession() {
		return( dynamic_cast<cfsec::ICFSecSecSessionObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntSecSessionEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSecSessionBuff* CFIntSecSessionEditObj::getBuff() {
		return( buff );
	}

	void CFIntSecSessionEditObj::setBuff( cfsec::CFSecSecSessionBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSecSessionPKey* CFIntSecSessionEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntSecSessionEditObj::setPKey( cfsec::CFSecSecSessionPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntSecSessionEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntSecSessionEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const uuid_ptr_t CFIntSecSessionEditObj::getRequiredSecSessionId() {
		return( getPKey()->getRequiredSecSessionId() );
	}

	const uuid_ptr_t CFIntSecSessionEditObj::getRequiredSecSessionIdReference() {
		return( getPKey()->getRequiredSecSessionIdReference() );
	}

	const uuid_ptr_t CFIntSecSessionEditObj::getRequiredSecUserId() {
		return( getSecSessionBuff()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFIntSecSessionEditObj::getRequiredSecUserIdReference() {
		return( getSecSessionBuff()->getRequiredSecUserIdReference() );
	}

	bool CFIntSecSessionEditObj::isOptionalSecDevNameNull() {
		return( getSecSessionBuff()->isOptionalSecDevNameNull() );
	}

	const std::string& CFIntSecSessionEditObj::getOptionalSecDevNameValue() {
		return( getSecSessionBuff()->getOptionalSecDevNameValue() );
	}

	const std::string* CFIntSecSessionEditObj::getOptionalSecDevNameReference() {
		return( getSecSessionBuff()->getOptionalSecDevNameReference() );
	}

	void CFIntSecSessionEditObj::setOptionalSecDevNameNull() {
		if( ! getSecSessionBuff()->isOptionalSecDevNameNull() ) {
			getSecSessionEditBuff()->setOptionalSecDevNameNull();
		}
	}

	void CFIntSecSessionEditObj::setOptionalSecDevNameValue( const std::string& value ) {
		if( getSecSessionBuff()->isOptionalSecDevNameNull() ) {
			getSecSessionEditBuff()->setOptionalSecDevNameValue( value );
		}
		else if( getSecSessionBuff()->getOptionalSecDevNameValue() != value ) {
			getSecSessionEditBuff()->setOptionalSecDevNameValue( value );
		}
	}

	const std::chrono::system_clock::time_point& CFIntSecSessionEditObj::getRequiredStart() {
		return( getSecSessionBuff()->getRequiredStart() );
	}

	const std::chrono::system_clock::time_point* CFIntSecSessionEditObj::getRequiredStartReference() {
		return( getSecSessionBuff()->getRequiredStartReference() );
	}

	void CFIntSecSessionEditObj::setRequiredStart( const std::chrono::system_clock::time_point& value ) {
		if( getSecSessionBuff()->getRequiredStart() != value ) {
			getSecSessionEditBuff()->setRequiredStart( value );
		}
	}

	bool CFIntSecSessionEditObj::isOptionalFinishNull() {
		return( getSecSessionBuff()->isOptionalFinishNull() );
	}

	const std::chrono::system_clock::time_point& CFIntSecSessionEditObj::getOptionalFinishValue() {
		return( getSecSessionBuff()->getOptionalFinishValue() );
	}

	const std::chrono::system_clock::time_point* CFIntSecSessionEditObj::getOptionalFinishReference() {
		return( getSecSessionBuff()->getOptionalFinishReference() );
	}

	void CFIntSecSessionEditObj::setOptionalFinishNull() {
		if( ! getSecSessionBuff()->isOptionalFinishNull() ) {
			getSecSessionEditBuff()->setOptionalFinishNull();
		}
	}

	void CFIntSecSessionEditObj::setOptionalFinishValue( const std::chrono::system_clock::time_point& value ) {
		if( getSecSessionBuff()->isOptionalFinishNull() ) {
			getSecSessionEditBuff()->setOptionalFinishValue( value );
		}
		else if( getSecSessionBuff()->getOptionalFinishValue() != value ) {
			getSecSessionEditBuff()->setOptionalFinishValue( value );
		}
	}

	bool CFIntSecSessionEditObj::isOptionalSecProxyIdNull() {
		return( getSecSessionBuff()->isOptionalSecProxyIdNull() );
	}

	const uuid_ptr_t CFIntSecSessionEditObj::getOptionalSecProxyIdValue() {
		return( getSecSessionBuff()->getOptionalSecProxyIdValue() );
	}

	const uuid_ptr_t CFIntSecSessionEditObj::getOptionalSecProxyIdReference() {
		return( getSecSessionBuff()->getOptionalSecProxyIdReference() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecSessionEditObj::getRequiredContainerSecUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecSession()->getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecSessionBuff()->getRequiredSecUserId() );
		}
		return( retobj );
	}

	void CFIntSecSessionEditObj::setRequiredContainerSecUser( cfsec::ICFSecSecUserObj* value ) {
			
			if( value != NULL ) {
				getSecSessionEditBuff()->setRequiredSecUserId( value->getRequiredSecUserId() );
			}
		}

	cfsec::ICFSecSecUserObj* CFIntSecSessionEditObj::getRequiredParentSecProxy( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;

			if( getSecSessionBuff()->isOptionalSecProxyIdNull() ) {
				anyMissing = true;
			}		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSecSession()->getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecSessionBuff()->getOptionalSecProxyIdValue() );
		}
		return( retobj );
	}

	void CFIntSecSessionEditObj::setRequiredParentSecProxy( cfsec::ICFSecSecUserObj* value ) {
			
			if( value != NULL ) {
				getSecSessionEditBuff()->setOptionalSecProxyIdValue( value->getRequiredSecUserId() );
			}
			else {
				getSecSessionEditBuff()->setOptionalSecProxyIdNull();
			}
		}

	void CFIntSecSessionEditObj::copyPKeyToBuff() {
		cfsec::CFSecSecSessionPKey* tablePKey = getPKey();
		cfsec::CFSecSecSessionBuff* tableBuff = getSecSessionEditBuff();
		tableBuff->setRequiredSecSessionId( tablePKey->getRequiredSecSessionId() );
	}

	void CFIntSecSessionEditObj::copyBuffToPKey() {
		cfsec::CFSecSecSessionPKey* tablePKey = getPKey();
		cfsec::CFSecSecSessionBuff* tableBuff = getSecSessionBuff();
		tablePKey->setRequiredSecSessionId( tableBuff->getRequiredSecSessionId() );
	}

	void CFIntSecSessionEditObj::copyBuffToOrig() {
		cfsec::CFSecSecSessionBuff* origBuff = getOrigAsSecSession()->getSecSessionEditBuff();
		cfsec::CFSecSecSessionBuff* myBuff = getSecSessionBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntSecSessionEditObj::copyOrigToBuff() {
		cfsec::CFSecSecSessionBuff* origBuff = getOrigAsSecSession()->getSecSessionBuff();
		cfsec::CFSecSecSessionBuff* myBuff = getSecSessionEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
