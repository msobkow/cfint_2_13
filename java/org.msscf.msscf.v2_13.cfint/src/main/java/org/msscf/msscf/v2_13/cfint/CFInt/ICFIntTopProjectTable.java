
// Description: Java 11 DbIO interface for TopProject.

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

package org.msscf.msscf.v2_13.cfint.CFInt;

import java.lang.reflect.*;
import java.net.*;
import java.rmi.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;
import org.msscf.msscf.v2_13.cfsec.CFSecObj.*;
import org.msscf.msscf.v2_13.cfint.CFIntObj.*;

/*
 *	CFIntTopProjectTable database interface for TopProject
 */
public interface ICFIntTopProjectTable
{

	/**
	 *	Create the instance in the database, and update the specified buffer
	 *	with the assigned primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be created.
	 */
	void createTopProject( CFSecAuthorization Authorization,
		CFIntTopProjectBuff Buff );


	/**
	 *	Update the instance in the database, and update the specified buffer
	 *	with any calculated changes imposed by the associated stored procedure.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be updated.
	 */
	void updateTopProject( CFSecAuthorization Authorization,
		CFIntTopProjectBuff Buff );


	/**
	 *	Delete the instance from the database.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	Buff	The buffer to be deleted.
	 */
	void deleteTopProject( CFSecAuthorization Authorization,
		CFIntTopProjectBuff Buff );
	/**
	 *	Delete the TopProject instance identified by the primary key attributes.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argId	The TopProject key attribute of the instance generating the id.
	 */
	void deleteTopProjectByIdIdx( CFSecAuthorization Authorization,
		long argTenantId,
		long argId );

	/**
	 *	Delete the TopProject instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The primary key identifying the instance to be deleted.
	 */
	void deleteTopProjectByIdIdx( CFSecAuthorization Authorization,
		CFIntTopProjectPKey argKey );
	/**
	 *	Delete the TopProject instances identified by the key TenantIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 */
	void deleteTopProjectByTenantIdx( CFSecAuthorization Authorization,
		long argTenantId );

	/**
	 *	Delete the TopProject instances identified by the key TenantIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteTopProjectByTenantIdx( CFSecAuthorization Authorization,
		CFIntTopProjectByTenantIdxKey argKey );
	/**
	 *	Delete the TopProject instances identified by the key TopDomainIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 */
	void deleteTopProjectByTopDomainIdx( CFSecAuthorization Authorization,
		long argTenantId,
		long argTopDomainId );

	/**
	 *	Delete the TopProject instances identified by the key TopDomainIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteTopProjectByTopDomainIdx( CFSecAuthorization Authorization,
		CFIntTopProjectByTopDomainIdxKey argKey );
	/**
	 *	Delete the TopProject instances identified by the key NameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argName	The TopProject key attribute of the instance generating the id.
	 */
	void deleteTopProjectByNameIdx( CFSecAuthorization Authorization,
		long argTenantId,
		long argTopDomainId,
		String argName );

	/**
	 *	Delete the TopProject instances identified by the key NameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argKey	The key identifying the instances to be deleted.
	 */
	void deleteTopProjectByNameIdx( CFSecAuthorization Authorization,
		CFIntTopProjectByNameIdxKey argKey );


	/**
	 *	Read the derived TopProject buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the TopProject instance to be read.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFIntTopProjectBuff readDerived( CFSecAuthorization Authorization,
		CFIntTopProjectPKey PKey );

	/**
	 *	Lock the derived TopProject buffer instance by primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the TopProject instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 */
	CFIntTopProjectBuff lockDerived( CFSecAuthorization Authorization,
		CFIntTopProjectPKey PKey );

	/**
	 *	Read all TopProject instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return An array of derived buffer instances, potentially with 0 elements in the set.
	 */
	CFIntTopProjectBuff[] readAllDerived( CFSecAuthorization Authorization );

	/**
	 *	Read the derived TopProject buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFIntTopProjectBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		long TenantId,
		long Id );

	/**
	 *	Read an array of the derived TopProject buffer instances identified by the duplicate key TenantIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFIntTopProjectBuff[] readDerivedByTenantIdx( CFSecAuthorization Authorization,
		long TenantId );

	/**
	 *	Read an array of the derived TopProject buffer instances identified by the duplicate key TopDomainIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 */
	CFIntTopProjectBuff[] readDerivedByTopDomainIdx( CFSecAuthorization Authorization,
		long TenantId,
		long TopDomainId );

	/**
	 *	Read the derived TopProject buffer instance identified by the unique key NameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argName	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 */
	CFIntTopProjectBuff readDerivedByNameIdx( CFSecAuthorization Authorization,
		long TenantId,
		long TopDomainId,
		String Name );

	/**
	 *	Read the specific TopProject buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the TopProject instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFIntTopProjectBuff readBuff( CFSecAuthorization Authorization,
		CFIntTopProjectPKey PKey );

	/**
	 *	Lock the specific TopProject buffer instance identified by the primary key.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	PKey	The primary key of the TopProject instance to be locked.
	 *
	 *	@return The buffer instance for the specified primary key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFIntTopProjectBuff lockBuff( CFSecAuthorization Authorization,
		CFIntTopProjectPKey PKey );

	/**
	 *	Read all the specific TopProject buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific TopProject instances in the database accessible for the Authorization.
	 */
	CFIntTopProjectBuff[] readAllBuff( CFSecAuthorization Authorization );

	/**
	 *	Read the specific TopProject buffer instance identified by the unique key IdIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFIntTopProjectBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		long TenantId,
		long Id );

	/**
	 *	Read an array of the specific TopProject buffer instances identified by the duplicate key TenantIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFIntTopProjectBuff[] readBuffByTenantIdx( CFSecAuthorization Authorization,
		long TenantId );

	/**
	 *	Read an array of the specific TopProject buffer instances identified by the duplicate key TopDomainIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFIntTopProjectBuff[] readBuffByTopDomainIdx( CFSecAuthorization Authorization,
		long TenantId,
		long TopDomainId );

	/**
	 *	Read the specific TopProject buffer instance identified by the unique key NameIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argTenantId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argTopDomainId	The TopProject key attribute of the instance generating the id.
	 *
	 *	@param	argName	The TopProject key attribute of the instance generating the id.
	 *
	 *	@return The buffer instance for the specified key, or null if there is
	 *		no such existing key value.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	CFIntTopProjectBuff readBuffByNameIdx( CFSecAuthorization Authorization,
		long TenantId,
		long TopDomainId,
		String Name );

	/**
	 *	Release any prepared statements allocated by this instance.
	 *
	 *	@throws CFLibNotSupportedException thrown by client-side implementations.
	 */
	void releasePreparedStatements();
}
