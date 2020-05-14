// Description: Java 11 JavaFX Element TabPane implementation for Tld.

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
import java.util.List;
import javafx.scene.Parent;
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
 *	CFIntJavaFXTldEltTabPane JavaFX Element TabPane implementation
 *	for Tld.
 */
public class CFIntJavaFXTldEltTabPane
extends CFTabPane
implements ICFIntJavaFXTldPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFIntJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	public final String LABEL_TabComponentsTopDomainList = "Optional Components Top Domain";
	protected CFTab tabComponentsTopDomain = null;
	protected CFBorderPane tabViewComponentsTopDomainListPane = null;

	public CFIntJavaFXTldEltTabPane( ICFFormManager formManager, ICFIntJavaFXSchema argSchema, ICFIntTldObj argFocus ) {
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
		setJavaFXFocusAsTld( argFocus );
		// Wire the newly constructed Panes/Tabs to this TabPane
		tabComponentsTopDomain = new CFTab();
		tabComponentsTopDomain.setText( LABEL_TabComponentsTopDomainList );
		tabComponentsTopDomain.setContent( getTabViewComponentsTopDomainListPane() );
		getTabs().add( tabComponentsTopDomain );
		javafxIsInitializing = false;
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

	public void setJavaFXFocus( ICFLibAnyObj value ) {
		final String S_ProcName = "setJavaFXFocus";
		if( ( value == null ) || ( value instanceof ICFIntTldObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFIntTldObj" );
		}
	}

	public void setJavaFXFocusAsTld( ICFIntTldObj value ) {
		setJavaFXFocus( value );
	}

	public ICFIntTldObj getJavaFXFocusAsTld() {
		return( (ICFIntTldObj)getJavaFXFocus() );
	}

	protected class RefreshComponentsTopDomainList
	implements ICFRefreshCallback
	{
		public RefreshComponentsTopDomainList() {
		}

		public void refreshMe() {
			Collection<ICFIntTopDomainObj> dataCollection;
			ICFIntTldObj focus = (ICFIntTldObj)getJavaFXFocusAsTld();
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsTopDomain( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			CFBorderPane pane = getTabViewComponentsTopDomainListPane();
			ICFIntJavaFXTopDomainPaneList jpList = (ICFIntJavaFXTopDomainPaneList)pane;
			jpList.setJavaFXDataCollection( dataCollection );
		}
	}

	public CFBorderPane getTabViewComponentsTopDomainListPane() {
		if( tabViewComponentsTopDomainListPane == null ) {
			ICFIntTldObj focus = (ICFIntTldObj)getJavaFXFocusAsTld();
			Collection<ICFIntTopDomainObj> dataCollection;
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsTopDomain( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			ICFIntTldObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFIntTldObj ) ) {
				javafxContainer = (ICFIntTldObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsTopDomainListPane = javafxSchema.getTopDomainFactory().newListPane( cfFormManager, javafxContainer, null, dataCollection, new RefreshComponentsTopDomainList(), false );
		}
		return( tabViewComponentsTopDomainListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewComponentsTopDomainListPane != null ) {
			((ICFIntJavaFXTopDomainPaneCommon)tabViewComponentsTopDomainListPane).setPaneMode( value );
		}
	}
}
