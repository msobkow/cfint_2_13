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

#include <cfintobj/ICFIntSecDeviceObj.hpp>
#include <cfintobj/ICFIntSecDeviceEditObj.hpp>
#include <cfsecobj/ICFSecSecDeviceObj.hpp>
#include <cfsecobj/ICFSecSecDeviceEditObj.hpp>
#include <cfsecobj/ICFSecSecDeviceTableObj.hpp>

namespace cfint {

	class ICFIntSecDeviceTableObj
	: public virtual cfsec::ICFSecSecDeviceTableObj
	{
	public:
		ICFIntSecDeviceTableObj();
		virtual ~ICFIntSecDeviceTableObj();
		virtual cfsec::ICFSecSecDeviceObj* newInstance() = 0;

		virtual cfsec::ICFSecSecDeviceEditObj* newEditInstance( cfsec::ICFSecSecDeviceObj* orig ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* realizeSecDevice( cfsec::ICFSecSecDeviceObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;
		virtual void deepDisposeByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;
		virtual void deepDisposeByUserIdx( const uuid_ptr_t SecUserId ) = 0;
		virtual void reallyDeepDisposeSecDevice( cfsec::ICFSecSecDeviceObj* Obj ) = 0;
		virtual cfsec::ICFSecSecDeviceObj* createSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readSecDevice( cfsec::CFSecSecDevicePKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* lockSecDevice( cfsec::CFSecSecDevicePKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readAllSecDevice( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> pageAllSecDevice(const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByNameIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readSecDeviceByUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDevice( cfsec::CFSecSecDevicePKey* pkey ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByIdIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByNameIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readCachedSecDeviceByUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByLookupNameIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByLookupNameIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> pageSecDeviceByUserIdx( const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName ) = 0;

		virtual cfsec::ICFSecSecDeviceObj* updateSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj ) = 0;

		virtual void deleteSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj ) = 0;

		virtual void deleteSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual void deleteSecDeviceByNameIdx(const uuid_ptr_t SecUserId,
			const std::string& DevName ) = 0;

		virtual void deleteSecDeviceByUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual void reallyDetachFromIndexesSecDevice( cfsec::ICFSecSecDeviceObj* Obj ) = 0;

	};
}
