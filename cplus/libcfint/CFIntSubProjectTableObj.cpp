// Description: C++18 Table Object implementation for CFInt.

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

	const std::string CFIntSubProjectTableObj::CLASS_NAME( "CFIntSubProjectTableObj" );
	const std::string CFIntSubProjectTableObj::TABLE_NAME( "SubProject" );
	const std::string CFIntSubProjectTableObj::TABLE_DBNAME( "sprjdef" );

	CFIntSubProjectTableObj::CFIntSubProjectTableObj() {
		schema = NULL;
		members = new std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>();
		allSubProject = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntSubProjectByTenantIdxKey,
			std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>*>();
		indexByTopProjectIdx = new std::map< cfint::CFIntSubProjectByTopProjectIdxKey,
			std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntSubProjectByNameIdxKey,
			cfint::ICFIntSubProjectObj*>();
	}

	CFIntSubProjectTableObj::CFIntSubProjectTableObj( cfint::ICFIntSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>();
		allSubProject = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntSubProjectByTenantIdxKey,
			std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>*>();
		indexByTopProjectIdx = new std::map< cfint::CFIntSubProjectByTopProjectIdxKey,
			std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntSubProjectByNameIdxKey,
			cfint::ICFIntSubProjectObj*>();
	}

	CFIntSubProjectTableObj::~CFIntSubProjectTableObj() {
		minimizeMemory();
		if( indexByTenantIdx != NULL ) {
			delete indexByTenantIdx;
			indexByTenantIdx = NULL;
		}
		if( indexByTopProjectIdx != NULL ) {
			delete indexByTopProjectIdx;
			indexByTopProjectIdx = NULL;
		}
		if( indexByNameIdx != NULL ) {
			delete indexByNameIdx;
			indexByNameIdx = NULL;
		}
		if( members != NULL ) {
			cfint::ICFIntSubProjectObj* curMember;
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

	cfint::ICFIntSchemaObj* CFIntSubProjectTableObj::getSchema() {
		return( schema );
	}

	void CFIntSubProjectTableObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntSubProjectTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntSubProjectTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntSubProjectTableObj::getObjQualifyingClassCode() {
		return( &cfsec::CFSecTenantBuff::CLASS_CODE );
	}


	void CFIntSubProjectTableObj::minimizeMemory() {
		if( allSubProject != NULL ) {
			allSubProject->clear();
			delete allSubProject;
			allSubProject = NULL;
		}
		if( indexByTenantIdx != NULL ) {
			std::map< cfint::CFIntSubProjectByTenantIdxKey,
				std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* >::iterator iterByTenantIdx = indexByTenantIdx->begin();
			std::map< cfint::CFIntSubProjectByTenantIdxKey,
				std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* >::iterator endByTenantIdx = indexByTenantIdx->end();
			std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* curByTenantIdx = NULL;
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
		if( indexByTopProjectIdx != NULL ) {
			std::map< cfint::CFIntSubProjectByTopProjectIdxKey,
				std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* >::iterator iterByTopProjectIdx = indexByTopProjectIdx->begin();
			std::map< cfint::CFIntSubProjectByTopProjectIdxKey,
				std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* >::iterator endByTopProjectIdx = indexByTopProjectIdx->end();
			std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* curByTopProjectIdx = NULL;
			while( iterByTopProjectIdx != endByTopProjectIdx ) {
				curByTopProjectIdx = iterByTopProjectIdx->second;
				if( curByTopProjectIdx != NULL ) {
					curByTopProjectIdx->clear();
					delete curByTopProjectIdx;
					curByTopProjectIdx = NULL;
					iterByTopProjectIdx->second = NULL;
				}
				iterByTopProjectIdx ++;
			}
			indexByTopProjectIdx->clear();
		}
		if( indexByNameIdx != NULL ) {
			indexByNameIdx->clear();
		}
		if( members != NULL ) {
			cfint::ICFIntSubProjectObj* cur = NULL;
			cfint::ICFIntSubProjectEditObj* edit = NULL;
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

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::newInstance() {
		cfint::ICFIntSubProjectObj* inst = dynamic_cast<cfint::ICFIntSubProjectObj*>( new CFIntSubProjectObj( schema ) );
		return( inst );
	}

	cfint::ICFIntSubProjectEditObj* CFIntSubProjectTableObj::newEditInstance( cfint::ICFIntSubProjectObj* orig ) {
		cfint::ICFIntSubProjectEditObj* edit = dynamic_cast<cfint::ICFIntSubProjectEditObj*>( new CFIntSubProjectEditObj( orig ));
		return( edit );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::realizeSubProject( cfint::ICFIntSubProjectObj* Obj ) {
		static const std::string S_ProcName( "realizeSubProject" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntSubProjectObj* obj = Obj;
		cfint::ICFIntSubProjectObj* existingObj = NULL;
		cfint::CFIntSubProjectPKey* pkey = obj->getPKey();
		cfint::ICFIntSubProjectObj* keepObj = NULL;
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
				cfint::CFIntSubProjectByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* mapTenantIdx = searchTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						auto removalProbe = mapTenantIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTenantIdx->end() ) {
							mapTenantIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByTopProjectIdx != NULL ) {
				cfint::CFIntSubProjectByTopProjectIdxKey keyTopProjectIdx;
				keyTopProjectIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTopProjectIdx.setRequiredTopProjectId( keepObj->getRequiredTopProjectId() );
				auto searchTopProjectIdx = indexByTopProjectIdx->find( keyTopProjectIdx );
				if( searchTopProjectIdx != indexByTopProjectIdx->end() ) {
					std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* mapTopProjectIdx = searchTopProjectIdx->second;
					if( mapTopProjectIdx != NULL ) {
						auto removalProbe = mapTopProjectIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTopProjectIdx->end() ) {
							mapTopProjectIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntSubProjectByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredTopProjectId( keepObj->getRequiredTopProjectId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByNameIdx->find( keyNameIdx );
				if( removalProbe != indexByNameIdx->end() ) {
					indexByNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfint::CFIntSubProjectBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntSubProjectObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntSubProjectObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntSubProjectByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByTopProjectIdx != NULL ) {
				static const std::string S_ATopProjectIdxObj( "aTopProjectIdxObj" );
				cfint::ICFIntSubProjectObj* aTopProjectIdxObj =
					dynamic_cast<cfint::ICFIntSubProjectObj*>( keepObj );
				if( aTopProjectIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATopProjectIdxObj );
				}
				cfint::CFIntSubProjectByTopProjectIdxKey keyTopProjectIdx;
				keyTopProjectIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTopProjectIdx.setRequiredTopProjectId( keepObj->getRequiredTopProjectId() );
				auto searchIndexByTopProjectIdx = indexByTopProjectIdx->find( keyTopProjectIdx );
				if( searchIndexByTopProjectIdx != indexByTopProjectIdx->end() ) {
					std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* mapTopProjectIdx = searchIndexByTopProjectIdx->second;
					if( mapTopProjectIdx != NULL ) {
						mapTopProjectIdx->insert( std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >::value_type( *(keepObj->getPKey()), aTopProjectIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntSubProjectObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntSubProjectObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntSubProjectByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredTopProjectId( keepObj->getRequiredTopProjectId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntSubProjectByNameIdxKey, cfint::ICFIntSubProjectObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allSubProject != NULL ) {
				allSubProject->insert( std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntSubProjectObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntSubProjectObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntSubProjectByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByTopProjectIdx != NULL ) {
				static const std::string S_ATopProjectIdxObj( "aTopProjectIdxObj" );
				cfint::ICFIntSubProjectObj* aTopProjectIdxObj =
					dynamic_cast<cfint::ICFIntSubProjectObj*>( keepObj );
				if( aTopProjectIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATopProjectIdxObj );
				}
				cfint::CFIntSubProjectByTopProjectIdxKey keyTopProjectIdx;
				keyTopProjectIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTopProjectIdx.setRequiredTopProjectId( keepObj->getRequiredTopProjectId() );
				auto searchIndexByTopProjectIdx = indexByTopProjectIdx->find( keyTopProjectIdx );
				if( searchIndexByTopProjectIdx != indexByTopProjectIdx->end() ) {
					std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* mapTopProjectIdx = searchIndexByTopProjectIdx->second;
					if( mapTopProjectIdx != NULL ) {
						mapTopProjectIdx->insert( std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >::value_type( *(keepObj->getPKey()), aTopProjectIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntSubProjectObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntSubProjectObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntSubProjectByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredTopProjectId( keepObj->getRequiredTopProjectId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntSubProjectByNameIdxKey, cfint::ICFIntSubProjectObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allSubProject != NULL ) {
				allSubProject->insert( std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntSubProjectTableObj::deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfint::ICFIntSubProjectObj*> list;
		cfint::ICFIntSubProjectObj* existingObj = readCachedSubProjectByIdIdx( TenantId,
				Id );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntSubProjectObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntSubProjectBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->reallyDeepDisposeSubProject( dynamic_cast<cfint::ICFIntSubProjectObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSubProjectTableObj::deepDisposeByTenantIdx( const int64_t TenantId ) {
		static const std::string S_ProcName( "deepDisposeByTenantIdx" );
		std::vector<cfint::ICFIntSubProjectObj*> list;
		std::vector<cfint::ICFIntSubProjectObj*> matchesFound = readCachedSubProjectByTenantIdx( TenantId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntSubProjectObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntSubProjectBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->reallyDeepDisposeSubProject( dynamic_cast<cfint::ICFIntSubProjectObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSubProjectTableObj::deepDisposeByTopProjectIdx( const int64_t TenantId,
			const int64_t TopProjectId ) {
		static const std::string S_ProcName( "deepDisposeByTopProjectIdx" );
		std::vector<cfint::ICFIntSubProjectObj*> list;
		std::vector<cfint::ICFIntSubProjectObj*> matchesFound = readCachedSubProjectByTopProjectIdx( TenantId,
				TopProjectId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntSubProjectObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntSubProjectBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->reallyDeepDisposeSubProject( dynamic_cast<cfint::ICFIntSubProjectObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSubProjectTableObj::deepDisposeByNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByNameIdx" );
		std::vector<cfint::ICFIntSubProjectObj*> list;
		cfint::ICFIntSubProjectObj* existingObj = readCachedSubProjectByNameIdx( TenantId,
				TopProjectId,
				Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntSubProjectObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntSubProjectBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->reallyDeepDisposeSubProject( dynamic_cast<cfint::ICFIntSubProjectObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSubProjectTableObj::reallyDeepDisposeSubProject( cfint::ICFIntSubProjectObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSubProject" );

		if( Obj == NULL ) {
			return;
		}

		cfint::ICFIntSubProjectObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->deepDisposeBySubProjectIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfint::CFIntSubProjectBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->reallyDetachFromIndexesSubProject( dynamic_cast<cfint::ICFIntSubProjectObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::createSubProject( cfint::ICFIntSubProjectEditObj* Obj ) {
		static const std::string S_ProcName( "createSubProject" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntSubProjectObj* obj = dynamic_cast<cfint::ICFIntSubProjectObj*>( Obj->getOrig() );
		try {
			cfint::CFIntSubProjectBuff* buff = dynamic_cast<cfint::CFIntSubProjectBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->createSubProject(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfint::CFIntSubProjectBuff*>( cloneable ) );
			obj = dynamic_cast<cfint::ICFIntSubProjectObj*>( obj->realize() );
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

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::readSubProject( cfint::CFIntSubProjectPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSubProject" );
		cfint::ICFIntSubProjectObj* obj = NULL;
		cfint::ICFIntSubProjectObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntSubProjectBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredTenantId(),
			pkey->getRequiredId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfint::ICFIntSubProjectObj*>( obj->realize() );
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

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::lockSubProject( cfint::CFIntSubProjectPKey* pkey ) {
		static const std::string S_ProcName( "lockSubProject" );
		cfint::ICFIntSubProjectObj* locked = NULL;
		cfint::CFIntSubProjectBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfint::ICFIntSubProjectObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfint::ICFIntSubProjectObj*> CFIntSubProjectTableObj::readAllSubProject( bool forceRead ) {
		static const std::string S_ProcName( "readAllSubProject" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntSubProjectObj* realized = NULL;
		if( forceRead || ( allSubProject == NULL ) ) {
			std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* map = new std::map<cfint::CFIntSubProjectPKey,cfint::ICFIntSubProjectObj*>();
			allSubProject = map;
			std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->readAllDerived( schema->getAuthorization() );
			cfint::CFIntSubProjectBuff* buff = NULL;
			cfint::ICFIntSubProjectObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfint::ICFIntSubProjectObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSubProject->insert( std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSubProject->size();
		std::vector<cfint::ICFIntSubProjectObj*> arr;
		auto valIter = allSubProject->begin();
		size_t idx = 0;
		while( valIter != allSubProject->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::readSubProjectByIdIdx( const int64_t TenantId,
			const int64_t Id, bool forceRead )
	{
		static const std::string S_ProcName( "readSubProjectByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntSubProjectPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntSubProjectObj* obj = readSubProject( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfint::ICFIntSubProjectObj*> CFIntSubProjectTableObj::readSubProjectByTenantIdx( const int64_t TenantId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSubProjectByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntSubProjectByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* dict;
		std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* oldDict;
		if( indexByTenantIdx == NULL ) {
			indexByTenantIdx = new std::map< cfint::CFIntSubProjectByTenantIdxKey,
				std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>*>();
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
			dict = new std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>();
			cfint::ICFIntSubProjectObj* obj;
			std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->readDerivedByTenantIdx( schema->getAuthorization(),
				TenantId );
			cfint::CFIntSubProjectBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntSubProjectObj* realized = dynamic_cast<cfint::ICFIntSubProjectObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTenantIdx->erase( searchIndexByTenantIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTenantIdx->insert( std::map< cfint::CFIntSubProjectByTenantIdxKey,
				std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntSubProjectObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfint::ICFIntSubProjectObj*> CFIntSubProjectTableObj::readSubProjectByTopProjectIdx( const int64_t TenantId,
			const int64_t TopProjectId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSubProjectByTopProjectIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntSubProjectByTopProjectIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* dict;
		std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* oldDict;
		if( indexByTopProjectIdx == NULL ) {
			indexByTopProjectIdx = new std::map< cfint::CFIntSubProjectByTopProjectIdxKey,
				std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>*>();
		}
		auto searchIndexByTopProjectIdx = indexByTopProjectIdx->find( key );
		if( searchIndexByTopProjectIdx != indexByTopProjectIdx->end() ) {
			oldDict = searchIndexByTopProjectIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>();
			cfint::ICFIntSubProjectObj* obj;
			std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->readDerivedByTopProjectIdx( schema->getAuthorization(),
				TenantId,
				TopProjectId );
			cfint::CFIntSubProjectBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntSubProjectObj* realized = dynamic_cast<cfint::ICFIntSubProjectObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTopProjectIdx->erase( searchIndexByTopProjectIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTopProjectIdx->insert( std::map< cfint::CFIntSubProjectByTopProjectIdxKey,
				std::map< cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntSubProjectObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::readSubProjectByNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readSubProjectByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntSubProjectByNameIdxKey,
				cfint::ICFIntSubProjectObj*>();
		}
		cfint::CFIntSubProjectByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		key.setRequiredName( Name );
		cfint::ICFIntSubProjectObj* obj = NULL;
		cfint::ICFIntSubProjectObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntSubProjectBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->readDerivedByNameIdx( schema->getAuthorization(),
				TenantId,
				TopProjectId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntSubProjectObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntSubProjectByNameIdxKey, cfint::ICFIntSubProjectObj*>::value_type( key, dynamic_cast<cfint::ICFIntSubProjectObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::readSubProjectByLookupNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readSubProjectByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntSubProjectByNameIdxKey,
				cfint::ICFIntSubProjectObj*>();
		}
		cfint::CFIntSubProjectByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		key.setRequiredName( Name );
		cfint::ICFIntSubProjectObj* obj = NULL;
		cfint::ICFIntSubProjectObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				obj = searchIndexByNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntSubProjectBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->readDerivedByLookupNameIdx( schema->getAuthorization(),
				TenantId,
				TopProjectId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::ICFIntSubProjectObj*>( dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntSubProjectObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntSubProjectByNameIdxKey, cfint::ICFIntSubProjectObj*>::value_type( key, dynamic_cast<cfint::ICFIntSubProjectObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::readCachedSubProject( cfint::CFIntSubProjectPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSubProject" );
		cfint::ICFIntSubProjectObj* obj = NULL;
		cfint::ICFIntSubProjectObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::readCachedSubProjectByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readCachedSubProjectByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntSubProjectPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntSubProjectObj* obj = readCachedSubProject( &pkey );
		return( obj );
	}

	std::vector<cfint::ICFIntSubProjectObj*> CFIntSubProjectTableObj::readCachedSubProjectByTenantIdx( const int64_t TenantId )
	{
		static const std::string S_ProcName( "readCachedSubProjectByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntSubProjectObj*> arr;
		cfint::CFIntSubProjectByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* dict;
		if( indexByTenantIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTenantIdx = indexByTenantIdx->find( key );
		if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
			dict = searchIndexByTenantIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntSubProjectObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntSubProjectObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntSubProjectBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfint::ICFIntSubProjectObj*> CFIntSubProjectTableObj::readCachedSubProjectByTopProjectIdx( const int64_t TenantId,
			const int64_t TopProjectId )
	{
		static const std::string S_ProcName( "readCachedSubProjectByTopProjectIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntSubProjectObj*> arr;
		cfint::CFIntSubProjectByTopProjectIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* dict;
		if( indexByTopProjectIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTopProjectIdx = indexByTopProjectIdx->find( key );
		if( searchIndexByTopProjectIdx != indexByTopProjectIdx->end() ) {
			dict = searchIndexByTopProjectIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntSubProjectObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntSubProjectObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntSubProjectBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::readCachedSubProjectByNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedSubProjectByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntSubProjectByNameIdxKey,
				cfint::ICFIntSubProjectObj*>();
		}
		cfint::CFIntSubProjectByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		key.setRequiredName( Name );
		cfint::ICFIntSubProjectObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntSubProjectBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::readCachedSubProjectByLookupNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedSubProjectByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntSubProjectByNameIdxKey,
				cfint::ICFIntSubProjectObj*>();
		}
		cfint::CFIntSubProjectByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		key.setRequiredName( Name );
		cfint::ICFIntSubProjectObj* obj = NULL;
		cfint::ICFIntSubProjectObj* realized = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntSubProjectBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntSubProjectObj* CFIntSubProjectTableObj::updateSubProject( cfint::ICFIntSubProjectEditObj* Obj ) {
		static const std::string S_ProcName( "updateSubProject" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntSubProjectObj* obj = dynamic_cast<cfint::ICFIntSubProjectObj*>( Obj->getOrig() );
		try {
			cfint::CFIntSubProjectBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->updateSubProject( schema->getAuthorization(),
				dynamic_cast<cfint::CFIntSubProjectBuff*>( Obj->getSubProjectBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfint::ICFIntSubProjectObj*>( dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfint::ICFIntSubProjectObj*>( obj->realize() );
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

	void CFIntSubProjectTableObj::deleteSubProject( cfint::ICFIntSubProjectEditObj* Obj ) {
		cfint::ICFIntSubProjectObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->deleteSubProject( schema->getAuthorization(),
			obj->getSubProjectBuff() );
		deepDisposeByIdIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
	}

	void CFIntSubProjectTableObj::deleteSubProjectByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		cfint::CFIntSubProjectPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntSubProjectObj* obj = readSubProject( &pkey, true );
		if( obj != NULL ) {
			cfint::ICFIntSubProjectEditObj* editObj = dynamic_cast<cfint::ICFIntSubProjectEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfint::ICFIntSubProjectEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntSubProjectTableObj::deleteSubProjectByTenantIdx( const int64_t TenantId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->deleteSubProjectByTenantIdx( schema->getAuthorization(),
				TenantId );
		deepDisposeByTenantIdx( TenantId );
	}

	void CFIntSubProjectTableObj::deleteSubProjectByTopProjectIdx( const int64_t TenantId,
			const int64_t TopProjectId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->deleteSubProjectByTopProjectIdx( schema->getAuthorization(),
				TenantId,
				TopProjectId );
		deepDisposeByTopProjectIdx( TenantId,
			TopProjectId );
	}

	void CFIntSubProjectTableObj::deleteSubProjectByNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name )
	{
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntSubProjectByNameIdxKey,
				cfint::ICFIntSubProjectObj*>();
		}
		cfint::CFIntSubProjectByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		key.setRequiredName( Name );
		cfint::ICFIntSubProjectObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->deleteSubProjectByNameIdx( schema->getAuthorization(),
				TenantId,
				TopProjectId,
				Name );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSubProject()->deleteSubProjectByNameIdx( schema->getAuthorization(),
				TenantId,
				TopProjectId,
				Name );
		}
		deepDisposeByNameIdx( TenantId,
			TopProjectId,
			Name );
	}

	void CFIntSubProjectTableObj::reallyDetachFromIndexesSubProject( cfint::ICFIntSubProjectObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSubProject" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntSubProjectObj* obj = Obj;
		cfint::CFIntSubProjectPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfint::ICFIntSubProjectObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByTenantIdx != NULL ) {
				cfint::CFIntSubProjectByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* mapTenantIdx = searchTenantIdx->second;
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

			if( indexByTopProjectIdx != NULL ) {
				cfint::CFIntSubProjectByTopProjectIdxKey keyTopProjectIdx;
				keyTopProjectIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyTopProjectIdx.setRequiredTopProjectId( obj->getRequiredTopProjectId() );
				auto searchTopProjectIdx = indexByTopProjectIdx->find( keyTopProjectIdx );
				if( searchTopProjectIdx != indexByTopProjectIdx->end() ) {
					std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* mapTopProjectIdx = searchTopProjectIdx->second;
					if( mapTopProjectIdx != NULL ) {
						auto removalProbe = mapTopProjectIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapTopProjectIdx->end() ) {
							mapTopProjectIdx->erase( removalProbe );
							if( mapTopProjectIdx->empty() ) {
								delete mapTopProjectIdx;
								mapTopProjectIdx = NULL;
								indexByTopProjectIdx->erase( searchTopProjectIdx );
							}
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntSubProjectByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyNameIdx.setRequiredTopProjectId( obj->getRequiredTopProjectId() );
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
