// Description: Java 11 JavaFX Picker Form implementation for TopDomain.

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

package org.msscf.msscf.cfint.CFIntJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/**
 *	CFIntJavaFXTopDomainPickerForm JavaFX Picker Form implementation
 *	for TopDomain.
 */
public class CFIntJavaFXTopDomainPickerForm
extends CFBorderPane
implements ICFIntJavaFXTopDomainPaneList,
	ICFForm
{
	protected ICFFormManager cfFormManager = null;
	protected CFBorderPane javafxPickerPane = null;
	protected ICFIntJavaFXSchema javafxSchema = null;
	protected Collection<ICFIntTopDomainObj> javafxDataCollection = null;

	public CFIntJavaFXTopDomainPickerForm( ICFFormManager formManager,
		ICFIntJavaFXSchema argSchema,
		ICFIntTopDomainObj argFocus,
		ICFIntTldObj argContainer,
		Collection<ICFIntTopDomainObj> argDataCollection,
		ICFIntJavaFXTopDomainChosen whenChosen )
	{
		super();
		final String S_ProcName = "construct-schema-focus";
		if( formManager == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"formManager" );
		}
		cfFormManager = formManager;
		if( argSchema == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				2,
				"argSchema" );
		}
		if( whenChosen == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				6,
				"whenChosen" );
		}
		// argFocus is optional; focus may be set later during execution as
		// conditions of the runtime change.
		javafxSchema = argSchema;
		javafxPickerPane = argSchema.getTopDomainFactory().newPickerPane( cfFormManager, argFocus, argContainer, argDataCollection, whenChosen );
		setJavaFXFocusAsTopDomain( argFocus );
		setJavaFXDataCollection( argDataCollection );
		setJavaFXContainer( argContainer );
		setCenter( javafxPickerPane );
		setPaneMode( CFPane.PaneMode.View );
	}

	public ICFFormManager getCFFormManager() {
		return( cfFormManager );
	}

	public void setCFFormManager( ICFFormManager value ) {
		final String S_ProcName = "setCFFormManager";
		if( value == null ) {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				1,
				"value" );
		}
		cfFormManager = value;
	}

	public void forceCancelAndClose() {
		if( cfFormManager != null ) {
			if( cfFormManager.getCurrentForm() == this ) {
				cfFormManager.closeCurrentForm();
			}
		}
	}

	public ICFIntJavaFXSchema getJavaFXSchema() {
		return( javafxSchema );
	}

	public void setJavaFXFocus( ICFLibAnyObj value ) {
		final String S_ProcName = "setJavaFXFocus";
		if( ( value == null ) || ( value instanceof ICFIntTopDomainObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFIntTopDomainObj" );
		}
		((ICFIntJavaFXTopDomainPaneCommon)javafxPickerPane).setJavaFXFocus( (ICFIntTopDomainObj)value );
	}

	public ICFIntTopDomainObj getJavaFXFocusAsTopDomain() {
		return( (ICFIntTopDomainObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsTopDomain( ICFIntTopDomainObj value ) {
		setJavaFXFocus( value );
	}

	public Collection<ICFIntTopDomainObj> getJavaFXDataCollection() {
		ICFIntJavaFXTopDomainPaneList jplPicker = (ICFIntJavaFXTopDomainPaneList)javafxPickerPane;
		Collection<ICFIntTopDomainObj> cltn = jplPicker.getJavaFXDataCollection();
		return( cltn );
	}

	public void setJavaFXDataCollection( Collection<ICFIntTopDomainObj> value ) {
		ICFIntJavaFXTopDomainPaneList jplPicker = (ICFIntJavaFXTopDomainPaneList)javafxPickerPane;
		jplPicker.setJavaFXDataCollection( value );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		final String S_ProcName = "setPaneMode";
		CFPane.PaneMode oldValue = getPaneMode();
		if( oldValue == value ) {
			return;
		}
		if( value != CFPane.PaneMode.View ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"PickerForms only support PaneMode View" );
		}
		super.setPaneMode( value );
		if( javafxPickerPane != null ) {
			ICFIntJavaFXTopDomainPaneCommon jpanelCommon = (ICFIntJavaFXTopDomainPaneCommon)javafxPickerPane;
			jpanelCommon.setPaneMode( value );
		}
	}

	public ICFIntTldObj getJavaFXContainer() {
		ICFIntJavaFXTopDomainPaneList jplPicker = (ICFIntJavaFXTopDomainPaneList)javafxPickerPane;
		ICFIntTldObj cnt = jplPicker.getJavaFXContainer();
		return( cnt );
	}

	public void setJavaFXContainer( ICFIntTldObj value ) {
		ICFIntJavaFXTopDomainPaneList jplPicker = (ICFIntJavaFXTopDomainPaneList)javafxPickerPane;
		jplPicker.setJavaFXContainer( value );
	}
}