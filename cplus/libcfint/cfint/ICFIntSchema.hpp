#pragma once

// Description: C++18 interface for a CFInt schema.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
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


#include <uuid/uuid.h>

#include <array>
#include <cassert>
#include <cstddef>
#include <chrono>
#include <ctime>
#include <functional>
#include <list>
#include <string>

#include <cflib/ICFLibPublic.hpp>

#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/ICFSecSchema.hpp>
#include <cfint/CFIntConfigurationFile.hpp>
#include <cfint/ICFIntTablePerms.hpp>

#include <cfsec/ICFSecPublic.hpp>
namespace cfint {

	class CFIntLicensePKey;
	class CFIntMajorVersionPKey;
	class CFIntMimeTypePKey;
	class CFIntMinorVersionPKey;
	class CFIntSubProjectPKey;
	class CFIntTldPKey;
	class CFIntTopDomainPKey;
	class CFIntTopProjectPKey;
	class CFIntURLProtocolPKey;

	class CFIntMajorVersionHPKey;
	class CFIntMimeTypeHPKey;
	class CFIntMinorVersionHPKey;
	class CFIntSubProjectHPKey;
	class CFIntTldHPKey;
	class CFIntTopDomainHPKey;
	class CFIntTopProjectHPKey;
	class CFIntURLProtocolHPKey;

	class CFIntLicenseBuff;
	class CFIntMajorVersionBuff;
	class CFIntMimeTypeBuff;
	class CFIntMinorVersionBuff;
	class CFIntSubProjectBuff;
	class CFIntTldBuff;
	class CFIntTopDomainBuff;
	class CFIntTopProjectBuff;
	class CFIntURLProtocolBuff;

	class CFIntMajorVersionHBuff;
	class CFIntMimeTypeHBuff;
	class CFIntMinorVersionHBuff;
	class CFIntSubProjectHBuff;
	class CFIntTldHBuff;
	class CFIntTopDomainHBuff;
	class CFIntTopProjectHBuff;
	class CFIntURLProtocolHBuff;

	class ICFIntClusterTable;
	class ICFIntHostNodeTable;
	class ICFIntISOCcyTable;
	class ICFIntISOCtryTable;
	class ICFIntISOCtryCcyTable;
	class ICFIntISOCtryLangTable;
	class ICFIntISOLangTable;
	class ICFIntISOTZoneTable;
	class ICFIntLicenseTable;
	class ICFIntMajorVersionTable;
	class ICFIntMimeTypeTable;
	class ICFIntMinorVersionTable;
	class ICFIntSecAppTable;
	class ICFIntSecDeviceTable;
	class ICFIntSecFormTable;
	class ICFIntSecGroupTable;
	class ICFIntSecGroupFormTable;
	class ICFIntSecGrpIncTable;
	class ICFIntSecGrpMembTable;
	class ICFIntSecSessionTable;
	class ICFIntSecUserTable;
	class ICFIntServiceTable;
	class ICFIntServiceTypeTable;
	class ICFIntSubProjectTable;
	class ICFIntSysClusterTable;
	class ICFIntTSecGroupTable;
	class ICFIntTSecGrpIncTable;
	class ICFIntTSecGrpMembTable;
	class ICFIntTenantTable;
	class ICFIntTldTable;
	class ICFIntTopDomainTable;
	class ICFIntTopProjectTable;
	class ICFIntURLProtocolTable;
}


namespace cfint {

	class ICFIntSchema
	: public virtual cfsec::ICFSecSchema
	{
	public:
		static const std::string CLASS_NAME;

	public:
		ICFIntSchema();
		virtual ~ICFIntSchema();

		virtual cfsec::CFSecConfigurationFile* getConfigurationFile() const = 0;
		virtual void setConfigurationFile( cfsec::CFSecConfigurationFile* value ) = 0;

		virtual const std::string* getJndiName() const = 0;
		virtual void setJndiName( const std::string& value ) = 0;

		virtual bool isConnected() = 0;
		virtual bool connect() = 0;
		virtual bool connect( const std::string& username, const std::string& password ) = 0;
		virtual bool connect( const std::string& loginId, const std::string& password, const std::string& clusterName, const std::string& tenantName ) = 0;
		virtual void disconnect( bool doCommit ) = 0;
		virtual void logout( cfsec::CFSecAuthorization* auth ) = 0;

		virtual std::string fileImport( const cfsec::CFSecAuthorization* auth, const std::string& fileName, const std::string& fileContent ) = 0;

		virtual ICFSecSchema* newSchema() = 0;

		virtual int16_t nextISOCcyIdGen() = 0;

		virtual int16_t nextISOCtryIdGen() = 0;

		virtual int16_t nextISOLangIdGen() = 0;

		virtual int16_t nextISOTZoneIdGen() = 0;

		virtual int32_t nextServiceTypeIdGen() = 0;

		virtual int32_t nextMimeTypeIdGen() = 0;

		virtual int32_t nextURLProtocolIdGen() = 0;

		virtual int64_t nextClusterIdGen() = 0;

		virtual int64_t nextTenantIdGen() = 0;

		virtual cfsec::ICFSecClusterTable* getTableCluster() = 0;

		virtual cfsec::ICFSecHostNodeTable* getTableHostNode() = 0;

		virtual cfsec::ICFSecISOCcyTable* getTableISOCcy() = 0;

		virtual cfsec::ICFSecISOCtryTable* getTableISOCtry() = 0;

		virtual cfsec::ICFSecISOCtryCcyTable* getTableISOCtryCcy() = 0;

		virtual cfsec::ICFSecISOCtryLangTable* getTableISOCtryLang() = 0;

		virtual cfsec::ICFSecISOLangTable* getTableISOLang() = 0;

		virtual cfsec::ICFSecISOTZoneTable* getTableISOTZone() = 0;

		virtual cfint::ICFIntLicenseTable* getTableLicense() = 0;

		virtual cfint::ICFIntMajorVersionTable* getTableMajorVersion() = 0;

		virtual cfint::ICFIntMimeTypeTable* getTableMimeType() = 0;

		virtual cfint::ICFIntMinorVersionTable* getTableMinorVersion() = 0;

		virtual cfsec::ICFSecSecAppTable* getTableSecApp() = 0;

		virtual cfsec::ICFSecSecDeviceTable* getTableSecDevice() = 0;

		virtual cfsec::ICFSecSecFormTable* getTableSecForm() = 0;

		virtual cfsec::ICFSecSecGroupTable* getTableSecGroup() = 0;

		virtual cfsec::ICFSecSecGroupFormTable* getTableSecGroupForm() = 0;

		virtual cfsec::ICFSecSecGrpIncTable* getTableSecGrpInc() = 0;

		virtual cfsec::ICFSecSecGrpMembTable* getTableSecGrpMemb() = 0;

		virtual cfsec::ICFSecSecSessionTable* getTableSecSession() = 0;

		virtual cfsec::ICFSecSecUserTable* getTableSecUser() = 0;

		virtual cfsec::ICFSecServiceTable* getTableService() = 0;

		virtual cfsec::ICFSecServiceTypeTable* getTableServiceType() = 0;

		virtual cfint::ICFIntSubProjectTable* getTableSubProject() = 0;

		virtual cfsec::ICFSecSysClusterTable* getTableSysCluster() = 0;

		virtual cfsec::ICFSecTSecGroupTable* getTableTSecGroup() = 0;

		virtual cfsec::ICFSecTSecGrpIncTable* getTableTSecGrpInc() = 0;

		virtual cfsec::ICFSecTSecGrpMembTable* getTableTSecGrpMemb() = 0;

		virtual cfsec::ICFSecTenantTable* getTableTenant() = 0;

		virtual cfint::ICFIntTldTable* getTableTld() = 0;

		virtual cfint::ICFIntTopDomainTable* getTableTopDomain() = 0;

		virtual cfint::ICFIntTopProjectTable* getTableTopProject() = 0;

		virtual cfint::ICFIntURLProtocolTable* getTableURLProtocol() = 0;

		virtual bool isTransactionOpen() const = 0;
		virtual bool beginTransaction() = 0;
		virtual void commit() = 0;
		virtual void rollback() = 0;

		virtual cfsec::ICFSecTablePerms* getTablePerms() = 0;
		virtual void setTablePerms( cfsec::ICFSecTablePerms* value ) = 0;

		virtual void releasePreparedStatements() = 0;

		virtual const std::string* getDbSchemaName() const = 0;
		virtual const std::string* getLowerDbSchemaName() const = 0;

		virtual void setDbSchemaName( const std::string& argDbSchemaName ) = 0;
;
	};
}
