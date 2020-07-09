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

#include <cfintobj/ICFIntSecGrpIncObj.hpp>
#include <cfintobj/ICFIntSecGrpIncEditObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncEditObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncTableObj.hpp>

namespace cfint {

	class ICFIntSecGrpIncTableObj
	: public virtual cfsec::ICFSecSecGrpIncTableObj
	{
	public:
		ICFIntSecGrpIncTableObj();
		virtual ~ICFIntSecGrpIncTableObj();
		virtual cfsec::ICFSecSecGrpIncObj* newInstance() = 0;

		virtual cfsec::ICFSecSecGrpIncEditObj* newEditInstance( cfsec::ICFSecSecGrpIncObj* orig ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* realizeSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;
		virtual void deepDisposeByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId ) = 0;
		virtual void deepDisposeByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId ) = 0;
		virtual void reallyDeepDisposeSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) = 0;
		virtual cfsec::ICFSecSecGrpIncObj* createSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* lockSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readAllSecGrpInc( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageAllSecGrpInc(const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readSecGrpIncByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readSecGrpIncByUIncludeIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readCachedSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readCachedSecGrpIncByIdIdx(const int64_t ClusterId,
			const int64_t SecGrpIncId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readCachedSecGrpIncByClusterIdx( const int64_t ClusterId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readCachedSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readCachedSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* readCachedSecGrpIncByUIncludeIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageSecGrpIncByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId ) = 0;

		virtual cfsec::ICFSecSecGrpIncObj* updateSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) = 0;

		virtual void deleteSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj ) = 0;

		virtual void deleteSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId ) = 0;

		virtual void deleteSecGrpIncByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual void deleteSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId ) = 0;

		virtual void deleteSecGrpIncByUIncludeIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId ) = 0;

		virtual void reallyDetachFromIndexesSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj ) = 0;

	};
}
