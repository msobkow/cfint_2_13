
// Description: Java 11 Default Factory implementation for HostNode.

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
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;

	/*
	 *	CFIntHostNodeFactory implementation for HostNode
	 */
public class CFIntHostNodeDefaultFactory
	extends CFSecHostNodeDefaultFactory
	implements ICFIntHostNodeFactory
{
	public CFIntHostNodeDefaultFactory() {
		super();
	}

	public CFSecHostNodePKey newPKey() {
		CFSecHostNodePKey pkey =
			new CFSecHostNodePKey();
		return( pkey );
	}

	public CFSecHostNodeHPKey newHPKey() {
		CFSecHostNodeHPKey hpkey =
			new CFSecHostNodeHPKey();
		return( hpkey );
	}

	public CFSecHostNodeByClusterIdxKey newClusterIdxKey() {
		CFSecHostNodeByClusterIdxKey key =
			new CFSecHostNodeByClusterIdxKey();
		return( key );
	}

	public CFSecHostNodeByUDescrIdxKey newUDescrIdxKey() {
		CFSecHostNodeByUDescrIdxKey key =
			new CFSecHostNodeByUDescrIdxKey();
		return( key );
	}

	public CFSecHostNodeByHostNameIdxKey newHostNameIdxKey() {
		CFSecHostNodeByHostNameIdxKey key =
			new CFSecHostNodeByHostNameIdxKey();
		return( key );
	}

	public CFSecHostNodeBuff newBuff() {
		CFSecHostNodeBuff buff =
			new CFSecHostNodeBuff();
		return( buff );
	}

	public CFSecHostNodeHBuff newHBuff() {
		CFSecHostNodeHBuff hbuff =
			new CFSecHostNodeHBuff();
		return( hbuff );
	}
}
