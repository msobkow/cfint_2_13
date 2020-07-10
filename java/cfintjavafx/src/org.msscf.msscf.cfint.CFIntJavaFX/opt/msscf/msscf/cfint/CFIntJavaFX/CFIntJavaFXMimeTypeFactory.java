// Description: Java 11 JavaFX Display Element Factory for MimeType.

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
 *	CFIntJavaFXMimeTypeFactory JavaFX Display Element Factory
 *	for MimeType.
 */
public class CFIntJavaFXMimeTypeFactory
implements ICFIntJavaFXMimeTypeFactory
{
	protected ICFIntJavaFXSchema javafxSchema = null;

	public CFIntJavaFXMimeTypeFactory( ICFIntJavaFXSchema argSchema ) {
		final String S_ProcName = "construct-schema";
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( this.getClass(),
				S_ProcName,
				1,
				"argSchema" );
		}
		javafxSchema = argSchema;
	}

	public CFGridPane newAttrPane( ICFFormManager formManager, ICFIntMimeTypeObj argFocus ) {
		CFIntJavaFXMimeTypeAttrPane retnew = new CFIntJavaFXMimeTypeAttrPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFLibAnyObj argContainer,
		ICFIntMimeTypeObj argFocus,
		Collection<ICFIntMimeTypeObj> argDataCollection,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain )
	{
		CFIntJavaFXMimeTypeListPane retnew = new CFIntJavaFXMimeTypeListPane( formManager,
			javafxSchema,
			argContainer,
			argFocus,
			argDataCollection,
			refreshCallback,
			sortByChain );
		return( retnew );
	}

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFIntMimeTypeObj argFocus,
		ICFLibAnyObj argContainer,
		Collection<ICFIntMimeTypeObj> argDataCollection,
		ICFIntJavaFXMimeTypeChosen whenChosen )
	{
		CFIntJavaFXMimeTypePickerPane retnew = new CFIntJavaFXMimeTypePickerPane( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFTabPane newEltTabPane( ICFFormManager formManager, ICFIntMimeTypeObj argFocus ) {
		CFIntJavaFXMimeTypeEltTabPane retnew = new CFIntJavaFXMimeTypeEltTabPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newAddPane( ICFFormManager formManager, ICFIntMimeTypeObj argFocus ) {
		CFIntJavaFXMimeTypeAddPane retnew = new CFIntJavaFXMimeTypeAddPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFSplitPane newViewEditPane( ICFFormManager formManager, ICFIntMimeTypeObj argFocus ) {
		CFIntJavaFXMimeTypeViewEditPane retnew = new CFIntJavaFXMimeTypeViewEditPane( formManager, javafxSchema, argFocus );
		return( retnew );
	}

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFIntMimeTypeObj argFocus, ICFDeleteCallback callback ) {
		CFIntJavaFXMimeTypeAskDeleteForm retnew = new CFIntJavaFXMimeTypeAskDeleteForm( formManager, javafxSchema, argFocus, callback );
		return( retnew );
	}

	public CFBorderPane newFinderForm( ICFFormManager formManager ) {
		CFIntJavaFXMimeTypeFinderForm retnew = new CFIntJavaFXMimeTypeFinderForm( formManager, javafxSchema );
		return( retnew );
	}

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFIntMimeTypeObj argFocus,
		ICFLibAnyObj argContainer,
		Collection<ICFIntMimeTypeObj> argDataCollection,
		ICFIntJavaFXMimeTypeChosen whenChosen )
	{
		CFIntJavaFXMimeTypePickerForm retnew = new CFIntJavaFXMimeTypePickerForm( formManager,
			javafxSchema,
			argFocus,
			argContainer,
			argDataCollection,
			whenChosen );
		return( retnew );
	}

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFIntMimeTypeObj argFocus, ICFFormClosedCallback closeCallback, boolean allowSave ) {
		CFIntJavaFXMimeTypeAddForm retnew = new CFIntJavaFXMimeTypeAddForm( formManager, javafxSchema, argFocus, closeCallback, allowSave );
		return( retnew );
	}

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFIntMimeTypeObj argFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd ) {
		CFIntJavaFXMimeTypeViewEditForm retnew = new CFIntJavaFXMimeTypeViewEditForm( formManager, javafxSchema, argFocus, closeCallback, cameFromAdd );
		return( retnew );
	}
}
