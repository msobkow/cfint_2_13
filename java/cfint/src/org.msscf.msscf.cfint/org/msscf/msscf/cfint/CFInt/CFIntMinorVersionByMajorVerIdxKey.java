// Description: Java 11 implementation of a MinorVersion by MajorVerIdx index key object.

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

package org.msscf.msscf.cfint.CFInt;

import java.lang.reflect.*;
import java.io.*;
import java.math.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
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