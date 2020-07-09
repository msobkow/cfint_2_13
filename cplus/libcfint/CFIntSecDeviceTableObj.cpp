// Description: C++18 Table Object implementation for CFInt.

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

	const std::string CFIntSecDeviceTableObj::CLASS_NAME( "CFIntSecDeviceTableObj" );
	const std::string CFIntSecDeviceTableObj::TABLE_NAME( "SecDevice" );
	const std::string CFIntSecDeviceTableObj::TABLE_DBNAME( "SecDev" );

	CFIntSecDeviceTableObj::CFIntSecDeviceTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>();
		allSecDevice = NULL;
		indexByNameIdx = new std::map< cfsec::CFSecSecDeviceByNameIdxKey,
			cfsec::ICFSecSecDeviceObj*>();
		indexByUserIdx = new std::map< cfsec::CFSecSecDeviceByUserIdxKey,
			std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>*>();
	}

	CFIntSecDeviceTableObj::CFIntSecDeviceTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>();
		allSecDevice = NULL;
		indexByNameIdx = new std::map< cfsec::CFSecSecDeviceByNameIdxKey,
			cfsec::ICFSecSecDeviceObj*>();
		indexByUserIdx = new std::map< cfsec::CFSecSecDeviceByUserIdxKey,
			std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>*>();
	}

	CFIntSecDeviceTableObj::~CFIntSecDeviceTableObj() {
		minimizeMemory();
		if( indexByNameIdx != NULL ) {
			delete indexByNameIdx;
			indexByNameIdx = NULL;
		}
		if( indexByUserIdx != NULL ) {
			delete indexByUserIdx;
			indexByUserIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecSecDeviceObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntSecDeviceTableObj::getSchema() {
		return( schema );
	}

	void CFIntSecDeviceTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntSecDeviceTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntSecDeviceTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntSecDeviceTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntSecDeviceTableObj::minimizeMemory() {
		if( allSecDevice != NULL ) {
			allSecDevice->clear();
			delete allSecDevice;
			allSecDevice = NULL;
		}
		if( indexByNameIdx != NULL ) {
			indexByNameIdx->clear();
		}
		if( indexByUserIdx != NULL ) {
			std::map< cfsec::CFSecSecDeviceByUserIdxKey,
				std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* >::iterator iterByUserIdx = indexByUserIdx->begin();
			std::map< cfsec::CFSecSecDeviceByUserIdxKey,
				std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* >::iterator endByUserIdx = indexByUserIdx->end();
			std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* curByUserIdx = NULL;
			while( iterByUserIdx != endByUserIdx ) {
				curByUserIdx = iterByUserIdx->second;
				if( curByUserIdx != NULL ) {
					curByUserIdx->clear();
					delete curByUserIdx;
					curByUserIdx = NULL;
					iterByUserIdx->second = NULL;
				}
				iterByUserIdx ++;
			}
			indexByUserIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecSecDeviceObj* cur = NULL;
			cfsec::ICFSecSecDeviceEditObj* edit = NULL;
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

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::newInstance() {
		cfsec::ICFSecSecDeviceObj* inst = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( new CFIntSecDeviceObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSecDeviceEditObj* CFIntSecDeviceTableObj::newEditInstance( cfsec::ICFSecSecDeviceObj* orig ) {
		cfsec::ICFSecSecDeviceEditObj* edit = dynamic_cast<cfsec::ICFSecSecDeviceEditObj*>( new CFIntSecDeviceEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::realizeSecDevice( cfsec::ICFSecSecDeviceObj* Obj ) {
		static const std::string S_ProcName( "realizeSecDevice" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecDeviceObj* obj = Obj;
		cfsec::ICFSecSecDeviceObj* existingObj = NULL;
		cfsec::CFSecSecDevicePKey* pkey = obj->getPKey();
		cfsec::ICFSecSecDeviceObj* keepObj = NULL;
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
			if( indexByNameIdx != NULL ) {
				cfsec::CFSecSecDeviceByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				keyNameIdx.setRequiredDevName( keepObj->getRequiredDevName() );
				auto removalProbe = indexByNameIdx->find( keyNameIdx );
				if( removalProbe != indexByNameIdx->end() ) {
					indexByNameIdx->erase( removalProbe );
				}
			}

			if( indexByUserIdx != NULL ) {
				cfsec::CFSecSecDeviceByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* mapUserIdx = searchUserIdx->second;
					if( mapUserIdx != NULL ) {
						auto removalProbe = mapUserIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapUserIdx->end() ) {
							mapUserIdx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfsec::ICFSecSecDeviceObj* aNameIdxObj =
					dynamic_cast<cfsec::ICFSecSecDeviceObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfsec::CFSecSecDeviceByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				keyNameIdx.setRequiredDevName( keepObj->getRequiredDevName() );
				indexByNameIdx->insert( std::map< cfsec::CFSecSecDeviceByNameIdxKey, cfsec::ICFSecSecDeviceObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( indexByUserIdx != NULL ) {
				static const std::string S_AUserIdxObj( "aUserIdxObj" );
				cfsec::ICFSecSecDeviceObj* aUserIdxObj =
					dynamic_cast<cfsec::ICFSecSecDeviceObj*>( keepObj );
				if( aUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUserIdxObj );
				}
				cfsec::CFSecSecDeviceByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchIndexByUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchIndexByUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* mapUserIdx = searchIndexByUserIdx->second;
					if( mapUserIdx != NULL ) {
						mapUserIdx->insert( std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj* >::value_type( *(keepObj->getPKey()), aUserIdxObj ) );
					}
				}
			}

			if( allSecDevice != NULL ) {
				allSecDevice->insert( std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfsec::ICFSecSecDeviceObj* aNameIdxObj =
					dynamic_cast<cfsec::ICFSecSecDeviceObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfsec::CFSecSecDeviceByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				keyNameIdx.setRequiredDevName( keepObj->getRequiredDevName() );
				indexByNameIdx->insert( std::map< cfsec::CFSecSecDeviceByNameIdxKey, cfsec::ICFSecSecDeviceObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( indexByUserIdx != NULL ) {
				static const std::string S_AUserIdxObj( "aUserIdxObj" );
				cfsec::ICFSecSecDeviceObj* aUserIdxObj =
					dynamic_cast<cfsec::ICFSecSecDeviceObj*>( keepObj );
				if( aUserIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUserIdxObj );
				}
				cfsec::CFSecSecDeviceByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( keepObj->getRequiredSecUserId() );
				auto searchIndexByUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchIndexByUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* mapUserIdx = searchIndexByUserIdx->second;
					if( mapUserIdx != NULL ) {
						mapUserIdx->insert( std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj* >::value_type( *(keepObj->getPKey()), aUserIdxObj ) );
					}
				}
			}

			if( allSecDevice != NULL ) {
				allSecDevice->insert( std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntSecDeviceTableObj::deepDisposeByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSecDeviceObj*> list;
		cfsec::ICFSecSecDeviceObj* existingObj = readCachedSecDeviceByIdIdx( SecUserId,
				DevName );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecDeviceObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->reallyDeepDisposeSecDevice( dynamic_cast<cfsec::ICFSecSecDeviceObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecDeviceTableObj::deepDisposeByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName ) {
		static const std::string S_ProcName( "deepDisposeByNameIdx" );
		std::vector<cfsec::ICFSecSecDeviceObj*> list;
		cfsec::ICFSecSecDeviceObj* existingObj = readCachedSecDeviceByNameIdx( SecUserId,
				DevName );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecDeviceObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->reallyDeepDisposeSecDevice( dynamic_cast<cfsec::ICFSecSecDeviceObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecDeviceTableObj::deepDisposeByUserIdx( const uuid_ptr_t SecUserId ) {
		static const std::string S_ProcName( "deepDisposeByUserIdx" );
		std::vector<cfsec::ICFSecSecDeviceObj*> list;
		std::vector<cfsec::ICFSecSecDeviceObj*> matchesFound = readCachedSecDeviceByUserIdx( SecUserId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecDeviceObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->reallyDeepDisposeSecDevice( dynamic_cast<cfsec::ICFSecSecDeviceObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecDeviceTableObj::reallyDeepDisposeSecDevice( cfsec::ICFSecSecDeviceObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSecDevice" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSecDeviceObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSecDeviceBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->reallyDetachFromIndexesSecDevice( dynamic_cast<cfsec::ICFSecSecDeviceObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::createSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj ) {
		static const std::string S_ProcName( "createSecDevice" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecDeviceObj* obj = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecDeviceBuff* buff = dynamic_cast<cfsec::CFSecSecDeviceBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->createSecDevice(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSecDeviceBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( obj->realize() );
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

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::readSecDevice( cfsec::CFSecSecDevicePKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecDevice" );
		cfsec::ICFSecSecDeviceObj* obj = NULL;
		cfsec::ICFSecSecDeviceObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecDeviceBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredSecUserId(),
			pkey->getRequiredDevName() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( obj->realize() );
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

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::lockSecDevice( cfsec::CFSecSecDevicePKey* pkey ) {
		static const std::string S_ProcName( "lockSecDevice" );
		cfsec::ICFSecSecDeviceObj* locked = NULL;
		cfsec::CFSecSecDeviceBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSecDeviceObj*> CFIntSecDeviceTableObj::readAllSecDevice( bool forceRead ) {
		static const std::string S_ProcName( "readAllSecDevice" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecDeviceObj* realized = NULL;
		if( forceRead || ( allSecDevice == NULL ) ) {
			std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* map = new std::map<cfsec::CFSecSecDevicePKey,cfsec::ICFSecSecDeviceObj*>();
			allSecDevice = map;
			std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSecDeviceBuff* buff = NULL;
			cfsec::ICFSecSecDeviceObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSecDevice->insert( std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSecDevice->size();
		std::vector<cfsec::ICFSecSecDeviceObj*> arr;
		auto valIter = allSecDevice->begin();
		size_t idx = 0;
		while( valIter != allSecDevice->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecDeviceObj*> CFIntSecDeviceTableObj::pageAllSecDevice(const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllSecDevice" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* map = NULL;
		cfsec::CFSecSecDeviceBuff* buff = NULL;
		cfsec::ICFSecSecDeviceObj* obj = NULL;
		cfsec::ICFSecSecDeviceObj* realized = NULL;
		std::vector<cfsec::ICFSecSecDeviceObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecSecDevicePKey,cfsec::ICFSecSecDeviceObj*>();
			std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->pageAllBuff( schema->getAuthorization(),
				priorSecUserId,
				priorDevName );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
				arrayList.push_back( realized );
				realized = NULL;
			}
		}
		CFLIB_EXCEPTION_CATCH_FALLTHROUGH

		if( ( obj != NULL ) && obj->getIsNew() ) {
			delete obj;
			obj = NULL;
		}

		CFLIB_EXCEPTION_RETHROW_CFLIBEXCEPTION

		return( arrayList );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::readSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName, bool forceRead )
	{
		static const std::string S_ProcName( "readSecDeviceByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecDevicePKey pkey;
		pkey.setRequiredSecUserId( SecUserId );
		pkey.setRequiredDevName( DevName );
		cfsec::ICFSecSecDeviceObj* obj = readSecDevice( &pkey, forceRead );
		return( obj );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::readSecDeviceByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName, bool forceRead )
	{
		static const std::string S_ProcName( "readSecDeviceByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfsec::CFSecSecDeviceByNameIdxKey,
				cfsec::ICFSecSecDeviceObj*>();
		}
		cfsec::CFSecSecDeviceByNameIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredDevName( DevName );
		cfsec::ICFSecSecDeviceObj* obj = NULL;
		cfsec::ICFSecSecDeviceObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecDeviceBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->readDerivedByNameIdx( schema->getAuthorization(),
				SecUserId,
				DevName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfsec::CFSecSecDeviceByNameIdxKey, cfsec::ICFSecSecDeviceObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecDeviceObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecDeviceObj*> CFIntSecDeviceTableObj::readSecDeviceByUserIdx( const uuid_ptr_t SecUserId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecDeviceByUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecDeviceByUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* dict;
		std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* oldDict;
		if( indexByUserIdx == NULL ) {
			indexByUserIdx = new std::map< cfsec::CFSecSecDeviceByUserIdxKey,
				std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>*>();
		}
		auto searchIndexByUserIdx = indexByUserIdx->find( key );
		if( searchIndexByUserIdx != indexByUserIdx->end() ) {
			oldDict = searchIndexByUserIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>();
			cfsec::ICFSecSecDeviceObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->readDerivedByUserIdx( schema->getAuthorization(),
				SecUserId );
			cfsec::CFSecSecDeviceBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecDeviceObj* realized = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByUserIdx->erase( searchIndexByUserIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByUserIdx->insert( std::map< cfsec::CFSecSecDeviceByUserIdxKey,
				std::map< cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecDeviceObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::readSecDeviceByLookupNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readSecDeviceByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfsec::CFSecSecDeviceByNameIdxKey,
				cfsec::ICFSecSecDeviceObj*>();
		}
		cfsec::CFSecSecDeviceByNameIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredDevName( DevName );
		cfsec::ICFSecSecDeviceObj* obj = NULL;
		cfsec::ICFSecSecDeviceObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				obj = searchIndexByNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecDeviceBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->readDerivedByLookupNameIdx( schema->getAuthorization(),
				SecUserId,
				DevName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( dynamic_cast<cfint::CFIntSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfsec::CFSecSecDeviceByNameIdxKey, cfsec::ICFSecSecDeviceObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecDeviceObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::readCachedSecDevice( cfsec::CFSecSecDevicePKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecDevice" );
		cfsec::ICFSecSecDeviceObj* obj = NULL;
		cfsec::ICFSecSecDeviceObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::readCachedSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName )
	{
		static const std::string S_ProcName( "readCachedSecDeviceByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecDevicePKey pkey;
		pkey.setRequiredSecUserId( SecUserId );
		pkey.setRequiredDevName( DevName );
		cfsec::ICFSecSecDeviceObj* obj = readCachedSecDevice( &pkey );
		return( obj );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::readCachedSecDeviceByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName )
	{
		static const std::string S_ProcName( "readCachedSecDeviceByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfsec::CFSecSecDeviceByNameIdxKey,
				cfsec::ICFSecSecDeviceObj*>();
		}
		cfsec::CFSecSecDeviceByNameIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredDevName( DevName );
		cfsec::ICFSecSecDeviceObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecDeviceBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecDeviceObj*> CFIntSecDeviceTableObj::readCachedSecDeviceByUserIdx( const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readCachedSecDeviceByUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecDeviceObj*> arr;
		cfsec::CFSecSecDeviceByUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* dict;
		if( indexByUserIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByUserIdx = indexByUserIdx->find( key );
		if( searchIndexByUserIdx != indexByUserIdx->end() ) {
			dict = searchIndexByUserIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecDeviceObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecDeviceObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecDeviceBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::readCachedSecDeviceByLookupNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedSecDeviceByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfsec::CFSecSecDeviceByNameIdxKey,
				cfsec::ICFSecSecDeviceObj*>();
		}
		cfsec::CFSecSecDeviceByNameIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredDevName( DevName );
		cfsec::ICFSecSecDeviceObj* obj = NULL;
		cfsec::ICFSecSecDeviceObj* realized = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecDeviceBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecDeviceObj*> CFIntSecDeviceTableObj::pageSecDeviceByUserIdx( const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName )
	{
		static const std::string S_ProcName( "pageSecDeviceByUserIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecDeviceByUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		cfsec::ICFSecSecDeviceObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecDeviceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->pageBuffByUserIdx( schema->getAuthorization(),
				SecUserId,
				priorSecUserId,
				priorDevName );
		std::vector<cfsec::ICFSecSecDeviceObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecDeviceBuff* buff;
		cfsec::ICFSecSecDeviceObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( obj->realize() );
			if( realized == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Realized );
			}
			// No need to delete obj -- realize() auto-destructs the instance it decided to discard
			obj = NULL;
			retList.push_back( realized );
		}
		return( retList );
	}

	cfsec::ICFSecSecDeviceObj* CFIntSecDeviceTableObj::updateSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj ) {
		static const std::string S_ProcName( "updateSecDevice" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecDeviceObj* obj = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecDeviceBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->updateSecDevice( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSecDeviceBuff*>( Obj->getSecDeviceBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( dynamic_cast<cfint::CFIntSecDeviceTableObj*>( schema->getSecDeviceTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSecDeviceObj*>( obj->realize() );
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

	void CFIntSecDeviceTableObj::deleteSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj ) {
		cfsec::ICFSecSecDeviceObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->deleteSecDevice( schema->getAuthorization(),
			obj->getSecDeviceBuff() );
		deepDisposeByIdIdx( obj->getRequiredSecUserId(),
			obj->getRequiredDevName() );
	}

	void CFIntSecDeviceTableObj::deleteSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName )
	{
		cfsec::CFSecSecDevicePKey pkey;
		pkey.setRequiredSecUserId( SecUserId );
		pkey.setRequiredDevName( DevName );
		cfsec::ICFSecSecDeviceObj* obj = readSecDevice( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSecDeviceEditObj* editObj = dynamic_cast<cfsec::ICFSecSecDeviceEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSecDeviceEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntSecDeviceTableObj::deleteSecDeviceByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName )
	{
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfsec::CFSecSecDeviceByNameIdxKey,
				cfsec::ICFSecSecDeviceObj*>();
		}
		cfsec::CFSecSecDeviceByNameIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredDevName( DevName );
		cfsec::ICFSecSecDeviceObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->deleteSecDeviceByNameIdx( schema->getAuthorization(),
				SecUserId,
				DevName );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecDevice()->deleteSecDeviceByNameIdx( schema->getAuthorization(),
				SecUserId,
				DevName );
		}
		deepDisposeByNameIdx( SecUserId,
			DevName );
	}

	void CFIntSecDeviceTableObj::deleteSecDeviceByUserIdx( const uuid_ptr_t SecUserId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecDevice()->deleteSecDeviceByUserIdx( schema->getAuthorization(),
				SecUserId );
		deepDisposeByUserIdx( SecUserId );
	}

	void CFIntSecDeviceTableObj::reallyDetachFromIndexesSecDevice( cfsec::ICFSecSecDeviceObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSecDevice" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecDeviceObj* obj = Obj;
		cfsec::CFSecSecDevicePKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSecDeviceObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByNameIdx != NULL ) {
				cfsec::CFSecSecDeviceByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredSecUserId( obj->getRequiredSecUserId() );
				keyNameIdx.setRequiredDevName( obj->getRequiredDevName() );
				auto removalProbe = indexByNameIdx->find( keyNameIdx );
				if( removalProbe != indexByNameIdx->end() ) {
					indexByNameIdx->erase( removalProbe );
				}
			}

			if( indexByUserIdx != NULL ) {
				cfsec::CFSecSecDeviceByUserIdxKey keyUserIdx;
				keyUserIdx.setRequiredSecUserId( obj->getRequiredSecUserId() );
				auto searchUserIdx = indexByUserIdx->find( keyUserIdx );
				if( searchUserIdx != indexByUserIdx->end() ) {
					std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* mapUserIdx = searchUserIdx->second;
					if( mapUserIdx != NULL ) {
						auto removalProbe = mapUserIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapUserIdx->end() ) {
							mapUserIdx->erase( removalProbe );
							if( mapUserIdx->empty() ) {
								delete mapUserIdx;
								mapUserIdx = NULL;
								indexByUserIdx->erase( searchUserIdx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}


}
