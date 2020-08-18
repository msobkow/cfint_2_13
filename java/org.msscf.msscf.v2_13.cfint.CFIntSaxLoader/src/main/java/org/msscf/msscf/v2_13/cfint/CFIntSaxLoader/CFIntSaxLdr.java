// Description: Java 11 XML SAX Parser for CFInt.

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

package org.msscf.msscf.v2_13.cfint.CFIntSaxLoader;

import java.io.File;
import java.util.Calendar;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;
import org.msscf.msscf.v2_13.cfint.CFInt.*;
import org.msscf.msscf.v2_13.cfsec.CFSecObj.*;
import org.msscf.msscf.v2_13.cfint.CFIntObj.*;

public class CFIntSaxLdr
{
	protected ICFLibMessageLog log = null;
	protected CFIntSaxLoader saxLoader = null;
	protected String clusterName = "system";
	protected ICFSecClusterObj clusterObj = null;
	protected String tenantName = "system";
	protected static ICFSecTenantObj tenantObj = null;
	protected String secUserName = "system";
	protected ICFSecSecUserObj secUserObj = null;
	protected ICFSecSecSessionObj secSessionObj = null;
	// Constructors

	public CFIntSaxLdr() {
		log = null;
		getSaxLoader();
	}

	public CFIntSaxLdr( ICFLibMessageLog messageLog ) {
		log = messageLog;
		getSaxLoader();
	}

	// Accessors

	public void setSaxLoader( CFIntSaxLoader value ) {
		saxLoader = value;
	}

	public CFIntSaxLoader getSaxLoader() {
		if( saxLoader == null ) {
			saxLoader = new CFIntSaxLoader( log );
		}
		return( saxLoader );
	}

	public void setClusterName( String value ) {
		final String S_ProcName = "setClusterName";
		ICFIntSchemaObj schema = saxLoader.getSchemaObj();
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"value" );
		}
		else if( value.equals( "default" ) ) {
			boolean transactionStarted = schema.beginTransaction();
			try {
				ICFSecSysClusterObj sysCluster = schema.getSysClusterTableObj().readSysClusterByIdIdx( 1 );
				if( sysCluster == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"sysCluster" );
				}
				ICFSecClusterObj useCluster = sysCluster.getRequiredContainerCluster();
				if( useCluster == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"sysCluster.containerCluster" );
				}
				clusterName = value;
				clusterObj = useCluster;
				saxLoader.getSchemaObj().setSecCluster( useCluster );
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
		else if( value.equals( "system" ) ) {
			boolean transactionStarted = schema.beginTransaction();
			try {
				ICFSecClusterObj useCluster = schema.getClusterTableObj().readClusterByUDomNameIdx( "system" );
				if( useCluster == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"readClusterByUDomName-system" );
				}
				clusterName = value;
				clusterObj = useCluster;
				saxLoader.getSchemaObj().setSecCluster( useCluster );
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
		else {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Expected value to by 'default' or 'system'" );
		}
	}

	public String getClusterName() {
		return( clusterName );
	}

	public ICFSecClusterObj getClusterObj() {
		final String S_ProcName = "getClusterObj";
		if( clusterObj == null ) {
			ICFIntSchemaObj schema = saxLoader.getSchemaObj();
			if( clusterName.equals( "default" ) ) {
				boolean transactionStarted = schema.beginTransaction();
				try {
					ICFSecSysClusterObj sysCluster = schema.getSysClusterTableObj().readSysClusterByIdIdx( 1 );
					if( sysCluster == null ) {
						throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"sysCluster" );
					}
					ICFSecClusterObj useCluster = sysCluster.getRequiredContainerCluster();
					if( useCluster == null ) {
						throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"sysCluster.containerCluster" );
					}
					clusterObj = useCluster;
					saxLoader.getSchemaObj().setSecCluster( useCluster );
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
			else if( clusterName.equals( "system" ) ) {
				boolean transactionStarted = schema.beginTransaction();
				try {
					ICFSecClusterObj useCluster = schema.getClusterTableObj().readClusterByUDomNameIdx( "system" );
					if( useCluster == null ) {
						throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"readClusterByUDomName-system" );
					}
					clusterObj = useCluster;
					saxLoader.getSchemaObj().setSecCluster( useCluster );
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
		if( clusterObj == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				0,
				"clusterObj" );
		}
		return( clusterObj );
	}


	public void setTenantName( String value ) {
		final String S_ProcName = "setTenantName";
		ICFIntSchemaObj schema = saxLoader.getSchemaObj();
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"value" );
		}
		else if( value.equals( "system" ) ) {
			boolean transactionStarted = schema.beginTransaction();
			try {
				ICFSecTenantObj useTenant = schema.getTenantTableObj().readTenantByUNameIdx( clusterObj.getRequiredId(),
					"system" );
				if( useTenant == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"readTenantByUNameIdx-" + clusterObj.getObjName() + "-system" );
				}
				tenantName = value;
				tenantObj = useTenant;
				saxLoader.getSchemaObj().setSecTenant( useTenant );
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
		else {
			if( clusterObj == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					0,
					"clusterObj" );
			}
			if( clusterName.equals( "system" ) ) {
				throw new CFLibUsageException( getClass(),
					S_ProcName,
					"Cluster 'system' only supports the tenant 'system', not '" + value + "'" );
			}
			boolean transactionStarted = schema.beginTransaction();
			try {
				ICFSecTenantObj useTenant = schema.getTenantTableObj().readTenantByUNameIdx( clusterObj.getRequiredId(),
					value );
				if( useTenant == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"readTenantByUNameIdx-" + clusterObj.getObjName() + "-" + value );
				}
				tenantName = value;
				tenantObj = useTenant;
				saxLoader.getSchemaObj().setSecTenant( useTenant );
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

	public String getTenantName() {
		return( tenantName );
	}

	public ICFSecTenantObj getTenantObj() {
		final String S_ProcName = "getTenantObj";
		if( tenantObj == null ) {
			ICFIntSchemaObj schema = saxLoader.getSchemaObj();
			if( tenantName == null ) {
				throw new CFLibNullArgumentException( getClass(),
					S_ProcName,
					1,
					"value" );
			}
			else if( tenantName.equals( "system" ) ) {
				boolean transactionStarted = schema.beginTransaction();
				try {
					ICFSecTenantObj useTenant = schema.getTenantTableObj().readTenantByUNameIdx( clusterObj.getRequiredId(),
						"system" );
					if( useTenant == null ) {
						throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"readTenantByUNameIdx-" + clusterObj.getObjName() + "-system" );
					}
					tenantObj = useTenant;
					saxLoader.getSchemaObj().setSecTenant( useTenant );
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
			else {
				if( clusterObj == null ) {
					throw new CFLibNullArgumentException( getClass(),
						S_ProcName,
						0,
						"clusterObj" );
				}
				if( clusterName.equals( "system" ) ) {
					throw new CFLibUsageException( getClass(),
						S_ProcName,
						"Cluster 'system' only supports the tenant 'system', not '" + tenantName + "'" );
				}
				boolean transactionStarted = schema.beginTransaction();
				try {
					ICFSecTenantObj useTenant = schema.getTenantTableObj().readTenantByUNameIdx( clusterObj.getRequiredId(),
						tenantName );
					if( useTenant == null ) {
						throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"readTenantByUNameIdx-" + clusterObj.getObjName() + "-" + tenantName );
					}
					tenantObj = useTenant;
					saxLoader.getSchemaObj().setSecTenant( useTenant );
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
		if( tenantObj == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				0,
				"tenantObj-" + tenantName );
		}
		return( tenantObj );
	}


	public void setSecUserName( String value ) {
		secUserName = value;
	}

	public String getSecUserName() {
		return( secUserName );
	}

	public ICFSecSecUserObj getSecUserObj() {
		if( secUserObj == null ) {
			ICFIntSchemaObj schema = saxLoader.getSchemaObj();
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
		return( secUserObj );
	}


	public ICFSecSecSessionObj getSecSessionObj() {
		if( secSessionObj == null ) {
			ICFIntSchemaObj schema = saxLoader.getSchemaObj();
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
		return( secSessionObj );
	}

	// Apply the loader options argument to the specified loader

	protected static void applyLoaderOptions( CFIntSaxLoader loader, String loaderOptions ) {
		final String S_ProcName = "CFIntSaxLdr.applyLoaderOptions() ";
		while( loaderOptions.length() > 0 ) {
			String evalSegment;
			int sepIndex = loaderOptions.indexOf( File.pathSeparatorChar );
			if( sepIndex >= 0 ) {
				evalSegment = loaderOptions.substring( 0, sepIndex );
				if( loaderOptions.length() > sepIndex + 1 ) {
					loaderOptions = loaderOptions.substring( sepIndex + 1 );
				}
				else {
					loaderOptions = "";
				}
			}
			else {
				evalSegment = loaderOptions;
				loaderOptions = "";
			}
			evalLoaderSegment( loader, evalSegment );
		}
	}

	// Evaluate a loader options argument segment

	protected static void evalLoaderSegment( CFIntSaxLoader loader, String evalSegment ) {
		final String S_ProcName = "CFIntSaxParserCLI.evalLoaderSegment() ";
		int sepEquals = evalSegment.indexOf( '=' );
		if( sepEquals <= 0 ) {
			throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
		}
		String tableName = evalSegment.substring( 0, sepEquals );
		String tableOption = evalSegment.substring( sepEquals + 1 );
		if( tableName.equals( "Cluster" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setClusterLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setClusterLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setClusterLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "HostNode" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setHostNodeLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setHostNodeLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setHostNodeLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "ISOCcy" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setISOCcyLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setISOCcyLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setISOCcyLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "ISOCtry" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setISOCtryLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setISOCtryLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setISOCtryLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "ISOCtryCcy" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setISOCtryCcyLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setISOCtryCcyLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setISOCtryCcyLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "ISOCtryLang" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setISOCtryLangLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setISOCtryLangLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setISOCtryLangLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "ISOLang" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setISOLangLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setISOLangLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setISOLangLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "ISOTZone" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setISOTZoneLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setISOTZoneLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setISOTZoneLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "License" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setLicenseLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setLicenseLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setLicenseLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "MajorVersion" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setMajorVersionLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setMajorVersionLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setMajorVersionLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "MimeType" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setMimeTypeLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setMimeTypeLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setMimeTypeLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "MinorVersion" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setMinorVersionLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setMinorVersionLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setMinorVersionLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "SecApp" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setSecAppLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setSecAppLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setSecAppLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "SecDevice" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setSecDeviceLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setSecDeviceLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setSecDeviceLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "SecForm" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setSecFormLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setSecFormLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setSecFormLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "SecGroup" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setSecGroupLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setSecGroupLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setSecGroupLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "SecGroupForm" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setSecGroupFormLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setSecGroupFormLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setSecGroupFormLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "SecGrpInc" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setSecGrpIncLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setSecGrpIncLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setSecGrpIncLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "SecGrpMemb" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setSecGrpMembLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setSecGrpMembLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setSecGrpMembLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "SecSession" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setSecSessionLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setSecSessionLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setSecSessionLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "SecUser" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setSecUserLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setSecUserLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setSecUserLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "Service" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setServiceLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setServiceLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setServiceLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "ServiceType" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setServiceTypeLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setServiceTypeLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setServiceTypeLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "SubProject" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setSubProjectLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setSubProjectLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setSubProjectLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "SysCluster" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setSysClusterLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setSysClusterLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setSysClusterLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "TSecGroup" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setTSecGroupLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setTSecGroupLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setTSecGroupLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "TSecGrpInc" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setTSecGrpIncLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setTSecGrpIncLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setTSecGrpIncLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "TSecGrpMemb" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setTSecGrpMembLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setTSecGrpMembLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setTSecGrpMembLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "Tenant" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setTenantLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setTenantLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setTenantLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "Tld" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setTldLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setTldLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setTldLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "TopDomain" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setTopDomainLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setTopDomainLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setTopDomainLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "TopProject" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setTopProjectLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setTopProjectLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setTopProjectLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else if( tableName.equals( "URLProtocol" ) ) {
			if( tableOption.equals( "*" ) ) {
				// Leave at default
			}
			else if( tableOption.equals( "Insert" ) ) {
				loader.setURLProtocolLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Insert );
			}
			else if( tableOption.equals( "Update" ) ) {
				loader.setURLProtocolLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Update );
			}
			else if( tableOption.equals( "Replace" ) ) {
				loader.setURLProtocolLoaderBehaviour( CFIntSaxLoader.LoaderBehaviourEnum.Replace );
			}
			else {
				throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
			}
		}
		else {
			throw new RuntimeException( S_ProcName + "ERROR: Expected segment to comprise <TableName>={*|Insert|Update|Replace}" );
		}
	}

	// Evaluate remaining arguments

	public void evaluateRemainingArgs( String[] args, int consumed ) {
		// This method gets overloaded to evaluate the database-specific
		// connection arguments, if supported by a database specialization.
	}

}
