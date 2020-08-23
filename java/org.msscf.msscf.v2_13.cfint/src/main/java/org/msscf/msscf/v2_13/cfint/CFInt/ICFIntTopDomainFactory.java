
// Description: Java 11 Factory interface for TopDomain.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow msobkow@sasktel.net
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
 *	CFIntTopDomainFactory interface for TopDomain
 */
public interface ICFIntTopDomainFactory
{

	/**
	 *	Allocate a primary key for TopDomain instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntTopDomainPKey newPKey();

	/**
	 *	Allocate a primary history key for TopDomain instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntTopDomainHPKey newHPKey();

	/**
	 *	Allocate a TenantIdx key over TopDomain instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntTopDomainByTenantIdxKey newTenantIdxKey();

	/**
	 *	Allocate a TldIdx key over TopDomain instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntTopDomainByTldIdxKey newTldIdxKey();

	/**
	 *	Allocate a NameIdx key over TopDomain instances.
	 *
	 *	@return	The new instance.
	 */
	CFIntTopDomainByNameIdxKey newNameIdxKey();

	/**
	 *	Allocate a TopDomain instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFIntTopDomainBuff newBuff();

	/**
	 *	Allocate a TopDomain history instance buffer.
	 *
	 *	@return	The new instance.
	 */
	CFIntTopDomainHBuff newHBuff();

}
