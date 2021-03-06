// Description: Java 11 base object instance implementation for CFInt TSecGrpMemb.

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

public class CFIntTSecGrpMembObj
	implements ICFIntTSecGrpMembObj
{
	public final static String CLASS_CODE = "a018";
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected boolean isNew;
	protected ICFSecTSecGrpMembEditObj edit;
	protected ICFSecSchemaObj schema;
	protected CFSecTSecGrpMembPKey pKey;
	protected CFSecTSecGrpMembBuff buff;
	protected ICFSecTenantObj requiredOwnerTenant;
	protected ICFSecTSecGroupObj requiredContainerGroup;
	protected ICFSecSecUserObj requiredParentUser;

	public CFIntTSecGrpMembObj() {
		isNew = true;
		requiredOwnerTenant = null;
		requiredContainerGroup = null;
		requiredParentUser = null;
	}

	public CFIntTSecGrpMembObj( ICFSecSchemaObj argSchema ) {
		schema = argSchema;
		isNew = true;
		edit = null;
		requiredOwnerTenant = null;
		requiredContainerGroup = null;
		requiredParentUser = null;
	}

	public String getClassCode() {
		return( CLASS_CODE );
	}

	public String getGenDefName() {
		return( "TSecGrpMemb" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecTSecGroupObj scope = getRequiredContainerGroup();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecTSecGroupObj scope = getRequiredContainerGroup();
		return( scope );
	}

	public String getObjName() {
		String objName;
		long val = getRequiredTSecGrpMembId();
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

	public ICFSecTSecGrpMembObj realise() {
		ICFSecTSecGrpMembObj retobj = ((ICFIntSchemaObj)schema).getTSecGrpMembTableObj().realiseTSecGrpMemb(
			(ICFSecTSecGrpMembObj)this );
		return( (ICFSecTSecGrpMembObj)retobj );
	}

	public void forget() {
		((ICFIntSchemaObj)schema).getTSecGrpMembTableObj().reallyDeepDisposeTSecGrpMemb( (ICFSecTSecGrpMembObj)this );
	}

	public ICFSecTSecGrpMembObj read() {
		ICFSecTSecGrpMembObj retobj = ((ICFIntSchemaObj)schema).getTSecGrpMembTableObj().readTSecGrpMembByIdIdx( getPKey().getRequiredTenantId(),
			getPKey().getRequiredTSecGrpMembId(), false );
		return( (ICFSecTSecGrpMembObj)retobj );
	}

	public ICFSecTSecGrpMembObj read( boolean forceRead ) {
		ICFSecTSecGrpMembObj retobj = ((ICFIntSchemaObj)schema).getTSecGrpMembTableObj().readTSecGrpMembByIdIdx( getPKey().getRequiredTenantId(),
			getPKey().getRequiredTSecGrpMembId(), forceRead );
		return( (ICFSecTSecGrpMembObj)retobj );
	}

	public ICFSecTSecGrpMembTableObj getTSecGrpMembTable() {
		return( ((ICFIntSchemaObj)schema).getTSecGrpMembTableObj() );
	}

	public ICFSecSchemaObj getSchema() {
		return( schema );
	}

	public void setSchema( ICFSecSchemaObj value ) {
		schema = value;
	}

	public CFSecTSecGrpMembBuff getBuff() {
		if( buff == null ) {
			if( isNew ) {
				buff = ((ICFIntSchema)schema.getBackingStore()).getFactoryTSecGrpMemb().newBuff();
			}
			else {
				// Read the data buff via the backing store
				buff = ((ICFIntSchema)schema.getBackingStore()).getTableTSecGrpMemb().readDerivedByIdIdx( ((ICFIntSchemaObj)schema).getAuthorization(),
						getPKey().getRequiredTenantId(),
						getPKey().getRequiredTSecGrpMembId() );
				if( buff != null ) {
					copyBuffToPKey();
				}
			}
		}
		return( buff );
	}

	public void setBuff( CFSecTSecGrpMembBuff value ) {
		if( ! ( ( value == null ) || ( value instanceof CFSecTSecGrpMembBuff ) ) ) {
			throw new CFLibUnsupportedClassException( getClass(),
				"setBuff",
				"value",
				value,
				"CFSecTSecGrpMembBuff" );
		}
		buff = value;
		copyBuffToPKey();
		requiredOwnerTenant = null;
		requiredContainerGroup = null;
		requiredParentUser = null;
	}

	public CFSecTSecGrpMembBuff getTSecGrpMembBuff() {
		return( (CFSecTSecGrpMembBuff)getBuff() );
	}

	public CFSecTSecGrpMembPKey getPKey() {
		if( pKey == null ) {
			pKey = ((ICFIntSchema)schema.getBackingStore()).getFactoryTSecGrpMemb().newPKey();
		}
		return( pKey );
	}

	public void setPKey( CFSecTSecGrpMembPKey value ) {
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

	public ICFSecTSecGrpMembEditObj beginEdit() {
		if( edit != null ) {
			throw new CFLibUsageException( getClass(), "beginEdit", "An edit is already open" );
		}
		ICFSecTSecGrpMembObj lockobj;
		if( getIsNew() ) {
			lockobj = (ICFSecTSecGrpMembObj)this;
		}
		else {
			lockobj = ((ICFIntSchemaObj)schema).getTSecGrpMembTableObj().lockTSecGrpMemb( getPKey() );
		}
		edit = ((ICFIntSchemaObj)schema).getTSecGrpMembTableObj().newEditInstance( lockobj );
		return( (ICFSecTSecGrpMembEditObj)edit );
	}

	public void endEdit() {
		edit = null;
	}

	public ICFSecTSecGrpMembEditObj getEdit() {
		return( edit );
	}

	public ICFSecTSecGrpMembEditObj getEditAsTSecGrpMemb() {
		return( (ICFSecTSecGrpMembEditObj)edit );
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecTSecGrpMembBuff buff = getBuff();
			createdBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecTSecGrpMembBuff buff = getBuff();
			updatedBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	public Calendar getUpdatedAt() {
		return( getBuff().getUpdatedAt() );
	}

	public long getRequiredTenantId() {
		return( getPKey().getRequiredTenantId() );
	}

	public long getRequiredTSecGrpMembId() {
		return( getPKey().getRequiredTSecGrpMembId() );
	}

	public int getRequiredTSecGroupId() {
		return( getTSecGrpMembBuff().getRequiredTSecGroupId() );
	}

	public UUID getRequiredSecUserId() {
		return( getTSecGrpMembBuff().getRequiredSecUserId() );
	}

	public ICFSecTenantObj getRequiredOwnerTenant() {
		return( getRequiredOwnerTenant( false ) );
	}

	public ICFSecTenantObj getRequiredOwnerTenant( boolean forceRead ) {
		if( ( requiredOwnerTenant == null ) || forceRead ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				requiredOwnerTenant = ((ICFIntSchemaObj)schema).getTenantTableObj().readTenantByIdIdx( getPKey().getRequiredTenantId(), forceRead );
			}
		}
		return( requiredOwnerTenant );
	}

	public ICFSecTSecGroupObj getRequiredContainerGroup() {
		return( getRequiredContainerGroup( false ) );
	}

	public ICFSecTSecGroupObj getRequiredContainerGroup( boolean forceRead ) {
		if( ( requiredContainerGroup == null ) || forceRead ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				requiredContainerGroup = ((ICFIntSchemaObj)schema).getTSecGroupTableObj().readTSecGroupByIdIdx( getPKey().getRequiredTenantId(),
					getTSecGrpMembBuff().getRequiredTSecGroupId(), forceRead );
			}
		}
		return( requiredContainerGroup );
	}

	public ICFSecSecUserObj getRequiredParentUser() {
		return( getRequiredParentUser( false ) );
	}

	public ICFSecSecUserObj getRequiredParentUser( boolean forceRead ) {
		if( ( requiredParentUser == null ) || forceRead ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				requiredParentUser = ((ICFIntSchemaObj)schema).getSecUserTableObj().readSecUserByIdIdx( getTSecGrpMembBuff().getRequiredSecUserId(), forceRead );
			}
		}
		return( requiredParentUser );
	}

	public void copyPKeyToBuff() {
		if( buff != null ) {
			buff.setRequiredTenantId( getPKey().getRequiredTenantId() );
			buff.setRequiredTSecGrpMembId( getPKey().getRequiredTSecGrpMembId() );
		}
		if( edit != null ) {
			edit.copyPKeyToBuff();
		}
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredTenantId( buff.getRequiredTenantId() );
		getPKey().setRequiredTSecGrpMembId( buff.getRequiredTSecGrpMembId() );
	}
}
