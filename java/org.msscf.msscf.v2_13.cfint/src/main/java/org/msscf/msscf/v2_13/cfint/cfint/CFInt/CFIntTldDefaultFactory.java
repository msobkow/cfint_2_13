
// Description: Java 11 Default Factory implementation for Tld.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

package org.msscf.msscf.v2_13.cfint.cfint.CFInt;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

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
