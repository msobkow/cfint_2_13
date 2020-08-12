// Description: Java 11 JavaFX Display Element Factory for URLProtocol.

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

package org.msscf.msscf.cfint.v2_13.cfint.CFIntJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cflib.v2_13.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/**
 *	CFIntJavaFXURLProtocolFactory JavaFX Display Element Factory
 *	for URLProtocol.
 */
public class CFIntJavaFXURLProtocolFactory
implements ICFIntJavaFXURLProtocolFactory
{
	protected ICFIntJavaFXSchema javafxSchema = null;

	public CFIntJavaFXURLProtocolFactory( ICFIntJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFIntURLProtocolObj argFocus ) {
		CFIntJavaFXURLProtocolAttrPane retnew = new CFIntJavaFXURLProtocolAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFLibAnyObj argContainer,
		ICFIntURLProtocolObj argFocus,
		Collection<ICFIntURLProtocolObj> argDataCollection,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFIntJavaFXURLProtocolListPane retnew = new CFIntJavaFXURLProtocolListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argDataCollection,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFIntURLProtocolObj argFocus,
		ICFLibAnyObj argContainer,
		Collection<ICFIntURLProtocolObj> argDataCollection,
		ICFIntJavaFXURLProtocolChosen whenChosen )
	{
		CFIntJavaFXURLProtocolPickerPane retnew = new CFIntJavaFXURLProtocolPickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFIntURLProtocolObj argFocus ) {
		CFIntJavaFXURLProtocolEltTabPane retnew = new CFIntJavaFXURLProtocolEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFIntURLProtocolObj argFocus ) {
		CFIntJavaFXURLProtocolAddPane retnew = new CFIntJavaFXURLProtocolAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFIntURLProtocolObj argFocus ) {
		CFIntJavaFXURLProtocolViewEditPane retnew = new CFIntJavaFXURLProtocolViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFIntURLProtocolObj argFocus, ICFDeleteCallback callback ) {
		CFIntJavaFXURLProtocolAskDeleteForm retnew = new CFIntJavaFXURLProtocolAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newFinderForm( ICFFormManager formManager ) {
		CFIntJavaFXURLProtocolFinderForm retnew = new CFIntJavaFXURLProtocolFinderForm( formManager, javafxSchema );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFIntURLProtocolObj argFocus,
		ICFLibAnyObj argContainer,
		Collection<ICFIntURLProtocolObj> argDataCollection,
		ICFIntJavaFXURLProtocolChosen whenChosen )
	{
		CFIntJavaFXURLProtocolPickerForm retnew = new CFIntJavaFXURLProtocolPickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFIntURLProtocolObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFIntJavaFXURLProtocolAddForm retnew = new CFIntJavaFXURLProtocolAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFIntURLProtocolObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFIntJavaFXURLProtocolViewEditForm retnew = new CFIntJavaFXURLProtocolViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
