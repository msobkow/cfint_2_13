#pragma once

// Description: C++18 Table Object interface for CFInt.

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

namespace cfint {
	class ICFIntSchemaObj;
	class ICFIntClusterObj;
	class ICFIntClusterEditObj;
	class ICFIntClusterTableObj;
	class ICFIntHostNodeObj;
	class ICFIntHostNodeEditObj;
	class ICFIntHostNodeTableObj;
	class ICFIntISOCcyObj;
	class ICFIntISOCcyEditObj;
	class ICFIntISOCcyTableObj;
	class ICFIntISOCtryObj;
	class ICFIntISOCtryEditObj;
	class ICFIntISOCtryTableObj;
	class ICFIntISOCtryCcyObj;
	class ICFIntISOCtryCcyEditObj;
	class ICFIntISOCtryCcyTableObj;
	class ICFIntISOCtryLangObj;
	class ICFIntISOCtryLangEditObj;
	class ICFIntISOCtryLangTableObj;
	class ICFIntISOLangObj;
	class ICFIntISOLangEditObj;
	class ICFIntISOLangTableObj;
	class ICFIntISOTZoneObj;
	class ICFIntISOTZoneEditObj;
	class ICFIntISOTZoneTableObj;
	class ICFIntLicenseObj;
	class ICFIntLicenseEditObj;
	class ICFIntLicenseTableObj;
	class ICFIntMajorVersionObj;
	class ICFIntMajorVersionEditObj;
	class ICFIntMajorVersionTableObj;
	class ICFIntMimeTypeObj;
	class ICFIntMimeTypeEditObj;
	class ICFIntMimeTypeTableObj;
	class ICFIntMinorVersionObj;
	class ICFIntMinorVersionEditObj;
	class ICFIntMinorVersionTableObj;
	class ICFIntSecAppObj;
	class ICFIntSecAppEditObj;
	class ICFIntSecAppTableObj;
	class ICFIntSecDeviceObj;
	class ICFIntSecDeviceEditObj;
	class ICFIntSecDeviceTableObj;
	class ICFIntSecFormObj;
	class ICFIntSecFormEditObj;
	class ICFIntSecFormTableObj;
	class ICFIntSecGroupObj;
	class ICFIntSecGroupEditObj;
	class ICFIntSecGroupTableObj;
	class ICFIntSecGroupFormObj;
	class ICFIntSecGroupFormEditObj;
	class ICFIntSecGroupFormTableObj;
	class ICFIntSecGrpIncObj;
	class ICFIntSecGrpIncEditObj;
	class ICFIntSecGrpIncTableObj;
	class ICFIntSecGrpMembObj;
	class ICFIntSecGrpMembEditObj;
	class ICFIntSecGrpMembTableObj;
	class ICFIntSecSessionObj;
	class ICFIntSecSessionEditObj;
	class ICFIntSecSessionTableObj;
	class ICFIntSecUserObj;
	class ICFIntSecUserEditObj;
	class ICFIntSecUserTableObj;
	class ICFIntServiceObj;
	class ICFIntServiceEditObj;
	class ICFIntServiceTableObj;
	class ICFIntServiceTypeObj;
	class ICFIntServiceTypeEditObj;
	class ICFIntServiceTypeTableObj;
	class ICFIntSubProjectObj;
	class ICFIntSubProjectEditObj;
	class ICFIntSubProjectTableObj;
	class ICFIntSysClusterObj;
	class ICFIntSysClusterEditObj;
	class ICFIntSysClusterTableObj;
	class ICFIntTSecGroupObj;
	class ICFIntTSecGroupEditObj;
	class ICFIntTSecGroupTableObj;
	class ICFIntTSecGrpIncObj;
	class ICFIntTSecGrpIncEditObj;
	class ICFIntTSecGrpIncTableObj;
	class ICFIntTSecGrpMembObj;
	class ICFIntTSecGrpMembEditObj;
	class ICFIntTSecGrpMembTableObj;
	class ICFIntTenantObj;
	class ICFIntTenantEditObj;
	class ICFIntTenantTableObj;
	class ICFIntTldObj;
	class ICFIntTldEditObj;
	class ICFIntTldTableObj;
	class ICFIntTopDomainObj;
	class ICFIntTopDomainEditObj;
	class ICFIntTopDomainTableObj;
	class ICFIntTopProjectObj;
	class ICFIntTopProjectEditObj;
	class ICFIntTopProjectTableObj;
	class ICFIntURLProtocolObj;
	class ICFIntURLProtocolEditObj;
	class ICFIntURLProtocolTableObj;
}

#include <cfintobj/ICFIntTSecGrpMembObj.hpp>
#include <cfintobj/ICFIntTSecGrpMembEditObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembEditObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembTableObj.hpp>

namespace cfint {

	class ICFIntTSecGrpMembTableObj
	: public virtual cfsec::ICFSecTSecGrpMembTableObj
	{
	public:
		ICFIntTSecGrpMembTableObj();
		virtual ~ICFIntTSecGrpMembTableObj();
		virtual cfsec::ICFSecTSecGrpMembObj* newInstance() = 0;

		virtual cfsec::ICFSecTSecGrpMembEditObj* newEditInstance( cfsec::ICFSecTSecGrpMembObj* orig ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* realizeTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId ) = 0;
		virtual void deepDisposeByTenantIdx( const int64_t TenantId ) = 0;
		virtual void deepDisposeByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;
		virtual void deepDisposeByUserIdx( const uuid_ptr_t SecUserId ) = 0;
		virtual void deepDisposeByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId ) = 0;
		virtual void reallyDeepDisposeTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj ) = 0;
		virtual cfsec::ICFSecTSecGrpMembObj* createTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* lockTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readAllTSecGrpMemb( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageAllTSecGrpMemb(const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByTenantIdx( const int64_t TenantId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMembByUUserIdx(const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMembByIdIdx(const int64_t TenantId,
			const int64_t TSecGrpMembId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByTenantIdx( const int64_t TenantId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMembByUUserIdx(const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByTenantIdx( const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId ) = 0;

		virtual cfsec::ICFSecTSecGrpMembObj* updateTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj ) = 0;

		virtual void deleteTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj ) = 0;

		virtual void deleteTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId ) = 0;

		virtual void deleteTSecGrpMembByTenantIdx( const int64_t TenantId ) = 0;

		virtual void deleteTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual void deleteTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual void deleteTSecGrpMembByUUserIdx(const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId ) = 0;

		virtual void reallyDetachFromIndexesTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj ) = 0;

	};
}
