// Description: Java 11 edit object instance implementation for CFInt Tld.

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

public class CFIntTldEditObj
	implements ICFIntTldEditObj
{
	protected ICFIntTldObj orig;
	protected CFIntTldBuff buff;
	protected ICFSecSecUserObj createdBy = null;
	protected ICFSecSecUserObj updatedBy = null;
	protected ICFSecTenantObj requiredContainerTenant;

	public CFIntTldEditObj( ICFIntTldObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFIntTldBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredContainerTenant = null;
	}

	public ICFSecSecUserObj getCreatedBy() {
		if( createdBy == null ) {
			CFIntTldBuff buff = getBuff();
			createdBy = ((ICFIntSchemaObj)getSchema()).getSecUserTableObj().readSecUserByIdIdx( buff.getCreatedByUserId() );
		}
		return( createdBy );
	}

	public Calendar getCreatedAt() {
		return( getBuff().getCreatedAt() );
	}

	public ICFSecSecUserObj getUpdatedBy() {
		if( updatedBy == null ) {
			CFIntTldBuff buff = getBuff();
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
		return( CFIntTldObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "Tld" );
	}

	public ICFLibAnyObj getScope() {
		return( getRequiredContainerTenant() );
	}

	public ICFLibAnyObj getObjScope() {
		return( getRequiredContainerTenant() );
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
		if( subObj == null ) {
			subObj = ((ICFIntSchemaObj)getSchema()).getTopDomainTableObj().readTopDomainByNameIdx( getRequiredTenantId(),
				getRequiredId(),
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
			else if( container instanceof ICFIntTenantObj ) {
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

	public ICFIntTldObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFIntTldObj retobj = getSchema().getTldTableObj().realiseTld( (ICFIntTldObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsTld().forget();
	}

	public ICFIntTldObj read() {
		ICFIntTldObj retval = getOrigAsTld().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFIntTldObj read( boolean forceRead ) {
		ICFIntTldObj retval = getOrigAsTld().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFIntTldObj create() {
		copyBuffToOrig();
		ICFIntTldObj retobj = ((ICFIntSchemaObj)getOrigAsTld().getSchema()).getTldTableObj().createTld( getOrigAsTld() );
		if( retobj == getOrigAsTld() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFIntTldEditObj update() {
		getSchema().getTldTableObj().updateTld( (ICFIntTldObj)this );
		return( null );
	}

	public CFIntTldEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getTldTableObj().deleteTld( getOrigAsTld() );
		return( null );
	}

	public ICFIntTldTableObj getTldTable() {
		return( orig.getSchema().getTldTableObj() );
	}

	public ICFIntTldEditObj getEdit() {
		return( (ICFIntTldEditObj)this );
	}

	public ICFIntTldEditObj getEditAsTld() {
		return( (ICFIntTldEditObj)this );
	}

	public ICFIntTldEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFIntTldObj getOrig() {
		return( orig );
	}

	public ICFIntTldObj getOrigAsTld() {
		return( (ICFIntTldObj)orig );
	}

	public ICFIntSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFIntTldBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFIntSchema)getOrigAsTld().getSchema().getBackingStore()).getFactoryTld().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFIntTldBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredContainerTenant = null;
		}
	}

	public CFIntTldBuff getTldBuff() {
		return( (CFIntTldBuff)getBuff() );
	}

	public CFIntTldPKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFIntTldPKey value ) {
		orig.setPKey( value );
		copyPKeyToBuff();
	}

	public boolean getIsNew() {
		return( orig.getIsNew() );
	}

	public void setIsNew( boolean value ) {
		orig.setIsNew( value );
	}

	public long getRequiredTenantId() {
		return( getPKey().getRequiredTenantId() );
	}

	public long getRequiredId() {
		return( getPKey().getRequiredId() );
	}

	public String getRequiredName() {
		return( getTldBuff().getRequiredName() );
	}

	public void setRequiredName( String value ) {
		if( getTldBuff().getRequiredName() != value ) {
			getTldBuff().setRequiredName( value );
		}
	}

	public String getOptionalDescription() {
		return( getTldBuff().getOptionalDescription() );
	}

	public void setOptionalDescription( String value ) {
		if( getTldBuff().getOptionalDescription() != value ) {
			getTldBuff().setOptionalDescription( value );
		}
	}

	public ICFSecTenantObj getRequiredContainerTenant() {
		return( getRequiredContainerTenant( false ) );
	}

	public ICFSecTenantObj getRequiredContainerTenant( boolean forceRead ) {
		if( forceRead || ( requiredContainerTenant == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecTenantObj obj = ((ICFIntSchemaObj)getOrigAsTld().getSchema()).getTenantTableObj().readTenantByIdIdx( getPKey().getRequiredTenantId() );
				requiredContainerTenant = obj;
				if( obj != null ) {
					getTldBuff().setRequiredTenantId( obj.getRequiredId() );
					requiredContainerTenant = obj;
				}
			}
		}
		return( requiredContainerTenant );
	}

	public void setRequiredContainerTenant( ICFSecTenantObj value ) {
			if( buff == null ) {
				getTldBuff();
			}
			if( value != null ) {
				getPKey().setRequiredTenantId( value.getRequiredId() );
				getTldBuff().setRequiredTenantId( value.getRequiredId() );
			}
			requiredContainerTenant = value;
	}

	public List<ICFIntTopDomainObj> getOptionalComponentsTopDomain() {
		List<ICFIntTopDomainObj> retval;
		retval = ((ICFIntSchemaObj)getOrigAsTld().getSchema()).getTopDomainTableObj().readTopDomainByTldIdx( getPKey().getRequiredTenantId(),
					getPKey().getRequiredId(),
			false );
		return( retval );
	}

	public List<ICFIntTopDomainObj> getOptionalComponentsTopDomain( boolean forceRead ) {
		List<ICFIntTopDomainObj> retval;
		retval = ((ICFIntSchemaObj)getOrigAsTld().getSchema()).getTopDomainTableObj().readTopDomainByTldIdx( getPKey().getRequiredTenantId(),
					getPKey().getRequiredId(),
			forceRead );
		return( retval );
	}

	public void copyPKeyToBuff() {
		buff.setRequiredTenantId( getPKey().getRequiredTenantId() );
		buff.setRequiredId( getPKey().getRequiredId() );
	}

	public void copyBuffToPKey() {
		getPKey().setRequiredTenantId( buff.getRequiredTenantId() );
		getPKey().setRequiredId( buff.getRequiredId() );
	}

	public void copyBuffToOrig() {
		CFIntTldBuff origBuff = getOrigAsTld().getTldBuff();
		CFIntTldBuff myBuff = getTldBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFIntTldBuff origBuff = getOrigAsTld().getTldBuff();
		CFIntTldBuff myBuff = getTldBuff();
		myBuff.set( origBuff );
	}
}
