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

	const std::string CFIntSecGroupTableObj::CLASS_NAME( "CFIntSecGroupTableObj" );
	const std::string CFIntSecGroupTableObj::TABLE_NAME( "SecGroup" );
	const std::string CFIntSecGroupTableObj::TABLE_DBNAME( "SecGrp" );

	CFIntSecGroupTableObj::CFIntSecGroupTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>();
		allSecGroup = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecGroupByClusterIdxKey,
			std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>*>();
		indexByClusterVisIdx = new std::map< cfsec::CFSecSecGroupByClusterVisIdxKey,
			std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>*>();
		indexByUNameIdx = new std::map< cfsec::CFSecSecGroupByUNameIdxKey,
			cfsec::ICFSecSecGroupObj*>();
	}

	CFIntSecGroupTableObj::CFIntSecGroupTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>();
		allSecGroup = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecGroupByClusterIdxKey,
			std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>*>();
		indexByClusterVisIdx = new std::map< cfsec::CFSecSecGroupByClusterVisIdxKey,
			std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>*>();
		indexByUNameIdx = new std::map< cfsec::CFSecSecGroupByUNameIdxKey,
			cfsec::ICFSecSecGroupObj*>();
	}

	CFIntSecGroupTableObj::~CFIntSecGroupTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
		}
		if( indexByClusterVisIdx != NULL ) {
			delete indexByClusterVisIdx;
			indexByClusterVisIdx = NULL;
		}
		if( indexByUNameIdx != NULL ) {
			delete indexByUNameIdx;
			indexByUNameIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecSecGroupObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntSecGroupTableObj::getSchema() {
		return( schema );
	}

	void CFIntSecGroupTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntSecGroupTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntSecGroupTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntSecGroupTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntSecGroupTableObj::minimizeMemory() {
		if( allSecGroup != NULL ) {
			allSecGroup->clear();
			delete allSecGroup;
			allSecGroup = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecSecGroupByClusterIdxKey,
				std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecSecGroupByClusterIdxKey,
				std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* curByClusterIdx = NULL;
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
		if( indexByClusterVisIdx != NULL ) {
			std::map< cfsec::CFSecSecGroupByClusterVisIdxKey,
				std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* >::iterator iterByClusterVisIdx = indexByClusterVisIdx->begin();
			std::map< cfsec::CFSecSecGroupByClusterVisIdxKey,
				std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* >::iterator endByClusterVisIdx = indexByClusterVisIdx->end();
			std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* curByClusterVisIdx = NULL;
			while( iterByClusterVisIdx != endByClusterVisIdx ) {
				curByClusterVisIdx = iterByClusterVisIdx->second;
				if( curByClusterVisIdx != NULL ) {
					curByClusterVisIdx->clear();
					delete curByClusterVisIdx;
					curByClusterVisIdx = NULL;
					iterByClusterVisIdx->second = NULL;
				}
				iterByClusterVisIdx ++;
			}
			indexByClusterVisIdx->clear();
		}
		if( indexByUNameIdx != NULL ) {
			indexByUNameIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecSecGroupObj* cur = NULL;
			cfsec::ICFSecSecGroupEditObj* edit = NULL;
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

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::newInstance() {
		cfsec::ICFSecSecGroupObj* inst = dynamic_cast<cfsec::ICFSecSecGroupObj*>( new CFIntSecGroupObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSecGroupEditObj* CFIntSecGroupTableObj::newEditInstance( cfsec::ICFSecSecGroupObj* orig ) {
		cfsec::ICFSecSecGroupEditObj* edit = dynamic_cast<cfsec::ICFSecSecGroupEditObj*>( new CFIntSecGroupEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::realizeSecGroup( cfsec::ICFSecSecGroupObj* Obj ) {
		static const std::string S_ProcName( "realizeSecGroup" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecGroupObj* obj = Obj;
		cfsec::ICFSecSecGroupObj* existingObj = NULL;
		cfsec::CFSecSecGroupPKey* pkey = obj->getPKey();
		cfsec::ICFSecSecGroupObj* keepObj = NULL;
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
				cfsec::CFSecSecGroupByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByClusterVisIdx != NULL ) {
				cfsec::CFSecSecGroupByClusterVisIdxKey keyClusterVisIdx;
				keyClusterVisIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyClusterVisIdx.setRequiredIsVisible( keepObj->getRequiredIsVisible() );
				auto searchClusterVisIdx = indexByClusterVisIdx->find( keyClusterVisIdx );
				if( searchClusterVisIdx != indexByClusterVisIdx->end() ) {
					std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* mapClusterVisIdx = searchClusterVisIdx->second;
					if( mapClusterVisIdx != NULL ) {
						auto removalProbe = mapClusterVisIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterVisIdx->end() ) {
							mapClusterVisIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				cfsec::CFSecSecGroupByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByUNameIdx->find( keyUNameIdx );
				if( removalProbe != indexByUNameIdx->end() ) {
					indexByUNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSecGroupBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecGroupObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecGroupByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByClusterVisIdx != NULL ) {
				static const std::string S_AClusterVisIdxObj( "aClusterVisIdxObj" );
				cfsec::ICFSecSecGroupObj* aClusterVisIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupObj*>( keepObj );
				if( aClusterVisIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterVisIdxObj );
				}
				cfsec::CFSecSecGroupByClusterVisIdxKey keyClusterVisIdx;
				keyClusterVisIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyClusterVisIdx.setRequiredIsVisible( keepObj->getRequiredIsVisible() );
				auto searchIndexByClusterVisIdx = indexByClusterVisIdx->find( keyClusterVisIdx );
				if( searchIndexByClusterVisIdx != indexByClusterVisIdx->end() ) {
					std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* mapClusterVisIdx = searchIndexByClusterVisIdx->second;
					if( mapClusterVisIdx != NULL ) {
						mapClusterVisIdx->insert( std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >::value_type( *(keepObj->getPKey()), aClusterVisIdxObj ) );
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfsec::ICFSecSecGroupObj* aUNameIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfsec::CFSecSecGroupByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByUNameIdx->insert( std::map< cfsec::CFSecSecGroupByUNameIdxKey, cfsec::ICFSecSecGroupObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( allSecGroup != NULL ) {
				allSecGroup->insert( std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecGroupObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecGroupByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByClusterVisIdx != NULL ) {
				static const std::string S_AClusterVisIdxObj( "aClusterVisIdxObj" );
				cfsec::ICFSecSecGroupObj* aClusterVisIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupObj*>( keepObj );
				if( aClusterVisIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterVisIdxObj );
				}
				cfsec::CFSecSecGroupByClusterVisIdxKey keyClusterVisIdx;
				keyClusterVisIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyClusterVisIdx.setRequiredIsVisible( keepObj->getRequiredIsVisible() );
				auto searchIndexByClusterVisIdx = indexByClusterVisIdx->find( keyClusterVisIdx );
				if( searchIndexByClusterVisIdx != indexByClusterVisIdx->end() ) {
					std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* mapClusterVisIdx = searchIndexByClusterVisIdx->second;
					if( mapClusterVisIdx != NULL ) {
						mapClusterVisIdx->insert( std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >::value_type( *(keepObj->getPKey()), aClusterVisIdxObj ) );
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfsec::ICFSecSecGroupObj* aUNameIdxObj =
					dynamic_cast<cfsec::ICFSecSecGroupObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfsec::CFSecSecGroupByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByUNameIdx->insert( std::map< cfsec::CFSecSecGroupByUNameIdxKey, cfsec::ICFSecSecGroupObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( allSecGroup != NULL ) {
				allSecGroup->insert( std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntSecGroupTableObj::deepDisposeByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSecGroupObj*> list;
		cfsec::ICFSecSecGroupObj* existingObj = readCachedSecGroupByIdIdx( ClusterId,
				SecGroupId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecGroupObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->reallyDeepDisposeSecGroup( dynamic_cast<cfsec::ICFSecSecGroupObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecGroupTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecSecGroupObj*> list;
		std::vector<cfsec::ICFSecSecGroupObj*> matchesFound = readCachedSecGroupByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGroupObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->reallyDeepDisposeSecGroup( dynamic_cast<cfsec::ICFSecSecGroupObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecGroupTableObj::deepDisposeByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible ) {
		static const std::string S_ProcName( "deepDisposeByClusterVisIdx" );
		std::vector<cfsec::ICFSecSecGroupObj*> list;
		std::vector<cfsec::ICFSecSecGroupObj*> matchesFound = readCachedSecGroupByClusterVisIdx( ClusterId,
				IsVisible );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGroupObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->reallyDeepDisposeSecGroup( dynamic_cast<cfsec::ICFSecSecGroupObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecGroupTableObj::deepDisposeByUNameIdx( const int64_t ClusterId,
			const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByUNameIdx" );
		std::vector<cfsec::ICFSecSecGroupObj*> list;
		cfsec::ICFSecSecGroupObj* existingObj = readCachedSecGroupByUNameIdx( ClusterId,
				Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecGroupObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->reallyDeepDisposeSecGroup( dynamic_cast<cfsec::ICFSecSecGroupObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecGroupTableObj::reallyDeepDisposeSecGroup( cfsec::ICFSecSecGroupObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSecGroup" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSecGroupObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->deepDisposeByGroupIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecGroupId() );
		dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->deepDisposeByIncludeIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecGroupId() );
		dynamic_cast<cfint::CFIntSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->deepDisposeByGroupIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecGroupId() );
		dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->deepDisposeByGroupIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecGroupId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSecGroupBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->reallyDetachFromIndexesSecGroup( dynamic_cast<cfsec::ICFSecSecGroupObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::createSecGroup( cfsec::ICFSecSecGroupEditObj* Obj ) {
		static const std::string S_ProcName( "createSecGroup" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGroupObj* obj = dynamic_cast<cfsec::ICFSecSecGroupObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecGroupBuff* buff = dynamic_cast<cfsec::CFSecSecGroupBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->createSecGroup(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSecGroupBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSecGroupObj*>( obj->realize() );
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

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::readSecGroup( cfsec::CFSecSecGroupPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecGroup" );
		cfsec::ICFSecSecGroupObj* obj = NULL;
		cfsec::ICFSecSecGroupObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecGroupBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredClusterId(),
			pkey->getRequiredSecGroupId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSecGroupObj*>( obj->realize() );
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

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::lockSecGroup( cfsec::CFSecSecGroupPKey* pkey ) {
		static const std::string S_ProcName( "lockSecGroup" );
		cfsec::ICFSecSecGroupObj* locked = NULL;
		cfsec::CFSecSecGroupBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSecGroupObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSecGroupObj*> CFIntSecGroupTableObj::readAllSecGroup( bool forceRead ) {
		static const std::string S_ProcName( "readAllSecGroup" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGroupObj* realized = NULL;
		if( forceRead || ( allSecGroup == NULL ) ) {
			std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* map = new std::map<cfsec::CFSecSecGroupPKey,cfsec::ICFSecSecGroupObj*>();
			allSecGroup = map;
			std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSecGroupBuff* buff = NULL;
			cfsec::ICFSecSecGroupObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSecGroupObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSecGroup->insert( std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSecGroup->size();
		std::vector<cfsec::ICFSecSecGroupObj*> arr;
		auto valIter = allSecGroup->begin();
		size_t idx = 0;
		while( valIter != allSecGroup->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::readSecGroupByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecGroupByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGroupId( SecGroupId );
		cfsec::ICFSecSecGroupObj* obj = readSecGroup( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGroupObj*> CFIntSecGroupTableObj::readSecGroupByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGroupByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* dict;
		std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecSecGroupByClusterIdxKey,
				std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>*>();
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
			dict = new std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>();
			cfsec::ICFSecSecGroupObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecSecGroupBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGroupObj* realized = dynamic_cast<cfsec::ICFSecSecGroupObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecSecGroupByClusterIdxKey,
				std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGroupObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGroupObj*> CFIntSecGroupTableObj::readSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGroupByClusterVisIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupByClusterVisIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIsVisible( IsVisible );
		std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* dict;
		std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* oldDict;
		if( indexByClusterVisIdx == NULL ) {
			indexByClusterVisIdx = new std::map< cfsec::CFSecSecGroupByClusterVisIdxKey,
				std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>*>();
		}
		auto searchIndexByClusterVisIdx = indexByClusterVisIdx->find( key );
		if( searchIndexByClusterVisIdx != indexByClusterVisIdx->end() ) {
			oldDict = searchIndexByClusterVisIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>();
			cfsec::ICFSecSecGroupObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->readDerivedByClusterVisIdx( schema->getAuthorization(),
				ClusterId,
				IsVisible );
			cfsec::CFSecSecGroupBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGroupObj* realized = dynamic_cast<cfsec::ICFSecSecGroupObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterVisIdx->erase( searchIndexByClusterVisIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterVisIdx->insert( std::map< cfsec::CFSecSecGroupByClusterVisIdxKey,
				std::map< cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGroupObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::readSecGroupByUNameIdx( const int64_t ClusterId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readSecGroupByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecSecGroupByUNameIdxKey,
				cfsec::ICFSecSecGroupObj*>();
		}
		cfsec::CFSecSecGroupByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredName( Name );
		cfsec::ICFSecSecGroupObj* obj = NULL;
		cfsec::ICFSecSecGroupObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecGroupBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->readDerivedByUNameIdx( schema->getAuthorization(),
				ClusterId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecGroupObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfsec::CFSecSecGroupByUNameIdxKey, cfsec::ICFSecSecGroupObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecGroupObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::readSecGroupByLookupUNameIdx( const int64_t ClusterId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readSecGroupByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecSecGroupByUNameIdxKey,
				cfsec::ICFSecSecGroupObj*>();
		}
		cfsec::CFSecSecGroupByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredName( Name );
		cfsec::ICFSecSecGroupObj* obj = NULL;
		cfsec::ICFSecSecGroupObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				obj = searchIndexByUNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecGroupBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->readDerivedByLookupUNameIdx( schema->getAuthorization(),
				ClusterId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecSecGroupObj*>( dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecGroupObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfsec::CFSecSecGroupByUNameIdxKey, cfsec::ICFSecSecGroupObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecGroupObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::readCachedSecGroup( cfsec::CFSecSecGroupPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecGroup" );
		cfsec::ICFSecSecGroupObj* obj = NULL;
		cfsec::ICFSecSecGroupObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::readCachedSecGroupByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		static const std::string S_ProcName( "readCachedSecGroupByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGroupPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGroupId( SecGroupId );
		cfsec::ICFSecSecGroupObj* obj = readCachedSecGroup( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGroupObj*> CFIntSecGroupTableObj::readCachedSecGroupByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedSecGroupByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGroupObj*> arr;
		cfsec::CFSecSecGroupByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGroupObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGroupObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGroupBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGroupObj*> CFIntSecGroupTableObj::readCachedSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible )
	{
		static const std::string S_ProcName( "readCachedSecGroupByClusterVisIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGroupObj*> arr;
		cfsec::CFSecSecGroupByClusterVisIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIsVisible( IsVisible );
		std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* dict;
		if( indexByClusterVisIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterVisIdx = indexByClusterVisIdx->find( key );
		if( searchIndexByClusterVisIdx != indexByClusterVisIdx->end() ) {
			dict = searchIndexByClusterVisIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGroupObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGroupObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGroupBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::readCachedSecGroupByUNameIdx( const int64_t ClusterId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedSecGroupByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecSecGroupByUNameIdxKey,
				cfsec::ICFSecSecGroupObj*>();
		}
		cfsec::CFSecSecGroupByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredName( Name );
		cfsec::ICFSecSecGroupObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGroupBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::readCachedSecGroupByLookupUNameIdx( const int64_t ClusterId,
			const std::string& Name )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedSecGroupByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecSecGroupByUNameIdxKey,
				cfsec::ICFSecSecGroupObj*>();
		}
		cfsec::CFSecSecGroupByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredName( Name );
		cfsec::ICFSecSecGroupObj* obj = NULL;
		cfsec::ICFSecSecGroupObj* realized = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGroupBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecGroupObj* CFIntSecGroupTableObj::updateSecGroup( cfsec::ICFSecSecGroupEditObj* Obj ) {
		static const std::string S_ProcName( "updateSecGroup" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGroupObj* obj = dynamic_cast<cfsec::ICFSecSecGroupObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecGroupBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->updateSecGroup( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSecGroupBuff*>( Obj->getSecGroupBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSecGroupObj*>( dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSecGroupObj*>( obj->realize() );
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

	void CFIntSecGroupTableObj::deleteSecGroup( cfsec::ICFSecSecGroupEditObj* Obj ) {
		cfsec::ICFSecSecGroupObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->deleteSecGroup( schema->getAuthorization(),
			obj->getSecGroupBuff() );
		deepDisposeByIdIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecGroupId() );
	}

	void CFIntSecGroupTableObj::deleteSecGroupByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		cfsec::CFSecSecGroupPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGroupId( SecGroupId );
		cfsec::ICFSecSecGroupObj* obj = readSecGroup( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSecGroupEditObj* editObj = dynamic_cast<cfsec::ICFSecSecGroupEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSecGroupEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntSecGroupTableObj::deleteSecGroupByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroup()->deleteSecGroupByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFIntSecGroupTableObj::deleteSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGroup()->deleteSecGroupByClusterVisIdx( schema->getAuthorization(),
				ClusterId,
				IsVisible );
		deepDisposeByClusterVisIdx( ClusterId,
			IsVisible );
	}

	void CFIntSecGroupTableObj::deleteSecGroupByUNameIdx( const int64_t ClusterId,
			const std::string& Name )
	{
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecSecGroupByUNameIdxKey,
				cfsec::ICFSecSecGroupObj*>();
		}
		cfsec::CFSecSecGroupByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredName( Name );
		cfsec::ICFSecSecGroupObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->deleteSecGroupByUNameIdx( schema->getAuthorization(),
				ClusterId,
				Name );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGroup()->deleteSecGroupByUNameIdx( schema->getAuthorization(),
				ClusterId,
				Name );
		}
		deepDisposeByUNameIdx( ClusterId,
			Name );
	}

	void CFIntSecGroupTableObj::reallyDetachFromIndexesSecGroup( cfsec::ICFSecSecGroupObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSecGroup" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecGroupObj* obj = Obj;
		cfsec::CFSecSecGroupPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSecGroupObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecSecGroupByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* mapClusterIdx = searchClusterIdx->second;
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

			if( indexByClusterVisIdx != NULL ) {
				cfsec::CFSecSecGroupByClusterVisIdxKey keyClusterVisIdx;
				keyClusterVisIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyClusterVisIdx.setRequiredIsVisible( obj->getRequiredIsVisible() );
				auto searchClusterVisIdx = indexByClusterVisIdx->find( keyClusterVisIdx );
				if( searchClusterVisIdx != indexByClusterVisIdx->end() ) {
					std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* mapClusterVisIdx = searchClusterVisIdx->second;
					if( mapClusterVisIdx != NULL ) {
						auto removalProbe = mapClusterVisIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapClusterVisIdx->end() ) {
							mapClusterVisIdx->erase( removalProbe );
							if( mapClusterVisIdx->empty() ) {
								delete mapClusterVisIdx;
								mapClusterVisIdx = NULL;
								indexByClusterVisIdx->erase( searchClusterVisIdx );
							}
						}
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				cfsec::CFSecSecGroupByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyUNameIdx.setRequiredName( obj->getRequiredName() );
				auto removalProbe = indexByUNameIdx->find( keyUNameIdx );
				if( removalProbe != indexByUNameIdx->end() ) {
					indexByUNameIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
