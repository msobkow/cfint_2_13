
// Description: Java 11 Default Factory implementation for URLProtocol.

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
	 *	CFIntURLProtocolFactory implementation for URLProtocol
	 */
public class CFIntURLProtocolDefaultFactory
	implements ICFIntURLProtocolFactory
{
	public CFIntURLProtocolDefaultFactory() {
	}

	public CFIntURLProtocolPKey newPKey() {
		CFIntURLProtocolPKey pkey =
			new CFIntURLProtocolPKey();
		return( pkey );
	}

	public CFIntURLProtocolHPKey newHPKey() {
		CFIntURLProtocolHPKey hpkey =
			new CFIntURLProtocolHPKey();
		return( hpkey );
	}

	public CFIntURLProtocolByUNameIdxKey newUNameIdxKey() {
		CFIntURLProtocolByUNameIdxKey key =
			new CFIntURLProtocolByUNameIdxKey();
		return( key );
	}

	public CFIntURLProtocolByIsSecureIdxKey newIsSecureIdxKey() {
		CFIntURLProtocolByIsSecureIdxKey key =
			new CFIntURLProtocolByIsSecureIdxKey();
		return( key );
	}

	public CFIntURLProtocolBuff newBuff() {
		CFIntURLProtocolBuff buff =
			new CFIntURLProtocolBuff();
		return( buff );
	}

	public CFIntURLProtocolHBuff newHBuff() {
		CFIntURLProtocolHBuff hbuff =
			new CFIntURLProtocolHBuff();
		return( hbuff );
	}
}