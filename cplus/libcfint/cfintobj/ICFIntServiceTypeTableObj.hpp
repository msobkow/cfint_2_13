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

#include <cfintobj/ICFIntServiceTypeObj.hpp>
#include <cfintobj/ICFIntServiceTypeEditObj.hpp>
#include <cfsecobj/ICFSecServiceTypeObj.hpp>
#include <cfsecobj/ICFSecServiceTypeEditObj.hpp>
#include <cfsecobj/ICFSecServiceTypeTableObj.hpp>

namespace cfint {

	class ICFIntServiceTypeTableObj
	: public virtual cfsec::ICFSecServiceTypeTableObj
	{
	public:
		ICFIntServiceTypeTableObj();
		virtual ~ICFIntServiceTypeTableObj();
		virtual cfsec::ICFSecServiceTypeObj* newInstance() = 0;

		virtual cfsec::ICFSecServiceTypeEditObj* newEditInstance( cfsec::ICFSecServiceTypeObj* orig ) = 0;

		virtual cfsec::ICFSecServiceTypeObj* realizeServiceType( cfsec::ICFSecServiceTypeObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int32_t ServiceTypeId ) = 0;
		virtual void deepDisposeByUDescrIdx( const std::string& Description ) = 0;
		virtual void reallyDeepDisposeServiceType( cfsec::ICFSecServiceTypeObj* Obj ) = 0;
		virtual cfsec::ICFSecServiceTypeObj* createServiceType( cfsec::ICFSecServiceTypeEditObj* Obj ) = 0;

		virtual cfsec::ICFSecServiceTypeObj* readServiceType( cfsec::CFSecServiceTypePKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceTypeObj* lockServiceType( cfsec::CFSecServiceTypePKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecServiceTypeObj*> readAllServiceType( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceTypeObj* readServiceTypeByIdIdx( const int32_t ServiceTypeId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceTypeObj* readServiceTypeByUDescrIdx(const std::string& Description,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceTypeObj* readCachedServiceType( cfsec::CFSecServiceTypePKey* pkey ) = 0;

		virtual cfsec::ICFSecServiceTypeObj* readCachedServiceTypeByIdIdx(const int32_t ServiceTypeId ) = 0;

		virtual cfsec::ICFSecServiceTypeObj* readCachedServiceTypeByUDescrIdx(const std::string& Description ) = 0;

		virtual cfsec::ICFSecServiceTypeObj* readServiceTypeByLookupUDescrIdx(const std::string& Description,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecServiceTypeObj* readCachedServiceTypeByLookupUDescrIdx(const std::string& Description ) = 0;

		virtual cfsec::ICFSecServiceTypeObj* updateServiceType( cfsec::ICFSecServiceTypeEditObj* Obj ) = 0;

		virtual void deleteServiceType( cfsec::ICFSecServiceTypeEditObj* Obj ) = 0;

		virtual void deleteServiceTypeByIdIdx( const int32_t ServiceTypeId ) = 0;

		virtual void deleteServiceTypeByUDescrIdx(const std::string& Description ) = 0;

		virtual void reallyDetachFromIndexesServiceType( cfsec::ICFSecServiceTypeObj* Obj ) = 0;

	};
}
