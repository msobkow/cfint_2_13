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

public interface ICFIntURLProtocolTableObj
{
	ICFIntSchemaObj getSchema();
	void setSchema( ICFIntSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new URLProtocol instance.
	 *
	 *	@return	A new instance.
	 */
	ICFIntURLProtocolObj newInstance();

	/**
	 *	Instantiate a new URLProtocol edition of the specified URLProtocol instance.
	 *
	 *	@return	A new edition.
	 */
	ICFIntURLProtocolEditObj newEditInstance( ICFIntURLProtocolObj orig );

	/**
	 *	Internal use only.
	 */
	ICFIntURLProtocolObj realiseURLProtocol( ICFIntURLProtocolObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFIntURLProtocolObj createURLProtocol( ICFIntURLProtocolObj Obj );

	/**
	 *	Read a URLProtocol-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The URLProtocol-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntURLProtocolObj readURLProtocol( CFIntURLProtocolPKey pkey );

	/**
	 *	Read a URLProtocol-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The URLProtocol-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntURLProtocolObj readURLProtocol( CFIntURLProtocolPKey pkey,
		boolean forceRead );

	ICFIntURLProtocolObj readCachedURLProtocol( CFIntURLProtocolPKey pkey );

	public void reallyDeepDisposeURLProtocol( ICFIntURLProtocolObj obj );

	void deepDisposeURLProtocol( CFIntURLProtocolPKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFIntURLProtocolObj lockURLProtocol( CFIntURLProtocolPKey pkey );

	/**
	 *	Return a sorted list of all the URLProtocol-derived instances in the database.
	 *
	 *	@return	List of ICFIntURLProtocolObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntURLProtocolObj> readAllURLProtocol();

	/**
	 *	Return a sorted map of all the URLProtocol-derived instances in the database.
	 *
	 *	@return	List of ICFIntURLProtocolObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntURLProtocolObj> readAllURLProtocol( boolean forceRead );

	List<ICFIntURLProtocolObj> readCachedAllURLProtocol();

	/**
	 *	Get the CFIntURLProtocolObj instance for the primary key attributes.
	 *
	 *	@param	argURLProtocolId	The URLProtocol key attribute of the instance generating the id.
	 *
	 *	@return	CFIntURLProtocolObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntURLProtocolObj readURLProtocolByIdIdx( int URLProtocolId );

	/**
	 *	Get the CFIntURLProtocolObj instance for the primary key attributes.
	 *
	 *	@param	argURLProtocolId	The URLProtocol key attribute of the instance generating the id.
	 *
	 *	@return	CFIntURLProtocolObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntURLProtocolObj readURLProtocolByIdIdx( int URLProtocolId,
		boolean forceRead );

	/**
	 *	Get the CFIntURLProtocolObj instance for the unique UNameIdx key.
	 *
	 *	@param	argName	The URLProtocol key attribute of the instance generating the id.
	 *
	 *	@return	CFIntURLProtocolObj cached instance for the unique UNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntURLProtocolObj readURLProtocolByUNameIdx(String Name );

	/**
	 *	Get the CFIntURLProtocolObj instance for the unique UNameIdx key.
	 *
	 *	@param	argName	The URLProtocol key attribute of the instance generating the id.
	 *
	 *	@return	CFIntURLProtocolObj refreshed instance for the unique UNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntURLProtocolObj readURLProtocolByUNameIdx(String Name,
		boolean forceRead );

	/**
	 *	Get the map of CFIntURLProtocolObj instances sorted by their primary keys for the duplicate IsSecureIdx key.
	 *
	 *	@param	argIsSecure	The URLProtocol key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntURLProtocolObj cached instances sorted by their primary keys for the duplicate IsSecureIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntURLProtocolObj> readURLProtocolByIsSecureIdx( boolean IsSecure );

	/**
	 *	Get the map of CFIntURLProtocolObj instances sorted by their primary keys for the duplicate IsSecureIdx key.
	 *
	 *	@param	argIsSecure	The URLProtocol key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntURLProtocolObj cached instances sorted by their primary keys for the duplicate IsSecureIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntURLProtocolObj> readURLProtocolByIsSecureIdx( boolean IsSecure,
		boolean forceRead );

	ICFIntURLProtocolObj readCachedURLProtocolByIdIdx( int URLProtocolId );

	ICFIntURLProtocolObj readCachedURLProtocolByUNameIdx( String Name );

	List<ICFIntURLProtocolObj> readCachedURLProtocolByIsSecureIdx( boolean IsSecure );

	void deepDisposeURLProtocolByIdIdx( int URLProtocolId );

	void deepDisposeURLProtocolByUNameIdx( String Name );

	void deepDisposeURLProtocolByIsSecureIdx( boolean IsSecure );

	/**
	 *	Internal use only.
	 */
	ICFIntURLProtocolObj updateURLProtocol( ICFIntURLProtocolObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteURLProtocol( ICFIntURLProtocolObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argURLProtocolId	The URLProtocol key attribute of the instance generating the id.
	 */
	void deleteURLProtocolByIdIdx( int URLProtocolId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argName	The URLProtocol key attribute of the instance generating the id.
	 */
	void deleteURLProtocolByUNameIdx(String Name );

	/**
	 *	Internal use only.
	 *
	 *	@param	argIsSecure	The URLProtocol key attribute of the instance generating the id.
	 */
	void deleteURLProtocolByIsSecureIdx( boolean IsSecure );
}
