#pragma once

// Description: C++18 Table Object specification for CFInt.

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
}

namespace cfsec {
	class ICFSecClusterObj;
	class ICFSecClusterEditObj;
	class ICFSecClusterTableObj;
}

namespace cfint { 
	class ICFIntClusterObj;
	class ICFIntClusterEditObj;
	class ICFIntClusterTableObj;
}

namespace cfsec {
	class ICFSecHostNodeObj;
	class ICFSecHostNodeEditObj;
	class ICFSecHostNodeTableObj;
}

namespace cfint { 
	class ICFIntHostNodeObj;
	class ICFIntHostNodeEditObj;
	class ICFIntHostNodeTableObj;
}

namespace cfsec {
	class ICFSecISOCcyObj;
	class ICFSecISOCcyEditObj;
	class ICFSecISOCcyTableObj;
}

namespace cfint { 
	class ICFIntISOCcyObj;
	class ICFIntISOCcyEditObj;
	class ICFIntISOCcyTableObj;
}

namespace cfsec {
	class ICFSecISOCtryObj;
	class ICFSecISOCtryEditObj;
	class ICFSecISOCtryTableObj;
}

namespace cfint { 
	class ICFIntISOCtryObj;
	class ICFIntISOCtryEditObj;
	class ICFIntISOCtryTableObj;
}

namespace cfsec {
	class ICFSecISOCtryCcyObj;
	class ICFSecISOCtryCcyEditObj;
	class ICFSecISOCtryCcyTableObj;
}

namespace cfint { 
	class ICFIntISOCtryCcyObj;
	class ICFIntISOCtryCcyEditObj;
	class ICFIntISOCtryCcyTableObj;
}

namespace cfsec {
	class ICFSecISOCtryLangObj;
	class ICFSecISOCtryLangEditObj;
	class ICFSecISOCtryLangTableObj;
}

namespace cfint { 
	class ICFIntISOCtryLangObj;
	class ICFIntISOCtryLangEditObj;
	class ICFIntISOCtryLangTableObj;
}

namespace cfsec {
	class ICFSecISOLangObj;
	class ICFSecISOLangEditObj;
	class ICFSecISOLangTableObj;
}

namespace cfint { 
	class ICFIntISOLangObj;
	class ICFIntISOLangEditObj;
	class ICFIntISOLangTableObj;
}

namespace cfsec {
	class ICFSecISOTZoneObj;
	class ICFSecISOTZoneEditObj;
	class ICFSecISOTZoneTableObj;
}

namespace cfint { 
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
}

namespace cfsec {
	class ICFSecSecAppObj;
	class ICFSecSecAppEditObj;
	class ICFSecSecAppTableObj;
}

namespace cfint { 
	class ICFIntSecAppObj;
	class ICFIntSecAppEditObj;
	class ICFIntSecAppTableObj;
}

namespace cfsec {
	class ICFSecSecDeviceObj;
	class ICFSecSecDeviceEditObj;
	class ICFSecSecDeviceTableObj;
}

namespace cfint { 
	class ICFIntSecDeviceObj;
	class ICFIntSecDeviceEditObj;
	class ICFIntSecDeviceTableObj;
}

namespace cfsec {
	class ICFSecSecFormObj;
	class ICFSecSecFormEditObj;
	class ICFSecSecFormTableObj;
}

namespace cfint { 
	class ICFIntSecFormObj;
	class ICFIntSecFormEditObj;
	class ICFIntSecFormTableObj;
}

namespace cfsec {
	class ICFSecSecGroupObj;
	class ICFSecSecGroupEditObj;
	class ICFSecSecGroupTableObj;
}

namespace cfint { 
	class ICFIntSecGroupObj;
	class ICFIntSecGroupEditObj;
	class ICFIntSecGroupTableObj;
}

namespace cfsec {
	class ICFSecSecGroupFormObj;
	class ICFSecSecGroupFormEditObj;
	class ICFSecSecGroupFormTableObj;
}

namespace cfint { 
	class ICFIntSecGroupFormObj;
	class ICFIntSecGroupFormEditObj;
	class ICFIntSecGroupFormTableObj;
}

namespace cfsec {
	class ICFSecSecGrpIncObj;
	class ICFSecSecGrpIncEditObj;
	class ICFSecSecGrpIncTableObj;
}

namespace cfint { 
	class ICFIntSecGrpIncObj;
	class ICFIntSecGrpIncEditObj;
	class ICFIntSecGrpIncTableObj;
}

namespace cfsec {
	class ICFSecSecGrpMembObj;
	class ICFSecSecGrpMembEditObj;
	class ICFSecSecGrpMembTableObj;
}

namespace cfint { 
	class ICFIntSecGrpMembObj;
	class ICFIntSecGrpMembEditObj;
	class ICFIntSecGrpMembTableObj;
}

namespace cfsec {
	class ICFSecSecSessionObj;
	class ICFSecSecSessionEditObj;
	class ICFSecSecSessionTableObj;
}

namespace cfint { 
	class ICFIntSecSessionObj;
	class ICFIntSecSessionEditObj;
	class ICFIntSecSessionTableObj;
}

namespace cfsec {
	class ICFSecSecUserObj;
	class ICFSecSecUserEditObj;
	class ICFSecSecUserTableObj;
}

namespace cfint { 
	class ICFIntSecUserObj;
	class ICFIntSecUserEditObj;
	class ICFIntSecUserTableObj;
}

namespace cfsec {
	class ICFSecServiceObj;
	class ICFSecServiceEditObj;
	class ICFSecServiceTableObj;
}

namespace cfint { 
	class ICFIntServiceObj;
	class ICFIntServiceEditObj;
	class ICFIntServiceTableObj;
}

namespace cfsec {
	class ICFSecServiceTypeObj;
	class ICFSecServiceTypeEditObj;
	class ICFSecServiceTypeTableObj;
}

namespace cfint { 
	class ICFIntServiceTypeObj;
	class ICFIntServiceTypeEditObj;
	class ICFIntServiceTypeTableObj;
	class ICFIntSubProjectObj;
	class ICFIntSubProjectEditObj;
	class ICFIntSubProjectTableObj;
}

namespace cfsec {
	class ICFSecSysClusterObj;
	class ICFSecSysClusterEditObj;
	class ICFSecSysClusterTableObj;
}

namespace cfint { 
	class ICFIntSysClusterObj;
	class ICFIntSysClusterEditObj;
	class ICFIntSysClusterTableObj;
}

namespace cfsec {
	class ICFSecTSecGroupObj;
	class ICFSecTSecGroupEditObj;
	class ICFSecTSecGroupTableObj;
}

namespace cfint { 
	class ICFIntTSecGroupObj;
	class ICFIntTSecGroupEditObj;
	class ICFIntTSecGroupTableObj;
}

namespace cfsec {
	class ICFSecTSecGrpIncObj;
	class ICFSecTSecGrpIncEditObj;
	class ICFSecTSecGrpIncTableObj;
}

namespace cfint { 
	class ICFIntTSecGrpIncObj;
	class ICFIntTSecGrpIncEditObj;
	class ICFIntTSecGrpIncTableObj;
}

namespace cfsec {
	class ICFSecTSecGrpMembObj;
	class ICFSecTSecGrpMembEditObj;
	class ICFSecTSecGrpMembTableObj;
}

namespace cfint { 
	class ICFIntTSecGrpMembObj;
	class ICFIntTSecGrpMembEditObj;
	class ICFIntTSecGrpMembTableObj;
}

namespace cfsec {
	class ICFSecTenantObj;
	class ICFSecTenantEditObj;
	class ICFSecTenantTableObj;
}

namespace cfint { 
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
#include <cfintobj/ICFIntMinorVersionTableObj.hpp>

namespace cfint {

	class CFIntMinorVersionTableObj
	: public virtual ICFIntMinorVersionTableObj
	{
	protected:
		cfint::ICFIntSchemaObj* schema;
		std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* members;
		std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>* allMinorVersion;
		std::map< cfint::CFIntMinorVersionByTenantIdxKey,
			std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>*>* indexByTenantIdx;
		std::map< cfint::CFIntMinorVersionByMajorVerIdxKey,
			std::map<cfint::CFIntMinorVersionPKey, cfint::ICFIntMinorVersionObj*>*>* indexByMajorVerIdx;
		std::map< cfint::CFIntMinorVersionByNameIdxKey,
			cfint::ICFIntMinorVersionObj*>* indexByNameIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFIntMinorVersionTableObj();
		CFIntMinorVersionTableObj( cfint::ICFIntSchemaObj* argSchema );
		virtual ~CFIntMinorVersionTableObj();
		virtual cfint::ICFIntSchemaObj* getSchema();
		virtual void setSchema( cfint::ICFIntSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfint::ICFIntMinorVersionObj* newInstance();

		virtual cfint::ICFIntMinorVersionEditObj* newEditInstance( cfint::ICFIntMinorVersionObj* orig );

		virtual cfint::ICFIntMinorVersionObj* realizeMinorVersion( cfint::ICFIntMinorVersionObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id );
		virtual void deepDisposeByTenantIdx( const int64_t TenantId );
		virtual void deepDisposeByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId );
		virtual void deepDisposeByNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name );
		virtual void reallyDeepDisposeMinorVersion( cfint::ICFIntMinorVersionObj* Obj );
		virtual cfint::ICFIntMinorVersionObj* createMinorVersion( cfint::ICFIntMinorVersionEditObj* Obj );

		virtual cfint::ICFIntMinorVersionObj* readMinorVersion( cfint::CFIntMinorVersionPKey* pkey, bool forceRead = false );

		virtual cfint::ICFIntMinorVersionObj* lockMinorVersion( cfint::CFIntMinorVersionPKey* pkey );

		virtual std::vector<cfint::ICFIntMinorVersionObj*> readAllMinorVersion( bool forceRead = false );

		virtual cfint::ICFIntMinorVersionObj* readMinorVersionByIdIdx( const int64_t TenantId,
			const int64_t Id, bool forceRead = false );

		virtual std::vector<cfint::ICFIntMinorVersionObj*> readMinorVersionByTenantIdx( const int64_t TenantId,
			bool forceRead = false );

		virtual std::vector<cfint::ICFIntMinorVersionObj*> readMinorVersionByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			bool forceRead = false );

		virtual cfint::ICFIntMinorVersionObj* readMinorVersionByNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name, bool forceRead = false );

		virtual cfint::ICFIntMinorVersionObj* readCachedMinorVersion( cfint::CFIntMinorVersionPKey* pkey );

		virtual cfint::ICFIntMinorVersionObj* readCachedMinorVersionByIdIdx( const int64_t TenantId,
			const int64_t Id );

		virtual std::vector<cfint::ICFIntMinorVersionObj*> readCachedMinorVersionByTenantIdx( const int64_t TenantId );

		virtual std::vector<cfint::ICFIntMinorVersionObj*> readCachedMinorVersionByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId );

		virtual cfint::ICFIntMinorVersionObj* readCachedMinorVersionByNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name );

		virtual cfint::ICFIntMinorVersionObj* readMinorVersionByLookupNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name, bool forceRead = false );

		virtual cfint::ICFIntMinorVersionObj* readCachedMinorVersionByLookupNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name );

		virtual cfint::ICFIntMinorVersionObj* updateMinorVersion( cfint::ICFIntMinorVersionEditObj* Obj );

		virtual void deleteMinorVersion( cfint::ICFIntMinorVersionEditObj* Obj );

		virtual void deleteMinorVersionByIdIdx( const int64_t TenantId,
			const int64_t Id );

		virtual void deleteMinorVersionByTenantIdx( const int64_t TenantId );

		virtual void deleteMinorVersionByMajorVerIdx( const int64_t TenantId,
			const int64_t MajorVersionId );

		virtual void deleteMinorVersionByNameIdx( const int64_t TenantId,
			const int64_t MajorVersionId,
			const std::string& Name );

		virtual void reallyDetachFromIndexesMinorVersion( cfint::ICFIntMinorVersionObj* Obj );

	};

}
