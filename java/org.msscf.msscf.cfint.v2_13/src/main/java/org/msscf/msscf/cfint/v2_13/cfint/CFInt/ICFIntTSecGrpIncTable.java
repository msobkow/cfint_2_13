
// Description: Java 11 DbIO interface for TSecGrpInc.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
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

package org.msscf.msscf.cfint.v2_13.cfint.CFInt;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/*
 *	CFIntTSecGrpIncTable database interface for TSecGrpInc
 */
public interface ICFIntTSecGrpIncTable
extends ICFSecTSecGrpIncTable
{

	/**
	 *	Create the instance in the database, and update the specified buffer
	 *	with the assigned primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be created.
	 */
	void createTSecGrpInc( CFSecAuthorization Authorization,
		CFSecTSecGrpIncBuff Buff );


	/**
	 *	Update the instance in the database, and update the specified buffer
	 *	with any calculated changes imposed by the associated stored procedure.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be updated.
	 */
	void updateTSecGrpInc( CFSecAuthorization Authorization,
		CFSecTSecGrpIncBuff Buff );


	/**
	 *	Delete the instance from the database.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be deleted.
	 */
	void deleteTSecGrpInc( CFSecAuthorization Authorization,
		CFSecTSecGrpIncBuff Buff );
	/**
	 *	Delete the TSecGrpInc instance identified by the primary key attributes.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argTSecGrpIncId	The TSecGrpInc key attribute of the instance generating the id.
	 */
	void deleteTSecGrpIncByIdIdx( CFSecAuthorization Authorization,
		long argTenantId,
		long argTSecGrpIncId );

	/**
	 *	Delete the TSecGrpInc instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The primary key identifying the instance to be deleted.
	 */
	void deleteTSecGrpIncByIdIdx( CFSecAuthorization Authorization,
		CFSecTSecGrpIncPKey argKey );
	/**
	 *	Delete the TSecGrpInc instances identified by the key TenantIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 */
	void deleteTSecGrpIncByTenantIdx( CFSecAuthorization Authorization,
		long argTenantId );

	/**
	 *	Delete the TSecGrpInc instances identified by the key TenantIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteTSecGrpIncByTenantIdx( CFSecAuthorization Authorization,
		CFSecTSecGrpIncByTenantIdxKey argKey );
	/**
	 *	Delete the TSecGrpInc instances identified by the key GroupIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argTSecGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 */
	void deleteTSecGrpIncByGroupIdx( CFSecAuthorization Authorization,
		long argTenantId,
		int argTSecGroupId );

	/**
	 *	Delete the TSecGrpInc instances identified by the key GroupIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteTSecGrpIncByGroupIdx( CFSecAuthorization Authorization,
		CFSecTSecGrpIncByGroupIdxKey argKey );
	/**
	 *	Delete the TSecGrpInc instances identified by the key IncludeIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argIncludeGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 */
	void deleteTSecGrpIncByIncludeIdx( CFSecAuthorization Authorization,
		long argTenantId,
		int argIncludeGroupId );

	/**
	 *	Delete the TSecGrpInc instances identified by the key IncludeIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteTSecGrpIncByIncludeIdx( CFSecAuthorization Authorization,
		CFSecTSecGrpIncByIncludeIdxKey argKey );
	/**
	 *	Delete the TSecGrpInc instances identified by the key UIncludeIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argTSecGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argIncludeGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 */
	void deleteTSecGrpIncByUIncludeIdx( CFSecAuthorization Authorization,
		long argTenantId,
		int argTSecGroupId,
		int argIncludeGroupId );

	/**
	 *	Delete the TSecGrpInc instances identified by the key UIncludeIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteTSecGrpIncByUIncludeIdx( CFSecAuthorization Authorization,
		CFSecTSecGrpIncByUIncludeIdxKey argKey );


	/**
	 *	Read the derived TSecGrpInc buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the TSecGrpInc instance to be read.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecTSecGrpIncBuff readDerived( CFSecAuthorization Authorization,
		CFSecTSecGrpIncPKey PKey );

	/**
	 *	Lock the derived TSecGrpInc buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the TSecGrpInc instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFSecTSecGrpIncBuff lockDerived( CFSecAuthorization Authorization,
		CFSecTSecGrpIncPKey PKey );

	/**
	 *	Read all TSecGrpInc instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return An array of derived buffer instances, potentially with 0 elements in the set.
	 */
	CFSecTSecGrpIncBuff[] readAllDerived( CFSecAuthorization Authorization );

	/**
	 *	Read the derived TSecGrpInc buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argTSecGrpIncId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFSecTSecGrpIncBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		long TenantId,
		long TSecGrpIncId );

	/**
	 *	Read an array of the derived TSecGrpInc buffer instances identified by the duplicate key TenantIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFSecTSecGrpIncBuff[] readDerivedByTenantIdx( CFSecAuthorization Authorization,
		long TenantId );

	/**
	 *	Read an array of the derived TSecGrpInc buffer instances identified by the duplicate key GroupIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argTSecGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFSecTSecGrpIncBuff[] readDerivedByGroupIdx( CFSecAuthorization Authorization,
		long TenantId,
		int TSecGroupId );

	/**
	 *	Read an array of the derived TSecGrpInc buffer instances identified by the duplicate key IncludeIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argIncludeGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFSecTSecGrpIncBuff[] readDerivedByIncludeIdx( CFSecAuthorization Authorization,
		long TenantId,
		int IncludeGroupId );

	/**
	 *	Read the derived TSecGrpInc buffer instance identified by the unique key UIncludeIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argTSecGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argIncludeGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFSecTSecGrpIncBuff readDerivedByUIncludeIdx( CFSecAuthorization Authorization,
		long TenantId,
		int TSecGroupId,
		int IncludeGroupId );

	/**
	 *	Read the specific TSecGrpInc buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the TSecGrpInc instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTSecGrpIncBuff readBuff( CFSecAuthorization Authorization,
		CFSecTSecGrpIncPKey PKey );

	/**
	 *	Lock the specific TSecGrpInc buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the TSecGrpInc instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTSecGrpIncBuff lockBuff( CFSecAuthorization Authorization,
		CFSecTSecGrpIncPKey PKey );

	/**
	 *	Read all the specific TSecGrpInc buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific TSecGrpInc instances in the database accessible for the Authorization.
	 */
	CFSecTSecGrpIncBuff[] readAllBuff( CFSecAuthorization Authorization );

	/**
	 *	Read a page of all the specific TSecGrpInc buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific TSecGrpInc instances in the database accessible for the Authorization.
	 */
	CFSecTSecGrpIncBuff[] pageAllBuff( CFSecAuthorization Authorization,
		Long priorTenantId,
		Long priorTSecGrpIncId );

	/**
	 *	Read the specific TSecGrpInc buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argTSecGrpIncId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTSecGrpIncBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		long TenantId,
		long TSecGrpIncId );

	/**
	 *	Read an array of the specific TSecGrpInc buffer instances identified by the duplicate key TenantIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTSecGrpIncBuff[] readBuffByTenantIdx( CFSecAuthorization Authorization,
		long TenantId );

	/**
	 *	Read an array of the specific TSecGrpInc buffer instances identified by the duplicate key GroupIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argTSecGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTSecGrpIncBuff[] readBuffByGroupIdx( CFSecAuthorization Authorization,
		long TenantId,
		int TSecGroupId );

	/**
	 *	Read an array of the specific TSecGrpInc buffer instances identified by the duplicate key IncludeIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argIncludeGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTSecGrpIncBuff[] readBuffByIncludeIdx( CFSecAuthorization Authorization,
		long TenantId,
		int IncludeGroupId );

	/**
	 *	Read the specific TSecGrpInc buffer instance identified by the unique key UIncludeIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argTSecGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argIncludeGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTSecGrpIncBuff readBuffByUIncludeIdx( CFSecAuthorization Authorization,
		long TenantId,
		int TSecGroupId,
		int IncludeGroupId );

	/**
	 *	Read a page array of the specific TSecGrpInc buffer instances identified by the duplicate key TenantIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTSecGrpIncBuff[] pageBuffByTenantIdx( CFSecAuthorization Authorization,
		long TenantId,
		Long priorTenantId,
		Long priorTSecGrpIncId );

	/**
	 *	Read a page array of the specific TSecGrpInc buffer instances identified by the duplicate key GroupIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argTSecGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTSecGrpIncBuff[] pageBuffByGroupIdx( CFSecAuthorization Authorization,
		long TenantId,
		int TSecGroupId,
		Long priorTenantId,
		Long priorTSecGrpIncId );

	/**
	 *	Read a page array of the specific TSecGrpInc buffer instances identified by the duplicate key IncludeIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@param	argIncludeGroupId	The TSecGrpInc key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFSecTSecGrpIncBuff[] pageBuffByIncludeIdx( CFSecAuthorization Authorization,
		long TenantId,
		int IncludeGroupId,
		Long priorTenantId,
		Long priorTSecGrpIncId );

	/**
	 *	Release any prepared statements allocated by this instance.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 */
	void releasePreparedStatements();
}
