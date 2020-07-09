// Description: Java 11 JavaFX Display Element Factory Interface for License.

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
 *	ICFIntJavaFXLicenseFactory JavaFX Display Element Factory Interface
 *	for License.
 */
public interface ICFIntJavaFXLicenseFactory
{
	public CFGridPane newAttrPane( ICFFormManager formManager, ICFIntLicenseObj javaFXFocus );

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFIntTopDomainObj argContainer,
		ICFIntLicenseObj argFocus,
		Collection<ICFIntLicenseObj> argDataCollection,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain );

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFIntLicenseObj argFocus,
		ICFIntTopDomainObj argContainer,
		Collection<ICFIntLicenseObj> argDataCollection,
		ICFIntJavaFXLicenseChosen whenChosen );

	public CFTabPane newEltTabPane( ICFFormManager formManger, ICFIntLicenseObj javaFXFocus );

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFIntLicenseObj javaFXFocus, ICFDeleteCallback callback );

	public CFSplitPane newAddPane( ICFFormManager formManger, ICFIntLicenseObj javaFXFocus );

	public CFSplitPane newViewEditPane( ICFFormManager formManger, ICFIntLicenseObj javaFXFocus );

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFIntLicenseObj javaFXFocus,
		ICFIntTopDomainObj argContainer,
		Collection<ICFIntLicenseObj> argDataCollection,
		ICFIntJavaFXLicenseChosen whenChosen );

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFIntLicenseObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean allowSave );

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFIntLicenseObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd );
}
