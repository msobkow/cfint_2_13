// Description: C++18 Table Object implementation for CFInt.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
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

	const std::string CFIntMajorVersionTableObj::CLASS_NAME( "CFIntMajorVersionTableObj" );
	const std::string CFIntMajorVersionTableObj::TABLE_NAME( "MajorVersion" );
	const std::string CFIntMajorVersionTableObj::TABLE_DBNAME( "mjvrdef" );

	CFIntMajorVersionTableObj::CFIntMajorVersionTableObj() {
		schema = NULL;
		members = new std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>();
		allMajorVersion = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntMajorVersionByTenantIdxKey,
			std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>*>();
		indexBySubProjectIdx = new std::map< cfint::CFIntMajorVersionBySubProjectIdxKey,
			std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntMajorVersionByNameIdxKey,
			cfint::ICFIntMajorVersionObj*>();
	}

	CFIntMajorVersionTableObj::CFIntMajorVersionTableObj( cfint::ICFIntSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>();
		allMajorVersion = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntMajorVersionByTenantIdxKey,
			std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>*>();
		indexBySubProjectIdx = new std::map< cfint::CFIntMajorVersionBySubProjectIdxKey,
			std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntMajorVersionByNameIdxKey,
			cfint::ICFIntMajorVersionObj*>();
	}

	CFIntMajorVersionTableObj::~CFIntMajorVersionTableObj() {
		minimizeMemory();
		if( indexByTenantIdx != NULL ) {
			delete indexByTenantIdx;
			indexByTenantIdx = NULL;
		}
		if( indexBySubProjectIdx != NULL ) {
			delete indexBySubProjectIdx;
			indexBySubProjectIdx = NULL;
		}
		if( indexByNameIdx != NULL ) {
			delete indexByNameIdx;
			indexByNameIdx = NULL;
		}
		if( members != NULL ) {
			cfint::ICFIntMajorVersionObj* curMember;
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

	cfint::ICFIntSchemaObj* CFIntMajorVersionTableObj::getSchema() {
		return( schema );
	}

	void CFIntMajorVersionTableObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntMajorVersionTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntMajorVersionTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntMajorVersionTableObj::getObjQualifyingClassCode() {
		return( &cfsec::CFSecTenantBuff::CLASS_CODE );
	}


	void CFIntMajorVersionTableObj::minimizeMemory() {
		if( allMajorVersion != NULL ) {
			allMajorVersion->clear();
			delete allMajorVersion;
			allMajorVersion = NULL;
		}
		if( indexByTenantIdx != NULL ) {
			std::map< cfint::CFIntMajorVersionByTenantIdxKey,
				std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* >::iterator iterByTenantIdx = indexByTenantIdx->begin();
			std::map< cfint::CFIntMajorVersionByTenantIdxKey,
				std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* >::iterator endByTenantIdx = indexByTenantIdx->end();
			std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* curByTenantIdx = NULL;
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
		if( indexBySubProjectIdx != NULL ) {
			std::map< cfint::CFIntMajorVersionBySubProjectIdxKey,
				std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* >::iterator iterBySubProjectIdx = indexBySubProjectIdx->begin();
			std::map< cfint::CFIntMajorVersionBySubProjectIdxKey,
				std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* >::iterator endBySubProjectIdx = indexBySubProjectIdx->end();
			std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* curBySubProjectIdx = NULL;
			while( iterBySubProjectIdx != endBySubProjectIdx ) {
				curBySubProjectIdx = iterBySubProjectIdx->second;
				if( curBySubProjectIdx != NULL ) {
					curBySubProjectIdx->clear();
					delete curBySubProjectIdx;
					curBySubProjectIdx = NULL;
					iterBySubProjectIdx->second = NULL;
				}
				iterBySubProjectIdx ++;
			}
			indexBySubProjectIdx->clear();
		}
		if( indexByNameIdx != NULL ) {
			indexByNameIdx->clear();
		}
		if( members != NULL ) {
			cfint::ICFIntMajorVersionObj* cur = NULL;
			cfint::ICFIntMajorVersionEditObj* edit = NULL;
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

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::newInstance() {
		cfint::ICFIntMajorVersionObj* inst = dynamic_cast<cfint::ICFIntMajorVersionObj*>( new CFIntMajorVersionObj( schema ) );
		return( inst );
	}

	cfint::ICFIntMajorVersionEditObj* CFIntMajorVersionTableObj::newEditInstance( cfint::ICFIntMajorVersionObj* orig ) {
		cfint::ICFIntMajorVersionEditObj* edit = dynamic_cast<cfint::ICFIntMajorVersionEditObj*>( new CFIntMajorVersionEditObj( orig ));
		return( edit );
	}

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::realizeMajorVersion( cfint::ICFIntMajorVersionObj* Obj ) {
		static const std::string S_ProcName( "realizeMajorVersion" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntMajorVersionObj* obj = Obj;
		cfint::ICFIntMajorVersionObj* existingObj = NULL;
		cfint::CFIntMajorVersionPKey* pkey = obj->getPKey();
		cfint::ICFIntMajorVersionObj* keepObj = NULL;
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
				cfint::CFIntMajorVersionByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* mapTenantIdx = searchTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						auto removalProbe = mapTenantIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTenantIdx->end() ) {
							mapTenantIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexBySubProjectIdx != NULL ) {
				cfint::CFIntMajorVersionBySubProjectIdxKey keySubProjectIdx;
				keySubProjectIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keySubProjectIdx.setRequiredSubProjectId( keepObj->getRequiredSubProjectId() );
				auto searchSubProjectIdx = indexBySubProjectIdx->find( keySubProjectIdx );
				if( searchSubProjectIdx != indexBySubProjectIdx->end() ) {
					std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* mapSubProjectIdx = searchSubProjectIdx->second;
					if( mapSubProjectIdx != NULL ) {
						auto removalProbe = mapSubProjectIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapSubProjectIdx->end() ) {
							mapSubProjectIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntMajorVersionByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredSubProjectId( keepObj->getRequiredSubProjectId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByNameIdx->find( keyNameIdx );
				if( removalProbe != indexByNameIdx->end() ) {
					indexByNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfint::CFIntMajorVersionBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntMajorVersionObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntMajorVersionObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntMajorVersionByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexBySubProjectIdx != NULL ) {
				static const std::string S_ASubProjectIdxObj( "aSubProjectIdxObj" );
				cfint::ICFIntMajorVersionObj* aSubProjectIdxObj =
					dynamic_cast<cfint::ICFIntMajorVersionObj*>( keepObj );
				if( aSubProjectIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ASubProjectIdxObj );
				}
				cfint::CFIntMajorVersionBySubProjectIdxKey keySubProjectIdx;
				keySubProjectIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keySubProjectIdx.setRequiredSubProjectId( keepObj->getRequiredSubProjectId() );
				auto searchIndexBySubProjectIdx = indexBySubProjectIdx->find( keySubProjectIdx );
				if( searchIndexBySubProjectIdx != indexBySubProjectIdx->end() ) {
					std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* mapSubProjectIdx = searchIndexBySubProjectIdx->second;
					if( mapSubProjectIdx != NULL ) {
						mapSubProjectIdx->insert( std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >::value_type( *(keepObj->getPKey()), aSubProjectIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntMajorVersionObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntMajorVersionObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntMajorVersionByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredSubProjectId( keepObj->getRequiredSubProjectId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntMajorVersionByNameIdxKey, cfint::ICFIntMajorVersionObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allMajorVersion != NULL ) {
				allMajorVersion->insert( std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntMajorVersionObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntMajorVersionObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntMajorVersionByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexBySubProjectIdx != NULL ) {
				static const std::string S_ASubProjectIdxObj( "aSubProjectIdxObj" );
				cfint::ICFIntMajorVersionObj* aSubProjectIdxObj =
					dynamic_cast<cfint::ICFIntMajorVersionObj*>( keepObj );
				if( aSubProjectIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ASubProjectIdxObj );
				}
				cfint::CFIntMajorVersionBySubProjectIdxKey keySubProjectIdx;
				keySubProjectIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keySubProjectIdx.setRequiredSubProjectId( keepObj->getRequiredSubProjectId() );
				auto searchIndexBySubProjectIdx = indexBySubProjectIdx->find( keySubProjectIdx );
				if( searchIndexBySubProjectIdx != indexBySubProjectIdx->end() ) {
					std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* mapSubProjectIdx = searchIndexBySubProjectIdx->second;
					if( mapSubProjectIdx != NULL ) {
						mapSubProjectIdx->insert( std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >::value_type( *(keepObj->getPKey()), aSubProjectIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntMajorVersionObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntMajorVersionObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntMajorVersionByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredSubProjectId( keepObj->getRequiredSubProjectId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntMajorVersionByNameIdxKey, cfint::ICFIntMajorVersionObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allMajorVersion != NULL ) {
				allMajorVersion->insert( std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntMajorVersionTableObj::deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfint::ICFIntMajorVersionObj*> list;
		cfint::ICFIntMajorVersionObj* existingObj = readCachedMajorVersionByIdIdx( TenantId,
				Id );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntMajorVersionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->reallyDeepDisposeMajorVersion( dynamic_cast<cfint::ICFIntMajorVersionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntMajorVersionTableObj::deepDisposeByTenantIdx( const int64_t TenantId ) {
		static const std::string S_ProcName( "deepDisposeByTenantIdx" );
		std::vector<cfint::ICFIntMajorVersionObj*> list;
		std::vector<cfint::ICFIntMajorVersionObj*> matchesFound = readCachedMajorVersionByTenantIdx( TenantId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntMajorVersionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->reallyDeepDisposeMajorVersion( dynamic_cast<cfint::ICFIntMajorVersionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntMajorVersionTableObj::deepDisposeBySubProjectIdx( const int64_t TenantId,
			const int64_t SubProjectId ) {
		static const std::string S_ProcName( "deepDisposeBySubProjectIdx" );
		std::vector<cfint::ICFIntMajorVersionObj*> list;
		std::vector<cfint::ICFIntMajorVersionObj*> matchesFound = readCachedMajorVersionBySubProjectIdx( TenantId,
				SubProjectId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntMajorVersionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->reallyDeepDisposeMajorVersion( dynamic_cast<cfint::ICFIntMajorVersionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntMajorVersionTableObj::deepDisposeByNameIdx( const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByNameIdx" );
		std::vector<cfint::ICFIntMajorVersionObj*> list;
		cfint::ICFIntMajorVersionObj* existingObj = readCachedMajorVersionByNameIdx( TenantId,
				SubProjectId,
				Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntMajorVersionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->reallyDeepDisposeMajorVersion( dynamic_cast<cfint::ICFIntMajorVersionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntMajorVersionTableObj::reallyDeepDisposeMajorVersion( cfint::ICFIntMajorVersionObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeMajorVersion" );

		if( Obj == NULL ) {
			return;
		}

		cfint::ICFIntMajorVersionObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->deepDisposeByMajorVerIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->reallyDetachFromIndexesMajorVersion( dynamic_cast<cfint::ICFIntMajorVersionObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::createMajorVersion( cfint::ICFIntMajorVersionEditObj* Obj ) {
		static const std::string S_ProcName( "createMajorVersion" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntMajorVersionObj* obj = dynamic_cast<cfint::ICFIntMajorVersionObj*>( Obj->getOrig() );
		try {
			cfint::CFIntMajorVersionBuff* buff = dynamic_cast<cfint::CFIntMajorVersionBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->createMajorVersion(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfint::CFIntMajorVersionBuff*>( cloneable ) );
			obj = dynamic_cast<cfint::ICFIntMajorVersionObj*>( obj->realize() );
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

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::readMajorVersion( cfint::CFIntMajorVersionPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readMajorVersion" );
		cfint::ICFIntMajorVersionObj* obj = NULL;
		cfint::ICFIntMajorVersionObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntMajorVersionBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredTenantId(),
			pkey->getRequiredId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfint::ICFIntMajorVersionObj*>( obj->realize() );
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

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::lockMajorVersion( cfint::CFIntMajorVersionPKey* pkey ) {
		static const std::string S_ProcName( "lockMajorVersion" );
		cfint::ICFIntMajorVersionObj* locked = NULL;
		cfint::CFIntMajorVersionBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfint::ICFIntMajorVersionObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfint::ICFIntMajorVersionObj*> CFIntMajorVersionTableObj::readAllMajorVersion( bool forceRead ) {
		static const std::string S_ProcName( "readAllMajorVersion" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntMajorVersionObj* realized = NULL;
		if( forceRead || ( allMajorVersion == NULL ) ) {
			std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* map = new std::map<cfint::CFIntMajorVersionPKey,cfint::ICFIntMajorVersionObj*>();
			allMajorVersion = map;
			std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->readAllDerived( schema->getAuthorization() );
			cfint::CFIntMajorVersionBuff* buff = NULL;
			cfint::ICFIntMajorVersionObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfint::ICFIntMajorVersionObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allMajorVersion->insert( std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allMajorVersion->size();
		std::vector<cfint::ICFIntMajorVersionObj*> arr;
		auto valIter = allMajorVersion->begin();
		size_t idx = 0;
		while( valIter != allMajorVersion->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::readMajorVersionByIdIdx( const int64_t TenantId,
			const int64_t Id, bool forceRead )
	{
		static const std::string S_ProcName( "readMajorVersionByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntMajorVersionPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntMajorVersionObj* obj = readMajorVersion( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfint::ICFIntMajorVersionObj*> CFIntMajorVersionTableObj::readMajorVersionByTenantIdx( const int64_t TenantId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readMajorVersionByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntMajorVersionByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* dict;
		std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* oldDict;
		if( indexByTenantIdx == NULL ) {
			indexByTenantIdx = new std::map< cfint::CFIntMajorVersionByTenantIdxKey,
				std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>*>();
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
			dict = new std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>();
			cfint::ICFIntMajorVersionObj* obj;
			std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->readDerivedByTenantIdx( schema->getAuthorization(),
				TenantId );
			cfint::CFIntMajorVersionBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntMajorVersionObj* realized = dynamic_cast<cfint::ICFIntMajorVersionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTenantIdx->erase( searchIndexByTenantIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTenantIdx->insert( std::map< cfint::CFIntMajorVersionByTenantIdxKey,
				std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntMajorVersionObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfint::ICFIntMajorVersionObj*> CFIntMajorVersionTableObj::readMajorVersionBySubProjectIdx( const int64_t TenantId,
			const int64_t SubProjectId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readMajorVersionBySubProjectIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntMajorVersionBySubProjectIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* dict;
		std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* oldDict;
		if( indexBySubProjectIdx == NULL ) {
			indexBySubProjectIdx = new std::map< cfint::CFIntMajorVersionBySubProjectIdxKey,
				std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>*>();
		}
		auto searchIndexBySubProjectIdx = indexBySubProjectIdx->find( key );
		if( searchIndexBySubProjectIdx != indexBySubProjectIdx->end() ) {
			oldDict = searchIndexBySubProjectIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>();
			cfint::ICFIntMajorVersionObj* obj;
			std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->readDerivedBySubProjectIdx( schema->getAuthorization(),
				TenantId,
				SubProjectId );
			cfint::CFIntMajorVersionBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntMajorVersionObj* realized = dynamic_cast<cfint::ICFIntMajorVersionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexBySubProjectIdx->erase( searchIndexBySubProjectIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexBySubProjectIdx->insert( std::map< cfint::CFIntMajorVersionBySubProjectIdxKey,
				std::map< cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntMajorVersionObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::readMajorVersionByNameIdx( const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readMajorVersionByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntMajorVersionByNameIdxKey,
				cfint::ICFIntMajorVersionObj*>();
		}
		cfint::CFIntMajorVersionByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		key.setRequiredName( Name );
		cfint::ICFIntMajorVersionObj* obj = NULL;
		cfint::ICFIntMajorVersionObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntMajorVersionBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->readDerivedByNameIdx( schema->getAuthorization(),
				TenantId,
				SubProjectId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntMajorVersionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntMajorVersionByNameIdxKey, cfint::ICFIntMajorVersionObj*>::value_type( key, dynamic_cast<cfint::ICFIntMajorVersionObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::readMajorVersionByLookupNameIdx( const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readMajorVersionByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntMajorVersionByNameIdxKey,
				cfint::ICFIntMajorVersionObj*>();
		}
		cfint::CFIntMajorVersionByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		key.setRequiredName( Name );
		cfint::ICFIntMajorVersionObj* obj = NULL;
		cfint::ICFIntMajorVersionObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				obj = searchIndexByNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntMajorVersionBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->readDerivedByLookupNameIdx( schema->getAuthorization(),
				TenantId,
				SubProjectId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::ICFIntMajorVersionObj*>( dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntMajorVersionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntMajorVersionByNameIdxKey, cfint::ICFIntMajorVersionObj*>::value_type( key, dynamic_cast<cfint::ICFIntMajorVersionObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::readCachedMajorVersion( cfint::CFIntMajorVersionPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readMajorVersion" );
		cfint::ICFIntMajorVersionObj* obj = NULL;
		cfint::ICFIntMajorVersionObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::readCachedMajorVersionByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readCachedMajorVersionByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntMajorVersionPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntMajorVersionObj* obj = readCachedMajorVersion( &pkey );
		return( obj );
	}

	std::vector<cfint::ICFIntMajorVersionObj*> CFIntMajorVersionTableObj::readCachedMajorVersionByTenantIdx( const int64_t TenantId )
	{
		static const std::string S_ProcName( "readCachedMajorVersionByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntMajorVersionObj*> arr;
		cfint::CFIntMajorVersionByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* dict;
		if( indexByTenantIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTenantIdx = indexByTenantIdx->find( key );
		if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
			dict = searchIndexByTenantIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntMajorVersionObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntMajorVersionObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntMajorVersionBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfint::ICFIntMajorVersionObj*> CFIntMajorVersionTableObj::readCachedMajorVersionBySubProjectIdx( const int64_t TenantId,
			const int64_t SubProjectId )
	{
		static const std::string S_ProcName( "readCachedMajorVersionBySubProjectIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntMajorVersionObj*> arr;
		cfint::CFIntMajorVersionBySubProjectIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* dict;
		if( indexBySubProjectIdx == NULL ) {
			return( arr );
		}
		auto searchIndexBySubProjectIdx = indexBySubProjectIdx->find( key );
		if( searchIndexBySubProjectIdx != indexBySubProjectIdx->end() ) {
			dict = searchIndexBySubProjectIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntMajorVersionObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntMajorVersionObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntMajorVersionBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::readCachedMajorVersionByNameIdx( const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedMajorVersionByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntMajorVersionByNameIdxKey,
				cfint::ICFIntMajorVersionObj*>();
		}
		cfint::CFIntMajorVersionByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		key.setRequiredName( Name );
		cfint::ICFIntMajorVersionObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntMajorVersionBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::readCachedMajorVersionByLookupNameIdx( const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedMajorVersionByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntMajorVersionByNameIdxKey,
				cfint::ICFIntMajorVersionObj*>();
		}
		cfint::CFIntMajorVersionByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		key.setRequiredName( Name );
		cfint::ICFIntMajorVersionObj* obj = NULL;
		cfint::ICFIntMajorVersionObj* realized = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntMajorVersionBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntMajorVersionObj* CFIntMajorVersionTableObj::updateMajorVersion( cfint::ICFIntMajorVersionEditObj* Obj ) {
		static const std::string S_ProcName( "updateMajorVersion" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntMajorVersionObj* obj = dynamic_cast<cfint::ICFIntMajorVersionObj*>( Obj->getOrig() );
		try {
			cfint::CFIntMajorVersionBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->updateMajorVersion( schema->getAuthorization(),
				dynamic_cast<cfint::CFIntMajorVersionBuff*>( Obj->getMajorVersionBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfint::ICFIntMajorVersionObj*>( dynamic_cast<cfint::CFIntMajorVersionTableObj*>( schema->getMajorVersionTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfint::ICFIntMajorVersionObj*>( obj->realize() );
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

	void CFIntMajorVersionTableObj::deleteMajorVersion( cfint::ICFIntMajorVersionEditObj* Obj ) {
		cfint::ICFIntMajorVersionObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->deleteMajorVersion( schema->getAuthorization(),
			obj->getMajorVersionBuff() );
		deepDisposeByIdIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
	}

	void CFIntMajorVersionTableObj::deleteMajorVersionByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		cfint::CFIntMajorVersionPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntMajorVersionObj* obj = readMajorVersion( &pkey, true );
		if( obj != NULL ) {
			cfint::ICFIntMajorVersionEditObj* editObj = dynamic_cast<cfint::ICFIntMajorVersionEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfint::ICFIntMajorVersionEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntMajorVersionTableObj::deleteMajorVersionByTenantIdx( const int64_t TenantId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->deleteMajorVersionByTenantIdx( schema->getAuthorization(),
				TenantId );
		deepDisposeByTenantIdx( TenantId );
	}

	void CFIntMajorVersionTableObj::deleteMajorVersionBySubProjectIdx( const int64_t TenantId,
			const int64_t SubProjectId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->deleteMajorVersionBySubProjectIdx( schema->getAuthorization(),
				TenantId,
				SubProjectId );
		deepDisposeBySubProjectIdx( TenantId,
			SubProjectId );
	}

	void CFIntMajorVersionTableObj::deleteMajorVersionByNameIdx( const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name )
	{
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntMajorVersionByNameIdxKey,
				cfint::ICFIntMajorVersionObj*>();
		}
		cfint::CFIntMajorVersionByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		key.setRequiredName( Name );
		cfint::ICFIntMajorVersionObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->deleteMajorVersionByNameIdx( schema->getAuthorization(),
				TenantId,
				SubProjectId,
				Name );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMajorVersion()->deleteMajorVersionByNameIdx( schema->getAuthorization(),
				TenantId,
				SubProjectId,
				Name );
		}
		deepDisposeByNameIdx( TenantId,
			SubProjectId,
			Name );
	}

	void CFIntMajorVersionTableObj::reallyDetachFromIndexesMajorVersion( cfint::ICFIntMajorVersionObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesMajorVersion" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntMajorVersionObj* obj = Obj;
		cfint::CFIntMajorVersionPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfint::ICFIntMajorVersionObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByTenantIdx != NULL ) {
				cfint::CFIntMajorVersionByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* mapTenantIdx = searchTenantIdx->second;
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

			if( indexBySubProjectIdx != NULL ) {
				cfint::CFIntMajorVersionBySubProjectIdxKey keySubProjectIdx;
				keySubProjectIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keySubProjectIdx.setRequiredSubProjectId( obj->getRequiredSubProjectId() );
				auto searchSubProjectIdx = indexBySubProjectIdx->find( keySubProjectIdx );
				if( searchSubProjectIdx != indexBySubProjectIdx->end() ) {
					std::map<cfint::CFIntMajorVersionPKey, cfint::ICFIntMajorVersionObj*>* mapSubProjectIdx = searchSubProjectIdx->second;
					if( mapSubProjectIdx != NULL ) {
						auto removalProbe = mapSubProjectIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapSubProjectIdx->end() ) {
							mapSubProjectIdx->erase( removalProbe );
							if( mapSubProjectIdx->empty() ) {
								delete mapSubProjectIdx;
								mapSubProjectIdx = NULL;
								indexBySubProjectIdx->erase( searchSubProjectIdx );
							}
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntMajorVersionByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyNameIdx.setRequiredSubProjectId( obj->getRequiredSubProjectId() );
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
