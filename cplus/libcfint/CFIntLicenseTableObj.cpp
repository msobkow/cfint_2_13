// Description: C++18 Table Object implementation for CFInt.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
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

	const std::string CFIntLicenseTableObj::CLASS_NAME( "CFIntLicenseTableObj" );
	const std::string CFIntLicenseTableObj::TABLE_NAME( "License" );
	const std::string CFIntLicenseTableObj::TABLE_DBNAME( "licn" );

	CFIntLicenseTableObj::CFIntLicenseTableObj() {
		schema = NULL;
		members = new std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>();
		allLicense = NULL;
		indexByLicnTenantIdx = new std::map< cfint::CFIntLicenseByLicnTenantIdxKey,
			std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>*>();
		indexByDomainIdx = new std::map< cfint::CFIntLicenseByDomainIdxKey,
			std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>*>();
		indexByUNameIdx = new std::map< cfint::CFIntLicenseByUNameIdxKey,
			cfint::ICFIntLicenseObj*>();
	}

	CFIntLicenseTableObj::CFIntLicenseTableObj( cfint::ICFIntSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>();
		allLicense = NULL;
		indexByLicnTenantIdx = new std::map< cfint::CFIntLicenseByLicnTenantIdxKey,
			std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>*>();
		indexByDomainIdx = new std::map< cfint::CFIntLicenseByDomainIdxKey,
			std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>*>();
		indexByUNameIdx = new std::map< cfint::CFIntLicenseByUNameIdxKey,
			cfint::ICFIntLicenseObj*>();
	}

	CFIntLicenseTableObj::~CFIntLicenseTableObj() {
		minimizeMemory();
		if( indexByLicnTenantIdx != NULL ) {
			delete indexByLicnTenantIdx;
			indexByLicnTenantIdx = NULL;
		}
		if( indexByDomainIdx != NULL ) {
			delete indexByDomainIdx;
			indexByDomainIdx = NULL;
		}
		if( indexByUNameIdx != NULL ) {
			delete indexByUNameIdx;
			indexByUNameIdx = NULL;
		}
		if( members != NULL ) {
			cfint::ICFIntLicenseObj* curMember;
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

	cfint::ICFIntSchemaObj* CFIntLicenseTableObj::getSchema() {
		return( schema );
	}

	void CFIntLicenseTableObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntLicenseTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntLicenseTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntLicenseTableObj::getObjQualifyingClassCode() {
		return( &cfsec::CFSecTenantBuff::CLASS_CODE );
	}


	void CFIntLicenseTableObj::minimizeMemory() {
		if( allLicense != NULL ) {
			allLicense->clear();
			delete allLicense;
			allLicense = NULL;
		}
		if( indexByLicnTenantIdx != NULL ) {
			std::map< cfint::CFIntLicenseByLicnTenantIdxKey,
				std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* >::iterator iterByLicnTenantIdx = indexByLicnTenantIdx->begin();
			std::map< cfint::CFIntLicenseByLicnTenantIdxKey,
				std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* >::iterator endByLicnTenantIdx = indexByLicnTenantIdx->end();
			std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* curByLicnTenantIdx = NULL;
			while( iterByLicnTenantIdx != endByLicnTenantIdx ) {
				curByLicnTenantIdx = iterByLicnTenantIdx->second;
				if( curByLicnTenantIdx != NULL ) {
					curByLicnTenantIdx->clear();
					delete curByLicnTenantIdx;
					curByLicnTenantIdx = NULL;
					iterByLicnTenantIdx->second = NULL;
				}
				iterByLicnTenantIdx ++;
			}
			indexByLicnTenantIdx->clear();
		}
		if( indexByDomainIdx != NULL ) {
			std::map< cfint::CFIntLicenseByDomainIdxKey,
				std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* >::iterator iterByDomainIdx = indexByDomainIdx->begin();
			std::map< cfint::CFIntLicenseByDomainIdxKey,
				std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* >::iterator endByDomainIdx = indexByDomainIdx->end();
			std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* curByDomainIdx = NULL;
			while( iterByDomainIdx != endByDomainIdx ) {
				curByDomainIdx = iterByDomainIdx->second;
				if( curByDomainIdx != NULL ) {
					curByDomainIdx->clear();
					delete curByDomainIdx;
					curByDomainIdx = NULL;
					iterByDomainIdx->second = NULL;
				}
				iterByDomainIdx ++;
			}
			indexByDomainIdx->clear();
		}
		if( indexByUNameIdx != NULL ) {
			indexByUNameIdx->clear();
		}
		if( members != NULL ) {
			cfint::ICFIntLicenseObj* cur = NULL;
			cfint::ICFIntLicenseEditObj* edit = NULL;
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

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::newInstance() {
		cfint::ICFIntLicenseObj* inst = dynamic_cast<cfint::ICFIntLicenseObj*>( new CFIntLicenseObj( schema ) );
		return( inst );
	}

	cfint::ICFIntLicenseEditObj* CFIntLicenseTableObj::newEditInstance( cfint::ICFIntLicenseObj* orig ) {
		cfint::ICFIntLicenseEditObj* edit = dynamic_cast<cfint::ICFIntLicenseEditObj*>( new CFIntLicenseEditObj( orig ));
		return( edit );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::realizeLicense( cfint::ICFIntLicenseObj* Obj ) {
		static const std::string S_ProcName( "realizeLicense" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntLicenseObj* obj = Obj;
		cfint::ICFIntLicenseObj* existingObj = NULL;
		cfint::CFIntLicensePKey* pkey = obj->getPKey();
		cfint::ICFIntLicenseObj* keepObj = NULL;
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
			if( indexByLicnTenantIdx != NULL ) {
				cfint::CFIntLicenseByLicnTenantIdxKey keyLicnTenantIdx;
				keyLicnTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchLicnTenantIdx = indexByLicnTenantIdx->find( keyLicnTenantIdx );
				if( searchLicnTenantIdx != indexByLicnTenantIdx->end() ) {
					std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* mapLicnTenantIdx = searchLicnTenantIdx->second;
					if( mapLicnTenantIdx != NULL ) {
						auto removalProbe = mapLicnTenantIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapLicnTenantIdx->end() ) {
							mapLicnTenantIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByDomainIdx != NULL ) {
				cfint::CFIntLicenseByDomainIdxKey keyDomainIdx;
				keyDomainIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyDomainIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				auto searchDomainIdx = indexByDomainIdx->find( keyDomainIdx );
				if( searchDomainIdx != indexByDomainIdx->end() ) {
					std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* mapDomainIdx = searchDomainIdx->second;
					if( mapDomainIdx != NULL ) {
						auto removalProbe = mapDomainIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapDomainIdx->end() ) {
							mapDomainIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				cfint::CFIntLicenseByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUNameIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByUNameIdx->find( keyUNameIdx );
				if( removalProbe != indexByUNameIdx->end() ) {
					indexByUNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfint::CFIntLicenseBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByLicnTenantIdx != NULL ) {
				static const std::string S_ALicnTenantIdxObj( "aLicnTenantIdxObj" );
				cfint::ICFIntLicenseObj* aLicnTenantIdxObj =
					dynamic_cast<cfint::ICFIntLicenseObj*>( keepObj );
				if( aLicnTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ALicnTenantIdxObj );
				}
				cfint::CFIntLicenseByLicnTenantIdxKey keyLicnTenantIdx;
				keyLicnTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByLicnTenantIdx = indexByLicnTenantIdx->find( keyLicnTenantIdx );
				if( searchIndexByLicnTenantIdx != indexByLicnTenantIdx->end() ) {
					std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* mapLicnTenantIdx = searchIndexByLicnTenantIdx->second;
					if( mapLicnTenantIdx != NULL ) {
						mapLicnTenantIdx->insert( std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >::value_type( *(keepObj->getPKey()), aLicnTenantIdxObj ) );
					}
				}
			}

			if( indexByDomainIdx != NULL ) {
				static const std::string S_ADomainIdxObj( "aDomainIdxObj" );
				cfint::ICFIntLicenseObj* aDomainIdxObj =
					dynamic_cast<cfint::ICFIntLicenseObj*>( keepObj );
				if( aDomainIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ADomainIdxObj );
				}
				cfint::CFIntLicenseByDomainIdxKey keyDomainIdx;
				keyDomainIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyDomainIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				auto searchIndexByDomainIdx = indexByDomainIdx->find( keyDomainIdx );
				if( searchIndexByDomainIdx != indexByDomainIdx->end() ) {
					std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* mapDomainIdx = searchIndexByDomainIdx->second;
					if( mapDomainIdx != NULL ) {
						mapDomainIdx->insert( std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >::value_type( *(keepObj->getPKey()), aDomainIdxObj ) );
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfint::ICFIntLicenseObj* aUNameIdxObj =
					dynamic_cast<cfint::ICFIntLicenseObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfint::CFIntLicenseByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUNameIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByUNameIdx->insert( std::map< cfint::CFIntLicenseByUNameIdxKey, cfint::ICFIntLicenseObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( allLicense != NULL ) {
				allLicense->insert( std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByLicnTenantIdx != NULL ) {
				static const std::string S_ALicnTenantIdxObj( "aLicnTenantIdxObj" );
				cfint::ICFIntLicenseObj* aLicnTenantIdxObj =
					dynamic_cast<cfint::ICFIntLicenseObj*>( keepObj );
				if( aLicnTenantIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ALicnTenantIdxObj );
				}
				cfint::CFIntLicenseByLicnTenantIdxKey keyLicnTenantIdx;
				keyLicnTenantIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				auto searchIndexByLicnTenantIdx = indexByLicnTenantIdx->find( keyLicnTenantIdx );
				if( searchIndexByLicnTenantIdx != indexByLicnTenantIdx->end() ) {
					std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* mapLicnTenantIdx = searchIndexByLicnTenantIdx->second;
					if( mapLicnTenantIdx != NULL ) {
						mapLicnTenantIdx->insert( std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >::value_type( *(keepObj->getPKey()), aLicnTenantIdxObj ) );
					}
				}
			}

			if( indexByDomainIdx != NULL ) {
				static const std::string S_ADomainIdxObj( "aDomainIdxObj" );
				cfint::ICFIntLicenseObj* aDomainIdxObj =
					dynamic_cast<cfint::ICFIntLicenseObj*>( keepObj );
				if( aDomainIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ADomainIdxObj );
				}
				cfint::CFIntLicenseByDomainIdxKey keyDomainIdx;
				keyDomainIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyDomainIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				auto searchIndexByDomainIdx = indexByDomainIdx->find( keyDomainIdx );
				if( searchIndexByDomainIdx != indexByDomainIdx->end() ) {
					std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* mapDomainIdx = searchIndexByDomainIdx->second;
					if( mapDomainIdx != NULL ) {
						mapDomainIdx->insert( std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >::value_type( *(keepObj->getPKey()), aDomainIdxObj ) );
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfint::ICFIntLicenseObj* aUNameIdxObj =
					dynamic_cast<cfint::ICFIntLicenseObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfint::CFIntLicenseByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredTenantId( keepObj->getRequiredTenantId() );
				keyUNameIdx.setRequiredTopDomainId( keepObj->getRequiredTopDomainId() );
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByUNameIdx->insert( std::map< cfint::CFIntLicenseByUNameIdxKey, cfint::ICFIntLicenseObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( allLicense != NULL ) {
				allLicense->insert( std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntLicenseTableObj::deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfint::ICFIntLicenseObj*> list;
		cfint::ICFIntLicenseObj* existingObj = readCachedLicenseByIdIdx( TenantId,
				Id );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntLicenseObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntLicenseBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->reallyDeepDisposeLicense( dynamic_cast<cfint::ICFIntLicenseObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntLicenseTableObj::deepDisposeByLicnTenantIdx( const int64_t TenantId ) {
		static const std::string S_ProcName( "deepDisposeByLicnTenantIdx" );
		std::vector<cfint::ICFIntLicenseObj*> list;
		std::vector<cfint::ICFIntLicenseObj*> matchesFound = readCachedLicenseByLicnTenantIdx( TenantId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntLicenseObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntLicenseBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->reallyDeepDisposeLicense( dynamic_cast<cfint::ICFIntLicenseObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntLicenseTableObj::deepDisposeByDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId ) {
		static const std::string S_ProcName( "deepDisposeByDomainIdx" );
		std::vector<cfint::ICFIntLicenseObj*> list;
		std::vector<cfint::ICFIntLicenseObj*> matchesFound = readCachedLicenseByDomainIdx( TenantId,
				TopDomainId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntLicenseObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntLicenseBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->reallyDeepDisposeLicense( dynamic_cast<cfint::ICFIntLicenseObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntLicenseTableObj::deepDisposeByUNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByUNameIdx" );
		std::vector<cfint::ICFIntLicenseObj*> list;
		cfint::ICFIntLicenseObj* existingObj = readCachedLicenseByUNameIdx( TenantId,
				TopDomainId,
				Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntLicenseObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntLicenseBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->reallyDeepDisposeLicense( dynamic_cast<cfint::ICFIntLicenseObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntLicenseTableObj::reallyDeepDisposeLicense( cfint::ICFIntLicenseObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeLicense" );

		if( Obj == NULL ) {
			return;
		}

		cfint::ICFIntLicenseObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfint::CFIntLicenseBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->reallyDetachFromIndexesLicense( dynamic_cast<cfint::ICFIntLicenseObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::createLicense( cfint::ICFIntLicenseEditObj* Obj ) {
		static const std::string S_ProcName( "createLicense" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntLicenseObj* obj = dynamic_cast<cfint::ICFIntLicenseObj*>( Obj->getOrig() );
		try {
			cfint::CFIntLicenseBuff* buff = dynamic_cast<cfint::CFIntLicenseBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->createLicense(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfint::CFIntLicenseBuff*>( cloneable ) );
			obj = dynamic_cast<cfint::ICFIntLicenseObj*>( obj->realize() );
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

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::readLicense( cfint::CFIntLicensePKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readLicense" );
		cfint::ICFIntLicenseObj* obj = NULL;
		cfint::ICFIntLicenseObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntLicenseBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredTenantId(),
			pkey->getRequiredId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfint::ICFIntLicenseObj*>( obj->realize() );
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

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::lockLicense( cfint::CFIntLicensePKey* pkey ) {
		static const std::string S_ProcName( "lockLicense" );
		cfint::ICFIntLicenseObj* locked = NULL;
		cfint::CFIntLicenseBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfint::ICFIntLicenseObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfint::ICFIntLicenseObj*> CFIntLicenseTableObj::readAllLicense( bool forceRead ) {
		static const std::string S_ProcName( "readAllLicense" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntLicenseObj* realized = NULL;
		if( forceRead || ( allLicense == NULL ) ) {
			std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* map = new std::map<cfint::CFIntLicensePKey,cfint::ICFIntLicenseObj*>();
			allLicense = map;
			std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->readAllDerived( schema->getAuthorization() );
			cfint::CFIntLicenseBuff* buff = NULL;
			cfint::ICFIntLicenseObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfint::ICFIntLicenseObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allLicense->insert( std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allLicense->size();
		std::vector<cfint::ICFIntLicenseObj*> arr;
		auto valIter = allLicense->begin();
		size_t idx = 0;
		while( valIter != allLicense->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::readLicenseByIdIdx( const int64_t TenantId,
			const int64_t Id, bool forceRead )
	{
		static const std::string S_ProcName( "readLicenseByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntLicensePKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntLicenseObj* obj = readLicense( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfint::ICFIntLicenseObj*> CFIntLicenseTableObj::readLicenseByLicnTenantIdx( const int64_t TenantId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readLicenseByLicnTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntLicenseByLicnTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* dict;
		std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* oldDict;
		if( indexByLicnTenantIdx == NULL ) {
			indexByLicnTenantIdx = new std::map< cfint::CFIntLicenseByLicnTenantIdxKey,
				std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>*>();
		}
		auto searchIndexByLicnTenantIdx = indexByLicnTenantIdx->find( key );
		if( searchIndexByLicnTenantIdx != indexByLicnTenantIdx->end() ) {
			oldDict = searchIndexByLicnTenantIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>();
			cfint::ICFIntLicenseObj* obj;
			std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->readDerivedByLicnTenantIdx( schema->getAuthorization(),
				TenantId );
			cfint::CFIntLicenseBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntLicenseObj* realized = dynamic_cast<cfint::ICFIntLicenseObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByLicnTenantIdx->erase( searchIndexByLicnTenantIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByLicnTenantIdx->insert( std::map< cfint::CFIntLicenseByLicnTenantIdxKey,
				std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntLicenseObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfint::ICFIntLicenseObj*> CFIntLicenseTableObj::readLicenseByDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readLicenseByDomainIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntLicenseByDomainIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* dict;
		std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* oldDict;
		if( indexByDomainIdx == NULL ) {
			indexByDomainIdx = new std::map< cfint::CFIntLicenseByDomainIdxKey,
				std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>*>();
		}
		auto searchIndexByDomainIdx = indexByDomainIdx->find( key );
		if( searchIndexByDomainIdx != indexByDomainIdx->end() ) {
			oldDict = searchIndexByDomainIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>();
			cfint::ICFIntLicenseObj* obj;
			std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->readDerivedByDomainIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId );
			cfint::CFIntLicenseBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntLicenseObj* realized = dynamic_cast<cfint::ICFIntLicenseObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByDomainIdx->erase( searchIndexByDomainIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByDomainIdx->insert( std::map< cfint::CFIntLicenseByDomainIdxKey,
				std::map< cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntLicenseObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::readLicenseByUNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readLicenseByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntLicenseByUNameIdxKey,
				cfint::ICFIntLicenseObj*>();
		}
		cfint::CFIntLicenseByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::ICFIntLicenseObj* obj = NULL;
		cfint::ICFIntLicenseObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntLicenseBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->readDerivedByUNameIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntLicenseObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfint::CFIntLicenseByUNameIdxKey, cfint::ICFIntLicenseObj*>::value_type( key, dynamic_cast<cfint::ICFIntLicenseObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::readLicenseByLookupUNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readLicenseByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntLicenseByUNameIdxKey,
				cfint::ICFIntLicenseObj*>();
		}
		cfint::CFIntLicenseByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::ICFIntLicenseObj* obj = NULL;
		cfint::ICFIntLicenseObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				obj = searchIndexByUNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntLicenseBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->readDerivedByLookupUNameIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId,
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::ICFIntLicenseObj*>( dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntLicenseObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfint::CFIntLicenseByUNameIdxKey, cfint::ICFIntLicenseObj*>::value_type( key, dynamic_cast<cfint::ICFIntLicenseObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::readCachedLicense( cfint::CFIntLicensePKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readLicense" );
		cfint::ICFIntLicenseObj* obj = NULL;
		cfint::ICFIntLicenseObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::readCachedLicenseByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readCachedLicenseByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntLicensePKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntLicenseObj* obj = readCachedLicense( &pkey );
		return( obj );
	}

	std::vector<cfint::ICFIntLicenseObj*> CFIntLicenseTableObj::readCachedLicenseByLicnTenantIdx( const int64_t TenantId )
	{
		static const std::string S_ProcName( "readCachedLicenseByLicnTenantIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntLicenseObj*> arr;
		cfint::CFIntLicenseByLicnTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* dict;
		if( indexByLicnTenantIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByLicnTenantIdx = indexByLicnTenantIdx->find( key );
		if( searchIndexByLicnTenantIdx != indexByLicnTenantIdx->end() ) {
			dict = searchIndexByLicnTenantIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntLicenseObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntLicenseObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntLicenseBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfint::ICFIntLicenseObj*> CFIntLicenseTableObj::readCachedLicenseByDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId )
	{
		static const std::string S_ProcName( "readCachedLicenseByDomainIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntLicenseObj*> arr;
		cfint::CFIntLicenseByDomainIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* dict;
		if( indexByDomainIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByDomainIdx = indexByDomainIdx->find( key );
		if( searchIndexByDomainIdx != indexByDomainIdx->end() ) {
			dict = searchIndexByDomainIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntLicenseObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntLicenseObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntLicenseBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::readCachedLicenseByUNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedLicenseByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntLicenseByUNameIdxKey,
				cfint::ICFIntLicenseObj*>();
		}
		cfint::CFIntLicenseByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::ICFIntLicenseObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntLicenseBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::readCachedLicenseByLookupUNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedLicenseByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntLicenseByUNameIdxKey,
				cfint::ICFIntLicenseObj*>();
		}
		cfint::CFIntLicenseByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::ICFIntLicenseObj* obj = NULL;
		cfint::ICFIntLicenseObj* realized = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntLicenseBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseTableObj::updateLicense( cfint::ICFIntLicenseEditObj* Obj ) {
		static const std::string S_ProcName( "updateLicense" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntLicenseObj* obj = dynamic_cast<cfint::ICFIntLicenseObj*>( Obj->getOrig() );
		try {
			cfint::CFIntLicenseBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->updateLicense( schema->getAuthorization(),
				dynamic_cast<cfint::CFIntLicenseBuff*>( Obj->getLicenseBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfint::ICFIntLicenseObj*>( dynamic_cast<cfint::CFIntLicenseTableObj*>( schema->getLicenseTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfint::ICFIntLicenseObj*>( obj->realize() );
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

	void CFIntLicenseTableObj::deleteLicense( cfint::ICFIntLicenseEditObj* Obj ) {
		cfint::ICFIntLicenseObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->deleteLicense( schema->getAuthorization(),
			obj->getLicenseBuff() );
		deepDisposeByIdIdx( obj->getRequiredTenantId(),
			obj->getRequiredId() );
	}

	void CFIntLicenseTableObj::deleteLicenseByIdIdx( const int64_t TenantId,
			const int64_t Id )
	{
		cfint::CFIntLicensePKey pkey;
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		cfint::ICFIntLicenseObj* obj = readLicense( &pkey, true );
		if( obj != NULL ) {
			cfint::ICFIntLicenseEditObj* editObj = dynamic_cast<cfint::ICFIntLicenseEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfint::ICFIntLicenseEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntLicenseTableObj::deleteLicenseByLicnTenantIdx( const int64_t TenantId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->deleteLicenseByLicnTenantIdx( schema->getAuthorization(),
				TenantId );
		deepDisposeByLicnTenantIdx( TenantId );
	}

	void CFIntLicenseTableObj::deleteLicenseByDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->deleteLicenseByDomainIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId );
		deepDisposeByDomainIdx( TenantId,
			TopDomainId );
	}

	void CFIntLicenseTableObj::deleteLicenseByUNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name )
	{
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntLicenseByUNameIdxKey,
				cfint::ICFIntLicenseObj*>();
		}
		cfint::CFIntLicenseByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::ICFIntLicenseObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->deleteLicenseByUNameIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId,
				Name );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableLicense()->deleteLicenseByUNameIdx( schema->getAuthorization(),
				TenantId,
				TopDomainId,
				Name );
		}
		deepDisposeByUNameIdx( TenantId,
			TopDomainId,
			Name );
	}

	void CFIntLicenseTableObj::reallyDetachFromIndexesLicense( cfint::ICFIntLicenseObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesLicense" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntLicenseObj* obj = Obj;
		cfint::CFIntLicensePKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfint::ICFIntLicenseObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByLicnTenantIdx != NULL ) {
				cfint::CFIntLicenseByLicnTenantIdxKey keyLicnTenantIdx;
				keyLicnTenantIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				auto searchLicnTenantIdx = indexByLicnTenantIdx->find( keyLicnTenantIdx );
				if( searchLicnTenantIdx != indexByLicnTenantIdx->end() ) {
					std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* mapLicnTenantIdx = searchLicnTenantIdx->second;
					if( mapLicnTenantIdx != NULL ) {
						auto removalProbe = mapLicnTenantIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapLicnTenantIdx->end() ) {
							mapLicnTenantIdx->erase( removalProbe );
							if( mapLicnTenantIdx->empty() ) {
								delete mapLicnTenantIdx;
								mapLicnTenantIdx = NULL;
								indexByLicnTenantIdx->erase( searchLicnTenantIdx );
							}
						}
					}
				}
			}

			if( indexByDomainIdx != NULL ) {
				cfint::CFIntLicenseByDomainIdxKey keyDomainIdx;
				keyDomainIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyDomainIdx.setRequiredTopDomainId( obj->getRequiredTopDomainId() );
				auto searchDomainIdx = indexByDomainIdx->find( keyDomainIdx );
				if( searchDomainIdx != indexByDomainIdx->end() ) {
					std::map<cfint::CFIntLicensePKey, cfint::ICFIntLicenseObj*>* mapDomainIdx = searchDomainIdx->second;
					if( mapDomainIdx != NULL ) {
						auto removalProbe = mapDomainIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapDomainIdx->end() ) {
							mapDomainIdx->erase( removalProbe );
							if( mapDomainIdx->empty() ) {
								delete mapDomainIdx;
								mapDomainIdx = NULL;
								indexByDomainIdx->erase( searchDomainIdx );
							}
						}
					}
				}
			}

			if( indexByUNameIdx != NULL ) {
				cfint::CFIntLicenseByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredTenantId( obj->getRequiredTenantId() );
				keyUNameIdx.setRequiredTopDomainId( obj->getRequiredTopDomainId() );
				keyUNameIdx.setRequiredName( obj->getRequiredName() );
				auto removalProbe = indexByUNameIdx->find( keyUNameIdx );
				if( removalProbe != indexByUNameIdx->end() ) {
					indexByUNameIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
