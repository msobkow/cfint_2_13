// Description: Java 11 base object instance implementation for CFInt SecUser.

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

package org.msscf.msscf.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFInt.*;

public class CFIntSecUserObj
	implements ICFIntSecUserObj
{
	public final static String CLASS_CODE = "a011";
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected boolean isNew;
	protected ICFSecSecUserEditObj edit;
	protected ICFSecSchemaObj schema;
	protected CFSecSecUserPKey pKey;
	protected CFSecSecUserBuff buff;
	protected ICFSecSecDeviceObj optionalLookupDefDev;

	public CFIntSecUserObj() {
		isNew = true;
		optionalLookupDefDev = null;
	}

	public CFIntSecUserObj( ICFSecSchemaObj argSchema ) {
		schema = argSchema;
		isNew = true;
		edit = null;
		optionalLookupDefDev = null;
	}

	public String getClassCode() {
		return( CLASS_CODE );
	}

	public String getGenDefName() {
		return( "SecUser" );
	}

	public ICFLibAnyObj getScope() {
		return( null );
	}

	public ICFLibAnyObj getObjScope() {
		return( null );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredLoginId();
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
		if( subObj == null ) {
			subObj = ((ICFIntSchemaObj)getSchema()).getSecDeviceTableObj().readSecDeviceByNameIdx( getRequiredSecUserId(),
				nextName, false );
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

	public ICFSecSecUserObj realise() {
		ICFSecSecUserObj retobj = ((ICFIntSchemaObj)schema).getSecUserTableObj().realiseSecUser(
			(ICFSecSecUserObj)this );
		return( (ICFSecSecUserObj)retobj );
	}

	public void forget() {
		((ICFIntSchemaObj)schema).getSecUserTableObj().reallyDeepDisposeSecUser( (ICFSecSecUserObj)this );
	}

	public ICFSecSecUserObj read() {
		ICFSecSecUserObj retobj = ((ICFIntSchemaObj)schema).getSecUserTableObj().readSecUserByIdIdx( getPKey().getRequiredSecUserId(), false );
		return( (ICFSecSecUserObj)retobj );
	}

	public ICFSecSecUserObj read( boolean forceRead ) {
		ICFSecSecUserObj retobj = ((ICFIntSchemaObj)schema).getSecUserTableObj().readSecUserByIdIdx( getPKey().getRequiredSecUserId(), forceRead );
		return( (ICFSecSecUserObj)retobj );
	}

	public ICFSecSecUserTableObj getSecUserTable() {
		return( ((ICFIntSchemaObj)schema).getSecUserTableObj() );
	}

	public ICFSecSchemaObj getSchema() {
		return( schema );
	}

	public void setSchema( ICFSecSchemaObj value ) {
		schema = value;
	}

	public CFSecSecUserBuff getBuff() {
		if( buff == null ) {
			if( isNew ) {
				buff = ((ICFIntSchema)schema.getBackingStore()).getFactorySecUser().newBuff();
			}
			else {
				// Read the data buff via the backing store
				buff = ((ICFIntSchema)schema.getBackingStore()).getTableSecUser().readDerivedByIdIdx( ((ICFIntSchemaObj)schema).getAuthorization(),
						getPKey().getRequiredSecUserId() );
				if( buff != null ) {
					copyBuffToPKey();
				}
			}
		}
		return( buff );
	}

	public void setBuff( CFSecSecUserBuff value ) {
		if( ! ( ( value == null ) || ( value instanceof CFSecSecUserBuff ) ) ) {
			throw new CFLibUnsupportedClassException( getClass(),
				"setBuff",
				"value",
				value,
				"CFSecSecUserBuff" );
		}
		buff = value;
		copyBuffToPKey();
		optionalLookupDefDev = null;
	}

	public CFSecSecUserBuff getSecUserBuff() {
		return( (CFSecSecUserBuff)getBuff() );
	}

	public CFSecSecUserPKey getPKey() {
		if( pKey == null ) {
			pKey = ((ICFIntSchema)schema.getBackingStore()).getFactorySecUser().newPKey();
		}
		return( pKey );
	}

	public void setPKey( CFSecSecUserPKey value ) {
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

	public ICFSecSecUserEditObj beginEdit() {
		if( edit != null ) {
			throw new CFLibUsageException( getClass(), "beginEdit", "An edit is already open" );
		}
		ICFSecSecUserObj lockobj;
		if( getIsNew() ) {
			lockobj = (ICFSecSecUserObj)this;
		}
		else {
			lockobj = ((ICFIntSchemaObj)schema).getSecUserTableObj().lockSecUser( getPKey() );
		}
		edit = ((ICFIntSchemaObj)schema).getSecUserTableObj().newEditInstance( lockobj );
		return( (ICFSecSecUserEditObj)edit );
	}

	public void endEdit() {
		edit = null;
	}

	public ICFSecSecUserEditObj getEdit() {
		return( edit );
	}

	public ICFSecSecUserEditObj getEditAsSecUser() {
		return( (ICFSecSecUserEditObj)edit );
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecSecUserBuff buff = getBuff();
			createdBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecSecUserBuff buff = getBuff();
			updatedBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	public Calendar getUpdatedAt() {
		return( getBuff().getUpdatedAt() );
	}

	public UUID getRequiredSecUserId() {
		return( getPKey().getRequiredSecUserId() );
	}

	public String getRequiredLoginId() {
		return( getSecUserBuff().getRequiredLoginId() );
	}

	public String getRequiredEMailAddress() {
		return( getSecUserBuff().getRequiredEMailAddress() );
	}

	public UUID getOptionalEMailConfirmUuid() {
		return( getSecUserBuff().getOptionalEMailConfirmUuid() );
	}

	public UUID getOptionalDfltDevUserId() {
		return( getSecUserBuff().getOptionalDfltDevUserId() );
	}

	public String getOptionalDfltDevName() {
		return( getSecUserBuff().getOptionalDfltDevName() );
	}

	public String getRequiredPasswordHash() {
		return( getSecUserBuff().getRequiredPasswordHash() );
	}

	public UUID getOptionalPasswordResetUuid() {
		return( getSecUserBuff().getOptionalPasswordResetUuid() );
	}

	public List<ICFSecSecDeviceObj> getOptionalComponentsSecDev() {
		List<ICFSecSecDeviceObj> retval;
		retval = ((ICFIntSchemaObj)schema).getSecDeviceTableObj().readSecDeviceByUserIdx( getPKey().getRequiredSecUserId(),
			false );
		return( retval );
	}

	public List<ICFSecSecDeviceObj> getOptionalComponentsSecDev( boolean forceRead ) {
		List<ICFSecSecDeviceObj> retval;
		retval = ((ICFIntSchemaObj)schema).getSecDeviceTableObj().readSecDeviceByUserIdx( getPKey().getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	public ICFSecSecDeviceObj getOptionalLookupDefDev() {
		return( getOptionalLookupDefDev( false ) );
	}

	public ICFSecSecDeviceObj getOptionalLookupDefDev( boolean forceRead ) {
		if( ( optionalLookupDefDev == null ) || forceRead ) {
			boolean anyMissing = false;
			if( getSecUserBuff().getOptionalDfltDevUserId() == null ) {
				anyMissing = true;
			}
			if( getSecUserBuff().getOptionalDfltDevName() == null ) {
				anyMissing = true;
			}
			if( ! anyMissing ) {
				optionalLookupDefDev = ((ICFIntSchemaObj)schema).getSecDeviceTableObj().readSecDeviceByIdIdx( getSecUserBuff().getOptionalDfltDevUserId(),
					getSecUserBuff().getOptionalDfltDevName(), forceRead );
			}
		}
		return( optionalLookupDefDev );
	}

	public List<ICFSecSecSessionObj> getOptionalComponentsSecSess() {
		List<ICFSecSecSessionObj> retval;
		retval = ((ICFIntSchemaObj)schema).getSecSessionTableObj().readSecSessionBySecUserIdx( getPKey().getRequiredSecUserId(),
			false );
		return( retval );
	}

	public List<ICFSecSecSessionObj> getOptionalComponentsSecSess( boolean forceRead ) {
		List<ICFSecSecSessionObj> retval;
		retval = ((ICFIntSchemaObj)schema).getSecSessionTableObj().readSecSessionBySecUserIdx( getPKey().getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecSecSessionObj> getOptionalChildrenSecProxy() {
		List<ICFSecSecSessionObj> retval;
		retval = ((ICFIntSchemaObj)schema).getSecSessionTableObj().readSecSessionBySecProxyIdx( getPKey().getRequiredSecUserId(),
			false );
		return( retval );
	}

	public List<ICFSecSecSessionObj> getOptionalChildrenSecProxy( boolean forceRead ) {
		List<ICFSecSecSessionObj> retval;
		retval = ((ICFIntSchemaObj)schema).getSecSessionTableObj().readSecSessionBySecProxyIdx( getPKey().getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecSecGrpMembObj> getOptionalChildrenSecGrpMemb() {
		List<ICFSecSecGrpMembObj> retval;
		retval = ((ICFIntSchemaObj)schema).getSecGrpMembTableObj().readSecGrpMembByUserIdx( getPKey().getRequiredSecUserId(),
			false );
		return( retval );
	}

	public List<ICFSecSecGrpMembObj> getOptionalChildrenSecGrpMemb( boolean forceRead ) {
		List<ICFSecSecGrpMembObj> retval;
		retval = ((ICFIntSchemaObj)schema).getSecGrpMembTableObj().readSecGrpMembByUserIdx( getPKey().getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	public List<ICFSecTSecGrpMembObj> getOptionalChildrenTSecGrpMemb() {
		List<ICFSecTSecGrpMembObj> retval;
		retval = ((ICFIntSchemaObj)schema).getTSecGrpMembTableObj().readTSecGrpMembByUserIdx( getPKey().getRequiredSecUserId(),
			false );
		return( retval );
	}

	public List<ICFSecTSecGrpMembObj> getOptionalChildrenTSecGrpMemb( boolean forceRead ) {
		List<ICFSecTSecGrpMembObj> retval;
		retval = ((ICFIntSchemaObj)schema).getTSecGrpMembTableObj().readTSecGrpMembByUserIdx( getPKey().getRequiredSecUserId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		if( buff != null ) {
			buff.setRequiredSecUserId( getPKey().getRequiredSecUserId() );
		}
		if( edit != null ) {
			edit.copyPKeyToBuff();
		}
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredSecUserId( buff.getRequiredSecUserId() );
	}
}
