#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for MinorVersion.

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

	class CFIntRamMinorVersionTable
	: public virtual cfint::ICFIntMinorVersionTable
	{
	protected:
		cfint::ICFIntSchema* schema;
		std::map<cfint::CFIntMinorVersionPKey,
			cfint::CFIntMinorVersionBuff*>* dictByPKey;
		std::map<cfint::CFIntMinorVersionByTenantIdxKey,
			std::map<cfint::CFIntMinorVersionPKey,
				cfint::CFIntMinorVersionBuff*>*>* dictByTenantIdx;
		std::map<cfint::CFIntMinorVersionByMajorVerIdxKey,
			std::map<cfint::CFIntMinorVersionPKey,
				cfint::CFIntMinorVersionBuff*>*>* dictByMajorVerIdx;
		std::map<cfint::CFIntMinorVersionByNameIdxKey,
			cfint::CFIntMinorVersionBuff*>* dictByNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFIntRamMinorVersionTable( cfint::ICFIntSchema* argSchema );

		virtual ~CFIntRamMinorVersionTable();

		virtual cfint::CFIntMinorVersionBuff* createMinorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMinorVersionBuff* Buff );

		virtual cfint::CFIntMinorVersionBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionPKey* PKey );

		virtual cfint::CFIntMinorVersionBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readDerivedByMajorVerIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId );

		virtual cfint::CFIntMinorVersionBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name );

		virtual cfint::CFIntMinorVersionBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual cfint::CFIntMinorVersionBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionPKey* PKey );

		virtual cfint::CFIntMinorVersionBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntMinorVersionBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntMinorVersionBuff*> readBuffByMajorVerIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId );

		virtual cfint::CFIntMinorVersionBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name );

		virtual cfint::CFIntMinorVersionBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntMinorVersionBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t MajorVersionId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntMinorVersionBuff* updateMinorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMinorVersionBuff* Buff );

		virtual void deleteMinorVersion( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMinorVersionBuff* Buff );
		virtual void deleteMinorVersionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId );

		virtual void deleteMinorVersionByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionPKey* argKey );

		virtual void deleteMinorVersionByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId );

		virtual void deleteMinorVersionByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionByTenantIdxKey* argKey );

		virtual void deleteMinorVersionByMajorVerIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argMajorVersionId );

		virtual void deleteMinorVersionByMajorVerIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionByMajorVerIdxKey* argKey );

		virtual void deleteMinorVersionByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argMajorVersionId,
			const std::string& argName );

		virtual void deleteMinorVersionByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMinorVersionByNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
