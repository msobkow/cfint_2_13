// Description: Java 11 Table Object interface for CFInt.

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

package org.msscf.msscf.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFInt.*;

public interface ICFIntTldTableObj
{
	ICFIntSchemaObj getSchema();
	void setSchema( ICFIntSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new Tld instance.
	 *
	 *	@return	A new instance.
	 */
	ICFIntTldObj newInstance();

	/**
	 *	Instantiate a new Tld edition of the specified Tld instance.
	 *
	 *	@return	A new edition.
	 */
	ICFIntTldEditObj newEditInstance( ICFIntTldObj orig );

	/**
	 *	Internal use only.
	 */
	ICFIntTldObj realiseTld( ICFIntTldObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFIntTldObj createTld( ICFIntTldObj Obj );

	/**
	 *	Read a Tld-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The Tld-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntTldObj readTld( CFIntTldPKey pkey );

	/**
	 *	Read a Tld-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The Tld-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntTldObj readTld( CFIntTldPKey pkey,
		boolean forceRead );

	ICFIntTldObj readCachedTld( CFIntTldPKey pkey );

	public void reallyDeepDisposeTld( ICFIntTldObj obj );

	void deepDisposeTld( CFIntTldPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFIntTldObj lockTld( CFIntTldPKey pkey );

	/**
	 *	Return a sorted list of all the Tld-derived instances in the database.
	 *
	 *	@return	List of ICFIntTldObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntTldObj> readAllTld();

	/**
	 *	Return a sorted map of all the Tld-derived instances in the database.
	 *
	 *	@return	List of ICFIntTldObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntTldObj> readAllTld( boolean forceRead );

	List<ICFIntTldObj> readCachedAllTld();

	/**
	 *	Get the CFIntTldObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The Tld key attribute of the instance generating the id.
	 *
	 *	@param	argId	The Tld key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTldObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntTldObj readTldByIdIdx( long TenantId,
		long Id );

	/**
	 *	Get the CFIntTldObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The Tld key attribute of the instance generating the id.
	 *
	 *	@param	argId	The Tld key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTldObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntTldObj readTldByIdIdx( long TenantId,
		long Id,
		boolean forceRead );

	/**
	 *	Get the map of CFIntTldObj instances sorted by their primary keys for the duplicate TenantIdx key.
	 *
	 *	@param	argTenantId	The Tld key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntTldObj cached instances sorted by their primary keys for the duplicate TenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntTldObj> readTldByTenantIdx( long TenantId );

	/**
	 *	Get the map of CFIntTldObj instances sorted by their primary keys for the duplicate TenantIdx key.
	 *
	 *	@param	argTenantId	The Tld key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntTldObj cached instances sorted by their primary keys for the duplicate TenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntTldObj> readTldByTenantIdx( long TenantId,
		boolean forceRead );

	/**
	 *	Get the CFIntTldObj instance for the unique NameIdx key.
	 *
	 *	@param	argTenantId	The Tld key attribute of the instance generating the id.
	 *
	 *	@param	argName	The Tld key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTldObj cached instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntTldObj readTldByNameIdx(long TenantId,
		String Name );

	/**
	 *	Get the CFIntTldObj instance for the unique NameIdx key.
	 *
	 *	@param	argTenantId	The Tld key attribute of the instance generating the id.
	 *
	 *	@param	argName	The Tld key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTldObj refreshed instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntTldObj readTldByNameIdx(long TenantId,
		String Name,
		boolean forceRead );

	ICFIntTldObj readCachedTldByIdIdx( long TenantId,
		long Id );

	List<ICFIntTldObj> readCachedTldByTenantIdx( long TenantId );

	ICFIntTldObj readCachedTldByNameIdx( long TenantId,
		String Name );

	void deepDisposeTldByIdIdx( long TenantId,
		long Id );

	void deepDisposeTldByTenantIdx( long TenantId );

	void deepDisposeTldByNameIdx( long TenantId,
		String Name );

	/**
	 *	Internal use only.
	 */
	ICFIntTldObj updateTld( ICFIntTldObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteTld( ICFIntTldObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The Tld key attribute of the instance generating the id.
	 *
	 *	@param	argId	The Tld key attribute of the instance generating the id.
	 */
	void deleteTldByIdIdx( long TenantId,
		long Id );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The Tld key attribute of the instance generating the id.
	 */
	void deleteTldByTenantIdx( long TenantId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The Tld key attribute of the instance generating the id.
	 *
	 *	@param	argName	The Tld key attribute of the instance generating the id.
	 */
	void deleteTldByNameIdx(long TenantId,
		String Name );
}
