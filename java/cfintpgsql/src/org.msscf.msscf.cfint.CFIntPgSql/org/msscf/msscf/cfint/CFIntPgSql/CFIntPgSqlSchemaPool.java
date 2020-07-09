// Description: Java 11 implementation of a PostgreSQL CFInt schema pool.

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

package org.msscf.msscf.cfint.CFIntPgSql;

import java.util.*;

import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;

public class CFIntPgSqlSchemaPool
extends CFIntSchemaPool
{
	public CFIntPgSqlSchemaPool() {
		setJndiName( "java:comp/env/CFINet213ConnectionPool" );
	}

	/**
	 *	You need to overload the implementation of newInstance() to return
	 *	connected instances of your backing store.
	 */
	public ICFIntSchema newInstance() {
		ICFIntSchema inst = new CFIntPgSqlSchema();
		return( inst );
	}
}
