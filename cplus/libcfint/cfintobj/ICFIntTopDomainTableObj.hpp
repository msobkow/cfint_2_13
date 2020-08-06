#pragma once

// Description: C++18 Table Object interface for CFInt.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
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

#include <cfintobj/ICFIntTopDomainObj.hpp>
#include <cfintobj/ICFIntTopDomainEditObj.hpp>

namespace cfint {

	class ICFIntTopDomainTableObj
	{
	public:
		ICFIntTopDomainTableObj();
		virtual ~ICFIntTopDomainTableObj();
		virtual cfint::ICFIntSchemaObj* getSchema() = 0;
		virtual void setSchema( cfint::ICFIntSchemaObj* value ) = 0;

		virtual void minimizeMemory() = 0;

		virtual const std::string getTableName() = 0;
		virtual const std::string getTableDbName() = 0;
		virtual const classcode_t* getObjQualifyingClassCode() = 0;

		virtual cfint::ICFIntTopDomainObj* newInstance() = 0;

		virtual cfint::ICFIntTopDomainEditObj* newEditInstance( cfint::ICFIntTopDomainObj* orig ) = 0;

		virtual cfint::ICFIntTopDomainObj* realizeTopDomain( cfint::ICFIntTopDomainObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id ) = 0;
		virtual void deepDisposeByTenantIdx( const int64_t TenantId ) = 0;
		virtual void deepDisposeByTldIdx( const int64_t TenantId,
			const int64_t TldId ) = 0;
		virtual void deepDisposeByNameIdx( const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name ) = 0;
		virtual void reallyDeepDisposeTopDomain( cfint::ICFIntTopDomainObj* Obj ) = 0;
		virtual cfint::ICFIntTopDomainObj* createTopDomain( cfint::ICFIntTopDomainEditObj* Obj ) = 0;

		virtual cfint::ICFIntTopDomainObj* readTopDomain( cfint::CFIntTopDomainPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntTopDomainObj* lockTopDomain( cfint::CFIntTopDomainPKey* pkey ) = 0;

		virtual std::vector<cfint::ICFIntTopDomainObj*> readAllTopDomain( bool forceRead = false ) = 0;

		virtual cfint::ICFIntTopDomainObj* readTopDomainByIdIdx( const int64_t TenantId,
			const int64_t Id,
			bool forceRead = false ) = 0;

		virtual std::vector<cfint::ICFIntTopDomainObj*> readTopDomainByTenantIdx( const int64_t TenantId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfint::ICFIntTopDomainObj*> readTopDomainByTldIdx( const int64_t TenantId,
			const int64_t TldId,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntTopDomainObj* readTopDomainByNameIdx(const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntTopDomainObj* readCachedTopDomain( cfint::CFIntTopDomainPKey* pkey ) = 0;

		virtual cfint::ICFIntTopDomainObj* readCachedTopDomainByIdIdx(const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual std::vector<cfint::ICFIntTopDomainObj*> readCachedTopDomainByTenantIdx( const int64_t TenantId ) = 0;

		virtual std::vector<cfint::ICFIntTopDomainObj*> readCachedTopDomainByTldIdx( const int64_t TenantId,
			const int64_t TldId ) = 0;

		virtual cfint::ICFIntTopDomainObj* readCachedTopDomainByNameIdx(const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name ) = 0;

		virtual cfint::ICFIntTopDomainObj* readTopDomainByLookupNameIdx(const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::ICFIntTopDomainObj* readCachedTopDomainByLookupNameIdx(const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name ) = 0;

		virtual cfint::ICFIntTopDomainObj* updateTopDomain( cfint::ICFIntTopDomainEditObj* Obj ) = 0;

		virtual void deleteTopDomain( cfint::ICFIntTopDomainEditObj* Obj ) = 0;

		virtual void deleteTopDomainByIdIdx( const int64_t TenantId,
			const int64_t Id ) = 0;

		virtual void deleteTopDomainByTenantIdx( const int64_t TenantId ) = 0;

		virtual void deleteTopDomainByTldIdx( const int64_t TenantId,
			const int64_t TldId ) = 0;

		virtual void deleteTopDomainByNameIdx(const int64_t TenantId,
			const int64_t TldId,
			const std::string& Name ) = 0;

		virtual void reallyDetachFromIndexesTopDomain( cfint::ICFIntTopDomainObj* Obj ) = 0;

	};
}
