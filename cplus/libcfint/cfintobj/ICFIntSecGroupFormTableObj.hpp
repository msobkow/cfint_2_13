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

#include <cfintobj/ICFIntSecGroupFormObj.hpp>
#include <cfintobj/ICFIntSecGroupFormEditObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormEditObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormTableObj.hpp>

namespace cfint {

	class ICFIntSecGroupFormTableObj
	: public virtual cfsec::ICFSecSecGroupFormTableObj
	{
	public:
		ICFIntSecGroupFormTableObj();
		virtual ~ICFIntSecGroupFormTableObj();
		virtual cfsec::ICFSecSecGroupFormObj* newInstance() = 0;

		virtual cfsec::ICFSecSecGroupFormEditObj* newEditInstance( cfsec::ICFSecSecGroupFormObj* orig ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* realizeSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;
		virtual void deepDisposeByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId ) = 0;
		virtual void deepDisposeByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId ) = 0;
		virtual void deepDisposeByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId ) = 0;
		virtual void reallyDeepDisposeSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj ) = 0;
		virtual cfsec::ICFSecSecGroupFormObj* createSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* lockSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readAllSecGroupForm( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageAllSecGroupForm(const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupFormByUFormIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupFormByIdIdx(const int64_t ClusterId,
			const int64_t SecGroupFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByClusterIdx( const int64_t ClusterId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupFormByUFormIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId ) = 0;

		virtual cfsec::ICFSecSecGroupFormObj* updateSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj ) = 0;

		virtual void deleteSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj ) = 0;

		virtual void deleteSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId ) = 0;

		virtual void deleteSecGroupFormByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual void deleteSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual void deleteSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId ) = 0;

		virtual void deleteSecGroupFormByUFormIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId ) = 0;

		virtual void reallyDetachFromIndexesSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj ) = 0;

	};
}
