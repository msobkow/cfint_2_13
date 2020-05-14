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

#include <cfintobj/ICFIntTenantObj.hpp>
#include <cfintobj/ICFIntTenantEditObj.hpp>
#include <cfsecobj/ICFSecTenantObj.hpp>
#include <cfsecobj/ICFSecTenantEditObj.hpp>
#include <cfsecobj/ICFSecTenantTableObj.hpp>

namespace cfint {

	class ICFIntTenantTableObj
	: public virtual cfsec::ICFSecTenantTableObj
	{
	public:
		ICFIntTenantTableObj();
		virtual ~ICFIntTenantTableObj();
		virtual cfsec::ICFSecTenantObj* newInstance() = 0;

		virtual cfsec::ICFSecTenantEditObj* newEditInstance( cfsec::ICFSecTenantObj* orig ) = 0;

		virtual cfsec::ICFSecTenantObj* realizeTenant( cfsec::ICFSecTenantObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t Id ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByUNameIdx( const int64_t ClusterId,
			const std::string& TenantName ) = 0;
		virtual void reallyDeepDisposeTenant( cfsec::ICFSecTenantObj* Obj ) = 0;
		virtual cfsec::ICFSecTenantObj* createTenant( cfsec::ICFSecTenantEditObj* Obj ) = 0;

		virtual cfsec::ICFSecTenantObj* readTenant( cfsec::CFSecTenantPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTenantObj* lockTenant( cfsec::CFSecTenantPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecTenantObj*> readAllTenant( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTenantObj*> pageAllTenant(const int64_t* priorId ) = 0;

		virtual cfsec::ICFSecTenantObj* readTenantByIdIdx( const int64_t Id,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecTenantObj*> readTenantByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTenantObj* readTenantByUNameIdx(const int64_t ClusterId,
			const std::string& TenantName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTenantObj* readCachedTenant( cfsec::CFSecTenantPKey* pkey ) = 0;

		virtual cfsec::ICFSecTenantObj* readCachedTenantByIdIdx(const int64_t Id ) = 0;

		virtual std::vector<cfsec::ICFSecTenantObj*> readCachedTenantByClusterIdx( const int64_t ClusterId ) = 0;

		virtual cfsec::ICFSecTenantObj* readCachedTenantByUNameIdx(const int64_t ClusterId,
			const std::string& TenantName ) = 0;

		virtual cfsec::ICFSecTenantObj* readTenantByLookupUNameIdx(const int64_t ClusterId,
			const std::string& TenantName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecTenantObj* readCachedTenantByLookupUNameIdx(const int64_t ClusterId,
			const std::string& TenantName ) = 0;

		virtual std::vector<cfsec::ICFSecTenantObj*> pageTenantByClusterIdx( const int64_t ClusterId,
			const int64_t* priorId ) = 0;

		virtual cfsec::ICFSecTenantObj* updateTenant( cfsec::ICFSecTenantEditObj* Obj ) = 0;

		virtual void deleteTenant( cfsec::ICFSecTenantEditObj* Obj ) = 0;

		virtual void deleteTenantByIdIdx( const int64_t Id ) = 0;

		virtual void deleteTenantByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteTenantByUNameIdx(const int64_t ClusterId,
			const std::string& TenantName ) = 0;

		virtual void reallyDetachFromIndexesTenant( cfsec::ICFSecTenantObj* Obj ) = 0;

	virtual cfsec::ICFSecTenantObj* getSystemTenant() = 0;

	};
}
