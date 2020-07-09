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

	const std::string CFIntTopDomainTableObj::CLASS_NAME( "CFIntTopDomainTableObj" );
	const std::string CFIntTopDomainTableObj::TABLE_NAME( "TopDomain" );
	const std::string CFIntTopDomainTableObj::TABLE_DBNAME( "tdomdef" );

	CFIntTopDomainTableObj::CFIntTopDomainTableObj() {
		schema = NULL;
		members = new std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>();
		allTopDomain = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntTopDomainByTenantIdxKey,
			std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>*>();
		indexByTldIdx = new std::map< cfint::CFIntTopDomainByTldIdxKey,
			std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntTopDomainByNameIdxKey,
			cfint::ICFIntTopDomainObj*>();
	}

	CFIntTopDomainTableObj::CFIntTopDomainTableObj( cfint::ICFIntSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>();
		allTopDomain = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntTopDomainByTenantIdxKey,
			std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>*>();
		indexByTldIdx = new std::map< cfint::CFIntTopDomainByTldIdxKey,
			std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntTopDomainByNameIdxKey,
			cfint::ICFIntTopDomainObj*>();
	}

	CFIntTopDomainTableObj::~CFIntTopDomainTableObj() {
		minimizeMemory();
		if( indexByTenantIdx != NULL ) {
			delete indexByTenantIdx;
			indexByTenantIdx = NULL;
		}
		if( indexByTldIdx != NULL ) {
			delete indexByTldIdx;
			indexByTldIdx = NULL;
		}
		if( indexByNameIdx != NULL ) {
			delete indexByNameIdx;
			indexByNameIdx = NULL;
		}
		if( members != NULL ) {
			cfint::ICFIntTopDomainObj* curMember;
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

	cfint::ICFIntSchemaObj* CFIntTopDomainTableObj::getSchema() {
		return( schema );
	}

	void CFIntTopDomainTableObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntTopDomainTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntTopDomainTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntTopDomainTableObj::getObjQualifyingClassCode() {
		return( &cfsec::CFSecTenantBuff::CLASS_CODE );
	}


	void CFIntTopDomainTableObj::minimizeMemory() {
		if( allTopDomain != NULL ) {
			allTopDomain->clear();
			delete allTopDomain;
			allTopDomain = NULL;
		}
		if( indexByTenantIdx != NULL ) {
			std::map< cfint::CFIntTopDomainByTenantIdxKey,
				std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* >::iterator iterByTenantIdx = indexByTenantIdx->begin();
			std::map< cfint::CFIntTopDomainByTenantIdxKey,
				std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* >::iterator endByTenantIdx = indexByTenantIdx->end();
			std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* curByTenantIdx = NULL;
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
		if( indexByTldIdx != NULL ) {
			std::map< cfint::CFIntTopDomainByTldIdxKey,
				std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* >::iterator iterByTldIdx = indexByTldIdx->begin();
			std::map< cfint::CFIntTopDomainByTldIdxKey,
				std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* >::iterator endByTldIdx = indexByTldIdx->end();
			std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* curByTldIdx = NULL;
			while( iterByTldIdx != endByTldIdx ) {
				curByTldIdx = iterByTldIdx->second;
				if( curByTldIdx != NULL ) {
					curByTldIdx->clear();
					delete curByTldIdx;
					curByTldIdx = NULL;
					iterByTldIdx->second = NULL;
				}
				iterByTldIdx ++;
			}
			indexByTldIdx->clear();
		}
		if( indexByNameIdx != NULL ) {
			indexByNameIdx->clear();
		}
		if( members != NULL ) {
			cfint::ICFIntTopDomainObj* cur = NULL;
			cfint::ICFIntTopDomainEditObj* edit = NULL;
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

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::newInstance() {
		cfint::ICFIntTopDomainObj* inst = dynamic_cast<cfint::ICFIntTopDomainObj*>( new CFIntTopDomainObj( schema ) );
		return( inst );
	}

	cfint::ICFIntTopDomainEditObj* CFIntTopDomainTableObj::newEditInstance( cfint::ICFIntTopDomainObj* orig ) {
		cfint::ICFIntTopDomainEditObj* edit = dynamic_cast<cfint::ICFIntTopDomainEditObj*>( new CFIntTopDomainEditObj( orig ));
		return( edit );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::realizeTopDomain( cfint::ICFIntTopDomainObj* Obj ) {
		static const std::string S_ProcName( "realizeTopDomain" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntTopDomainObj* obj = Obj;
		cfint::ICFIntTopDomainObj* existingObj = NULL;
		cfint::CFIntTopDomainPKey* pkey = obj->getPKey();
		cfint::ICFIntTopDomainObj* keepObj = NULL;
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
				cfint::CFIntTopDomainByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* mapTenantIdx = searchTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						auto removalProbe = mapTenantIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTenantIdx->end() ) {
							mapTenantIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByTldIdx != NULL ) {
				cfint::CFIntTopDomainByTldIdxKey keyTldIdx;
				keyTldIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTldIdx.setRequiredTldId( keepObj->getRequiredTldId() );
				auto searchTldIdx = indexByTldIdx->find( keyTldIdx );
				if( searchTldIdx != indexByTldIdx->end() ) {
					std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* mapTldIdx = searchTldIdx->second;
					if( mapTldIdx != NULL ) {
						auto removalProbe = mapTldIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTldIdx->end() ) {
							mapTldIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntTopDomainByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredTldId( keepObj->getRequiredTldId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByNameIdx->find( keyNameIdx );
				if( removalProbe != indexByNameIdx->end() ) {
					indexByNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfint::CFIntTopDomainBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntTopDomainObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntTopDomainObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntTopDomainByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByTldIdx != NULL ) {
				static const std::string S_ATldIdxObj( "aTldIdxObj" );
				cfint::ICFIntTopDomainObj* aTldIdxObj =
					dynamic_cast<cfint::ICFIntTopDomainObj*>( keepObj );
				if( aTldIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATldIdxObj );
				}
				cfint::CFIntTopDomainByTldIdxKey keyTldIdx;
				keyTldIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTldIdx.setRequiredTldId( keepObj->getRequiredTldId() );
				auto searchIndexByTldIdx = indexByTldIdx->find( keyTldIdx );
				if( searchIndexByTldIdx != indexByTldIdx->end() ) {
					std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* mapTldIdx = searchIndexByTldIdx->second;
					if( mapTldIdx != NULL ) {
						mapTldIdx->insert( std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >::value_type( *(keepObj->getPKey()), aTldIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntTopDomainObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntTopDomainObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntTopDomainByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredTldId( keepObj->getRequiredTldId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntTopDomainByNameIdxKey, cfint::ICFIntTopDomainObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allTopDomain != NULL ) {
				allTopDomain->insert( std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntTopDomainObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntTopDomainObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntTopDomainByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByTldIdx != NULL ) {
				static const std::string S_ATldIdxObj( "aTldIdxObj" );
				cfint::ICFIntTopDomainObj* aTldIdxObj =
					dynamic_cast<cfint::ICFIntTopDomainObj*>( keepObj );
				if( aTldIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATldIdxObj );
				}
				cfint::CFIntTopDomainByTldIdxKey keyTldIdx;
				keyTldIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyTldIdx.setRequiredTldId( keepObj->getRequiredTldId() );
				auto searchIndexByTldIdx = indexByTldIdx->find( keyTldIdx );
				if( searchIndexByTldIdx != indexByTldIdx->end() ) {
					std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* mapTldIdx = searchIndexByTldIdx->second;
					if( mapTldIdx != NULL ) {
						mapTldIdx->insert( std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >::value_type( *(keepObj->getPKey()), aTldIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntTopDomainObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntTopDomainObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntTopDomainByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredTldId( keepObj->getRequiredTldId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntTopDomainByNameIdxKey, cfint::ICFIntTopDomainObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allTopDomain != NULL ) {
				allTopDomain->insert( std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntTopDomainTableObj::deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfint::ICFIntTopDomainObj*> list;
		cfint::ICFIntTopDomainObj* existingObj = readCachedTopDomainByIdIdx( TenantId,
				Id );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntTopDomainObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntTopDomainBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->reallyDeepDisposeTopDomain( dynamic_cast<cfint::ICFIntTopDomainObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTopDomainTableObj::deepDisposeByTenantIdx( const int64_t TenantId ) {
		static const std::string S_ProcName( "deepDisposeByTenantIdx" );
		std::vector<cfint::ICFIntTopDomainObj*> list;
		std::vector<cfint::ICFIntTopDomainObj*> matchesFound = readCachedTopDomainByTenantIdx( TenantId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntTopDomainObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntTopDomainBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->reallyDeepDisposeTopDomain( dynamic_cast<cfint::ICFIntTopDomainObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTopDomainTableObj::deepDisposeByTldIdx( const int64_t TenantId,
			const int64_t TldId ) {
		static const std::string S_ProcName( "deepDisposeByTldIdx" );
		std::vector<cfint::ICFIntTopDomainObj*> list;
		std::vector<cfint::ICFIntTopDomainObj*> matchesFound = readCachedTopDomainByTldIdx( TenantId,
				TldId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntTopDomainObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntTopDomainBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->reallyDeepDisposeTopDomain( dynamic_cast<cfint::ICFIntTopDomainObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTopDomainTableObj::deepDisposeByNameIdx( const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByNameIdx" );
		std::vector<cfint::ICFIntTopDomainObj*> list;
		cfint::ICFIntTopDomainObj* existingObj = readCachedTopDomainByNameIdx( TenantId,
				TldId,
				Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntTopDomainObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntTopDomainBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->reallyDeepDisposeTopDomain( dynamic_cast<cfint::ICFIntTopDomainObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntTopDomainTableObj::reallyDeepDisposeTopDomain( cfint::ICFIntTopDomainObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeTopDomain" );

		if( Obj == NULL ) {
			return;
		}

		cfint::ICFIntTopDomainObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntTopProjectTableObj*>( schema->getTopProjectTableObj() )->deepDisposeByTopDomainIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
		dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->deepDisposeByDomainIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfint::CFIntTopDomainBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->reallyDetachFromIndexesTopDomain( dynamic_cast<cfint::ICFIntTopDomainObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::createTopDomain( cfint::ICFIntTopDomainEditObj* Obj ) {
		static const std::string S_ProcName( "createTopDomain" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntTopDomainObj* obj = dynamic_cast<cfint::ICFIntTopDomainObj*>( Obj->getOrig() );
		try {
			cfint::CFIntTopDomainBuff* buff = dynamic_cast<cfint::CFIntTopDomainBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->createTopDomain(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfint::CFIntTopDomainBuff*>( cloneable ) );
			obj = dynamic_cast<cfint::ICFIntTopDomainObj*>( obj->realize() );
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

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::readTopDomain( cfint::CFIntTopDomainPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTopDomain" );
		cfint::ICFIntTopDomainObj* obj = NULL;
		cfint::ICFIntTopDomainObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntTopDomainBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredTenantId(),
			pkey->getRequiredId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfint::ICFIntTopDomainObj*>( obj->realize() );
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

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::lockTopDomain( cfint::CFIntTopDomainPKey* pkey ) {
		static const std::string S_ProcName( "lockTopDomain" );
		cfint::ICFIntTopDomainObj* locked = NULL;
		cfint::CFIntTopDomainBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfint::ICFIntTopDomainObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfint::ICFIntTopDomainObj*> CFIntTopDomainTableObj::readAllTopDomain( bool forceRead ) {
		static const std::string S_ProcName( "readAllTopDomain" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntTopDomainObj* realized = NULL;
		if( forceRead || ( allTopDomain == NULL ) ) {
			std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* map = new std::map<cfint::CFIntTopDomainPKey,cfint::ICFIntTopDomainObj*>();
			allTopDomain = map;
			std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->readAllDerived( schema->getAuthorization() );
			cfint::CFIntTopDomainBuff* buff = NULL;
			cfint::ICFIntTopDomainObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfint::ICFIntTopDomainObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allTopDomain->insert( std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allTopDomain->size();
		std::vector<cfint::ICFIntTopDomainObj*> arr;
		auto valIter = allTopDomain->begin();
		size_t idx = 0;
		while( valIter != allTopDomain->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::readTopDomainByIdIdx( const int64_t TenantId,
			const int64_t Id, bool forceRead )
	{
		static const std::string S_ProcName( "readTopDomainByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntTopDomainPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntTopDomainObj* obj = readTopDomain( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfint::ICFIntTopDomainObj*> CFIntTopDomainTableObj::readTopDomainByTenantIdx( const int64_t TenantId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTopDomainByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntTopDomainByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* dict;
		std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* oldDict;
		if( indexByTenantIdx == NULL ) {
			indexByTenantIdx = new std::map< cfint::CFIntTopDomainByTenantIdxKey,
				std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>*>();
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
			dict = new std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>();
			cfint::ICFIntTopDomainObj* obj;
			std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->readDerivedByTenantIdx( schema->getAuthorization(),
				TenantId );
			cfint::CFIntTopDomainBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntTopDomainObj* realized = dynamic_cast<cfint::ICFIntTopDomainObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTenantIdx->erase( searchIndexByTenantIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTenantIdx->insert( std::map< cfint::CFIntTopDomainByTenantIdxKey,
				std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntTopDomainObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfint::ICFIntTopDomainObj*> CFIntTopDomainTableObj::readTopDomainByTldIdx( const int64_t TenantId,
			const int64_t TldId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readTopDomainByTldIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntTopDomainByTldIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* dict;
		std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* oldDict;
		if( indexByTldIdx == NULL ) {
			indexByTldIdx = new std::map< cfint::CFIntTopDomainByTldIdxKey,
				std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>*>();
		}
		auto searchIndexByTldIdx = indexByTldIdx->find( key );
		if( searchIndexByTldIdx != indexByTldIdx->end() ) {
			oldDict = searchIndexByTldIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>();
			cfint::ICFIntTopDomainObj* obj;
			std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->readDerivedByTldIdx( schema->getAuthorization(),
				TenantId,
				TldId );
			cfint::CFIntTopDomainBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntTopDomainObj* realized = dynamic_cast<cfint::ICFIntTopDomainObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTldIdx->erase( searchIndexByTldIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTldIdx->insert( std::map< cfint::CFIntTopDomainByTldIdxKey,
				std::map< cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntTopDomainObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::readTopDomainByNameIdx( const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readTopDomainByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTopDomainByNameIdxKey,
				cfint::ICFIntTopDomainObj*>();
		}
		cfint::CFIntTopDomainByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		key.setRequiredName( Name );
		cfint::ICFIntTopDomainObj* obj = NULL;
		cfint::ICFIntTopDomainObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntTopDomainBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->readDerivedByNameIdx( schema->getAuthorization(),
				TenantId,
				TldId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntTopDomainObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntTopDomainByNameIdxKey, cfint::ICFIntTopDomainObj*>::value_type( key, dynamic_cast<cfint::ICFIntTopDomainObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::readTopDomainByLookupNameIdx( const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readTopDomainByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTopDomainByNameIdxKey,
				cfint::ICFIntTopDomainObj*>();
		}
		cfint::CFIntTopDomainByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		key.setRequiredName( Name );
		cfint::ICFIntTopDomainObj* obj = NULL;
		cfint::ICFIntTopDomainObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				obj = searchIndexByNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntTopDomainBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->readDerivedByLookupNameIdx( schema->getAuthorization(),
				TenantId,
				TldId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::ICFIntTopDomainObj*>( dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntTopDomainObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntTopDomainByNameIdxKey, cfint::ICFIntTopDomainObj*>::value_type( key, dynamic_cast<cfint::ICFIntTopDomainObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::readCachedTopDomain( cfint::CFIntTopDomainPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readTopDomain" );
		cfint::ICFIntTopDomainObj* obj = NULL;
		cfint::ICFIntTopDomainObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::readCachedTopDomainByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readCachedTopDomainByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntTopDomainPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntTopDomainObj* obj = readCachedTopDomain( &pkey );
		return( obj );
	}

	std::vector<cfint::ICFIntTopDomainObj*> CFIntTopDomainTableObj::readCachedTopDomainByTenantIdx( const int64_t TenantId )
	{
		static const std::string S_ProcName( "readCachedTopDomainByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntTopDomainObj*> arr;
		cfint::CFIntTopDomainByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* dict;
		if( indexByTenantIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTenantIdx = indexByTenantIdx->find( key );
		if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
			dict = searchIndexByTenantIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntTopDomainObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntTopDomainObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntTopDomainBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfint::ICFIntTopDomainObj*> CFIntTopDomainTableObj::readCachedTopDomainByTldIdx( const int64_t TenantId,
			const int64_t TldId )
	{
		static const std::string S_ProcName( "readCachedTopDomainByTldIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntTopDomainObj*> arr;
		cfint::CFIntTopDomainByTldIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* dict;
		if( indexByTldIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTldIdx = indexByTldIdx->find( key );
		if( searchIndexByTldIdx != indexByTldIdx->end() ) {
			dict = searchIndexByTldIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntTopDomainObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntTopDomainObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntTopDomainBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::readCachedTopDomainByNameIdx( const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedTopDomainByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTopDomainByNameIdxKey,
				cfint::ICFIntTopDomainObj*>();
		}
		cfint::CFIntTopDomainByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		key.setRequiredName( Name );
		cfint::ICFIntTopDomainObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntTopDomainBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::readCachedTopDomainByLookupNameIdx( const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedTopDomainByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTopDomainByNameIdxKey,
				cfint::ICFIntTopDomainObj*>();
		}
		cfint::CFIntTopDomainByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		key.setRequiredName( Name );
		cfint::ICFIntTopDomainObj* obj = NULL;
		cfint::ICFIntTopDomainObj* realized = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntTopDomainBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntTopDomainObj* CFIntTopDomainTableObj::updateTopDomain( cfint::ICFIntTopDomainEditObj* Obj ) {
		static const std::string S_ProcName( "updateTopDomain" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntTopDomainObj* obj = dynamic_cast<cfint::ICFIntTopDomainObj*>( Obj->getOrig() );
		try {
			cfint::CFIntTopDomainBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->updateTopDomain( schema->getAuthorization(),
				dynamic_cast<cfint::CFIntTopDomainBuff*>( Obj->getTopDomainBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfint::ICFIntTopDomainObj*>( dynamic_cast<cfint::CFIntTopDomainTableObj*>( schema->getTopDomainTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfint::ICFIntTopDomainObj*>( obj->realize() );
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

	void CFIntTopDomainTableObj::deleteTopDomain( cfint::ICFIntTopDomainEditObj* Obj ) {
		cfint::ICFIntTopDomainObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->deleteTopDomain( schema->getAuthorization(),
			obj->getTopDomainBuff() );
		deepDisposeByIdIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
	}

	void CFIntTopDomainTableObj::deleteTopDomainByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		cfint::CFIntTopDomainPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntTopDomainObj* obj = readTopDomain( &pkey, true );
		if( obj != NULL ) {
			cfint::ICFIntTopDomainEditObj* editObj = dynamic_cast<cfint::ICFIntTopDomainEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfint::ICFIntTopDomainEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntTopDomainTableObj::deleteTopDomainByTenantIdx( const int64_t TenantId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->deleteTopDomainByTenantIdx( schema->getAuthorization(),
				TenantId );
		deepDisposeByTenantIdx( TenantId );
	}

	void CFIntTopDomainTableObj::deleteTopDomainByTldIdx( const int64_t TenantId,
			const int64_t TldId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->deleteTopDomainByTldIdx( schema->getAuthorization(),
				TenantId,
				TldId );
		deepDisposeByTldIdx( TenantId,
			TldId );
	}

	void CFIntTopDomainTableObj::deleteTopDomainByNameIdx( const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name )
	{
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntTopDomainByNameIdxKey,
				cfint::ICFIntTopDomainObj*>();
		}
		cfint::CFIntTopDomainByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		key.setRequiredName( Name );
		cfint::ICFIntTopDomainObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->deleteTopDomainByNameIdx( schema->getAuthorization(),
				TenantId,
				TldId,
				Name );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableTopDomain()->deleteTopDomainByNameIdx( schema->getAuthorization(),
				TenantId,
				TldId,
				Name );
		}
		deepDisposeByNameIdx( TenantId,
			TldId,
			Name );
	}

	void CFIntTopDomainTableObj::reallyDetachFromIndexesTopDomain( cfint::ICFIntTopDomainObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesTopDomain" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntTopDomainObj* obj = Obj;
		cfint::CFIntTopDomainPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfint::ICFIntTopDomainObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByTenantIdx != NULL ) {
				cfint::CFIntTopDomainByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* mapTenantIdx = searchTenantIdx->second;
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

			if( indexByTldIdx != NULL ) {
				cfint::CFIntTopDomainByTldIdxKey keyTldIdx;
				keyTldIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyTldIdx.setRequiredTldId( obj->getRequiredTldId() );
				auto searchTldIdx = indexByTldIdx->find( keyTldIdx );
				if( searchTldIdx != indexByTldIdx->end() ) {
					std::map<cfint::CFIntTopDomainPKey, cfint::ICFIntTopDomainObj*>* mapTldIdx = searchTldIdx->second;
					if( mapTldIdx != NULL ) {
						auto removalProbe = mapTldIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapTldIdx->end() ) {
							mapTldIdx->erase( removalProbe );
							if( mapTldIdx->empty() ) {
								delete mapTldIdx;
								mapTldIdx = NULL;
								indexByTldIdx->erase( searchTldIdx );
							}
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntTopDomainByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyNameIdx.setRequiredTldId( obj->getRequiredTldId() );
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
