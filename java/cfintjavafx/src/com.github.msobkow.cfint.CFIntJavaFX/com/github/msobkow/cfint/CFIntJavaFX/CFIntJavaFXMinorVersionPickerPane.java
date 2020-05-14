// Description: Java 11 JavaFX Picker of Obj Pane implementation for MinorVersion.

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
import javafx.beans.property.ReadOnlyObjectWrapper;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Parent;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import javafx.scene.control.TableCell;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableColumn.CellDataFeatures;
import javafx.scene.control.TableView;
import javafx.util.Callback;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfint.CFInt.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFIntObj.*;
import com.github.msobkow.cfsec.CFSecJavaFX.*;

/**
 *	CFIntJavaFXMinorVersionPickerPane JavaFX Pick Obj Pane implementation
 *	for MinorVersion.
 */
public class CFIntJavaFXMinorVersionPickerPane
extends CFBorderPane
implements ICFIntJavaFXMinorVersionPaneList
{
	public static String S_FormName = "Choose MinorVersion";
	protected ICFIntJavaFXSchema javafxSchema = null;
	protected Collection<ICFIntMinorVersionObj> javafxDataCollection = null;
	protected ObservableList<ICFIntMinorVersionObj> observableListOfMinorVersion = null;
	protected TableColumn<ICFIntMinorVersionObj, Long> tableColumnId = null;
	protected TableColumn<ICFIntMinorVersionObj, String> tableColumnName = null;
	protected TableColumn<ICFIntMinorVersionObj, String> tableColumnDescription = null;
	protected TableView<ICFIntMinorVersionObj> dataTable = null;
	protected CFHBox hboxMenu = null;
	public final String S_ColumnNames[] = { "Name" };
	protected ICFFormManager cfFormManager = null;
	protected ICFIntJavaFXMinorVersionChosen invokeWhenChosen = null;
	protected ICFIntMajorVersionObj javafxContainer = null;
	protected CFButton buttonCancel = null;
	protected CFButton buttonChooseNone = null;
	protected CFButton buttonChooseSelected = null;
	protected ScrollPane scrollMenu = null;
	public CFIntJavaFXMinorVersionPickerPane( ICFFormManager formManager,
		ICFIntJavaFXSchema argSchema,
		ICFIntMinorVersionObj argFocus,
		ICFIntMajorVersionObj argContainer,
		Collection<ICFIntMinorVersionObj> argDataCollection,
		ICFIntJavaFXMinorVersionChosen whenChosen )
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
		invokeWhenChosen = whenChosen;
		// argFocus is optional; focus may be set later during execution as
		// conditions of the runtime change.
		javafxSchema = argSchema;
		javaFXFocus = argFocus;
		javafxContainer = argContainer;
		setJavaFXDataCollection( argDataCollection );
		dataTable = new TableView<ICFIntMinorVersionObj>();
		tableColumnId = new TableColumn<ICFIntMinorVersionObj,Long>( "Id" );
		tableColumnId.setCellValueFactory( new Callback<CellDataFeatures<ICFIntMinorVersionObj,Long>,ObservableValue<Long> >() {
			public ObservableValue<Long> call( CellDataFeatures<ICFIntMinorVersionObj, Long> p ) {
				ICFIntMinorVersionObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					long value = obj.getRequiredId();
					Long wrapped = Long.valueOf( value );
					ReadOnlyObjectWrapper<Long> observable = new ReadOnlyObjectWrapper<Long>();
					observable.setValue( wrapped );
					return( observable );
				}
			}
		});
		tableColumnId.setCellFactory( new Callback<TableColumn<ICFIntMinorVersionObj,Long>,TableCell<ICFIntMinorVersionObj,Long>>() {
			@Override public TableCell<ICFIntMinorVersionObj,Long> call(
				TableColumn<ICFIntMinorVersionObj,Long> arg)
			{
				return new CFInt64TableCell<ICFIntMinorVersionObj>();
			}
		});
		dataTable.getColumns().add( tableColumnId );
		tableColumnName = new TableColumn<ICFIntMinorVersionObj,String>( "Name" );
		tableColumnName.setCellValueFactory( new Callback<CellDataFeatures<ICFIntMinorVersionObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFIntMinorVersionObj, String> p ) {
				ICFIntMinorVersionObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getRequiredName();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnName.setCellFactory( new Callback<TableColumn<ICFIntMinorVersionObj,String>,TableCell<ICFIntMinorVersionObj,String>>() {
			@Override public TableCell<ICFIntMinorVersionObj,String> call(
				TableColumn<ICFIntMinorVersionObj,String> arg)
			{
				return new CFStringTableCell<ICFIntMinorVersionObj>();
			}
		});
		dataTable.getColumns().add( tableColumnName );
		tableColumnDescription = new TableColumn<ICFIntMinorVersionObj,String>( "Description" );
		tableColumnDescription.setCellValueFactory( new Callback<CellDataFeatures<ICFIntMinorVersionObj,String>,ObservableValue<String> >() {
			public ObservableValue<String> call( CellDataFeatures<ICFIntMinorVersionObj, String> p ) {
				ICFIntMinorVersionObj obj = p.getValue();
				if( obj == null ) {
					return( null );
				}
				else {
					String value = obj.getOptionalDescription();
					ReadOnlyObjectWrapper<String> observable = new ReadOnlyObjectWrapper<String>();
					observable.setValue( value );
					return( observable );
				}
			}
		});
		tableColumnDescription.setCellFactory( new Callback<TableColumn<ICFIntMinorVersionObj,String>,TableCell<ICFIntMinorVersionObj,String>>() {
			@Override public TableCell<ICFIntMinorVersionObj,String> call(
				TableColumn<ICFIntMinorVersionObj,String> arg)
			{
				return new CFStringTableCell<ICFIntMinorVersionObj>();
			}
		});
		dataTable.getColumns().add( tableColumnDescription );
		dataTable.getSelectionModel().selectedItemProperty().addListener(
			new ChangeListener<ICFIntMinorVersionObj>() {
				@Override public void changed( ObservableValue<? extends ICFIntMinorVersionObj> observable,
					ICFIntMinorVersionObj oldValue,
					ICFIntMinorVersionObj newValue )
				{
					setJavaFXFocus( newValue );
					if( buttonChooseSelected != null ) {
						if( newValue != null ) {
							buttonChooseSelected.setDisable( false );
						}
						else {
							buttonChooseSelected.setDisable( true );
						}
					}
				}
			});
		hboxMenu = new CFHBox( 10 );
		buttonCancel = new CFButton();
		buttonCancel.setMinWidth( 200 );
		buttonCancel.setText( "Cancel" );
		buttonCancel.setOnAction( new EventHandler<ActionEvent>() {
			@Override public void handle( ActionEvent e ) {
				final String S_ProcName = "handle";
				try {
					cfFormManager.closeCurrentForm();
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});
		hboxMenu.getChildren().add( buttonCancel );
		buttonChooseNone = new CFButton();
		buttonChooseNone.setMinWidth( 200 );
		buttonChooseNone.setText( "ChooseNone" );
		buttonChooseNone.setOnAction( new EventHandler<ActionEvent>() {
			@Override public void handle( ActionEvent e ) {
				final String S_ProcName = "handle";
				try {
					ICFIntSchemaObj schemaObj = (ICFIntSchemaObj)javafxSchema.getSchema();
					if( schemaObj == null ) {
						throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"schemaObj" );
					}
					invokeWhenChosen.choseMinorVersion( null );
					cfFormManager.closeCurrentForm();
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});
		hboxMenu.getChildren().add( buttonChooseNone );
		buttonChooseSelected = new CFButton();
		buttonChooseSelected.setMinWidth( 200 );
		buttonChooseSelected.setText( "ChooseSelected" );
		buttonChooseSelected.setOnAction( new EventHandler<ActionEvent>() {
			@Override public void handle( ActionEvent e ) {
				final String S_ProcName = "handle";
				try {
					ICFIntSchemaObj schemaObj = (ICFIntSchemaObj)javafxSchema.getSchema();
					if( schemaObj == null ) {
						throw new CFLibNullArgumentException( getClass(),
							S_ProcName,
							0,
							"schemaObj" );
					}
					ICFIntMinorVersionObj selectedInstance = getJavaFXFocusAsMinorVersion();
					invokeWhenChosen.choseMinorVersion( selectedInstance );
					cfFormManager.closeCurrentForm();
				}
				catch( Throwable t ) {
					CFConsole.formException( S_FormName, ((CFButton)e.getSource()).getText(), t );
				}
			}
		});
		hboxMenu.getChildren().add( buttonChooseSelected );
		if( argFocus != null ) {
			dataTable.getSelectionModel().select( argFocus );
		}

		scrollMenu = new ScrollPane();
		scrollMenu.setVbarPolicy( ScrollBarPolicy.NEVER );
		scrollMenu.setHbarPolicy( ScrollBarPolicy.AS_NEEDED );
		scrollMenu.setFitToHeight( true );
		scrollMenu.setContent( hboxMenu );

		setTop( scrollMenu );
		setCenter( dataTable );
		adjustListButtons();
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
		if( ( value == null ) || ( value instanceof ICFIntMinorVersionObj ) ) {
			super.setJavaFXFocus( value );
		}
		else {
			throw new CFLibUnsupportedClassException( getClass(),
				S_ProcName,
				"value",
				value,
				"ICFIntMinorVersionObj" );
		}
		if( dataTable == null ) {
			return;
		}
	}

	public ICFIntMinorVersionObj getJavaFXFocusAsMinorVersion() {
		return( (ICFIntMinorVersionObj)getJavaFXFocus() );
	}

	public void setJavaFXFocusAsMinorVersion( ICFIntMinorVersionObj value ) {
		setJavaFXFocus( value );
	}

	public class MinorVersionByQualNameComparator
	implements Comparator<ICFIntMinorVersionObj>
	{
		public MinorVersionByQualNameComparator() {
		}

		public int compare( ICFIntMinorVersionObj lhs, ICFIntMinorVersionObj rhs ) {
			if( lhs == null ) {
				if( rhs == null ) {
					return( 0 );
				}
				else {
					return( -1 );
				}
			}
			else if( rhs == null ) {
				return( 1 );
			}
			else {
				String lhsValue = lhs.getObjQualifiedName();
				String rhsValue = rhs.getObjQualifiedName();
				if( lhsValue == null ) {
					if( rhsValue == null ) {
						return( 0 );
					}
					else {
						return( -1 );
					}
				}
				else if( rhsValue == null ) {
					return( 1 );
				}
				else {
					return( lhsValue.compareTo( rhsValue ) );
				}
			}
		}
	}

	protected MinorVersionByQualNameComparator compareMinorVersionByQualName = new MinorVersionByQualNameComparator();

	public Collection<ICFIntMinorVersionObj> getJavaFXDataCollection() {
		return( javafxDataCollection );
	}

	public void setJavaFXDataCollection( Collection<ICFIntMinorVersionObj> value ) {
		final String S_ProcName = "setJavaFXDataCollection";
		javafxDataCollection = value;
		observableListOfMinorVersion = FXCollections.observableArrayList();
		if( javafxDataCollection != null ) {
				Iterator<ICFIntMinorVersionObj> iter = javafxDataCollection.iterator();
				while( iter.hasNext() ) {
					observableListOfMinorVersion.add( iter.next() );
				}
				observableListOfMinorVersion.sort( compareMinorVersionByQualName );
		}
		if( dataTable != null ) {
			dataTable.setItems( observableListOfMinorVersion );
			// Hack from stackoverflow to fix JavaFX TableView refresh issue
			((TableColumn)dataTable.getColumns().get(0)).setVisible( false );
			((TableColumn)dataTable.getColumns().get(0)).setVisible( true );
		}
	}

	public ICFIntMajorVersionObj getJavaFXContainer() {
		return( javafxContainer );
	}

	public void setJavaFXContainer( ICFIntMajorVersionObj value ) {
		javafxContainer = value;
	}

	public void adjustListButtons() {
		boolean enableState;
		ICFIntMinorVersionObj selectedObj = getJavaFXFocusAsMinorVersion();
		if( selectedObj == null ) {
			enableState = false;
		}
		else {
			enableState = true;
		}

		if( buttonChooseSelected != null ) {
			buttonChooseSelected.setDisable( ! enableState );
		}
		if( buttonChooseNone != null ) {
			buttonChooseNone.setDisable( false );
		}
		if( buttonCancel != null ) {
			buttonCancel.setDisable( false );
		}

	}
}
