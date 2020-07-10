// Description: Java 11 JavaFX Schema for CFInt.

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

package com.github.msobkow.cfint.CFIntJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import java.security.KeyStore;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfint.CFInt.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFIntObj.*;
import com.github.msobkow.cfsec.CFSecJavaFX.*;
import com.github.msobkow.cfint.CFIntSaxLoader.CFIntSaxLoader;

public class CFIntJavaFXSchema
implements ICFIntJavaFXSchema
{
	protected CFSecClientConfigurationFile clientConfigurationFile = null;
	protected KeyStore keyStore = null;
	protected ICFIntSchemaObj schema = null;
	protected String clusterName = "system";
	protected ICFSecClusterObj clusterObj = null;
	protected String tenantName = "system";
	protected ICFSecTenantObj tenantObj = null;
	protected String secUserName = "system";
	protected ICFSecSecUserObj secUserObj = null;
	protected ICFSecSecSessionObj secSessionObj = null;
	protected ICFSecJavaFXClusterFactory factoryCluster = null;
	protected ICFSecJavaFXHostNodeFactory factoryHostNode = null;
	protected ICFSecJavaFXISOCcyFactory factoryISOCcy = null;
	protected ICFSecJavaFXISOCtryFactory factoryISOCtry = null;
	protected ICFSecJavaFXISOCtryCcyFactory factoryISOCtryCcy = null;
	protected ICFSecJavaFXISOCtryLangFactory factoryISOCtryLang = null;
	protected ICFSecJavaFXISOLangFactory factoryISOLang = null;
	protected ICFSecJavaFXISOTZoneFactory factoryISOTZone = null;
	protected ICFIntJavaFXLicenseFactory factoryLicense = null;
	protected ICFIntJavaFXMajorVersionFactory factoryMajorVersion = null;
	protected ICFIntJavaFXMimeTypeFactory factoryMimeType = null;
	protected ICFIntJavaFXMinorVersionFactory factoryMinorVersion = null;
	protected ICFSecJavaFXSecAppFactory factorySecApp = null;
	protected ICFSecJavaFXSecDeviceFactory factorySecDevice = null;
	protected ICFSecJavaFXSecFormFactory factorySecForm = null;
	protected ICFSecJavaFXSecGroupFactory factorySecGroup = null;
	protected ICFSecJavaFXSecGroupFormFactory factorySecGroupForm = null;
	protected ICFSecJavaFXSecGrpIncFactory factorySecGrpInc = null;
	protected ICFSecJavaFXSecGrpMembFactory factorySecGrpMemb = null;
	protected ICFSecJavaFXSecSessionFactory factorySecSession = null;
	protected ICFSecJavaFXSecUserFactory factorySecUser = null;
	protected ICFSecJavaFXServiceFactory factoryService = null;
	protected ICFSecJavaFXServiceTypeFactory factoryServiceType = null;
	protected ICFIntJavaFXSubProjectFactory factorySubProject = null;
	protected ICFSecJavaFXSysClusterFactory factorySysCluster = null;
	protected ICFSecJavaFXTSecGroupFactory factoryTSecGroup = null;
	protected ICFSecJavaFXTSecGrpIncFactory factoryTSecGrpInc = null;
	protected ICFSecJavaFXTSecGrpMembFactory factoryTSecGrpMemb = null;
	protected ICFSecJavaFXTenantFactory factoryTenant = null;
	protected ICFIntJavaFXTldFactory factoryTld = null;
	protected ICFIntJavaFXTopDomainFactory factoryTopDomain = null;
	protected ICFIntJavaFXTopProjectFactory factoryTopProject = null;
	protected ICFIntJavaFXURLProtocolFactory factoryURLProtocol = null;

	public CFIntJavaFXSchema() {
	}

	public CFSecClientConfigurationFile getClientConfigurationFile() {
		return( clientConfigurationFile );
	}

	public void setClientConfigurationFile( CFSecClientConfigurationFile value ) {
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				"setClientConfigurationFile",
				1,
				"value" );
		}
		clientConfigurationFile = value;
	}

	public KeyStore getKeyStore() {
		return( keyStore );
	}

	public void setKeyStore( KeyStore value ) {
		keyStore = value;
	}

	public ICFSecSchemaObj getSchema() {
		return( schema );
	}

	public void setSchema( ICFSecSchemaObj argSchema ) {
		final String S_ProcName = "setSchema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		if( ! ( argSchema instanceof ICFIntSchemaObj ) ) {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"argSchema",
				argSchema,
				"ICFIntSchemaObj" );
		}
		schema = (ICFIntSchemaObj)argSchema;
	}

	public String getClusterName() {
		return( clusterName );
	}

	public void setClusterName( String argClusterName ) {
		final String S_ProcName = "setClusterName";
		if( ( argClusterName == null ) || ( argClusterName.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"argClusterName" );
		}
		clusterName = argClusterName;
		clusterObj = null;
	}

	public ICFSecClusterObj getClusterObj() {
		if( clusterObj == null ) {
			if( ( schema != null ) && schema.isConnected() ) {
				boolean transactionStarted = schema.beginTransaction();
				try {
					clusterObj = schema.getClusterTableObj().readClusterByUDomNameIdx( clusterName );
					if( transactionStarted ) {
						schema.commit();
					}
				}
				catch( RuntimeException e ) {
					if( transactionStarted ) {
						try {
							schema.rollback();
						}
						catch( Exception e2 ) {
						}
					}
					throw e;
				}
			}
			if( clusterObj == null ) {
				throw new RuntimeException( "Cluster \"" + clusterName + "\" could not be found" );
			}
		}
		else {
			throw new RuntimeException( "Cannot resolve Cluster before a connection is established" );
		}
		return( clusterObj );
	}

	public String getTenantName() {
		return( tenantName );
	}

	public void setTenantName( String argTenantName ) {
		final String S_ProcName = "setTenantName";
		if( ( argTenantName == null ) || ( argTenantName.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"argTenantName" );
		}
		tenantName = argTenantName;
		tenantObj = null;
	}

	public ICFSecTenantObj getTenantObj() {
		if( tenantObj == null ) {
			if( ( schema != null ) && schema.isConnected() ) {
				boolean transactionStarted = schema.beginTransaction();
				try {
					tenantObj = schema.getTenantTableObj().readTenantByUNameIdx( getClusterObj().getRequiredId(), tenantName );
					if( transactionStarted ) {
						schema.commit();
					}
				}
				catch( RuntimeException e ) {
					if( transactionStarted ) {
						try {
							schema.rollback();
						}
						catch( Exception e2 ) {
						}
					}
					throw e;
				}
			}
			if( tenantObj == null ) {
				throw new RuntimeException( "Tenant \"" + tenantName + "\" could not be found for Cluster \"" + clusterName + "\"" );
			}
		}
		else {
			throw new CFLibRuntimeException( "Cannot resolve tenant before a connection is established" );
		}
		return( tenantObj );
	}

	public String getSecUserName() {
		return( secUserName );
	}

	public void setSecUserName( String argSecUserName ) {
		final String S_ProcName = "setSecUserName";
		if( ( argSecUserName == null ) || ( argSecUserName.length() <= 0 ) ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"argSecUserName" );
		}
		secUserName = argSecUserName;
		secUserObj = null;
	}

	public ICFSecSecUserObj getSecUserObj() {
		if( secUserObj == null ) {
			if( ( schema != null ) && schema.isConnected() ) {
				boolean transactionStarted = schema.beginTransaction();
				try {
					secUserObj = schema.getSecUserTableObj().readSecUserByULoginIdx( secUserName );
					if( transactionStarted ) {
						schema.commit();
					}
				}
				catch( RuntimeException e ) {
					if( transactionStarted ) {
						try {
							schema.rollback();
						}
						catch( Exception e2 ) {
						}
					}
					throw e;
				}
			}
			if( secUserObj == null ) {
				throw new RuntimeException( "SecUser \"" + secUserName + "\" could not be found" );
			}
		}
		else {
			throw new CFLibRuntimeException( "Cannot resolve sec user before a connection is established" );
		}
		return( secUserObj );
	}

	public ICFSecSecSessionObj getSecSessionObj() {
		if( secSessionObj == null ) {
			if( ( schema != null ) && schema.isConnected() ) {
				boolean transactionStarted = schema.beginTransaction();
				try {
					getClusterObj();
					getTenantObj();
					getSecUserObj();
					secSessionObj = schema.getSecSessionTableObj().newInstance();
					ICFSecSecSessionEditObj sessionEdit = secSessionObj.beginEdit();
					sessionEdit.setRequiredContainerSecUser( secUserObj );
					sessionEdit.setRequiredStart( Calendar.getInstance() );
					sessionEdit.setOptionalFinish( null );
					secSessionObj = sessionEdit.create();
					sessionEdit = null;
					if( transactionStarted ) {
						schema.commit();
					}
				}
				catch( RuntimeException e ) {
					if( transactionStarted ) {
						try {
							schema.rollback();
						}
						catch( Exception e2 ) {
						}
					}
					throw e;
				}
			}
		}
		else {
			throw new CFLibRuntimeException( "Cannot resolve sec session before a connection is established" );
		}
		return( secSessionObj );
	}

	public ICFSecJavaFXClusterFactory getClusterFactory() {
		if( factoryCluster == null ) {
			factoryCluster = new CFSecJavaFXClusterFactory( this );
		}
		return( factoryCluster );
	}

	public ICFSecJavaFXHostNodeFactory getHostNodeFactory() {
		if( factoryHostNode == null ) {
			factoryHostNode = new CFSecJavaFXHostNodeFactory( this );
		}
		return( factoryHostNode );
	}

	public ICFSecJavaFXISOCcyFactory getISOCcyFactory() {
		if( factoryISOCcy == null ) {
			factoryISOCcy = new CFSecJavaFXISOCcyFactory( this );
		}
		return( factoryISOCcy );
	}

	public ICFSecJavaFXISOCtryFactory getISOCtryFactory() {
		if( factoryISOCtry == null ) {
			factoryISOCtry = new CFSecJavaFXISOCtryFactory( this );
		}
		return( factoryISOCtry );
	}

	public ICFSecJavaFXISOCtryCcyFactory getISOCtryCcyFactory() {
		if( factoryISOCtryCcy == null ) {
			factoryISOCtryCcy = new CFSecJavaFXISOCtryCcyFactory( this );
		}
		return( factoryISOCtryCcy );
	}

	public ICFSecJavaFXISOCtryLangFactory getISOCtryLangFactory() {
		if( factoryISOCtryLang == null ) {
			factoryISOCtryLang = new CFSecJavaFXISOCtryLangFactory( this );
		}
		return( factoryISOCtryLang );
	}

	public ICFSecJavaFXISOLangFactory getISOLangFactory() {
		if( factoryISOLang == null ) {
			factoryISOLang = new CFSecJavaFXISOLangFactory( this );
		}
		return( factoryISOLang );
	}

	public ICFSecJavaFXISOTZoneFactory getISOTZoneFactory() {
		if( factoryISOTZone == null ) {
			factoryISOTZone = new CFSecJavaFXISOTZoneFactory( this );
		}
		return( factoryISOTZone );
	}

	public ICFIntJavaFXLicenseFactory getLicenseFactory() {
		if( factoryLicense == null ) {
			factoryLicense = new CFIntJavaFXLicenseFactory( this );
		}
		return( factoryLicense );
	}

	public ICFIntJavaFXMajorVersionFactory getMajorVersionFactory() {
		if( factoryMajorVersion == null ) {
			factoryMajorVersion = new CFIntJavaFXMajorVersionFactory( this );
		}
		return( factoryMajorVersion );
	}

	public ICFIntJavaFXMimeTypeFactory getMimeTypeFactory() {
		if( factoryMimeType == null ) {
			factoryMimeType = new CFIntJavaFXMimeTypeFactory( this );
		}
		return( factoryMimeType );
	}

	public ICFIntJavaFXMinorVersionFactory getMinorVersionFactory() {
		if( factoryMinorVersion == null ) {
			factoryMinorVersion = new CFIntJavaFXMinorVersionFactory( this );
		}
		return( factoryMinorVersion );
	}

	public ICFSecJavaFXSecAppFactory getSecAppFactory() {
		if( factorySecApp == null ) {
			factorySecApp = new CFSecJavaFXSecAppFactory( this );
		}
		return( factorySecApp );
	}

	public ICFSecJavaFXSecDeviceFactory getSecDeviceFactory() {
		if( factorySecDevice == null ) {
			factorySecDevice = new CFSecJavaFXSecDeviceFactory( this );
		}
		return( factorySecDevice );
	}

	public ICFSecJavaFXSecFormFactory getSecFormFactory() {
		if( factorySecForm == null ) {
			factorySecForm = new CFSecJavaFXSecFormFactory( this );
		}
		return( factorySecForm );
	}

	public ICFSecJavaFXSecGroupFactory getSecGroupFactory() {
		if( factorySecGroup == null ) {
			factorySecGroup = new CFSecJavaFXSecGroupFactory( this );
		}
		return( factorySecGroup );
	}

	public ICFSecJavaFXSecGroupFormFactory getSecGroupFormFactory() {
		if( factorySecGroupForm == null ) {
			factorySecGroupForm = new CFSecJavaFXSecGroupFormFactory( this );
		}
		return( factorySecGroupForm );
	}

	public ICFSecJavaFXSecGrpIncFactory getSecGrpIncFactory() {
		if( factorySecGrpInc == null ) {
			factorySecGrpInc = new CFSecJavaFXSecGrpIncFactory( this );
		}
		return( factorySecGrpInc );
	}

	public ICFSecJavaFXSecGrpMembFactory getSecGrpMembFactory() {
		if( factorySecGrpMemb == null ) {
			factorySecGrpMemb = new CFSecJavaFXSecGrpMembFactory( this );
		}
		return( factorySecGrpMemb );
	}

	public ICFSecJavaFXSecSessionFactory getSecSessionFactory() {
		if( factorySecSession == null ) {
			factorySecSession = new CFSecJavaFXSecSessionFactory( this );
		}
		return( factorySecSession );
	}

	public ICFSecJavaFXSecUserFactory getSecUserFactory() {
		if( factorySecUser == null ) {
			factorySecUser = new CFSecJavaFXSecUserFactory( this );
		}
		return( factorySecUser );
	}

	public ICFSecJavaFXServiceFactory getServiceFactory() {
		if( factoryService == null ) {
			factoryService = new CFSecJavaFXServiceFactory( this );
		}
		return( factoryService );
	}

	public ICFSecJavaFXServiceTypeFactory getServiceTypeFactory() {
		if( factoryServiceType == null ) {
			factoryServiceType = new CFSecJavaFXServiceTypeFactory( this );
		}
		return( factoryServiceType );
	}

	public ICFIntJavaFXSubProjectFactory getSubProjectFactory() {
		if( factorySubProject == null ) {
			factorySubProject = new CFIntJavaFXSubProjectFactory( this );
		}
		return( factorySubProject );
	}

	public ICFSecJavaFXSysClusterFactory getSysClusterFactory() {
		if( factorySysCluster == null ) {
			factorySysCluster = new CFSecJavaFXSysClusterFactory( this );
		}
		return( factorySysCluster );
	}

	public ICFSecJavaFXTSecGroupFactory getTSecGroupFactory() {
		if( factoryTSecGroup == null ) {
			factoryTSecGroup = new CFSecJavaFXTSecGroupFactory( this );
		}
		return( factoryTSecGroup );
	}

	public ICFSecJavaFXTSecGrpIncFactory getTSecGrpIncFactory() {
		if( factoryTSecGrpInc == null ) {
			factoryTSecGrpInc = new CFSecJavaFXTSecGrpIncFactory( this );
		}
		return( factoryTSecGrpInc );
	}

	public ICFSecJavaFXTSecGrpMembFactory getTSecGrpMembFactory() {
		if( factoryTSecGrpMemb == null ) {
			factoryTSecGrpMemb = new CFSecJavaFXTSecGrpMembFactory( this );
		}
		return( factoryTSecGrpMemb );
	}

	public ICFSecJavaFXTenantFactory getTenantFactory() {
		if( factoryTenant == null ) {
			factoryTenant = new CFSecJavaFXTenantFactory( this );
		}
		return( factoryTenant );
	}

	public ICFIntJavaFXTldFactory getTldFactory() {
		if( factoryTld == null ) {
			factoryTld = new CFIntJavaFXTldFactory( this );
		}
		return( factoryTld );
	}

	public ICFIntJavaFXTopDomainFactory getTopDomainFactory() {
		if( factoryTopDomain == null ) {
			factoryTopDomain = new CFIntJavaFXTopDomainFactory( this );
		}
		return( factoryTopDomain );
	}

	public ICFIntJavaFXTopProjectFactory getTopProjectFactory() {
		if( factoryTopProject == null ) {
			factoryTopProject = new CFIntJavaFXTopProjectFactory( this );
		}
		return( factoryTopProject );
	}

	public ICFIntJavaFXURLProtocolFactory getURLProtocolFactory() {
		if( factoryURLProtocol == null ) {
			factoryURLProtocol = new CFIntJavaFXURLProtocolFactory( this );
		}
		return( factoryURLProtocol );
	}
}
