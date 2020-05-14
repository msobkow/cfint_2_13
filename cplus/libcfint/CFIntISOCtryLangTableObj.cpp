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

	const std::string CFIntISOCtryLangTableObj::CLASS_NAME( "CFIntISOCtryLangTableObj" );
	const std::string CFIntISOCtryLangTableObj::TABLE_NAME( "ISOCtryLang" );
	const std::string CFIntISOCtryLangTableObj::TABLE_DBNAME( "iso_cntrylng" );

	CFIntISOCtryLangTableObj::CFIntISOCtryLangTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>();
		allISOCtryLang = NULL;
		indexByCtryIdx = new std::map< cfsec::CFSecISOCtryLangByCtryIdxKey,
			std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>*>();
		indexByLangIdx = new std::map< cfsec::CFSecISOCtryLangByLangIdxKey,
			std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>*>();
	}

	CFIntISOCtryLangTableObj::CFIntISOCtryLangTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>();
		allISOCtryLang = NULL;
		indexByCtryIdx = new std::map< cfsec::CFSecISOCtryLangByCtryIdxKey,
			std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>*>();
		indexByLangIdx = new std::map< cfsec::CFSecISOCtryLangByLangIdxKey,
			std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>*>();
	}

	CFIntISOCtryLangTableObj::~CFIntISOCtryLangTableObj() {
		minimizeMemory();
		if( indexByCtryIdx != NULL ) {
			delete indexByCtryIdx;
			indexByCtryIdx = NULL;
		}
		if( indexByLangIdx != NULL ) {
			delete indexByLangIdx;
			indexByLangIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecISOCtryLangObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntISOCtryLangTableObj::getSchema() {
		return( schema );
	}

	void CFIntISOCtryLangTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntISOCtryLangTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntISOCtryLangTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntISOCtryLangTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntISOCtryLangTableObj::minimizeMemory() {
		if( allISOCtryLang != NULL ) {
			allISOCtryLang->clear();
			delete allISOCtryLang;
			allISOCtryLang = NULL;
		}
		if( indexByCtryIdx != NULL ) {
			std::map< cfsec::CFSecISOCtryLangByCtryIdxKey,
				std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* >::iterator iterByCtryIdx = indexByCtryIdx->begin();
			std::map< cfsec::CFSecISOCtryLangByCtryIdxKey,
				std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* >::iterator endByCtryIdx = indexByCtryIdx->end();
			std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* curByCtryIdx = NULL;
			while( iterByCtryIdx != endByCtryIdx ) {
				curByCtryIdx = iterByCtryIdx->second;
				if( curByCtryIdx != NULL ) {
					curByCtryIdx->clear();
					delete curByCtryIdx;
					curByCtryIdx = NULL;
					iterByCtryIdx->second = NULL;
				}
				iterByCtryIdx ++;
			}
			indexByCtryIdx->clear();
		}
		if( indexByLangIdx != NULL ) {
			std::map< cfsec::CFSecISOCtryLangByLangIdxKey,
				std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* >::iterator iterByLangIdx = indexByLangIdx->begin();
			std::map< cfsec::CFSecISOCtryLangByLangIdxKey,
				std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* >::iterator endByLangIdx = indexByLangIdx->end();
			std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* curByLangIdx = NULL;
			while( iterByLangIdx != endByLangIdx ) {
				curByLangIdx = iterByLangIdx->second;
				if( curByLangIdx != NULL ) {
					curByLangIdx->clear();
					delete curByLangIdx;
					curByLangIdx = NULL;
					iterByLangIdx->second = NULL;
				}
				iterByLangIdx ++;
			}
			indexByLangIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecISOCtryLangObj* cur = NULL;
			cfsec::ICFSecISOCtryLangEditObj* edit = NULL;
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

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangTableObj::newInstance() {
		cfsec::ICFSecISOCtryLangObj* inst = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( new CFIntISOCtryLangObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecISOCtryLangEditObj* CFIntISOCtryLangTableObj::newEditInstance( cfsec::ICFSecISOCtryLangObj* orig ) {
		cfsec::ICFSecISOCtryLangEditObj* edit = dynamic_cast<cfsec::ICFSecISOCtryLangEditObj*>( new CFIntISOCtryLangEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangTableObj::realizeISOCtryLang( cfsec::ICFSecISOCtryLangObj* Obj ) {
		static const std::string S_ProcName( "realizeISOCtryLang" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOCtryLangObj* obj = Obj;
		cfsec::ICFSecISOCtryLangObj* existingObj = NULL;
		cfsec::CFSecISOCtryLangPKey* pkey = obj->getPKey();
		cfsec::ICFSecISOCtryLangObj* keepObj = NULL;
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
			if( indexByCtryIdx != NULL ) {
				cfsec::CFSecISOCtryLangByCtryIdxKey keyCtryIdx;
				keyCtryIdx.setRequiredISOCtryId( keepObj->getRequiredISOCtryId() );
				auto searchCtryIdx = indexByCtryIdx->find( keyCtryIdx );
				if( searchCtryIdx != indexByCtryIdx->end() ) {
					std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* mapCtryIdx = searchCtryIdx->second;
					if( mapCtryIdx != NULL ) {
						auto removalProbe = mapCtryIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapCtryIdx->end() ) {
							mapCtryIdx->erase( removalProbe );
						}
					}
				}
			}

			if( indexByLangIdx != NULL ) {
				cfsec::CFSecISOCtryLangByLangIdxKey keyLangIdx;
				keyLangIdx.setRequiredISOLangId( keepObj->getRequiredISOLangId() );
				auto searchLangIdx = indexByLangIdx->find( keyLangIdx );
				if( searchLangIdx != indexByLangIdx->end() ) {
					std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* mapLangIdx = searchLangIdx->second;
					if( mapLangIdx != NULL ) {
						auto removalProbe = mapLangIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapLangIdx->end() ) {
							mapLangIdx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByCtryIdx != NULL ) {
				static const std::string S_ACtryIdxObj( "aCtryIdxObj" );
				cfsec::ICFSecISOCtryLangObj* aCtryIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( keepObj );
				if( aCtryIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACtryIdxObj );
				}
				cfsec::CFSecISOCtryLangByCtryIdxKey keyCtryIdx;
				keyCtryIdx.setRequiredISOCtryId( keepObj->getRequiredISOCtryId() );
				auto searchIndexByCtryIdx = indexByCtryIdx->find( keyCtryIdx );
				if( searchIndexByCtryIdx != indexByCtryIdx->end() ) {
					std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* mapCtryIdx = searchIndexByCtryIdx->second;
					if( mapCtryIdx != NULL ) {
						mapCtryIdx->insert( std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >::value_type( *(keepObj->getPKey()), aCtryIdxObj ) );
					}
				}
			}

			if( indexByLangIdx != NULL ) {
				static const std::string S_ALangIdxObj( "aLangIdxObj" );
				cfsec::ICFSecISOCtryLangObj* aLangIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( keepObj );
				if( aLangIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ALangIdxObj );
				}
				cfsec::CFSecISOCtryLangByLangIdxKey keyLangIdx;
				keyLangIdx.setRequiredISOLangId( keepObj->getRequiredISOLangId() );
				auto searchIndexByLangIdx = indexByLangIdx->find( keyLangIdx );
				if( searchIndexByLangIdx != indexByLangIdx->end() ) {
					std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* mapLangIdx = searchIndexByLangIdx->second;
					if( mapLangIdx != NULL ) {
						mapLangIdx->insert( std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >::value_type( *(keepObj->getPKey()), aLangIdxObj ) );
					}
				}
			}

			if( allISOCtryLang != NULL ) {
				allISOCtryLang->insert( std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByCtryIdx != NULL ) {
				static const std::string S_ACtryIdxObj( "aCtryIdxObj" );
				cfsec::ICFSecISOCtryLangObj* aCtryIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( keepObj );
				if( aCtryIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACtryIdxObj );
				}
				cfsec::CFSecISOCtryLangByCtryIdxKey keyCtryIdx;
				keyCtryIdx.setRequiredISOCtryId( keepObj->getRequiredISOCtryId() );
				auto searchIndexByCtryIdx = indexByCtryIdx->find( keyCtryIdx );
				if( searchIndexByCtryIdx != indexByCtryIdx->end() ) {
					std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* mapCtryIdx = searchIndexByCtryIdx->second;
					if( mapCtryIdx != NULL ) {
						mapCtryIdx->insert( std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >::value_type( *(keepObj->getPKey()), aCtryIdxObj ) );
					}
				}
			}

			if( indexByLangIdx != NULL ) {
				static const std::string S_ALangIdxObj( "aLangIdxObj" );
				cfsec::ICFSecISOCtryLangObj* aLangIdxObj =
					dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( keepObj );
				if( aLangIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ALangIdxObj );
				}
				cfsec::CFSecISOCtryLangByLangIdxKey keyLangIdx;
				keyLangIdx.setRequiredISOLangId( keepObj->getRequiredISOLangId() );
				auto searchIndexByLangIdx = indexByLangIdx->find( keyLangIdx );
				if( searchIndexByLangIdx != indexByLangIdx->end() ) {
					std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* mapLangIdx = searchIndexByLangIdx->second;
					if( mapLangIdx != NULL ) {
						mapLangIdx->insert( std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >::value_type( *(keepObj->getPKey()), aLangIdxObj ) );
					}
				}
			}

			if( allISOCtryLang != NULL ) {
				allISOCtryLang->insert( std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntISOCtryLangTableObj::deepDisposeByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOLangId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecISOCtryLangObj*> list;
		cfsec::ICFSecISOCtryLangObj* existingObj = readCachedISOCtryLangByIdIdx( ISOCtryId,
				ISOLangId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOCtryLangObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->reallyDeepDisposeISOCtryLang( dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOCtryLangTableObj::deepDisposeByCtryIdx( const int16_t ISOCtryId ) {
		static const std::string S_ProcName( "deepDisposeByCtryIdx" );
		std::vector<cfsec::ICFSecISOCtryLangObj*> list;
		std::vector<cfsec::ICFSecISOCtryLangObj*> matchesFound = readCachedISOCtryLangByCtryIdx( ISOCtryId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecISOCtryLangObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->reallyDeepDisposeISOCtryLang( dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOCtryLangTableObj::deepDisposeByLangIdx( const int16_t ISOLangId ) {
		static const std::string S_ProcName( "deepDisposeByLangIdx" );
		std::vector<cfsec::ICFSecISOCtryLangObj*> list;
		std::vector<cfsec::ICFSecISOCtryLangObj*> matchesFound = readCachedISOCtryLangByLangIdx( ISOLangId );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecISOCtryLangObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->reallyDeepDisposeISOCtryLang( dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOCtryLangTableObj::reallyDeepDisposeISOCtryLang( cfsec::ICFSecISOCtryLangObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeISOCtryLang" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecISOCtryLangObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecISOCtryLangBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->reallyDetachFromIndexesISOCtryLang( dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangTableObj::createISOCtryLang( cfsec::ICFSecISOCtryLangEditObj* Obj ) {
		static const std::string S_ProcName( "createISOCtryLang" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCtryLangObj* obj = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOCtryLangBuff* buff = dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCtryLang()->createISOCtryLang(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( obj->realize() );
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

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangTableObj::readISOCtryLang( cfsec::CFSecISOCtryLangPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOCtryLang" );
		cfsec::ICFSecISOCtryLangObj* obj = NULL;
		cfsec::ICFSecISOCtryLangObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCtryLangBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCtryLang()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredISOCtryId(),
			pkey->getRequiredISOLangId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( obj->realize() );
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

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangTableObj::lockISOCtryLang( cfsec::CFSecISOCtryLangPKey* pkey ) {
		static const std::string S_ProcName( "lockISOCtryLang" );
		cfsec::ICFSecISOCtryLangObj* locked = NULL;
		cfsec::CFSecISOCtryLangBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCtryLang()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecISOCtryLangObj*> CFIntISOCtryLangTableObj::readAllISOCtryLang( bool forceRead ) {
		static const std::string S_ProcName( "readAllISOCtryLang" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCtryLangObj* realized = NULL;
		if( forceRead || ( allISOCtryLang == NULL ) ) {
			std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* map = new std::map<cfsec::CFSecISOCtryLangPKey,cfsec::ICFSecISOCtryLangObj*>();
			allISOCtryLang = map;
			std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCtryLang()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecISOCtryLangBuff* buff = NULL;
			cfsec::ICFSecISOCtryLangObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allISOCtryLang->insert( std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allISOCtryLang->size();
		std::vector<cfsec::ICFSecISOCtryLangObj*> arr;
		auto valIter = allISOCtryLang->begin();
		size_t idx = 0;
		while( valIter != allISOCtryLang->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangTableObj::readISOCtryLangByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOLangId, bool forceRead )
	{
		static const std::string S_ProcName( "readISOCtryLangByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCtryLangPKey pkey;
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOLangId( ISOLangId );
		cfsec::ICFSecISOCtryLangObj* obj = readISOCtryLang( &pkey, forceRead );
		return( obj );
	}

	std::vector<cfsec::ICFSecISOCtryLangObj*> CFIntISOCtryLangTableObj::readISOCtryLangByCtryIdx( const int16_t ISOCtryId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readISOCtryLangByCtryIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCtryLangByCtryIdxKey key;
		key.setRequiredISOCtryId( ISOCtryId );
		std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* dict;
		std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* oldDict;
		if( indexByCtryIdx == NULL ) {
			indexByCtryIdx = new std::map< cfsec::CFSecISOCtryLangByCtryIdxKey,
				std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>*>();
		}
		auto searchIndexByCtryIdx = indexByCtryIdx->find( key );
		if( searchIndexByCtryIdx != indexByCtryIdx->end() ) {
			oldDict = searchIndexByCtryIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>();
			cfsec::ICFSecISOCtryLangObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCtryLang()->readDerivedByCtryIdx( schema->getAuthorization(),
				ISOCtryId );
			cfsec::CFSecISOCtryLangBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecISOCtryLangObj* realized = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByCtryIdx->erase( searchIndexByCtryIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByCtryIdx->insert( std::map< cfsec::CFSecISOCtryLangByCtryIdxKey,
				std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecISOCtryLangObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecISOCtryLangObj*> CFIntISOCtryLangTableObj::readISOCtryLangByLangIdx( const int16_t ISOLangId,
		bool forceRead )
	{
		static const std::string S_ProcName( "readISOCtryLangByLangIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCtryLangByLangIdxKey key;
		key.setRequiredISOLangId( ISOLangId );
		std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* dict;
		std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* oldDict;
		if( indexByLangIdx == NULL ) {
			indexByLangIdx = new std::map< cfsec::CFSecISOCtryLangByLangIdxKey,
				std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>*>();
		}
		auto searchIndexByLangIdx = indexByLangIdx->find( key );
		if( searchIndexByLangIdx != indexByLangIdx->end() ) {
			oldDict = searchIndexByLangIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>();
			cfsec::ICFSecISOCtryLangObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecISOCtryLangBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCtryLang()->readDerivedByLangIdx( schema->getAuthorization(),
				ISOLangId );
			cfsec::CFSecISOCtryLangBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecISOCtryLangObj* realized = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByLangIdx->erase( searchIndexByLangIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByLangIdx->insert( std::map< cfsec::CFSecISOCtryLangByLangIdxKey,
				std::map< cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecISOCtryLangObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangTableObj::readCachedISOCtryLang( cfsec::CFSecISOCtryLangPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOCtryLang" );
		cfsec::ICFSecISOCtryLangObj* obj = NULL;
		cfsec::ICFSecISOCtryLangObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangTableObj::readCachedISOCtryLangByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOLangId )
	{
		static const std::string S_ProcName( "readCachedISOCtryLangByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCtryLangPKey pkey;
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOLangId( ISOLangId );
		cfsec::ICFSecISOCtryLangObj* obj = readCachedISOCtryLang( &pkey );
		return( obj );
	}

	std::vector<cfsec::ICFSecISOCtryLangObj*> CFIntISOCtryLangTableObj::readCachedISOCtryLangByCtryIdx( const int16_t ISOCtryId )
	{
		static const std::string S_ProcName( "readCachedISOCtryLangByCtryIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecISOCtryLangObj*> arr;
		cfsec::CFSecISOCtryLangByCtryIdxKey key;
		key.setRequiredISOCtryId( ISOCtryId );
		std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* dict;
		if( indexByCtryIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByCtryIdx = indexByCtryIdx->find( key );
		if( searchIndexByCtryIdx != indexByCtryIdx->end() ) {
			dict = searchIndexByCtryIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecISOCtryLangObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecISOCtryLangObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	std::vector<cfsec::ICFSecISOCtryLangObj*> CFIntISOCtryLangTableObj::readCachedISOCtryLangByLangIdx( const int16_t ISOLangId )
	{
		static const std::string S_ProcName( "readCachedISOCtryLangByLangIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecISOCtryLangObj*> arr;
		cfsec::CFSecISOCtryLangByLangIdxKey key;
		key.setRequiredISOLangId( ISOLangId );
		std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* dict;
		if( indexByLangIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByLangIdx = indexByLangIdx->find( key );
		if( searchIndexByLangIdx != indexByLangIdx->end() ) {
			dict = searchIndexByLangIdx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecISOCtryLangObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecISOCtryLangObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecISOCtryLangObj* CFIntISOCtryLangTableObj::updateISOCtryLang( cfsec::ICFSecISOCtryLangEditObj* Obj ) {
		static const std::string S_ProcName( "updateISOCtryLang" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCtryLangObj* obj = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOCtryLangBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCtryLang()->updateISOCtryLang( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecISOCtryLangBuff*>( Obj->getISOCtryLangBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( dynamic_cast<cfint::CFIntISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecISOCtryLangObj*>( obj->realize() );
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

	void CFIntISOCtryLangTableObj::deleteISOCtryLang( cfsec::ICFSecISOCtryLangEditObj* Obj ) {
		cfsec::ICFSecISOCtryLangObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCtryLang()->deleteISOCtryLang( schema->getAuthorization(),
			obj->getISOCtryLangBuff() );
		deepDisposeByIdIdx( obj->getRequiredISOCtryId(),
			obj->getRequiredISOLangId() );
	}

	void CFIntISOCtryLangTableObj::deleteISOCtryLangByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOLangId )
	{
		cfsec::CFSecISOCtryLangPKey pkey;
		pkey.setRequiredISOCtryId( ISOCtryId );
		pkey.setRequiredISOLangId( ISOLangId );
		cfsec::ICFSecISOCtryLangObj* obj = readISOCtryLang( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecISOCtryLangEditObj* editObj = dynamic_cast<cfsec::ICFSecISOCtryLangEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecISOCtryLangEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntISOCtryLangTableObj::deleteISOCtryLangByCtryIdx( const int16_t ISOCtryId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryLang()->deleteISOCtryLangByCtryIdx( schema->getAuthorization(),
				ISOCtryId );
		deepDisposeByCtryIdx( ISOCtryId );
	}

	void CFIntISOCtryLangTableObj::deleteISOCtryLangByLangIdx( const int16_t ISOLangId )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableISOCtryLang()->deleteISOCtryLangByLangIdx( schema->getAuthorization(),
				ISOLangId );
		deepDisposeByLangIdx( ISOLangId );
	}

	void CFIntISOCtryLangTableObj::reallyDetachFromIndexesISOCtryLang( cfsec::ICFSecISOCtryLangObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesISOCtryLang" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOCtryLangObj* obj = Obj;
		cfsec::CFSecISOCtryLangPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecISOCtryLangObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByCtryIdx != NULL ) {
				cfsec::CFSecISOCtryLangByCtryIdxKey keyCtryIdx;
				keyCtryIdx.setRequiredISOCtryId( obj->getRequiredISOCtryId() );
				auto searchCtryIdx = indexByCtryIdx->find( keyCtryIdx );
				if( searchCtryIdx != indexByCtryIdx->end() ) {
					std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* mapCtryIdx = searchCtryIdx->second;
					if( mapCtryIdx != NULL ) {
						auto removalProbe = mapCtryIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapCtryIdx->end() ) {
							mapCtryIdx->erase( removalProbe );
							if( mapCtryIdx->empty() ) {
								delete mapCtryIdx;
								mapCtryIdx = NULL;
								indexByCtryIdx->erase( searchCtryIdx );
							}
						}
					}
				}
			}

			if( indexByLangIdx != NULL ) {
				cfsec::CFSecISOCtryLangByLangIdxKey keyLangIdx;
				keyLangIdx.setRequiredISOLangId( obj->getRequiredISOLangId() );
				auto searchLangIdx = indexByLangIdx->find( keyLangIdx );
				if( searchLangIdx != indexByLangIdx->end() ) {
					std::map<cfsec::CFSecISOCtryLangPKey, cfsec::ICFSecISOCtryLangObj*>* mapLangIdx = searchLangIdx->second;
					if( mapLangIdx != NULL ) {
						auto removalProbe = mapLangIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapLangIdx->end() ) {
							mapLangIdx->erase( removalProbe );
							if( mapLangIdx->empty() ) {
								delete mapLangIdx;
								mapLangIdx = NULL;
								indexByLangIdx->erase( searchLangIdx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}


}
