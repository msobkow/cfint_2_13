#pragma once

// Description: C++18 DbIO interface for TopDomain.

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
