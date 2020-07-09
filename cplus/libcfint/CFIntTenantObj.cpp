// Description: C++18 base object instance implementation for CFInt Tenant.

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
#include <cfintobj/CFIntTenantObj.hpp>

namespace cfint {

	const std::string CFIntTenantObj::CLASS_NAME( "CFIntTenantObj" );
	const classcode_t CFIntTenantObj::CLASS_CODE = 0xa015L;

	int32_t CFIntTenantObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntTenantObj::getRequiredClusterId() {
		return( getTenantBuff()->getRequiredClusterId() );
	}

	const int64_t* CFIntTenantObj::getRequiredClusterIdReference() {
		return( getTenantBuff()->getRequiredClusterIdReference() );
	}

	const int64_t CFIntTenantObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntTenantObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const std::string& CFIntTenantObj::getRequiredTenantName() {
		return( getTenantBuff()->getRequiredTenantName() );
	}

	const std::string* CFIntTenantObj::getRequiredTenantNameReference() {
		return( getTenantBuff()->getRequiredTenantNameReference() );
	}


	cfsec::ICFSecClusterObj* CFIntTenantObj::getRequiredContainerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getTenantBuff()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfsec::ICFSecTSecGroupObj*> CFIntTenantObj::getOptionalComponentsTSecGroup( bool forceRead ) {
		std::vector<cfsec::ICFSecTSecGroupObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTSecGroupTableObj()->readTSecGroupByTenantIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfint::ICFIntTldObj*> CFIntTenantObj::getOptionalComponentsTld( bool forceRead ) {
		std::vector<cfint::ICFIntTldObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTldTableObj()->readTldByTenantIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	CFIntTenantObj::CFIntTenantObj()
	: ICFIntTenantObj(),
	  ICFSecTenantObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntTenantObj::CFIntTenantObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntTenantObj(),
	  ICFSecTenantObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntTenantObj::~CFIntTenantObj() {
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

	cfsec::CFSecTenantBuff* CFIntTenantObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecTenantBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredId() );
			}
		}
		return( buff );
	}

	void CFIntTenantObj::setBuff( cfsec::CFSecTenantBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntTenantObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntTenantObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntTenantObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecTenantBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntTenantObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTenantObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_Id( "Id" );
		static const std::string S_TenantName( "TenantName" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntTenantObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntTenantObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntTenantObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntTenantObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntTenantObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntTenantObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntTenantObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_TenantName, CFIntTenantObj::getRequiredTenantName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntTenantObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredTenantName() );
		return( objName );
	}

	const std::string CFIntTenantObj::getGenDefName() {
		return( cfsec::CFSecTenantBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntTenantObj::getScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTenantObj::getObjScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntTenantObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntTenantObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntTenantObj::getNamedObject( const std::string& objName ) {
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
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTldTableObj()->readTldByLookupNameIdx( getRequiredId(),
				nextName,
				false );
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

	std::string CFIntTenantObj::getObjQualifiedName() {
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

	std::string CFIntTenantObj::getObjFullName() {
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

	cfsec::ICFSecTenantObj* CFIntTenantObj::realize() {
		cfsec::ICFSecTenantObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->realizeTenant(
			(cfsec::ICFSecTenantObj*)this );
		return( dynamic_cast<cfsec::ICFSecTenantObj*>( retobj ) );
	}

	cfsec::ICFSecTenantObj* CFIntTenantObj::read( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByIdIdx( getTenantBuff()->getRequiredId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecTenantObj*>( retobj ) );
	}

	cfsec::ICFSecTenantTableObj* CFIntTenantObj::getTenantTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntTenantObj::getSchema() {
		return( schema );
	}

	void CFIntTenantObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecTenantPKey* CFIntTenantObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecTenantPKey();
		}
		return( pKey );
	}

	void CFIntTenantObj::setPKey( cfsec::CFSecTenantPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecTenantPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntTenantObj::getIsNew() {
		return( isNew );
	}

	void CFIntTenantObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecTenantEditObj* CFIntTenantObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecTenantObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->lockTenant( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecTenantEditObj*>( edit ) );
	}

	void CFIntTenantObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecTenantEditObj* CFIntTenantObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecTenantEditObj* CFIntTenantObj::getTenantEdit() {
		return( dynamic_cast<cfsec::ICFSecTenantEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntTenantObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTenantBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntTenantObj::getCreatedAt() {
		return( getTenantBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntTenantObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getTenantBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntTenantObj::getUpdatedAt() {
		return( getTenantBuff()->getUpdatedAt() );
	}

	void CFIntTenantObj::copyPKeyToBuff() {
		cfsec::CFSecTenantPKey* tablePKey = getPKey();
		cfsec::CFSecTenantBuff* tableBuff = getTenantEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredId( tablePKey->getRequiredId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntTenantObj::copyBuffToPKey() {
		cfsec::CFSecTenantPKey* tablePKey = getPKey();
		cfsec::CFSecTenantBuff* tableBuff = getTenantBuff();
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

}
