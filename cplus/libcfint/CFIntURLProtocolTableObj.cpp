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

	const std::string CFIntURLProtocolTableObj::CLASS_NAME( "CFIntURLProtocolTableObj" );
	const std::string CFIntURLProtocolTableObj::TABLE_NAME( "URLProtocol" );
	const std::string CFIntURLProtocolTableObj::TABLE_DBNAME( "URLProto" );

	CFIntURLProtocolTableObj::CFIntURLProtocolTableObj() {
		schema = NULL;
		members = new std::map<cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>();
		allURLProtocol = NULL;
		indexByUNameIdx = new std::map< cfint::CFIntURLProtocolByUNameIdxKey,
			cfint::ICFIntURLProtocolObj*>();
		indexByIsSecureIdx = new std::map< cfint::CFIntURLProtocolByIsSecureIdxKey,
			std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>*>();
	}

	CFIntURLProtocolTableObj::CFIntURLProtocolTableObj( cfint::ICFIntSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>();
		allURLProtocol = NULL;
		indexByUNameIdx = new std::map< cfint::CFIntURLProtocolByUNameIdxKey,
			cfint::ICFIntURLProtocolObj*>();
		indexByIsSecureIdx = new std::map< cfint::CFIntURLProtocolByIsSecureIdxKey,
			std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>*>();
	}

	CFIntURLProtocolTableObj::~CFIntURLProtocolTableObj() {
		minimizeMemory();
		if( indexByUNameIdx != NULL ) {
			delete indexByUNameIdx;
			indexByUNameIdx = NULL;
		}
		if( indexByIsSecureIdx != NULL ) {
			delete indexByIsSecureIdx;
			indexByIsSecureIdx = NULL;
		}
		if( members != NULL ) {
			cfint::ICFIntURLProtocolObj* curMember;
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

	cfint::ICFIntSchemaObj* CFIntURLProtocolTableObj::getSchema() {
		return( schema );
	}

	void CFIntURLProtocolTableObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntURLProtocolTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntURLProtocolTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntURLProtocolTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntURLProtocolTableObj::minimizeMemory() {
		if( allURLProtocol != NULL ) {
			allURLProtocol->clear();
			delete allURLProtocol;
			allURLProtocol = NULL;
		}
		if( indexByUNameIdx != NULL ) {
			indexByUNameIdx->clear();
		}
		if( indexByIsSecureIdx != NULL ) {
			std::map< cfint::CFIntURLProtocolByIsSecureIdxKey,
				std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>* >::iterator iterByIsSecureIdx = indexByIsSecureIdx->begin();
			std::map< cfint::CFIntURLProtocolByIsSecureIdxKey,
				std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>* >::iterator endByIsSecureIdx = indexByIsSecureIdx->end();
			std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>* curByIsSecureIdx = NULL;
			while( iterByIsSecureIdx != endByIsSecureIdx ) {
				curByIsSecureIdx = iterByIsSecureIdx->second;
				if( curByIsSecureIdx != NULL ) {
					curByIsSecureIdx->clear();
					delete curByIsSecureIdx;
					curByIsSecureIdx = NULL;
					iterByIsSecureIdx->second = NULL;
				}
				iterByIsSecureIdx ++;
			}
			indexByIsSecureIdx->clear();
		}
		if( members != NULL ) {
			cfint::ICFIntURLProtocolObj* cur = NULL;
			cfint::ICFIntURLProtocolEditObj* edit = NULL;
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

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::newInstance() {
		cfint::ICFIntURLProtocolObj* inst = dynamic_cast<cfint::ICFIntURLProtocolObj*>( new CFIntURLProtocolObj( schema ) );
		return( inst );
	}

	cfint::ICFIntURLProtocolEditObj* CFIntURLProtocolTableObj::newEditInstance( cfint::ICFIntURLProtocolObj* orig ) {
		cfint::ICFIntURLProtocolEditObj* edit = dynamic_cast<cfint::ICFIntURLProtocolEditObj*>( new CFIntURLProtocolEditObj( orig ));
		return( edit );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::realizeURLProtocol( cfint::ICFIntURLProtocolObj* Obj ) {
		static const std::string S_ProcName( "realizeURLProtocol" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntURLProtocolObj* obj = Obj;
		cfint::ICFIntURLProtocolObj* existingObj = NULL;
		cfint::CFIntURLProtocolPKey* pkey = obj->getPKey();
		cfint::ICFIntURLProtocolObj* keepObj = NULL;
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
			if( indexByUNameIdx != NULL ) {
				cfint::CFIntURLProtocolByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByUNameIdx->find( keyUNameIdx );
				if( removalProbe != indexByUNameIdx->end() ) {
					indexByUNameIdx->erase( removalProbe );
				}
			}

			if( indexByIsSecureIdx != NULL ) {
				cfint::CFIntURLProtocolByIsSecureIdxKey keyIsSecureIdx;
				keyIsSecureIdx.setRequiredIsSecure( keepObj->getRequiredIsSecure() );
				auto searchIsSecureIdx = indexByIsSecureIdx->find( keyIsSecureIdx );
				if( searchIsSecureIdx != indexByIsSecureIdx->end() ) {
					std::map<cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>* mapIsSecureIdx = searchIsSecureIdx->second;
					if( mapIsSecureIdx != NULL ) {
						auto removalProbe = mapIsSecureIdx->find( *(keepObj->getPKey()) );
						if( removalProbe != mapIsSecureIdx->end() ) {
							mapIsSecureIdx->erase( removalProbe );
						}
					}
				}
			}

			keepObj->setBuff( dynamic_cast<cfint::CFIntURLProtocolBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfint::ICFIntURLProtocolObj* aUNameIdxObj =
					dynamic_cast<cfint::ICFIntURLProtocolObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfint::CFIntURLProtocolByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByUNameIdx->insert( std::map< cfint::CFIntURLProtocolByUNameIdxKey, cfint::ICFIntURLProtocolObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( indexByIsSecureIdx != NULL ) {
				static const std::string S_AIsSecureIdxObj( "aIsSecureIdxObj" );
				cfint::ICFIntURLProtocolObj* aIsSecureIdxObj =
					dynamic_cast<cfint::ICFIntURLProtocolObj*>( keepObj );
				if( aIsSecureIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIsSecureIdxObj );
				}
				cfint::CFIntURLProtocolByIsSecureIdxKey keyIsSecureIdx;
				keyIsSecureIdx.setRequiredIsSecure( keepObj->getRequiredIsSecure() );
				auto searchIndexByIsSecureIdx = indexByIsSecureIdx->find( keyIsSecureIdx );
				if( searchIndexByIsSecureIdx != indexByIsSecureIdx->end() ) {
					std::map<cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>* mapIsSecureIdx = searchIndexByIsSecureIdx->second;
					if( mapIsSecureIdx != NULL ) {
						mapIsSecureIdx->insert( std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj* >::value_type( *(keepObj->getPKey()), aIsSecureIdxObj ) );
					}
				}
			}

			if( allURLProtocol != NULL ) {
				allURLProtocol->insert( std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfint::ICFIntURLProtocolObj* aUNameIdxObj =
					dynamic_cast<cfint::ICFIntURLProtocolObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfint::CFIntURLProtocolByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByUNameIdx->insert( std::map< cfint::CFIntURLProtocolByUNameIdxKey, cfint::ICFIntURLProtocolObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( indexByIsSecureIdx != NULL ) {
				static const std::string S_AIsSecureIdxObj( "aIsSecureIdxObj" );
				cfint::ICFIntURLProtocolObj* aIsSecureIdxObj =
					dynamic_cast<cfint::ICFIntURLProtocolObj*>( keepObj );
				if( aIsSecureIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AIsSecureIdxObj );
				}
				cfint::CFIntURLProtocolByIsSecureIdxKey keyIsSecureIdx;
				keyIsSecureIdx.setRequiredIsSecure( keepObj->getRequiredIsSecure() );
				auto searchIndexByIsSecureIdx = indexByIsSecureIdx->find( keyIsSecureIdx );
				if( searchIndexByIsSecureIdx != indexByIsSecureIdx->end() ) {
					std::map<cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>* mapIsSecureIdx = searchIndexByIsSecureIdx->second;
					if( mapIsSecureIdx != NULL ) {
						mapIsSecureIdx->insert( std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj* >::value_type( *(keepObj->getPKey()), aIsSecureIdxObj ) );
					}
				}
			}

			if( allURLProtocol != NULL ) {
				allURLProtocol->insert( std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntURLProtocolTableObj::deepDisposeByIdIdx( const int32_t URLProtocolId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfint::ICFIntURLProtocolObj*> list;
		cfint::ICFIntURLProtocolObj* existingObj = readCachedURLProtocolByIdIdx( URLProtocolId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntURLProtocolObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntURLProtocolTableObj*>( schema->getURLProtocolTableObj() )->reallyDeepDisposeURLProtocol( dynamic_cast<cfint::ICFIntURLProtocolObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntURLProtocolTableObj::deepDisposeByUNameIdx( const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByUNameIdx" );
		std::vector<cfint::ICFIntURLProtocolObj*> list;
		cfint::ICFIntURLProtocolObj* existingObj = readCachedURLProtocolByUNameIdx( Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntURLProtocolObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntURLProtocolTableObj*>( schema->getURLProtocolTableObj() )->reallyDeepDisposeURLProtocol( dynamic_cast<cfint::ICFIntURLProtocolObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntURLProtocolTableObj::deepDisposeByIsSecureIdx( const bool IsSecure ) {
		static const std::string S_ProcName( "deepDisposeByIsSecureIdx" );
		std::vector<cfint::ICFIntURLProtocolObj*> list;
		std::vector<cfint::ICFIntURLProtocolObj*> matchesFound = readCachedURLProtocolByIsSecureIdx( IsSecure );
		auto iterMatches = matchesFound.begin();
		auto endMatches = matchesFound.end();
		while( iterMatches != endMatches ) {
			if( *iterMatches != NULL ) {
				list.push_back( *iterMatches );
			}
			iterMatches ++;
		}
		cfint::ICFIntURLProtocolObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntURLProtocolTableObj*>( schema->getURLProtocolTableObj() )->reallyDeepDisposeURLProtocol( dynamic_cast<cfint::ICFIntURLProtocolObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntURLProtocolTableObj::reallyDeepDisposeURLProtocol( cfint::ICFIntURLProtocolObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeURLProtocol" );

		if( Obj == NULL ) {
			return;
		}

		cfint::ICFIntURLProtocolObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntURLProtocolTableObj*>( schema->getURLProtocolTableObj() )->reallyDetachFromIndexesURLProtocol( dynamic_cast<cfint::ICFIntURLProtocolObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::createURLProtocol( cfint::ICFIntURLProtocolEditObj* Obj ) {
		static const std::string S_ProcName( "createURLProtocol" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntURLProtocolObj* obj = dynamic_cast<cfint::ICFIntURLProtocolObj*>( Obj->getOrig() );
		try {
			cfint::CFIntURLProtocolBuff* buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->createURLProtocol(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfint::CFIntURLProtocolBuff*>( cloneable ) );
			obj = dynamic_cast<cfint::ICFIntURLProtocolObj*>( obj->realize() );
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

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::readURLProtocol( cfint::CFIntURLProtocolPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readURLProtocol" );
		cfint::ICFIntURLProtocolObj* obj = NULL;
		cfint::ICFIntURLProtocolObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntURLProtocolBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredURLProtocolId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntURLProtocolTableObj*>( schema->getURLProtocolTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfint::ICFIntURLProtocolObj*>( obj->realize() );
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

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::lockURLProtocol( cfint::CFIntURLProtocolPKey* pkey ) {
		static const std::string S_ProcName( "lockURLProtocol" );
		cfint::ICFIntURLProtocolObj* locked = NULL;
		cfint::CFIntURLProtocolBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntURLProtocolTableObj*>( schema->getURLProtocolTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfint::ICFIntURLProtocolObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfint::ICFIntURLProtocolObj*> CFIntURLProtocolTableObj::readAllURLProtocol( bool forceRead ) {
		static const std::string S_ProcName( "readAllURLProtocol" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntURLProtocolObj* realized = NULL;
		if( forceRead || ( allURLProtocol == NULL ) ) {
			std::map<cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>* map = new std::map<cfint::CFIntURLProtocolPKey,cfint::ICFIntURLProtocolObj*>();
			allURLProtocol = map;
			std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->readAllDerived( schema->getAuthorization() );
			cfint::CFIntURLProtocolBuff* buff = NULL;
			cfint::ICFIntURLProtocolObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfint::ICFIntURLProtocolObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allURLProtocol->insert( std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allURLProtocol->size();
		std::vector<cfint::ICFIntURLProtocolObj*> arr;
		auto valIter = allURLProtocol->begin();
		size_t idx = 0;
		while( valIter != allURLProtocol->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::readURLProtocolByIdIdx( const int32_t URLProtocolId, bool forceRead )
	{
		static const std::string S_ProcName( "readURLProtocolByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntURLProtocolPKey pkey;
		pkey.setRequiredURLProtocolId( URLProtocolId );
		cfint::ICFIntURLProtocolObj* obj = readURLProtocol( &pkey, forceRead );
		return( obj );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::readURLProtocolByUNameIdx( const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readURLProtocolByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntURLProtocolByUNameIdxKey,
				cfint::ICFIntURLProtocolObj*>();
		}
		cfint::CFIntURLProtocolByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::ICFIntURLProtocolObj* obj = NULL;
		cfint::ICFIntURLProtocolObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntURLProtocolBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->readDerivedByUNameIdx( schema->getAuthorization(),
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntURLProtocolTableObj*>( schema->getURLProtocolTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntURLProtocolObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfint::CFIntURLProtocolByUNameIdxKey, cfint::ICFIntURLProtocolObj*>::value_type( key, dynamic_cast<cfint::ICFIntURLProtocolObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	std::vector<cfint::ICFIntURLProtocolObj*> CFIntURLProtocolTableObj::readURLProtocolByIsSecureIdx( const bool IsSecure,
		bool forceRead )
	{
		static const std::string S_ProcName( "readURLProtocolByIsSecureIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntURLProtocolByIsSecureIdxKey key;
		key.setRequiredIsSecure( IsSecure );
		std::map<cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>* dict;
		std::map<cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>* oldDict;
		if( indexByIsSecureIdx == NULL ) {
			indexByIsSecureIdx = new std::map< cfint::CFIntURLProtocolByIsSecureIdxKey,
				std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>*>();
		}
		auto searchIndexByIsSecureIdx = indexByIsSecureIdx->find( key );
		if( searchIndexByIsSecureIdx != indexByIsSecureIdx->end() ) {
			oldDict = searchIndexByIsSecureIdx->second;
		}
		else {
			oldDict = NULL;
		}
		if( ( oldDict != NULL ) && ( ! forceRead ) ) {
			dict = oldDict;
		}
		else {
			dict = new std::map<cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>();
			cfint::ICFIntURLProtocolObj* obj;
			std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->readDerivedByIsSecureIdx( schema->getAuthorization(),
				IsSecure );
			cfint::CFIntURLProtocolBuff* buff;
			for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
				buff = buffList[ idx ];
				buffList[ idx ] = NULL;
				obj = dynamic_cast<cfint::CFIntURLProtocolTableObj*>( schema->getURLProtocolTableObj() )->newInstance();
				if( obj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Obj );
				}
				obj->setBuff( buff );
				cfint::ICFIntURLProtocolObj* realized = dynamic_cast<cfint::ICFIntURLProtocolObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				dict->insert( std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj* >::value_type( *(realized->getPKey()), realized ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = NULL;
			}
			if( oldDict != NULL ) {
				indexByIsSecureIdx->erase( searchIndexByIsSecureIdx );
				delete oldDict;
				oldDict = NULL;
			}
			indexByIsSecureIdx->insert( std::map< cfint::CFIntURLProtocolByIsSecureIdxKey,
				std::map< cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj* >* >::value_type( key, dict ) );
		}
		size_t len = dict->size();
		std::vector<cfint::ICFIntURLProtocolObj*> arr;
		arr.reserve( len );
		auto valIter = dict->begin();
		while( valIter != dict->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::readURLProtocolByLookupUNameIdx( const std::string& Name, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readURLProtocolByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntURLProtocolByUNameIdxKey,
				cfint::ICFIntURLProtocolObj*>();
		}
		cfint::CFIntURLProtocolByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::ICFIntURLProtocolObj* obj = NULL;
		cfint::ICFIntURLProtocolObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				obj = searchIndexByUNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntURLProtocolBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->readDerivedByLookupUNameIdx( schema->getAuthorization(),
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::ICFIntURLProtocolObj*>( dynamic_cast<cfint::CFIntURLProtocolTableObj*>( schema->getURLProtocolTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntURLProtocolObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfint::CFIntURLProtocolByUNameIdxKey, cfint::ICFIntURLProtocolObj*>::value_type( key, dynamic_cast<cfint::ICFIntURLProtocolObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::readCachedURLProtocol( cfint::CFIntURLProtocolPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readURLProtocol" );
		cfint::ICFIntURLProtocolObj* obj = NULL;
		cfint::ICFIntURLProtocolObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::readCachedURLProtocolByIdIdx( const int32_t URLProtocolId )
	{
		static const std::string S_ProcName( "readCachedURLProtocolByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntURLProtocolPKey pkey;
		pkey.setRequiredURLProtocolId( URLProtocolId );
		cfint::ICFIntURLProtocolObj* obj = readCachedURLProtocol( &pkey );
		return( obj );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::readCachedURLProtocolByUNameIdx( const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedURLProtocolByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntURLProtocolByUNameIdxKey,
				cfint::ICFIntURLProtocolObj*>();
		}
		cfint::CFIntURLProtocolByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::ICFIntURLProtocolObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntURLProtocolBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	std::vector<cfint::ICFIntURLProtocolObj*> CFIntURLProtocolTableObj::readCachedURLProtocolByIsSecureIdx( const bool IsSecure )
	{
		static const std::string S_ProcName( "readCachedURLProtocolByIsSecureIdx" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		std::vector<cfint::ICFIntURLProtocolObj*> arr;
		cfint::CFIntURLProtocolByIsSecureIdxKey key;
		key.setRequiredIsSecure( IsSecure );
		std::map<cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>* dict;
		if( indexByIsSecureIdx == NULL ) {
			return( arr );
		}
		auto searchIndexByIsSecureIdx = indexByIsSecureIdx->find( key );
		if( searchIndexByIsSecureIdx != indexByIsSecureIdx->end() ) {
			dict = searchIndexByIsSecureIdx->second;
			size_t len = dict->size();
			std::vector<cfint::ICFIntURLProtocolObj*> arr;
			arr.reserve( len );
			auto valIter = dict->begin();
			while( valIter != dict->end() ) {
				arr.push_back( valIter->second );
				valIter ++;
			}
		}
		else {
			cfint::ICFIntURLProtocolObj* obj;
			for( auto iterMembers = members->begin(); iterMembers != members->end(); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntURLProtocolBuff*>( obj->getBuff() ) ) == key ) {
						arr.push_back( obj );
					}
				}
			}
		}
		return( arr );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::readCachedURLProtocolByLookupUNameIdx( const std::string& Name )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedURLProtocolByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntURLProtocolByUNameIdxKey,
				cfint::ICFIntURLProtocolObj*>();
		}
		cfint::CFIntURLProtocolByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::ICFIntURLProtocolObj* obj = NULL;
		cfint::ICFIntURLProtocolObj* realized = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntURLProtocolBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntURLProtocolObj* CFIntURLProtocolTableObj::updateURLProtocol( cfint::ICFIntURLProtocolEditObj* Obj ) {
		static const std::string S_ProcName( "updateURLProtocol" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntURLProtocolObj* obj = dynamic_cast<cfint::ICFIntURLProtocolObj*>( Obj->getOrig() );
		try {
			cfint::CFIntURLProtocolBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->updateURLProtocol( schema->getAuthorization(),
				dynamic_cast<cfint::CFIntURLProtocolBuff*>( Obj->getURLProtocolBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfint::ICFIntURLProtocolObj*>( dynamic_cast<cfint::CFIntURLProtocolTableObj*>( schema->getURLProtocolTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfint::ICFIntURLProtocolObj*>( obj->realize() );
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

	void CFIntURLProtocolTableObj::deleteURLProtocol( cfint::ICFIntURLProtocolEditObj* Obj ) {
		cfint::ICFIntURLProtocolObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->deleteURLProtocol( schema->getAuthorization(),
			obj->getURLProtocolBuff() );
		deepDisposeByIdIdx( obj->getRequiredURLProtocolId() );
	}

	void CFIntURLProtocolTableObj::deleteURLProtocolByIdIdx( const int32_t URLProtocolId )
	{
		cfint::CFIntURLProtocolPKey pkey;
		pkey.setRequiredURLProtocolId( URLProtocolId );
		cfint::ICFIntURLProtocolObj* obj = readURLProtocol( &pkey, true );
		if( obj != NULL ) {
			cfint::ICFIntURLProtocolEditObj* editObj = dynamic_cast<cfint::ICFIntURLProtocolEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfint::ICFIntURLProtocolEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntURLProtocolTableObj::deleteURLProtocolByUNameIdx( const std::string& Name )
	{
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntURLProtocolByUNameIdxKey,
				cfint::ICFIntURLProtocolObj*>();
		}
		cfint::CFIntURLProtocolByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::ICFIntURLProtocolObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->deleteURLProtocolByUNameIdx( schema->getAuthorization(),
				Name );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->deleteURLProtocolByUNameIdx( schema->getAuthorization(),
				Name );
		}
		deepDisposeByUNameIdx( Name );
	}

	void CFIntURLProtocolTableObj::deleteURLProtocolByIsSecureIdx( const bool IsSecure )
	{
		dynamic_cast<cfint::ICFIntSchema*>( schema->getBackingStore() )->getTableURLProtocol()->deleteURLProtocolByIsSecureIdx( schema->getAuthorization(),
				IsSecure );
		deepDisposeByIsSecureIdx( IsSecure );
	}

	void CFIntURLProtocolTableObj::reallyDetachFromIndexesURLProtocol( cfint::ICFIntURLProtocolObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesURLProtocol" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntURLProtocolObj* obj = Obj;
		cfint::CFIntURLProtocolPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfint::ICFIntURLProtocolObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByUNameIdx != NULL ) {
				cfint::CFIntURLProtocolByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredName( obj->getRequiredName() );
				auto removalProbe = indexByUNameIdx->find( keyUNameIdx );
				if( removalProbe != indexByUNameIdx->end() ) {
					indexByUNameIdx->erase( removalProbe );
				}
			}

			if( indexByIsSecureIdx != NULL ) {
				cfint::CFIntURLProtocolByIsSecureIdxKey keyIsSecureIdx;
				keyIsSecureIdx.setRequiredIsSecure( obj->getRequiredIsSecure() );
				auto searchIsSecureIdx = indexByIsSecureIdx->find( keyIsSecureIdx );
				if( searchIsSecureIdx != indexByIsSecureIdx->end() ) {
					std::map<cfint::CFIntURLProtocolPKey, cfint::ICFIntURLProtocolObj*>* mapIsSecureIdx = searchIsSecureIdx->second;
					if( mapIsSecureIdx != NULL ) {
						auto removalProbe = mapIsSecureIdx->find( *(obj->getPKey()) );
						if( removalProbe != mapIsSecureIdx->end() ) {
							mapIsSecureIdx->erase( removalProbe );
							if( mapIsSecureIdx->empty() ) {
								delete mapIsSecureIdx;
								mapIsSecureIdx = NULL;
								indexByIsSecureIdx->erase( searchIsSecureIdx );
							}
						}
					}
				}
			}

			members->erase( searchMembers );
		}
	}


}
