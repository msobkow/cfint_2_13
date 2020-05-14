// Description: Java 11 Table Object interface for CFInt.

/*
 *	com.github.msobkow.CFInt
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

package com.github.msobkow.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFInt.*;

public interface ICFIntTopDomainTableObj
{
	ICFIntSchemaObj getSchema();
	void setSchema( ICFIntSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new TopDomain instance.
	 *
	 *	@return	A new instance.
	 */
	ICFIntTopDomainObj newInstance();

	/**
	 *	Instantiate a new TopDomain edition of the specified TopDomain instance.
	 *
	 *	@return	A new edition.
	 */
	ICFIntTopDomainEditObj newEditInstance( ICFIntTopDomainObj orig );

	/**
	 *	Internal use only.
	 */
	ICFIntTopDomainObj realiseTopDomain( ICFIntTopDomainObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFIntTopDomainObj createTopDomain( ICFIntTopDomainObj Obj );

	/**
	 *	Read a TopDomain-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The TopDomain-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntTopDomainObj readTopDomain( CFIntTopDomainPKey pkey );

	/**
	 *	Read a TopDomain-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The TopDomain-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntTopDomainObj readTopDomain( CFIntTopDomainPKey pkey,
		boolean forceRead );

	ICFIntTopDomainObj readCachedTopDomain( CFIntTopDomainPKey pkey );

	public void reallyDeepDisposeTopDomain( ICFIntTopDomainObj obj );

	void deepDisposeTopDomain( CFIntTopDomainPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFIntTopDomainObj lockTopDomain( CFIntTopDomainPKey pkey );

	/**
	 *	Return a sorted list of all the TopDomain-derived instances in the database.
	 *
	 *	@return	List of ICFIntTopDomainObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntTopDomainObj> readAllTopDomain();

	/**
	 *	Return a sorted map of all the TopDomain-derived instances in the database.
	 *
	 *	@return	List of ICFIntTopDomainObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntTopDomainObj> readAllTopDomain( boolean forceRead );

	List<ICFIntTopDomainObj> readCachedAllTopDomain();

	/**
	 *	Get the CFIntTopDomainObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTopDomainObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntTopDomainObj readTopDomainByIdIdx( long TenantId,
		long Id );

	/**
	 *	Get the CFIntTopDomainObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTopDomainObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntTopDomainObj readTopDomainByIdIdx( long TenantId,
		long Id,
		boolean forceRead );

	/**
	 *	Get the map of CFIntTopDomainObj instances sorted by their primary keys for the duplicate TenantIdx key.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntTopDomainObj cached instances sorted by their primary keys for the duplicate TenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntTopDomainObj> readTopDomainByTenantIdx( long TenantId );

	/**
	 *	Get the map of CFIntTopDomainObj instances sorted by their primary keys for the duplicate TenantIdx key.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntTopDomainObj cached instances sorted by their primary keys for the duplicate TenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntTopDomainObj> readTopDomainByTenantIdx( long TenantId,
		boolean forceRead );

	/**
	 *	Get the map of CFIntTopDomainObj instances sorted by their primary keys for the duplicate TldIdx key.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argTldId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntTopDomainObj cached instances sorted by their primary keys for the duplicate TldIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntTopDomainObj> readTopDomainByTldIdx( long TenantId,
		long TldId );

	/**
	 *	Get the map of CFIntTopDomainObj instances sorted by their primary keys for the duplicate TldIdx key.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argTldId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntTopDomainObj cached instances sorted by their primary keys for the duplicate TldIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntTopDomainObj> readTopDomainByTldIdx( long TenantId,
		long TldId,
		boolean forceRead );

	/**
	 *	Get the CFIntTopDomainObj instance for the unique NameIdx key.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argTldId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argName	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTopDomainObj cached instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntTopDomainObj readTopDomainByNameIdx(long TenantId,
		long TldId,
		String Name );

	/**
	 *	Get the CFIntTopDomainObj instance for the unique NameIdx key.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argTldId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argName	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@return	CFIntTopDomainObj refreshed instance for the unique NameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntTopDomainObj readTopDomainByNameIdx(long TenantId,
		long TldId,
		String Name,
		boolean forceRead );

	ICFIntTopDomainObj readCachedTopDomainByIdIdx( long TenantId,
		long Id );

	List<ICFIntTopDomainObj> readCachedTopDomainByTenantIdx( long TenantId );

	List<ICFIntTopDomainObj> readCachedTopDomainByTldIdx( long TenantId,
		long TldId );

	ICFIntTopDomainObj readCachedTopDomainByNameIdx( long TenantId,
		long TldId,
		String Name );

	void deepDisposeTopDomainByIdIdx( long TenantId,
		long Id );

	void deepDisposeTopDomainByTenantIdx( long TenantId );

	void deepDisposeTopDomainByTldIdx( long TenantId,
		long TldId );

	void deepDisposeTopDomainByNameIdx( long TenantId,
		long TldId,
		String Name );

	/**
	 *	Internal use only.
	 */
	ICFIntTopDomainObj updateTopDomain( ICFIntTopDomainObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteTopDomain( ICFIntTopDomainObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argId	The TopDomain key attribute of the instance generating the id.
	 */
	void deleteTopDomainByIdIdx( long TenantId,
		long Id );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 */
	void deleteTopDomainByTenantIdx( long TenantId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argTldId	The TopDomain key attribute of the instance generating the id.
	 */
	void deleteTopDomainByTldIdx( long TenantId,
		long TldId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argTldId	The TopDomain key attribute of the instance generating the id.
	 *
	 *	@param	argName	The TopDomain key attribute of the instance generating the id.
	 */
	void deleteTopDomainByNameIdx(long TenantId,
		long TldId,
		String Name );
}
