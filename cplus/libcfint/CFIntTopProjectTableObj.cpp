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

	const std::string CFIntTopProjectTableObj::CLASS_NAME( "CFIntTopProjectTableObj" );
	const std::string CFIntTopProjectTableObj::TABLE_NAME( "TopProject" );
	const std::string CFIntTopProjectTableObj::TABLE_DBNAME( "tprjdef" );

	CFIntTopProjectTableObj::CFIntTopProjectTableObj() {
		schema = NULL;
		members = new std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>();
		allTopProject = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntTopProjectByTenantIdxKey,
			std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>*>();
		indexByTopDomainIdx = new std::map< cfint::CFIntTopProjectByTopDomainIdxKey,
			std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntTopProjectByNameIdxKey,
			cfint::ICFIntTopProjectObj*>();
	}

	CFIntTopProjectTableObj::CFIntTopProjectTableObj( cfint::ICFIntSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>();
		allTopProject = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntTopProjectByTenantIdxKey,
			std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>*>();
		indexByTopDomainIdx = new std::map< cfint::CFIntTopProjectByTopDomainIdxKey,
			std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntTopProjectByNameIdxKey,
			cfint::ICFIntTopProjectObj*>();
	}

	CFIntTopProjectTableObj::~CFIntTopProjectTableObj() {
		minimizeMemory();
		if( indexByTenantIdx != NULL ) {
			delete indexByTenantIdx;
			indexByTenantIdx = NULL;
		}
		if( indexByTopDomainIdx != NULL ) {
			delete indexByTopDomainIdx;
			indexByTopDomainIdx = NULL;
		}
		if( indexByNameIdx != NULL ) {
			delete indexByNameIdx;
			indexByNameIdx = NULL;
		}
		if( members != NULL ) {
			cfint::ICFIntTopProjectObj* curMember;
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

	cfint::ICFIntSchemaObj* CFIntTopProjectTableObj::getSchema() {
		return( schema );
	}

	void CFIntTopProjectTableObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntTopProjectTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntTopProjectTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntTopProjectTableObj::getObjQualifyingClassCode() {
		return( &cfsec::CFSecTenantBuff::CLASS_CODE );
	}


	void CFIntTopProjectTableObj::minimizeMemory() {
		if( allTopProject != NULL ) {
			allTopProject->clear();
			delete allTopProject;
			allTopProject = NULL;
		}
		if( indexByTenantIdx != NULL ) {
			std::map< cfint::CFIntTopProjectByTenantIdxKey,
				std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* >::iterator iterByTenantIdx = indexByTenantIdx->begin();
			std::map< cfint::CFIntTopProjectByTenantIdxKey,
				std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* >::iterator endByTenantIdx = indexByTenantIdx->end();
			std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* curByTenantIdx = NULL;
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
		if( indexByTopDomainIdx != NULL ) {
			std::map< cfint::CFIntTopProjectByTopDomainIdxKey,
				std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* >::iterator iterByTopDomainIdx = indexByTopDomainIdx->begin();
			std::map< cfint::CFIntTopProjectByTopDomainIdxKey,
				std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* >::iterator endByTopDomainIdx = indexByTopDomainIdx->end();
			std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* curByTopDomainIdx = NULL;
			while( iterByTopDomainIdx != endByTopDomainIdx ) {
				curByTopDomainIdx = iterByTopDomainIdx->second;
				if( curByTopDomainIdx != NULL ) {
					curByTopDomainIdx->clear();
					delete curByTopDomainIdx;
					curByTopDomainIdx = NULL;
					iterByTopDomainIdx->second = NULL;
				}
				iterByTopDomainIdx ++;
			}
			indexByTopDomainIdx->clear();
		}
		if( indexByNameIdx != NULL ) {
			indexByNameIdx->clear();
		}
		if( members != NULL ) {
			cfint::ICFIntTopProjectObj* cur = NULL;
			cfint::ICFIntTopProjectEditObj* edit = NULL;
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

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::newInstance() {
		cfint::ICFIntTopProjectObj* inst = dynamic_cast<cfint::ICFIntTopProjectObj*>( new CFIntTopProjectObj( schema ) );
		return( inst );
	}

	cfint::ICFIntTopProjectEditObj* CFIntTopProjectTableObj::newEditInstance( cfint::ICFIntTopProjectObj* orig ) {
		cfint::ICFIntTopProjectEditObj* edit = dynamic_cast<cfint::ICFIntTopProjectEditObj*>( new CFIntTopProjectEditObj( orig ));
		return( edit );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::realizeTopProject( cfint::ICFIntTopProjectObj* Obj ) {
		static const std::string S_ProcName( "realizeTopProject" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntTopProjectObj* obj = Obj;
		cfint::ICFIntTopProjectObj* existingObj = NULL;
		cfint::CFIntTopProjectPKey* pkey = obj->getPKey();
		cfint::ICFIntTopProjectObj* keepObj = NULL;
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
				cfint::CFIntTopProjectByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* mapTenantIdx = searchTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						auto removalProbe = mapTenantIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTenantIdx->end() ) {
							mapTenantIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByTopDomainIdx != NULL ) {
				cfint::CFIntTopProjectByTopDomainIdxKey keyTopDomainIdx;
				keyTopDomainIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTopDomainIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				auto searchTopDomainIdx = indexByTopDomainIdx->find( keyTopDomainIdx );
				if( searchTopDomainIdx != indexByTopDomainIdx->end() ) {
					std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* mapTopDomainIdx = searchTopDomainIdx->second;
					if( mapTopDomainIdx != NULL ) {
						auto removalProbe = mapTopDomainIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTopDomainIdx->end() ) {
							mapTopDomainIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntTopProjectByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByNameIdx->find( keyNameIdx );
				if( removalProbe != indexByNameIdx->end() ) {
					indexByNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfint::CFIntTopProjectBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntTopProjectObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntTopProjectObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntTopProjectByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByTopDomainIdx != NULL ) {
				static const std::string S_ATopDomainIdxObj( "aTopDomainIdxObj" );
				cfint::ICFIntTopProjectObj* aTopDomainIdxObj =
					dynamic_cast<cfint::ICFIntTopProjectObj*>( keepObj );
				if( aTopDomainIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATopDomainIdxObj );
				}
				cfint::CFIntTopProjectByTopDomainIdxKey keyTopDomainIdx;
				keyTopDomainIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTopDomainIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				auto searchIndexByTopDomainIdx = indexByTopDomainIdx->find( keyTopDomainIdx );
				if( searchIndexByTopDomainIdx != indexByTopDomainIdx->end() ) {
					std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* mapTopDomainIdx = searchIndexByTopDomainIdx->second;
					if( mapTopDomainIdx != NULL ) {
						mapTopDomainIdx->insert( std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >::value_type( *(keepObj->getPKey()), aTopDomainIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntTopProjectObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntTopProjectObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntTopProjectByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntTopProjectByNameIdxKey, cfint::ICFIntTopProjectObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allTopProject != NULL ) {
				allTopProject->insert( std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntTopProjectObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntTopProjectObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntTopProjectByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByTopDomainIdx != NULL ) {
				static const std::string S_ATopDomainIdxObj( "aTopDomainIdxObj" );
				cfint::ICFIntTopProjectObj* aTopDomainIdxObj =
					dynamic_cast<cfint::ICFIntTopProjectObj*>( keepObj );
				if( aTopDomainIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATopDomainIdxObj );
				}
				cfint::CFIntTopProjectByTopDomainIdxKey keyTopDomainIdx;
				keyTopDomainIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTopDomainIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				auto searchIndexByTopDomainIdx = indexByTopDomainIdx->find( keyTopDomainIdx );
				if( searchIndexByTopDomainIdx != indexByTopDomainIdx->end() ) {
					std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* mapTopDomainIdx = searchIndexByTopDomainIdx->second;
					if( mapTopDomainIdx != NULL ) {
						mapTopDomainIdx->insert( std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >::value_type( *(keepObj->getPKey()), aTopDomainIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntTopProjectObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntTopProjectObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntTopProjectByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntTopProjectByNameIdxKey, cfint::ICFIntTopProjectObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allTopProject != NULL ) {
				allTopProject->insert( std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntTopProjectTableObj::deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfint::ICFIntTopProjectObj*> list;
		cfint::ICFIntTopProjectObj* existingObj = readCachedTopProjectByIdIdx( TenantId,
				Id );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntTopProjectObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->reallyDeepDisposeTopProject( dynamic_cast<cfint::ICFIntTopProjectObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTopProjectTableObj::deepDisposeByTenantIdx( const int64_t TenantId ) {
		static const std::string S_ProcName( "deepDisposeByTenantIdx" );
		std::vector<cfint::ICFIntTopProjectObj*> list;
		std::vector<cfint::ICFIntTopProjectObj*> matchesFound = readCachedTopProjectByTenantIdx( TenantId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntTopProjectObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->reallyDeepDisposeTopProject( dynamic_cast<cfint::ICFIntTopProjectObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTopProjectTableObj::deepDisposeByTopDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId ) {
		static const std::string S_ProcName( "deepDisposeByTopDomainIdx" );
		std::vector<cfint::ICFIntTopProjectObj*> list;
		std::vector<cfint::ICFIntTopProjectObj*> matchesFound = readCachedTopProjectByTopDomainIdx( TenantId,
				TopDomainId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntTopProjectObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->reallyDeepDisposeTopProject( dynamic_cast<cfint::ICFIntTopProjectObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTopProjectTableObj::deepDisposeByNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByNameIdx" );
		std::vector<cfint::ICFIntTopProjectObj*> list;
		cfint::ICFIntTopProjectObj* existingObj = readCachedTopProjectByNameIdx( TenantId,
				TopDomainId,
				Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntTopProjectObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->reallyDeepDisposeTopProject( dynamic_cast<cfint::ICFIntTopProjectObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTopProjectTableObj::reallyDeepDisposeTopProject( cfint::ICFIntTopProjectObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeTopProject" );

		if( Obj == NULL ) {
			return;
		}

		cfint::ICFIntTopProjectObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntSubProjectTableObj*>( schema->getSubProjectTableObj() )->deepDisposeByTopProjectIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->reallyDetachFromIndexesTopProject( dynamic_cast<cfint::ICFIntTopProjectObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::createTopProject( cfint::ICFIntTopProjectEditObj* Obj ) {
		static const std::string S_ProcName( "createTopProject" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntTopProjectObj* obj = dynamic_cast<cfint::ICFIntTopProjectObj*>( Obj->getOrig() );
		try {
			cfint::CFIntTopProjectBuff* buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->createTopProject(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfint::CFIntTopProjectBuff*>( cloneable ) );
			obj = dynamic_cast<cfint::ICFIntTopProjectObj*>( obj->realize() );
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

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::readTopProject( cfint::CFIntTopProjectPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTopProject" );
		cfint::ICFIntTopProjectObj* obj = NULL;
		cfint::ICFIntTopProjectObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntTopProjectBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredTenantId(),
			pkey->getRequiredId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfint::ICFIntTopProjectObj*>( obj->realize() );
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

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::lockTopProject( cfint::CFIntTopProjectPKey* pkey ) {
		static const std::string S_ProcName( "lockTopProject" );
		cfint::ICFIntTopProjectObj* locked = NULL;
		cfint::CFIntTopProjectBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfint::ICFIntTopProjectObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfint::ICFIntTopProjectObj*> CFIntTopProjectTableObj::readAllTopProject( bool forceRead ) {
		static const std::string S_ProcName( "readAllTopProject" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntTopProjectObj* realized = NULL;
		if( forceRead || ( allTopProject == NULL ) ) {
			std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* map = new std::map<cfint::CFIntTopProjectPKey,cfint::ICFIntTopProjectObj*>();
			allTopProject = map;
			std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->readAllDerived( schema->getAuthorization() );
			cfint::CFIntTopProjectBuff* buff = NULL;
			cfint::ICFIntTopProjectObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfint::ICFIntTopProjectObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allTopProject->insert( std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allTopProject->size();
		std::vector<cfint::ICFIntTopProjectObj*> arr;
		auto valIter = allTopProject->begin();
		size_t idx = 0;
		while( valIter != allTopProject->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::readTopProjectByIdIdx( const int64_t TenantId,
			const int64_t Id, bool forceRead )
	{
		static const std::string S_ProcName( "readTopProjectByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntTopProjectPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntTopProjectObj* obj = readTopProject( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfint::ICFIntTopProjectObj*> CFIntTopProjectTableObj::readTopProjectByTenantIdx( const int64_t TenantId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTopProjectByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntTopProjectByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* dict;
		std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* oldDict;
		if( indexByTenantIdx == NULL ) {
			indexByTenantIdx = new std::map< cfint::CFIntTopProjectByTenantIdxKey,
				std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>*>();
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
			dict = new std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>();
			cfint::ICFIntTopProjectObj* obj;
			std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->readDerivedByTenantIdx( schema->getAuthorization(),
				TenantId );
			cfint::CFIntTopProjectBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntTopProjectObj* realized = dynamic_cast<cfint::ICFIntTopProjectObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTenantIdx->erase( searchIndexByTenantIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTenantIdx->insert( std::map< cfint::CFIntTopProjectByTenantIdxKey,
				std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntTopProjectObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfint::ICFIntTopProjectObj*> CFIntTopProjectTableObj::readTopProjectByTopDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTopProjectByTopDomainIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntTopProjectByTopDomainIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* dict;
		std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* oldDict;
		if( indexByTopDomainIdx == NULL ) {
			indexByTopDomainIdx = new std::map< cfint::CFIntTopProjectByTopDomainIdxKey,
				std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>*>();
		}
		auto searchIndexByTopDomainIdx = indexByTopDomainIdx->find( key );
		if( searchIndexByTopDomainIdx != indexByTopDomainIdx->end() ) {
			oldDict = searchIndexByTopDomainIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>();
			cfint::ICFIntTopProjectObj* obj;
			std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->readDerivedByTopDomainIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId );
			cfint::CFIntTopProjectBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntTopProjectObj* realized = dynamic_cast<cfint::ICFIntTopProjectObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTopDomainIdx->erase( searchIndexByTopDomainIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTopDomainIdx->insert( std::map< cfint::CFIntTopProjectByTopDomainIdxKey,
				std::map< cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntTopProjectObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::readTopProjectByNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readTopProjectByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTopProjectByNameIdxKey,
				cfint::ICFIntTopProjectObj*>();
		}
		cfint::CFIntTopProjectByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::ICFIntTopProjectObj* obj = NULL;
		cfint::ICFIntTopProjectObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntTopProjectBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->readDerivedByNameIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntTopProjectObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntTopProjectByNameIdxKey, cfint::ICFIntTopProjectObj*>::value_type( key, dynamic_cast<cfint::ICFIntTopProjectObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::readTopProjectByLookupNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readTopProjectByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTopProjectByNameIdxKey,
				cfint::ICFIntTopProjectObj*>();
		}
		cfint::CFIntTopProjectByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::ICFIntTopProjectObj* obj = NULL;
		cfint::ICFIntTopProjectObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				obj = searchIndexByNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntTopProjectBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->readDerivedByLookupNameIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::ICFIntTopProjectObj*>( dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntTopProjectObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntTopProjectByNameIdxKey, cfint::ICFIntTopProjectObj*>::value_type( key, dynamic_cast<cfint::ICFIntTopProjectObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::readCachedTopProject( cfint::CFIntTopProjectPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTopProject" );
		cfint::ICFIntTopProjectObj* obj = NULL;
		cfint::ICFIntTopProjectObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::readCachedTopProjectByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readCachedTopProjectByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntTopProjectPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntTopProjectObj* obj = readCachedTopProject( &pkey );
		return( obj );
	}

	std::vector<cfint::ICFIntTopProjectObj*> CFIntTopProjectTableObj::readCachedTopProjectByTenantIdx( const int64_t TenantId )
	{
		static const std::string S_ProcName( "readCachedTopProjectByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntTopProjectObj*> arr;
		cfint::CFIntTopProjectByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* dict;
		if( indexByTenantIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTenantIdx = indexByTenantIdx->find( key );
		if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
			dict = searchIndexByTenantIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntTopProjectObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntTopProjectObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntTopProjectBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfint::ICFIntTopProjectObj*> CFIntTopProjectTableObj::readCachedTopProjectByTopDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId )
	{
		static const std::string S_ProcName( "readCachedTopProjectByTopDomainIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntTopProjectObj*> arr;
		cfint::CFIntTopProjectByTopDomainIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* dict;
		if( indexByTopDomainIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTopDomainIdx = indexByTopDomainIdx->find( key );
		if( searchIndexByTopDomainIdx != indexByTopDomainIdx->end() ) {
			dict = searchIndexByTopDomainIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntTopProjectObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntTopProjectObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntTopProjectBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::readCachedTopProjectByNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedTopProjectByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTopProjectByNameIdxKey,
				cfint::ICFIntTopProjectObj*>();
		}
		cfint::CFIntTopProjectByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::ICFIntTopProjectObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntTopProjectBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::readCachedTopProjectByLookupNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedTopProjectByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTopProjectByNameIdxKey,
				cfint::ICFIntTopProjectObj*>();
		}
		cfint::CFIntTopProjectByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::ICFIntTopProjectObj* obj = NULL;
		cfint::ICFIntTopProjectObj* realized = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntTopProjectBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntTopProjectObj* CFIntTopProjectTableObj::updateTopProject( cfint::ICFIntTopProjectEditObj* Obj ) {
		static const std::string S_ProcName( "updateTopProject" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntTopProjectObj* obj = dynamic_cast<cfint::ICFIntTopProjectObj*>( Obj->getOrig() );
		try {
			cfint::CFIntTopProjectBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->updateTopProject( schema->getAuthorization(),
				dynamic_cast<cfint::CFIntTopProjectBuff*>( Obj->getTopProjectBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfint::ICFIntTopProjectObj*>( dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfint::ICFIntTopProjectObj*>( obj->realize() );
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

	void CFIntTopProjectTableObj::deleteTopProject( cfint::ICFIntTopProjectEditObj* Obj ) {
		cfint::ICFIntTopProjectObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->deleteTopProject( schema->getAuthorization(),
			obj->getTopProjectBuff() );
		deepDisposeByIdIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
	}

	void CFIntTopProjectTableObj::deleteTopProjectByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		cfint::CFIntTopProjectPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntTopProjectObj* obj = readTopProject( &pkey, true );
		if( obj != NULL ) {
			cfint::ICFIntTopProjectEditObj* editObj = dynamic_cast<cfint::ICFIntTopProjectEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfint::ICFIntTopProjectEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntTopProjectTableObj::deleteTopProjectByTenantIdx( const int64_t TenantId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->deleteTopProjectByTenantIdx( schema->getAuthorization(),
				TenantId );
		deepDisposeByTenantIdx( TenantId );
	}

	void CFIntTopProjectTableObj::deleteTopProjectByTopDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->deleteTopProjectByTopDomainIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId );
		deepDisposeByTopDomainIdx( TenantId,
			TopDomainId );
	}

	void CFIntTopProjectTableObj::deleteTopProjectByNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name )
	{
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTopProjectByNameIdxKey,
				cfint::ICFIntTopProjectObj*>();
		}
		cfint::CFIntTopProjectByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::ICFIntTopProjectObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->deleteTopProjectByNameIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId,
				Name );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopProject()->deleteTopProjectByNameIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId,
				Name );
		}
		deepDisposeByNameIdx( TenantId,
			TopDomainId,
			Name );
	}

	void CFIntTopProjectTableObj::reallyDetachFromIndexesTopProject( cfint::ICFIntTopProjectObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesTopProject" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntTopProjectObj* obj = Obj;
		cfint::CFIntTopProjectPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfint::ICFIntTopProjectObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByTenantIdx != NULL ) {
				cfint::CFIntTopProjectByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* mapTenantIdx = searchTenantIdx->second;
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

			if( indexByTopDomainIdx != NULL ) {
				cfint::CFIntTopProjectByTopDomainIdxKey keyTopDomainIdx;
				keyTopDomainIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyTopDomainIdx.setRequiredTopDomainId( obj->getRequiredTopDomainId() );
				auto searchTopDomainIdx = indexByTopDomainIdx->find( keyTopDomainIdx );
				if( searchTopDomainIdx != indexByTopDomainIdx->end() ) {
					std::map<cfint::CFIntTopProjectPKey, cfint::ICFIntTopProjectObj*>* mapTopDomainIdx = searchTopDomainIdx->second;
					if( mapTopDomainIdx != NULL ) {
						auto removalProbe = mapTopDomainIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapTopDomainIdx->end() ) {
							mapTopDomainIdx->erase( removalProbe );
							if( mapTopDomainIdx->empty() ) {
								delete mapTopDomainIdx;
								mapTopDomainIdx = NULL;
								indexByTopDomainIdx->erase( searchTopDomainIdx );
							}
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntTopProjectByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyNameIdx.setRequiredTopDomainId( obj->getRequiredTopDomainId() );
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
