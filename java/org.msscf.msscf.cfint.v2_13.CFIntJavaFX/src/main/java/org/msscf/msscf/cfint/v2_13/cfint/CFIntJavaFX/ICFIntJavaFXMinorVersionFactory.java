// Description: Java 11 JavaFX Display Element Factory Interface for MinorVersion.

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
 *	ICFIntJavaFXMinorVersionFactory JavaFX Display Element Factory Interface
 *	for MinorVersion.
 */
public interface ICFIntJavaFXMinorVersionFactory
{
	public CFGridPane newAttrPane( ICFFormManager formManager, ICFIntMinorVersionObj javaFXFocus );

	public CFBorderPane newListPane( ICFFormManager formManager,
		ICFIntMajorVersionObj argContainer,
		ICFIntMinorVersionObj argFocus,
		Collection<ICFIntMinorVersionObj> argDataCollection,
		ICFRefreshCallback refreshCallback,
		boolean sortByChain );

	public CFBorderPane newPickerPane( ICFFormManager formManager,
		ICFIntMinorVersionObj argFocus,
		ICFIntMajorVersionObj argContainer,
		Collection<ICFIntMinorVersionObj> argDataCollection,
		ICFIntJavaFXMinorVersionChosen whenChosen );

	public CFTabPane newEltTabPane( ICFFormManager formManger, ICFIntMinorVersionObj javaFXFocus );

	public CFBorderPane newAskDeleteForm( ICFFormManager formManager, ICFIntMinorVersionObj javaFXFocus, ICFDeleteCallback callback );

	public CFSplitPane newAddPane( ICFFormManager formManger, ICFIntMinorVersionObj javaFXFocus );

	public CFSplitPane newViewEditPane( ICFFormManager formManger, ICFIntMinorVersionObj javaFXFocus );

	public CFBorderPane newPickerForm( ICFFormManager formManager,
		ICFIntMinorVersionObj javaFXFocus,
		ICFIntMajorVersionObj argContainer,
		Collection<ICFIntMinorVersionObj> argDataCollection,
		ICFIntJavaFXMinorVersionChosen whenChosen );

	public CFBorderPane newAddForm( ICFFormManager formManager, ICFIntMinorVersionObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean allowSave );

	public CFBorderPane newViewEditForm( ICFFormManager formManager, ICFIntMinorVersionObj javaFXFocus, ICFFormClosedCallback closeCallback, boolean cameFromAdd );
}
