// Description: Java 11 edit object instance implementation for CFInt SecForm.

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

package org.msscf.msscf.v2_13.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;
import org.msscf.msscf.v2_13.cfsec.CFSecObj.*;
import org.msscf.msscf.v2_13.cfint.CFInt.*;

public class CFIntSecFormEditObj
	implements ICFIntSecFormEditObj
{
	protected ICFSecSecFormObj orig;
	protected CFSecSecFormBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecClusterObj requiredOwnerCluster;
	protected ICFSecSecAppObj requiredContainerApplication;

	public CFIntSecFormEditObj( ICFSecSecFormObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecSecFormBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredOwnerCluster = null;
		requiredContainerApplication = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecSecFormBuff buff = getBuff();
			createdBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecSecFormBuff buff = getBuff();
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
		return( CFIntSecFormObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "SecForm" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecSecAppObj scope = getRequiredContainerApplication();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecSecAppObj scope = getRequiredContainerApplication();
		return( scope );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredJEEServletMapName();
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

	public ICFSecSecFormObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecSecFormObj retobj = getSchema().getSecFormTableObj().realiseSecForm( (ICFIntSecFormObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsSecForm().forget();
	}

	public ICFSecSecFormObj read() {
		ICFSecSecFormObj retval = getOrigAsSecForm().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecFormObj read( boolean forceRead ) {
		ICFSecSecFormObj retval = getOrigAsSecForm().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecSecFormObj create() {
		copyBuffToOrig();
		ICFSecSecFormObj retobj = ((ICFIntSchemaObj)getOrigAsSecForm().getSchema()).getSecFormTableObj().createSecForm( getOrigAsSecForm() );
		if( retobj == getOrigAsSecForm() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecSecFormEditObj update() {
		getSchema().getSecFormTableObj().updateSecForm( (ICFSecSecFormObj)this );
		return( null );
	}

	public CFSecSecFormEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getSecFormTableObj().deleteSecForm( getOrigAsSecForm() );
		return( null );
	}

	public ICFSecSecFormTableObj getSecFormTable() {
		return( orig.getSchema().getSecFormTableObj() );
	}

	public ICFSecSecFormEditObj getEdit() {
		return( (ICFSecSecFormEditObj)this );
	}

	public ICFSecSecFormEditObj getEditAsSecForm() {
		return( (ICFSecSecFormEditObj)this );
	}

	public ICFSecSecFormEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecSecFormObj getOrig() {
		return( orig );
	}

	public ICFSecSecFormObj getOrigAsSecForm() {
		return( (ICFSecSecFormObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecSecFormBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFIntSchema)getOrigAsSecForm().getSchema().getBackingStore()).getFactorySecForm().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecSecFormBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredOwnerCluster = null;
			requiredContainerApplication = null;
		}
	}

	public CFSecSecFormBuff getSecFormBuff() {
		return( (CFSecSecFormBuff)getBuff() );
	}

	public CFSecSecFormPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecSecFormPKey value ) {
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

	public int getRequiredSecFormId() {
		return( getPKey().getRequiredSecFormId() );
	}

	public int getRequiredSecAppId() {
		return( getSecFormBuff().getRequiredSecAppId() );
	}

	public String getRequiredJEEServletMapName() {
		return( getSecFormBuff().getRequiredJEEServletMapName() );
	}

	public void setRequiredJEEServletMapName( String value ) {
		if( getSecFormBuff().getRequiredJEEServletMapName() != value ) {
			getSecFormBuff().setRequiredJEEServletMapName( value );
		}
	}

	public ICFSecClusterObj getRequiredOwnerCluster() {
		return( getRequiredOwnerCluster( false ) );
	}

	public ICFSecClusterObj getRequiredOwnerCluster( boolean forceRead ) {
		if( forceRead || ( requiredOwnerCluster == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecClusterObj obj = ((ICFIntSchemaObj)getOrigAsSecForm().getSchema()).getClusterTableObj().readClusterByIdIdx( getPKey().getRequiredClusterId() );
				requiredOwnerCluster = obj;
			}
		}
		return( requiredOwnerCluster );
	}

	public void setRequiredOwnerCluster( ICFSecClusterObj value ) {
			if( buff == null ) {
				getSecFormBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredId() );
				getSecFormBuff().setRequiredClusterId( value.getRequiredId() );
			}
			requiredOwnerCluster = value;
	}

	public ICFSecSecAppObj getRequiredContainerApplication() {
		return( getRequiredContainerApplication( false ) );
	}

	public ICFSecSecAppObj getRequiredContainerApplication( boolean forceRead ) {
		if( forceRead || ( requiredContainerApplication == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecSecAppObj obj = ((ICFIntSchemaObj)getOrigAsSecForm().getSchema()).getSecAppTableObj().readSecAppByIdIdx( getPKey().getRequiredClusterId(),
					getSecFormBuff().getRequiredSecAppId() );
				requiredContainerApplication = obj;
				if( obj != null ) {
					getSecFormBuff().setRequiredClusterId( obj.getRequiredClusterId() );
					getSecFormBuff().setRequiredSecAppId( obj.getRequiredSecAppId() );
					requiredContainerApplication = obj;
				}
			}
		}
		return( requiredContainerApplication );
	}

	public void setRequiredContainerApplication( ICFSecSecAppObj value ) {
			if( buff == null ) {
				getSecFormBuff();
			}
			if( value != null ) {
				getPKey().setRequiredClusterId( value.getRequiredClusterId() );
				getSecFormBuff().setRequiredClusterId( value.getRequiredClusterId() );
				getSecFormBuff().setRequiredSecAppId( value.getRequiredSecAppId() );
			}
			requiredContainerApplication = value;
	}

	public void copyPKeyToBuff() {
		buff.setRequiredClusterId( getPKey().getRequiredClusterId() );
		buff.setRequiredSecFormId( getPKey().getRequiredSecFormId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredClusterId( buff.getRequiredClusterId() );
		getPKey().setRequiredSecFormId( buff.getRequiredSecFormId() );
	}

	public void copyBuffToOrig() {
		CFSecSecFormBuff origBuff = getOrigAsSecForm().getSecFormBuff();
		CFSecSecFormBuff myBuff = getSecFormBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecSecFormBuff origBuff = getOrigAsSecForm().getSecFormBuff();
		CFSecSecFormBuff myBuff = getSecFormBuff();
		myBuff.set( origBuff );
	}
}