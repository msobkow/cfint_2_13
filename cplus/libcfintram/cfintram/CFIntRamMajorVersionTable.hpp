#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for MajorVersion.

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
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintsaxloader/CFIntSaxLoader.hpp>

namespace cfint {

	class CFIntRamMajorVersionTable
	: public virtual cfint::ICFIntMajorVersionTable
	{
	protected:
		cfint::ICFIntSchema* schema;
		std::map<cfint::CFIntMajorVersionPKey,
			cfint::CFIntMajorVersionBuff*>* dictByPKey;
		std::map<cfint::CFIntMajorVersionByTenantIdxKey,
			std::map<cfint::CFIntMajorVersionPKey,
				cfint::CFIntMajorVersionBuff*>*>* dictByTenantIdx;
		std::map<cfint::CFIntMajorVersionBySubProjectIdxKey,
			std::map<cfint::CFIntMajorVersionPKey,
				cfint::CFIntMajorVersionBuff*>*>* dictBySubProjectIdx;
		std::map<cfint::CFIntMajorVersionByNameIdxKey,
			cfint::CFIntMajorVersionBuff*>* dictByNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFIntRamMajorVersionTable( cfint::ICFIntSchema* argSchema );

		virtual ~CFIntRamMajorVersionTable();

		virtual cfint::CFIntMajorVersionBuff* createMajorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMajorVersionBuff* Buff );

		virtual cfint::CFIntMajorVersionBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionPKey* PKey );

		virtual cfint::CFIntMajorVersionBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readDerivedBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId );

		virtual cfint::CFIntMajorVersionBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name );

		virtual cfint::CFIntMajorVersionBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual cfint::CFIntMajorVersionBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionPKey* PKey );

		virtual cfint::CFIntMajorVersionBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntMajorVersionBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntMajorVersionBuff*> readBuffBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId );

		virtual cfint::CFIntMajorVersionBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId,
			const std::string& Name );

		virtual cfint::CFIntMajorVersionBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntMajorVersionBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t SubProjectId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntMajorVersionBuff* updateMajorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMajorVersionBuff* Buff );

		virtual void deleteMajorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMajorVersionBuff* Buff );
		virtual void deleteMajorVersionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId );

		virtual void deleteMajorVersionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionPKey* argKey );

		virtual void deleteMajorVersionByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId );

		virtual void deleteMajorVersionByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionByTenantIdxKey* argKey );

		virtual void deleteMajorVersionBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argSubProjectId );

		virtual void deleteMajorVersionBySubProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionBySubProjectIdxKey* argKey );

		virtual void deleteMajorVersionByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argSubProjectId,
			const std::string& argName );

		virtual void deleteMajorVersionByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMajorVersionByNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
