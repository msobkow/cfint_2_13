#pragma once

// Description: C++18 Table Object specification for CFInt.

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

#include <cfintobj/ICFIntSecGroupObj.hpp>
#include <cfintobj/ICFIntSecGroupEditObj.hpp>
#include <cfintobj/ICFIntSecGroupTableObj.hpp>
#include <cfsecobj/ICFSecSecGroupObj.hpp>
#include <cfsecobj/ICFSecSecGroupEditObj.hpp>
#include <cfsecobj/ICFSecSecGroupTableObj.hpp>
#include <cfsecobj/CFSecSecGroupObj.hpp>
#include <cfsecobj/CFSecSecGroupEditObj.hpp>
#include <cfsecobj/CFSecSecGroupTableObj.hpp>

namespace cfint {

	class CFIntSecGroupTableObj
	: public virtual ICFIntSecGroupTableObj,
	  public virtual cfsec::ICFSecSecGroupTableObj
	{
	protected:
		cfint::ICFIntSchemaObj* schema;
		std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* members;
		std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>* allSecGroup;
		std::map< cfsec::CFSecSecGroupByClusterIdxKey,
			std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecSecGroupByClusterVisIdxKey,
			std::map<cfsec::CFSecSecGroupPKey, cfsec::ICFSecSecGroupObj*>*>* indexByClusterVisIdx;
		std::map< cfsec::CFSecSecGroupByUNameIdxKey,
			cfsec::ICFSecSecGroupObj*>* indexByUNameIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFIntSecGroupTableObj();
		CFIntSecGroupTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFIntSecGroupTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecGroupObj* newInstance();

		virtual cfsec::ICFSecSecGroupEditObj* newEditInstance( cfsec::ICFSecSecGroupObj* orig );

		virtual cfsec::ICFSecSecGroupObj* realizeSecGroup( cfsec::ICFSecSecGroupObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible );
		virtual void deepDisposeByUNameIdx( const int64_t ClusterId,
			const std::string& Name );
		virtual void reallyDeepDisposeSecGroup( cfsec::ICFSecSecGroupObj* Obj );
		virtual cfsec::ICFSecSecGroupObj* createSecGroup( cfsec::ICFSecSecGroupEditObj* Obj );

		virtual cfsec::ICFSecSecGroupObj* readSecGroup( cfsec::CFSecSecGroupPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecGroupObj* lockSecGroup( cfsec::CFSecSecGroupPKey* pkey );

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readAllSecGroup( bool forceRead = false );

		virtual cfsec::ICFSecSecGroupObj* readSecGroupByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readSecGroupByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible,
			bool forceRead = false );

		virtual cfsec::ICFSecSecGroupObj* readSecGroupByUNameIdx( const int64_t ClusterId,
			const std::string& Name, bool forceRead = false );

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroup( cfsec::CFSecSecGroupPKey* pkey );

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroupByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readCachedSecGroupByClusterIdx( const int64_t ClusterId );

		virtual std::vector<cfsec::ICFSecSecGroupObj*> readCachedSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible );

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroupByUNameIdx( const int64_t ClusterId,
			const std::string& Name );

		virtual cfsec::ICFSecSecGroupObj* readSecGroupByLookupUNameIdx( const int64_t ClusterId,
			const std::string& Name, bool forceRead = false );

		virtual cfsec::ICFSecSecGroupObj* readCachedSecGroupByLookupUNameIdx( const int64_t ClusterId,
			const std::string& Name );

		virtual cfsec::ICFSecSecGroupObj* updateSecGroup( cfsec::ICFSecSecGroupEditObj* Obj );

		virtual void deleteSecGroup( cfsec::ICFSecSecGroupEditObj* Obj );

		virtual void deleteSecGroupByIdIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual void deleteSecGroupByClusterIdx( const int64_t ClusterId );

		virtual void deleteSecGroupByClusterVisIdx( const int64_t ClusterId,
			const bool IsVisible );

		virtual void deleteSecGroupByUNameIdx( const int64_t ClusterId,
			const std::string& Name );

		virtual void reallyDetachFromIndexesSecGroup( cfsec::ICFSecSecGroupObj* Obj );

	};

}
