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

#include <cfintobj/ICFIntSecAppObj.hpp>
#include <cfintobj/ICFIntSecAppEditObj.hpp>
#include <cfsecobj/ICFSecSecAppObj.hpp>
#include <cfsecobj/ICFSecSecAppEditObj.hpp>
#include <cfsecobj/ICFSecSecAppTableObj.hpp>

namespace cfint {

	class ICFIntSecAppTableObj
	: public virtual cfsec::ICFSecSecAppTableObj
	{
	public:
		ICFIntSecAppTableObj();
		virtual ~ICFIntSecAppTableObj();
		virtual cfsec::ICFSecSecAppObj* newInstance() = 0;

		virtual cfsec::ICFSecSecAppEditObj* newEditInstance( cfsec::ICFSecSecAppObj* orig ) = 0;

		virtual cfsec::ICFSecSecAppObj* realizeSecApp( cfsec::ICFSecSecAppObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int32_t SecAppId ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByUJEEMountIdx( const int64_t ClusterId,
			const std::string& JEEMountName ) = 0;
		virtual void reallyDeepDisposeSecApp( cfsec::ICFSecSecAppObj* Obj ) = 0;
		virtual cfsec::ICFSecSecAppObj* createSecApp( cfsec::ICFSecSecAppEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecAppObj* readSecApp( cfsec::CFSecSecAppPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecAppObj* lockSecApp( cfsec::CFSecSecAppPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecAppObj*> readAllSecApp( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecAppObj*> pageAllSecApp(const int64_t* priorClusterId,
			const int32_t* priorSecAppId ) = 0;

		virtual cfsec::ICFSecSecAppObj* readSecAppByIdIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecAppObj*> readSecAppByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecAppObj* readSecAppByUJEEMountIdx(const int64_t ClusterId,
			const std::string& JEEMountName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecAppObj* readCachedSecApp( cfsec::CFSecSecAppPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecAppObj* readCachedSecAppByIdIdx(const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual std::vector<cfsec::ICFSecSecAppObj*> readCachedSecAppByClusterIdx( const int64_t ClusterId ) = 0;

		virtual cfsec::ICFSecSecAppObj* readCachedSecAppByUJEEMountIdx(const int64_t ClusterId,
			const std::string& JEEMountName ) = 0;

		virtual cfsec::ICFSecSecAppObj* readSecAppByLookupUJEEMountIdx(const int64_t ClusterId,
			const std::string& JEEMountName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecAppObj* readCachedSecAppByLookupUJEEMountIdx(const int64_t ClusterId,
			const std::string& JEEMountName ) = 0;

		virtual std::vector<cfsec::ICFSecSecAppObj*> pageSecAppByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecAppId ) = 0;

		virtual cfsec::ICFSecSecAppObj* updateSecApp( cfsec::ICFSecSecAppEditObj* Obj ) = 0;

		virtual void deleteSecApp( cfsec::ICFSecSecAppEditObj* Obj ) = 0;

		virtual void deleteSecAppByIdIdx( const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual void deleteSecAppByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteSecAppByUJEEMountIdx(const int64_t ClusterId,
			const std::string& JEEMountName ) = 0;

		virtual void reallyDetachFromIndexesSecApp( cfsec::ICFSecSecAppObj* Obj ) = 0;

	};
}
