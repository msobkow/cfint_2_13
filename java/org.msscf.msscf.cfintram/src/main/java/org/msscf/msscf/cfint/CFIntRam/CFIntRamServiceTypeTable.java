
// Description: Java 11 in-memory RAM DbIO implementation for ServiceType.

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
 *	CFIntRamServiceTypeTable in-memory RAM DbIO implementation
 *	for ServiceType.
 */
public class CFIntRamServiceTypeTable
	implements ICFIntServiceTypeTable
{
	private ICFIntSchema schema;
	private Map< CFSecServiceTypePKey,
				CFSecServiceTypeBuff > dictByPKey
		= new HashMap< CFSecServiceTypePKey,
				CFSecServiceTypeBuff >();
	private Map< CFSecServiceTypeByUDescrIdxKey,
			CFSecServiceTypeBuff > dictByUDescrIdx
		= new HashMap< CFSecServiceTypeByUDescrIdxKey,
			CFSecServiceTypeBuff >();

	public CFIntRamServiceTypeTable( ICFIntSchema argSchema ) {
		schema = argSchema;
	}

	public void createServiceType( CFSecAuthorization Authorization,
		CFSecServiceTypeBuff Buff )
	{
		final String S_ProcName = "createServiceType";
		CFSecServiceTypePKey pkey = schema.getFactoryServiceType().newPKey();
		pkey.setRequiredServiceTypeId( schema.nextServiceTypeIdGen() );
		Buff.setRequiredServiceTypeId( pkey.getRequiredServiceTypeId() );
		CFSecServiceTypeByUDescrIdxKey keyUDescrIdx = schema.getFactoryServiceType().newUDescrIdxKey();
		keyUDescrIdx.setRequiredDescription( Buff.getRequiredDescription() );

		// Validate unique indexes

		if( dictByPKey.containsKey( pkey ) ) {
			throw new CFLibPrimaryKeyNotNewException( getClass(), S_ProcName, pkey );
		}

		if( dictByUDescrIdx.containsKey( keyUDescrIdx ) ) {
			throw new CFLibUniqueIndexViolationException( getClass(),
				S_ProcName,
				"ServiceTypeUDescrIdx",
				keyUDescrIdx );
		}

		// Validate foreign keys

		// Proceed with adding the new record

		dictByPKey.put( pkey, Buff );

		dictByUDescrIdx.put( keyUDescrIdx, Buff );

	}

	public CFSecServiceTypeBuff readDerived( CFSecAuthorization Authorization,
		CFSecServiceTypePKey PKey )
	{
		final String S_ProcName = "CFIntRamServiceType.readDerived";
		CFSecServiceTypePKey key = schema.getFactoryServiceType().newPKey();
		key.setRequiredServiceTypeId( PKey.getRequiredServiceTypeId() );
		CFSecServiceTypeBuff buff;
		if( dictByPKey.containsKey( key ) ) {
			buff = dictByPKey.get( key );
		}
		else {
			buff = null;
		}
		return( buff );
	}

	public CFSecServiceTypeBuff lockDerived( CFSecAuthorization Authorization,
		CFSecServiceTypePKey PKey )
	{
		final String S_ProcName = "CFIntRamServiceType.readDerived";
		CFSecServiceTypePKey key = schema.getFactoryServiceType().newPKey();
		key.setRequiredServiceTypeId( PKey.getRequiredServiceTypeId() );
		CFSecServiceTypeBuff buff;
		if( dictByPKey.containsKey( key ) ) {
			buff = dictByPKey.get( key );
		}
		else {
			buff = null;
		}
		return( buff );
	}

	public CFSecServiceTypeBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "CFIntRamServiceType.readAllDerived";
		CFSecServiceTypeBuff[] retList = new CFSecServiceTypeBuff[ dictByPKey.values().size() ];
		Iterator< CFSecServiceTypeBuff > iter = dictByPKey.values().iterator();
		int idx = 0;
		while( iter.hasNext() ) {
			retList[ idx++ ] = iter.next();
		}
		return( retList );
	}

	public CFSecServiceTypeBuff readDerivedByUDescrIdx( CFSecAuthorization Authorization,
		String Description )
	{
		final String S_ProcName = "CFIntRamServiceType.readDerivedByUDescrIdx";
		CFSecServiceTypeByUDescrIdxKey key = schema.getFactoryServiceType().newUDescrIdxKey();
		key.setRequiredDescription( Description );

		CFSecServiceTypeBuff buff;
		if( dictByUDescrIdx.containsKey( key ) ) {
			buff = dictByUDescrIdx.get( key );
		}
		else {
			buff = null;
		}
		return( buff );
	}

	public CFSecServiceTypeBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		int ServiceTypeId )
	{
		final String S_ProcName = "CFIntRamServiceType.readDerivedByIdIdx() ";
		CFSecServiceTypePKey key = schema.getFactoryServiceType().newPKey();
		key.setRequiredServiceTypeId( ServiceTypeId );

		CFSecServiceTypeBuff buff;
		if( dictByPKey.containsKey( key ) ) {
			buff = dictByPKey.get( key );
		}
		else {
			buff = null;
		}
		return( buff );
	}

	public CFSecServiceTypeBuff readBuff( CFSecAuthorization Authorization,
		CFSecServiceTypePKey PKey )
	{
		final String S_ProcName = "CFIntRamServiceType.readBuff";
		CFSecServiceTypeBuff buff = readDerived( Authorization, PKey );
		if( ( buff != null ) && ( ! buff.getClassCode().equals( "a013" ) ) ) {
			buff = null;
		}
		return( buff );
	}

	public CFSecServiceTypeBuff lockBuff( CFSecAuthorization Authorization,
		CFSecServiceTypePKey PKey )
	{
		final String S_ProcName = "lockBuff";
		CFSecServiceTypeBuff buff = readDerived( Authorization, PKey );
		if( ( buff != null ) && ( ! buff.getClassCode().equals( "a013" ) ) ) {
			buff = null;
		}
		return( buff );
	}

	public CFSecServiceTypeBuff[] readAllBuff( CFSecAuthorization Authorization )
	{
		final String S_ProcName = "CFIntRamServiceType.readAllBuff";
		CFSecServiceTypeBuff buff;
		ArrayList<CFSecServiceTypeBuff> filteredList = new ArrayList<CFSecServiceTypeBuff>();
		CFSecServiceTypeBuff[] buffList = readAllDerived( Authorization );
		for( int idx = 0; idx < buffList.length; idx ++ ) {
			buff = buffList[idx];
			if( ( buff != null ) && buff.getClassCode().equals( "a013" ) ) {
				filteredList.add( buff );
			}
		}
		return( filteredList.toArray( new CFSecServiceTypeBuff[0] ) );
	}

	public CFSecServiceTypeBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		int ServiceTypeId )
	{
		final String S_ProcName = "CFIntRamServiceType.readBuffByIdIdx() ";
		CFSecServiceTypeBuff buff = readDerivedByIdIdx( Authorization,
			ServiceTypeId );
		if( ( buff != null ) && buff.getClassCode().equals( "a013" ) ) {
			return( (CFSecServiceTypeBuff)buff );
		}
		else {
			return( null );
		}
	}

	public CFSecServiceTypeBuff readBuffByUDescrIdx( CFSecAuthorization Authorization,
		String Description )
	{
		final String S_ProcName = "CFIntRamServiceType.readBuffByUDescrIdx() ";
		CFSecServiceTypeBuff buff = readDerivedByUDescrIdx( Authorization,
			Description );
		if( ( buff != null ) && buff.getClassCode().equals( "a013" ) ) {
			return( (CFSecServiceTypeBuff)buff );
		}
		else {
			return( null );
		}
	}

	public void updateServiceType( CFSecAuthorization Authorization,
		CFSecServiceTypeBuff Buff )
	{
		CFSecServiceTypePKey pkey = schema.getFactoryServiceType().newPKey();
		pkey.setRequiredServiceTypeId( Buff.getRequiredServiceTypeId() );
		CFSecServiceTypeBuff existing = dictByPKey.get( pkey );
		if( existing == null ) {
			throw new CFLibStaleCacheDetectedException( getClass(),
				"updateServiceType",
				"Existing record not found",
				"ServiceType",
				pkey );
		}
		if( existing.getRequiredRevision() != Buff.getRequiredRevision() ) {
			throw new CFLibCollisionDetectedException( getClass(),
				"updateServiceType",
				pkey );
		}
		Buff.setRequiredRevision( Buff.getRequiredRevision() + 1 );
		CFSecServiceTypeByUDescrIdxKey existingKeyUDescrIdx = schema.getFactoryServiceType().newUDescrIdxKey();
		existingKeyUDescrIdx.setRequiredDescription( existing.getRequiredDescription() );

		CFSecServiceTypeByUDescrIdxKey newKeyUDescrIdx = schema.getFactoryServiceType().newUDescrIdxKey();
		newKeyUDescrIdx.setRequiredDescription( Buff.getRequiredDescription() );

		// Check unique indexes

		if( ! existingKeyUDescrIdx.equals( newKeyUDescrIdx ) ) {
			if( dictByUDescrIdx.containsKey( newKeyUDescrIdx ) ) {
				throw new CFLibUniqueIndexViolationException( getClass(),
					"updateServiceType",
					"ServiceTypeUDescrIdx",
					newKeyUDescrIdx );
			}
		}

		// Validate foreign keys

		// Update is valid

		Map< CFSecServiceTypePKey, CFSecServiceTypeBuff > subdict;

		dictByPKey.remove( pkey );
		dictByPKey.put( pkey, Buff );

		dictByUDescrIdx.remove( existingKeyUDescrIdx );
		dictByUDescrIdx.put( newKeyUDescrIdx, Buff );

	}

	public void deleteServiceType( CFSecAuthorization Authorization,
		CFSecServiceTypeBuff Buff )
	{
		final String S_ProcName = "CFIntRamServiceTypeTable.deleteServiceType() ";
		String classCode;
		CFSecServiceTypePKey pkey = schema.getFactoryServiceType().newPKey();
		pkey.setRequiredServiceTypeId( Buff.getRequiredServiceTypeId() );
		CFSecServiceTypeBuff existing = dictByPKey.get( pkey );
		if( existing == null ) {
			return;
		}
		if( existing.getRequiredRevision() != Buff.getRequiredRevision() )
		{
			throw new CFLibCollisionDetectedException( getClass(),
				"deleteServiceType",
				pkey );
		}
		// Short circuit self-referential code to prevent stack overflows
		Object arrCheckServiceTypeDeployed[] = schema.getTableService().readDerivedByTypeIdx( Authorization,
						existing.getRequiredServiceTypeId() );
		if( arrCheckServiceTypeDeployed.length > 0 ) {
			schema.getTableService().deleteServiceByTypeIdx( Authorization,
						existing.getRequiredServiceTypeId() );
		}
		CFSecServiceTypeByUDescrIdxKey keyUDescrIdx = schema.getFactoryServiceType().newUDescrIdxKey();
		keyUDescrIdx.setRequiredDescription( existing.getRequiredDescription() );

		// Validate reverse foreign keys

		// Delete is valid
		Map< CFSecServiceTypePKey, CFSecServiceTypeBuff > subdict;

		dictByPKey.remove( pkey );

		dictByUDescrIdx.remove( keyUDescrIdx );

	}
	public void deleteServiceTypeByIdIdx( CFSecAuthorization Authorization,
		int argServiceTypeId )
	{
		CFSecServiceTypePKey key = schema.getFactoryServiceType().newPKey();
		key.setRequiredServiceTypeId( argServiceTypeId );
		deleteServiceTypeByIdIdx( Authorization, key );
	}

	public void deleteServiceTypeByIdIdx( CFSecAuthorization Authorization,
		CFSecServiceTypePKey argKey )
	{
		boolean anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		CFSecServiceTypeBuff cur;
		LinkedList<CFSecServiceTypeBuff> matchSet = new LinkedList<CFSecServiceTypeBuff>();
		Iterator<CFSecServiceTypeBuff> values = dictByPKey.values().iterator();
		while( values.hasNext() ) {
			cur = values.next();
			if( argKey.equals( cur ) ) {
				matchSet.add( cur );
			}
		}
		Iterator<CFSecServiceTypeBuff> iterMatch = matchSet.iterator();
		while( iterMatch.hasNext() ) {
			cur = iterMatch.next();
			cur = schema.getTableServiceType().readDerivedByIdIdx( Authorization,
				cur.getRequiredServiceTypeId() );
			deleteServiceType( Authorization, cur );
		}
	}

	public void deleteServiceTypeByUDescrIdx( CFSecAuthorization Authorization,
		String argDescription )
	{
		CFSecServiceTypeByUDescrIdxKey key = schema.getFactoryServiceType().newUDescrIdxKey();
		key.setRequiredDescription( argDescription );
		deleteServiceTypeByUDescrIdx( Authorization, key );
	}

	public void deleteServiceTypeByUDescrIdx( CFSecAuthorization Authorization,
		CFSecServiceTypeByUDescrIdxKey argKey )
	{
		CFSecServiceTypeBuff cur;
		boolean anyNotNull = false;
		anyNotNull = true;
		if( ! anyNotNull ) {
			return;
		}
		LinkedList<CFSecServiceTypeBuff> matchSet = new LinkedList<CFSecServiceTypeBuff>();
		Iterator<CFSecServiceTypeBuff> values = dictByPKey.values().iterator();
		while( values.hasNext() ) {
			cur = values.next();
			if( argKey.equals( cur ) ) {
				matchSet.add( cur );
			}
		}
		Iterator<CFSecServiceTypeBuff> iterMatch = matchSet.iterator();
		while( iterMatch.hasNext() ) {
			cur = iterMatch.next();
			cur = schema.getTableServiceType().readDerivedByIdIdx( Authorization,
				cur.getRequiredServiceTypeId() );
			deleteServiceType( Authorization, cur );
		}
	}

	public void releasePreparedStatements() {
	}
}
