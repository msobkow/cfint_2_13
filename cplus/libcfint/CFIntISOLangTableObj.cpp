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

	const std::string CFIntISOLangTableObj::CLASS_NAME( "CFIntISOLangTableObj" );
	const std::string CFIntISOLangTableObj::TABLE_NAME( "ISOLang" );
	const std::string CFIntISOLangTableObj::TABLE_DBNAME( "iso_lang" );

	CFIntISOLangTableObj::CFIntISOLangTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>();
		allISOLang = NULL;
		indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
			cfsec::ICFSecISOLangObj*>();
		indexByCode2Idx = new std::map< cfsec::CFSecISOLangByCode2IdxKey,
			std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>*>();
	}

	CFIntISOLangTableObj::CFIntISOLangTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>();
		allISOLang = NULL;
		indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
			cfsec::ICFSecISOLangObj*>();
		indexByCode2Idx = new std::map< cfsec::CFSecISOLangByCode2IdxKey,
			std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>*>();
	}

	CFIntISOLangTableObj::~CFIntISOLangTableObj() {
		minimizeMemory();
		if( indexByCode3Idx != NULL ) {
			delete indexByCode3Idx;
			indexByCode3Idx = NULL;
		}
		if( indexByCode2Idx != NULL ) {
			delete indexByCode2Idx;
			indexByCode2Idx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecISOLangObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntISOLangTableObj::getSchema() {
		return( schema );
	}

	void CFIntISOLangTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntISOLangTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntISOLangTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntISOLangTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntISOLangTableObj::minimizeMemory() {
		if( allISOLang != NULL ) {
			allISOLang->clear();
			delete allISOLang;
			allISOLang = NULL;
		}
		if( indexByCode3Idx != NULL ) {
			indexByCode3Idx->clear();
		}
		if( indexByCode2Idx != NULL ) {
			std::map< cfsec::CFSecISOLangByCode2IdxKey,
				std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* >::iterator iterByCode2Idx = indexByCode2Idx->begin();
			std::map< cfsec::CFSecISOLangByCode2IdxKey,
				std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* >::iterator endByCode2Idx = indexByCode2Idx->end();
			std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* curByCode2Idx = NULL;
			while( iterByCode2Idx != endByCode2Idx ) {
				curByCode2Idx = iterByCode2Idx->second;
				if( curByCode2Idx != NULL ) {
					curByCode2Idx->clear();
					delete curByCode2Idx;
					curByCode2Idx = NULL;
					iterByCode2Idx->second = NULL;
				}
				iterByCode2Idx ++;
			}
			indexByCode2Idx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecISOLangObj* cur = NULL;
			cfsec::ICFSecISOLangEditObj* edit = NULL;
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

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::newInstance() {
		cfsec::ICFSecISOLangObj* inst = dynamic_cast<cfsec::ICFSecISOLangObj*>( new CFIntISOLangObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecISOLangEditObj* CFIntISOLangTableObj::newEditInstance( cfsec::ICFSecISOLangObj* orig ) {
		cfsec::ICFSecISOLangEditObj* edit = dynamic_cast<cfsec::ICFSecISOLangEditObj*>( new CFIntISOLangEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::realizeISOLang( cfsec::ICFSecISOLangObj* Obj ) {
		static const std::string S_ProcName( "realizeISOLang" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOLangObj* obj = Obj;
		cfsec::ICFSecISOLangObj* existingObj = NULL;
		cfsec::CFSecISOLangPKey* pkey = obj->getPKey();
		cfsec::ICFSecISOLangObj* keepObj = NULL;
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
			if( indexByCode3Idx != NULL ) {
				cfsec::CFSecISOLangByCode3IdxKey keyCode3Idx;
				keyCode3Idx.setRequiredISO6392Code( keepObj->getRequiredISO6392Code() );
				auto removalProbe = indexByCode3Idx->find( keyCode3Idx );
				if( removalProbe != indexByCode3Idx->end() ) {
					indexByCode3Idx->erase( removalProbe );
				}
			}

			if( indexByCode2Idx != NULL ) {
				cfsec::CFSecISOLangByCode2IdxKey keyCode2Idx;
				if( keepObj->isOptionalISO6391CodeNull() ) {
					keyCode2Idx.setOptionalISO6391CodeNull();
				}
				else {
					keyCode2Idx.setOptionalISO6391CodeValue( keepObj->getOptionalISO6391CodeValue() );
				}
				auto searchCode2Idx = indexByCode2Idx->find( keyCode2Idx );
				if( searchCode2Idx != indexByCode2Idx->end() ) {
					std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* mapCode2Idx = searchCode2Idx->second;
					if( mapCode2Idx != NULL ) {
						auto removalProbe = mapCode2Idx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapCode2Idx->end() ) {
							mapCode2Idx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecISOLangBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByCode3Idx != NULL ) {
				static const std::string S_ACode3IdxObj( "aCode3IdxObj" );
				cfsec::ICFSecISOLangObj* aCode3IdxObj =
					dynamic_cast<cfsec::ICFSecISOLangObj*>( keepObj );
				if( aCode3IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACode3IdxObj );
				}
				cfsec::CFSecISOLangByCode3IdxKey keyCode3Idx;
				keyCode3Idx.setRequiredISO6392Code( keepObj->getRequiredISO6392Code() );
				indexByCode3Idx->insert( std::map< cfsec::CFSecISOLangByCode3IdxKey, cfsec::ICFSecISOLangObj* >::value_type( keyCode3Idx, aCode3IdxObj ) );
			}

			if( indexByCode2Idx != NULL ) {
				static const std::string S_ACode2IdxObj( "aCode2IdxObj" );
				cfsec::ICFSecISOLangObj* aCode2IdxObj =
					dynamic_cast<cfsec::ICFSecISOLangObj*>( keepObj );
				if( aCode2IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACode2IdxObj );
				}
				cfsec::CFSecISOLangByCode2IdxKey keyCode2Idx;
				if( keepObj->isOptionalISO6391CodeNull() ) {
					keyCode2Idx.setOptionalISO6391CodeNull();
				}
				else {
					keyCode2Idx.setOptionalISO6391CodeValue( keepObj->getOptionalISO6391CodeValue() );
				}
				auto searchIndexByCode2Idx = indexByCode2Idx->find( keyCode2Idx );
				if( searchIndexByCode2Idx != indexByCode2Idx->end() ) {
					std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* mapCode2Idx = searchIndexByCode2Idx->second;
					if( mapCode2Idx != NULL ) {
						mapCode2Idx->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(keepObj->getPKey()), aCode2IdxObj ) );
					}
				}
			}

			if( allISOLang != NULL ) {
				allISOLang->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByCode3Idx != NULL ) {
				static const std::string S_ACode3IdxObj( "aCode3IdxObj" );
				cfsec::ICFSecISOLangObj* aCode3IdxObj =
					dynamic_cast<cfsec::ICFSecISOLangObj*>( keepObj );
				if( aCode3IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACode3IdxObj );
				}
				cfsec::CFSecISOLangByCode3IdxKey keyCode3Idx;
				keyCode3Idx.setRequiredISO6392Code( keepObj->getRequiredISO6392Code() );
				indexByCode3Idx->insert( std::map< cfsec::CFSecISOLangByCode3IdxKey, cfsec::ICFSecISOLangObj* >::value_type( keyCode3Idx, aCode3IdxObj ) );
			}

			if( indexByCode2Idx != NULL ) {
				static const std::string S_ACode2IdxObj( "aCode2IdxObj" );
				cfsec::ICFSecISOLangObj* aCode2IdxObj =
					dynamic_cast<cfsec::ICFSecISOLangObj*>( keepObj );
				if( aCode2IdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACode2IdxObj );
				}
				cfsec::CFSecISOLangByCode2IdxKey keyCode2Idx;
				if( keepObj->isOptionalISO6391CodeNull() ) {
					keyCode2Idx.setOptionalISO6391CodeNull();
				}
				else {
					keyCode2Idx.setOptionalISO6391CodeValue( keepObj->getOptionalISO6391CodeValue() );
				}
				auto searchIndexByCode2Idx = indexByCode2Idx->find( keyCode2Idx );
				if( searchIndexByCode2Idx != indexByCode2Idx->end() ) {
					std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* mapCode2Idx = searchIndexByCode2Idx->second;
					if( mapCode2Idx != NULL ) {
						mapCode2Idx->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(keepObj->getPKey()), aCode2IdxObj ) );
					}
				}
			}

			if( allISOLang != NULL ) {
				allISOLang->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntISOLangTableObj::deepDisposeByIdIdx( const int16_t ISOLangId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecISOLangObj*> list;
		cfsec::ICFSecISOLangObj* existingObj = readCachedISOLangByIdIdx( ISOLangId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOLangObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOLangTableObj*>( schema->getISOLangTableObj() )->reallyDeepDisposeISOLang( dynamic_cast<cfsec::ICFSecISOLangObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOLangTableObj::deepDisposeByCode3Idx( const std::string& ISO6392Code ) {
		static const std::string S_ProcName( "deepDisposeByCode3Idx" );
		std::vector<cfsec::ICFSecISOLangObj*> list;
		cfsec::ICFSecISOLangObj* existingObj = readCachedISOLangByCode3Idx( ISO6392Code );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOLangObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOLangTableObj*>( schema->getISOLangTableObj() )->reallyDeepDisposeISOLang( dynamic_cast<cfsec::ICFSecISOLangObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOLangTableObj::deepDisposeByCode2Idx( const std::string* ISO6391Code ) {
		static const std::string S_ProcName( "deepDisposeByCode2Idx" );
		std::vector<cfsec::ICFSecISOLangObj*> list;
		std::vector<cfsec::ICFSecISOLangObj*> matchesFound = readCachedISOLangByCode2Idx( ISO6391Code );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfsec::ICFSecISOLangObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOLangTableObj*>( schema->getISOLangTableObj() )->reallyDeepDisposeISOLang( dynamic_cast<cfsec::ICFSecISOLangObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOLangTableObj::reallyDeepDisposeISOLang( cfsec::ICFSecISOLangObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeISOLang" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecISOLangObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntISOCtryLangTableObj*>( schema->getISOCtryLangTableObj() )->deepDisposeByLangIdx( obj->getRequiredISOLangId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecISOLangBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntISOLangTableObj*>( schema->getISOLangTableObj() )->reallyDetachFromIndexesISOLang( dynamic_cast<cfsec::ICFSecISOLangObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::createISOLang( cfsec::ICFSecISOLangEditObj* Obj ) {
		static const std::string S_ProcName( "createISOLang" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOLangObj* obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOLangBuff* buff = dynamic_cast<cfsec::CFSecISOLangBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->createISOLang(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecISOLangBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
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

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::readISOLang( cfsec::CFSecISOLangPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOLang" );
		cfsec::ICFSecISOLangObj* obj = NULL;
		cfsec::ICFSecISOLangObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOLangBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredISOLangId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
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

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::lockISOLang( cfsec::CFSecISOLangPKey* pkey ) {
		static const std::string S_ProcName( "lockISOLang" );
		cfsec::ICFSecISOLangObj* locked = NULL;
		cfsec::CFSecISOLangBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecISOLangObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecISOLangObj*> CFIntISOLangTableObj::readAllISOLang( bool forceRead ) {
		static const std::string S_ProcName( "readAllISOLang" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOLangObj* realized = NULL;
		if( forceRead || ( allISOLang == NULL ) ) {
			std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* map = new std::map<cfsec::CFSecISOLangPKey,cfsec::ICFSecISOLangObj*>();
			allISOLang = map;
			std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecISOLangBuff* buff = NULL;
			cfsec::ICFSecISOLangObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allISOLang->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allISOLang->size();
		std::vector<cfsec::ICFSecISOLangObj*> arr;
		auto valIter = allISOLang->begin();
		size_t idx = 0;
		while( valIter != allISOLang->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::readISOLangByIdIdx( const int16_t ISOLangId, bool forceRead )
	{
		static const std::string S_ProcName( "readISOLangByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOLangPKey pkey;
		pkey.setRequiredISOLangId( ISOLangId );
		cfsec::ICFSecISOLangObj* obj = readISOLang( &pkey, forceRead );
		return( obj );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::readISOLangByCode3Idx( const std::string& ISO6392Code, bool forceRead )
	{
		static const std::string S_ProcName( "readISOLangByCode3Idx" );
		static const std::string S_Realized( "realized" );
		if( indexByCode3Idx == NULL ) {
			indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
				cfsec::ICFSecISOLangObj*>();
		}
		cfsec::CFSecISOLangByCode3IdxKey key;
		key.setRequiredISO6392Code( ISO6392Code );
		cfsec::ICFSecISOLangObj* obj = NULL;
		cfsec::ICFSecISOLangObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByCode3Idx = indexByCode3Idx->find( key );
			if( searchIndexByCode3Idx != indexByCode3Idx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByCode3Idx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOLangBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->readDerivedByCode3Idx( schema->getAuthorization(),
				ISO6392Code );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByCode3Idx->insert( std::map< cfsec::CFSecISOLangByCode3IdxKey, cfsec::ICFSecISOLangObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOLangObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecISOLangObj*> CFIntISOLangTableObj::readISOLangByCode2Idx( const std::string* ISO6391Code,
		bool forceRead )
	{
		static const std::string S_ProcName( "readISOLangByCode2Idx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOLangByCode2IdxKey key;
		if( ISO6391Code == NULL ) {
			key.setOptionalISO6391CodeNull();
		}
		else {
			key.setOptionalISO6391CodeValue( *ISO6391Code );
		}
		std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* dict;
		std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* oldDict;
		if( indexByCode2Idx == NULL ) {
			indexByCode2Idx = new std::map< cfsec::CFSecISOLangByCode2IdxKey,
				std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>*>();
		}
		auto searchIndexByCode2Idx = indexByCode2Idx->find( key );
		if( searchIndexByCode2Idx != indexByCode2Idx->end() ) {
			oldDict = searchIndexByCode2Idx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>();
			cfsec::ICFSecISOLangObj* obj;
			std::TCFLibOwningVector<cfsec::CFSecISOLangBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->readDerivedByCode2Idx( schema->getAuthorization(),
				ISO6391Code );
			cfsec::CFSecISOLangBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfsec::ICFSecISOLangObj* realized = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByCode2Idx->erase( searchIndexByCode2Idx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByCode2Idx->insert( std::map< cfsec::CFSecISOLangByCode2IdxKey,
				std::map< cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfsec::ICFSecISOLangObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::readISOLangByLookupCode3Idx( const std::string& ISO6392Code, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readISOLangByLookupCode3Idx" );
		if( indexByCode3Idx == NULL ) {
			indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
				cfsec::ICFSecISOLangObj*>();
		}
		cfsec::CFSecISOLangByCode3IdxKey key;
		key.setRequiredISO6392Code( ISO6392Code );
		cfsec::ICFSecISOLangObj* obj = NULL;
		cfsec::ICFSecISOLangObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByCode3Idx = indexByCode3Idx->find( key );
			if( searchIndexByCode3Idx != indexByCode3Idx->end() ) {
				obj = searchIndexByCode3Idx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOLangBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->readDerivedByLookupCode3Idx( schema->getAuthorization(),
				ISO6392Code );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( dynamic_cast<cfint::CFIntISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByCode3Idx->insert( std::map< cfsec::CFSecISOLangByCode3IdxKey, cfsec::ICFSecISOLangObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOLangObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::readCachedISOLang( cfsec::CFSecISOLangPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOLang" );
		cfsec::ICFSecISOLangObj* obj = NULL;
		cfsec::ICFSecISOLangObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::readCachedISOLangByIdIdx( const int16_t ISOLangId )
	{
		static const std::string S_ProcName( "readCachedISOLangByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOLangPKey pkey;
		pkey.setRequiredISOLangId( ISOLangId );
		cfsec::ICFSecISOLangObj* obj = readCachedISOLang( &pkey );
		return( obj );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::readCachedISOLangByCode3Idx( const std::string& ISO6392Code )
	{
		static const std::string S_ProcName( "readCachedISOLangByCode3Idx" );
		static const std::string S_Realized( "realized" );
		if( indexByCode3Idx == NULL ) {
			indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
				cfsec::ICFSecISOLangObj*>();
		}
		cfsec::CFSecISOLangByCode3IdxKey key;
		key.setRequiredISO6392Code( ISO6392Code );
		cfsec::ICFSecISOLangObj* obj = NULL;
		auto searchIndexByCode3Idx = indexByCode3Idx->find( key );
		if( searchIndexByCode3Idx != indexByCode3Idx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByCode3Idx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOLangBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfsec::ICFSecISOLangObj*> CFIntISOLangTableObj::readCachedISOLangByCode2Idx( const std::string* ISO6391Code )
	{
		static const std::string S_ProcName( "readCachedISOLangByCode2Idx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfsec::ICFSecISOLangObj*> arr;
		cfsec::CFSecISOLangByCode2IdxKey key;
		if( ISO6391Code == NULL ) {
			key.setOptionalISO6391CodeNull();
		}
		else {
			key.setOptionalISO6391CodeValue( *ISO6391Code );
		}
		std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* dict;
		if( indexByCode2Idx == NULL ) {
			return( arr );
		}
		auto searchIndexByCode2Idx = indexByCode2Idx->find( key );
		if( searchIndexByCode2Idx != indexByCode2Idx->end() ) {
			dict = searchIndexByCode2Idx->second;
			size_t len = dict->size();
			std::vector<cfsec::ICFSecISOLangObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfsec::ICFSecISOLangObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOLangBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::readCachedISOLangByLookupCode3Idx( const std::string& ISO6392Code )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedISOLangByLookupCode3Idx" );
		if( indexByCode3Idx == NULL ) {
			indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
				cfsec::ICFSecISOLangObj*>();
		}
		cfsec::CFSecISOLangByCode3IdxKey key;
		key.setRequiredISO6392Code( ISO6392Code );
		cfsec::ICFSecISOLangObj* obj = NULL;
		cfsec::ICFSecISOLangObj* realized = NULL;
		auto searchIndexByCode3Idx = indexByCode3Idx->find( key );
		if( searchIndexByCode3Idx != indexByCode3Idx->end() ) {
			obj = searchIndexByCode3Idx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOLangBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOLangObj* CFIntISOLangTableObj::updateISOLang( cfsec::ICFSecISOLangEditObj* Obj ) {
		static const std::string S_ProcName( "updateISOLang" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOLangObj* obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOLangBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->updateISOLang( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecISOLangBuff*>( Obj->getISOLangBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( dynamic_cast<cfint::CFIntISOLangTableObj*>( schema->getISOLangTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecISOLangObj*>( obj->realize() );
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

	void CFIntISOLangTableObj::deleteISOLang( cfsec::ICFSecISOLangEditObj* Obj ) {
		cfsec::ICFSecISOLangObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->deleteISOLang( schema->getAuthorization(),
			obj->getISOLangBuff() );
		deepDisposeByIdIdx( obj->getRequiredISOLangId() );
	}

	void CFIntISOLangTableObj::deleteISOLangByIdIdx( const int16_t ISOLangId )
	{
		cfsec::CFSecISOLangPKey pkey;
		pkey.setRequiredISOLangId( ISOLangId );
		cfsec::ICFSecISOLangObj* obj = readISOLang( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecISOLangEditObj* editObj = dynamic_cast<cfsec::ICFSecISOLangEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecISOLangEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntISOLangTableObj::deleteISOLangByCode3Idx( const std::string& ISO6392Code )
	{
		if( indexByCode3Idx == NULL ) {
			indexByCode3Idx = new std::map< cfsec::CFSecISOLangByCode3IdxKey,
				cfsec::ICFSecISOLangObj*>();
		}
		cfsec::CFSecISOLangByCode3IdxKey key;
		key.setRequiredISO6392Code( ISO6392Code );
		cfsec::ICFSecISOLangObj* obj = NULL;
		auto searchIndexByCode3Idx = indexByCode3Idx->find( key );
		if( searchIndexByCode3Idx != indexByCode3Idx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->deleteISOLangByCode3Idx( schema->getAuthorization(),
				ISO6392Code );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOLang()->deleteISOLangByCode3Idx( schema->getAuthorization(),
				ISO6392Code );
		}
		deepDisposeByCode3Idx( ISO6392Code );
	}

	void CFIntISOLangTableObj::deleteISOLangByCode2Idx( const std::string* ISO6391Code )
	{
		dynamic_cast<cfsec::ICFSecSchema*>( schema->getBackingStore() )->getTableISOLang()->deleteISOLangByCode2Idx( schema->getAuthorization(),
				ISO6391Code );
		deepDisposeByCode2Idx( ISO6391Code );
	}

	void CFIntISOLangTableObj::reallyDetachFromIndexesISOLang( cfsec::ICFSecISOLangObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesISOLang" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOLangObj* obj = Obj;
		cfsec::CFSecISOLangPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecISOLangObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByCode3Idx != NULL ) {
				cfsec::CFSecISOLangByCode3IdxKey keyCode3Idx;
				keyCode3Idx.setRequiredISO6392Code( obj->getRequiredISO6392Code() );
				auto removalProbe = indexByCode3Idx->find( keyCode3Idx );
				if( removalProbe != indexByCode3Idx->end() ) {
					indexByCode3Idx->erase( removalProbe );
				}
			}

			if( indexByCode2Idx != NULL ) {
				cfsec::CFSecISOLangByCode2IdxKey keyCode2Idx;
				if( obj->isOptionalISO6391CodeNull() ) {
					keyCode2Idx.setOptionalISO6391CodeNull();
				}
				else {
					keyCode2Idx.setOptionalISO6391CodeValue( obj->getOptionalISO6391CodeValue() );
				}
				auto searchCode2Idx = indexByCode2Idx->find( keyCode2Idx );
				if( searchCode2Idx != indexByCode2Idx->end() ) {
					std::map<cfsec::CFSecISOLangPKey, cfsec::ICFSecISOLangObj*>* mapCode2Idx = searchCode2Idx->second;
					if( mapCode2Idx != NULL ) {
						auto removalProbe = mapCode2Idx->find( *(obj->getPKey()) );
						if( removalProbe != mapCode2Idx->end() ) {
							mapCode2Idx->erase( removalProbe );
							if( mapCode2Idx->empty() ) {
								delete mapCode2Idx;
								mapCode2Idx = NULL;
								indexByCode2Idx->erase( searchCode2Idx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}


}
