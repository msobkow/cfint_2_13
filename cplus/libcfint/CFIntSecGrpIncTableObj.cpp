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

	const std::string CFIntSecGrpIncTableObj::CLASS_NAME( "CFIntSecGrpIncTableObj" );
	const std::string CFIntSecGrpIncTableObj::TABLE_NAME( "SecGrpInc" );
	const std::string CFIntSecGrpIncTableObj::TABLE_DBNAME( "SecInc" );

	CFIntSecGrpIncTableObj::CFIntSecGrpIncTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>();
		allSecGrpInc = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByUIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey,
			cfsec::ICFSecSecGrpIncObj*>();
	}

	CFIntSecGrpIncTableObj::CFIntSecGrpIncTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>();
		allSecGrpInc = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByGroupIdx = new std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		indexByUIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey,
			cfsec::ICFSecSecGrpIncObj*>();
	}

	CFIntSecGrpIncTableObj::~CFIntSecGrpIncTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
		}
		if( indexByGroupIdx != NULL ) {
			delete indexByGroupIdx;
			indexByGroupIdx = NULL;
		}
		if( indexByIncludeIdx != NULL ) {
			delete indexByIncludeIdx;
			indexByIncludeIdx = NULL;
		}
		if( indexByUIncludeIdx != NULL ) {
			delete indexByUIncludeIdx;
			indexByUIncludeIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecSecGrpIncObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntSecGrpIncTableObj::getSchema() {
		return( schema );
	}

	void CFIntSecGrpIncTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntSecGrpIncTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntSecGrpIncTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntSecGrpIncTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntSecGrpIncTableObj::minimizeMemory() {
		if( allSecGrpInc != NULL ) {
			allSecGrpInc->clear();
			delete allSecGrpInc;
			allSecGrpInc = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* curByClusterIdx = NULL;
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
		if( indexByGroupIdx != NULL ) {
			std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator iterByGroupIdx = indexByGroupIdx->begin();
			std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator endByGroupIdx = indexByGroupIdx->end();
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* curByGroupIdx = NULL;
			while( iterByGroupIdx != endByGroupIdx ) {
				curByGroupIdx = iterByGroupIdx->second;
				if( curByGroupIdx != NULL ) {
					curByGroupIdx->clear();
					delete curByGroupIdx;
					curByGroupIdx = NULL;
					iterByGroupIdx->second = NULL;
				}
				iterByGroupIdx ++;
			}
			indexByGroupIdx->clear();
		}
		if( indexByIncludeIdx != NULL ) {
			std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator iterByIncludeIdx = indexByIncludeIdx->begin();
			std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* >::iterator endByIncludeIdx = indexByIncludeIdx->end();
			std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* curByIncludeIdx = NULL;
			while( iterByIncludeIdx != endByIncludeIdx ) {
				curByIncludeIdx = iterByIncludeIdx->second;
				if( curByIncludeIdx != NULL ) {
					curByIncludeIdx->clear();
					delete curByIncludeIdx;
					curByIncludeIdx = NULL;
					iterByIncludeIdx->second = NULL;
				}
				iterByIncludeIdx ++;
			}
			indexByIncludeIdx->clear();
		}
		if( indexByUIncludeIdx != NULL ) {
			indexByUIncludeIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecSecGrpIncObj* cur = NULL;
			cfsec::ICFSecSecGrpIncEditObj* edit = NULL;
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

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncTableObj::newInstance() {
		cfsec::ICFSecSecGrpIncObj* inst = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( new CFIntSecGrpIncObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSecGrpIncEditObj* CFIntSecGrpIncTableObj::newEditInstance( cfsec::ICFSecSecGrpIncObj* orig ) {
		cfsec::ICFSecSecGrpIncEditObj* edit = dynamic_cast<cfsec::ICFSecSecGrpIncEditObj*>( new CFIntSecGrpIncEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncTableObj::realizeSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) {
		static const std::string S_ProcName( "realizeSecGrpInc" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecGrpIncObj* obj = Obj;
		cfsec::ICFSecSecGrpIncObj* existingObj = NULL;
		cfsec::CFSecSecGrpIncPKey* pkey = obj->getPKey();
		cfsec::ICFSecSecGrpIncObj* keepObj = NULL;
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
				cfsec::CFSecSecGrpIncByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				cfsec::CFSecSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapGroupIdx = searchGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						auto removalProbe = mapGroupIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapGroupIdx->end() ) {
							mapGroupIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByIncludeIdx != NULL ) {
				cfsec::CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto searchIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapIncludeIdx = searchIncludeIdx->second;
					if( mapIncludeIdx != NULL ) {
						auto removalProbe = mapIncludeIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapIncludeIdx->end() ) {
							mapIncludeIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUIncludeIdx != NULL ) {
				cfsec::CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUIncludeIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto removalProbe = indexByUIncludeIdx->find( keyUIncludeIdx );
				if( removalProbe != indexByUIncludeIdx->end() ) {
					indexByUIncludeIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecGrpIncByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByIncludeIdx != NULL ) {
				static const std::string S_AIncludeIdxObj( "aIncludeIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIncludeIdxObj );
				}
				cfsec::CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto searchIndexByIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIndexByIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapIncludeIdx = searchIndexByIncludeIdx->second;
					if( mapIncludeIdx != NULL ) {
						mapIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aIncludeIdxObj ) );
					}
				}
			}

			if( indexByUIncludeIdx != NULL ) {
				static const std::string S_AUIncludeIdxObj( "aUIncludeIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aUIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aUIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUIncludeIdxObj );
				}
				cfsec::CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUIncludeIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				indexByUIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey, cfsec::ICFSecSecGrpIncObj* >::value_type( keyUIncludeIdx, aUIncludeIdxObj ) );
			}

			if( allSecGrpInc != NULL ) {
				allSecGrpInc->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecGrpIncByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByGroupIdx != NULL ) {
				static const std::string S_AGroupIdxObj( "aGroupIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aGroupIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aGroupIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AGroupIdxObj );
				}
				cfsec::CFSecSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				auto searchIndexByGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapGroupIdx = searchIndexByGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						mapGroupIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aGroupIdxObj ) );
					}
				}
			}

			if( indexByIncludeIdx != NULL ) {
				static const std::string S_AIncludeIdxObj( "aIncludeIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIncludeIdxObj );
				}
				cfsec::CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				auto searchIndexByIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIndexByIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapIncludeIdx = searchIndexByIncludeIdx->second;
					if( mapIncludeIdx != NULL ) {
						mapIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), aIncludeIdxObj ) );
					}
				}
			}

			if( indexByUIncludeIdx != NULL ) {
				static const std::string S_AUIncludeIdxObj( "aUIncludeIdxObj" );
				cfsec::ICFSecSecGrpIncObj* aUIncludeIdxObj =
					dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( keepObj );
				if( aUIncludeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUIncludeIdxObj );
				}
				cfsec::CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUIncludeIdx.setRequiredSecGroupId( keepObj->getRequiredSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( keepObj->getRequiredIncludeGroupId() );
				indexByUIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey, cfsec::ICFSecSecGrpIncObj* >::value_type( keyUIncludeIdx, aUIncludeIdxObj ) );
			}

			if( allSecGrpInc != NULL ) {
				allSecGrpInc->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntSecGrpIncTableObj::deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> list;
		cfsec::ICFSecSecGrpIncObj* existingObj = readCachedSecGrpIncByIdIdx( ClusterId,
				SecGrpIncId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDeepDisposeSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecGrpIncTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> list;
		std::vector<cfsec::ICFSecSecGrpIncObj*> matchesFound = readCachedSecGrpIncByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDeepDisposeSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecGrpIncTableObj::deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) {
		static const std::string S_ProcName( "deepDisposeByGroupIdx" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> list;
		std::vector<cfsec::ICFSecSecGrpIncObj*> matchesFound = readCachedSecGrpIncByGroupIdx( ClusterId,
				SecGroupId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDeepDisposeSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecGrpIncTableObj::deepDisposeByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId ) {
		static const std::string S_ProcName( "deepDisposeByIncludeIdx" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> list;
		std::vector<cfsec::ICFSecSecGrpIncObj*> matchesFound = readCachedSecGrpIncByIncludeIdx( ClusterId,
				IncludeGroupId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDeepDisposeSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecGrpIncTableObj::deepDisposeByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId ) {
		static const std::string S_ProcName( "deepDisposeByUIncludeIdx" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> list;
		cfsec::ICFSecSecGrpIncObj* existingObj = readCachedSecGrpIncByUIncludeIdx( ClusterId,
				SecGroupId,
				IncludeGroupId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecGrpIncObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDeepDisposeSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecGrpIncTableObj::reallyDeepDisposeSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSecGrpInc" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSecGrpIncObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSecGrpIncBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->reallyDetachFromIndexesSecGrpInc( dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncTableObj::createSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) {
		static const std::string S_ProcName( "createSecGrpInc" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGrpIncObj* obj = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecGrpIncBuff* buff = dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->createSecGrpInc(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncTableObj::readSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecGrpInc" );
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		cfsec::ICFSecSecGrpIncObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecGrpIncBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredClusterId(),
			pkey->getRequiredSecGrpIncId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncTableObj::lockSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey ) {
		static const std::string S_ProcName( "lockSecGrpInc" );
		cfsec::ICFSecSecGrpIncObj* locked = NULL;
		cfsec::CFSecSecGrpIncBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGrpIncTableObj::readAllSecGrpInc( bool forceRead ) {
		static const std::string S_ProcName( "readAllSecGrpInc" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGrpIncObj* realized = NULL;
		if( forceRead || ( allSecGrpInc == NULL ) ) {
			std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* map = new std::map<cfsec::CFSecSecGrpIncPKey,cfsec::ICFSecSecGrpIncObj*>();
			allSecGrpInc = map;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSecGrpIncBuff* buff = NULL;
			cfsec::ICFSecSecGrpIncObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSecGrpInc->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSecGrpInc->size();
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		auto valIter = allSecGrpInc->begin();
		size_t idx = 0;
		while( valIter != allSecGrpInc->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGrpIncTableObj::pageAllSecGrpInc(const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllSecGrpInc" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* map = NULL;
		cfsec::CFSecSecGrpIncBuff* buff = NULL;
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		cfsec::ICFSecSecGrpIncObj* realized = NULL;
		std::vector<cfsec::ICFSecSecGrpIncObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecSecGrpIncPKey,cfsec::ICFSecSecGrpIncObj*>();
			std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->pageAllBuff( schema->getAuthorization(),
				priorClusterId,
				priorSecGrpIncId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncTableObj::readSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpIncByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpIncId( SecGrpIncId );
		cfsec::ICFSecSecGrpIncObj* obj = readSecGrpInc( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGrpIncTableObj::readSecGrpIncByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpIncByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
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
			dict = new std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>();
			cfsec::ICFSecSecGrpIncObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecSecGrpIncBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGrpIncObj* realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGrpIncTableObj::readSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpIncByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* oldDict;
		if( indexByGroupIdx == NULL ) {
			indexByGroupIdx = new std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		}
		auto searchIndexByGroupIdx = indexByGroupIdx->find( key );
		if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
			oldDict = searchIndexByGroupIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>();
			cfsec::ICFSecSecGrpIncObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId );
			cfsec::CFSecSecGrpIncBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGrpIncObj* realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByGroupIdx->erase( searchIndexByGroupIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByGroupIdx->insert( std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGrpIncTableObj::readSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpIncByIncludeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* oldDict;
		if( indexByIncludeIdx == NULL ) {
			indexByIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>();
		}
		auto searchIndexByIncludeIdx = indexByIncludeIdx->find( key );
		if( searchIndexByIncludeIdx != indexByIncludeIdx->end() ) {
			oldDict = searchIndexByIncludeIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>();
			cfsec::ICFSecSecGrpIncObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByIncludeIdx( schema->getAuthorization(),
				ClusterId,
				IncludeGroupId );
			cfsec::CFSecSecGrpIncBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecGrpIncObj* realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByIncludeIdx->erase( searchIndexByIncludeIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
				std::map< cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncTableObj::readSecGrpIncByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecGrpIncByUIncludeIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUIncludeIdx == NULL ) {
			indexByUIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey,
				cfsec::ICFSecSecGrpIncObj*>();
		}
		cfsec::CFSecSecGrpIncByUIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		cfsec::ICFSecSecGrpIncObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUIncludeIdx = indexByUIncludeIdx->find( key );
			if( searchIndexByUIncludeIdx != indexByUIncludeIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUIncludeIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecGrpIncBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->readDerivedByUIncludeIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				IncludeGroupId );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUIncludeIdx->insert( std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey, cfsec::ICFSecSecGrpIncObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncTableObj::readCachedSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecGrpInc" );
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		cfsec::ICFSecSecGrpIncObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncTableObj::readCachedSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId )
	{
		static const std::string S_ProcName( "readCachedSecGrpIncByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpIncId( SecGrpIncId );
		cfsec::ICFSecSecGrpIncObj* obj = readCachedSecGrpInc( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGrpIncTableObj::readCachedSecGrpIncByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedSecGrpIncByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		cfsec::CFSecSecGrpIncByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGrpIncObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGrpIncTableObj::readCachedSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		static const std::string S_ProcName( "readCachedSecGrpIncByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		cfsec::CFSecSecGrpIncByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		if( indexByGroupIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByGroupIdx = indexByGroupIdx->find( key );
		if( searchIndexByGroupIdx != indexByGroupIdx->end() ) {
			dict = searchIndexByGroupIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGrpIncObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGrpIncTableObj::readCachedSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId )
	{
		static const std::string S_ProcName( "readCachedSecGrpIncByIncludeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
		cfsec::CFSecSecGrpIncByIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* dict;
		if( indexByIncludeIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByIncludeIdx = indexByIncludeIdx->find( key );
		if( searchIndexByIncludeIdx != indexByIncludeIdx->end() ) {
			dict = searchIndexByIncludeIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecGrpIncObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecGrpIncObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncTableObj::readCachedSecGrpIncByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId )
	{
		static const std::string S_ProcName( "readCachedSecGrpIncByUIncludeIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUIncludeIdx == NULL ) {
			indexByUIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey,
				cfsec::ICFSecSecGrpIncObj*>();
		}
		cfsec::CFSecSecGrpIncByUIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		auto searchIndexByUIncludeIdx = indexByUIncludeIdx->find( key );
		if( searchIndexByUIncludeIdx != indexByUIncludeIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUIncludeIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGrpIncTableObj::pageSecGrpIncByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId )
	{
		static const std::string S_ProcName( "pageSecGrpIncByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		cfsec::ICFSecSecGrpIncObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->pageBuffByClusterIdx( schema->getAuthorization(),
				ClusterId,
				priorClusterId,
				priorSecGrpIncId );
		std::vector<cfsec::ICFSecSecGrpIncObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGrpIncBuff* buff;
		cfsec::ICFSecSecGrpIncObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGrpIncTableObj::pageSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId )
	{
		static const std::string S_ProcName( "pageSecGrpIncByGroupIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		cfsec::ICFSecSecGrpIncObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->pageBuffByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				priorClusterId,
				priorSecGrpIncId );
		std::vector<cfsec::ICFSecSecGrpIncObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGrpIncBuff* buff;
		cfsec::ICFSecSecGrpIncObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecGrpIncObj*> CFIntSecGrpIncTableObj::pageSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId )
	{
		static const std::string S_ProcName( "pageSecGrpIncByIncludeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecGrpIncByIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecSecGrpIncObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecGrpIncBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->pageBuffByIncludeIdx( schema->getAuthorization(),
				ClusterId,
				IncludeGroupId,
				priorClusterId,
				priorSecGrpIncId );
		std::vector<cfsec::ICFSecSecGrpIncObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecGrpIncBuff* buff;
		cfsec::ICFSecSecGrpIncObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	cfsec::ICFSecSecGrpIncObj* CFIntSecGrpIncTableObj::updateSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) {
		static const std::string S_ProcName( "updateSecGrpInc" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecGrpIncObj* obj = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecGrpIncBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->updateSecGrpInc( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSecGrpIncBuff*>( Obj->getSecGrpIncBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSecGrpIncObj*>( obj->realize() );
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

	void CFIntSecGrpIncTableObj::deleteSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) {
		cfsec::ICFSecSecGrpIncObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpInc( schema->getAuthorization(),
			obj->getSecGrpIncBuff() );
		deepDisposeByIdIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecGrpIncId() );
	}

	void CFIntSecGrpIncTableObj::deleteSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId )
	{
		cfsec::CFSecSecGrpIncPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecGrpIncId( SecGrpIncId );
		cfsec::ICFSecSecGrpIncObj* obj = readSecGrpInc( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSecGrpIncEditObj* editObj = dynamic_cast<cfsec::ICFSecSecGrpIncEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSecGrpIncEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntSecGrpIncTableObj::deleteSecGrpIncByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpIncByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFIntSecGrpIncTableObj::deleteSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpIncByGroupIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId );
		deepDisposeByGroupIdx( ClusterId,
			SecGroupId );
	}

	void CFIntSecGrpIncTableObj::deleteSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpIncByIncludeIdx( schema->getAuthorization(),
				ClusterId,
				IncludeGroupId );
		deepDisposeByIncludeIdx( ClusterId,
			IncludeGroupId );
	}

	void CFIntSecGrpIncTableObj::deleteSecGrpIncByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId )
	{
		if( indexByUIncludeIdx == NULL ) {
			indexByUIncludeIdx = new std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey,
				cfsec::ICFSecSecGrpIncObj*>();
		}
		cfsec::CFSecSecGrpIncByUIncludeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredIncludeGroupId( IncludeGroupId );
		cfsec::ICFSecSecGrpIncObj* obj = NULL;
		auto searchIndexByUIncludeIdx = indexByUIncludeIdx->find( key );
		if( searchIndexByUIncludeIdx != indexByUIncludeIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpIncByUIncludeIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				IncludeGroupId );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecGrpInc()->deleteSecGrpIncByUIncludeIdx( schema->getAuthorization(),
				ClusterId,
				SecGroupId,
				IncludeGroupId );
		}
		deepDisposeByUIncludeIdx( ClusterId,
			SecGroupId,
			IncludeGroupId );
	}

	void CFIntSecGrpIncTableObj::reallyDetachFromIndexesSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSecGrpInc" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecGrpIncObj* obj = Obj;
		cfsec::CFSecSecGrpIncPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSecGrpIncObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecSecGrpIncByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapClusterIdx = searchClusterIdx->second;
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

			if( indexByGroupIdx != NULL ) {
				cfsec::CFSecSecGrpIncByGroupIdxKey keyGroupIdx;
				keyGroupIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyGroupIdx.setRequiredSecGroupId( obj->getRequiredSecGroupId() );
				auto searchGroupIdx = indexByGroupIdx->find( keyGroupIdx );
				if( searchGroupIdx != indexByGroupIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapGroupIdx = searchGroupIdx->second;
					if( mapGroupIdx != NULL ) {
						auto removalProbe = mapGroupIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapGroupIdx->end() ) {
							mapGroupIdx->erase( removalProbe );
							if( mapGroupIdx->empty() ) {
								delete mapGroupIdx;
								mapGroupIdx = NULL;
								indexByGroupIdx->erase( searchGroupIdx );
							}
						}
					}
				}
			}

			if( indexByIncludeIdx != NULL ) {
				cfsec::CFSecSecGrpIncByIncludeIdxKey keyIncludeIdx;
				keyIncludeIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyIncludeIdx.setRequiredIncludeGroupId( obj->getRequiredIncludeGroupId() );
				auto searchIncludeIdx = indexByIncludeIdx->find( keyIncludeIdx );
				if( searchIncludeIdx != indexByIncludeIdx->end() ) {
					std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* mapIncludeIdx = searchIncludeIdx->second;
					if( mapIncludeIdx != NULL ) {
						auto removalProbe = mapIncludeIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapIncludeIdx->end() ) {
							mapIncludeIdx->erase( removalProbe );
							if( mapIncludeIdx->empty() ) {
								delete mapIncludeIdx;
								mapIncludeIdx = NULL;
								indexByIncludeIdx->erase( searchIncludeIdx );
							}
						}
					}
				}
			}

			if( indexByUIncludeIdx != NULL ) {
				cfsec::CFSecSecGrpIncByUIncludeIdxKey keyUIncludeIdx;
				keyUIncludeIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyUIncludeIdx.setRequiredSecGroupId( obj->getRequiredSecGroupId() );
				keyUIncludeIdx.setRequiredIncludeGroupId( obj->getRequiredIncludeGroupId() );
				auto removalProbe = indexByUIncludeIdx->find( keyUIncludeIdx );
				if( removalProbe != indexByUIncludeIdx->end() ) {
					indexByUIncludeIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
