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

#include <cfintobj/ICFIntServiceObj.hpp>
#include <cfintobj/ICFIntServiceEditObj.hpp>
#include <cfintobj/ICFIntServiceTableObj.hpp>
#include <cfsecobj/ICFSecServiceObj.hpp>
#include <cfsecobj/ICFSecServiceEditObj.hpp>
#include <cfsecobj/ICFSecServiceTableObj.hpp>
#include <cfsecobj/CFSecServiceObj.hpp>
#include <cfsecobj/CFSecServiceEditObj.hpp>
#include <cfsecobj/CFSecServiceTableObj.hpp>

namespace cfint {

	class CFIntServiceTableObj
	: public virtual ICFIntServiceTableObj,
	  public virtual cfsec::ICFSecServiceTableObj
	{
	protected:
		cfint::ICFIntSchemaObj* schema;
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* members;
		std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>* allService;
		std::map< cfsec::CFSecServiceByClusterIdxKey,
			std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecServiceByHostIdxKey,
			std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>* indexByHostIdx;
		std::map< cfsec::CFSecServiceByTypeIdxKey,
			std::map<cfsec::CFSecServicePKey, cfsec::ICFSecServiceObj*>*>* indexByTypeIdx;
		std::map< cfsec::CFSecServiceByUTypeIdxKey,
			cfsec::ICFSecServiceObj*>* indexByUTypeIdx;
		std::map< cfsec::CFSecServiceByUHostPortIdxKey,
			cfsec::ICFSecServiceObj*>* indexByUHostPortIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFIntServiceTableObj();
		CFIntServiceTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFIntServiceTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecServiceObj* newInstance();

		virtual cfsec::ICFSecServiceEditObj* newEditInstance( cfsec::ICFSecServiceObj* orig );

		virtual cfsec::ICFSecServiceObj* realizeService( cfsec::ICFSecServiceObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId );
		virtual void deepDisposeByTypeIdx( const int32_t ServiceTypeId );
		virtual void deepDisposeByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId );
		virtual void deepDisposeByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort );
		virtual void reallyDeepDisposeService( cfsec::ICFSecServiceObj* Obj );
		virtual cfsec::ICFSecServiceObj* createService( cfsec::ICFSecServiceEditObj* Obj );

		virtual cfsec::ICFSecServiceObj* readService( cfsec::CFSecServicePKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecServiceObj* lockService( cfsec::CFSecServicePKey* pkey );

		virtual std::vector<cfsec::ICFSecServiceObj*> readAllService( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecServiceObj*> pageAllService(const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual cfsec::ICFSecServiceObj* readServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecServiceObj*> readServiceByTypeIdx( const int32_t ServiceTypeId,
			bool forceRead = false );

		virtual cfsec::ICFSecServiceObj* readServiceByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId, bool forceRead = false );

		virtual cfsec::ICFSecServiceObj* readServiceByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort, bool forceRead = false );

		virtual cfsec::ICFSecServiceObj* readCachedService( cfsec::CFSecServicePKey* pkey );

		virtual cfsec::ICFSecServiceObj* readCachedServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId );

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByClusterIdx( const int64_t ClusterId );

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId );

		virtual std::vector<cfsec::ICFSecServiceObj*> readCachedServiceByTypeIdx( const int32_t ServiceTypeId );

		virtual cfsec::ICFSecServiceObj* readCachedServiceByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId );

		virtual cfsec::ICFSecServiceObj* readCachedServiceByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort );

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual std::vector<cfsec::ICFSecServiceObj*> pageServiceByTypeIdx( const int32_t ServiceTypeId,
			const int64_t* priorClusterId,
			const int64_t* priorServiceId );

		virtual cfsec::ICFSecServiceObj* updateService( cfsec::ICFSecServiceEditObj* Obj );

		virtual void deleteService( cfsec::ICFSecServiceEditObj* Obj );

		virtual void deleteServiceByIdIdx( const int64_t ClusterId,
			const int64_t ServiceId );

		virtual void deleteServiceByClusterIdx( const int64_t ClusterId );

		virtual void deleteServiceByHostIdx( const int64_t ClusterId,
			const int64_t HostNodeId );

		virtual void deleteServiceByTypeIdx( const int32_t ServiceTypeId );

		virtual void deleteServiceByUTypeIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int32_t ServiceTypeId );

		virtual void deleteServiceByUHostPortIdx( const int64_t ClusterId,
			const int64_t HostNodeId,
			const int16_t HostPort );

		virtual void reallyDetachFromIndexesService( cfsec::ICFSecServiceObj* Obj );

	};

}
