// Description: Java 11 JavaFX Element TabPane implementation for TopDomain.

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
import java.util.List;
import javafx.scene.Parent;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/**
 *	CFIntJavaFXTopDomainEltTabPane JavaFX Element TabPane implementation
 *	for TopDomain.
 */
public class CFIntJavaFXTopDomainEltTabPane
extends CFTabPane
implements ICFIntJavaFXTopDomainPaneCommon
{
	protected ICFFormManager cfFormManager = null;
	protected ICFIntJavaFXSchema javafxSchema = null;
	protected boolean javafxIsInitializing = true;
	public final String LABEL_TabComponentsLicenseList = "Optional Components License";
	protected CFTab tabComponentsLicense = null;
	public final String LABEL_TabComponentsTopProjectList = "Optional Components Top Project";
	protected CFTab tabComponentsTopProject = null;
	protected CFBorderPane tabViewComponentsLicenseListPane = null;
	protected CFBorderPane tabViewComponentsTopProjectListPane = null;

	public CFIntJavaFXTopDomainEltTabPane( ICFFormManager formManager, ICFIntJavaFXSchema argSchema, ICFIntTopDomainObj argFocus ) {
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
		setJavaFXFocusAsTopDomain( argFocus );
		// Wire the newly constructed Panes/Tabs to this TabPane
		tabComponentsLicense = new CFTab();
		tabComponentsLicense.setText( LABEL_TabComponentsLicenseList );
		tabComponentsLicense.setContent( getTabViewComponentsLicenseListPane() );
		getTabs().add( tabComponentsLicense );
		tabComponentsTopProject = new CFTab();
		tabComponentsTopProject.setText( LABEL_TabComponentsTopProjectList );
		tabComponentsTopProject.setContent( getTabViewComponentsTopProjectListPane() );
		getTabs().add( tabComponentsTopProject );
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
	}

	public void setJavaFXFocusAsTopDomain( ICFIntTopDomainObj value ) {
		setJavaFXFocus( value );
	}

	public ICFIntTopDomainObj getJavaFXFocusAsTopDomain() {
		return( (ICFIntTopDomainObj)getJavaFXFocus() );
	}

	protected class RefreshComponentsLicenseList
	implements ICFRefreshCallback
	{
		public RefreshComponentsLicenseList() {
		}

		public void refreshMe() {
			Collection<ICFIntLicenseObj> dataCollection;
			ICFIntTopDomainObj focus = (ICFIntTopDomainObj)getJavaFXFocusAsTopDomain();
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsLicense( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			CFBorderPane pane = getTabViewComponentsLicenseListPane();
			ICFIntJavaFXLicensePaneList jpList = (ICFIntJavaFXLicensePaneList)pane;
			jpList.setJavaFXDataCollection( dataCollection );
		}
	}

	public CFBorderPane getTabViewComponentsLicenseListPane() {
		if( tabViewComponentsLicenseListPane == null ) {
			ICFIntTopDomainObj focus = (ICFIntTopDomainObj)getJavaFXFocusAsTopDomain();
			Collection<ICFIntLicenseObj> dataCollection;
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsLicense( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			ICFIntTopDomainObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFIntTopDomainObj ) ) {
				javafxContainer = (ICFIntTopDomainObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsLicenseListPane = javafxSchema.getLicenseFactory().newListPane( cfFormManager, javafxContainer, null, dataCollection, new RefreshComponentsLicenseList(), false );
		}
		return( tabViewComponentsLicenseListPane );
	}

	protected class RefreshComponentsTopProjectList
	implements ICFRefreshCallback
	{
		public RefreshComponentsTopProjectList() {
		}

		public void refreshMe() {
			Collection<ICFIntTopProjectObj> dataCollection;
			ICFIntTopDomainObj focus = (ICFIntTopDomainObj)getJavaFXFocusAsTopDomain();
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsTopProject( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			CFBorderPane pane = getTabViewComponentsTopProjectListPane();
			ICFIntJavaFXTopProjectPaneList jpList = (ICFIntJavaFXTopProjectPaneList)pane;
			jpList.setJavaFXDataCollection( dataCollection );
		}
	}

	public CFBorderPane getTabViewComponentsTopProjectListPane() {
		if( tabViewComponentsTopProjectListPane == null ) {
			ICFIntTopDomainObj focus = (ICFIntTopDomainObj)getJavaFXFocusAsTopDomain();
			Collection<ICFIntTopProjectObj> dataCollection;
			if( focus != null ) {
				dataCollection = focus.getOptionalComponentsTopProject( javafxIsInitializing );
			}
			else {
				dataCollection = null;
			}
			ICFIntTopDomainObj javafxContainer;
			if( ( focus != null ) && ( focus instanceof ICFIntTopDomainObj ) ) {
				javafxContainer = (ICFIntTopDomainObj)focus;
			}
			else {
				javafxContainer = null;
			}
			tabViewComponentsTopProjectListPane = javafxSchema.getTopProjectFactory().newListPane( cfFormManager, javafxContainer, null, dataCollection, new RefreshComponentsTopProjectList(), false );
		}
		return( tabViewComponentsTopProjectListPane );
	}

	public void setPaneMode( CFPane.PaneMode value ) {
		CFPane.PaneMode oldMode = getPaneMode();
		super.setPaneMode( value );
		if( tabViewComponentsLicenseListPane != null ) {
			((ICFIntJavaFXLicensePaneCommon)tabViewComponentsLicenseListPane).setPaneMode( value );
		}
		if( tabViewComponentsTopProjectListPane != null ) {
			((ICFIntJavaFXTopProjectPaneCommon)tabViewComponentsTopProjectListPane).setPaneMode( value );
		}
	}
}