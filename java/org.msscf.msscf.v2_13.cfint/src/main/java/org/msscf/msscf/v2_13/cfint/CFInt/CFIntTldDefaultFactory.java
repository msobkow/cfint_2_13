
// Description: Java 11 Default Factory implementation for Tld.

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
	 *	CFIntTldFactory implementation for Tld
	 */
public class CFIntTldDefaultFactory
	implements ICFIntTldFactory
{
	public CFIntTldDefaultFactory() {
	}

	public CFIntTldPKey newPKey() {
		CFIntTldPKey pkey =
			new CFIntTldPKey();
		return( pkey );
	}

	public CFIntTldHPKey newHPKey() {
		CFIntTldHPKey hpkey =
			new CFIntTldHPKey();
		return( hpkey );
	}

	public CFIntTldByTenantIdxKey newTenantIdxKey() {
		CFIntTldByTenantIdxKey key =
			new CFIntTldByTenantIdxKey();
		return( key );
	}

	public CFIntTldByNameIdxKey newNameIdxKey() {
		CFIntTldByNameIdxKey key =
			new CFIntTldByNameIdxKey();
		return( key );
	}

	public CFIntTldBuff newBuff() {
		CFIntTldBuff buff =
			new CFIntTldBuff();
		return( buff );
	}

	public CFIntTldHBuff newHBuff() {
		CFIntTldHBuff hbuff =
			new CFIntTldHBuff();
		return( hbuff );
	}
}
