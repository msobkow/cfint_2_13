// Description: Java 11 JavaFX Display Element Factory Interface for TopProject.

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
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/**
 *	ICFIntJavaFXTopProjectFactory JavaFX Display Element Factory Interface
 *	for TopProject.
 */
public interface ICFIntJavaFXTopProjectFactory
{
	public CFGridPane newAttrPane( ICFFormManager formManager, ICFIntTopProjectObj javaFXFocus );

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFIntTopDomainObj argContainer,
		ICFIntTopProjectObj argFocus,
		Collection<ICFIntTopProjectObj> argDataCollection,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain );

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFIntTopProjectObj argFocus,
		ICFIntTopDomainObj argContainer,
		Collection<ICFIntTopProjectObj> argDataCollection,
		ICFIntJavaFXTopProjectChosen whenChosen );

	public CFTabPane newEltTabPane( ICFFormManager formManger, ICFIntTopProjectObj javaFXFocus );

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFIntTopProjectObj javaFXFocus, ICFDeleteCallback callback );

	public CFSplitPane newAddPane( ICFFormManager formManger, ICFIntTopProjectObj javaFXFocus );

	public CFSplitPane newViewEditPane( ICFFormManager formManger, ICFIntTopProjectObj javaFXFocus );

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFIntTopProjectObj javaFXFocus,
		ICFIntTopDomainObj argContainer,
		Collection<ICFIntTopProjectObj> argDataCollection,
		ICFIntJavaFXTopProjectChosen whenChosen );

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFIntTopProjectObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean allowSave );

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFIntTopProjectObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd );
}
