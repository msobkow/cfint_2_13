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

	const std::string CFIntMinorVersionTableObj::CLASS_NAME( "CFIntMinorVersionTableObj" );
	const std::string CFIntMinorVersionTableObj::TABLE_NAME( "MinorVersion" );
	const std::string CFIntMinorVersionTableObj::TABLE_DBNAME( "mnvrdef" );

	CFIntMinorVersionTableObj::CFIntMinorVersionTableObj() {
		schema = NULL;
		members = new std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>();
		allMinorVersion = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntMinorVersionByTenantIdxKey,
			std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>*>();
		indexByMajorVerIdx = new std::map< cfint::CFIntMinorVersionByMajorVerIdxKey,
			std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntMinorVersionByNameIdxKey,
			cfint::ICFIntMinorVersionObj*>();
	}

	CFIntMinorVersionTableObj::CFIntMinorVersionTableObj( cfint::ICFIntSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>();
		allMinorVersion = NULL;
		indexByTenantIdx = new std::map< cfint::CFIntMinorVersionByTenantIdxKey,
			std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>*>();
		indexByMajorVerIdx = new std::map< cfint::CFIntMinorVersionByMajorVerIdxKey,
			std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>*>();
		indexByNameIdx = new std::map< cfint::CFIntMinorVersionByNameIdxKey,
			cfint::ICFIntMinorVersionObj*>();
	}

	CFIntMinorVersionTableObj::~CFIntMinorVersionTableObj() {
		minimizeMemory();
		if( indexByTenantIdx != NULL ) {
			delete indexByTenantIdx;
			indexByTenantIdx = NULL;
		}
		if( indexByMajorVerIdx != NULL ) {
			delete indexByMajorVerIdx;
			indexByMajorVerIdx = NULL;
		}
		if( indexByNameIdx != NULL ) {
			delete indexByNameIdx;
			indexByNameIdx = NULL;
		}
		if( members != NULL ) {
			cfint::ICFIntMinorVersionObj* curMember;
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

	cfint::ICFIntSchemaObj* CFIntMinorVersionTableObj::getSchema() {
		return( schema );
	}

	void CFIntMinorVersionTableObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntMinorVersionTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntMinorVersionTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntMinorVersionTableObj::getObjQualifyingClassCode() {
		return( &cfsec::CFSecTenantBuff::CLASS_CODE );
	}


	void CFIntMinorVersionTableObj::minimizeMemory() {
		if( allMinorVersion != NULL ) {
			allMinorVersion->clear();
			delete allMinorVersion;
			allMinorVersion = NULL;
		}
		if( indexByTenantIdx != NULL ) {
			std::map< cfint::CFIntMinorVersionByTenantIdxKey,
				std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* >::iterator iterByTenantIdx = indexByTenantIdx->begin();
			std::map< cfint::CFIntMinorVersionByTenantIdxKey,
				std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* >::iterator endByTenantIdx = indexByTenantIdx->end();
			std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* curByTenantIdx = NULL;
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
		if( indexByMajorVerIdx != NULL ) {
			std::map< cfint::CFIntMinorVersionByMajorVerIdxKey,
				std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* >::iterator iterByMajorVerIdx = indexByMajorVerIdx->begin();
			std::map< cfint::CFIntMinorVersionByMajorVerIdxKey,
				std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* >::iterator endByMajorVerIdx = indexByMajorVerIdx->end();
			std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* curByMajorVerIdx = NULL;
			while( iterByMajorVerIdx != endByMajorVerIdx ) {
				curByMajorVerIdx = iterByMajorVerIdx->second;
				if( curByMajorVerIdx != NULL ) {
					curByMajorVerIdx->clear();
					delete curByMajorVerIdx;
					curByMajorVerIdx = NULL;
					iterByMajorVerIdx->second = NULL;
				}
				iterByMajorVerIdx ++;
			}
			indexByMajorVerIdx->clear();
		}
		if( indexByNameIdx != NULL ) {
			indexByNameIdx->clear();
		}
		if( members != NULL ) {
			cfint::ICFIntMinorVersionObj* cur = NULL;
			cfint::ICFIntMinorVersionEditObj* edit = NULL;
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

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::newInstance() {
		cfint::ICFIntMinorVersionObj* inst = dynamic_cast<cfint::ICFIntMinorVersionObj*>( new CFIntMinorVersionObj( schema ) );
		return( inst );
	}

	cfint::ICFIntMinorVersionEditObj* CFIntMinorVersionTableObj::newEditInstance( cfint::ICFIntMinorVersionObj* orig ) {
		cfint::ICFIntMinorVersionEditObj* edit = dynamic_cast<cfint::ICFIntMinorVersionEditObj*>( new CFIntMinorVersionEditObj( orig ));
		return( edit );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::realizeMinorVersion( cfint::ICFIntMinorVersionObj* Obj ) {
		static const std::string S_ProcName( "realizeMinorVersion" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntMinorVersionObj* obj = Obj;
		cfint::ICFIntMinorVersionObj* existingObj = NULL;
		cfint::CFIntMinorVersionPKey* pkey = obj->getPKey();
		cfint::ICFIntMinorVersionObj* keepObj = NULL;
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
				cfint::CFIntMinorVersionByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* mapTenantIdx = searchTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						auto removalProbe = mapTenantIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapTenantIdx->end() ) {
							mapTenantIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByMajorVerIdx != NULL ) {
				cfint::CFIntMinorVersionByMajorVerIdxKey keyMajorVerIdx;
				keyMajorVerIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyMajorVerIdx.setRequiredMajorVersionId( keepObj->getRequiredMajorVersionId() );
				auto searchMajorVerIdx = indexByMajorVerIdx->find( keyMajorVerIdx );
				if( searchMajorVerIdx != indexByMajorVerIdx->end() ) {
					std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* mapMajorVerIdx = searchMajorVerIdx->second;
					if( mapMajorVerIdx != NULL ) {
						auto removalProbe = mapMajorVerIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapMajorVerIdx->end() ) {
							mapMajorVerIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntMinorVersionByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredMajorVersionId( keepObj->getRequiredMajorVersionId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByNameIdx->find( keyNameIdx );
				if( removalProbe != indexByNameIdx->end() ) {
					indexByNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfint::CFIntMinorVersionBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntMinorVersionObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntMinorVersionObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntMinorVersionByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByMajorVerIdx != NULL ) {
				static const std::string S_AMajorVerIdxObj( "aMajorVerIdxObj" );
				cfint::ICFIntMinorVersionObj* aMajorVerIdxObj =
					dynamic_cast<cfint::ICFIntMinorVersionObj*>( keepObj );
				if( aMajorVerIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AMajorVerIdxObj );
				}
				cfint::CFIntMinorVersionByMajorVerIdxKey keyMajorVerIdx;
				keyMajorVerIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyMajorVerIdx.setRequiredMajorVersionId( keepObj->getRequiredMajorVersionId() );
				auto searchIndexByMajorVerIdx = indexByMajorVerIdx->find( keyMajorVerIdx );
				if( searchIndexByMajorVerIdx != indexByMajorVerIdx->end() ) {
					std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* mapMajorVerIdx = searchIndexByMajorVerIdx->second;
					if( mapMajorVerIdx != NULL ) {
						mapMajorVerIdx->insert( std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >::value_type( *(keepObj->getPKey()), aMajorVerIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntMinorVersionObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntMinorVersionObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntMinorVersionByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredMajorVersionId( keepObj->getRequiredMajorVersionId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntMinorVersionByNameIdxKey, cfint::ICFIntMinorVersionObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allMinorVersion != NULL ) {
				allMinorVersion->insert( std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != NULL ) {
				static const std::string S_ATenantIdxObj( "aTenantIdxObj" );
				cfint::ICFIntMinorVersionObj* aTenantIdxObj =
					dynamic_cast<cfint::ICFIntMinorVersionObj*>( keepObj );
				if( aTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ATenantIdxObj );
				}
				cfint::CFIntMinorVersionByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* mapTenantIdx = searchIndexByTenantIdx->second;
					if( mapTenantIdx != NULL ) {
						mapTenantIdx->insert( std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >::value_type( *(keepObj->getPKey()), aTenantIdxObj ) );
					}
				}
			}

			if( indexByMajorVerIdx != NULL ) {
				static const std::string S_AMajorVerIdxObj( "aMajorVerIdxObj" );
				cfint::ICFIntMinorVersionObj* aMajorVerIdxObj =
					dynamic_cast<cfint::ICFIntMinorVersionObj*>( keepObj );
				if( aMajorVerIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AMajorVerIdxObj );
				}
				cfint::CFIntMinorVersionByMajorVerIdxKey keyMajorVerIdx;
				keyMajorVerIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyMajorVerIdx.setRequiredMajorVersionId( keepObj->getRequiredMajorVersionId() );
				auto searchIndexByMajorVerIdx = indexByMajorVerIdx->find( keyMajorVerIdx );
				if( searchIndexByMajorVerIdx != indexByMajorVerIdx->end() ) {
					std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* mapMajorVerIdx = searchIndexByMajorVerIdx->second;
					if( mapMajorVerIdx != NULL ) {
						mapMajorVerIdx->insert( std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >::value_type( *(keepObj->getPKey()), aMajorVerIdxObj ) );
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				static const std::string S_ANameIdxObj( "aNameIdxObj" );
				cfint::ICFIntMinorVersionObj* aNameIdxObj =
					dynamic_cast<cfint::ICFIntMinorVersionObj*>( keepObj );
				if( aNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ANameIdxObj );
				}
				cfint::CFIntMinorVersionByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyNameIdx.setRequiredMajorVersionId( keepObj->getRequiredMajorVersionId() );
				keyNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByNameIdx->insert( std::map< cfint::CFIntMinorVersionByNameIdxKey, cfint::ICFIntMinorVersionObj* >::value_type( keyNameIdx, aNameIdxObj ) );
			}

			if( allMinorVersion != NULL ) {
				allMinorVersion->insert( std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntMinorVersionTableObj::deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfint::ICFIntMinorVersionObj*> list;
		cfint::ICFIntMinorVersionObj* existingObj = readCachedMinorVersionByIdIdx( TenantId,
				Id );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntMinorVersionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntMinorVersionBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->reallyDeepDisposeMinorVersion( dynamic_cast<cfint::ICFIntMinorVersionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntMinorVersionTableObj::deepDisposeByTenantIdx( const int64_t TenantId ) {
		static const std::string S_ProcName( "deepDisposeByTenantIdx" );
		std::vector<cfint::ICFIntMinorVersionObj*> list;
		std::vector<cfint::ICFIntMinorVersionObj*> matchesFound = readCachedMinorVersionByTenantIdx( TenantId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntMinorVersionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntMinorVersionBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->reallyDeepDisposeMinorVersion( dynamic_cast<cfint::ICFIntMinorVersionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntMinorVersionTableObj::deepDisposeByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId ) {
		static const std::string S_ProcName( "deepDisposeByMajorVerIdx" );
		std::vector<cfint::ICFIntMinorVersionObj*> list;
		std::vector<cfint::ICFIntMinorVersionObj*> matchesFound = readCachedMinorVersionByMajorVerIdx( TenantId,
				MajorVersionId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntMinorVersionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntMinorVersionBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->reallyDeepDisposeMinorVersion( dynamic_cast<cfint::ICFIntMinorVersionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntMinorVersionTableObj::deepDisposeByNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByNameIdx" );
		std::vector<cfint::ICFIntMinorVersionObj*> list;
		cfint::ICFIntMinorVersionObj* existingObj = readCachedMinorVersionByNameIdx( TenantId,
				MajorVersionId,
				Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntMinorVersionObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntMinorVersionBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->reallyDeepDisposeMinorVersion( dynamic_cast<cfint::ICFIntMinorVersionObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntMinorVersionTableObj::reallyDeepDisposeMinorVersion( cfint::ICFIntMinorVersionObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeMinorVersion" );

		if( Obj == NULL ) {
			return;
		}

		cfint::ICFIntMinorVersionObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfint::CFIntMinorVersionBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->reallyDetachFromIndexesMinorVersion( dynamic_cast<cfint::ICFIntMinorVersionObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::createMinorVersion( cfint::ICFIntMinorVersionEditObj* Obj ) {
		static const std::string S_ProcName( "createMinorVersion" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntMinorVersionObj* obj = dynamic_cast<cfint::ICFIntMinorVersionObj*>( Obj->getOrig() );
		try {
			cfint::CFIntMinorVersionBuff* buff = dynamic_cast<cfint::CFIntMinorVersionBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->createMinorVersion(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfint::CFIntMinorVersionBuff*>( cloneable ) );
			obj = dynamic_cast<cfint::ICFIntMinorVersionObj*>( obj->realize() );
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

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::readMinorVersion( cfint::CFIntMinorVersionPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readMinorVersion" );
		cfint::ICFIntMinorVersionObj* obj = NULL;
		cfint::ICFIntMinorVersionObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntMinorVersionBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredTenantId(),
			pkey->getRequiredId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfint::ICFIntMinorVersionObj*>( obj->realize() );
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

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::lockMinorVersion( cfint::CFIntMinorVersionPKey* pkey ) {
		static const std::string S_ProcName( "lockMinorVersion" );
		cfint::ICFIntMinorVersionObj* locked = NULL;
		cfint::CFIntMinorVersionBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfint::ICFIntMinorVersionObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfint::ICFIntMinorVersionObj*> CFIntMinorVersionTableObj::readAllMinorVersion( bool forceRead ) {
		static const std::string S_ProcName( "readAllMinorVersion" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntMinorVersionObj* realized = NULL;
		if( forceRead || ( allMinorVersion == NULL ) ) {
			std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* map = new std::map<cfint::CFIntMinorVersionPKey,cfint::ICFIntMinorVersionObj*>();
			allMinorVersion = map;
			std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->readAllDerived( schema->getAuthorization() );
			cfint::CFIntMinorVersionBuff* buff = NULL;
			cfint::ICFIntMinorVersionObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfint::ICFIntMinorVersionObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allMinorVersion->insert( std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allMinorVersion->size();
		std::vector<cfint::ICFIntMinorVersionObj*> arr;
		auto valIter = allMinorVersion->begin();
		size_t idx = 0;
		while( valIter != allMinorVersion->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::readMinorVersionByIdIdx( const int64_t TenantId,
			const int64_t Id, bool forceRead )
	{
		static const std::string S_ProcName( "readMinorVersionByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntMinorVersionPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntMinorVersionObj* obj = readMinorVersion( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfint::ICFIntMinorVersionObj*> CFIntMinorVersionTableObj::readMinorVersionByTenantIdx( const int64_t TenantId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readMinorVersionByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntMinorVersionByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* dict;
		std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* oldDict;
		if( indexByTenantIdx == NULL ) {
			indexByTenantIdx = new std::map< cfint::CFIntMinorVersionByTenantIdxKey,
				std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>*>();
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
			dict = new std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>();
			cfint::ICFIntMinorVersionObj* obj;
			std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->readDerivedByTenantIdx( schema->getAuthorization(),
				TenantId );
			cfint::CFIntMinorVersionBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntMinorVersionObj* realized = dynamic_cast<cfint::ICFIntMinorVersionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByTenantIdx->erase( searchIndexByTenantIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByTenantIdx->insert( std::map< cfint::CFIntMinorVersionByTenantIdxKey,
				std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntMinorVersionObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfint::ICFIntMinorVersionObj*> CFIntMinorVersionTableObj::readMinorVersionByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readMinorVersionByMajorVerIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntMinorVersionByMajorVerIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredMajorVersionId( MajorVersionId );
		std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* dict;
		std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* oldDict;
		if( indexByMajorVerIdx == NULL ) {
			indexByMajorVerIdx = new std::map< cfint::CFIntMinorVersionByMajorVerIdxKey,
				std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>*>();
		}
		auto searchIndexByMajorVerIdx = indexByMajorVerIdx->find( key );
		if( searchIndexByMajorVerIdx != indexByMajorVerIdx->end() ) {
			oldDict = searchIndexByMajorVerIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>();
			cfint::ICFIntMinorVersionObj* obj;
			std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->readDerivedByMajorVerIdx( schema->getAuthorization(),
				TenantId,
				MajorVersionId );
			cfint::CFIntMinorVersionBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntMinorVersionObj* realized = dynamic_cast<cfint::ICFIntMinorVersionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByMajorVerIdx->erase( searchIndexByMajorVerIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByMajorVerIdx->insert( std::map< cfint::CFIntMinorVersionByMajorVerIdxKey,
				std::map< cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntMinorVersionObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::readMinorVersionByNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readMinorVersionByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntMinorVersionByNameIdxKey,
				cfint::ICFIntMinorVersionObj*>();
		}
		cfint::CFIntMinorVersionByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredMajorVersionId( MajorVersionId );
		key.setRequiredName( Name );
		cfint::ICFIntMinorVersionObj* obj = NULL;
		cfint::ICFIntMinorVersionObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntMinorVersionBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->readDerivedByNameIdx( schema->getAuthorization(),
				TenantId,
				MajorVersionId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntMinorVersionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntMinorVersionByNameIdxKey, cfint::ICFIntMinorVersionObj*>::value_type( key, dynamic_cast<cfint::ICFIntMinorVersionObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::readMinorVersionByLookupNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readMinorVersionByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntMinorVersionByNameIdxKey,
				cfint::ICFIntMinorVersionObj*>();
		}
		cfint::CFIntMinorVersionByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredMajorVersionId( MajorVersionId );
		key.setRequiredName( Name );
		cfint::ICFIntMinorVersionObj* obj = NULL;
		cfint::ICFIntMinorVersionObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByNameIdx = indexByNameIdx->find( key );
			if( searchIndexByNameIdx != indexByNameIdx->end() ) {
				obj = searchIndexByNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntMinorVersionBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->readDerivedByLookupNameIdx( schema->getAuthorization(),
				TenantId,
				MajorVersionId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::ICFIntMinorVersionObj*>( dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntMinorVersionObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByNameIdx->insert( std::map< cfint::CFIntMinorVersionByNameIdxKey, cfint::ICFIntMinorVersionObj*>::value_type( key, dynamic_cast<cfint::ICFIntMinorVersionObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::readCachedMinorVersion( cfint::CFIntMinorVersionPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readMinorVersion" );
		cfint::ICFIntMinorVersionObj* obj = NULL;
		cfint::ICFIntMinorVersionObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::readCachedMinorVersionByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readCachedMinorVersionByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntMinorVersionPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntMinorVersionObj* obj = readCachedMinorVersion( &pkey );
		return( obj );
	}

	std::vector<cfint::ICFIntMinorVersionObj*> CFIntMinorVersionTableObj::readCachedMinorVersionByTenantIdx( const int64_t TenantId )
	{
		static const std::string S_ProcName( "readCachedMinorVersionByTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntMinorVersionObj*> arr;
		cfint::CFIntMinorVersionByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* dict;
		if( indexByTenantIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByTenantIdx = indexByTenantIdx->find( key );
		if( searchIndexByTenantIdx != indexByTenantIdx->end() ) {
			dict = searchIndexByTenantIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntMinorVersionObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntMinorVersionObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntMinorVersionBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfint::ICFIntMinorVersionObj*> CFIntMinorVersionTableObj::readCachedMinorVersionByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId )
	{
		static const std::string S_ProcName( "readCachedMinorVersionByMajorVerIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntMinorVersionObj*> arr;
		cfint::CFIntMinorVersionByMajorVerIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredMajorVersionId( MajorVersionId );
		std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* dict;
		if( indexByMajorVerIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByMajorVerIdx = indexByMajorVerIdx->find( key );
		if( searchIndexByMajorVerIdx != indexByMajorVerIdx->end() ) {
			dict = searchIndexByMajorVerIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntMinorVersionObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntMinorVersionObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntMinorVersionBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::readCachedMinorVersionByNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedMinorVersionByNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntMinorVersionByNameIdxKey,
				cfint::ICFIntMinorVersionObj*>();
		}
		cfint::CFIntMinorVersionByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredMajorVersionId( MajorVersionId );
		key.setRequiredName( Name );
		cfint::ICFIntMinorVersionObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntMinorVersionBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::readCachedMinorVersionByLookupNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedMinorVersionByLookupNameIdx" );
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntMinorVersionByNameIdxKey,
				cfint::ICFIntMinorVersionObj*>();
		}
		cfint::CFIntMinorVersionByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredMajorVersionId( MajorVersionId );
		key.setRequiredName( Name );
		cfint::ICFIntMinorVersionObj* obj = NULL;
		cfint::ICFIntMinorVersionObj* realized = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			obj = searchIndexByNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntMinorVersionBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntMinorVersionObj* CFIntMinorVersionTableObj::updateMinorVersion( cfint::ICFIntMinorVersionEditObj* Obj ) {
		static const std::string S_ProcName( "updateMinorVersion" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntMinorVersionObj* obj = dynamic_cast<cfint::ICFIntMinorVersionObj*>( Obj->getOrig() );
		try {
			cfint::CFIntMinorVersionBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->updateMinorVersion( schema->getAuthorization(),
				dynamic_cast<cfint::CFIntMinorVersionBuff*>( Obj->getMinorVersionBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfint::ICFIntMinorVersionObj*>( dynamic_cast<cfint::CFIntMinorVersionTableObj*>( schema->getMinorVersionTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfint::ICFIntMinorVersionObj*>( obj->realize() );
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

	void CFIntMinorVersionTableObj::deleteMinorVersion( cfint::ICFIntMinorVersionEditObj* Obj ) {
		cfint::ICFIntMinorVersionObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->deleteMinorVersion( schema->getAuthorization(),
			obj->getMinorVersionBuff() );
		deepDisposeByIdIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
	}

	void CFIntMinorVersionTableObj::deleteMinorVersionByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		cfint::CFIntMinorVersionPKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntMinorVersionObj* obj = readMinorVersion( &pkey, true );
		if( obj != NULL ) {
			cfint::ICFIntMinorVersionEditObj* editObj = dynamic_cast<cfint::ICFIntMinorVersionEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfint::ICFIntMinorVersionEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntMinorVersionTableObj::deleteMinorVersionByTenantIdx( const int64_t TenantId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->deleteMinorVersionByTenantIdx( schema->getAuthorization(),
				TenantId );
		deepDisposeByTenantIdx( TenantId );
	}

	void CFIntMinorVersionTableObj::deleteMinorVersionByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->deleteMinorVersionByMajorVerIdx( schema->getAuthorization(),
				TenantId,
				MajorVersionId );
		deepDisposeByMajorVerIdx( TenantId,
			MajorVersionId );
	}

	void CFIntMinorVersionTableObj::deleteMinorVersionByNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name )
	{
		if( indexByNameIdx == NULL ) {
			indexByNameIdx = new std::map< cfint::CFIntMinorVersionByNameIdxKey,
				cfint::ICFIntMinorVersionObj*>();
		}
		cfint::CFIntMinorVersionByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredMajorVersionId( MajorVersionId );
		key.setRequiredName( Name );
		cfint::ICFIntMinorVersionObj* obj = NULL;
		auto searchIndexByNameIdx = indexByNameIdx->find( key );
		if( searchIndexByNameIdx != indexByNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->deleteMinorVersionByNameIdx( schema->getAuthorization(),
				TenantId,
				MajorVersionId,
				Name );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMinorVersion()->deleteMinorVersionByNameIdx( schema->getAuthorization(),
				TenantId,
				MajorVersionId,
				Name );
		}
		deepDisposeByNameIdx( TenantId,
			MajorVersionId,
			Name );
	}

	void CFIntMinorVersionTableObj::reallyDetachFromIndexesMinorVersion( cfint::ICFIntMinorVersionObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesMinorVersion" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntMinorVersionObj* obj = Obj;
		cfint::CFIntMinorVersionPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfint::ICFIntMinorVersionObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByTenantIdx != NULL ) {
				cfint::CFIntMinorVersionByTenantIdxKey keyTenantIdx;
				keyTenantIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				auto searchTenantIdx = indexByTenantIdx->find( keyTenantIdx );
				if( searchTenantIdx != indexByTenantIdx->end() ) {
					std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* mapTenantIdx = searchTenantIdx->second;
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

			if( indexByMajorVerIdx != NULL ) {
				cfint::CFIntMinorVersionByMajorVerIdxKey keyMajorVerIdx;
				keyMajorVerIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyMajorVerIdx.setRequiredMajorVersionId( obj->getRequiredMajorVersionId() );
				auto searchMajorVerIdx = indexByMajorVerIdx->find( keyMajorVerIdx );
				if( searchMajorVerIdx != indexByMajorVerIdx->end() ) {
					std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* mapMajorVerIdx = searchMajorVerIdx->second;
					if( mapMajorVerIdx != NULL ) {
						auto removalProbe = mapMajorVerIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapMajorVerIdx->end() ) {
							mapMajorVerIdx->erase( removalProbe );
							if( mapMajorVerIdx->empty() ) {
								delete mapMajorVerIdx;
								mapMajorVerIdx = NULL;
								indexByMajorVerIdx->erase( searchMajorVerIdx );
							}
						}
					}
				}
			}

			if( indexByNameIdx != NULL ) {
				cfint::CFIntMinorVersionByNameIdxKey keyNameIdx;
				keyNameIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyNameIdx.setRequiredMajorVersionId( obj->getRequiredMajorVersionId() );
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
