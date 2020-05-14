#pragma once

// Description: C++18 DbIO interface for SubProject.

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
#include <cfint/CFIntSubProjectBuff.hpp>
#include <cfint/CFIntSubProjectPKey.hpp>
#include <cfint/CFIntSubProjectHBuff.hpp>
#include <cfint/CFIntSubProjectHPKey.hpp>
#include <cfint/CFIntSubProjectByTenantIdxKey.hpp>
#include <cfint/CFIntSubProjectByTopProjectIdxKey.hpp>
#include <cfint/CFIntSubProjectByNameIdxKey.hpp>

namespace cfint {
	class ICFIntSchemaObj;
}

namespace cfint {
	class ICFIntSubProjectObj;

	class ICFIntSubProjectTable
	{
	public:
		ICFIntSubProjectTable();
		virtual ~ICFIntSubProjectTable();

		virtual cfint::CFIntSubProjectBuff* createSubProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntSubProjectBuff* Buff ) = 0;

		virtual cfint::CFIntSubProjectBuff* updateSubProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntSubProjectBuff* Buff ) = 0;

		virtual void deleteSubProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntSubProjectBuff* Buff ) = 0;
		virtual void deleteSubProjectByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId ) = 0;

		virtual void deleteSubProjectByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectPKey* argKey ) = 0;
		virtual void deleteSubProjectByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteSubProjectByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectByTenantIdxKey* argKey ) = 0;
		virtual void deleteSubProjectByTopProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopProjectId ) = 0;

		virtual void deleteSubProjectByTopProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectByTopProjectIdxKey* argKey ) = 0;
		virtual void deleteSubProjectByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopProjectId,
			const std::string& argName ) = 0;

		virtual void deleteSubProjectByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectByNameIdxKey* argKey ) = 0;

		virtual cfint::CFIntSubProjectBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectPKey* PKey ) = 0;

		virtual cfint::CFIntSubProjectBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntSubProjectBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readDerivedByTopProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId ) = 0;

		virtual cfint::CFIntSubProjectBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntSubProjectBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectPKey* PKey ) = 0;

		virtual cfint::CFIntSubProjectBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntSubProjectBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readBuffByTopProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId ) = 0;

		virtual cfint::CFIntSubProjectBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntSubProjectBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::CFIntSubProjectBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
