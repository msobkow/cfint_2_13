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

#include <cfintobj/ICFIntHostNodeObj.hpp>
#include <cfintobj/ICFIntHostNodeEditObj.hpp>
#include <cfsecobj/ICFSecHostNodeObj.hpp>
#include <cfsecobj/ICFSecHostNodeEditObj.hpp>
#include <cfsecobj/ICFSecHostNodeTableObj.hpp>

namespace cfint {

	class ICFIntHostNodeTableObj
	: public virtual cfsec::ICFSecHostNodeTableObj
	{
	public:
		ICFIntHostNodeTableObj();
		virtual ~ICFIntHostNodeTableObj();
		virtual cfsec::ICFSecHostNodeObj* newInstance() = 0;

		virtual cfsec::ICFSecHostNodeEditObj* newEditInstance( cfsec::ICFSecHostNodeObj* orig ) = 0;

		virtual cfsec::ICFSecHostNodeObj* realizeHostNode( cfsec::ICFSecHostNodeObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByUDescrIdx( const int64_t ClusterId,
			const std::string& Description ) = 0;
		virtual void deepDisposeByHostNameIdx( const int64_t ClusterId,
			const std::string& HostName ) = 0;
		virtual void reallyDeepDisposeHostNode( cfsec::ICFSecHostNodeObj* Obj ) = 0;
		virtual cfsec::ICFSecHostNodeObj* createHostNode( cfsec::ICFSecHostNodeEditObj* Obj ) = 0;

		virtual cfsec::ICFSecHostNodeObj* readHostNode( cfsec::CFSecHostNodePKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecHostNodeObj* lockHostNode( cfsec::CFSecHostNodePKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecHostNodeObj*> readAllHostNode( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecHostNodeObj*> pageAllHostNode(const int64_t* priorClusterId,
			const int64_t* priorHostNodeId ) = 0;

		virtual cfsec::ICFSecHostNodeObj* readHostNodeByIdIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecHostNodeObj*> readHostNodeByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecHostNodeObj* readHostNodeByUDescrIdx(const int64_t ClusterId,
			const std::string& Description,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecHostNodeObj* readHostNodeByHostNameIdx(const int64_t ClusterId,
			const std::string& HostName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecHostNodeObj* readCachedHostNode( cfsec::CFSecHostNodePKey* pkey ) = 0;

		virtual cfsec::ICFSecHostNodeObj* readCachedHostNodeByIdIdx(const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;

		virtual std::vector<cfsec::ICFSecHostNodeObj*> readCachedHostNodeByClusterIdx( const int64_t ClusterId ) = 0;

		virtual cfsec::ICFSecHostNodeObj* readCachedHostNodeByUDescrIdx(const int64_t ClusterId,
			const std::string& Description ) = 0;

		virtual cfsec::ICFSecHostNodeObj* readCachedHostNodeByHostNameIdx(const int64_t ClusterId,
			const std::string& HostName ) = 0;

		virtual cfsec::ICFSecHostNodeObj* readHostNodeByLookupHostNameIdx(const int64_t ClusterId,
			const std::string& HostName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecHostNodeObj* readCachedHostNodeByLookupHostNameIdx(const int64_t ClusterId,
			const std::string& HostName ) = 0;

		virtual std::vector<cfsec::ICFSecHostNodeObj*> pageHostNodeByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorHostNodeId ) = 0;

		virtual cfsec::ICFSecHostNodeObj* updateHostNode( cfsec::ICFSecHostNodeEditObj* Obj ) = 0;

		virtual void deleteHostNode( cfsec::ICFSecHostNodeEditObj* Obj ) = 0;

		virtual void deleteHostNodeByIdIdx( const int64_t ClusterId,
			const int64_t HostNodeId ) = 0;

		virtual void deleteHostNodeByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteHostNodeByUDescrIdx(const int64_t ClusterId,
			const std::string& Description ) = 0;

		virtual void deleteHostNodeByHostNameIdx(const int64_t ClusterId,
			const std::string& HostName ) = 0;

		virtual void reallyDetachFromIndexesHostNode( cfsec::ICFSecHostNodeObj* Obj ) = 0;

	};
}
