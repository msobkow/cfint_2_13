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

#include <cfintobj/ICFIntSecGrpMembObj.hpp>
#include <cfintobj/ICFIntSecGrpMembEditObj.hpp>
#include <cfsecobj/ICFSecSecGrpMembObj.hpp>
#include <cfsecobj/ICFSecSecGrpMembEditObj.hpp>
#include <cfsecobj/ICFSecSecGrpMembTableObj.hpp>

namespace cfint {

	class ICFIntSecGrpMembTableObj
	: public virtual cfsec::ICFSecSecGrpMembTableObj
	{
	public:
		ICFIntSecGrpMembTableObj();
		virtual ~ICFIntSecGrpMembTableObj();
		virtual cfsec::ICFSecSecGrpMembObj* newInstance() = 0;

		virtual cfsec::ICFSecSecGrpMembEditObj* newEditInstance( cfsec::ICFSecSecGrpMembObj* orig ) = 0;

		virtual cfsec::ICFSecSecGrpMembObj* realizeSecGrpMemb( cfsec::ICFSecSecGrpMembObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpMembId ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;
		virtual void deepDisposeByUserIdx( const uuid_ptr_t SecUserId ) = 0;
		virtual void deepDisposeByUUserIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId ) = 0;
		virtual void reallyDeepDisposeSecGrpMemb( cfsec::ICFSecSecGrpMembObj* Obj ) = 0;
		virtual cfsec::ICFSecSecGrpMembObj* createSecGrpMemb( cfsec::ICFSecSecGrpMembEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecGrpMembObj* readSecGrpMemb( cfsec::CFSecSecGrpMembPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGrpMembObj* lockSecGrpMemb( cfsec::CFSecSecGrpMembPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readAllSecGrpMemb( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> pageAllSecGrpMemb(const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId ) = 0;

		virtual cfsec::ICFSecSecGrpMembObj* readSecGrpMembByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpMembId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readSecGrpMembByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGrpMembObj* readSecGrpMembByUUserIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecGrpMembObj* readCachedSecGrpMemb( cfsec::CFSecSecGrpMembPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecGrpMembObj* readCachedSecGrpMembByIdIdx(const int64_t ClusterId,
			const int64_t SecGrpMembId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readCachedSecGrpMembByClusterIdx( const int64_t ClusterId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readCachedSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> readCachedSecGrpMembByUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::ICFSecSecGrpMembObj* readCachedSecGrpMembByUUserIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> pageSecGrpMembByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> pageSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId ) = 0;

		virtual std::vector<cfsec::ICFSecSecGrpMembObj*> pageSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpMembId ) = 0;

		virtual cfsec::ICFSecSecGrpMembObj* updateSecGrpMemb( cfsec::ICFSecSecGrpMembEditObj* Obj ) = 0;

		virtual void deleteSecGrpMemb( cfsec::ICFSecSecGrpMembEditObj* Obj ) = 0;

		virtual void deleteSecGrpMembByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpMembId ) = 0;

		virtual void deleteSecGrpMembByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteSecGrpMembByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId ) = 0;

		virtual void deleteSecGrpMembByUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual void deleteSecGrpMembByUUserIdx(const int64_t ClusterId,
			const int32_t SecGroupId,
			const uuid_ptr_t SecUserId ) = 0;

		virtual void reallyDetachFromIndexesSecGrpMemb( cfsec::ICFSecSecGrpMembObj* Obj ) = 0;

	};
}
