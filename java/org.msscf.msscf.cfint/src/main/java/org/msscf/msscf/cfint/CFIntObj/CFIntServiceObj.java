// Description: Java 11 base object instance implementation for CFInt Service.

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

package org.msscf.msscf.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFInt.*;

public class CFIntServiceObj
	implements ICFIntServiceObj
{
	public final static String CLASS_CODE = "a012";
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected boolean isNew;
	protected ICFSecServiceEditObj edit;
	protected ICFSecSchemaObj schema;
	protected CFSecServicePKey pKey;
	protected CFSecServiceBuff buff;
	protected ICFSecClusterObj requiredOwnerCluster;
	protected ICFSecHostNodeObj optionalContainerHost;
	protected ICFSecServiceTypeObj optionalParentServiceType;

	public CFIntServiceObj() {
		isNew = true;
		requiredOwnerCluster = null;
		optionalContainerHost = null;
		optionalParentServiceType = null;
	}

	public CFIntServiceObj( ICFSecSchemaObj argSchema ) {
		schema = argSchema;
		isNew = true;
		edit = null;
		requiredOwnerCluster = null;
		optionalContainerHost = null;
		optionalParentServiceType = null;
	}

	public String getClassCode() {
		return( CLASS_CODE );
	}

	public String getGenDefName() {
		return( "Service" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecHostNodeObj scope = getOptionalContainerHost();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecHostNodeObj scope = getOptionalContainerHost();
		return( scope );
	}

	public String getObjName() {
		String objName;
		long val = getRequiredServiceId();
		objName = Long.toString( val );
		return( objName );
	}

	public ICFLibAnyObj getObjQualifier( Class qualifyingClass ) {
		ICFLibAnyObj container = this;
		if( qualifyingClass != null ) {
			while( container != null ) {
				if( container instanceof ICFIntClusterObj ) {
					break;
				}
				else if( container instanceof ICFIntTenantObj ) {
					break;
				}
				else if( qualifyingClass.isInstance( container ) ) {
					break;
				}
				container = container.getObjScope();
			}
		}
		else {
			while( container != null ) {
				if( container instanceof ICFIntClusterObj ) {
					break;
				}
				else if( container instanceof ICFIntTenantObj ) {
					break;
				}
				container = container.getObjScope();
			}
		}
		return( container );
	}

	public ICFLibAnyObj getNamedObject( Class qualifyingClass, String objName ) {
		ICFLibAnyObj topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == null ) {
			return( null );
		}
		ICFLibAnyObj namedObject = topContainer.getNamedObject( objName );
		return( namedObject );
	}

	public ICFLibAnyObj getNamedObject( String objName ) {
		String nextName;
		String remainingName;
		ICFLibAnyObj subObj = null;
		ICFLibAnyObj retObj;
		int nextDot = objName.indexOf( '.' );
		if( nextDot >= 0 ) {
			nextName = objName.substring( 0, nextDot );
			remainingName = objName.substring( nextDot + 1 );
		}
		else {
			nextName = objName;
			remainingName = null;
		}
		if( remainingName == null ) {
			retObj = subObj;
		}
		else if( subObj == null ) {
			retObj = null;
		}
		else {
			retObj = subObj.getNamedObject( remainingName );
		}
		return( retObj );
	}

	public String getObjQualifiedName() {
		String qualName = getObjName();
		ICFLibAnyObj container = getObjScope();
		String containerName;
		while( container != null ) {
			if( container instanceof ICFSecClusterObj ) {
				container = null;
			}
			else if( container instanceof ICFSecTenantObj ) {
				container = null;
			}
			else {
				containerName = container.getObjName();
				qualName = containerName + "." + qualName;
				container = container.getObjScope();
			}
		}
		return( qualName );
	}

	public String getObjFullName() {
		String fullName = getObjName();
		ICFLibAnyObj container = getObjScope();
		String containerName;
		while( container != null ) {
			if( container instanceof ICFSecClusterObj ) {
				container = null;
			}
			else if( container instanceof ICFSecTenantObj ) {
				container = null;
			}
			else {
				containerName = container.getObjName();
				fullName = containerName + "." + fullName;
				container = container.getObjScope();
			}
		}
		return( fullName );
	}

	public ICFSecServiceObj realise() {
		ICFSecServiceObj retobj = ((ICFIntSchemaObj)schema).getServiceTableObj().realiseService(
			(ICFSecServiceObj)this );
		return( (ICFSecServiceObj)retobj );
	}

	public void forget() {
		((ICFIntSchemaObj)schema).getServiceTableObj().reallyDeepDisposeService( (ICFSecServiceObj)this );
	}

	public ICFSecServiceObj read() {
		ICFSecServiceObj retobj = ((ICFIntSchemaObj)schema).getServiceTableObj().readServiceByIdIdx( getPKey().getRequiredClusterId(),
			getPKey().getRequiredServiceId(), false );
		return( (ICFSecServiceObj)retobj );
	}

	public ICFSecServiceObj read( boolean forceRead ) {
		ICFSecServiceObj retobj = ((ICFIntSchemaObj)schema).getServiceTableObj().readServiceByIdIdx( getPKey().getRequiredClusterId(),
			getPKey().getRequiredServiceId(), forceRead );
		return( (ICFSecServiceObj)retobj );
	}

	public ICFSecServiceTableObj getServiceTable() {
		return( ((ICFIntSchemaObj)schema).getServiceTableObj() );
	}

	public ICFSecSchemaObj getSchema() {
		return( schema );
	}

	public void setSchema( ICFSecSchemaObj value ) {
		schema = value;
	}

	public CFSecServiceBuff getBuff() {
		if( buff == null ) {
			if( isNew ) {
				buff = ((ICFIntSchema)schema.getBackingStore()).getFactoryService().newBuff();
			}
			else {
				// Read the data buff via the backing store
				buff = ((ICFIntSchema)schema.getBackingStore()).getTableService().readDerivedByIdIdx( ((ICFIntSchemaObj)schema).getAuthorization(),
						getPKey().getRequiredClusterId(),
						getPKey().getRequiredServiceId() );
				if( buff != null ) {
					copyBuffToPKey();
				}
			}
		}
		return( buff );
	}

	public void setBuff( CFSecServiceBuff value ) {
		if( ! ( ( value == null ) || ( value instanceof CFSecServiceBuff ) ) ) {
			throw new CFLibUnsupportedClassException( getClass(),
				"setBuff",
				"value",
				value,
				"CFSecServiceBuff" );
		}
		buff = value;
		copyBuffToPKey();
		requiredOwnerCluster = null;
		optionalContainerHost = null;
		optionalParentServiceType = null;
	}

	public CFSecServiceBuff getServiceBuff() {
		return( (CFSecServiceBuff)getBuff() );
	}

	public CFSecServicePKey getPKey() {
		if( pKey == null ) {
			pKey = ((ICFIntSchema)schema.getBackingStore()).getFactoryService().newPKey();
		}
		return( pKey );
	}

	public void setPKey( CFSecServicePKey value ) {
		if( pKey != value ) {
			pKey = value;
			copyPKeyToBuff();
		}
	}

	public boolean getIsNew() {
		return( isNew );
	}

	public void setIsNew( boolean value ) {
		isNew = value;
	}

	public ICFSecServiceEditObj beginEdit() {
		if( edit != null ) {
			throw new CFLibUsageException( getClass(), "beginEdit", "An edit is already open" );
		}
		ICFSecServiceObj lockobj;
		if( getIsNew() ) {
			lockobj = (ICFSecServiceObj)this;
		}
		else {
			lockobj = ((ICFIntSchemaObj)schema).getServiceTableObj().lockService( getPKey() );
		}
		edit = ((ICFIntSchemaObj)schema).getServiceTableObj().newEditInstance( lockobj );
		return( (ICFSecServiceEditObj)edit );
	}

	public void endEdit() {
		edit = null;
	}

	public ICFSecServiceEditObj getEdit() {
		return( edit );
	}

	public ICFSecServiceEditObj getEditAsService() {
		return( (ICFSecServiceEditObj)edit );
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecServiceBuff buff = getBuff();
			createdBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecServiceBuff buff = getBuff();
			updatedBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	public Calendar getUpdatedAt() {
		return( getBuff().getUpdatedAt() );
	}

	public long getRequiredClusterId() {
		return( getPKey().getRequiredClusterId() );
	}

	public long getRequiredServiceId() {
		return( getPKey().getRequiredServiceId() );
	}

	public long getRequiredHostNodeId() {
		return( getServiceBuff().getRequiredHostNodeId() );
	}

	public int getRequiredServiceTypeId() {
		return( getServiceBuff().getRequiredServiceTypeId() );
	}

	public short getRequiredHostPort() {
		return( getServiceBuff().getRequiredHostPort() );
	}

	public ICFSecClusterObj getRequiredOwnerCluster() {
		return( getRequiredOwnerCluster( false ) );
	}

	public ICFSecClusterObj getRequiredOwnerCluster( boolean forceRead ) {
		if( ( requiredOwnerCluster == null ) || forceRead ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				requiredOwnerCluster = ((ICFIntSchemaObj)schema).getClusterTableObj().readClusterByIdIdx( getPKey().getRequiredClusterId(), forceRead );
			}
		}
		return( requiredOwnerCluster );
	}

	public ICFSecHostNodeObj getOptionalContainerHost() {
		return( getOptionalContainerHost( false ) );
	}

	public ICFSecHostNodeObj getOptionalContainerHost( boolean forceRead ) {
		if( ( optionalContainerHost == null ) || forceRead ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				optionalContainerHost = ((ICFIntSchemaObj)schema).getHostNodeTableObj().readHostNodeByIdIdx( getPKey().getRequiredClusterId(),
					getServiceBuff().getRequiredHostNodeId(), forceRead );
			}
		}
		return( optionalContainerHost );
	}

	public ICFSecServiceTypeObj getOptionalParentServiceType() {
		return( getOptionalParentServiceType( false ) );
	}

	public ICFSecServiceTypeObj getOptionalParentServiceType( boolean forceRead ) {
		if( ( optionalParentServiceType == null ) || forceRead ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				optionalParentServiceType = ((ICFIntSchemaObj)schema).getServiceTypeTableObj().readServiceTypeByIdIdx( getServiceBuff().getRequiredServiceTypeId(), forceRead );
			}
		}
		return( optionalParentServiceType );
	}

	public void copyPKeyToBuff() {
		if( buff != null ) {
			buff.setRequiredClusterId( getPKey().getRequiredClusterId() );
			buff.setRequiredServiceId( getPKey().getRequiredServiceId() );
		}
		if( edit != null ) {
			edit.copyPKeyToBuff();
		}
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredClusterId( buff.getRequiredClusterId() );
		getPKey().setRequiredServiceId( buff.getRequiredServiceId() );
	}
}