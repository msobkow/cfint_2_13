
// Description: C++18 Implementation for an in-memory RAM DbIO for SecGroupForm.

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
#include <cfint/ICFIntPublic.hpp>
#include <cfintram/CFIntRamClusterTable.hpp>
#include <cfintram/CFIntRamHostNodeTable.hpp>
#include <cfintram/CFIntRamISOCcyTable.hpp>
#include <cfintram/CFIntRamISOCtryTable.hpp>
#include <cfintram/CFIntRamISOCtryCcyTable.hpp>
#include <cfintram/CFIntRamISOCtryLangTable.hpp>
#include <cfintram/CFIntRamISOLangTable.hpp>
#include <cfintram/CFIntRamISOTZoneTable.hpp>
#include <cfintram/CFIntRamLicenseTable.hpp>
#include <cfintram/CFIntRamMajorVersionTable.hpp>
#include <cfintram/CFIntRamMimeTypeTable.hpp>
#include <cfintram/CFIntRamMinorVersionTable.hpp>
#include <cfintram/CFIntRamSecAppTable.hpp>
#include <cfintram/CFIntRamSecDeviceTable.hpp>
#include <cfintram/CFIntRamSecFormTable.hpp>
#include <cfintram/CFIntRamSecGroupTable.hpp>
#include <cfintram/CFIntRamSecGroupFormTable.hpp>
#include <cfintram/CFIntRamSecGrpIncTable.hpp>
#include <cfintram/CFIntRamSecGrpMembTable.hpp>
#include <cfintram/CFIntRamSecSessionTable.hpp>
#include <cfintram/CFIntRamSecUserTable.hpp>
#include <cfintram/CFIntRamServiceTable.hpp>
#include <cfintram/CFIntRamServiceTypeTable.hpp>
#include <cfintram/CFIntRamSubProjectTable.hpp>
#include <cfintram/CFIntRamSysClusterTable.hpp>
#include <cfintram/CFIntRamTSecGroupTable.hpp>
#include <cfintram/CFIntRamTSecGrpIncTable.hpp>
#include <cfintram/CFIntRamTSecGrpMembTable.hpp>
#include <cfintram/CFIntRamTenantTable.hpp>
#include <cfintram/CFIntRamTldTable.hpp>
#include <cfintram/CFIntRamTopDomainTable.hpp>
#include <cfintram/CFIntRamTopProjectTable.hpp>
#include <cfintram/CFIntRamURLProtocolTable.hpp>

using namespace std;

namespace cfint {

	const std::string CFIntRamSecGroupFormTable::CLASS_NAME( "CFIntRamSecGroupFormTable" );

	CFIntRamSecGroupFormTable::CFIntRamSecGroupFormTable( ICFIntSchema* argSchema )
	: cfsec::ICFSecSecGroupFormTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>();
		dictByClusterIdx = new std::map<cfsec::CFSecSecGroupFormByClusterIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>*>();
		dictByGroupIdx = new std::map<cfsec::CFSecSecGroupFormByGroupIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>*>();
		dictByAppIdx = new std::map<cfsec::CFSecSecGroupFormByAppIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>*>();
		dictByFormIdx = new std::map<cfsec::CFSecSecGroupFormByFormIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>*>();
		dictByUFormIdx = new std::map<cfsec::CFSecSecGroupFormByUFormIdxKey, cfsec::CFSecSecGroupFormBuff*>();
	}

	CFIntRamSecGroupFormTable::~CFIntRamSecGroupFormTable() {
		if( dictByClusterIdx != NULL ) {
			for( auto iterDict = dictByClusterIdx->begin(); iterDict != dictByClusterIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByClusterIdx;
			dictByClusterIdx = NULL;
		}
		if( dictByGroupIdx != NULL ) {
			for( auto iterDict = dictByGroupIdx->begin(); iterDict != dictByGroupIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByGroupIdx;
			dictByGroupIdx = NULL;
		}
		if( dictByAppIdx != NULL ) {
			for( auto iterDict = dictByAppIdx->begin(); iterDict != dictByAppIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByAppIdx;
			dictByAppIdx = NULL;
		}
		if( dictByFormIdx != NULL ) {
			for( auto iterDict = dictByFormIdx->begin(); iterDict != dictByFormIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByFormIdx;
			dictByFormIdx = NULL;
		}
		if( dictByUFormIdx != NULL ) {
			delete dictByUFormIdx;
			dictByUFormIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecSecGroupFormBuff* elt;
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecSecGroupFormPKey,
					cfsec::CFSecSecGroupFormBuff*>::iterator cur = dictByPKey->begin();
				cur != end;
				cur ++ )
			{
				elt = cur->second;
				if( elt != NULL ) {
					delete elt;
					elt = NULL;
					cur->second = NULL;
				}
			}
			delete dictByPKey;
			dictByPKey = NULL;
		}
		schema = NULL;
	}

	cfsec::CFSecSecGroupFormBuff* CFIntRamSecGroupFormTable::createSecGroupForm( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecGroupFormBuff* Buff )
	{
		static const std::string S_ProcName( "createSecGroupForm" );
		cfsec::CFSecSecGroupFormPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecGroupFormId( dynamic_cast<CFIntRamClusterTable*>( schema->getTableCluster() )->nextSecGroupFormIdGen( Authorization,
			Buff->getRequiredClusterId() ) );
		Buff->setRequiredClusterId( pkey.getRequiredClusterId() );
		Buff->setRequiredSecGroupFormId( pkey.getRequiredSecGroupFormId() );
		cfsec::CFSecSecGroupFormByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecSecGroupFormByGroupIdxKey keyGroupIdx;
		keyGroupIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyGroupIdx.setRequiredSecGroupId( Buff->getRequiredSecGroupId() );
		cfsec::CFSecSecGroupFormByAppIdxKey keyAppIdx;
		keyAppIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyAppIdx.setRequiredSecAppId( Buff->getRequiredSecAppId() );
		cfsec::CFSecSecGroupFormByFormIdxKey keyFormIdx;
		keyFormIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyFormIdx.setRequiredSecFormId( Buff->getRequiredSecFormId() );
		cfsec::CFSecSecGroupFormByUFormIdxKey keyUFormIdx;
		keyUFormIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		keyUFormIdx.setRequiredSecGroupId( Buff->getRequiredSecGroupId() );
		keyUFormIdx.setRequiredSecFormId( Buff->getRequiredSecFormId() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUFormIdx = dictByUFormIdx->find( keyUFormIdx );
		if( searchDictByUFormIdx != dictByUFormIdx->end() ) {
			std::string Msg( "Duplicate key detected for index SecGroupFormUFormIdx " + keyUFormIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		{
			bool allNull = true;
			allNull = false;
			if( ! allNull ) {
				cfsec::CFSecClusterBuff* chk = dynamic_cast<cfsec::CFSecClusterBuff*>( schema->getTableCluster()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredClusterId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Owner relationship SecGroupFormCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		{
			bool allNull = true;
			allNull = false;
			allNull = false;
			if( ! allNull ) {
				cfsec::CFSecSecGroupBuff* chk = dynamic_cast<cfsec::CFSecSecGroupBuff*>( schema->getTableSecGroup()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredClusterId(),
						Buff->getRequiredSecGroupId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship SecGroupFormGroup to table SecGroup" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecSecGroupFormBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>* subdictClusterIdx;
		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchDictByClusterIdx->second;
		}
		else {
			subdictClusterIdx = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSecGroupFormByClusterIdxKey,
				std::map<cfsec::CFSecSecGroupFormPKey,
					cfsec::CFSecSecGroupFormBuff*>*>::value_type( keyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>* subdictGroupIdx;
		auto searchDictByGroupIdx = dictByGroupIdx->find( keyGroupIdx );
		if( searchDictByGroupIdx != dictByGroupIdx->end() ) {
			subdictGroupIdx = searchDictByGroupIdx->second;
		}
		else {
			subdictGroupIdx = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>();
			dictByGroupIdx->insert( std::map<cfsec::CFSecSecGroupFormByGroupIdxKey,
				std::map<cfsec::CFSecSecGroupFormPKey,
					cfsec::CFSecSecGroupFormBuff*>*>::value_type( keyGroupIdx, subdictGroupIdx ) );
		}
		subdictGroupIdx->insert( std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>* subdictAppIdx;
		auto searchDictByAppIdx = dictByAppIdx->find( keyAppIdx );
		if( searchDictByAppIdx != dictByAppIdx->end() ) {
			subdictAppIdx = searchDictByAppIdx->second;
		}
		else {
			subdictAppIdx = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>();
			dictByAppIdx->insert( std::map<cfsec::CFSecSecGroupFormByAppIdxKey,
				std::map<cfsec::CFSecSecGroupFormPKey,
					cfsec::CFSecSecGroupFormBuff*>*>::value_type( keyAppIdx, subdictAppIdx ) );
		}
		subdictAppIdx->insert( std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>* subdictFormIdx;
		auto searchDictByFormIdx = dictByFormIdx->find( keyFormIdx );
		if( searchDictByFormIdx != dictByFormIdx->end() ) {
			subdictFormIdx = searchDictByFormIdx->second;
		}
		else {
			subdictFormIdx = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>();
			dictByFormIdx->insert( std::map<cfsec::CFSecSecGroupFormByFormIdxKey,
				std::map<cfsec::CFSecSecGroupFormPKey,
					cfsec::CFSecSecGroupFormBuff*>*>::value_type( keyFormIdx, subdictFormIdx ) );
		}
		subdictFormIdx->insert( std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>::value_type( pkey, buff ) );

		dictByUFormIdx->insert( std::map<cfsec::CFSecSecGroupFormByUFormIdxKey, cfsec::CFSecSecGroupFormBuff*>::value_type( keyUFormIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecSecGroupFormBuff* CFIntRamSecGroupFormTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupFormPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecSecGroupFormBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecGroupFormBuff* CFIntRamSecGroupFormTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupFormPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecSecGroupFormBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff->clone() );
			}
			else {
				dictByPKey->erase( searchDictByPKey );
				buff = NULL;
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> retVec;
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecSecGroupFormBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readDerivedByClusterIdx" );
		cfsec::CFSecSecGroupFormByClusterIdxKey key;
		key.setRequiredClusterId( ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> recVec;
		cfsec::CFSecSecGroupFormBuff* clone;
		auto searchDictByClusterIdx = dictByClusterIdx->find( key );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSecGroupFormPKey,
				 cfsec::CFSecSecGroupFormBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>::iterator iter = subdictClusterIdx->begin();
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>::iterator end = subdictClusterIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::readDerivedByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		static const std::string S_ProcName( "readDerivedByGroupIdx" );
		cfsec::CFSecSecGroupFormByGroupIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> recVec;
		cfsec::CFSecSecGroupFormBuff* clone;
		auto searchDictByGroupIdx = dictByGroupIdx->find( key );
		if( searchDictByGroupIdx != dictByGroupIdx->end() ) {
			std::map<cfsec::CFSecSecGroupFormPKey,
				 cfsec::CFSecSecGroupFormBuff*>* subdictGroupIdx = searchDictByGroupIdx->second;
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>::iterator iter = subdictGroupIdx->begin();
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>::iterator end = subdictGroupIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::readDerivedByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId )
	{
		static const std::string S_ProcName( "readDerivedByAppIdx" );
		cfsec::CFSecSecGroupFormByAppIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecAppId( SecAppId );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> recVec;
		cfsec::CFSecSecGroupFormBuff* clone;
		auto searchDictByAppIdx = dictByAppIdx->find( key );
		if( searchDictByAppIdx != dictByAppIdx->end() ) {
			std::map<cfsec::CFSecSecGroupFormPKey,
				 cfsec::CFSecSecGroupFormBuff*>* subdictAppIdx = searchDictByAppIdx->second;
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>::iterator iter = subdictAppIdx->begin();
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>::iterator end = subdictAppIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::readDerivedByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId )
	{
		static const std::string S_ProcName( "readDerivedByFormIdx" );
		cfsec::CFSecSecGroupFormByFormIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecFormId( SecFormId );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> recVec;
		cfsec::CFSecSecGroupFormBuff* clone;
		auto searchDictByFormIdx = dictByFormIdx->find( key );
		if( searchDictByFormIdx != dictByFormIdx->end() ) {
			std::map<cfsec::CFSecSecGroupFormPKey,
				 cfsec::CFSecSecGroupFormBuff*>* subdictFormIdx = searchDictByFormIdx->second;
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>::iterator iter = subdictFormIdx->begin();
			std::map<cfsec::CFSecSecGroupFormPKey,
				cfsec::CFSecSecGroupFormBuff*>::iterator end = subdictFormIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSecGroupFormBuff* CFIntRamSecGroupFormTable::readDerivedByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId )
	{
		static const std::string S_ProcName( "readDerivedByUFormIdx" );
		cfsec::CFSecSecGroupFormByUFormIdxKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupId( SecGroupId );
		key.setRequiredSecFormId( SecFormId );
		cfsec::CFSecSecGroupFormBuff* buff;
		auto searchDictByUFormIdx = dictByUFormIdx->find( key );
		if( searchDictByUFormIdx != dictByUFormIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( searchDictByUFormIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecGroupFormBuff* CFIntRamSecGroupFormTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGroupFormId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecSecGroupFormPKey key;
		key.setRequiredClusterId( ClusterId );
		key.setRequiredSecGroupFormId( SecGroupFormId );
		cfsec::CFSecSecGroupFormBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecGroupFormBuff* CFIntRamSecGroupFormTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupFormPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecSecGroupFormBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff ) );
	}

	cfsec::CFSecSecGroupFormBuff* CFIntRamSecGroupFormTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupFormPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecSecGroupFormBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecSecGroupFormBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecGroupFormBuff* CFIntRamSecGroupFormTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t SecGroupFormId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecSecGroupFormBuff* buff = readDerivedByIdIdx( Authorization,
			ClusterId,
			SecGroupFormId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId )
	{
		static const std::string S_ProcName( "readBuffByClusterIdx" );
		cfsec::CFSecSecGroupFormBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = readDerivedByClusterIdx( Authorization,
			ClusterId );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::readBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId )
	{
		static const std::string S_ProcName( "readBuffByGroupIdx" );
		cfsec::CFSecSecGroupFormBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = readDerivedByGroupIdx( Authorization,
			ClusterId,
			SecGroupId );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::readBuffByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId )
	{
		static const std::string S_ProcName( "readBuffByAppIdx" );
		cfsec::CFSecSecGroupFormBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = readDerivedByAppIdx( Authorization,
			ClusterId,
			SecAppId );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::readBuffByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId )
	{
		static const std::string S_ProcName( "readBuffByFormIdx" );
		cfsec::CFSecSecGroupFormBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> buffList = readDerivedByFormIdx( Authorization,
			ClusterId,
			SecFormId );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSecGroupFormBuff* CFIntRamSecGroupFormTable::readBuffByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId )
	{
		static const std::string S_ProcName( "readBuffByUFormIdx" );
		cfsec::CFSecSecGroupFormBuff* buff = readDerivedByUFormIdx( Authorization,
			ClusterId,
			SecGroupId,
			SecFormId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId )
	{
		static const std::string S_ProcName( "pageBuffByClusterIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::pageBuffByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId )
	{
		static const std::string S_ProcName( "pageBuffByGroupIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::pageBuffByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId )
	{
		static const std::string S_ProcName( "pageBuffByAppIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> CFIntRamSecGroupFormTable::pageBuffByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int32_t SecFormId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId )
	{
		static const std::string S_ProcName( "pageBuffByFormIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecGroupFormBuff* CFIntRamSecGroupFormTable::updateSecGroupForm( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecGroupFormBuff* Buff )
	{
		static const std::string S_ProcName( "updateSecGroupForm" );
		cfsec::CFSecSecGroupFormPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecGroupFormId( Buff->getRequiredSecGroupFormId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in SecGroupForm for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecSecGroupFormBuff* existing = searchExisting->second;

		if( existing == NULL ) {
			delete Buff;
			static const std::string S_Existing( "existing" );
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_Existing );
		}

		// Make sure the buffer classes match

		if( existing->getClassCode() != Buff->getClassCode() ) {
			static const std::string S_DoesNotMatchExisting( " does not match existing " );
			std::string Msg( "Buffer class " );
			Msg.append( cflib::CFLib::formatClassCode( Buff->getClassCode() ) );
			Msg.append( S_DoesNotMatchExisting );
			Msg.append( cflib::CFLib::formatClassCode( existing->getClassCode() ) );
			delete Buff;
			throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
				S_ProcName,
				Msg );
		}
		if( existing->getRequiredRevision() != Buff->getRequiredRevision() ) {
			std::string Msg( "Collision detected for SecGroupForm primary key " );
			Msg.append( pkey.toString() );
			Msg.append( " existing revision " );
			Msg.append( std::to_string( existing->getRequiredRevision() ) );
			Msg.append( " argument buffer revision " );
			Msg.append( std::to_string( Buff->getRequiredRevision() ) );
			delete Buff;
			throw cflib::CFLibCollisionDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}
		cfsec::CFSecSecGroupFormByClusterIdxKey existingKeyClusterIdx;
		existingKeyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecSecGroupFormByClusterIdxKey newKeyClusterIdx;
		newKeyClusterIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		cfsec::CFSecSecGroupFormByGroupIdxKey existingKeyGroupIdx;
		existingKeyGroupIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyGroupIdx.setRequiredSecGroupId( existing->getRequiredSecGroupId() );
		cfsec::CFSecSecGroupFormByGroupIdxKey newKeyGroupIdx;
		newKeyGroupIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyGroupIdx.setRequiredSecGroupId( Buff->getRequiredSecGroupId() );
		cfsec::CFSecSecGroupFormByAppIdxKey existingKeyAppIdx;
		existingKeyAppIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyAppIdx.setRequiredSecAppId( existing->getRequiredSecAppId() );
		cfsec::CFSecSecGroupFormByAppIdxKey newKeyAppIdx;
		newKeyAppIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyAppIdx.setRequiredSecAppId( Buff->getRequiredSecAppId() );
		cfsec::CFSecSecGroupFormByFormIdxKey existingKeyFormIdx;
		existingKeyFormIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyFormIdx.setRequiredSecFormId( existing->getRequiredSecFormId() );
		cfsec::CFSecSecGroupFormByFormIdxKey newKeyFormIdx;
		newKeyFormIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyFormIdx.setRequiredSecFormId( Buff->getRequiredSecFormId() );
		cfsec::CFSecSecGroupFormByUFormIdxKey existingKeyUFormIdx;
		existingKeyUFormIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		existingKeyUFormIdx.setRequiredSecGroupId( existing->getRequiredSecGroupId() );
		existingKeyUFormIdx.setRequiredSecFormId( existing->getRequiredSecFormId() );
		cfsec::CFSecSecGroupFormByUFormIdxKey newKeyUFormIdx;
		newKeyUFormIdx.setRequiredClusterId( Buff->getRequiredClusterId() );
		newKeyUFormIdx.setRequiredSecGroupId( Buff->getRequiredSecGroupId() );
		newKeyUFormIdx.setRequiredSecFormId( Buff->getRequiredSecFormId() );
		// Check unique indexes

		if( existingKeyUFormIdx != newKeyUFormIdx ) {
			auto searchDictByUFormIdx = dictByUFormIdx->find( newKeyUFormIdx );
			if( searchDictByUFormIdx != dictByUFormIdx->end() ) {
				std::string Msg( "Duplicate key detected for index SecGroupFormUFormIdx " + newKeyUFormIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		{
			bool allNull = true;

			if( allNull ) {
				cfsec::CFSecClusterBuff* chk = dynamic_cast<cfsec::CFSecClusterBuff*>( schema->getTableCluster()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredClusterId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Owner relationship SecGroupFormCluster to table Cluster" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		{
			bool allNull = true;

			if( allNull ) {
				cfsec::CFSecSecGroupBuff* chk = dynamic_cast<cfsec::CFSecSecGroupBuff*>( schema->getTableSecGroup()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredClusterId(),
						Buff->getRequiredSecGroupId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship SecGroupFormGroup to table SecGroup" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecSecGroupFormBuff" );
			std::string Msg( "Unsupported buffer class " );
			Msg.append( cflib::CFLib::formatClassCode( Buff->getClassCode() ) );
			Msg.append( S_IsNotA );
			delete Buff;
			throw cflib::CFLibUnsupportedClassException( CLASS_NAME,
				S_ProcName,
				Msg );
		}
		*existing = *Buff;
		existing->setRequiredRevision( existing->getRequiredRevision() + 1 );

		dictByPKey->insert( std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecGroupFormPKey,
			 cfsec::CFSecSecGroupFormBuff*>* subdictClusterIdx;
		auto searchDictByClusterIdx = dictByClusterIdx->find( existingKeyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchDictByClusterIdx->second;
			auto searchSubDict = subdictClusterIdx->find( pkey );
			if( searchSubDict != subdictClusterIdx->end() ) {
				subdictClusterIdx->erase( searchSubDict );
			}
			if( subdictClusterIdx->size() <= 0 ) {
				delete subdictClusterIdx;
				dictByClusterIdx->erase( searchDictByClusterIdx );
			}
			subdictClusterIdx = NULL;
		}
		auto searchNewKeyDictByClusterIdx = dictByClusterIdx->find( newKeyClusterIdx );
		if( searchNewKeyDictByClusterIdx != dictByClusterIdx->end() ) {
			subdictClusterIdx = searchNewKeyDictByClusterIdx->second;
		}
		else {
			subdictClusterIdx = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>();
			dictByClusterIdx->insert( std::map<cfsec::CFSecSecGroupFormByClusterIdxKey,
				std::map<cfsec::CFSecSecGroupFormPKey,
					cfsec::CFSecSecGroupFormBuff*>*>::value_type( newKeyClusterIdx, subdictClusterIdx ) );
		}
		subdictClusterIdx->insert( std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecGroupFormPKey,
			 cfsec::CFSecSecGroupFormBuff*>* subdictGroupIdx;
		auto searchDictByGroupIdx = dictByGroupIdx->find( existingKeyGroupIdx );
		if( searchDictByGroupIdx != dictByGroupIdx->end() ) {
			subdictGroupIdx = searchDictByGroupIdx->second;
			auto searchSubDict = subdictGroupIdx->find( pkey );
			if( searchSubDict != subdictGroupIdx->end() ) {
				subdictGroupIdx->erase( searchSubDict );
			}
			if( subdictGroupIdx->size() <= 0 ) {
				delete subdictGroupIdx;
				dictByGroupIdx->erase( searchDictByGroupIdx );
			}
			subdictGroupIdx = NULL;
		}
		auto searchNewKeyDictByGroupIdx = dictByGroupIdx->find( newKeyGroupIdx );
		if( searchNewKeyDictByGroupIdx != dictByGroupIdx->end() ) {
			subdictGroupIdx = searchNewKeyDictByGroupIdx->second;
		}
		else {
			subdictGroupIdx = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>();
			dictByGroupIdx->insert( std::map<cfsec::CFSecSecGroupFormByGroupIdxKey,
				std::map<cfsec::CFSecSecGroupFormPKey,
					cfsec::CFSecSecGroupFormBuff*>*>::value_type( newKeyGroupIdx, subdictGroupIdx ) );
		}
		subdictGroupIdx->insert( std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecGroupFormPKey,
			 cfsec::CFSecSecGroupFormBuff*>* subdictAppIdx;
		auto searchDictByAppIdx = dictByAppIdx->find( existingKeyAppIdx );
		if( searchDictByAppIdx != dictByAppIdx->end() ) {
			subdictAppIdx = searchDictByAppIdx->second;
			auto searchSubDict = subdictAppIdx->find( pkey );
			if( searchSubDict != subdictAppIdx->end() ) {
				subdictAppIdx->erase( searchSubDict );
			}
			if( subdictAppIdx->size() <= 0 ) {
				delete subdictAppIdx;
				dictByAppIdx->erase( searchDictByAppIdx );
			}
			subdictAppIdx = NULL;
		}
		auto searchNewKeyDictByAppIdx = dictByAppIdx->find( newKeyAppIdx );
		if( searchNewKeyDictByAppIdx != dictByAppIdx->end() ) {
			subdictAppIdx = searchNewKeyDictByAppIdx->second;
		}
		else {
			subdictAppIdx = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>();
			dictByAppIdx->insert( std::map<cfsec::CFSecSecGroupFormByAppIdxKey,
				std::map<cfsec::CFSecSecGroupFormPKey,
					cfsec::CFSecSecGroupFormBuff*>*>::value_type( newKeyAppIdx, subdictAppIdx ) );
		}
		subdictAppIdx->insert( std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecGroupFormPKey,
			 cfsec::CFSecSecGroupFormBuff*>* subdictFormIdx;
		auto searchDictByFormIdx = dictByFormIdx->find( existingKeyFormIdx );
		if( searchDictByFormIdx != dictByFormIdx->end() ) {
			subdictFormIdx = searchDictByFormIdx->second;
			auto searchSubDict = subdictFormIdx->find( pkey );
			if( searchSubDict != subdictFormIdx->end() ) {
				subdictFormIdx->erase( searchSubDict );
			}
			if( subdictFormIdx->size() <= 0 ) {
				delete subdictFormIdx;
				dictByFormIdx->erase( searchDictByFormIdx );
			}
			subdictFormIdx = NULL;
		}
		auto searchNewKeyDictByFormIdx = dictByFormIdx->find( newKeyFormIdx );
		if( searchNewKeyDictByFormIdx != dictByFormIdx->end() ) {
			subdictFormIdx = searchNewKeyDictByFormIdx->second;
		}
		else {
			subdictFormIdx = new std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>();
			dictByFormIdx->insert( std::map<cfsec::CFSecSecGroupFormByFormIdxKey,
				std::map<cfsec::CFSecSecGroupFormPKey,
					cfsec::CFSecSecGroupFormBuff*>*>::value_type( newKeyFormIdx, subdictFormIdx ) );
		}
		subdictFormIdx->insert( std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>::value_type( pkey, existing ) );

		auto removalDictByUFormIdx = dictByUFormIdx->find( existingKeyUFormIdx );
		if( removalDictByUFormIdx != dictByUFormIdx->end() ) {
			dictByUFormIdx->erase( removalDictByUFormIdx );
		}
		dictByUFormIdx->insert( std::map<cfsec::CFSecSecGroupFormByUFormIdxKey, cfsec::CFSecSecGroupFormBuff*>::value_type( newKeyUFormIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecSecGroupFormBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecSecGroupFormBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupForm( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecGroupFormBuff* Buff )
	{
		static const std::string S_ProcName( "deleteSecGroupForm" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecSecGroupFormPKey pkey;
		pkey.setRequiredClusterId( Buff->getRequiredClusterId() );
		pkey.setRequiredSecGroupFormId( Buff->getRequiredSecGroupFormId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecSecGroupFormBuff* existing = searchExisting->second;
		cfsec::CFSecSecGroupFormByClusterIdxKey keyClusterIdx;
		keyClusterIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		cfsec::CFSecSecGroupFormByGroupIdxKey keyGroupIdx;
		keyGroupIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyGroupIdx.setRequiredSecGroupId( existing->getRequiredSecGroupId() );
		cfsec::CFSecSecGroupFormByAppIdxKey keyAppIdx;
		keyAppIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyAppIdx.setRequiredSecAppId( existing->getRequiredSecAppId() );
		cfsec::CFSecSecGroupFormByFormIdxKey keyFormIdx;
		keyFormIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyFormIdx.setRequiredSecFormId( existing->getRequiredSecFormId() );
		cfsec::CFSecSecGroupFormByUFormIdxKey keyUFormIdx;
		keyUFormIdx.setRequiredClusterId( existing->getRequiredClusterId() );
		keyUFormIdx.setRequiredSecGroupId( existing->getRequiredSecGroupId() );
		keyUFormIdx.setRequiredSecFormId( existing->getRequiredSecFormId() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::CFSecSecGroupFormBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByClusterIdx = dictByClusterIdx->find( keyClusterIdx );
		if( searchDictByClusterIdx != dictByClusterIdx->end() ) {
			std::map<cfsec::CFSecSecGroupFormPKey,
				 cfsec::CFSecSecGroupFormBuff*>* subdictClusterIdx = searchDictByClusterIdx->second;
			auto searchSubDict = subdictClusterIdx->find( pkey );
			if( searchSubDict != subdictClusterIdx->end() ) {
				subdictClusterIdx->erase( searchSubDict );
			}
			subdictClusterIdx = NULL;
		}

		auto searchDictByGroupIdx = dictByGroupIdx->find( keyGroupIdx );
		if( searchDictByGroupIdx != dictByGroupIdx->end() ) {
			std::map<cfsec::CFSecSecGroupFormPKey,
				 cfsec::CFSecSecGroupFormBuff*>* subdictGroupIdx = searchDictByGroupIdx->second;
			auto searchSubDict = subdictGroupIdx->find( pkey );
			if( searchSubDict != subdictGroupIdx->end() ) {
				subdictGroupIdx->erase( searchSubDict );
			}
			subdictGroupIdx = NULL;
		}

		auto searchDictByAppIdx = dictByAppIdx->find( keyAppIdx );
		if( searchDictByAppIdx != dictByAppIdx->end() ) {
			std::map<cfsec::CFSecSecGroupFormPKey,
				 cfsec::CFSecSecGroupFormBuff*>* subdictAppIdx = searchDictByAppIdx->second;
			auto searchSubDict = subdictAppIdx->find( pkey );
			if( searchSubDict != subdictAppIdx->end() ) {
				subdictAppIdx->erase( searchSubDict );
			}
			subdictAppIdx = NULL;
		}

		auto searchDictByFormIdx = dictByFormIdx->find( keyFormIdx );
		if( searchDictByFormIdx != dictByFormIdx->end() ) {
			std::map<cfsec::CFSecSecGroupFormPKey,
				 cfsec::CFSecSecGroupFormBuff*>* subdictFormIdx = searchDictByFormIdx->second;
			auto searchSubDict = subdictFormIdx->find( pkey );
			if( searchSubDict != subdictFormIdx->end() ) {
				subdictFormIdx->erase( searchSubDict );
			}
			subdictFormIdx = NULL;
		}

		auto searchDictByUFormIdx = dictByUFormIdx->find( keyUFormIdx );
		if( searchDictByUFormIdx != dictByUFormIdx->end() ) {
			dictByUFormIdx->erase( searchDictByUFormIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int64_t argSecGroupFormId )
	{
		cfsec::CFSecSecGroupFormPKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecGroupFormId( argSecGroupFormId );
		deleteSecGroupFormByIdIdx( Authorization, &key );
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupFormPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecSecGroupFormBuff* cur = NULL;
		cfsec::CFSecSecGroupFormBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> matchSet;
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGroupForm()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGroupFormId() );
			rereadCur = cur;
			deleteSecGroupForm( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId )
	{
		cfsec::CFSecSecGroupFormByClusterIdxKey key;
		key.setRequiredClusterId( argClusterId );
		deleteSecGroupFormByClusterIdx( Authorization, &key );
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupFormByClusterIdxKey* argKey )
	{
		cfsec::CFSecSecGroupFormBuff* cur = NULL;
		cfsec::CFSecSecGroupFormBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> matchSet;
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGroupForm()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGroupFormId() );
			rereadCur = cur;
			deleteSecGroupForm( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId )
	{
		cfsec::CFSecSecGroupFormByGroupIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecGroupId( argSecGroupId );
		deleteSecGroupFormByGroupIdx( Authorization, &key );
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByGroupIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupFormByGroupIdxKey* argKey )
	{
		cfsec::CFSecSecGroupFormBuff* cur = NULL;
		cfsec::CFSecSecGroupFormBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> matchSet;
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGroupForm()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGroupFormId() );
			rereadCur = cur;
			deleteSecGroupForm( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByAppIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecAppId )
	{
		cfsec::CFSecSecGroupFormByAppIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecAppId( argSecAppId );
		deleteSecGroupFormByAppIdx( Authorization, &key );
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByAppIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupFormByAppIdxKey* argKey )
	{
		cfsec::CFSecSecGroupFormBuff* cur = NULL;
		cfsec::CFSecSecGroupFormBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> matchSet;
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGroupForm()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGroupFormId() );
			rereadCur = cur;
			deleteSecGroupForm( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecFormId )
	{
		cfsec::CFSecSecGroupFormByFormIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecFormId( argSecFormId );
		deleteSecGroupFormByFormIdx( Authorization, &key );
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByFormIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupFormByFormIdxKey* argKey )
	{
		cfsec::CFSecSecGroupFormBuff* cur = NULL;
		cfsec::CFSecSecGroupFormBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> matchSet;
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGroupForm()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGroupFormId() );
			rereadCur = cur;
			deleteSecGroupForm( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const int32_t argSecGroupId,
			const int32_t argSecFormId )
	{
		cfsec::CFSecSecGroupFormByUFormIdxKey key;
		key.setRequiredClusterId( argClusterId );
		key.setRequiredSecGroupId( argSecGroupId );
		key.setRequiredSecFormId( argSecFormId );
		deleteSecGroupFormByUFormIdx( Authorization, &key );
	}

	void CFIntRamSecGroupFormTable::deleteSecGroupFormByUFormIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecGroupFormByUFormIdxKey* argKey )
	{
		cfsec::CFSecSecGroupFormBuff* cur = NULL;
		cfsec::CFSecSecGroupFormBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*> matchSet;
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecGroupFormPKey,
			cfsec::CFSecSecGroupFormBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecGroupFormBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupFormBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecGroupForm()->readDerivedByIdIdx( Authorization,
				cur->getRequiredClusterId(),
				cur->getRequiredSecGroupFormId() );
			rereadCur = cur;
			deleteSecGroupForm( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamSecGroupFormTable::releasePreparedStatements() {
	}

}
