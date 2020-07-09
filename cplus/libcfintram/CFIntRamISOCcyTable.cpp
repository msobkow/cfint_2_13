
// Description: C++18 Implementation for an in-memory RAM DbIO for ISOCcy.

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

	const std::string CFIntRamISOCcyTable::CLASS_NAME( "CFIntRamISOCcyTable" );

	CFIntRamISOCcyTable::CFIntRamISOCcyTable( ICFIntSchema* argSchema )
	: cfsec::ICFSecISOCcyTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecISOCcyPKey, cfsec::CFSecISOCcyBuff*>();
		dictByCcyCdIdx = new std::map<cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::CFSecISOCcyBuff*>();
		dictByCcyNmIdx = new std::map<cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::CFSecISOCcyBuff*>();
	}

	CFIntRamISOCcyTable::~CFIntRamISOCcyTable() {
		if( dictByCcyCdIdx != NULL ) {
			delete dictByCcyCdIdx;
			dictByCcyCdIdx = NULL;
		}
		if( dictByCcyNmIdx != NULL ) {
			delete dictByCcyNmIdx;
			dictByCcyNmIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecISOCcyBuff* elt;
			std::map<cfsec::CFSecISOCcyPKey,
				cfsec::CFSecISOCcyBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecISOCcyPKey,
					cfsec::CFSecISOCcyBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::createISOCcy( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCcyBuff* Buff )
	{
		static const std::string S_ProcName( "createISOCcy" );
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( schema->nextISOCcyIdGen() );
		Buff->setRequiredISOCcyId( pkey.getRequiredISOCcyId() );
		cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
		keyCcyCdIdx.setRequiredISOCode( Buff->getRequiredISOCode() );
		cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
		keyCcyNmIdx.setRequiredName( Buff->getRequiredName() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByCcyCdIdx = dictByCcyCdIdx->find( keyCcyCdIdx );
		if( searchDictByCcyCdIdx != dictByCcyCdIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ISOCcyCodeIdx " + keyCcyCdIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		auto searchDictByCcyNmIdx = dictByCcyNmIdx->find( keyCcyNmIdx );
		if( searchDictByCcyNmIdx != dictByCcyNmIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ISOCcyNameIdx " + keyCcyNmIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		// Proceed with adding the new record
		cfsec::CFSecISOCcyBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecISOCcyPKey, cfsec::CFSecISOCcyBuff*>::value_type( pkey, buff ) );

		dictByCcyCdIdx->insert( std::map<cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::CFSecISOCcyBuff*>::value_type( keyCcyCdIdx, buff ) );

		dictByCcyNmIdx->insert( std::map<cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::CFSecISOCcyBuff*>::value_type( keyCcyNmIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecISOCcyBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecISOCcyBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> CFIntRamISOCcyTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> retVec;
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecISOCcyBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecISOCcyBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::readDerivedByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode )
	{
		static const std::string S_ProcName( "readDerivedByCcyCdIdx" );
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( ISOCode );
		cfsec::CFSecISOCcyBuff* buff;
		auto searchDictByCcyCdIdx = dictByCcyCdIdx->find( key );
		if( searchDictByCcyCdIdx != dictByCcyCdIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( searchDictByCcyCdIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::readDerivedByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readDerivedByCcyNmIdx" );
		cfsec::CFSecISOCcyByCcyNmIdxKey key;
		key.setRequiredName( Name );
		cfsec::CFSecISOCcyBuff* buff;
		auto searchDictByCcyNmIdx = dictByCcyNmIdx->find( key );
		if( searchDictByCcyNmIdx != dictByCcyNmIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( searchDictByCcyNmIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecISOCcyPKey key;
		key.setRequiredISOCcyId( ISOCcyId );
		cfsec::CFSecISOCcyBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecISOCcyBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecISOCcyBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> CFIntRamISOCcyTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecISOCcyBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t ISOCcyId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecISOCcyBuff* buff = readDerivedByIdIdx( Authorization,
			ISOCcyId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::readBuffByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& ISOCode )
	{
		static const std::string S_ProcName( "readBuffByCcyCdIdx" );
		cfsec::CFSecISOCcyBuff* buff = readDerivedByCcyCdIdx( Authorization,
			ISOCode );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::readBuffByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readBuffByCcyNmIdx" );
		cfsec::CFSecISOCcyBuff* buff = readDerivedByCcyNmIdx( Authorization,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::readBuffByLookupCcyCdIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupCcyCdIdx" );
		cfsec::CFSecISOCcyBuff* buff = readBuffByCcyCdIdx( Authorization,
			ISOCode );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::readDerivedByLookupCcyCdIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& ISOCode,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupCcyCdIdx" );
		cfsec::CFSecISOCcyBuff* buff = readDerivedByCcyCdIdx( Authorization,
			ISOCode );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecISOCcyBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfsec::CFSecISOCcyBuff* CFIntRamISOCcyTable::updateISOCcy( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCcyBuff* Buff )
	{
		static const std::string S_ProcName( "updateISOCcy" );
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( Buff->getRequiredISOCcyId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in ISOCcy for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecISOCcyBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for ISOCcy primary key " );
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
		cfsec::CFSecISOCcyByCcyCdIdxKey existingKeyCcyCdIdx;
		existingKeyCcyCdIdx.setRequiredISOCode( existing->getRequiredISOCode() );
		cfsec::CFSecISOCcyByCcyCdIdxKey newKeyCcyCdIdx;
		newKeyCcyCdIdx.setRequiredISOCode( Buff->getRequiredISOCode() );
		cfsec::CFSecISOCcyByCcyNmIdxKey existingKeyCcyNmIdx;
		existingKeyCcyNmIdx.setRequiredName( existing->getRequiredName() );
		cfsec::CFSecISOCcyByCcyNmIdxKey newKeyCcyNmIdx;
		newKeyCcyNmIdx.setRequiredName( Buff->getRequiredName() );
		// Check unique indexes

		if( existingKeyCcyCdIdx != newKeyCcyCdIdx ) {
			auto searchDictByCcyCdIdx = dictByCcyCdIdx->find( newKeyCcyCdIdx );
			if( searchDictByCcyCdIdx != dictByCcyCdIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ISOCcyCodeIdx " + newKeyCcyCdIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		if( existingKeyCcyNmIdx != newKeyCcyNmIdx ) {
			auto searchDictByCcyNmIdx = dictByCcyNmIdx->find( newKeyCcyNmIdx );
			if( searchDictByCcyNmIdx != dictByCcyNmIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ISOCcyNameIdx " + newKeyCcyNmIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		// Update is valid
		std::map<cfsec::CFSecISOCcyPKey, cfsec::CFSecISOCcyBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecISOCcyBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecISOCcyPKey, cfsec::CFSecISOCcyBuff*>::value_type( pkey, existing ) );

		auto removalDictByCcyCdIdx = dictByCcyCdIdx->find( existingKeyCcyCdIdx );
		if( removalDictByCcyCdIdx != dictByCcyCdIdx->end() ) {
			dictByCcyCdIdx->erase( removalDictByCcyCdIdx );
		}
		dictByCcyCdIdx->insert( std::map<cfsec::CFSecISOCcyByCcyCdIdxKey, cfsec::CFSecISOCcyBuff*>::value_type( newKeyCcyCdIdx, existing ) );

		auto removalDictByCcyNmIdx = dictByCcyNmIdx->find( existingKeyCcyNmIdx );
		if( removalDictByCcyNmIdx != dictByCcyNmIdx->end() ) {
			dictByCcyNmIdx->erase( removalDictByCcyNmIdx );
		}
		dictByCcyNmIdx->insert( std::map<cfsec::CFSecISOCcyByCcyNmIdxKey, cfsec::CFSecISOCcyBuff*>::value_type( newKeyCcyNmIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecISOCcyBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecISOCcyBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecISOCcyBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFIntRamISOCcyTable::deleteISOCcy( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecISOCcyBuff* Buff )
	{
		static const std::string S_ProcName( "deleteISOCcy" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecISOCcyPKey pkey;
		pkey.setRequiredISOCcyId( Buff->getRequiredISOCcyId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecISOCcyBuff* existing = searchExisting->second;
		std::TCFLibOwningVector<cfsec::CFSecISOCtryCcyBuff*> arrCheckISOCcyCountries = schema->getTableISOCtryCcy()->readDerivedByCcyIdx( Authorization,
			existing->getRequiredISOCcyId() );
		if( arrCheckISOCcyCountries.size() > 0 ) {
			schema->getTableISOCtryCcy()->deleteISOCtryCcyByCcyIdx( Authorization,
			existing->getRequiredISOCcyId() );
		}
		cfsec::CFSecISOCcyByCcyCdIdxKey keyCcyCdIdx;
		keyCcyCdIdx.setRequiredISOCode( existing->getRequiredISOCode() );
		cfsec::CFSecISOCcyByCcyNmIdxKey keyCcyNmIdx;
		keyCcyNmIdx.setRequiredName( existing->getRequiredName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecISOCcyPKey, cfsec::CFSecISOCcyBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByCcyCdIdx = dictByCcyCdIdx->find( keyCcyCdIdx );
		if( searchDictByCcyCdIdx != dictByCcyCdIdx->end() ) {
			dictByCcyCdIdx->erase( searchDictByCcyCdIdx );
		}

		auto searchDictByCcyNmIdx = dictByCcyNmIdx->find( keyCcyNmIdx );
		if( searchDictByCcyNmIdx != dictByCcyNmIdx->end() ) {
			dictByCcyNmIdx->erase( searchDictByCcyNmIdx );
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFIntRamISOCcyTable::deleteISOCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int16_t argISOCcyId )
	{
		cfsec::CFSecISOCcyPKey key;
		key.setRequiredISOCcyId( argISOCcyId );
		deleteISOCcyByIdIdx( Authorization, &key );
	}

	void CFIntRamISOCcyTable::deleteISOCcyByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecISOCcyBuff* cur = NULL;
		cfsec::CFSecISOCcyBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> matchSet;
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCcy()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCcyId() );
			rereadCur = cur;
			deleteISOCcy( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFIntRamISOCcyTable::deleteISOCcyByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argISOCode )
	{
		cfsec::CFSecISOCcyByCcyCdIdxKey key;
		key.setRequiredISOCode( argISOCode );
		deleteISOCcyByCcyCdIdx( Authorization, &key );
	}

	void CFIntRamISOCcyTable::deleteISOCcyByCcyCdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyByCcyCdIdxKey* argKey )
	{
		cfsec::CFSecISOCcyBuff* cur = NULL;
		cfsec::CFSecISOCcyBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> matchSet;
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCcy()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCcyId() );
			rereadCur = cur;
			deleteISOCcy( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamISOCcyTable::deleteISOCcyByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName )
	{
		cfsec::CFSecISOCcyByCcyNmIdxKey key;
		key.setRequiredName( argName );
		deleteISOCcyByCcyNmIdx( Authorization, &key );
	}

	void CFIntRamISOCcyTable::deleteISOCcyByCcyNmIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecISOCcyByCcyNmIdxKey* argKey )
	{
		cfsec::CFSecISOCcyBuff* cur = NULL;
		cfsec::CFSecISOCcyBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*> matchSet;
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecISOCcyPKey,
			cfsec::CFSecISOCcyBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecISOCcyBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecISOCcyBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableISOCcy()->readDerivedByIdIdx( Authorization,
				cur->getRequiredISOCcyId() );
			rereadCur = cur;
			deleteISOCcy( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamISOCcyTable::releasePreparedStatements() {
	}

}
