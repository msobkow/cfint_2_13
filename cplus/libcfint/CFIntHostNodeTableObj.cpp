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

	const std::string CFIntHostNodeTableObj::CLASS_NAME( "CFIntHostNodeTableObj" );
	const std::string CFIntHostNodeTableObj::TABLE_NAME( "HostNode" );
	const std::string CFIntHostNodeTableObj::TABLE_DBNAME( "HostNode" );

	CFIntHostNodeTableObj::CFIntHostNodeTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>();
		allHostNode = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecHostNodeByClusterIdxKey,
			std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>*>();
		indexByUDescrIdx = new std::map< cfsec::CFSecHostNodeByUDescrIdxKey,
			cfsec::ICFSecHostNodeObj*>();
		indexByHostNameIdx = new std::map< cfsec::CFSecHostNodeByHostNameIdxKey,
			cfsec::ICFSecHostNodeObj*>();
	}

	CFIntHostNodeTableObj::CFIntHostNodeTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>();
		allHostNode = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecHostNodeByClusterIdxKey,
			std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>*>();
		indexByUDescrIdx = new std::map< cfsec::CFSecHostNodeByUDescrIdxKey,
			cfsec::ICFSecHostNodeObj*>();
		indexByHostNameIdx = new std::map< cfsec::CFSecHostNodeByHostNameIdxKey,
			cfsec::ICFSecHostNodeObj*>();
	}

	CFIntHostNodeTableObj::~CFIntHostNodeTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
		}
		if( indexByUDescrIdx != NULL ) {
			delete indexByUDescrIdx;
			indexByUDescrIdx = NULL;
		}
		if( indexByHostNameIdx != NULL ) {
			delete indexByHostNameIdx;
			indexByHostNameIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecHostNodeObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntHostNodeTableObj::getSchema() {
		return( schema );
	}

	void CFIntHostNodeTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntHostNodeTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntHostNodeTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntHostNodeTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntHostNodeTableObj::minimizeMemory() {
		if( allHostNode != NULL ) {
			allHostNode->clear();
			delete allHostNode;
			allHostNode = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecHostNodeByClusterIdxKey,
				std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecHostNodeByClusterIdxKey,
				std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* curByClusterIdx = NULL;
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
		if( indexByUDescrIdx != NULL ) {
			indexByUDescrIdx->clear();
		}
		if( indexByHostNameIdx != NULL ) {
			indexByHostNameIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecHostNodeObj* cur = NULL;
			cfsec::ICFSecHostNodeEditObj* edit = NULL;
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

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::newInstance() {
		cfsec::ICFSecHostNodeObj* inst = dynamic_cast<cfsec::ICFSecHostNodeObj*>( new CFIntHostNodeObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecHostNodeEditObj* CFIntHostNodeTableObj::newEditInstance( cfsec::ICFSecHostNodeObj* orig ) {
		cfsec::ICFSecHostNodeEditObj* edit = dynamic_cast<cfsec::ICFSecHostNodeEditObj*>( new CFIntHostNodeEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::realizeHostNode( cfsec::ICFSecHostNodeObj* Obj ) {
		static const std::string S_ProcName( "realizeHostNode" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecHostNodeObj* obj = Obj;
		cfsec::ICFSecHostNodeObj* existingObj = NULL;
		cfsec::CFSecHostNodePKey* pkey = obj->getPKey();
		cfsec::ICFSecHostNodeObj* keepObj = NULL;
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
				cfsec::CFSecHostNodeByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUDescrIdx != NULL ) {
				cfsec::CFSecHostNodeByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				auto removalProbe = indexByUDescrIdx->find( keyUDescrIdx );
				if( removalProbe != indexByUDescrIdx->end() ) {
					indexByUDescrIdx->erase( removalProbe );
				}
			}

			if( indexByHostNameIdx != NULL ) {
				cfsec::CFSecHostNodeByHostNameIdxKey keyHostNameIdx;
				keyHostNameIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyHostNameIdx.setRequiredHostName( keepObj->getRequiredHostName() );
				auto removalProbe = indexByHostNameIdx->find( keyHostNameIdx );
				if( removalProbe != indexByHostNameIdx->end() ) {
					indexByHostNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecHostNodeBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecHostNodeObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecHostNodeObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecHostNodeByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByUDescrIdx != NULL ) {
				static const std::string S_AUDescrIdxObj( "aUDescrIdxObj" );
				cfsec::ICFSecHostNodeObj* aUDescrIdxObj =
					dynamic_cast<cfsec::ICFSecHostNodeObj*>( keepObj );
				if( aUDescrIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDescrIdxObj );
				}
				cfsec::CFSecHostNodeByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				indexByUDescrIdx->insert( std::map< cfsec::CFSecHostNodeByUDescrIdxKey, cfsec::ICFSecHostNodeObj* >::value_type( keyUDescrIdx, aUDescrIdxObj ) );
			}

			if( indexByHostNameIdx != NULL ) {
				static const std::string S_AHostNameIdxObj( "aHostNameIdxObj" );
				cfsec::ICFSecHostNodeObj* aHostNameIdxObj =
					dynamic_cast<cfsec::ICFSecHostNodeObj*>( keepObj );
				if( aHostNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AHostNameIdxObj );
				}
				cfsec::CFSecHostNodeByHostNameIdxKey keyHostNameIdx;
				keyHostNameIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyHostNameIdx.setRequiredHostName( keepObj->getRequiredHostName() );
				indexByHostNameIdx->insert( std::map< cfsec::CFSecHostNodeByHostNameIdxKey, cfsec::ICFSecHostNodeObj* >::value_type( keyHostNameIdx, aHostNameIdxObj ) );
			}

			if( allHostNode != NULL ) {
				allHostNode->insert( std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecHostNodeObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecHostNodeObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecHostNodeByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByUDescrIdx != NULL ) {
				static const std::string S_AUDescrIdxObj( "aUDescrIdxObj" );
				cfsec::ICFSecHostNodeObj* aUDescrIdxObj =
					dynamic_cast<cfsec::ICFSecHostNodeObj*>( keepObj );
				if( aUDescrIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUDescrIdxObj );
				}
				cfsec::CFSecHostNodeByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUDescrIdx.setRequiredDescription( keepObj->getRequiredDescription() );
				indexByUDescrIdx->insert( std::map< cfsec::CFSecHostNodeByUDescrIdxKey, cfsec::ICFSecHostNodeObj* >::value_type( keyUDescrIdx, aUDescrIdxObj ) );
			}

			if( indexByHostNameIdx != NULL ) {
				static const std::string S_AHostNameIdxObj( "aHostNameIdxObj" );
				cfsec::ICFSecHostNodeObj* aHostNameIdxObj =
					dynamic_cast<cfsec::ICFSecHostNodeObj*>( keepObj );
				if( aHostNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AHostNameIdxObj );
				}
				cfsec::CFSecHostNodeByHostNameIdxKey keyHostNameIdx;
				keyHostNameIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyHostNameIdx.setRequiredHostName( keepObj->getRequiredHostName() );
				indexByHostNameIdx->insert( std::map< cfsec::CFSecHostNodeByHostNameIdxKey, cfsec::ICFSecHostNodeObj* >::value_type( keyHostNameIdx, aHostNameIdxObj ) );
			}

			if( allHostNode != NULL ) {
				allHostNode->insert( std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntHostNodeTableObj::deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t HostNodeId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecHostNodeObj*> list;
		cfsec::ICFSecHostNodeObj* existingObj = readCachedHostNodeByIdIdx( ClusterId,
				HostNodeId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecHostNodeObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->reallyDeepDisposeHostNode( dynamic_cast<cfsec::ICFSecHostNodeObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntHostNodeTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecHostNodeObj*> list;
		std::vector<cfsec::ICFSecHostNodeObj*> matchesFound = readCachedHostNodeByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecHostNodeObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->reallyDeepDisposeHostNode( dynamic_cast<cfsec::ICFSecHostNodeObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntHostNodeTableObj::deepDisposeByUDescrIdx( const int64_t ClusterId,
			const std::string& Description ) {
		static const std::string S_ProcName( "deepDisposeByUDescrIdx" );
		std::vector<cfsec::ICFSecHostNodeObj*> list;
		cfsec::ICFSecHostNodeObj* existingObj = readCachedHostNodeByUDescrIdx( ClusterId,
				Description );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecHostNodeObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->reallyDeepDisposeHostNode( dynamic_cast<cfsec::ICFSecHostNodeObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntHostNodeTableObj::deepDisposeByHostNameIdx( const int64_t ClusterId,
			const std::string& HostName ) {
		static const std::string S_ProcName( "deepDisposeByHostNameIdx" );
		std::vector<cfsec::ICFSecHostNodeObj*> list;
		cfsec::ICFSecHostNodeObj* existingObj = readCachedHostNodeByHostNameIdx( ClusterId,
				HostName );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecHostNodeObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->reallyDeepDisposeHostNode( dynamic_cast<cfsec::ICFSecHostNodeObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntHostNodeTableObj::reallyDeepDisposeHostNode( cfsec::ICFSecHostNodeObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeHostNode" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecHostNodeObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->deepDisposeByHostIdx( obj->getRequiredClusterId(),
			obj->getRequiredHostNodeId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecHostNodeBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->reallyDetachFromIndexesHostNode( dynamic_cast<cfsec::ICFSecHostNodeObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::createHostNode( cfsec::ICFSecHostNodeEditObj* Obj ) {
		static const std::string S_ProcName( "createHostNode" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecHostNodeObj* obj = dynamic_cast<cfsec::ICFSecHostNodeObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecHostNodeBuff* buff = dynamic_cast<cfsec::CFSecHostNodeBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->createHostNode(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecHostNodeBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecHostNodeObj*>( obj->realize() );
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

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::readHostNode( cfsec::CFSecHostNodePKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readHostNode" );
		cfsec::ICFSecHostNodeObj* obj = NULL;
		cfsec::ICFSecHostNodeObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecHostNodeBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredClusterId(),
			pkey->getRequiredHostNodeId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecHostNodeObj*>( obj->realize() );
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

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::lockHostNode( cfsec::CFSecHostNodePKey* pkey ) {
		static const std::string S_ProcName( "lockHostNode" );
		cfsec::ICFSecHostNodeObj* locked = NULL;
		cfsec::CFSecHostNodeBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecHostNodeObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecHostNodeObj*> CFIntHostNodeTableObj::readAllHostNode( bool forceRead ) {
		static const std::string S_ProcName( "readAllHostNode" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecHostNodeObj* realized = NULL;
		if( forceRead || ( allHostNode == NULL ) ) {
			std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* map = new std::map<cfsec::CFSecHostNodePKey,cfsec::ICFSecHostNodeObj*>();
			allHostNode = map;
			std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecHostNodeBuff* buff = NULL;
			cfsec::ICFSecHostNodeObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecHostNodeObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allHostNode->insert( std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allHostNode->size();
		std::vector<cfsec::ICFSecHostNodeObj*> arr;
		auto valIter = allHostNode->begin();
		size_t idx = 0;
		while( valIter != allHostNode->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecHostNodeObj*> CFIntHostNodeTableObj::pageAllHostNode(const int64_t* priorClusterId,
			const int64_t* priorHostNodeId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllHostNode" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* map = NULL;
		cfsec::CFSecHostNodeBuff* buff = NULL;
		cfsec::ICFSecHostNodeObj* obj = NULL;
		cfsec::ICFSecHostNodeObj* realized = NULL;
		std::vector<cfsec::ICFSecHostNodeObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecHostNodePKey,cfsec::ICFSecHostNodeObj*>();
			std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->pageAllBuff( schema->getAuthorization(),
				priorClusterId,
				priorHostNodeId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecHostNodeObj*>( obj->realize() );
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

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::readHostNodeByIdIdx( const int64_t ClusterId,
			const int64_t HostNodeId, bool forceRead )
	{
		static const std::string S_ProcName( "readHostNodeByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecHostNodePKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredHostNodeId( HostNodeId );
		cfsec::ICFSecHostNodeObj* obj = readHostNode( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecHostNodeObj*> CFIntHostNodeTableObj::readHostNodeByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readHostNodeByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecHostNodeByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* dict;
		std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecHostNodeByClusterIdxKey,
				std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>*>();
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
			dict = new std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>();
			cfsec::ICFSecHostNodeObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecHostNodeBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecHostNodeObj* realized = dynamic_cast<cfsec::ICFSecHostNodeObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecHostNodeByClusterIdxKey,
				std::map< cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecHostNodeObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::readHostNodeByUDescrIdx( const int64_t ClusterId,
			const std::string& Description, bool forceRead )
	{
		static const std::string S_ProcName( "readHostNodeByUDescrIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecHostNodeByUDescrIdxKey,
				cfsec::ICFSecHostNodeObj*>();
		}
		cfsec::CFSecHostNodeByUDescrIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredDescription( Description );
		cfsec::ICFSecHostNodeObj* obj = NULL;
		cfsec::ICFSecHostNodeObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
			if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUDescrIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecHostNodeBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->readDerivedByUDescrIdx( schema->getAuthorization(),
				ClusterId,
				Description );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecHostNodeObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUDescrIdx->insert( std::map< cfsec::CFSecHostNodeByUDescrIdxKey, cfsec::ICFSecHostNodeObj*>::value_type( key, dynamic_cast<cfsec::ICFSecHostNodeObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::readHostNodeByHostNameIdx( const int64_t ClusterId,
			const std::string& HostName, bool forceRead )
	{
		static const std::string S_ProcName( "readHostNodeByHostNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByHostNameIdx == NULL ) {
			indexByHostNameIdx = new std::map< cfsec::CFSecHostNodeByHostNameIdxKey,
				cfsec::ICFSecHostNodeObj*>();
		}
		cfsec::CFSecHostNodeByHostNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostName( HostName );
		cfsec::ICFSecHostNodeObj* obj = NULL;
		cfsec::ICFSecHostNodeObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByHostNameIdx = indexByHostNameIdx->find( key );
			if( searchIndexByHostNameIdx != indexByHostNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByHostNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecHostNodeBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->readDerivedByHostNameIdx( schema->getAuthorization(),
				ClusterId,
				HostName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecHostNodeObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByHostNameIdx->insert( std::map< cfsec::CFSecHostNodeByHostNameIdxKey, cfsec::ICFSecHostNodeObj*>::value_type( key, dynamic_cast<cfsec::ICFSecHostNodeObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::readHostNodeByLookupHostNameIdx( const int64_t ClusterId,
			const std::string& HostName, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readHostNodeByLookupHostNameIdx" );
		if( indexByHostNameIdx == NULL ) {
			indexByHostNameIdx = new std::map< cfsec::CFSecHostNodeByHostNameIdxKey,
				cfsec::ICFSecHostNodeObj*>();
		}
		cfsec::CFSecHostNodeByHostNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostName( HostName );
		cfsec::ICFSecHostNodeObj* obj = NULL;
		cfsec::ICFSecHostNodeObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByHostNameIdx = indexByHostNameIdx->find( key );
			if( searchIndexByHostNameIdx != indexByHostNameIdx->end() ) {
				obj = searchIndexByHostNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecHostNodeBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->readDerivedByLookupHostNameIdx( schema->getAuthorization(),
				ClusterId,
				HostName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecHostNodeObj*>( dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecHostNodeObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByHostNameIdx->insert( std::map< cfsec::CFSecHostNodeByHostNameIdxKey, cfsec::ICFSecHostNodeObj*>::value_type( key, dynamic_cast<cfsec::ICFSecHostNodeObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::readCachedHostNode( cfsec::CFSecHostNodePKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readHostNode" );
		cfsec::ICFSecHostNodeObj* obj = NULL;
		cfsec::ICFSecHostNodeObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::readCachedHostNodeByIdIdx( const int64_t ClusterId,
			const int64_t HostNodeId )
	{
		static const std::string S_ProcName( "readCachedHostNodeByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecHostNodePKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredHostNodeId( HostNodeId );
		cfsec::ICFSecHostNodeObj* obj = readCachedHostNode( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecHostNodeObj*> CFIntHostNodeTableObj::readCachedHostNodeByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedHostNodeByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecHostNodeObj*> arr;
		cfsec::CFSecHostNodeByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecHostNodeObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecHostNodeObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecHostNodeBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::readCachedHostNodeByUDescrIdx( const int64_t ClusterId,
			const std::string& Description )
	{
		static const std::string S_ProcName( "readCachedHostNodeByUDescrIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecHostNodeByUDescrIdxKey,
				cfsec::ICFSecHostNodeObj*>();
		}
		cfsec::CFSecHostNodeByUDescrIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredDescription( Description );
		cfsec::ICFSecHostNodeObj* obj = NULL;
		auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
		if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUDescrIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecHostNodeBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::readCachedHostNodeByHostNameIdx( const int64_t ClusterId,
			const std::string& HostName )
	{
		static const std::string S_ProcName( "readCachedHostNodeByHostNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByHostNameIdx == NULL ) {
			indexByHostNameIdx = new std::map< cfsec::CFSecHostNodeByHostNameIdxKey,
				cfsec::ICFSecHostNodeObj*>();
		}
		cfsec::CFSecHostNodeByHostNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostName( HostName );
		cfsec::ICFSecHostNodeObj* obj = NULL;
		auto searchIndexByHostNameIdx = indexByHostNameIdx->find( key );
		if( searchIndexByHostNameIdx != indexByHostNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByHostNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecHostNodeBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::readCachedHostNodeByLookupHostNameIdx( const int64_t ClusterId,
			const std::string& HostName )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedHostNodeByLookupHostNameIdx" );
		if( indexByHostNameIdx == NULL ) {
			indexByHostNameIdx = new std::map< cfsec::CFSecHostNodeByHostNameIdxKey,
				cfsec::ICFSecHostNodeObj*>();
		}
		cfsec::CFSecHostNodeByHostNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostName( HostName );
		cfsec::ICFSecHostNodeObj* obj = NULL;
		cfsec::ICFSecHostNodeObj* realized = NULL;
		auto searchIndexByHostNameIdx = indexByHostNameIdx->find( key );
		if( searchIndexByHostNameIdx != indexByHostNameIdx->end() ) {
			obj = searchIndexByHostNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecHostNodeBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecHostNodeObj*> CFIntHostNodeTableObj::pageHostNodeByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorHostNodeId )
	{
		static const std::string S_ProcName( "pageHostNodeByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecHostNodeByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		cfsec::ICFSecHostNodeObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecHostNodeBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->pageBuffByClusterIdx( schema->getAuthorization(),
				ClusterId,
				priorClusterId,
				priorHostNodeId );
		std::vector<cfsec::ICFSecHostNodeObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecHostNodeBuff* buff;
		cfsec::ICFSecHostNodeObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecHostNodeObj*>( obj->realize() );
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

	cfsec::ICFSecHostNodeObj* CFIntHostNodeTableObj::updateHostNode( cfsec::ICFSecHostNodeEditObj* Obj ) {
		static const std::string S_ProcName( "updateHostNode" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecHostNodeObj* obj = dynamic_cast<cfsec::ICFSecHostNodeObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecHostNodeBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->updateHostNode( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecHostNodeBuff*>( Obj->getHostNodeBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecHostNodeObj*>( dynamic_cast<cfint::CFIntHostNodeTableObj*>( schema->getHostNodeTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecHostNodeObj*>( obj->realize() );
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

	void CFIntHostNodeTableObj::deleteHostNode( cfsec::ICFSecHostNodeEditObj* Obj ) {
		cfsec::ICFSecHostNodeObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->deleteHostNode( schema->getAuthorization(),
			obj->getHostNodeBuff() );
		deepDisposeByIdIdx( obj->getRequiredClusterId(),
			obj->getRequiredHostNodeId() );
	}

	void CFIntHostNodeTableObj::deleteHostNodeByIdIdx( const int64_t ClusterId,
			const int64_t HostNodeId )
	{
		cfsec::CFSecHostNodePKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredHostNodeId( HostNodeId );
		cfsec::ICFSecHostNodeObj* obj = readHostNode( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecHostNodeEditObj* editObj = dynamic_cast<cfsec::ICFSecHostNodeEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecHostNodeEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntHostNodeTableObj::deleteHostNodeByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableHostNode()->deleteHostNodeByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFIntHostNodeTableObj::deleteHostNodeByUDescrIdx( const int64_t ClusterId,
			const std::string& Description )
	{
		if( indexByUDescrIdx == NULL ) {
			indexByUDescrIdx = new std::map< cfsec::CFSecHostNodeByUDescrIdxKey,
				cfsec::ICFSecHostNodeObj*>();
		}
		cfsec::CFSecHostNodeByUDescrIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredDescription( Description );
		cfsec::ICFSecHostNodeObj* obj = NULL;
		auto searchIndexByUDescrIdx = indexByUDescrIdx->find( key );
		if( searchIndexByUDescrIdx != indexByUDescrIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->deleteHostNodeByUDescrIdx( schema->getAuthorization(),
				ClusterId,
				Description );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->deleteHostNodeByUDescrIdx( schema->getAuthorization(),
				ClusterId,
				Description );
		}
		deepDisposeByUDescrIdx( ClusterId,
			Description );
	}

	void CFIntHostNodeTableObj::deleteHostNodeByHostNameIdx( const int64_t ClusterId,
			const std::string& HostName )
	{
		if( indexByHostNameIdx == NULL ) {
			indexByHostNameIdx = new std::map< cfsec::CFSecHostNodeByHostNameIdxKey,
				cfsec::ICFSecHostNodeObj*>();
		}
		cfsec::CFSecHostNodeByHostNameIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostName( HostName );
		cfsec::ICFSecHostNodeObj* obj = NULL;
		auto searchIndexByHostNameIdx = indexByHostNameIdx->find( key );
		if( searchIndexByHostNameIdx != indexByHostNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->deleteHostNodeByHostNameIdx( schema->getAuthorization(),
				ClusterId,
				HostName );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableHostNode()->deleteHostNodeByHostNameIdx( schema->getAuthorization(),
				ClusterId,
				HostName );
		}
		deepDisposeByHostNameIdx( ClusterId,
			HostName );
	}

	void CFIntHostNodeTableObj::reallyDetachFromIndexesHostNode( cfsec::ICFSecHostNodeObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesHostNode" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecHostNodeObj* obj = Obj;
		cfsec::CFSecHostNodePKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecHostNodeObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecHostNodeByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecHostNodePKey, cfsec::ICFSecHostNodeObj*>* mapClusterIdx = searchClusterIdx->second;
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

			if( indexByUDescrIdx != NULL ) {
				cfsec::CFSecHostNodeByUDescrIdxKey keyUDescrIdx;
				keyUDescrIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyUDescrIdx.setRequiredDescription( obj->getRequiredDescription() );
				auto removalProbe = indexByUDescrIdx->find( keyUDescrIdx );
				if( removalProbe != indexByUDescrIdx->end() ) {
					indexByUDescrIdx->erase( removalProbe );
				}
			}

			if( indexByHostNameIdx != NULL ) {
				cfsec::CFSecHostNodeByHostNameIdxKey keyHostNameIdx;
				keyHostNameIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyHostNameIdx.setRequiredHostName( obj->getRequiredHostName() );
				auto removalProbe = indexByHostNameIdx->find( keyHostNameIdx );
				if( removalProbe != indexByHostNameIdx->end() ) {
					indexByHostNameIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
