// Description: Java 11 edit object instance implementation for CFInt HostNode.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow mark.sobkow@gmail.com
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

package org.msscf.msscf.v2_13.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;
import org.msscf.msscf.v2_13.cfsec.CFSecObj.*;
import org.msscf.msscf.v2_13.cfint.CFInt.*;

public class CFIntHostNodeEditObj
	implements ICFIntHostNodeEditObj
{
	protected ICFSecHostNodeObj orig;
	protected CFSecHostNodeBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecClusterObj requiredContainerCluster;

	public CFIntHostNodeEditObj( ICFSecHostNodeObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecHostNodeBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredContainerCluster = null;
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

	public void setCreatedBy( ICFSecSecUserObj value ) {
		createdBy = value;
		if( value != null ) {
			getBuff().setCreatedByUserId( value.getRequiredSecUserId() );
		}
	}

	public void setCreatedAt( Calendar value ) {
		getBuff().setCreatedAt( value );
	}

	public void setUpdatedBy( ICFSecSecUserObj value ) {
		updatedBy = value;
		if( value != null ) {
			getBuff().setUpdatedByUserId( value.getRequiredSecUserId() );
		}
	}

	public void setUpdatedAt( Calendar value ) {
		getBuff().setUpdatedAt( value );
	}

	public String getClassCode() {
		return( CFIntHostNodeObj.CLASS_CODE );
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
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecHostNodeObj retobj = getSchema().getHostNodeTableObj().realiseHostNode( (ICFIntHostNodeObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsHostNode().forget();
	}

	public ICFSecHostNodeObj read() {
		ICFSecHostNodeObj retval = getOrigAsHostNode().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecHostNodeObj read( boolean forceRead ) {
		ICFSecHostNodeObj retval = getOrigAsHostNode().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecHostNodeObj create() {
		copyBuffToOrig();
		ICFSecHostNodeObj retobj = ((ICFIntSchemaObj)getOrigAsHostNode().getSchema()).getHostNodeTableObj().createHostNode( getOrigAsHostNode() );
		if( retobj == getOrigAsHostNode() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecHostNodeEditObj update() {
		getSchema().getHostNodeTableObj().updateHostNode( (ICFSecHostNodeObj)this );
		return( null );
	}

	public CFSecHostNodeEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getHostNodeTableObj().deleteHostNode( getOrigAsHostNode() );
		return( null );
	}

	public ICFSecHostNodeTableObj getHostNodeTable() {
		return( orig.getSchema().getHostNodeTableObj() );
	}

	public ICFSecHostNodeEditObj getEdit() {
		return( (ICFSecHostNodeEditObj)this );
	}

	public ICFSecHostNodeEditObj getEditAsHostNode() {
		return( (ICFSecHostNodeEditObj)this );
	}

	public ICFSecHostNodeEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecHostNodeObj getOrig() {
		return( orig );
	}

	public ICFSecHostNodeObj getOrigAsHostNode() {
		return( (ICFSecHostNodeObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecHostNodeBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFIntSchema)getOrigAsHostNode().getSchema().getBackingStore()).getFactoryHostNode().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecHostNodeBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredContainerCluster = null;
		}
	}

	public CFSecHostNodeBuff getHostNodeBuff() {
		return( (CFSecHostNodeBuff)getBuff() );
	}

	public CFSecHostNodePKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecHostNodePKey value ) {
		orig.setPKey( value );
		copyPKeyToBuff();
	}

	public boolean getIsNew() {
		return( orig.getIsNew() );
	}

	public void setIsNew( boolean value ) {
		orig.setIsNew( value );
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

	public void setRequiredDescription( String value ) {
		if( getHostNodeBuff().getRequiredDescription() != value ) {
			getHostNodeBuff().setRequiredDescription( value );
		}
	}

	public String getRequiredHostName() {
		return( getHostNodeBuff().getRequiredHostName() );
	}

	public void setRequiredHostName( String value ) {
		if( getHostNodeBuff().getRequiredHostName() != value ) {
			getHostNodeBuff().setRequiredHostName( value );
		}
	}

	public ICFSecClusterObj getRequiredContainerCluster() {
		return( getRequiredContainerCluster( false ) );
	}

	public ICFSecClusterObj getRequiredContainerCluster( boolean forceRead ) {
		if( forceRead || ( requiredContainerCluster == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecClusterObj obj = ((ICFIntSchemaObj)getOrigAsHostNode().getSchema()).getClusterTableObj().readClusterByIdIdx( getPKey().getRequiredClusterId() );
				requiredContainerCluster = obj;
				if( obj != null ) {
					getHostNodeBuff().setRequiredClusterId( obj.getRequiredId() );
					requiredContainerCluster = obj;
				}
			}
		}
		return( requiredContainerCluster );
	}

	public void setRequiredContainerCluster( ICFSecClusterObj value ) {
			if( buff == null ) {
				getHostNodeBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredId() );
				getHostNodeBuff().setRequiredClusterId( value.getRequiredId() );
			}
			requiredContainerCluster = value;
	}

	public List<ICFSecServiceObj> getOptionalComponentsService() {
		List<ICFSecServiceObj> retval;
		retval = ((ICFIntSchemaObj)getOrigAsHostNode().getSchema()).getServiceTableObj().readServiceByHostIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredHostNodeId(),
			false );
		return( retval );
	}

	public List<ICFSecServiceObj> getOptionalComponentsService( boolean forceRead ) {
		List<ICFSecServiceObj> retval;
		retval = ((ICFIntSchemaObj)getOrigAsHostNode().getSchema()).getServiceTableObj().readServiceByHostIdx( getPKey().getRequiredClusterId(),
					getPKey().getRequiredHostNodeId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		buff.setRequiredClusterId( getPKey().getRequiredClusterId() );
		buff.setRequiredHostNodeId( getPKey().getRequiredHostNodeId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredClusterId( buff.getRequiredClusterId() );
		getPKey().setRequiredHostNodeId( buff.getRequiredHostNodeId() );
	}

	public void copyBuffToOrig() {
		CFSecHostNodeBuff origBuff = getOrigAsHostNode().getHostNodeBuff();
		CFSecHostNodeBuff myBuff = getHostNodeBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecHostNodeBuff origBuff = getOrigAsHostNode().getHostNodeBuff();
		CFSecHostNodeBuff myBuff = getHostNodeBuff();
		myBuff.set( origBuff );
	}
}
