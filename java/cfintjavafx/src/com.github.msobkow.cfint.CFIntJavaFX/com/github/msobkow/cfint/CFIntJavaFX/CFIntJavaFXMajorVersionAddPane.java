// Description: Java 11 JavaFX Add Pane implementation for MajorVersion.

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
import javafx.geometry.Orientation;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfint.CFInt.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFIntObj.*;

/**
 *	CFIntJavaFXMajorVersionAddPane JavaFX Add Pane implementation
 *	for MajorVersion.
 */
public class CFIntJavaFXMajorVersionAddPane
extends CFSplitPane
implements ICFIntJavaFXMajorVersionPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFIntJavaFXSchema javafxSchema = null;
	protected ScrollPane attrScrollPane = null;
	protected CFGridPane attrPane = null;

	public CFIntJavaFXMajorVersionAddPane( ICFFormManager formManager, ICFIntJavaFXSchema argSchema, ICFIntMajorVersionObj argFocus ) {
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
		// argFocus is optional; focus may be set later during execution as
		// conditions of the runtime change.
		javafxSchema = argSchema;
		setJavaFXFocus( argFocus );
		attrPane = argSchema.getMajorVersionFactory().newAttrPane( cfFormManager, argFocus );
		attrScrollPane = new ScrollPane( attrPane );
		attrScrollPane.setFitToWidth( true );
		attrScrollPane.setHbarPolicy( ScrollBarPolicy.NEVER );
		attrScrollPane.setVbarPolicy( ScrollBarPolicy.AS_NEEDED );
		attrScrollPane.setContent( attrPane );
		setOrientation( Orientation.VERTICAL );
		getItems().add( attrScrollPane );
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

	public ICFIntJavaFXSchema getJavaFXSchema() {
		return( javafxSchema );
	}

	public ICFLibAnyObj getJavaFXFocus() {
		ICFLibAnyObj obj;
		if( attrPane != null ) {
			obj = attrPane.getJavaFXFocus();
		}
		else {
			obj = null;
		}
		return( obj );
	}

	public void setJavaFXFocus( ICFLibAnyObj value ) {
		final String S_ProcName = "setJavaFXFocus";
		if( ( value == null ) || ( value instanceof ICFIntMajorVersionObj ) ) {
			super.setJavaFXFocus( value );
			if( ( attrPane != null ) && ( attrPane.getJavaFXFocus() != value ) ) {
				attrPane.setJavaFXFocus( value );
			}
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFIntMajorVersionObj" );
		}
	}

	public void setJavaFXFocusAsMajorVersion( ICFIntMajorVersionObj value ) {
		setJavaFXFocus( value );
	}

	public ICFIntMajorVersionObj getJavaFXFocusAsMajorVersion() {
		return( (ICFIntMajorVersionObj)getJavaFXFocus() );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldValue = getPaneMode();
		if( value == oldValue ) {
			return;
		}
		try {
			super.setPaneMode( value );
			((ICFIntJavaFXMajorVersionPaneCommon)attrPane).setPaneMode( value );
		}
		catch( Throwable t ) {
			super.setPaneMode( oldValue );
			((ICFIntJavaFXMajorVersionPaneCommon)attrPane).setPaneMode( oldValue );
			throw t;
		}
	}
}
