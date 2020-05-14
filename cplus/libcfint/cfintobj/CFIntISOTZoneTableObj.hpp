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

#include <cfintobj/ICFIntISOTZoneObj.hpp>
#include <cfintobj/ICFIntISOTZoneEditObj.hpp>
#include <cfintobj/ICFIntISOTZoneTableObj.hpp>
#include <cfsecobj/ICFSecISOTZoneObj.hpp>
#include <cfsecobj/ICFSecISOTZoneEditObj.hpp>
#include <cfsecobj/ICFSecISOTZoneTableObj.hpp>
#include <cfsecobj/CFSecISOTZoneObj.hpp>
#include <cfsecobj/CFSecISOTZoneEditObj.hpp>
#include <cfsecobj/CFSecISOTZoneTableObj.hpp>

namespace cfint {

	class CFIntISOTZoneTableObj
	: public virtual ICFIntISOTZoneTableObj,
	  public virtual cfsec::ICFSecISOTZoneTableObj
	{
	protected:
		cfint::ICFIntSchemaObj* schema;
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* members;
		std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>* allISOTZone;
		std::map< cfsec::CFSecISOTZoneByOffsetIdxKey,
			std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>* indexByOffsetIdx;
		std::map< cfsec::CFSecISOTZoneByUTZNameIdxKey,
			cfsec::ICFSecISOTZoneObj*>* indexByUTZNameIdx;
		std::map< cfsec::CFSecISOTZoneByIso8601IdxKey,
			std::map<cfsec::CFSecISOTZonePKey, cfsec::ICFSecISOTZoneObj*>*>* indexByIso8601Idx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFIntISOTZoneTableObj();
		CFIntISOTZoneTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFIntISOTZoneTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecISOTZoneObj* newInstance();

		virtual cfsec::ICFSecISOTZoneEditObj* newEditInstance( cfsec::ICFSecISOTZoneObj* orig );

		virtual cfsec::ICFSecISOTZoneObj* realizeISOTZone( cfsec::ICFSecISOTZoneObj* Obj );

		virtual void deepDisposeByIdIdx( const int16_t ISOTZoneId );
		virtual void deepDisposeByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset );
		virtual void deepDisposeByUTZNameIdx( const std::string& TZName );
		virtual void deepDisposeByIso8601Idx( const std::string& Iso8601 );
		virtual void reallyDeepDisposeISOTZone( cfsec::ICFSecISOTZoneObj* Obj );
		virtual cfsec::ICFSecISOTZoneObj* createISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj );

		virtual cfsec::ICFSecISOTZoneObj* readISOTZone( cfsec::CFSecISOTZonePKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecISOTZoneObj* lockISOTZone( cfsec::CFSecISOTZonePKey* pkey );

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readAllISOTZone( bool forceRead = false );

		virtual cfsec::ICFSecISOTZoneObj* readISOTZoneByIdIdx( const int16_t ISOTZoneId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset,
			bool forceRead = false );

		virtual cfsec::ICFSecISOTZoneObj* readISOTZoneByUTZNameIdx( const std::string& TZName, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readISOTZoneByIso8601Idx( const std::string& Iso8601,
			bool forceRead = false );

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZone( cfsec::CFSecISOTZonePKey* pkey );

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZoneByIdIdx( const int16_t ISOTZoneId );

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readCachedISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset );

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZoneByUTZNameIdx( const std::string& TZName );

		virtual std::vector<cfsec::ICFSecISOTZoneObj*> readCachedISOTZoneByIso8601Idx( const std::string& Iso8601 );

		virtual cfsec::ICFSecISOTZoneObj* readISOTZoneByLookupUTZNameIdx( const std::string& TZName, bool forceRead = false );

		virtual cfsec::ICFSecISOTZoneObj* readCachedISOTZoneByLookupUTZNameIdx( const std::string& TZName );

		virtual cfsec::ICFSecISOTZoneObj* updateISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj );

		virtual void deleteISOTZone( cfsec::ICFSecISOTZoneEditObj* Obj );

		virtual void deleteISOTZoneByIdIdx( const int16_t ISOTZoneId );

		virtual void deleteISOTZoneByOffsetIdx( const int16_t TZHourOffset,
			const int16_t TZMinOffset );

		virtual void deleteISOTZoneByUTZNameIdx( const std::string& TZName );

		virtual void deleteISOTZoneByIso8601Idx( const std::string& Iso8601 );

		virtual void reallyDetachFromIndexesISOTZone( cfsec::ICFSecISOTZoneObj* Obj );

	};

}