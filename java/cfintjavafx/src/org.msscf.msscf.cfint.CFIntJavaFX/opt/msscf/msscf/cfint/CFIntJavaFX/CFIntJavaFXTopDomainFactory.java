// Description: Java 11 JavaFX Display Element Factory for TopDomain.

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

package com.github.msobkow.cfint.CFIntJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfint.CFInt.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFIntObj.*;

/**
 *	CFIntJavaFXTopDomainFactory JavaFX Display Element Factory
 *	for TopDomain.
 */
public class CFIntJavaFXTopDomainFactory
implements ICFIntJavaFXTopDomainFactory
{
	protected ICFIntJavaFXSchema javafxSchema = null;

	public CFIntJavaFXTopDomainFactory( ICFIntJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFIntTopDomainObj argFocus ) {
		CFIntJavaFXTopDomainAttrPane retnew = new CFIntJavaFXTopDomainAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFIntTldObj argContainer,
		ICFIntTopDomainObj argFocus,
		Collection<ICFIntTopDomainObj> argDataCollection,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFIntJavaFXTopDomainListPane retnew = new CFIntJavaFXTopDomainListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argDataCollection,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFIntTopDomainObj argFocus,
		ICFIntTldObj argContainer,
		Collection<ICFIntTopDomainObj> argDataCollection,
		ICFIntJavaFXTopDomainChosen whenChosen )
	{
		CFIntJavaFXTopDomainPickerPane retnew = new CFIntJavaFXTopDomainPickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFIntTopDomainObj argFocus ) {
		CFIntJavaFXTopDomainEltTabPane retnew = new CFIntJavaFXTopDomainEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFIntTopDomainObj argFocus ) {
		CFIntJavaFXTopDomainAddPane retnew = new CFIntJavaFXTopDomainAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFIntTopDomainObj argFocus ) {
		CFIntJavaFXTopDomainViewEditPane retnew = new CFIntJavaFXTopDomainViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFIntTopDomainObj argFocus, ICFDeleteCallback callback ) {
		CFIntJavaFXTopDomainAskDeleteForm retnew = new CFIntJavaFXTopDomainAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFIntTopDomainObj argFocus,
		ICFIntTldObj argContainer,
		Collection<ICFIntTopDomainObj> argDataCollection,
		ICFIntJavaFXTopDomainChosen whenChosen )
	{
		CFIntJavaFXTopDomainPickerForm retnew = new CFIntJavaFXTopDomainPickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFIntTopDomainObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFIntJavaFXTopDomainAddForm retnew = new CFIntJavaFXTopDomainAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFIntTopDomainObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFIntJavaFXTopDomainViewEditForm retnew = new CFIntJavaFXTopDomainViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
