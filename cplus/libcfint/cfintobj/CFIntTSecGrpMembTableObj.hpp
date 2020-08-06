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

#include <cfintobj/ICFIntTSecGrpMembObj.hpp>
#include <cfintobj/ICFIntTSecGrpMembEditObj.hpp>
#include <cfintobj/ICFIntTSecGrpMembTableObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembEditObj.hpp>
#include <cfsecobj/ICFSecTSecGrpMembTableObj.hpp>
#include <cfsecobj/CFSecTSecGrpMembObj.hpp>
#include <cfsecobj/CFSecTSecGrpMembEditObj.hpp>
#include <cfsecobj/CFSecTSecGrpMembTableObj.hpp>

namespace cfint {

	class CFIntTSecGrpMembTableObj
	: public virtual ICFIntTSecGrpMembTableObj,
	  public virtual cfsec::ICFSecTSecGrpMembTableObj
	{
	protected:
		cfint::ICFIntSchemaObj* schema;
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* members;
		std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>* allTSecGrpMemb;
		std::map< cfsec::CFSecTSecGrpMembByTenantIdxKey,
			std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>* indexByTenantIdx;
		std::map< cfsec::CFSecTSecGrpMembByGroupIdxKey,
			std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>* indexByGroupIdx;
		std::map< cfsec::CFSecTSecGrpMembByUserIdxKey,
			std::map<cfsec::CFSecTSecGrpMembPKey, cfsec::ICFSecTSecGrpMembObj*>*>* indexByUserIdx;
		std::map< cfsec::CFSecTSecGrpMembByUUserIdxKey,
			cfsec::ICFSecTSecGrpMembObj*>* indexByUUserIdx;

	public:
		static const std::string CLASS_NAME;
		static const std::string TABLE_NAME;
		static const std::string TABLE_DBNAME;

		CFIntTSecGrpMembTableObj();
		CFIntTSecGrpMembTableObj( cfsec::ICFSecSchemaObj* argSchema );
		virtual ~CFIntTSecGrpMembTableObj();
		virtual cfsec::ICFSecSchemaObj* getSchema();
		virtual void setSchema( cfsec::ICFSecSchemaObj* value );
		virtual const std::string getTableName();
		virtual const std::string getTableDbName();
		virtual const classcode_t* getObjQualifyingClassCode();

		virtual void minimizeMemory();

		virtual cfsec::ICFSecTSecGrpMembObj* newInstance();

		virtual cfsec::ICFSecTSecGrpMembEditObj* newEditInstance( cfsec::ICFSecTSecGrpMembObj* orig );

		virtual cfsec::ICFSecTSecGrpMembObj* realizeTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj );

		virtual void deepDisposeByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId );
		virtual void deepDisposeByTenantIdx( const int64_t TenantId );
		virtual void deepDisposeByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId );
		virtual void deepDisposeByUserIdx( const uuid_ptr_t SecUserId );
		virtual void deepDisposeByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId );
		virtual void reallyDeepDisposeTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj );
		virtual cfsec::ICFSecTSecGrpMembObj* createTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj );

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey, bool forceRead = false );

		virtual cfsec::ICFSecTSecGrpMembObj* lockTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readAllTSecGrpMemb( bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageAllTSecGrpMemb(const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId );

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId, bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByTenantIdx( const int64_t TenantId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			bool forceRead = false );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false );

		virtual cfsec::ICFSecTSecGrpMembObj* readTSecGrpMembByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId, bool forceRead = false );

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMemb( cfsec::CFSecTSecGrpMembPKey* pkey );

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByTenantIdx( const int64_t TenantId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> readCachedTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId );

		virtual cfsec::ICFSecTSecGrpMembObj* readCachedTSecGrpMembByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByTenantIdx( const int64_t TenantId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId );

		virtual std::vector<cfsec::ICFSecTSecGrpMembObj*> pageTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId,
			const int64_t* priorTenantId,
			const int64_t* priorTSecGrpMembId );

		virtual cfsec::ICFSecTSecGrpMembObj* updateTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj );

		virtual void deleteTSecGrpMemb( cfsec::ICFSecTSecGrpMembEditObj* Obj );

		virtual void deleteTSecGrpMembByIdIdx( const int64_t TenantId,
			const int64_t TSecGrpMembId );

		virtual void deleteTSecGrpMembByTenantIdx( const int64_t TenantId );

		virtual void deleteTSecGrpMembByGroupIdx( const int64_t TenantId,
			const int32_t TSecGroupId );

		virtual void deleteTSecGrpMembByUserIdx( const uuid_ptr_t SecUserId );

		virtual void deleteTSecGrpMembByUUserIdx( const int64_t TenantId,
			const int32_t TSecGroupId,
			const uuid_ptr_t SecUserId );

		virtual void reallyDetachFromIndexesTSecGrpMemb( cfsec::ICFSecTSecGrpMembObj* Obj );

	};

}
