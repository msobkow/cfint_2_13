// Description: C++18 base object instance implementation for CFInt SecGroup.

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
#include <cfintobj/CFIntSecGroupObj.hpp>

namespace cfint {

	const std::string CFIntSecGroupObj::CLASS_NAME( "CFIntSecGroupObj" );
	const classcode_t CFIntSecGroupObj::CLASS_CODE = 0xa00cL;

	int32_t CFIntSecGroupObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int64_t CFIntSecGroupObj::getRequiredClusterId() {
		return( getPKey()->getRequiredClusterId() );
	}

	const int64_t* CFIntSecGroupObj::getRequiredClusterIdReference() {
		return( getPKey()->getRequiredClusterIdReference() );
	}

	const int32_t CFIntSecGroupObj::getRequiredSecGroupId() {
		return( getPKey()->getRequiredSecGroupId() );
	}

	const int32_t* CFIntSecGroupObj::getRequiredSecGroupIdReference() {
		return( getPKey()->getRequiredSecGroupIdReference() );
	}

	const std::string& CFIntSecGroupObj::getRequiredName() {
		return( getSecGroupBuff()->getRequiredName() );
	}

	const std::string* CFIntSecGroupObj::getRequiredNameReference() {
		return( getSecGroupBuff()->getRequiredNameReference() );
	}

	const bool CFIntSecGroupObj::getRequiredIsVisible() {
		return( getSecGroupBuff()->getRequiredIsVisible() );
	}

	const bool* CFIntSecGroupObj::getRequiredIsVisibleReference() {
		return( getSecGroupBuff()->getRequiredIsVisibleReference() );
	}


	cfsec::ICFSecClusterObj* CFIntSecGroupObj::getRequiredContainerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getPKey()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGroupObj::getOptionalComponentsInclude( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpIncObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->readSecGrpIncByGroupIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGrpMembObj*> CFIntSecGroupObj::getOptionalComponentsMember( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpMembObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpMembTableObj()->readSecGrpMembByGroupIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGroupObj::getRequiredChildrenIncByGroup( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGrpIncObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGrpIncTableObj()->readSecGrpIncByIncludeIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	std::vector<cfsec::ICFSecSecGroupFormObj*> CFIntSecGroupObj::getOptionalComponentsForm( bool forceRead ) {
		std::vector<cfsec::ICFSecSecGroupFormObj*> retval;
		retval = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupFormTableObj()->readSecGroupFormByGroupIdx( getPKey()->getRequiredClusterId(),
					getPKey()->getRequiredSecGroupId(),
			forceRead );
		return( retval );
	}

	CFIntSecGroupObj::CFIntSecGroupObj()
	: ICFIntSecGroupObj(),
	  ICFSecSecGroupObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecGroupObj::CFIntSecGroupObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntSecGroupObj(),
	  ICFSecSecGroupObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSecGroupObj::~CFIntSecGroupObj() {
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

	cfsec::CFSecSecGroupBuff* CFIntSecGroupObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSecGroupBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredClusterId(),
						getPKey()->getRequiredSecGroupId() );
			}
		}
		return( buff );
	}

	void CFIntSecGroupObj::setBuff( cfsec::CFSecSecGroupBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntSecGroupObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSecGroupObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntSecGroupObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSecGroupObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSecGroupObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_ClusterId( "ClusterId" );
		static const std::string S_SecGroupId( "SecGroupId" );
		static const std::string S_Name( "Name" );
		static const std::string S_IsVisible( "IsVisible" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSecGroupObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_CreatedBy, CFIntSecGroupObj::getCreatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, CFIntSecGroupObj::getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_UpdatedBy, CFIntSecGroupObj::getUpdatedBy()->toString() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, CFIntSecGroupObj::getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSecGroupObj::getRequiredClusterId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SecGroupId, CFIntSecGroupObj::getRequiredSecGroupId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntSecGroupObj::getRequiredName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsVisible, CFIntSecGroupObj::getRequiredIsVisible() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntSecGroupObj::getObjName() {
		std::string objName( CLASS_NAME );
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntSecGroupObj::getGenDefName() {
		return( cfsec::CFSecSecGroupBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupObj::getScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupObj::getObjScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSecGroupObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSecGroupObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSecGroupObj::getObjQualifiedName() {
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

	std::string CFIntSecGroupObj::getObjFullName() {
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

	cfsec::ICFSecSecGroupObj* CFIntSecGroupObj::realize() {
		cfsec::ICFSecSecGroupObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj()->realizeSecGroup(
			(cfsec::ICFSecSecGroupObj*)this );
		return( dynamic_cast<cfsec::ICFSecSecGroupObj*>( retobj ) );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupObj::read( bool forceRead ) {
		cfsec::ICFSecSecGroupObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj()->readSecGroupByIdIdx( getSecGroupBuff()->getRequiredClusterId(),
		getSecGroupBuff()->getRequiredSecGroupId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSecGroupObj*>( retobj ) );
	}

	cfsec::ICFSecSecGroupTableObj* CFIntSecGroupObj::getSecGroupTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntSecGroupObj::getSchema() {
		return( schema );
	}

	void CFIntSecGroupObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSecGroupPKey* CFIntSecGroupObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSecGroupPKey();
		}
		return( pKey );
	}

	void CFIntSecGroupObj::setPKey( cfsec::CFSecSecGroupPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSecGroupPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntSecGroupObj::getIsNew() {
		return( isNew );
	}

	void CFIntSecGroupObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSecGroupEditObj* CFIntSecGroupObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSecGroupObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj()->lockSecGroup( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecGroupTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSecGroupEditObj*>( edit ) );
	}

	void CFIntSecGroupObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSecGroupEditObj* CFIntSecGroupObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSecGroupEditObj* CFIntSecGroupObj::getSecGroupEdit() {
		return( dynamic_cast<cfsec::ICFSecSecGroupEditObj*>( edit ) );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGroupObj::getCreatedBy() {
		if( createdBy == NULL ) {
			createdBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGroupBuff()->getCreatedByUserId() );
		}
		return( createdBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGroupObj::getCreatedAt() {
		return( getSecGroupBuff()->getCreatedAt() );
	}

	cfsec::ICFSecSecUserObj* CFIntSecGroupObj::getUpdatedBy() {
		if( updatedBy == NULL ) {
			updatedBy = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSecUserTableObj()->readSecUserByIdIdx( getSecGroupBuff()->getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	const std::chrono::system_clock::time_point& CFIntSecGroupObj::getUpdatedAt() {
		return( getSecGroupBuff()->getUpdatedAt() );
	}

	void CFIntSecGroupObj::copyPKeyToBuff() {
		cfsec::CFSecSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecSecGroupBuff* tableBuff = getSecGroupEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredClusterId( tablePKey->getRequiredClusterId() );
			tableBuff->setRequiredSecGroupId( tablePKey->getRequiredSecGroupId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntSecGroupObj::copyBuffToPKey() {
		cfsec::CFSecSecGroupPKey* tablePKey = getPKey();
		cfsec::CFSecSecGroupBuff* tableBuff = getSecGroupBuff();
		tablePKey->setRequiredClusterId( tableBuff->getRequiredClusterId() );
		tablePKey->setRequiredSecGroupId( tableBuff->getRequiredSecGroupId() );
	}

}
