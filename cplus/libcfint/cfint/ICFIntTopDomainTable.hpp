#pragma once

// Description: C++18 DbIO interface for TopDomain.

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
#include <cfint/CFIntTopDomainBuff.hpp>
#include <cfint/CFIntTopDomainPKey.hpp>
#include <cfint/CFIntTopDomainHBuff.hpp>
#include <cfint/CFIntTopDomainHPKey.hpp>
#include <cfint/CFIntTopDomainByTenantIdxKey.hpp>
#include <cfint/CFIntTopDomainByTldIdxKey.hpp>
#include <cfint/CFIntTopDomainByNameIdxKey.hpp>

namespace cfint {
	class ICFIntSchemaObj;
}

namespace cfint {
	class ICFIntTopDomainObj;

	class ICFIntTopDomainTable
	{
	public:
		ICFIntTopDomainTable();
		virtual ~ICFIntTopDomainTable();

		virtual cfint::CFIntTopDomainBuff* createTopDomain( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopDomainBuff* Buff ) = 0;

		virtual cfint::CFIntTopDomainBuff* updateTopDomain( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopDomainBuff* Buff ) = 0;

		virtual void deleteTopDomain( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopDomainBuff* Buff ) = 0;
		virtual void deleteTopDomainByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId ) = 0;

		virtual void deleteTopDomainByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainPKey* argKey ) = 0;
		virtual void deleteTopDomainByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteTopDomainByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainByTenantIdxKey* argKey ) = 0;
		virtual void deleteTopDomainByTldIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTldId ) = 0;

		virtual void deleteTopDomainByTldIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainByTldIdxKey* argKey ) = 0;
		virtual void deleteTopDomainByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTldId,
			const std::string& argName ) = 0;

		virtual void deleteTopDomainByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainByNameIdxKey* argKey ) = 0;

		virtual cfint::CFIntTopDomainBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainPKey* PKey ) = 0;

		virtual cfint::CFIntTopDomainBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntTopDomainBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readDerivedByTldIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId ) = 0;

		virtual cfint::CFIntTopDomainBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntTopDomainBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainPKey* PKey ) = 0;

		virtual cfint::CFIntTopDomainBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntTopDomainBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readBuffByTldIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId ) = 0;

		virtual cfint::CFIntTopDomainBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntTopDomainBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::CFIntTopDomainBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
