// Description: C++18 base object instance implementation for CFInt SecSession.

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
#include <cfintobj/CFIntSecSessionObj.hpp>

namespace cfint {

	const std::string CFIntSecSessionObj::CLASS_NAME( "CFIntSecSessionObj" );
	const classcode_t CFIntSecSessionObj::CLASS_CODE = 0xa010L;

	int32_t CFIntSecSessionObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const uuid_ptr_t CFIntSecSessionObj::getRequiredSecSessionId() {
		return( getPKey()->getRequiredSecSessionId() );
	}

	const uuid_ptr_t CFIntSecSessionObj::getRequiredSecSessionIdReference() {
		return( getPKey()->getRequiredSecSessionIdReference() );
	}

	const uuid_ptr_t CFIntSecSessionObj::getRequiredSecUserId() {
		return( getSecSessionBuff()->getRequiredSecUserId() );
	}

	const uuid_ptr_t CFIntSecSessionObj::getRequiredSecUserIdReference() {
		return( getSecSessionBuff()->getRequiredSecUserIdReference() );
	}

	bool CFIntSecSessionObj::isOptionalSecDevNameNull() {
		return( getSecSessionBuff()->isOptionalSecDevNameNull() );
	}

	const std::string& CFIntSecSessionObj::getOptionalSecDevNameValue() {
		return( getSecSessionBuff()->getOptionalSecDevNameValue() );
	}

	const std::string* CFIntSecSessionObj::getOptionalSecDevNameReference() {
		return( getSecSessionBuff()->getOptionalSecDevNameReference() );
	}

	const std::chrono::system_clock::time_point& CFIntSecSessionObj::getRequiredStart() {
		return( getSecSessionBuff()->getRequiredStart() );
	}

	const std::chrono::system_clock::time_point* CFIntSecSessionObj::getRequiredStartReference() {
		return( getSecSessionBuff()->getRequiredStartReference() );
	}

	bool CFIntSecSessionObj::isOptionalFinishNull() {
		return( getSecSessionBuff()->isOptionalFinishNull() );
	}

	const std::chrono::system_clock::time_point& CFIntSecSessionObj::getOptionalFinishValue() {
		return( getSecSessionBuff()->getOptionalFinishValue() );
	}

	const std::chrono::system_clock::time_point* CFIntSecSessionObj::getOptionalFinishReference() {
		return( getSecSessionBuff()->getOptionalFinishReference() );
	}

	bool CFIntSecSessionObj::isOptionalSecProxyIdNull() {
		return( getSecSessionBuff()->isOptionalSecProxyIdNull() );
	}

	const uuid_ptr_t CFIntSecSessionObj::getOptionalSecProxyIdValue() {
		return( getSecSessionBuff()->getOptionalSecProxyIdValue() );
	}

	const uuid_ptr_t CFIntSecSessionObj::getOptionalSecProxyIdReference() {
		return( getSecSessionBuff()->getOptionalSecProxyIdReference() );
	}


	cfsec::ICFSecSecUserObj* CFIntSecSessionObj::getRequiredContainerSecUser( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecSessionBuff()->getRequiredSecUserId(), forceRead );
		}
		return( retobj );
	}

	cfsec::ICFSecSecUserObj* CFIntSecSessionObj::getRequiredParentSecProxy( bool forceRead ) {
		cfsec::ICFSecSecUserObj* retobj = NULL;
		bool anyMissing = false;
			if( getSecSessionBuff()->isOptionalSecProxyIdNull() ) {
				anyMissing = true;
			}
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecSessionBuff()->getOptionalSecProxyIdValue(), forceRead );
		}
		return( retobj );
	}

	CFIntSecSessionObj::CFIntSecSessionObj()
	: ICFIntSecSessionObj(),
	  ICFSecSecSessionObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecSessionObj::CFIntSecSessionObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntSecSessionObj(),
	  ICFSecSecSessionObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecSessionObj::~CFIntSecSessionObj() {
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

	cfsec::CFSecSecSessionBuff* CFIntSecSessionObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecSessionBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecSession()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredSecSessionId() );
			}
		}
		return( buff );
	}

	void CFIntSecSessionObj::setBuff( cfsec::CFSecSecSessionBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntSecSessionObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSecSessionObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntSecSessionObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecSessionObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecSessionObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_SecSessionId( "SecSessionId" );
		static const std::string S_SecUserId( "SecUserId" );
		static const std::string S_SecDevName( "SecDevName" );
		static const std::string S_Start( "Start" );
		static const std::string S_Finish( "Finish" );
		static const std::string S_SecProxyId( "SecProxyId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecSessionObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecSessionId, CFIntSecSessionObj::getRequiredSecSessionId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecUserId, CFIntSecSessionObj::getRequiredSecUserId() ) );
		if( ! CFIntSecSessionObj::isOptionalSecDevNameNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_SecDevName, CFIntSecSessionObj::getOptionalSecDevNameValue() ) );
		}
		ret.append( cflib::CFLibXmlUtil::formatRequiredTimestamp( &S_Space, S_Start, CFIntSecSessionObj::getRequiredStart() ) );
		if( ! CFIntSecSessionObj::isOptionalFinishNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredTimestamp( &S_Space, S_Finish, CFIntSecSessionObj::getOptionalFinishValue() ) );
		}
		if( ! CFIntSecSessionObj::isOptionalSecProxyIdNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_SecProxyId, CFIntSecSessionObj::getOptionalSecProxyIdValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntSecSessionObj::getObjName() {
		std::string objName( CLASS_NAME );
		const uuid_ptr_t val = getRequiredSecSessionId();
		objName = cflib::CFLibXmlUtil::formatUuid( val );
		return( objName );
	}

	const std::string CFIntSecSessionObj::getGenDefName() {
		return( cfsec::CFSecSecSessionBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecSessionObj::getScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecSessionObj::getObjScope() {
		cfsec::ICFSecSecUserObj* scope = getRequiredContainerSecUser();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecSessionObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecSessionObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecSessionObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecSessionObj::getObjQualifiedName() {
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

	std::string CFIntSecSessionObj::getObjFullName() {
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

	cfsec::ICFSecSecSessionObj* CFIntSecSessionObj::realize() {
		cfsec::ICFSecSecSessionObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecSessionTableObj()->realizeSecSession(
			(cfsec::ICFSecSecSessionObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecSessionObj*>( retobj ) );
	}

	cfsec::ICFSecSecSessionObj* CFIntSecSessionObj::read( bool forceRead ) {
		cfsec::ICFSecSecSessionObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecSessionTableObj()->readSecSessionByIdIdx( getSecSessionBuff()->getRequiredSecSessionId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecSessionObj*>( retobj ) );
	}

	cfsec::ICFSecSecSessionTableObj* CFIntSecSessionObj::getSecSessionTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecSessionTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntSecSessionObj::getSchema() {
		return( schema );
	}

	void CFIntSecSessionObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecSessionPKey* CFIntSecSessionObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecSessionPKey();
		}
		return( pKey );
	}

	void CFIntSecSessionObj::setPKey( cfsec::CFSecSecSessionPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecSessionPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntSecSessionObj::getIsNew() {
		return( isNew );
	}

	void CFIntSecSessionObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecSessionEditObj* CFIntSecSessionObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecSessionObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecSessionTableObj()->lockSecSession( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecSessionTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecSessionEditObj*>( edit ) );
	}

	void CFIntSecSessionObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecSessionEditObj* CFIntSecSessionObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecSessionEditObj* CFIntSecSessionObj::getSecSessionEdit() {
		return( dynamic_cast<cfsec::ICFSecSecSessionEditObj*>( edit ) );
	}

	void CFIntSecSessionObj::copyPKeyToBuff() {
		cfsec::CFSecSecSessionPKey* tablePKey = getPKey();
		cfsec::CFSecSecSessionBuff* tableBuff = getSecSessionEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredSecSessionId( tablePKey->getRequiredSecSessionId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntSecSessionObj::copyBuffToPKey() {
		cfsec::CFSecSecSessionPKey* tablePKey = getPKey();
		cfsec::CFSecSecSessionBuff* tableBuff = getSecSessionBuff();
		tablePKey->setRequiredSecSessionId( tableBuff->getRequiredSecSessionId() );
	}

}
