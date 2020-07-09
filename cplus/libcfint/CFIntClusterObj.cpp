// Description: C++18 base object instance implementation for CFInt Cluster.

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
#include <cfintobj/CFIntClusterObj.hpp>

namespace cfint {

	const std::string CFIntClusterObj::CLASS_NAME( "CFIntClusterObj" );
	const classcode_t CFIntClusterObj::CLASS_CODE = 0xa001L;

	int32_t CFIntClusterObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntClusterObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntClusterObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const std::string& CFIntClusterObj::getRequiredFullDomName() {
		return( getClusterBuff()->getRequiredFullDomName() );
	}

	const std::string* CFIntClusterObj::getRequiredFullDomNameReference() {
		return( getClusterBuff()->getRequiredFullDomNameReference() );
	}

	const std::string& CFIntClusterObj::getRequiredDescription() {
		return( getClusterBuff()->getRequiredDescription() );
	}

	const std::string* CFIntClusterObj::getRequiredDescriptionReference() {
		return( getClusterBuff()->getRequiredDescriptionReference() );
	}


	std::vector<cfsec::ICFSecHostNodeObj*> CFIntClusterObj::getOptionalComponentsHostNode( bool forceRead ) {
		std::vector<cfsec::ICFSecHostNodeObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getHostNodeTableObj()->readHostNodeByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecTenantObj*> CFIntClusterObj::getOptionalComponentsTenant( bool forceRead ) {
		std::vector<cfsec::ICFSecTenantObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecAppObj*> CFIntClusterObj::getOptionalComponentsSecApp( bool forceRead ) {
		std::vector<cfsec::ICFSecSecAppObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecAppTableObj()->readSecAppByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGroupObj*> CFIntClusterObj::getOptionalComponentsSecGroup( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGroupObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSysClusterObj*> CFIntClusterObj::getOptionalComponentsSysCluster( bool forceRead ) {
		std::vector<cfsec::ICFSecSysClusterObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSysClusterTableObj()->readSysClusterByClusterIdx( getPKey()->getRequiredId(),
			forceRead );
		return( retval );
	}

	CFIntClusterObj::CFIntClusterObj()
	: ICFIntClusterObj(),
	  ICFSecClusterObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntClusterObj::CFIntClusterObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntClusterObj(),
	  ICFSecClusterObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntClusterObj::~CFIntClusterObj() {
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

	cfsec::CFSecClusterBuff* CFIntClusterObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecClusterBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredId() );
			}
		}
		return( buff );
	}

	void CFIntClusterObj::setBuff( cfsec::CFSecClusterBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntClusterObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntClusterObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntClusterObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecClusterBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntClusterObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntClusterObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_Id( "Id" );
		static const std::string S_FullDomName( "FullDomName" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntClusterObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntClusterObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntClusterObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntClusterObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntClusterObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntClusterObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_FullDomName, CFIntClusterObj::getRequiredFullDomName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntClusterObj::getRequiredDescription() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntClusterObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredFullDomName() );
		return( objName );
	}

	const std::string CFIntClusterObj::getGenDefName() {
		return( cfsec::CFSecClusterBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntClusterObj::getScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntClusterObj::getObjScope() {
		return( NULL );
	}

	cflib::ICFLibAnyObj* CFIntClusterObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntClusterObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntClusterObj::getNamedObject( const std::string& objName ) {
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
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getHostNodeTableObj()->readHostNodeByLookupHostNameIdx( getRequiredId(),
				nextName,
				false );
		}
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getTenantTableObj()->readTenantByLookupUNameIdx( getRequiredId(),
				nextName,
				false );
		}
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecAppTableObj()->readSecAppByLookupUJEEMountIdx( getRequiredId(),
				nextName,
				false );
		}
		if( subObj == NULL ) {
			subObj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByLookupUNameIdx( getRequiredId(),
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

	std::string CFIntClusterObj::getObjQualifiedName() {
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

	std::string CFIntClusterObj::getObjFullName() {
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

	cfsec::ICFSecClusterObj* CFIntClusterObj::realize() {
		cfsec::ICFSecClusterObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj()->realizeCluster(
			(cfsec::ICFSecClusterObj*)this );
		return( dynamic_cast<cfsec::ICFSecClusterObj*>( retobj ) );
	}

	cfsec::ICFSecClusterObj* CFIntClusterObj::read( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getClusterBuff()->getRequiredId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecClusterObj*>( retobj ) );
	}

	cfsec::ICFSecClusterTableObj* CFIntClusterObj::getClusterTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntClusterObj::getSchema() {
		return( schema );
	}

	void CFIntClusterObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecClusterPKey* CFIntClusterObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecClusterPKey();
		}
		return( pKey );
	}

	void CFIntClusterObj::setPKey( cfsec::CFSecClusterPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecClusterPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntClusterObj::getIsNew() {
		return( isNew );
	}

	void CFIntClusterObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecClusterEditObj* CFIntClusterObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecClusterObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj()->lockCluster( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecClusterEditObj*>( edit ) );
	}

	void CFIntClusterObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecClusterEditObj* CFIntClusterObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecClusterEditObj* CFIntClusterObj::getClusterEdit() {
		return( dynamic_cast<cfsec::ICFSecClusterEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntClusterObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getClusterBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntClusterObj::getCreatedAt() {
		return( getClusterBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntClusterObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getClusterBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntClusterObj::getUpdatedAt() {
		return( getClusterBuff()->getUpdatedAt() );
	}

	void CFIntClusterObj::copyPKeyToBuff() {
		cfsec::CFSecClusterPKey* tablePKey = getPKey();
		cfsec::CFSecClusterBuff* tableBuff = getClusterEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredId( tablePKey->getRequiredId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntClusterObj::copyBuffToPKey() {
		cfsec::CFSecClusterPKey* tablePKey = getPKey();
		cfsec::CFSecClusterBuff* tableBuff = getClusterBuff();
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

}
