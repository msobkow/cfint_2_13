
// Description: Java 11 Factory interface for License.

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

package org.msscf.msscf.cfint.CFInt;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;

/*
 *	CFIntLicenseFactory interface for License
 */
public interface ICFIntLicenseFactory
{

	/**
	 *	Allocate a primary key for License instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntLicensePKey newPKey();

	/**
	 *	Allocate a primary history key for License instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntLicenseHPKey newHPKey();

	/**
	 *	Allocate a LicnTenantIdx key over License instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntLicenseByLicnTenantIdxKey newLicnTenantIdxKey();

	/**
	 *	Allocate a DomainIdx key over License instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntLicenseByDomainIdxKey newDomainIdxKey();

	/**
	 *	Allocate a UNameIdx key over License instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntLicenseByUNameIdxKey newUNameIdxKey();

	/**
	 *	Allocate a License instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFIntLicenseBuff newBuff();

	/**
	 *	Allocate a License history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFIntLicenseHBuff newHBuff();

}
