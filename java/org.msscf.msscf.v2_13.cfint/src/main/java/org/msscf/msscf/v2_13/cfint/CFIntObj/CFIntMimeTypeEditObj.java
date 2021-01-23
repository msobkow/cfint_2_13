// Description: Java 11 edit object instance implementation for CFInt MimeType.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
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

public class CFIntMimeTypeEditObj
	implements ICFIntMimeTypeEditObj
{
	protected ICFIntMimeTypeObj orig;
	protected CFIntMimeTypeBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;

	public CFIntMimeTypeEditObj( ICFIntMimeTypeObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFIntMimeTypeBuff origBuff = orig.getBuff();
		buff.set( origBuff );
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFIntMimeTypeBuff buff = getBuff();
			createdBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFIntMimeTypeBuff buff = getBuff();
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
		return( CFIntMimeTypeObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "MimeType" );
	}

	public ICFLibAnyObj getScope() {
		return( null );
	}

	public ICFLibAnyObj getObjScope() {
		return( null );
	}

	public String getObjName() {
		String objName;
		objName = getRequiredName();
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

	public ICFIntMimeTypeObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFIntMimeTypeObj retobj = getSchema().getMimeTypeTableObj().realiseMimeType( (ICFIntMimeTypeObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsMimeType().forget();
	}

	public ICFIntMimeTypeObj read() {
		ICFIntMimeTypeObj retval = getOrigAsMimeType().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFIntMimeTypeObj read( boolean forceRead ) {
		ICFIntMimeTypeObj retval = getOrigAsMimeType().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFIntMimeTypeObj create() {
		copyBuffToOrig();
		ICFIntMimeTypeObj retobj = ((ICFIntSchemaObj)getOrigAsMimeType().getSchema()).getMimeTypeTableObj().createMimeType( getOrigAsMimeType() );
		if( retobj == getOrigAsMimeType() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFIntMimeTypeEditObj update() {
		getSchema().getMimeTypeTableObj().updateMimeType( (ICFIntMimeTypeObj)this );
		return( null );
	}

	public CFIntMimeTypeEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getMimeTypeTableObj().deleteMimeType( getOrigAsMimeType() );
		return( null );
	}

	public ICFIntMimeTypeTableObj getMimeTypeTable() {
		return( orig.getSchema().getMimeTypeTableObj() );
	}

	public ICFIntMimeTypeEditObj getEdit() {
		return( (ICFIntMimeTypeEditObj)this );
	}

	public ICFIntMimeTypeEditObj getEditAsMimeType() {
		return( (ICFIntMimeTypeEditObj)this );
	}

	public ICFIntMimeTypeEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFIntMimeTypeObj getOrig() {
		return( orig );
	}

	public ICFIntMimeTypeObj getOrigAsMimeType() {
		return( (ICFIntMimeTypeObj)orig );
	}

	public ICFIntSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFIntMimeTypeBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFIntSchema)getOrigAsMimeType().getSchema().getBackingStore()).getFactoryMimeType().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFIntMimeTypeBuff value ) {
		if( buff != value ) {
			buff = value;
		}
	}

	public CFIntMimeTypeBuff getMimeTypeBuff() {
		return( (CFIntMimeTypeBuff)getBuff() );
	}

	public CFIntMimeTypePKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFIntMimeTypePKey value ) {
		orig.setPKey( value );
		copyPKeyToBuff();
	}

	public boolean getIsNew() {
		return( orig.getIsNew() );
	}

	public void setIsNew( boolean value ) {
		orig.setIsNew( value );
	}

	public int getRequiredMimeTypeId() {
		return( getPKey().getRequiredMimeTypeId() );
	}

	public String getRequiredName() {
		return( getMimeTypeBuff().getRequiredName() );
	}

	public void setRequiredName( String value ) {
		if( getMimeTypeBuff().getRequiredName() != value ) {
			getMimeTypeBuff().setRequiredName( value );
		}
	}

	public String getOptionalFileTypes() {
		return( getMimeTypeBuff().getOptionalFileTypes() );
	}

	public void setOptionalFileTypes( String value ) {
		if( getMimeTypeBuff().getOptionalFileTypes() != value ) {
			getMimeTypeBuff().setOptionalFileTypes( value );
		}
	}

	public void copyPKeyToBuff() {
		buff.setRequiredMimeTypeId( getPKey().getRequiredMimeTypeId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredMimeTypeId( buff.getRequiredMimeTypeId() );
	}

	public void copyBuffToOrig() {
		CFIntMimeTypeBuff origBuff = getOrigAsMimeType().getMimeTypeBuff();
		CFIntMimeTypeBuff myBuff = getMimeTypeBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFIntMimeTypeBuff origBuff = getOrigAsMimeType().getMimeTypeBuff();
		CFIntMimeTypeBuff myBuff = getMimeTypeBuff();
		myBuff.set( origBuff );
	}
}
