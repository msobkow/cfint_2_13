#pragma once

// Description: C++18 DbIO interface for License.

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
#include <cfint/CFIntLicenseBuff.hpp>
#include <cfint/CFIntLicensePKey.hpp>
#include <cfint/CFIntLicenseHBuff.hpp>
#include <cfint/CFIntLicenseHPKey.hpp>
#include <cfint/CFIntLicenseByLicnTenantIdxKey.hpp>
#include <cfint/CFIntLicenseByDomainIdxKey.hpp>
#include <cfint/CFIntLicenseByUNameIdxKey.hpp>

namespace cfint {
	class ICFIntSchemaObj;
}

namespace cfint {
	class ICFIntLicenseObj;

	class ICFIntLicenseTable
	{
	public:
		ICFIntLicenseTable();
		virtual ~ICFIntLicenseTable();

		virtual cfint::CFIntLicenseBuff* createLicense( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntLicenseBuff* Buff ) = 0;

		virtual cfint::CFIntLicenseBuff* updateLicense( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntLicenseBuff* Buff ) = 0;

		virtual void deleteLicense( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntLicenseBuff* Buff ) = 0;
		virtual void deleteLicenseByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId ) = 0;

		virtual void deleteLicenseByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicensePKey* argKey ) = 0;
		virtual void deleteLicenseByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId ) = 0;

		virtual void deleteLicenseByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicenseByLicnTenantIdxKey* argKey ) = 0;
		virtual void deleteLicenseByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId ) = 0;

		virtual void deleteLicenseByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicenseByDomainIdxKey* argKey ) = 0;
		virtual void deleteLicenseByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId,
			const std::string& argName ) = 0;

		virtual void deleteLicenseByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicenseByUNameIdxKey* argKey ) = 0;

		virtual cfint::CFIntLicenseBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicensePKey* PKey ) = 0;

		virtual cfint::CFIntLicenseBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicensePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntLicenseBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readDerivedByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readDerivedByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId ) = 0;

		virtual cfint::CFIntLicenseBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntLicenseBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicensePKey* PKey ) = 0;

		virtual cfint::CFIntLicenseBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicensePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntLicenseBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readBuffByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readBuffByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId ) = 0;

		virtual cfint::CFIntLicenseBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name ) = 0;

		virtual cfint::CFIntLicenseBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::CFIntLicenseBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
