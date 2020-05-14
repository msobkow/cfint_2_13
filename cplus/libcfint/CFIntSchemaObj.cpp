// Description: C++18 Schema Object implementation for CFInt.

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

using namespace std;

#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintobj/CFIntSchemaObj.hpp>

#include <cfintobj/CFIntClusterTableObj.hpp>
#include <cfintobj/CFIntHostNodeTableObj.hpp>
#include <cfintobj/CFIntISOCcyTableObj.hpp>
#include <cfintobj/CFIntISOCtryTableObj.hpp>
#include <cfintobj/CFIntISOCtryCcyTableObj.hpp>
#include <cfintobj/CFIntISOCtryLangTableObj.hpp>
#include <cfintobj/CFIntISOLangTableObj.hpp>
#include <cfintobj/CFIntISOTZoneTableObj.hpp>
#include <cfintobj/CFIntLicenseTableObj.hpp>
#include <cfintobj/CFIntMajorVersionTableObj.hpp>
#include <cfintobj/CFIntMimeTypeTableObj.hpp>
#include <cfintobj/CFIntMinorVersionTableObj.hpp>
#include <cfintobj/CFIntSecAppTableObj.hpp>
#include <cfintobj/CFIntSecDeviceTableObj.hpp>
#include <cfintobj/CFIntSecFormTableObj.hpp>
#include <cfintobj/CFIntSecGroupTableObj.hpp>
#include <cfintobj/CFIntSecGroupFormTableObj.hpp>
#include <cfintobj/CFIntSecGrpIncTableObj.hpp>
#include <cfintobj/CFIntSecGrpMembTableObj.hpp>
#include <cfintobj/CFIntSecSessionTableObj.hpp>
#include <cfintobj/CFIntSecUserTableObj.hpp>
#include <cfintobj/CFIntServiceTableObj.hpp>
#include <cfintobj/CFIntServiceTypeTableObj.hpp>
#include <cfintobj/CFIntSubProjectTableObj.hpp>
#include <cfintobj/CFIntSysClusterTableObj.hpp>
#include <cfintobj/CFIntTSecGroupTableObj.hpp>
#include <cfintobj/CFIntTSecGrpIncTableObj.hpp>
#include <cfintobj/CFIntTSecGrpMembTableObj.hpp>
#include <cfintobj/CFIntTenantTableObj.hpp>
#include <cfintobj/CFIntTldTableObj.hpp>
#include <cfintobj/CFIntTopDomainTableObj.hpp>
#include <cfintobj/CFIntTopProjectTableObj.hpp>
#include <cfintobj/CFIntURLProtocolTableObj.hpp>

namespace cfint {
	const std::string CFIntSchemaObj::CLASS_NAME( "CFIntSchemaObj" );
	const std::string CFIntSchemaObj::SCHEMA_NAME( "CFInt" );
	const std::string CFIntSchemaObj::SCHEMA_DBNAME( "cfinet213" );
	const std::string CFIntSchemaObj::S_System( "system" );

	CFIntSchemaObj::CFIntSchemaObj() {
		authorization = NULL;
		backingStore = NULL;
		secClusterName = new std::string( S_System );
		secTenantName = new std::string( S_System );
		secUserName = new std::string( S_System );
		secCluster = NULL;
		secClusterId = 0L;
		secTenant = NULL;
		secTenantId = 0L;
		secUser = NULL;
		for( int i = 0; i < 16; i++ ) {
			secSessionUserId[i] = 0;
		}
		secSession = NULL;
		for( int i = 0; i < 16; i++ ) {
			secSessionSessionId[i] = 0;
		}
		schemaDbName = new std::string( SCHEMA_DBNAME );
		lowerDbSchemaName = new std::string( SCHEMA_DBNAME );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );
		clusterTableObj = new CFIntClusterTableObj( this );
		hostNodeTableObj = new CFIntHostNodeTableObj( this );
		iSOCcyTableObj = new CFIntISOCcyTableObj( this );
		iSOCtryTableObj = new CFIntISOCtryTableObj( this );
		iSOCtryCcyTableObj = new CFIntISOCtryCcyTableObj( this );
		iSOCtryLangTableObj = new CFIntISOCtryLangTableObj( this );
		iSOLangTableObj = new CFIntISOLangTableObj( this );
		iSOTZoneTableObj = new CFIntISOTZoneTableObj( this );
		licenseTableObj = new CFIntLicenseTableObj( this );
		majorVersionTableObj = new CFIntMajorVersionTableObj( this );
		mimeTypeTableObj = new CFIntMimeTypeTableObj( this );
		minorVersionTableObj = new CFIntMinorVersionTableObj( this );
		secAppTableObj = new CFIntSecAppTableObj( this );
		secDeviceTableObj = new CFIntSecDeviceTableObj( this );
		secFormTableObj = new CFIntSecFormTableObj( this );
		secGroupTableObj = new CFIntSecGroupTableObj( this );
		secGroupFormTableObj = new CFIntSecGroupFormTableObj( this );
		secGrpIncTableObj = new CFIntSecGrpIncTableObj( this );
		secGrpMembTableObj = new CFIntSecGrpMembTableObj( this );
		secSessionTableObj = new CFIntSecSessionTableObj( this );
		secUserTableObj = new CFIntSecUserTableObj( this );
		serviceTableObj = new CFIntServiceTableObj( this );
		serviceTypeTableObj = new CFIntServiceTypeTableObj( this );
		subProjectTableObj = new CFIntSubProjectTableObj( this );
		sysClusterTableObj = new CFIntSysClusterTableObj( this );
		tSecGroupTableObj = new CFIntTSecGroupTableObj( this );
		tSecGrpIncTableObj = new CFIntTSecGrpIncTableObj( this );
		tSecGrpMembTableObj = new CFIntTSecGrpMembTableObj( this );
		tenantTableObj = new CFIntTenantTableObj( this );
		tldTableObj = new CFIntTldTableObj( this );
		topDomainTableObj = new CFIntTopDomainTableObj( this );
		topProjectTableObj = new CFIntTopProjectTableObj( this );
		uRLProtocolTableObj = new CFIntURLProtocolTableObj( this );
	}

	CFIntSchemaObj::~CFIntSchemaObj() {
		authorization = NULL;
		backingStore = NULL;
		if( secClusterName != NULL ) {
			delete secClusterName;
			secClusterName = NULL;
		}
		if( secTenantName != NULL ) {
			delete secTenantName;
			secTenantName = NULL;
		}
		if( secUserName != NULL ) {
			delete secUserName;
			secUserName = NULL;
		}
		secCluster = NULL;
		secClusterId = 0L;
		secTenant = NULL;
		secTenantId = 0L;
		secUser = NULL;
		for( int i = 0; i < 16; i++ ) {
			secSessionUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			secSessionSessionId[i] = 0;
		}
		if( schemaDbName != NULL ) {
			delete schemaDbName;
			schemaDbName = NULL;
		}
		if( lowerDbSchemaName != NULL ) {
			delete lowerDbSchemaName;
			lowerDbSchemaName = NULL;
		}

		if( clusterTableObj != NULL ) {
			clusterTableObj->minimizeMemory();
		}

		if( clusterTableObj != NULL ) {
			delete clusterTableObj;
			clusterTableObj = NULL;
		}

		if( hostNodeTableObj != NULL ) {
			hostNodeTableObj->minimizeMemory();
		}

		if( hostNodeTableObj != NULL ) {
			delete hostNodeTableObj;
			hostNodeTableObj = NULL;
		}

		if( iSOCcyTableObj != NULL ) {
			iSOCcyTableObj->minimizeMemory();
		}

		if( iSOCcyTableObj != NULL ) {
			delete iSOCcyTableObj;
			iSOCcyTableObj = NULL;
		}

		if( iSOCtryTableObj != NULL ) {
			iSOCtryTableObj->minimizeMemory();
		}

		if( iSOCtryTableObj != NULL ) {
			delete iSOCtryTableObj;
			iSOCtryTableObj = NULL;
		}

		if( iSOCtryCcyTableObj != NULL ) {
			iSOCtryCcyTableObj->minimizeMemory();
		}

		if( iSOCtryCcyTableObj != NULL ) {
			delete iSOCtryCcyTableObj;
			iSOCtryCcyTableObj = NULL;
		}

		if( iSOCtryLangTableObj != NULL ) {
			iSOCtryLangTableObj->minimizeMemory();
		}

		if( iSOCtryLangTableObj != NULL ) {
			delete iSOCtryLangTableObj;
			iSOCtryLangTableObj = NULL;
		}

		if( iSOLangTableObj != NULL ) {
			iSOLangTableObj->minimizeMemory();
		}

		if( iSOLangTableObj != NULL ) {
			delete iSOLangTableObj;
			iSOLangTableObj = NULL;
		}

		if( iSOTZoneTableObj != NULL ) {
			iSOTZoneTableObj->minimizeMemory();
		}

		if( iSOTZoneTableObj != NULL ) {
			delete iSOTZoneTableObj;
			iSOTZoneTableObj = NULL;
		}

		if( licenseTableObj != NULL ) {
			licenseTableObj->minimizeMemory();
		}

		if( licenseTableObj != NULL ) {
			delete licenseTableObj;
			licenseTableObj = NULL;
		}

		if( majorVersionTableObj != NULL ) {
			majorVersionTableObj->minimizeMemory();
		}

		if( majorVersionTableObj != NULL ) {
			delete majorVersionTableObj;
			majorVersionTableObj = NULL;
		}

		if( mimeTypeTableObj != NULL ) {
			mimeTypeTableObj->minimizeMemory();
		}

		if( mimeTypeTableObj != NULL ) {
			delete mimeTypeTableObj;
			mimeTypeTableObj = NULL;
		}

		if( minorVersionTableObj != NULL ) {
			minorVersionTableObj->minimizeMemory();
		}

		if( minorVersionTableObj != NULL ) {
			delete minorVersionTableObj;
			minorVersionTableObj = NULL;
		}

		if( secAppTableObj != NULL ) {
			secAppTableObj->minimizeMemory();
		}

		if( secAppTableObj != NULL ) {
			delete secAppTableObj;
			secAppTableObj = NULL;
		}

		if( secDeviceTableObj != NULL ) {
			secDeviceTableObj->minimizeMemory();
		}

		if( secDeviceTableObj != NULL ) {
			delete secDeviceTableObj;
			secDeviceTableObj = NULL;
		}

		if( secFormTableObj != NULL ) {
			secFormTableObj->minimizeMemory();
		}

		if( secFormTableObj != NULL ) {
			delete secFormTableObj;
			secFormTableObj = NULL;
		}

		if( secGroupTableObj != NULL ) {
			secGroupTableObj->minimizeMemory();
		}

		if( secGroupTableObj != NULL ) {
			delete secGroupTableObj;
			secGroupTableObj = NULL;
		}

		if( secGroupFormTableObj != NULL ) {
			secGroupFormTableObj->minimizeMemory();
		}

		if( secGroupFormTableObj != NULL ) {
			delete secGroupFormTableObj;
			secGroupFormTableObj = NULL;
		}

		if( secGrpIncTableObj != NULL ) {
			secGrpIncTableObj->minimizeMemory();
		}

		if( secGrpIncTableObj != NULL ) {
			delete secGrpIncTableObj;
			secGrpIncTableObj = NULL;
		}

		if( secGrpMembTableObj != NULL ) {
			secGrpMembTableObj->minimizeMemory();
		}

		if( secGrpMembTableObj != NULL ) {
			delete secGrpMembTableObj;
			secGrpMembTableObj = NULL;
		}

		if( secSessionTableObj != NULL ) {
			secSessionTableObj->minimizeMemory();
		}

		if( secSessionTableObj != NULL ) {
			delete secSessionTableObj;
			secSessionTableObj = NULL;
		}

		if( secUserTableObj != NULL ) {
			secUserTableObj->minimizeMemory();
		}

		if( secUserTableObj != NULL ) {
			delete secUserTableObj;
			secUserTableObj = NULL;
		}

		if( serviceTableObj != NULL ) {
			serviceTableObj->minimizeMemory();
		}

		if( serviceTableObj != NULL ) {
			delete serviceTableObj;
			serviceTableObj = NULL;
		}

		if( serviceTypeTableObj != NULL ) {
			serviceTypeTableObj->minimizeMemory();
		}

		if( serviceTypeTableObj != NULL ) {
			delete serviceTypeTableObj;
			serviceTypeTableObj = NULL;
		}

		if( subProjectTableObj != NULL ) {
			subProjectTableObj->minimizeMemory();
		}

		if( subProjectTableObj != NULL ) {
			delete subProjectTableObj;
			subProjectTableObj = NULL;
		}

		if( sysClusterTableObj != NULL ) {
			sysClusterTableObj->minimizeMemory();
		}

		if( sysClusterTableObj != NULL ) {
			delete sysClusterTableObj;
			sysClusterTableObj = NULL;
		}

		if( tSecGroupTableObj != NULL ) {
			tSecGroupTableObj->minimizeMemory();
		}

		if( tSecGroupTableObj != NULL ) {
			delete tSecGroupTableObj;
			tSecGroupTableObj = NULL;
		}

		if( tSecGrpIncTableObj != NULL ) {
			tSecGrpIncTableObj->minimizeMemory();
		}

		if( tSecGrpIncTableObj != NULL ) {
			delete tSecGrpIncTableObj;
			tSecGrpIncTableObj = NULL;
		}

		if( tSecGrpMembTableObj != NULL ) {
			tSecGrpMembTableObj->minimizeMemory();
		}

		if( tSecGrpMembTableObj != NULL ) {
			delete tSecGrpMembTableObj;
			tSecGrpMembTableObj = NULL;
		}

		if( tenantTableObj != NULL ) {
			tenantTableObj->minimizeMemory();
		}

		if( tenantTableObj != NULL ) {
			delete tenantTableObj;
			tenantTableObj = NULL;
		}

		if( tldTableObj != NULL ) {
			tldTableObj->minimizeMemory();
		}

		if( tldTableObj != NULL ) {
			delete tldTableObj;
			tldTableObj = NULL;
		}

		if( topDomainTableObj != NULL ) {
			topDomainTableObj->minimizeMemory();
		}

		if( topDomainTableObj != NULL ) {
			delete topDomainTableObj;
			topDomainTableObj = NULL;
		}

		if( topProjectTableObj != NULL ) {
			topProjectTableObj->minimizeMemory();
		}

		if( topProjectTableObj != NULL ) {
			delete topProjectTableObj;
			topProjectTableObj = NULL;
		}

		if( uRLProtocolTableObj != NULL ) {
			uRLProtocolTableObj->minimizeMemory();
		}

		if( uRLProtocolTableObj != NULL ) {
			delete uRLProtocolTableObj;
			uRLProtocolTableObj = NULL;
		}
	}

	void CFIntSchemaObj::setSecClusterName( const std::string& value ) {
		if( value.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				"setClusterName",
				1,
				"value" );
		}
		if( secClusterName != NULL ) {
			delete secClusterName;
			secClusterName = NULL;
		}
		secClusterName = new std::string( value );
		secCluster = NULL;
	}

	std::string CFIntSchemaObj::getSecClusterName() {
		std::string retval( *secClusterName );
		return( retval );
	}

	cfsec::ICFSecClusterObj* CFIntSchemaObj::getSecCluster() {
		if( secCluster == NULL ) {
			if( authorization != NULL ) {
				secCluster = getClusterTableObj()->readClusterByIdIdx( authorization->getSecClusterId() );
			}
			else {
				secCluster = getClusterTableObj()->readClusterByUDomNameIdx( *secClusterName );
				if( ( secCluster == NULL ) && ( secClusterId > 0 ) ) {
					secCluster = getClusterTableObj()->readClusterByIdIdx( secClusterId );
				}
			}
			if( secCluster != NULL ) {
				if( secClusterName != NULL ) {
					delete secClusterName;
					secClusterName = NULL;
				}
				secClusterName = new std::string( secCluster->getRequiredFullDomName() );
				secClusterId = secCluster->getRequiredId();
				if( authorization != NULL ) {
					authorization->setSecCluster( *secCluster );
				}
			}
		}
		return( secCluster );
	}

	void CFIntSchemaObj::setSecCluster( cfsec::ICFSecClusterObj* value ) {
		secCluster = value;
		if( secCluster == NULL ) {
			return;
		}
		secClusterId = secCluster->getRequiredId();
		if( secClusterName != NULL ) {
			delete secClusterName;
			secClusterName = NULL;
		}
		secClusterName = new std::string( secCluster->getRequiredFullDomName() );
		if( authorization != NULL ) {
			authorization->setSecCluster( *secCluster );
		}
	}

	long CFIntSchemaObj::getSecClusterId() {
		return( secClusterId );
	}

	void CFIntSchemaObj::setSecTenantName( const std::string& value ) {
		if( value.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				"setTenantName",
				1,
				"value" );
		}
		if( secTenantName != NULL ) {
			delete secTenantName;
			secTenantName = NULL;
		}
		secTenantName = new std::string( value );
		secTenant = NULL;
	}

	std::string CFIntSchemaObj::getSecTenantName() {
		std::string retval( *secTenantName );
		return( retval );
	}

	cfsec::ICFSecTenantObj* CFIntSchemaObj::getSecTenant() {
		if( secTenant == NULL ) {
			if( authorization != NULL ) {
				secTenant = getTenantTableObj()->readTenantByIdIdx( authorization->getSecTenantId() );
			}
			else {
				secTenant = getTenantTableObj()->readTenantByUNameIdx( getSecCluster()->getRequiredId(), *secTenantName );
				if( ( secTenant == NULL ) && ( secTenantId > 0 ) ) {
					secTenant = getTenantTableObj()->readTenantByIdIdx( secTenantId );
				}
			}
			if( secTenant != NULL ) {
				if( secTenantName != NULL ) {
					delete secTenantName;
					secTenantName = NULL;
				}
				secTenantName = new std::string( secTenant->getRequiredTenantName() );
				secTenantId = secTenant->getRequiredId();
				if( authorization != NULL ) {
					authorization->setSecTenant( *secTenant );
				}
			}
		}
		return( secTenant );
	}

	void CFIntSchemaObj::setSecTenant( cfsec::ICFSecTenantObj* value ) {
		secTenant = value;
		if( secTenant == NULL ) {
			return;
		}
		secTenantId = secTenant->getRequiredId();
		if( secTenantName != NULL ) {
			delete secTenantName;
			secTenantName = NULL;
		}
		secTenantName = new std::string( secTenant->getRequiredTenantName() );
		if( authorization != NULL ) {
			authorization->setSecTenant( *secTenant );
		}
	}

	long CFIntSchemaObj::getSecTenantId() {
		return( secTenantId );
	}

	void CFIntSchemaObj::setSecUserName( const std::string& value ) {
		if( value.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				"setUserName",
				1,
				"value" );
		}
		if( secUserName != NULL ) {
			delete secUserName;
			secUserName = NULL;
		}
		secUserName = new std::string( value );
		secUser = NULL;
	}

	std::string CFIntSchemaObj::getSecUserName() {
		std::string retval( *secUserName );
		return( retval );
	}

	cfsec::ICFSecSecUserObj* CFIntSchemaObj::getSecUser() {
		if( secUser == NULL ) {
			if( authorization != NULL ) {
				secUser = getSecUserTableObj()->readSecUserByIdIdx( authorization->getSecUserId() );
			}
			else {
				secUser = getSecUserTableObj()->readSecUserByULoginIdx( *secUserName );
				if( ( secUser == NULL ) &&
					( ( secSessionUserId[0] != 0 ) || ( secSessionUserId[1] != 0 )
						|| ( secSessionUserId[2] != 0 ) || ( secSessionUserId[3] != 0 )
						|| ( secSessionUserId[4] != 0 ) || ( secSessionUserId[5] != 0 )
						|| ( secSessionUserId[6] != 0 ) || ( secSessionUserId[7] != 0 )
						|| ( secSessionUserId[8] != 0 ) || ( secSessionUserId[9] != 0 )
						|| ( secSessionUserId[10] != 0 ) || ( secSessionUserId[11] != 0 )
						|| ( secSessionUserId[12] != 0 ) || ( secSessionUserId[13] != 0 )
						|| ( secSessionUserId[14] != 0 ) || ( secSessionUserId[15] != 0 ) ) )
				{
					secUser = getSecUserTableObj()->readSecUserByIdIdx( secSessionUserId );
				}
			}
			if( secUser != NULL ) {
				if( secUserName != NULL ) {
					delete secUserName;
					secUserName = NULL;
				}
				secUserName = new std::string( secUser->getRequiredLoginId() );
				uuid_copy( secSessionUserId, secUser->getRequiredSecUserId() );
			}
		}
		return( secUser );
	}

	void CFIntSchemaObj::setSecUser( cfsec::ICFSecSecUserObj* value ) {
		secUser = value;
		if( secUser != NULL ) {
			if( secUserName != NULL ) {
				delete secUserName;
				secUserName = NULL;
			}
			secUserName = new std::string( secUser->getRequiredLoginId() );
			uuid_copy( secSessionUserId, secUser->getRequiredSecUserId() );
		}
	}
	cfsec::ICFSecSecSessionObj* CFIntSchemaObj::getSecSession() {
		if( secSession == NULL ) {
			if( authorization != NULL ) {
				secSession = getSecSessionTableObj()->readSecSessionByIdIdx( authorization->getSecSessionId() );
			}
			else if( ( secSessionSessionId[0] != 0 )
				|| ( secSessionSessionId[1] != 0 )
				|| ( secSessionSessionId[2] != 0 )
				|| ( secSessionSessionId[3] != 0 )
				|| ( secSessionSessionId[4] != 0 )
				|| ( secSessionSessionId[5] != 0 )
				|| ( secSessionSessionId[6] != 0 )
				|| ( secSessionSessionId[7] != 0 )
				|| ( secSessionSessionId[8] != 0 )
				|| ( secSessionSessionId[9] != 0 )
				|| ( secSessionSessionId[10] != 0 )
				|| ( secSessionSessionId[11] != 0 )
				|| ( secSessionSessionId[12] != 0 )
				|| ( secSessionSessionId[13] != 0 )
				|| ( secSessionSessionId[14] != 0 )
				|| ( secSessionSessionId[15] != 0 ) )
			{
				secSession = getSecSessionTableObj()->readSecSessionByIdIdx( secSessionSessionId );
			}
			if( secSession != NULL ) {
				uuid_copy( secSessionSessionId, secSession->getRequiredSecSessionId() );
				uuid_copy( secSessionUserId, secSession->getRequiredSecUserId() );
			}
		}
		return( secSession );
	}

	void CFIntSchemaObj::setSecSession( cfsec::ICFSecSecSessionObj* value ) {
		secSession = value;
		if( secSession == NULL ) {
			return;
		}
		uuid_copy( secSessionSessionId, secSession->getRequiredSecSessionId() );
		uuid_copy( secSessionUserId, secSession->getRequiredSecUserId() );
		if( authorization != NULL ) {
			authorization->setSecSession( secSession );
		}
	}

	void CFIntSchemaObj::setSecSessionId( const uuid_ptr_t value ) {
		uuid_copy( secSessionSessionId, value );
	}

	uuid_ptr_t CFIntSchemaObj::getSecSessionSessionId() {
		return( secSessionSessionId );
	}

	uuid_ptr_t CFIntSchemaObj::getSecSessionUserId() {
		return( secSessionUserId );
	}

	std::string CFIntSchemaObj::getDbSchemaName() {
		std::string retval( *schemaDbName );
		return( retval );
	}

	std::string CFIntSchemaObj::getLowerDbSchemaName() {
		std::string retval( *lowerDbSchemaName );
		return( retval );
	}

	void CFIntSchemaObj::setDbSchemaName( const std::string& argDbSchemaName ) {
		static const std::string S_ProcName = "setDbSchemaName";

		rollback();

		if( argDbSchemaName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				"argDbSchemaName" );
		}

		if( backingStore != NULL ) {
			backingStore->setDbSchemaName( argDbSchemaName );
		}

		if( schemaDbName != NULL ) {
			delete schemaDbName;
			schemaDbName = NULL;
		}
		schemaDbName = new std::string( argDbSchemaName );
		lowerDbSchemaName = new std::string( argDbSchemaName );
		std::transform( lowerDbSchemaName->begin(), lowerDbSchemaName->end(), lowerDbSchemaName->begin(), ::tolower );

		releasePreparedStatements();
	}

	std::string CFIntSchemaObj::fileImport( const std::string& fileName, const std::string& fileContent ) {
		std::string logContent = backingStore->fileImport( getAuthorization(), fileName, fileContent );
		return( logContent );
	}

	/**
	 *	Release any prepared statements acquired by this connection.
	 *	<p>
	 *	Resets the prepared statements so they can acquire the new value of
	 *	<tt>setDbSchemaName()</tt>.
	 */
	void CFIntSchemaObj::releasePreparedStatements() {
	}
	cfsec::CFSecAuthorization* CFIntSchemaObj::getAuthorization() const {
		return( authorization );
	}

	void CFIntSchemaObj::setAuthorization( cfsec::CFSecAuthorization* value ) {
		authorization = value;
	}

	cfsec::ICFSecSchema* CFIntSchemaObj::getBackingStore() {
		return( backingStore );
	}

	void CFIntSchemaObj::setBackingStore( cfsec::ICFSecSchema* value ) {
		backingStore = value;
	}

	std::string CFIntSchemaObj::getSchemaName() {
		return( SCHEMA_NAME );
	}

	bool CFIntSchemaObj::isConnected() {
		if( backingStore == NULL ) {
			return( false );
		}
		else {
			return( backingStore->isConnected() );
		}
	}

	bool CFIntSchemaObj::connect() {
		return( backingStore->connect() );
	}

	bool CFIntSchemaObj::connect( const std::string& username, const std::string& password ) {
		return( backingStore->connect( username, password ) );
	}

	bool CFIntSchemaObj::connect( const std::string& clusterName, const std::string& tenantName, const std::string& secUserName, const std::string& password ) {
		static const std::string S_ProcName = "connect-full";
		if( clusterName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				1,
				"clusterName" );
		}
		if( tenantName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				2,
				"tenantName" );
		}
		if( secUserName.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				3,
				"secUserName" );
		}
		if( password.length() <= 0 ) {
			throw cflib::CFLibEmptyArgumentException( CLASS_NAME,
				S_ProcName,
				5,
				"password" );
		}
		if( ! backingStore->connect( secUserName, password, clusterName, tenantName ) ) {
			authorization = NULL;
			return( false );
		}
		if( authorization != NULL ) {
			// The login was established as an XMsg client, which automatically sets the Authorization
			// information based on the return message.  You only need to do the remaining SecSession
			// and authorization creation if you're using a direct client-server model instead of
			// an XMsg client-server model.
			setSecClusterName( clusterName );
			setSecTenantName( tenantName );
			setSecUserName( secUserName );
			return( true );
		}

		if( ( clusterName == S_System )
		 && ( tenantName == S_System )
		 && ( secUserName == S_System ) )
		{
			if( secCluster == NULL ) {
				secCluster = getClusterTableObj()->newInstance();
				cfsec::ICFSecClusterEditObj* editCluster = secCluster->getEdit();
				if( editCluster == NULL ) {
					editCluster = secCluster->beginEdit();
					editCluster->setRequiredDescription( S_System );
					editCluster->setRequiredFullDomName( S_System );
					secCluster = editCluster->create();
					editCluster = NULL;
				}
			}
			if( secTenant == NULL ) {
				secTenant = getTenantTableObj()->newInstance();
				cfsec::ICFSecTenantEditObj* editTenant = secTenant->getEdit();
				if( editTenant == NULL ) {
					editTenant = secTenant->beginEdit();
					editTenant->setRequiredContainerCluster( secCluster);
					editTenant->setRequiredTenantName( S_System );
					secTenant = editTenant->create();
					editTenant = NULL;
				}
			}
			if( secUser == NULL ) {
				secUser = getSecUserTableObj()->newInstance();
				cfsec::ICFSecSecUserEditObj* editSecUser = secUser->getEdit();
				if( editSecUser == NULL ) {
					editSecUser = secUser->beginEdit();
					editSecUser->setRequiredEMailAddress( S_System );
					editSecUser->setRequiredLoginId( S_System );
					secUser = editSecUser->create();
					editSecUser = NULL;
				}
			}
			setSecClusterName( clusterName );
			setSecTenantName( tenantName );
			setSecUserName( secUserName );
			secCluster = NULL;
			secTenant = NULL;
			secUser = NULL;
			secSession = NULL;
			cfsec::ICFSecClusterObj* cluster = getSecCluster();
			cfsec::ICFSecTenantObj* tenant = getSecTenant();
			cfsec::ICFSecSecUserObj* user = getSecUser();
			cfsec::ICFSecSecSessionObj* session;
			if( ( cluster != NULL ) && ( tenant != NULL ) && ( user != NULL ) ) {
				session = getSecSessionTableObj()->newInstance();
				cfsec::ICFSecSecSessionEditObj* sessionEdit = session->beginEdit();
				sessionEdit->setRequiredContainerSecUser( user );
				std::chrono::system_clock::time_point timestamp = cflib::CFLib::getUTCTimestampInstance();
				sessionEdit->setRequiredStart( timestamp );
				sessionEdit->setOptionalFinishNull();
				session = sessionEdit->create();
				setSecSession( session );
			}
			else {
				session = NULL;
			}
			if( ( cluster == NULL ) || ( tenant == NULL ) || ( user == NULL ) || ( session == NULL ) ) {
				disconnect( false );
				authorization = NULL;
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					"Could not resolve cluster name, tenant name, user name, or session.  Login cancelled" );
			}
			if( authorization == NULL ) {
				authorization = new cfsec::CFSecAuthorization();
			}
			authorization->setSecCluster( *cluster );
			authorization->setSecTenant( *tenant );
			authorization->setSecSession( session );
			return( true );
		}
		setSecClusterName( clusterName );
		setSecTenantName( tenantName );
		setSecUserName( secUserName );
		bool transactionStarted = beginTransaction();
		secCluster = NULL;
		secTenant = NULL;
		secUser = NULL;
		secSession = NULL;
		cfsec::ICFSecClusterObj* cluster = getSecCluster();
		cfsec::ICFSecTenantObj* tenant = getSecTenant();
		cfsec::ICFSecSecUserObj* user = getSecUser();
		cfsec::ICFSecSecSessionObj* session;
		if( ( cluster != NULL ) && ( tenant != NULL ) && ( user != NULL ) ) {
			session = getSecSessionTableObj()->newInstance();
			cfsec::ICFSecSecSessionEditObj* sessionEdit = session->beginEdit();
			sessionEdit->setRequiredContainerSecUser( user );
			std::chrono::system_clock::time_point timestamp = cflib::CFLib::getUTCTimestampInstance();
			sessionEdit->setRequiredStart( timestamp );
			sessionEdit->setOptionalFinishNull();
			session = sessionEdit->create();
			setSecSession( session );
		}
		else {
			session = NULL;
		}
		if( transactionStarted ) {
			commit();
		}
		if( ( cluster == NULL ) || ( tenant == NULL ) || ( user == NULL ) || ( session == NULL ) ) {
			disconnect( false );
			authorization = NULL;
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				"Could not resolve cluster name, tenant name, user name, or session.  Login cancelled" );
		}
		if( authorization == NULL ) {
			authorization = new cfsec::CFSecAuthorization();
		}
		authorization->setSecCluster( *cluster );
		authorization->setSecTenant( *tenant );
		authorization->setSecSession( session );
		return( true );
	}

	void CFIntSchemaObj::disconnect( bool doCommit ) {
		backingStore->disconnect( doCommit );
	}

	void CFIntSchemaObj::logout() {
		if( authorization == NULL ) {
			if( isConnected() ) {
				disconnect( false );
			}
			return;
		}
		if( isConnected() ) {
			try {
				bool transactionStarted = beginTransaction();
				if( ! transactionStarted ) {
					rollback();
					transactionStarted = beginTransaction();
					if( ! transactionStarted ) {
						setAuthorization( NULL );
						return;
					}
				}
				const uuid_ptr_t secSessionId = authorization->getSecSessionId();
				if( ( secSessionId[0] != 0 )
					|| ( secSessionId[1] != 0 )
					|| ( secSessionId[2] != 0 )
					|| ( secSessionId[3] != 0 )
					|| ( secSessionId[4] != 0 )
					|| ( secSessionId[5] != 0 )
					|| ( secSessionId[6] != 0 )
					|| ( secSessionId[7] != 0 )
					|| ( secSessionId[8] != 0 )
					|| ( secSessionId[9] != 0 )
					|| ( secSessionId[10] != 0 )
					|| ( secSessionId[11] != 0 )
					|| ( secSessionId[12] != 0 )
					|| ( secSessionId[13] != 0 )
					|| ( secSessionId[14] != 0 )
					|| ( secSessionId[15] != 0 ) )
				{
					cfsec::ICFSecSecSessionObj* secSession = getSecSessionTableObj()->readSecSessionByIdIdx( secSessionId );
					if( secSession != NULL ) {
						if( secSession->isOptionalFinishNull() ) {
							cfsec::ICFSecSecSessionEditObj* editSecSession = secSession->beginEdit();
							std::chrono::system_clock::time_point timestamp = cflib::CFLib::getUTCTimestampInstance();
							editSecSession->setOptionalFinishValue( timestamp );
							editSecSession->update();
							editSecSession = NULL;
						}
					}
				}
				commit();
			}
			catch( std::exception x ) {
				setAuthorization( NULL );
				try {
					disconnect( false );
				}
				catch( std::exception e ) {
				}
			}
			setAuthorization( NULL );
			try {
				disconnect( false );
			}
			catch( std::exception e ) {
			}
		}
	}

	void CFIntSchemaObj::minimizeMemory() {
		if( clusterTableObj != NULL ) {
			clusterTableObj->minimizeMemory();
		}
		if( hostNodeTableObj != NULL ) {
			hostNodeTableObj->minimizeMemory();
		}
		if( iSOCcyTableObj != NULL ) {
			iSOCcyTableObj->minimizeMemory();
		}
		if( iSOCtryTableObj != NULL ) {
			iSOCtryTableObj->minimizeMemory();
		}
		if( iSOCtryCcyTableObj != NULL ) {
			iSOCtryCcyTableObj->minimizeMemory();
		}
		if( iSOCtryLangTableObj != NULL ) {
			iSOCtryLangTableObj->minimizeMemory();
		}
		if( iSOLangTableObj != NULL ) {
			iSOLangTableObj->minimizeMemory();
		}
		if( iSOTZoneTableObj != NULL ) {
			iSOTZoneTableObj->minimizeMemory();
		}
		if( licenseTableObj != NULL ) {
			licenseTableObj->minimizeMemory();
		}
		if( majorVersionTableObj != NULL ) {
			majorVersionTableObj->minimizeMemory();
		}
		if( mimeTypeTableObj != NULL ) {
			mimeTypeTableObj->minimizeMemory();
		}
		if( minorVersionTableObj != NULL ) {
			minorVersionTableObj->minimizeMemory();
		}
		if( secAppTableObj != NULL ) {
			secAppTableObj->minimizeMemory();
		}
		if( secDeviceTableObj != NULL ) {
			secDeviceTableObj->minimizeMemory();
		}
		if( secFormTableObj != NULL ) {
			secFormTableObj->minimizeMemory();
		}
		if( secGroupTableObj != NULL ) {
			secGroupTableObj->minimizeMemory();
		}
		if( secGroupFormTableObj != NULL ) {
			secGroupFormTableObj->minimizeMemory();
		}
		if( secGrpIncTableObj != NULL ) {
			secGrpIncTableObj->minimizeMemory();
		}
		if( secGrpMembTableObj != NULL ) {
			secGrpMembTableObj->minimizeMemory();
		}
		if( secSessionTableObj != NULL ) {
			secSessionTableObj->minimizeMemory();
		}
		if( secUserTableObj != NULL ) {
			secUserTableObj->minimizeMemory();
		}
		if( serviceTableObj != NULL ) {
			serviceTableObj->minimizeMemory();
		}
		if( serviceTypeTableObj != NULL ) {
			serviceTypeTableObj->minimizeMemory();
		}
		if( subProjectTableObj != NULL ) {
			subProjectTableObj->minimizeMemory();
		}
		if( sysClusterTableObj != NULL ) {
			sysClusterTableObj->minimizeMemory();
		}
		if( tSecGroupTableObj != NULL ) {
			tSecGroupTableObj->minimizeMemory();
		}
		if( tSecGrpIncTableObj != NULL ) {
			tSecGrpIncTableObj->minimizeMemory();
		}
		if( tSecGrpMembTableObj != NULL ) {
			tSecGrpMembTableObj->minimizeMemory();
		}
		if( tenantTableObj != NULL ) {
			tenantTableObj->minimizeMemory();
		}
		if( tldTableObj != NULL ) {
			tldTableObj->minimizeMemory();
		}
		if( topDomainTableObj != NULL ) {
			topDomainTableObj->minimizeMemory();
		}
		if( topProjectTableObj != NULL ) {
			topProjectTableObj->minimizeMemory();
		}
		if( uRLProtocolTableObj != NULL ) {
			uRLProtocolTableObj->minimizeMemory();
		}
	}

	bool CFIntSchemaObj::isTransactionOpen() {
		bool txnOpen = backingStore->isTransactionOpen();
		return( txnOpen );
	}

	bool CFIntSchemaObj::beginTransaction() {
		bool txnInitiated = backingStore->beginTransaction();
		return( txnInitiated );
	}

	void CFIntSchemaObj::commit() {
		backingStore->commit();
	}

	void CFIntSchemaObj::rollback() {
		backingStore->rollback();
	}
	cfsec::ICFSecClusterTableObj* CFIntSchemaObj::getClusterTableObj() {
		return( clusterTableObj );
	}

	cfsec::ICFSecHostNodeTableObj* CFIntSchemaObj::getHostNodeTableObj() {
		return( hostNodeTableObj );
	}

	cfsec::ICFSecISOCcyTableObj* CFIntSchemaObj::getISOCcyTableObj() {
		return( iSOCcyTableObj );
	}

	cfsec::ICFSecISOCtryTableObj* CFIntSchemaObj::getISOCtryTableObj() {
		return( iSOCtryTableObj );
	}

	cfsec::ICFSecISOCtryCcyTableObj* CFIntSchemaObj::getISOCtryCcyTableObj() {
		return( iSOCtryCcyTableObj );
	}

	cfsec::ICFSecISOCtryLangTableObj* CFIntSchemaObj::getISOCtryLangTableObj() {
		return( iSOCtryLangTableObj );
	}

	cfsec::ICFSecISOLangTableObj* CFIntSchemaObj::getISOLangTableObj() {
		return( iSOLangTableObj );
	}

	cfsec::ICFSecISOTZoneTableObj* CFIntSchemaObj::getISOTZoneTableObj() {
		return( iSOTZoneTableObj );
	}

	cfint::ICFIntLicenseTableObj* CFIntSchemaObj::getLicenseTableObj() {
		return( licenseTableObj );
	}

	cfint::ICFIntMajorVersionTableObj* CFIntSchemaObj::getMajorVersionTableObj() {
		return( majorVersionTableObj );
	}

	cfint::ICFIntMimeTypeTableObj* CFIntSchemaObj::getMimeTypeTableObj() {
		return( mimeTypeTableObj );
	}

	cfint::ICFIntMinorVersionTableObj* CFIntSchemaObj::getMinorVersionTableObj() {
		return( minorVersionTableObj );
	}

	cfsec::ICFSecSecAppTableObj* CFIntSchemaObj::getSecAppTableObj() {
		return( secAppTableObj );
	}

	cfsec::ICFSecSecDeviceTableObj* CFIntSchemaObj::getSecDeviceTableObj() {
		return( secDeviceTableObj );
	}

	cfsec::ICFSecSecFormTableObj* CFIntSchemaObj::getSecFormTableObj() {
		return( secFormTableObj );
	}

	cfsec::ICFSecSecGroupTableObj* CFIntSchemaObj::getSecGroupTableObj() {
		return( secGroupTableObj );
	}

	cfsec::ICFSecSecGroupFormTableObj* CFIntSchemaObj::getSecGroupFormTableObj() {
		return( secGroupFormTableObj );
	}

	cfsec::ICFSecSecGrpIncTableObj* CFIntSchemaObj::getSecGrpIncTableObj() {
		return( secGrpIncTableObj );
	}

	cfsec::ICFSecSecGrpMembTableObj* CFIntSchemaObj::getSecGrpMembTableObj() {
		return( secGrpMembTableObj );
	}

	cfsec::ICFSecSecSessionTableObj* CFIntSchemaObj::getSecSessionTableObj() {
		return( secSessionTableObj );
	}

	cfsec::ICFSecSecUserTableObj* CFIntSchemaObj::getSecUserTableObj() {
		return( secUserTableObj );
	}

	cfsec::ICFSecServiceTableObj* CFIntSchemaObj::getServiceTableObj() {
		return( serviceTableObj );
	}

	cfsec::ICFSecServiceTypeTableObj* CFIntSchemaObj::getServiceTypeTableObj() {
		return( serviceTypeTableObj );
	}

	cfint::ICFIntSubProjectTableObj* CFIntSchemaObj::getSubProjectTableObj() {
		return( subProjectTableObj );
	}

	cfsec::ICFSecSysClusterTableObj* CFIntSchemaObj::getSysClusterTableObj() {
		return( sysClusterTableObj );
	}

	cfsec::ICFSecTSecGroupTableObj* CFIntSchemaObj::getTSecGroupTableObj() {
		return( tSecGroupTableObj );
	}

	cfsec::ICFSecTSecGrpIncTableObj* CFIntSchemaObj::getTSecGrpIncTableObj() {
		return( tSecGrpIncTableObj );
	}

	cfsec::ICFSecTSecGrpMembTableObj* CFIntSchemaObj::getTSecGrpMembTableObj() {
		return( tSecGrpMembTableObj );
	}

	cfsec::ICFSecTenantTableObj* CFIntSchemaObj::getTenantTableObj() {
		return( tenantTableObj );
	}

	cfint::ICFIntTldTableObj* CFIntSchemaObj::getTldTableObj() {
		return( tldTableObj );
	}

	cfint::ICFIntTopDomainTableObj* CFIntSchemaObj::getTopDomainTableObj() {
		return( topDomainTableObj );
	}

	cfint::ICFIntTopProjectTableObj* CFIntSchemaObj::getTopProjectTableObj() {
		return( topProjectTableObj );
	}

	cfint::ICFIntURLProtocolTableObj* CFIntSchemaObj::getURLProtocolTableObj() {
		return( uRLProtocolTableObj );
	}
}
