
// Description: C++18 Implementation for an in-memory RAM DbIO for SecSession.

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

	const std::string CFIntRamSecSessionTable::CLASS_NAME( "CFIntRamSecSessionTable" );

	CFIntRamSecSessionTable::CFIntRamSecSessionTable( ICFIntSchema* argSchema )
	: cfsec::ICFSecSecSessionTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
		dictBySecUserIdx = new std::map<cfsec::CFSecSecSessionBySecUserIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>();
		dictBySecDevIdx = new std::map<cfsec::CFSecSecSessionBySecDevIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>();
		dictByStartIdx = new std::map<cfsec::CFSecSecSessionByStartIdxKey, cfsec::CFSecSecSessionBuff*>();
		dictByFinishIdx = new std::map<cfsec::CFSecSecSessionByFinishIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>();
		dictBySecProxyIdx = new std::map<cfsec::CFSecSecSessionBySecProxyIdxKey,
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>*>();
	}

	CFIntRamSecSessionTable::~CFIntRamSecSessionTable() {
		if( dictBySecUserIdx != NULL ) {
			for( auto iterDict = dictBySecUserIdx->begin(); iterDict != dictBySecUserIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictBySecUserIdx;
			dictBySecUserIdx = NULL;
		}
		if( dictBySecDevIdx != NULL ) {
			for( auto iterDict = dictBySecDevIdx->begin(); iterDict != dictBySecDevIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictBySecDevIdx;
			dictBySecDevIdx = NULL;
		}
		if( dictByStartIdx != NULL ) {
			delete dictByStartIdx;
			dictByStartIdx = NULL;
		}
		if( dictByFinishIdx != NULL ) {
			for( auto iterDict = dictByFinishIdx->begin(); iterDict != dictByFinishIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByFinishIdx;
			dictByFinishIdx = NULL;
		}
		if( dictBySecProxyIdx != NULL ) {
			for( auto iterDict = dictBySecProxyIdx->begin(); iterDict != dictBySecProxyIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictBySecProxyIdx;
			dictBySecProxyIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecSecSessionBuff* elt;
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecSecSessionBuff* CFIntRamSecSessionTable::createSecSession( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecSessionBuff* Buff )
	{
		static const std::string S_ProcName( "createSecSession" );
		cfsec::CFSecSecSessionPKey pkey;
		pkey.generateRequiredSecSessionId();
		Buff->setRequiredSecSessionId( pkey.getRequiredSecSessionId() );
		cfsec::CFSecSecSessionBySecUserIdxKey keySecUserIdx;
		keySecUserIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		cfsec::CFSecSecSessionBySecDevIdxKey keySecDevIdx;
		keySecDevIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		if( Buff->isOptionalSecDevNameNull() ) {
			keySecDevIdx.setOptionalSecDevNameNull();
		}
		else {
			keySecDevIdx.setOptionalSecDevNameValue( Buff->getOptionalSecDevNameValue() );
		}
		cfsec::CFSecSecSessionByStartIdxKey keyStartIdx;
		keyStartIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		keyStartIdx.setRequiredStart( Buff->getRequiredStart() );
		cfsec::CFSecSecSessionByFinishIdxKey keyFinishIdx;
		keyFinishIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		if( Buff->isOptionalFinishNull() ) {
			keyFinishIdx.setOptionalFinishNull();
		}
		else {
			keyFinishIdx.setOptionalFinishValue( Buff->getOptionalFinishValue() );
		}
		cfsec::CFSecSecSessionBySecProxyIdxKey keySecProxyIdx;
		if( Buff->isOptionalSecProxyIdNull() ) {
			keySecProxyIdx.setOptionalSecProxyIdNull();
		}
		else {
			keySecProxyIdx.setOptionalSecProxyIdValue( Buff->getOptionalSecProxyIdValue() );
		}
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByStartIdx = dictByStartIdx->find( keyStartIdx );
		if( searchDictByStartIdx != dictByStartIdx->end() ) {
			std::string Msg( "Duplicate key detected for index SessionStartIdx " + keyStartIdx.toString() );
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
				cfsec::CFSecSecUserBuff* chk = dynamic_cast<cfsec::CFSecSecUserBuff*>( schema->getTableSecUser()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredSecUserId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship SecSessionUser to table SecUser" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Proceed with adding the new record
		cfsec::CFSecSecSessionBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdictSecUserIdx;
		auto searchDictBySecUserIdx = dictBySecUserIdx->find( keySecUserIdx );
		if( searchDictBySecUserIdx != dictBySecUserIdx->end() ) {
			subdictSecUserIdx = searchDictBySecUserIdx->second;
		}
		else {
			subdictSecUserIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecUserIdx->insert( std::map<cfsec::CFSecSecSessionBySecUserIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( keySecUserIdx, subdictSecUserIdx ) );
		}
		subdictSecUserIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdictSecDevIdx;
		auto searchDictBySecDevIdx = dictBySecDevIdx->find( keySecDevIdx );
		if( searchDictBySecDevIdx != dictBySecDevIdx->end() ) {
			subdictSecDevIdx = searchDictBySecDevIdx->second;
		}
		else {
			subdictSecDevIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecDevIdx->insert( std::map<cfsec::CFSecSecSessionBySecDevIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( keySecDevIdx, subdictSecDevIdx ) );
		}
		subdictSecDevIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, buff ) );

		dictByStartIdx->insert( std::map<cfsec::CFSecSecSessionByStartIdxKey, cfsec::CFSecSecSessionBuff*>::value_type( keyStartIdx, buff ) );

		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdictFinishIdx;
		auto searchDictByFinishIdx = dictByFinishIdx->find( keyFinishIdx );
		if( searchDictByFinishIdx != dictByFinishIdx->end() ) {
			subdictFinishIdx = searchDictByFinishIdx->second;
		}
		else {
			subdictFinishIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictByFinishIdx->insert( std::map<cfsec::CFSecSecSessionByFinishIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( keyFinishIdx, subdictFinishIdx ) );
		}
		subdictFinishIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, buff ) );

		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdictSecProxyIdx;
		auto searchDictBySecProxyIdx = dictBySecProxyIdx->find( keySecProxyIdx );
		if( searchDictBySecProxyIdx != dictBySecProxyIdx->end() ) {
			subdictSecProxyIdx = searchDictBySecProxyIdx->second;
		}
		else {
			subdictSecProxyIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecProxyIdx->insert( std::map<cfsec::CFSecSecSessionBySecProxyIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( keySecProxyIdx, subdictSecProxyIdx ) );
		}
		subdictSecProxyIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecSecSessionBuff* CFIntRamSecSessionTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecSecSessionBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecSessionBuff* CFIntRamSecSessionTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecSecSessionBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> retVec;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecSecSessionBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecSecSessionBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::readDerivedBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readDerivedBySecUserIdx" );
		cfsec::CFSecSecSessionBySecUserIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> recVec;
		cfsec::CFSecSecSessionBuff* clone;
		auto searchDictBySecUserIdx = dictBySecUserIdx->find( key );
		if( searchDictBySecUserIdx != dictBySecUserIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecUserIdx = searchDictBySecUserIdx->second;
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator iter = subdictSecUserIdx->begin();
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator end = subdictSecUserIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecSessionBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::readDerivedBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName )
	{
		static const std::string S_ProcName( "readDerivedBySecDevIdx" );
		cfsec::CFSecSecSessionBySecDevIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		if( SecDevName == NULL ) {
			key.setOptionalSecDevNameNull();
		}
		else {
			key.setOptionalSecDevNameValue( *SecDevName );
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> recVec;
		cfsec::CFSecSecSessionBuff* clone;
		auto searchDictBySecDevIdx = dictBySecDevIdx->find( key );
		if( searchDictBySecDevIdx != dictBySecDevIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecDevIdx = searchDictBySecDevIdx->second;
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator iter = subdictSecDevIdx->begin();
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator end = subdictSecDevIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecSessionBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSecSessionBuff* CFIntRamSecSessionTable::readDerivedByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start )
	{
		static const std::string S_ProcName( "readDerivedByStartIdx" );
		cfsec::CFSecSecSessionByStartIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		key.setRequiredStart( Start );
		cfsec::CFSecSecSessionBuff* buff;
		auto searchDictByStartIdx = dictByStartIdx->find( key );
		if( searchDictByStartIdx != dictByStartIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( searchDictByStartIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::readDerivedByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish )
	{
		static const std::string S_ProcName( "readDerivedByFinishIdx" );
		cfsec::CFSecSecSessionByFinishIdxKey key;
		key.setRequiredSecUserId( SecUserId );
		if( Finish == NULL ) {
			key.setOptionalFinishNull();
		}
		else {
			key.setOptionalFinishValue( *Finish );
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> recVec;
		cfsec::CFSecSecSessionBuff* clone;
		auto searchDictByFinishIdx = dictByFinishIdx->find( key );
		if( searchDictByFinishIdx != dictByFinishIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictFinishIdx = searchDictByFinishIdx->second;
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator iter = subdictFinishIdx->begin();
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator end = subdictFinishIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecSessionBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::readDerivedBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId )
	{
		static const std::string S_ProcName( "readDerivedBySecProxyIdx" );
		cfsec::CFSecSecSessionBySecProxyIdxKey key;
		if( SecProxyId == NULL ) {
			key.setOptionalSecProxyIdNull();
		}
		else {
			key.setOptionalSecProxyIdValue( SecProxyId );
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> recVec;
		cfsec::CFSecSecSessionBuff* clone;
		auto searchDictBySecProxyIdx = dictBySecProxyIdx->find( key );
		if( searchDictBySecProxyIdx != dictBySecProxyIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecProxyIdx = searchDictBySecProxyIdx->second;
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator iter = subdictSecProxyIdx->begin();
			std::map<cfsec::CFSecSecSessionPKey,
				cfsec::CFSecSecSessionBuff*>::iterator end = subdictSecProxyIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfsec::CFSecSecSessionBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfsec::CFSecSecSessionBuff* CFIntRamSecSessionTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecSessionId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecSecSessionPKey key;
		key.setRequiredSecSessionId( SecSessionId );
		cfsec::CFSecSecSessionBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecSecSessionBuff* CFIntRamSecSessionTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecSecSessionBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff ) );
	}

	cfsec::CFSecSecSessionBuff* CFIntRamSecSessionTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecSecSessionBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecSecSessionBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageAllBuff" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecSessionBuff* CFIntRamSecSessionTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecSessionId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecSecSessionBuff* buff = readDerivedByIdIdx( Authorization,
			SecSessionId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::readBuffBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId )
	{
		static const std::string S_ProcName( "readBuffBySecUserIdx" );
		cfsec::CFSecSecSessionBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = readDerivedBySecUserIdx( Authorization,
			SecUserId );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::readBuffBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName )
	{
		static const std::string S_ProcName( "readBuffBySecDevIdx" );
		cfsec::CFSecSecSessionBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = readDerivedBySecDevIdx( Authorization,
			SecUserId,
			SecDevName );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecSecSessionBuff* CFIntRamSecSessionTable::readBuffByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start )
	{
		static const std::string S_ProcName( "readBuffByStartIdx" );
		cfsec::CFSecSecSessionBuff* buff = readDerivedByStartIdx( Authorization,
			SecUserId,
			Start );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::readBuffByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish )
	{
		static const std::string S_ProcName( "readBuffByFinishIdx" );
		cfsec::CFSecSecSessionBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = readDerivedByFinishIdx( Authorization,
			SecUserId,
			Finish );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::readBuffBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId )
	{
		static const std::string S_ProcName( "readBuffBySecProxyIdx" );
		cfsec::CFSecSecSessionBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> buffList = readDerivedBySecProxyIdx( Authorization,
			SecProxyId );
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::pageBuffBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageBuffBySecUserIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::pageBuffBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageBuffBySecDevIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::pageBuffByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageBuffByFinishIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> CFIntRamSecSessionTable::pageBuffBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t SecProxyId,
			const uuid_ptr_t priorSecSessionId )
	{
		static const std::string S_ProcName( "pageBuffBySecProxyIdx" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::CFSecSecSessionBuff* CFIntRamSecSessionTable::updateSecSession( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecSessionBuff* Buff )
	{
		static const std::string S_ProcName( "updateSecSession" );
		cfsec::CFSecSecSessionPKey pkey;
		pkey.setRequiredSecSessionId( Buff->getRequiredSecSessionId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in SecSession for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecSecSessionBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for SecSession primary key " );
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
		cfsec::CFSecSecSessionBySecUserIdxKey existingKeySecUserIdx;
		existingKeySecUserIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		cfsec::CFSecSecSessionBySecUserIdxKey newKeySecUserIdx;
		newKeySecUserIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		cfsec::CFSecSecSessionBySecDevIdxKey existingKeySecDevIdx;
		existingKeySecDevIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		if( existing->isOptionalSecDevNameNull() ) {
			existingKeySecDevIdx.setOptionalSecDevNameNull();
		}
		else {
			existingKeySecDevIdx.setOptionalSecDevNameValue( existing->getOptionalSecDevNameValue() );
		}
		cfsec::CFSecSecSessionBySecDevIdxKey newKeySecDevIdx;
		newKeySecDevIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		if( Buff->isOptionalSecDevNameNull() ) {
			newKeySecDevIdx.setOptionalSecDevNameNull();
		}
		else {
			newKeySecDevIdx.setOptionalSecDevNameValue( Buff->getOptionalSecDevNameValue() );
		}
		cfsec::CFSecSecSessionByStartIdxKey existingKeyStartIdx;
		existingKeyStartIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		existingKeyStartIdx.setRequiredStart( existing->getRequiredStart() );
		cfsec::CFSecSecSessionByStartIdxKey newKeyStartIdx;
		newKeyStartIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		newKeyStartIdx.setRequiredStart( Buff->getRequiredStart() );
		cfsec::CFSecSecSessionByFinishIdxKey existingKeyFinishIdx;
		existingKeyFinishIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		if( existing->isOptionalFinishNull() ) {
			existingKeyFinishIdx.setOptionalFinishNull();
		}
		else {
			existingKeyFinishIdx.setOptionalFinishValue( existing->getOptionalFinishValue() );
		}
		cfsec::CFSecSecSessionByFinishIdxKey newKeyFinishIdx;
		newKeyFinishIdx.setRequiredSecUserId( Buff->getRequiredSecUserId() );
		if( Buff->isOptionalFinishNull() ) {
			newKeyFinishIdx.setOptionalFinishNull();
		}
		else {
			newKeyFinishIdx.setOptionalFinishValue( Buff->getOptionalFinishValue() );
		}
		cfsec::CFSecSecSessionBySecProxyIdxKey existingKeySecProxyIdx;
		if( existing->isOptionalSecProxyIdNull() ) {
			existingKeySecProxyIdx.setOptionalSecProxyIdNull();
		}
		else {
			existingKeySecProxyIdx.setOptionalSecProxyIdValue( existing->getOptionalSecProxyIdValue() );
		}
		cfsec::CFSecSecSessionBySecProxyIdxKey newKeySecProxyIdx;
		if( Buff->isOptionalSecProxyIdNull() ) {
			newKeySecProxyIdx.setOptionalSecProxyIdNull();
		}
		else {
			newKeySecProxyIdx.setOptionalSecProxyIdValue( Buff->getOptionalSecProxyIdValue() );
		}
		// Check unique indexes

		if( existingKeyStartIdx != newKeyStartIdx ) {
			auto searchDictByStartIdx = dictByStartIdx->find( newKeyStartIdx );
			if( searchDictByStartIdx != dictByStartIdx->end() ) {
				std::string Msg( "Duplicate key detected for index SessionStartIdx " + newKeyStartIdx.toString() );
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
				cfsec::CFSecSecUserBuff* chk = dynamic_cast<cfsec::CFSecSecUserBuff*>( schema->getTableSecUser()->readDerivedByIdIdx( Authorization,
						Buff->getRequiredSecUserId() ) );
				if( chk == NULL ) {
					delete Buff;
					std::string Msg( "Could not resolve Container relationship SecSessionUser to table SecUser" );
					throw cflib::CFLibUnresolvedRelationException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				delete chk;
				chk = NULL;
			}
		}

		// Update is valid
		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecSecSessionBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecSessionPKey,
			 cfsec::CFSecSecSessionBuff*>* subdictSecUserIdx;
		auto searchDictBySecUserIdx = dictBySecUserIdx->find( existingKeySecUserIdx );
		if( searchDictBySecUserIdx != dictBySecUserIdx->end() ) {
			subdictSecUserIdx = searchDictBySecUserIdx->second;
			auto searchSubDict = subdictSecUserIdx->find( pkey );
			if( searchSubDict != subdictSecUserIdx->end() ) {
				subdictSecUserIdx->erase( searchSubDict );
			}
			if( subdictSecUserIdx->size() <= 0 ) {
				delete subdictSecUserIdx;
				dictBySecUserIdx->erase( searchDictBySecUserIdx );
			}
			subdictSecUserIdx = NULL;
		}
		auto searchNewKeyDictBySecUserIdx = dictBySecUserIdx->find( newKeySecUserIdx );
		if( searchNewKeyDictBySecUserIdx != dictBySecUserIdx->end() ) {
			subdictSecUserIdx = searchNewKeyDictBySecUserIdx->second;
		}
		else {
			subdictSecUserIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecUserIdx->insert( std::map<cfsec::CFSecSecSessionBySecUserIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( newKeySecUserIdx, subdictSecUserIdx ) );
		}
		subdictSecUserIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecSessionPKey,
			 cfsec::CFSecSecSessionBuff*>* subdictSecDevIdx;
		auto searchDictBySecDevIdx = dictBySecDevIdx->find( existingKeySecDevIdx );
		if( searchDictBySecDevIdx != dictBySecDevIdx->end() ) {
			subdictSecDevIdx = searchDictBySecDevIdx->second;
			auto searchSubDict = subdictSecDevIdx->find( pkey );
			if( searchSubDict != subdictSecDevIdx->end() ) {
				subdictSecDevIdx->erase( searchSubDict );
			}
			if( subdictSecDevIdx->size() <= 0 ) {
				delete subdictSecDevIdx;
				dictBySecDevIdx->erase( searchDictBySecDevIdx );
			}
			subdictSecDevIdx = NULL;
		}
		auto searchNewKeyDictBySecDevIdx = dictBySecDevIdx->find( newKeySecDevIdx );
		if( searchNewKeyDictBySecDevIdx != dictBySecDevIdx->end() ) {
			subdictSecDevIdx = searchNewKeyDictBySecDevIdx->second;
		}
		else {
			subdictSecDevIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecDevIdx->insert( std::map<cfsec::CFSecSecSessionBySecDevIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( newKeySecDevIdx, subdictSecDevIdx ) );
		}
		subdictSecDevIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, existing ) );

		auto removalDictByStartIdx = dictByStartIdx->find( existingKeyStartIdx );
		if( removalDictByStartIdx != dictByStartIdx->end() ) {
			dictByStartIdx->erase( removalDictByStartIdx );
		}
		dictByStartIdx->insert( std::map<cfsec::CFSecSecSessionByStartIdxKey, cfsec::CFSecSecSessionBuff*>::value_type( newKeyStartIdx, existing ) );

		std::map<cfsec::CFSecSecSessionPKey,
			 cfsec::CFSecSecSessionBuff*>* subdictFinishIdx;
		auto searchDictByFinishIdx = dictByFinishIdx->find( existingKeyFinishIdx );
		if( searchDictByFinishIdx != dictByFinishIdx->end() ) {
			subdictFinishIdx = searchDictByFinishIdx->second;
			auto searchSubDict = subdictFinishIdx->find( pkey );
			if( searchSubDict != subdictFinishIdx->end() ) {
				subdictFinishIdx->erase( searchSubDict );
			}
			if( subdictFinishIdx->size() <= 0 ) {
				delete subdictFinishIdx;
				dictByFinishIdx->erase( searchDictByFinishIdx );
			}
			subdictFinishIdx = NULL;
		}
		auto searchNewKeyDictByFinishIdx = dictByFinishIdx->find( newKeyFinishIdx );
		if( searchNewKeyDictByFinishIdx != dictByFinishIdx->end() ) {
			subdictFinishIdx = searchNewKeyDictByFinishIdx->second;
		}
		else {
			subdictFinishIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictByFinishIdx->insert( std::map<cfsec::CFSecSecSessionByFinishIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( newKeyFinishIdx, subdictFinishIdx ) );
		}
		subdictFinishIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, existing ) );

		std::map<cfsec::CFSecSecSessionPKey,
			 cfsec::CFSecSecSessionBuff*>* subdictSecProxyIdx;
		auto searchDictBySecProxyIdx = dictBySecProxyIdx->find( existingKeySecProxyIdx );
		if( searchDictBySecProxyIdx != dictBySecProxyIdx->end() ) {
			subdictSecProxyIdx = searchDictBySecProxyIdx->second;
			auto searchSubDict = subdictSecProxyIdx->find( pkey );
			if( searchSubDict != subdictSecProxyIdx->end() ) {
				subdictSecProxyIdx->erase( searchSubDict );
			}
			if( subdictSecProxyIdx->size() <= 0 ) {
				delete subdictSecProxyIdx;
				dictBySecProxyIdx->erase( searchDictBySecProxyIdx );
			}
			subdictSecProxyIdx = NULL;
		}
		auto searchNewKeyDictBySecProxyIdx = dictBySecProxyIdx->find( newKeySecProxyIdx );
		if( searchNewKeyDictBySecProxyIdx != dictBySecProxyIdx->end() ) {
			subdictSecProxyIdx = searchNewKeyDictBySecProxyIdx->second;
		}
		else {
			subdictSecProxyIdx = new std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>();
			dictBySecProxyIdx->insert( std::map<cfsec::CFSecSecSessionBySecProxyIdxKey,
				std::map<cfsec::CFSecSecSessionPKey,
					cfsec::CFSecSecSessionBuff*>*>::value_type( newKeySecProxyIdx, subdictSecProxyIdx ) );
		}
		subdictSecProxyIdx->insert( std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>::value_type( pkey, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecSecSessionBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecSecSessionBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecSecSessionBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFIntRamSecSessionTable::deleteSecSession( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecSecSessionBuff* Buff )
	{
		static const std::string S_ProcName( "deleteSecSession" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecSecSessionPKey pkey;
		pkey.setRequiredSecSessionId( Buff->getRequiredSecSessionId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecSecSessionBuff* existing = searchExisting->second;
		cfsec::CFSecSecSessionBySecUserIdxKey keySecUserIdx;
		keySecUserIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		cfsec::CFSecSecSessionBySecDevIdxKey keySecDevIdx;
		keySecDevIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		if( existing->isOptionalSecDevNameNull() ) {
			keySecDevIdx.setOptionalSecDevNameNull();
		}
		else {
			keySecDevIdx.setOptionalSecDevNameValue( existing->getOptionalSecDevNameValue() );
		}
		cfsec::CFSecSecSessionByStartIdxKey keyStartIdx;
		keyStartIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		keyStartIdx.setRequiredStart( existing->getRequiredStart() );
		cfsec::CFSecSecSessionByFinishIdxKey keyFinishIdx;
		keyFinishIdx.setRequiredSecUserId( existing->getRequiredSecUserId() );
		if( existing->isOptionalFinishNull() ) {
			keyFinishIdx.setOptionalFinishNull();
		}
		else {
			keyFinishIdx.setOptionalFinishValue( existing->getOptionalFinishValue() );
		}
		cfsec::CFSecSecSessionBySecProxyIdxKey keySecProxyIdx;
		if( existing->isOptionalSecProxyIdNull() ) {
			keySecProxyIdx.setOptionalSecProxyIdNull();
		}
		else {
			keySecProxyIdx.setOptionalSecProxyIdValue( existing->getOptionalSecProxyIdValue() );
		}
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecSecSessionPKey, cfsec::CFSecSecSessionBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictBySecUserIdx = dictBySecUserIdx->find( keySecUserIdx );
		if( searchDictBySecUserIdx != dictBySecUserIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecUserIdx = searchDictBySecUserIdx->second;
			auto searchSubDict = subdictSecUserIdx->find( pkey );
			if( searchSubDict != subdictSecUserIdx->end() ) {
				subdictSecUserIdx->erase( searchSubDict );
			}
			subdictSecUserIdx = NULL;
		}

		auto searchDictBySecDevIdx = dictBySecDevIdx->find( keySecDevIdx );
		if( searchDictBySecDevIdx != dictBySecDevIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecDevIdx = searchDictBySecDevIdx->second;
			auto searchSubDict = subdictSecDevIdx->find( pkey );
			if( searchSubDict != subdictSecDevIdx->end() ) {
				subdictSecDevIdx->erase( searchSubDict );
			}
			subdictSecDevIdx = NULL;
		}

		auto searchDictByStartIdx = dictByStartIdx->find( keyStartIdx );
		if( searchDictByStartIdx != dictByStartIdx->end() ) {
			dictByStartIdx->erase( searchDictByStartIdx );
		}

		auto searchDictByFinishIdx = dictByFinishIdx->find( keyFinishIdx );
		if( searchDictByFinishIdx != dictByFinishIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictFinishIdx = searchDictByFinishIdx->second;
			auto searchSubDict = subdictFinishIdx->find( pkey );
			if( searchSubDict != subdictFinishIdx->end() ) {
				subdictFinishIdx->erase( searchSubDict );
			}
			subdictFinishIdx = NULL;
		}

		auto searchDictBySecProxyIdx = dictBySecProxyIdx->find( keySecProxyIdx );
		if( searchDictBySecProxyIdx != dictBySecProxyIdx->end() ) {
			std::map<cfsec::CFSecSecSessionPKey,
				 cfsec::CFSecSecSessionBuff*>* subdictSecProxyIdx = searchDictBySecProxyIdx->second;
			auto searchSubDict = subdictSecProxyIdx->find( pkey );
			if( searchSubDict != subdictSecProxyIdx->end() ) {
				subdictSecProxyIdx->erase( searchSubDict );
			}
			subdictSecProxyIdx = NULL;
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFIntRamSecSessionTable::deleteSecSessionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecSessionId )
	{
		cfsec::CFSecSecSessionPKey key;
		key.setRequiredSecSessionId( argSecSessionId );
		deleteSecSessionByIdIdx( Authorization, &key );
	}

	void CFIntRamSecSessionTable::deleteSecSessionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFIntRamSecSessionTable::deleteSecSessionBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId )
	{
		cfsec::CFSecSecSessionBySecUserIdxKey key;
		key.setRequiredSecUserId( argSecUserId );
		deleteSecSessionBySecUserIdx( Authorization, &key );
	}

	void CFIntRamSecSessionTable::deleteSecSessionBySecUserIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionBySecUserIdxKey* argKey )
	{
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamSecSessionTable::deleteSecSessionBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::string* argSecDevName )
	{
		cfsec::CFSecSecSessionBySecDevIdxKey key;
		key.setRequiredSecUserId( argSecUserId );
		if( argSecDevName == NULL ) {
			key.setOptionalSecDevNameNull();
		}
		else {
			key.setOptionalSecDevNameValue( *argSecDevName );
		}
		deleteSecSessionBySecDevIdx( Authorization, &key );
	}

	void CFIntRamSecSessionTable::deleteSecSessionBySecDevIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionBySecDevIdxKey* argKey )
	{
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( argKey->isOptionalSecDevNameNull() ) {
			anyNotNull = true;
		}
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamSecSessionTable::deleteSecSessionByStartIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::chrono::system_clock::time_point& argStart )
	{
		cfsec::CFSecSecSessionByStartIdxKey key;
		key.setRequiredSecUserId( argSecUserId );
		key.setRequiredStart( argStart );
		deleteSecSessionByStartIdx( Authorization, &key );
	}

	void CFIntRamSecSessionTable::deleteSecSessionByStartIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionByStartIdxKey* argKey )
	{
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamSecSessionTable::deleteSecSessionByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecUserId,
			const std::chrono::system_clock::time_point* argFinish )
	{
		cfsec::CFSecSecSessionByFinishIdxKey key;
		key.setRequiredSecUserId( argSecUserId );
		if( argFinish == NULL ) {
			key.setOptionalFinishNull();
		}
		else {
			key.setOptionalFinishValue( *argFinish );
		}
		deleteSecSessionByFinishIdx( Authorization, &key );
	}

	void CFIntRamSecSessionTable::deleteSecSessionByFinishIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionByFinishIdxKey* argKey )
	{
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( argKey->isOptionalFinishNull() ) {
			anyNotNull = true;
		}
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamSecSessionTable::deleteSecSessionBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
			const uuid_ptr_t argSecProxyId )
	{
		cfsec::CFSecSecSessionBySecProxyIdxKey key;
		if( argSecProxyId == NULL ) {
			key.setOptionalSecProxyIdNull();
		}
		else {
			key.setOptionalSecProxyIdValue( argSecProxyId );
		}
		deleteSecSessionBySecProxyIdx( Authorization, &key );
	}

	void CFIntRamSecSessionTable::deleteSecSessionBySecProxyIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecSecSessionBySecProxyIdxKey* argKey )
	{
		cfsec::CFSecSecSessionBuff* cur = NULL;
		cfsec::CFSecSecSessionBuff* rereadCur = NULL;
		bool anyNotNull = false;
		if( argKey->isOptionalSecProxyIdNull() ) {
			anyNotNull = true;
		}
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*> matchSet;
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecSecSessionPKey,
			cfsec::CFSecSecSessionBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecSecSessionBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecSecSessionBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableSecSession()->readDerivedByIdIdx( Authorization,
				cur->getRequiredSecSessionId() );
			rereadCur = cur;
			deleteSecSession( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamSecSessionTable::releasePreparedStatements() {
	}

}
