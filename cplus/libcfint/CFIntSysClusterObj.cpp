// Description: C++18 base object instance implementation for CFInt SysCluster.

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
#include <cfintobj/CFIntSysClusterObj.hpp>

namespace cfint {

	const std::string CFIntSysClusterObj::CLASS_NAME( "CFIntSysClusterObj" );
	const classcode_t CFIntSysClusterObj::CLASS_CODE = 0xa014L;

	int32_t CFIntSysClusterObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	const int32_t CFIntSysClusterObj::getRequiredSingletonId() {
		return( getPKey()->getRequiredSingletonId() );
	}

	const int32_t* CFIntSysClusterObj::getRequiredSingletonIdReference() {
		return( getPKey()->getRequiredSingletonIdReference() );
	}

	const int64_t CFIntSysClusterObj::getRequiredClusterId() {
		return( getSysClusterBuff()->getRequiredClusterId() );
	}

	const int64_t* CFIntSysClusterObj::getRequiredClusterIdReference() {
		return( getSysClusterBuff()->getRequiredClusterIdReference() );
	}


	cfsec::ICFSecClusterObj* CFIntSysClusterObj::getRequiredContainerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getClusterTableObj()->readClusterByIdIdx( getSysClusterBuff()->getRequiredClusterId(), forceRead );
		}
		return( retobj );
	}

	CFIntSysClusterObj::CFIntSysClusterObj()
	: ICFIntSysClusterObj(),
	  ICFSecSysClusterObj()
	{
		schema = NULL;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSysClusterObj::CFIntSysClusterObj( cfsec::ICFSecSchemaObj* argSchema )
	: ICFIntSysClusterObj(),
	  ICFSecSysClusterObj()
	{
		schema = argSchema;
		pKey = NULL;
		buff = NULL;
		isNew = true;
		edit = NULL;
	}

	CFIntSysClusterObj::~CFIntSysClusterObj() {
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

	cfsec::CFSecSysClusterBuff* CFIntSysClusterObj::getBuff() {
		if( buff == NULL ) {
			if( isNew ) {
				buff = new cfsec::CFSecSysClusterBuff();
				copyBuffToPKey();
			}
			else {
				// Read the data buff via the backing store
				buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSysCluster()->readDerivedByIdIdx( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getAuthorization(),
						getPKey()->getRequiredSingletonId() );
			}
		}
		return( buff );
	}

	void CFIntSysClusterObj::setBuff( cfsec::CFSecSysClusterBuff* value ) {
		if( ( buff != NULL ) && ( buff != value ) ) {
			delete buff;
			buff = NULL;
		}
		buff = value;
		if( buff != NULL ) {
			copyBuffToPKey();
		}
	}

	const std::string& CFIntSysClusterObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSysClusterObj::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntSysClusterObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSysClusterObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSysClusterObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_SingletonId( "SingletonId" );
		static const std::string S_ClusterId( "ClusterId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSysClusterObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SingletonId, CFIntSysClusterObj::getRequiredSingletonId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSysClusterObj::getRequiredClusterId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	std::string CFIntSysClusterObj::getObjName() {
		std::string objName( CLASS_NAME );
		int32_t val = getRequiredSingletonId();
		objName = cflib::CFLibXmlUtil::formatInt32( val );
		return( objName );
	}

	const std::string CFIntSysClusterObj::getGenDefName() {
		return( cfsec::CFSecSysClusterBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSysClusterObj::getScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSysClusterObj::getObjScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSysClusterObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSysClusterObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSysClusterObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSysClusterObj::getObjQualifiedName() {
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

	std::string CFIntSysClusterObj::getObjFullName() {
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

	cfsec::ICFSecSysClusterObj* CFIntSysClusterObj::realize() {
		cfsec::ICFSecSysClusterObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSysClusterTableObj()->realizeSysCluster(
			(cfsec::ICFSecSysClusterObj*)this );
		return( dynamic_cast<cfsec::ICFSecSysClusterObj*>( retobj ) );
	}

	cfsec::ICFSecSysClusterObj* CFIntSysClusterObj::read( bool forceRead ) {
		cfsec::ICFSecSysClusterObj* retobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSysClusterTableObj()->readSysClusterByIdIdx( getSysClusterBuff()->getRequiredSingletonId(), forceRead );
		return( dynamic_cast<cfsec::ICFSecSysClusterObj*>( retobj ) );
	}

	cfsec::ICFSecSysClusterTableObj* CFIntSysClusterObj::getSysClusterTable() {
		return( dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSysClusterTableObj() );
	}

	cfsec::ICFSecSchemaObj* CFIntSysClusterObj::getSchema() {
		return( schema );
	}

	void CFIntSysClusterObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = value;
	}

	cfsec::CFSecSysClusterPKey* CFIntSysClusterObj::getPKey() {
		if( pKey == NULL ) {
			pKey = new cfsec::CFSecSysClusterPKey();
		}
		return( pKey );
	}

	void CFIntSysClusterObj::setPKey( cfsec::CFSecSysClusterPKey* value ) {
		if( ( pKey != NULL ) && ( pKey != value ) ) {
			delete pKey;
			pKey = NULL;
		}
		if( value != NULL ) {
			pKey = new cfsec::CFSecSysClusterPKey();
			*pKey = *value;
			copyPKeyToBuff();
		}
	}

	bool CFIntSysClusterObj::getIsNew() {
		return( isNew );
	}

	void CFIntSysClusterObj::setIsNew( bool value ) {
		isNew = value;
	}

	cfsec::ICFSecSysClusterEditObj* CFIntSysClusterObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_EditAlreadyOpen( "An edit is already open" );
		if( edit != NULL ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_ProcName, S_EditAlreadyOpen );
		}
		if( ! getIsNew() ) {
			cfsec::ICFSecSysClusterObj* lockobj = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSysClusterTableObj()->lockSysCluster( getPKey() );
			lockobj->realize();
		}
		edit = dynamic_cast<ICFIntSchemaObj*>( getSchema() )->getSysClusterTableObj()->newEditInstance( this );
		return( dynamic_cast<cfsec::ICFSecSysClusterEditObj*>( edit ) );
	}

	void CFIntSysClusterObj::endEdit() {
		if( edit != NULL ) {
			delete edit;
			edit = NULL;
		}
	}

	cfsec::ICFSecSysClusterEditObj* CFIntSysClusterObj::getEdit() {
		return( edit );
	}

	cfsec::ICFSecSysClusterEditObj* CFIntSysClusterObj::getSysClusterEdit() {
		return( dynamic_cast<cfsec::ICFSecSysClusterEditObj*>( edit ) );
	}

	void CFIntSysClusterObj::copyPKeyToBuff() {
		cfsec::CFSecSysClusterPKey* tablePKey = getPKey();
		cfsec::CFSecSysClusterBuff* tableBuff = getSysClusterEditBuff();
		if( tableBuff != NULL ) {
			tableBuff->setRequiredSingletonId( tablePKey->getRequiredSingletonId() );
		}
		if( edit != NULL ) {
			edit->copyPKeyToBuff();
		}
	}

	void CFIntSysClusterObj::copyBuffToPKey() {
		cfsec::CFSecSysClusterPKey* tablePKey = getPKey();
		cfsec::CFSecSysClusterBuff* tableBuff = getSysClusterBuff();
		tablePKey->setRequiredSingletonId( tableBuff->getRequiredSingletonId() );
	}

}
