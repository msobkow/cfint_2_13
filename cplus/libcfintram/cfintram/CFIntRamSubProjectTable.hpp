#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for SubProject.

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

	class CFIntRamSubProjectTable
	: public virtual cfint::ICFIntSubProjectTable
	{
	protected:
		cfint::ICFIntSchema* schema;
		std::map<cfint::CFIntSubProjectPKey,
			cfint::CFIntSubProjectBuff*>* dictByPKey;
		std::map<cfint::CFIntSubProjectByTenantIdxKey,
			std::map<cfint::CFIntSubProjectPKey,
				cfint::CFIntSubProjectBuff*>*>* dictByTenantIdx;
		std::map<cfint::CFIntSubProjectByTopProjectIdxKey,
			std::map<cfint::CFIntSubProjectPKey,
				cfint::CFIntSubProjectBuff*>*>* dictByTopProjectIdx;
		std::map<cfint::CFIntSubProjectByNameIdxKey,
			cfint::CFIntSubProjectBuff*>* dictByNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFIntRamSubProjectTable( cfint::ICFIntSchema* argSchema );

		virtual ~CFIntRamSubProjectTable();

		virtual cfint::CFIntSubProjectBuff* createSubProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntSubProjectBuff* Buff );

		virtual cfint::CFIntSubProjectBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectPKey* PKey );

		virtual cfint::CFIntSubProjectBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readDerivedByTopProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId );

		virtual cfint::CFIntSubProjectBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name );

		virtual cfint::CFIntSubProjectBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual cfint::CFIntSubProjectBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectPKey* PKey );

		virtual cfint::CFIntSubProjectBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntSubProjectBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntSubProjectBuff*> readBuffByTopProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId );

		virtual cfint::CFIntSubProjectBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name );

		virtual cfint::CFIntSubProjectBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntSubProjectBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopProjectId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntSubProjectBuff* updateSubProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntSubProjectBuff* Buff );

		virtual void deleteSubProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntSubProjectBuff* Buff );
		virtual void deleteSubProjectByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId );

		virtual void deleteSubProjectByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectPKey* argKey );

		virtual void deleteSubProjectByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId );

		virtual void deleteSubProjectByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectByTenantIdxKey* argKey );

		virtual void deleteSubProjectByTopProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopProjectId );

		virtual void deleteSubProjectByTopProjectIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectByTopProjectIdxKey* argKey );

		virtual void deleteSubProjectByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopProjectId,
			const std::string& argName );

		virtual void deleteSubProjectByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntSubProjectByNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
