// Description: C++18 implementation of a CFInt schema.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfint/CFIntSchema.hpp>
#include <cfint/ICFIntPublic.hpp>

namespace cfint {

	const std::string CFIntSchema::CLASS_NAME( "CFIntSchema" );

	CFIntSchema::CFIntSchema()
	: ICFIntSchema(),
	  cfsec::ICFSecSchema()
 	{
		authorization = NULL;
		tablePerms = NULL;
		configuration = NULL;
		jndiName = NULL;
		schemaDbName = new std::string( "CFINet213" );
		lowerDbSchemaName = new std::string( "CFINet213" );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );

		tableCluster = NULL;
		tableHostNode = NULL;
		tableISOCcy = NULL;
		tableISOCtry = NULL;
		tableISOCtryCcy = NULL;
		tableISOCtryLang = NULL;
		tableISOLang = NULL;
		tableISOTZone = NULL;
		tableLicense = NULL;
		tableMajorVersion = NULL;
		tableMimeType = NULL;
		tableMinorVersion = NULL;
		tableSecApp = NULL;
		tableSecDevice = NULL;
		tableSecForm = NULL;
		tableSecGroup = NULL;
		tableSecGroupForm = NULL;
		tableSecGrpInc = NULL;
		tableSecGrpMemb = NULL;
		tableSecSession = NULL;
		tableSecUser = NULL;
		tableService = NULL;
		tableServiceType = NULL;
		tableSubProject = NULL;
		tableSysCluster = NULL;
		tableTSecGroup = NULL;
		tableTSecGrpInc = NULL;
		tableTSecGrpMemb = NULL;
		tableTenant = NULL;
		tableTld = NULL;
		tableTopDomain = NULL;
		tableTopProject = NULL;
		tableURLProtocol = NULL;
	}

	CFIntSchema::CFIntSchema( cfsec::CFSecConfigurationFile* conf )
	: ICFIntSchema(),
	  cfsec::ICFSecSchema()
 	{
		static const std::string S_ProcName( "CFIntSchema-constructor" );
		static const std::string S_Conf( "conf" );
		if( conf == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_Conf );
		}
		authorization = NULL;
		tablePerms = NULL;
		configuration = conf;
		jndiName = NULL;
		schemaDbName = new std::string( "CFINet213" );
		lowerDbSchemaName = new std::string( "CFINet213" );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );
		jndiName = NULL;

		tableCluster = NULL;
		tableHostNode = NULL;
		tableISOCcy = NULL;
		tableISOCtry = NULL;
		tableISOCtryCcy = NULL;
		tableISOCtryLang = NULL;
		tableISOLang = NULL;
		tableISOTZone = NULL;
		tableLicense = NULL;
		tableMajorVersion = NULL;
		tableMimeType = NULL;
		tableMinorVersion = NULL;
		tableSecApp = NULL;
		tableSecDevice = NULL;
		tableSecForm = NULL;
		tableSecGroup = NULL;
		tableSecGroupForm = NULL;
		tableSecGrpInc = NULL;
		tableSecGrpMemb = NULL;
		tableSecSession = NULL;
		tableSecUser = NULL;
		tableService = NULL;
		tableServiceType = NULL;
		tableSubProject = NULL;
		tableSysCluster = NULL;
		tableTSecGroup = NULL;
		tableTSecGrpInc = NULL;
		tableTSecGrpMemb = NULL;
		tableTenant = NULL;
		tableTld = NULL;
		tableTopDomain = NULL;
		tableTopProject = NULL;
		tableURLProtocol = NULL;
	}

	CFIntSchema::CFIntSchema( const std::string& argJndiName )
	: ICFIntSchema(),
	  cfsec::ICFSecSchema()
	{
		static const std::string S_ProcName( "CFIntSchema-constructor" );
		static const std::string S_ArgJndiName( "argJndiName" );
		if( argJndiName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_ArgJndiName );
		}
		authorization = NULL;
		tablePerms = NULL;
		configuration = NULL;
		jndiName = new std::string( argJndiName );
		schemaDbName = new std::string( "CFINet213" );
		lowerDbSchemaName = new std::string( "CFINet213" );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );

		tableCluster = NULL;
		tableHostNode = NULL;
		tableISOCcy = NULL;
		tableISOCtry = NULL;
		tableISOCtryCcy = NULL;
		tableISOCtryLang = NULL;
		tableISOLang = NULL;
		tableISOTZone = NULL;
		tableLicense = NULL;
		tableMajorVersion = NULL;
		tableMimeType = NULL;
		tableMinorVersion = NULL;
		tableSecApp = NULL;
		tableSecDevice = NULL;
		tableSecForm = NULL;
		tableSecGroup = NULL;
		tableSecGroupForm = NULL;
		tableSecGrpInc = NULL;
		tableSecGrpMemb = NULL;
		tableSecSession = NULL;
		tableSecUser = NULL;
		tableService = NULL;
		tableServiceType = NULL;
		tableSubProject = NULL;
		tableSysCluster = NULL;
		tableTSecGroup = NULL;
		tableTSecGrpInc = NULL;
		tableTSecGrpMemb = NULL;
		tableTenant = NULL;
		tableTld = NULL;
		tableTopDomain = NULL;
		tableTopProject = NULL;
		tableURLProtocol = NULL;
	}

	CFIntSchema::~CFIntSchema() {
		authorization = NULL;
		if( tablePerms != NULL ) {
			delete tablePerms;
			tablePerms = NULL;
		}
		configuration = NULL;
		if( jndiName != NULL ) {
			delete jndiName;
			jndiName = NULL;
		}
		if( schemaDbName != NULL ) {
			delete schemaDbName;
			schemaDbName = NULL;
		}
		if( lowerDbSchemaName != NULL ) {
			delete lowerDbSchemaName;
			lowerDbSchemaName = NULL;
		}

		if( tableCluster != NULL ) {
			delete tableCluster;
			tableCluster = NULL;
		}
		if( tableHostNode != NULL ) {
			delete tableHostNode;
			tableHostNode = NULL;
		}
		if( tableISOCcy != NULL ) {
			delete tableISOCcy;
			tableISOCcy = NULL;
		}
		if( tableISOCtry != NULL ) {
			delete tableISOCtry;
			tableISOCtry = NULL;
		}
		if( tableISOCtryCcy != NULL ) {
			delete tableISOCtryCcy;
			tableISOCtryCcy = NULL;
		}
		if( tableISOCtryLang != NULL ) {
			delete tableISOCtryLang;
			tableISOCtryLang = NULL;
		}
		if( tableISOLang != NULL ) {
			delete tableISOLang;
			tableISOLang = NULL;
		}
		if( tableISOTZone != NULL ) {
			delete tableISOTZone;
			tableISOTZone = NULL;
		}
		if( tableLicense != NULL ) {
			delete tableLicense;
			tableLicense = NULL;
		}
		if( tableMajorVersion != NULL ) {
			delete tableMajorVersion;
			tableMajorVersion = NULL;
		}
		if( tableMimeType != NULL ) {
			delete tableMimeType;
			tableMimeType = NULL;
		}
		if( tableMinorVersion != NULL ) {
			delete tableMinorVersion;
			tableMinorVersion = NULL;
		}
		if( tableSecApp != NULL ) {
			delete tableSecApp;
			tableSecApp = NULL;
		}
		if( tableSecDevice != NULL ) {
			delete tableSecDevice;
			tableSecDevice = NULL;
		}
		if( tableSecForm != NULL ) {
			delete tableSecForm;
			tableSecForm = NULL;
		}
		if( tableSecGroup != NULL ) {
			delete tableSecGroup;
			tableSecGroup = NULL;
		}
		if( tableSecGroupForm != NULL ) {
			delete tableSecGroupForm;
			tableSecGroupForm = NULL;
		}
		if( tableSecGrpInc != NULL ) {
			delete tableSecGrpInc;
			tableSecGrpInc = NULL;
		}
		if( tableSecGrpMemb != NULL ) {
			delete tableSecGrpMemb;
			tableSecGrpMemb = NULL;
		}
		if( tableSecSession != NULL ) {
			delete tableSecSession;
			tableSecSession = NULL;
		}
		if( tableSecUser != NULL ) {
			delete tableSecUser;
			tableSecUser = NULL;
		}
		if( tableService != NULL ) {
			delete tableService;
			tableService = NULL;
		}
		if( tableServiceType != NULL ) {
			delete tableServiceType;
			tableServiceType = NULL;
		}
		if( tableSubProject != NULL ) {
			delete tableSubProject;
			tableSubProject = NULL;
		}
		if( tableSysCluster != NULL ) {
			delete tableSysCluster;
			tableSysCluster = NULL;
		}
		if( tableTSecGroup != NULL ) {
			delete tableTSecGroup;
			tableTSecGroup = NULL;
		}
		if( tableTSecGrpInc != NULL ) {
			delete tableTSecGrpInc;
			tableTSecGrpInc = NULL;
		}
		if( tableTSecGrpMemb != NULL ) {
			delete tableTSecGrpMemb;
			tableTSecGrpMemb = NULL;
		}
		if( tableTenant != NULL ) {
			delete tableTenant;
			tableTenant = NULL;
		}
		if( tableTld != NULL ) {
			delete tableTld;
			tableTld = NULL;
		}
		if( tableTopDomain != NULL ) {
			delete tableTopDomain;
			tableTopDomain = NULL;
		}
		if( tableTopProject != NULL ) {
			delete tableTopProject;
			tableTopProject = NULL;
		}
		if( tableURLProtocol != NULL ) {
			delete tableURLProtocol;
			tableURLProtocol = NULL;
		}
	}

	cfsec::CFSecConfigurationFile* CFIntSchema::getConfigurationFile() const {
		return( configuration );
	}

	void CFIntSchema::setConfigurationFile( cfsec::CFSecConfigurationFile* value ) {
		configuration = NULL;
		if( value != NULL ) {
			configuration = value;
			if( jndiName != NULL ) {
				delete jndiName;
				jndiName = NULL;
			}
		}
	}

	cfsec::CFSecAuthorization* CFIntSchema::getAuthorization() const {
		return( authorization );
	}

	void CFIntSchema::setAuthorization( cfsec::CFSecAuthorization* value ) {
		authorization = value;
	}

	const std::string* CFIntSchema::getJndiName() const {
		return( jndiName );
	}

	void CFIntSchema::setJndiName( const std::string& value ) {
		if( jndiName != NULL ) {
			delete jndiName;
			jndiName = NULL;
		}
		if( value.length() > 0 ) {
			jndiName = new std::string( value );
			configuration = NULL;
		}
	}

	bool CFIntSchema::isConnected() {
		static const std::string S_ProcName( "isConnected" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	bool CFIntSchema::connect() {
		static const std::string S_ProcName( "connect" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	bool CFIntSchema::connect( const std::string& username, const std::string& password ) {
		static const std::string S_ProcName( "connect-userpw" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	bool CFIntSchema::connect( const std::string& loginId, const std::string& password, const std::string& clusterName, const std::string& tenantName ) {
		static const std::string S_ProcName( "connect-full" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	void CFIntSchema::disconnect( bool doCommit ) {
		static const std::string S_ProcName( "disconnect" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	void CFIntSchema::logout( cfsec::CFSecAuthorization* auth ) {
		static const std::string S_ProcName( "logout" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	ICFIntSchema* CFIntSchema::newSchema() {
		static const std::string S_ProcName( "newSchema" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	std::string CFIntSchema::fileImport( const cfsec::CFSecAuthorization* auth, const std::string& fileName, const std::string& fileContent ) {
		static const std::string S_ProcName( "fileImport" );
		static const std::string S_Msg( "You must overload this method to apply a SAX Parser to the file contents" );
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME,
			S_ProcName,
			S_Msg );
	}

	int16_t CFIntSchema::nextISOCcyIdGen() {
		static const std::string S_ProcName( "nextISOCcyIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int16_t CFIntSchema::nextISOCtryIdGen() {
		static const std::string S_ProcName( "nextISOCtryIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int16_t CFIntSchema::nextISOLangIdGen() {
		static const std::string S_ProcName( "nextISOLangIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int16_t CFIntSchema::nextISOTZoneIdGen() {
		static const std::string S_ProcName( "nextISOTZoneIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int32_t CFIntSchema::nextServiceTypeIdGen() {
		static const std::string S_ProcName( "nextServiceTypeIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int32_t CFIntSchema::nextMimeTypeIdGen() {
		static const std::string S_ProcName( "nextMimeTypeIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int32_t CFIntSchema::nextURLProtocolIdGen() {
		static const std::string S_ProcName( "nextURLProtocolIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int64_t CFIntSchema::nextClusterIdGen() {
		static const std::string S_ProcName( "nextClusterIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	int64_t CFIntSchema::nextTenantIdGen() {
		static const std::string S_ProcName( "nextTenantIdGen" );
		// MSS TODO WORKING
		throw cflib::CFLibNotImplementedYetException( CLASS_NAME, S_ProcName );
	}

	cfsec::ICFSecClusterTable* CFIntSchema::getTableCluster() {
		return( tableCluster );
	}

	void CFIntSchema::setTableCluster( cfsec::ICFSecClusterTable* value ) {
		if( tableCluster != NULL ) {
			delete tableCluster;
			tableCluster = NULL;
		}
		tableCluster = value;
	}

	cfsec::ICFSecHostNodeTable* CFIntSchema::getTableHostNode() {
		return( tableHostNode );
	}

	void CFIntSchema::setTableHostNode( cfsec::ICFSecHostNodeTable* value ) {
		if( tableHostNode != NULL ) {
			delete tableHostNode;
			tableHostNode = NULL;
		}
		tableHostNode = value;
	}

	cfsec::ICFSecISOCcyTable* CFIntSchema::getTableISOCcy() {
		return( tableISOCcy );
	}

	void CFIntSchema::setTableISOCcy( cfsec::ICFSecISOCcyTable* value ) {
		if( tableISOCcy != NULL ) {
			delete tableISOCcy;
			tableISOCcy = NULL;
		}
		tableISOCcy = value;
	}

	cfsec::ICFSecISOCtryTable* CFIntSchema::getTableISOCtry() {
		return( tableISOCtry );
	}

	void CFIntSchema::setTableISOCtry( cfsec::ICFSecISOCtryTable* value ) {
		if( tableISOCtry != NULL ) {
			delete tableISOCtry;
			tableISOCtry = NULL;
		}
		tableISOCtry = value;
	}

	cfsec::ICFSecISOCtryCcyTable* CFIntSchema::getTableISOCtryCcy() {
		return( tableISOCtryCcy );
	}

	void CFIntSchema::setTableISOCtryCcy( cfsec::ICFSecISOCtryCcyTable* value ) {
		if( tableISOCtryCcy != NULL ) {
			delete tableISOCtryCcy;
			tableISOCtryCcy = NULL;
		}
		tableISOCtryCcy = value;
	}

	cfsec::ICFSecISOCtryLangTable* CFIntSchema::getTableISOCtryLang() {
		return( tableISOCtryLang );
	}

	void CFIntSchema::setTableISOCtryLang( cfsec::ICFSecISOCtryLangTable* value ) {
		if( tableISOCtryLang != NULL ) {
			delete tableISOCtryLang;
			tableISOCtryLang = NULL;
		}
		tableISOCtryLang = value;
	}

	cfsec::ICFSecISOLangTable* CFIntSchema::getTableISOLang() {
		return( tableISOLang );
	}

	void CFIntSchema::setTableISOLang( cfsec::ICFSecISOLangTable* value ) {
		if( tableISOLang != NULL ) {
			delete tableISOLang;
			tableISOLang = NULL;
		}
		tableISOLang = value;
	}

	cfsec::ICFSecISOTZoneTable* CFIntSchema::getTableISOTZone() {
		return( tableISOTZone );
	}

	void CFIntSchema::setTableISOTZone( cfsec::ICFSecISOTZoneTable* value ) {
		if( tableISOTZone != NULL ) {
			delete tableISOTZone;
			tableISOTZone = NULL;
		}
		tableISOTZone = value;
	}

	cfint::ICFIntLicenseTable* CFIntSchema::getTableLicense() {
		return( tableLicense );
	}

	void CFIntSchema::setTableLicense( cfint::ICFIntLicenseTable* value ) {
		if( tableLicense != NULL ) {
			delete tableLicense;
			tableLicense = NULL;
		}
		tableLicense = value;
	}

	cfint::ICFIntMajorVersionTable* CFIntSchema::getTableMajorVersion() {
		return( tableMajorVersion );
	}

	void CFIntSchema::setTableMajorVersion( cfint::ICFIntMajorVersionTable* value ) {
		if( tableMajorVersion != NULL ) {
			delete tableMajorVersion;
			tableMajorVersion = NULL;
		}
		tableMajorVersion = value;
	}

	cfint::ICFIntMimeTypeTable* CFIntSchema::getTableMimeType() {
		return( tableMimeType );
	}

	void CFIntSchema::setTableMimeType( cfint::ICFIntMimeTypeTable* value ) {
		if( tableMimeType != NULL ) {
			delete tableMimeType;
			tableMimeType = NULL;
		}
		tableMimeType = value;
	}

	cfint::ICFIntMinorVersionTable* CFIntSchema::getTableMinorVersion() {
		return( tableMinorVersion );
	}

	void CFIntSchema::setTableMinorVersion( cfint::ICFIntMinorVersionTable* value ) {
		if( tableMinorVersion != NULL ) {
			delete tableMinorVersion;
			tableMinorVersion = NULL;
		}
		tableMinorVersion = value;
	}

	cfsec::ICFSecSecAppTable* CFIntSchema::getTableSecApp() {
		return( tableSecApp );
	}

	void CFIntSchema::setTableSecApp( cfsec::ICFSecSecAppTable* value ) {
		if( tableSecApp != NULL ) {
			delete tableSecApp;
			tableSecApp = NULL;
		}
		tableSecApp = value;
	}

	cfsec::ICFSecSecDeviceTable* CFIntSchema::getTableSecDevice() {
		return( tableSecDevice );
	}

	void CFIntSchema::setTableSecDevice( cfsec::ICFSecSecDeviceTable* value ) {
		if( tableSecDevice != NULL ) {
			delete tableSecDevice;
			tableSecDevice = NULL;
		}
		tableSecDevice = value;
	}

	cfsec::ICFSecSecFormTable* CFIntSchema::getTableSecForm() {
		return( tableSecForm );
	}

	void CFIntSchema::setTableSecForm( cfsec::ICFSecSecFormTable* value ) {
		if( tableSecForm != NULL ) {
			delete tableSecForm;
			tableSecForm = NULL;
		}
		tableSecForm = value;
	}

	cfsec::ICFSecSecGroupTable* CFIntSchema::getTableSecGroup() {
		return( tableSecGroup );
	}

	void CFIntSchema::setTableSecGroup( cfsec::ICFSecSecGroupTable* value ) {
		if( tableSecGroup != NULL ) {
			delete tableSecGroup;
			tableSecGroup = NULL;
		}
		tableSecGroup = value;
	}

	cfsec::ICFSecSecGroupFormTable* CFIntSchema::getTableSecGroupForm() {
		return( tableSecGroupForm );
	}

	void CFIntSchema::setTableSecGroupForm( cfsec::ICFSecSecGroupFormTable* value ) {
		if( tableSecGroupForm != NULL ) {
			delete tableSecGroupForm;
			tableSecGroupForm = NULL;
		}
		tableSecGroupForm = value;
	}

	cfsec::ICFSecSecGrpIncTable* CFIntSchema::getTableSecGrpInc() {
		return( tableSecGrpInc );
	}

	void CFIntSchema::setTableSecGrpInc( cfsec::ICFSecSecGrpIncTable* value ) {
		if( tableSecGrpInc != NULL ) {
			delete tableSecGrpInc;
			tableSecGrpInc = NULL;
		}
		tableSecGrpInc = value;
	}

	cfsec::ICFSecSecGrpMembTable* CFIntSchema::getTableSecGrpMemb() {
		return( tableSecGrpMemb );
	}

	void CFIntSchema::setTableSecGrpMemb( cfsec::ICFSecSecGrpMembTable* value ) {
		if( tableSecGrpMemb != NULL ) {
			delete tableSecGrpMemb;
			tableSecGrpMemb = NULL;
		}
		tableSecGrpMemb = value;
	}

	cfsec::ICFSecSecSessionTable* CFIntSchema::getTableSecSession() {
		return( tableSecSession );
	}

	void CFIntSchema::setTableSecSession( cfsec::ICFSecSecSessionTable* value ) {
		if( tableSecSession != NULL ) {
			delete tableSecSession;
			tableSecSession = NULL;
		}
		tableSecSession = value;
	}

	cfsec::ICFSecSecUserTable* CFIntSchema::getTableSecUser() {
		return( tableSecUser );
	}

	void CFIntSchema::setTableSecUser( cfsec::ICFSecSecUserTable* value ) {
		if( tableSecUser != NULL ) {
			delete tableSecUser;
			tableSecUser = NULL;
		}
		tableSecUser = value;
	}

	cfsec::ICFSecServiceTable* CFIntSchema::getTableService() {
		return( tableService );
	}

	void CFIntSchema::setTableService( cfsec::ICFSecServiceTable* value ) {
		if( tableService != NULL ) {
			delete tableService;
			tableService = NULL;
		}
		tableService = value;
	}

	cfsec::ICFSecServiceTypeTable* CFIntSchema::getTableServiceType() {
		return( tableServiceType );
	}

	void CFIntSchema::setTableServiceType( cfsec::ICFSecServiceTypeTable* value ) {
		if( tableServiceType != NULL ) {
			delete tableServiceType;
			tableServiceType = NULL;
		}
		tableServiceType = value;
	}

	cfint::ICFIntSubProjectTable* CFIntSchema::getTableSubProject() {
		return( tableSubProject );
	}

	void CFIntSchema::setTableSubProject( cfint::ICFIntSubProjectTable* value ) {
		if( tableSubProject != NULL ) {
			delete tableSubProject;
			tableSubProject = NULL;
		}
		tableSubProject = value;
	}

	cfsec::ICFSecSysClusterTable* CFIntSchema::getTableSysCluster() {
		return( tableSysCluster );
	}

	void CFIntSchema::setTableSysCluster( cfsec::ICFSecSysClusterTable* value ) {
		if( tableSysCluster != NULL ) {
			delete tableSysCluster;
			tableSysCluster = NULL;
		}
		tableSysCluster = value;
	}

	cfsec::ICFSecTSecGroupTable* CFIntSchema::getTableTSecGroup() {
		return( tableTSecGroup );
	}

	void CFIntSchema::setTableTSecGroup( cfsec::ICFSecTSecGroupTable* value ) {
		if( tableTSecGroup != NULL ) {
			delete tableTSecGroup;
			tableTSecGroup = NULL;
		}
		tableTSecGroup = value;
	}

	cfsec::ICFSecTSecGrpIncTable* CFIntSchema::getTableTSecGrpInc() {
		return( tableTSecGrpInc );
	}

	void CFIntSchema::setTableTSecGrpInc( cfsec::ICFSecTSecGrpIncTable* value ) {
		if( tableTSecGrpInc != NULL ) {
			delete tableTSecGrpInc;
			tableTSecGrpInc = NULL;
		}
		tableTSecGrpInc = value;
	}

	cfsec::ICFSecTSecGrpMembTable* CFIntSchema::getTableTSecGrpMemb() {
		return( tableTSecGrpMemb );
	}

	void CFIntSchema::setTableTSecGrpMemb( cfsec::ICFSecTSecGrpMembTable* value ) {
		if( tableTSecGrpMemb != NULL ) {
			delete tableTSecGrpMemb;
			tableTSecGrpMemb = NULL;
		}
		tableTSecGrpMemb = value;
	}

	cfsec::ICFSecTenantTable* CFIntSchema::getTableTenant() {
		return( tableTenant );
	}

	void CFIntSchema::setTableTenant( cfsec::ICFSecTenantTable* value ) {
		if( tableTenant != NULL ) {
			delete tableTenant;
			tableTenant = NULL;
		}
		tableTenant = value;
	}

	cfint::ICFIntTldTable* CFIntSchema::getTableTld() {
		return( tableTld );
	}

	void CFIntSchema::setTableTld( cfint::ICFIntTldTable* value ) {
		if( tableTld != NULL ) {
			delete tableTld;
			tableTld = NULL;
		}
		tableTld = value;
	}

	cfint::ICFIntTopDomainTable* CFIntSchema::getTableTopDomain() {
		return( tableTopDomain );
	}

	void CFIntSchema::setTableTopDomain( cfint::ICFIntTopDomainTable* value ) {
		if( tableTopDomain != NULL ) {
			delete tableTopDomain;
			tableTopDomain = NULL;
		}
		tableTopDomain = value;
	}

	cfint::ICFIntTopProjectTable* CFIntSchema::getTableTopProject() {
		return( tableTopProject );
	}

	void CFIntSchema::setTableTopProject( cfint::ICFIntTopProjectTable* value ) {
		if( tableTopProject != NULL ) {
			delete tableTopProject;
			tableTopProject = NULL;
		}
		tableTopProject = value;
	}

	cfint::ICFIntURLProtocolTable* CFIntSchema::getTableURLProtocol() {
		return( tableURLProtocol );
	}

	void CFIntSchema::setTableURLProtocol( cfint::ICFIntURLProtocolTable* value ) {
		if( tableURLProtocol != NULL ) {
			delete tableURLProtocol;
			tableURLProtocol = NULL;
		}
		tableURLProtocol = value;
	}

	bool CFIntSchema::isTransactionOpen() const {
		static const std::string S_ProcName( "isTransactionOpen" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	bool CFIntSchema::beginTransaction() {
		static const std::string S_ProcName( "beginTransaction" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	void CFIntSchema::commit() {
		static const std::string S_ProcName( "commit" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	void CFIntSchema::rollback() {
		static const std::string S_ProcName( "rollback" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	cfsec::ICFSecTablePerms* CFIntSchema::getTablePerms() {
		return( tablePerms );
	}

	void CFIntSchema::setTablePerms( cfsec::ICFSecTablePerms* value ) {
		if( tablePerms != NULL ) {
			delete tablePerms;
			tablePerms = NULL;
		}
		tablePerms = value;
	}

	void CFIntSchema::releasePreparedStatements() {
	}

	const std::string* CFIntSchema::getDbSchemaName() const {
		return( schemaDbName );
	}

	const std::string* CFIntSchema::getLowerDbSchemaName() const {
		return( lowerDbSchemaName );
	}

	void CFIntSchema::setDbSchemaName( const std::string& argDbSchemaName ) {
		static const std::string S_ProcName( "setDbSchemaName" );
		static const std::string S_ArgDbSchemaName( "argDbSchemaName" );
		if( argDbSchemaName.length() <= 0 ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_ArgDbSchemaName );
		}
		if( schemaDbName != NULL ) {
			delete schemaDbName;
			schemaDbName = NULL;
		}
		if( lowerDbSchemaName != NULL ) {
			delete lowerDbSchemaName;
			lowerDbSchemaName = NULL;
		}
		schemaDbName = new std::string( argDbSchemaName );
		lowerDbSchemaName = new std::string( argDbSchemaName );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );
	}

}
