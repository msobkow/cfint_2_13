#pragma once

// Description: C++18 specification of a CFInt schema.

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
#include <cflib/ICFLibPublic.hpp>

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

	class CFIntLicenseByLicnTenantIdxKey;
	class CFIntLicenseByDomainIdxKey;
	class CFIntLicenseByUNameIdxKey;
	class CFIntMajorVersionByTenantIdxKey;
	class CFIntMajorVersionBySubProjectIdxKey;
	class CFIntMajorVersionByNameIdxKey;
	class CFIntMimeTypeByUNameIdxKey;
	class CFIntMinorVersionByTenantIdxKey;
	class CFIntMinorVersionByMajorVerIdxKey;
	class CFIntMinorVersionByNameIdxKey;
	class CFIntSubProjectByTenantIdxKey;
	class CFIntSubProjectByTopProjectIdxKey;
	class CFIntSubProjectByNameIdxKey;
	class CFIntTldByTenantIdxKey;
	class CFIntTldByNameIdxKey;
	class CFIntTopDomainByTenantIdxKey;
	class CFIntTopDomainByTldIdxKey;
	class CFIntTopDomainByNameIdxKey;
	class CFIntTopProjectByTenantIdxKey;
	class CFIntTopProjectByTopDomainIdxKey;
	class CFIntTopProjectByNameIdxKey;
	class CFIntURLProtocolByUNameIdxKey;
	class CFIntURLProtocolByIsSecureIdxKey;

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

#include <cfint/ICFIntSchema.hpp>

#include <cfsec/CFSecAuthorization.hpp>
#include <cfsec/CFSecConfigurationFile.hpp>
#include <cfsec/ICFSecTablePerms.hpp>

namespace cfint {

	class CFIntSchema
	: public virtual cfint::ICFIntSchema,
	  public virtual cfsec::ICFSecSchema
	{
	protected:
		cfsec::CFSecAuthorization* authorization;
cfsec::ICFSecTablePerms* tablePerms;
cfsec::CFSecConfigurationFile* configuration;
		std::string* jndiName;
		std::string* schemaDbName;
		std::string* lowerDbSchemaName;
		cfsec::ICFSecClusterTable* tableCluster;
		cfsec::ICFSecHostNodeTable* tableHostNode;
		cfsec::ICFSecISOCcyTable* tableISOCcy;
		cfsec::ICFSecISOCtryTable* tableISOCtry;
		cfsec::ICFSecISOCtryCcyTable* tableISOCtryCcy;
		cfsec::ICFSecISOCtryLangTable* tableISOCtryLang;
		cfsec::ICFSecISOLangTable* tableISOLang;
		cfsec::ICFSecISOTZoneTable* tableISOTZone;
		cfint::ICFIntLicenseTable* tableLicense;
		cfint::ICFIntMajorVersionTable* tableMajorVersion;
		cfint::ICFIntMimeTypeTable* tableMimeType;
		cfint::ICFIntMinorVersionTable* tableMinorVersion;
		cfsec::ICFSecSecAppTable* tableSecApp;
		cfsec::ICFSecSecDeviceTable* tableSecDevice;
		cfsec::ICFSecSecFormTable* tableSecForm;
		cfsec::ICFSecSecGroupTable* tableSecGroup;
		cfsec::ICFSecSecGroupFormTable* tableSecGroupForm;
		cfsec::ICFSecSecGrpIncTable* tableSecGrpInc;
		cfsec::ICFSecSecGrpMembTable* tableSecGrpMemb;
		cfsec::ICFSecSecSessionTable* tableSecSession;
		cfsec::ICFSecSecUserTable* tableSecUser;
		cfsec::ICFSecServiceTable* tableService;
		cfsec::ICFSecServiceTypeTable* tableServiceType;
		cfint::ICFIntSubProjectTable* tableSubProject;
		cfsec::ICFSecSysClusterTable* tableSysCluster;
		cfsec::ICFSecTSecGroupTable* tableTSecGroup;
		cfsec::ICFSecTSecGrpIncTable* tableTSecGrpInc;
		cfsec::ICFSecTSecGrpMembTable* tableTSecGrpMemb;
		cfsec::ICFSecTenantTable* tableTenant;
		cfint::ICFIntTldTable* tableTld;
		cfint::ICFIntTopDomainTable* tableTopDomain;
		cfint::ICFIntTopProjectTable* tableTopProject;
		cfint::ICFIntURLProtocolTable* tableURLProtocol;

	public:
		static const std::string CLASS_NAME;

		CFIntSchema();
		CFIntSchema( cfsec::CFSecConfigurationFile* conf );
		CFIntSchema( const std::string& argJndiName );
		virtual ~CFIntSchema();

		virtual cfsec::CFSecConfigurationFile* getConfigurationFile() const;
		virtual void setConfigurationFile( cfsec::CFSecConfigurationFile* value );

		virtual cfsec::CFSecAuthorization* getAuthorization() const;
		virtual void setAuthorization( cfsec::CFSecAuthorization* value );

		virtual const std::string* getJndiName() const;
		virtual void setJndiName( const std::string& value );

		virtual bool isConnected();
		virtual bool connect();
		virtual bool connect( const std::string& username, const std::string& password );
		virtual bool connect( const std::string& loginId, const std::string& password, const std::string& clusterName, const std::string& tenantName );
		virtual void disconnect( bool doCommit );
		virtual void logout( cfsec::CFSecAuthorization* auth );

		virtual cfint::ICFIntSchema* newSchema();

		virtual std::string fileImport( const cfsec::CFSecAuthorization* auth, const std::string& fileName, const std::string& fileContent );

		virtual int16_t nextISOCcyIdGen();

		virtual int16_t nextISOCtryIdGen();

		virtual int16_t nextISOLangIdGen();

		virtual int16_t nextISOTZoneIdGen();

		virtual int32_t nextServiceTypeIdGen();

		virtual int32_t nextMimeTypeIdGen();

		virtual int32_t nextURLProtocolIdGen();

		virtual int64_t nextClusterIdGen();

		virtual int64_t nextTenantIdGen();

		virtual cfsec::ICFSecClusterTable* getTableCluster();
		virtual void setTableCluster( cfsec::ICFSecClusterTable* value );

		virtual cfsec::ICFSecHostNodeTable* getTableHostNode();
		virtual void setTableHostNode( cfsec::ICFSecHostNodeTable* value );

		virtual cfsec::ICFSecISOCcyTable* getTableISOCcy();
		virtual void setTableISOCcy( cfsec::ICFSecISOCcyTable* value );

		virtual cfsec::ICFSecISOCtryTable* getTableISOCtry();
		virtual void setTableISOCtry( cfsec::ICFSecISOCtryTable* value );

		virtual cfsec::ICFSecISOCtryCcyTable* getTableISOCtryCcy();
		virtual void setTableISOCtryCcy( cfsec::ICFSecISOCtryCcyTable* value );

		virtual cfsec::ICFSecISOCtryLangTable* getTableISOCtryLang();
		virtual void setTableISOCtryLang( cfsec::ICFSecISOCtryLangTable* value );

		virtual cfsec::ICFSecISOLangTable* getTableISOLang();
		virtual void setTableISOLang( cfsec::ICFSecISOLangTable* value );

		virtual cfsec::ICFSecISOTZoneTable* getTableISOTZone();
		virtual void setTableISOTZone( cfsec::ICFSecISOTZoneTable* value );

		virtual cfint::ICFIntLicenseTable* getTableLicense();
		virtual void setTableLicense( cfint::ICFIntLicenseTable* value );

		virtual cfint::ICFIntMajorVersionTable* getTableMajorVersion();
		virtual void setTableMajorVersion( cfint::ICFIntMajorVersionTable* value );

		virtual cfint::ICFIntMimeTypeTable* getTableMimeType();
		virtual void setTableMimeType( cfint::ICFIntMimeTypeTable* value );

		virtual cfint::ICFIntMinorVersionTable* getTableMinorVersion();
		virtual void setTableMinorVersion( cfint::ICFIntMinorVersionTable* value );

		virtual cfsec::ICFSecSecAppTable* getTableSecApp();
		virtual void setTableSecApp( cfsec::ICFSecSecAppTable* value );

		virtual cfsec::ICFSecSecDeviceTable* getTableSecDevice();
		virtual void setTableSecDevice( cfsec::ICFSecSecDeviceTable* value );

		virtual cfsec::ICFSecSecFormTable* getTableSecForm();
		virtual void setTableSecForm( cfsec::ICFSecSecFormTable* value );

		virtual cfsec::ICFSecSecGroupTable* getTableSecGroup();
		virtual void setTableSecGroup( cfsec::ICFSecSecGroupTable* value );

		virtual cfsec::ICFSecSecGroupFormTable* getTableSecGroupForm();
		virtual void setTableSecGroupForm( cfsec::ICFSecSecGroupFormTable* value );

		virtual cfsec::ICFSecSecGrpIncTable* getTableSecGrpInc();
		virtual void setTableSecGrpInc( cfsec::ICFSecSecGrpIncTable* value );

		virtual cfsec::ICFSecSecGrpMembTable* getTableSecGrpMemb();
		virtual void setTableSecGrpMemb( cfsec::ICFSecSecGrpMembTable* value );

		virtual cfsec::ICFSecSecSessionTable* getTableSecSession();
		virtual void setTableSecSession( cfsec::ICFSecSecSessionTable* value );

		virtual cfsec::ICFSecSecUserTable* getTableSecUser();
		virtual void setTableSecUser( cfsec::ICFSecSecUserTable* value );

		virtual cfsec::ICFSecServiceTable* getTableService();
		virtual void setTableService( cfsec::ICFSecServiceTable* value );

		virtual cfsec::ICFSecServiceTypeTable* getTableServiceType();
		virtual void setTableServiceType( cfsec::ICFSecServiceTypeTable* value );

		virtual cfint::ICFIntSubProjectTable* getTableSubProject();
		virtual void setTableSubProject( cfint::ICFIntSubProjectTable* value );

		virtual cfsec::ICFSecSysClusterTable* getTableSysCluster();
		virtual void setTableSysCluster( cfsec::ICFSecSysClusterTable* value );

		virtual cfsec::ICFSecTSecGroupTable* getTableTSecGroup();
		virtual void setTableTSecGroup( cfsec::ICFSecTSecGroupTable* value );

		virtual cfsec::ICFSecTSecGrpIncTable* getTableTSecGrpInc();
		virtual void setTableTSecGrpInc( cfsec::ICFSecTSecGrpIncTable* value );

		virtual cfsec::ICFSecTSecGrpMembTable* getTableTSecGrpMemb();
		virtual void setTableTSecGrpMemb( cfsec::ICFSecTSecGrpMembTable* value );

		virtual cfsec::ICFSecTenantTable* getTableTenant();
		virtual void setTableTenant( cfsec::ICFSecTenantTable* value );

		virtual cfint::ICFIntTldTable* getTableTld();
		virtual void setTableTld( cfint::ICFIntTldTable* value );

		virtual cfint::ICFIntTopDomainTable* getTableTopDomain();
		virtual void setTableTopDomain( cfint::ICFIntTopDomainTable* value );

		virtual cfint::ICFIntTopProjectTable* getTableTopProject();
		virtual void setTableTopProject( cfint::ICFIntTopProjectTable* value );

		virtual cfint::ICFIntURLProtocolTable* getTableURLProtocol();
		virtual void setTableURLProtocol( cfint::ICFIntURLProtocolTable* value );

		virtual bool isTransactionOpen() const;
		virtual bool beginTransaction();
		virtual void commit();
		virtual void rollback();

		virtual cfsec::ICFSecTablePerms* getTablePerms();
		virtual void setTablePerms( cfsec::ICFSecTablePerms* value );

		virtual void releasePreparedStatements();

		virtual const std::string* getDbSchemaName() const;
		virtual const std::string* getLowerDbSchemaName() const;
		virtual void setDbSchemaName( const std::string& argDbSchemaName );
	};
}
