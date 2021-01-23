// Description: C++18 Implementation of an in-memory RAM CFInt schema.

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
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintobj/CFIntSchemaObj.hpp>
#include <cfintsaxloader/CFIntSaxLoader.hpp>
#include <cfintram/CFIntRamSchema.hpp>
#include <cfintram/CFIntRamClusterTable.hpp>
#include <cfintram/CFIntRamHostNodeTable.hpp>
#include <cfintram/CFIntRamISOCcyTable.hpp>
#include <cfintram/CFIntRamISOCtryTable.hpp>
#include <cfintram/CFIntRamISOCtryCcyTable.hpp>
#include <cfintram/CFIntRamISOCtryLangTable.hpp>
#include <cfintram/CFIntRamISOLangTable.hpp>
#include <cfintram/CFIntRamISOTZoneTable.hpp>
#include <cfintram/CFIntRamLicenseTable.hpp>
#include <cfintram/CFIntRamMajorVersionTable.hpp>
#include <cfintram/CFIntRamMimeTypeTable.hpp>
#include <cfintram/CFIntRamMinorVersionTable.hpp>
#include <cfintram/CFIntRamSecAppTable.hpp>
#include <cfintram/CFIntRamSecDeviceTable.hpp>
#include <cfintram/CFIntRamSecFormTable.hpp>
#include <cfintram/CFIntRamSecGroupTable.hpp>
#include <cfintram/CFIntRamSecGroupFormTable.hpp>
#include <cfintram/CFIntRamSecGrpIncTable.hpp>
#include <cfintram/CFIntRamSecGrpMembTable.hpp>
#include <cfintram/CFIntRamSecSessionTable.hpp>
#include <cfintram/CFIntRamSecUserTable.hpp>
#include <cfintram/CFIntRamServiceTable.hpp>
#include <cfintram/CFIntRamServiceTypeTable.hpp>
#include <cfintram/CFIntRamSubProjectTable.hpp>
#include <cfintram/CFIntRamSysClusterTable.hpp>
#include <cfintram/CFIntRamTSecGroupTable.hpp>
#include <cfintram/CFIntRamTSecGrpIncTable.hpp>
#include <cfintram/CFIntRamTSecGrpMembTable.hpp>
#include <cfintram/CFIntRamTenantTable.hpp>
#include <cfintram/CFIntRamTldTable.hpp>
#include <cfintram/CFIntRamTopDomainTable.hpp>
#include <cfintram/CFIntRamTopProjectTable.hpp>
#include <cfintram/CFIntRamURLProtocolTable.hpp>

using namespace std;

namespace cfint {

	const std::string CFIntRamSchema::CLASS_NAME( "CFIntRamSchema" );

	CFIntRamSchema::CFIntRamSchema()
	: cfint::CFIntSchema(),
	  cfint::ICFIntSchema()
	{
		sessConnected = false;
		tranOpen = false;
		nextISOCcyIdGenValue = 1;
		nextISOCtryIdGenValue = 1;
		nextISOLangIdGenValue = 1;
		nextISOTZoneIdGenValue = 1;
		nextServiceTypeIdGenValue = 1;
		nextMimeTypeIdGenValue = 1;
		nextURLProtocolIdGenValue = 1;
		nextClusterIdGenValue = 1L;
		nextTenantIdGenValue = 1L;
		tableCluster = new CFIntRamClusterTable( this );
		tableHostNode = new CFIntRamHostNodeTable( this );
		tableISOCcy = new CFIntRamISOCcyTable( this );
		tableISOCtry = new CFIntRamISOCtryTable( this );
		tableISOCtryCcy = new CFIntRamISOCtryCcyTable( this );
		tableISOCtryLang = new CFIntRamISOCtryLangTable( this );
		tableISOLang = new CFIntRamISOLangTable( this );
		tableISOTZone = new CFIntRamISOTZoneTable( this );
		tableLicense = new CFIntRamLicenseTable( this );
		tableMajorVersion = new CFIntRamMajorVersionTable( this );
		tableMimeType = new CFIntRamMimeTypeTable( this );
		tableMinorVersion = new CFIntRamMinorVersionTable( this );
		tableSecApp = new CFIntRamSecAppTable( this );
		tableSecDevice = new CFIntRamSecDeviceTable( this );
		tableSecForm = new CFIntRamSecFormTable( this );
		tableSecGroup = new CFIntRamSecGroupTable( this );
		tableSecGroupForm = new CFIntRamSecGroupFormTable( this );
		tableSecGrpInc = new CFIntRamSecGrpIncTable( this );
		tableSecGrpMemb = new CFIntRamSecGrpMembTable( this );
		tableSecSession = new CFIntRamSecSessionTable( this );
		tableSecUser = new CFIntRamSecUserTable( this );
		tableService = new CFIntRamServiceTable( this );
		tableServiceType = new CFIntRamServiceTypeTable( this );
		tableSubProject = new CFIntRamSubProjectTable( this );
		tableSysCluster = new CFIntRamSysClusterTable( this );
		tableTSecGroup = new CFIntRamTSecGroupTable( this );
		tableTSecGrpInc = new CFIntRamTSecGrpIncTable( this );
		tableTSecGrpMemb = new CFIntRamTSecGrpMembTable( this );
		tableTenant = new CFIntRamTenantTable( this );
		tableTld = new CFIntRamTldTable( this );
		tableTopDomain = new CFIntRamTopDomainTable( this );
		tableTopProject = new CFIntRamTopProjectTable( this );
		tableURLProtocol = new CFIntRamURLProtocolTable( this );
	}

	CFIntRamSchema::~CFIntRamSchema() {
		tranOpen = false;
		sessConnected = false;
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

	bool CFIntRamSchema::isConnected() {
		return( sessConnected );
	}

	bool CFIntRamSchema::connect() {
		if( sessConnected ) {
			return( false );
		}
		else {
			sessConnected = true;
			tranOpen = false;
			return( true );
		}
	}

	bool CFIntRamSchema::connect( const std::string& username, const std::string& password ) {
		static const std::string S_ProcName( "connect" );
		static const std::string S_UserName( "username" );
		static const std::string S_System( "system" );
		static const std::string S_MsgOnlySystem( "Only 'system' is authorized to use a RAM database" );
		if( username.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_UserName );
		}
		if( username != S_System ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_MsgOnlySystem );
		}
		if( sessConnected ) {
			return( false );
		}
		else {
			sessConnected = true;
			tranOpen = false;
			return( true );
		}
	}

	bool CFIntRamSchema::connect( const std::string& loginId, const std::string& password, const std::string& clusterName, const std::string& tenantName ) {
		static const std::string S_ProcName( "connect" );
		static const std::string S_LoginId( "loginId" );
		static const std::string S_ClusterName( "clusterName" );
		static const std::string S_TenantName( "tenantName" );
		static const std::string S_System( "system" );
		static const std::string S_MsgOnlySystemAuthorized( "Only 'system' is authorized to use a RAM database" );
		static const std::string S_MsgOnlySystemClusterAuthorized( "Only the 'system' Cluster is authorized to use a RAM database" );
		static const std::string S_MsgOnlySystemTenantAuthorized( "Only the 'system' Tenant is authorized to use a RAM database" );
		if( loginId.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_LoginId );
		}
		if( clusterName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				3,
				S_ClusterName );
		}
		if( tenantName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				4,
				S_TenantName );
		}
		if( loginId != S_System ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_MsgOnlySystemAuthorized );
		}
		if( clusterName != S_System ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_MsgOnlySystemClusterAuthorized );
		}
		if( tenantName != S_System ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_MsgOnlySystemTenantAuthorized );
		}
		if( sessConnected ) {
			return( false );
		}
		else {
			sessConnected = true;
			tranOpen = false;
			return( true );
		}
	}

	void CFIntRamSchema::disconnect( bool doCommit ) {
		tranOpen = false;
		sessConnected = false;
	}

	//	Transactions are not supported, so pretend there is always one open

	bool CFIntRamSchema::isTransactionOpen() {
		return( tranOpen );
	}

	bool CFIntRamSchema::beginTransaction() {
		if( tranOpen ) {
			return( false );
		}
		tranOpen = true;
		return( true );
	}

	void CFIntRamSchema::commit() {
		tranOpen = false;
	}

	void CFIntRamSchema::rollback() {
		tranOpen = false;
	}

	cfint::ICFIntSchema* CFIntRamSchema::newSchema() {
		static const std::string S_ProcName( "newSchema" );
		throw cflib::CFLibMustOverrideException( CLASS_NAME, S_ProcName );
	}

	int16_t CFIntRamSchema::nextISOCcyIdGen() {
		int16_t next = nextISOCcyIdGenValue++;
		return( next );
	}

	int16_t CFIntRamSchema::nextISOCtryIdGen() {
		int16_t next = nextISOCtryIdGenValue++;
		return( next );
	}

	int16_t CFIntRamSchema::nextISOLangIdGen() {
		int16_t next = nextISOLangIdGenValue++;
		return( next );
	}

	int16_t CFIntRamSchema::nextISOTZoneIdGen() {
		int16_t next = nextISOTZoneIdGenValue++;
		return( next );
	}

	int32_t CFIntRamSchema::nextServiceTypeIdGen() {
		int32_t next = nextServiceTypeIdGenValue++;
		return( next );
	}

	int32_t CFIntRamSchema::nextMimeTypeIdGen() {
		int32_t next = nextMimeTypeIdGenValue++;
		return( next );
	}

	int32_t CFIntRamSchema::nextURLProtocolIdGen() {
		int32_t next = nextURLProtocolIdGenValue++;
		return( next );
	}

	int64_t CFIntRamSchema::nextClusterIdGen() {
		int64_t next = nextClusterIdGenValue++;
		return( next );
	}

	int64_t CFIntRamSchema::nextTenantIdGen() {
		int64_t next = nextTenantIdGenValue++;
		return( next );
	}

	void CFIntRamSchema::releasePreparedStatements() {
	}

	std::string CFIntRamSchema::fileImport( cfsec::CFSecAuthorization* Authorization,
		const std::string& fileName,
		const std::string& fileContent )
	{
		const static std::string S_ProcName( "fileImport" );
		const static std::string S_FileName( "fileName" );
		const static std::string S_FileContent( "fileContent" );
		if( fileName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				S_FileName );
		}
		if( fileContent.length() <= 0 ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				2,
				S_FileContent );
		}
		cfint::CFIntSaxLoader* saxLoader = new cfint::CFIntSaxLoader();
		cfint::ICFIntSchemaObj* schemaObj = new cfint::CFIntSchemaObj();
		schemaObj->setBackingStore( this );
		saxLoader->setSchemaObj( schemaObj );
		cfsec::ICFSecClusterObj* useCluster = schemaObj->getClusterTableObj()->readClusterByIdIdx( Authorization->getSecClusterId() );
		cfsec::ICFSecTenantObj* useTenant = schemaObj->getTenantTableObj()->readTenantByIdIdx( Authorization->getSecTenantId() );
		cflib::CFLibCachedMessageLog runlog;
		saxLoader->setLog( &runlog );
		saxLoader->setUseCluster( useCluster );
		saxLoader->setUseTenant( useTenant );
		// MSS TODO WORKING - Need to wrap parseStringContents() with try-catch so it can never crash out
		saxLoader->parseStringContents( fileName, fileContent );
		return( runlog.getCacheContents() );
	}

}
