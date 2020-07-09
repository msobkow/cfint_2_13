#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for TopProject.

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

	class CFIntRamTopProjectTable
	: public virtual cfint::ICFIntTopProjectTable
	{
	protected:
		cfint::ICFIntSchema* schema;
		std::map<cfint::CFIntTopProjectPKey,
			cfint::CFIntTopProjectBuff*>* dictByPKey;
		std::map<cfint::CFIntTopProjectByTenantIdxKey,
			std::map<cfint::CFIntTopProjectPKey,
				cfint::CFIntTopProjectBuff*>*>* dictByTenantIdx;
		std::map<cfint::CFIntTopProjectByTopDomainIdxKey,
			std::map<cfint::CFIntTopProjectPKey,
				cfint::CFIntTopProjectBuff*>*>* dictByTopDomainIdx;
		std::map<cfint::CFIntTopProjectByNameIdxKey,
			cfint::CFIntTopProjectBuff*>* dictByNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFIntRamTopProjectTable( cfint::ICFIntSchema* argSchema );

		virtual ~CFIntRamTopProjectTable();

		virtual cfint::CFIntTopProjectBuff* createTopProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopProjectBuff* Buff );

		virtual cfint::CFIntTopProjectBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectPKey* PKey );

		virtual cfint::CFIntTopProjectBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readDerivedByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId );

		virtual cfint::CFIntTopProjectBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name );

		virtual cfint::CFIntTopProjectBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual cfint::CFIntTopProjectBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectPKey* PKey );

		virtual cfint::CFIntTopProjectBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntTopProjectBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntTopProjectBuff*> readBuffByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId );

		virtual cfint::CFIntTopProjectBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name );

		virtual cfint::CFIntTopProjectBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntTopProjectBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntTopProjectBuff* updateTopProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopProjectBuff* Buff );

		virtual void deleteTopProject( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopProjectBuff* Buff );
		virtual void deleteTopProjectByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId );

		virtual void deleteTopProjectByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectPKey* argKey );

		virtual void deleteTopProjectByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId );

		virtual void deleteTopProjectByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectByTenantIdxKey* argKey );

		virtual void deleteTopProjectByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId );

		virtual void deleteTopProjectByTopDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectByTopDomainIdxKey* argKey );

		virtual void deleteTopProjectByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId,
			const std::string& argName );

		virtual void deleteTopProjectByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopProjectByNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
