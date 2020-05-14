#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for License.

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

	class CFIntRamLicenseTable
	: public virtual cfint::ICFIntLicenseTable
	{
	protected:
		cfint::ICFIntSchema* schema;
		std::map<cfint::CFIntLicensePKey,
			cfint::CFIntLicenseBuff*>* dictByPKey;
		std::map<cfint::CFIntLicenseByLicnTenantIdxKey,
			std::map<cfint::CFIntLicensePKey,
				cfint::CFIntLicenseBuff*>*>* dictByLicnTenantIdx;
		std::map<cfint::CFIntLicenseByDomainIdxKey,
			std::map<cfint::CFIntLicensePKey,
				cfint::CFIntLicenseBuff*>*>* dictByDomainIdx;
		std::map<cfint::CFIntLicenseByUNameIdxKey,
			cfint::CFIntLicenseBuff*>* dictByUNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFIntRamLicenseTable( cfint::ICFIntSchema* argSchema );

		virtual ~CFIntRamLicenseTable();

		virtual cfint::CFIntLicenseBuff* createLicense( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntLicenseBuff* Buff );

		virtual cfint::CFIntLicenseBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicensePKey* PKey );

		virtual cfint::CFIntLicenseBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicensePKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readDerivedByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readDerivedByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId );

		virtual cfint::CFIntLicenseBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name );

		virtual cfint::CFIntLicenseBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual cfint::CFIntLicenseBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicensePKey* PKey );

		virtual cfint::CFIntLicenseBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicensePKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntLicenseBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t Id );

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readBuffByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId );

		virtual std::TCFLibOwningVector<cfint::CFIntLicenseBuff*> readBuffByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId );

		virtual cfint::CFIntLicenseBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name );

		virtual cfint::CFIntLicenseBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntLicenseBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t TenantId,
			const int64_t TopDomainId, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntLicenseBuff* updateLicense( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntLicenseBuff* Buff );

		virtual void deleteLicense( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntLicenseBuff* Buff );
		virtual void deleteLicenseByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argId );

		virtual void deleteLicenseByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicensePKey* argKey );

		virtual void deleteLicenseByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId );

		virtual void deleteLicenseByLicnTenantIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicenseByLicnTenantIdxKey* argKey );

		virtual void deleteLicenseByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId );

		virtual void deleteLicenseByDomainIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicenseByDomainIdxKey* argKey );

		virtual void deleteLicenseByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const int64_t argTenantId,
			const int64_t argTopDomainId,
			const std::string& argName );

		virtual void deleteLicenseByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntLicenseByUNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
