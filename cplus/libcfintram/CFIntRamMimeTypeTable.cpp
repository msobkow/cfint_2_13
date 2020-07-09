
// Description: C++18 Implementation for an in-memory RAM DbIO for MimeType.

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

	const std::string CFIntRamMimeTypeTable::CLASS_NAME( "CFIntRamMimeTypeTable" );

	CFIntRamMimeTypeTable::CFIntRamMimeTypeTable( ICFIntSchema* argSchema )
	: cfint::ICFIntMimeTypeTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfint::CFIntMimeTypePKey, cfint::CFIntMimeTypeBuff*>();
		dictByUNameIdx = new std::map<cfint::CFIntMimeTypeByUNameIdxKey, cfint::CFIntMimeTypeBuff*>();
	}

	CFIntRamMimeTypeTable::~CFIntRamMimeTypeTable() {
		if( dictByUNameIdx != NULL ) {
			delete dictByUNameIdx;
			dictByUNameIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfint::CFIntMimeTypeBuff* elt;
			std::map<cfint::CFIntMimeTypePKey,
				cfint::CFIntMimeTypeBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfint::CFIntMimeTypePKey,
					cfint::CFIntMimeTypeBuff*>::iterator cur = dictByPKey->begin();
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

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::createMimeType( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntMimeTypeBuff* Buff )
	{
		static const std::string S_ProcName( "createMimeType" );
		cfint::CFIntMimeTypePKey pkey;
		pkey.setRequiredMimeTypeId( schema->nextMimeTypeIdGen() );
		Buff->setRequiredMimeTypeId( pkey.getRequiredMimeTypeId() );
		cfint::CFIntMimeTypeByUNameIdxKey keyUNameIdx;
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
			std::string Msg( "Duplicate key detected for index MimeTypeUNameIdx " + keyUNameIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		// Proceed with adding the new record
		cfint::CFIntMimeTypeBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfint::CFIntMimeTypePKey, cfint::CFIntMimeTypeBuff*>::value_type( pkey, buff ) );

		dictByUNameIdx->insert( std::map<cfint::CFIntMimeTypeByUNameIdxKey, cfint::CFIntMimeTypeBuff*>::value_type( keyUNameIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMimeTypePKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfint::CFIntMimeTypeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMimeTypePKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfint::CFIntMimeTypeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> CFIntRamMimeTypeTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> retVec;
		std::map<cfint::CFIntMimeTypePKey,
			cfint::CFIntMimeTypeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntMimeTypePKey,
			cfint::CFIntMimeTypeBuff*>::iterator end = dictByPKey->end();
		cfint::CFIntMimeTypeBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfint::CFIntMimeTypeBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readDerivedByUNameIdx" );
		cfint::CFIntMimeTypeByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::CFIntMimeTypeBuff* buff;
		auto searchDictByUNameIdx = dictByUNameIdx->find( key );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( searchDictByUNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t MimeTypeId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfint::CFIntMimeTypePKey key;
		key.setRequiredMimeTypeId( MimeTypeId );
		cfint::CFIntMimeTypeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMimeTypePKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfint::CFIntMimeTypeBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff ) );
	}

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMimeTypePKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfint::CFIntMimeTypeBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> CFIntRamMimeTypeTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfint::CFIntMimeTypeBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntMimeTypeBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t MimeTypeId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfint::CFIntMimeTypeBuff* buff = readDerivedByIdIdx( Authorization,
			MimeTypeId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readBuffByUNameIdx" );
		cfint::CFIntMimeTypeBuff* buff = readDerivedByUNameIdx( Authorization,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUNameIdx" );
		cfint::CFIntMimeTypeBuff* buff = readBuffByUNameIdx( Authorization,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUNameIdx" );
		cfint::CFIntMimeTypeBuff* buff = readDerivedByUNameIdx( Authorization,
			Name );
		if( buff != NULL ) {
			return( dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfint::CFIntMimeTypeBuff* CFIntRamMimeTypeTable::updateMimeType( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntMimeTypeBuff* Buff )
	{
		static const std::string S_ProcName( "updateMimeType" );
		cfint::CFIntMimeTypePKey pkey;
		pkey.setRequiredMimeTypeId( Buff->getRequiredMimeTypeId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in MimeType for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfint::CFIntMimeTypeBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for MimeType primary key " );
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
		cfint::CFIntMimeTypeByUNameIdxKey existingKeyUNameIdx;
		existingKeyUNameIdx.setRequiredName( existing->getRequiredName() );
		cfint::CFIntMimeTypeByUNameIdxKey newKeyUNameIdx;
		newKeyUNameIdx.setRequiredName( Buff->getRequiredName() );
		// Check unique indexes

		if( existingKeyUNameIdx != newKeyUNameIdx ) {
			auto searchDictByUNameIdx = dictByUNameIdx->find( newKeyUNameIdx );
			if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index MimeTypeUNameIdx " + newKeyUNameIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		// Update is valid
		std::map<cfint::CFIntMimeTypePKey, cfint::CFIntMimeTypeBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfint::CFIntMimeTypeBuff" );
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

		dictByPKey->insert( std::map<cfint::CFIntMimeTypePKey, cfint::CFIntMimeTypeBuff*>::value_type( pkey, existing ) );

		auto removalDictByUNameIdx = dictByUNameIdx->find( existingKeyUNameIdx );
		if( removalDictByUNameIdx != dictByUNameIdx->end() ) {
			dictByUNameIdx->erase( removalDictByUNameIdx );
		}
		dictByUNameIdx->insert( std::map<cfint::CFIntMimeTypeByUNameIdxKey, cfint::CFIntMimeTypeBuff*>::value_type( newKeyUNameIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfint::CFIntMimeTypeBuff* buff;
		if( existing->getClassCode() == cfint::CFIntMimeTypeBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfint::CFIntMimeTypeBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFIntRamMimeTypeTable::deleteMimeType( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntMimeTypeBuff* Buff )
	{
		static const std::string S_ProcName( "deleteMimeType" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfint::CFIntMimeTypePKey pkey;
		pkey.setRequiredMimeTypeId( Buff->getRequiredMimeTypeId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfint::CFIntMimeTypeBuff* existing = searchExisting->second;
		cfint::CFIntMimeTypeByUNameIdxKey keyUNameIdx;
		keyUNameIdx.setRequiredName( existing->getRequiredName() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfint::CFIntMimeTypePKey, cfint::CFIntMimeTypeBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
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

	void CFIntRamMimeTypeTable::deleteMimeTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argMimeTypeId )
	{
		cfint::CFIntMimeTypePKey key;
		key.setRequiredMimeTypeId( argMimeTypeId );
		deleteMimeTypeByIdIdx( Authorization, &key );
	}

	void CFIntRamMimeTypeTable::deleteMimeTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMimeTypePKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfint::CFIntMimeTypeBuff* cur = NULL;
		cfint::CFIntMimeTypeBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> matchSet;
		std::map<cfint::CFIntMimeTypePKey,
			cfint::CFIntMimeTypeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntMimeTypePKey,
			cfint::CFIntMimeTypeBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntMimeTypeBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntMimeTypeBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableMimeType()->readDerivedByIdIdx( Authorization,
				cur->getRequiredMimeTypeId() );
			rereadCur = cur;
			deleteMimeType( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFIntRamMimeTypeTable::deleteMimeTypeByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName )
	{
		cfint::CFIntMimeTypeByUNameIdxKey key;
		key.setRequiredName( argName );
		deleteMimeTypeByUNameIdx( Authorization, &key );
	}

	void CFIntRamMimeTypeTable::deleteMimeTypeByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntMimeTypeByUNameIdxKey* argKey )
	{
		cfint::CFIntMimeTypeBuff* cur = NULL;
		cfint::CFIntMimeTypeBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> matchSet;
		std::map<cfint::CFIntMimeTypePKey,
			cfint::CFIntMimeTypeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntMimeTypePKey,
			cfint::CFIntMimeTypeBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntMimeTypeBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntMimeTypeBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableMimeType()->readDerivedByIdIdx( Authorization,
				cur->getRequiredMimeTypeId() );
			rereadCur = cur;
			deleteMimeType( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamMimeTypeTable::releasePreparedStatements() {
	}

}
