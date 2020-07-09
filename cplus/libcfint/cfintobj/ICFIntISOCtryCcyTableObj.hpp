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

#include <cfintobj/ICFIntISOCtryCcyObj.hpp>
#include <cfintobj/ICFIntISOCtryCcyEditObj.hpp>
#include <cfsecobj/ICFSecISOCtryCcyObj.hpp>
#include <cfsecobj/ICFSecISOCtryCcyEditObj.hpp>
#include <cfsecobj/ICFSecISOCtryCcyTableObj.hpp>

namespace cfint {

	class ICFIntISOCtryCcyTableObj
	: public virtual cfsec::ICFSecISOCtryCcyTableObj
	{
	public:
		ICFIntISOCtryCcyTableObj();
		virtual ~ICFIntISOCtryCcyTableObj();
		virtual cfsec::ICFSecISOCtryCcyObj* newInstance() = 0;

		virtual cfsec::ICFSecISOCtryCcyEditObj* newEditInstance( cfsec::ICFSecISOCtryCcyObj* orig ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* realizeISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId ) = 0;
		virtual void deepDisposeByCtryIdx( const int16_t ISOCtryId ) = 0;
		virtual void deepDisposeByCcyIdx( const int16_t ISOCcyId ) = 0;
		virtual void reallyDeepDisposeISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj ) = 0;
		virtual cfsec::ICFSecISOCtryCcyObj* createISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* readISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* lockISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readAllISOCtryCcy( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* readISOCtryCcyByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readISOCtryCcyByCtryIdx( const int16_t ISOCtryId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readISOCtryCcyByCcyIdx( const int16_t ISOCcyId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* readCachedISOCtryCcy( cfsec::CFSecISOCtryCcyPKey* pkey ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* readCachedISOCtryCcyByIdIdx(const int16_t ISOCtryId,
			const int16_t ISOCcyId ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readCachedISOCtryCcyByCtryIdx( const int16_t ISOCtryId ) = 0;

		virtual std::vector<cfsec::ICFSecISOCtryCcyObj*> readCachedISOCtryCcyByCcyIdx( const int16_t ISOCcyId ) = 0;

		virtual cfsec::ICFSecISOCtryCcyObj* updateISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj ) = 0;

		virtual void deleteISOCtryCcy( cfsec::ICFSecISOCtryCcyEditObj* Obj ) = 0;

		virtual void deleteISOCtryCcyByIdIdx( const int16_t ISOCtryId,
			const int16_t ISOCcyId ) = 0;

		virtual void deleteISOCtryCcyByCtryIdx( const int16_t ISOCtryId ) = 0;

		virtual void deleteISOCtryCcyByCcyIdx( const int16_t ISOCcyId ) = 0;

		virtual void reallyDetachFromIndexesISOCtryCcy( cfsec::ICFSecISOCtryCcyObj* Obj ) = 0;

	};
}
