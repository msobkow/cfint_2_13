// Description: Java 11 implementation of a URLProtocol primary key object.

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
import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.apache.commons.codec.binary.Base64;

/*
 *	CFIntURLProtocolPKey Primary Key for URLProtocol

 *		requiredURLProtocolId	Required object attribute URLProtocolId. */
public class CFIntURLProtocolPKey
	implements Comparable<Object>,
		Serializable
{

	protected int requiredURLProtocolId;
	public CFIntURLProtocolPKey() {
		requiredURLProtocolId = CFIntURLProtocolBuff.URLPROTOCOLID_INIT_VALUE;
	}

	public int getRequiredURLProtocolId() {
		return( requiredURLProtocolId );
	}

	public void setRequiredURLProtocolId( int value ) {
		if( value < CFIntURLProtocolBuff.URLPROTOCOLID_MIN_VALUE ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				"setRequiredURLProtocolId",
				1,
				"value",
				value,
				CFIntURLProtocolBuff.URLPROTOCOLID_MIN_VALUE );
		}
		requiredURLProtocolId = value;
	}

	public boolean equals( Object obj ) {
		if( obj == null ) {
			return( false );
		}
		else if( obj instanceof CFIntURLProtocolHPKey ) {
			CFIntURLProtocolHPKey rhs = (CFIntURLProtocolHPKey)obj;
			if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFIntURLProtocolPKey ) {
			CFIntURLProtocolPKey rhs = (CFIntURLProtocolPKey)obj;
			if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFIntURLProtocolHBuff ) {
			CFIntURLProtocolHBuff rhs = (CFIntURLProtocolHBuff)obj;
			if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
				return( false );
			}
			return( true );
		}
		else if( obj instanceof CFIntURLProtocolBuff ) {
			CFIntURLProtocolBuff rhs = (CFIntURLProtocolBuff)obj;
			if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
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
		hashCode = hashCode + getRequiredURLProtocolId();
		return( hashCode & 0x7fffffff );
	}

	public int compareTo( Object obj ) {
		if( obj == null ) {
			return( -1 );
		}
		else if( obj instanceof CFIntURLProtocolHPKey ) {
			CFIntURLProtocolHPKey rhs = (CFIntURLProtocolHPKey)obj;
			if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
				return( -1 );
			}
			else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFIntURLProtocolPKey ) {
			CFIntURLProtocolPKey rhs = (CFIntURLProtocolPKey)obj;
			if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
				return( -1 );
			}
			else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFIntURLProtocolBuff ) {
			CFIntURLProtocolBuff rhs = (CFIntURLProtocolBuff)obj;
			if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
				return( -1 );
			}
			else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else if( obj instanceof CFIntURLProtocolHBuff ) {
			CFIntURLProtocolHBuff rhs = (CFIntURLProtocolHBuff)obj;
			if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
				return( -1 );
			}
			else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
				return( 1 );
			}
			return( 0 );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				"compareTo",
				"obj",
				obj,
				"CFIntURLProtocolPKey, CFIntURLProtocolBuff" );
		}
	}

	public String toString() {
		String ret = "<CFIntURLProtocolPKey"
			+ " RequiredURLProtocolId=" + "\"" + Integer.toString( getRequiredURLProtocolId() ) + "\""
			+ "/>";
		return( ret );
	}
}
