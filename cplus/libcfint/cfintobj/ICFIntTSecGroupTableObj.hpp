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

#include <cfintobj/ICFIntTSecGroupObj.hpp>
#include <cfintobj/ICFIntTSecGroupEditObj.hpp>
#include <cfsecobj/ICFSecTSecGroupObj.hpp>
#include <cfsecobj/ICFSecTSecGroupEditObj.hpp>
#include <cfsecobj/ICFSecTSecGroupTableObj.hpp>

namespace cfint {

	class ICFIntTSecGroupTableObj
	: public virtual cfsec::ICFSecTSecGroupTableObj
	{
	public:
		ICFIntTSecGroupTableObj();
		virtual ~ICFIntTSecGroupTableObj();
		virtual cfsec::ICFSecTSecGroupObj* newInstance() = 0;

		virtual cfsec::ICFSecTSecGroupEditObj* newEditInstance( cfsec::ICFSecTSecGroupObj* orig ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* realizeTSecGroup( cfsec::ICFSecTSecGroupObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;
		virtual void deepDisposeByTenantIdx( const int64_t TenantId ) = 0;
		virtual void deepDisposeByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible ) = 0;
		virtual void deepDisposeByUNameIdx( const int64_t TenantId,
			const std::string& Name ) = 0;
		virtual void reallyDeepDisposeTSecGroup( cfsec::ICFSecTSecGroupObj* Obj ) = 0;
		virtual cfsec::ICFSecTSecGroupObj* createTSecGroup( cfsec::ICFSecTSecGroupEditObj* Obj ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* readTSecGroup( cfsec::CFSecTSecGroupPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* lockTSecGroup( cfsec::CFSecTSecGroupPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGroupObj*> readAllTSecGroup( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* readTSecGroupByIdIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGroupObj*> readTSecGroupByTenantIdx( const int64_t TenantId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGroupObj*> readTSecGroupByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* readTSecGroupByUNameIdx(const int64_t TenantId,
			const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* readCachedTSecGroup( cfsec::CFSecTSecGroupPKey* pkey ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* readCachedTSecGroupByIdIdx(const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGroupObj*> readCachedTSecGroupByTenantIdx( const int64_t TenantId ) = 0;

		virtual std::vector<cfsec::ICFSecTSecGroupObj*> readCachedTSecGroupByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* readCachedTSecGroupByUNameIdx(const int64_t TenantId,
			const std::string& Name ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* readTSecGroupByLookupUNameIdx(const int64_t TenantId,
			const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* readCachedTSecGroupByLookupUNameIdx(const int64_t TenantId,
			const std::string& Name ) = 0;

		virtual cfsec::ICFSecTSecGroupObj* updateTSecGroup( cfsec::ICFSecTSecGroupEditObj* Obj ) = 0;

		virtual void deleteTSecGroup( cfsec::ICFSecTSecGroupEditObj* Obj ) = 0;

		virtual void deleteTSecGroupByIdIdx( const int64_t TenantId,
			const int32_t TSecGroupId ) = 0;

		virtual void deleteTSecGroupByTenantIdx( const int64_t TenantId ) = 0;

		virtual void deleteTSecGroupByTenantVisIdx( const int64_t TenantId,
			const bool IsVisible ) = 0;

		virtual void deleteTSecGroupByUNameIdx(const int64_t TenantId,
			const std::string& Name ) = 0;

		virtual void reallyDetachFromIndexesTSecGroup( cfsec::ICFSecTSecGroupObj* Obj ) = 0;

	};
}
