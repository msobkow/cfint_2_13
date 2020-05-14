// Description: Java 11 implementation of a License by DomainIdx index key object.

/*
 *	com.github.msobkow.CFInt
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

package com.github.msobkow.cfint.CFInt;

import java.lang.reflect.*;
import java.io.*;
import java.math.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;

public class CFIntLicenseByDomainIdxKey
	implements Comparable<Object>,
		Serializable
{
	protected long requiredTenantId;
	protected long requiredTopDomainId;
	public CFIntLicenseByDomainIdxKey() {
		requiredTenantId = CFIntLicenseBuff.TENANTID_INIT_VALUE;
		requiredTopDomainId = CFIntLicenseBuff.TOPDOMAINID_INIT_VALUE;
	}

	public long getRequiredTenantId() {
		return( requiredTenantId );
	}

	public void setRequiredTenantId( long value ) {
		if( value < CFIntLicenseBuff.TENANTID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredTenantId",
				1,
				"value",
				value,
				CFIntLicenseBuff.TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	public long getRequiredTopDomainId() {
		return( requiredTopDomainId );
	}

	public void setRequiredTopDomainId( long value ) {
		if( value < CFIntLicenseBuff.TOPDOMAINID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredTopDomainId",
				1,
				"value",
				value,
				CFIntLicenseBuff.TOPDOMAINID_MIN_VALUE );
		}
		requiredTopDomainId = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFIntLicenseByDomainIdxKey ) {
			CFIntLicenseByDomainIdxKey rhs = (CFIntLicenseByDomainIdxKey)obj;
			if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
				return( false );
			}
			if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFIntLicenseBuff ) {
			CFIntLicenseBuff rhs = (CFIntLicenseBuff)obj;
			if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
				return( false );
			}
			if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
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
		hashCode = hashCode + (int)( getRequiredTopDomainId() );
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( 1 );
		}
		else if( obj instanceof CFIntLicenseByDomainIdxKey ) {
			CFIntLicenseByDomainIdxKey rhs = (CFIntLicenseByDomainIdxKey)obj;
			if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
				return( -1 );
			}
			else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
				return( 1 );
			}
			if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
				return( -1 );
			}
			else if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFIntLicenseBuff ) {
			CFIntLicenseBuff rhs = (CFIntLicenseBuff)obj;
			if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
				return( -1 );
			}
			else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
				return( 1 );
			}
			if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
				return( -1 );
			}
			else if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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
		String ret = "<CFIntLicenseByDomainIdx"
			+ " RequiredTenantId=" + "\"" + Long.toString( getRequiredTenantId() ) + "\""
			+ " RequiredTopDomainId=" + "\"" + Long.toString( getRequiredTopDomainId() ) + "\""
			+ "/>";
		return( ret );
	}
}
