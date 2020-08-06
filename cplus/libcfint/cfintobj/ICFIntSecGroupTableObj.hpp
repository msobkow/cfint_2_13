#pragma once

// Description: C++18 Table Object interface for CFInt.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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

#include <cfintobj/ICFIntSecGroupObj.hpp>
#include <cfintobj/ICFIntSecGroupEditObj.hpp>
#include <cfsecobj/ICFSecSecGroupObj.hpp>
#include <cfsecobj/ICFSecSecGroupEditObj.hpp>
#include <cfsecobj/ICFSecSecGroupTableObj.hpp>

namespace cfint {

	class ICFIntSecGroupTableObj
	: public virtual cfsec::ICFSecSecGroupTableObj
	{
	public:
		ICFIntSecGroupTableObj();
		virtual ~ICFIntSecGroupTableObj();
		virtual cfsec::ICFSecSecGroupObj* newInstance() = 0;

		virtual cfsec::ICFSecSecGroupEditObj* newEditInstance( cfsec::ICFSecSecGroupObj* orig ) = 0;

		virtual cfsec::ICFSecSecGroupObj* realizeSecGroup( cfsec::ICFSecSecGroupObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible ) = 0;
		virtual void deepDisposeByUNameIdx( const int64_t ClusterId,
			const std::string& Name ) = 0;
		virtual void reallyDeepDisposeSecGroup( cfsec::ICFSecSecGroupObj* Obj ) = 0;
		virtual cfsec::ICFSecSecGroupObj* createSecGroup( cfsec::ICFSecSecGroupEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecGroupObj* readSecGroup( cfsec::CFSecSecGroupPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGroupObj* lockSecGroup( cfsec::CFSecSecGroupPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readAllSecGroup( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGroupObj* readSecGroupByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readSecGroupByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGroupObj* readSecGroupByUNameIdx(const int64_t ClusterId,
			const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroup( cfsec::CFSecSecGroupPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroupByIdIdx(const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readCachedSecGroupByClusterIdx( const int64_t ClusterId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readCachedSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible ) = 0;

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroupByUNameIdx(const int64_t ClusterId,
			const std::string& Name ) = 0;

		virtual cfsec::ICFSecSecGroupObj* readSecGroupByLookupUNameIdx(const int64_t ClusterId,
			const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroupByLookupUNameIdx(const int64_t ClusterId,
			const std::string& Name ) = 0;

		virtual cfsec::ICFSecSecGroupObj* updateSecGroup( cfsec::ICFSecSecGroupEditObj* Obj ) = 0;

		virtual void deleteSecGroup( cfsec::ICFSecSecGroupEditObj* Obj ) = 0;

		virtual void deleteSecGroupByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual void deleteSecGroupByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible ) = 0;

		virtual void deleteSecGroupByUNameIdx(const int64_t ClusterId,
			const std::string& Name ) = 0;

		virtual void reallyDetachFromIndexesSecGroup( cfsec::ICFSecSecGroupObj* Obj ) = 0;

	};
}
