
// Description: C++18 Implementation for an in-memory RAM DbIO for TopProject.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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

	const std::string CFIntRamTopProjectTable::CLASS_NAME( "CFIntRamTopProjectTable" );

	CFIntRamTopProjectTable::CFIntRamTopProjectTable( ICFIntSchema* argSchema )
	: cfint::ICFIntTopProjectTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>();
		dictByTenantIdx = new std::map<cfint::CFIntTopProjectByTenantIdxKey,
			std::map<cfint::CFIntTopProjectPKey,
				cfint::CFIntTopProjectBuff*>*>();
		dictByTopDomainIdx = new std::map<cfint::CFIntTopProjectByTopDomainIdxKey,
			std::map<cfint::CFIntTopProjectPKey,
				cfint::CFIntTopProjectBuff*>*>();
		dictByNameIdx = new std::map<cfint::CFIntTopProjectByNameIdxKey, cfint::CFIntTopProjectBuff*>();
	}

	CFIntRamTopProjectTable::~CFIntRamTopProjectTable() {
		if( dictByTenantIdx != NULL ) {
			for( auto iterDict = dictByTenantIdx->begin(); iterDict != dictByTenantIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByTenantIdx;
			dictByTenantIdx = NULL;
		}
		if( dictByTopDomainIdx != NULL ) {
			for( auto iterDict = dictByTopDomainIdx->begin(); iterDict != dictByTopDomainIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByTopDomainIdx;
			dictByTopDomainIdx = NULL;
		}
		if( dictByNameIdx != NULL ) {
			delete dictByNameIdx;
			dictByNameIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfint::CFIntTopProjectBuff* elt;
			std::map<cfint::CFIntTopProjectPKey,
				cfint::CFIntTopProjectBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfint::CFIntTopProjectPKey,
					cfint::CFIntTopProjectBuff*>::iterator cur = dictByPKey->begin();
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

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::createTopProject( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntTopProjectBuff* Buff )
	{
		static const std::string S_ProcName( "createTopProject" );
		cfint::CFIntTopProjectPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( dynamic_cast<CFIntRamTenantTable*>( schema->getTableTenant() )->nextTopProjectIdGen( Authorization,
			Buff->getRequiredTenantId() ) );
		Buff->setRequiredTenantId( pkey.getRequiredTenantId() );
		Buff->setRequiredId( pkey.getRequiredId() );
		cfint::CFIntTopProjectByTenantIdxKey keyTenantIdx;
		keyTenantIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		cfint::CFIntTopProjectByTopDomainIdxKey keyTopDomainIdx;
		keyTopDomainIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		keyTopDomainIdx.setRequiredTopDomainId( Buff->getRequiredTopDomainId() );
		cfint::CFIntTopProjectByNameIdxKey keyNameIdx;
		keyNameIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		keyNameIdx.setRequiredTopDomainId( Buff->getRequiredTopDomainId() );
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
			std::string Msg( "Duplicate key detected for index TopProjectNameIdx " + keyNameIdx.toString() );
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
				cfint::CFIntTopDomainBuff* chk = dynamic_cast<cfint::CFIntTopDomainBuff*>( schema->getTableTopDomain()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredTenantId(),
						Buff->getRequiredTopDomainId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship ParentTopDomain to table TopDomain" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfint::CFIntTopProjectBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>::value_type( pkey, buff ) );

		std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>* subdictTenantIdx;
		auto searchDictByTenantIdx = dictByTenantIdx->find( keyTenantIdx );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			subdictTenantIdx = searchDictByTenantIdx->second;
		}
		else {
			subdictTenantIdx = new std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>();
			dictByTenantIdx->insert( std::map<cfint::CFIntTopProjectByTenantIdxKey,
				std::map<cfint::CFIntTopProjectPKey,
					cfint::CFIntTopProjectBuff*>*>::value_type( keyTenantIdx, subdictTenantIdx ) );
		}
		subdictTenantIdx->insert( std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>::value_type( pkey, buff ) );

		std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>* subdictTopDomainIdx;
		auto searchDictByTopDomainIdx = dictByTopDomainIdx->find( keyTopDomainIdx );
		if( searchDictByTopDomainIdx != dictByTopDomainIdx->end() ) {
			subdictTopDomainIdx = searchDictByTopDomainIdx->second;
		}
		else {
			subdictTopDomainIdx = new std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>();
			dictByTopDomainIdx->insert( std::map<cfint::CFIntTopProjectByTopDomainIdxKey,
				std::map<cfint::CFIntTopProjectPKey,
					cfint::CFIntTopProjectBuff*>*>::value_type( keyTopDomainIdx, subdictTopDomainIdx ) );
		}
		subdictTopDomainIdx->insert( std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>::value_type( pkey, buff ) );

		dictByNameIdx->insert( std::map<cfint::CFIntTopProjectByNameIdxKey, cfint::CFIntTopProjectBuff*>::value_type( keyNameIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTopProjectPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfint::CFIntTopProjectBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTopProjectPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfint::CFIntTopProjectBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> CFIntRamTopProjectTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> retVec;
		std::map<cfint::CFIntTopProjectPKey,
			cfint::CFIntTopProjectBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntTopProjectPKey,
			cfint::CFIntTopProjectBuff*>::iterator end = dictByPKey->end();
		cfint::CFIntTopProjectBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfint::CFIntTopProjectBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> CFIntRamTopProjectTable::readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId )
	{
		static const std::string S_ProcName( "readDerivedByTenantIdx" );
		cfint::CFIntTopProjectByTenantIdxKey key;
		key.setRequiredTenantId( TenantId );
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> recVec;
		cfint::CFIntTopProjectBuff* clone;
		auto searchDictByTenantIdx = dictByTenantIdx->find( key );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			std::map<cfint::CFIntTopProjectPKey,
				 cfint::CFIntTopProjectBuff*>* subdictTenantIdx = searchDictByTenantIdx->second;
			std::map<cfint::CFIntTopProjectPKey,
				cfint::CFIntTopProjectBuff*>::iterator iter = subdictTenantIdx->begin();
			std::map<cfint::CFIntTopProjectPKey,
				cfint::CFIntTopProjectBuff*>::iterator end = subdictTenantIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfint::CFIntTopProjectBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> CFIntRamTopProjectTable::readDerivedByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId )
	{
		static const std::string S_ProcName( "readDerivedByTopDomainIdx" );
		cfint::CFIntTopProjectByTopDomainIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> recVec;
		cfint::CFIntTopProjectBuff* clone;
		auto searchDictByTopDomainIdx = dictByTopDomainIdx->find( key );
		if( searchDictByTopDomainIdx != dictByTopDomainIdx->end() ) {
			std::map<cfint::CFIntTopProjectPKey,
				 cfint::CFIntTopProjectBuff*>* subdictTopDomainIdx = searchDictByTopDomainIdx->second;
			std::map<cfint::CFIntTopProjectPKey,
				cfint::CFIntTopProjectBuff*>::iterator iter = subdictTopDomainIdx->begin();
			std::map<cfint::CFIntTopProjectPKey,
				cfint::CFIntTopProjectBuff*>::iterator end = subdictTopDomainIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfint::CFIntTopProjectBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readDerivedByNameIdx" );
		cfint::CFIntTopProjectByNameIdxKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		cfint::CFIntTopProjectBuff* buff;
		auto searchDictByNameIdx = dictByNameIdx->find( key );
		if( searchDictByNameIdx != dictByNameIdx->end() ) {
			buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( searchDictByNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfint::CFIntTopProjectPKey key;
		key.setRequiredTenantId( TenantId );
		key.setRequiredId( Id );
		cfint::CFIntTopProjectBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTopProjectPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfint::CFIntTopProjectBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfint::CFIntTopProjectBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfint::CFIntTopProjectBuff*>( buff ) );
	}

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTopProjectPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfint::CFIntTopProjectBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfint::CFIntTopProjectBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> CFIntRamTopProjectTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfint::CFIntTopProjectBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntTopProjectBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntTopProjectBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfint::CFIntTopProjectBuff* buff = readDerivedByIdIdx( Authorization,
			TenantId,
			Id );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntTopProjectBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> CFIntRamTopProjectTable::readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId )
	{
		static const std::string S_ProcName( "readBuffByTenantIdx" );
		cfint::CFIntTopProjectBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> buffList = readDerivedByTenantIdx( Authorization,
			TenantId );
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntTopProjectBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntTopProjectBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> CFIntRamTopProjectTable::readBuffByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId )
	{
		static const std::string S_ProcName( "readBuffByTopDomainIdx" );
		cfint::CFIntTopProjectBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> buffList = readDerivedByTopDomainIdx( Authorization,
			TenantId,
			TopDomainId );
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntTopProjectBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntTopProjectBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readBuffByNameIdx" );
		cfint::CFIntTopProjectBuff* buff = readDerivedByNameIdx( Authorization,
			TenantId,
			TopDomainId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntTopProjectBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupNameIdx" );
		cfint::CFIntTopProjectBuff* buff = readBuffByNameIdx( Authorization,
			TenantId,
			TopDomainId,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntTopProjectBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupNameIdx" );
		cfint::CFIntTopProjectBuff* buff = readDerivedByNameIdx( Authorization,
			TenantId,
			TopDomainId,
			Name );
		if( buff != NULL ) {
			return( dynamic_cast<cfint::CFIntTopProjectBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfint::CFIntTopProjectBuff* CFIntRamTopProjectTable::updateTopProject( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntTopProjectBuff* Buff )
	{
		static const std::string S_ProcName( "updateTopProject" );
		cfint::CFIntTopProjectPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( Buff->getRequiredId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in TopProject for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfint::CFIntTopProjectBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for TopProject primary key " );
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
		cfint::CFIntTopProjectByTenantIdxKey existingKeyTenantIdx;
		existingKeyTenantIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		cfint::CFIntTopProjectByTenantIdxKey newKeyTenantIdx;
		newKeyTenantIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		cfint::CFIntTopProjectByTopDomainIdxKey existingKeyTopDomainIdx;
		existingKeyTopDomainIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		existingKeyTopDomainIdx.setRequiredTopDomainId( existing->getRequiredTopDomainId() );
		cfint::CFIntTopProjectByTopDomainIdxKey newKeyTopDomainIdx;
		newKeyTopDomainIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		newKeyTopDomainIdx.setRequiredTopDomainId( Buff->getRequiredTopDomainId() );
		cfint::CFIntTopProjectByNameIdxKey existingKeyNameIdx;
		existingKeyNameIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		existingKeyNameIdx.setRequiredTopDomainId( existing->getRequiredTopDomainId() );
		existingKeyNameIdx.setRequiredName( existing->getRequiredName() );
		cfint::CFIntTopProjectByNameIdxKey newKeyNameIdx;
		newKeyNameIdx.setRequiredTenantId( Buff->getRequiredTenantId() );
		newKeyNameIdx.setRequiredTopDomainId( Buff->getRequiredTopDomainId() );
		newKeyNameIdx.setRequiredName( Buff->getRequiredName() );
		// Check unique indexes

		if( existingKeyNameIdx != newKeyNameIdx ) {
			auto searchDictByNameIdx = dictByNameIdx->find( newKeyNameIdx );
			if( searchDictByNameIdx != dictByNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index TopProjectNameIdx " + newKeyNameIdx.toString() );
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
				cfint::CFIntTopDomainBuff* chk = dynamic_cast<cfint::CFIntTopDomainBuff*>( schema->getTableTopDomain()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredTenantId(),
						Buff->getRequiredTopDomainId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship ParentTopDomain to table TopDomain" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfint::CFIntTopProjectBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfint::CFIntTopProjectBuff" );
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

		dictByPKey->insert( std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>::value_type( pkey, existing ) );

		std::map<cfint::CFIntTopProjectPKey,
			 cfint::CFIntTopProjectBuff*>* subdictTenantIdx;
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
			subdictTenantIdx = new std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>();
			dictByTenantIdx->insert( std::map<cfint::CFIntTopProjectByTenantIdxKey,
				std::map<cfint::CFIntTopProjectPKey,
					cfint::CFIntTopProjectBuff*>*>::value_type( newKeyTenantIdx, subdictTenantIdx ) );
		}
		subdictTenantIdx->insert( std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>::value_type( pkey, existing ) );

		std::map<cfint::CFIntTopProjectPKey,
			 cfint::CFIntTopProjectBuff*>* subdictTopDomainIdx;
		auto searchDictByTopDomainIdx = dictByTopDomainIdx->find( existingKeyTopDomainIdx );
		if( searchDictByTopDomainIdx != dictByTopDomainIdx->end() ) {
			subdictTopDomainIdx = searchDictByTopDomainIdx->second;
			auto searchSubDict = subdictTopDomainIdx->find( pkey );
			if( searchSubDict != subdictTopDomainIdx->end() ) {
				subdictTopDomainIdx->erase( searchSubDict );
			}
			if( subdictTopDomainIdx->size() <= 0 ) {
				delete subdictTopDomainIdx;
				dictByTopDomainIdx->erase( searchDictByTopDomainIdx );
			}
			subdictTopDomainIdx = NULL;
		}
		auto searchNewKeyDictByTopDomainIdx = dictByTopDomainIdx->find( newKeyTopDomainIdx );
		if( searchNewKeyDictByTopDomainIdx != dictByTopDomainIdx->end() ) {
			subdictTopDomainIdx = searchNewKeyDictByTopDomainIdx->second;
		}
		else {
			subdictTopDomainIdx = new std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>();
			dictByTopDomainIdx->insert( std::map<cfint::CFIntTopProjectByTopDomainIdxKey,
				std::map<cfint::CFIntTopProjectPKey,
					cfint::CFIntTopProjectBuff*>*>::value_type( newKeyTopDomainIdx, subdictTopDomainIdx ) );
		}
		subdictTopDomainIdx->insert( std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>::value_type( pkey, existing ) );

		auto removalDictByNameIdx = dictByNameIdx->find( existingKeyNameIdx );
		if( removalDictByNameIdx != dictByNameIdx->end() ) {
			dictByNameIdx->erase( removalDictByNameIdx );
		}
		dictByNameIdx->insert( std::map<cfint::CFIntTopProjectByNameIdxKey, cfint::CFIntTopProjectBuff*>::value_type( newKeyNameIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfint::CFIntTopProjectBuff* buff;
		if( existing->getClassCode() == cfint::CFIntTopProjectBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfint::CFIntTopProjectBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFIntRamTopProjectTable::deleteTopProject( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntTopProjectBuff* Buff )
	{
		static const std::string S_ProcName( "deleteTopProject" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfint::CFIntTopProjectPKey pkey;
		pkey.setRequiredTenantId( Buff->getRequiredTenantId() );
		pkey.setRequiredId( Buff->getRequiredId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfint::CFIntTopProjectBuff* existing = searchExisting->second;
		schema->getTableSubProject()->deleteSubProjectByTopProjectIdx( Authorization,
			existing->getRequiredTenantId(),
			existing->getRequiredId() );
		cfint::CFIntTopProjectByTenantIdxKey keyTenantIdx;
		keyTenantIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		cfint::CFIntTopProjectByTopDomainIdxKey keyTopDomainIdx;
		keyTopDomainIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		keyTopDomainIdx.setRequiredTopDomainId( existing->getRequiredTopDomainId() );
		cfint::CFIntTopProjectByNameIdxKey keyNameIdx;
		keyNameIdx.setRequiredTenantId( existing->getRequiredTenantId() );
		keyNameIdx.setRequiredTopDomainId( existing->getRequiredTopDomainId() );
		keyNameIdx.setRequiredName( existing->getRequiredName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfint::CFIntTopProjectPKey, cfint::CFIntTopProjectBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByTenantIdx = dictByTenantIdx->find( keyTenantIdx );
		if( searchDictByTenantIdx != dictByTenantIdx->end() ) {
			std::map<cfint::CFIntTopProjectPKey,
				 cfint::CFIntTopProjectBuff*>* subdictTenantIdx = searchDictByTenantIdx->second;
			auto searchSubDict = subdictTenantIdx->find( pkey );
			if( searchSubDict != subdictTenantIdx->end() ) {
				subdictTenantIdx->erase( searchSubDict );
			}
			subdictTenantIdx = NULL;
		}

		auto searchDictByTopDomainIdx = dictByTopDomainIdx->find( keyTopDomainIdx );
		if( searchDictByTopDomainIdx != dictByTopDomainIdx->end() ) {
			std::map<cfint::CFIntTopProjectPKey,
				 cfint::CFIntTopProjectBuff*>* subdictTopDomainIdx = searchDictByTopDomainIdx->second;
			auto searchSubDict = subdictTopDomainIdx->find( pkey );
			if( searchSubDict != subdictTopDomainIdx->end() ) {
				subdictTopDomainIdx->erase( searchSubDict );
			}
			subdictTopDomainIdx = NULL;
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

	void CFIntRamTopProjectTable::deleteTopProjectByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId )
	{
		cfint::CFIntTopProjectPKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredId( argId );
		deleteTopProjectByIdIdx( Authorization, &key );
	}

	void CFIntRamTopProjectTable::deleteTopProjectByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTopProjectPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfint::CFIntTopProjectBuff* cur = NULL;
		cfint::CFIntTopProjectBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> matchSet;
		std::map<cfint::CFIntTopProjectPKey,
			cfint::CFIntTopProjectBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntTopProjectPKey,
			cfint::CFIntTopProjectBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntTopProjectBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntTopProjectBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTopProject()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteTopProject( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFIntRamTopProjectTable::deleteTopProjectByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId )
	{
		cfint::CFIntTopProjectByTenantIdxKey key;
		key.setRequiredTenantId( argTenantId );
		deleteTopProjectByTenantIdx( Authorization, &key );
	}

	void CFIntRamTopProjectTable::deleteTopProjectByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTopProjectByTenantIdxKey* argKey )
	{
		cfint::CFIntTopProjectBuff* cur = NULL;
		cfint::CFIntTopProjectBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> matchSet;
		std::map<cfint::CFIntTopProjectPKey,
			cfint::CFIntTopProjectBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntTopProjectPKey,
			cfint::CFIntTopProjectBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntTopProjectBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntTopProjectBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTopProject()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteTopProject( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamTopProjectTable::deleteTopProjectByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId )
	{
		cfint::CFIntTopProjectByTopDomainIdxKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredTopDomainId( argTopDomainId );
		deleteTopProjectByTopDomainIdx( Authorization, &key );
	}

	void CFIntRamTopProjectTable::deleteTopProjectByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTopProjectByTopDomainIdxKey* argKey )
	{
		cfint::CFIntTopProjectBuff* cur = NULL;
		cfint::CFIntTopProjectBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> matchSet;
		std::map<cfint::CFIntTopProjectPKey,
			cfint::CFIntTopProjectBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntTopProjectPKey,
			cfint::CFIntTopProjectBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntTopProjectBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntTopProjectBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTopProject()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteTopProject( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamTopProjectTable::deleteTopProjectByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId,
			const std::string& argName )
	{
		cfint::CFIntTopProjectByNameIdxKey key;
		key.setRequiredTenantId( argTenantId );
		key.setRequiredTopDomainId( argTopDomainId );
		key.setRequiredName( argName );
		deleteTopProjectByNameIdx( Authorization, &key );
	}

	void CFIntRamTopProjectTable::deleteTopProjectByNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntTopProjectByNameIdxKey* argKey )
	{
		cfint::CFIntTopProjectBuff* cur = NULL;
		cfint::CFIntTopProjectBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> matchSet;
		std::map<cfint::CFIntTopProjectPKey,
			cfint::CFIntTopProjectBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntTopProjectPKey,
			cfint::CFIntTopProjectBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntTopProjectBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntTopProjectBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableTopProject()->readDerivedByIdIdx( Authorization,
				cur->getRequiredTenantId(),
				cur->getRequiredId() );
			rereadCur = cur;
			deleteTopProject( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamTopProjectTable::releasePreparedStatements() {
	}

}
