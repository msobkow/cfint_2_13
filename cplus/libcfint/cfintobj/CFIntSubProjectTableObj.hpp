#pragma once

// Description: C++18 Table Object specification for CFInt.

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

#include <cfintobj/ICFIntSubProjectObj.hpp>
#include <cfintobj/ICFIntSubProjectEditObj.hpp>
#include <cfintobj/ICFIntSubProjectTableObj.hpp>

namespace cfint {

	class CFIntSubProjectTableObj
	: public virtual ICFIntSubProjectTableObj
	{
	protected:
		cfint::ICFIntSchemaObj* schema;
		std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* members;
		std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>* allSubProject;
		std::map< cfint::CFIntSubProjectByTenantIdxKey,
			std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>*>* indexByTenantIdx;
		std::map< cfint::CFIntSubProjectByTopProjectIdxKey,
			std::map<cfint::CFIntSubProjectPKey, cfint::ICFIntSubProjectObj*>*>* indexByTopProjectIdx;
		std::map< cfint::CFIntSubProjectByNameIdxKey,
			cfint::ICFIntSubProjectObj*>* indexByNameIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFIntSubProjectTableObj();
		CFIntSubProjectTableObj( cfint::ICFIntSchemaObj* argSchema );
		virtual ~CFIntSubProjectTableObj();
		virtual cfint::ICFIntSchemaObj* getSchema();
		virtual void setSchema( cfint::ICFIntSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfint::ICFIntSubProjectObj* newInstance();

		virtual cfint::ICFIntSubProjectEditObj* newEditInstance( cfint::ICFIntSubProjectObj* orig );

		virtual cfint::ICFIntSubProjectObj* realizeSubProject( cfint::ICFIntSubProjectObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t Id );
		virtual void deepDisposeByTenantIdx( const int64_t TenantId );
		virtual void deepDisposeByTopProjectIdx( const int64_t TenantId,
			const int64_t TopProjectId );
		virtual void deepDisposeByNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name );
		virtual void reallyDeepDisposeSubProject( cfint::ICFIntSubProjectObj* Obj );
		virtual cfint::ICFIntSubProjectObj* createSubProject( cfint::ICFIntSubProjectEditObj* Obj );

		virtual cfint::ICFIntSubProjectObj* readSubProject( cfint::CFIntSubProjectPKey* pkey, bool forceRead = false );

		virtual cfint::ICFIntSubProjectObj* lockSubProject( cfint::CFIntSubProjectPKey* pkey );

		virtual std::vector<cfint::ICFIntSubProjectObj*> readAllSubProject( bool forceRead = false );

		virtual cfint::ICFIntSubProjectObj* readSubProjectByIdIdx( const int64_t TenantId,
			const int64_t Id, bool forceRead = false );

		virtual std::vector<cfint::ICFIntSubProjectObj*> readSubProjectByTenantIdx( const int64_t TenantId,
			bool forceRead = false );

		virtual std::vector<cfint::ICFIntSubProjectObj*> readSubProjectByTopProjectIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			bool forceRead = false );

		virtual cfint::ICFIntSubProjectObj* readSubProjectByNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name, bool forceRead = false );

		virtual cfint::ICFIntSubProjectObj* readCachedSubProject( cfint::CFIntSubProjectPKey* pkey );

		virtual cfint::ICFIntSubProjectObj* readCachedSubProjectByIdIdx( const int64_t TenantId,
			const int64_t Id );

		virtual std::vector<cfint::ICFIntSubProjectObj*> readCachedSubProjectByTenantIdx( const int64_t TenantId );

		virtual std::vector<cfint::ICFIntSubProjectObj*> readCachedSubProjectByTopProjectIdx( const int64_t TenantId,
			const int64_t TopProjectId );

		virtual cfint::ICFIntSubProjectObj* readCachedSubProjectByNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name );

		virtual cfint::ICFIntSubProjectObj* readSubProjectByLookupNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name, bool forceRead = false );

		virtual cfint::ICFIntSubProjectObj* readCachedSubProjectByLookupNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name );

		virtual cfint::ICFIntSubProjectObj* updateSubProject( cfint::ICFIntSubProjectEditObj* Obj );

		virtual void deleteSubProject( cfint::ICFIntSubProjectEditObj* Obj );

		virtual void deleteSubProjectByIdIdx( const int64_t TenantId,
			const int64_t Id );

		virtual void deleteSubProjectByTenantIdx( const int64_t TenantId );

		virtual void deleteSubProjectByTopProjectIdx( const int64_t TenantId,
			const int64_t TopProjectId );

		virtual void deleteSubProjectByNameIdx( const int64_t TenantId,
			const int64_t TopProjectId,
			const std::string& Name );

		virtual void reallyDetachFromIndexesSubProject( cfint::ICFIntSubProjectObj* Obj );

	};

}
