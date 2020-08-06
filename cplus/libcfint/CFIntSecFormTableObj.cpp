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

	const std::string CFIntSecFormTableObj::CLASS_NAME( "CFIntSecFormTableObj" );
	const std::string CFIntSecFormTableObj::TABLE_NAME( "SecForm" );
	const std::string CFIntSecFormTableObj::TABLE_DBNAME( "SecForm" );

	CFIntSecFormTableObj::CFIntSecFormTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>();
		allSecForm = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecFormByClusterIdxKey,
			std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>*>();
		indexBySecAppIdx = new std::map< cfsec::CFSecSecFormBySecAppIdxKey,
			std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>*>();
		indexByUJEEServletIdx = new std::map< cfsec::CFSecSecFormByUJEEServletIdxKey,
			cfsec::ICFSecSecFormObj*>();
	}

	CFIntSecFormTableObj::CFIntSecFormTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>();
		allSecForm = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecFormByClusterIdxKey,
			std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>*>();
		indexBySecAppIdx = new std::map< cfsec::CFSecSecFormBySecAppIdxKey,
			std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>*>();
		indexByUJEEServletIdx = new std::map< cfsec::CFSecSecFormByUJEEServletIdxKey,
			cfsec::ICFSecSecFormObj*>();
	}

	CFIntSecFormTableObj::~CFIntSecFormTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
		}
		if( indexBySecAppIdx != NULL ) {
			delete indexBySecAppIdx;
			indexBySecAppIdx = NULL;
		}
		if( indexByUJEEServletIdx != NULL ) {
			delete indexByUJEEServletIdx;
			indexByUJEEServletIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecSecFormObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntSecFormTableObj::getSchema() {
		return( schema );
	}

	void CFIntSecFormTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntSecFormTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntSecFormTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntSecFormTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntSecFormTableObj::minimizeMemory() {
		if( allSecForm != NULL ) {
			allSecForm->clear();
			delete allSecForm;
			allSecForm = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecSecFormByClusterIdxKey,
				std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecSecFormByClusterIdxKey,
				std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* curByClusterIdx = NULL;
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
		if( indexBySecAppIdx != NULL ) {
			std::map< cfsec::CFSecSecFormBySecAppIdxKey,
				std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* >::iterator iterBySecAppIdx = indexBySecAppIdx->begin();
			std::map< cfsec::CFSecSecFormBySecAppIdxKey,
				std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* >::iterator endBySecAppIdx = indexBySecAppIdx->end();
			std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* curBySecAppIdx = NULL;
			while( iterBySecAppIdx != endBySecAppIdx ) {
				curBySecAppIdx = iterBySecAppIdx->second;
				if( curBySecAppIdx != NULL ) {
					curBySecAppIdx->clear();
					delete curBySecAppIdx;
					curBySecAppIdx = NULL;
					iterBySecAppIdx->second = NULL;
				}
				iterBySecAppIdx ++;
			}
			indexBySecAppIdx->clear();
		}
		if( indexByUJEEServletIdx != NULL ) {
			indexByUJEEServletIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecSecFormObj* cur = NULL;
			cfsec::ICFSecSecFormEditObj* edit = NULL;
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

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::newInstance() {
		cfsec::ICFSecSecFormObj* inst = dynamic_cast<cfsec::ICFSecSecFormObj*>( new CFIntSecFormObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSecFormEditObj* CFIntSecFormTableObj::newEditInstance( cfsec::ICFSecSecFormObj* orig ) {
		cfsec::ICFSecSecFormEditObj* edit = dynamic_cast<cfsec::ICFSecSecFormEditObj*>( new CFIntSecFormEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::realizeSecForm( cfsec::ICFSecSecFormObj* Obj ) {
		static const std::string S_ProcName( "realizeSecForm" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecFormObj* obj = Obj;
		cfsec::ICFSecSecFormObj* existingObj = NULL;
		cfsec::CFSecSecFormPKey* pkey = obj->getPKey();
		cfsec::ICFSecSecFormObj* keepObj = NULL;
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
				cfsec::CFSecSecFormByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexBySecAppIdx != NULL ) {
				cfsec::CFSecSecFormBySecAppIdxKey keySecAppIdx;
				keySecAppIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keySecAppIdx.setRequiredSecAppId( keepObj->getRequiredSecAppId() );
				auto searchSecAppIdx = indexBySecAppIdx->find( keySecAppIdx );
				if( searchSecAppIdx != indexBySecAppIdx->end() ) {
					std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* mapSecAppIdx = searchSecAppIdx->second;
					if( mapSecAppIdx != NULL ) {
						auto removalProbe = mapSecAppIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapSecAppIdx->end() ) {
							mapSecAppIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUJEEServletIdx != NULL ) {
				cfsec::CFSecSecFormByUJEEServletIdxKey keyUJEEServletIdx;
				keyUJEEServletIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUJEEServletIdx.setRequiredSecAppId( keepObj->getRequiredSecAppId() );
				keyUJEEServletIdx.setRequiredJEEServletMapName( keepObj->getRequiredJEEServletMapName() );
				auto removalProbe = indexByUJEEServletIdx->find( keyUJEEServletIdx );
				if( removalProbe != indexByUJEEServletIdx->end() ) {
					indexByUJEEServletIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSecFormBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecFormObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecFormObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecFormByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexBySecAppIdx != NULL ) {
				static const std::string S_ASecAppIdxObj( "aSecAppIdxObj" );
				cfsec::ICFSecSecFormObj* aSecAppIdxObj =
					dynamic_cast<cfsec::ICFSecSecFormObj*>( keepObj );
				if( aSecAppIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ASecAppIdxObj );
				}
				cfsec::CFSecSecFormBySecAppIdxKey keySecAppIdx;
				keySecAppIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keySecAppIdx.setRequiredSecAppId( keepObj->getRequiredSecAppId() );
				auto searchIndexBySecAppIdx = indexBySecAppIdx->find( keySecAppIdx );
				if( searchIndexBySecAppIdx != indexBySecAppIdx->end() ) {
					std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* mapSecAppIdx = searchIndexBySecAppIdx->second;
					if( mapSecAppIdx != NULL ) {
						mapSecAppIdx->insert( std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >::value_type( *(keepObj->getPKey()), aSecAppIdxObj ) );
					}
				}
			}

			if( indexByUJEEServletIdx != NULL ) {
				static const std::string S_AUJEEServletIdxObj( "aUJEEServletIdxObj" );
				cfsec::ICFSecSecFormObj* aUJEEServletIdxObj =
					dynamic_cast<cfsec::ICFSecSecFormObj*>( keepObj );
				if( aUJEEServletIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUJEEServletIdxObj );
				}
				cfsec::CFSecSecFormByUJEEServletIdxKey keyUJEEServletIdx;
				keyUJEEServletIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUJEEServletIdx.setRequiredSecAppId( keepObj->getRequiredSecAppId() );
				keyUJEEServletIdx.setRequiredJEEServletMapName( keepObj->getRequiredJEEServletMapName() );
				indexByUJEEServletIdx->insert( std::map< cfsec::CFSecSecFormByUJEEServletIdxKey, cfsec::ICFSecSecFormObj* >::value_type( keyUJEEServletIdx, aUJEEServletIdxObj ) );
			}

			if( allSecForm != NULL ) {
				allSecForm->insert( std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecFormObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecFormObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecFormByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexBySecAppIdx != NULL ) {
				static const std::string S_ASecAppIdxObj( "aSecAppIdxObj" );
				cfsec::ICFSecSecFormObj* aSecAppIdxObj =
					dynamic_cast<cfsec::ICFSecSecFormObj*>( keepObj );
				if( aSecAppIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ASecAppIdxObj );
				}
				cfsec::CFSecSecFormBySecAppIdxKey keySecAppIdx;
				keySecAppIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keySecAppIdx.setRequiredSecAppId( keepObj->getRequiredSecAppId() );
				auto searchIndexBySecAppIdx = indexBySecAppIdx->find( keySecAppIdx );
				if( searchIndexBySecAppIdx != indexBySecAppIdx->end() ) {
					std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* mapSecAppIdx = searchIndexBySecAppIdx->second;
					if( mapSecAppIdx != NULL ) {
						mapSecAppIdx->insert( std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >::value_type( *(keepObj->getPKey()), aSecAppIdxObj ) );
					}
				}
			}

			if( indexByUJEEServletIdx != NULL ) {
				static const std::string S_AUJEEServletIdxObj( "aUJEEServletIdxObj" );
				cfsec::ICFSecSecFormObj* aUJEEServletIdxObj =
					dynamic_cast<cfsec::ICFSecSecFormObj*>( keepObj );
				if( aUJEEServletIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUJEEServletIdxObj );
				}
				cfsec::CFSecSecFormByUJEEServletIdxKey keyUJEEServletIdx;
				keyUJEEServletIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUJEEServletIdx.setRequiredSecAppId( keepObj->getRequiredSecAppId() );
				keyUJEEServletIdx.setRequiredJEEServletMapName( keepObj->getRequiredJEEServletMapName() );
				indexByUJEEServletIdx->insert( std::map< cfsec::CFSecSecFormByUJEEServletIdxKey, cfsec::ICFSecSecFormObj* >::value_type( keyUJEEServletIdx, aUJEEServletIdxObj ) );
			}

			if( allSecForm != NULL ) {
				allSecForm->insert( std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntSecFormTableObj::deepDisposeByIdIdx( const int64_t ClusterId,
			const int32_t SecFormId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSecFormObj*> list;
		cfsec::ICFSecSecFormObj* existingObj = readCachedSecFormByIdIdx( ClusterId,
				SecFormId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecFormObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->reallyDeepDisposeSecForm( dynamic_cast<cfsec::ICFSecSecFormObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecFormTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecSecFormObj*> list;
		std::vector<cfsec::ICFSecSecFormObj*> matchesFound = readCachedSecFormByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecFormObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->reallyDeepDisposeSecForm( dynamic_cast<cfsec::ICFSecSecFormObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecFormTableObj::deepDisposeBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId ) {
		static const std::string S_ProcName( "deepDisposeBySecAppIdx" );
		std::vector<cfsec::ICFSecSecFormObj*> list;
		std::vector<cfsec::ICFSecSecFormObj*> matchesFound = readCachedSecFormBySecAppIdx( ClusterId,
				SecAppId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecFormObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->reallyDeepDisposeSecForm( dynamic_cast<cfsec::ICFSecSecFormObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecFormTableObj::deepDisposeByUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName ) {
		static const std::string S_ProcName( "deepDisposeByUJEEServletIdx" );
		std::vector<cfsec::ICFSecSecFormObj*> list;
		cfsec::ICFSecSecFormObj* existingObj = readCachedSecFormByUJEEServletIdx( ClusterId,
				SecAppId,
				JEEServletMapName );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecFormObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->reallyDeepDisposeSecForm( dynamic_cast<cfsec::ICFSecSecFormObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecFormTableObj::reallyDeepDisposeSecForm( cfsec::ICFSecSecFormObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSecForm" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSecFormObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSecFormBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->reallyDetachFromIndexesSecForm( dynamic_cast<cfsec::ICFSecSecFormObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::createSecForm( cfsec::ICFSecSecFormEditObj* Obj ) {
		static const std::string S_ProcName( "createSecForm" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecFormObj* obj = dynamic_cast<cfsec::ICFSecSecFormObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecFormBuff* buff = dynamic_cast<cfsec::CFSecSecFormBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->createSecForm(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSecFormBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSecFormObj*>( obj->realize() );
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

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::readSecForm( cfsec::CFSecSecFormPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecForm" );
		cfsec::ICFSecSecFormObj* obj = NULL;
		cfsec::ICFSecSecFormObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecFormBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredClusterId(),
			pkey->getRequiredSecFormId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSecFormObj*>( obj->realize() );
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

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::lockSecForm( cfsec::CFSecSecFormPKey* pkey ) {
		static const std::string S_ProcName( "lockSecForm" );
		cfsec::ICFSecSecFormObj* locked = NULL;
		cfsec::CFSecSecFormBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSecFormObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSecFormObj*> CFIntSecFormTableObj::readAllSecForm( bool forceRead ) {
		static const std::string S_ProcName( "readAllSecForm" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecFormObj* realized = NULL;
		if( forceRead || ( allSecForm == NULL ) ) {
			std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* map = new std::map<cfsec::CFSecSecFormPKey,cfsec::ICFSecSecFormObj*>();
			allSecForm = map;
			std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSecFormBuff* buff = NULL;
			cfsec::ICFSecSecFormObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSecFormObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSecForm->insert( std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSecForm->size();
		std::vector<cfsec::ICFSecSecFormObj*> arr;
		auto valIter = allSecForm->begin();
		size_t idx = 0;
		while( valIter != allSecForm->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecFormObj*> CFIntSecFormTableObj::pageAllSecForm(const int64_t* priorClusterId,
			const int32_t* priorSecFormId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllSecForm" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* map = NULL;
		cfsec::CFSecSecFormBuff* buff = NULL;
		cfsec::ICFSecSecFormObj* obj = NULL;
		cfsec::ICFSecSecFormObj* realized = NULL;
		std::vector<cfsec::ICFSecSecFormObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecSecFormPKey,cfsec::ICFSecSecFormObj*>();
			std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->pageAllBuff( schema->getAuthorization(),
				priorClusterId,
				priorSecFormId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecFormObj*>( obj->realize() );
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

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::readSecFormByIdIdx( const int64_t ClusterId,
			const int32_t SecFormId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecFormByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecFormPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecFormId( SecFormId );
		cfsec::ICFSecSecFormObj* obj = readSecForm( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecFormObj*> CFIntSecFormTableObj::readSecFormByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecFormByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecFormByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* dict;
		std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecSecFormByClusterIdxKey,
				std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>*>();
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
			dict = new std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>();
			cfsec::ICFSecSecFormObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecSecFormBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecFormObj* realized = dynamic_cast<cfsec::ICFSecSecFormObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecSecFormByClusterIdxKey,
				std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecFormObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecFormObj*> CFIntSecFormTableObj::readSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecFormBySecAppIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecFormBySecAppIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* dict;
		std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* oldDict;
		if( indexBySecAppIdx == NULL ) {
			indexBySecAppIdx = new std::map< cfsec::CFSecSecFormBySecAppIdxKey,
				std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>*>();
		}
		auto searchIndexBySecAppIdx = indexBySecAppIdx->find( key );
		if( searchIndexBySecAppIdx != indexBySecAppIdx->end() ) {
			oldDict = searchIndexBySecAppIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>();
			cfsec::ICFSecSecFormObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->readDerivedBySecAppIdx( schema->getAuthorization(),
				ClusterId,
				SecAppId );
			cfsec::CFSecSecFormBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecFormObj* realized = dynamic_cast<cfsec::ICFSecSecFormObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexBySecAppIdx->erase( searchIndexBySecAppIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexBySecAppIdx->insert( std::map< cfsec::CFSecSecFormBySecAppIdxKey,
				std::map< cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecFormObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::readSecFormByUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName, bool forceRead )
	{
		static const std::string S_ProcName( "readSecFormByUJEEServletIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUJEEServletIdx == NULL ) {
			indexByUJEEServletIdx = new std::map< cfsec::CFSecSecFormByUJEEServletIdxKey,
				cfsec::ICFSecSecFormObj*>();
		}
		cfsec::CFSecSecFormByUJEEServletIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		key.setRequiredJEEServletMapName( JEEServletMapName );
		cfsec::ICFSecSecFormObj* obj = NULL;
		cfsec::ICFSecSecFormObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUJEEServletIdx = indexByUJEEServletIdx->find( key );
			if( searchIndexByUJEEServletIdx != indexByUJEEServletIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUJEEServletIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecFormBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->readDerivedByUJEEServletIdx( schema->getAuthorization(),
				ClusterId,
				SecAppId,
				JEEServletMapName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecFormObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUJEEServletIdx->insert( std::map< cfsec::CFSecSecFormByUJEEServletIdxKey, cfsec::ICFSecSecFormObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecFormObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::readSecFormByLookupUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readSecFormByLookupUJEEServletIdx" );
		if( indexByUJEEServletIdx == NULL ) {
			indexByUJEEServletIdx = new std::map< cfsec::CFSecSecFormByUJEEServletIdxKey,
				cfsec::ICFSecSecFormObj*>();
		}
		cfsec::CFSecSecFormByUJEEServletIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		key.setRequiredJEEServletMapName( JEEServletMapName );
		cfsec::ICFSecSecFormObj* obj = NULL;
		cfsec::ICFSecSecFormObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUJEEServletIdx = indexByUJEEServletIdx->find( key );
			if( searchIndexByUJEEServletIdx != indexByUJEEServletIdx->end() ) {
				obj = searchIndexByUJEEServletIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecFormBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->readDerivedByLookupUJEEServletIdx( schema->getAuthorization(),
				ClusterId,
				SecAppId,
				JEEServletMapName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecSecFormObj*>( dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecFormObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUJEEServletIdx->insert( std::map< cfsec::CFSecSecFormByUJEEServletIdxKey, cfsec::ICFSecSecFormObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecFormObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::readCachedSecForm( cfsec::CFSecSecFormPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecForm" );
		cfsec::ICFSecSecFormObj* obj = NULL;
		cfsec::ICFSecSecFormObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::readCachedSecFormByIdIdx( const int64_t ClusterId,
			const int32_t SecFormId )
	{
		static const std::string S_ProcName( "readCachedSecFormByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecFormPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecFormId( SecFormId );
		cfsec::ICFSecSecFormObj* obj = readCachedSecForm( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecFormObj*> CFIntSecFormTableObj::readCachedSecFormByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedSecFormByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecFormObj*> arr;
		cfsec::CFSecSecFormByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecFormObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecFormObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecFormBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecFormObj*> CFIntSecFormTableObj::readCachedSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId )
	{
		static const std::string S_ProcName( "readCachedSecFormBySecAppIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecFormObj*> arr;
		cfsec::CFSecSecFormBySecAppIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* dict;
		if( indexBySecAppIdx == NULL ) {
			return( arr );
		}
		auto searchIndexBySecAppIdx = indexBySecAppIdx->find( key );
		if( searchIndexBySecAppIdx != indexBySecAppIdx->end() ) {
			dict = searchIndexBySecAppIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecFormObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecFormObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecFormBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::readCachedSecFormByUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName )
	{
		static const std::string S_ProcName( "readCachedSecFormByUJEEServletIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUJEEServletIdx == NULL ) {
			indexByUJEEServletIdx = new std::map< cfsec::CFSecSecFormByUJEEServletIdxKey,
				cfsec::ICFSecSecFormObj*>();
		}
		cfsec::CFSecSecFormByUJEEServletIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		key.setRequiredJEEServletMapName( JEEServletMapName );
		cfsec::ICFSecSecFormObj* obj = NULL;
		auto searchIndexByUJEEServletIdx = indexByUJEEServletIdx->find( key );
		if( searchIndexByUJEEServletIdx != indexByUJEEServletIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUJEEServletIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecFormBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::readCachedSecFormByLookupUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedSecFormByLookupUJEEServletIdx" );
		if( indexByUJEEServletIdx == NULL ) {
			indexByUJEEServletIdx = new std::map< cfsec::CFSecSecFormByUJEEServletIdxKey,
				cfsec::ICFSecSecFormObj*>();
		}
		cfsec::CFSecSecFormByUJEEServletIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		key.setRequiredJEEServletMapName( JEEServletMapName );
		cfsec::ICFSecSecFormObj* obj = NULL;
		cfsec::ICFSecSecFormObj* realized = NULL;
		auto searchIndexByUJEEServletIdx = indexByUJEEServletIdx->find( key );
		if( searchIndexByUJEEServletIdx != indexByUJEEServletIdx->end() ) {
			obj = searchIndexByUJEEServletIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecFormBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecFormObj*> CFIntSecFormTableObj::pageSecFormByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId )
	{
		static const std::string S_ProcName( "pageSecFormByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecFormByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		cfsec::ICFSecSecFormObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->pageBuffByClusterIdx( schema->getAuthorization(),
				ClusterId,
				priorClusterId,
				priorSecFormId );
		std::vector<cfsec::ICFSecSecFormObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecFormBuff* buff;
		cfsec::ICFSecSecFormObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecFormObj*>( obj->realize() );
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

	std::vector<cfsec::ICFSecSecFormObj*> CFIntSecFormTableObj::pageSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId )
	{
		static const std::string S_ProcName( "pageSecFormBySecAppIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecFormBySecAppIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		cfsec::ICFSecSecFormObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecFormBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->pageBuffBySecAppIdx( schema->getAuthorization(),
				ClusterId,
				SecAppId,
				priorClusterId,
				priorSecFormId );
		std::vector<cfsec::ICFSecSecFormObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecFormBuff* buff;
		cfsec::ICFSecSecFormObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecFormObj*>( obj->realize() );
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

	cfsec::ICFSecSecFormObj* CFIntSecFormTableObj::updateSecForm( cfsec::ICFSecSecFormEditObj* Obj ) {
		static const std::string S_ProcName( "updateSecForm" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecFormObj* obj = dynamic_cast<cfsec::ICFSecSecFormObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecFormBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->updateSecForm( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSecFormBuff*>( Obj->getSecFormBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSecFormObj*>( dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSecFormObj*>( obj->realize() );
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

	void CFIntSecFormTableObj::deleteSecForm( cfsec::ICFSecSecFormEditObj* Obj ) {
		cfsec::ICFSecSecFormObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->deleteSecForm( schema->getAuthorization(),
			obj->getSecFormBuff() );
		deepDisposeByIdIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecFormId() );
	}

	void CFIntSecFormTableObj::deleteSecFormByIdIdx( const int64_t ClusterId,
			const int32_t SecFormId )
	{
		cfsec::CFSecSecFormPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecFormId( SecFormId );
		cfsec::ICFSecSecFormObj* obj = readSecForm( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSecFormEditObj* editObj = dynamic_cast<cfsec::ICFSecSecFormEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSecFormEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntSecFormTableObj::deleteSecFormByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecForm()->deleteSecFormByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFIntSecFormTableObj::deleteSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecForm()->deleteSecFormBySecAppIdx( schema->getAuthorization(),
				ClusterId,
				SecAppId );
		deepDisposeBySecAppIdx( ClusterId,
			SecAppId );
	}

	void CFIntSecFormTableObj::deleteSecFormByUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName )
	{
		if( indexByUJEEServletIdx == NULL ) {
			indexByUJEEServletIdx = new std::map< cfsec::CFSecSecFormByUJEEServletIdxKey,
				cfsec::ICFSecSecFormObj*>();
		}
		cfsec::CFSecSecFormByUJEEServletIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		key.setRequiredJEEServletMapName( JEEServletMapName );
		cfsec::ICFSecSecFormObj* obj = NULL;
		auto searchIndexByUJEEServletIdx = indexByUJEEServletIdx->find( key );
		if( searchIndexByUJEEServletIdx != indexByUJEEServletIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->deleteSecFormByUJEEServletIdx( schema->getAuthorization(),
				ClusterId,
				SecAppId,
				JEEServletMapName );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecForm()->deleteSecFormByUJEEServletIdx( schema->getAuthorization(),
				ClusterId,
				SecAppId,
				JEEServletMapName );
		}
		deepDisposeByUJEEServletIdx( ClusterId,
			SecAppId,
			JEEServletMapName );
	}

	void CFIntSecFormTableObj::reallyDetachFromIndexesSecForm( cfsec::ICFSecSecFormObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSecForm" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecFormObj* obj = Obj;
		cfsec::CFSecSecFormPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSecFormObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecSecFormByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* mapClusterIdx = searchClusterIdx->second;
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

			if( indexBySecAppIdx != NULL ) {
				cfsec::CFSecSecFormBySecAppIdxKey keySecAppIdx;
				keySecAppIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keySecAppIdx.setRequiredSecAppId( obj->getRequiredSecAppId() );
				auto searchSecAppIdx = indexBySecAppIdx->find( keySecAppIdx );
				if( searchSecAppIdx != indexBySecAppIdx->end() ) {
					std::map<cfsec::CFSecSecFormPKey, cfsec::ICFSecSecFormObj*>* mapSecAppIdx = searchSecAppIdx->second;
					if( mapSecAppIdx != NULL ) {
						auto removalProbe = mapSecAppIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapSecAppIdx->end() ) {
							mapSecAppIdx->erase( removalProbe );
							if( mapSecAppIdx->empty() ) {
								delete mapSecAppIdx;
								mapSecAppIdx = NULL;
								indexBySecAppIdx->erase( searchSecAppIdx );
							}
						}
					}
				}
			}

			if( indexByUJEEServletIdx != NULL ) {
				cfsec::CFSecSecFormByUJEEServletIdxKey keyUJEEServletIdx;
				keyUJEEServletIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyUJEEServletIdx.setRequiredSecAppId( obj->getRequiredSecAppId() );
				keyUJEEServletIdx.setRequiredJEEServletMapName( obj->getRequiredJEEServletMapName() );
				auto removalProbe = indexByUJEEServletIdx->find( keyUJEEServletIdx );
				if( removalProbe != indexByUJEEServletIdx->end() ) {
					indexByUJEEServletIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
