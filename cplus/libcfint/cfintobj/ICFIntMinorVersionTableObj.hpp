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

#include <cfintobj/ICFIntMinorVersionObj.hpp>
#include <cfintobj/ICFIntMinorVersionEditObj.hpp>

namespace cfint {

	class ICFIntMinorVersionTableObj
	{
	public:
		ICFIntMinorVersionTableObj();
		virtual ~ICFIntMinorVersionTableObj();
		virtual cfint::ICFIntSchemaObj* getSchema() = 0;
		virtual void setSchema( cfint::ICFIntSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfint::ICFIntMinorVersionObj* newInstance() = 0;

		virtual cfint::ICFIntMinorVersionEditObj* newEditInstance( cfint::ICFIntMinorVersionObj* orig ) = 0;

		virtual cfint::ICFIntMinorVersionObj* realizeMinorVersion( cfint::ICFIntMinorVersionObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id ) = 0;
		virtual void deepDisposeByTenantIdx( const int64_t TenantId ) = 0;
		virtual void deepDisposeByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId ) = 0;
		virtual void deepDisposeByNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name ) = 0;
		virtual void reallyDeepDisposeMinorVersion( cfint::ICFIntMinorVersionObj* Obj ) = 0;
		virtual cfint::ICFIntMinorVersionObj* createMinorVersion( cfint::ICFIntMinorVersionEditObj* Obj ) = 0;

		virtual cfint::ICFIntMinorVersionObj* readMinorVersion( cfint::CFIntMinorVersionPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntMinorVersionObj* lockMinorVersion( cfint::CFIntMinorVersionPKey* pkey ) = 0;

		virtual std::vector<cfint::ICFIntMinorVersionObj*> readAllMinorVersion( bool forceRead = false ) = 0;

		virtual cfint::ICFIntMinorVersionObj* readMinorVersionByIdIdx( const int64_t TenantId,
			const int64_t Id,
			bool forceRead = false ) = 0;

		virtual std::vector<cfint::ICFIntMinorVersionObj*> readMinorVersionByTenantIdx( const int64_t TenantId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfint::ICFIntMinorVersionObj*> readMinorVersionByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntMinorVersionObj* readMinorVersionByNameIdx(const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntMinorVersionObj* readCachedMinorVersion( cfint::CFIntMinorVersionPKey* pkey ) = 0;

		virtual cfint::ICFIntMinorVersionObj* readCachedMinorVersionByIdIdx(const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::vector<cfint::ICFIntMinorVersionObj*> readCachedMinorVersionByTenantIdx( const int64_t TenantId ) = 0;

		virtual std::vector<cfint::ICFIntMinorVersionObj*> readCachedMinorVersionByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId ) = 0;

		virtual cfint::ICFIntMinorVersionObj* readCachedMinorVersionByNameIdx(const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name ) = 0;

		virtual cfint::ICFIntMinorVersionObj* readMinorVersionByLookupNameIdx(const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntMinorVersionObj* readCachedMinorVersionByLookupNameIdx(const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name ) = 0;

		virtual cfint::ICFIntMinorVersionObj* updateMinorVersion( cfint::ICFIntMinorVersionEditObj* Obj ) = 0;

		virtual void deleteMinorVersion( cfint::ICFIntMinorVersionEditObj* Obj ) = 0;

		virtual void deleteMinorVersionByIdIdx( const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual void deleteMinorVersionByTenantIdx( const int64_t TenantId ) = 0;

		virtual void deleteMinorVersionByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId ) = 0;

		virtual void deleteMinorVersionByNameIdx(const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name ) = 0;

		virtual void reallyDetachFromIndexesMinorVersion( cfint::ICFIntMinorVersionObj* Obj ) = 0;

	};
}
