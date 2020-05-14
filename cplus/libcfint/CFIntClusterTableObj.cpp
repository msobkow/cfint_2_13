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

	const std::string CFIntClusterTableObj::CLASS_NAME( "CFIntClusterTableObj" );
	const std::string CFIntClusterTableObj::TABLE_NAME( "Cluster" );
	const std::string CFIntClusterTableObj::TABLE_DBNAME( "clus" );

	CFIntClusterTableObj::CFIntClusterTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj*>();
		allCluster = NULL;
		indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
			cfsec::ICFSecClusterObj*>();
		indexByUDescrIdx = new std::map< cfsec::CFSecClusterByUDescrIdxKey,
			cfsec::ICFSecClusterObj*>();
	}

	CFIntClusterTableObj::CFIntClusterTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj*>();
		allCluster = NULL;
		indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
			cfsec::ICFSecClusterObj*>();
		indexByUDescrIdx = new std::map< cfsec::CFSecClusterByUDescrIdxKey,
			cfsec::ICFSecClusterObj*>();
	}

	CFIntClusterTableObj::~CFIntClusterTableObj() {
		minimizeMemory();
		if( indexByUDomNameIdx != NULL ) {
			delete indexByUDomNameIdx;
			indexByUDomNameIdx = NULL;
		}
		if( indexByUDescrIdx != NULL ) {
			delete indexByUDescrIdx;
			indexByUDescrIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecClusterObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntClusterTableObj::getSchema() {
		return( schema );
	}

	void CFIntClusterTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntClusterTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntClusterTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntClusterTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntClusterTableObj::minimizeMemory() {
		if( allCluster != NULL ) {
			allCluster->clear();
			delete allCluster;
			allCluster = NULL;
		}
		if( indexByUDomNameIdx != NULL ) {
			indexByUDomNameIdx->clear();
		}
		if( indexByUDescrIdx != NULL ) {
			indexByUDescrIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecClusterObj* cur = NULL;
			cfsec::ICFSecClusterEditObj* edit = NULL;
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

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::newInstance() {
		cfsec::ICFSecClusterObj* inst = dynamic_cast<cfsec::ICFSecClusterObj*>( new CFIntClusterObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecClusterEditObj* CFIntClusterTableObj::newEditInstance( cfsec::ICFSecClusterObj* orig ) {
		cfsec::ICFSecClusterEditObj* edit = dynamic_cast<cfsec::ICFSecClusterEditObj*>( new CFIntClusterEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::realizeCluster( cfsec::ICFSecClusterObj* Obj ) {
		static const std::string S_ProcName( "realizeCluster" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecClusterObj* obj = Obj;
		cfsec::ICFSecClusterObj* existingObj = NULL;
		cfsec::CFSecClusterPKey* pkey = obj->getPKey();
		cfsec::ICFSecClusterObj* keepObj = NULL;
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
			if( indexByUDomNameIdx != NULL ) {
				cfsec::CFSecClusterByUDomNameIdxKey keyUDomNameIdx;
				keyUDomNameIdx.setRequiredFullDomName( keepObj->getRequiredFullDomName() );
				auto removalProbe = indexByUDomNameIdx->find( keyUDomNameIdx );
				if( removalProbe != indexByUDomNameIdx->end() ) {
					indexByUDomNameIdx->erase( removalProbe );
				}
			}

			if( indexByUDescrIdx != NULL ) {
				cfsec::CFSecClusterByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				auto removalProbe = indexByUDescrIdx->find( keyUDescrIdx );
				if( removalProbe != indexByUDescrIdx->end() ) {
					indexByUDescrIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecClusterBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByUDomNameIdx != NULL ) {
				static const std::string S_AUDomNameIdxObj( "aUDomNameIdxObj" );
				cfsec::ICFSecClusterObj* aUDomNameIdxObj =
					dynamic_cast<cfsec::ICFSecClusterObj*>( keepObj );
				if( aUDomNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDomNameIdxObj );
				}
				cfsec::CFSecClusterByUDomNameIdxKey keyUDomNameIdx;
				keyUDomNameIdx.setRequiredFullDomName( keepObj->getRequiredFullDomName() );
				indexByUDomNameIdx->insert( std::map< cfsec::CFSecClusterByUDomNameIdxKey, cfsec::ICFSecClusterObj* >::value_type( keyUDomNameIdx, aUDomNameIdxObj ) );
			}

			if( indexByUDescrIdx != NULL ) {
				static const std::string S_AUDescrIdxObj( "aUDescrIdxObj" );
				cfsec::ICFSecClusterObj* aUDescrIdxObj =
					dynamic_cast<cfsec::ICFSecClusterObj*>( keepObj );
				if( aUDescrIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDescrIdxObj );
				}
				cfsec::CFSecClusterByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				indexByUDescrIdx->insert( std::map< cfsec::CFSecClusterByUDescrIdxKey, cfsec::ICFSecClusterObj* >::value_type( keyUDescrIdx, aUDescrIdxObj ) );
			}

			if( allCluster != NULL ) {
				allCluster->insert( std::map< cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByUDomNameIdx != NULL ) {
				static const std::string S_AUDomNameIdxObj( "aUDomNameIdxObj" );
				cfsec::ICFSecClusterObj* aUDomNameIdxObj =
					dynamic_cast<cfsec::ICFSecClusterObj*>( keepObj );
				if( aUDomNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDomNameIdxObj );
				}
				cfsec::CFSecClusterByUDomNameIdxKey keyUDomNameIdx;
				keyUDomNameIdx.setRequiredFullDomName( keepObj->getRequiredFullDomName() );
				indexByUDomNameIdx->insert( std::map< cfsec::CFSecClusterByUDomNameIdxKey, cfsec::ICFSecClusterObj* >::value_type( keyUDomNameIdx, aUDomNameIdxObj ) );
			}

			if( indexByUDescrIdx != NULL ) {
				static const std::string S_AUDescrIdxObj( "aUDescrIdxObj" );
				cfsec::ICFSecClusterObj* aUDescrIdxObj =
					dynamic_cast<cfsec::ICFSecClusterObj*>( keepObj );
				if( aUDescrIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDescrIdxObj );
				}
				cfsec::CFSecClusterByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				indexByUDescrIdx->insert( std::map< cfsec::CFSecClusterByUDescrIdxKey, cfsec::ICFSecClusterObj* >::value_type( keyUDescrIdx, aUDescrIdxObj ) );
			}

			if( allCluster != NULL ) {
				allCluster->insert( std::map< cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntClusterTableObj::deepDisposeByIdIdx( const int64_t Id ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecClusterObj*> list;
		cfsec::ICFSecClusterObj* existingObj = readCachedClusterByIdIdx( Id );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecClusterObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntClusterTableObj*>( schema->getClusterTableObj() )->reallyDeepDisposeCluster( dynamic_cast<cfsec::ICFSecClusterObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntClusterTableObj::deepDisposeByUDomNameIdx( const std::string& FullDomName ) {
		static const std::string S_ProcName( "deepDisposeByUDomNameIdx" );
		std::vector<cfsec::ICFSecClusterObj*> list;
		cfsec::ICFSecClusterObj* existingObj = readCachedClusterByUDomNameIdx( FullDomName );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecClusterObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntClusterTableObj*>( schema->getClusterTableObj() )->reallyDeepDisposeCluster( dynamic_cast<cfsec::ICFSecClusterObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntClusterTableObj::deepDisposeByUDescrIdx( const std::string& Description ) {
		static const std::string S_ProcName( "deepDisposeByUDescrIdx" );
		std::vector<cfsec::ICFSecClusterObj*> list;
		cfsec::ICFSecClusterObj* existingObj = readCachedClusterByUDescrIdx( Description );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecClusterObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntClusterTableObj*>( schema->getClusterTableObj() )->reallyDeepDisposeCluster( dynamic_cast<cfsec::ICFSecClusterObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntClusterTableObj::reallyDeepDisposeCluster( cfsec::ICFSecClusterObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeCluster" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecClusterObj* obj = Obj;
		
		cfsec::ICFSecSecGroupObj* objDelSecGroupForms;
		std::vector<cfsec::ICFSecSecGroupObj*> arrDelSecGroupForms = dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->readCachedSecGroupByClusterIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator iterArrDelSecGroupForms = arrDelSecGroupForms.begin();
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator endArrDelSecGroupForms = arrDelSecGroupForms.end();
		while( iterArrDelSecGroupForms != endArrDelSecGroupForms ) {
			objDelSecGroupForms = *iterArrDelSecGroupForms;
			iterArrDelSecGroupForms ++;
			dynamic_cast<cfint::CFIntSecGroupFormTableObj*>( schema->getSecGroupFormTableObj() )->deepDisposeByGroupIdx( objDelSecGroupForms->getRequiredClusterId(),
				objDelSecGroupForms->getRequiredSecGroupId() );
		}
		cfsec::ICFSecSecGroupObj* objDelSecGrpIncByGroup;
		std::vector<cfsec::ICFSecSecGroupObj*> arrDelSecGrpIncByGroup = dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->readCachedSecGroupByClusterIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator iterArrDelSecGrpIncByGroup = arrDelSecGrpIncByGroup.begin();
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator endArrDelSecGrpIncByGroup = arrDelSecGrpIncByGroup.end();
		while( iterArrDelSecGrpIncByGroup != endArrDelSecGrpIncByGroup ) {
			objDelSecGrpIncByGroup = *iterArrDelSecGrpIncByGroup;
			iterArrDelSecGrpIncByGroup ++;
			dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->deepDisposeByIncludeIdx( objDelSecGrpIncByGroup->getRequiredClusterId(),
				objDelSecGrpIncByGroup->getRequiredSecGroupId() );
		}
		cfsec::ICFSecSecGroupObj* objDelSecGrpMembs;
		std::vector<cfsec::ICFSecSecGroupObj*> arrDelSecGrpMembs = dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->readCachedSecGroupByClusterIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator iterArrDelSecGrpMembs = arrDelSecGrpMembs.begin();
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator endArrDelSecGrpMembs = arrDelSecGrpMembs.end();
		while( iterArrDelSecGrpMembs != endArrDelSecGrpMembs ) {
			objDelSecGrpMembs = *iterArrDelSecGrpMembs;
			iterArrDelSecGrpMembs ++;
			dynamic_cast<cfint::CFIntSecGrpMembTableObj*>( schema->getSecGrpMembTableObj() )->deepDisposeByGroupIdx( objDelSecGrpMembs->getRequiredClusterId(),
				objDelSecGrpMembs->getRequiredSecGroupId() );
		}
		cfsec::ICFSecSecGroupObj* objDelSecGrpIncs;
		std::vector<cfsec::ICFSecSecGroupObj*> arrDelSecGrpIncs = dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->readCachedSecGroupByClusterIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator iterArrDelSecGrpIncs = arrDelSecGrpIncs.begin();
		std::vector<cfsec::ICFSecSecGroupObj*>::iterator endArrDelSecGrpIncs = arrDelSecGrpIncs.end();
		while( iterArrDelSecGrpIncs != endArrDelSecGrpIncs ) {
			objDelSecGrpIncs = *iterArrDelSecGrpIncs;
			iterArrDelSecGrpIncs ++;
			dynamic_cast<cfint::CFIntSecGrpIncTableObj*>( schema->getSecGrpIncTableObj() )->deepDisposeByGroupIdx( objDelSecGrpIncs->getRequiredClusterId(),
				objDelSecGrpIncs->getRequiredSecGroupId() );
		}
		dynamic_cast<cfint::CFIntSecGroupTableObj*>( schema->getSecGroupTableObj() )->deepDisposeByClusterIdx( obj->getRequiredId() );
		cfsec::ICFSecSecAppObj* objDelSecAppForms;
		std::vector<cfsec::ICFSecSecAppObj*> arrDelSecAppForms = dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->readCachedSecAppByClusterIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecSecAppObj*>::iterator iterArrDelSecAppForms = arrDelSecAppForms.begin();
		std::vector<cfsec::ICFSecSecAppObj*>::iterator endArrDelSecAppForms = arrDelSecAppForms.end();
		while( iterArrDelSecAppForms != endArrDelSecAppForms ) {
			objDelSecAppForms = *iterArrDelSecAppForms;
			iterArrDelSecAppForms ++;
			dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->deepDisposeBySecAppIdx( objDelSecAppForms->getRequiredClusterId(),
				objDelSecAppForms->getRequiredSecAppId() );
		}
		dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->deepDisposeByClusterIdx( obj->getRequiredId() );
		dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->deepDisposeByClusterIdx( obj->getRequiredId() );
		dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->deepDisposeByClusterIdx( obj->getRequiredId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecClusterBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntClusterTableObj*>( schema->getClusterTableObj() )->reallyDetachFromIndexesCluster( dynamic_cast<cfsec::ICFSecClusterObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::createCluster( cfsec::ICFSecClusterEditObj* Obj ) {
		static const std::string S_ProcName( "createCluster" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecClusterObj* obj = dynamic_cast<cfsec::ICFSecClusterObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecClusterBuff* buff = dynamic_cast<cfsec::CFSecClusterBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->createCluster(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecClusterBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
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

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::readCluster( cfsec::CFSecClusterPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readCluster" );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecClusterBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntClusterTableObj*>( schema->getClusterTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
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

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::lockCluster( cfsec::CFSecClusterPKey* pkey ) {
		static const std::string S_ProcName( "lockCluster" );
		cfsec::ICFSecClusterObj* locked = NULL;
		cfsec::CFSecClusterBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntClusterTableObj*>( schema->getClusterTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecClusterObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecClusterObj*> CFIntClusterTableObj::readAllCluster( bool forceRead ) {
		static const std::string S_ProcName( "readAllCluster" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecClusterObj* realized = NULL;
		if( forceRead || ( allCluster == NULL ) ) {
			std::map<cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj*>* map = new std::map<cfsec::CFSecClusterPKey,cfsec::ICFSecClusterObj*>();
			allCluster = map;
			std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecClusterBuff* buff = NULL;
			cfsec::ICFSecClusterObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allCluster->insert( std::map< cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allCluster->size();
		std::vector<cfsec::ICFSecClusterObj*> arr;
		auto valIter = allCluster->begin();
		size_t idx = 0;
		while( valIter != allCluster->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecClusterObj*> CFIntClusterTableObj::pageAllCluster(const int64_t* priorId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllCluster" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecClusterPKey, cfsec::ICFSecClusterObj*>* map = NULL;
		cfsec::CFSecClusterBuff* buff = NULL;
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		std::vector<cfsec::ICFSecClusterObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecClusterPKey,cfsec::ICFSecClusterObj*>();
			std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->pageAllBuff( schema->getAuthorization(),
				priorId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
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

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::readClusterByIdIdx( const int64_t Id, bool forceRead )
	{
		static const std::string S_ProcName( "readClusterByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecClusterPKey pkey;
		pkey.setRequiredId( Id );
		cfsec::ICFSecClusterObj* obj = readCluster( &pkey, forceRead );
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::readClusterByUDomNameIdx( const std::string& FullDomName, bool forceRead )
	{
		static const std::string S_ProcName( "readClusterByUDomNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDomNameIdx == NULL ) {
			indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( FullDomName );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUDomNameIdx = indexByUDomNameIdx->find( key );
			if( searchIndexByUDomNameIdx != indexByUDomNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUDomNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecClusterBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->readDerivedByUDomNameIdx( schema->getAuthorization(),
				FullDomName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntClusterTableObj*>( schema->getClusterTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUDomNameIdx->insert( std::map< cfsec::CFSecClusterByUDomNameIdxKey, cfsec::ICFSecClusterObj*>::value_type( key, dynamic_cast<cfsec::ICFSecClusterObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::readClusterByUDescrIdx( const std::string& Description, bool forceRead )
	{
		static const std::string S_ProcName( "readClusterByUDescrIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecClusterByUDescrIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
			if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUDescrIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecClusterBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->readDerivedByUDescrIdx( schema->getAuthorization(),
				Description );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntClusterTableObj*>( schema->getClusterTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUDescrIdx->insert( std::map< cfsec::CFSecClusterByUDescrIdxKey, cfsec::ICFSecClusterObj*>::value_type( key, dynamic_cast<cfsec::ICFSecClusterObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::readClusterByLookupUDomNameIdx( const std::string& FullDomName, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readClusterByLookupUDomNameIdx" );
		if( indexByUDomNameIdx == NULL ) {
			indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( FullDomName );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUDomNameIdx = indexByUDomNameIdx->find( key );
			if( searchIndexByUDomNameIdx != indexByUDomNameIdx->end() ) {
				obj = searchIndexByUDomNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecClusterBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->readDerivedByLookupUDomNameIdx( schema->getAuthorization(),
				FullDomName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecClusterObj*>( dynamic_cast<cfint::CFIntClusterTableObj*>( schema->getClusterTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUDomNameIdx->insert( std::map< cfsec::CFSecClusterByUDomNameIdxKey, cfsec::ICFSecClusterObj*>::value_type( key, dynamic_cast<cfsec::ICFSecClusterObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::readCachedCluster( cfsec::CFSecClusterPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readCluster" );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::readCachedClusterByIdIdx( const int64_t Id )
	{
		static const std::string S_ProcName( "readCachedClusterByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecClusterPKey pkey;
		pkey.setRequiredId( Id );
		cfsec::ICFSecClusterObj* obj = readCachedCluster( &pkey );
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::readCachedClusterByUDomNameIdx( const std::string& FullDomName )
	{
		static const std::string S_ProcName( "readCachedClusterByUDomNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDomNameIdx == NULL ) {
			indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( FullDomName );
		cfsec::ICFSecClusterObj* obj = NULL;
		auto searchIndexByUDomNameIdx = indexByUDomNameIdx->find( key );
		if( searchIndexByUDomNameIdx != indexByUDomNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUDomNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecClusterBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::readCachedClusterByUDescrIdx( const std::string& Description )
	{
		static const std::string S_ProcName( "readCachedClusterByUDescrIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecClusterByUDescrIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::ICFSecClusterObj* obj = NULL;
		auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
		if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUDescrIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecClusterBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::readCachedClusterByLookupUDomNameIdx( const std::string& FullDomName )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedClusterByLookupUDomNameIdx" );
		if( indexByUDomNameIdx == NULL ) {
			indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( FullDomName );
		cfsec::ICFSecClusterObj* obj = NULL;
		cfsec::ICFSecClusterObj* realized = NULL;
		auto searchIndexByUDomNameIdx = indexByUDomNameIdx->find( key );
		if( searchIndexByUDomNameIdx != indexByUDomNameIdx->end() ) {
			obj = searchIndexByUDomNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecClusterBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::updateCluster( cfsec::ICFSecClusterEditObj* Obj ) {
		static const std::string S_ProcName( "updateCluster" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecClusterObj* obj = dynamic_cast<cfsec::ICFSecClusterObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecClusterBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->updateCluster( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecClusterBuff*>( Obj->getClusterBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecClusterObj*>( dynamic_cast<cfint::CFIntClusterTableObj*>( schema->getClusterTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecClusterObj*>( obj->realize() );
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

	void CFIntClusterTableObj::deleteCluster( cfsec::ICFSecClusterEditObj* Obj ) {
		cfsec::ICFSecClusterObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->deleteCluster( schema->getAuthorization(),
			obj->getClusterBuff() );
		deepDisposeByIdIdx( obj->getRequiredId() );
	}

	void CFIntClusterTableObj::deleteClusterByIdIdx( const int64_t Id )
	{
		cfsec::CFSecClusterPKey pkey;
		pkey.setRequiredId( Id );
		cfsec::ICFSecClusterObj* obj = readCluster( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecClusterEditObj* editObj = dynamic_cast<cfsec::ICFSecClusterEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecClusterEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntClusterTableObj::deleteClusterByUDomNameIdx( const std::string& FullDomName )
	{
		if( indexByUDomNameIdx == NULL ) {
			indexByUDomNameIdx = new std::map< cfsec::CFSecClusterByUDomNameIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( FullDomName );
		cfsec::ICFSecClusterObj* obj = NULL;
		auto searchIndexByUDomNameIdx = indexByUDomNameIdx->find( key );
		if( searchIndexByUDomNameIdx != indexByUDomNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->deleteClusterByUDomNameIdx( schema->getAuthorization(),
				FullDomName );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->deleteClusterByUDomNameIdx( schema->getAuthorization(),
				FullDomName );
		}
		deepDisposeByUDomNameIdx( FullDomName );
	}

	void CFIntClusterTableObj::deleteClusterByUDescrIdx( const std::string& Description )
	{
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecClusterByUDescrIdxKey,
				cfsec::ICFSecClusterObj*>();
		}
		cfsec::CFSecClusterByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::ICFSecClusterObj* obj = NULL;
		auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
		if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->deleteClusterByUDescrIdx( schema->getAuthorization(),
				Description );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableCluster()->deleteClusterByUDescrIdx( schema->getAuthorization(),
				Description );
		}
		deepDisposeByUDescrIdx( Description );
	}

	void CFIntClusterTableObj::reallyDetachFromIndexesCluster( cfsec::ICFSecClusterObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesCluster" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecClusterObj* obj = Obj;
		cfsec::CFSecClusterPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecClusterObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByUDomNameIdx != NULL ) {
				cfsec::CFSecClusterByUDomNameIdxKey keyUDomNameIdx;
				keyUDomNameIdx.setRequiredFullDomName( obj->getRequiredFullDomName() );
				auto removalProbe = indexByUDomNameIdx->find( keyUDomNameIdx );
				if( removalProbe != indexByUDomNameIdx->end() ) {
					indexByUDomNameIdx->erase( removalProbe );
				}
			}

			if( indexByUDescrIdx != NULL ) {
				cfsec::CFSecClusterByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredDescription( obj->getRequiredDescription() );
				auto removalProbe = indexByUDescrIdx->find( keyUDescrIdx );
				if( removalProbe != indexByUDescrIdx->end() ) {
					indexByUDescrIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}

	cfsec::ICFSecClusterObj* CFIntClusterTableObj::getSystemCluster() {
		static const std::string S_System( "system" );
		bool transactionStarted = schema->beginTransaction();
		cfsec::ICFSecClusterObj* clusterObj;
		try {
			clusterObj = readClusterByUDomNameIdx( S_System );
			if( clusterObj == NULL ) {
				clusterObj = readClusterByUDomNameIdx( S_System, true );
				if( clusterObj == NULL ) {
					clusterObj = newInstance();
					cfsec::ICFSecClusterEditObj* clusterEdit = clusterObj->beginEdit();
					clusterEdit->setRequiredFullDomName( S_System );
					clusterEdit->setRequiredDescription( S_System );
					clusterObj = clusterEdit->create();
				}
			}
			if( transactionStarted ) {
				schema->commit();
			}
		}
		catch( std::exception& e ) {
			if( transactionStarted ) {
				try {
					schema->rollback();
				}
				catch( ... ) {
				}
			}
			throw e;
		}
		return( clusterObj );
	}


}
