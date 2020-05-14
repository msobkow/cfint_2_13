#pragma once

// Description: C++18 Table Object interface for CFInt.

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

#include <cfintobj/ICFIntSecUserObj.hpp>
#include <cfintobj/ICFIntSecUserEditObj.hpp>
#include <cfsecobj/ICFSecSecUserObj.hpp>
#include <cfsecobj/ICFSecSecUserEditObj.hpp>
#include <cfsecobj/ICFSecSecUserTableObj.hpp>

namespace cfint {

	class ICFIntSecUserTableObj
	: public virtual cfsec::ICFSecSecUserTableObj
	{
	public:
		ICFIntSecUserTableObj();
		virtual ~ICFIntSecUserTableObj();
		virtual cfsec::ICFSecSecUserObj* newInstance() = 0;

		virtual cfsec::ICFSecSecUserEditObj* newEditInstance( cfsec::ICFSecSecUserObj* orig ) = 0;

		virtual cfsec::ICFSecSecUserObj* realizeSecUser( cfsec::ICFSecSecUserObj* Obj ) = 0;

		virtual void deepDisposeByIdIdx( const uuid_ptr_t SecUserId ) = 0;
		virtual void deepDisposeByULoginIdx( const std::string& LoginId ) = 0;
		virtual void deepDisposeByEMConfIdx( const uuid_ptr_t EMailConfirmUuid ) = 0;
		virtual void deepDisposeByPwdResetIdx( const uuid_ptr_t PasswordResetUuid ) = 0;
		virtual void deepDisposeByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName ) = 0;
		virtual void reallyDeepDisposeSecUser( cfsec::ICFSecSecUserObj* Obj ) = 0;
		virtual cfsec::ICFSecSecUserObj* createSecUser( cfsec::ICFSecSecUserEditObj* Obj ) = 0;

		virtual cfsec::ICFSecSecUserObj* readSecUser( cfsec::CFSecSecUserPKey* pkey,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecUserObj* lockSecUser( cfsec::CFSecSecUserPKey* pkey ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readAllSecUser( bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageAllSecUser(const uuid_ptr_t priorSecUserId ) = 0;

		virtual cfsec::ICFSecSecUserObj* readSecUserByIdIdx( const uuid_ptr_t SecUserId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecUserObj* readSecUserByULoginIdx(const std::string& LoginId,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid,
			bool forceRead = false ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecUserObj* readCachedSecUser( cfsec::CFSecSecUserPKey* pkey ) = 0;

		virtual cfsec::ICFSecSecUserObj* readCachedSecUserByIdIdx(const uuid_ptr_t SecUserId ) = 0;

		virtual cfsec::ICFSecSecUserObj* readCachedSecUserByULoginIdx(const std::string& LoginId ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readCachedSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readCachedSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> readCachedSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName ) = 0;

		virtual cfsec::ICFSecSecUserObj* readSecUserByLookupULoginIdx(const std::string& LoginId,
			bool forceRead = false ) = 0;

		virtual cfsec::ICFSecSecUserObj* readCachedSecUserByLookupULoginIdx(const std::string& LoginId ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid,
			const uuid_ptr_t priorSecUserId ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid,
			const uuid_ptr_t priorSecUserId ) = 0;

		virtual std::vector<cfsec::ICFSecSecUserObj*> pageSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName,
			const uuid_ptr_t priorSecUserId ) = 0;

		virtual cfsec::ICFSecSecUserObj* updateSecUser( cfsec::ICFSecSecUserEditObj* Obj ) = 0;

		virtual void deleteSecUser( cfsec::ICFSecSecUserEditObj* Obj ) = 0;

		virtual void deleteSecUserByIdIdx( const uuid_ptr_t SecUserId ) = 0;

		virtual void deleteSecUserByULoginIdx(const std::string& LoginId ) = 0;

		virtual void deleteSecUserByEMConfIdx( const uuid_ptr_t EMailConfirmUuid ) = 0;

		virtual void deleteSecUserByPwdResetIdx( const uuid_ptr_t PasswordResetUuid ) = 0;

		virtual void deleteSecUserByDefDevIdx( const uuid_ptr_t DfltDevUserId,
			const std::string* DfltDevName ) = 0;

		virtual void reallyDetachFromIndexesSecUser( cfsec::ICFSecSecUserObj* Obj ) = 0;

	virtual cfsec::ICFSecSecUserObj* getSystemUser() = 0;

	};
}
