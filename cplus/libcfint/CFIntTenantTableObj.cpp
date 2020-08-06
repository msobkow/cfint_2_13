// Description: C++18 Table Object implementation for CFInt.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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

	const std::string CFIntTenantTableObj::CLASS_NAME( "CFIntTenantTableObj" );
	const std::string CFIntTenantTableObj::TABLE_NAME( "Tenant" );
	const std::string CFIntTenantTableObj::TABLE_DBNAME( "tenant" );

	CFIntTenantTableObj::CFIntTenantTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>();
		allTenant = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecTenantByClusterIdxKey,
			std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>*>();
		indexByUNameIdx = new std::map< cfsec::CFSecTenantByUNameIdxKey,
			cfsec::ICFSecTenantObj*>();
	}

	CFIntTenantTableObj::CFIntTenantTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>();
		allTenant = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecTenantByClusterIdxKey,
			std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>*>();
		indexByUNameIdx = new std::map< cfsec::CFSecTenantByUNameIdxKey,
			cfsec::ICFSecTenantObj*>();
	}

	CFIntTenantTableObj::~CFIntTenantTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
		}
		if( indexByUNameIdx != NULL ) {
			delete indexByUNameIdx;
			indexByUNameIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecTenantObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntTenantTableObj::getSchema() {
		return( schema );
	}

	void CFIntTenantTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntTenantTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntTenantTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntTenantTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntTenantTableObj::minimizeMemory() {
		if( allTenant != NULL ) {
			allTenant->clear();
			delete allTenant;
			allTenant = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecTenantByClusterIdxKey,
				std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecTenantByClusterIdxKey,
				std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* curByClusterIdx = NULL;
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
		if( indexByUNameIdx != NULL ) {
			indexByUNameIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecTenantObj* cur = NULL;
			cfsec::ICFSecTenantEditObj* edit = NULL;
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

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::newInstance() {
		cfsec::ICFSecTenantObj* inst = dynamic_cast<cfsec::ICFSecTenantObj*>( new CFIntTenantObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecTenantEditObj* CFIntTenantTableObj::newEditInstance( cfsec::ICFSecTenantObj* orig ) {
		cfsec::ICFSecTenantEditObj* edit = dynamic_cast<cfsec::ICFSecTenantEditObj*>( new CFIntTenantEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::realizeTenant( cfsec::ICFSecTenantObj* Obj ) {
		static const std::string S_ProcName( "realizeTenant" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecTenantObj* obj = Obj;
		cfsec::ICFSecTenantObj* existingObj = NULL;
		cfsec::CFSecTenantPKey* pkey = obj->getPKey();
		cfsec::ICFSecTenantObj* keepObj = NULL;
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
				cfsec::CFSecTenantByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				cfsec::CFSecTenantByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUNameIdx.setRequiredTenantName( keepObj->getRequiredTenantName() );
				auto removalProbe = indexByUNameIdx->find( keyUNameIdx );
				if( removalProbe != indexByUNameIdx->end() ) {
					indexByUNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecTenantBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecTenantObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecTenantObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecTenantByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfsec::ICFSecTenantObj* aUNameIdxObj =
					dynamic_cast<cfsec::ICFSecTenantObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfsec::CFSecTenantByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUNameIdx.setRequiredTenantName( keepObj->getRequiredTenantName() );
				indexByUNameIdx->insert( std::map< cfsec::CFSecTenantByUNameIdxKey, cfsec::ICFSecTenantObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( allTenant != NULL ) {
				allTenant->insert( std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecTenantObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecTenantObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecTenantByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfsec::ICFSecTenantObj* aUNameIdxObj =
					dynamic_cast<cfsec::ICFSecTenantObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfsec::CFSecTenantByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUNameIdx.setRequiredTenantName( keepObj->getRequiredTenantName() );
				indexByUNameIdx->insert( std::map< cfsec::CFSecTenantByUNameIdxKey, cfsec::ICFSecTenantObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( allTenant != NULL ) {
				allTenant->insert( std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntTenantTableObj::deepDisposeByIdIdx( const int64_t Id ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecTenantObj*> list;
		cfsec::ICFSecTenantObj* existingObj = readCachedTenantByIdIdx( Id );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecTenantObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTenantBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->reallyDeepDisposeTenant( dynamic_cast<cfsec::ICFSecTenantObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTenantTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecTenantObj*> list;
		std::vector<cfsec::ICFSecTenantObj*> matchesFound = readCachedTenantByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecTenantObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTenantBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->reallyDeepDisposeTenant( dynamic_cast<cfsec::ICFSecTenantObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTenantTableObj::deepDisposeByUNameIdx( const int64_t ClusterId,
			const std::string& TenantName ) {
		static const std::string S_ProcName( "deepDisposeByUNameIdx" );
		std::vector<cfsec::ICFSecTenantObj*> list;
		cfsec::ICFSecTenantObj* existingObj = readCachedTenantByUNameIdx( ClusterId,
				TenantName );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecTenantObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecTenantBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->reallyDeepDisposeTenant( dynamic_cast<cfsec::ICFSecTenantObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTenantTableObj::reallyDeepDisposeTenant( cfsec::ICFSecTenantObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeTenant" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecTenantObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntTldTableObj*>( schema->getTldTableObj() )->deepDisposeByTenantIdx( obj->getRequiredId() );
		cfsec::ICFSecTSecGroupObj* objDelIncludedByGroup;
		std::vector<cfsec::ICFSecTSecGroupObj*> arrDelIncludedByGroup = dynamic_cast<cfint::CFIntTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->readCachedTSecGroupByTenantIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecTSecGroupObj*>::iterator iterArrDelIncludedByGroup = arrDelIncludedByGroup.begin();
		std::vector<cfsec::ICFSecTSecGroupObj*>::iterator endArrDelIncludedByGroup = arrDelIncludedByGroup.end();
		while( iterArrDelIncludedByGroup != endArrDelIncludedByGroup ) {
			objDelIncludedByGroup = *iterArrDelIncludedByGroup;
			iterArrDelIncludedByGroup ++;
			dynamic_cast<cfint::CFIntTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->deepDisposeByIncludeIdx( objDelIncludedByGroup->getRequiredTenantId(),
				objDelIncludedByGroup->getRequiredTSecGroupId() );
		}
		cfsec::ICFSecTSecGroupObj* objDelGrpMembs;
		std::vector<cfsec::ICFSecTSecGroupObj*> arrDelGrpMembs = dynamic_cast<cfint::CFIntTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->readCachedTSecGroupByTenantIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecTSecGroupObj*>::iterator iterArrDelGrpMembs = arrDelGrpMembs.begin();
		std::vector<cfsec::ICFSecTSecGroupObj*>::iterator endArrDelGrpMembs = arrDelGrpMembs.end();
		while( iterArrDelGrpMembs != endArrDelGrpMembs ) {
			objDelGrpMembs = *iterArrDelGrpMembs;
			iterArrDelGrpMembs ++;
			dynamic_cast<cfint::CFIntTSecGrpMembTableObj*>( schema->getTSecGrpMembTableObj() )->deepDisposeByGroupIdx( objDelGrpMembs->getRequiredTenantId(),
				objDelGrpMembs->getRequiredTSecGroupId() );
		}
		cfsec::ICFSecTSecGroupObj* objDelGrpIncs;
		std::vector<cfsec::ICFSecTSecGroupObj*> arrDelGrpIncs = dynamic_cast<cfint::CFIntTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->readCachedTSecGroupByTenantIdx( obj->getRequiredId() );
		std::vector<cfsec::ICFSecTSecGroupObj*>::iterator iterArrDelGrpIncs = arrDelGrpIncs.begin();
		std::vector<cfsec::ICFSecTSecGroupObj*>::iterator endArrDelGrpIncs = arrDelGrpIncs.end();
		while( iterArrDelGrpIncs != endArrDelGrpIncs ) {
			objDelGrpIncs = *iterArrDelGrpIncs;
			iterArrDelGrpIncs ++;
			dynamic_cast<cfint::CFIntTSecGrpIncTableObj*>( schema->getTSecGrpIncTableObj() )->deepDisposeByGroupIdx( objDelGrpIncs->getRequiredTenantId(),
				objDelGrpIncs->getRequiredTSecGroupId() );
		}
		dynamic_cast<cfint::CFIntTSecGroupTableObj*>( schema->getTSecGroupTableObj() )->deepDisposeByTenantIdx( obj->getRequiredId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecTenantBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->reallyDetachFromIndexesTenant( dynamic_cast<cfsec::ICFSecTenantObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::createTenant( cfsec::ICFSecTenantEditObj* Obj ) {
		static const std::string S_ProcName( "createTenant" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTenantObj* obj = dynamic_cast<cfsec::ICFSecTenantObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecTenantBuff* buff = dynamic_cast<cfsec::CFSecTenantBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->createTenant(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecTenantBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecTenantObj*>( obj->realize() );
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

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::readTenant( cfsec::CFSecTenantPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTenant" );
		cfsec::ICFSecTenantObj* obj = NULL;
		cfsec::ICFSecTenantObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecTenantBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecTenantObj*>( obj->realize() );
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

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::lockTenant( cfsec::CFSecTenantPKey* pkey ) {
		static const std::string S_ProcName( "lockTenant" );
		cfsec::ICFSecTenantObj* locked = NULL;
		cfsec::CFSecTenantBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecTenantObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecTenantObj*> CFIntTenantTableObj::readAllTenant( bool forceRead ) {
		static const std::string S_ProcName( "readAllTenant" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTenantObj* realized = NULL;
		if( forceRead || ( allTenant == NULL ) ) {
			std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* map = new std::map<cfsec::CFSecTenantPKey,cfsec::ICFSecTenantObj*>();
			allTenant = map;
			std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecTenantBuff* buff = NULL;
			cfsec::ICFSecTenantObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecTenantObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allTenant->insert( std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allTenant->size();
		std::vector<cfsec::ICFSecTenantObj*> arr;
		auto valIter = allTenant->begin();
		size_t idx = 0;
		while( valIter != allTenant->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecTenantObj*> CFIntTenantTableObj::pageAllTenant(const int64_t* priorId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllTenant" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* map = NULL;
		cfsec::CFSecTenantBuff* buff = NULL;
		cfsec::ICFSecTenantObj* obj = NULL;
		cfsec::ICFSecTenantObj* realized = NULL;
		std::vector<cfsec::ICFSecTenantObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecTenantPKey,cfsec::ICFSecTenantObj*>();
			std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->pageAllBuff( schema->getAuthorization(),
				priorId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecTenantObj*>( obj->realize() );
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

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::readTenantByIdIdx( const int64_t Id, bool forceRead )
	{
		static const std::string S_ProcName( "readTenantByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTenantPKey pkey;
		pkey.setRequiredId( Id );
		cfsec::ICFSecTenantObj* obj = readTenant( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecTenantObj*> CFIntTenantTableObj::readTenantByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTenantByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTenantByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* dict;
		std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecTenantByClusterIdxKey,
				std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>*>();
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
			dict = new std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>();
			cfsec::ICFSecTenantObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecTenantBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecTenantObj* realized = dynamic_cast<cfsec::ICFSecTenantObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecTenantByClusterIdxKey,
				std::map< cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecTenantObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::readTenantByUNameIdx( const int64_t ClusterId,
			const std::string& TenantName, bool forceRead )
	{
		static const std::string S_ProcName( "readTenantByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecTenantByUNameIdxKey,
				cfsec::ICFSecTenantObj*>();
		}
		cfsec::CFSecTenantByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredTenantName( TenantName );
		cfsec::ICFSecTenantObj* obj = NULL;
		cfsec::ICFSecTenantObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecTenantBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->readDerivedByUNameIdx( schema->getAuthorization(),
				ClusterId,
				TenantName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecTenantObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfsec::CFSecTenantByUNameIdxKey, cfsec::ICFSecTenantObj*>::value_type( key, dynamic_cast<cfsec::ICFSecTenantObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::readTenantByLookupUNameIdx( const int64_t ClusterId,
			const std::string& TenantName, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readTenantByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecTenantByUNameIdxKey,
				cfsec::ICFSecTenantObj*>();
		}
		cfsec::CFSecTenantByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredTenantName( TenantName );
		cfsec::ICFSecTenantObj* obj = NULL;
		cfsec::ICFSecTenantObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				obj = searchIndexByUNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecTenantBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->readDerivedByLookupUNameIdx( schema->getAuthorization(),
				ClusterId,
				TenantName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecTenantObj*>( dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecTenantObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfsec::CFSecTenantByUNameIdxKey, cfsec::ICFSecTenantObj*>::value_type( key, dynamic_cast<cfsec::ICFSecTenantObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::readCachedTenant( cfsec::CFSecTenantPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTenant" );
		cfsec::ICFSecTenantObj* obj = NULL;
		cfsec::ICFSecTenantObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::readCachedTenantByIdIdx( const int64_t Id )
	{
		static const std::string S_ProcName( "readCachedTenantByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTenantPKey pkey;
		pkey.setRequiredId( Id );
		cfsec::ICFSecTenantObj* obj = readCachedTenant( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecTenantObj*> CFIntTenantTableObj::readCachedTenantByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedTenantByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecTenantObj*> arr;
		cfsec::CFSecTenantByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecTenantObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecTenantObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTenantBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::readCachedTenantByUNameIdx( const int64_t ClusterId,
			const std::string& TenantName )
	{
		static const std::string S_ProcName( "readCachedTenantByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecTenantByUNameIdxKey,
				cfsec::ICFSecTenantObj*>();
		}
		cfsec::CFSecTenantByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredTenantName( TenantName );
		cfsec::ICFSecTenantObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTenantBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::readCachedTenantByLookupUNameIdx( const int64_t ClusterId,
			const std::string& TenantName )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedTenantByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecTenantByUNameIdxKey,
				cfsec::ICFSecTenantObj*>();
		}
		cfsec::CFSecTenantByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredTenantName( TenantName );
		cfsec::ICFSecTenantObj* obj = NULL;
		cfsec::ICFSecTenantObj* realized = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecTenantBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecTenantObj*> CFIntTenantTableObj::pageTenantByClusterIdx( const int64_t ClusterId,
			const int64_t* priorId )
	{
		static const std::string S_ProcName( "pageTenantByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecTenantByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		cfsec::ICFSecTenantObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->pageBuffByClusterIdx( schema->getAuthorization(),
				ClusterId,
				priorId );
		std::vector<cfsec::ICFSecTenantObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecTenantBuff* buff;
		cfsec::ICFSecTenantObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecTenantObj*>( obj->realize() );
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

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::updateTenant( cfsec::ICFSecTenantEditObj* Obj ) {
		static const std::string S_ProcName( "updateTenant" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecTenantObj* obj = dynamic_cast<cfsec::ICFSecTenantObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecTenantBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->updateTenant( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecTenantBuff*>( Obj->getTenantBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecTenantObj*>( dynamic_cast<cfint::CFIntTenantTableObj*>( schema->getTenantTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecTenantObj*>( obj->realize() );
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

	void CFIntTenantTableObj::deleteTenant( cfsec::ICFSecTenantEditObj* Obj ) {
		cfsec::ICFSecTenantObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->deleteTenant( schema->getAuthorization(),
			obj->getTenantBuff() );
		deepDisposeByIdIdx( obj->getRequiredId() );
	}

	void CFIntTenantTableObj::deleteTenantByIdIdx( const int64_t Id )
	{
		cfsec::CFSecTenantPKey pkey;
		pkey.setRequiredId( Id );
		cfsec::ICFSecTenantObj* obj = readTenant( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecTenantEditObj* editObj = dynamic_cast<cfsec::ICFSecTenantEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecTenantEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntTenantTableObj::deleteTenantByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableTenant()->deleteTenantByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFIntTenantTableObj::deleteTenantByUNameIdx( const int64_t ClusterId,
			const std::string& TenantName )
	{
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfsec::CFSecTenantByUNameIdxKey,
				cfsec::ICFSecTenantObj*>();
		}
		cfsec::CFSecTenantByUNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredTenantName( TenantName );
		cfsec::ICFSecTenantObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->deleteTenantByUNameIdx( schema->getAuthorization(),
				ClusterId,
				TenantName );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTenant()->deleteTenantByUNameIdx( schema->getAuthorization(),
				ClusterId,
				TenantName );
		}
		deepDisposeByUNameIdx( ClusterId,
			TenantName );
	}

	void CFIntTenantTableObj::reallyDetachFromIndexesTenant( cfsec::ICFSecTenantObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesTenant" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecTenantObj* obj = Obj;
		cfsec::CFSecTenantPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecTenantObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecTenantByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecTenantPKey, cfsec::ICFSecTenantObj*>* mapClusterIdx = searchClusterIdx->second;
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

			if( indexByUNameIdx != NULL ) {
				cfsec::CFSecTenantByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyUNameIdx.setRequiredTenantName( obj->getRequiredTenantName() );
				auto removalProbe = indexByUNameIdx->find( keyUNameIdx );
				if( removalProbe != indexByUNameIdx->end() ) {
					indexByUNameIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}

	cfsec::ICFSecTenantObj* CFIntTenantTableObj::getSystemTenant() {
		static const std::string S_System( "system" );
		bool transactionStarted = schema->beginTransaction();
		cfsec::ICFSecTenantObj* tenantObj;
		try {
			cfsec::ICFSecClusterObj* clusterObj = schema->getClusterTableObj()->getSystemCluster();
			tenantObj = readTenantByUNameIdx( clusterObj->getRequiredId(), S_System );
			if( tenantObj == NULL ) {
				tenantObj = readTenantByUNameIdx( clusterObj->getRequiredId(), S_System, true );
				if( tenantObj == NULL ) {
					tenantObj = newInstance();
					cfsec::ICFSecTenantEditObj* tenantEdit = tenantObj->beginEdit();
					tenantEdit->setRequiredContainerCluster( clusterObj );
					tenantEdit->setRequiredTenantName( S_System );
					tenantObj = tenantEdit->create();
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
		return( tenantObj );
	}


}
