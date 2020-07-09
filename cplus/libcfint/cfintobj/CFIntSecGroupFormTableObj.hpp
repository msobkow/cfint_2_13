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

#include <cfintobj/ICFIntSecGroupFormObj.hpp>
#include <cfintobj/ICFIntSecGroupFormEditObj.hpp>
#include <cfintobj/ICFIntSecGroupFormTableObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormEditObj.hpp>
#include <cfsecobj/ICFSecSecGroupFormTableObj.hpp>
#include <cfsecobj/CFSecSecGroupFormObj.hpp>
#include <cfsecobj/CFSecSecGroupFormEditObj.hpp>
#include <cfsecobj/CFSecSecGroupFormTableObj.hpp>

namespace cfint {

	class CFIntSecGroupFormTableObj
	: public virtual ICFIntSecGroupFormTableObj,
	  public virtual cfsec::ICFSecSecGroupFormTableObj
	{
	protected:
		cfint::ICFIntSchemaObj* schema;
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* members;
		std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>* allSecGroupForm;
		std::map< cfsec::CFSecSecGroupFormByClusterIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecSecGroupFormByGroupIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>* indexByGroupIdx;
		std::map< cfsec::CFSecSecGroupFormByAppIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>* indexByAppIdx;
		std::map< cfsec::CFSecSecGroupFormByFormIdxKey,
			std::map<cfsec::CFSecSecGroupFormPKey, cfsec::ICFSecSecGroupFormObj*>*>* indexByFormIdx;
		std::map< cfsec::CFSecSecGroupFormByUFormIdxKey,
			cfsec::ICFSecSecGroupFormObj*>* indexByUFormIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFIntSecGroupFormTableObj();
		CFIntSecGroupFormTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFIntSecGroupFormTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecGroupFormObj* newInstance();

		virtual cfsec::ICFSecSecGroupFormEditObj* newEditInstance( cfsec::ICFSecSecGroupFormObj* orig );

		virtual cfsec::ICFSecSecGroupFormObj* realizeSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );
		virtual void deepDisposeByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId );
		virtual void deepDisposeByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId );
		virtual void deepDisposeByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId );
		virtual void reallyDeepDisposeSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj );
		virtual cfsec::ICFSecSecGroupFormObj* createSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj );

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecGroupFormObj* lockSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readAllSecGroupForm( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageAllSecGroupForm(const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId,
			bool forceRead = false );

		virtual cfsec::ICFSecSecGroupFormObj* readSecGroupFormByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId, bool forceRead = false );

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupForm( cfsec::CFSecSecGroupFormPKey* pkey );

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByClusterIdx( const int64_t ClusterId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> readCachedSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId );

		virtual cfsec::ICFSecSecGroupFormObj* readCachedSecGroupFormByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual std::vector<cfsec::ICFSecSecGroupFormObj*> pageSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGroupFormId );

		virtual cfsec::ICFSecSecGroupFormObj* updateSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj );

		virtual void deleteSecGroupForm( cfsec::ICFSecSecGroupFormEditObj* Obj );

		virtual void deleteSecGroupFormByIdIdx( const int64_t ClusterId,
			const int64_t SecGroupFormId );

		virtual void deleteSecGroupFormByClusterIdx( const int64_t ClusterId );

		virtual void deleteSecGroupFormByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual void deleteSecGroupFormByAppIdx( const int64_t ClusterId,
			const int32_t SecAppId );

		virtual void deleteSecGroupFormByFormIdx( const int64_t ClusterId,
			const int32_t SecFormId );

		virtual void deleteSecGroupFormByUFormIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t SecFormId );

		virtual void reallyDetachFromIndexesSecGroupForm( cfsec::ICFSecSecGroupFormObj* Obj );

	};

}
