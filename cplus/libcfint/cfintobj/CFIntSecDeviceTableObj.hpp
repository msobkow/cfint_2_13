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

#include <cfintobj/ICFIntSecDeviceObj.hpp>
#include <cfintobj/ICFIntSecDeviceEditObj.hpp>
#include <cfintobj/ICFIntSecDeviceTableObj.hpp>
#include <cfsecobj/ICFSecSecDeviceObj.hpp>
#include <cfsecobj/ICFSecSecDeviceEditObj.hpp>
#include <cfsecobj/ICFSecSecDeviceTableObj.hpp>
#include <cfsecobj/CFSecSecDeviceObj.hpp>
#include <cfsecobj/CFSecSecDeviceEditObj.hpp>
#include <cfsecobj/CFSecSecDeviceTableObj.hpp>

namespace cfint {

	class CFIntSecDeviceTableObj
	: public virtual ICFIntSecDeviceTableObj,
	  public virtual cfsec::ICFSecSecDeviceTableObj
	{
	protected:
		cfint::ICFIntSchemaObj* schema;
		std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* members;
		std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>* allSecDevice;
		std::map< cfsec::CFSecSecDeviceByNameIdxKey,
			cfsec::ICFSecSecDeviceObj*>* indexByNameIdx;
		std::map< cfsec::CFSecSecDeviceByUserIdxKey,
			std::map<cfsec::CFSecSecDevicePKey, cfsec::ICFSecSecDeviceObj*>*>* indexByUserIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFIntSecDeviceTableObj();
		CFIntSecDeviceTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFIntSecDeviceTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecDeviceObj* newInstance();

		virtual cfsec::ICFSecSecDeviceEditObj* newEditInstance( cfsec::ICFSecSecDeviceObj* orig );

		virtual cfsec::ICFSecSecDeviceObj* realizeSecDevice( cfsec::ICFSecSecDeviceObj* Obj );

		virtual void deepDisposeByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );
		virtual void deepDisposeByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );
		virtual void deepDisposeByUserIdx( const uuid_ptr_t SecUserId );
		virtual void reallyDeepDisposeSecDevice( cfsec::ICFSecSecDeviceObj* Obj );
		virtual cfsec::ICFSecSecDeviceObj* createSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj );

		virtual cfsec::ICFSecSecDeviceObj* readSecDevice( cfsec::CFSecSecDevicePKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecDeviceObj* lockSecDevice( cfsec::CFSecSecDevicePKey* pkey );

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readAllSecDevice( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> pageAllSecDevice(const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName );

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName, bool forceRead = false );

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readSecDeviceByUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false );

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDevice( cfsec::CFSecSecDevicePKey* pkey );

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> readCachedSecDeviceByUserIdx( const uuid_ptr_t SecUserId );

		virtual cfsec::ICFSecSecDeviceObj* readSecDeviceByLookupNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName, bool forceRead = false );

		virtual cfsec::ICFSecSecDeviceObj* readCachedSecDeviceByLookupNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual std::vector<cfsec::ICFSecSecDeviceObj*> pageSecDeviceByUserIdx( const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecUserId,
			const std::string* priorDevName );

		virtual cfsec::ICFSecSecDeviceObj* updateSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj );

		virtual void deleteSecDevice( cfsec::ICFSecSecDeviceEditObj* Obj );

		virtual void deleteSecDeviceByIdIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual void deleteSecDeviceByNameIdx( const uuid_ptr_t SecUserId,
			const std::string& DevName );

		virtual void deleteSecDeviceByUserIdx( const uuid_ptr_t SecUserId );

		virtual void reallyDetachFromIndexesSecDevice( cfsec::ICFSecSecDeviceObj* Obj );

	};

}
