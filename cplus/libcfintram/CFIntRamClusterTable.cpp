
// Description: C++18 Implementation for an in-memory RAM DbIO for Cluster.

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

	const std::string CFIntRamClusterTable::CLASS_NAME( "CFIntRamClusterTable" );

	CFIntRamClusterTable::CFIntRamClusterTable( ICFIntSchema* argSchema )
	: cfsec::ICFSecClusterTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecClusterPKey, cfsec::CFSecClusterBuff*>();
		id32Generator = new std::map<CFIntRamClusterId32Gen, CFIntRamClusterId32Gen*>();
		id64Generator = new std::map<CFIntRamClusterId64Gen, CFIntRamClusterId64Gen*>();
		dictByUDomNameIdx = new std::map<cfsec::CFSecClusterByUDomNameIdxKey, cfsec::CFSecClusterBuff*>();
		dictByUDescrIdx = new std::map<cfsec::CFSecClusterByUDescrIdxKey, cfsec::CFSecClusterBuff*>();
	}

	CFIntRamClusterTable::~CFIntRamClusterTable() {
		if( dictByUDomNameIdx != NULL ) {
			delete dictByUDomNameIdx;
			dictByUDomNameIdx = NULL;
		}
		if( dictByUDescrIdx != NULL ) {
			delete dictByUDescrIdx;
			dictByUDescrIdx = NULL;
		}
		if( id32Generator != NULL ) {
			cfint::CFIntRamClusterId32Gen* elt;
			std::map<CFIntRamClusterId32Gen,
				CFIntRamClusterId32Gen*>::iterator end = id32Generator->end();
			for( std::map<CFIntRamClusterId32Gen,
					CFIntRamClusterId32Gen*>::iterator cur = id32Generator->begin();
				cur != end;
				cur ++ )
			{
				if( cur->second != NULL ) {
					delete cur->second;
					cur->second = NULL;
				}
			}
			delete id32Generator;
			id32Generator = NULL;
		}
		if( id64Generator != NULL ) {
			cfint::CFIntRamClusterId64Gen* elt;
			std::map<CFIntRamClusterId64Gen,
				CFIntRamClusterId64Gen*>::iterator end = id64Generator->end();
			for( std::map<CFIntRamClusterId64Gen,
					CFIntRamClusterId64Gen*>::iterator cur = id64Generator->begin();
				cur != end;
				cur ++ )
			{
				if( cur->second != NULL ) {
					delete cur->second;
					cur->second = NULL;
				}
			}
			delete id64Generator;
			id64Generator = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecClusterBuff* elt;
			std::map<cfsec::CFSecClusterPKey,
				cfsec::CFSecClusterBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecClusterPKey,
					cfsec::CFSecClusterBuff*>::iterator cur = dictByPKey->begin();
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

	int32_t CFIntRamClusterTable::generateNextId32( int64_t argId,
		int16_t argSliceId )
	{
		cfint::CFIntRamClusterId32Gen* key = new cfint::CFIntRamClusterId32Gen();
		key->setRequiredId( argId );
		key->setRequiredSliceId( argSliceId );

		cfint::CFIntRamClusterId32Gen* useGen;
		auto genSearch = id32Generator->find( *key );
		if( genSearch != id32Generator->end() ) {
			useGen = genSearch->second;
			delete key;
			key = NULL;
		}
		else {
			id32Generator->insert( std::map<CFIntRamClusterId32Gen, CFIntRamClusterId32Gen*>::value_type( *key, key ) );
			useGen = key;
			key = NULL;
		}

		int32_t retNext = useGen->getNextId();

		return( retNext );
	}

	int64_t CFIntRamClusterTable::generateNextId64( int64_t argId,
		int16_t argSliceId )
	{
		cfint::CFIntRamClusterId64Gen* key = new cfint::CFIntRamClusterId64Gen();
		key->setRequiredId( argId );
		key->setRequiredSliceId( argSliceId );

		cfint::CFIntRamClusterId64Gen* useGen;
		auto genSearch = id64Generator->find( *key );
		if( genSearch != id64Generator->end() ) {
			useGen = genSearch->second;
			delete key;
			key = NULL;
		}
		else {
			id64Generator->insert( std::map<CFIntRamClusterId64Gen, CFIntRamClusterId64Gen*>::value_type( *key, key ) );
			useGen = key;
			key = NULL;
		}

		int64_t retNext = useGen->getNextId();

		return( retNext );
	}

	int32_t CFIntRamClusterTable::nextSecAppIdGen( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* pkey )
	{
		int32_t retval = nextSecAppIdGen( Authorization,
			pkey->getRequiredId() );
		return( retval );
	}

	int32_t CFIntRamClusterTable::nextSecAppIdGen( const cfsec::CFSecAuthorization* Authorization,
		int64_t argId )
	{
		int32_t retNext = generateNextId32( argId,
			(int16_t)107 );
		return( retNext );
	}

	int32_t CFIntRamClusterTable::nextSecFormIdGen( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* pkey )
	{
		int32_t retval = nextSecFormIdGen( Authorization,
			pkey->getRequiredId() );
		return( retval );
	}

	int32_t CFIntRamClusterTable::nextSecFormIdGen( const cfsec::CFSecAuthorization* Authorization,
		int64_t argId )
	{
		int32_t retNext = generateNextId32( argId,
			(int16_t)108 );
		return( retNext );
	}

	int32_t CFIntRamClusterTable::nextSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* pkey )
	{
		int32_t retval = nextSecGroupIdGen( Authorization,
			pkey->getRequiredId() );
		return( retval );
	}

	int32_t CFIntRamClusterTable::nextSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
		int64_t argId )
	{
		int32_t retNext = generateNextId32( argId,
			(int16_t)109 );
		return( retNext );
	}

	int64_t CFIntRamClusterTable::nextHostNodeIdGen( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* pkey )
	{
		int64_t retval = nextHostNodeIdGen( Authorization,
			pkey->getRequiredId() );
		return( retval );
	}

	int64_t CFIntRamClusterTable::nextHostNodeIdGen( const cfsec::CFSecAuthorization* Authorization,
		int64_t argId )
	{
		int64_t retNext = generateNextId64( argId,
			(int16_t)116 );
		return( retNext );
	}

	int64_t CFIntRamClusterTable::nextSecGroupFormIdGen( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* pkey )
	{
		int64_t retval = nextSecGroupFormIdGen( Authorization,
			pkey->getRequiredId() );
		return( retval );
	}

	int64_t CFIntRamClusterTable::nextSecGroupFormIdGen( const cfsec::CFSecAuthorization* Authorization,
		int64_t argId )
	{
		int64_t retNext = generateNextId64( argId,
			(int16_t)112 );
		return( retNext );
	}

	int64_t CFIntRamClusterTable::nextSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* pkey )
	{
		int64_t retval = nextSecGrpIncIdGen( Authorization,
			pkey->getRequiredId() );
		return( retval );
	}

	int64_t CFIntRamClusterTable::nextSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
		int64_t argId )
	{
		int64_t retNext = generateNextId64( argId,
			(int16_t)111 );
		return( retNext );
	}

	int64_t CFIntRamClusterTable::nextSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* pkey )
	{
		int64_t retval = nextSecGrpMembIdGen( Authorization,
			pkey->getRequiredId() );
		return( retval );
	}

	int64_t CFIntRamClusterTable::nextSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
		int64_t argId )
	{
		int64_t retNext = generateNextId64( argId,
			(int16_t)110 );
		return( retNext );
	}

	int64_t CFIntRamClusterTable::nextServiceIdGen( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* pkey )
	{
		int64_t retval = nextServiceIdGen( Authorization,
			pkey->getRequiredId() );
		return( retval );
	}

	int64_t CFIntRamClusterTable::nextServiceIdGen( const cfsec::CFSecAuthorization* Authorization,
		int64_t argId )
	{
		int64_t retNext = generateNextId64( argId,
			(int16_t)115 );
		return( retNext );
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::createCluster( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecClusterBuff* Buff )
	{
		static const std::string S_ProcName( "createCluster" );
		cfsec::CFSecClusterPKey pkey;
		pkey.setRequiredId( schema->nextClusterIdGen() );
		Buff->setRequiredId( pkey.getRequiredId() );
		cfsec::CFSecClusterByUDomNameIdxKey keyUDomNameIdx;
		keyUDomNameIdx.setRequiredFullDomName( Buff->getRequiredFullDomName() );
		cfsec::CFSecClusterByUDescrIdxKey keyUDescrIdx;
		keyUDescrIdx.setRequiredDescription( Buff->getRequiredDescription() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUDomNameIdx = dictByUDomNameIdx->find( keyUDomNameIdx );
		if( searchDictByUDomNameIdx != dictByUDomNameIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ClusterUDomNameIdx " + keyUDomNameIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		auto searchDictByUDescrIdx = dictByUDescrIdx->find( keyUDescrIdx );
		if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ClusterUDescrNameIdx " + keyUDescrIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		// Proceed with adding the new record
		cfsec::CFSecClusterBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecClusterPKey, cfsec::CFSecClusterBuff*>::value_type( pkey, buff ) );

		dictByUDomNameIdx->insert( std::map<cfsec::CFSecClusterByUDomNameIdxKey, cfsec::CFSecClusterBuff*>::value_type( keyUDomNameIdx, buff ) );

		dictByUDescrIdx->insert( std::map<cfsec::CFSecClusterByUDescrIdxKey, cfsec::CFSecClusterBuff*>::value_type( keyUDescrIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecClusterBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecClusterBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecClusterBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecClusterBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecClusterBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecClusterBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecClusterBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> CFIntRamClusterTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> retVec;
		std::map<cfsec::CFSecClusterPKey,
			cfsec::CFSecClusterBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecClusterPKey,
			cfsec::CFSecClusterBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecClusterBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecClusterBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::readDerivedByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& FullDomName )
	{
		static const std::string S_ProcName( "readDerivedByUDomNameIdx" );
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( FullDomName );
		cfsec::CFSecClusterBuff* buff;
		auto searchDictByUDomNameIdx = dictByUDomNameIdx->find( key );
		if( searchDictByUDomNameIdx != dictByUDomNameIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecClusterBuff*>( searchDictByUDomNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecClusterBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::readDerivedByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description )
	{
		static const std::string S_ProcName( "readDerivedByUDescrIdx" );
		cfsec::CFSecClusterByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::CFSecClusterBuff* buff;
		auto searchDictByUDescrIdx = dictByUDescrIdx->find( key );
		if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecClusterBuff*>( searchDictByUDescrIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecClusterBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecClusterPKey key;
		key.setRequiredId( Id );
		cfsec::CFSecClusterBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecClusterBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecClusterBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecClusterBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecClusterBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecClusterBuff*>( buff ) );
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecClusterBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecClusterBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> CFIntRamClusterTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecClusterBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecClusterBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> CFIntRamClusterTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorId )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecClusterBuff* buff = readDerivedByIdIdx( Authorization,
			Id );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecClusterBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::readBuffByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& FullDomName )
	{
		static const std::string S_ProcName( "readBuffByUDomNameIdx" );
		cfsec::CFSecClusterBuff* buff = readDerivedByUDomNameIdx( Authorization,
			FullDomName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecClusterBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::readBuffByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description )
	{
		static const std::string S_ProcName( "readBuffByUDescrIdx" );
		cfsec::CFSecClusterBuff* buff = readDerivedByUDescrIdx( Authorization,
			Description );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecClusterBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::readBuffByLookupUDomNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& FullDomName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUDomNameIdx" );
		cfsec::CFSecClusterBuff* buff = readBuffByUDomNameIdx( Authorization,
			FullDomName );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecClusterBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::readDerivedByLookupUDomNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& FullDomName,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUDomNameIdx" );
		cfsec::CFSecClusterBuff* buff = readDerivedByUDomNameIdx( Authorization,
			FullDomName );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecClusterBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfsec::CFSecClusterBuff* CFIntRamClusterTable::updateCluster( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecClusterBuff* Buff )
	{
		static const std::string S_ProcName( "updateCluster" );
		cfsec::CFSecClusterPKey pkey;
		pkey.setRequiredId( Buff->getRequiredId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in Cluster for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecClusterBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for Cluster primary key " );
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
		cfsec::CFSecClusterByUDomNameIdxKey existingKeyUDomNameIdx;
		existingKeyUDomNameIdx.setRequiredFullDomName( existing->getRequiredFullDomName() );
		cfsec::CFSecClusterByUDomNameIdxKey newKeyUDomNameIdx;
		newKeyUDomNameIdx.setRequiredFullDomName( Buff->getRequiredFullDomName() );
		cfsec::CFSecClusterByUDescrIdxKey existingKeyUDescrIdx;
		existingKeyUDescrIdx.setRequiredDescription( existing->getRequiredDescription() );
		cfsec::CFSecClusterByUDescrIdxKey newKeyUDescrIdx;
		newKeyUDescrIdx.setRequiredDescription( Buff->getRequiredDescription() );
		// Check unique indexes

		if( existingKeyUDomNameIdx != newKeyUDomNameIdx ) {
			auto searchDictByUDomNameIdx = dictByUDomNameIdx->find( newKeyUDomNameIdx );
			if( searchDictByUDomNameIdx != dictByUDomNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ClusterUDomNameIdx " + newKeyUDomNameIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		if( existingKeyUDescrIdx != newKeyUDescrIdx ) {
			auto searchDictByUDescrIdx = dictByUDescrIdx->find( newKeyUDescrIdx );
			if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ClusterUDescrNameIdx " + newKeyUDescrIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		// Update is valid
		std::map<cfsec::CFSecClusterPKey, cfsec::CFSecClusterBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecClusterBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecClusterBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecClusterPKey, cfsec::CFSecClusterBuff*>::value_type( pkey, existing ) );

		auto removalDictByUDomNameIdx = dictByUDomNameIdx->find( existingKeyUDomNameIdx );
		if( removalDictByUDomNameIdx != dictByUDomNameIdx->end() ) {
			dictByUDomNameIdx->erase( removalDictByUDomNameIdx );
		}
		dictByUDomNameIdx->insert( std::map<cfsec::CFSecClusterByUDomNameIdxKey, cfsec::CFSecClusterBuff*>::value_type( newKeyUDomNameIdx, existing ) );

		auto removalDictByUDescrIdx = dictByUDescrIdx->find( existingKeyUDescrIdx );
		if( removalDictByUDescrIdx != dictByUDescrIdx->end() ) {
			dictByUDescrIdx->erase( removalDictByUDescrIdx );
		}
		dictByUDescrIdx->insert( std::map<cfsec::CFSecClusterByUDescrIdxKey, cfsec::CFSecClusterBuff*>::value_type( newKeyUDescrIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecClusterBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecClusterBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFIntRamClusterTable::deleteCluster( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecClusterBuff* Buff )
	{
		static const std::string S_ProcName( "deleteCluster" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecClusterPKey pkey;
		pkey.setRequiredId( Buff->getRequiredId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecClusterBuff* existing = searchExisting->second;
		cfsec::CFSecSecGroupBuff* buffDelSecGroupForms;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> arrDelSecGroupForms = schema->getTableSecGroup()->readDerivedByClusterIdx( Authorization,
			existing->getRequiredId() );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator iterArrDelSecGroupForms = arrDelSecGroupForms.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator endArrDelSecGroupForms = arrDelSecGroupForms.end();
		while( iterArrDelSecGroupForms != endArrDelSecGroupForms ) {
			buffDelSecGroupForms = *iterArrDelSecGroupForms;
			iterArrDelSecGroupForms ++;
			schema->getTableSecGroupForm()->deleteSecGroupFormByGroupIdx( Authorization,
				buffDelSecGroupForms->getRequiredClusterId(),
				buffDelSecGroupForms->getRequiredSecGroupId() );
		}
		cfsec::CFSecSecGroupBuff* buffDelSecGrpIncByGroup;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> arrDelSecGrpIncByGroup = schema->getTableSecGroup()->readDerivedByClusterIdx( Authorization,
			existing->getRequiredId() );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator iterArrDelSecGrpIncByGroup = arrDelSecGrpIncByGroup.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator endArrDelSecGrpIncByGroup = arrDelSecGrpIncByGroup.end();
		while( iterArrDelSecGrpIncByGroup != endArrDelSecGrpIncByGroup ) {
			buffDelSecGrpIncByGroup = *iterArrDelSecGrpIncByGroup;
			iterArrDelSecGrpIncByGroup ++;
			schema->getTableSecGrpInc()->deleteSecGrpIncByIncludeIdx( Authorization,
				buffDelSecGrpIncByGroup->getRequiredClusterId(),
				buffDelSecGrpIncByGroup->getRequiredSecGroupId() );
		}
		cfsec::CFSecSecGroupBuff* buffDelSecGrpMembs;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> arrDelSecGrpMembs = schema->getTableSecGroup()->readDerivedByClusterIdx( Authorization,
			existing->getRequiredId() );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator iterArrDelSecGrpMembs = arrDelSecGrpMembs.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator endArrDelSecGrpMembs = arrDelSecGrpMembs.end();
		while( iterArrDelSecGrpMembs != endArrDelSecGrpMembs ) {
			buffDelSecGrpMembs = *iterArrDelSecGrpMembs;
			iterArrDelSecGrpMembs ++;
			schema->getTableSecGrpMemb()->deleteSecGrpMembByGroupIdx( Authorization,
				buffDelSecGrpMembs->getRequiredClusterId(),
				buffDelSecGrpMembs->getRequiredSecGroupId() );
		}
		cfsec::CFSecSecGroupBuff* buffDelSecGrpIncs;
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*> arrDelSecGrpIncs = schema->getTableSecGroup()->readDerivedByClusterIdx( Authorization,
			existing->getRequiredId() );
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator iterArrDelSecGrpIncs = arrDelSecGrpIncs.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecGroupBuff*>::iterator endArrDelSecGrpIncs = arrDelSecGrpIncs.end();
		while( iterArrDelSecGrpIncs != endArrDelSecGrpIncs ) {
			buffDelSecGrpIncs = *iterArrDelSecGrpIncs;
			iterArrDelSecGrpIncs ++;
			schema->getTableSecGrpInc()->deleteSecGrpIncByGroupIdx( Authorization,
				buffDelSecGrpIncs->getRequiredClusterId(),
				buffDelSecGrpIncs->getRequiredSecGroupId() );
		}
		schema->getTableSecGroup()->deleteSecGroupByClusterIdx( Authorization,
			existing->getRequiredId() );
		cfsec::CFSecSecAppBuff* buffDelSecAppForms;
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*> arrDelSecAppForms = schema->getTableSecApp()->readDerivedByClusterIdx( Authorization,
			existing->getRequiredId() );
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator iterArrDelSecAppForms = arrDelSecAppForms.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecAppBuff*>::iterator endArrDelSecAppForms = arrDelSecAppForms.end();
		while( iterArrDelSecAppForms != endArrDelSecAppForms ) {
			buffDelSecAppForms = *iterArrDelSecAppForms;
			iterArrDelSecAppForms ++;
			schema->getTableSecForm()->deleteSecFormBySecAppIdx( Authorization,
				buffDelSecAppForms->getRequiredClusterId(),
				buffDelSecAppForms->getRequiredSecAppId() );
		}
		schema->getTableSecApp()->deleteSecAppByClusterIdx( Authorization,
			existing->getRequiredId() );
		schema->getTableTenant()->deleteTenantByClusterIdx( Authorization,
			existing->getRequiredId() );
		schema->getTableHostNode()->deleteHostNodeByClusterIdx( Authorization,
			existing->getRequiredId() );
		cfsec::CFSecClusterByUDomNameIdxKey keyUDomNameIdx;
		keyUDomNameIdx.setRequiredFullDomName( existing->getRequiredFullDomName() );
		cfsec::CFSecClusterByUDescrIdxKey keyUDescrIdx;
		keyUDescrIdx.setRequiredDescription( existing->getRequiredDescription() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecClusterPKey, cfsec::CFSecClusterBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByUDomNameIdx = dictByUDomNameIdx->find( keyUDomNameIdx );
		if( searchDictByUDomNameIdx != dictByUDomNameIdx->end() ) {
			dictByUDomNameIdx->erase( searchDictByUDomNameIdx );
		}

		auto searchDictByUDescrIdx = dictByUDescrIdx->find( keyUDescrIdx );
		if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
			dictByUDescrIdx->erase( searchDictByUDescrIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFIntRamClusterTable::deleteClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId )
	{
		cfsec::CFSecClusterPKey key;
		key.setRequiredId( argId );
		deleteClusterByIdIdx( Authorization, &key );
	}

	void CFIntRamClusterTable::deleteClusterByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecClusterBuff* cur = NULL;
		cfsec::CFSecClusterBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> matchSet;
		std::map<cfsec::CFSecClusterPKey,
			cfsec::CFSecClusterBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecClusterPKey,
			cfsec::CFSecClusterBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecClusterBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecClusterBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableCluster()->readDerivedByIdIdx( Authorization,
				cur->getRequiredId() );
			rereadCur = cur;
			deleteCluster( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFIntRamClusterTable::deleteClusterByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argFullDomName )
	{
		cfsec::CFSecClusterByUDomNameIdxKey key;
		key.setRequiredFullDomName( argFullDomName );
		deleteClusterByUDomNameIdx( Authorization, &key );
	}

	void CFIntRamClusterTable::deleteClusterByUDomNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterByUDomNameIdxKey* argKey )
	{
		cfsec::CFSecClusterBuff* cur = NULL;
		cfsec::CFSecClusterBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> matchSet;
		std::map<cfsec::CFSecClusterPKey,
			cfsec::CFSecClusterBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecClusterPKey,
			cfsec::CFSecClusterBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecClusterBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecClusterBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableCluster()->readDerivedByIdIdx( Authorization,
				cur->getRequiredId() );
			rereadCur = cur;
			deleteCluster( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamClusterTable::deleteClusterByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argDescription )
	{
		cfsec::CFSecClusterByUDescrIdxKey key;
		key.setRequiredDescription( argDescription );
		deleteClusterByUDescrIdx( Authorization, &key );
	}

	void CFIntRamClusterTable::deleteClusterByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecClusterByUDescrIdxKey* argKey )
	{
		cfsec::CFSecClusterBuff* cur = NULL;
		cfsec::CFSecClusterBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*> matchSet;
		std::map<cfsec::CFSecClusterPKey,
			cfsec::CFSecClusterBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecClusterPKey,
			cfsec::CFSecClusterBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecClusterBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecClusterBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecClusterBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableCluster()->readDerivedByIdIdx( Authorization,
				cur->getRequiredId() );
			rereadCur = cur;
			deleteCluster( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamClusterTable::releasePreparedStatements() {
	}

}
