
// Description: C++18 Implementation for an in-memory RAM DbIO for ServiceType.

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

	const std::string CFIntRamServiceTypeTable::CLASS_NAME( "CFIntRamServiceTypeTable" );

	CFIntRamServiceTypeTable::CFIntRamServiceTypeTable( ICFIntSchema* argSchema )
	: cfsec::ICFSecServiceTypeTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfsec::CFSecServiceTypePKey, cfsec::CFSecServiceTypeBuff*>();
		dictByUDescrIdx = new std::map<cfsec::CFSecServiceTypeByUDescrIdxKey, cfsec::CFSecServiceTypeBuff*>();
	}

	CFIntRamServiceTypeTable::~CFIntRamServiceTypeTable() {
		if( dictByUDescrIdx != NULL ) {
			delete dictByUDescrIdx;
			dictByUDescrIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfsec::CFSecServiceTypeBuff* elt;
			std::map<cfsec::CFSecServiceTypePKey,
				cfsec::CFSecServiceTypeBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfsec::CFSecServiceTypePKey,
					cfsec::CFSecServiceTypeBuff*>::iterator cur = dictByPKey->begin();
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

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::createServiceType( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecServiceTypeBuff* Buff )
	{
		static const std::string S_ProcName( "createServiceType" );
		cfsec::CFSecServiceTypePKey pkey;
		pkey.setRequiredServiceTypeId( schema->nextServiceTypeIdGen() );
		Buff->setRequiredServiceTypeId( pkey.getRequiredServiceTypeId() );
		cfsec::CFSecServiceTypeByUDescrIdxKey keyUDescrIdx;
		keyUDescrIdx.setRequiredDescription( Buff->getRequiredDescription() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUDescrIdx = dictByUDescrIdx->find( keyUDescrIdx );
		if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
			std::string Msg( "Duplicate key detected for index ServiceTypeUDescrIdx " + keyUDescrIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		// Proceed with adding the new record
		cfsec::CFSecServiceTypeBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfsec::CFSecServiceTypePKey, cfsec::CFSecServiceTypeBuff*>::value_type( pkey, buff ) );

		dictByUDescrIdx->insert( std::map<cfsec::CFSecServiceTypeByUDescrIdxKey, cfsec::CFSecServiceTypeBuff*>::value_type( keyUDescrIdx, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypePKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfsec::CFSecServiceTypeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypePKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfsec::CFSecServiceTypeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> CFIntRamServiceTypeTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> retVec;
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator end = dictByPKey->end();
		cfsec::CFSecServiceTypeBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::readDerivedByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description )
	{
		static const std::string S_ProcName( "readDerivedByUDescrIdx" );
		cfsec::CFSecServiceTypeByUDescrIdxKey key;
		key.setRequiredDescription( Description );
		cfsec::CFSecServiceTypeBuff* buff;
		auto searchDictByUDescrIdx = dictByUDescrIdx->find( key );
		if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( searchDictByUDescrIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfsec::CFSecServiceTypePKey key;
		key.setRequiredServiceTypeId( ServiceTypeId );
		cfsec::CFSecServiceTypeBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypePKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfsec::CFSecServiceTypeBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
	}

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypePKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfsec::CFSecServiceTypeBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> CFIntRamServiceTypeTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfsec::CFSecServiceTypeBuff* buff;
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> filteredList;
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t ServiceTypeId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfsec::CFSecServiceTypeBuff* buff = readDerivedByIdIdx( Authorization,
			ServiceTypeId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::readBuffByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Description )
	{
		static const std::string S_ProcName( "readBuffByUDescrIdx" );
		cfsec::CFSecServiceTypeBuff* buff = readDerivedByUDescrIdx( Authorization,
			Description );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::readBuffByLookupUDescrIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Description,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUDescrIdx" );
		cfsec::CFSecServiceTypeBuff* buff = readBuffByUDescrIdx( Authorization,
			Description );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::readDerivedByLookupUDescrIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Description,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUDescrIdx" );
		cfsec::CFSecServiceTypeBuff* buff = readDerivedByUDescrIdx( Authorization,
			Description );
		if( buff != NULL ) {
			return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfsec::CFSecServiceTypeBuff* CFIntRamServiceTypeTable::updateServiceType( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecServiceTypeBuff* Buff )
	{
		static const std::string S_ProcName( "updateServiceType" );
		cfsec::CFSecServiceTypePKey pkey;
		pkey.setRequiredServiceTypeId( Buff->getRequiredServiceTypeId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in ServiceType for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfsec::CFSecServiceTypeBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for ServiceType primary key " );
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
		cfsec::CFSecServiceTypeByUDescrIdxKey existingKeyUDescrIdx;
		existingKeyUDescrIdx.setRequiredDescription( existing->getRequiredDescription() );
		cfsec::CFSecServiceTypeByUDescrIdxKey newKeyUDescrIdx;
		newKeyUDescrIdx.setRequiredDescription( Buff->getRequiredDescription() );
		// Check unique indexes

		if( existingKeyUDescrIdx != newKeyUDescrIdx ) {
			auto searchDictByUDescrIdx = dictByUDescrIdx->find( newKeyUDescrIdx );
			if( searchDictByUDescrIdx != dictByUDescrIdx->end() ) {
				std::string Msg( "Duplicate key detected for index ServiceTypeUDescrIdx " + newKeyUDescrIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		// Update is valid
		std::map<cfsec::CFSecServiceTypePKey, cfsec::CFSecServiceTypeBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfsec::CFSecServiceTypeBuff" );
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

		dictByPKey->insert( std::map<cfsec::CFSecServiceTypePKey, cfsec::CFSecServiceTypeBuff*>::value_type( pkey, existing ) );

		auto removalDictByUDescrIdx = dictByUDescrIdx->find( existingKeyUDescrIdx );
		if( removalDictByUDescrIdx != dictByUDescrIdx->end() ) {
			dictByUDescrIdx->erase( removalDictByUDescrIdx );
		}
		dictByUDescrIdx->insert( std::map<cfsec::CFSecServiceTypeByUDescrIdxKey, cfsec::CFSecServiceTypeBuff*>::value_type( newKeyUDescrIdx, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfsec::CFSecServiceTypeBuff* buff;
		if( existing->getClassCode() == cfsec::CFSecServiceTypeBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfsec::CFSecServiceTypeBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFIntRamServiceTypeTable::deleteServiceType( const cfsec::CFSecAuthorization* Authorization,
		cfsec::CFSecServiceTypeBuff* Buff )
	{
		static const std::string S_ProcName( "deleteServiceType" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfsec::CFSecServiceTypePKey pkey;
		pkey.setRequiredServiceTypeId( Buff->getRequiredServiceTypeId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfsec::CFSecServiceTypeBuff* existing = searchExisting->second;
		std::TCFLibOwningVector<cfsec::CFSecServiceBuff*> arrCheckServiceTypeDeployed = schema->getTableService()->readDerivedByTypeIdx( Authorization,
			existing->getRequiredServiceTypeId() );
		if( arrCheckServiceTypeDeployed.size() > 0 ) {
			schema->getTableService()->deleteServiceByTypeIdx( Authorization,
			existing->getRequiredServiceTypeId() );
		}
		cfsec::CFSecServiceTypeByUDescrIdxKey keyUDescrIdx;
		keyUDescrIdx.setRequiredDescription( existing->getRequiredDescription() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfsec::CFSecServiceTypePKey, cfsec::CFSecServiceTypeBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
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

	void CFIntRamServiceTypeTable::deleteServiceTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argServiceTypeId )
	{
		cfsec::CFSecServiceTypePKey key;
		key.setRequiredServiceTypeId( argServiceTypeId );
		deleteServiceTypeByIdIdx( Authorization, &key );
	}

	void CFIntRamServiceTypeTable::deleteServiceTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypePKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfsec::CFSecServiceTypeBuff* cur = NULL;
		cfsec::CFSecServiceTypeBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> matchSet;
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecServiceTypeBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableServiceType()->readDerivedByIdIdx( Authorization,
				cur->getRequiredServiceTypeId() );
			rereadCur = cur;
			deleteServiceType( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFIntRamServiceTypeTable::deleteServiceTypeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argDescription )
	{
		cfsec::CFSecServiceTypeByUDescrIdxKey key;
		key.setRequiredDescription( argDescription );
		deleteServiceTypeByUDescrIdx( Authorization, &key );
	}

	void CFIntRamServiceTypeTable::deleteServiceTypeByUDescrIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfsec::CFSecServiceTypeByUDescrIdxKey* argKey )
	{
		cfsec::CFSecServiceTypeBuff* cur = NULL;
		cfsec::CFSecServiceTypeBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*> matchSet;
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfsec::CFSecServiceTypePKey,
			cfsec::CFSecServiceTypeBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfsec::CFSecServiceTypeBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfsec::CFSecServiceTypeBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableServiceType()->readDerivedByIdIdx( Authorization,
				cur->getRequiredServiceTypeId() );
			rereadCur = cur;
			deleteServiceType( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamServiceTypeTable::releasePreparedStatements() {
	}

}
