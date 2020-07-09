// Description: C++18 edit object instance implementation for CFInt Service.

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
#include <cfintobj/CFIntServiceObj.hpp>
#include <cfintobj/CFIntServiceEditObj.hpp>


namespace cfint {

	const std::string CFIntServiceEditObj::CLASS_NAME( "CFIntServiceEditObj" );

	CFIntServiceEditObj::CFIntServiceEditObj( cfsec::ICFSecServiceObj* argOrig )
	: ICFIntServiceEditObj(),
	  ICFSecServiceEditObj()
	{
		static const std::string S_ProcName( "CFIntServiceEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecServiceBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecServiceBuff*>( origBuff->clone() );
	}

	CFIntServiceEditObj::~CFIntServiceEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntServiceEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	cfsec::ICFSecSecUserObj* CFIntServiceEditObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getServiceBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntServiceEditObj::getCreatedAt() {
		return( getServiceBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntServiceEditObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<cfint::ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getServiceBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntServiceEditObj::getUpdatedAt() {
		return( getServiceBuff()->getUpdatedAt() );
	}

	void CFIntServiceEditObj::setCreatedBy( cfsec::ICFSecSecUserObj* value ) {
		createdBy = value;
		if( value != NULL ) {
			getServiceEditBuff()->setCreatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntServiceEditObj::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		getServiceEditBuff()->setCreatedAt( value );
	}

	void CFIntServiceEditObj::setUpdatedBy( cfsec::ICFSecSecUserObj* value ) {
		updatedBy = value;
		if( value != NULL ) {
			getServiceEditBuff()->setUpdatedByUserId( value->getRequiredSecUserIdReference() );
		}
	}

	void CFIntServiceEditObj::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		getServiceEditBuff()->setUpdatedAt( value );
	}

	const classcode_t CFIntServiceEditObj::getClassCode() const {
		return( cfsec::CFSecServiceBuff::CLASS_CODE );
	}

	bool CFIntServiceEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecServiceBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntServiceEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntServiceEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_ServiceId( "ServiceId" );
		static const std::string S_HostNodeId( "HostNodeId" );
		static const std::string S_ServiceTypeId( "ServiceTypeId" );
		static const std::string S_HostPort( "HostPort" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntServiceEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntServiceEditObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntServiceEditObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntServiceEditObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntServiceEditObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntServiceEditObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ServiceId, CFIntServiceEditObj::getRequiredServiceId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_HostNodeId, CFIntServiceEditObj::getRequiredHostNodeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_ServiceTypeId, CFIntServiceEditObj::getRequiredServiceTypeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_HostPort, CFIntServiceEditObj::getRequiredHostPort() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntServiceEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntServiceEditObj::setRequiredRevision( int32_t value ) {
		getServiceEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntServiceEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int64_t val = getRequiredServiceId();
		objName = cflib::CFLibXmlUtil::formatInt64( val );
		return( objName );
	}

	const std::string CFIntServiceEditObj::getGenDefName() {
		return( cfsec::CFSecServiceBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntServiceEditObj::getScope() {
		cfsec::ICFSecHostNodeObj* scope = getOptionalContainerHost();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntServiceEditObj::getObjScope() {
		cfsec::ICFSecHostNodeObj* scope = getOptionalContainerHost();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntServiceEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntServiceEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntServiceEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntServiceEditObj::getObjQualifiedName() {
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

	std::string CFIntServiceEditObj::getObjFullName() {
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

	cfsec::ICFSecServiceObj* CFIntServiceEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecServiceObj* retobj = getSchema()->getServiceTableObj()->realizeService( dynamic_cast<cfsec::ICFSecServiceObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecServiceObj* CFIntServiceEditObj::read( bool forceRead ) {
		cfsec::ICFSecServiceObj* retval = getOrigAsService()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecServiceObj* CFIntServiceEditObj::create() {
		cfsec::ICFSecServiceObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsService()->getSchema() )->getServiceTableObj()->createService( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecServiceEditObj* CFIntServiceEditObj::update() {
		getSchema()->getServiceTableObj()->updateService( this );
		return( NULL );
	}

	cfsec::ICFSecServiceEditObj* CFIntServiceEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getServiceTableObj()->deleteService( this );
		return( NULL );
	}

	cfsec::ICFSecServiceTableObj* CFIntServiceEditObj::getServiceTable() {
		return( orig->getSchema()->getServiceTableObj() );
	}

	cfsec::ICFSecServiceEditObj* CFIntServiceEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecServiceEditObj* CFIntServiceEditObj::getServiceEdit() {
		return( (cfsec::ICFSecServiceEditObj*)this );
	}

	cfsec::ICFSecServiceEditObj* CFIntServiceEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntServiceEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecServiceObj* CFIntServiceEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecServiceObj* CFIntServiceEditObj::getOrigAsService() {
		return( dynamic_cast<cfsec::ICFSecServiceObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntServiceEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecServiceBuff* CFIntServiceEditObj::getBuff() {
		return( buff );
	}

	void CFIntServiceEditObj::setBuff( cfsec::CFSecServiceBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecServicePKey* CFIntServiceEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntServiceEditObj::setPKey( cfsec::CFSecServicePKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntServiceEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntServiceEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntServiceEditObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFIntServiceEditObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int64_t CFIntServiceEditObj::getRequiredServiceId() {
		return( getPKey()->getRequiredServiceId() );
	}

	const int64_t* CFIntServiceEditObj::getRequiredServiceIdReference() {
		return( getPKey()->getRequiredServiceIdReference() );
	}

	const int64_t CFIntServiceEditObj::getRequiredHostNodeId() {
		return( getServiceBuff()->getRequiredHostNodeId() );
	}

	const int64_t* CFIntServiceEditObj::getRequiredHostNodeIdReference() {
		return( getServiceBuff()->getRequiredHostNodeIdReference() );
	}

	const int32_t CFIntServiceEditObj::getRequiredServiceTypeId() {
		return( getServiceBuff()->getRequiredServiceTypeId() );
	}

	const int32_t* CFIntServiceEditObj::getRequiredServiceTypeIdReference() {
		return( getServiceBuff()->getRequiredServiceTypeIdReference() );
	}

	const int16_t CFIntServiceEditObj::getRequiredHostPort() {
		return( getServiceBuff()->getRequiredHostPort() );
	}

	const int16_t* CFIntServiceEditObj::getRequiredHostPortReference() {
		return( getServiceBuff()->getRequiredHostPortReference() );
	}

	void CFIntServiceEditObj::setRequiredHostPort( const int16_t value ) {
		if( getServiceBuff()->getRequiredHostPort() != value ) {
			getServiceEditBuff()->setRequiredHostPort( value );
		}
	}

	cfsec::ICFSecClusterObj* CFIntServiceEditObj::getRequiredOwnerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsService()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFIntServiceEditObj::setRequiredOwnerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredId() );
				getServiceEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	cfsec::ICFSecHostNodeObj* CFIntServiceEditObj::getOptionalContainerHost( bool forceRead ) {
		cfsec::ICFSecHostNodeObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsService()->getSchema() )->getHostNodeTableObj()->readHostNodeByIdIdx( getPKey()->getRequiredClusterId(),
					getServiceBuff()->getRequiredHostNodeId() );
		}
		return( retobj );
	}

	void CFIntServiceEditObj::setOptionalContainerHost( cfsec::ICFSecHostNodeObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredClusterId
( value->getRequiredClusterId() );
				getServiceEditBuff()->setRequiredClusterId( value->getRequiredClusterId() );
				getServiceEditBuff()->setRequiredHostNodeId( value->getRequiredHostNodeId() );
			}
		}

	cfsec::ICFSecServiceTypeObj* CFIntServiceEditObj::getOptionalParentServiceType( bool forceRead ) {
		cfsec::ICFSecServiceTypeObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsService()->getSchema() )->getServiceTypeTableObj()->readServiceTypeByIdIdx( getServiceBuff()->getRequiredServiceTypeId() );
		}
		return( retobj );
	}

	void CFIntServiceEditObj::setOptionalParentServiceType( cfsec::ICFSecServiceTypeObj* value ) {
			
			if( value != NULL ) {
				getServiceEditBuff()->setRequiredServiceTypeId( value->getRequiredServiceTypeId() );
			}
			else {
			}
		}

	void CFIntServiceEditObj::copyPKeyToBuff() {
		cfsec::CFSecServicePKey* tablePKey = getPKey();
		cfsec::CFSecServiceBuff* tableBuff = getServiceEditBuff();
		tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
		tableBuff->setRequiredServiceId( tablePKey->getRequiredServiceId() );
	}

	void CFIntServiceEditObj::copyBuffToPKey() {
		cfsec::CFSecServicePKey* tablePKey = getPKey();
		cfsec::CFSecServiceBuff* tableBuff = getServiceBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredServiceId( tableBuff->getRequiredServiceId() );
	}

	void CFIntServiceEditObj::copyBuffToOrig() {
		cfsec::CFSecServiceBuff* origBuff = getOrigAsService()->getServiceEditBuff();
		cfsec::CFSecServiceBuff* myBuff = getServiceBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntServiceEditObj::copyOrigToBuff() {
		cfsec::CFSecServiceBuff* origBuff = getOrigAsService()->getServiceBuff();
		cfsec::CFSecServiceBuff* myBuff = getServiceEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
