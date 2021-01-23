#pragma once

// Description: C++18 DbIO interface for MinorVersion.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
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
