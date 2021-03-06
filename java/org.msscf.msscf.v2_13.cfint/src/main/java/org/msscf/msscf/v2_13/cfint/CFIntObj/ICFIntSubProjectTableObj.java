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

public interface ICFIntSubProjectTableObj
{
	ICFIntSchemaObj getSchema();
	void setSchema( ICFIntSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new SubProject instance.
	 *
	 *	@return	A new instance.
	 */
	ICFIntSubProjectObj newInstance();

	/**
	 *	Instantiate a new SubProject edition of the specified SubProject instance.
	 *
	 *	@return	A new edition.
	 */
	ICFIntSubProjectEditObj newEditInstance( ICFIntSubProjectObj orig );

	/**
	 *	Internal use only.
	 */
	ICFIntSubProjectObj realiseSubProject( ICFIntSubProjectObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFIntSubProjectObj createSubProject( ICFIntSubProjectObj Obj );

	/**
	 *	Read a SubProject-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The SubProject-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntSubProjectObj readSubProject( CFIntSubProjectPKey pkey );

	/**
	 *	Read a SubProject-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The SubProject-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntSubProjectObj readSubProject( CFIntSubProjectPKey pkey,
		boolean forceRead );

	ICFIntSubProjectObj readCachedSubProject( CFIntSubProjectPKey pkey );

	public void reallyDeepDisposeSubProject( ICFIntSubProjectObj obj );

	void deepDisposeSubProject( CFIntSubProjectPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFIntSubProjectObj lockSubProject( CFIntSubProjectPKey pkey );

	/**
	 *	Return a sorted list of all the SubProject-derived instances in the database.
	 *
	 *	@return	List of ICFIntSubProjectObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntSubProjectObj> readAllSubProject();

	/**
	 *	Return a sorted map of all the SubProject-derived instances in the database.
	 *
	 *	@return	List of ICFIntSubProjectObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntSubProjectObj> readAllSubProject( boolean forceRead );

	List<ICFIntSubProjectObj> readCachedAllSubProject();

	/**
	 *	Get the CFIntSubProjectObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@return	CFIntSubProjectObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntSubProjectObj readSubProjectByIdIdx( long TenantId,
		long Id );

	/**
	 *	Get the CFIntSubProjectObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@return	CFIntSubProjectObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntSubProjectObj readSubProjectByIdIdx( long TenantId,
		long Id,
		boolean forceRead );

	/**
	 *	Get the map of CFIntSubProjectObj instances sorted by their primary keys for the duplicate TenantIdx key.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntSubProjectObj cached instances sorted by their primary keys for the duplicate TenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntSubProjectObj> readSubProjectByTenantIdx( long TenantId );

	/**
	 *	Get the map of CFIntSubProjectObj instances sorted by their primary keys for the duplicate TenantIdx key.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntSubProjectObj cached instances sorted by their primary keys for the duplicate TenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntSubProjectObj> readSubProjectByTenantIdx( long TenantId,
		boolean forceRead );

	/**
	 *	Get the map of CFIntSubProjectObj instances sorted by their primary keys for the duplicate TopProjectIdx key.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopProjectId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntSubProjectObj cached instances sorted by their primary keys for the duplicate TopProjectIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntSubProjectObj> readSubProjectByTopProjectIdx( long TenantId,
		long TopProjectId );

	/**
	 *	Get the map of CFIntSubProjectObj instances sorted by their primary keys for the duplicate TopProjectIdx key.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopProjectId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntSubProjectObj cached instances sorted by their primary keys for the duplicate TopProjectIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntSubProjectObj> readSubProjectByTopProjectIdx( long TenantId,
		long TopProjectId,
		boolean forceRead );

	/**
	 *	Get the CFIntSubProjectObj instance for the unique NameIdx key.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopProjectId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argName	The SubProject key attribute of the instance generating the id.
	 *
	 *	@return	CFIntSubProjectObj cached instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntSubProjectObj readSubProjectByNameIdx(long TenantId,
		long TopProjectId,
		String Name );

	/**
	 *	Get the CFIntSubProjectObj instance for the unique NameIdx key.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopProjectId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argName	The SubProject key attribute of the instance generating the id.
	 *
	 *	@return	CFIntSubProjectObj refreshed instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntSubProjectObj readSubProjectByNameIdx(long TenantId,
		long TopProjectId,
		String Name,
		boolean forceRead );

	ICFIntSubProjectObj readCachedSubProjectByIdIdx( long TenantId,
		long Id );

	List<ICFIntSubProjectObj> readCachedSubProjectByTenantIdx( long TenantId );

	List<ICFIntSubProjectObj> readCachedSubProjectByTopProjectIdx( long TenantId,
		long TopProjectId );

	ICFIntSubProjectObj readCachedSubProjectByNameIdx( long TenantId,
		long TopProjectId,
		String Name );

	void deepDisposeSubProjectByIdIdx( long TenantId,
		long Id );

	void deepDisposeSubProjectByTenantIdx( long TenantId );

	void deepDisposeSubProjectByTopProjectIdx( long TenantId,
		long TopProjectId );

	void deepDisposeSubProjectByNameIdx( long TenantId,
		long TopProjectId,
		String Name );

	/**
	 *	Internal use only.
	 */
	ICFIntSubProjectObj updateSubProject( ICFIntSubProjectObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteSubProject( ICFIntSubProjectObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argId	The SubProject key attribute of the instance generating the id.
	 */
	void deleteSubProjectByIdIdx( long TenantId,
		long Id );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 */
	void deleteSubProjectByTenantIdx( long TenantId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopProjectId	The SubProject key attribute of the instance generating the id.
	 */
	void deleteSubProjectByTopProjectIdx( long TenantId,
		long TopProjectId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopProjectId	The SubProject key attribute of the instance generating the id.
	 *
	 *	@param	argName	The SubProject key attribute of the instance generating the id.
	 */
	void deleteSubProjectByNameIdx(long TenantId,
		long TopProjectId,
		String Name );
}
