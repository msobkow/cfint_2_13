
// Description: Java 11 Factory interface for SubProject.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow mark.sobkow@gmail.com
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

package org.msscf.msscf.v2_13.cfint.CFInt;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;

/*
 *	CFIntSubProjectFactory interface for SubProject
 */
public interface ICFIntSubProjectFactory
{

	/**
	 *	Allocate a primary key for SubProject instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntSubProjectPKey newPKey();

	/**
	 *	Allocate a primary history key for SubProject instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntSubProjectHPKey newHPKey();

	/**
	 *	Allocate a TenantIdx key over SubProject instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntSubProjectByTenantIdxKey newTenantIdxKey();

	/**
	 *	Allocate a TopProjectIdx key over SubProject instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntSubProjectByTopProjectIdxKey newTopProjectIdxKey();

	/**
	 *	Allocate a NameIdx key over SubProject instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntSubProjectByNameIdxKey newNameIdxKey();

	/**
	 *	Allocate a SubProject instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFIntSubProjectBuff newBuff();

	/**
	 *	Allocate a SubProject history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFIntSubProjectHBuff newHBuff();

}
