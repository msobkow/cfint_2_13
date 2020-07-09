#pragma once

// Description: C++18 DbIO interface for Tld.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfint/CFIntHPKey.hpp>
#include <cfint/CFIntTldBuff.hpp>
#include <cfint/CFIntTldPKey.hpp>
#include <cfint/CFIntTldHBuff.hpp>
#include <cfint/CFIntTldHPKey.hpp>
#include <cfint/CFIntTldByTenantIdxKey.hpp>
#include <cfint/CFIntTldByNameIdxKey.hpp>

namespace cfint {
	class ICFIntSchemaObj;
}

namespace cfint {
	class ICFIntTldObj;

	class ICFIntTldTable
	{
	public:
		ICFIntTldTable();
		virtual ~ICFIntTldTable();

		virtual cfint::CFIntTldBuff* createTld( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTldBuff* Buff ) = 0;

		virtual cfint::CFIntTldBuff* updateTld( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTldBuff* Buff ) = 0;

		virtual void deleteTld( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTldBuff* Buff ) = 0;
		virtual void deleteTldByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId ) = 0;

		virtual void deleteTldByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* argKey ) = 0;
		virtual void deleteTldByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteTldByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldByTenantIdxKey* argKey ) = 0;
		virtual void deleteTldByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const std::string& argName ) = 0;

		virtual void deleteTldByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldByNameIdxKey* argKey ) = 0;

		virtual cfint::CFIntTldBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey ) = 0;

		virtual cfint::CFIntTldBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntTldBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual cfint::CFIntTldBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntTldBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey ) = 0;

		virtual cfint::CFIntTldBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntTldBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual cfint::CFIntTldBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntTldBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::CFIntTldBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
