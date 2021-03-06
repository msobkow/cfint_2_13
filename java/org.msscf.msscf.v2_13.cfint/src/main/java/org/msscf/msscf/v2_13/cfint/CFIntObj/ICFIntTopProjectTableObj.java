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

public interface ICFIntTopProjectTableObj
{
	ICFIntSchemaObj getSchema();
	void setSchema( ICFIntSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new TopProject instance.
	 *
	 *	@return	A new instance.
	 */
	ICFIntTopProjectObj newInstance();

	/**
	 *	Instantiate a new TopProject edition of the specified TopProject instance.
	 *
	 *	@return	A new edition.
	 */
	ICFIntTopProjectEditObj newEditInstance( ICFIntTopProjectObj orig );

	/**
	 *	Internal use only.
	 */
	ICFIntTopProjectObj realiseTopProject( ICFIntTopProjectObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFIntTopProjectObj createTopProject( ICFIntTopProjectObj Obj );

	/**
	 *	Read a TopProject-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The TopProject-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntTopProjectObj readTopProject( CFIntTopProjectPKey pkey );

	/**
	 *	Read a TopProject-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The TopProject-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntTopProjectObj readTopProject( CFIntTopProjectPKey pkey,
		boolean forceRead );

	ICFIntTopProjectObj readCachedTopProject( CFIntTopProjectPKey pkey );

	public void reallyDeepDisposeTopProject( ICFIntTopProjectObj obj );

	void deepDisposeTopProject( CFIntTopProjectPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFIntTopProjectObj lockTopProject( CFIntTopProjectPKey pkey );

	/**
	 *	Return a sorted list of all the TopProject-derived instances in the database.
	 *
	 *	@return	List of ICFIntTopProjectObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntTopProjectObj> readAllTopProject();

	/**
	 *	Return a sorted map of all the TopProject-derived instances in the database.
	 *
	 *	@return	List of ICFIntTopProjectObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntTopProjectObj> readAllTopProject( boolean forceRead );

	List<ICFIntTopProjectObj> readCachedAllTopProject();

	/**
	 *	Get the CFIntTopProjectObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTopProjectObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntTopProjectObj readTopProjectByIdIdx( long TenantId,
		long Id );

	/**
	 *	Get the CFIntTopProjectObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTopProjectObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntTopProjectObj readTopProjectByIdIdx( long TenantId,
		long Id,
		boolean forceRead );

	/**
	 *	Get the map of CFIntTopProjectObj instances sorted by their primary keys for the duplicate TenantIdx key.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntTopProjectObj cached instances sorted by their primary keys for the duplicate TenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntTopProjectObj> readTopProjectByTenantIdx( long TenantId );

	/**
	 *	Get the map of CFIntTopProjectObj instances sorted by their primary keys for the duplicate TenantIdx key.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntTopProjectObj cached instances sorted by their primary keys for the duplicate TenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntTopProjectObj> readTopProjectByTenantIdx( long TenantId,
		boolean forceRead );

	/**
	 *	Get the map of CFIntTopProjectObj instances sorted by their primary keys for the duplicate TopDomainIdx key.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntTopProjectObj cached instances sorted by their primary keys for the duplicate TopDomainIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntTopProjectObj> readTopProjectByTopDomainIdx( long TenantId,
		long TopDomainId );

	/**
	 *	Get the map of CFIntTopProjectObj instances sorted by their primary keys for the duplicate TopDomainIdx key.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntTopProjectObj cached instances sorted by their primary keys for the duplicate TopDomainIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntTopProjectObj> readTopProjectByTopDomainIdx( long TenantId,
		long TopDomainId,
		boolean forceRead );

	/**
	 *	Get the CFIntTopProjectObj instance for the unique NameIdx key.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argName	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTopProjectObj cached instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntTopProjectObj readTopProjectByNameIdx(long TenantId,
		long TopDomainId,
		String Name );

	/**
	 *	Get the CFIntTopProjectObj instance for the unique NameIdx key.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argName	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTopProjectObj refreshed instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntTopProjectObj readTopProjectByNameIdx(long TenantId,
		long TopDomainId,
		String Name,
		boolean forceRead );

	ICFIntTopProjectObj readCachedTopProjectByIdIdx( long TenantId,
		long Id );

	List<ICFIntTopProjectObj> readCachedTopProjectByTenantIdx( long TenantId );

	List<ICFIntTopProjectObj> readCachedTopProjectByTopDomainIdx( long TenantId,
		long TopDomainId );

	ICFIntTopProjectObj readCachedTopProjectByNameIdx( long TenantId,
		long TopDomainId,
		String Name );

	void deepDisposeTopProjectByIdIdx( long TenantId,
		long Id );

	void deepDisposeTopProjectByTenantIdx( long TenantId );

	void deepDisposeTopProjectByTopDomainIdx( long TenantId,
		long TopDomainId );

	void deepDisposeTopProjectByNameIdx( long TenantId,
		long TopDomainId,
		String Name );

	/**
	 *	Internal use only.
	 */
	ICFIntTopProjectObj updateTopProject( ICFIntTopProjectObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteTopProject( ICFIntTopProjectObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argId	The TopProject key attribute of the instance generating the id.
	 */
	void deleteTopProjectByIdIdx( long TenantId,
		long Id );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 */
	void deleteTopProjectByTenantIdx( long TenantId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 */
	void deleteTopProjectByTopDomainIdx( long TenantId,
		long TopDomainId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argName	The TopProject key attribute of the instance generating the id.
	 */
	void deleteTopProjectByNameIdx(long TenantId,
		long TopDomainId,
		String Name );
}
