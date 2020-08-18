// Description: Java 11 Table Object interface for CFInt.

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

package org.msscf.msscf.v2_13.cfint.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFInt.*;

public interface ICFIntMimeTypeTableObj
{
	ICFIntSchemaObj getSchema();
	void setSchema( ICFIntSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new MimeType instance.
	 *
	 *	@return	A new instance.
	 */
	ICFIntMimeTypeObj newInstance();

	/**
	 *	Instantiate a new MimeType edition of the specified MimeType instance.
	 *
	 *	@return	A new edition.
	 */
	ICFIntMimeTypeEditObj newEditInstance( ICFIntMimeTypeObj orig );

	/**
	 *	Internal use only.
	 */
	ICFIntMimeTypeObj realiseMimeType( ICFIntMimeTypeObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFIntMimeTypeObj createMimeType( ICFIntMimeTypeObj Obj );

	/**
	 *	Read a MimeType-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The MimeType-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntMimeTypeObj readMimeType( CFIntMimeTypePKey pkey );

	/**
	 *	Read a MimeType-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The MimeType-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntMimeTypeObj readMimeType( CFIntMimeTypePKey pkey,
		boolean forceRead );

	ICFIntMimeTypeObj readCachedMimeType( CFIntMimeTypePKey pkey );

	public void reallyDeepDisposeMimeType( ICFIntMimeTypeObj obj );

	void deepDisposeMimeType( CFIntMimeTypePKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFIntMimeTypeObj lockMimeType( CFIntMimeTypePKey pkey );

	/**
	 *	Return a sorted list of all the MimeType-derived instances in the database.
	 *
	 *	@return	List of ICFIntMimeTypeObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntMimeTypeObj> readAllMimeType();

	/**
	 *	Return a sorted map of all the MimeType-derived instances in the database.
	 *
	 *	@return	List of ICFIntMimeTypeObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntMimeTypeObj> readAllMimeType( boolean forceRead );

	List<ICFIntMimeTypeObj> readCachedAllMimeType();

	/**
	 *	Get the CFIntMimeTypeObj instance for the primary key attributes.
	 *
	 *	@param	argMimeTypeId	The MimeType key attribute of the instance generating the id.
	 *
	 *	@return	CFIntMimeTypeObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntMimeTypeObj readMimeTypeByIdIdx( int MimeTypeId );

	/**
	 *	Get the CFIntMimeTypeObj instance for the primary key attributes.
	 *
	 *	@param	argMimeTypeId	The MimeType key attribute of the instance generating the id.
	 *
	 *	@return	CFIntMimeTypeObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntMimeTypeObj readMimeTypeByIdIdx( int MimeTypeId,
		boolean forceRead );

	/**
	 *	Get the CFIntMimeTypeObj instance for the unique UNameIdx key.
	 *
	 *	@param	argName	The MimeType key attribute of the instance generating the id.
	 *
	 *	@return	CFIntMimeTypeObj cached instance for the unique UNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntMimeTypeObj readMimeTypeByUNameIdx(String Name );

	/**
	 *	Get the CFIntMimeTypeObj instance for the unique UNameIdx key.
	 *
	 *	@param	argName	The MimeType key attribute of the instance generating the id.
	 *
	 *	@return	CFIntMimeTypeObj refreshed instance for the unique UNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntMimeTypeObj readMimeTypeByUNameIdx(String Name,
		boolean forceRead );

	ICFIntMimeTypeObj readCachedMimeTypeByIdIdx( int MimeTypeId );

	ICFIntMimeTypeObj readCachedMimeTypeByUNameIdx( String Name );

	void deepDisposeMimeTypeByIdIdx( int MimeTypeId );

	void deepDisposeMimeTypeByUNameIdx( String Name );

	/**
	 *	Internal use only.
	 */
	ICFIntMimeTypeObj updateMimeType( ICFIntMimeTypeObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteMimeType( ICFIntMimeTypeObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argMimeTypeId	The MimeType key attribute of the instance generating the id.
	 */
	void deleteMimeTypeByIdIdx( int MimeTypeId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argName	The MimeType key attribute of the instance generating the id.
	 */
	void deleteMimeTypeByUNameIdx(String Name );
}
