#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for Tld.

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
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintsaxloader/CFIntSaxLoader.hpp>

namespace cfint {

	class CFIntRamTldTable
	: public virtual cfint::ICFIntTldTable
	{
	protected:
		cfint::ICFIntSchema* schema;
		std::map<cfint::CFIntTldPKey,
			cfint::CFIntTldBuff*>* dictByPKey;
		std::map<cfint::CFIntTldByTenantIdxKey,
			std::map<cfint::CFIntTldPKey,
				cfint::CFIntTldBuff*>*>* dictByTenantIdx;
		std::map<cfint::CFIntTldByNameIdxKey,
			cfint::CFIntTldBuff*>* dictByNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFIntRamTldTable( cfint::ICFIntSchema* argSchema );

		virtual ~CFIntRamTldTable();

		virtual cfint::CFIntTldBuff* createTld( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTldBuff* Buff );

		virtual cfint::CFIntTldBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey );

		virtual cfint::CFIntTldBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual cfint::CFIntTldBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name );

		virtual cfint::CFIntTldBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual cfint::CFIntTldBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey );

		virtual cfint::CFIntTldBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntTldBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual cfint::CFIntTldBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name );

		virtual cfint::CFIntTldBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntTldBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntTldBuff* updateTld( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTldBuff* Buff );

		virtual void deleteTld( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTldBuff* Buff );
		virtual void deleteTldByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId );

		virtual void deleteTldByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* argKey );

		virtual void deleteTldByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId );

		virtual void deleteTldByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldByTenantIdxKey* argKey );

		virtual void deleteTldByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const std::string& argName );

		virtual void deleteTldByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldByNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
