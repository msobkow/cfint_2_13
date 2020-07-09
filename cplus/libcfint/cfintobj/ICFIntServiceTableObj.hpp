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

#include <cfintobj/ICFIntServiceObj.hpp>
#include <cfintobj/ICFIntServiceEditObj.hpp>
#include <cfsecobj/ICFSecServiceObj.hpp>
#include <cfsecobj/ICFSecServiceEditObj.hpp>
#include <cfsecobj/ICFSecServiceTableObj.hpp>

namespace cfint {

	class ICFIntServiceTableObj
	: public virtual cfsec::ICFSecServiceTableObj
	{
	public:
		ICFIntServiceTableObj();
		virtual ~ICFIntServiceTableObj();
		virtual cfsec::ICFSecServiceObj* newInstance() = 0;

		virtual cfsec::ICFSecServiceEditObj* newEditInstance( cfsec::ICFSecServiceObj* orig ) = 0;

		virtual cfsec::ICFSecServiceObj* realizeService( cfsec::ICFSecServiceObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;
		virtual void deepDisposeByTypeIdx( const int32_t ServiceTypeId ) = 0;
		virtual void deepDisposeByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId ) = 0;
		virtual void deepDisposeByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort ) = 0;
		virtual void reallyDeepDisposeService( cfsec::ICFSecServiceObj* Obj ) = 0;
		virtual cfsec::ICFSecServiceObj* createService( cfsec::ICFSecServiceEditObj* Obj ) = 0;

		virtual cfsec::ICFSecServiceObj* readService( cfsec::CFSecServicePKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceObj* lockService( cfsec::CFSecServicePKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readAllService( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> pageAllService(const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual cfsec::ICFSecServiceObj* readServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByTypeIdx( const int32_t ServiceTypeId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceObj* readServiceByUTypeIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceObj* readServiceByUHostPortIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceObj* readCachedService( cfsec::CFSecServicePKey* pkey ) = 0;

		virtual cfsec::ICFSecServiceObj* readCachedServiceByIdIdx(const int64_t ClusterId,
			const int64_t ServiceId ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByClusterIdx( const int64_t ClusterId ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByTypeIdx( const int32_t ServiceTypeId ) = 0;

		virtual cfsec::ICFSecServiceObj* readCachedServiceByUTypeIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId ) = 0;

		virtual cfsec::ICFSecServiceObj* readCachedServiceByUHostPortIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByTypeIdx( const int32_t ServiceTypeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId ) = 0;

		virtual cfsec::ICFSecServiceObj* updateService( cfsec::ICFSecServiceEditObj* Obj ) = 0;

		virtual void deleteService( cfsec::ICFSecServiceEditObj* Obj ) = 0;

		virtual void deleteServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId ) = 0;

		virtual void deleteServiceByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;

		virtual void deleteServiceByTypeIdx( const int32_t ServiceTypeId ) = 0;

		virtual void deleteServiceByUTypeIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId ) = 0;

		virtual void deleteServiceByUHostPortIdx(const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort ) = 0;

		virtual void reallyDetachFromIndexesService( cfsec::ICFSecServiceObj* Obj ) = 0;

	};
}
