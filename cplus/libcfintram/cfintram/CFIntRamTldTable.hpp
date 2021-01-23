#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for Tld.

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
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintsaxloader/CFIntSaxLoader.hpp>

namespace cfint {

	class CFIntRamTldTable
	: public virtual cfint::ICFIntTldTable
	{
	protected:
		cfint::ICFIntSchema* schema;
		std::map<cfint::CFIntTldPKey,
			cfint::CFIntTldBuff*>* dictByPKey;
		std::map<cfint::CFIntTldByTenantIdxKey,
			std::map<cfint::CFIntTldPKey,
				cfint::CFIntTldBuff*>*>* dictByTenantIdx;
		std::map<cfint::CFIntTldByNameIdxKey,
			cfint::CFIntTldBuff*>* dictByNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFIntRamTldTable( cfint::ICFIntSchema* argSchema );

		virtual ~CFIntRamTldTable();

		virtual cfint::CFIntTldBuff* createTld( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTldBuff* Buff );

		virtual cfint::CFIntTldBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey );

		virtual cfint::CFIntTldBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual cfint::CFIntTldBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name );

		virtual cfint::CFIntTldBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual cfint::CFIntTldBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey );

		virtual cfint::CFIntTldBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntTldBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual std::TCFLibOwningVector<cfint::CFIntTldBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual cfint::CFIntTldBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const std::string& Name );

		virtual cfint::CFIntTldBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntTldBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntTldBuff* updateTld( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTldBuff* Buff );

		virtual void deleteTld( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTldBuff* Buff );
		virtual void deleteTldByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId );

		virtual void deleteTldByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldPKey* argKey );

		virtual void deleteTldByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId );

		virtual void deleteTldByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldByTenantIdxKey* argKey );

		virtual void deleteTldByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const std::string& argName );

		virtual void deleteTldByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTldByNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
