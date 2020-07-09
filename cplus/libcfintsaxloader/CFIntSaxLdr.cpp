// Description: C++18 XML Command Line Interface common core implementation for CFInt.

/*
 *	org.msscf.msscf.CFInt
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
#include <cfintobj/ICFIntObjPublic.hpp>

#include <cfintsaxloader/CFIntSaxLoader.hpp>
#include <cfintsaxloader/CFIntSaxLdr.hpp>

namespace cfint {

	const std::string CFIntSaxLdr::CLASS_NAME( "CFIntSaxLdr" );
	const std::string CFIntSaxLdr::S_SYSTEM( "system" );
	const std::string CFIntSaxLdr::S_UnhandledException( "Unhandled exception" );

	CFIntSaxLdr::CFIntSaxLdr() {
		log = NULL;
		saxLoader = NULL;
		clusterName = new std::string( S_SYSTEM );
		clusterObj = NULL;
		tenantName = new std::string( S_SYSTEM );
		tenantObj = NULL;
		secUserName = new std::string( S_SYSTEM );
		secUserObj = NULL;
		secSessionObj = NULL;
	}

	CFIntSaxLdr::~CFIntSaxLdr() {
		if( saxLoader != NULL ) {
			delete saxLoader;
			saxLoader = NULL;
		}
		if( clusterName != NULL ) {
			delete clusterName;
			clusterName = NULL;
		}
		if( tenantName != NULL ) {
			delete tenantName;
			tenantName = NULL;
		}
		if( secUserName != NULL ) {
			delete secUserName;
			secUserName = NULL;
		}
		clusterObj = NULL;
		tenantObj = NULL;
		secUserObj = NULL;
		secSessionObj = NULL;
	}

	CFIntSaxLdr::CFIntSaxLdr( cflib::ICFLibMessageLog* messageLog ) {
		log = messageLog;
		saxLoader = NULL;
		clusterName = new std::string( S_SYSTEM );
		clusterObj = NULL;
		tenantName = new std::string( S_SYSTEM );
		tenantObj = NULL;
		secUserName = new std::string( S_SYSTEM );
		secUserObj = NULL;
		secSessionObj = NULL;
		getSaxLoader();
	}

	void CFIntSaxLdr::setSaxLoader( cfint::CFIntSaxLoader* value ) {
		saxLoader = value;
	}

	cfint::CFIntSaxLoader* CFIntSaxLdr::getSaxLoader() {
		static const std::string S_ProcName( "getSaxLoader" );
		static const std::string S_Log( "log" );
		if( log == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_Log );
		}
		if( saxLoader == NULL ) {
			saxLoader = new CFIntSaxLoader( log );
		}
		return( saxLoader );
	}

	void CFIntSaxLdr::setClusterName( const std::string& value ) {
		const static std::string S_ProcName( "setClusterName" );
		const static std::string S_Default( "default" );
		const static std::string S_System( "system" );
		const static std::string S_ReadClusterSystem( "readClusterByUDomName-system" );
		const static std::string S_ExpectedValues( "Expected value to by 'default' or 'system'" );
		CFLIB_EXCEPTION_DECLINFO
		cfint::ICFIntSchemaObj* schema = saxLoader->getSchemaObj();
		if( value == S_Default ) {
			bool transactionStarted = schema->beginTransaction();
			try {
				cfsec::ICFSecSysClusterObj* sysCluster = schema->getSysClusterTableObj()->readSysClusterByIdIdx( 1 );
				if( sysCluster == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"sysCluster" );
				}
				cfsec::ICFSecClusterObj* useCluster = sysCluster->getRequiredContainerCluster();
				if( useCluster == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						"sysCluster->containerCluster" );
				}
				if( clusterName != NULL ) {
					delete clusterName;
					clusterName = NULL;
				}
				clusterName = new std::string( value );
				clusterObj = useCluster;
				saxLoader->getSchemaObj()->setSecCluster( useCluster );
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
		else if( value == S_System ) {
			bool transactionStarted = schema->beginTransaction();
			try {
				cfsec::ICFSecClusterObj* useCluster = schema->getClusterTableObj()->readClusterByUDomNameIdx( S_System );
				if( useCluster == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ReadClusterSystem );
				}
				if( clusterName != NULL ) {
					delete clusterName;
					clusterName = NULL;
				}
				clusterName = new std::string( value );
				clusterObj = useCluster;
				saxLoader->getSchemaObj()->setSecCluster( useCluster );
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
		else {
			throw cflib::CFLibUsageException( CLASS_NAME,
				S_ProcName,
				S_ExpectedValues );
		}
	}

	const std::string& CFIntSaxLdr::getClusterName() const {
		return( *clusterName );
	}

	cfsec::ICFSecClusterObj* CFIntSaxLdr::getClusterObj() {
		const static std::string S_ProcName( "getClusterObj" );
		const static std::string S_Default( "default" );
		const static std::string S_System( "system" );
		const static std::string S_SysCluster( "sysCluster" );
		const static std::string S_SysClusterContainingCluster( "sysCluster->containingCluster" );
		const static std::string S_ReadClusterSystem( "readClusterByUDomName-system" );
		const static std::string S_ClusterObj( "clusterObj" );
		CFLIB_EXCEPTION_DECLINFO
		if( clusterObj == NULL ) {
			cfint::ICFIntSchemaObj* schema = saxLoader->getSchemaObj();
			if( *clusterName == S_Default ) {
				bool transactionStarted = schema->beginTransaction();
				try {
					cfsec::ICFSecSysClusterObj* sysCluster = schema->getSysClusterTableObj()->readSysClusterByIdIdx( 1 );
					if( sysCluster == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_SysCluster );
					}
					cfsec::ICFSecClusterObj* useCluster = sysCluster->getRequiredContainerCluster();
					if( useCluster == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_SysClusterContainingCluster );
					}
					clusterObj = useCluster;
					saxLoader->getSchemaObj()->setSecCluster( useCluster );
					if( transactionStarted ) {
						schema->commit();
					}
				}
				CFLIB_EXCEPTION_CATCH_FALLTHROUGH
				if( ! CFLIB_EXCEPTION_EMPTY ) {
					if( transactionStarted ) {
						try {
							schema->rollback();
						}
						catch( ... ) {
						}
					}
					throw cflib::CFLibRuntimeException( CLASS_NAME,
						S_ProcName,
						S_UnhandledException );
				}
			}
			else if( *clusterName == S_System ) {
				bool transactionStarted = schema->beginTransaction();
				try {
					cfsec::ICFSecClusterObj* useCluster = schema->getClusterTableObj()->readClusterByUDomNameIdx( S_System );
					if( useCluster == NULL ) {
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							S_ReadClusterSystem );
					}
					clusterObj = useCluster;
					saxLoader->getSchemaObj()->setSecCluster( useCluster );
					if( transactionStarted ) {
						schema->commit();
					}
				}
				CFLIB_EXCEPTION_CATCH_FALLTHROUGH
				if( ! CFLIB_EXCEPTION_EMPTY ) {
					if( transactionStarted ) {
						try {
							schema->rollback();
						}
						catch( ... ) {
						}
					}
					throw cflib::CFLibRuntimeException( CLASS_NAME,
						S_ProcName,
						S_UnhandledException );
				}
			}
		}
		if( clusterObj == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_ClusterObj );
		}
		return( clusterObj );
	}

	void CFIntSaxLdr::setTenantName( const std::string& value ) {
		const static std::string S_ProcName = "setTenantName";
		const static std::string S_System= "system";
		const static std::string S_Value = "value";
		const static std::string S_ClusterObj = "clusterObj";
		cfint::ICFIntSchemaObj* schema = saxLoader->getSchemaObj();
		CFLIB_EXCEPTION_DECLINFO
		if( value == S_System ) {
			bool transactionStarted = schema->beginTransaction();
			try {
				cfsec::ICFSecTenantObj* useTenant = schema->getTenantTableObj()->readTenantByUNameIdx( clusterObj->getRequiredId(),
					S_System );
				if( useTenant == NULL ) {
					std::string Msg( "readTenantByUNameIdx-" + clusterObj->getObjName() + "-system" );
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						Msg );
				}
				if( tenantName != NULL ) {
					delete tenantName;
					tenantName = NULL;
				}
				tenantName = new std::string( value );
				tenantObj = useTenant;
				saxLoader->getSchemaObj()->setSecTenant( useTenant );
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
		else {
			if( clusterObj == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_ClusterObj );
			}
			if( *clusterName == S_System ) {
				std::string Msg( "Cluster 'system' only supports the tenant 'system', not '" + value + "'" );
				throw cflib::CFLibUsageException( CLASS_NAME,
					S_ProcName,
					Msg );
			}
			bool transactionStarted = schema->beginTransaction();
			try {
				cfsec::ICFSecTenantObj* useTenant = schema->getTenantTableObj()->readTenantByUNameIdx( clusterObj->getRequiredId(),
					value );
				if( useTenant == NULL ) {
					std::string Msg( "readTenantByUNameIdx-" + clusterObj->getObjName() + "-" + value );
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						Msg );
				}
				if( tenantName != NULL ) {
					delete tenantName;
					tenantName = NULL;
				}
				tenantName = new std::string( value );
				tenantObj = useTenant;
				saxLoader->getSchemaObj()->setSecTenant( useTenant );
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
	}

	const std::string& CFIntSaxLdr::getTenantName() const {
		return( *tenantName );
	}

	cfsec::ICFSecTenantObj* CFIntSaxLdr::getTenantObj() {
		const static std::string S_ProcName( "getTenantObj" );
		const static std::string S_System( "system" );
		const static std::string S_TenantName( "tenantName" );
		const static std::string S_ClusterObj( "clusterObj" );
		CFLIB_EXCEPTION_DECLINFO
		if( tenantObj == NULL ) {
			cfint::ICFIntSchemaObj* schema = saxLoader->getSchemaObj();
			if( tenantName == NULL ) {
				throw cflib::CFLibNullArgumentException( CLASS_NAME,
					S_ProcName,
					0,
					S_TenantName );
			}
			else if( *tenantName == S_System ) {
				bool transactionStarted = schema->beginTransaction();
				try {
					cfsec::ICFSecTenantObj* useTenant = schema->getTenantTableObj()->readTenantByUNameIdx( clusterObj->getRequiredId(),
						S_System );
					if( useTenant == NULL ) {
						std::string Msg( "readTenantByUNameIdx-" + clusterObj->getObjName() + "-system" );
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							Msg );
					}
					tenantObj = useTenant;
					saxLoader->getSchemaObj()->setSecTenant( useTenant );
					if( transactionStarted ) {
						schema->commit();
					}
				}
				CFLIB_EXCEPTION_CATCH_FALLTHROUGH
				if( ! CFLIB_EXCEPTION_EMPTY ) {
					if( transactionStarted ) {
						try {
							schema->rollback();
						}
						catch( ... ) {
						}
					}
					throw cflib::CFLibRuntimeException( CLASS_NAME,
						S_ProcName,
						S_UnhandledException );
				}
			}
			else {
				if( clusterObj == NULL ) {
					throw cflib::CFLibNullArgumentException( CLASS_NAME,
						S_ProcName,
						0,
						S_ClusterObj );
				}
				if( *clusterName == S_System ) {
					std::string Msg( "Cluster 'system' only supports the tenant 'system', not '" + *tenantName + "'" );
					throw cflib::CFLibUsageException( CLASS_NAME,
						S_ProcName,
						Msg );
				}
				bool transactionStarted = schema->beginTransaction();
				try {
					cfsec::ICFSecTenantObj* useTenant = schema->getTenantTableObj()->readTenantByUNameIdx( clusterObj->getRequiredId(),
						*tenantName );
					if( useTenant == NULL ) {
						std::string Msg( "readTenantByUNameIdx-" + clusterObj->getObjName() + "-" + *tenantName );
						throw cflib::CFLibNullArgumentException( CLASS_NAME,
							S_ProcName,
							0,
							Msg );
					}
					tenantObj = useTenant;
					saxLoader->getSchemaObj()->setSecTenant( useTenant );
					if( transactionStarted ) {
						schema->commit();
					}
				}
				CFLIB_EXCEPTION_CATCH_FALLTHROUGH
				if( ! CFLIB_EXCEPTION_EMPTY ) {
					if( transactionStarted ) {
						try {
							schema->rollback();
						}
						catch( ... ) {
						}
					}
					throw cflib::CFLibRuntimeException( CLASS_NAME,
						S_ProcName,
						S_UnhandledException );
				}
			}
		}
		if( tenantObj == NULL ) {
			std::string Msg( "tenantObj-" + *tenantName );
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				Msg );
		}
		return( tenantObj );
	}

	void CFIntSaxLdr::setSecUserName( const std::string& value ) {
		if( secUserName != NULL ) {
			delete secUserName;
			secUserName = NULL;
		}
		secUserName = new std::string( value );
	}

	const std::string& CFIntSaxLdr::getSecUserName() const {
		return( *secUserName );
	}

	cfsec::ICFSecSecUserObj* CFIntSaxLdr::getSecUserObj() {
		static const std::string S_ProcName( "getSecUserObj" );
		CFLIB_EXCEPTION_DECLINFO
		if( secUserObj == NULL ) {
			ICFIntSchemaObj* schema = saxLoader->getSchemaObj();
			bool transactionStarted = schema->beginTransaction();
			try {
				secUserObj = schema->getSecUserTableObj()->readSecUserByULoginIdx( *secUserName );
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
		if( secUserObj == NULL ) {
			std::string Msg( "SecUser \"" + *secUserName + "\" could not be found" );
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				Msg );
		}
		return( secUserObj );
	}

	cfsec::ICFSecSecSessionObj* CFIntSaxLdr::getSecSessionObj() {
		static const std::string S_ProcName( "getSecSessionObj" );
		CFLIB_EXCEPTION_DECLINFO
		if( secSessionObj == NULL ) {
			cfint::ICFIntSchemaObj* schema = saxLoader->getSchemaObj();
			bool transactionStarted = schema->beginTransaction();
			try {
				getClusterObj();
				getTenantObj();
				getSecUserObj();
				secSessionObj = schema->getSecSessionTableObj()->newInstance();
				cfsec::ICFSecSecSessionEditObj* sessionEdit = secSessionObj->beginEdit();
				sessionEdit->setRequiredContainerSecUser( secUserObj );
				std::chrono::system_clock::time_point curTimestamp = cflib::CFLib::getUTCTimestampInstance();
				sessionEdit->setRequiredStart( curTimestamp );
				sessionEdit->setOptionalFinishNull();
				secSessionObj = sessionEdit->create();
				if( transactionStarted ) {
					schema->commit();
				}
			}
			CFLIB_EXCEPTION_CATCH_FALLTHROUGH
			if( ! CFLIB_EXCEPTION_EMPTY ) {
				if( transactionStarted ) {
					try {
						schema->rollback();
					}
					catch( ... ) {
					}
				}
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_UnhandledException );
			}
		}
		return( secSessionObj );
	}

	void CFIntSaxLdr::applyLoaderOptions( cfint::CFIntSaxLoader* loader, const std::string& loaderOptions ) {
		static const std::string S_PathSeparator( ":" );
		std::string workingOptions( loaderOptions );
		while( workingOptions.length() > 0 ) {
			std::string evalSegment;
			std::string::size_type sepIndex = workingOptions.find( S_PathSeparator );
			if( sepIndex != std::string::npos ) {
				evalSegment = workingOptions.substr( 0, sepIndex );
				if( workingOptions.length() > sepIndex + 1 ) {
					workingOptions = workingOptions.substr( sepIndex + 1 );
				}
				else {
					workingOptions.clear();
				}
			}
			else {
				evalSegment = workingOptions;
				workingOptions.clear();
			}
			evalLoaderSegment( loader, evalSegment );
		}
	}

	void CFIntSaxLdr::evalLoaderSegment( cfint::CFIntSaxLoader* loader, const std::string& evalSegment ) {
		const static std::string S_ProcName( "evalLoaderSegment()" );
		const static std::string S_Asterisk( "*" );
		const static std::string S_Equal( "=" );
		const static std::string S_Insert( "Insert" );
		const static std::string S_Update( "Update" );
		const static std::string S_Replace( "Replace" );
		const static std::string S_SegmentMsg( "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
		std::string::size_type sepEquals = evalSegment.find( S_Equal );
		if( sepEquals == std::string::npos ) {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_SegmentMsg );
		}
		std::string tableName = evalSegment.substr( 0, sepEquals );
		std::string tableOption = evalSegment.substr( sepEquals + 1 );
		if( tableName == cfsec::CFSecClusterBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setClusterLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setClusterLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setClusterLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecHostNodeBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setHostNodeLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setHostNodeLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setHostNodeLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOCcyBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOCcyLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOCcyLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOCcyLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOCtryBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOCtryLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOCtryLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOCtryLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOCtryCcyBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOCtryCcyLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOCtryCcyLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOCtryCcyLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOCtryLangBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOCtryLangLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOCtryLangLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOCtryLangLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOLangBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOLangLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOLangLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOLangLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecISOTZoneBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setISOTZoneLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setISOTZoneLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setISOTZoneLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfint::CFIntLicenseBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setLicenseLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setLicenseLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setLicenseLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfint::CFIntMajorVersionBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setMajorVersionLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setMajorVersionLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setMajorVersionLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfint::CFIntMimeTypeBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setMimeTypeLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setMimeTypeLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setMimeTypeLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfint::CFIntMinorVersionBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setMinorVersionLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setMinorVersionLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setMinorVersionLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecAppBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecAppLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecAppLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecAppLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecDeviceBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecDeviceLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecDeviceLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecDeviceLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecFormBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecFormLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecFormLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecFormLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecGroupBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecGroupLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecGroupLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecGroupLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecGroupFormBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecGroupFormLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecGroupFormLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecGroupFormLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecGrpIncBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecGrpIncLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecGrpIncLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecGrpIncLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecGrpMembBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecGrpMembLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecGrpMembLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecGrpMembLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecSessionBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecSessionLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecSessionLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecSessionLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSecUserBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSecUserLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSecUserLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSecUserLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecServiceBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setServiceLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setServiceLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setServiceLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecServiceTypeBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setServiceTypeLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setServiceTypeLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setServiceTypeLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfint::CFIntSubProjectBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSubProjectLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSubProjectLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSubProjectLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecSysClusterBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setSysClusterLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setSysClusterLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setSysClusterLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecTSecGroupBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setTSecGroupLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setTSecGroupLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setTSecGroupLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecTSecGrpIncBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setTSecGrpIncLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setTSecGrpIncLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setTSecGrpIncLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecTSecGrpMembBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setTSecGrpMembLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setTSecGrpMembLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setTSecGrpMembLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfsec::CFSecTenantBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setTenantLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setTenantLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setTenantLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfint::CFIntTldBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setTldLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setTldLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setTldLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfint::CFIntTopDomainBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setTopDomainLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setTopDomainLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setTopDomainLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfint::CFIntTopProjectBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setTopProjectLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setTopProjectLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setTopProjectLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else if( tableName == cfint::CFIntURLProtocolBuff::GENDEFNAME ) {
			if( tableOption == S_Asterisk ) {
				// Leave at default
			}
			else if( tableOption == S_Insert ) {
				loader->setURLProtocolLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert );
			}
			else if( tableOption == S_Update ) {
				loader->setURLProtocolLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update );
			}
			else if( tableOption == S_Replace ) {
				loader->setURLProtocolLoaderBehaviour( cfint::CFIntSaxLoader::LoaderBehaviourEnum::Replace );
			}
			else {
				throw cflib::CFLibRuntimeException( CLASS_NAME,
					S_ProcName,
					S_SegmentMsg );
			}
		}
		else {
			throw cflib::CFLibRuntimeException( CLASS_NAME,
				S_ProcName,
				S_SegmentMsg );
		}
	}

	void CFIntSaxLdr::evaluateRemainingArgs( size_t argc, char* argv[], size_t consumed ) {
		// This method gets overloaded to evaluate the database-specific
		// connection arguments, if supported by a database specialization.
	}

}
