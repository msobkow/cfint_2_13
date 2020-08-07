
// Description: Java 11 Default Factory implementation for TSecGrpMemb.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
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

package org.msscf.msscf.cfint.CFInt;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

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
