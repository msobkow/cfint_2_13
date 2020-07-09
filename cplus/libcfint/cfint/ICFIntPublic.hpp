#pragma once

// Description: C++18 interface for a CFInt public invoker.

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

#include <uuid/uuid.h>

#include <array>
#include <cassert>
#include <cstddef>
#include <chrono>
#include <ctime>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <vector>

#include <cflib/ICFLibPublic.hpp>

namespace cfint {

	class CFIntLicensePKey;
	class CFIntMajorVersionPKey;
	class CFIntMimeTypePKey;
	class CFIntMinorVersionPKey;
	class CFIntSubProjectPKey;
	class CFIntTldPKey;
	class CFIntTopDomainPKey;
	class CFIntTopProjectPKey;
	class CFIntURLProtocolPKey;

	class CFIntMajorVersionHPKey;
	class CFIntMimeTypeHPKey;
	class CFIntMinorVersionHPKey;
	class CFIntSubProjectHPKey;
	class CFIntTldHPKey;
	class CFIntTopDomainHPKey;
	class CFIntTopProjectHPKey;
	class CFIntURLProtocolHPKey;

	class CFIntLicenseBuff;
	class CFIntMajorVersionBuff;
	class CFIntMimeTypeBuff;
	class CFIntMinorVersionBuff;
	class CFIntSubProjectBuff;
	class CFIntTldBuff;
	class CFIntTopDomainBuff;
	class CFIntTopProjectBuff;
	class CFIntURLProtocolBuff;

	class CFIntMajorVersionHBuff;
	class CFIntMimeTypeHBuff;
	class CFIntMinorVersionHBuff;
	class CFIntSubProjectHBuff;
	class CFIntTldHBuff;
	class CFIntTopDomainHBuff;
	class CFIntTopProjectHBuff;
	class CFIntURLProtocolHBuff;

	class CFIntLicenseByLicnTenantIdxKey;
	class CFIntLicenseByDomainIdxKey;
	class CFIntLicenseByUNameIdxKey;
	class CFIntMajorVersionByTenantIdxKey;
	class CFIntMajorVersionBySubProjectIdxKey;
	class CFIntMajorVersionByNameIdxKey;
	class CFIntMimeTypeByUNameIdxKey;
	class CFIntMinorVersionByTenantIdxKey;
	class CFIntMinorVersionByMajorVerIdxKey;
	class CFIntMinorVersionByNameIdxKey;
	class CFIntSubProjectByTenantIdxKey;
	class CFIntSubProjectByTopProjectIdxKey;
	class CFIntSubProjectByNameIdxKey;
	class CFIntTldByTenantIdxKey;
	class CFIntTldByNameIdxKey;
	class CFIntTopDomainByTenantIdxKey;
	class CFIntTopDomainByTldIdxKey;
	class CFIntTopDomainByNameIdxKey;
	class CFIntTopProjectByTenantIdxKey;
	class CFIntTopProjectByTopDomainIdxKey;
	class CFIntTopProjectByNameIdxKey;
	class CFIntURLProtocolByUNameIdxKey;
	class CFIntURLProtocolByIsSecureIdxKey;

	class ICFIntClusterTable;
	class ICFIntHostNodeTable;
	class ICFIntISOCcyTable;
	class ICFIntISOCtryTable;
	class ICFIntISOCtryCcyTable;
	class ICFIntISOCtryLangTable;
	class ICFIntISOLangTable;
	class ICFIntISOTZoneTable;
	class ICFIntLicenseTable;
	class ICFIntMajorVersionTable;
	class ICFIntMimeTypeTable;
	class ICFIntMinorVersionTable;
	class ICFIntSecAppTable;
	class ICFIntSecDeviceTable;
	class ICFIntSecFormTable;
	class ICFIntSecGroupTable;
	class ICFIntSecGroupFormTable;
	class ICFIntSecGrpIncTable;
	class ICFIntSecGrpMembTable;
	class ICFIntSecSessionTable;
	class ICFIntSecUserTable;
	class ICFIntServiceTable;
	class ICFIntServiceTypeTable;
	class ICFIntSubProjectTable;
	class ICFIntSysClusterTable;
	class ICFIntTSecGroupTable;
	class ICFIntTSecGrpIncTable;
	class ICFIntTSecGrpMembTable;
	class ICFIntTenantTable;
	class ICFIntTldTable;
	class ICFIntTopDomainTable;
	class ICFIntTopProjectTable;
	class ICFIntURLProtocolTable;
}
#include <cfsec/ICFSecSchema.hpp>
#include <cfsec/CFSecAuthorization.hpp>
#include <cfint/CFIntConfigurationFile.hpp>
#include <cfint/ICFIntTablePerms.hpp>
#include <cfsec/ICFSecPublic.hpp>

#include <cfint/CFIntLicensePKey.hpp>
#include <cfint/CFIntMajorVersionPKey.hpp>
#include <cfint/CFIntMimeTypePKey.hpp>
#include <cfint/CFIntMinorVersionPKey.hpp>
#include <cfint/CFIntSubProjectPKey.hpp>
#include <cfint/CFIntTldPKey.hpp>
#include <cfint/CFIntTopDomainPKey.hpp>
#include <cfint/CFIntTopProjectPKey.hpp>
#include <cfint/CFIntURLProtocolPKey.hpp>

#include <cfint/CFIntMajorVersionHPKey.hpp>
#include <cfint/CFIntMimeTypeHPKey.hpp>
#include <cfint/CFIntMinorVersionHPKey.hpp>
#include <cfint/CFIntSubProjectHPKey.hpp>
#include <cfint/CFIntTldHPKey.hpp>
#include <cfint/CFIntTopDomainHPKey.hpp>
#include <cfint/CFIntTopProjectHPKey.hpp>
#include <cfint/CFIntURLProtocolHPKey.hpp>

#include <cfint/CFIntLicenseBuff.hpp>
#include <cfint/CFIntMajorVersionBuff.hpp>
#include <cfint/CFIntMimeTypeBuff.hpp>
#include <cfint/CFIntMinorVersionBuff.hpp>
#include <cfint/CFIntSubProjectBuff.hpp>
#include <cfint/CFIntTldBuff.hpp>
#include <cfint/CFIntTopDomainBuff.hpp>
#include <cfint/CFIntTopProjectBuff.hpp>
#include <cfint/CFIntURLProtocolBuff.hpp>

#include <cfint/CFIntMajorVersionHBuff.hpp>
#include <cfint/CFIntMimeTypeHBuff.hpp>
#include <cfint/CFIntMinorVersionHBuff.hpp>
#include <cfint/CFIntSubProjectHBuff.hpp>
#include <cfint/CFIntTldHBuff.hpp>
#include <cfint/CFIntTopDomainHBuff.hpp>
#include <cfint/CFIntTopProjectHBuff.hpp>
#include <cfint/CFIntURLProtocolHBuff.hpp>

#include <cfint/CFIntLicenseByLicnTenantIdxKey.hpp>
#include <cfint/CFIntLicenseByDomainIdxKey.hpp>
#include <cfint/CFIntLicenseByUNameIdxKey.hpp>
#include <cfint/CFIntMajorVersionByTenantIdxKey.hpp>
#include <cfint/CFIntMajorVersionBySubProjectIdxKey.hpp>
#include <cfint/CFIntMajorVersionByNameIdxKey.hpp>
#include <cfint/CFIntMimeTypeByUNameIdxKey.hpp>
#include <cfint/CFIntMinorVersionByTenantIdxKey.hpp>
#include <cfint/CFIntMinorVersionByMajorVerIdxKey.hpp>
#include <cfint/CFIntMinorVersionByNameIdxKey.hpp>
#include <cfint/CFIntSubProjectByTenantIdxKey.hpp>
#include <cfint/CFIntSubProjectByTopProjectIdxKey.hpp>
#include <cfint/CFIntSubProjectByNameIdxKey.hpp>
#include <cfint/CFIntTldByTenantIdxKey.hpp>
#include <cfint/CFIntTldByNameIdxKey.hpp>
#include <cfint/CFIntTopDomainByTenantIdxKey.hpp>
#include <cfint/CFIntTopDomainByTldIdxKey.hpp>
#include <cfint/CFIntTopDomainByNameIdxKey.hpp>
#include <cfint/CFIntTopProjectByTenantIdxKey.hpp>
#include <cfint/CFIntTopProjectByTopDomainIdxKey.hpp>
#include <cfint/CFIntTopProjectByNameIdxKey.hpp>
#include <cfint/CFIntURLProtocolByUNameIdxKey.hpp>
#include <cfint/CFIntURLProtocolByIsSecureIdxKey.hpp>

#include <cfint/ICFIntClusterTable.hpp>
#include <cfint/ICFIntHostNodeTable.hpp>
#include <cfint/ICFIntISOCcyTable.hpp>
#include <cfint/ICFIntISOCtryTable.hpp>
#include <cfint/ICFIntISOCtryCcyTable.hpp>
#include <cfint/ICFIntISOCtryLangTable.hpp>
#include <cfint/ICFIntISOLangTable.hpp>
#include <cfint/ICFIntISOTZoneTable.hpp>
#include <cfint/ICFIntLicenseTable.hpp>
#include <cfint/ICFIntMajorVersionTable.hpp>
#include <cfint/ICFIntMimeTypeTable.hpp>
#include <cfint/ICFIntMinorVersionTable.hpp>
#include <cfint/ICFIntSecAppTable.hpp>
#include <cfint/ICFIntSecDeviceTable.hpp>
#include <cfint/ICFIntSecFormTable.hpp>
#include <cfint/ICFIntSecGroupTable.hpp>
#include <cfint/ICFIntSecGroupFormTable.hpp>
#include <cfint/ICFIntSecGrpIncTable.hpp>
#include <cfint/ICFIntSecGrpMembTable.hpp>
#include <cfint/ICFIntSecSessionTable.hpp>
#include <cfint/ICFIntSecUserTable.hpp>
#include <cfint/ICFIntServiceTable.hpp>
#include <cfint/ICFIntServiceTypeTable.hpp>
#include <cfint/ICFIntSubProjectTable.hpp>
#include <cfint/ICFIntSysClusterTable.hpp>
#include <cfint/ICFIntTSecGroupTable.hpp>
#include <cfint/ICFIntTSecGrpIncTable.hpp>
#include <cfint/ICFIntTSecGrpMembTable.hpp>
#include <cfint/ICFIntTenantTable.hpp>
#include <cfint/ICFIntTldTable.hpp>
#include <cfint/ICFIntTopDomainTable.hpp>
#include <cfint/ICFIntTopProjectTable.hpp>
#include <cfint/ICFIntURLProtocolTable.hpp>
