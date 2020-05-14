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

#include <cfintobj/ICFIntMimeTypeObj.hpp>
#include <cfintobj/ICFIntMimeTypeEditObj.hpp>

namespace cfint {

	class ICFIntMimeTypeTableObj
	{
	public:
		ICFIntMimeTypeTableObj();
		virtual ~ICFIntMimeTypeTableObj();
		virtual cfint::ICFIntSchemaObj* getSchema() = 0;
		virtual void setSchema( cfint::ICFIntSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfint::ICFIntMimeTypeObj* newInstance() = 0;

		virtual cfint::ICFIntMimeTypeEditObj* newEditInstance( cfint::ICFIntMimeTypeObj* orig ) = 0;

		virtual cfint::ICFIntMimeTypeObj* realizeMimeType( cfint::ICFIntMimeTypeObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int32_t MimeTypeId ) = 0;
		virtual void deepDisposeByUNameIdx( const std::string& Name ) = 0;
		virtual void reallyDeepDisposeMimeType( cfint::ICFIntMimeTypeObj* Obj ) = 0;
		virtual cfint::ICFIntMimeTypeObj* createMimeType( cfint::ICFIntMimeTypeEditObj* Obj ) = 0;

		virtual cfint::ICFIntMimeTypeObj* readMimeType( cfint::CFIntMimeTypePKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntMimeTypeObj* lockMimeType( cfint::CFIntMimeTypePKey* pkey ) = 0;

		virtual std::vector<cfint::ICFIntMimeTypeObj*> readAllMimeType( bool forceRead = false ) = 0;

		virtual cfint::ICFIntMimeTypeObj* readMimeTypeByIdIdx( const int32_t MimeTypeId,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntMimeTypeObj* readMimeTypeByUNameIdx(const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntMimeTypeObj* readCachedMimeType( cfint::CFIntMimeTypePKey* pkey ) = 0;

		virtual cfint::ICFIntMimeTypeObj* readCachedMimeTypeByIdIdx(const int32_t MimeTypeId ) = 0;

		virtual cfint::ICFIntMimeTypeObj* readCachedMimeTypeByUNameIdx(const std::string& Name ) = 0;

		virtual cfint::ICFIntMimeTypeObj* readMimeTypeByLookupUNameIdx(const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntMimeTypeObj* readCachedMimeTypeByLookupUNameIdx(const std::string& Name ) = 0;

		virtual cfint::ICFIntMimeTypeObj* updateMimeType( cfint::ICFIntMimeTypeEditObj* Obj ) = 0;

		virtual void deleteMimeType( cfint::ICFIntMimeTypeEditObj* Obj ) = 0;

		virtual void deleteMimeTypeByIdIdx( const int32_t MimeTypeId ) = 0;

		virtual void deleteMimeTypeByUNameIdx(const std::string& Name ) = 0;

		virtual void reallyDetachFromIndexesMimeType( cfint::ICFIntMimeTypeObj* Obj ) = 0;

	};
}