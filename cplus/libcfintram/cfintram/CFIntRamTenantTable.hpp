#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for Tenant.

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
#include <cfintram/CFIntRamTenantId32Gen.hpp>
#include <cfintram/CFIntRamTenantId64Gen.hpp>

namespace cfint {

	class CFIntRamTenantTable
	: public virtual cfsec::ICFSecTenantTable
	{
	protected:
		cfint::ICFIntSchema* schema;
		std::map<cfsec::CFSecTenantPKey,
			cfsec::CFSecTenantBuff*>* dictByPKey;
		std::map<cfsec::CFSecTenantByClusterIdxKey,
			std::map<cfsec::CFSecTenantPKey,
				cfsec::CFSecTenantBuff*>*>* dictByClusterIdx;
		std::map<cfsec::CFSecTenantByUNameIdxKey,
			cfsec::CFSecTenantBuff*>* dictByUNameIdx;
		std::map<cfint::CFIntRamTenantId32Gen, cfint::CFIntRamTenantId32Gen*>* id32Generator;
		std::map<cfint::CFIntRamTenantId64Gen, cfint::CFIntRamTenantId64Gen*>* id64Generator;
		virtual int32_t generateNextId32( int64_t argId,
			int16_t argSliceId );

		virtual int64_t generateNextId64( int64_t argId,
			int16_t argSliceId );

	public:
		static const std::string CLASS_NAME;
		CFIntRamTenantTable( cfint::ICFIntSchema* argSchema );

		virtual ~CFIntRamTenantTable();

		virtual int32_t nextTSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int32_t nextTSecGroupIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextTSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int64_t nextTSecGrpIncIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextTSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int64_t nextTSecGrpMembIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextLicenseIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int64_t nextLicenseIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextMajorVersionIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int64_t nextMajorVersionIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextMinorVersionIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int64_t nextMinorVersionIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextSubProjectIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int64_t nextSubProjectIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextTldIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int64_t nextTldIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextTopDomainIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int64_t nextTopDomainIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual int64_t nextTopProjectIdGen( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* pkey );

		virtual int64_t nextTopProjectIdGen( const cfsec::CFSecAuthorization* Authorization,
			int64_t argId );

		virtual cfsec::CFSecTenantBuff* createTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff );

		virtual cfsec::CFSecTenantBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey );

		virtual cfsec::CFSecTenantBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readDerivedByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual cfsec::CFSecTenantBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& TenantName );

		virtual cfsec::CFSecTenantBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id );

		virtual cfsec::CFSecTenantBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey );

		virtual cfsec::CFSecTenantBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* PKey );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> pageAllBuff( const cfsec::CFSecAuthorization* Authorization,
			const int64_t* priorId );

		virtual cfsec::CFSecTenantBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t Id );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> readBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId );

		virtual cfsec::CFSecTenantBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const std::string& TenantName );

		virtual cfsec::CFSecTenantBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& TenantName,
			bool forceRead = false );

		virtual cfsec::CFSecTenantBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId, const std::string& TenantName,
			bool forceRead = false );

		virtual std::TCFLibOwningVector<cfsec::CFSecTenantBuff*> pageBuffByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t ClusterId,
			const int64_t* priorId );

		virtual cfsec::CFSecTenantBuff* updateTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff );

		virtual void deleteTenant( const cfsec::CFSecAuthorization* Authorization,
			cfsec::CFSecTenantBuff* Buff );
		virtual void deleteTenantByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argId );

		virtual void deleteTenantByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantPKey* argKey );

		virtual void deleteTenantByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId );

		virtual void deleteTenantByClusterIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantByClusterIdxKey* argKey );

		virtual void deleteTenantByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argClusterId,
			const std::string& argTenantName );

		virtual void deleteTenantByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfsec::CFSecTenantByUNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
