
// Description: C++18 Implementation for an in-memory RAM DbIO for URLProtocol.

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

	const std::string CFIntRamURLProtocolTable::CLASS_NAME( "CFIntRamURLProtocolTable" );

	CFIntRamURLProtocolTable::CFIntRamURLProtocolTable( ICFIntSchema* argSchema )
	: cfint::ICFIntURLProtocolTable()
	{
		schema = argSchema;
		dictByPKey = new std::map<cfint::CFIntURLProtocolPKey, cfint::CFIntURLProtocolBuff*>();
		dictByUNameIdx = new std::map<cfint::CFIntURLProtocolByUNameIdxKey, cfint::CFIntURLProtocolBuff*>();
		dictByIsSecureIdx = new std::map<cfint::CFIntURLProtocolByIsSecureIdxKey,
			std::map<cfint::CFIntURLProtocolPKey,
				cfint::CFIntURLProtocolBuff*>*>();
	}

	CFIntRamURLProtocolTable::~CFIntRamURLProtocolTable() {
		if( dictByUNameIdx != NULL ) {
			delete dictByUNameIdx;
			dictByUNameIdx = NULL;
		}
		if( dictByIsSecureIdx != NULL ) {
			for( auto iterDict = dictByIsSecureIdx->begin(); iterDict != dictByIsSecureIdx->end(); iterDict ++ ) {
				delete iterDict->second;
				iterDict->second = NULL;
			}
			delete dictByIsSecureIdx;
			dictByIsSecureIdx = NULL;
		}
		if( dictByPKey != NULL ) {
			cfint::CFIntURLProtocolBuff* elt;
			std::map<cfint::CFIntURLProtocolPKey,
				cfint::CFIntURLProtocolBuff*>::iterator end = dictByPKey->end();
			for( std::map<cfint::CFIntURLProtocolPKey,
					cfint::CFIntURLProtocolBuff*>::iterator cur = dictByPKey->begin();
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

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::createURLProtocol( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntURLProtocolBuff* Buff )
	{
		static const std::string S_ProcName( "createURLProtocol" );
		cfint::CFIntURLProtocolPKey pkey;
		pkey.setRequiredURLProtocolId( schema->nextURLProtocolIdGen() );
		Buff->setRequiredURLProtocolId( pkey.getRequiredURLProtocolId() );
		cfint::CFIntURLProtocolByUNameIdxKey keyUNameIdx;
		keyUNameIdx.setRequiredName( Buff->getRequiredName() );
		cfint::CFIntURLProtocolByIsSecureIdxKey keyIsSecureIdx;
		keyIsSecureIdx.setRequiredIsSecure( Buff->getRequiredIsSecure() );
		// Validate unique indexes
		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Duplicate primary key detected " + pkey.toString() );
			throw cflib::CFLibPrimaryKeyNotNewException( CLASS_NAME, S_ProcName, Msg );
		}

		auto searchDictByUNameIdx = dictByUNameIdx->find( keyUNameIdx );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			std::string Msg( "Duplicate key detected for index URLProtocolUNameIdx " + keyUNameIdx.toString() );
			delete Buff;
			throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		// Validate foreign keys

		// Proceed with adding the new record
		cfint::CFIntURLProtocolBuff* buff = Buff;
		buff->setRequiredRevision( 1 );
		dictByPKey->insert( std::map<cfint::CFIntURLProtocolPKey, cfint::CFIntURLProtocolBuff*>::value_type( pkey, buff ) );

		dictByUNameIdx->insert( std::map<cfint::CFIntURLProtocolByUNameIdxKey, cfint::CFIntURLProtocolBuff*>::value_type( keyUNameIdx, buff ) );

		std::map<cfint::CFIntURLProtocolPKey, cfint::CFIntURLProtocolBuff*>* subdictIsSecureIdx;
		auto searchDictByIsSecureIdx = dictByIsSecureIdx->find( keyIsSecureIdx );
		if( searchDictByIsSecureIdx != dictByIsSecureIdx->end() ) {
			subdictIsSecureIdx = searchDictByIsSecureIdx->second;
		}
		else {
			subdictIsSecureIdx = new std::map<cfint::CFIntURLProtocolPKey, cfint::CFIntURLProtocolBuff*>();
			dictByIsSecureIdx->insert( std::map<cfint::CFIntURLProtocolByIsSecureIdxKey,
				std::map<cfint::CFIntURLProtocolPKey,
					cfint::CFIntURLProtocolBuff*>*>::value_type( keyIsSecureIdx, subdictIsSecureIdx ) );
		}
		subdictIsSecureIdx->insert( std::map<cfint::CFIntURLProtocolPKey, cfint::CFIntURLProtocolBuff*>::value_type( pkey, buff ) );

		// The top level code has to clone the final buffer. The one passed in is now part of the persistent storage.
		if( buff->getClassCode() == cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
			buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff->clone() );
		}
		return( buff );
	}

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::readDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntURLProtocolPKey* PKey )
	{
		static const std::string S_ProcName( "readDerived" );
		cfint::CFIntURLProtocolBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::lockDerived( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntURLProtocolPKey* PKey )
	{
		static const std::string S_ProcName( "lockDerived" );
		cfint::CFIntURLProtocolBuff* buff;
		auto searchDictByPKey = dictByPKey->find( *PKey );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff->clone() );
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

	std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> CFIntRamURLProtocolTable::readAllDerived( const cfsec::CFSecAuthorization* Authorization ) {
		static const std::string S_ProcName( "readAllDerived" );
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> retVec;
		std::map<cfint::CFIntURLProtocolPKey,
			cfint::CFIntURLProtocolBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntURLProtocolPKey,
			cfint::CFIntURLProtocolBuff*>::iterator end = dictByPKey->end();
		cfint::CFIntURLProtocolBuff* clone;
		while( iter != end ) {
			clone = dynamic_cast<cfint::CFIntURLProtocolBuff*>( iter->second->clone() );
			retVec.push_back( clone );
			iter ++;
		}
		return( retVec );
	}

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readDerivedByUNameIdx" );
		cfint::CFIntURLProtocolByUNameIdxKey key;
		key.setRequiredName( Name );
		cfint::CFIntURLProtocolBuff* buff;
		auto searchDictByUNameIdx = dictByUNameIdx->find( key );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( searchDictByUNameIdx->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> CFIntRamURLProtocolTable::readDerivedByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
			const bool IsSecure )
	{
		static const std::string S_ProcName( "readDerivedByIsSecureIdx" );
		cfint::CFIntURLProtocolByIsSecureIdxKey key;
		key.setRequiredIsSecure( IsSecure );
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> recVec;
		cfint::CFIntURLProtocolBuff* clone;
		auto searchDictByIsSecureIdx = dictByIsSecureIdx->find( key );
		if( searchDictByIsSecureIdx != dictByIsSecureIdx->end() ) {
			std::map<cfint::CFIntURLProtocolPKey,
				 cfint::CFIntURLProtocolBuff*>* subdictIsSecureIdx = searchDictByIsSecureIdx->second;
			std::map<cfint::CFIntURLProtocolPKey,
				cfint::CFIntURLProtocolBuff*>::iterator iter = subdictIsSecureIdx->begin();
			std::map<cfint::CFIntURLProtocolPKey,
				cfint::CFIntURLProtocolBuff*>::iterator end = subdictIsSecureIdx->end();
			while( iter != end ) {
				clone = dynamic_cast<cfint::CFIntURLProtocolBuff*>( iter->second->clone() );
				recVec.push_back( clone );
				iter ++;
			}
		}
		return( recVec );
	}

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t URLProtocolId )
	{
		static const std::string S_ProcName( "readDerivedByIdIdx" );
		cfint::CFIntURLProtocolPKey key;
		key.setRequiredURLProtocolId( URLProtocolId );
		cfint::CFIntURLProtocolBuff* buff;
		auto searchDictByPKey = dictByPKey->find( key );
		if( searchDictByPKey != dictByPKey->end() ) {
			buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( searchDictByPKey->second );
			if( buff != NULL ) {
				buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff->clone() );
			}
		}
		else {
			buff = NULL;
		}
		return( buff );
	}

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::readBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntURLProtocolPKey* PKey )
	{
		static const std::string S_ProcName( "readBuff" );
		cfint::CFIntURLProtocolBuff* buff = readDerived( Authorization, PKey );
		if( buff != NULL ) {
			if( buff->getClassCode() != cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
				delete buff;
				buff = NULL;
			}
		}
		return( dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff ) );
	}

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::lockBuff( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntURLProtocolPKey* PKey )
	{
		static const std::string S_ProcName( "lockBuff" );
		cfint::CFIntURLProtocolBuff* buff = lockDerived( Authorization, PKey );
		return( dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff ) );
	}

	std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> CFIntRamURLProtocolTable::readAllBuff( const cfsec::CFSecAuthorization* Authorization )
	{
		static const std::string S_ProcName( "readAllBuff" );
		cfint::CFIntURLProtocolBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> buffList = readAllDerived( Authorization );
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntURLProtocolBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t URLProtocolId )
	{
		static const std::string S_ProcName( "readBuffByIdIdx" );
		cfint::CFIntURLProtocolBuff* buff = readDerivedByIdIdx( Authorization,
			URLProtocolId );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name )
	{
		static const std::string S_ProcName( "readBuffByUNameIdx" );
		cfint::CFIntURLProtocolBuff* buff = readDerivedByUNameIdx( Authorization,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> CFIntRamURLProtocolTable::readBuffByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
			const bool IsSecure )
	{
		static const std::string S_ProcName( "readBuffByIsSecureIdx" );
		cfint::CFIntURLProtocolBuff* buff;
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> filteredList;
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> buffList = readDerivedByIsSecureIdx( Authorization,
			IsSecure );
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*>::iterator iterBuffList = buffList.begin();
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*>::iterator endBuffList = buffList.end();
		while( iterBuffList != endBuffList ) {
			buff = *iterBuffList;
			iterBuffList ++;
			if( ( buff != NULL ) && ( buff->getClassCode() == cfint::CFIntURLProtocolBuff::CLASS_CODE ) ) {
				filteredList.push_back( dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff->clone() ) );
			}
		}
		return( filteredList );
	}

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readBuffByLookupUNameIdx" );
		cfint::CFIntURLProtocolBuff* buff = readBuffByUNameIdx( Authorization,
			Name );
		if( buff == NULL ) {
			return( NULL );
		}
		else if( buff->getClassCode() == cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
			return( dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff ) );
		}
		else {
			delete buff;
			buff = NULL;
			return( NULL );
		}
	}

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
		bool forceRead )
	{
		static const std::string S_ProcName( "readDerivedByLookupUNameIdx" );
		cfint::CFIntURLProtocolBuff* buff = readDerivedByUNameIdx( Authorization,
			Name );
		if( buff != NULL ) {
			return( dynamic_cast<cfint::CFIntURLProtocolBuff*>( buff->clone() ) );
		}
		else {
			return( NULL );
		}
	}

	cfint::CFIntURLProtocolBuff* CFIntRamURLProtocolTable::updateURLProtocol( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntURLProtocolBuff* Buff )
	{
		static const std::string S_ProcName( "updateURLProtocol" );
		cfint::CFIntURLProtocolPKey pkey;
		pkey.setRequiredURLProtocolId( Buff->getRequiredURLProtocolId() );

		// Search for existing buffer

		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			delete Buff;
			std::string Msg( "Existing record not found in URLProtocol for key " + pkey.toString() );
			throw cflib::CFLibStaleCacheDetectedException( CLASS_NAME,
				S_ProcName,
				Msg );
		}

		cfint::CFIntURLProtocolBuff* existing = searchExisting->second;

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
			std::string Msg( "Collision detected for URLProtocol primary key " );
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
		cfint::CFIntURLProtocolByUNameIdxKey existingKeyUNameIdx;
		existingKeyUNameIdx.setRequiredName( existing->getRequiredName() );
		cfint::CFIntURLProtocolByUNameIdxKey newKeyUNameIdx;
		newKeyUNameIdx.setRequiredName( Buff->getRequiredName() );
		cfint::CFIntURLProtocolByIsSecureIdxKey existingKeyIsSecureIdx;
		existingKeyIsSecureIdx.setRequiredIsSecure( existing->getRequiredIsSecure() );
		cfint::CFIntURLProtocolByIsSecureIdxKey newKeyIsSecureIdx;
		newKeyIsSecureIdx.setRequiredIsSecure( Buff->getRequiredIsSecure() );
		// Check unique indexes

		if( existingKeyUNameIdx != newKeyUNameIdx ) {
			auto searchDictByUNameIdx = dictByUNameIdx->find( newKeyUNameIdx );
			if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
				std::string Msg( "Duplicate key detected for index URLProtocolUNameIdx " + newKeyUNameIdx.toString() );
				delete Buff;
				throw cflib::CFLibUniqueIndexViolationException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
		}

		// Validate foreign keys

		// Update is valid
		std::map<cfint::CFIntURLProtocolPKey, cfint::CFIntURLProtocolBuff*>* subdict;
		auto removalDictByPKey = dictByPKey->find( pkey );
		if( removalDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( removalDictByPKey );
		}
		// Copy edited buffer to existing persistent buffer

		if( Buff->getClassCode() != cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
			const static std::string S_IsNotA( " is not a cfint::CFIntURLProtocolBuff" );
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

		dictByPKey->insert( std::map<cfint::CFIntURLProtocolPKey, cfint::CFIntURLProtocolBuff*>::value_type( pkey, existing ) );

		auto removalDictByUNameIdx = dictByUNameIdx->find( existingKeyUNameIdx );
		if( removalDictByUNameIdx != dictByUNameIdx->end() ) {
			dictByUNameIdx->erase( removalDictByUNameIdx );
		}
		dictByUNameIdx->insert( std::map<cfint::CFIntURLProtocolByUNameIdxKey, cfint::CFIntURLProtocolBuff*>::value_type( newKeyUNameIdx, existing ) );

		std::map<cfint::CFIntURLProtocolPKey,
			 cfint::CFIntURLProtocolBuff*>* subdictIsSecureIdx;
		auto searchDictByIsSecureIdx = dictByIsSecureIdx->find( existingKeyIsSecureIdx );
		if( searchDictByIsSecureIdx != dictByIsSecureIdx->end() ) {
			subdictIsSecureIdx = searchDictByIsSecureIdx->second;
			auto searchSubDict = subdictIsSecureIdx->find( pkey );
			if( searchSubDict != subdictIsSecureIdx->end() ) {
				subdictIsSecureIdx->erase( searchSubDict );
			}
			if( subdictIsSecureIdx->size() <= 0 ) {
				delete subdictIsSecureIdx;
				dictByIsSecureIdx->erase( searchDictByIsSecureIdx );
			}
			subdictIsSecureIdx = NULL;
		}
		auto searchNewKeyDictByIsSecureIdx = dictByIsSecureIdx->find( newKeyIsSecureIdx );
		if( searchNewKeyDictByIsSecureIdx != dictByIsSecureIdx->end() ) {
			subdictIsSecureIdx = searchNewKeyDictByIsSecureIdx->second;
		}
		else {
			subdictIsSecureIdx = new std::map<cfint::CFIntURLProtocolPKey, cfint::CFIntURLProtocolBuff*>();
			dictByIsSecureIdx->insert( std::map<cfint::CFIntURLProtocolByIsSecureIdxKey,
				std::map<cfint::CFIntURLProtocolPKey,
					cfint::CFIntURLProtocolBuff*>*>::value_type( newKeyIsSecureIdx, subdictIsSecureIdx ) );
		}
		subdictIsSecureIdx->insert( std::map<cfint::CFIntURLProtocolPKey, cfint::CFIntURLProtocolBuff*>::value_type( pkey, existing ) );


		// The top level code has to clean up the memory buffer that was passed in, and return a clone
		// of the copy that existing buffer that is attached to the RAM storage.  All other cases
		// return the existing buffer.

		cfint::CFIntURLProtocolBuff* buff;
		if( existing->getClassCode() == cfint::CFIntURLProtocolBuff::CLASS_CODE ) {
			delete Buff;
			Buff = NULL;
			buff = dynamic_cast<cfint::CFIntURLProtocolBuff*>( existing->clone() );
		}
		else {
			buff = existing;
		}
		return( buff );
	}

	void CFIntRamURLProtocolTable::deleteURLProtocol( const cfsec::CFSecAuthorization* Authorization,
		cfint::CFIntURLProtocolBuff* Buff )
	{
		static const std::string S_ProcName( "deleteURLProtocol" );
		static const std::string S_Prev( "prev" );
		classcode_t classCode;
		cfint::CFIntURLProtocolPKey pkey;
		pkey.setRequiredURLProtocolId( Buff->getRequiredURLProtocolId() );
		auto searchExisting = dictByPKey->find( pkey );
		if( searchExisting == dictByPKey->end() ) {
			return;
		}
		cfint::CFIntURLProtocolBuff* existing = searchExisting->second;
		cfint::CFIntURLProtocolByUNameIdxKey keyUNameIdx;
		keyUNameIdx.setRequiredName( existing->getRequiredName() );
		cfint::CFIntURLProtocolByIsSecureIdxKey keyIsSecureIdx;
		keyIsSecureIdx.setRequiredIsSecure( existing->getRequiredIsSecure() );
		// Validate reverse foreign keys

		// Delete is valid
		std::map<cfint::CFIntURLProtocolPKey, cfint::CFIntURLProtocolBuff*>* subdict;

		auto searchDictByPKey = dictByPKey->find( pkey );
		if( searchDictByPKey != dictByPKey->end() ) {
			dictByPKey->erase( searchDictByPKey );
		}

		auto searchDictByUNameIdx = dictByUNameIdx->find( keyUNameIdx );
		if( searchDictByUNameIdx != dictByUNameIdx->end() ) {
			dictByUNameIdx->erase( searchDictByUNameIdx );
		}

		auto searchDictByIsSecureIdx = dictByIsSecureIdx->find( keyIsSecureIdx );
		if( searchDictByIsSecureIdx != dictByIsSecureIdx->end() ) {
			std::map<cfint::CFIntURLProtocolPKey,
				 cfint::CFIntURLProtocolBuff*>* subdictIsSecureIdx = searchDictByIsSecureIdx->second;
			auto searchSubDict = subdictIsSecureIdx->find( pkey );
			if( searchSubDict != subdictIsSecureIdx->end() ) {
				subdictIsSecureIdx->erase( searchSubDict );
			}
			subdictIsSecureIdx = NULL;
		}

		if( existing != NULL ) {
			delete existing;
			existing = NULL;
		}
	}

	void CFIntRamURLProtocolTable::deleteURLProtocolByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argURLProtocolId )
	{
		cfint::CFIntURLProtocolPKey key;
		key.setRequiredURLProtocolId( argURLProtocolId );
		deleteURLProtocolByIdIdx( Authorization, &key );
	}

	void CFIntRamURLProtocolTable::deleteURLProtocolByIdIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntURLProtocolPKey* argKey )
	{
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		cfint::CFIntURLProtocolBuff* cur = NULL;
		cfint::CFIntURLProtocolBuff* rereadCur = NULL;
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> matchSet;
		std::map<cfint::CFIntURLProtocolPKey,
			cfint::CFIntURLProtocolBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntURLProtocolPKey,
			cfint::CFIntURLProtocolBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntURLProtocolBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntURLProtocolBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableURLProtocol()->readDerivedByIdIdx( Authorization,
				cur->getRequiredURLProtocolId() );
			rereadCur = cur;
			deleteURLProtocol( Authorization, cur );
			if( rereadCur != NULL ) {
				delete rereadCur;
				rereadCur = NULL;
			}
		}
	}

	void CFIntRamURLProtocolTable::deleteURLProtocolByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName )
	{
		cfint::CFIntURLProtocolByUNameIdxKey key;
		key.setRequiredName( argName );
		deleteURLProtocolByUNameIdx( Authorization, &key );
	}

	void CFIntRamURLProtocolTable::deleteURLProtocolByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntURLProtocolByUNameIdxKey* argKey )
	{
		cfint::CFIntURLProtocolBuff* cur = NULL;
		cfint::CFIntURLProtocolBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> matchSet;
		std::map<cfint::CFIntURLProtocolPKey,
			cfint::CFIntURLProtocolBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntURLProtocolPKey,
			cfint::CFIntURLProtocolBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntURLProtocolBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntURLProtocolBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableURLProtocol()->readDerivedByIdIdx( Authorization,
				cur->getRequiredURLProtocolId() );
			rereadCur = cur;
			deleteURLProtocol( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamURLProtocolTable::deleteURLProtocolByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
			const bool argIsSecure )
	{
		cfint::CFIntURLProtocolByIsSecureIdxKey key;
		key.setRequiredIsSecure( argIsSecure );
		deleteURLProtocolByIsSecureIdx( Authorization, &key );
	}

	void CFIntRamURLProtocolTable::deleteURLProtocolByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
		const cfint::CFIntURLProtocolByIsSecureIdxKey* argKey )
	{
		cfint::CFIntURLProtocolBuff* cur = NULL;
		cfint::CFIntURLProtocolBuff* rereadCur = NULL;
		bool anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> matchSet;
		std::map<cfint::CFIntURLProtocolPKey,
			cfint::CFIntURLProtocolBuff*>::iterator iter = dictByPKey->begin();
		std::map<cfint::CFIntURLProtocolPKey,
			cfint::CFIntURLProtocolBuff*>::iterator end = dictByPKey->end();
		while( iter != end ) {
			cur = iter->second;
			iter ++;
			if( *dynamic_cast<cfint::CFIntURLProtocolBuff*>( cur ) == *argKey ) {
				matchSet.push_back( dynamic_cast<cfint::CFIntURLProtocolBuff*>( cur->clone() ) );
			}
		}
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*>::iterator iterMatch = matchSet.begin();
		std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*>::iterator matchEnd = matchSet.end();
		while( iterMatch != matchEnd ) {
			cur = *iterMatch;
			iterMatch ++;
			cur = schema->getTableURLProtocol()->readDerivedByIdIdx( Authorization,
				cur->getRequiredURLProtocolId() );
			rereadCur = cur;
			deleteURLProtocol( Authorization, cur );
			delete rereadCur;
			rereadCur = NULL;
		}
	}

	void CFIntRamURLProtocolTable::releasePreparedStatements() {
	}

}
