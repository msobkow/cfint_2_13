// Description: Java 11 edit object instance implementation for CFInt ISOCcy.

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

public class CFIntISOCcyEditObj
	implements ICFIntISOCcyEditObj
{
	protected ICFSecISOCcyObj orig;
	protected CFSecISOCcyBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;

	public CFIntISOCcyEditObj( ICFSecISOCcyObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFSecISOCcyBuff origBuff = orig.getBuff();
		buff.set( origBuff );
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFSecISOCcyBuff buff = getBuff();
			createdBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFSecISOCcyBuff buff = getBuff();
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
		return( CFIntISOCcyObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "ISOCcy" );
	}

	public ICFLibAnyObj getScope() {
		return( null );
	}

	public ICFLibAnyObj getObjScope() {
		return( null );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredISOCode();
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

	public ICFSecISOCcyObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFSecISOCcyObj retobj = getSchema().getISOCcyTableObj().realiseISOCcy( (ICFIntISOCcyObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsISOCcy().forget();
	}

	public ICFSecISOCcyObj read() {
		ICFSecISOCcyObj retval = getOrigAsISOCcy().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOCcyObj read( boolean forceRead ) {
		ICFSecISOCcyObj retval = getOrigAsISOCcy().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFSecISOCcyObj create() {
		copyBuffToOrig();
		ICFSecISOCcyObj retobj = ((ICFIntSchemaObj)getOrigAsISOCcy().getSchema()).getISOCcyTableObj().createISOCcy( getOrigAsISOCcy() );
		if( retobj == getOrigAsISOCcy() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFSecISOCcyEditObj update() {
		getSchema().getISOCcyTableObj().updateISOCcy( (ICFSecISOCcyObj)this );
		return( null );
	}

	public CFSecISOCcyEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getISOCcyTableObj().deleteISOCcy( getOrigAsISOCcy() );
		return( null );
	}

	public ICFSecISOCcyTableObj getISOCcyTable() {
		return( orig.getSchema().getISOCcyTableObj() );
	}

	public ICFSecISOCcyEditObj getEdit() {
		return( (ICFSecISOCcyEditObj)this );
	}

	public ICFSecISOCcyEditObj getEditAsISOCcy() {
		return( (ICFSecISOCcyEditObj)this );
	}

	public ICFSecISOCcyEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFSecISOCcyObj getOrig() {
		return( orig );
	}

	public ICFSecISOCcyObj getOrigAsISOCcy() {
		return( (ICFSecISOCcyObj)orig );
	}

	public ICFSecSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFSecISOCcyBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFIntSchema)getOrigAsISOCcy().getSchema().getBackingStore()).getFactoryISOCcy().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFSecISOCcyBuff value ) {
		if( buff != value ) {
			buff = value;
		}
	}

	public CFSecISOCcyBuff getISOCcyBuff() {
		return( (CFSecISOCcyBuff)getBuff() );
	}

	public CFSecISOCcyPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFSecISOCcyPKey value ) {
		orig.setPKey( value );
		copyPKeyToBuff();
	}

	public boolean getIsNew() {
		return( orig.getIsNew() );
	}

	public void setIsNew( boolean value ) {
		orig.setIsNew( value );
	}

	public short getRequiredISOCcyId() {
		return( getPKey().getRequiredISOCcyId() );
	}

	public String getRequiredISOCode() {
		return( getISOCcyBuff().getRequiredISOCode() );
	}

	public void setRequiredISOCode( String value ) {
		if( getISOCcyBuff().getRequiredISOCode() != value ) {
			getISOCcyBuff().setRequiredISOCode( value );
		}
	}

	public String getRequiredName() {
		return( getISOCcyBuff().getRequiredName() );
	}

	public void setRequiredName( String value ) {
		if( getISOCcyBuff().getRequiredName() != value ) {
			getISOCcyBuff().setRequiredName( value );
		}
	}

	public String getOptionalUnitSymbol() {
		return( getISOCcyBuff().getOptionalUnitSymbol() );
	}

	public void setOptionalUnitSymbol( String value ) {
		if( getISOCcyBuff().getOptionalUnitSymbol() != value ) {
			getISOCcyBuff().setOptionalUnitSymbol( value );
		}
	}

	public short getRequiredPrecis() {
		return( getISOCcyBuff().getRequiredPrecis() );
	}

	public void setRequiredPrecis( short value ) {
		if( getISOCcyBuff().getRequiredPrecis() != value ) {
			getISOCcyBuff().setRequiredPrecis( value );
		}
	}

	public List<ICFSecISOCtryCcyObj> getOptionalChildrenCtry() {
		List<ICFSecISOCtryCcyObj> retval;
		retval = ((ICFIntSchemaObj)getOrigAsISOCcy().getSchema()).getISOCtryCcyTableObj().readISOCtryCcyByCcyIdx( getPKey().getRequiredISOCcyId(),
			false );
		return( retval );
	}

	public List<ICFSecISOCtryCcyObj> getOptionalChildrenCtry( boolean forceRead ) {
		List<ICFSecISOCtryCcyObj> retval;
		retval = ((ICFIntSchemaObj)getOrigAsISOCcy().getSchema()).getISOCtryCcyTableObj().readISOCtryCcyByCcyIdx( getPKey().getRequiredISOCcyId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		buff.setRequiredISOCcyId( getPKey().getRequiredISOCcyId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredISOCcyId( buff.getRequiredISOCcyId() );
	}

	public void copyBuffToOrig() {
		CFSecISOCcyBuff origBuff = getOrigAsISOCcy().getISOCcyBuff();
		CFSecISOCcyBuff myBuff = getISOCcyBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFSecISOCcyBuff origBuff = getOrigAsISOCcy().getISOCcyBuff();
		CFSecISOCcyBuff myBuff = getISOCcyBuff();
		myBuff.set( origBuff );
	}
}
