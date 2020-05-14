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

#include <cfintobj/ICFIntISOCtryObj.hpp>
#include <cfintobj/ICFIntISOCtryEditObj.hpp>
#include <cfsecobj/ICFSecISOCtryObj.hpp>
#include <cfsecobj/ICFSecISOCtryEditObj.hpp>
#include <cfsecobj/ICFSecISOCtryTableObj.hpp>

namespace cfint {

	class ICFIntISOCtryTableObj
	: public virtual cfsec::ICFSecISOCtryTableObj
	{
	public:
		ICFIntISOCtryTableObj();
		virtual ~ICFIntISOCtryTableObj();
		virtual cfsec::ICFSecISOCtryObj* newInstance() = 0;

		virtual cfsec::ICFSecISOCtryEditObj* newEditInstance( cfsec::ICFSecISOCtryObj* orig ) = 0;

		virtual cfsec::ICFSecISOCtryObj* realizeISOCtry( cfsec::ICFSecISOCtryObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int16_t ISOCtryId ) = 0;
		virtual void deepDisposeByISOCodeIdx( const std::string& ISOCode ) = 0;
		virtual void deepDisposeByNameIdx( const std::string& Name ) = 0;
		virtual void reallyDeepDisposeISOCtry( cfsec::ICFSecISOCtryObj* Obj ) = 0;
		virtual cfsec::ICFSecISOCtryObj* createISOCtry( cfsec::ICFSecISOCtryEditObj* Obj ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readISOCtry( cfsec::CFSecISOCtryPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* lockISOCtry( cfsec::CFSecISOCtryPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryObj*> readAllISOCtry( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByIdIdx( const int16_t ISOCtryId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByISOCodeIdx(const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByNameIdx(const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtry( cfsec::CFSecISOCtryPKey* pkey ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByIdIdx(const int16_t ISOCtryId ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByISOCodeIdx(const std::string& ISOCode ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByNameIdx(const std::string& Name ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readISOCtryByLookupISOCodeIdx(const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryObj* readCachedISOCtryByLookupISOCodeIdx(const std::string& ISOCode ) = 0;

		virtual cfsec::ICFSecISOCtryObj* updateISOCtry( cfsec::ICFSecISOCtryEditObj* Obj ) = 0;

		virtual void deleteISOCtry( cfsec::ICFSecISOCtryEditObj* Obj ) = 0;

		virtual void deleteISOCtryByIdIdx( const int16_t ISOCtryId ) = 0;

		virtual void deleteISOCtryByISOCodeIdx(const std::string& ISOCode ) = 0;

		virtual void deleteISOCtryByNameIdx(const std::string& Name ) = 0;

		virtual void reallyDetachFromIndexesISOCtry( cfsec::ICFSecISOCtryObj* Obj ) = 0;

	};
}
