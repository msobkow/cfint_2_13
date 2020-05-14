#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for MajorVersion.

/*
 *	com.github.msobkow.CFInt
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
