
// Description: C++18 Implementation for an in-memory RAM DbIO for MajorVersion.

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

	const std::string CFIntRamMajorVersionTable::CLASS_NAME( "CFIntRamMajorVersionTable" );

	CFIntRamMajorVersionTable::CFIntRamMajorVersionTable( ICFIntSchema* argSchema )
	: cfint::ICFIntMajorVersionTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>();
		dictByTenantIdx = new std::map<cfint::CFIntMajorVersionByTenantIdxKey,
			std::map<cfint::CFIntMajorVersionPKey,
				cfint::CFIntMajorVersionBuff*>*>();
		dictBySubProjectIdx = new std::map<cfint::CFIntMajorVersionBySubProjectIdxKey,
			std::map<cfint::CFIntMajorVersionPKey,
				cfint::CFIntMajorVersionBuff*>*>();
		dictByNameIdx = new std::map<cfint::CFIntMajorVersionByNameIdxKey, cfint::CFIntMajorVersionBuff*>();
	}

	CFIntRamMajorVersionTable::~CFIntRamMajorVersionTable() {
		if( dictByTenantIdx != NULL ) {
			for( auto iterDict = dictByTenantIdx->begin(); iterDict != dictByTenantIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByTenantIdx;
			dictByTenantIdx = NULL;
		}
		if( dictBySubProjectIdx != NULL ) {
			for( auto iterDict = dictBySubProjectIdx->begin(); iterDict != dictBySubProjectIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictBySubProjectIdx;
			dictBySubProjectIdx = NULL;
		}
		if( dictByNameIdx != NULL ) {
			delete dictByNameIdx;
			dictByNameIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfint::CFIntMajorVersionBuff* elt;
			std::map<cfint::CFIntMajorVersionPKey,
				cfint::CFIntMajorVersionBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfint::CFIntMajorVersionPKey,
					cfint::CFIntMajorVersionBuff*>::iterator cur = dictByPKey->begin();
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

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::createMajorVersion( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntMajorVersionBuff* Buff )
	{
		static const std::string S_ProcName( "createMajorVersion" );
		cfint::CFIntMajorVersionPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( dynamic_cast<CFIntRamTenantTable*>( schema->getTableTenant() )->nextMajorVersionIdGen( Authorization,
			Buff->getRequiredTenantId() ) );
		Buff->setRequiredTenantId( pkey.getRequiredTenantId() );
		Buff->setRequiredId( pkey.getRequiredId() );
		cfint::CFIntMajorVersionByTenantIdxKey keyTenantIdx;
		keyTenantIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		cfint::CFIntMajorVersionBySubProjectIdxKey keySubProjectIdx;
		keySubProjectIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		keySubProjectIdx.setRequiredSubProjectId( Buff->getRequiredSubProjectId() );
		cfint::CFIntMajorVersionByNameIdxKey keyNameIdx;
		keyNameIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		keyNameIdx.setRequiredSubProjectId( Buff->getRequiredSubProjectId() );
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
			std::string Msg( "Duplicate key detected for index MajorVersionNameIdx " + keyNameIdx.toString() );
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
					std::string Msg( "Could not resolve Owner relationship Tenant to table Tenant" );
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
				cfint::CFIntSubProjectBuff* chk = dynamic_cast<cfint::CFIntSubProjectBuff*>( schema->getTableSubProject()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredTenantId(),
						Buff->getRequiredSubProjectId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship ParentSubProject to table SubProject" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfint::CFIntMajorVersionBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>::value_type( pkey, buff ) );

		std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>* subdictTenantIdx;
		auto searchDictByTenantIdx = dictByTenantIdx->find( keyTenantIdx );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			subdictTenantIdx = searchDictByTenantIdx->second;
		}
		else {
			subdictTenantIdx = new std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>();
			dictByTenantIdx->insert( std::map<cfint::CFIntMajorVersionByTenantIdxKey,
				std::map<cfint::CFIntMajorVersionPKey,
					cfint::CFIntMajorVersionBuff*>*>::value_type( keyTenantIdx, subdictTenantIdx ) );
		}
		subdictTenantIdx->insert( std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>::value_type( pkey, buff ) );

		std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>* subdictSubProjectIdx;
		auto searchDictBySubProjectIdx = dictBySubProjectIdx->find( keySubProjectIdx );
		if( searchDictBySubProjectIdx != dictBySubProjectIdx->end() ) {
			subdictSubProjectIdx = searchDictBySubProjectIdx->second;
		}
		else {
			subdictSubProjectIdx = new std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>();
			dictBySubProjectIdx->insert( std::map<cfint::CFIntMajorVersionBySubProjectIdxKey,
				std::map<cfint::CFIntMajorVersionPKey,
					cfint::CFIntMajorVersionBuff*>*>::value_type( keySubProjectIdx, subdictSubProjectIdx ) );
		}
		subdictSubProjectIdx->insert( std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>::value_type( pkey, buff ) );

		dictByNameIdx->insert( std::map<cfint::CFIntMajorVersionByNameIdxKey, cfint::CFIntMajorVersionBuff*>::value_type( keyNameIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMajorVersionPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfint::CFIntMajorVersionBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntMajorVersionBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMajorVersionPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfint::CFIntMajorVersionBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntMajorVersionBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> CFIntRamMajorVersionTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> retVec;
		std::map<cfint::CFIntMajorVersionPKey,
			cfint::CFIntMajorVersionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntMajorVersionPKey,
			cfint::CFIntMajorVersionBuff*>::iterator end = dictByPKey->end();
		cfint::CFIntMajorVersionBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfint::CFIntMajorVersionBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> CFIntRamMajorVersionTable::readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId )
	{
		static const std::string S_ProcName( "readDerivedByTenantIdx" );
		cfint::CFIntMajorVersionByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> recVec;
		cfint::CFIntMajorVersionBuff* clone;
		auto searchDictByTenantIdx = dictByTenantIdx->find( key );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			std::map<cfint::CFIntMajorVersionPKey,
				 cfint::CFIntMajorVersionBuff*>* subdictTenantIdx = searchDictByTenantIdx->second;
			std::map<cfint::CFIntMajorVersionPKey,
				cfint::CFIntMajorVersionBuff*>::iterator iter = subdictTenantIdx->begin();
			std::map<cfint::CFIntMajorVersionPKey,
				cfint::CFIntMajorVersionBuff*>::iterator end = subdictTenantIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfint::CFIntMajorVersionBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> CFIntRamMajorVersionTable::readDerivedBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId )
	{
		static const std::string S_ProcName( "readDerivedBySubProjectIdx" );
		cfint::CFIntMajorVersionBySubProjectIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> recVec;
		cfint::CFIntMajorVersionBuff* clone;
		auto searchDictBySubProjectIdx = dictBySubProjectIdx->find( key );
		if( searchDictBySubProjectIdx != dictBySubProjectIdx->end() ) {
			std::map<cfint::CFIntMajorVersionPKey,
				 cfint::CFIntMajorVersionBuff*>* subdictSubProjectIdx = searchDictBySubProjectIdx->second;
			std::map<cfint::CFIntMajorVersionPKey,
				cfint::CFIntMajorVersionBuff*>::iterator iter = subdictSubProjectIdx->begin();
			std::map<cfint::CFIntMajorVersionPKey,
				cfint::CFIntMajorVersionBuff*>::iterator end = subdictSubProjectIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfint::CFIntMajorVersionBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readDerivedByNameIdx" );
		cfint::CFIntMajorVersionByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		key.setRequiredName( Name );
		cfint::CFIntMajorVersionBuff* buff;
		auto searchDictByNameIdx = dictByNameIdx->find( key );
		if( searchDictByNameIdx != dictByNameIdx->end() ) {
			buff = dynamic_cast<cfint::CFIntMajorVersionBuff*>( searchDictByNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfint::CFIntMajorVersionPKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredId( Id );
		cfint::CFIntMajorVersionBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntMajorVersionBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMajorVersionPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfint::CFIntMajorVersionBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff ) );
	}

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMajorVersionPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfint::CFIntMajorVersionBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> CFIntRamMajorVersionTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfint::CFIntMajorVersionBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntMajorVersionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfint::CFIntMajorVersionBuff* buff = readDerivedByIdIdx( Authorization,
			TenantId,
			Id );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> CFIntRamMajorVersionTable::readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId )
	{
		static const std::string S_ProcName( "readBuffByTenantIdx" );
		cfint::CFIntMajorVersionBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> buffList = readDerivedByTenantIdx( Authorization,
			TenantId );
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntMajorVersionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> CFIntRamMajorVersionTable::readBuffBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId )
	{
		static const std::string S_ProcName( "readBuffBySubProjectIdx" );
		cfint::CFIntMajorVersionBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> buffList = readDerivedBySubProjectIdx( Authorization,
			TenantId,
			SubProjectId );
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntMajorVersionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readBuffByNameIdx" );
		cfint::CFIntMajorVersionBuff* buff = readDerivedByNameIdx( Authorization,
			TenantId,
			SubProjectId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupNameIdx" );
		cfint::CFIntMajorVersionBuff* buff = readBuffByNameIdx( Authorization,
			TenantId,
			SubProjectId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupNameIdx" );
		cfint::CFIntMajorVersionBuff* buff = readDerivedByNameIdx( Authorization,
			TenantId,
			SubProjectId,
			Name );
		if( buff != NULL ) {
			return( dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfint::CFIntMajorVersionBuff* CFIntRamMajorVersionTable::updateMajorVersion( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntMajorVersionBuff* Buff )
	{
		static const std::string S_ProcName( "updateMajorVersion" );
		cfint::CFIntMajorVersionPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( Buff->getRequiredId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in MajorVersion for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfint::CFIntMajorVersionBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for MajorVersion primary key " );
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
		cfint::CFIntMajorVersionByTenantIdxKey existingKeyTenantIdx;
		existingKeyTenantIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		cfint::CFIntMajorVersionByTenantIdxKey newKeyTenantIdx;
		newKeyTenantIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		cfint::CFIntMajorVersionBySubProjectIdxKey existingKeySubProjectIdx;
		existingKeySubProjectIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		existingKeySubProjectIdx.setRequiredSubProjectId( existing->getRequiredSubProjectId() );
		cfint::CFIntMajorVersionBySubProjectIdxKey newKeySubProjectIdx;
		newKeySubProjectIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		newKeySubProjectIdx.setRequiredSubProjectId( Buff->getRequiredSubProjectId() );
		cfint::CFIntMajorVersionByNameIdxKey existingKeyNameIdx;
		existingKeyNameIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		existingKeyNameIdx.setRequiredSubProjectId( existing->getRequiredSubProjectId() );
		existingKeyNameIdx.setRequiredName( existing->getRequiredName() );
		cfint::CFIntMajorVersionByNameIdxKey newKeyNameIdx;
		newKeyNameIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		newKeyNameIdx.setRequiredSubProjectId( Buff->getRequiredSubProjectId() );
		newKeyNameIdx.setRequiredName( Buff->getRequiredName() );
		// Check unique indexes

		if( existingKeyNameIdx != newKeyNameIdx ) {
			auto searchDictByNameIdx = dictByNameIdx->find( newKeyNameIdx );
			if( searchDictByNameIdx != dictByNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index MajorVersionNameIdx " + newKeyNameIdx.toString() );
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
					std::string Msg( "Could not resolve Owner relationship Tenant to table Tenant" );
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
				cfint::CFIntSubProjectBuff* chk = dynamic_cast<cfint::CFIntSubProjectBuff*>( schema->getTableSubProject()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredTenantId(),
						Buff->getRequiredSubProjectId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship ParentSubProject to table SubProject" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfint::CFIntMajorVersionBuff" );
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

		dictByPKey->insert( std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>::value_type( pkey, existing ) );

		std::map<cfint::CFIntMajorVersionPKey,
			 cfint::CFIntMajorVersionBuff*>* subdictTenantIdx;
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
			subdictTenantIdx = new std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>();
			dictByTenantIdx->insert( std::map<cfint::CFIntMajorVersionByTenantIdxKey,
				std::map<cfint::CFIntMajorVersionPKey,
					cfint::CFIntMajorVersionBuff*>*>::value_type( newKeyTenantIdx, subdictTenantIdx ) );
		}
		subdictTenantIdx->insert( std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>::value_type( pkey, existing ) );

		std::map<cfint::CFIntMajorVersionPKey,
			 cfint::CFIntMajorVersionBuff*>* subdictSubProjectIdx;
		auto searchDictBySubProjectIdx = dictBySubProjectIdx->find( existingKeySubProjectIdx );
		if( searchDictBySubProjectIdx != dictBySubProjectIdx->end() ) {
			subdictSubProjectIdx = searchDictBySubProjectIdx->second;
			auto searchSubDict = subdictSubProjectIdx->find( pkey );
			if( searchSubDict != subdictSubProjectIdx->end() ) {
				subdictSubProjectIdx->erase( searchSubDict );
			}
			if( subdictSubProjectIdx->size() <= 0 ) {
				delete subdictSubProjectIdx;
				dictBySubProjectIdx->erase( searchDictBySubProjectIdx );
			}
			subdictSubProjectIdx = NULL;
		}
		auto searchNewKeyDictBySubProjectIdx = dictBySubProjectIdx->find( newKeySubProjectIdx );
		if( searchNewKeyDictBySubProjectIdx != dictBySubProjectIdx->end() ) {
			subdictSubProjectIdx = searchNewKeyDictBySubProjectIdx->second;
		}
		else {
			subdictSubProjectIdx = new std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>();
			dictBySubProjectIdx->insert( std::map<cfint::CFIntMajorVersionBySubProjectIdxKey,
				std::map<cfint::CFIntMajorVersionPKey,
					cfint::CFIntMajorVersionBuff*>*>::value_type( newKeySubProjectIdx, subdictSubProjectIdx ) );
		}
		subdictSubProjectIdx->insert( std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>::value_type( pkey, existing ) );

		auto removalDictByNameIdx = dictByNameIdx->find( existingKeyNameIdx );
		if( removalDictByNameIdx != dictByNameIdx->end() ) {
			dictByNameIdx->erase( removalDictByNameIdx );
		}
		dictByNameIdx->insert( std::map<cfint::CFIntMajorVersionByNameIdxKey, cfint::CFIntMajorVersionBuff*>::value_type( newKeyNameIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfint::CFIntMajorVersionBuff* buff;
		if( existing->getClassCode() == cfint::CFIntMajorVersionBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfint::CFIntMajorVersionBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFIntRamMajorVersionTable::deleteMajorVersion( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntMajorVersionBuff* Buff )
	{
		static const std::string S_ProcName( "deleteMajorVersion" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfint::CFIntMajorVersionPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( Buff->getRequiredId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfint::CFIntMajorVersionBuff* existing = searchExisting->second;
		schema->getTableMinorVersion()->deleteMinorVersionByMajorVerIdx( Authorization,
			existing->getRequiredTenantId(),
			existing->getRequiredId() );
		cfint::CFIntMajorVersionByTenantIdxKey keyTenantIdx;
		keyTenantIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		cfint::CFIntMajorVersionBySubProjectIdxKey keySubProjectIdx;
		keySubProjectIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		keySubProjectIdx.setRequiredSubProjectId( existing->getRequiredSubProjectId() );
		cfint::CFIntMajorVersionByNameIdxKey keyNameIdx;
		keyNameIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		keyNameIdx.setRequiredSubProjectId( existing->getRequiredSubProjectId() );
		keyNameIdx.setRequiredName( existing->getRequiredName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfint::CFIntMajorVersionPKey, cfint::CFIntMajorVersionBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByTenantIdx = dictByTenantIdx->find( keyTenantIdx );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			std::map<cfint::CFIntMajorVersionPKey,
				 cfint::CFIntMajorVersionBuff*>* subdictTenantIdx = searchDictByTenantIdx->second;
			auto searchSubDict = subdictTenantIdx->find( pkey );
			if( searchSubDict != subdictTenantIdx->end() ) {
				subdictTenantIdx->erase( searchSubDict );
			}
			subdictTenantIdx = NULL;
		}

		auto searchDictBySubProjectIdx = dictBySubProjectIdx->find( keySubProjectIdx );
		if( searchDictBySubProjectIdx != dictBySubProjectIdx->end() ) {
			std::map<cfint::CFIntMajorVersionPKey,
				 cfint::CFIntMajorVersionBuff*>* subdictSubProjectIdx = searchDictBySubProjectIdx->second;
			auto searchSubDict = subdictSubProjectIdx->find( pkey );
			if( searchSubDict != subdictSubProjectIdx->end() ) {
				subdictSubProjectIdx->erase( searchSubDict );
			}
			subdictSubProjectIdx = NULL;
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

	void CFIntRamMajorVersionTable::deleteMajorVersionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId )
	{
		cfint::CFIntMajorVersionPKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredId( argId );
		deleteMajorVersionByIdIdx( Authorization, &key );
	}

	void CFIntRamMajorVersionTable::deleteMajorVersionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMajorVersionPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfint::CFIntMajorVersionBuff* cur = NULL;
		cfint::CFIntMajorVersionBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> matchSet;
		std::map<cfint::CFIntMajorVersionPKey,
			cfint::CFIntMajorVersionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntMajorVersionPKey,
			cfint::CFIntMajorVersionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntMajorVersionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntMajorVersionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableMajorVersion()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteMajorVersion( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFIntRamMajorVersionTable::deleteMajorVersionByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId )
	{
		cfint::CFIntMajorVersionByTenantIdxKey key;
		key.setRequiredTenantId( argTenantId );
		deleteMajorVersionByTenantIdx( Authorization, &key );
	}

	void CFIntRamMajorVersionTable::deleteMajorVersionByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMajorVersionByTenantIdxKey* argKey )
	{
		cfint::CFIntMajorVersionBuff* cur = NULL;
		cfint::CFIntMajorVersionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> matchSet;
		std::map<cfint::CFIntMajorVersionPKey,
			cfint::CFIntMajorVersionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntMajorVersionPKey,
			cfint::CFIntMajorVersionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntMajorVersionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntMajorVersionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableMajorVersion()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteMajorVersion( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamMajorVersionTable::deleteMajorVersionBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argSubProjectId )
	{
		cfint::CFIntMajorVersionBySubProjectIdxKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredSubProjectId( argSubProjectId );
		deleteMajorVersionBySubProjectIdx( Authorization, &key );
	}

	void CFIntRamMajorVersionTable::deleteMajorVersionBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMajorVersionBySubProjectIdxKey* argKey )
	{
		cfint::CFIntMajorVersionBuff* cur = NULL;
		cfint::CFIntMajorVersionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> matchSet;
		std::map<cfint::CFIntMajorVersionPKey,
			cfint::CFIntMajorVersionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntMajorVersionPKey,
			cfint::CFIntMajorVersionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntMajorVersionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntMajorVersionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableMajorVersion()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteMajorVersion( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamMajorVersionTable::deleteMajorVersionByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argSubProjectId,
			const std::string& argName )
	{
		cfint::CFIntMajorVersionByNameIdxKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredSubProjectId( argSubProjectId );
		key.setRequiredName( argName );
		deleteMajorVersionByNameIdx( Authorization, &key );
	}

	void CFIntRamMajorVersionTable::deleteMajorVersionByNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMajorVersionByNameIdxKey* argKey )
	{
		cfint::CFIntMajorVersionBuff* cur = NULL;
		cfint::CFIntMajorVersionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> matchSet;
		std::map<cfint::CFIntMajorVersionPKey,
			cfint::CFIntMajorVersionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntMajorVersionPKey,
			cfint::CFIntMajorVersionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntMajorVersionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntMajorVersionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableMajorVersion()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteMajorVersion( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamMajorVersionTable::releasePreparedStatements() {
	}

}
