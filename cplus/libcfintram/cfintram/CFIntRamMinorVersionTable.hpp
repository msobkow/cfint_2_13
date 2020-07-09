#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for MinorVersion.

/*
 *	org.msscf.msscf.CFInt
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
