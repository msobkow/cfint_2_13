
// Description: Java 11 Default Factory implementation for TSecGrpMemb.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
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
	 *	CFIntTSecGrpMembFactory implementation for TSecGrpMemb
	 */
public class CFIntTSecGrpMembDefaultFactory
	extends CFSecTSecGrpMembDefaultFactory
	implements ICFIntTSecGrpMembFactory
{
	public CFIntTSecGrpMembDefaultFactory() {
		super();
	}

	public CFSecTSecGrpMembPKey newPKey() {
		CFSecTSecGrpMembPKey pkey =
			new CFSecTSecGrpMembPKey();
		return( pkey );
	}

	public CFSecTSecGrpMembHPKey newHPKey() {
		CFSecTSecGrpMembHPKey hpkey =
			new CFSecTSecGrpMembHPKey();
		return( hpkey );
	}

	public CFSecTSecGrpMembByTenantIdxKey newTenantIdxKey() {
		CFSecTSecGrpMembByTenantIdxKey key =
			new CFSecTSecGrpMembByTenantIdxKey();
		return( key );
	}

	public CFSecTSecGrpMembByGroupIdxKey newGroupIdxKey() {
		CFSecTSecGrpMembByGroupIdxKey key =
			new CFSecTSecGrpMembByGroupIdxKey();
		return( key );
	}

	public CFSecTSecGrpMembByUserIdxKey newUserIdxKey() {
		CFSecTSecGrpMembByUserIdxKey key =
			new CFSecTSecGrpMembByUserIdxKey();
		return( key );
	}

	public CFSecTSecGrpMembByUUserIdxKey newUUserIdxKey() {
		CFSecTSecGrpMembByUUserIdxKey key =
			new CFSecTSecGrpMembByUUserIdxKey();
		return( key );
	}

	public CFSecTSecGrpMembBuff newBuff() {
		CFSecTSecGrpMembBuff buff =
			new CFSecTSecGrpMembBuff();
		return( buff );
	}

	public CFSecTSecGrpMembHBuff newHBuff() {
		CFSecTSecGrpMembHBuff hbuff =
			new CFSecTSecGrpMembHBuff();
		return( hbuff );
	}
}
