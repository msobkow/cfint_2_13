// Description: Java 13 Cust JavaFX Schema.

/*
 *	CF Int Cust JavaFX Implementation
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
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
 */

package org.msscf.msscf.cfintcust.CFIntCust;

import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.msscf.msscf.cfseccust.CFSecCust.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/**
 *	The CFIntCustSchema defines the interface object that is
 *	provided by the cust interface for manipulating the CFInt
 *	facet in the user interface.
 */
public class CFIntCustSchema
extends CFSecCustSchema
implements ICFIntCustSchema
{
	public CFIntCustSchema() {
		super();
	}

	public ICFIntSchemaObj getCFIntSchema() {
		return( (ICFIntSchemaObj)schema );
	}

	public CFIntCustFacetPane newIntFacetPane( ICFFormManager formManager ) {
		CFIntCustFacetPane pane = newIntFacetPane( formManager, this );
		return( pane );
	}

	public CFIntCustFacetPane newIntFacetPane( ICFFormManager formManager, ICFIntCustSchema argSchema ) {
		CFIntCustFacetPane pane = new CFIntCustFacetPane( formManager, argSchema );
		return( pane );
	}
}
