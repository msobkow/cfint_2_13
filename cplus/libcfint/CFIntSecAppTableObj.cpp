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

	const std::string CFIntSecAppTableObj::CLASS_NAME( "CFIntSecAppTableObj" );
	const std::string CFIntSecAppTableObj::TABLE_NAME( "SecApp" );
	const std::string CFIntSecAppTableObj::TABLE_DBNAME( "SecApp" );

	CFIntSecAppTableObj::CFIntSecAppTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>();
		allSecApp = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecAppByClusterIdxKey,
			std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>*>();
		indexByUJEEMountIdx = new std::map< cfsec::CFSecSecAppByUJEEMountIdxKey,
			cfsec::ICFSecSecAppObj*>();
	}

	CFIntSecAppTableObj::CFIntSecAppTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>();
		allSecApp = NULL;
		indexByClusterIdx = new std::map< cfsec::CFSecSecAppByClusterIdxKey,
			std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>*>();
		indexByUJEEMountIdx = new std::map< cfsec::CFSecSecAppByUJEEMountIdxKey,
			cfsec::ICFSecSecAppObj*>();
	}

	CFIntSecAppTableObj::~CFIntSecAppTableObj() {
		minimizeMemory();
		if( indexByClusterIdx != NULL ) {
			delete indexByClusterIdx;
			indexByClusterIdx = NULL;
		}
		if( indexByUJEEMountIdx != NULL ) {
			delete indexByUJEEMountIdx;
			indexByUJEEMountIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecSecAppObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntSecAppTableObj::getSchema() {
		return( schema );
	}

	void CFIntSecAppTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntSecAppTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntSecAppTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntSecAppTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntSecAppTableObj::minimizeMemory() {
		if( allSecApp != NULL ) {
			allSecApp->clear();
			delete allSecApp;
			allSecApp = NULL;
		}
		if( indexByClusterIdx != NULL ) {
			std::map< cfsec::CFSecSecAppByClusterIdxKey,
				std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* >::iterator iterByClusterIdx = indexByClusterIdx->begin();
			std::map< cfsec::CFSecSecAppByClusterIdxKey,
				std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* >::iterator endByClusterIdx = indexByClusterIdx->end();
			std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* curByClusterIdx = NULL;
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
		if( indexByUJEEMountIdx != NULL ) {
			indexByUJEEMountIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecSecAppObj* cur = NULL;
			cfsec::ICFSecSecAppEditObj* edit = NULL;
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

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::newInstance() {
		cfsec::ICFSecSecAppObj* inst = dynamic_cast<cfsec::ICFSecSecAppObj*>( new CFIntSecAppObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecSecAppEditObj* CFIntSecAppTableObj::newEditInstance( cfsec::ICFSecSecAppObj* orig ) {
		cfsec::ICFSecSecAppEditObj* edit = dynamic_cast<cfsec::ICFSecSecAppEditObj*>( new CFIntSecAppEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::realizeSecApp( cfsec::ICFSecSecAppObj* Obj ) {
		static const std::string S_ProcName( "realizeSecApp" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecAppObj* obj = Obj;
		cfsec::ICFSecSecAppObj* existingObj = NULL;
		cfsec::CFSecSecAppPKey* pkey = obj->getPKey();
		cfsec::ICFSecSecAppObj* keepObj = NULL;
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
				cfsec::CFSecSecAppByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* mapClusterIdx = searchClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						auto removalProbe = mapClusterIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapClusterIdx->end() ) {
							mapClusterIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUJEEMountIdx != NULL ) {
				cfsec::CFSecSecAppByUJEEMountIdxKey keyUJEEMountIdx;
				keyUJEEMountIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUJEEMountIdx.setRequiredJEEMountName( keepObj->getRequiredJEEMountName() );
				auto removalProbe = indexByUJEEMountIdx->find( keyUJEEMountIdx );
				if( removalProbe != indexByUJEEMountIdx->end() ) {
					indexByUJEEMountIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecSecAppBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecAppObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecAppObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecAppByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByUJEEMountIdx != NULL ) {
				static const std::string S_AUJEEMountIdxObj( "aUJEEMountIdxObj" );
				cfsec::ICFSecSecAppObj* aUJEEMountIdxObj =
					dynamic_cast<cfsec::ICFSecSecAppObj*>( keepObj );
				if( aUJEEMountIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUJEEMountIdxObj );
				}
				cfsec::CFSecSecAppByUJEEMountIdxKey keyUJEEMountIdx;
				keyUJEEMountIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUJEEMountIdx.setRequiredJEEMountName( keepObj->getRequiredJEEMountName() );
				indexByUJEEMountIdx->insert( std::map< cfsec::CFSecSecAppByUJEEMountIdxKey, cfsec::ICFSecSecAppObj* >::value_type( keyUJEEMountIdx, aUJEEMountIdxObj ) );
			}

			if( allSecApp != NULL ) {
				allSecApp->insert( std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByClusterIdx != NULL ) {
				static const std::string S_AClusterIdxObj( "aClusterIdxObj" );
				cfsec::ICFSecSecAppObj* aClusterIdxObj =
					dynamic_cast<cfsec::ICFSecSecAppObj*>( keepObj );
				if( aClusterIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AClusterIdxObj );
				}
				cfsec::CFSecSecAppByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				auto searchIndexByClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* mapClusterIdx = searchIndexByClusterIdx->second;
					if( mapClusterIdx != NULL ) {
						mapClusterIdx->insert( std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj* >::value_type( *(keepObj->getPKey()), aClusterIdxObj ) );
					}
				}
			}

			if( indexByUJEEMountIdx != NULL ) {
				static const std::string S_AUJEEMountIdxObj( "aUJEEMountIdxObj" );
				cfsec::ICFSecSecAppObj* aUJEEMountIdxObj =
					dynamic_cast<cfsec::ICFSecSecAppObj*>( keepObj );
				if( aUJEEMountIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUJEEMountIdxObj );
				}
				cfsec::CFSecSecAppByUJEEMountIdxKey keyUJEEMountIdx;
				keyUJEEMountIdx.setRequiredClusterId( keepObj->getRequiredClusterId() );
				keyUJEEMountIdx.setRequiredJEEMountName( keepObj->getRequiredJEEMountName() );
				indexByUJEEMountIdx->insert( std::map< cfsec::CFSecSecAppByUJEEMountIdxKey, cfsec::ICFSecSecAppObj* >::value_type( keyUJEEMountIdx, aUJEEMountIdxObj ) );
			}

			if( allSecApp != NULL ) {
				allSecApp->insert( std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntSecAppTableObj::deepDisposeByIdIdx( const int64_t ClusterId,
			const int32_t SecAppId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecSecAppObj*> list;
		cfsec::ICFSecSecAppObj* existingObj = readCachedSecAppByIdIdx( ClusterId,
				SecAppId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecAppObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->reallyDeepDisposeSecApp( dynamic_cast<cfsec::ICFSecSecAppObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecAppTableObj::deepDisposeByClusterIdx( const int64_t ClusterId ) {
		static const std::string S_ProcName( "deepDisposeByClusterIdx" );
		std::vector<cfsec::ICFSecSecAppObj*> list;
		std::vector<cfsec::ICFSecSecAppObj*> matchesFound = readCachedSecAppByClusterIdx( ClusterId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecSecAppObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->reallyDeepDisposeSecApp( dynamic_cast<cfsec::ICFSecSecAppObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecAppTableObj::deepDisposeByUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName ) {
		static const std::string S_ProcName( "deepDisposeByUJEEMountIdx" );
		std::vector<cfsec::ICFSecSecAppObj*> list;
		cfsec::ICFSecSecAppObj* existingObj = readCachedSecAppByUJEEMountIdx( ClusterId,
				JEEMountName );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecSecAppObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->reallyDeepDisposeSecApp( dynamic_cast<cfsec::ICFSecSecAppObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntSecAppTableObj::reallyDeepDisposeSecApp( cfsec::ICFSecSecAppObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeSecApp" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecSecAppObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntSecFormTableObj*>( schema->getSecFormTableObj() )->deepDisposeBySecAppIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecAppId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecSecAppBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->reallyDetachFromIndexesSecApp( dynamic_cast<cfsec::ICFSecSecAppObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::createSecApp( cfsec::ICFSecSecAppEditObj* Obj ) {
		static const std::string S_ProcName( "createSecApp" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecAppObj* obj = dynamic_cast<cfsec::ICFSecSecAppObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecAppBuff* buff = dynamic_cast<cfsec::CFSecSecAppBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->createSecApp(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecSecAppBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecSecAppObj*>( obj->realize() );
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

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::readSecApp( cfsec::CFSecSecAppPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecApp" );
		cfsec::ICFSecSecAppObj* obj = NULL;
		cfsec::ICFSecSecAppObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecAppBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredClusterId(),
			pkey->getRequiredSecAppId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecSecAppObj*>( obj->realize() );
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

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::lockSecApp( cfsec::CFSecSecAppPKey* pkey ) {
		static const std::string S_ProcName( "lockSecApp" );
		cfsec::ICFSecSecAppObj* locked = NULL;
		cfsec::CFSecSecAppBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecSecAppObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecSecAppObj*> CFIntSecAppTableObj::readAllSecApp( bool forceRead ) {
		static const std::string S_ProcName( "readAllSecApp" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecAppObj* realized = NULL;
		if( forceRead || ( allSecApp == NULL ) ) {
			std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* map = new std::map<cfsec::CFSecSecAppPKey,cfsec::ICFSecSecAppObj*>();
			allSecApp = map;
			std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecSecAppBuff* buff = NULL;
			cfsec::ICFSecSecAppObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecSecAppObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allSecApp->insert( std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allSecApp->size();
		std::vector<cfsec::ICFSecSecAppObj*> arr;
		auto valIter = allSecApp->begin();
		size_t idx = 0;
		while( valIter != allSecApp->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecSecAppObj*> CFIntSecAppTableObj::pageAllSecApp(const int64_t* priorClusterId,
			const int32_t* priorSecAppId )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "pageAllSecApp" );
		CFLIB_EXCEPTION_DECLINFO
		std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* map = NULL;
		cfsec::CFSecSecAppBuff* buff = NULL;
		cfsec::ICFSecSecAppObj* obj = NULL;
		cfsec::ICFSecSecAppObj* realized = NULL;
		std::vector<cfsec::ICFSecSecAppObj*> arrayList;
		try {
			map = new std::map<cfsec::CFSecSecAppPKey,cfsec::ICFSecSecAppObj*>();
			std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->pageAllBuff( schema->getAuthorization(),
				priorClusterId,
				priorSecAppId );
			arrayList.reserve( buffList.size() );
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecAppObj*>( obj->realize() );
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

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::readSecAppByIdIdx( const int64_t ClusterId,
			const int32_t SecAppId, bool forceRead )
	{
		static const std::string S_ProcName( "readSecAppByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecAppPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecAppId( SecAppId );
		cfsec::ICFSecSecAppObj* obj = readSecApp( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecAppObj*> CFIntSecAppTableObj::readSecAppByClusterIdx( const int64_t ClusterId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readSecAppByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecAppByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* dict;
		std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* oldDict;
		if( indexByClusterIdx == NULL ) {
			indexByClusterIdx = new std::map< cfsec::CFSecSecAppByClusterIdxKey,
				std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>*>();
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
			dict = new std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>();
			cfsec::ICFSecSecAppObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->readDerivedByClusterIdx( schema->getAuthorization(),
				ClusterId );
			cfsec::CFSecSecAppBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecSecAppObj* realized = dynamic_cast<cfsec::ICFSecSecAppObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByClusterIdx->erase( searchIndexByClusterIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByClusterIdx->insert( std::map< cfsec::CFSecSecAppByClusterIdxKey,
				std::map< cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecSecAppObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::readSecAppByUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName, bool forceRead )
	{
		static const std::string S_ProcName( "readSecAppByUJEEMountIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUJEEMountIdx == NULL ) {
			indexByUJEEMountIdx = new std::map< cfsec::CFSecSecAppByUJEEMountIdxKey,
				cfsec::ICFSecSecAppObj*>();
		}
		cfsec::CFSecSecAppByUJEEMountIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredJEEMountName( JEEMountName );
		cfsec::ICFSecSecAppObj* obj = NULL;
		cfsec::ICFSecSecAppObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUJEEMountIdx = indexByUJEEMountIdx->find( key );
			if( searchIndexByUJEEMountIdx != indexByUJEEMountIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUJEEMountIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecAppBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->readDerivedByUJEEMountIdx( schema->getAuthorization(),
				ClusterId,
				JEEMountName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecAppObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUJEEMountIdx->insert( std::map< cfsec::CFSecSecAppByUJEEMountIdxKey, cfsec::ICFSecSecAppObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecAppObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::readSecAppByLookupUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readSecAppByLookupUJEEMountIdx" );
		if( indexByUJEEMountIdx == NULL ) {
			indexByUJEEMountIdx = new std::map< cfsec::CFSecSecAppByUJEEMountIdxKey,
				cfsec::ICFSecSecAppObj*>();
		}
		cfsec::CFSecSecAppByUJEEMountIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredJEEMountName( JEEMountName );
		cfsec::ICFSecSecAppObj* obj = NULL;
		cfsec::ICFSecSecAppObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUJEEMountIdx = indexByUJEEMountIdx->find( key );
			if( searchIndexByUJEEMountIdx != indexByUJEEMountIdx->end() ) {
				obj = searchIndexByUJEEMountIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecSecAppBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->readDerivedByLookupUJEEMountIdx( schema->getAuthorization(),
				ClusterId,
				JEEMountName );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecSecAppObj*>( dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecSecAppObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUJEEMountIdx->insert( std::map< cfsec::CFSecSecAppByUJEEMountIdxKey, cfsec::ICFSecSecAppObj*>::value_type( key, dynamic_cast<cfsec::ICFSecSecAppObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::readCachedSecApp( cfsec::CFSecSecAppPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readSecApp" );
		cfsec::ICFSecSecAppObj* obj = NULL;
		cfsec::ICFSecSecAppObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::readCachedSecAppByIdIdx( const int64_t ClusterId,
			const int32_t SecAppId )
	{
		static const std::string S_ProcName( "readCachedSecAppByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecAppPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecAppId( SecAppId );
		cfsec::ICFSecSecAppObj* obj = readCachedSecApp( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecSecAppObj*> CFIntSecAppTableObj::readCachedSecAppByClusterIdx( const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readCachedSecAppByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecSecAppObj*> arr;
		cfsec::CFSecSecAppByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* dict;
		if( indexByClusterIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByClusterIdx = indexByClusterIdx->find( key );
		if( searchIndexByClusterIdx != indexByClusterIdx->end() ) {
			dict = searchIndexByClusterIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecSecAppObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecSecAppObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecAppBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::readCachedSecAppByUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName )
	{
		static const std::string S_ProcName( "readCachedSecAppByUJEEMountIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUJEEMountIdx == NULL ) {
			indexByUJEEMountIdx = new std::map< cfsec::CFSecSecAppByUJEEMountIdxKey,
				cfsec::ICFSecSecAppObj*>();
		}
		cfsec::CFSecSecAppByUJEEMountIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredJEEMountName( JEEMountName );
		cfsec::ICFSecSecAppObj* obj = NULL;
		auto searchIndexByUJEEMountIdx = indexByUJEEMountIdx->find( key );
		if( searchIndexByUJEEMountIdx != indexByUJEEMountIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUJEEMountIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecAppBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::readCachedSecAppByLookupUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedSecAppByLookupUJEEMountIdx" );
		if( indexByUJEEMountIdx == NULL ) {
			indexByUJEEMountIdx = new std::map< cfsec::CFSecSecAppByUJEEMountIdxKey,
				cfsec::ICFSecSecAppObj*>();
		}
		cfsec::CFSecSecAppByUJEEMountIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredJEEMountName( JEEMountName );
		cfsec::ICFSecSecAppObj* obj = NULL;
		cfsec::ICFSecSecAppObj* realized = NULL;
		auto searchIndexByUJEEMountIdx = indexByUJEEMountIdx->find( key );
		if( searchIndexByUJEEMountIdx != indexByUJEEMountIdx->end() ) {
			obj = searchIndexByUJEEMountIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecSecAppBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecSecAppObj*> CFIntSecAppTableObj::pageSecAppByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecAppId )
	{
		static const std::string S_ProcName( "pageSecAppByClusterIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecSecAppByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		cfsec::ICFSecSecAppObj* obj;
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->pageBuffByClusterIdx( schema->getAuthorization(),
				ClusterId,
				priorClusterId,
				priorSecAppId );
		std::vector<cfsec::ICFSecSecAppObj*> retList;
		retList.reserve( buffList.size() );
		cfsec::CFSecSecAppBuff* buff;
		cfsec::ICFSecSecAppObj* realized;
		for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
			buff = buffList[ idx ];
			buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
			obj->setBuff( buff );
			realized = dynamic_cast<cfsec::ICFSecSecAppObj*>( obj->realize() );
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

	cfsec::ICFSecSecAppObj* CFIntSecAppTableObj::updateSecApp( cfsec::ICFSecSecAppEditObj* Obj ) {
		static const std::string S_ProcName( "updateSecApp" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecSecAppObj* obj = dynamic_cast<cfsec::ICFSecSecAppObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecSecAppBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->updateSecApp( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecSecAppBuff*>( Obj->getSecAppBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecSecAppObj*>( dynamic_cast<cfint::CFIntSecAppTableObj*>( schema->getSecAppTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecSecAppObj*>( obj->realize() );
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

	void CFIntSecAppTableObj::deleteSecApp( cfsec::ICFSecSecAppEditObj* Obj ) {
		cfsec::ICFSecSecAppObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->deleteSecApp( schema->getAuthorization(),
			obj->getSecAppBuff() );
		deepDisposeByIdIdx( obj->getRequiredClusterId(),
			obj->getRequiredSecAppId() );
	}

	void CFIntSecAppTableObj::deleteSecAppByIdIdx( const int64_t ClusterId,
			const int32_t SecAppId )
	{
		cfsec::CFSecSecAppPKey pkey;
		pkey.setRequiredClusterId( ClusterId );
		pkey.setRequiredSecAppId( SecAppId );
		cfsec::ICFSecSecAppObj* obj = readSecApp( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecSecAppEditObj* editObj = dynamic_cast<cfsec::ICFSecSecAppEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecSecAppEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntSecAppTableObj::deleteSecAppByClusterIdx( const int64_t ClusterId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableSecApp()->deleteSecAppByClusterIdx( schema->getAuthorization(),
				ClusterId );
		deepDisposeByClusterIdx( ClusterId );
	}

	void CFIntSecAppTableObj::deleteSecAppByUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName )
	{
		if( indexByUJEEMountIdx == NULL ) {
			indexByUJEEMountIdx = new std::map< cfsec::CFSecSecAppByUJEEMountIdxKey,
				cfsec::ICFSecSecAppObj*>();
		}
		cfsec::CFSecSecAppByUJEEMountIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredJEEMountName( JEEMountName );
		cfsec::ICFSecSecAppObj* obj = NULL;
		auto searchIndexByUJEEMountIdx = indexByUJEEMountIdx->find( key );
		if( searchIndexByUJEEMountIdx != indexByUJEEMountIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->deleteSecAppByUJEEMountIdx( schema->getAuthorization(),
				ClusterId,
				JEEMountName );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableSecApp()->deleteSecAppByUJEEMountIdx( schema->getAuthorization(),
				ClusterId,
				JEEMountName );
		}
		deepDisposeByUJEEMountIdx( ClusterId,
			JEEMountName );
	}

	void CFIntSecAppTableObj::reallyDetachFromIndexesSecApp( cfsec::ICFSecSecAppObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesSecApp" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecSecAppObj* obj = Obj;
		cfsec::CFSecSecAppPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecSecAppObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByClusterIdx != NULL ) {
				cfsec::CFSecSecAppByClusterIdxKey keyClusterIdx;
				keyClusterIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				auto searchClusterIdx = indexByClusterIdx->find( keyClusterIdx );
				if( searchClusterIdx != indexByClusterIdx->end() ) {
					std::map<cfsec::CFSecSecAppPKey, cfsec::ICFSecSecAppObj*>* mapClusterIdx = searchClusterIdx->second;
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

			if( indexByUJEEMountIdx != NULL ) {
				cfsec::CFSecSecAppByUJEEMountIdxKey keyUJEEMountIdx;
				keyUJEEMountIdx.setRequiredClusterId( obj->getRequiredClusterId() );
				keyUJEEMountIdx.setRequiredJEEMountName( obj->getRequiredJEEMountName() );
				auto removalProbe = indexByUJEEMountIdx->find( keyUJEEMountIdx );
				if( removalProbe != indexByUJEEMountIdx->end() ) {
					indexByUJEEMountIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
