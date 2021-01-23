
// Description: Java 11 Default Factory implementation for MinorVersion.

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
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

	/*
	 *	CFIntMinorVersionFactory implementation for MinorVersion
	 */
public class CFIntMinorVersionDefaultFactory
	implements ICFIntMinorVersionFactory
{
	public CFIntMinorVersionDefaultFactory() {
	}

	public CFIntMinorVersionPKey newPKey() {
		CFIntMinorVersionPKey pkey =
			new CFIntMinorVersionPKey();
		return( pkey );
	}

	public CFIntMinorVersionHPKey newHPKey() {
		CFIntMinorVersionHPKey hpkey =
			new CFIntMinorVersionHPKey();
		return( hpkey );
	}

	public CFIntMinorVersionByTenantIdxKey newTenantIdxKey() {
		CFIntMinorVersionByTenantIdxKey key =
			new CFIntMinorVersionByTenantIdxKey();
		return( key );
	}

	public CFIntMinorVersionByMajorVerIdxKey newMajorVerIdxKey() {
		CFIntMinorVersionByMajorVerIdxKey key =
			new CFIntMinorVersionByMajorVerIdxKey();
		return( key );
	}

	public CFIntMinorVersionByNameIdxKey newNameIdxKey() {
		CFIntMinorVersionByNameIdxKey key =
			new CFIntMinorVersionByNameIdxKey();
		return( key );
	}

	public CFIntMinorVersionBuff newBuff() {
		CFIntMinorVersionBuff buff =
			new CFIntMinorVersionBuff();
		return( buff );
	}

	public CFIntMinorVersionHBuff newHBuff() {
		CFIntMinorVersionHBuff hbuff =
			new CFIntMinorVersionHBuff();
		return( hbuff );
	}
}
