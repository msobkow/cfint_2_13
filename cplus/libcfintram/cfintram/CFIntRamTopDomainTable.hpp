#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for TopDomain.

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

	class CFIntRamTopDomainTable
	: public virtual cfint::ICFIntTopDomainTable
	{
	protected:
		cfint::ICFIntSchema* schema;
		std::map<cfint::CFIntTopDomainPKey,
			cfint::CFIntTopDomainBuff*>* dictByPKey;
		std::map<cfint::CFIntTopDomainByTenantIdxKey,
			std::map<cfint::CFIntTopDomainPKey,
				cfint::CFIntTopDomainBuff*>*>* dictByTenantIdx;
		std::map<cfint::CFIntTopDomainByTldIdxKey,
			std::map<cfint::CFIntTopDomainPKey,
				cfint::CFIntTopDomainBuff*>*>* dictByTldIdx;
		std::map<cfint::CFIntTopDomainByNameIdxKey,
			cfint::CFIntTopDomainBuff*>* dictByNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFIntRamTopDomainTable( cfint::ICFIntSchema* argSchema );

		virtual ~CFIntRamTopDomainTable();

		virtual cfint::CFIntTopDomainBuff* createTopDomain( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopDomainBuff* Buff );

		virtual cfint::CFIntTopDomainBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainPKey* PKey );

		virtual cfint::CFIntTopDomainBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readDerivedByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readDerivedByTldIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId );

		virtual cfint::CFIntTopDomainBuff* readDerivedByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name );

		virtual cfint::CFIntTopDomainBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual cfint::CFIntTopDomainBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainPKey* PKey );

		virtual cfint::CFIntTopDomainBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntTopDomainBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readBuffByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntTopDomainBuff*> readBuffByTldIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId );

		virtual cfint::CFIntTopDomainBuff* readBuffByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name );

		virtual cfint::CFIntTopDomainBuff* readBuffByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntTopDomainBuff* readDerivedByLookupNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TldId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntTopDomainBuff* updateTopDomain( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopDomainBuff* Buff );

		virtual void deleteTopDomain( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntTopDomainBuff* Buff );
		virtual void deleteTopDomainByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId );

		virtual void deleteTopDomainByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainPKey* argKey );

		virtual void deleteTopDomainByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId );

		virtual void deleteTopDomainByTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainByTenantIdxKey* argKey );

		virtual void deleteTopDomainByTldIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTldId );

		virtual void deleteTopDomainByTldIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainByTldIdxKey* argKey );

		virtual void deleteTopDomainByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTldId,
			const std::string& argName );

		virtual void deleteTopDomainByNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntTopDomainByNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
