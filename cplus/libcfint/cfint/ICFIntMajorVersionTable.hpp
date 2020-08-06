#pragma once

// Description: C++18 DbIO interface for MajorVersion.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfint/CFIntHPKey.hpp>
#include <cfint/CFIntMajorVersionBuff.hpp>
#include <cfint/CFIntMajorVersionPKey.hpp>
#include <cfint/CFIntMajorVersionHBuff.hpp>
#include <cfint/CFIntMajorVersionHPKey.hpp>
#include <cfint/CFIntMajorVersionByTenantIdxKey.hpp>
#include <cfint/CFIntMajorVersionBySubProjectIdxKey.hpp>
#include <cfint/CFIntMajorVersionByNameIdxKey.hpp>

namespace cfint {
	class ICFIntSchemaObj;
}

namespace cfint {
	class ICFIntMajorVersionObj;

	class ICFIntMajorVersionTable
	{
	public:
		ICFIntMajorVersionTable();
		virtual ~ICFIntMajorVersionTable();

		virtual cfint::CFIntMajorVersionBuff* createMajorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMajorVersionBuff* Buff ) = 0;

		virtual cfint::CFIntMajorVersionBuff* updateMajorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMajorVersionBuff* Buff ) = 0;

		virtual void deleteMajorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMajorVersionBuff* Buff ) = 0;
		virtual void deleteMajorVersionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId ) = 0;

		virtual void deleteMajorVersionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionPKey* argKey ) = 0;
		virtual void deleteMajorVersionByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteMajorVersionByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionByTenantIdxKey* argKey ) = 0;
		virtual void deleteMajorVersionBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argSubProjectId ) = 0;

		virtual void deleteMajorVersionBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionBySubProjectIdxKey* argKey ) = 0;
		virtual void deleteMajorVersionByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argSubProjectId,
			const std::string& argName ) = 0;

		virtual void deleteMajorVersionByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionByNameIdxKey* argKey ) = 0;

		virtual cfint::CFIntMajorVersionBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionPKey* PKey ) = 0;

		virtual cfint::CFIntMajorVersionBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntMajorVersionBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readDerivedBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId ) = 0;

		virtual cfint::CFIntMajorVersionBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntMajorVersionBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionPKey* PKey ) = 0;

		virtual cfint::CFIntMajorVersionBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntMajorVersionBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readBuffBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId ) = 0;

		virtual cfint::CFIntMajorVersionBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntMajorVersionBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::CFIntMajorVersionBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
