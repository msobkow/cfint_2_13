
// Description: Java 11 Default Factory implementation for SubProject.

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
	 *	CFIntSubProjectFactory implementation for SubProject
	 */
public class CFIntSubProjectDefaultFactory
	implements ICFIntSubProjectFactory
{
	public CFIntSubProjectDefaultFactory() {
	}

	public CFIntSubProjectPKey newPKey() {
		CFIntSubProjectPKey pkey =
			new CFIntSubProjectPKey();
		return( pkey );
	}

	public CFIntSubProjectHPKey newHPKey() {
		CFIntSubProjectHPKey hpkey =
			new CFIntSubProjectHPKey();
		return( hpkey );
	}

	public CFIntSubProjectByTenantIdxKey newTenantIdxKey() {
		CFIntSubProjectByTenantIdxKey key =
			new CFIntSubProjectByTenantIdxKey();
		return( key );
	}

	public CFIntSubProjectByTopProjectIdxKey newTopProjectIdxKey() {
		CFIntSubProjectByTopProjectIdxKey key =
			new CFIntSubProjectByTopProjectIdxKey();
		return( key );
	}

	public CFIntSubProjectByNameIdxKey newNameIdxKey() {
		CFIntSubProjectByNameIdxKey key =
			new CFIntSubProjectByNameIdxKey();
		return( key );
	}

	public CFIntSubProjectBuff newBuff() {
		CFIntSubProjectBuff buff =
			new CFIntSubProjectBuff();
		return( buff );
	}

	public CFIntSubProjectHBuff newHBuff() {
		CFIntSubProjectHBuff hbuff =
			new CFIntSubProjectHBuff();
		return( hbuff );
	}
}