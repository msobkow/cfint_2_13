
// Description: Java 11 Default Factory implementation for ISOCtryCcy.

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
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

	/*
	 *	CFIntISOCtryCcyFactory implementation for ISOCtryCcy
	 */
public class CFIntISOCtryCcyDefaultFactory
	extends CFSecISOCtryCcyDefaultFactory
	implements ICFIntISOCtryCcyFactory
{
	public CFIntISOCtryCcyDefaultFactory() {
		super();
	}

	public CFSecISOCtryCcyPKey newPKey() {
		CFSecISOCtryCcyPKey pkey =
			new CFSecISOCtryCcyPKey();
		return( pkey );
	}

	public CFSecISOCtryCcyHPKey newHPKey() {
		CFSecISOCtryCcyHPKey hpkey =
			new CFSecISOCtryCcyHPKey();
		return( hpkey );
	}

	public CFSecISOCtryCcyByCtryIdxKey newCtryIdxKey() {
		CFSecISOCtryCcyByCtryIdxKey key =
			new CFSecISOCtryCcyByCtryIdxKey();
		return( key );
	}

	public CFSecISOCtryCcyByCcyIdxKey newCcyIdxKey() {
		CFSecISOCtryCcyByCcyIdxKey key =
			new CFSecISOCtryCcyByCcyIdxKey();
		return( key );
	}

	public CFSecISOCtryCcyBuff newBuff() {
		CFSecISOCtryCcyBuff buff =
			new CFSecISOCtryCcyBuff();
		return( buff );
	}

	public CFSecISOCtryCcyHBuff newHBuff() {
		CFSecISOCtryCcyHBuff hbuff =
			new CFSecISOCtryCcyHBuff();
		return( hbuff );
	}
}
