// Description: Java 11 base object instance implementation for CFInt HostNode.

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

package com.github.msobkow.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFInt.*;

public class CFIntHostNodeObj
	implements ICFIntHostNodeObj
{
	public final static String CLASS_CODE = "a002";
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected boolean isNew;
	protected ICFSecHostNodeEditObj edit;
	protected ICFSecSchemaObj schema;
	protected CFSecHostNodePKey pKey;
	protected CFSecHostNodeBuff buff;
	protected ICFSecClusterObj requiredContainerCluster;

	public CFIntHostNodeObj() {
		isNew = true;
		requiredContainerCluster = null;
	}

	public CFIntHostNodeObj( ICFSecSchemaObj argSchema ) {
		schema = argSchema;
		isNew = true;
		edit = null;
		requiredContainerCluster = null;
	}

	public String getClassCode() {
		return( CLASS_CODE );
	}

	public String getGenDefName() {
		return( "HostNode" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecClusterObj scope = getRequiredContainerCluster();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecClusterObj scope = getRequiredContainerCluster();
		return( scope );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredHostName();
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

	public ICFSecHostNodeObj realise() {
		ICFSecHostNodeObj retobj = ((ICFIntSchemaObj)schema).getHostNodeTableObj().realiseHostNode(
			(ICFSecHostNodeObj)this );
		return( (ICFSecHostNodeObj)retobj );
	}

	public void forget() {
		((ICFIntSchemaObj)schema).getHostNodeTableObj().reallyDeepDisposeHostNode( (ICFSecHostNodeObj)this );
	}

	public ICFSecHostNodeObj read() {
		ICFSecHostNodeObj retobj = ((ICFIntSchemaObj)schema).getHostNodeTableObj().readHostNodeByIdIdx( getPKey().getRequiredClusterId(),
			getPKey().getRequiredHostNodeId(), false );
		return( (ICFSecHostNodeObj)retobj );
	}

	public ICFSecHostNodeObj read( boolean forceRead ) {
		ICFSecHostNodeObj retobj = ((ICFIntSchemaObj)schema).getHostNodeTableObj().readHostNodeByIdIdx( getPKey().getRequiredClusterId(),
			getPKey().getRequiredHostNodeId(), forceRead );
		return( (ICFSecHostNodeObj)retobj );
	}

	public ICFSecHostNodeTableObj getHostNodeTable() {
		return( ((ICFIntSchemaObj)schema).getHostNodeTableObj() );
	}

	public ICFSecSchemaObj getSchema() {
		return( schema );
	}

	public void setSchema( ICFSecSchemaObj value ) {
		schema = value;
	}

	public CFSecHostNodeBuff getBuff() {
		if( buff == null ) {
			if( isNew ) {
				buff = ((ICFIntSchema)schema.getBackingStore()).getFactoryHostNode().newBuff();
			}
			else {
				// Read the data buff via the backing store
				buff = ((ICFIntSchema)schema.getBackingStore()).getTableHostNode().readDerivedByIdIdx( ((ICFIntSchemaObj)schema).getAuthorization(),
						getPKey().getRequiredClusterId(),
						getPKey().getRequiredHostNodeId() );
				if( buff != null ) {
					copyBuffToPKey();
				}
			}
		}
		return( buff );
	}

	public void setBuff( CFSecHostNodeBuff value ) {
		if( ! ( ( value == null ) || ( value instanceof CFSecHostNodeBuff ) ) ) {
			throw new CFLibUnsupportedClassException( getClass(),
				"setBuff",
				"value",
				value,
				"CFSecHostNodeBuff" );
		}
		buff = value;
		copyBuffToPKey();
		requiredContainerCluster = null;
	}

	public CFSecHostNodeBuff getHostNodeBuff() {
		return( (CFSecHostNodeBuff)getBuff() );
	}

	public CFSecHostNodePKey getPKey() {
		if( pKey == null ) {
			pKey = ((ICFIntSchema)schema.getBackingStore()).getFactoryHostNode().newPKey();
		}
		return( pKey );
	}

	public void setPKey( CFSecHostNodePKey value ) {
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

	public ICFSecHostNodeEditObj beginEdit() {
		if( edit != null ) {
			throw new CFLibUsageException( getClass(), "beginEdit", "An edit is already open" );
		}
		ICFSecHostNodeObj lockobj;
		if( getIsNew() ) {
			lockobj = (ICFSecHostNodeObj)this;
		}
		else {
			lockobj = ((ICFIntSchemaObj)schema).getHostNodeTableObj().lockHostNode( getPKey() );
		}
		edit = ((ICFIntSchemaObj)schema).getHostNodeTableObj().newEditInstance( lockobj );
		return( (ICFSecHostNodeEditObj)edit );
	}

	public void endEdit() {
		edit = null;
	}

	public ICFSecHostNodeEditObj getEdit() {
		return( edit );
	}

	public ICFSecHostNodeEditObj getEditAsHostNode() {
		return( (ICFSecHostNodeEditObj)edit );
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecHostNodeBuff buff = getBuff();
			createdBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecHostNodeBuff buff = getBuff();
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

	public long getRequiredHostNodeId() {
		return( getPKey().getRequiredHostNodeId() );
	}

	public String getRequiredDescription() {
		return( getHostNodeBuff().getRequiredDescription() );
	}

	public String getRequiredHostName() {
		return( getHostNodeBuff().getRequiredHostName() );
	}

	public ICFSecClusterObj getRequiredContainerCluster() {
		return( getRequiredContainerCluster( false ) );
	}

	public ICFSecClusterObj getRequiredContainerCluster( boolean forceRead ) {
		if( ( requiredContainerCluster == null ) || forceRead ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				requiredContainerCluster = ((ICFIntSchemaObj)schema).getClusterTableObj().readClusterByIdIdx( getPKey().getRequiredClusterId(), forceRead );
			}
		}
		return( requiredContainerCluster );
	}

	public List<ICFSecServiceObj> getOptionalComponentsService() {
		List<ICFSecServiceObj> retval;
		retval = ((ICFIntSchemaObj)schema).getServiceTableObj().readServiceByHostIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredHostNodeId(),
			false );
		return( retval );
	}

	public List<ICFSecServiceObj> getOptionalComponentsService( boolean forceRead ) {
		List<ICFSecServiceObj> retval;
		retval = ((ICFIntSchemaObj)schema).getServiceTableObj().readServiceByHostIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredHostNodeId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		if( buff != null ) {
			buff.setRequiredClusterId( getPKey().getRequiredClusterId() );
			buff.setRequiredHostNodeId( getPKey().getRequiredHostNodeId() );
		}
		if( edit != null ) {
			edit.copyPKeyToBuff();
		}
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredClusterId( buff.getRequiredClusterId() );
		getPKey().setRequiredHostNodeId( buff.getRequiredHostNodeId() );
	}
}