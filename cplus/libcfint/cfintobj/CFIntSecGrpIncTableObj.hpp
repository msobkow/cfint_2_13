#pragma once

// Description: C++18 Table Object specification for CFInt.

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

#include <cfintobj/ICFIntSecGrpIncObj.hpp>
#include <cfintobj/ICFIntSecGrpIncEditObj.hpp>
#include <cfintobj/ICFIntSecGrpIncTableObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncEditObj.hpp>
#include <cfsecobj/ICFSecSecGrpIncTableObj.hpp>
#include <cfsecobj/CFSecSecGrpIncObj.hpp>
#include <cfsecobj/CFSecSecGrpIncEditObj.hpp>
#include <cfsecobj/CFSecSecGrpIncTableObj.hpp>

namespace cfint {

	class CFIntSecGrpIncTableObj
	: public virtual ICFIntSecGrpIncTableObj,
	  public virtual cfsec::ICFSecSecGrpIncTableObj
	{
	protected:
		cfint::ICFIntSchemaObj* schema;
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* members;
		std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>* allSecGrpInc;
		std::map< cfsec::CFSecSecGrpIncByClusterIdxKey,
			std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>* indexByClusterIdx;
		std::map< cfsec::CFSecSecGrpIncByGroupIdxKey,
			std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>* indexByGroupIdx;
		std::map< cfsec::CFSecSecGrpIncByIncludeIdxKey,
			std::map<cfsec::CFSecSecGrpIncPKey, cfsec::ICFSecSecGrpIncObj*>*>* indexByIncludeIdx;
		std::map< cfsec::CFSecSecGrpIncByUIncludeIdxKey,
			cfsec::ICFSecSecGrpIncObj*>* indexByUIncludeIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFIntSecGrpIncTableObj();
		CFIntSecGrpIncTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFIntSecGrpIncTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecSecGrpIncObj* newInstance();

		virtual cfsec::ICFSecSecGrpIncEditObj* newEditInstance( cfsec::ICFSecSecGrpIncObj* orig );

		virtual cfsec::ICFSecSecGrpIncObj* realizeSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId );
		virtual void deepDisposeByClusterIdx( const int64_t ClusterId );
		virtual void deepDisposeByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );
		virtual void deepDisposeByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId );
		virtual void deepDisposeByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId );
		virtual void reallyDeepDisposeSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj );
		virtual cfsec::ICFSecSecGrpIncObj* createSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj );

		virtual cfsec::ICFSecSecGrpIncObj* readSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecSecGrpIncObj* lockSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey );

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readAllSecGrpInc( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageAllSecGrpInc(const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId );

		virtual cfsec::ICFSecSecGrpIncObj* readSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readSecGrpIncByClusterIdx( const int64_t ClusterId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId,
			bool forceRead = false );

		virtual cfsec::ICFSecSecGrpIncObj* readSecGrpIncByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId, bool forceRead = false );

		virtual cfsec::ICFSecSecGrpIncObj* readCachedSecGrpInc( cfsec::CFSecSecGrpIncPKey* pkey );

		virtual cfsec::ICFSecSecGrpIncObj* readCachedSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId );

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readCachedSecGrpIncByClusterIdx( const int64_t ClusterId );

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readCachedSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> readCachedSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId );

		virtual cfsec::ICFSecSecGrpIncObj* readCachedSecGrpIncByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId );

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageSecGrpIncByClusterIdx( const int64_t ClusterId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId );

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId );

		virtual std::vector<cfsec::ICFSecSecGrpIncObj*> pageSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId,
			const int64_t* priorClusterId,
			const int64_t* priorSecGrpIncId );

		virtual cfsec::ICFSecSecGrpIncObj* updateSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj );

		virtual void deleteSecGrpInc( cfsec::ICFSecSecGrpIncEditObj* Obj );

		virtual void deleteSecGrpIncByIdIdx( const int64_t ClusterId,
			const int64_t SecGrpIncId );

		virtual void deleteSecGrpIncByClusterIdx( const int64_t ClusterId );

		virtual void deleteSecGrpIncByGroupIdx( const int64_t ClusterId,
			const int32_t SecGroupId );

		virtual void deleteSecGrpIncByIncludeIdx( const int64_t ClusterId,
			const int32_t IncludeGroupId );

		virtual void deleteSecGrpIncByUIncludeIdx( const int64_t ClusterId,
			const int32_t SecGroupId,
			const int32_t IncludeGroupId );

		virtual void reallyDetachFromIndexesSecGrpInc( cfsec::ICFSecSecGrpIncObj* Obj );

	};

}
