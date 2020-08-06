#pragma once

// Description: C++18 Table Object interface for CFInt.

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

#include <cfintobj/ICFIntSecSessionObj.hpp>
#include <cfintobj/ICFIntSecSessionEditObj.hpp>
#include <cfsecobj/ICFSecSecSessionObj.hpp>
#include <cfsecobj/ICFSecSecSessionEditObj.hpp>
#include <cfsecobj/ICFSecSecSessionTableObj.hpp>

namespace cfint {

	class ICFIntSecSessionTableObj
	: public virtual cfsec::ICFSecSecSessionTableObj
	{
	public:
		ICFIntSecSessionTableObj();
		virtual ~ICFIntSecSessionTableObj();
		virtual cfsec::ICFSecSecSessionObj* newInstance() = 0;

		virtual cfsec::ICFSecSecSessionEditObj* newEditInstance( cfsec::ICFSecSecSessionObj* orig ) = 0;

		virtual cfsec::ICFSecSecSessionObj* realizeSecSession( cfsec::ICFSecSecSessionObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const uuid_ptr_t SecSessionId ) = 0;
		virtual void deepDisposeBySecUserIdx( const uuid_ptr_t SecUserId ) = 0;
		virtual void deepDisposeBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName ) = 0;
		virtual void deepDisposeByStartIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start ) = 0;
		virtual void deepDisposeByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish ) = 0;
		virtual void deepDisposeBySecProxyIdx( const uuid_ptr_t SecProxyId ) = 0;
		virtual void reallyDeepDisposeSecSession( cfsec::ICFSecSecSessionObj* Obj ) = 0;
		virtual cfsec::ICFSecSecSessionObj* createSecSession( cfsec::ICFSecSecSessionEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readSecSession( cfsec::CFSecSecSessionPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecSessionObj* lockSecSession( cfsec::CFSecSecSessionPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readAllSecSession( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageAllSecSession(const uuid_ptr_t priorSecSessionId ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readSecSessionByIdIdx( const uuid_ptr_t SecSessionId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionBySecUserIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readSecSessionByStartIdx(const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readCachedSecSession( cfsec::CFSecSecSessionPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readCachedSecSessionByIdIdx(const uuid_ptr_t SecSessionId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionBySecUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName ) = 0;

		virtual cfsec::ICFSecSecSessionObj* readCachedSecSessionByStartIdx(const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> readCachedSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionBySecUserIdx( const uuid_ptr_t SecUserId,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual std::vector<cfsec::ICFSecSecSessionObj*> pageSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId,
			const uuid_ptr_t priorSecSessionId ) = 0;

		virtual cfsec::ICFSecSecSessionObj* updateSecSession( cfsec::ICFSecSecSessionEditObj* Obj ) = 0;

		virtual void deleteSecSession( cfsec::ICFSecSecSessionEditObj* Obj ) = 0;

		virtual void deleteSecSessionByIdIdx( const uuid_ptr_t SecSessionId ) = 0;

		virtual void deleteSecSessionBySecUserIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual void deleteSecSessionBySecDevIdx( const uuid_ptr_t SecUserId,
			const std::string* SecDevName ) = 0;

		virtual void deleteSecSessionByStartIdx(const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point& Start ) = 0;

		virtual void deleteSecSessionByFinishIdx( const uuid_ptr_t SecUserId,
			const std::chrono::system_clock::time_point* Finish ) = 0;

		virtual void deleteSecSessionBySecProxyIdx( const uuid_ptr_t SecProxyId ) = 0;

		virtual void reallyDetachFromIndexesSecSession( cfsec::ICFSecSecSessionObj* Obj ) = 0;

	virtual cfsec::ICFSecSecSessionObj* getSystemSession() = 0;

	};
}
