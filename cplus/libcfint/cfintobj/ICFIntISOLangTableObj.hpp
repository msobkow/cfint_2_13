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

#include <cfintobj/ICFIntISOLangObj.hpp>
#include <cfintobj/ICFIntISOLangEditObj.hpp>
#include <cfsecobj/ICFSecISOLangObj.hpp>
#include <cfsecobj/ICFSecISOLangEditObj.hpp>
#include <cfsecobj/ICFSecISOLangTableObj.hpp>

namespace cfint {

	class ICFIntISOLangTableObj
	: public virtual cfsec::ICFSecISOLangTableObj
	{
	public:
		ICFIntISOLangTableObj();
		virtual ~ICFIntISOLangTableObj();
		virtual cfsec::ICFSecISOLangObj* newInstance() = 0;

		virtual cfsec::ICFSecISOLangEditObj* newEditInstance( cfsec::ICFSecISOLangObj* orig ) = 0;

		virtual cfsec::ICFSecISOLangObj* realizeISOLang( cfsec::ICFSecISOLangObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int16_t ISOLangId ) = 0;
		virtual void deepDisposeByCode3Idx( const std::string& ISO6392Code ) = 0;
		virtual void deepDisposeByCode2Idx( const std::string* ISO6391Code ) = 0;
		virtual void reallyDeepDisposeISOLang( cfsec::ICFSecISOLangObj* Obj ) = 0;
		virtual cfsec::ICFSecISOLangObj* createISOLang( cfsec::ICFSecISOLangEditObj* Obj ) = 0;

		virtual cfsec::ICFSecISOLangObj* readISOLang( cfsec::CFSecISOLangPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOLangObj* lockISOLang( cfsec::CFSecISOLangPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecISOLangObj*> readAllISOLang( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOLangObj* readISOLangByIdIdx( const int16_t ISOLangId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOLangObj* readISOLangByCode3Idx(const std::string& ISO6392Code,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOLangObj*> readISOLangByCode2Idx( const std::string* ISO6391Code,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOLangObj* readCachedISOLang( cfsec::CFSecISOLangPKey* pkey ) = 0;

		virtual cfsec::ICFSecISOLangObj* readCachedISOLangByIdIdx(const int16_t ISOLangId ) = 0;

		virtual cfsec::ICFSecISOLangObj* readCachedISOLangByCode3Idx(const std::string& ISO6392Code ) = 0;

		virtual std::vector<cfsec::ICFSecISOLangObj*> readCachedISOLangByCode2Idx( const std::string* ISO6391Code ) = 0;

		virtual cfsec::ICFSecISOLangObj* readISOLangByLookupCode3Idx(const std::string& ISO6392Code,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOLangObj* readCachedISOLangByLookupCode3Idx(const std::string& ISO6392Code ) = 0;

		virtual cfsec::ICFSecISOLangObj* updateISOLang( cfsec::ICFSecISOLangEditObj* Obj ) = 0;

		virtual void deleteISOLang( cfsec::ICFSecISOLangEditObj* Obj ) = 0;

		virtual void deleteISOLangByIdIdx( const int16_t ISOLangId ) = 0;

		virtual void deleteISOLangByCode3Idx(const std::string& ISO6392Code ) = 0;

		virtual void deleteISOLangByCode2Idx( const std::string* ISO6391Code ) = 0;

		virtual void reallyDetachFromIndexesISOLang( cfsec::ICFSecISOLangObj* Obj ) = 0;

	};
}
