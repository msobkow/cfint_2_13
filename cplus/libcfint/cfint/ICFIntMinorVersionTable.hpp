#pragma once

// Description: C++18 DbIO interface for MinorVersion.

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
#include <cfint/CFIntMinorVersionBuff.hpp>
#include <cfint/CFIntMinorVersionPKey.hpp>
#include <cfint/CFIntMinorVersionHBuff.hpp>
#include <cfint/CFIntMinorVersionHPKey.hpp>
#include <cfint/CFIntMinorVersionByTenantIdxKey.hpp>
#include <cfint/CFIntMinorVersionByMajorVerIdxKey.hpp>
#include <cfint/CFIntMinorVersionByNameIdxKey.hpp>

namespace cfint {
	class ICFIntSchemaObj;
}

namespace cfint {
	class ICFIntMinorVersionObj;

	class ICFIntMinorVersionTable
	{
	public:
		ICFIntMinorVersionTable();
		virtual ~ICFIntMinorVersionTable();

		virtual cfint::CFIntMinorVersionBuff* createMinorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMinorVersionBuff* Buff ) = 0;

		virtual cfint::CFIntMinorVersionBuff* updateMinorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMinorVersionBuff* Buff ) = 0;

		virtual void deleteMinorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMinorVersionBuff* Buff ) = 0;
		virtual void deleteMinorVersionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId ) = 0;

		virtual void deleteMinorVersionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionPKey* argKey ) = 0;
		virtual void deleteMinorVersionByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteMinorVersionByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionByTenantIdxKey* argKey ) = 0;
		virtual void deleteMinorVersionByMajorVerIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argMajorVersionId ) = 0;

		virtual void deleteMinorVersionByMajorVerIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionByMajorVerIdxKey* argKey ) = 0;
		virtual void deleteMinorVersionByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argMajorVersionId,
			const std::string& argName ) = 0;

		virtual void deleteMinorVersionByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionByNameIdxKey* argKey ) = 0;

		virtual cfint::CFIntMinorVersionBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionPKey* PKey ) = 0;

		virtual cfint::CFIntMinorVersionBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntMinorVersionBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readDerivedByMajorVerIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId ) = 0;

		virtual cfint::CFIntMinorVersionBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntMinorVersionBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionPKey* PKey ) = 0;

		virtual cfint::CFIntMinorVersionBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntMinorVersionBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readBuffByMajorVerIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId ) = 0;

		virtual cfint::CFIntMinorVersionBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntMinorVersionBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::CFIntMinorVersionBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
