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

#include <cfintobj/ICFIntISOCcyObj.hpp>
#include <cfintobj/ICFIntISOCcyEditObj.hpp>
#include <cfsecobj/ICFSecISOCcyObj.hpp>
#include <cfsecobj/ICFSecISOCcyEditObj.hpp>
#include <cfsecobj/ICFSecISOCcyTableObj.hpp>

namespace cfint {

	class ICFIntISOCcyTableObj
	: public virtual cfsec::ICFSecISOCcyTableObj
	{
	public:
		ICFIntISOCcyTableObj();
		virtual ~ICFIntISOCcyTableObj();
		virtual cfsec::ICFSecISOCcyObj* newInstance() = 0;

		virtual cfsec::ICFSecISOCcyEditObj* newEditInstance( cfsec::ICFSecISOCcyObj* orig ) = 0;

		virtual cfsec::ICFSecISOCcyObj* realizeISOCcy( cfsec::ICFSecISOCcyObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int16_t ISOCcyId ) = 0;
		virtual void deepDisposeByCcyCdIdx( const std::string& ISOCode ) = 0;
		virtual void deepDisposeByCcyNmIdx( const std::string& Name ) = 0;
		virtual void reallyDeepDisposeISOCcy( cfsec::ICFSecISOCcyObj* Obj ) = 0;
		virtual cfsec::ICFSecISOCcyObj* createISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readISOCcy( cfsec::CFSecISOCcyPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* lockISOCcy( cfsec::CFSecISOCcyPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecISOCcyObj*> readAllISOCcy( bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readISOCcyByIdIdx( const int16_t ISOCcyId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readISOCcyByCcyCdIdx(const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readISOCcyByCcyNmIdx(const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readCachedISOCcy( cfsec::CFSecISOCcyPKey* pkey ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readCachedISOCcyByIdIdx(const int16_t ISOCcyId ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readCachedISOCcyByCcyCdIdx(const std::string& ISOCode ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readCachedISOCcyByCcyNmIdx(const std::string& Name ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readISOCcyByLookupCcyCdIdx(const std::string& ISOCode,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecISOCcyObj* readCachedISOCcyByLookupCcyCdIdx(const std::string& ISOCode ) = 0;

		virtual cfsec::ICFSecISOCcyObj* updateISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) = 0;

		virtual void deleteISOCcy( cfsec::ICFSecISOCcyEditObj* Obj ) = 0;

		virtual void deleteISOCcyByIdIdx( const int16_t ISOCcyId ) = 0;

		virtual void deleteISOCcyByCcyCdIdx(const std::string& ISOCode ) = 0;

		virtual void deleteISOCcyByCcyNmIdx(const std::string& Name ) = 0;

		virtual void reallyDetachFromIndexesISOCcy( cfsec::ICFSecISOCcyObj* Obj ) = 0;

	};
}
