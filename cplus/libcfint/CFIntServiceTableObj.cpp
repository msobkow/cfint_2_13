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

	const std::string CFIntServiceTableObj::CLASS_NAME( "CFIntServiceTableObj" );
	const std::string CFIntServiceTableObj::TABLE_NAME( "Service" );
	const std::string CFIntServiceTableObj::TABLE_DBNAME( "HostSvc" );

	CFIntServiceTableObj::CFIntServiceTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>();
		allService = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecServiceByClusterIdxKey,
			std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>();
		indexByHostIdx = new std::map< cfsec::CFSecServiceByHostIdxKey,
			std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>();
		indexByTypeIdx = new std::map< cfsec::CFSecServiceByTypeIdxKey,
			std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>();
		indexByUTypeIdx = new std::map< cfsec::CFSecServiceByUTypeIdxKey,
			cfsec::ICFSecServiceObj*>();
		indexByUHostPortIdx = new std::map< cfsec::CFSecServiceByUHostPortIdxKey,
			cfsec::ICFSecServiceObj*>();
	}

	CFIntServiceTableObj::CFIntServiceTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>();
		allService = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecServiceByClusterIdxKey,
			std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>();
		indexByHostIdx = new std::map< cfsec::CFSecServiceByHostIdxKey,
			std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>();
		indexByTypeIdx = new std::map< cfsec::CFSecServiceByTypeIdxKey,
			std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>();
		indexByUTypeIdx = new std::map< cfsec::CFSecServiceByUTypeIdxKey,
			cfsec::ICFSecServiceObj*>();
		indexByUHostPortIdx = new std::map< cfsec::CFSecServiceByUHostPortIdxKey,
			cfsec::ICFSecServiceObj*>();
	}

	CFIntServiceTableObj::~CFIntServiceTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
		}
		if( indexByHostIdx != NULL ) {
			delete indexByHostIdx;
			indexByHostIdx = NULL;
		}
		if( indexByTypeIdx != NULL ) {
			delete indexByTypeIdx;
			indexByTypeIdx = NULL;
		}
		if( indexByUTypeIdx != NULL ) {
			delete indexByUTypeIdx;
			indexByUTypeIdx = NULL;
		}
		if( indexByUHostPortIdx != NULL ) {
			delete indexByUHostPortIdx;
			indexByUHostPortIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecServiceObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntServiceTableObj::getSchema() {
		return( schema );
	}

	void CFIntServiceTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntServiceTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntServiceTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntServiceTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntServiceTableObj::minimizeMemory() {
		if( allService != NULL ) {
			allService->clear();
			delete allService;
			allService = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecServiceByClusterIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecServiceByClusterIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* curByClusterIdx = NULL;
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
		if( indexByHostIdx != NULL ) {
			std::map< cfsec::CFSecServiceByHostIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* >::iterator iterByHostIdx = indexByHostIdx->begin();
			std::map< cfsec::CFSecServiceByHostIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* >::iterator endByHostIdx = indexByHostIdx->end();
			std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* curByHostIdx = NULL;
			while( iterByHostIdx != endByHostIdx ) {
				curByHostIdx = iterByHostIdx->second;
				if( curByHostIdx != NULL ) {
					curByHostIdx->clear();
					delete curByHostIdx;
					curByHostIdx = NULL;
					iterByHostIdx->second = NULL;
				}
				iterByHostIdx ++;
			}
			indexByHostIdx->clear();
		}
		if( indexByTypeIdx != NULL ) {
			std::map< cfsec::CFSecServiceByTypeIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* >::iterator iterByTypeIdx = indexByTypeIdx->begin();
			std::map< cfsec::CFSecServiceByTypeIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* >::iterator endByTypeIdx = indexByTypeIdx->end();
			std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* curByTypeIdx = NULL;
			while( iterByTypeIdx != endByTypeIdx ) {
				curByTypeIdx = iterByTypeIdx->second;
				if( curByTypeIdx != NULL ) {
					curByTypeIdx->clear();
					delete curByTypeIdx;
					curByTypeIdx = NULL;
					iterByTypeIdx->second = NULL;
				}
				iterByTypeIdx ++;
			}
			indexByTypeIdx->clear();
		}
		if( indexByUTypeIdx != NULL ) {
			indexByUTypeIdx->clear();
		}
		if( indexByUHostPortIdx != NULL ) {
			indexByUHostPortIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecServiceObj* cur = NULL;
			cfsec::ICFSecServiceEditObj* edit = NULL;
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

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::newInstance() {
		cfsec::ICFSecServiceObj* inst = dynamic_cast<cfsec::ICFSecServiceObj*>( new CFIntServiceObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecServiceEditObj* CFIntServiceTableObj::newEditInstance( cfsec::ICFSecServiceObj* orig ) {
		cfsec::ICFSecServiceEditObj* edit = dynamic_cast<cfsec::ICFSecServiceEditObj*>( new CFIntServiceEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::realizeService( cfsec::ICFSecServiceObj* Obj ) {
		static const std::string S_ProcName( "realizeService" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecServiceObj* obj = Obj;
		cfsec::ICFSecServiceObj* existingObj = NULL;
		cfsec::CFSecServicePKey* pkey = obj->getPKey();
		cfsec::ICFSecServiceObj* keepObj = NULL;
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
				cfsec::CFSecServiceByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByHostIdx != NULL ) {
				cfsec::CFSecServiceByHostIdxKey keyHostIdx;
				keyHostIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyHostIdx.setRequiredHostNodeId( keepObj->getRequiredHostNodeId() );
				auto searchHostIdx = indexByHostIdx->find( keyHostIdx );
				if( searchHostIdx != indexByHostIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapHostIdx = searchHostIdx->second;
					if( mapHostIdx != NULL ) {
						auto removalProbe = mapHostIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapHostIdx->end() ) {
							mapHostIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByTypeIdx != NULL ) {
				cfsec::CFSecServiceByTypeIdxKey keyTypeIdx;
				keyTypeIdx.setRequiredServiceTypeId( keepObj->getRequiredServiceTypeId() );
				auto searchTypeIdx = indexByTypeIdx->find( keyTypeIdx );
				if( searchTypeIdx != indexByTypeIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapTypeIdx = searchTypeIdx->second;
					if( mapTypeIdx != NULL ) {
						auto removalProbe = mapTypeIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTypeIdx->end() ) {
							mapTypeIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUTypeIdx != NULL ) {
				cfsec::CFSecServiceByUTypeIdxKey keyUTypeIdx;
				keyUTypeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUTypeIdx.setRequiredHostNodeId( keepObj->getRequiredHostNodeId() );
				keyUTypeIdx.setRequiredServiceTypeId( keepObj->getRequiredServiceTypeId() );
				auto removalProbe = indexByUTypeIdx->find( keyUTypeIdx );
				if( removalProbe != indexByUTypeIdx->end() ) {
					indexByUTypeIdx->erase( removalProbe );
				}
			}

			if( indexByUHostPortIdx != NULL ) {
				cfsec::CFSecServiceByUHostPortIdxKey keyUHostPortIdx;
				keyUHostPortIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUHostPortIdx.setRequiredHostNodeId( keepObj->getRequiredHostNodeId() );
				keyUHostPortIdx.setRequiredHostPort( keepObj->getRequiredHostPort() );
				auto removalProbe = indexByUHostPortIdx->find( keyUHostPortIdx );
				if( removalProbe != indexByUHostPortIdx->end() ) {
					indexByUHostPortIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecServiceBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecServiceObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecServiceObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecServiceByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByHostIdx != NULL ) {
				static const std::string S_AHostIdxObj( "aHostIdxObj" );
				cfsec::ICFSecServiceObj* aHostIdxObj =
					dynamic_cast<cfsec::ICFSecServiceObj*>( keepObj );
				if( aHostIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AHostIdxObj );
				}
				cfsec::CFSecServiceByHostIdxKey keyHostIdx;
				keyHostIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyHostIdx.setRequiredHostNodeId( keepObj->getRequiredHostNodeId() );
				auto searchIndexByHostIdx = indexByHostIdx->find( keyHostIdx );
				if( searchIndexByHostIdx != indexByHostIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapHostIdx = searchIndexByHostIdx->second;
					if( mapHostIdx != NULL ) {
						mapHostIdx->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(keepObj->getPKey()), aHostIdxObj ) );
					}
				}
			}

			if( indexByTypeIdx != NULL ) {
				static const std::string S_ATypeIdxObj( "aTypeIdxObj" );
				cfsec::ICFSecServiceObj* aTypeIdxObj =
					dynamic_cast<cfsec::ICFSecServiceObj*>( keepObj );
				if( aTypeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATypeIdxObj );
				}
				cfsec::CFSecServiceByTypeIdxKey keyTypeIdx;
				keyTypeIdx.setRequiredServiceTypeId( keepObj->getRequiredServiceTypeId() );
				auto searchIndexByTypeIdx = indexByTypeIdx->find( keyTypeIdx );
				if( searchIndexByTypeIdx != indexByTypeIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapTypeIdx = searchIndexByTypeIdx->second;
					if( mapTypeIdx != NULL ) {
						mapTypeIdx->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(keepObj->getPKey()), aTypeIdxObj ) );
					}
				}
			}

			if( indexByUTypeIdx != NULL ) {
				static const std::string S_AUTypeIdxObj( "aUTypeIdxObj" );
				cfsec::ICFSecServiceObj* aUTypeIdxObj =
					dynamic_cast<cfsec::ICFSecServiceObj*>( keepObj );
				if( aUTypeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUTypeIdxObj );
				}
				cfsec::CFSecServiceByUTypeIdxKey keyUTypeIdx;
				keyUTypeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUTypeIdx.setRequiredHostNodeId( keepObj->getRequiredHostNodeId() );
				keyUTypeIdx.setRequiredServiceTypeId( keepObj->getRequiredServiceTypeId() );
				indexByUTypeIdx->insert( std::map< cfsec::CFSecServiceByUTypeIdxKey, cfsec::ICFSecServiceObj* >::value_type( keyUTypeIdx, aUTypeIdxObj ) );
			}

			if( indexByUHostPortIdx != NULL ) {
				static const std::string S_AUHostPortIdxObj( "aUHostPortIdxObj" );
				cfsec::ICFSecServiceObj* aUHostPortIdxObj =
					dynamic_cast<cfsec::ICFSecServiceObj*>( keepObj );
				if( aUHostPortIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUHostPortIdxObj );
				}
				cfsec::CFSecServiceByUHostPortIdxKey keyUHostPortIdx;
				keyUHostPortIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUHostPortIdx.setRequiredHostNodeId( keepObj->getRequiredHostNodeId() );
				keyUHostPortIdx.setRequiredHostPort( keepObj->getRequiredHostPort() );
				indexByUHostPortIdx->insert( std::map< cfsec::CFSecServiceByUHostPortIdxKey, cfsec::ICFSecServiceObj* >::value_type( keyUHostPortIdx, aUHostPortIdxObj ) );
			}

			if( allService != NULL ) {
				allService->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecServiceObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecServiceObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecServiceByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByHostIdx != NULL ) {
				static const std::string S_AHostIdxObj( "aHostIdxObj" );
				cfsec::ICFSecServiceObj* aHostIdxObj =
					dynamic_cast<cfsec::ICFSecServiceObj*>( keepObj );
				if( aHostIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AHostIdxObj );
				}
				cfsec::CFSecServiceByHostIdxKey keyHostIdx;
				keyHostIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyHostIdx.setRequiredHostNodeId( keepObj->getRequiredHostNodeId() );
				auto searchIndexByHostIdx = indexByHostIdx->find( keyHostIdx );
				if( searchIndexByHostIdx != indexByHostIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapHostIdx = searchIndexByHostIdx->second;
					if( mapHostIdx != NULL ) {
						mapHostIdx->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(keepObj->getPKey()), aHostIdxObj ) );
					}
				}
			}

			if( indexByTypeIdx != NULL ) {
				static const std::string S_ATypeIdxObj( "aTypeIdxObj" );
				cfsec::ICFSecServiceObj* aTypeIdxObj =
					dynamic_cast<cfsec::ICFSecServiceObj*>( keepObj );
				if( aTypeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATypeIdxObj );
				}
				cfsec::CFSecServiceByTypeIdxKey keyTypeIdx;
				keyTypeIdx.setRequiredServiceTypeId( keepObj->getRequiredServiceTypeId() );
				auto searchIndexByTypeIdx = indexByTypeIdx->find( keyTypeIdx );
				if( searchIndexByTypeIdx != indexByTypeIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapTypeIdx = searchIndexByTypeIdx->second;
					if( mapTypeIdx != NULL ) {
						mapTypeIdx->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(keepObj->getPKey()), aTypeIdxObj ) );
					}
				}
			}

			if( indexByUTypeIdx != NULL ) {
				static const std::string S_AUTypeIdxObj( "aUTypeIdxObj" );
				cfsec::ICFSecServiceObj* aUTypeIdxObj =
					dynamic_cast<cfsec::ICFSecServiceObj*>( keepObj );
				if( aUTypeIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUTypeIdxObj );
				}
				cfsec::CFSecServiceByUTypeIdxKey keyUTypeIdx;
				keyUTypeIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUTypeIdx.setRequiredHostNodeId( keepObj->getRequiredHostNodeId() );
				keyUTypeIdx.setRequiredServiceTypeId( keepObj->getRequiredServiceTypeId() );
				indexByUTypeIdx->insert( std::map< cfsec::CFSecServiceByUTypeIdxKey, cfsec::ICFSecServiceObj* >::value_type( keyUTypeIdx, aUTypeIdxObj ) );
			}

			if( indexByUHostPortIdx != NULL ) {
				static const std::string S_AUHostPortIdxObj( "aUHostPortIdxObj" );
				cfsec::ICFSecServiceObj* aUHostPortIdxObj =
					dynamic_cast<cfsec::ICFSecServiceObj*>( keepObj );
				if( aUHostPortIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUHostPortIdxObj );
				}
				cfsec::CFSecServiceByUHostPortIdxKey keyUHostPortIdx;
				keyUHostPortIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUHostPortIdx.setRequiredHostNodeId( keepObj->getRequiredHostNodeId() );
				keyUHostPortIdx.setRequiredHostPort( keepObj->getRequiredHostPort() );
				indexByUHostPortIdx->insert( std::map< cfsec::CFSecServiceByUHostPortIdxKey, cfsec::ICFSecServiceObj* >::value_type( keyUHostPortIdx, aUHostPortIdxObj ) );
			}

			if( allService != NULL ) {
				allService->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntServiceTableObj::deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecServiceObj*> list;
		cfsec::ICFSecServiceObj* existingObj = readCachedServiceByIdIdx( ClusterId,
				ServiceId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecServiceObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecServiceBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->reallyDeepDisposeService( dynamic_cast<cfsec::ICFSecServiceObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntServiceTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecServiceObj*> list;
		std::vector<cfsec::ICFSecServiceObj*> matchesFound = readCachedServiceByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecServiceObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecServiceBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->reallyDeepDisposeService( dynamic_cast<cfsec::ICFSecServiceObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntServiceTableObj::deepDisposeByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId ) {
		static const std::string S_ProcName( "deepDisposeByHostIdx" );
		std::vector<cfsec::ICFSecServiceObj*> list;
		std::vector<cfsec::ICFSecServiceObj*> matchesFound = readCachedServiceByHostIdx( ClusterId,
				HostNodeId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecServiceObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecServiceBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->reallyDeepDisposeService( dynamic_cast<cfsec::ICFSecServiceObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntServiceTableObj::deepDisposeByTypeIdx( const int32_t ServiceTypeId ) {
		static const std::string S_ProcName( "deepDisposeByTypeIdx" );
		std::vector<cfsec::ICFSecServiceObj*> list;
		std::vector<cfsec::ICFSecServiceObj*> matchesFound = readCachedServiceByTypeIdx( ServiceTypeId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecServiceObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecServiceBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->reallyDeepDisposeService( dynamic_cast<cfsec::ICFSecServiceObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntServiceTableObj::deepDisposeByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId ) {
		static const std::string S_ProcName( "deepDisposeByUTypeIdx" );
		std::vector<cfsec::ICFSecServiceObj*> list;
		cfsec::ICFSecServiceObj* existingObj = readCachedServiceByUTypeIdx( ClusterId,
				HostNodeId,
				ServiceTypeId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecServiceObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecServiceBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->reallyDeepDisposeService( dynamic_cast<cfsec::ICFSecServiceObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntServiceTableObj::deepDisposeByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort ) {
		static const std::string S_ProcName( "deepDisposeByUHostPortIdx" );
		std::vector<cfsec::ICFSecServiceObj*> list;
		cfsec::ICFSecServiceObj* existingObj = readCachedServiceByUHostPortIdx( ClusterId,
				HostNodeId,
				HostPort );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecServiceObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecServiceBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->reallyDeepDisposeService( dynamic_cast<cfsec::ICFSecServiceObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntServiceTableObj::reallyDeepDisposeService( cfsec::ICFSecServiceObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeService" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecServiceObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecServiceBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->reallyDetachFromIndexesService( dynamic_cast<cfsec::ICFSecServiceObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::createService( cfsec::ICFSecServiceEditObj* Obj ) {
		static const std::string S_ProcName( "createService" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecServiceObj* obj = dynamic_cast<cfsec::ICFSecServiceObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecServiceBuff* buff = dynamic_cast<cfsec::CFSecServiceBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->createService(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecServiceBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
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

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::readService( cfsec::CFSecServicePKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readService" );
		cfsec::ICFSecServiceObj* obj = NULL;
		cfsec::ICFSecServiceObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecServiceBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredClusterId(),
			pkey->getRequiredServiceId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
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

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::lockService( cfsec::CFSecServicePKey* pkey ) {
		static const std::string S_ProcName( "lockService" );
		cfsec::ICFSecServiceObj* locked = NULL;
		cfsec::CFSecServiceBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecServiceObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTableObj::readAllService( bool forceRead ) {
		static const std::string S_ProcName( "readAllService" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecServiceObj* realized = NULL;
		if( forceRead || ( allService == NULL ) ) {
			std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* map = new std::map<cfsec::CFSecServicePKey,cfsec::ICFSecServiceObj*>();
			allService = map;
			std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecServiceBuff* buff = NULL;
			cfsec::ICFSecServiceObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allService->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allService->size();
		std::vector<cfsec::ICFSecServiceObj*> arr;
		auto valIter = allService->begin();
		size_t idx = 0;
		while( valIter != allService->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTableObj::pageAllService(const int64_t* priorClusterId,
			const int64_t* priorServiceId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllService" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* map = NULL;
		cfsec::CFSecServiceBuff* buff = NULL;
		cfsec::ICFSecServiceObj* obj = NULL;
		cfsec::ICFSecServiceObj* realized = NULL;
		std::vector<cfsec::ICFSecServiceObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecServicePKey,cfsec::ICFSecServiceObj*>();
			std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->pageAllBuff( schema->getAuthorization(),
				priorClusterId,
				priorServiceId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
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

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::readServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId, bool forceRead )
	{
		static const std::string S_ProcName( "readServiceByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecServicePKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredServiceId( ServiceId );
		cfsec::ICFSecServiceObj* obj = readService( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTableObj::readServiceByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readServiceByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecServiceByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* dict;
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecServiceByClusterIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>();
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
			dict = new std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>();
			cfsec::ICFSecServiceObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecServiceBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecServiceObj* realized = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecServiceByClusterIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecServiceObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTableObj::readServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readServiceByHostIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecServiceByHostIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* dict;
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* oldDict;
		if( indexByHostIdx == NULL ) {
			indexByHostIdx = new std::map< cfsec::CFSecServiceByHostIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>();
		}
		auto searchIndexByHostIdx = indexByHostIdx->find( key );
		if( searchIndexByHostIdx != indexByHostIdx->end() ) {
			oldDict = searchIndexByHostIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>();
			cfsec::ICFSecServiceObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->readDerivedByHostIdx( schema->getAuthorization(),
				ClusterId,
				HostNodeId );
			cfsec::CFSecServiceBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecServiceObj* realized = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByHostIdx->erase( searchIndexByHostIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByHostIdx->insert( std::map< cfsec::CFSecServiceByHostIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecServiceObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTableObj::readServiceByTypeIdx( const int32_t ServiceTypeId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readServiceByTypeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecServiceByTypeIdxKey key;
		key.setRequiredServiceTypeId( ServiceTypeId );
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* dict;
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* oldDict;
		if( indexByTypeIdx == NULL ) {
			indexByTypeIdx = new std::map< cfsec::CFSecServiceByTypeIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>();
		}
		auto searchIndexByTypeIdx = indexByTypeIdx->find( key );
		if( searchIndexByTypeIdx != indexByTypeIdx->end() ) {
			oldDict = searchIndexByTypeIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>();
			cfsec::ICFSecServiceObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->readDerivedByTypeIdx( schema->getAuthorization(),
				ServiceTypeId );
			cfsec::CFSecServiceBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecServiceObj* realized = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTypeIdx->erase( searchIndexByTypeIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTypeIdx->insert( std::map< cfsec::CFSecServiceByTypeIdxKey,
				std::map< cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecServiceObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::readServiceByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId, bool forceRead )
	{
		static const std::string S_ProcName( "readServiceByUTypeIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUTypeIdx == NULL ) {
			indexByUTypeIdx = new std::map< cfsec::CFSecServiceByUTypeIdxKey,
				cfsec::ICFSecServiceObj*>();
		}
		cfsec::CFSecServiceByUTypeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredServiceTypeId( ServiceTypeId );
		cfsec::ICFSecServiceObj* obj = NULL;
		cfsec::ICFSecServiceObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUTypeIdx = indexByUTypeIdx->find( key );
			if( searchIndexByUTypeIdx != indexByUTypeIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUTypeIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecServiceBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->readDerivedByUTypeIdx( schema->getAuthorization(),
				ClusterId,
				HostNodeId,
				ServiceTypeId );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUTypeIdx->insert( std::map< cfsec::CFSecServiceByUTypeIdxKey, cfsec::ICFSecServiceObj*>::value_type( key, dynamic_cast<cfsec::ICFSecServiceObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::readServiceByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort, bool forceRead )
	{
		static const std::string S_ProcName( "readServiceByUHostPortIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUHostPortIdx == NULL ) {
			indexByUHostPortIdx = new std::map< cfsec::CFSecServiceByUHostPortIdxKey,
				cfsec::ICFSecServiceObj*>();
		}
		cfsec::CFSecServiceByUHostPortIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredHostPort( HostPort );
		cfsec::ICFSecServiceObj* obj = NULL;
		cfsec::ICFSecServiceObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUHostPortIdx = indexByUHostPortIdx->find( key );
			if( searchIndexByUHostPortIdx != indexByUHostPortIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUHostPortIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecServiceBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->readDerivedByUHostPortIdx( schema->getAuthorization(),
				ClusterId,
				HostNodeId,
				HostPort );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUHostPortIdx->insert( std::map< cfsec::CFSecServiceByUHostPortIdxKey, cfsec::ICFSecServiceObj*>::value_type( key, dynamic_cast<cfsec::ICFSecServiceObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::readCachedService( cfsec::CFSecServicePKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readService" );
		cfsec::ICFSecServiceObj* obj = NULL;
		cfsec::ICFSecServiceObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::readCachedServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId )
	{
		static const std::string S_ProcName( "readCachedServiceByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecServicePKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredServiceId( ServiceId );
		cfsec::ICFSecServiceObj* obj = readCachedService( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTableObj::readCachedServiceByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedServiceByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecServiceObj*> arr;
		cfsec::CFSecServiceByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecServiceObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecServiceObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecServiceBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTableObj::readCachedServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId )
	{
		static const std::string S_ProcName( "readCachedServiceByHostIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecServiceObj*> arr;
		cfsec::CFSecServiceByHostIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* dict;
		if( indexByHostIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByHostIdx = indexByHostIdx->find( key );
		if( searchIndexByHostIdx != indexByHostIdx->end() ) {
			dict = searchIndexByHostIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecServiceObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecServiceObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecServiceBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTableObj::readCachedServiceByTypeIdx( const int32_t ServiceTypeId )
	{
		static const std::string S_ProcName( "readCachedServiceByTypeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecServiceObj*> arr;
		cfsec::CFSecServiceByTypeIdxKey key;
		key.setRequiredServiceTypeId( ServiceTypeId );
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* dict;
		if( indexByTypeIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTypeIdx = indexByTypeIdx->find( key );
		if( searchIndexByTypeIdx != indexByTypeIdx->end() ) {
			dict = searchIndexByTypeIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecServiceObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecServiceObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecServiceBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::readCachedServiceByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId )
	{
		static const std::string S_ProcName( "readCachedServiceByUTypeIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUTypeIdx == NULL ) {
			indexByUTypeIdx = new std::map< cfsec::CFSecServiceByUTypeIdxKey,
				cfsec::ICFSecServiceObj*>();
		}
		cfsec::CFSecServiceByUTypeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredServiceTypeId( ServiceTypeId );
		cfsec::ICFSecServiceObj* obj = NULL;
		auto searchIndexByUTypeIdx = indexByUTypeIdx->find( key );
		if( searchIndexByUTypeIdx != indexByUTypeIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUTypeIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecServiceBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::readCachedServiceByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort )
	{
		static const std::string S_ProcName( "readCachedServiceByUHostPortIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUHostPortIdx == NULL ) {
			indexByUHostPortIdx = new std::map< cfsec::CFSecServiceByUHostPortIdxKey,
				cfsec::ICFSecServiceObj*>();
		}
		cfsec::CFSecServiceByUHostPortIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredHostPort( HostPort );
		cfsec::ICFSecServiceObj* obj = NULL;
		auto searchIndexByUHostPortIdx = indexByUHostPortIdx->find( key );
		if( searchIndexByUHostPortIdx != indexByUHostPortIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUHostPortIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecServiceBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTableObj::pageServiceByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId )
	{
		static const std::string S_ProcName( "pageServiceByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecServiceByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		cfsec::ICFSecServiceObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->pageBuffByClusterIdx( schema->getAuthorization(),
				ClusterId,
				priorClusterId,
				priorServiceId );
		std::vector<cfsec::ICFSecServiceObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecServiceBuff* buff;
		cfsec::ICFSecServiceObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTableObj::pageServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId )
	{
		static const std::string S_ProcName( "pageServiceByHostIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecServiceByHostIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		cfsec::ICFSecServiceObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->pageBuffByHostIdx( schema->getAuthorization(),
				ClusterId,
				HostNodeId,
				priorClusterId,
				priorServiceId );
		std::vector<cfsec::ICFSecServiceObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecServiceBuff* buff;
		cfsec::ICFSecServiceObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecServiceObj*> CFIntServiceTableObj::pageServiceByTypeIdx( const int32_t ServiceTypeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId )
	{
		static const std::string S_ProcName( "pageServiceByTypeIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecServiceByTypeIdxKey key;
		key.setRequiredServiceTypeId( ServiceTypeId );
		cfsec::ICFSecServiceObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->pageBuffByTypeIdx( schema->getAuthorization(),
				ServiceTypeId,
				priorClusterId,
				priorServiceId );
		std::vector<cfsec::ICFSecServiceObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecServiceBuff* buff;
		cfsec::ICFSecServiceObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
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

	cfsec::ICFSecServiceObj* CFIntServiceTableObj::updateService( cfsec::ICFSecServiceEditObj* Obj ) {
		static const std::string S_ProcName( "updateService" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecServiceObj* obj = dynamic_cast<cfsec::ICFSecServiceObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecServiceBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->updateService( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecServiceBuff*>( Obj->getServiceBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecServiceObj*>( dynamic_cast<cfint::CFIntServiceTableObj*>( schema->getServiceTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecServiceObj*>( obj->realize() );
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

	void CFIntServiceTableObj::deleteService( cfsec::ICFSecServiceEditObj* Obj ) {
		cfsec::ICFSecServiceObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->deleteService( schema->getAuthorization(),
			obj->getServiceBuff() );
		deepDisposeByIdIdx( obj->getRequiredClusterId(),
			obj->getRequiredServiceId() );
	}

	void CFIntServiceTableObj::deleteServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId )
	{
		cfsec::CFSecServicePKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredServiceId( ServiceId );
		cfsec::ICFSecServiceObj* obj = readService( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecServiceEditObj* editObj = dynamic_cast<cfsec::ICFSecServiceEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecServiceEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntServiceTableObj::deleteServiceByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableService()->deleteServiceByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFIntServiceTableObj::deleteServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableService()->deleteServiceByHostIdx( schema->getAuthorization(),
				ClusterId,
				HostNodeId );
		deepDisposeByHostIdx( ClusterId,
			HostNodeId );
	}

	void CFIntServiceTableObj::deleteServiceByTypeIdx( const int32_t ServiceTypeId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableService()->deleteServiceByTypeIdx( schema->getAuthorization(),
				ServiceTypeId );
		deepDisposeByTypeIdx( ServiceTypeId );
	}

	void CFIntServiceTableObj::deleteServiceByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId )
	{
		if( indexByUTypeIdx == NULL ) {
			indexByUTypeIdx = new std::map< cfsec::CFSecServiceByUTypeIdxKey,
				cfsec::ICFSecServiceObj*>();
		}
		cfsec::CFSecServiceByUTypeIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredServiceTypeId( ServiceTypeId );
		cfsec::ICFSecServiceObj* obj = NULL;
		auto searchIndexByUTypeIdx = indexByUTypeIdx->find( key );
		if( searchIndexByUTypeIdx != indexByUTypeIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->deleteServiceByUTypeIdx( schema->getAuthorization(),
				ClusterId,
				HostNodeId,
				ServiceTypeId );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->deleteServiceByUTypeIdx( schema->getAuthorization(),
				ClusterId,
				HostNodeId,
				ServiceTypeId );
		}
		deepDisposeByUTypeIdx( ClusterId,
			HostNodeId,
			ServiceTypeId );
	}

	void CFIntServiceTableObj::deleteServiceByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort )
	{
		if( indexByUHostPortIdx == NULL ) {
			indexByUHostPortIdx = new std::map< cfsec::CFSecServiceByUHostPortIdxKey,
				cfsec::ICFSecServiceObj*>();
		}
		cfsec::CFSecServiceByUHostPortIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredHostNodeId( HostNodeId );
		key.setRequiredHostPort( HostPort );
		cfsec::ICFSecServiceObj* obj = NULL;
		auto searchIndexByUHostPortIdx = indexByUHostPortIdx->find( key );
		if( searchIndexByUHostPortIdx != indexByUHostPortIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->deleteServiceByUHostPortIdx( schema->getAuthorization(),
				ClusterId,
				HostNodeId,
				HostPort );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableService()->deleteServiceByUHostPortIdx( schema->getAuthorization(),
				ClusterId,
				HostNodeId,
				HostPort );
		}
		deepDisposeByUHostPortIdx( ClusterId,
			HostNodeId,
			HostPort );
	}

	void CFIntServiceTableObj::reallyDetachFromIndexesService( cfsec::ICFSecServiceObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesService" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecServiceObj* obj = Obj;
		cfsec::CFSecServicePKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecServiceObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecServiceByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapClusterIdx = searchClusterIdx->second;
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

			if( indexByHostIdx != NULL ) {
				cfsec::CFSecServiceByHostIdxKey keyHostIdx;
				keyHostIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyHostIdx.setRequiredHostNodeId( obj->getRequiredHostNodeId() );
				auto searchHostIdx = indexByHostIdx->find( keyHostIdx );
				if( searchHostIdx != indexByHostIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapHostIdx = searchHostIdx->second;
					if( mapHostIdx != NULL ) {
						auto removalProbe = mapHostIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapHostIdx->end() ) {
							mapHostIdx->erase( removalProbe );
							if( mapHostIdx->empty() ) {
								delete mapHostIdx;
								mapHostIdx = NULL;
								indexByHostIdx->erase( searchHostIdx );
							}
						}
					}
				}
			}

			if( indexByTypeIdx != NULL ) {
				cfsec::CFSecServiceByTypeIdxKey keyTypeIdx;
				keyTypeIdx.setRequiredServiceTypeId( obj->getRequiredServiceTypeId() );
				auto searchTypeIdx = indexByTypeIdx->find( keyTypeIdx );
				if( searchTypeIdx != indexByTypeIdx->end() ) {
					std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* mapTypeIdx = searchTypeIdx->second;
					if( mapTypeIdx != NULL ) {
						auto removalProbe = mapTypeIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapTypeIdx->end() ) {
							mapTypeIdx->erase( removalProbe );
							if( mapTypeIdx->empty() ) {
								delete mapTypeIdx;
								mapTypeIdx = NULL;
								indexByTypeIdx->erase( searchTypeIdx );
							}
						}
					}
				}
			}

			if( indexByUTypeIdx != NULL ) {
				cfsec::CFSecServiceByUTypeIdxKey keyUTypeIdx;
				keyUTypeIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyUTypeIdx.setRequiredHostNodeId( obj->getRequiredHostNodeId() );
				keyUTypeIdx.setRequiredServiceTypeId( obj->getRequiredServiceTypeId() );
				auto removalProbe = indexByUTypeIdx->find( keyUTypeIdx );
				if( removalProbe != indexByUTypeIdx->end() ) {
					indexByUTypeIdx->erase( removalProbe );
				}
			}

			if( indexByUHostPortIdx != NULL ) {
				cfsec::CFSecServiceByUHostPortIdxKey keyUHostPortIdx;
				keyUHostPortIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyUHostPortIdx.setRequiredHostNodeId( obj->getRequiredHostNodeId() );
				keyUHostPortIdx.setRequiredHostPort( obj->getRequiredHostPort() );
				auto removalProbe = indexByUHostPortIdx->find( keyUHostPortIdx );
				if( removalProbe != indexByUHostPortIdx->end() ) {
					indexByUHostPortIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
