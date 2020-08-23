
// Description: Java 11 Default Factory implementation for MajorVersion.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow msobkow@sasktel.net
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
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

	/*
	 *	CFIntMajorVersionFactory implementation for MajorVersion
	 */
public class CFIntMajorVersionDefaultFactory
	implements ICFIntMajorVersionFactory
{
	public CFIntMajorVersionDefaultFactory() {
	}

	public CFIntMajorVersionPKey newPKey() {
		CFIntMajorVersionPKey pkey =
			new CFIntMajorVersionPKey();
		return( pkey );
	}

	public CFIntMajorVersionHPKey newHPKey() {
		CFIntMajorVersionHPKey hpkey =
			new CFIntMajorVersionHPKey();
		return( hpkey );
	}

	public CFIntMajorVersionByTenantIdxKey newTenantIdxKey() {
		CFIntMajorVersionByTenantIdxKey key =
			new CFIntMajorVersionByTenantIdxKey();
		return( key );
	}

	public CFIntMajorVersionBySubProjectIdxKey newSubProjectIdxKey() {
		CFIntMajorVersionBySubProjectIdxKey key =
			new CFIntMajorVersionBySubProjectIdxKey();
		return( key );
	}

	public CFIntMajorVersionByNameIdxKey newNameIdxKey() {
		CFIntMajorVersionByNameIdxKey key =
			new CFIntMajorVersionByNameIdxKey();
		return( key );
	}

	public CFIntMajorVersionBuff newBuff() {
		CFIntMajorVersionBuff buff =
			new CFIntMajorVersionBuff();
		return( buff );
	}

	public CFIntMajorVersionHBuff newHBuff() {
		CFIntMajorVersionHBuff hbuff =
			new CFIntMajorVersionHBuff();
		return( hbuff );
	}
}
