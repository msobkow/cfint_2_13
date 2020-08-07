
// Description: Java 11 in-memory RAM DbIO implementation for Tenant.

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

package org.msscf.msscf.cfint.CFIntRam;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfint.CFIntObj.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/*
 *	CFIntRamTenantTable in-memory RAM DbIO implementation
 *	for Tenant.
 */
public class CFIntRamTenantTable
	implements ICFIntTenantTable
{
	private ICFIntSchema schema;
	private Map< CFSecTenantPKey,
				CFSecTenantBuff > dictByPKey
		= new HashMap< CFSecTenantPKey,
				CFSecTenantBuff >();
	private Map< CFSecTenantByClusterIdxKey,
				Map< CFSecTenantPKey,
					CFSecTenantBuff >> dictByClusterIdx
		= new HashMap< CFSecTenantByClusterIdxKey,
				Map< CFSecTenantPKey,
					CFSecTenantBuff >>();
	private Map< CFSecTenantByUNameIdxKey,
			CFSecTenantBuff > dictByUNameIdx
		= new HashMap< CFSecTenantByUNameIdxKey,
			CFSecTenantBuff >();
	private Map< CFIntRamTenantId32Gen,
				CFIntRamTenantId32Gen > id32Generator
		= new HashMap< CFIntRamTenantId32Gen,
				CFIntRamTenantId32Gen >();
	private Map< CFIntRamTenantId64Gen,
				CFIntRamTenantId64Gen > id64Generator
		= new HashMap< CFIntRamTenantId64Gen,
				CFIntRamTenantId64Gen >();

	public CFIntRamTenantTable( ICFIntSchema argSchema ) {
		schema = argSchema;
	}

	protected int generateNextId32( long argId,
		short argSliceId )
	{
		CFIntRamTenantId32Gen key = new CFIntRamTenantId32Gen();
		key.setRequiredId( argId );
		key.setRequiredSliceId( argSliceId );

		CFIntRamTenantId32Gen useGen = id32Generator.get( key );
		if( useGen == null ) {
			id32Generator.put( key, key );
			useGen = key;
		}

		int retNext = useGen.getNextId();

		return( retNext );
	}

	protected long generateNextId64( long argId,
		short argSliceId )
	{
		CFIntRamTenantId64Gen key = new CFIntRamTenantId64Gen();
		key.setRequiredId( argId );
		key.setRequiredSliceId( argSliceId );

		CFIntRamTenantId64Gen useGen = id64Generator.get( key );
		if( useGen == null ) {
			id64Generator.put( key, key );
			useGen = key;
		}

		long retNext = useGen.getNextId();

		return( retNext );
	}

	public int nextTSecGroupIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey pkey )
	{
		int retval = nextTSecGroupIdGen( Authorization,
			pkey.getRequiredId() );
		return( retval );
	}

	public int nextTSecGroupIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		int retNext = generateNextId32( argId,
			(short)117 );
		return( retNext );
	}

	public long nextTSecGrpIncIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey pkey )
	{
		long retval = nextTSecGrpIncIdGen( Authorization,
			pkey.getRequiredId() );
		return( retval );
	}

	public long nextTSecGrpIncIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		long retNext = generateNextId64( argId,
			(short)119 );
		return( retNext );
	}

	public long nextTSecGrpMembIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey pkey )
	{
		long retval = nextTSecGrpMembIdGen( Authorization,
			pkey.getRequiredId() );
		return( retval );
	}

	public long nextTSecGrpMembIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		long retNext = generateNextId64( argId,
			(short)118 );
		return( retNext );
	}

	public long nextLicenseIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey pkey )
	{
		long retval = nextLicenseIdGen( Authorization,
			pkey.getRequiredId() );
		return( retval );
	}

	public long nextLicenseIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		long retNext = generateNextId64( argId,
			(short)207 );
		return( retNext );
	}

	public long nextMajorVersionIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey pkey )
	{
		long retval = nextMajorVersionIdGen( Authorization,
			pkey.getRequiredId() );
		return( retval );
	}

	public long nextMajorVersionIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		long retNext = generateNextId64( argId,
			(short)205 );
		return( retNext );
	}

	public long nextMinorVersionIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey pkey )
	{
		long retval = nextMinorVersionIdGen( Authorization,
			pkey.getRequiredId() );
		return( retval );
	}

	public long nextMinorVersionIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		long retNext = generateNextId64( argId,
			(short)206 );
		return( retNext );
	}

	public long nextSubProjectIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey pkey )
	{
		long retval = nextSubProjectIdGen( Authorization,
			pkey.getRequiredId() );
		return( retval );
	}

	public long nextSubProjectIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		long retNext = generateNextId64( argId,
			(short)204 );
		return( retNext );
	}

	public long nextTldIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey pkey )
	{
		long retval = nextTldIdGen( Authorization,
			pkey.getRequiredId() );
		return( retval );
	}

	public long nextTldIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		long retNext = generateNextId64( argId,
			(short)200 );
		return( retNext );
	}

	public long nextTopDomainIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey pkey )
	{
		long retval = nextTopDomainIdGen( Authorization,
			pkey.getRequiredId() );
		return( retval );
	}

	public long nextTopDomainIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		long retNext = generateNextId64( argId,
			(short)201 );
		return( retNext );
	}

	public long nextTopProjectIdGen( CFSecAuthorization Authorization,
		CFSecTenantPKey pkey )
	{
		long retval = nextTopProjectIdGen( Authorization,
			pkey.getRequiredId() );
		return( retval );
	}

	public long nextTopProjectIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		long retNext = generateNextId64( argId,
			(short)203 );
		return( retNext );
	}

	public void createTenant( CFSecAuthorization Authorization,
		CFSecTenantBuff Buff )
	{
		final String S_ProcName = "createTenant";
		CFSecTenantPKey pkey = schema.getFactoryTenant().newPKey();
		pkey.setRequiredId( schema.nextTenantIdGen() );
		Buff.setRequiredId( pkey.getRequiredId() );
		CFSecTenantByClusterIdxKey keyClusterIdx = schema.getFactoryTenant().newClusterIdxKey();
		keyClusterIdx.setRequiredClusterId( Buff.getRequiredClusterId() );

		CFSecTenantByUNameIdxKey keyUNameIdx = schema.getFactoryTenant().newUNameIdxKey();
		keyUNameIdx.setRequiredClusterId( Buff.getRequiredClusterId() );
		keyUNameIdx.setRequiredTenantName( Buff.getRequiredTenantName() );

		// Validate unique indexes

		if( dictByPKey.containsKey( pkey ) ) {
			throw new CFLibPrimaryKeyNotNewException( getClass(), S_ProcName, pkey );
		}

		if( dictByUNameIdx.containsKey( keyUNameIdx ) ) {
			throw new CFLibUniqueIndexViolationException( getClass(),
				S_ProcName,
				"TenantUNameIdx",
				keyUNameIdx );
		}

		// Validate foreign keys

		{
			boolean allNull = true;
			allNull = false;
			if( ! allNull ) {
				if( null == schema.getTableCluster().readDerivedByIdIdx( Authorization,
						Buff.getRequiredClusterId() ) )
				{
					throw new CFLibUnresolvedRelationException( getClass(),
						S_ProcName,
						"Container",
						"TenantCluster",
						"Cluster",
						null );
				}
			}
		}

		// Proceed with adding the new record

		dictByPKey.put( pkey, Buff );

		Map< CFSecTenantPKey, CFSecTenantBuff > subdictClusterIdx;
		if( dictByClusterIdx.containsKey( keyClusterIdx ) ) {
			subdictClusterIdx = dictByClusterIdx.get( keyClusterIdx );
		}
		else {
			subdictClusterIdx = new HashMap< CFSecTenantPKey, CFSecTenantBuff >();
			dictByClusterIdx.put( keyClusterIdx, subdictClusterIdx );
		}
		subdictClusterIdx.put( pkey, Buff );

		dictByUNameIdx.put( keyUNameIdx, Buff );

	}

	public CFSecTenantBuff readDerived( CFSecAuthorization Authorization,
		CFSecTenantPKey PKey )
	{
		final String S_ProcName = "CFIntRamTenant.readDerived";
		CFSecTenantPKey key = schema.getFactoryTenant().newPKey();
		key.setRequiredId( PKey.getRequiredId() );
		CFSecTenantBuff buff;
		if( dictByPKey.containsKey( key ) ) {
			buff = dictByPKey.get( key );
		}
		else {
			buff = null;
		}
		return( buff );
	}

	public CFSecTenantBuff lockDerived( CFSecAuthorization Authorization,
		CFSecTenantPKey PKey )
	{
		final String S_ProcName = "CFIntRamTenant.readDerived";
		CFSecTenantPKey key = schema.getFactoryTenant().newPKey();
		key.setRequiredId( PKey.getRequiredId() );
		CFSecTenantBuff buff;
		if( dictByPKey.containsKey( key ) ) {
			buff = dictByPKey.get( key );
		}
		else {
			buff = null;
		}
		return( buff );
	}

	public CFSecTenantBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "CFIntRamTenant.readAllDerived";
		CFSecTenantBuff[] retList = new CFSecTenantBuff[ dictByPKey.values().size() ];
		Iterator< CFSecTenantBuff > iter = dictByPKey.values().iterator();
		int idx = 0;
		while( iter.hasNext() ) {
			retList[ idx++ ] = iter.next();
		}
		return( retList );
	}

	public CFSecTenantBuff[] readDerivedByClusterIdx( CFSecAuthorization Authorization,
		long ClusterId )
	{
		final String S_ProcName = "CFIntRamTenant.readDerivedByClusterIdx";
		CFSecTenantByClusterIdxKey key = schema.getFactoryTenant().newClusterIdxKey();
		key.setRequiredClusterId( ClusterId );

		CFSecTenantBuff[] recArray;
		if( dictByClusterIdx.containsKey( key ) ) {
			Map< CFSecTenantPKey, CFSecTenantBuff > subdictClusterIdx
				= dictByClusterIdx.get( key );
			recArray = new CFSecTenantBuff[ subdictClusterIdx.size() ];
			Iterator< CFSecTenantBuff > iter = subdictClusterIdx.values().iterator();
			int idx = 0;
			while( iter.hasNext() ) {
				recArray[ idx++ ] = iter.next();
			}
		}
		else {
			Map< CFSecTenantPKey, CFSecTenantBuff > subdictClusterIdx
				= new HashMap< CFSecTenantPKey, CFSecTenantBuff >();
			dictByClusterIdx.put( key, subdictClusterIdx );
			recArray = new CFSecTenantBuff[0];
		}
		return( recArray );
	}

	public CFSecTenantBuff readDerivedByUNameIdx( CFSecAuthorization Authorization,
		long ClusterId,
		String TenantName )
	{
		final String S_ProcName = "CFIntRamTenant.readDerivedByUNameIdx";
		CFSecTenantByUNameIdxKey key = schema.getFactoryTenant().newUNameIdxKey();
		key.setRequiredClusterId( ClusterId );
		key.setRequiredTenantName( TenantName );

		CFSecTenantBuff buff;
		if( dictByUNameIdx.containsKey( key ) ) {
			buff = dictByUNameIdx.get( key );
		}
		else {
			buff = null;
		}
		return( buff );
	}

	public CFSecTenantBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		long Id )
	{
		final String S_ProcName = "CFIntRamTenant.readDerivedByIdIdx() ";
		CFSecTenantPKey key = schema.getFactoryTenant().newPKey();
		key.setRequiredId( Id );

		CFSecTenantBuff buff;
		if( dictByPKey.containsKey( key ) ) {
			buff = dictByPKey.get( key );
		}
		else {
			buff = null;
		}
		return( buff );
	}

	public CFSecTenantBuff readBuff( CFSecAuthorization Authorization,
		CFSecTenantPKey PKey )
	{
		final String S_ProcName = "CFIntRamTenant.readBuff";
		CFSecTenantBuff buff = readDerived( Authorization, PKey );
		if( ( buff != null ) && ( ! buff.getClassCode().equals( "a015" ) ) ) {
			buff = null;
		}
		return( buff );
	}

	public CFSecTenantBuff lockBuff( CFSecAuthorization Authorization,
		CFSecTenantPKey PKey )
	{
		final String S_ProcName = "lockBuff";
		CFSecTenantBuff buff = readDerived( Authorization, PKey );
		if( ( buff != null ) && ( ! buff.getClassCode().equals( "a015" ) ) ) {
			buff = null;
		}
		return( buff );
	}

	public CFSecTenantBuff[] readAllBuff( CFSecAuthorization Authorization )
	{
		final String S_ProcName = "CFIntRamTenant.readAllBuff";
		CFSecTenantBuff buff;
		ArrayList<CFSecTenantBuff> filteredList = new ArrayList<CFSecTenantBuff>();
		CFSecTenantBuff[] buffList = readAllDerived( Authorization );
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[idx];
			if( ( buff != null ) && buff.getClassCode().equals( "a015" ) ) {
				filteredList.add( buff );
			}
		}
		return( filteredList.toArray( new CFSecTenantBuff[0] ) );
	}

	/**
	 *	Read a page of all the specific Tenant buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific Tenant instances in the database accessible for the Authorization.
	 */
	public CFSecTenantBuff[] pageAllBuff( CFSecAuthorization Authorization,
		Long priorId )
	{
		final String S_ProcName = "pageAllBuff";
		throw new CFLibNotImplementedYetException( getClass(), S_ProcName );
	}

	public CFSecTenantBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		long Id )
	{
		final String S_ProcName = "CFIntRamTenant.readBuffByIdIdx() ";
		CFSecTenantBuff buff = readDerivedByIdIdx( Authorization,
			Id );
		if( ( buff != null ) && buff.getClassCode().equals( "a015" ) ) {
			return( (CFSecTenantBuff)buff );
		}
		else {
			return( null );
		}
	}

	public CFSecTenantBuff[] readBuffByClusterIdx( CFSecAuthorization Authorization,
		long ClusterId )
	{
		final String S_ProcName = "CFIntRamTenant.readBuffByClusterIdx() ";
		CFSecTenantBuff buff;
		ArrayList<CFSecTenantBuff> filteredList = new ArrayList<CFSecTenantBuff>();
		CFSecTenantBuff[] buffList = readDerivedByClusterIdx( Authorization,
			ClusterId );
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[idx];
			if( ( buff != null ) && buff.getClassCode().equals( "a015" ) ) {
				filteredList.add( (CFSecTenantBuff)buff );
			}
		}
		return( filteredList.toArray( new CFSecTenantBuff[0] ) );
	}

	public CFSecTenantBuff readBuffByUNameIdx( CFSecAuthorization Authorization,
		long ClusterId,
		String TenantName )
	{
		final String S_ProcName = "CFIntRamTenant.readBuffByUNameIdx() ";
		CFSecTenantBuff buff = readDerivedByUNameIdx( Authorization,
			ClusterId,
			TenantName );
		if( ( buff != null ) && buff.getClassCode().equals( "a015" ) ) {
			return( (CFSecTenantBuff)buff );
		}
		else {
			return( null );
		}
	}

	/**
	 *	Read a page array of the specific Tenant buffer instances identified by the duplicate key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The Tenant key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	public CFSecTenantBuff[] pageBuffByClusterIdx( CFSecAuthorization Authorization,
		long ClusterId,
		Long priorId )
	{
		final String S_ProcName = "pageBuffByClusterIdx";
		throw new CFLibNotImplementedYetException( getClass(), S_ProcName );
	}

	public void updateTenant( CFSecAuthorization Authorization,
		CFSecTenantBuff Buff )
	{
		CFSecTenantPKey pkey = schema.getFactoryTenant().newPKey();
		pkey.setRequiredId( Buff.getRequiredId() );
		CFSecTenantBuff existing = dictByPKey.get( pkey );
		if( existing == null ) {
			throw new CFLibStaleCacheDetectedException( getClass(),
				"updateTenant",
				"Existing record not found",
				"Tenant",
				pkey );
		}
		if( existing.getRequiredRevision() != Buff.getRequiredRevision() ) {
			throw new CFLibCollisionDetectedException( getClass(),
				"updateTenant",
				pkey );
		}
		Buff.setRequiredRevision( Buff.getRequiredRevision() + 1 );
		CFSecTenantByClusterIdxKey existingKeyClusterIdx = schema.getFactoryTenant().newClusterIdxKey();
		existingKeyClusterIdx.setRequiredClusterId( existing.getRequiredClusterId() );

		CFSecTenantByClusterIdxKey newKeyClusterIdx = schema.getFactoryTenant().newClusterIdxKey();
		newKeyClusterIdx.setRequiredClusterId( Buff.getRequiredClusterId() );

		CFSecTenantByUNameIdxKey existingKeyUNameIdx = schema.getFactoryTenant().newUNameIdxKey();
		existingKeyUNameIdx.setRequiredClusterId( existing.getRequiredClusterId() );
		existingKeyUNameIdx.setRequiredTenantName( existing.getRequiredTenantName() );

		CFSecTenantByUNameIdxKey newKeyUNameIdx = schema.getFactoryTenant().newUNameIdxKey();
		newKeyUNameIdx.setRequiredClusterId( Buff.getRequiredClusterId() );
		newKeyUNameIdx.setRequiredTenantName( Buff.getRequiredTenantName() );

		// Check unique indexes

		if( ! existingKeyUNameIdx.equals( newKeyUNameIdx ) ) {
			if( dictByUNameIdx.containsKey( newKeyUNameIdx ) ) {
				throw new CFLibUniqueIndexViolationException( getClass(),
					"updateTenant",
					"TenantUNameIdx",
					newKeyUNameIdx );
			}
		}

		// Validate foreign keys

		{
			boolean allNull = true;

			if( allNull ) {
				if( null == schema.getTableCluster().readDerivedByIdIdx( Authorization,
						Buff.getRequiredClusterId() ) )
				{
					throw new CFLibUnresolvedRelationException( getClass(),
						"updateTenant",
						"Container",
						"TenantCluster",
						"Cluster",
						null );
				}
			}
		}

		// Update is valid

		Map< CFSecTenantPKey, CFSecTenantBuff > subdict;

		dictByPKey.remove( pkey );
		dictByPKey.put( pkey, Buff );

		subdict = dictByClusterIdx.get( existingKeyClusterIdx );
		if( subdict != null ) {
			subdict.remove( pkey );
		}
		if( dictByClusterIdx.containsKey( newKeyClusterIdx ) ) {
			subdict = dictByClusterIdx.get( newKeyClusterIdx );
		}
		else {
			subdict = new HashMap< CFSecTenantPKey, CFSecTenantBuff >();
			dictByClusterIdx.put( newKeyClusterIdx, subdict );
		}
		subdict.put( pkey, Buff );

		dictByUNameIdx.remove( existingKeyUNameIdx );
		dictByUNameIdx.put( newKeyUNameIdx, Buff );

	}

	public void deleteTenant( CFSecAuthorization Authorization,
		CFSecTenantBuff Buff )
	{
		final String S_ProcName = "CFIntRamTenantTable.deleteTenant() ";
		String classCode;
		CFSecTenantPKey pkey = schema.getFactoryTenant().newPKey();
		pkey.setRequiredId( Buff.getRequiredId() );
		CFSecTenantBuff existing = dictByPKey.get( pkey );
		if( existing == null ) {
			return;
		}
		if( existing.getRequiredRevision() != Buff.getRequiredRevision() )
		{
			throw new CFLibCollisionDetectedException( getClass(),
				"deleteTenant",
				pkey );
		}
					schema.getTableTld().deleteTldByTenantIdx( Authorization,
						existing.getRequiredId() );
		CFSecTSecGroupBuff buffDelIncludedByGroup;
		CFSecTSecGroupBuff arrDelIncludedByGroup[] = schema.getTableTSecGroup().readDerivedByTenantIdx( Authorization,
			existing.getRequiredId() );
		for( int idxDelIncludedByGroup = 0; idxDelIncludedByGroup < arrDelIncludedByGroup.length; idxDelIncludedByGroup++ ) {
			buffDelIncludedByGroup = arrDelIncludedByGroup[idxDelIncludedByGroup];
					schema.getTableTSecGrpInc().deleteTSecGrpIncByIncludeIdx( Authorization,
						buffDelIncludedByGroup.getRequiredTenantId(),
						buffDelIncludedByGroup.getRequiredTSecGroupId() );
		}
		CFSecTSecGroupBuff buffDelGrpMembs;
		CFSecTSecGroupBuff arrDelGrpMembs[] = schema.getTableTSecGroup().readDerivedByTenantIdx( Authorization,
			existing.getRequiredId() );
		for( int idxDelGrpMembs = 0; idxDelGrpMembs < arrDelGrpMembs.length; idxDelGrpMembs++ ) {
			buffDelGrpMembs = arrDelGrpMembs[idxDelGrpMembs];
					schema.getTableTSecGrpMemb().deleteTSecGrpMembByGroupIdx( Authorization,
						buffDelGrpMembs.getRequiredTenantId(),
						buffDelGrpMembs.getRequiredTSecGroupId() );
		}
		CFSecTSecGroupBuff buffDelGrpIncs;
		CFSecTSecGroupBuff arrDelGrpIncs[] = schema.getTableTSecGroup().readDerivedByTenantIdx( Authorization,
			existing.getRequiredId() );
		for( int idxDelGrpIncs = 0; idxDelGrpIncs < arrDelGrpIncs.length; idxDelGrpIncs++ ) {
			buffDelGrpIncs = arrDelGrpIncs[idxDelGrpIncs];
					schema.getTableTSecGrpInc().deleteTSecGrpIncByGroupIdx( Authorization,
						buffDelGrpIncs.getRequiredTenantId(),
						buffDelGrpIncs.getRequiredTSecGroupId() );
		}
					schema.getTableTSecGroup().deleteTSecGroupByTenantIdx( Authorization,
						existing.getRequiredId() );
		CFSecTenantByClusterIdxKey keyClusterIdx = schema.getFactoryTenant().newClusterIdxKey();
		keyClusterIdx.setRequiredClusterId( existing.getRequiredClusterId() );

		CFSecTenantByUNameIdxKey keyUNameIdx = schema.getFactoryTenant().newUNameIdxKey();
		keyUNameIdx.setRequiredClusterId( existing.getRequiredClusterId() );
		keyUNameIdx.setRequiredTenantName( existing.getRequiredTenantName() );

		// Validate reverse foreign keys

		// Delete is valid
		Map< CFSecTenantPKey, CFSecTenantBuff > subdict;

		dictByPKey.remove( pkey );

		subdict = dictByClusterIdx.get( keyClusterIdx );
		subdict.remove( pkey );

		dictByUNameIdx.remove( keyUNameIdx );

	}
	public void deleteTenantByIdIdx( CFSecAuthorization Authorization,
		long argId )
	{
		CFSecTenantPKey key = schema.getFactoryTenant().newPKey();
		key.setRequiredId( argId );
		deleteTenantByIdIdx( Authorization, key );
	}

	public void deleteTenantByIdIdx( CFSecAuthorization Authorization,
		CFSecTenantPKey argKey )
	{
		boolean anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		CFSecTenantBuff cur;
		LinkedList<CFSecTenantBuff> matchSet = new LinkedList<CFSecTenantBuff>();
		Iterator<CFSecTenantBuff> values = dictByPKey.values().iterator();
		while( values.hasNext() ) {
			cur = values.next();
			if( argKey.equals( cur ) ) {
				matchSet.add( cur );
			}
		}
		Iterator<CFSecTenantBuff> iterMatch = matchSet.iterator();
		while( iterMatch.hasNext() ) {
			cur = iterMatch.next();
			cur = schema.getTableTenant().readDerivedByIdIdx( Authorization,
				cur.getRequiredId() );
			deleteTenant( Authorization, cur );
		}
	}

	public void deleteTenantByClusterIdx( CFSecAuthorization Authorization,
		long argClusterId )
	{
		CFSecTenantByClusterIdxKey key = schema.getFactoryTenant().newClusterIdxKey();
		key.setRequiredClusterId( argClusterId );
		deleteTenantByClusterIdx( Authorization, key );
	}

	public void deleteTenantByClusterIdx( CFSecAuthorization Authorization,
		CFSecTenantByClusterIdxKey argKey )
	{
		CFSecTenantBuff cur;
		boolean anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		LinkedList<CFSecTenantBuff> matchSet = new LinkedList<CFSecTenantBuff>();
		Iterator<CFSecTenantBuff> values = dictByPKey.values().iterator();
		while( values.hasNext() ) {
			cur = values.next();
			if( argKey.equals( cur ) ) {
				matchSet.add( cur );
			}
		}
		Iterator<CFSecTenantBuff> iterMatch = matchSet.iterator();
		while( iterMatch.hasNext() ) {
			cur = iterMatch.next();
			cur = schema.getTableTenant().readDerivedByIdIdx( Authorization,
				cur.getRequiredId() );
			deleteTenant( Authorization, cur );
		}
	}

	public void deleteTenantByUNameIdx( CFSecAuthorization Authorization,
		long argClusterId,
		String argTenantName )
	{
		CFSecTenantByUNameIdxKey key = schema.getFactoryTenant().newUNameIdxKey();
		key.setRequiredClusterId( argClusterId );
		key.setRequiredTenantName( argTenantName );
		deleteTenantByUNameIdx( Authorization, key );
	}

	public void deleteTenantByUNameIdx( CFSecAuthorization Authorization,
		CFSecTenantByUNameIdxKey argKey )
	{
		CFSecTenantBuff cur;
		boolean anyNotNull = false;
		anyNotNull = true;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		LinkedList<CFSecTenantBuff> matchSet = new LinkedList<CFSecTenantBuff>();
		Iterator<CFSecTenantBuff> values = dictByPKey.values().iterator();
		while( values.hasNext() ) {
			cur = values.next();
			if( argKey.equals( cur ) ) {
				matchSet.add( cur );
			}
		}
		Iterator<CFSecTenantBuff> iterMatch = matchSet.iterator();
		while( iterMatch.hasNext() ) {
			cur = iterMatch.next();
			cur = schema.getTableTenant().readDerivedByIdIdx( Authorization,
				cur.getRequiredId() );
			deleteTenant( Authorization, cur );
		}
	}

	public void releasePreparedStatements() {
	}
}