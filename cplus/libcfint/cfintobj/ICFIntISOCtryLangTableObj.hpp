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

#include <cfintobj/ICFIntISOCtryLangObj.hpp>
#include <cfintobj/ICFIntISOCtryLangEditObj.hpp>
#include <cfsecobj/ICFSecISOCtryLangObj.hpp>
#include <cfsecobj/ICFSecISOCtryLangEditObj.hpp>
#include <cfsecobj/ICFSecISOCtryLangTableObj.hpp>

namespace cfint {

	class ICFIntISOCtryLangTableObj
	: public virtual cfsec::ICFSecISOCtryLangTableObj
	{
	public:
		ICFIntISOCtryLangTableObj();
		virtual ~ICFIntISOCtryLangTableObj();
		virtual cfsec::ICFSecISOCtryLangObj* newInstance() = 0;

		virtual cfsec::ICFSecISOCtryLangEditObj* newEditInstance( cfsec::ICFSecISOCtryLangObj* orig ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* realizeISOCtryLang( cfsec::ICFSecISOCtryLangObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOLangId ) = 0;
		virtual void deepDisposeByCtryIdx( const int16_t ISOCtryId ) = 0;
		virtual void deepDisposeByLangIdx( const int16_t ISOLangId ) = 0;
		virtual void reallyDeepDisposeISOCtryLang( cfsec::ICFSecISOCtryLangObj* Obj ) = 0;
		virtual cfsec::ICFSecISOCtryLangObj* createISOCtryLang( cfsec::ICFSecISOCtryLangEditObj* Obj ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* readISOCtryLang( cfsec::CFSecISOCtryLangPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* lockISOCtryLang( cfsec::CFSecISOCtryLangPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryLangObj*> readAllISOCtryLang( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* readISOCtryLangByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOLangId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryLangObj*> readISOCtryLangByCtryIdx( const int16_t ISOCtryId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryLangObj*> readISOCtryLangByLangIdx( const int16_t ISOLangId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* readCachedISOCtryLang( cfsec::CFSecISOCtryLangPKey* pkey ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* readCachedISOCtryLangByIdIdx(const int16_t ISOCtryId,
			const int16_t ISOLangId ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryLangObj*> readCachedISOCtryLangByCtryIdx( const int16_t ISOCtryId ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryLangObj*> readCachedISOCtryLangByLangIdx( const int16_t ISOLangId ) = 0;

		virtual cfsec::ICFSecISOCtryLangObj* updateISOCtryLang( cfsec::ICFSecISOCtryLangEditObj* Obj ) = 0;

		virtual void deleteISOCtryLang( cfsec::ICFSecISOCtryLangEditObj* Obj ) = 0;

		virtual void deleteISOCtryLangByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOLangId ) = 0;

		virtual void deleteISOCtryLangByCtryIdx( const int16_t ISOCtryId ) = 0;

		virtual void deleteISOCtryLangByLangIdx( const int16_t ISOLangId ) = 0;

		virtual void reallyDetachFromIndexesISOCtryLang( cfsec::ICFSecISOCtryLangObj* Obj ) = 0;

	};
}
