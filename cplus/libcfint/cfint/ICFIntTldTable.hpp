#pragma once

// Description: C++18 DbIO interface for Tld.

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
