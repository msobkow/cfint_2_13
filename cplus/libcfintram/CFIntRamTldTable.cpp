
// Description: C++18 Implementation for an in-memory RAM DbIO for Tld.

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

	const std::string CFIntRamTldTable::CLASS_NAME( "CFIntRamTldTable" );

	CFIntRamTldTable::CFIntRamTldTable( ICFIntSchema* argSchema )
	: cfint::ICFIntTldTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfint::CFIntTldPKey, cfint::CFIntTldBuff*>();
		dictByTenantIdx = new std::map<cfint::CFIntTldByTenantIdxKey,
			std::map<cfint::CFIntTldPKey,
				cfint::CFIntTldBuff*>*>();
		dictByNameIdx = new std::map<cfint::CFIntTldByNameIdxKey, cfint::CFIntTldBuff*>();
	}

	CFIntRamTldTable::~CFIntRamTldTable() {
		if( dictByTenantIdx != NULL ) {
			for( auto iterDict = dictByTenantIdx->begin(); iterDict != dictByTenantIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByTenantIdx;
			dictByTenantIdx = NULL;
		}
		if( dictByNameIdx != NULL ) {
			delete dictByNameIdx;
			dictByNameIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfint::CFIntTldBuff* elt;
			std::map<cfint::CFIntTldPKey,
				cfint::CFIntTldBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfint::CFIntTldPKey,
					cfint::CFIntTldBuff*>::iterator cur = dictByPKey->begin();
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

	cfint::CFIntTldBuff* CFIntRamTldTable::createTld( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntTldBuff* Buff )
	{
		static const std::string S_ProcName( "createTld" );
		cfint::CFIntTldPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( dynamic_cast<CFIntRamTenantTable*>( schema->getTableTenant() )->nextTldIdGen( Authorization,
			Buff->getRequiredTenantId() ) );
		Buff->setRequiredTenantId( pkey.getRequiredTenantId() );
		Buff->setRequiredId( pkey.getRequiredId() );
		cfint::CFIntTldByTenantIdxKey keyTenantIdx;
		keyTenantIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		cfint::CFIntTldByNameIdxKey keyNameIdx;
		keyNameIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		keyNameIdx.setRequiredName( Buff->getRequiredName() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByNameIdx = dictByNameIdx->find( keyNameIdx );
		if( searchDictByNameIdx != dictByNameIdx->end() ) {
			std::string Msg( "Duplicate key detected for index TldNameIdx " + keyNameIdx.toString() );
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
				cfsec::CFSecTenantBuff* chk = dynamic_cast<cfsec::CFSecTenantBuff*>( schema->getTableTenant()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredTenantId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship TldTenant to table Tenant" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfint::CFIntTldBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfint::CFIntTldPKey, cfint::CFIntTldBuff*>::value_type( pkey, buff ) );

		std::map<cfint::CFIntTldPKey, cfint::CFIntTldBuff*>* subdictTenantIdx;
		auto searchDictByTenantIdx = dictByTenantIdx->find( keyTenantIdx );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			subdictTenantIdx = searchDictByTenantIdx->second;
		}
		else {
			subdictTenantIdx = new std::map<cfint::CFIntTldPKey, cfint::CFIntTldBuff*>();
			dictByTenantIdx->insert( std::map<cfint::CFIntTldByTenantIdxKey,
				std::map<cfint::CFIntTldPKey,
					cfint::CFIntTldBuff*>*>::value_type( keyTenantIdx, subdictTenantIdx ) );
		}
		subdictTenantIdx->insert( std::map<cfint::CFIntTldPKey, cfint::CFIntTldBuff*>::value_type( pkey, buff ) );

		dictByNameIdx->insert( std::map<cfint::CFIntTldByNameIdxKey, cfint::CFIntTldBuff*>::value_type( keyNameIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfint::CFIntTldBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfint::CFIntTldBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfint::CFIntTldBuff* CFIntRamTldTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTldPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfint::CFIntTldBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntTldBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntTldBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntTldBuff* CFIntRamTldTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTldPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfint::CFIntTldBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntTldBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntTldBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfint::CFIntTldBuff*> CFIntRamTldTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfint::CFIntTldBuff*> retVec;
		std::map<cfint::CFIntTldPKey,
			cfint::CFIntTldBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntTldPKey,
			cfint::CFIntTldBuff*>::iterator end = dictByPKey->end();
		cfint::CFIntTldBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfint::CFIntTldBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfint::CFIntTldBuff*> CFIntRamTldTable::readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId )
	{
		static const std::string S_ProcName( "readDerivedByTenantIdx" );
		cfint::CFIntTldByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::TCFLibOwningVector<cfint::CFIntTldBuff*> recVec;
		cfint::CFIntTldBuff* clone;
		auto searchDictByTenantIdx = dictByTenantIdx->find( key );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			std::map<cfint::CFIntTldPKey,
				 cfint::CFIntTldBuff*>* subdictTenantIdx = searchDictByTenantIdx->second;
			std::map<cfint::CFIntTldPKey,
				cfint::CFIntTldBuff*>::iterator iter = subdictTenantIdx->begin();
			std::map<cfint::CFIntTldPKey,
				cfint::CFIntTldBuff*>::iterator end = subdictTenantIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfint::CFIntTldBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfint::CFIntTldBuff* CFIntRamTldTable::readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readDerivedByNameIdx" );
		cfint::CFIntTldByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredName( Name );
		cfint::CFIntTldBuff* buff;
		auto searchDictByNameIdx = dictByNameIdx->find( key );
		if( searchDictByNameIdx != dictByNameIdx->end() ) {
			buff = dynamic_cast<cfint::CFIntTldBuff*>( searchDictByNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntTldBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntTldBuff* CFIntRamTldTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfint::CFIntTldPKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredId( Id );
		cfint::CFIntTldBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntTldBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntTldBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntTldBuff* CFIntRamTldTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTldPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfint::CFIntTldBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfint::CFIntTldBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfint::CFIntTldBuff*>( buff ) );
	}

	cfint::CFIntTldBuff* CFIntRamTldTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTldPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfint::CFIntTldBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfint::CFIntTldBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfint::CFIntTldBuff*> CFIntRamTldTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfint::CFIntTldBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntTldBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntTldBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfint::CFIntTldBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntTldBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntTldBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntTldBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfint::CFIntTldBuff* CFIntRamTldTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfint::CFIntTldBuff* buff = readDerivedByIdIdx( Authorization,
			TenantId,
			Id );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntTldBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntTldBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfint::CFIntTldBuff*> CFIntRamTldTable::readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId )
	{
		static const std::string S_ProcName( "readBuffByTenantIdx" );
		cfint::CFIntTldBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntTldBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntTldBuff*> buffList = readDerivedByTenantIdx( Authorization,
			TenantId );
		std::TCFLibOwningVector<cfint::CFIntTldBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntTldBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntTldBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntTldBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfint::CFIntTldBuff* CFIntRamTldTable::readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readBuffByNameIdx" );
		cfint::CFIntTldBuff* buff = readDerivedByNameIdx( Authorization,
			TenantId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntTldBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntTldBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntTldBuff* CFIntRamTldTable::readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupNameIdx" );
		cfint::CFIntTldBuff* buff = readBuffByNameIdx( Authorization,
			TenantId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntTldBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntTldBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntTldBuff* CFIntRamTldTable::readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupNameIdx" );
		cfint::CFIntTldBuff* buff = readDerivedByNameIdx( Authorization,
			TenantId,
			Name );
		if( buff != NULL ) {
			return( dynamic_cast<cfint::CFIntTldBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfint::CFIntTldBuff* CFIntRamTldTable::updateTld( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntTldBuff* Buff )
	{
		static const std::string S_ProcName( "updateTld" );
		cfint::CFIntTldPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( Buff->getRequiredId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in Tld for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfint::CFIntTldBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for Tld primary key " );
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
		cfint::CFIntTldByTenantIdxKey existingKeyTenantIdx;
		existingKeyTenantIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		cfint::CFIntTldByTenantIdxKey newKeyTenantIdx;
		newKeyTenantIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		cfint::CFIntTldByNameIdxKey existingKeyNameIdx;
		existingKeyNameIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		existingKeyNameIdx.setRequiredName( existing->getRequiredName() );
		cfint::CFIntTldByNameIdxKey newKeyNameIdx;
		newKeyNameIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		newKeyNameIdx.setRequiredName( Buff->getRequiredName() );
		// Check unique indexes

		if( existingKeyNameIdx != newKeyNameIdx ) {
			auto searchDictByNameIdx = dictByNameIdx->find( newKeyNameIdx );
			if( searchDictByNameIdx != dictByNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index TldNameIdx " + newKeyNameIdx.toString() );
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
				cfsec::CFSecTenantBuff* chk = dynamic_cast<cfsec::CFSecTenantBuff*>( schema->getTableTenant()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredTenantId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship TldTenant to table Tenant" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfint::CFIntTldPKey, cfint::CFIntTldBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfint::CFIntTldBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfint::CFIntTldBuff" );
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

		dictByPKey->insert( std::map<cfint::CFIntTldPKey, cfint::CFIntTldBuff*>::value_type( pkey, existing ) );

		std::map<cfint::CFIntTldPKey,
			 cfint::CFIntTldBuff*>* subdictTenantIdx;
		auto searchDictByTenantIdx = dictByTenantIdx->find( existingKeyTenantIdx );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			subdictTenantIdx = searchDictByTenantIdx->second;
			auto searchSubDict = subdictTenantIdx->find( pkey );
			if( searchSubDict != subdictTenantIdx->end() ) {
				subdictTenantIdx->erase( searchSubDict );
			}
			if( subdictTenantIdx->size() <= 0 ) {
				delete subdictTenantIdx;
				dictByTenantIdx->erase( searchDictByTenantIdx );
			}
			subdictTenantIdx = NULL;
		}
		auto searchNewKeyDictByTenantIdx = dictByTenantIdx->find( newKeyTenantIdx );
		if( searchNewKeyDictByTenantIdx != dictByTenantIdx->end() ) {
			subdictTenantIdx = searchNewKeyDictByTenantIdx->second;
		}
		else {
			subdictTenantIdx = new std::map<cfint::CFIntTldPKey, cfint::CFIntTldBuff*>();
			dictByTenantIdx->insert( std::map<cfint::CFIntTldByTenantIdxKey,
				std::map<cfint::CFIntTldPKey,
					cfint::CFIntTldBuff*>*>::value_type( newKeyTenantIdx, subdictTenantIdx ) );
		}
		subdictTenantIdx->insert( std::map<cfint::CFIntTldPKey, cfint::CFIntTldBuff*>::value_type( pkey, existing ) );

		auto removalDictByNameIdx = dictByNameIdx->find( existingKeyNameIdx );
		if( removalDictByNameIdx != dictByNameIdx->end() ) {
			dictByNameIdx->erase( removalDictByNameIdx );
		}
		dictByNameIdx->insert( std::map<cfint::CFIntTldByNameIdxKey, cfint::CFIntTldBuff*>::value_type( newKeyNameIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfint::CFIntTldBuff* buff;
		if( existing->getClassCode() == cfint::CFIntTldBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfint::CFIntTldBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFIntRamTldTable::deleteTld( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntTldBuff* Buff )
	{
		static const std::string S_ProcName( "deleteTld" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfint::CFIntTldPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( Buff->getRequiredId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfint::CFIntTldBuff* existing = searchExisting->second;
		schema->getTableTopDomain()->deleteTopDomainByTldIdx( Authorization,
			existing->getRequiredTenantId(),
			existing->getRequiredId() );
		cfint::CFIntTldByTenantIdxKey keyTenantIdx;
		keyTenantIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		cfint::CFIntTldByNameIdxKey keyNameIdx;
		keyNameIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		keyNameIdx.setRequiredName( existing->getRequiredName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfint::CFIntTldPKey, cfint::CFIntTldBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByTenantIdx = dictByTenantIdx->find( keyTenantIdx );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			std::map<cfint::CFIntTldPKey,
				 cfint::CFIntTldBuff*>* subdictTenantIdx = searchDictByTenantIdx->second;
			auto searchSubDict = subdictTenantIdx->find( pkey );
			if( searchSubDict != subdictTenantIdx->end() ) {
				subdictTenantIdx->erase( searchSubDict );
			}
			subdictTenantIdx = NULL;
		}

		auto searchDictByNameIdx = dictByNameIdx->find( keyNameIdx );
		if( searchDictByNameIdx != dictByNameIdx->end() ) {
			dictByNameIdx->erase( searchDictByNameIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFIntRamTldTable::deleteTldByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId )
	{
		cfint::CFIntTldPKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredId( argId );
		deleteTldByIdIdx( Authorization, &key );
	}

	void CFIntRamTldTable::deleteTldByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTldPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfint::CFIntTldBuff* cur = NULL;
		cfint::CFIntTldBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfint::CFIntTldBuff*> matchSet;
		std::map<cfint::CFIntTldPKey,
			cfint::CFIntTldBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntTldPKey,
			cfint::CFIntTldBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntTldBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntTldBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntTldBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntTldBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTld()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteTld( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFIntRamTldTable::deleteTldByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId )
	{
		cfint::CFIntTldByTenantIdxKey key;
		key.setRequiredTenantId( argTenantId );
		deleteTldByTenantIdx( Authorization, &key );
	}

	void CFIntRamTldTable::deleteTldByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTldByTenantIdxKey* argKey )
	{
		cfint::CFIntTldBuff* cur = NULL;
		cfint::CFIntTldBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntTldBuff*> matchSet;
		std::map<cfint::CFIntTldPKey,
			cfint::CFIntTldBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntTldPKey,
			cfint::CFIntTldBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntTldBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntTldBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntTldBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntTldBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTld()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteTld( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamTldTable::deleteTldByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const std::string& argName )
	{
		cfint::CFIntTldByNameIdxKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredName( argName );
		deleteTldByNameIdx( Authorization, &key );
	}

	void CFIntRamTldTable::deleteTldByNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTldByNameIdxKey* argKey )
	{
		cfint::CFIntTldBuff* cur = NULL;
		cfint::CFIntTldBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntTldBuff*> matchSet;
		std::map<cfint::CFIntTldPKey,
			cfint::CFIntTldBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntTldPKey,
			cfint::CFIntTldBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntTldBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntTldBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntTldBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntTldBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTld()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteTld( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamTldTable::releasePreparedStatements() {
	}

}
