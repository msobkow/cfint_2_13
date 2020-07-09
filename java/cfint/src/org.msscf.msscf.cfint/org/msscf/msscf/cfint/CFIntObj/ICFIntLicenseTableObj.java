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
import com.github.msobkow.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFInt.*;

public interface ICFIntLicenseTableObj
{
	ICFIntSchemaObj getSchema();
	void setSchema( ICFIntSchemaObj value );

	void minimizeMemory();

	String getTableName();
	String getTableDbName();

	Class getObjQualifyingClass();

	/**
	 *	Instantiate a new License instance.
	 *
	 *	@return	A new instance.
	 */
	ICFIntLicenseObj newInstance();

	/**
	 *	Instantiate a new License edition of the specified License instance.
	 *
	 *	@return	A new edition.
	 */
	ICFIntLicenseEditObj newEditInstance( ICFIntLicenseObj orig );

	/**
	 *	Internal use only.
	 */
	ICFIntLicenseObj realiseLicense( ICFIntLicenseObj Obj );

	/**
	 *	Internal use only.
	 */
	ICFIntLicenseObj createLicense( ICFIntLicenseObj Obj );

	/**
	 *	Read a License-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The License-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntLicenseObj readLicense( CFIntLicensePKey pkey );

	/**
	 *	Read a License-derived instance by it's primary key.
	 *
	 *	@param	pkey	The primary key identifying the instance to read.
	 *
	 *	@return	The License-derived instance identified by the primary key,
	 *		or null if no such key value exists.
	 */
	ICFIntLicenseObj readLicense( CFIntLicensePKey pkey,
		boolean forceRead );

	ICFIntLicenseObj readCachedLicense( CFIntLicensePKey pkey );

	public void reallyDeepDisposeLicense( ICFIntLicenseObj obj );

	void deepDisposeLicense( CFIntLicensePKey pkey );

	/**
	 *	Internal use only.
	 */
	ICFIntLicenseObj lockLicense( CFIntLicensePKey pkey );

	/**
	 *	Return a sorted list of all the License-derived instances in the database.
	 *
	 *	@return	List of ICFIntLicenseObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntLicenseObj> readAllLicense();

	/**
	 *	Return a sorted map of all the License-derived instances in the database.
	 *
	 *	@return	List of ICFIntLicenseObj instance, sorted by their primary keys, which
	 *		may include an empty set.
	 */
	List<ICFIntLicenseObj> readAllLicense( boolean forceRead );

	List<ICFIntLicenseObj> readCachedAllLicense();

	/**
	 *	Get the CFIntLicenseObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argId	The License key attribute of the instance generating the id.
	 *
	 *	@return	CFIntLicenseObj cached instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntLicenseObj readLicenseByIdIdx( long TenantId,
		long Id );

	/**
	 *	Get the CFIntLicenseObj instance for the primary key attributes.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argId	The License key attribute of the instance generating the id.
	 *
	 *	@return	CFIntLicenseObj refreshed instance for the primary key, or
	 *		null if no such instance exists.
	 */
	ICFIntLicenseObj readLicenseByIdIdx( long TenantId,
		long Id,
		boolean forceRead );

	/**
	 *	Get the map of CFIntLicenseObj instances sorted by their primary keys for the duplicate LicnTenantIdx key.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntLicenseObj cached instances sorted by their primary keys for the duplicate LicnTenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntLicenseObj> readLicenseByLicnTenantIdx( long TenantId );

	/**
	 *	Get the map of CFIntLicenseObj instances sorted by their primary keys for the duplicate LicnTenantIdx key.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntLicenseObj cached instances sorted by their primary keys for the duplicate LicnTenantIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntLicenseObj> readLicenseByLicnTenantIdx( long TenantId,
		boolean forceRead );

	/**
	 *	Get the map of CFIntLicenseObj instances sorted by their primary keys for the duplicate DomainIdx key.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The License key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntLicenseObj cached instances sorted by their primary keys for the duplicate DomainIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntLicenseObj> readLicenseByDomainIdx( long TenantId,
		long TopDomainId );

	/**
	 *	Get the map of CFIntLicenseObj instances sorted by their primary keys for the duplicate DomainIdx key.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The License key attribute of the instance generating the id.
	 *
	 *	@return	List of CFIntLicenseObj cached instances sorted by their primary keys for the duplicate DomainIdx key,
	 *		which may be an empty set.
	 */
	List<ICFIntLicenseObj> readLicenseByDomainIdx( long TenantId,
		long TopDomainId,
		boolean forceRead );

	/**
	 *	Get the CFIntLicenseObj instance for the unique UNameIdx key.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argName	The License key attribute of the instance generating the id.
	 *
	 *	@return	CFIntLicenseObj cached instance for the unique UNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntLicenseObj readLicenseByUNameIdx(long TenantId,
		long TopDomainId,
		String Name );

	/**
	 *	Get the CFIntLicenseObj instance for the unique UNameIdx key.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argName	The License key attribute of the instance generating the id.
	 *
	 *	@return	CFIntLicenseObj refreshed instance for the unique UNameIdx key, or
	 *		null if no such instance exists.
	 */
	ICFIntLicenseObj readLicenseByUNameIdx(long TenantId,
		long TopDomainId,
		String Name,
		boolean forceRead );

	ICFIntLicenseObj readCachedLicenseByIdIdx( long TenantId,
		long Id );

	List<ICFIntLicenseObj> readCachedLicenseByLicnTenantIdx( long TenantId );

	List<ICFIntLicenseObj> readCachedLicenseByDomainIdx( long TenantId,
		long TopDomainId );

	ICFIntLicenseObj readCachedLicenseByUNameIdx( long TenantId,
		long TopDomainId,
		String Name );

	void deepDisposeLicenseByIdIdx( long TenantId,
		long Id );

	void deepDisposeLicenseByLicnTenantIdx( long TenantId );

	void deepDisposeLicenseByDomainIdx( long TenantId,
		long TopDomainId );

	void deepDisposeLicenseByUNameIdx( long TenantId,
		long TopDomainId,
		String Name );

	/**
	 *	Internal use only.
	 */
	ICFIntLicenseObj updateLicense( ICFIntLicenseObj Obj );

	/**
	 *	Internal use only.
	 */
	void deleteLicense( ICFIntLicenseObj Obj );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argId	The License key attribute of the instance generating the id.
	 */
	void deleteLicenseByIdIdx( long TenantId,
		long Id );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 */
	void deleteLicenseByLicnTenantIdx( long TenantId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The License key attribute of the instance generating the id.
	 */
	void deleteLicenseByDomainIdx( long TenantId,
		long TopDomainId );

	/**
	 *	Internal use only.
	 *
	 *	@param	argTenantId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The License key attribute of the instance generating the id.
	 *
	 *	@param	argName	The License key attribute of the instance generating the id.
	 */
	void deleteLicenseByUNameIdx(long TenantId,
		long TopDomainId,
		String Name );
}
