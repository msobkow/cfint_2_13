// Description: Java 11 Schema Pooled Object implementation for CFInt.

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

package org.msscf.msscf.cfint.CFIntObj;

import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFInt.*;

/**
 *	A pooled schema object does not disconnect the backing
 *	store when a logout is performed, because the backing store
 *	comes from a connection pool that is reused across requests,
 *	rather than being owned by the SchemaPooledObj.
 */
public class CFIntSchemaPooledObj
	extends CFIntSchemaObj
{
	public CFIntSchemaPooledObj() {
		super();
	}

	public boolean isConnected() {
		if( backingStore == null ) {
			return( false );
		}
		else {
			return( true );
		}
	}

	public void disconnect( boolean doCommit ) {
		final String S_ProcName = "disconnect";
		throw new CFLibUsageException( getClass(),
			S_ProcName,
			"Schema objects over pooled storage cannot be explicitly disconnected" );
	}

	public void logout() {
		if( ( authorization == null ) || ( backingStore == null ) ) {
			return;
		}
		try {
			boolean transactionStarted = beginTransaction();
			if( ! transactionStarted ) {
				rollback();
				transactionStarted = beginTransaction();
				if( ! transactionStarted ) {
					setAuthorization( null );
					return;
				}
			}
			UUID secSessionId = authorization.getSecSessionId();
			if( secSessionId != null ) {
				ICFSecSecSessionObj secSession = getSecSessionTableObj().readSecSessionByIdIdx( secSessionId );
				if( secSession != null ) {
					if( secSession.getOptionalFinish() == null ) {
						ICFSecSecSessionEditObj editSecSession = secSession.beginEdit();
						editSecSession.setOptionalFinish( Calendar.getInstance() );
						editSecSession.update();
						editSecSession = null;
					}
				}
			}
			commit();
		}
		finally {
			setAuthorization( null );
			minimizeMemory();
		}
	}
}
