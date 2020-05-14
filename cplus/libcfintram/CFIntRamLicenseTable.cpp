
// Description: C++18 Implementation for an in-memory RAM DbIO for License.

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

	const std::string CFIntRamLicenseTable::CLASS_NAME( "CFIntRamLicenseTable" );

	CFIntRamLicenseTable::CFIntRamLicenseTable( ICFIntSchema* argSchema )
	: cfint::ICFIntLicenseTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>();
		dictByLicnTenantIdx = new std::map<cfint::CFIntLicenseByLicnTenantIdxKey,
			std::map<cfint::CFIntLicensePKey,
				cfint::CFIntLicenseBuff*>*>();
		dictByDomainIdx = new std::map<cfint::CFIntLicenseByDomainIdxKey,
			std::map<cfint::CFIntLicensePKey,
				cfint::CFIntLicenseBuff*>*>();
		dictByUNameIdx = new std::map<cfint::CFIntLicenseByUNameIdxKey, cfint::CFIntLicenseBuff*>();
	}

	CFIntRamLicenseTable::~CFIntRamLicenseTable() {
		if( dictByLicnTenantIdx != NULL ) {
			for( auto iterDict = dictByLicnTenantIdx->begin(); iterDict != dictByLicnTenantIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByLicnTenantIdx;
			dictByLicnTenantIdx = NULL;
		}
		if( dictByDomainIdx != NULL ) {
			for( auto iterDict = dictByDomainIdx->begin(); iterDict != dictByDomainIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByDomainIdx;
			dictByDomainIdx = NULL;
		}
		if( dictByUNameIdx != NULL ) {
			delete dictByUNameIdx;
			dictByUNameIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfint::CFIntLicenseBuff* elt;
			std::map<cfint::CFIntLicensePKey,
				cfint::CFIntLicenseBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfint::CFIntLicensePKey,
					cfint::CFIntLicenseBuff*>::iterator cur = dictByPKey->begin();
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

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::createLicense( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntLicenseBuff* Buff )
	{
		static const std::string S_ProcName( "createLicense" );
		cfint::CFIntLicensePKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( dynamic_cast<CFIntRamTenantTable*>( schema->getTableTenant() )->nextLicenseIdGen( Authorization,
			Buff->getRequiredTenantId() ) );
		Buff->setRequiredTenantId( pkey.getRequiredTenantId() );
		Buff->setRequiredId( pkey.getRequiredId() );
		cfint::CFIntLicenseByLicnTenantIdxKey keyLicnTenantIdx;
		keyLicnTenantIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		cfint::CFIntLicenseByDomainIdxKey keyDomainIdx;
		keyDomainIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		keyDomainIdx.setRequiredTopDomainId( Buff->getRequiredTopDomainId() );
		cfint::CFIntLicenseByUNameIdxKey keyUNameIdx;
		keyUNameIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		keyUNameIdx.setRequiredTopDomainId( Buff->getRequiredTopDomainId() );
		keyUNameIdx.setRequiredName( Buff->getRequiredName() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUNameIdx = dictByUNameIdx->find( keyUNameIdx );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			std::string Msg( "Duplicate key detected for index LicenseUNameIdx " + keyUNameIdx.toString() );
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
					std::string Msg( "Could not resolve Owner relationship Owner to table Tenant" );
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
				cfint::CFIntTopDomainBuff* chk = dynamic_cast<cfint::CFIntTopDomainBuff*>( schema->getTableTopDomain()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredTenantId(),
						Buff->getRequiredTopDomainId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship TopDomain to table TopDomain" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfint::CFIntLicenseBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>::value_type( pkey, buff ) );

		std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>* subdictLicnTenantIdx;
		auto searchDictByLicnTenantIdx = dictByLicnTenantIdx->find( keyLicnTenantIdx );
		if( searchDictByLicnTenantIdx != dictByLicnTenantIdx->end() ) {
			subdictLicnTenantIdx = searchDictByLicnTenantIdx->second;
		}
		else {
			subdictLicnTenantIdx = new std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>();
			dictByLicnTenantIdx->insert( std::map<cfint::CFIntLicenseByLicnTenantIdxKey,
				std::map<cfint::CFIntLicensePKey,
					cfint::CFIntLicenseBuff*>*>::value_type( keyLicnTenantIdx, subdictLicnTenantIdx ) );
		}
		subdictLicnTenantIdx->insert( std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>::value_type( pkey, buff ) );

		std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>* subdictDomainIdx;
		auto searchDictByDomainIdx = dictByDomainIdx->find( keyDomainIdx );
		if( searchDictByDomainIdx != dictByDomainIdx->end() ) {
			subdictDomainIdx = searchDictByDomainIdx->second;
		}
		else {
			subdictDomainIdx = new std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>();
			dictByDomainIdx->insert( std::map<cfint::CFIntLicenseByDomainIdxKey,
				std::map<cfint::CFIntLicensePKey,
					cfint::CFIntLicenseBuff*>*>::value_type( keyDomainIdx, subdictDomainIdx ) );
		}
		subdictDomainIdx->insert( std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>::value_type( pkey, buff ) );

		dictByUNameIdx->insert( std::map<cfint::CFIntLicenseByUNameIdxKey, cfint::CFIntLicenseBuff*>::value_type( keyUNameIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfint::CFIntLicenseBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfint::CFIntLicenseBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntLicensePKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfint::CFIntLicenseBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntLicenseBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntLicenseBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntLicensePKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfint::CFIntLicenseBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntLicenseBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntLicenseBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> CFIntRamLicenseTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> retVec;
		std::map<cfint::CFIntLicensePKey,
			cfint::CFIntLicenseBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntLicensePKey,
			cfint::CFIntLicenseBuff*>::iterator end = dictByPKey->end();
		cfint::CFIntLicenseBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfint::CFIntLicenseBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> CFIntRamLicenseTable::readDerivedByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId )
	{
		static const std::string S_ProcName( "readDerivedByLicnTenantIdx" );
		cfint::CFIntLicenseByLicnTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> recVec;
		cfint::CFIntLicenseBuff* clone;
		auto searchDictByLicnTenantIdx = dictByLicnTenantIdx->find( key );
		if( searchDictByLicnTenantIdx != dictByLicnTenantIdx->end() ) {
			std::map<cfint::CFIntLicensePKey,
				 cfint::CFIntLicenseBuff*>* subdictLicnTenantIdx = searchDictByLicnTenantIdx->second;
			std::map<cfint::CFIntLicensePKey,
				cfint::CFIntLicenseBuff*>::iterator iter = subdictLicnTenantIdx->begin();
			std::map<cfint::CFIntLicensePKey,
				cfint::CFIntLicenseBuff*>::iterator end = subdictLicnTenantIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfint::CFIntLicenseBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> CFIntRamLicenseTable::readDerivedByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId )
	{
		static const std::string S_ProcName( "readDerivedByDomainIdx" );
		cfint::CFIntLicenseByDomainIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> recVec;
		cfint::CFIntLicenseBuff* clone;
		auto searchDictByDomainIdx = dictByDomainIdx->find( key );
		if( searchDictByDomainIdx != dictByDomainIdx->end() ) {
			std::map<cfint::CFIntLicensePKey,
				 cfint::CFIntLicenseBuff*>* subdictDomainIdx = searchDictByDomainIdx->second;
			std::map<cfint::CFIntLicensePKey,
				cfint::CFIntLicenseBuff*>::iterator iter = subdictDomainIdx->begin();
			std::map<cfint::CFIntLicensePKey,
				cfint::CFIntLicenseBuff*>::iterator end = subdictDomainIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfint::CFIntLicenseBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readDerivedByUNameIdx" );
		cfint::CFIntLicenseByUNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::CFIntLicenseBuff* buff;
		auto searchDictByUNameIdx = dictByUNameIdx->find( key );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			buff = dynamic_cast<cfint::CFIntLicenseBuff*>( searchDictByUNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntLicenseBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfint::CFIntLicensePKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredId( Id );
		cfint::CFIntLicenseBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntLicenseBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntLicenseBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntLicensePKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfint::CFIntLicenseBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfint::CFIntLicenseBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfint::CFIntLicenseBuff*>( buff ) );
	}

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntLicensePKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfint::CFIntLicenseBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfint::CFIntLicenseBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> CFIntRamLicenseTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfint::CFIntLicenseBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntLicenseBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntLicenseBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfint::CFIntLicenseBuff* buff = readDerivedByIdIdx( Authorization,
			TenantId,
			Id );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntLicenseBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntLicenseBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> CFIntRamLicenseTable::readBuffByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId )
	{
		static const std::string S_ProcName( "readBuffByLicnTenantIdx" );
		cfint::CFIntLicenseBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> buffList = readDerivedByLicnTenantIdx( Authorization,
			TenantId );
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntLicenseBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntLicenseBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> CFIntRamLicenseTable::readBuffByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId )
	{
		static const std::string S_ProcName( "readBuffByDomainIdx" );
		cfint::CFIntLicenseBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> buffList = readDerivedByDomainIdx( Authorization,
			TenantId,
			TopDomainId );
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntLicenseBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntLicenseBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readBuffByUNameIdx" );
		cfint::CFIntLicenseBuff* buff = readDerivedByUNameIdx( Authorization,
			TenantId,
			TopDomainId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntLicenseBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntLicenseBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUNameIdx" );
		cfint::CFIntLicenseBuff* buff = readBuffByUNameIdx( Authorization,
			TenantId,
			TopDomainId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntLicenseBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntLicenseBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUNameIdx" );
		cfint::CFIntLicenseBuff* buff = readDerivedByUNameIdx( Authorization,
			TenantId,
			TopDomainId,
			Name );
		if( buff != NULL ) {
			return( dynamic_cast<cfint::CFIntLicenseBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfint::CFIntLicenseBuff* CFIntRamLicenseTable::updateLicense( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntLicenseBuff* Buff )
	{
		static const std::string S_ProcName( "updateLicense" );
		cfint::CFIntLicensePKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( Buff->getRequiredId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in License for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfint::CFIntLicenseBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for License primary key " );
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
		cfint::CFIntLicenseByLicnTenantIdxKey existingKeyLicnTenantIdx;
		existingKeyLicnTenantIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		cfint::CFIntLicenseByLicnTenantIdxKey newKeyLicnTenantIdx;
		newKeyLicnTenantIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		cfint::CFIntLicenseByDomainIdxKey existingKeyDomainIdx;
		existingKeyDomainIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		existingKeyDomainIdx.setRequiredTopDomainId( existing->getRequiredTopDomainId() );
		cfint::CFIntLicenseByDomainIdxKey newKeyDomainIdx;
		newKeyDomainIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		newKeyDomainIdx.setRequiredTopDomainId( Buff->getRequiredTopDomainId() );
		cfint::CFIntLicenseByUNameIdxKey existingKeyUNameIdx;
		existingKeyUNameIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		existingKeyUNameIdx.setRequiredTopDomainId( existing->getRequiredTopDomainId() );
		existingKeyUNameIdx.setRequiredName( existing->getRequiredName() );
		cfint::CFIntLicenseByUNameIdxKey newKeyUNameIdx;
		newKeyUNameIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		newKeyUNameIdx.setRequiredTopDomainId( Buff->getRequiredTopDomainId() );
		newKeyUNameIdx.setRequiredName( Buff->getRequiredName() );
		// Check unique indexes

		if( existingKeyUNameIdx != newKeyUNameIdx ) {
			auto searchDictByUNameIdx = dictByUNameIdx->find( newKeyUNameIdx );
			if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index LicenseUNameIdx " + newKeyUNameIdx.toString() );
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
					std::string Msg( "Could not resolve Owner relationship Owner to table Tenant" );
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
				cfint::CFIntTopDomainBuff* chk = dynamic_cast<cfint::CFIntTopDomainBuff*>( schema->getTableTopDomain()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredTenantId(),
						Buff->getRequiredTopDomainId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship TopDomain to table TopDomain" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfint::CFIntLicenseBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfint::CFIntLicenseBuff" );
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

		dictByPKey->insert( std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>::value_type( pkey, existing ) );

		std::map<cfint::CFIntLicensePKey,
			 cfint::CFIntLicenseBuff*>* subdictLicnTenantIdx;
		auto searchDictByLicnTenantIdx = dictByLicnTenantIdx->find( existingKeyLicnTenantIdx );
		if( searchDictByLicnTenantIdx != dictByLicnTenantIdx->end() ) {
			subdictLicnTenantIdx = searchDictByLicnTenantIdx->second;
			auto searchSubDict = subdictLicnTenantIdx->find( pkey );
			if( searchSubDict != subdictLicnTenantIdx->end() ) {
				subdictLicnTenantIdx->erase( searchSubDict );
			}
			if( subdictLicnTenantIdx->size() <= 0 ) {
				delete subdictLicnTenantIdx;
				dictByLicnTenantIdx->erase( searchDictByLicnTenantIdx );
			}
			subdictLicnTenantIdx = NULL;
		}
		auto searchNewKeyDictByLicnTenantIdx = dictByLicnTenantIdx->find( newKeyLicnTenantIdx );
		if( searchNewKeyDictByLicnTenantIdx != dictByLicnTenantIdx->end() ) {
			subdictLicnTenantIdx = searchNewKeyDictByLicnTenantIdx->second;
		}
		else {
			subdictLicnTenantIdx = new std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>();
			dictByLicnTenantIdx->insert( std::map<cfint::CFIntLicenseByLicnTenantIdxKey,
				std::map<cfint::CFIntLicensePKey,
					cfint::CFIntLicenseBuff*>*>::value_type( newKeyLicnTenantIdx, subdictLicnTenantIdx ) );
		}
		subdictLicnTenantIdx->insert( std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>::value_type( pkey, existing ) );

		std::map<cfint::CFIntLicensePKey,
			 cfint::CFIntLicenseBuff*>* subdictDomainIdx;
		auto searchDictByDomainIdx = dictByDomainIdx->find( existingKeyDomainIdx );
		if( searchDictByDomainIdx != dictByDomainIdx->end() ) {
			subdictDomainIdx = searchDictByDomainIdx->second;
			auto searchSubDict = subdictDomainIdx->find( pkey );
			if( searchSubDict != subdictDomainIdx->end() ) {
				subdictDomainIdx->erase( searchSubDict );
			}
			if( subdictDomainIdx->size() <= 0 ) {
				delete subdictDomainIdx;
				dictByDomainIdx->erase( searchDictByDomainIdx );
			}
			subdictDomainIdx = NULL;
		}
		auto searchNewKeyDictByDomainIdx = dictByDomainIdx->find( newKeyDomainIdx );
		if( searchNewKeyDictByDomainIdx != dictByDomainIdx->end() ) {
			subdictDomainIdx = searchNewKeyDictByDomainIdx->second;
		}
		else {
			subdictDomainIdx = new std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>();
			dictByDomainIdx->insert( std::map<cfint::CFIntLicenseByDomainIdxKey,
				std::map<cfint::CFIntLicensePKey,
					cfint::CFIntLicenseBuff*>*>::value_type( newKeyDomainIdx, subdictDomainIdx ) );
		}
		subdictDomainIdx->insert( std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>::value_type( pkey, existing ) );

		auto removalDictByUNameIdx = dictByUNameIdx->find( existingKeyUNameIdx );
		if( removalDictByUNameIdx != dictByUNameIdx->end() ) {
			dictByUNameIdx->erase( removalDictByUNameIdx );
		}
		dictByUNameIdx->insert( std::map<cfint::CFIntLicenseByUNameIdxKey, cfint::CFIntLicenseBuff*>::value_type( newKeyUNameIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfint::CFIntLicenseBuff* buff;
		if( existing->getClassCode() == cfint::CFIntLicenseBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfint::CFIntLicenseBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFIntRamLicenseTable::deleteLicense( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntLicenseBuff* Buff )
	{
		static const std::string S_ProcName( "deleteLicense" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfint::CFIntLicensePKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( Buff->getRequiredId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfint::CFIntLicenseBuff* existing = searchExisting->second;
		cfint::CFIntLicenseByLicnTenantIdxKey keyLicnTenantIdx;
		keyLicnTenantIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		cfint::CFIntLicenseByDomainIdxKey keyDomainIdx;
		keyDomainIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		keyDomainIdx.setRequiredTopDomainId( existing->getRequiredTopDomainId() );
		cfint::CFIntLicenseByUNameIdxKey keyUNameIdx;
		keyUNameIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		keyUNameIdx.setRequiredTopDomainId( existing->getRequiredTopDomainId() );
		keyUNameIdx.setRequiredName( existing->getRequiredName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfint::CFIntLicensePKey, cfint::CFIntLicenseBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByLicnTenantIdx = dictByLicnTenantIdx->find( keyLicnTenantIdx );
		if( searchDictByLicnTenantIdx != dictByLicnTenantIdx->end() ) {
			std::map<cfint::CFIntLicensePKey,
				 cfint::CFIntLicenseBuff*>* subdictLicnTenantIdx = searchDictByLicnTenantIdx->second;
			auto searchSubDict = subdictLicnTenantIdx->find( pkey );
			if( searchSubDict != subdictLicnTenantIdx->end() ) {
				subdictLicnTenantIdx->erase( searchSubDict );
			}
			subdictLicnTenantIdx = NULL;
		}

		auto searchDictByDomainIdx = dictByDomainIdx->find( keyDomainIdx );
		if( searchDictByDomainIdx != dictByDomainIdx->end() ) {
			std::map<cfint::CFIntLicensePKey,
				 cfint::CFIntLicenseBuff*>* subdictDomainIdx = searchDictByDomainIdx->second;
			auto searchSubDict = subdictDomainIdx->find( pkey );
			if( searchSubDict != subdictDomainIdx->end() ) {
				subdictDomainIdx->erase( searchSubDict );
			}
			subdictDomainIdx = NULL;
		}

		auto searchDictByUNameIdx = dictByUNameIdx->find( keyUNameIdx );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			dictByUNameIdx->erase( searchDictByUNameIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFIntRamLicenseTable::deleteLicenseByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId )
	{
		cfint::CFIntLicensePKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredId( argId );
		deleteLicenseByIdIdx( Authorization, &key );
	}

	void CFIntRamLicenseTable::deleteLicenseByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntLicensePKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfint::CFIntLicenseBuff* cur = NULL;
		cfint::CFIntLicenseBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> matchSet;
		std::map<cfint::CFIntLicensePKey,
			cfint::CFIntLicenseBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntLicensePKey,
			cfint::CFIntLicenseBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntLicenseBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntLicenseBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableLicense()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteLicense( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFIntRamLicenseTable::deleteLicenseByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId )
	{
		cfint::CFIntLicenseByLicnTenantIdxKey key;
		key.setRequiredTenantId( argTenantId );
		deleteLicenseByLicnTenantIdx( Authorization, &key );
	}

	void CFIntRamLicenseTable::deleteLicenseByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntLicenseByLicnTenantIdxKey* argKey )
	{
		cfint::CFIntLicenseBuff* cur = NULL;
		cfint::CFIntLicenseBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> matchSet;
		std::map<cfint::CFIntLicensePKey,
			cfint::CFIntLicenseBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntLicensePKey,
			cfint::CFIntLicenseBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntLicenseBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntLicenseBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableLicense()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteLicense( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamLicenseTable::deleteLicenseByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId )
	{
		cfint::CFIntLicenseByDomainIdxKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredTopDomainId( argTopDomainId );
		deleteLicenseByDomainIdx( Authorization, &key );
	}

	void CFIntRamLicenseTable::deleteLicenseByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntLicenseByDomainIdxKey* argKey )
	{
		cfint::CFIntLicenseBuff* cur = NULL;
		cfint::CFIntLicenseBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> matchSet;
		std::map<cfint::CFIntLicensePKey,
			cfint::CFIntLicenseBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntLicensePKey,
			cfint::CFIntLicenseBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntLicenseBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntLicenseBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableLicense()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteLicense( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamLicenseTable::deleteLicenseByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId,
			const std::string& argName )
	{
		cfint::CFIntLicenseByUNameIdxKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredTopDomainId( argTopDomainId );
		key.setRequiredName( argName );
		deleteLicenseByUNameIdx( Authorization, &key );
	}

	void CFIntRamLicenseTable::deleteLicenseByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntLicenseByUNameIdxKey* argKey )
	{
		cfint::CFIntLicenseBuff* cur = NULL;
		cfint::CFIntLicenseBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> matchSet;
		std::map<cfint::CFIntLicensePKey,
			cfint::CFIntLicenseBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntLicensePKey,
			cfint::CFIntLicenseBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntLicenseBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntLicenseBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntLicenseBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableLicense()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteLicense( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamLicenseTable::releasePreparedStatements() {
	}

}
