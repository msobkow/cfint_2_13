#pragma once

// Description: C++18 DbIO interface for TopProject.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfint/CFIntHPKey.hpp>
#include <cfint/CFIntTopProjectBuff.hpp>
#include <cfint/CFIntTopProjectPKey.hpp>
#include <cfint/CFIntTopProjectHBuff.hpp>
#include <cfint/CFIntTopProjectHPKey.hpp>
#include <cfint/CFIntTopProjectByTenantIdxKey.hpp>
#include <cfint/CFIntTopProjectByTopDomainIdxKey.hpp>
#include <cfint/CFIntTopProjectByNameIdxKey.hpp>

namespace cfint {
	class ICFIntSchemaObj;
}

namespace cfint {
	class ICFIntTopProjectObj;

	class ICFIntTopProjectTable
	{
	public:
		ICFIntTopProjectTable();
		virtual ~ICFIntTopProjectTable();

		virtual cfint::CFIntTopProjectBuff* createTopProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopProjectBuff* Buff ) = 0;

		virtual cfint::CFIntTopProjectBuff* updateTopProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopProjectBuff* Buff ) = 0;

		virtual void deleteTopProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopProjectBuff* Buff ) = 0;
		virtual void deleteTopProjectByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId ) = 0;

		virtual void deleteTopProjectByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectPKey* argKey ) = 0;
		virtual void deleteTopProjectByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteTopProjectByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectByTenantIdxKey* argKey ) = 0;
		virtual void deleteTopProjectByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId ) = 0;

		virtual void deleteTopProjectByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectByTopDomainIdxKey* argKey ) = 0;
		virtual void deleteTopProjectByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId,
			const std::string& argName ) = 0;

		virtual void deleteTopProjectByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectByNameIdxKey* argKey ) = 0;

		virtual cfint::CFIntTopProjectBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectPKey* PKey ) = 0;

		virtual cfint::CFIntTopProjectBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntTopProjectBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readDerivedByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId ) = 0;

		virtual cfint::CFIntTopProjectBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntTopProjectBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectPKey* PKey ) = 0;

		virtual cfint::CFIntTopProjectBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntTopProjectBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readBuffByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId ) = 0;

		virtual cfint::CFIntTopProjectBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntTopProjectBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::CFIntTopProjectBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
