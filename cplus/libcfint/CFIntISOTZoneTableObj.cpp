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

	const std::string CFIntISOTZoneTableObj::CLASS_NAME( "CFIntISOTZoneTableObj" );
	const std::string CFIntISOTZoneTableObj::TABLE_NAME( "ISOTZone" );
	const std::string CFIntISOTZoneTableObj::TABLE_DBNAME( "ISOTz" );

	CFIntISOTZoneTableObj::CFIntISOTZoneTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>();
		allISOTZone = NULL;
		indexByOffsetIdx = new std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
		indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
			cfsec::ICFSecISOTZoneObj*>();
		indexByIso8601Idx = new std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
	}

	CFIntISOTZoneTableObj::CFIntISOTZoneTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>();
		allISOTZone = NULL;
		indexByOffsetIdx = new std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
		indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
			cfsec::ICFSecISOTZoneObj*>();
		indexByIso8601Idx = new std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
	}

	CFIntISOTZoneTableObj::~CFIntISOTZoneTableObj() {
		minimizeMemory();
		if( indexByOffsetIdx != NULL ) {
			delete indexByOffsetIdx;
			indexByOffsetIdx = NULL;
		}
		if( indexByUTZNameIdx != NULL ) {
			delete indexByUTZNameIdx;
			indexByUTZNameIdx = NULL;
		}
		if( indexByIso8601Idx != NULL ) {
			delete indexByIso8601Idx;
			indexByIso8601Idx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecISOTZoneObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntISOTZoneTableObj::getSchema() {
		return( schema );
	}

	void CFIntISOTZoneTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntISOTZoneTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntISOTZoneTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntISOTZoneTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntISOTZoneTableObj::minimizeMemory() {
		if( allISOTZone != NULL ) {
			allISOTZone->clear();
			delete allISOTZone;
			allISOTZone = NULL;
		}
		if( indexByOffsetIdx != NULL ) {
			std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* >::iterator iterByOffsetIdx = indexByOffsetIdx->begin();
			std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* >::iterator endByOffsetIdx = indexByOffsetIdx->end();
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* curByOffsetIdx = NULL;
			while( iterByOffsetIdx != endByOffsetIdx ) {
				curByOffsetIdx = iterByOffsetIdx->second;
				if( curByOffsetIdx != NULL ) {
					curByOffsetIdx->clear();
					delete curByOffsetIdx;
					curByOffsetIdx = NULL;
					iterByOffsetIdx->second = NULL;
				}
				iterByOffsetIdx ++;
			}
			indexByOffsetIdx->clear();
		}
		if( indexByUTZNameIdx != NULL ) {
			indexByUTZNameIdx->clear();
		}
		if( indexByIso8601Idx != NULL ) {
			std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* >::iterator iterByIso8601Idx = indexByIso8601Idx->begin();
			std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* >::iterator endByIso8601Idx = indexByIso8601Idx->end();
			std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* curByIso8601Idx = NULL;
			while( iterByIso8601Idx != endByIso8601Idx ) {
				curByIso8601Idx = iterByIso8601Idx->second;
				if( curByIso8601Idx != NULL ) {
					curByIso8601Idx->clear();
					delete curByIso8601Idx;
					curByIso8601Idx = NULL;
					iterByIso8601Idx->second = NULL;
				}
				iterByIso8601Idx ++;
			}
			indexByIso8601Idx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecISOTZoneObj* cur = NULL;
			cfsec::ICFSecISOTZoneEditObj* edit = NULL;
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

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::newInstance() {
		cfsec::ICFSecISOTZoneObj* inst = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( new CFIntISOTZoneObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecISOTZoneEditObj* CFIntISOTZoneTableObj::newEditInstance( cfsec::ICFSecISOTZoneObj* orig ) {
		cfsec::ICFSecISOTZoneEditObj* edit = dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( new CFIntISOTZoneEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::realizeISOTZone( cfsec::ICFSecISOTZoneObj* Obj ) {
		static const std::string S_ProcName( "realizeISOTZone" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOTZoneObj* obj = Obj;
		cfsec::ICFSecISOTZoneObj* existingObj = NULL;
		cfsec::CFSecISOTZonePKey* pkey = obj->getPKey();
		cfsec::ICFSecISOTZoneObj* keepObj = NULL;
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
			if( indexByOffsetIdx != NULL ) {
				cfsec::CFSecISOTZoneByOffsetIdxKey keyOffsetIdx;
				keyOffsetIdx.setRequiredTZHourOffset( keepObj->getRequiredTZHourOffset() );
				keyOffsetIdx.setRequiredTZMinOffset( keepObj->getRequiredTZMinOffset() );
				auto searchOffsetIdx = indexByOffsetIdx->find( keyOffsetIdx );
				if( searchOffsetIdx != indexByOffsetIdx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapOffsetIdx = searchOffsetIdx->second;
					if( mapOffsetIdx != NULL ) {
						auto removalProbe = mapOffsetIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapOffsetIdx->end() ) {
							mapOffsetIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUTZNameIdx != NULL ) {
				cfsec::CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx;
				keyUTZNameIdx.setRequiredTZName( keepObj->getRequiredTZName() );
				auto removalProbe = indexByUTZNameIdx->find( keyUTZNameIdx );
				if( removalProbe != indexByUTZNameIdx->end() ) {
					indexByUTZNameIdx->erase( removalProbe );
				}
			}

			if( indexByIso8601Idx != NULL ) {
				cfsec::CFSecISOTZoneByIso8601IdxKey keyIso8601Idx;
				keyIso8601Idx.setRequiredIso8601( keepObj->getRequiredIso8601() );
				auto searchIso8601Idx = indexByIso8601Idx->find( keyIso8601Idx );
				if( searchIso8601Idx != indexByIso8601Idx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapIso8601Idx = searchIso8601Idx->second;
					if( mapIso8601Idx != NULL ) {
						auto removalProbe = mapIso8601Idx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapIso8601Idx->end() ) {
							mapIso8601Idx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByOffsetIdx != NULL ) {
				static const std::string S_AOffsetIdxObj( "aOffsetIdxObj" );
				cfsec::ICFSecISOTZoneObj* aOffsetIdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aOffsetIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AOffsetIdxObj );
				}
				cfsec::CFSecISOTZoneByOffsetIdxKey keyOffsetIdx;
				keyOffsetIdx.setRequiredTZHourOffset( keepObj->getRequiredTZHourOffset() );
				keyOffsetIdx.setRequiredTZMinOffset( keepObj->getRequiredTZMinOffset() );
				auto searchIndexByOffsetIdx = indexByOffsetIdx->find( keyOffsetIdx );
				if( searchIndexByOffsetIdx != indexByOffsetIdx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapOffsetIdx = searchIndexByOffsetIdx->second;
					if( mapOffsetIdx != NULL ) {
						mapOffsetIdx->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), aOffsetIdxObj ) );
					}
				}
			}

			if( indexByUTZNameIdx != NULL ) {
				static const std::string S_AUTZNameIdxObj( "aUTZNameIdxObj" );
				cfsec::ICFSecISOTZoneObj* aUTZNameIdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aUTZNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUTZNameIdxObj );
				}
				cfsec::CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx;
				keyUTZNameIdx.setRequiredTZName( keepObj->getRequiredTZName() );
				indexByUTZNameIdx->insert( std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey, cfsec::ICFSecISOTZoneObj* >::value_type( keyUTZNameIdx, aUTZNameIdxObj ) );
			}

			if( indexByIso8601Idx != NULL ) {
				static const std::string S_AIso8601IdxObj( "aIso8601IdxObj" );
				cfsec::ICFSecISOTZoneObj* aIso8601IdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aIso8601IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIso8601IdxObj );
				}
				cfsec::CFSecISOTZoneByIso8601IdxKey keyIso8601Idx;
				keyIso8601Idx.setRequiredIso8601( keepObj->getRequiredIso8601() );
				auto searchIndexByIso8601Idx = indexByIso8601Idx->find( keyIso8601Idx );
				if( searchIndexByIso8601Idx != indexByIso8601Idx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapIso8601Idx = searchIndexByIso8601Idx->second;
					if( mapIso8601Idx != NULL ) {
						mapIso8601Idx->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), aIso8601IdxObj ) );
					}
				}
			}

			if( allISOTZone != NULL ) {
				allISOTZone->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByOffsetIdx != NULL ) {
				static const std::string S_AOffsetIdxObj( "aOffsetIdxObj" );
				cfsec::ICFSecISOTZoneObj* aOffsetIdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aOffsetIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AOffsetIdxObj );
				}
				cfsec::CFSecISOTZoneByOffsetIdxKey keyOffsetIdx;
				keyOffsetIdx.setRequiredTZHourOffset( keepObj->getRequiredTZHourOffset() );
				keyOffsetIdx.setRequiredTZMinOffset( keepObj->getRequiredTZMinOffset() );
				auto searchIndexByOffsetIdx = indexByOffsetIdx->find( keyOffsetIdx );
				if( searchIndexByOffsetIdx != indexByOffsetIdx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapOffsetIdx = searchIndexByOffsetIdx->second;
					if( mapOffsetIdx != NULL ) {
						mapOffsetIdx->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), aOffsetIdxObj ) );
					}
				}
			}

			if( indexByUTZNameIdx != NULL ) {
				static const std::string S_AUTZNameIdxObj( "aUTZNameIdxObj" );
				cfsec::ICFSecISOTZoneObj* aUTZNameIdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aUTZNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUTZNameIdxObj );
				}
				cfsec::CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx;
				keyUTZNameIdx.setRequiredTZName( keepObj->getRequiredTZName() );
				indexByUTZNameIdx->insert( std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey, cfsec::ICFSecISOTZoneObj* >::value_type( keyUTZNameIdx, aUTZNameIdxObj ) );
			}

			if( indexByIso8601Idx != NULL ) {
				static const std::string S_AIso8601IdxObj( "aIso8601IdxObj" );
				cfsec::ICFSecISOTZoneObj* aIso8601IdxObj =
					dynamic_cast<cfsec::ICFSecISOTZoneObj*>( keepObj );
				if( aIso8601IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIso8601IdxObj );
				}
				cfsec::CFSecISOTZoneByIso8601IdxKey keyIso8601Idx;
				keyIso8601Idx.setRequiredIso8601( keepObj->getRequiredIso8601() );
				auto searchIndexByIso8601Idx = indexByIso8601Idx->find( keyIso8601Idx );
				if( searchIndexByIso8601Idx != indexByIso8601Idx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapIso8601Idx = searchIndexByIso8601Idx->second;
					if( mapIso8601Idx != NULL ) {
						mapIso8601Idx->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), aIso8601IdxObj ) );
					}
				}
			}

			if( allISOTZone != NULL ) {
				allISOTZone->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntISOTZoneTableObj::deepDisposeByIdIdx( const int16_t ISOTZoneId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecISOTZoneObj*> list;
		cfsec::ICFSecISOTZoneObj* existingObj = readCachedISOTZoneByIdIdx( ISOTZoneId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOTZoneObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->reallyDeepDisposeISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOTZoneTableObj::deepDisposeByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset ) {
		static const std::string S_ProcName( "deepDisposeByOffsetIdx" );
		std::vector<cfsec::ICFSecISOTZoneObj*> list;
		std::vector<cfsec::ICFSecISOTZoneObj*> matchesFound = readCachedISOTZoneByOffsetIdx( TZHourOffset,
				TZMinOffset );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecISOTZoneObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->reallyDeepDisposeISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOTZoneTableObj::deepDisposeByUTZNameIdx( const std::string& TZName ) {
		static const std::string S_ProcName( "deepDisposeByUTZNameIdx" );
		std::vector<cfsec::ICFSecISOTZoneObj*> list;
		cfsec::ICFSecISOTZoneObj* existingObj = readCachedISOTZoneByUTZNameIdx( TZName );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOTZoneObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->reallyDeepDisposeISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOTZoneTableObj::deepDisposeByIso8601Idx( const std::string& Iso8601 ) {
		static const std::string S_ProcName( "deepDisposeByIso8601Idx" );
		std::vector<cfsec::ICFSecISOTZoneObj*> list;
		std::vector<cfsec::ICFSecISOTZoneObj*> matchesFound = readCachedISOTZoneByIso8601Idx( Iso8601 );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecISOTZoneObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->reallyDeepDisposeISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOTZoneTableObj::reallyDeepDisposeISOTZone( cfsec::ICFSecISOTZoneObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeISOTZone" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecISOTZoneObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecISOTZoneBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->reallyDetachFromIndexesISOTZone( dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::createISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj ) {
		static const std::string S_ProcName( "createISOTZone" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOTZoneObj* obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOTZoneBuff* buff = dynamic_cast<cfsec::CFSecISOTZoneBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->createISOTZone(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecISOTZoneBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
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

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::readISOTZone( cfsec::CFSecISOTZonePKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOTZone" );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOTZoneBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredISOTZoneId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
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

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::lockISOTZone( cfsec::CFSecISOTZonePKey* pkey ) {
		static const std::string S_ProcName( "lockISOTZone" );
		cfsec::ICFSecISOTZoneObj* locked = NULL;
		cfsec::CFSecISOTZoneBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecISOTZoneObj*> CFIntISOTZoneTableObj::readAllISOTZone( bool forceRead ) {
		static const std::string S_ProcName( "readAllISOTZone" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		if( forceRead || ( allISOTZone == NULL ) ) {
			std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* map = new std::map<cfsec::CFSecISOTZonePKey,cfsec::ICFSecISOTZoneObj*>();
			allISOTZone = map;
			std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecISOTZoneBuff* buff = NULL;
			cfsec::ICFSecISOTZoneObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allISOTZone->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allISOTZone->size();
		std::vector<cfsec::ICFSecISOTZoneObj*> arr;
		auto valIter = allISOTZone->begin();
		size_t idx = 0;
		while( valIter != allISOTZone->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::readISOTZoneByIdIdx( const int16_t ISOTZoneId, bool forceRead )
	{
		static const std::string S_ProcName( "readISOTZoneByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOTZonePKey pkey;
		pkey.setRequiredISOTZoneId( ISOTZoneId );
		cfsec::ICFSecISOTZoneObj* obj = readISOTZone( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecISOTZoneObj*> CFIntISOTZoneTableObj::readISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset,
		bool forceRead )
	{
		static const std::string S_ProcName( "readISOTZoneByOffsetIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOTZoneByOffsetIdxKey key;
		key.setRequiredTZHourOffset( TZHourOffset );
		key.setRequiredTZMinOffset( TZMinOffset );
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* dict;
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* oldDict;
		if( indexByOffsetIdx == NULL ) {
			indexByOffsetIdx = new std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
		}
		auto searchIndexByOffsetIdx = indexByOffsetIdx->find( key );
		if( searchIndexByOffsetIdx != indexByOffsetIdx->end() ) {
			oldDict = searchIndexByOffsetIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>();
			cfsec::ICFSecISOTZoneObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByOffsetIdx( schema->getAuthorization(),
				TZHourOffset,
				TZMinOffset );
			cfsec::CFSecISOTZoneBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecISOTZoneObj* realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByOffsetIdx->erase( searchIndexByOffsetIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByOffsetIdx->insert( std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecISOTZoneObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::readISOTZoneByUTZNameIdx( const std::string& TZName, bool forceRead )
	{
		static const std::string S_ProcName( "readISOTZoneByUTZNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUTZNameIdx == NULL ) {
			indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
				cfsec::ICFSecISOTZoneObj*>();
		}
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( TZName );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUTZNameIdx = indexByUTZNameIdx->find( key );
			if( searchIndexByUTZNameIdx != indexByUTZNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUTZNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOTZoneBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByUTZNameIdx( schema->getAuthorization(),
				TZName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUTZNameIdx->insert( std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey, cfsec::ICFSecISOTZoneObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOTZoneObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecISOTZoneObj*> CFIntISOTZoneTableObj::readISOTZoneByIso8601Idx( const std::string& Iso8601,
		bool forceRead )
	{
		static const std::string S_ProcName( "readISOTZoneByIso8601Idx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOTZoneByIso8601IdxKey key;
		key.setRequiredIso8601( Iso8601 );
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* dict;
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* oldDict;
		if( indexByIso8601Idx == NULL ) {
			indexByIso8601Idx = new std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>();
		}
		auto searchIndexByIso8601Idx = indexByIso8601Idx->find( key );
		if( searchIndexByIso8601Idx != indexByIso8601Idx->end() ) {
			oldDict = searchIndexByIso8601Idx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>();
			cfsec::ICFSecISOTZoneObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecISOTZoneBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByIso8601Idx( schema->getAuthorization(),
				Iso8601 );
			cfsec::CFSecISOTZoneBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecISOTZoneObj* realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByIso8601Idx->erase( searchIndexByIso8601Idx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByIso8601Idx->insert( std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
				std::map< cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecISOTZoneObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::readISOTZoneByLookupUTZNameIdx( const std::string& TZName, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readISOTZoneByLookupUTZNameIdx" );
		if( indexByUTZNameIdx == NULL ) {
			indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
				cfsec::ICFSecISOTZoneObj*>();
		}
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( TZName );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUTZNameIdx = indexByUTZNameIdx->find( key );
			if( searchIndexByUTZNameIdx != indexByUTZNameIdx->end() ) {
				obj = searchIndexByUTZNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOTZoneBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->readDerivedByLookupUTZNameIdx( schema->getAuthorization(),
				TZName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUTZNameIdx->insert( std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey, cfsec::ICFSecISOTZoneObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOTZoneObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::readCachedISOTZone( cfsec::CFSecISOTZonePKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOTZone" );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::readCachedISOTZoneByIdIdx( const int16_t ISOTZoneId )
	{
		static const std::string S_ProcName( "readCachedISOTZoneByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOTZonePKey pkey;
		pkey.setRequiredISOTZoneId( ISOTZoneId );
		cfsec::ICFSecISOTZoneObj* obj = readCachedISOTZone( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecISOTZoneObj*> CFIntISOTZoneTableObj::readCachedISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset )
	{
		static const std::string S_ProcName( "readCachedISOTZoneByOffsetIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecISOTZoneObj*> arr;
		cfsec::CFSecISOTZoneByOffsetIdxKey key;
		key.setRequiredTZHourOffset( TZHourOffset );
		key.setRequiredTZMinOffset( TZMinOffset );
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* dict;
		if( indexByOffsetIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByOffsetIdx = indexByOffsetIdx->find( key );
		if( searchIndexByOffsetIdx != indexByOffsetIdx->end() ) {
			dict = searchIndexByOffsetIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecISOTZoneObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecISOTZoneObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOTZoneBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::readCachedISOTZoneByUTZNameIdx( const std::string& TZName )
	{
		static const std::string S_ProcName( "readCachedISOTZoneByUTZNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUTZNameIdx == NULL ) {
			indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
				cfsec::ICFSecISOTZoneObj*>();
		}
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( TZName );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		auto searchIndexByUTZNameIdx = indexByUTZNameIdx->find( key );
		if( searchIndexByUTZNameIdx != indexByUTZNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUTZNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOTZoneBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecISOTZoneObj*> CFIntISOTZoneTableObj::readCachedISOTZoneByIso8601Idx( const std::string& Iso8601 )
	{
		static const std::string S_ProcName( "readCachedISOTZoneByIso8601Idx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecISOTZoneObj*> arr;
		cfsec::CFSecISOTZoneByIso8601IdxKey key;
		key.setRequiredIso8601( Iso8601 );
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* dict;
		if( indexByIso8601Idx == NULL ) {
			return( arr );
		}
		auto searchIndexByIso8601Idx = indexByIso8601Idx->find( key );
		if( searchIndexByIso8601Idx != indexByIso8601Idx->end() ) {
			dict = searchIndexByIso8601Idx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecISOTZoneObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecISOTZoneObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOTZoneBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::readCachedISOTZoneByLookupUTZNameIdx( const std::string& TZName )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedISOTZoneByLookupUTZNameIdx" );
		if( indexByUTZNameIdx == NULL ) {
			indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
				cfsec::ICFSecISOTZoneObj*>();
		}
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( TZName );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		cfsec::ICFSecISOTZoneObj* realized = NULL;
		auto searchIndexByUTZNameIdx = indexByUTZNameIdx->find( key );
		if( searchIndexByUTZNameIdx != indexByUTZNameIdx->end() ) {
			obj = searchIndexByUTZNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOTZoneBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOTZoneObj* CFIntISOTZoneTableObj::updateISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj ) {
		static const std::string S_ProcName( "updateISOTZone" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOTZoneObj* obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOTZoneBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->updateISOTZone( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecISOTZoneBuff*>( Obj->getISOTZoneBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( dynamic_cast<cfint::CFIntISOTZoneTableObj*>( schema->getISOTZoneTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecISOTZoneObj*>( obj->realize() );
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

	void CFIntISOTZoneTableObj::deleteISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj ) {
		cfsec::ICFSecISOTZoneObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->deleteISOTZone( schema->getAuthorization(),
			obj->getISOTZoneBuff() );
		deepDisposeByIdIdx( obj->getRequiredISOTZoneId() );
	}

	void CFIntISOTZoneTableObj::deleteISOTZoneByIdIdx( const int16_t ISOTZoneId )
	{
		cfsec::CFSecISOTZonePKey pkey;
		pkey.setRequiredISOTZoneId( ISOTZoneId );
		cfsec::ICFSecISOTZoneObj* obj = readISOTZone( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecISOTZoneEditObj* editObj = dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecISOTZoneEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntISOTZoneTableObj::deleteISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->deleteISOTZoneByOffsetIdx( schema->getAuthorization(),
				TZHourOffset,
				TZMinOffset );
		deepDisposeByOffsetIdx( TZHourOffset,
			TZMinOffset );
	}

	void CFIntISOTZoneTableObj::deleteISOTZoneByUTZNameIdx( const std::string& TZName )
	{
		if( indexByUTZNameIdx == NULL ) {
			indexByUTZNameIdx = new std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
				cfsec::ICFSecISOTZoneObj*>();
		}
		cfsec::CFSecISOTZoneByUTZNameIdxKey key;
		key.setRequiredTZName( TZName );
		cfsec::ICFSecISOTZoneObj* obj = NULL;
		auto searchIndexByUTZNameIdx = indexByUTZNameIdx->find( key );
		if( searchIndexByUTZNameIdx != indexByUTZNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->deleteISOTZoneByUTZNameIdx( schema->getAuthorization(),
				TZName );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOTZone()->deleteISOTZoneByUTZNameIdx( schema->getAuthorization(),
				TZName );
		}
		deepDisposeByUTZNameIdx( TZName );
	}

	void CFIntISOTZoneTableObj::deleteISOTZoneByIso8601Idx( const std::string& Iso8601 )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableISOTZone()->deleteISOTZoneByIso8601Idx( schema->getAuthorization(),
				Iso8601 );
		deepDisposeByIso8601Idx( Iso8601 );
	}

	void CFIntISOTZoneTableObj::reallyDetachFromIndexesISOTZone( cfsec::ICFSecISOTZoneObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesISOTZone" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOTZoneObj* obj = Obj;
		cfsec::CFSecISOTZonePKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecISOTZoneObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByOffsetIdx != NULL ) {
				cfsec::CFSecISOTZoneByOffsetIdxKey keyOffsetIdx;
				keyOffsetIdx.setRequiredTZHourOffset( obj->getRequiredTZHourOffset() );
				keyOffsetIdx.setRequiredTZMinOffset( obj->getRequiredTZMinOffset() );
				auto searchOffsetIdx = indexByOffsetIdx->find( keyOffsetIdx );
				if( searchOffsetIdx != indexByOffsetIdx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapOffsetIdx = searchOffsetIdx->second;
					if( mapOffsetIdx != NULL ) {
						auto removalProbe = mapOffsetIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapOffsetIdx->end() ) {
							mapOffsetIdx->erase( removalProbe );
							if( mapOffsetIdx->empty() ) {
								delete mapOffsetIdx;
								mapOffsetIdx = NULL;
								indexByOffsetIdx->erase( searchOffsetIdx );
							}
						}
					}
				}
			}

			if( indexByUTZNameIdx != NULL ) {
				cfsec::CFSecISOTZoneByUTZNameIdxKey keyUTZNameIdx;
				keyUTZNameIdx.setRequiredTZName( obj->getRequiredTZName() );
				auto removalProbe = indexByUTZNameIdx->find( keyUTZNameIdx );
				if( removalProbe != indexByUTZNameIdx->end() ) {
					indexByUTZNameIdx->erase( removalProbe );
				}
			}

			if( indexByIso8601Idx != NULL ) {
				cfsec::CFSecISOTZoneByIso8601IdxKey keyIso8601Idx;
				keyIso8601Idx.setRequiredIso8601( obj->getRequiredIso8601() );
				auto searchIso8601Idx = indexByIso8601Idx->find( keyIso8601Idx );
				if( searchIso8601Idx != indexByIso8601Idx->end() ) {
					std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* mapIso8601Idx = searchIso8601Idx->second;
					if( mapIso8601Idx != NULL ) {
						auto removalProbe = mapIso8601Idx->find( *(obj->getPKey()) );
						if( removalProbe != mapIso8601Idx->end() ) {
							mapIso8601Idx->erase( removalProbe );
							if( mapIso8601Idx->empty() ) {
								delete mapIso8601Idx;
								mapIso8601Idx = NULL;
								indexByIso8601Idx->erase( searchIso8601Idx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}


}
