#pragma once

// Description: C++18 Table Object interface for CFInt.

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

#include <cfintobj/ICFIntTSecGrpIncObj.hpp>
#include <cfintobj/ICFIntTSecGrpIncEditObj.hpp>
#include <cfsecobj/ICFSecTSecGrpIncObj.hpp>
#include <cfsecobj/ICFSecTSecGrpIncEditObj.hpp>
#include <cfsecobj/ICFSecTSecGrpIncTableObj.hpp>

namespace cfint {

	class ICFIntTSecGrpIncTableObj
	: public virtual cfsec::ICFSecTSecGrpIncTableObj
	{
	public:
		ICFIntTSecGrpIncTableObj();
		virtual ~ICFIntTSecGrpIncTableObj();
		virtual cfsec::ICFSecTSecGrpIncObj* newInstance() = 0;

		virtual cfsec::ICFSecTSecGrpIncEditObj* newEditInstance( cfsec::ICFSecTSecGrpIncObj* orig ) = 0;

		virtual cfsec::ICFSecTSecGrpIncObj* realizeTSecGrpInc( cfsec::ICFSecTSecGrpIncObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpIncId ) = 0;
		virtual void deepDisposeByTenantIdx( const int64_t TenantId ) = 0;
		virtual void deepDisposeByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;
		virtual void deepDisposeByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId ) = 0;
		virtual void deepDisposeByUIncludeIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId ) = 0;
		virtual void reallyDeepDisposeTSecGrpInc( cfsec::ICFSecTSecGrpIncObj* Obj ) = 0;
		virtual cfsec::ICFSecTSecGrpIncObj* createTSecGrpInc( cfsec::ICFSecTSecGrpIncEditObj* Obj ) = 0;

		virtual cfsec::ICFSecTSecGrpIncObj* readTSecGrpInc( cfsec::CFSecTSecGrpIncPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGrpIncObj* lockTSecGrpInc( cfsec::CFSecTSecGrpIncPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readAllTSecGrpInc( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> pageAllTSecGrpInc(const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual cfsec::ICFSecTSecGrpIncObj* readTSecGrpIncByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpIncId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readTSecGrpIncByTenantIdx( const int64_t TenantId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGrpIncObj* readTSecGrpIncByUIncludeIdx(const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGrpIncObj* readCachedTSecGrpInc( cfsec::CFSecTSecGrpIncPKey* pkey ) = 0;

		virtual cfsec::ICFSecTSecGrpIncObj* readCachedTSecGrpIncByIdIdx(const int64_t TenantId,
			const int64_t TSecGrpIncId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readCachedTSecGrpIncByTenantIdx( const int64_t TenantId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readCachedTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> readCachedTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::ICFSecTSecGrpIncObj* readCachedTSecGrpIncByUIncludeIdx(const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> pageTSecGrpIncByTenantIdx( const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> pageTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGrpIncObj*> pageTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpIncId ) = 0;

		virtual cfsec::ICFSecTSecGrpIncObj* updateTSecGrpInc( cfsec::ICFSecTSecGrpIncEditObj* Obj ) = 0;

		virtual void deleteTSecGrpInc( cfsec::ICFSecTSecGrpIncEditObj* Obj ) = 0;

		virtual void deleteTSecGrpIncByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpIncId ) = 0;

		virtual void deleteTSecGrpIncByTenantIdx( const int64_t TenantId ) = 0;

		virtual void deleteTSecGrpIncByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual void deleteTSecGrpIncByIncludeIdx( const int64_t TenantId,
			const int32_t IncludeGroupId ) = 0;

		virtual void deleteTSecGrpIncByUIncludeIdx(const int64_t TenantId,
			const int32_t TSecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual void reallyDetachFromIndexesTSecGrpInc( cfsec::ICFSecTSecGrpIncObj* Obj ) = 0;

	};
}
