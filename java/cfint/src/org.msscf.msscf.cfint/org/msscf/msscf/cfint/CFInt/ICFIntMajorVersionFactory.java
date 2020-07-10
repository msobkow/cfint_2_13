
// Description: Java 11 Factory interface for MajorVersion.

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
 *	CFIntMajorVersionFactory interface for MajorVersion
 */
public interface ICFIntMajorVersionFactory
{

	/**
	 *	Allocate a primary key for MajorVersion instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntMajorVersionPKey newPKey();

	/**
	 *	Allocate a primary history key for MajorVersion instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntMajorVersionHPKey newHPKey();

	/**
	 *	Allocate a TenantIdx key over MajorVersion instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntMajorVersionByTenantIdxKey newTenantIdxKey();

	/**
	 *	Allocate a SubProjectIdx key over MajorVersion instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntMajorVersionBySubProjectIdxKey newSubProjectIdxKey();

	/**
	 *	Allocate a NameIdx key over MajorVersion instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntMajorVersionByNameIdxKey newNameIdxKey();

	/**
	 *	Allocate a MajorVersion instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFIntMajorVersionBuff newBuff();

	/**
	 *	Allocate a MajorVersion history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFIntMajorVersionHBuff newHBuff();

}
