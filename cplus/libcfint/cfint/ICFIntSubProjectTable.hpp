#pragma once

// Description: C++18 DbIO interface for SubProject.

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
