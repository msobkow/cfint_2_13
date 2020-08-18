// Description: Java 11 edit object instance implementation for CFInt License.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
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

public class CFIntLicenseEditObj
	implements ICFIntLicenseEditObj
{
	protected ICFIntLicenseObj orig;
	protected CFIntLicenseBuff buff;
	protected ICFSecTenantObj requiredOwnerTenant;
	protected ICFIntTopDomainObj requiredContainerTopDomain;

	public CFIntLicenseEditObj( ICFIntLicenseObj argOrig ) {
		orig = argOrig;
		getBuff();
		CFIntLicenseBuff origBuff = orig.getBuff();
		buff.set( origBuff );
		requiredOwnerTenant = null;
		requiredContainerTopDomain = null;
	}

	public String getClassCode() {
		return( CFIntLicenseObj.CLASS_CODE );
	}

	public String getGenDefName() {
		return( "License" );
	}

	public ICFLibAnyObj getScope() {
		ICFIntTopDomainObj scope = getRequiredContainerTopDomain();
		return( scope );
	}

	public ICFLibAnyObj getObjScope() {
		ICFIntTopDomainObj scope = getRequiredContainerTopDomain();
		return( scope );
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

	public ICFIntLicenseObj realise() {
		// We realise this so that it's buffer will get copied to orig during realization
		ICFIntLicenseObj retobj = getSchema().getLicenseTableObj().realiseLicense( (ICFIntLicenseObj)this );
		return( retobj );
	}

	public void forget() {
		getOrigAsLicense().forget();
	}

	public ICFIntLicenseObj read() {
		ICFIntLicenseObj retval = getOrigAsLicense().read();
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFIntLicenseObj read( boolean forceRead ) {
		ICFIntLicenseObj retval = getOrigAsLicense().read( forceRead );
		if( retval != orig ) {
			throw new CFLibUsageException( getClass(),
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	public ICFIntLicenseObj create() {
		copyBuffToOrig();
		ICFIntLicenseObj retobj = ((ICFIntSchemaObj)getOrigAsLicense().getSchema()).getLicenseTableObj().createLicense( getOrigAsLicense() );
		if( retobj == getOrigAsLicense() ) {
			copyOrigToBuff();
		}
		return( retobj );
	}

	public CFIntLicenseEditObj update() {
		getSchema().getLicenseTableObj().updateLicense( (ICFIntLicenseObj)this );
		return( null );
	}

	public CFIntLicenseEditObj deleteInstance() {
		if( getIsNew() ) {
			throw new CFLibUsageException( getClass(), "delete", "Cannot delete a new instance" );
		}
		getSchema().getLicenseTableObj().deleteLicense( getOrigAsLicense() );
		return( null );
	}

	public ICFIntLicenseTableObj getLicenseTable() {
		return( orig.getSchema().getLicenseTableObj() );
	}

	public ICFIntLicenseEditObj getEdit() {
		return( (ICFIntLicenseEditObj)this );
	}

	public ICFIntLicenseEditObj getEditAsLicense() {
		return( (ICFIntLicenseEditObj)this );
	}

	public ICFIntLicenseEditObj beginEdit() {
		throw new CFLibUsageException( getClass(), "beginEdit", "Cannot edit an edition" );
	}

	public void endEdit() {
		orig.endEdit();
	}

	public ICFIntLicenseObj getOrig() {
		return( orig );
	}

	public ICFIntLicenseObj getOrigAsLicense() {
		return( (ICFIntLicenseObj)orig );
	}

	public ICFIntSchemaObj getSchema() {
		return( orig.getSchema() );
	}

	public CFIntLicenseBuff getBuff() {
		if( buff == null ) {
			buff = ((ICFIntSchema)getOrigAsLicense().getSchema().getBackingStore()).getFactoryLicense().newBuff();
			buff.set( orig.getBuff() );
		}
		return( buff );
	}

	public void setBuff( CFIntLicenseBuff value ) {
		if( buff != value ) {
			buff = value;
			requiredOwnerTenant = null;
			requiredContainerTopDomain = null;
		}
	}

	public CFIntLicenseBuff getLicenseBuff() {
		return( (CFIntLicenseBuff)getBuff() );
	}

	public CFIntLicensePKey getPKey() {
		return( orig.getPKey() );
	}

	public void setPKey( CFIntLicensePKey value ) {
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

	public long getRequiredTopDomainId() {
		return( getLicenseBuff().getRequiredTopDomainId() );
	}

	public String getRequiredName() {
		return( getLicenseBuff().getRequiredName() );
	}

	public void setRequiredName( String value ) {
		if( getLicenseBuff().getRequiredName() != value ) {
			getLicenseBuff().setRequiredName( value );
		}
	}

	public String getOptionalDescription() {
		return( getLicenseBuff().getOptionalDescription() );
	}

	public void setOptionalDescription( String value ) {
		if( getLicenseBuff().getOptionalDescription() != value ) {
			getLicenseBuff().setOptionalDescription( value );
		}
	}

	public String getOptionalEmbeddedText() {
		return( getLicenseBuff().getOptionalEmbeddedText() );
	}

	public void setOptionalEmbeddedText( String value ) {
		if( getLicenseBuff().getOptionalEmbeddedText() != value ) {
			getLicenseBuff().setOptionalEmbeddedText( value );
		}
	}

	public String getOptionalFullText() {
		return( getLicenseBuff().getOptionalFullText() );
	}

	public void setOptionalFullText( String value ) {
		if( getLicenseBuff().getOptionalFullText() != value ) {
			getLicenseBuff().setOptionalFullText( value );
		}
	}

	public ICFSecTenantObj getRequiredOwnerTenant() {
		return( getRequiredOwnerTenant( false ) );
	}

	public ICFSecTenantObj getRequiredOwnerTenant( boolean forceRead ) {
		if( forceRead || ( requiredOwnerTenant == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFSecTenantObj obj = ((ICFIntSchemaObj)getOrigAsLicense().getSchema()).getTenantTableObj().readTenantByIdIdx( getPKey().getRequiredTenantId() );
				requiredOwnerTenant = obj;
			}
		}
		return( requiredOwnerTenant );
	}

	public void setRequiredOwnerTenant( ICFSecTenantObj value ) {
			if( buff == null ) {
				getLicenseBuff();
			}
			if( value != null ) {
				getPKey().setRequiredTenantId( value.getRequiredId() );
				getLicenseBuff().setRequiredTenantId( value.getRequiredId() );
			}
			requiredOwnerTenant = value;
	}

	public ICFIntTopDomainObj getRequiredContainerTopDomain() {
		return( getRequiredContainerTopDomain( false ) );
	}

	public ICFIntTopDomainObj getRequiredContainerTopDomain( boolean forceRead ) {
		if( forceRead || ( requiredContainerTopDomain == null ) ) {
			boolean anyMissing = false;
			if( ! anyMissing ) {
				ICFIntTopDomainObj obj = ((ICFIntSchemaObj)getOrigAsLicense().getSchema()).getTopDomainTableObj().readTopDomainByIdIdx( getPKey().getRequiredTenantId(),
					getLicenseBuff().getRequiredTopDomainId() );
				requiredContainerTopDomain = obj;
				if( obj != null ) {
					getLicenseBuff().setRequiredTenantId( obj.getRequiredTenantId() );
					getLicenseBuff().setRequiredTopDomainId( obj.getRequiredId() );
					requiredContainerTopDomain = obj;
				}
			}
		}
		return( requiredContainerTopDomain );
	}

	public void setRequiredContainerTopDomain( ICFIntTopDomainObj value ) {
			if( buff == null ) {
				getLicenseBuff();
			}
			if( value != null ) {
				getPKey().setRequiredTenantId( value.getRequiredTenantId() );
				getLicenseBuff().setRequiredTenantId( value.getRequiredTenantId() );
				getLicenseBuff().setRequiredTopDomainId( value.getRequiredId() );
			}
			requiredContainerTopDomain = value;
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
		CFIntLicenseBuff origBuff = getOrigAsLicense().getLicenseBuff();
		CFIntLicenseBuff myBuff = getLicenseBuff();
		origBuff.set( myBuff );
	}

	public void copyOrigToBuff() {
		CFIntLicenseBuff origBuff = getOrigAsLicense().getLicenseBuff();
		CFIntLicenseBuff myBuff = getLicenseBuff();
		myBuff.set( origBuff );
	}
}
