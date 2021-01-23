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

	const std::string CFIntSysClusterTableObj::CLASS_NAME( "CFIntSysClusterTableObj" );
	const std::string CFIntSysClusterTableObj::TABLE_NAME( "SysCluster" );
	const std::string CFIntSysClusterTableObj::TABLE_DBNAME( "sysclus" );

	CFIntSysClusterTableObj::CFIntSysClusterTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>();
		allSysCluster = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSysClusterByClusterIdxKey,
			std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>*>();
	}

	CFIntSysClusterTableObj::CFIntSysClusterTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>();
		allSysCluster = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSysClusterByClusterIdxKey,
			std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>*>();
	}

	CFIntSysClusterTableObj::~CFIntSysClusterTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecSysClusterObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntSysClusterTableObj::getSchema() {
		return( schema );
	}

	void CFIntSysClusterTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntSysClusterTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntSysClusterTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntSysClusterTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntSysClusterTableObj::minimizeMemory() {
		if( allSysCluster != NULL ) {
			allSysCluster->clear();
			delete allSysCluster;
			allSysCluster = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecSysClusterByClusterIdxKey,
				std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecSysClusterByClusterIdxKey,
				std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* curByClusterIdx = NULL;
			while( iterByClusterIdx != endByClusterIdx ) {
				curByClusterIdx = iterByClusterIdx->second;
				if( curByClusterIdx != NULL ) {
					curByClusterIdx->clear();
					delete curByClusterIdx;
					curByClusterIdx = NULL;
					iterByClusterIdx->second = NULL;
				}
				iterByClusterIdx ++;
			}
			indexByClusterIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecSysClusterObj* cur = NULL;
			cfsec::ICFSecSysClusterEditObj* edit = NULL;
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

	cfsec::ICFSecSysClusterObj* CFIntSysClusterTableObj::newInstance() {
		cfsec::ICFSecSysClusterObj* inst = dynamic_cast<cfsec::ICFSecSysClusterObj*>( new CFIntSysClusterObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSysClusterEditObj* CFIntSysClusterTableObj::newEditInstance( cfsec::ICFSecSysClusterObj* orig ) {
		cfsec::ICFSecSysClusterEditObj* edit = dynamic_cast<cfsec::ICFSecSysClusterEditObj*>( new CFIntSysClusterEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSysClusterObj* CFIntSysClusterTableObj::realizeSysCluster( cfsec::ICFSecSysClusterObj* Obj ) {
		static const std::string S_ProcName( "realizeSysCluster" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSysClusterObj* obj = Obj;
		cfsec::ICFSecSysClusterObj* existingObj = NULL;
		cfsec::CFSecSysClusterPKey* pkey = obj->getPKey();
		cfsec::ICFSecSysClusterObj* keepObj = NULL;
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
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecSysClusterByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSysClusterBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSysClusterObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSysClusterObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSysClusterByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( allSysCluster != NULL ) {
				allSysCluster->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSysClusterObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSysClusterObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSysClusterByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( allSysCluster != NULL ) {
				allSysCluster->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntSysClusterTableObj::deepDisposeByIdIdx( const int32_t SingletonId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSysClusterObj*> list;
		cfsec::ICFSecSysClusterObj* existingObj = readCachedSysClusterByIdIdx( SingletonId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSysClusterObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSysClusterTableObj*>( schema->getSysClusterTableObj() )->reallyDeepDisposeSysCluster( dynamic_cast<cfsec::ICFSecSysClusterObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSysClusterTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecSysClusterObj*> list;
		std::vector<cfsec::ICFSecSysClusterObj*> matchesFound = readCachedSysClusterByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSysClusterObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSysClusterTableObj*>( schema->getSysClusterTableObj() )->reallyDeepDisposeSysCluster( dynamic_cast<cfsec::ICFSecSysClusterObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSysClusterTableObj::reallyDeepDisposeSysCluster( cfsec::ICFSecSysClusterObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSysCluster" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSysClusterObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSysClusterBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntSysClusterTableObj*>( schema->getSysClusterTableObj() )->reallyDetachFromIndexesSysCluster( dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSysClusterObj* CFIntSysClusterTableObj::createSysCluster( cfsec::ICFSecSysClusterEditObj* Obj ) {
		static const std::string S_ProcName( "createSysCluster" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSysClusterObj* obj = dynamic_cast<cfsec::ICFSecSysClusterObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSysClusterBuff* buff = dynamic_cast<cfsec::CFSecSysClusterBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSysCluster()->createSysCluster(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSysClusterBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj->realize() );
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

	cfsec::ICFSecSysClusterObj* CFIntSysClusterTableObj::readSysCluster( cfsec::CFSecSysClusterPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSysCluster" );
		cfsec::ICFSecSysClusterObj* obj = NULL;
		cfsec::ICFSecSysClusterObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSysClusterBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSysCluster()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredSingletonId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntSysClusterTableObj*>( schema->getSysClusterTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj->realize() );
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

	cfsec::ICFSecSysClusterObj* CFIntSysClusterTableObj::lockSysCluster( cfsec::CFSecSysClusterPKey* pkey ) {
		static const std::string S_ProcName( "lockSysCluster" );
		cfsec::ICFSecSysClusterObj* locked = NULL;
		cfsec::CFSecSysClusterBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSysCluster()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntSysClusterTableObj*>( schema->getSysClusterTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSysClusterObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSysClusterObj*> CFIntSysClusterTableObj::readAllSysCluster( bool forceRead ) {
		static const std::string S_ProcName( "readAllSysCluster" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSysClusterObj* realized = NULL;
		if( forceRead || ( allSysCluster == NULL ) ) {
			std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* map = new std::map<cfsec::CFSecSysClusterPKey,cfsec::ICFSecSysClusterObj*>();
			allSysCluster = map;
			std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSysCluster()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSysClusterBuff* buff = NULL;
			cfsec::ICFSecSysClusterObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSysCluster->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSysCluster->size();
		std::vector<cfsec::ICFSecSysClusterObj*> arr;
		auto valIter = allSysCluster->begin();
		size_t idx = 0;
		while( valIter != allSysCluster->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSysClusterObj* CFIntSysClusterTableObj::readSysClusterByIdIdx( const int32_t SingletonId, bool forceRead )
	{
		static const std::string S_ProcName( "readSysClusterByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSysClusterPKey pkey;
		pkey.setRequiredSingletonId( SingletonId );
		cfsec::ICFSecSysClusterObj* obj = readSysCluster( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecSysClusterObj*> CFIntSysClusterTableObj::readSysClusterByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSysClusterByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSysClusterByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* dict;
		std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecSysClusterByClusterIdxKey,
				std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>*>();
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			oldDict = searchIndexByClusterIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>();
			cfsec::ICFSecSysClusterObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSysClusterBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSysCluster()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecSysClusterBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSysClusterTableObj*>( schema->getSysClusterTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSysClusterObj* realized = dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecSysClusterByClusterIdxKey,
				std::map< cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSysClusterObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSysClusterObj* CFIntSysClusterTableObj::readCachedSysCluster( cfsec::CFSecSysClusterPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSysCluster" );
		cfsec::ICFSecSysClusterObj* obj = NULL;
		cfsec::ICFSecSysClusterObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSysClusterObj* CFIntSysClusterTableObj::readCachedSysClusterByIdIdx( const int32_t SingletonId )
	{
		static const std::string S_ProcName( "readCachedSysClusterByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSysClusterPKey pkey;
		pkey.setRequiredSingletonId( SingletonId );
		cfsec::ICFSecSysClusterObj* obj = readCachedSysCluster( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecSysClusterObj*> CFIntSysClusterTableObj::readCachedSysClusterByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedSysClusterByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSysClusterObj*> arr;
		cfsec::CFSecSysClusterByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSysClusterObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSysClusterObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSysClusterBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSysClusterObj* CFIntSysClusterTableObj::updateSysCluster( cfsec::ICFSecSysClusterEditObj* Obj ) {
		static const std::string S_ProcName( "updateSysCluster" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSysClusterObj* obj = dynamic_cast<cfsec::ICFSecSysClusterObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSysClusterBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSysCluster()->updateSysCluster( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSysClusterBuff*>( Obj->getSysClusterBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSysClusterObj*>( dynamic_cast<cfint::CFIntSysClusterTableObj*>( schema->getSysClusterTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSysClusterObj*>( obj->realize() );
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

	void CFIntSysClusterTableObj::deleteSysCluster( cfsec::ICFSecSysClusterEditObj* Obj ) {
		cfsec::ICFSecSysClusterObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSysCluster()->deleteSysCluster( schema->getAuthorization(),
			obj->getSysClusterBuff() );
		deepDisposeByIdIdx( obj->getRequiredSingletonId() );
	}

	void CFIntSysClusterTableObj::deleteSysClusterByIdIdx( const int32_t SingletonId )
	{
		cfsec::CFSecSysClusterPKey pkey;
		pkey.setRequiredSingletonId( SingletonId );
		cfsec::ICFSecSysClusterObj* obj = readSysCluster( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSysClusterEditObj* editObj = dynamic_cast<cfsec::ICFSecSysClusterEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSysClusterEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntSysClusterTableObj::deleteSysClusterByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSysCluster()->deleteSysClusterByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFIntSysClusterTableObj::reallyDetachFromIndexesSysCluster( cfsec::ICFSecSysClusterObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSysCluster" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSysClusterObj* obj = Obj;
		cfsec::CFSecSysClusterPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSysClusterObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecSysClusterByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSysClusterPKey, cfsec::ICFSecSysClusterObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
							if( mapClusterIdx->empty() ) {
								delete mapClusterIdx;
								mapClusterIdx = NULL;
								indexByClusterIdx->erase( searchClusterIdx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}


}
