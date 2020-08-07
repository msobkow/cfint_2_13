// Description: Java 11 edit object instance implementation for CFInt Tenant.

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

public class CFIntTenantEditObj
	implements ICFIntTenantEditObj
{
	protected ICFSecTenantObj orig;
	protected CFSecTenantBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecClusterObj requiredContainerCluster;

	public CFIntTenantEditObj( ICFSecTenantObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecTenantBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredContainerCluster = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecTenantBuff buff = getBuff();
			createdBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecTenantBuff buff = getBuff();
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
		return( CFIntTenantObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "Tenant" );
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
		objName = getRequiredTenantName();
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
			subObj = ((ICFIntSchemaObj)getSchema()).getTSecGroupTableObj().readTSecGroupByUNameIdx( getRequiredId(),
				nextName, false );
		}
		if( subObj == null ) {
			subObj = ((ICFIntSchemaObj)getSchema()).getTldTableObj().readTldByNameIdx( getRequiredId(),
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

	public ICFSecTenantObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecTenantObj retobj = getSchema().getTenantTableObj().realiseTenant( (ICFIntTenantObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsTenant().forget();
	}

	public ICFSecTenantObj read() {
		ICFSecTenantObj retval = getOrigAsTenant().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecTenantObj read( boolean forceRead ) {
		ICFSecTenantObj retval = getOrigAsTenant().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecTenantObj create() {
		copyBuffToOrig();
		ICFSecTenantObj retobj = ((ICFIntSchemaObj)getOrigAsTenant().getSchema()).getTenantTableObj().createTenant( getOrigAsTenant() );
		if( retobj == getOrigAsTenant() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecTenantEditObj update() {
		getSchema().getTenantTableObj().updateTenant( (ICFSecTenantObj)this );
		return( null );
	}

	public CFSecTenantEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getTenantTableObj().deleteTenant( getOrigAsTenant() );
		return( null );
	}

	public ICFSecTenantTableObj getTenantTable() {
		return( orig.getSchema().getTenantTableObj() );
	}

	public ICFSecTenantEditObj getEdit() {
		return( (ICFSecTenantEditObj)this );
	}

	public ICFSecTenantEditObj getEditAsTenant() {
		return( (ICFSecTenantEditObj)this );
	}

	public ICFSecTenantEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecTenantObj getOrig() {
		return( orig );
	}

	public ICFSecTenantObj getOrigAsTenant() {
		return( (ICFSecTenantObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecTenantBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFIntSchema)getOrigAsTenant().getSchema().getBackingStore()).getFactoryTenant().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecTenantBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredContainerCluster = null;
		}
	}

	public CFSecTenantBuff getTenantBuff() {
		return( (CFSecTenantBuff)getBuff() );
	}

	public CFSecTenantPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecTenantPKey value ) {
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
		return( getTenantBuff().getRequiredClusterId() );
	}

	public long getRequiredId() {
		return( getPKey().getRequiredId() );
	}

	public String getRequiredTenantName() {
		return( getTenantBuff().getRequiredTenantName() );
	}

	public void setRequiredTenantName( String value ) {
		if( getTenantBuff().getRequiredTenantName() != value ) {
			getTenantBuff().setRequiredTenantName( value );
		}
	}

	public ICFSecClusterObj getRequiredContainerCluster() {
		return( getRequiredContainerCluster( false ) );
	}

	public ICFSecClusterObj getRequiredContainerCluster( boolean forceRead ) {
		if( forceRead || ( requiredContainerCluster == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecClusterObj obj = ((ICFIntSchemaObj)getOrigAsTenant().getSchema()).getClusterTableObj().readClusterByIdIdx( getTenantBuff().getRequiredClusterId() );
				requiredContainerCluster = obj;
				if( obj != null ) {
					getTenantBuff().setRequiredClusterId( obj.getRequiredId() );
					requiredContainerCluster = obj;
				}
			}
		}
		return( requiredContainerCluster );
	}

	public void setRequiredContainerCluster( ICFSecClusterObj value ) {
			if( buff == null ) {
				getTenantBuff();
			}
			if( value != null ) {
				getTenantBuff().setRequiredClusterId( value.getRequiredId() );
			}
			requiredContainerCluster = value;
	}

	public List<ICFSecTSecGroupObj> getOptionalComponentsTSecGroup() {
		List<ICFSecTSecGroupObj> retval;
		retval = ((ICFIntSchemaObj)getOrigAsTenant().getSchema()).getTSecGroupTableObj().readTSecGroupByTenantIdx( getPKey().getRequiredId(),
			false );
		return( retval );
	}

	public List<ICFSecTSecGroupObj> getOptionalComponentsTSecGroup( boolean forceRead ) {
		List<ICFSecTSecGroupObj> retval;
		retval = ((ICFIntSchemaObj)getOrigAsTenant().getSchema()).getTSecGroupTableObj().readTSecGroupByTenantIdx( getPKey().getRequiredId(),
			forceRead );
		return( retval );
	}

	public List<ICFIntTldObj> getOptionalComponentsTld() {
		List<ICFIntTldObj> retval;
		retval = ((ICFIntSchemaObj)getOrigAsTenant().getSchema()).getTldTableObj().readTldByTenantIdx( getPKey().getRequiredId(),
			false );
		return( retval );
	}

	public List<ICFIntTldObj> getOptionalComponentsTld( boolean forceRead ) {
		List<ICFIntTldObj> retval;
		retval = ((ICFIntSchemaObj)getOrigAsTenant().getSchema()).getTldTableObj().readTldByTenantIdx( getPKey().getRequiredId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		buff.setRequiredId( getPKey().getRequiredId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredId( buff.getRequiredId() );
	}

	public void copyBuffToOrig() {
		CFSecTenantBuff origBuff = getOrigAsTenant().getTenantBuff();
		CFSecTenantBuff myBuff = getTenantBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecTenantBuff origBuff = getOrigAsTenant().getTenantBuff();
		CFSecTenantBuff myBuff = getTenantBuff();
		myBuff.set( origBuff );
	}
}
