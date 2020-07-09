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

	const std::string CFIntTldTableObj::CLASS_NAME( "CFIntTldTableObj" );
	const std::string CFIntTldTableObj::TABLE_NAME( "Tld" );
	const std::string CFIntTldTableObj::TABLE_DBNAME( "tlddef" );

	CFIntTldTableObj::CFIntTldTableObj() {
		schema = NULL;
		members = new std::map<cfint::CFIntTldPKey, cfint::ICFIntTldObj*>();
		allTld = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntTldByTenantIdxKey,
			std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntTldByNameIdxKey,
			cfint::ICFIntTldObj*>();
	}

	CFIntTldTableObj::CFIntTldTableObj( cfint::ICFIntSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfint::CFIntTldPKey, cfint::ICFIntTldObj*>();
		allTld = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntTldByTenantIdxKey,
			std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntTldByNameIdxKey,
			cfint::ICFIntTldObj*>();
	}

	CFIntTldTableObj::~CFIntTldTableObj() {
		minimizeMemory();
		if( indexByTenantIdx != NULL ) {
			delete indexByTenantIdx;
			indexByTenantIdx = NULL;
		}
		if( indexByNameIdx != NULL ) {
			delete indexByNameIdx;
			indexByNameIdx = NULL;
		}
		if( members != NULL ) {
			cfint::ICFIntTldObj* curMember;
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

	cfint::ICFIntSchemaObj* CFIntTldTableObj::getSchema() {
		return( schema );
	}

	void CFIntTldTableObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntTldTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntTldTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntTldTableObj::getObjQualifyingClassCode() {
		return( &cfsec::CFSecTenantBuff::CLASS_CODE );
	}


	void CFIntTldTableObj::minimizeMemory() {
		if( allTld != NULL ) {
			allTld->clear();
			delete allTld;
			allTld = NULL;
		}
		if( indexByTenantIdx != NULL ) {
			std::map< cfint::CFIntTldByTenantIdxKey,
				std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj*>* >::iterator iterByTenantIdx = indexByTenantIdx->begin();
			std::map< cfint::CFIntTldByTenantIdxKey,
				std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj*>* >::iterator endByTenantIdx = indexByTenantIdx->end();
			std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj*>* curByTenantIdx = NULL;
			while( iterByTenantIdx != endByTenantIdx ) {
				curByTenantIdx = iterByTenantIdx->second;
				if( curByTenantIdx != NULL ) {
					curByTenantIdx->clear();
					delete curByTenantIdx;
					curByTenantIdx = NULL;
					iterByTenantIdx->second = NULL;
				}
				iterByTenantIdx ++;
			}
			indexByTenantIdx->clear();
		}
		if( indexByNameIdx != NULL ) {
			indexByNameIdx->clear();
		}
		if( members != NULL ) {
			cfint::ICFIntTldObj* cur = NULL;
			cfint::ICFIntTldEditObj* edit = NULL;
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

	cfint::ICFIntTldObj* CFIntTldTableObj::newInstance() {
		cfint::ICFIntTldObj* inst = dynamic_cast<cfint::ICFIntTldObj*>( new CFIntTldObj( schema ) );
		return( inst );
	}

	cfint::ICFIntTldEditObj* CFIntTldTableObj::newEditInstance( cfint::ICFIntTldObj* orig ) {
		cfint::ICFIntTldEditObj* edit = dynamic_cast<cfint::ICFIntTldEditObj*>( new CFIntTldEditObj( orig ));
		return( edit );
	}

	cfint::ICFIntTldObj* CFIntTldTableObj::realizeTld( cfint::ICFIntTldObj* Obj ) {
		static const std::string S_ProcName( "realizeTld" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntTldObj* obj = Obj;
		cfint::ICFIntTldObj* existingObj = NULL;
		cfint::CFIntTldPKey* pkey = obj->getPKey();
		cfint::ICFIntTldObj* keepObj = NULL;
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
			if( indexByTenantIdx != NULL ) {
				cfint::CFIntTldByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTldPKey, cfint::ICFIntTldObj*>* mapTenantIdx = searchTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						auto removalProbe = mapTenantIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTenantIdx->end() ) {
							mapTenantIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntTldByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByNameIdx->find( keyNameIdx );
				if( removalProbe != indexByNameIdx->end() ) {
					indexByNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfint::CFIntTldBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntTldObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntTldObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntTldByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTldPKey, cfint::ICFIntTldObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntTldObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntTldObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntTldByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntTldByNameIdxKey, cfint::ICFIntTldObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allTld != NULL ) {
				allTld->insert( std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntTldObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntTldObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntTldByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTldPKey, cfint::ICFIntTldObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntTldObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntTldObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntTldByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntTldByNameIdxKey, cfint::ICFIntTldObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allTld != NULL ) {
				allTld->insert( std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntTldTableObj::deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfint::ICFIntTldObj*> list;
		cfint::ICFIntTldObj* existingObj = readCachedTldByIdIdx( TenantId,
				Id );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntTldObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntTldBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTldTableObj*>( schema->getTldTableObj() )->reallyDeepDisposeTld( dynamic_cast<cfint::ICFIntTldObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTldTableObj::deepDisposeByTenantIdx( const int64_t TenantId ) {
		static const std::string S_ProcName( "deepDisposeByTenantIdx" );
		std::vector<cfint::ICFIntTldObj*> list;
		std::vector<cfint::ICFIntTldObj*> matchesFound = readCachedTldByTenantIdx( TenantId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntTldObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntTldBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTldTableObj*>( schema->getTldTableObj() )->reallyDeepDisposeTld( dynamic_cast<cfint::ICFIntTldObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTldTableObj::deepDisposeByNameIdx( const int64_t TenantId,
			const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByNameIdx" );
		std::vector<cfint::ICFIntTldObj*> list;
		cfint::ICFIntTldObj* existingObj = readCachedTldByNameIdx( TenantId,
				Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntTldObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntTldBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTldTableObj*>( schema->getTldTableObj() )->reallyDeepDisposeTld( dynamic_cast<cfint::ICFIntTldObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTldTableObj::reallyDeepDisposeTld( cfint::ICFIntTldObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeTld" );

		if( Obj == NULL ) {
			return;
		}

		cfint::ICFIntTldObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->deepDisposeByTldIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfint::CFIntTldBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntTldTableObj*>( schema->getTldTableObj() )->reallyDetachFromIndexesTld( dynamic_cast<cfint::ICFIntTldObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfint::ICFIntTldObj* CFIntTldTableObj::createTld( cfint::ICFIntTldEditObj* Obj ) {
		static const std::string S_ProcName( "createTld" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntTldObj* obj = dynamic_cast<cfint::ICFIntTldObj*>( Obj->getOrig() );
		try {
			cfint::CFIntTldBuff* buff = dynamic_cast<cfint::CFIntTldBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->createTld(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfint::CFIntTldBuff*>( cloneable ) );
			obj = dynamic_cast<cfint::ICFIntTldObj*>( obj->realize() );
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

	cfint::ICFIntTldObj* CFIntTldTableObj::readTld( cfint::CFIntTldPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTld" );
		cfint::ICFIntTldObj* obj = NULL;
		cfint::ICFIntTldObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntTldBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredTenantId(),
			pkey->getRequiredId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntTldTableObj*>( schema->getTldTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfint::ICFIntTldObj*>( obj->realize() );
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

	cfint::ICFIntTldObj* CFIntTldTableObj::lockTld( cfint::CFIntTldPKey* pkey ) {
		static const std::string S_ProcName( "lockTld" );
		cfint::ICFIntTldObj* locked = NULL;
		cfint::CFIntTldBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntTldTableObj*>( schema->getTldTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfint::ICFIntTldObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfint::ICFIntTldObj*> CFIntTldTableObj::readAllTld( bool forceRead ) {
		static const std::string S_ProcName( "readAllTld" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntTldObj* realized = NULL;
		if( forceRead || ( allTld == NULL ) ) {
			std::map<cfint::CFIntTldPKey, cfint::ICFIntTldObj*>* map = new std::map<cfint::CFIntTldPKey,cfint::ICFIntTldObj*>();
			allTld = map;
			std::TCFLibOwningVector<cfint::CFIntTldBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->readAllDerived( schema->getAuthorization() );
			cfint::CFIntTldBuff* buff = NULL;
			cfint::ICFIntTldObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfint::ICFIntTldObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allTld->insert( std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allTld->size();
		std::vector<cfint::ICFIntTldObj*> arr;
		auto valIter = allTld->begin();
		size_t idx = 0;
		while( valIter != allTld->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntTldObj* CFIntTldTableObj::readTldByIdIdx( const int64_t TenantId,
			const int64_t Id, bool forceRead )
	{
		static const std::string S_ProcName( "readTldByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntTldPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntTldObj* obj = readTld( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfint::ICFIntTldObj*> CFIntTldTableObj::readTldByTenantIdx( const int64_t TenantId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTldByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntTldByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntTldPKey, cfint::ICFIntTldObj*>* dict;
		std::map<cfint::CFIntTldPKey, cfint::ICFIntTldObj*>* oldDict;
		if( indexByTenantIdx == NULL ) {
			indexByTenantIdx = new std::map< cfint::CFIntTldByTenantIdxKey,
				std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj*>*>();
		}
		auto searchIndexByTenantIdx = indexByTenantIdx->find( key );
		if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
			oldDict = searchIndexByTenantIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfint::CFIntTldPKey, cfint::ICFIntTldObj*>();
			cfint::ICFIntTldObj* obj;
			std::TCFLibOwningVector<cfint::CFIntTldBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->readDerivedByTenantIdx( schema->getAuthorization(),
				TenantId );
			cfint::CFIntTldBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntTldTableObj*>( schema->getTldTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntTldObj* realized = dynamic_cast<cfint::ICFIntTldObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTenantIdx->erase( searchIndexByTenantIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTenantIdx->insert( std::map< cfint::CFIntTldByTenantIdxKey,
				std::map< cfint::CFIntTldPKey, cfint::ICFIntTldObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntTldObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntTldObj* CFIntTldTableObj::readTldByNameIdx( const int64_t TenantId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readTldByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTldByNameIdxKey,
				cfint::ICFIntTldObj*>();
		}
		cfint::CFIntTldByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfint::ICFIntTldObj* obj = NULL;
		cfint::ICFIntTldObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntTldBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->readDerivedByNameIdx( schema->getAuthorization(),
				TenantId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntTldTableObj*>( schema->getTldTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntTldObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntTldByNameIdxKey, cfint::ICFIntTldObj*>::value_type( key, dynamic_cast<cfint::ICFIntTldObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntTldObj* CFIntTldTableObj::readTldByLookupNameIdx( const int64_t TenantId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readTldByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTldByNameIdxKey,
				cfint::ICFIntTldObj*>();
		}
		cfint::CFIntTldByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfint::ICFIntTldObj* obj = NULL;
		cfint::ICFIntTldObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				obj = searchIndexByNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntTldBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->readDerivedByLookupNameIdx( schema->getAuthorization(),
				TenantId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::ICFIntTldObj*>( dynamic_cast<cfint::CFIntTldTableObj*>( schema->getTldTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntTldObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntTldByNameIdxKey, cfint::ICFIntTldObj*>::value_type( key, dynamic_cast<cfint::ICFIntTldObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntTldObj* CFIntTldTableObj::readCachedTld( cfint::CFIntTldPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTld" );
		cfint::ICFIntTldObj* obj = NULL;
		cfint::ICFIntTldObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfint::ICFIntTldObj* CFIntTldTableObj::readCachedTldByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readCachedTldByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntTldPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntTldObj* obj = readCachedTld( &pkey );
		return( obj );
	}

	std::vector<cfint::ICFIntTldObj*> CFIntTldTableObj::readCachedTldByTenantIdx( const int64_t TenantId )
	{
		static const std::string S_ProcName( "readCachedTldByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntTldObj*> arr;
		cfint::CFIntTldByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntTldPKey, cfint::ICFIntTldObj*>* dict;
		if( indexByTenantIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTenantIdx = indexByTenantIdx->find( key );
		if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
			dict = searchIndexByTenantIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntTldObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntTldObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntTldBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfint::ICFIntTldObj* CFIntTldTableObj::readCachedTldByNameIdx( const int64_t TenantId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedTldByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTldByNameIdxKey,
				cfint::ICFIntTldObj*>();
		}
		cfint::CFIntTldByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfint::ICFIntTldObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntTldBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntTldObj* CFIntTldTableObj::readCachedTldByLookupNameIdx( const int64_t TenantId,
			const std::string& Name )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedTldByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTldByNameIdxKey,
				cfint::ICFIntTldObj*>();
		}
		cfint::CFIntTldByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfint::ICFIntTldObj* obj = NULL;
		cfint::ICFIntTldObj* realized = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntTldBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntTldObj* CFIntTldTableObj::updateTld( cfint::ICFIntTldEditObj* Obj ) {
		static const std::string S_ProcName( "updateTld" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntTldObj* obj = dynamic_cast<cfint::ICFIntTldObj*>( Obj->getOrig() );
		try {
			cfint::CFIntTldBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->updateTld( schema->getAuthorization(),
				dynamic_cast<cfint::CFIntTldBuff*>( Obj->getTldBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfint::ICFIntTldObj*>( dynamic_cast<cfint::CFIntTldTableObj*>( schema->getTldTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfint::ICFIntTldObj*>( obj->realize() );
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

	void CFIntTldTableObj::deleteTld( cfint::ICFIntTldEditObj* Obj ) {
		cfint::ICFIntTldObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->deleteTld( schema->getAuthorization(),
			obj->getTldBuff() );
		deepDisposeByIdIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
	}

	void CFIntTldTableObj::deleteTldByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		cfint::CFIntTldPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntTldObj* obj = readTld( &pkey, true );
		if( obj != NULL ) {
			cfint::ICFIntTldEditObj* editObj = dynamic_cast<cfint::ICFIntTldEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfint::ICFIntTldEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntTldTableObj::deleteTldByTenantIdx( const int64_t TenantId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->deleteTldByTenantIdx( schema->getAuthorization(),
				TenantId );
		deepDisposeByTenantIdx( TenantId );
	}

	void CFIntTldTableObj::deleteTldByNameIdx( const int64_t TenantId,
			const std::string& Name )
	{
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTldByNameIdxKey,
				cfint::ICFIntTldObj*>();
		}
		cfint::CFIntTldByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfint::ICFIntTldObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->deleteTldByNameIdx( schema->getAuthorization(),
				TenantId,
				Name );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTld()->deleteTldByNameIdx( schema->getAuthorization(),
				TenantId,
				Name );
		}
		deepDisposeByNameIdx( TenantId,
			Name );
	}

	void CFIntTldTableObj::reallyDetachFromIndexesTld( cfint::ICFIntTldObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesTld" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntTldObj* obj = Obj;
		cfint::CFIntTldPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfint::ICFIntTldObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByTenantIdx != NULL ) {
				cfint::CFIntTldByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTldPKey, cfint::ICFIntTldObj*>* mapTenantIdx = searchTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						auto removalProbe = mapTenantIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapTenantIdx->end() ) {
							mapTenantIdx->erase( removalProbe );
							if( mapTenantIdx->empty() ) {
								delete mapTenantIdx;
								mapTenantIdx = NULL;
								indexByTenantIdx->erase( searchTenantIdx );
							}
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntTldByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyNameIdx.setRequiredName( obj->getRequiredName() );
				auto removalProbe = indexByNameIdx->find( keyNameIdx );
				if( removalProbe != indexByNameIdx->end() ) {
					indexByNameIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
