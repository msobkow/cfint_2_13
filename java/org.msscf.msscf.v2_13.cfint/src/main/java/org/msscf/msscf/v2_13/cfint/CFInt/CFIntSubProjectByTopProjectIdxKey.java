// Description: Java 11 implementation of a SubProject by TopProjectIdx index key object.

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

package org.msscf.msscf.v2_13.cfint.CFInt;

import java.lang.reflect.*;
import java.io.*;
import java.math.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

public class CFIntSubProjectByTopProjectIdxKey
	implements Comparable<Object>,
		Serializable
{
	protected long requiredTenantId;
	protected long requiredTopProjectId;
	public CFIntSubProjectByTopProjectIdxKey() {
		requiredTenantId = CFIntSubProjectBuff.TENANTID_INIT_VALUE;
		requiredTopProjectId = CFIntSubProjectBuff.TOPPROJECTID_INIT_VALUE;
	}

	public long getRequiredTenantId() {
		return( requiredTenantId );
	}

	public void setRequiredTenantId( long value ) {
		if( value < CFIntSubProjectBuff.TENANTID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredTenantId",
				1,
				"value",
				value,
				CFIntSubProjectBuff.TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	public long getRequiredTopProjectId() {
		return( requiredTopProjectId );
	}

	public void setRequiredTopProjectId( long value ) {
		if( value < CFIntSubProjectBuff.TOPPROJECTID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredTopProjectId",
				1,
				"value",
				value,
				CFIntSubProjectBuff.TOPPROJECTID_MIN_VALUE );
		}
		requiredTopProjectId = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFIntSubProjectByTopProjectIdxKey ) {
			CFIntSubProjectByTopProjectIdxKey rhs = (CFIntSubProjectByTopProjectIdxKey)obj;
			if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
				return( false );
			}
			if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFIntSubProjectBuff ) {
			CFIntSubProjectBuff rhs = (CFIntSubProjectBuff)obj;
			if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
				return( false );
			}
			if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
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
		hashCode = hashCode + (int)( getRequiredTopProjectId() );
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFIntSubProjectByTopProjectIdxKey ) {
			CFIntSubProjectByTopProjectIdxKey rhs = (CFIntSubProjectByTopProjectIdxKey)obj;
			if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
				return( -1 );
			}
			else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
				return( 1 );
			}
			if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
				return( -1 );
			}
			else if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFIntSubProjectBuff ) {
			CFIntSubProjectBuff rhs = (CFIntSubProjectBuff)obj;
			if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
				return( -1 );
			}
			else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
				return( 1 );
			}
			if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
				return( -1 );
			}
			else if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
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
		String ret = "<CFIntSubProjectByTopProjectIdx"
			+ " RequiredTenantId=" + "\"" + Long.toString( getRequiredTenantId() ) + "\""
			+ " RequiredTopProjectId=" + "\"" + Long.toString( getRequiredTopProjectId() ) + "\""
			+ "/>";
		return( ret );
	}
}
