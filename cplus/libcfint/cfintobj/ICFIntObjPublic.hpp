#pragma once

// Description: C++18 Public object interface for CFInt.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cfint/ICFIntPublic.hpp>

#include <cfsecobj/ICFSecObjPublic.hpp>

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

#include <cfintobj/ICFIntSchemaObj.hpp>

#include <cfintobj/ICFIntClusterObj.hpp>
#include <cfintobj/ICFIntHostNodeObj.hpp>
#include <cfintobj/ICFIntISOCcyObj.hpp>
#include <cfintobj/ICFIntISOCtryObj.hpp>
#include <cfintobj/ICFIntISOCtryCcyObj.hpp>
#include <cfintobj/ICFIntISOCtryLangObj.hpp>
#include <cfintobj/ICFIntISOLangObj.hpp>
#include <cfintobj/ICFIntISOTZoneObj.hpp>
#include <cfintobj/ICFIntLicenseObj.hpp>
#include <cfintobj/ICFIntMajorVersionObj.hpp>
#include <cfintobj/ICFIntMimeTypeObj.hpp>
#include <cfintobj/ICFIntMinorVersionObj.hpp>
#include <cfintobj/ICFIntSecAppObj.hpp>
#include <cfintobj/ICFIntSecDeviceObj.hpp>
#include <cfintobj/ICFIntSecFormObj.hpp>
#include <cfintobj/ICFIntSecGroupObj.hpp>
#include <cfintobj/ICFIntSecGroupFormObj.hpp>
#include <cfintobj/ICFIntSecGrpIncObj.hpp>
#include <cfintobj/ICFIntSecGrpMembObj.hpp>
#include <cfintobj/ICFIntSecSessionObj.hpp>
#include <cfintobj/ICFIntSecUserObj.hpp>
#include <cfintobj/ICFIntServiceObj.hpp>
#include <cfintobj/ICFIntServiceTypeObj.hpp>
#include <cfintobj/ICFIntSubProjectObj.hpp>
#include <cfintobj/ICFIntSysClusterObj.hpp>
#include <cfintobj/ICFIntTSecGroupObj.hpp>
#include <cfintobj/ICFIntTSecGrpIncObj.hpp>
#include <cfintobj/ICFIntTSecGrpMembObj.hpp>
#include <cfintobj/ICFIntTenantObj.hpp>
#include <cfintobj/ICFIntTldObj.hpp>
#include <cfintobj/ICFIntTopDomainObj.hpp>
#include <cfintobj/ICFIntTopProjectObj.hpp>
#include <cfintobj/ICFIntURLProtocolObj.hpp>

#include <cfintobj/ICFIntClusterEditObj.hpp>
#include <cfintobj/ICFIntHostNodeEditObj.hpp>
#include <cfintobj/ICFIntISOCcyEditObj.hpp>
#include <cfintobj/ICFIntISOCtryEditObj.hpp>
#include <cfintobj/ICFIntISOCtryCcyEditObj.hpp>
#include <cfintobj/ICFIntISOCtryLangEditObj.hpp>
#include <cfintobj/ICFIntISOLangEditObj.hpp>
#include <cfintobj/ICFIntISOTZoneEditObj.hpp>
#include <cfintobj/ICFIntLicenseEditObj.hpp>
#include <cfintobj/ICFIntMajorVersionEditObj.hpp>
#include <cfintobj/ICFIntMimeTypeEditObj.hpp>
#include <cfintobj/ICFIntMinorVersionEditObj.hpp>
#include <cfintobj/ICFIntSecAppEditObj.hpp>
#include <cfintobj/ICFIntSecDeviceEditObj.hpp>
#include <cfintobj/ICFIntSecFormEditObj.hpp>
#include <cfintobj/ICFIntSecGroupEditObj.hpp>
#include <cfintobj/ICFIntSecGroupFormEditObj.hpp>
#include <cfintobj/ICFIntSecGrpIncEditObj.hpp>
#include <cfintobj/ICFIntSecGrpMembEditObj.hpp>
#include <cfintobj/ICFIntSecSessionEditObj.hpp>
#include <cfintobj/ICFIntSecUserEditObj.hpp>
#include <cfintobj/ICFIntServiceEditObj.hpp>
#include <cfintobj/ICFIntServiceTypeEditObj.hpp>
#include <cfintobj/ICFIntSubProjectEditObj.hpp>
#include <cfintobj/ICFIntSysClusterEditObj.hpp>
#include <cfintobj/ICFIntTSecGroupEditObj.hpp>
#include <cfintobj/ICFIntTSecGrpIncEditObj.hpp>
#include <cfintobj/ICFIntTSecGrpMembEditObj.hpp>
#include <cfintobj/ICFIntTenantEditObj.hpp>
#include <cfintobj/ICFIntTldEditObj.hpp>
#include <cfintobj/ICFIntTopDomainEditObj.hpp>
#include <cfintobj/ICFIntTopProjectEditObj.hpp>
#include <cfintobj/ICFIntURLProtocolEditObj.hpp>

#include <cfintobj/ICFIntClusterTableObj.hpp>
#include <cfintobj/ICFIntHostNodeTableObj.hpp>
#include <cfintobj/ICFIntISOCcyTableObj.hpp>
#include <cfintobj/ICFIntISOCtryTableObj.hpp>
#include <cfintobj/ICFIntISOCtryCcyTableObj.hpp>
#include <cfintobj/ICFIntISOCtryLangTableObj.hpp>
#include <cfintobj/ICFIntISOLangTableObj.hpp>
#include <cfintobj/ICFIntISOTZoneTableObj.hpp>
#include <cfintobj/ICFIntLicenseTableObj.hpp>
#include <cfintobj/ICFIntMajorVersionTableObj.hpp>
#include <cfintobj/ICFIntMimeTypeTableObj.hpp>
#include <cfintobj/ICFIntMinorVersionTableObj.hpp>
#include <cfintobj/ICFIntSecAppTableObj.hpp>
#include <cfintobj/ICFIntSecDeviceTableObj.hpp>
#include <cfintobj/ICFIntSecFormTableObj.hpp>
#include <cfintobj/ICFIntSecGroupTableObj.hpp>
#include <cfintobj/ICFIntSecGroupFormTableObj.hpp>
#include <cfintobj/ICFIntSecGrpIncTableObj.hpp>
#include <cfintobj/ICFIntSecGrpMembTableObj.hpp>
#include <cfintobj/ICFIntSecSessionTableObj.hpp>
#include <cfintobj/ICFIntSecUserTableObj.hpp>
#include <cfintobj/ICFIntServiceTableObj.hpp>
#include <cfintobj/ICFIntServiceTypeTableObj.hpp>
#include <cfintobj/ICFIntSubProjectTableObj.hpp>
#include <cfintobj/ICFIntSysClusterTableObj.hpp>
#include <cfintobj/ICFIntTSecGroupTableObj.hpp>
#include <cfintobj/ICFIntTSecGrpIncTableObj.hpp>
#include <cfintobj/ICFIntTSecGrpMembTableObj.hpp>
#include <cfintobj/ICFIntTenantTableObj.hpp>
#include <cfintobj/ICFIntTldTableObj.hpp>
#include <cfintobj/ICFIntTopDomainTableObj.hpp>
#include <cfintobj/ICFIntTopProjectTableObj.hpp>
#include <cfintobj/ICFIntURLProtocolTableObj.hpp>
