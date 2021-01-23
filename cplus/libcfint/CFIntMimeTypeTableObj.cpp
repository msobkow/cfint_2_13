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

	const std::string CFIntMimeTypeTableObj::CLASS_NAME( "CFIntMimeTypeTableObj" );
	const std::string CFIntMimeTypeTableObj::TABLE_NAME( "MimeType" );
	const std::string CFIntMimeTypeTableObj::TABLE_DBNAME( "MimeType" );

	CFIntMimeTypeTableObj::CFIntMimeTypeTableObj() {
		schema = NULL;
		members = new std::map<cfint::CFIntMimeTypePKey, cfint::ICFIntMimeTypeObj*>();
		allMimeType = NULL;
		indexByUNameIdx = new std::map< cfint::CFIntMimeTypeByUNameIdxKey,
			cfint::ICFIntMimeTypeObj*>();
	}

	CFIntMimeTypeTableObj::CFIntMimeTypeTableObj( cfint::ICFIntSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfint::CFIntMimeTypePKey, cfint::ICFIntMimeTypeObj*>();
		allMimeType = NULL;
		indexByUNameIdx = new std::map< cfint::CFIntMimeTypeByUNameIdxKey,
			cfint::ICFIntMimeTypeObj*>();
	}

	CFIntMimeTypeTableObj::~CFIntMimeTypeTableObj() {
		minimizeMemory();
		if( indexByUNameIdx != NULL ) {
			delete indexByUNameIdx;
			indexByUNameIdx = NULL;
		}
		if( members != NULL ) {
			cfint::ICFIntMimeTypeObj* curMember;
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

	cfint::ICFIntSchemaObj* CFIntMimeTypeTableObj::getSchema() {
		return( schema );
	}

	void CFIntMimeTypeTableObj::setSchema( cfint::ICFIntSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntMimeTypeTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntMimeTypeTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntMimeTypeTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntMimeTypeTableObj::minimizeMemory() {
		if( allMimeType != NULL ) {
			allMimeType->clear();
			delete allMimeType;
			allMimeType = NULL;
		}
		if( indexByUNameIdx != NULL ) {
			indexByUNameIdx->clear();
		}
		if( members != NULL ) {
			cfint::ICFIntMimeTypeObj* cur = NULL;
			cfint::ICFIntMimeTypeEditObj* edit = NULL;
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

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::newInstance() {
		cfint::ICFIntMimeTypeObj* inst = dynamic_cast<cfint::ICFIntMimeTypeObj*>( new CFIntMimeTypeObj( schema ) );
		return( inst );
	}

	cfint::ICFIntMimeTypeEditObj* CFIntMimeTypeTableObj::newEditInstance( cfint::ICFIntMimeTypeObj* orig ) {
		cfint::ICFIntMimeTypeEditObj* edit = dynamic_cast<cfint::ICFIntMimeTypeEditObj*>( new CFIntMimeTypeEditObj( orig ));
		return( edit );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::realizeMimeType( cfint::ICFIntMimeTypeObj* Obj ) {
		static const std::string S_ProcName( "realizeMimeType" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntMimeTypeObj* obj = Obj;
		cfint::ICFIntMimeTypeObj* existingObj = NULL;
		cfint::CFIntMimeTypePKey* pkey = obj->getPKey();
		cfint::ICFIntMimeTypeObj* keepObj = NULL;
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
				cfint::CFIntMimeTypeByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByUNameIdx->find( keyUNameIdx );
				if( removalProbe != indexByUNameIdx->end() ) {
					indexByUNameIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfint::CFIntMimeTypeBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfint::ICFIntMimeTypeObj* aUNameIdxObj =
					dynamic_cast<cfint::ICFIntMimeTypeObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfint::CFIntMimeTypeByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByUNameIdx->insert( std::map< cfint::CFIntMimeTypeByUNameIdxKey, cfint::ICFIntMimeTypeObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( allMimeType != NULL ) {
				allMimeType->insert( std::map< cfint::CFIntMimeTypePKey, cfint::ICFIntMimeTypeObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfint::CFIntMimeTypePKey, cfint::ICFIntMimeTypeObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByUNameIdx != NULL ) {
				static const std::string S_AUNameIdxObj( "aUNameIdxObj" );
				cfint::ICFIntMimeTypeObj* aUNameIdxObj =
					dynamic_cast<cfint::ICFIntMimeTypeObj*>( keepObj );
				if( aUNameIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_AUNameIdxObj );
				}
				cfint::CFIntMimeTypeByUNameIdxKey keyUNameIdx;
				keyUNameIdx.setRequiredName( keepObj->getRequiredName() );
				indexByUNameIdx->insert( std::map< cfint::CFIntMimeTypeByUNameIdxKey, cfint::ICFIntMimeTypeObj* >::value_type( keyUNameIdx, aUNameIdxObj ) );
			}

			if( allMimeType != NULL ) {
				allMimeType->insert( std::map< cfint::CFIntMimeTypePKey, cfint::ICFIntMimeTypeObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntMimeTypeTableObj::deepDisposeByIdIdx( const int32_t MimeTypeId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfint::ICFIntMimeTypeObj*> list;
		cfint::ICFIntMimeTypeObj* existingObj = readCachedMimeTypeByIdIdx( MimeTypeId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntMimeTypeObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntMimeTypeTableObj*>( schema->getMimeTypeTableObj() )->reallyDeepDisposeMimeType( dynamic_cast<cfint::ICFIntMimeTypeObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntMimeTypeTableObj::deepDisposeByUNameIdx( const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByUNameIdx" );
		std::vector<cfint::ICFIntMimeTypeObj*> list;
		cfint::ICFIntMimeTypeObj* existingObj = readCachedMimeTypeByUNameIdx( Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfint::ICFIntMimeTypeObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntMimeTypeTableObj*>( schema->getMimeTypeTableObj() )->reallyDeepDisposeMimeType( dynamic_cast<cfint::ICFIntMimeTypeObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntMimeTypeTableObj::reallyDeepDisposeMimeType( cfint::ICFIntMimeTypeObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeMimeType" );

		if( Obj == NULL ) {
			return;
		}

		cfint::ICFIntMimeTypeObj* obj = Obj;
		
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntMimeTypeTableObj*>( schema->getMimeTypeTableObj() )->reallyDetachFromIndexesMimeType( dynamic_cast<cfint::ICFIntMimeTypeObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::createMimeType( cfint::ICFIntMimeTypeEditObj* Obj ) {
		static const std::string S_ProcName( "createMimeType" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntMimeTypeObj* obj = dynamic_cast<cfint::ICFIntMimeTypeObj*>( Obj->getOrig() );
		try {
			cfint::CFIntMimeTypeBuff* buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMimeType()->createMimeType(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfint::CFIntMimeTypeBuff*>( cloneable ) );
			obj = dynamic_cast<cfint::ICFIntMimeTypeObj*>( obj->realize() );
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

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::readMimeType( cfint::CFIntMimeTypePKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readMimeType" );
		cfint::ICFIntMimeTypeObj* obj = NULL;
		cfint::ICFIntMimeTypeObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntMimeTypeBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMimeType()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredMimeTypeId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntMimeTypeTableObj*>( schema->getMimeTypeTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfint::ICFIntMimeTypeObj*>( obj->realize() );
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

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::lockMimeType( cfint::CFIntMimeTypePKey* pkey ) {
		static const std::string S_ProcName( "lockMimeType" );
		cfint::ICFIntMimeTypeObj* locked = NULL;
		cfint::CFIntMimeTypeBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMimeType()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntMimeTypeTableObj*>( schema->getMimeTypeTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfint::ICFIntMimeTypeObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfint::ICFIntMimeTypeObj*> CFIntMimeTypeTableObj::readAllMimeType( bool forceRead ) {
		static const std::string S_ProcName( "readAllMimeType" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntMimeTypeObj* realized = NULL;
		if( forceRead || ( allMimeType == NULL ) ) {
			std::map<cfint::CFIntMimeTypePKey, cfint::ICFIntMimeTypeObj*>* map = new std::map<cfint::CFIntMimeTypePKey,cfint::ICFIntMimeTypeObj*>();
			allMimeType = map;
			std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMimeType()->readAllDerived( schema->getAuthorization() );
			cfint::CFIntMimeTypeBuff* buff = NULL;
			cfint::ICFIntMimeTypeObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfint::ICFIntMimeTypeObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allMimeType->insert( std::map< cfint::CFIntMimeTypePKey, cfint::ICFIntMimeTypeObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allMimeType->size();
		std::vector<cfint::ICFIntMimeTypeObj*> arr;
		auto valIter = allMimeType->begin();
		size_t idx = 0;
		while( valIter != allMimeType->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::readMimeTypeByIdIdx( const int32_t MimeTypeId, bool forceRead )
	{
		static const std::string S_ProcName( "readMimeTypeByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntMimeTypePKey pkey;
		pkey.setRequiredMimeTypeId( MimeTypeId );
		cfint::ICFIntMimeTypeObj* obj = readMimeType( &pkey, forceRead );
		return( obj );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::readMimeTypeByUNameIdx( const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readMimeTypeByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntMimeTypeByUNameIdxKey,
				cfint::ICFIntMimeTypeObj*>();
		}
		cfint::CFIntMimeTypeByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::ICFIntMimeTypeObj* obj = NULL;
		cfint::ICFIntMimeTypeObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByUNameIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntMimeTypeBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMimeType()->readDerivedByUNameIdx( schema->getAuthorization(),
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntMimeTypeTableObj*>( schema->getMimeTypeTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntMimeTypeObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfint::CFIntMimeTypeByUNameIdxKey, cfint::ICFIntMimeTypeObj*>::value_type( key, dynamic_cast<cfint::ICFIntMimeTypeObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::readMimeTypeByLookupUNameIdx( const std::string& Name, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readMimeTypeByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntMimeTypeByUNameIdxKey,
				cfint::ICFIntMimeTypeObj*>();
		}
		cfint::CFIntMimeTypeByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::ICFIntMimeTypeObj* obj = NULL;
		cfint::ICFIntMimeTypeObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
			if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
				obj = searchIndexByUNameIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfint::CFIntMimeTypeBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMimeType()->readDerivedByLookupUNameIdx( schema->getAuthorization(),
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::ICFIntMimeTypeObj*>( dynamic_cast<cfint::CFIntMimeTypeTableObj*>( schema->getMimeTypeTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfint::ICFIntMimeTypeObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByUNameIdx->insert( std::map< cfint::CFIntMimeTypeByUNameIdxKey, cfint::ICFIntMimeTypeObj*>::value_type( key, dynamic_cast<cfint::ICFIntMimeTypeObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::readCachedMimeType( cfint::CFIntMimeTypePKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readMimeType" );
		cfint::ICFIntMimeTypeObj* obj = NULL;
		cfint::ICFIntMimeTypeObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::readCachedMimeTypeByIdIdx( const int32_t MimeTypeId )
	{
		static const std::string S_ProcName( "readCachedMimeTypeByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfint::CFIntMimeTypePKey pkey;
		pkey.setRequiredMimeTypeId( MimeTypeId );
		cfint::ICFIntMimeTypeObj* obj = readCachedMimeType( &pkey );
		return( obj );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::readCachedMimeTypeByUNameIdx( const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedMimeTypeByUNameIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntMimeTypeByUNameIdxKey,
				cfint::ICFIntMimeTypeObj*>();
		}
		cfint::CFIntMimeTypeByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::ICFIntMimeTypeObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntMimeTypeBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::readCachedMimeTypeByLookupUNameIdx( const std::string& Name )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedMimeTypeByLookupUNameIdx" );
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntMimeTypeByUNameIdxKey,
				cfint::ICFIntMimeTypeObj*>();
		}
		cfint::CFIntMimeTypeByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::ICFIntMimeTypeObj* obj = NULL;
		cfint::ICFIntMimeTypeObj* realized = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			obj = searchIndexByUNameIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfint::CFIntMimeTypeBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfint::ICFIntMimeTypeObj* CFIntMimeTypeTableObj::updateMimeType( cfint::ICFIntMimeTypeEditObj* Obj ) {
		static const std::string S_ProcName( "updateMimeType" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntMimeTypeObj* obj = dynamic_cast<cfint::ICFIntMimeTypeObj*>( Obj->getOrig() );
		try {
			cfint::CFIntMimeTypeBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMimeType()->updateMimeType( schema->getAuthorization(),
				dynamic_cast<cfint::CFIntMimeTypeBuff*>( Obj->getMimeTypeBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfint::ICFIntMimeTypeObj*>( dynamic_cast<cfint::CFIntMimeTypeTableObj*>( schema->getMimeTypeTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfint::ICFIntMimeTypeObj*>( obj->realize() );
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

	void CFIntMimeTypeTableObj::deleteMimeType( cfint::ICFIntMimeTypeEditObj* Obj ) {
		cfint::ICFIntMimeTypeObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMimeType()->deleteMimeType( schema->getAuthorization(),
			obj->getMimeTypeBuff() );
		deepDisposeByIdIdx( obj->getRequiredMimeTypeId() );
	}

	void CFIntMimeTypeTableObj::deleteMimeTypeByIdIdx( const int32_t MimeTypeId )
	{
		cfint::CFIntMimeTypePKey pkey;
		pkey.setRequiredMimeTypeId( MimeTypeId );
		cfint::ICFIntMimeTypeObj* obj = readMimeType( &pkey, true );
		if( obj != NULL ) {
			cfint::ICFIntMimeTypeEditObj* editObj = dynamic_cast<cfint::ICFIntMimeTypeEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfint::ICFIntMimeTypeEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntMimeTypeTableObj::deleteMimeTypeByUNameIdx( const std::string& Name )
	{
		if( indexByUNameIdx == NULL ) {
			indexByUNameIdx = new std::map< cfint::CFIntMimeTypeByUNameIdxKey,
				cfint::ICFIntMimeTypeObj*>();
		}
		cfint::CFIntMimeTypeByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::ICFIntMimeTypeObj* obj = NULL;
		auto searchIndexByUNameIdx = indexByUNameIdx->find( key );
		if( searchIndexByUNameIdx != indexByUNameIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMimeType()->deleteMimeTypeByUNameIdx( schema->getAuthorization(),
				Name );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableMimeType()->deleteMimeTypeByUNameIdx( schema->getAuthorization(),
				Name );
		}
		deepDisposeByUNameIdx( Name );
	}

	void CFIntMimeTypeTableObj::reallyDetachFromIndexesMimeType( cfint::ICFIntMimeTypeObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesMimeType" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfint::ICFIntMimeTypeObj* obj = Obj;
		cfint::CFIntMimeTypePKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfint::ICFIntMimeTypeObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByUNameIdx != NULL ) {
				cfint::CFIntMimeTypeByUNameIdxKey keyUNameIdx;
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
