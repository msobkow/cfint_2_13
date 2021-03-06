// Description: Java 11 Table Object interface for CFInt.

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

package org.msscf.msscf.v2_13.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;
import org.msscf.msscf.v2_13.cfsec.CFSecObj.*;
import org.msscf.msscf.v2_13.cfint.CFInt.*;

public interface ICFIntMinorVersionTableObj
{
	ICFIntSchemaObj getSchema();
	void setSchema( ICFIntSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new MinorVersion instance.
	 *
	 *	@return	A new instance.
	 */
	ICFIntMinorVersionObj newInstance();

	/**
	 *	Instantiate a new MinorVersion edition of the specified MinorVersion instance.
	 *
	 *	@return	A new edition.
	 */
	ICFIntMinorVersionEditObj newEditInstance( ICFIntMinorVersionObj orig );

	/**
	 *	Internal use only.
	 */
	ICFIntMinorVersionObj realiseMinorVersion( ICFIntMinorVersionObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFIntMinorVersionObj createMinorVersion( ICFIntMinorVersionObj Obj );

	/**
	 *	Read a MinorVersion-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The MinorVersion-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntMinorVersionObj readMinorVersion( CFIntMinorVersionPKey pkey );

	/**
	 *	Read a MinorVersion-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The MinorVersion-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntMinorVersionObj readMinorVersion( CFIntMinorVersionPKey pkey,
		boolean forceRead );

	ICFIntMinorVersionObj readCachedMinorVersion( CFIntMinorVersionPKey pkey );

	public void reallyDeepDisposeMinorVersion( ICFIntMinorVersionObj obj );

	void deepDisposeMinorVersion( CFIntMinorVersionPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFIntMinorVersionObj lockMinorVersion( CFIntMinorVersionPKey pkey );

	/**
	 *	Return a sorted list of all the MinorVersion-derived instances in the database.
	 *
	 *	@return	List of ICFIntMinorVersionObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntMinorVersionObj> readAllMinorVersion();

	/**
	 *	Return a sorted map of all the MinorVersion-derived instances in the database.
	 *
	 *	@return	List of ICFIntMinorVersionObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntMinorVersionObj> readAllMinorVersion( boolean forceRead );

	List<ICFIntMinorVersionObj> readCachedAllMinorVersion();

	/**
	 *	Get the CFIntMinorVersionObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@return	CFIntMinorVersionObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntMinorVersionObj readMinorVersionByIdIdx( long TenantId,
		long Id );

	/**
	 *	Get the CFIntMinorVersionObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@return	CFIntMinorVersionObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntMinorVersionObj readMinorVersionByIdIdx( long TenantId,
		long Id,
		boolean forceRead );

	/**
	 *	Get the map of CFIntMinorVersionObj instances sorted by their primary keys for the duplicate TenantIdx key.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntMinorVersionObj cached instances sorted by their primary keys for the duplicate TenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntMinorVersionObj> readMinorVersionByTenantIdx( long TenantId );

	/**
	 *	Get the map of CFIntMinorVersionObj instances sorted by their primary keys for the duplicate TenantIdx key.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntMinorVersionObj cached instances sorted by their primary keys for the duplicate TenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntMinorVersionObj> readMinorVersionByTenantIdx( long TenantId,
		boolean forceRead );

	/**
	 *	Get the map of CFIntMinorVersionObj instances sorted by their primary keys for the duplicate MajorVerIdx key.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argMajorVersionId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntMinorVersionObj cached instances sorted by their primary keys for the duplicate MajorVerIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntMinorVersionObj> readMinorVersionByMajorVerIdx( long TenantId,
		long MajorVersionId );

	/**
	 *	Get the map of CFIntMinorVersionObj instances sorted by their primary keys for the duplicate MajorVerIdx key.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argMajorVersionId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntMinorVersionObj cached instances sorted by their primary keys for the duplicate MajorVerIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntMinorVersionObj> readMinorVersionByMajorVerIdx( long TenantId,
		long MajorVersionId,
		boolean forceRead );

	/**
	 *	Get the CFIntMinorVersionObj instance for the unique NameIdx key.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argMajorVersionId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argName	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@return	CFIntMinorVersionObj cached instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntMinorVersionObj readMinorVersionByNameIdx(long TenantId,
		long MajorVersionId,
		String Name );

	/**
	 *	Get the CFIntMinorVersionObj instance for the unique NameIdx key.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argMajorVersionId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argName	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@return	CFIntMinorVersionObj refreshed instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntMinorVersionObj readMinorVersionByNameIdx(long TenantId,
		long MajorVersionId,
		String Name,
		boolean forceRead );

	ICFIntMinorVersionObj readCachedMinorVersionByIdIdx( long TenantId,
		long Id );

	List<ICFIntMinorVersionObj> readCachedMinorVersionByTenantIdx( long TenantId );

	List<ICFIntMinorVersionObj> readCachedMinorVersionByMajorVerIdx( long TenantId,
		long MajorVersionId );

	ICFIntMinorVersionObj readCachedMinorVersionByNameIdx( long TenantId,
		long MajorVersionId,
		String Name );

	void deepDisposeMinorVersionByIdIdx( long TenantId,
		long Id );

	void deepDisposeMinorVersionByTenantIdx( long TenantId );

	void deepDisposeMinorVersionByMajorVerIdx( long TenantId,
		long MajorVersionId );

	void deepDisposeMinorVersionByNameIdx( long TenantId,
		long MajorVersionId,
		String Name );

	/**
	 *	Internal use only.
	 */
	ICFIntMinorVersionObj updateMinorVersion( ICFIntMinorVersionObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteMinorVersion( ICFIntMinorVersionObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argId	The MinorVersion key attribute of the instance generating the id.
	 */
	void deleteMinorVersionByIdIdx( long TenantId,
		long Id );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 */
	void deleteMinorVersionByTenantIdx( long TenantId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argMajorVersionId	The MinorVersion key attribute of the instance generating the id.
	 */
	void deleteMinorVersionByMajorVerIdx( long TenantId,
		long MajorVersionId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argMajorVersionId	The MinorVersion key attribute of the instance generating the id.
	 *
	 *	@param	argName	The MinorVersion key attribute of the instance generating the id.
	 */
	void deleteMinorVersionByNameIdx(long TenantId,
		long MajorVersionId,
		String Name );
}
