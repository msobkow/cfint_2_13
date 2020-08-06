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
