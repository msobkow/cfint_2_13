// Description: Java 11 implementation of a MinorVersion by MajorVerIdx index key object.

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

package org.msscf.msscf.cfint.v2_13.cfint.CFInt;

import java.lang.reflect.*;
import java.io.*;
import java.math.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

public class CFIntMinorVersionByMajorVerIdxKey
	implements Comparable<Object>,
		Serializable
{
	protected long requiredTenantId;
	protected long requiredMajorVersionId;
	public CFIntMinorVersionByMajorVerIdxKey() {
		requiredTenantId = CFIntMinorVersionBuff.TENANTID_INIT_VALUE;
		requiredMajorVersionId = CFIntMinorVersionBuff.MAJORVERSIONID_INIT_VALUE;
	}

	public long getRequiredTenantId() {
		return( requiredTenantId );
	}

	public void setRequiredTenantId( long value ) {
		if( value < CFIntMinorVersionBuff.TENANTID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredTenantId",
				1,
				"value",
				value,
				CFIntMinorVersionBuff.TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	public long getRequiredMajorVersionId() {
		return( requiredMajorVersionId );
	}

	public void setRequiredMajorVersionId( long value ) {
		if( value < CFIntMinorVersionBuff.MAJORVERSIONID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredMajorVersionId",
				1,
				"value",
				value,
				CFIntMinorVersionBuff.MAJORVERSIONID_MIN_VALUE );
		}
		requiredMajorVersionId = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFIntMinorVersionByMajorVerIdxKey ) {
			CFIntMinorVersionByMajorVerIdxKey rhs = (CFIntMinorVersionByMajorVerIdxKey)obj;
			if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
				return( false );
			}
			if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFIntMinorVersionBuff ) {
			CFIntMinorVersionBuff rhs = (CFIntMinorVersionBuff)obj;
			if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
				return( false );
			}
			if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
				return( false );
			}
			return( true );
		}
		else {
			return( false );
		}
	}

	public int hashCode() {
		int hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredMajorVersionId() );
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFIntMinorVersionByMajorVerIdxKey ) {
			CFIntMinorVersionByMajorVerIdxKey rhs = (CFIntMinorVersionByMajorVerIdxKey)obj;
			if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
				return( -1 );
			}
			else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
				return( 1 );
			}
			if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
				return( -1 );
			}
			else if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFIntMinorVersionBuff ) {
			CFIntMinorVersionBuff rhs = (CFIntMinorVersionBuff)obj;
			if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
				return( -1 );
			}
			else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
				return( 1 );
			}
			if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
				return( -1 );
			}
			else if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				"compareTo",
				"obj",
				obj,
				null );
		}
	}

	public String toString() {
		String ret = "<CFIntMinorVersionByMajorVerIdx"
			+ " RequiredTenantId=" + "\"" + Long.toString( getRequiredTenantId() ) + "\""
			+ " RequiredMajorVersionId=" + "\"" + Long.toString( getRequiredMajorVersionId() ) + "\""
			+ "/>";
		return( ret );
	}
}
