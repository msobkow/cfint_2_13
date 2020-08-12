// Description: Java 11 base object instance implementation for CFInt ISOCtryCcy.

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

package org.msscf.msscf.cfint.v2_13.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFInt.*;

public class CFIntISOCtryCcyObj
	implements ICFIntISOCtryCcyObj
{
	public final static String CLASS_CODE = "a005";
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected boolean isNew;
	protected ICFSecISOCtryCcyEditObj edit;
	protected ICFSecSchemaObj schema;
	protected CFSecISOCtryCcyPKey pKey;
	protected CFSecISOCtryCcyBuff buff;
	protected ICFSecISOCtryObj requiredContainerCtry;
	protected ICFSecISOCcyObj requiredParentCcy;

	public CFIntISOCtryCcyObj() {
		isNew = true;
		requiredContainerCtry = null;
		requiredParentCcy = null;
	}

	public CFIntISOCtryCcyObj( ICFSecSchemaObj argSchema ) {
		schema = argSchema;
		isNew = true;
		edit = null;
		requiredContainerCtry = null;
		requiredParentCcy = null;
	}

	public String getClassCode() {
		return( CLASS_CODE );
	}

	public String getGenDefName() {
		return( "ISOCtryCcy" );
	}

	public ICFLibAnyObj getScope() {
		ICFSecISOCtryObj scope = getRequiredContainerCtry();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFSecISOCtryObj scope = getRequiredContainerCtry();
		return( scope );
	}

	public String getObjName() {
		String objName;
		short val = getRequiredISOCcyId();
		objName = Short.toString( val );
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

	public ICFSecISOCtryCcyObj realise() {
		ICFSecISOCtryCcyObj retobj = ((ICFIntSchemaObj)schema).getISOCtryCcyTableObj().realiseISOCtryCcy(
			(ICFSecISOCtryCcyObj)this );
		return( (ICFSecISOCtryCcyObj)retobj );
	}

	public void forget() {
		((ICFIntSchemaObj)schema).getISOCtryCcyTableObj().reallyDeepDisposeISOCtryCcy( (ICFSecISOCtryCcyObj)this );
	}

	public ICFSecISOCtryCcyObj read() {
		ICFSecISOCtryCcyObj retobj = ((ICFIntSchemaObj)schema).getISOCtryCcyTableObj().readISOCtryCcyByIdIdx( getPKey().getRequiredISOCtryId(),
			getPKey().getRequiredISOCcyId(), false );
		return( (ICFSecISOCtryCcyObj)retobj );
	}

	public ICFSecISOCtryCcyObj read( boolean forceRead ) {
		ICFSecISOCtryCcyObj retobj = ((ICFIntSchemaObj)schema).getISOCtryCcyTableObj().readISOCtryCcyByIdIdx( getPKey().getRequiredISOCtryId(),
			getPKey().getRequiredISOCcyId(), forceRead );
		return( (ICFSecISOCtryCcyObj)retobj );
	}

	public ICFSecISOCtryCcyTableObj getISOCtryCcyTable() {
		return( ((ICFIntSchemaObj)schema).getISOCtryCcyTableObj() );
	}

	public ICFSecSchemaObj getSchema() {
		return( schema );
	}

	public void setSchema( ICFSecSchemaObj value ) {
		schema = value;
	}

	public CFSecISOCtryCcyBuff getBuff() {
		if( buff == null ) {
			if( isNew ) {
				buff = ((ICFIntSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newBuff();
			}
			else {
				// Read the data buff via the backing store
				buff = ((ICFIntSchema)schema.getBackingStore()).getTableISOCtryCcy().readDerivedByIdIdx( ((ICFIntSchemaObj)schema).getAuthorization(),
						getPKey().getRequiredISOCtryId(),
						getPKey().getRequiredISOCcyId() );
				if( buff != null ) {
					copyBuffToPKey();
				}
			}
		}
		return( buff );
	}

	public void setBuff( CFSecISOCtryCcyBuff value ) {
		if( ! ( ( value == null ) || ( value instanceof CFSecISOCtryCcyBuff ) ) ) {
			throw new CFLibUnsupportedClassException( getClass(),
				"setBuff",
				"value",
				value,
				"CFSecISOCtryCcyBuff" );
		}
		buff = value;
		copyBuffToPKey();
		requiredContainerCtry = null;
		requiredParentCcy = null;
	}

	public CFSecISOCtryCcyBuff getISOCtryCcyBuff() {
		return( (CFSecISOCtryCcyBuff)getBuff() );
	}

	public CFSecISOCtryCcyPKey getPKey() {
		if( pKey == null ) {
			pKey = ((ICFIntSchema)schema.getBackingStore()).getFactoryISOCtryCcy().newPKey();
		}
		return( pKey );
	}

	public void setPKey( CFSecISOCtryCcyPKey value ) {
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

	public ICFSecISOCtryCcyEditObj beginEdit() {
		if( edit != null ) {
			throw new CFLibUsageException( getClass(), "beginEdit", "An edit is already open" );
		}
		ICFSecISOCtryCcyObj lockobj;
		if( getIsNew() ) {
			lockobj = (ICFSecISOCtryCcyObj)this;
		}
		else {
			lockobj = ((ICFIntSchemaObj)schema).getISOCtryCcyTableObj().lockISOCtryCcy( getPKey() );
		}
		edit = ((ICFIntSchemaObj)schema).getISOCtryCcyTableObj().newEditInstance( lockobj );
		return( (ICFSecISOCtryCcyEditObj)edit );
	}

	public void endEdit() {
		edit = null;
	}

	public ICFSecISOCtryCcyEditObj getEdit() {
		return( edit );
	}

	public ICFSecISOCtryCcyEditObj getEditAsISOCtryCcy() {
		return( (ICFSecISOCtryCcyEditObj)edit );
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecISOCtryCcyBuff buff = getBuff();
			createdBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecISOCtryCcyBuff buff = getBuff();
			updatedBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getUpdatedByUserId() );
		}
		return( updatedBy );
	}

	public Calendar getUpdatedAt() {
		return( getBuff().getUpdatedAt() );
	}

	public short getRequiredISOCtryId() {
		return( getPKey().getRequiredISOCtryId() );
	}

	public short getRequiredISOCcyId() {
		return( getPKey().getRequiredISOCcyId() );
	}

	public ICFSecISOCtryObj getRequiredContainerCtry() {
		return( getRequiredContainerCtry( false ) );
	}

	public ICFSecISOCtryObj getRequiredContainerCtry( boolean forceRead ) {
		if( ( requiredContainerCtry == null ) || forceRead ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				requiredContainerCtry = ((ICFIntSchemaObj)schema).getISOCtryTableObj().readISOCtryByIdIdx( getPKey().getRequiredISOCtryId(), forceRead );
			}
		}
		return( requiredContainerCtry );
	}

	public ICFSecISOCcyObj getRequiredParentCcy() {
		return( getRequiredParentCcy( false ) );
	}

	public ICFSecISOCcyObj getRequiredParentCcy( boolean forceRead ) {
		if( ( requiredParentCcy == null ) || forceRead ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				requiredParentCcy = ((ICFIntSchemaObj)schema).getISOCcyTableObj().readISOCcyByIdIdx( getPKey().getRequiredISOCcyId(), forceRead );
			}
		}
		return( requiredParentCcy );
	}

	public void copyPKeyToBuff() {
		if( buff != null ) {
			buff.setRequiredISOCtryId( getPKey().getRequiredISOCtryId() );
			buff.setRequiredISOCcyId( getPKey().getRequiredISOCcyId() );
		}
		if( edit != null ) {
			edit.copyPKeyToBuff();
		}
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredISOCtryId( buff.getRequiredISOCtryId() );
		getPKey().setRequiredISOCcyId( buff.getRequiredISOCcyId() );
	}
}
