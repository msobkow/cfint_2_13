
// Description: Java 11 Default Factory implementation for SecGroupForm.

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
	 *	CFIntSecGroupFormFactory implementation for SecGroupForm
	 */
public class CFIntSecGroupFormDefaultFactory
	extends CFSecSecGroupFormDefaultFactory
	implements ICFIntSecGroupFormFactory
{
	public CFIntSecGroupFormDefaultFactory() {
		super();
	}

	public CFSecSecGroupFormPKey newPKey() {
		CFSecSecGroupFormPKey pkey =
			new CFSecSecGroupFormPKey();
		return( pkey );
	}

	public CFSecSecGroupFormHPKey newHPKey() {
		CFSecSecGroupFormHPKey hpkey =
			new CFSecSecGroupFormHPKey();
		return( hpkey );
	}

	public CFSecSecGroupFormByClusterIdxKey newClusterIdxKey() {
		CFSecSecGroupFormByClusterIdxKey key =
			new CFSecSecGroupFormByClusterIdxKey();
		return( key );
	}

	public CFSecSecGroupFormByGroupIdxKey newGroupIdxKey() {
		CFSecSecGroupFormByGroupIdxKey key =
			new CFSecSecGroupFormByGroupIdxKey();
		return( key );
	}

	public CFSecSecGroupFormByAppIdxKey newAppIdxKey() {
		CFSecSecGroupFormByAppIdxKey key =
			new CFSecSecGroupFormByAppIdxKey();
		return( key );
	}

	public CFSecSecGroupFormByFormIdxKey newFormIdxKey() {
		CFSecSecGroupFormByFormIdxKey key =
			new CFSecSecGroupFormByFormIdxKey();
		return( key );
	}

	public CFSecSecGroupFormByUFormIdxKey newUFormIdxKey() {
		CFSecSecGroupFormByUFormIdxKey key =
			new CFSecSecGroupFormByUFormIdxKey();
		return( key );
	}

	public CFSecSecGroupFormBuff newBuff() {
		CFSecSecGroupFormBuff buff =
			new CFSecSecGroupFormBuff();
		return( buff );
	}

	public CFSecSecGroupFormHBuff newHBuff() {
		CFSecSecGroupFormHBuff hbuff =
			new CFSecSecGroupFormHBuff();
		return( hbuff );
	}
}
