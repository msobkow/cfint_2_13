// Description: C++18 Table Object implementation for CFInt.

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

#include <cfintobj/CFIntClusterObj.hpp>
#include <cfintobj/CFIntHostNodeObj.hpp>
#include <cfintobj/CFIntISOCcyObj.hpp>
#include <cfintobj/CFIntISOCtryObj.hpp>
#include <cfintobj/CFIntISOCtryCcyObj.hpp>
#include <cfintobj/CFIntISOCtryLangObj.hpp>
#include <cfintobj/CFIntISOLangObj.hpp>
#include <cfintobj/CFIntISOTZoneObj.hpp>
#include <cfintobj/CFIntLicenseObj.hpp>
#include <cfintobj/CFIntMajorVersionObj.hpp>
#include <cfintobj/CFIntMimeTypeObj.hpp>
#include <cfintobj/CFIntMinorVersionObj.hpp>
#include <cfintobj/CFIntSecAppObj.hpp>
#include <cfintobj/CFIntSecDeviceObj.hpp>
#include <cfintobj/CFIntSecFormObj.hpp>
#include <cfintobj/CFIntSecGroupObj.hpp>
#include <cfintobj/CFIntSecGroupFormObj.hpp>
#include <cfintobj/CFIntSecGrpIncObj.hpp>
#include <cfintobj/CFIntSecGrpMembObj.hpp>
#include <cfintobj/CFIntSecSessionObj.hpp>
#include <cfintobj/CFIntSecUserObj.hpp>
#include <cfintobj/CFIntServiceObj.hpp>
#include <cfintobj/CFIntServiceTypeObj.hpp>
#include <cfintobj/CFIntSubProjectObj.hpp>
#include <cfintobj/CFIntSysClusterObj.hpp>
#include <cfintobj/CFIntTSecGroupObj.hpp>
#include <cfintobj/CFIntTSecGrpIncObj.hpp>
#include <cfintobj/CFIntTSecGrpMembObj.hpp>
#include <cfintobj/CFIntTenantObj.hpp>
#include <cfintobj/CFIntTldObj.hpp>
#include <cfintobj/CFIntTopDomainObj.hpp>
#include <cfintobj/CFIntTopProjectObj.hpp>
#include <cfintobj/CFIntURLProtocolObj.hpp>

#include <cfintobj/CFIntClusterEditObj.hpp>
#include <cfintobj/CFIntHostNodeEditObj.hpp>
#include <cfintobj/CFIntISOCcyEditObj.hpp>
#include <cfintobj/CFIntISOCtryEditObj.hpp>
#include <cfintobj/CFIntISOCtryCcyEditObj.hpp>
#include <cfintobj/CFIntISOCtryLangEditObj.hpp>
#include <cfintobj/CFIntISOLangEditObj.hpp>
#include <cfintobj/CFIntISOTZoneEditObj.hpp>
#include <cfintobj/CFIntLicenseEditObj.hpp>
#include <cfintobj/CFIntMajorVersionEditObj.hpp>
#include <cfintobj/CFIntMimeTypeEditObj.hpp>
#include <cfintobj/CFIntMinorVersionEditObj.hpp>
#include <cfintobj/CFIntSecAppEditObj.hpp>
#include <cfintobj/CFIntSecDeviceEditObj.hpp>
#include <cfintobj/CFIntSecFormEditObj.hpp>
#include <cfintobj/CFIntSecGroupEditObj.hpp>
#include <cfintobj/CFIntSecGroupFormEditObj.hpp>
#include <cfintobj/CFIntSecGrpIncEditObj.hpp>
#include <cfintobj/CFIntSecGrpMembEditObj.hpp>
#include <cfintobj/CFIntSecSessionEditObj.hpp>
#include <cfintobj/CFIntSecUserEditObj.hpp>
#include <cfintobj/CFIntServiceEditObj.hpp>
#include <cfintobj/CFIntServiceTypeEditObj.hpp>
#include <cfintobj/CFIntSubProjectEditObj.hpp>
#include <cfintobj/CFIntSysClusterEditObj.hpp>
#include <cfintobj/CFIntTSecGroupEditObj.hpp>
#include <cfintobj/CFIntTSecGrpIncEditObj.hpp>
#include <cfintobj/CFIntTSecGrpMembEditObj.hpp>
#include <cfintobj/CFIntTenantEditObj.hpp>
#include <cfintobj/CFIntTldEditObj.hpp>
#include <cfintobj/CFIntTopDomainEditObj.hpp>
#include <cfintobj/CFIntTopProjectEditObj.hpp>
#include <cfintobj/CFIntURLProtocolEditObj.hpp>

#include <cfintobj/CFIntClusterTableObj.hpp>
#include <cfintobj/CFIntHostNodeTableObj.hpp>
#include <cfintobj/CFIntISOCcyTableObj.hpp>
#include <cfintobj/CFIntISOCtryTableObj.hpp>
#include <cfintobj/CFIntISOCtryCcyTableObj.hpp>
#include <cfintobj/CFIntISOCtryLangTableObj.hpp>
#include <cfintobj/CFIntISOLangTableObj.hpp>
#include <cfintobj/CFIntISOTZoneTableObj.hpp>
#include <cfintobj/CFIntLicenseTableObj.hpp>
#include <cfintobj/CFIntMajorVersionTableObj.hpp>
#include <cfintobj/CFIntMimeTypeTableObj.hpp>
#include <cfintobj/CFIntMinorVersionTableObj.hpp>
#include <cfintobj/CFIntSecAppTableObj.hpp>
#include <cfintobj/CFIntSecDeviceTableObj.hpp>
#include <cfintobj/CFIntSecFormTableObj.hpp>
#include <cfintobj/CFIntSecGroupTableObj.hpp>
#include <cfintobj/CFIntSecGroupFormTableObj.hpp>
#include <cfintobj/CFIntSecGrpIncTableObj.hpp>
#include <cfintobj/CFIntSecGrpMembTableObj.hpp>
#include <cfintobj/CFIntSecSessionTableObj.hpp>
#include <cfintobj/CFIntSecUserTableObj.hpp>
#include <cfintobj/CFIntServiceTableObj.hpp>
#include <cfintobj/CFIntServiceTypeTableObj.hpp>
#include <cfintobj/CFIntSubProjectTableObj.hpp>
#include <cfintobj/CFIntSysClusterTableObj.hpp>
#include <cfintobj/CFIntTSecGroupTableObj.hpp>
#include <cfintobj/CFIntTSecGrpIncTableObj.hpp>
#include <cfintobj/CFIntTSecGrpMembTableObj.hpp>
#include <cfintobj/CFIntTenantTableObj.hpp>
#include <cfintobj/CFIntTldTableObj.hpp>
#include <cfintobj/CFIntTopDomainTableObj.hpp>
#include <cfintobj/CFIntTopProjectTableObj.hpp>
#include <cfintobj/CFIntURLProtocolTableObj.hpp>

namespace cfint {

	const std::string CFIntServiceTypeTableObj::CLASS_NAME( "CFIntServiceTypeTableObj" );
	const std::string CFIntServiceTypeTableObj::TABLE_NAME( "ServiceType" );
	const std::string CFIntServiceTypeTableObj::TABLE_DBNAME( "SvcType" );

	CFIntServiceTypeTableObj::CFIntServiceTypeTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecServiceTypePKey, cfsec::ICFSecServiceTypeObj*>();
		allServiceType = NULL;
		indexByUDescrIdx = new std::map< cfsec::CFSecServiceTypeByUDescrIdxKey,
			cfsec::ICFSecServiceTypeObj*>();
	}

	CFIntServiceTypeTableObj::CFIntServiceTypeTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecServiceTypePKey, cfsec::ICFSecServiceTypeObj*>();
		allServiceType = NULL;
		indexByUDescrIdx = new std::map< cfsec::CFSecServiceTypeByUDescrIdxKey,
			cfsec::ICFSecServiceTypeObj*>();
	}

	CFIntServiceTypeTableObj::~CFIntServiceTypeTableObj() {
		minimizeMemory();
		if( indexByUDescrIdx != NULL ) {
			delete indexByUDescrIdx;
			indexByUDescrIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecServiceTypeObj* curMember;
			auto membersIter = members->begin();
			while( membersIter != members->end() ) {
				curMember = membersIter->second;
				if( curMember != NULL ) {
					delete curMember;
				}
				members->erase( membersIter );
				membersIter = members->begin();
			}
			delete members;
			members = NULL;
		}
	}

	cfsec::ICFSecSchemaObj* CFIntServiceTypeTableObj::getSchema() {
		return( schema );
	}

	void CFIntServiceTypeTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntServiceTypeTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntServiceTypeTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntServiceTypeTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntServiceTypeTableObj::minimizeMemory() {
		if( allServiceType != NULL ) {
			allServiceType->clear();
			delete allServiceType;
			allServiceType = NULL;
		}
		if( indexByUDescrIdx != NULL ) {
			indexByUDescrIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecServiceTypeObj* cur = NULL;
			cfsec::ICFSecServiceTypeEditObj* edit = NULL;
			auto iter = members->begin();
			auto end = members->end();
			while( iter != end ) {
				cur = iter->second;
				if( cur != NULL ) {
					iter->second = NULL;
					edit = cur->getEdit();
					if( edit != NULL ) {
						edit->endEdit();
						edit = NULL;
					}
					delete cur;
					cur = NULL;
				}
				iter ++;
			}
			members->clear();
		}
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::newInstance() {
		cfsec::ICFSecServiceTypeObj* inst = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( new CFIntServiceTypeObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecServiceTypeEditObj* CFIntServiceTypeTableObj::newEditInstance( cfsec::ICFSecServiceTypeObj* orig ) {
		cfsec::ICFSecServiceTypeEditObj* edit = dynamic_cast<cfsec::ICFSecServiceTypeEditObj*>( new CFIntServiceTypeEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::realizeServiceType( cfsec::ICFSecServiceTypeObj* Obj ) {
		static const std::string S_ProcName( "realizeServiceType" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecServiceTypeObj* obj = Obj;
		cfsec::ICFSecServiceTypeObj* existingObj = NULL;
		cfsec::CFSecServiceTypePKey* pkey = obj->getPKey();
		cfsec::ICFSecServiceTypeObj* keepObj = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			keepObj = existingObj;
			pkey = keepObj->getPKey();
			/*
			 *	We always rebind the data because if we're being called, some index may have been
			 *	updated and is refreshing it's data, which may require binding a different lookup key
			 */
			// Detach object from alternate and duplicate indexes, leave PKey alone
			if( indexByUDescrIdx != NULL ) {
				cfsec::CFSecServiceTypeByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				auto removalProbe = indexByUDescrIdx->find( keyUDescrIdx );
				if( removalProbe != indexByUDescrIdx->end() ) {
					indexByUDescrIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByUDescrIdx != NULL ) {
				static const std::string S_AUDescrIdxObj( "aUDescrIdxObj" );
				cfsec::ICFSecServiceTypeObj* aUDescrIdxObj =
					dynamic_cast<cfsec::ICFSecServiceTypeObj*>( keepObj );
				if( aUDescrIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDescrIdxObj );
				}
				cfsec::CFSecServiceTypeByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				indexByUDescrIdx->insert( std::map< cfsec::CFSecServiceTypeByUDescrIdxKey, cfsec::ICFSecServiceTypeObj* >::value_type( keyUDescrIdx, aUDescrIdxObj ) );
			}

			if( allServiceType != NULL ) {
				allServiceType->insert( std::map< cfsec::CFSecServiceTypePKey, cfsec::ICFSecServiceTypeObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecServiceTypePKey, cfsec::ICFSecServiceTypeObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByUDescrIdx != NULL ) {
				static const std::string S_AUDescrIdxObj( "aUDescrIdxObj" );
				cfsec::ICFSecServiceTypeObj* aUDescrIdxObj =
					dynamic_cast<cfsec::ICFSecServiceTypeObj*>( keepObj );
				if( aUDescrIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDescrIdxObj );
				}
				cfsec::CFSecServiceTypeByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				indexByUDescrIdx->insert( std::map< cfsec::CFSecServiceTypeByUDescrIdxKey, cfsec::ICFSecServiceTypeObj* >::value_type( keyUDescrIdx, aUDescrIdxObj ) );
			}

			if( allServiceType != NULL ) {
				allServiceType->insert( std::map< cfsec::CFSecServiceTypePKey, cfsec::ICFSecServiceTypeObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		if( keepObj != obj ) {
			delete obj;
			obj = NULL;
		}
		// Something is leaking, so I've added this paranoid check
		if( ( keepObj != existingObj ) && ( existingObj != NULL ) ) {
			delete existingObj;
			existingObj = NULL;
		}
		return( keepObj );
	}

	void CFIntServiceTypeTableObj::deepDisposeByIdIdx( const int32_t ServiceTypeId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecServiceTypeObj*> list;
		cfsec::ICFSecServiceTypeObj* existingObj = readCachedServiceTypeByIdIdx( ServiceTypeId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecServiceTypeObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntServiceTypeTableObj*>( schema->getServiceTypeTableObj() )->reallyDeepDisposeServiceType( dynamic_cast<cfsec::ICFSecServiceTypeObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntServiceTypeTableObj::deepDisposeByUDescrIdx( const std::string& Description ) {
		static const std::string S_ProcName( "deepDisposeByUDescrIdx" );
		std::vector<cfsec::ICFSecServiceTypeObj*> list;
		cfsec::ICFSecServiceTypeObj* existingObj = readCachedServiceTypeByUDescrIdx( Description );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecServiceTypeObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntServiceTypeTableObj*>( schema->getServiceTypeTableObj() )->reallyDeepDisposeServiceType( dynamic_cast<cfsec::ICFSecServiceTypeObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntServiceTypeTableObj::reallyDeepDisposeServiceType( cfsec::ICFSecServiceTypeObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeServiceType" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecServiceTypeObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->deepDisposeByTypeIdx( obj->getRequiredServiceTypeId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntServiceTypeTableObj*>( schema->getServiceTypeTableObj() )->reallyDetachFromIndexesServiceType( dynamic_cast<cfsec::ICFSecServiceTypeObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::createServiceType( cfsec::ICFSecServiceTypeEditObj* Obj ) {
		static const std::string S_ProcName( "createServiceType" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecServiceTypeObj* obj = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecServiceTypeBuff* buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableServiceType()->createServiceType(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( obj->realize() );
			if( obj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Obj );
			}
		}
		CFLIB_EXCEPTION_CATCH_FALLTHROUGH
		if( ! CFLIB_EXCEPTION_EMPTY ) {
			if( obj->getEdit() != NULL ) {
				obj->endEdit();
			}
			if( obj->getIsNew() ) {
				delete obj;
				obj = NULL;
			}
			CFLIB_EXCEPTION_RETHROW_CFLIBEXCEPTION
		}
		return( obj );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::readServiceType( cfsec::CFSecServiceTypePKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readServiceType" );
		cfsec::ICFSecServiceTypeObj* obj = NULL;
		cfsec::ICFSecServiceTypeObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecServiceTypeBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableServiceType()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredServiceTypeId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntServiceTypeTableObj*>( schema->getServiceTypeTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
		}
		return( realized );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::lockServiceType( cfsec::CFSecServiceTypePKey* pkey ) {
		static const std::string S_ProcName( "lockServiceType" );
		cfsec::ICFSecServiceTypeObj* locked = NULL;
		cfsec::CFSecServiceTypeBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableServiceType()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntServiceTypeTableObj*>( schema->getServiceTypeTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecServiceTypeObj*> CFIntServiceTypeTableObj::readAllServiceType( bool forceRead ) {
		static const std::string S_ProcName( "readAllServiceType" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecServiceTypeObj* realized = NULL;
		if( forceRead || ( allServiceType == NULL ) ) {
			std::map<cfsec::CFSecServiceTypePKey, cfsec::ICFSecServiceTypeObj*>* map = new std::map<cfsec::CFSecServiceTypePKey,cfsec::ICFSecServiceTypeObj*>();
			allServiceType = map;
			std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableServiceType()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecServiceTypeBuff* buff = NULL;
			cfsec::ICFSecServiceTypeObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allServiceType->insert( std::map< cfsec::CFSecServiceTypePKey, cfsec::ICFSecServiceTypeObj* >::value_type( *(realized->getPKey()), realized ) );
					// No need to delete obj -- realize() auto-destructs the instance it decided to discard
					obj = NULL;
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH

			if( ( obj != NULL ) && obj->getIsNew() ) {
				delete obj;
				obj = NULL;
			}

			CFLIB_EXCEPTION_RETHROW_CFLIBEXCEPTION

		}
		size_t len = allServiceType->size();
		std::vector<cfsec::ICFSecServiceTypeObj*> arr;
		auto valIter = allServiceType->begin();
		size_t idx = 0;
		while( valIter != allServiceType->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::readServiceTypeByIdIdx( const int32_t ServiceTypeId, bool forceRead )
	{
		static const std::string S_ProcName( "readServiceTypeByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecServiceTypePKey pkey;
		pkey.setRequiredServiceTypeId( ServiceTypeId );
		cfsec::ICFSecServiceTypeObj* obj = readServiceType( &pkey, forceRead );
		return( obj );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::readServiceTypeByUDescrIdx( const std::string& Description, bool forceRead )
	{
		static const std::string S_ProcName( "readServiceTypeByUDescrIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecServiceTypeByUDescrIdxKey,
				cfsec::ICFSecServiceTypeObj*>();
		}
		cfsec::CFSecServiceTypeByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::ICFSecServiceTypeObj* obj = NULL;
		cfsec::ICFSecServiceTypeObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
			if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUDescrIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecServiceTypeBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableServiceType()->readDerivedByUDescrIdx( schema->getAuthorization(),
				Description );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntServiceTypeTableObj*>( schema->getServiceTypeTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUDescrIdx->insert( std::map< cfsec::CFSecServiceTypeByUDescrIdxKey, cfsec::ICFSecServiceTypeObj*>::value_type( key, dynamic_cast<cfsec::ICFSecServiceTypeObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::readServiceTypeByLookupUDescrIdx( const std::string& Description, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readServiceTypeByLookupUDescrIdx" );
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecServiceTypeByUDescrIdxKey,
				cfsec::ICFSecServiceTypeObj*>();
		}
		cfsec::CFSecServiceTypeByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::ICFSecServiceTypeObj* obj = NULL;
		cfsec::ICFSecServiceTypeObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
			if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
				obj = searchIndexByUDescrIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecServiceTypeBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableServiceType()->readDerivedByLookupUDescrIdx( schema->getAuthorization(),
				Description );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( dynamic_cast<cfint::CFIntServiceTypeTableObj*>( schema->getServiceTypeTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUDescrIdx->insert( std::map< cfsec::CFSecServiceTypeByUDescrIdxKey, cfsec::ICFSecServiceTypeObj*>::value_type( key, dynamic_cast<cfsec::ICFSecServiceTypeObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::readCachedServiceType( cfsec::CFSecServiceTypePKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readServiceType" );
		cfsec::ICFSecServiceTypeObj* obj = NULL;
		cfsec::ICFSecServiceTypeObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::readCachedServiceTypeByIdIdx( const int32_t ServiceTypeId )
	{
		static const std::string S_ProcName( "readCachedServiceTypeByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecServiceTypePKey pkey;
		pkey.setRequiredServiceTypeId( ServiceTypeId );
		cfsec::ICFSecServiceTypeObj* obj = readCachedServiceType( &pkey );
		return( obj );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::readCachedServiceTypeByUDescrIdx( const std::string& Description )
	{
		static const std::string S_ProcName( "readCachedServiceTypeByUDescrIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecServiceTypeByUDescrIdxKey,
				cfsec::ICFSecServiceTypeObj*>();
		}
		cfsec::CFSecServiceTypeByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::ICFSecServiceTypeObj* obj = NULL;
		auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
		if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUDescrIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecServiceTypeBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::readCachedServiceTypeByLookupUDescrIdx( const std::string& Description )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedServiceTypeByLookupUDescrIdx" );
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecServiceTypeByUDescrIdxKey,
				cfsec::ICFSecServiceTypeObj*>();
		}
		cfsec::CFSecServiceTypeByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::ICFSecServiceTypeObj* obj = NULL;
		cfsec::ICFSecServiceTypeObj* realized = NULL;
		auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
		if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
			obj = searchIndexByUDescrIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecServiceTypeBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecServiceTypeObj* CFIntServiceTypeTableObj::updateServiceType( cfsec::ICFSecServiceTypeEditObj* Obj ) {
		static const std::string S_ProcName( "updateServiceType" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecServiceTypeObj* obj = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecServiceTypeBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableServiceType()->updateServiceType( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecServiceTypeBuff*>( Obj->getServiceTypeBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( dynamic_cast<cfint::CFIntServiceTypeTableObj*>( schema->getServiceTypeTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecServiceTypeObj*>( obj->realize() );
			if( obj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Obj );
			}
			if( obj->getEdit() != NULL ) {
				obj->endEdit();
			}
		}
		CFLIB_EXCEPTION_CATCH_FALLTHROUGH
		if( ! CFLIB_EXCEPTION_EMPTY ) {
			if( obj->getEdit() != NULL ) {
				obj->endEdit();
			}
			CFLIB_EXCEPTION_RETHROW_CFLIBEXCEPTION
		}
		return( obj );
	}

	void CFIntServiceTypeTableObj::deleteServiceType( cfsec::ICFSecServiceTypeEditObj* Obj ) {
		cfsec::ICFSecServiceTypeObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableServiceType()->deleteServiceType( schema->getAuthorization(),
			obj->getServiceTypeBuff() );
		deepDisposeByIdIdx( obj->getRequiredServiceTypeId() );
	}

	void CFIntServiceTypeTableObj::deleteServiceTypeByIdIdx( const int32_t ServiceTypeId )
	{
		cfsec::CFSecServiceTypePKey pkey;
		pkey.setRequiredServiceTypeId( ServiceTypeId );
		cfsec::ICFSecServiceTypeObj* obj = readServiceType( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecServiceTypeEditObj* editObj = dynamic_cast<cfsec::ICFSecServiceTypeEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecServiceTypeEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntServiceTypeTableObj::deleteServiceTypeByUDescrIdx( const std::string& Description )
	{
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecServiceTypeByUDescrIdxKey,
				cfsec::ICFSecServiceTypeObj*>();
		}
		cfsec::CFSecServiceTypeByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::ICFSecServiceTypeObj* obj = NULL;
		auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
		if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableServiceType()->deleteServiceTypeByUDescrIdx( schema->getAuthorization(),
				Description );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableServiceType()->deleteServiceTypeByUDescrIdx( schema->getAuthorization(),
				Description );
		}
		deepDisposeByUDescrIdx( Description );
	}

	void CFIntServiceTypeTableObj::reallyDetachFromIndexesServiceType( cfsec::ICFSecServiceTypeObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesServiceType" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecServiceTypeObj* obj = Obj;
		cfsec::CFSecServiceTypePKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecServiceTypeObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByUDescrIdx != NULL ) {
				cfsec::CFSecServiceTypeByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( obj->getRequiredDescription() );
				auto removalProbe = indexByUDescrIdx->find( keyUDescrIdx );
				if( removalProbe != indexByUDescrIdx->end() ) {
					indexByUDescrIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
