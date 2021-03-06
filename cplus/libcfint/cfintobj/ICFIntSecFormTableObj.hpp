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

#include <cfintobj/ICFIntSecFormObj.hpp>
#include <cfintobj/ICFIntSecFormEditObj.hpp>
#include <cfsecobj/ICFSecSecFormObj.hpp>
#include <cfsecobj/ICFSecSecFormEditObj.hpp>
#include <cfsecobj/ICFSecSecFormTableObj.hpp>

namespace cfint {

	class ICFIntSecFormTableObj
	: public virtual cfsec::ICFSecSecFormTableObj
	{
	public:
		ICFIntSecFormTableObj();
		virtual ~ICFIntSecFormTableObj();
		virtual cfsec::ICFSecSecFormObj* newInstance() = 0;

		virtual cfsec::ICFSecSecFormEditObj* newEditInstance( cfsec::ICFSecSecFormObj* orig ) = 0;

		virtual cfsec::ICFSecSecFormObj* realizeSecForm( cfsec::ICFSecSecFormObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int32_t SecFormId ) = 0;
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId ) = 0;
		virtual void deepDisposeBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId ) = 0;
		virtual void deepDisposeByUJEEServletIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName ) = 0;
		virtual void reallyDeepDisposeSecForm( cfsec::ICFSecSecFormObj* Obj ) = 0;
		virtual cfsec::ICFSecSecFormObj* createSecForm( cfsec::ICFSecSecFormEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecFormObj* readSecForm( cfsec::CFSecSecFormPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecFormObj* lockSecForm( cfsec::CFSecSecFormPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecFormObj*> readAllSecForm( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecFormObj*> pageAllSecForm(const int64_t* priorClusterId,
			const int32_t* priorSecFormId ) = 0;

		virtual cfsec::ICFSecSecFormObj* readSecFormByIdIdx( const int64_t ClusterId,
			const int32_t SecFormId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecFormObj*> readSecFormByClusterIdx( const int64_t ClusterId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecFormObj*> readSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecFormObj* readSecFormByUJEEServletIdx(const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecFormObj* readCachedSecForm( cfsec::CFSecSecFormPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecFormObj* readCachedSecFormByIdIdx(const int64_t ClusterId,
			const int32_t SecFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecFormObj*> readCachedSecFormByClusterIdx( const int64_t ClusterId ) = 0;

		virtual std::vector<cfsec::ICFSecSecFormObj*> readCachedSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual cfsec::ICFSecSecFormObj* readCachedSecFormByUJEEServletIdx(const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName ) = 0;

		virtual cfsec::ICFSecSecFormObj* readSecFormByLookupUJEEServletIdx(const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecFormObj* readCachedSecFormByLookupUJEEServletIdx(const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName ) = 0;

		virtual std::vector<cfsec::ICFSecSecFormObj*> pageSecFormByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId ) = 0;

		virtual std::vector<cfsec::ICFSecSecFormObj*> pageSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int32_t* priorSecFormId ) = 0;

		virtual cfsec::ICFSecSecFormObj* updateSecForm( cfsec::ICFSecSecFormEditObj* Obj ) = 0;

		virtual void deleteSecForm( cfsec::ICFSecSecFormEditObj* Obj ) = 0;

		virtual void deleteSecFormByIdIdx( const int64_t ClusterId,
			const int32_t SecFormId ) = 0;

		virtual void deleteSecFormByClusterIdx( const int64_t ClusterId ) = 0;

		virtual void deleteSecFormBySecAppIdx( const int64_t ClusterId,
			const int32_t SecAppId ) = 0;

		virtual void deleteSecFormByUJEEServletIdx(const int64_t ClusterId,
			const int32_t SecAppId,
			const std::string& JEEServletMapName ) = 0;

		virtual void reallyDetachFromIndexesSecForm( cfsec::ICFSecSecFormObj* Obj ) = 0;

	};
}
