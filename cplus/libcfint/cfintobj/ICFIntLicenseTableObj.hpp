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

#include <cfintobj/ICFIntLicenseObj.hpp>
#include <cfintobj/ICFIntLicenseEditObj.hpp>

namespace cfint {

	class ICFIntLicenseTableObj
	{
	public:
		ICFIntLicenseTableObj();
		virtual ~ICFIntLicenseTableObj();
		virtual cfint::ICFIntSchemaObj* getSchema() = 0;
		virtual void setSchema( cfint::ICFIntSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfint::ICFIntLicenseObj* newInstance() = 0;

		virtual cfint::ICFIntLicenseEditObj* newEditInstance( cfint::ICFIntLicenseObj* orig ) = 0;

		virtual cfint::ICFIntLicenseObj* realizeLicense( cfint::ICFIntLicenseObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id ) = 0;
		virtual void deepDisposeByLicnTenantIdx( const int64_t TenantId ) = 0;
		virtual void deepDisposeByDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId ) = 0;
		virtual void deepDisposeByUNameIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name ) = 0;
		virtual void reallyDeepDisposeLicense( cfint::ICFIntLicenseObj* Obj ) = 0;
		virtual cfint::ICFIntLicenseObj* createLicense( cfint::ICFIntLicenseEditObj* Obj ) = 0;

		virtual cfint::ICFIntLicenseObj* readLicense( cfint::CFIntLicensePKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntLicenseObj* lockLicense( cfint::CFIntLicensePKey* pkey ) = 0;

		virtual std::vector<cfint::ICFIntLicenseObj*> readAllLicense( bool forceRead = false ) = 0;

		virtual cfint::ICFIntLicenseObj* readLicenseByIdIdx( const int64_t TenantId,
			const int64_t Id,
			bool forceRead = false ) = 0;

		virtual std::vector<cfint::ICFIntLicenseObj*> readLicenseByLicnTenantIdx( const int64_t TenantId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfint::ICFIntLicenseObj*> readLicenseByDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntLicenseObj* readLicenseByUNameIdx(const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntLicenseObj* readCachedLicense( cfint::CFIntLicensePKey* pkey ) = 0;

		virtual cfint::ICFIntLicenseObj* readCachedLicenseByIdIdx(const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::vector<cfint::ICFIntLicenseObj*> readCachedLicenseByLicnTenantIdx( const int64_t TenantId ) = 0;

		virtual std::vector<cfint::ICFIntLicenseObj*> readCachedLicenseByDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId ) = 0;

		virtual cfint::ICFIntLicenseObj* readCachedLicenseByUNameIdx(const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name ) = 0;

		virtual cfint::ICFIntLicenseObj* readLicenseByLookupUNameIdx(const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntLicenseObj* readCachedLicenseByLookupUNameIdx(const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name ) = 0;

		virtual cfint::ICFIntLicenseObj* updateLicense( cfint::ICFIntLicenseEditObj* Obj ) = 0;

		virtual void deleteLicense( cfint::ICFIntLicenseEditObj* Obj ) = 0;

		virtual void deleteLicenseByIdIdx( const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual void deleteLicenseByLicnTenantIdx( const int64_t TenantId ) = 0;

		virtual void deleteLicenseByDomainIdx( const int64_t TenantId,
			const int64_t TopDomainId ) = 0;

		virtual void deleteLicenseByUNameIdx(const int64_t TenantId,
			const int64_t TopDomainId,
			const std::string& Name ) = 0;

		virtual void reallyDetachFromIndexesLicense( cfint::ICFIntLicenseObj* Obj ) = 0;

	};
}
