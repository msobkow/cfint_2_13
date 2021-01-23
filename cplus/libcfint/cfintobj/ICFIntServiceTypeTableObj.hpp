#pragma once

// Description: C++18 Table Object interface for CFInt.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
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
