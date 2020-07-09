// Description: C++18 edit object instance implementation for CFInt SysCluster.

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
#include <cfintobj/CFIntSysClusterObj.hpp>
#include <cfintobj/CFIntSysClusterEditObj.hpp>


namespace cfint {

	const std::string CFIntSysClusterEditObj::CLASS_NAME( "CFIntSysClusterEditObj" );

	CFIntSysClusterEditObj::CFIntSysClusterEditObj( cfsec::ICFSecSysClusterObj* argOrig )
	: ICFIntSysClusterEditObj(),
	  ICFSecSysClusterEditObj()
	{
		static const std::string S_ProcName( "CFIntSysClusterEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfsec::CFSecSysClusterBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( origBuff->clone() );
	}

	CFIntSysClusterEditObj::~CFIntSysClusterEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntSysClusterEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntSysClusterEditObj::getClassCode() const {
		return( cfsec::CFSecSysClusterBuff::CLASS_CODE );
	}

	bool CFIntSysClusterEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntSysClusterEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSysClusterEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_SingletonId( "SingletonId" );
		static const std::string S_ClusterId( "ClusterId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntSysClusterEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_SingletonId, CFIntSysClusterEditObj::getRequiredSingletonId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_ClusterId, CFIntSysClusterEditObj::getRequiredClusterId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntSysClusterEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntSysClusterEditObj::setRequiredRevision( int32_t value ) {
		getSysClusterEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntSysClusterEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		int32_t val = getRequiredSingletonId();
		objName = cflib::CFLibXmlUtil::formatInt32( val );
		return( objName );
	}

	const std::string CFIntSysClusterEditObj::getGenDefName() {
		return( cfsec::CFSecSysClusterBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntSysClusterEditObj::getScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSysClusterEditObj::getObjScope() {
		cfsec::ICFSecClusterObj* scope = getRequiredContainerCluster();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntSysClusterEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
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

	cflib::ICFLibAnyObj* CFIntSysClusterEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntSysClusterEditObj::getNamedObject( const std::string& objName ) {
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

	std::string CFIntSysClusterEditObj::getObjQualifiedName() {
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

	std::string CFIntSysClusterEditObj::getObjFullName() {
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

	cfsec::ICFSecSysClusterObj* CFIntSysClusterEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfsec::ICFSecSysClusterObj* retobj = getSchema()->getSysClusterTableObj()->realizeSysCluster( dynamic_cast<cfsec::ICFSecSysClusterObj*>( this ) );
		return( retobj );
	}

	cfsec::ICFSecSysClusterObj* CFIntSysClusterEditObj::read( bool forceRead ) {
		cfsec::ICFSecSysClusterObj* retval = getOrigAsSysCluster()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfsec::ICFSecSysClusterObj* CFIntSysClusterEditObj::create() {
		cfsec::ICFSecSysClusterObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSysCluster()->getSchema() )->getSysClusterTableObj()->createSysCluster( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfsec::ICFSecSysClusterEditObj* CFIntSysClusterEditObj::update() {
		getSchema()->getSysClusterTableObj()->updateSysCluster( this );
		return( NULL );
	}

	cfsec::ICFSecSysClusterEditObj* CFIntSysClusterEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getSysClusterTableObj()->deleteSysCluster( this );
		return( NULL );
	}

	cfsec::ICFSecSysClusterTableObj* CFIntSysClusterEditObj::getSysClusterTable() {
		return( orig->getSchema()->getSysClusterTableObj() );
	}

	cfsec::ICFSecSysClusterEditObj* CFIntSysClusterEditObj::getEdit() {
		return( this );
	}

	cfsec::ICFSecSysClusterEditObj* CFIntSysClusterEditObj::getSysClusterEdit() {
		return( (cfsec::ICFSecSysClusterEditObj*)this );
	}

	cfsec::ICFSecSysClusterEditObj* CFIntSysClusterEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntSysClusterEditObj::endEdit() {
		orig->endEdit();
	}

	cfsec::ICFSecSysClusterObj* CFIntSysClusterEditObj::getOrig() {
		return( orig );
	}

	cfsec::ICFSecSysClusterObj* CFIntSysClusterEditObj::getOrigAsSysCluster() {
		return( dynamic_cast<cfsec::ICFSecSysClusterObj*>( orig ) );
	}

	cfsec::ICFSecSchemaObj* CFIntSysClusterEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfsec::CFSecSysClusterBuff* CFIntSysClusterEditObj::getBuff() {
		return( buff );
	}

	void CFIntSysClusterEditObj::setBuff( cfsec::CFSecSysClusterBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfsec::CFSecSysClusterPKey* CFIntSysClusterEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntSysClusterEditObj::setPKey( cfsec::CFSecSysClusterPKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntSysClusterEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntSysClusterEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int32_t CFIntSysClusterEditObj::getRequiredSingletonId() {
		return( getPKey()->getRequiredSingletonId() );
	}

	const int32_t* CFIntSysClusterEditObj::getRequiredSingletonIdReference() {
		return( getPKey()->getRequiredSingletonIdReference() );
	}

	void CFIntSysClusterEditObj::setRequiredSingletonId( const int32_t value ) {
		if( getPKey()->getRequiredSingletonId() != value ) {
			getPKey()->setRequiredSingletonId( value );
		}
		if( getSysClusterBuff()->getRequiredSingletonId() != value ) {
			getSysClusterEditBuff()->setRequiredSingletonId( value );
		}
	}

	const int64_t CFIntSysClusterEditObj::getRequiredClusterId() {
		return( getSysClusterBuff()->getRequiredClusterId() );
	}

	const int64_t* CFIntSysClusterEditObj::getRequiredClusterIdReference() {
		return( getSysClusterBuff()->getRequiredClusterIdReference() );
	}

	cfsec::ICFSecClusterObj* CFIntSysClusterEditObj::getRequiredContainerCluster( bool forceRead ) {
		cfsec::ICFSecClusterObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsSysCluster()->getSchema() )->getClusterTableObj()->readClusterByIdIdx( getSysClusterBuff()->getRequiredClusterId() );
		}
		return( retobj );
	}

	void CFIntSysClusterEditObj::setRequiredContainerCluster( cfsec::ICFSecClusterObj* value ) {
			
			if( value != NULL ) {
				getSysClusterEditBuff()->setRequiredClusterId( value->getRequiredId() );
			}
		}

	void CFIntSysClusterEditObj::copyPKeyToBuff() {
		cfsec::CFSecSysClusterPKey* tablePKey = getPKey();
		cfsec::CFSecSysClusterBuff* tableBuff = getSysClusterEditBuff();
		tableBuff->setRequiredSingletonId( tablePKey->getRequiredSingletonId() );
	}

	void CFIntSysClusterEditObj::copyBuffToPKey() {
		cfsec::CFSecSysClusterPKey* tablePKey = getPKey();
		cfsec::CFSecSysClusterBuff* tableBuff = getSysClusterBuff();
		tablePKey->setRequiredSingletonId( tableBuff->getRequiredSingletonId() );
	}

	void CFIntSysClusterEditObj::copyBuffToOrig() {
		cfsec::CFSecSysClusterBuff* origBuff = getOrigAsSysCluster()->getSysClusterEditBuff();
		cfsec::CFSecSysClusterBuff* myBuff = getSysClusterBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntSysClusterEditObj::copyOrigToBuff() {
		cfsec::CFSecSysClusterBuff* origBuff = getOrigAsSysCluster()->getSysClusterBuff();
		cfsec::CFSecSysClusterBuff* myBuff = getSysClusterEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
