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

	const std::string CFIntISOCcyTableObj::CLASS_NAME( "CFIntISOCcyTableObj" );
	const std::string CFIntISOCcyTableObj::TABLE_NAME( "ISOCcy" );
	const std::string CFIntISOCcyTableObj::TABLE_DBNAME( "iso_ccy" );

	CFIntISOCcyTableObj::CFIntISOCcyTableObj() {
		schema = NULL;
		members = new std::map<cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj*>();
		allISOCcy = NULL;
		indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
			cfsec::ICFSecISOCcyObj*>();
		indexByCcyNmIdx = new std::map< cfsec::CFSecISOCcyByCcyNmIdxKey,
			cfsec::ICFSecISOCcyObj*>();
	}

	CFIntISOCcyTableObj::CFIntISOCcyTableObj( cfsec::ICFSecSchemaObj* argSchema ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( argSchema );
		members = new std::map<cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj*>();
		allISOCcy = NULL;
		indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
			cfsec::ICFSecISOCcyObj*>();
		indexByCcyNmIdx = new std::map< cfsec::CFSecISOCcyByCcyNmIdxKey,
			cfsec::ICFSecISOCcyObj*>();
	}

	CFIntISOCcyTableObj::~CFIntISOCcyTableObj() {
		minimizeMemory();
		if( indexByCcyCdIdx != NULL ) {
			delete indexByCcyCdIdx;
			indexByCcyCdIdx = NULL;
		}
		if( indexByCcyNmIdx != NULL ) {
			delete indexByCcyNmIdx;
			indexByCcyNmIdx = NULL;
		}
		if( members != NULL ) {
			cfsec::ICFSecISOCcyObj* curMember;
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

	cfsec::ICFSecSchemaObj* CFIntISOCcyTableObj::getSchema() {
		return( schema );
	}

	void CFIntISOCcyTableObj::setSchema( cfsec::ICFSecSchemaObj* value ) {
		schema = dynamic_cast<cfint::ICFIntSchemaObj*>( value );
	}

	const std::string CFIntISOCcyTableObj::getTableName() {
		return( TABLE_NAME );
	}

	const std::string CFIntISOCcyTableObj::getTableDbName() {
		return( TABLE_DBNAME );
	}
	const classcode_t* CFIntISOCcyTableObj::getObjQualifyingClassCode() {
		return( NULL );
	}


	void CFIntISOCcyTableObj::minimizeMemory() {
		if( allISOCcy != NULL ) {
			allISOCcy->clear();
			delete allISOCcy;
			allISOCcy = NULL;
		}
		if( indexByCcyCdIdx != NULL ) {
			indexByCcyCdIdx->clear();
		}
		if( indexByCcyNmIdx != NULL ) {
			indexByCcyNmIdx->clear();
		}
		if( members != NULL ) {
			cfsec::ICFSecISOCcyObj* cur = NULL;
			cfsec::ICFSecISOCcyEditObj* edit = NULL;
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

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::newInstance() {
		cfsec::ICFSecISOCcyObj* inst = dynamic_cast<cfsec::ICFSecISOCcyObj*>( new CFIntISOCcyObj( schema ) );
		return( inst );
	}

	cfsec::ICFSecISOCcyEditObj* CFIntISOCcyTableObj::newEditInstance( cfsec::ICFSecISOCcyObj* orig ) {
		cfsec::ICFSecISOCcyEditObj* edit = dynamic_cast<cfsec::ICFSecISOCcyEditObj*>( new CFIntISOCcyEditObj( orig ));
		return( edit );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::realizeISOCcy( cfsec::ICFSecISOCcyObj* Obj ) {
		static const std::string S_ProcName( "realizeISOCcy" );
		static const std::string S_ExistingObj( "existingObj" );
		static const std::string S_KeepObj( "keepObj" );
		static const std::string S_Obj( "Obj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOCcyObj* obj = Obj;
		cfsec::ICFSecISOCcyObj* existingObj = NULL;
		cfsec::CFSecISOCcyPKey* pkey = obj->getPKey();
		cfsec::ICFSecISOCcyObj* keepObj = NULL;
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
			if( indexByCcyCdIdx != NULL ) {
				cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
				keyCcyCdIdx.setRequiredISOCode( keepObj->getRequiredISOCode() );
				auto removalProbe = indexByCcyCdIdx->find( keyCcyCdIdx );
				if( removalProbe != indexByCcyCdIdx->end() ) {
					indexByCcyCdIdx->erase( removalProbe );
				}
			}

			if( indexByCcyNmIdx != NULL ) {
				cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
				keyCcyNmIdx.setRequiredName( keepObj->getRequiredName() );
				auto removalProbe = indexByCcyNmIdx->find( keyCcyNmIdx );
				if( removalProbe != indexByCcyNmIdx->end() ) {
					indexByCcyNmIdx->erase( removalProbe );
				}
			}

			keepObj->setBuff( dynamic_cast<cfsec::CFSecISOCcyBuff*>( Obj->getBuff()->clone() ) );
			// Attach new object to alternate and duplicate indexes -- PKey stays stable

			if( indexByCcyCdIdx != NULL ) {
				static const std::string S_ACcyCdIdxObj( "aCcyCdIdxObj" );
				cfsec::ICFSecISOCcyObj* aCcyCdIdxObj =
					dynamic_cast<cfsec::ICFSecISOCcyObj*>( keepObj );
				if( aCcyCdIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACcyCdIdxObj );
				}
				cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
				keyCcyCdIdx.setRequiredISOCode( keepObj->getRequiredISOCode() );
				indexByCcyCdIdx->insert( std::map< cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::ICFSecISOCcyObj* >::value_type( keyCcyCdIdx, aCcyCdIdxObj ) );
			}

			if( indexByCcyNmIdx != NULL ) {
				static const std::string S_ACcyNmIdxObj( "aCcyNmIdxObj" );
				cfsec::ICFSecISOCcyObj* aCcyNmIdxObj =
					dynamic_cast<cfsec::ICFSecISOCcyObj*>( keepObj );
				if( aCcyNmIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACcyNmIdxObj );
				}
				cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
				keyCcyNmIdx.setRequiredName( keepObj->getRequiredName() );
				indexByCcyNmIdx->insert( std::map< cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::ICFSecISOCcyObj* >::value_type( keyCcyNmIdx, aCcyNmIdxObj ) );
			}

			if( allISOCcy != NULL ) {
				allISOCcy->insert( std::map< cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			}
		}
		else {
			keepObj = obj;
			keepObj->setIsNew( false );
			pkey = keepObj->getPKey();
			// Attach new object to PKey, all, alternate, and duplicate indexes
			members->insert( std::map< cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByCcyCdIdx != NULL ) {
				static const std::string S_ACcyCdIdxObj( "aCcyCdIdxObj" );
				cfsec::ICFSecISOCcyObj* aCcyCdIdxObj =
					dynamic_cast<cfsec::ICFSecISOCcyObj*>( keepObj );
				if( aCcyCdIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACcyCdIdxObj );
				}
				cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
				keyCcyCdIdx.setRequiredISOCode( keepObj->getRequiredISOCode() );
				indexByCcyCdIdx->insert( std::map< cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::ICFSecISOCcyObj* >::value_type( keyCcyCdIdx, aCcyCdIdxObj ) );
			}

			if( indexByCcyNmIdx != NULL ) {
				static const std::string S_ACcyNmIdxObj( "aCcyNmIdxObj" );
				cfsec::ICFSecISOCcyObj* aCcyNmIdxObj =
					dynamic_cast<cfsec::ICFSecISOCcyObj*>( keepObj );
				if( aCcyNmIdxObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ACcyNmIdxObj );
				}
				cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
				keyCcyNmIdx.setRequiredName( keepObj->getRequiredName() );
				indexByCcyNmIdx->insert( std::map< cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::ICFSecISOCcyObj* >::value_type( keyCcyNmIdx, aCcyNmIdxObj ) );
			}

			if( allISOCcy != NULL ) {
				allISOCcy->insert( std::map< cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj* >::value_type( *(keepObj->getPKey()), keepObj ) );
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

	void CFIntISOCcyTableObj::deepDisposeByIdIdx( const int16_t ISOCcyId ) {
		static const std::string S_ProcName( "deepDisposeByIdIdx" );
		std::vector<cfsec::ICFSecISOCcyObj*> list;
		cfsec::ICFSecISOCcyObj* existingObj = readCachedISOCcyByIdIdx( ISOCcyId );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOCcyObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOCcyTableObj*>( schema->getISOCcyTableObj() )->reallyDeepDisposeISOCcy( dynamic_cast<cfsec::ICFSecISOCcyObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOCcyTableObj::deepDisposeByCcyCdIdx( const std::string& ISOCode ) {
		static const std::string S_ProcName( "deepDisposeByCcyCdIdx" );
		std::vector<cfsec::ICFSecISOCcyObj*> list;
		cfsec::ICFSecISOCcyObj* existingObj = readCachedISOCcyByCcyCdIdx( ISOCode );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOCcyObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOCcyTableObj*>( schema->getISOCcyTableObj() )->reallyDeepDisposeISOCcy( dynamic_cast<cfsec::ICFSecISOCcyObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOCcyTableObj::deepDisposeByCcyNmIdx( const std::string& Name ) {
		static const std::string S_ProcName( "deepDisposeByCcyNmIdx" );
		std::vector<cfsec::ICFSecISOCcyObj*> list;
		cfsec::ICFSecISOCcyObj* existingObj = readCachedISOCcyByCcyNmIdx( Name );
		if( existingObj != NULL ) {
			list.push_back( existingObj );
		}
		cfsec::ICFSecISOCcyObj* cur = NULL;
		classcode_t classCode;
		auto listIter = list.begin();
		auto listEnd = list.end();
		while( listIter != listEnd ) {
			cur = *listIter;
			if( cur != NULL ) {
				classCode = cur->getClassCode();
				if( classCode == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
					dynamic_cast<cfint::CFIntISOCcyTableObj*>( schema->getISOCcyTableObj() )->reallyDeepDisposeISOCcy( dynamic_cast<cfsec::ICFSecISOCcyObj*>( cur ) );
				}
			}
			listIter ++;
		}
	}

	void CFIntISOCcyTableObj::reallyDeepDisposeISOCcy( cfsec::ICFSecISOCcyObj* Obj ) {
		static const std::string S_ProcName( "reallyDeepDisposeISOCcy" );

		if( Obj == NULL ) {
			return;
		}

		cfsec::ICFSecISOCcyObj* obj = Obj;
		
		dynamic_cast<cfint::CFIntISOCtryCcyTableObj*>( schema->getISOCtryCcyTableObj() )->deepDisposeByCcyIdx( obj->getRequiredISOCcyId() );
		classcode_t classCode = obj->getClassCode();
		if( classCode == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			dynamic_cast<cfint::CFIntISOCcyTableObj*>( schema->getISOCcyTableObj() )->reallyDetachFromIndexesISOCcy( dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj ) );
		}

		if( obj->getEdit() != NULL ) {
			obj->endEdit();
		}
		delete obj;
		obj = NULL;
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::createISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) {
		static const std::string S_ProcName( "createISOCcy" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Cloneable( "cloneable" );
		static const std::string S_ClonedBuff( "clonedbuff" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCcyObj* obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOCcyBuff* buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( Obj->getBuff()->clone() );
			// C++18 version of create returns a new buffer instance and takes over ownership of the passed-in buffer
			// MSS TODO WORKING The xmsg client will need to return the buffer instance created by processing
			// the response message, while xmsg rqst will have to delete the backing store instance
			// it receives after preparing the reply message so that memory doesn't leak on every request.
			cflib::ICFLibCloneableObj* cloneable = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->createISOCcy(
				schema->getAuthorization(),
				buff );
			if( cloneable == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Cloneable );
			}
			Obj->endEdit();
			obj->setBuff( dynamic_cast<cfsec::CFSecISOCcyBuff*>( cloneable ) );
			obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
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

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::readISOCcy( cfsec::CFSecISOCcyPKey* pkey, bool forceRead ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOCcy" );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		if( ! forceRead ) {
			auto searchMembers = members->find( *pkey );
			if( searchMembers != members->end() ) {
				// obj could be NULL if cache misses is enabled
				obj = searchMembers->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCcyBuff* readBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->readDerivedByIdIdx( schema->getAuthorization(),
			pkey->getRequiredISOCcyId() );
			if( readBuff != NULL ) {
			obj = dynamic_cast<cfint::CFIntISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance();
				obj->setBuff( readBuff );
				realized = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
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

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::lockISOCcy( cfsec::CFSecISOCcyPKey* pkey ) {
		static const std::string S_ProcName( "lockISOCcy" );
		cfsec::ICFSecISOCcyObj* locked = NULL;
		cfsec::CFSecISOCcyBuff* lockBuff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->lockDerived( schema->getAuthorization(), pkey );
		if( lockBuff != NULL ) {
			locked = dynamic_cast<cfint::CFIntISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance();
			locked->setBuff( lockBuff );
			locked = dynamic_cast<cfsec::ICFSecISOCcyObj*>( locked->realize() );
		}
		else {
			return( NULL );
		}
		return( locked );
	}

	std::vector<cfsec::ICFSecISOCcyObj*> CFIntISOCcyTableObj::readAllISOCcy( bool forceRead ) {
		static const std::string S_ProcName( "readAllISOCcy" );
		static const std::string S_Idx( "idx" );
		static const std::string S_Realized( "realized" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCcyObj* realized = NULL;
		if( forceRead || ( allISOCcy == NULL ) ) {
			std::map<cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj*>* map = new std::map<cfsec::CFSecISOCcyPKey,cfsec::ICFSecISOCcyObj*>();
			allISOCcy = map;
			std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> buffList = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->readAllDerived( schema->getAuthorization() );
			cfsec::CFSecISOCcyBuff* buff = NULL;
			cfsec::ICFSecISOCcyObj* obj = NULL;
			try {
				for( size_t idx = 0; idx < buffList.size(); idx ++ ) {
					buff = buffList[ idx ];
					buffList[ idx ] = NULL;
				obj = newInstance();
					obj->setBuff( buff );
					realized = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
					if( realized == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_Realized );
					}
					allISOCcy->insert( std::map< cfsec::CFSecISOCcyPKey, cfsec::ICFSecISOCcyObj* >::value_type( *(realized->getPKey()), realized ) );
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
		size_t len = allISOCcy->size();
		std::vector<cfsec::ICFSecISOCcyObj*> arr;
		auto valIter = allISOCcy->begin();
		size_t idx = 0;
		while( valIter != allISOCcy->end() ) {
			arr.push_back( valIter->second );
			valIter ++;
		}
		return( arr );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::readISOCcyByIdIdx( const int16_t ISOCcyId, bool forceRead )
	{
		static const std::string S_ProcName( "readISOCcyByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( ISOCcyId );
		cfsec::ICFSecISOCcyObj* obj = readISOCcy( &pkey, forceRead );
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::readISOCcyByCcyCdIdx( const std::string& ISOCode, bool forceRead )
	{
		static const std::string S_ProcName( "readISOCcyByCcyCdIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByCcyCdIdx == NULL ) {
			indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByCcyCdIdx = indexByCcyCdIdx->find( key );
			if( searchIndexByCcyCdIdx != indexByCcyCdIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByCcyCdIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCcyBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->readDerivedByCcyCdIdx( schema->getAuthorization(),
				ISOCode );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByCcyCdIdx->insert( std::map< cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::ICFSecISOCcyObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOCcyObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::readISOCcyByCcyNmIdx( const std::string& Name, bool forceRead )
	{
		static const std::string S_ProcName( "readISOCcyByCcyNmIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByCcyNmIdx == NULL ) {
			indexByCcyNmIdx = new std::map< cfsec::CFSecISOCcyByCcyNmIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyNmIdxKey key;
		key.setRequiredName( Name );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByCcyNmIdx = indexByCcyNmIdx->find( key );
			if( searchIndexByCcyNmIdx != indexByCcyNmIdx->end() ) {
				// Note: obj may be null if cache misses is enabled
				obj = searchIndexByCcyNmIdx->second;
				realized = obj;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCcyBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->readDerivedByCcyNmIdx( schema->getAuthorization(),
				Name );
			if( buff != NULL ) {
				obj = dynamic_cast<cfint::CFIntISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance();
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByCcyNmIdx->insert( std::map< cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::ICFSecISOCcyObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOCcyObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::readISOCcyByLookupCcyCdIdx( const std::string& ISOCode, bool forceRead )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readISOCcyByLookupCcyCdIdx" );
		if( indexByCcyCdIdx == NULL ) {
			indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		if( ! forceRead ) {
			auto searchIndexByCcyCdIdx = indexByCcyCdIdx->find( key );
			if( searchIndexByCcyCdIdx != indexByCcyCdIdx->end() ) {
				obj = searchIndexByCcyCdIdx->second;
			}
		}
		if( forceRead || ( obj == NULL ) ) {
			cfsec::CFSecISOCcyBuff* buff = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->readDerivedByLookupCcyCdIdx( schema->getAuthorization(),
				ISOCode );
			if( buff != NULL ) {
				obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( dynamic_cast<cfint::CFIntISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance() );
				obj->setBuff( buff );
				realized = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
				if( realized == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_Realized );
				}
				indexByCcyCdIdx->insert( std::map< cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::ICFSecISOCcyObj*>::value_type( key, dynamic_cast<cfsec::ICFSecISOCcyObj*>( realized ) ) );
				// No need to delete obj -- realize() auto-destructs the instance it decided to discard
				obj = realized;
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::readCachedISOCcy( cfsec::CFSecISOCcyPKey* pkey ) {
		static const std::string S_Obj( "obj" );
		static const std::string S_Realized( "realized" );
		static const std::string S_ProcName( "readISOCcy" );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			// obj could be NULL if cache misses is enabled
			obj = searchMembers->second;
			realized = obj;
		}
		return( realized );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::readCachedISOCcyByIdIdx( const int16_t ISOCcyId )
	{
		static const std::string S_ProcName( "readCachedISOCcyByIdIdx" );
		static const std::string S_Realized( "realized" );
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( ISOCcyId );
		cfsec::ICFSecISOCcyObj* obj = readCachedISOCcy( &pkey );
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::readCachedISOCcyByCcyCdIdx( const std::string& ISOCode )
	{
		static const std::string S_ProcName( "readCachedISOCcyByCcyCdIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByCcyCdIdx == NULL ) {
			indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		auto searchIndexByCcyCdIdx = indexByCcyCdIdx->find( key );
		if( searchIndexByCcyCdIdx != indexByCcyCdIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByCcyCdIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCcyBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::readCachedISOCcyByCcyNmIdx( const std::string& Name )
	{
		static const std::string S_ProcName( "readCachedISOCcyByCcyNmIdx" );
		static const std::string S_Realized( "realized" );
		if( indexByCcyNmIdx == NULL ) {
			indexByCcyNmIdx = new std::map< cfsec::CFSecISOCcyByCcyNmIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyNmIdxKey key;
		key.setRequiredName( Name );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		auto searchIndexByCcyNmIdx = indexByCcyNmIdx->find( key );
		if( searchIndexByCcyNmIdx != indexByCcyNmIdx->end() ) {
			// Note: obj may be null if cache misses is enabled
			obj = searchIndexByCcyNmIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCcyBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::readCachedISOCcyByLookupCcyCdIdx( const std::string& ISOCode )
	{
		static const std::string S_Realized( "realized" );
		static const std::string S_Obj( "obj" );
		static const std::string S_ProcName( "readCachedISOCcyByLookupCcyCdIdx" );
		if( indexByCcyCdIdx == NULL ) {
			indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		cfsec::ICFSecISOCcyObj* realized = NULL;
		auto searchIndexByCcyCdIdx = indexByCcyCdIdx->find( key );
		if( searchIndexByCcyCdIdx != indexByCcyCdIdx->end() ) {
			obj = searchIndexByCcyCdIdx->second;
		}
		else {
			for( auto iterMembers = members->begin(); ( obj == NULL ) && ( iterMembers != members->end() ); iterMembers ++ ) {
				obj = iterMembers->second;
				if( obj != NULL ) {
					if( *(dynamic_cast<cfsec::CFSecISOCcyBuff*>( obj->getBuff() ) ) != key ) {
						obj = NULL;
					}
				}
			}
		}
		return( obj );
	}

	cfsec::ICFSecISOCcyObj* CFIntISOCcyTableObj::updateISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) {
		static const std::string S_ProcName( "updateISOCcy" );
		static const std::string S_Obj( "obj" );
		static const std::string S_Updated( "updated" );
		CFLIB_EXCEPTION_DECLINFO
		cfsec::ICFSecISOCcyObj* obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( Obj->getOrig() );
		try {
			cfsec::CFSecISOCcyBuff* updated = dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->updateISOCcy( schema->getAuthorization(),
				dynamic_cast<cfsec::CFSecISOCcyBuff*>( Obj->getISOCcyBuff()->clone() ) );
			if( updated == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_Updated );
			}
			obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( dynamic_cast<cfint::CFIntISOCcyTableObj*>( schema->getISOCcyTableObj() )->newInstance() );
			obj->setBuff( updated );
			obj = dynamic_cast<cfsec::ICFSecISOCcyObj*>( obj->realize() );
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

	void CFIntISOCcyTableObj::deleteISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) {
		cfsec::ICFSecISOCcyObj* obj = Obj;
		dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->deleteISOCcy( schema->getAuthorization(),
			obj->getISOCcyBuff() );
		deepDisposeByIdIdx( obj->getRequiredISOCcyId() );
	}

	void CFIntISOCcyTableObj::deleteISOCcyByIdIdx( const int16_t ISOCcyId )
	{
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( ISOCcyId );
		cfsec::ICFSecISOCcyObj* obj = readISOCcy( &pkey, true );
		if( obj != NULL ) {
			cfsec::ICFSecISOCcyEditObj* editObj = dynamic_cast<cfsec::ICFSecISOCcyEditObj*>( obj->getEdit() );
			if( editObj == NULL ) {
				editObj = dynamic_cast<cfsec::ICFSecISOCcyEditObj*>( obj->beginEdit() );
			}
			if( editObj != NULL ) {
				editObj->deleteInstance();
				editObj = NULL;
			}
		}
	}

	void CFIntISOCcyTableObj::deleteISOCcyByCcyCdIdx( const std::string& ISOCode )
	{
		if( indexByCcyCdIdx == NULL ) {
			indexByCcyCdIdx = new std::map< cfsec::CFSecISOCcyByCcyCdIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		auto searchIndexByCcyCdIdx = indexByCcyCdIdx->find( key );
		if( searchIndexByCcyCdIdx != indexByCcyCdIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->deleteISOCcyByCcyCdIdx( schema->getAuthorization(),
				ISOCode );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->deleteISOCcyByCcyCdIdx( schema->getAuthorization(),
				ISOCode );
		}
		deepDisposeByCcyCdIdx( ISOCode );
	}

	void CFIntISOCcyTableObj::deleteISOCcyByCcyNmIdx( const std::string& Name )
	{
		if( indexByCcyNmIdx == NULL ) {
			indexByCcyNmIdx = new std::map< cfsec::CFSecISOCcyByCcyNmIdxKey,
				cfsec::ICFSecISOCcyObj*>();
		}
		cfsec::CFSecISOCcyByCcyNmIdxKey key;
		key.setRequiredName( Name );
		cfsec::ICFSecISOCcyObj* obj = NULL;
		auto searchIndexByCcyNmIdx = indexByCcyNmIdx->find( key );
		if( searchIndexByCcyNmIdx != indexByCcyNmIdx->end() ) {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->deleteISOCcyByCcyNmIdx( schema->getAuthorization(),
				Name );
		}
		else {
			dynamic_cast<ICFIntSchema*>( schema->getBackingStore() )->getTableISOCcy()->deleteISOCcyByCcyNmIdx( schema->getAuthorization(),
				Name );
		}
		deepDisposeByCcyNmIdx( Name );
	}

	void CFIntISOCcyTableObj::reallyDetachFromIndexesISOCcy( cfsec::ICFSecISOCcyObj* Obj ) {
		static const std::string S_ProcName( "reallyDetachFromIndexesISOCcy" );
		static const std::string S_Obj( "Obj" );
		static const std::string S_ExistingObj( "ExistingObj" );
		if( Obj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME, S_ProcName, 1, S_Obj );
		}
		cfsec::ICFSecISOCcyObj* obj = Obj;
		cfsec::CFSecISOCcyPKey* pkey = obj->getPKey();
		auto searchMembers = members->find( *pkey );
		if( searchMembers != members->end() ) {
			cfsec::ICFSecISOCcyObj* existingObj = searchMembers->second;
			if( existingObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ExistingObj );
			}
			if( indexByCcyCdIdx != NULL ) {
				cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
				keyCcyCdIdx.setRequiredISOCode( obj->getRequiredISOCode() );
				auto removalProbe = indexByCcyCdIdx->find( keyCcyCdIdx );
				if( removalProbe != indexByCcyCdIdx->end() ) {
					indexByCcyCdIdx->erase( removalProbe );
				}
			}

			if( indexByCcyNmIdx != NULL ) {
				cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
				keyCcyNmIdx.setRequiredName( obj->getRequiredName() );
				auto removalProbe = indexByCcyNmIdx->find( keyCcyNmIdx );
				if( removalProbe != indexByCcyNmIdx->end() ) {
					indexByCcyNmIdx->erase( removalProbe );
				}
			}

			members->erase( searchMembers );
		}
	}


}
