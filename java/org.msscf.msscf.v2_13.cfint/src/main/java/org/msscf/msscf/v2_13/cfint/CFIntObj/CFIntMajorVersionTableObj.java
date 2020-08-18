// Description: Java 11 Table Object implementation for CFInt.

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

package org.msscf.msscf.v2_13.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;
import org.msscf.msscf.v2_13.cfsec.CFSecObj.*;
import org.msscf.msscf.v2_13.cfint.CFInt.*;

public class CFIntMajorVersionTableObj
	implements ICFIntMajorVersionTableObj
{
	protected ICFIntSchemaObj schema;
	private Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj> members;
	private Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj> allMajorVersion;
	private Map< CFIntMajorVersionByTenantIdxKey,
		Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj > > indexByTenantIdx;
	private Map< CFIntMajorVersionBySubProjectIdxKey,
		Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj > > indexBySubProjectIdx;
	private Map< CFIntMajorVersionByNameIdxKey,
		ICFIntMajorVersionObj > indexByNameIdx;
	public static String TABLE_NAME = "MajorVersion";
	public static String TABLE_DBNAME = "mjvrdef";

	public CFIntMajorVersionTableObj() {
		schema = null;
		members = new HashMap<CFIntMajorVersionPKey, ICFIntMajorVersionObj>();
		allMajorVersion = null;
		indexByTenantIdx = null;
		indexBySubProjectIdx = null;
		indexByNameIdx = null;
	}

	public CFIntMajorVersionTableObj( ICFIntSchemaObj argSchema ) {
		schema = (ICFIntSchemaObj)argSchema;
		members = new HashMap<CFIntMajorVersionPKey, ICFIntMajorVersionObj>();
		allMajorVersion = null;
		indexByTenantIdx = null;
		indexBySubProjectIdx = null;
		indexByNameIdx = null;
	}

	public ICFIntSchemaObj getSchema() {
		return( schema );
	}

	public void setSchema( ICFIntSchemaObj value ) {
		schema = (ICFIntSchemaObj)value;
	}

	public String getTableName() {
		return( TABLE_NAME );
	}

	public String getTableDbName() {
		return( TABLE_DBNAME );
	}

	public Class getObjQualifyingClass() {
		return( ICFIntTenantObj.class );
	}


	public void minimizeMemory() {
		allMajorVersion = null;
		indexByTenantIdx = null;
		indexBySubProjectIdx = null;
		indexByNameIdx = null;
		List<ICFIntMajorVersionObj> toForget = new LinkedList<ICFIntMajorVersionObj>();
		ICFIntMajorVersionObj cur = null;
		Iterator<ICFIntMajorVersionObj> iter = members.values().iterator();
		while( iter.hasNext() ) {
			cur = iter.next();
			toForget.add( cur );
		}
		iter = toForget.iterator();
		while( iter.hasNext() ) {
			cur = iter.next();
			cur.forget();
		}
	}
	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFIntMajorVersionObj.
	 */
	public ICFIntMajorVersionObj newInstance() {
		ICFIntMajorVersionObj inst = new CFIntMajorVersionObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFIntMajorVersionObj.
	 */
	public ICFIntMajorVersionEditObj newEditInstance( ICFIntMajorVersionObj orig ) {
		ICFIntMajorVersionEditObj edit = new CFIntMajorVersionEditObj( orig );
		return( edit );
	}

	public ICFIntMajorVersionObj realiseMajorVersion( ICFIntMajorVersionObj Obj ) {
		ICFIntMajorVersionObj obj = Obj;
		CFIntMajorVersionPKey pkey = obj.getPKey();
		ICFIntMajorVersionObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFIntMajorVersionObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByTenantIdx != null ) {
				CFIntMajorVersionByTenantIdxKey keyTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.remove( keepObj.getPKey() );
					if( mapTenantIdx.size() <= 0 ) {
						indexByTenantIdx.remove( keyTenantIdx );
					}
				}
			}

			if( indexBySubProjectIdx != null ) {
				CFIntMajorVersionBySubProjectIdxKey keySubProjectIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newSubProjectIdxKey();
				keySubProjectIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keySubProjectIdx.setRequiredSubProjectId( keepObj.getRequiredSubProjectId() );
				Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj > mapSubProjectIdx = indexBySubProjectIdx.get( keySubProjectIdx );
				if( mapSubProjectIdx != null ) {
					mapSubProjectIdx.remove( keepObj.getPKey() );
					if( mapSubProjectIdx.size() <= 0 ) {
						indexBySubProjectIdx.remove( keySubProjectIdx );
					}
				}
			}

			if( indexByNameIdx != null ) {
				CFIntMajorVersionByNameIdxKey keyNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newNameIdxKey();
				keyNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyNameIdx.setRequiredSubProjectId( keepObj.getRequiredSubProjectId() );
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.remove( keyNameIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != null ) {
				CFIntMajorVersionByTenantIdxKey keyTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexBySubProjectIdx != null ) {
				CFIntMajorVersionBySubProjectIdxKey keySubProjectIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newSubProjectIdxKey();
				keySubProjectIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keySubProjectIdx.setRequiredSubProjectId( keepObj.getRequiredSubProjectId() );
				Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj > mapSubProjectIdx = indexBySubProjectIdx.get( keySubProjectIdx );
				if( mapSubProjectIdx != null ) {
					mapSubProjectIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByNameIdx != null ) {
				CFIntMajorVersionByNameIdxKey keyNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newNameIdxKey();
				keyNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyNameIdx.setRequiredSubProjectId( keepObj.getRequiredSubProjectId() );
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.put( keyNameIdx, keepObj );
			}

			if( allMajorVersion != null ) {
				allMajorVersion.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allMajorVersion != null ) {
				allMajorVersion.put( keepObj.getPKey(), keepObj );
			}

			if( indexByTenantIdx != null ) {
				CFIntMajorVersionByTenantIdxKey keyTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexBySubProjectIdx != null ) {
				CFIntMajorVersionBySubProjectIdxKey keySubProjectIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newSubProjectIdxKey();
				keySubProjectIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keySubProjectIdx.setRequiredSubProjectId( keepObj.getRequiredSubProjectId() );
				Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj > mapSubProjectIdx = indexBySubProjectIdx.get( keySubProjectIdx );
				if( mapSubProjectIdx != null ) {
					mapSubProjectIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByNameIdx != null ) {
				CFIntMajorVersionByNameIdxKey keyNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newNameIdxKey();
				keyNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyNameIdx.setRequiredSubProjectId( keepObj.getRequiredSubProjectId() );
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.put( keyNameIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFIntMajorVersionObj createMajorVersion( ICFIntMajorVersionObj Obj ) {
		ICFIntMajorVersionObj obj = Obj;
		CFIntMajorVersionBuff buff = obj.getMajorVersionBuff();
		((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().createMajorVersion(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFIntMajorVersionObj readMajorVersion( CFIntMajorVersionPKey pkey ) {
		return( readMajorVersion( pkey, false ) );
	}

	public ICFIntMajorVersionObj readMajorVersion( CFIntMajorVersionPKey pkey, boolean forceRead ) {
		ICFIntMajorVersionObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFIntMajorVersionBuff readBuff = ((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredTenantId(),
				pkey.getRequiredId() );
			if( readBuff != null ) {
				obj = schema.getMajorVersionTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFIntMajorVersionObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFIntMajorVersionObj readCachedMajorVersion( CFIntMajorVersionPKey pkey ) {
		ICFIntMajorVersionObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeMajorVersion( ICFIntMajorVersionObj obj )
	{
		final String S_ProcName = "CFIntMajorVersionTableObj.reallyDeepDisposeMajorVersion() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFIntMajorVersionPKey pkey = obj.getPKey();
		ICFIntMajorVersionObj existing = readCachedMajorVersion( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFIntMajorVersionByTenantIdxKey keyTenantIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newTenantIdxKey();
		keyTenantIdx.setRequiredTenantId( existing.getRequiredTenantId() );

		CFIntMajorVersionBySubProjectIdxKey keySubProjectIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newSubProjectIdxKey();
		keySubProjectIdx.setRequiredTenantId( existing.getRequiredTenantId() );
		keySubProjectIdx.setRequiredSubProjectId( existing.getRequiredSubProjectId() );

		CFIntMajorVersionByNameIdxKey keyNameIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newNameIdxKey();
		keyNameIdx.setRequiredTenantId( existing.getRequiredTenantId() );
		keyNameIdx.setRequiredSubProjectId( existing.getRequiredSubProjectId() );
		keyNameIdx.setRequiredName( existing.getRequiredName() );


					schema.getMinorVersionTableObj().deepDisposeMinorVersionByMajorVerIdx( existing.getRequiredTenantId(),
						existing.getRequiredId() );

		if( indexByTenantIdx != null ) {
			if( indexByTenantIdx.containsKey( keyTenantIdx ) ) {
				indexByTenantIdx.get( keyTenantIdx ).remove( pkey );
				if( indexByTenantIdx.get( keyTenantIdx ).size() <= 0 ) {
					indexByTenantIdx.remove( keyTenantIdx );
				}
			}
		}

		if( indexBySubProjectIdx != null ) {
			if( indexBySubProjectIdx.containsKey( keySubProjectIdx ) ) {
				indexBySubProjectIdx.get( keySubProjectIdx ).remove( pkey );
				if( indexBySubProjectIdx.get( keySubProjectIdx ).size() <= 0 ) {
					indexBySubProjectIdx.remove( keySubProjectIdx );
				}
			}
		}

		if( indexByNameIdx != null ) {
			indexByNameIdx.remove( keyNameIdx );
		}


	}
	public void deepDisposeMajorVersion( CFIntMajorVersionPKey pkey ) {
		ICFIntMajorVersionObj obj = readCachedMajorVersion( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFIntMajorVersionObj lockMajorVersion( CFIntMajorVersionPKey pkey ) {
		ICFIntMajorVersionObj locked = null;
		CFIntMajorVersionBuff lockBuff = ((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getMajorVersionTableObj().newInstance();
			locked.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFIntMajorVersionObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockMajorVersion", pkey );
		}
		return( locked );
	}

	public List<ICFIntMajorVersionObj> readAllMajorVersion() {
		return( readAllMajorVersion( false ) );
	}

	public List<ICFIntMajorVersionObj> readAllMajorVersion( boolean forceRead ) {
		final String S_ProcName = "readAllMajorVersion";
		if( ( allMajorVersion == null ) || forceRead ) {
			Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj> map = new HashMap<CFIntMajorVersionPKey,ICFIntMajorVersionObj>();
			allMajorVersion = map;
			CFIntMajorVersionBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().readAllDerived( schema.getAuthorization() );
			CFIntMajorVersionBuff buff;
			ICFIntMajorVersionObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newPKey() );
				obj.setBuff( buff );
				ICFIntMajorVersionObj realised = (ICFIntMajorVersionObj)obj.realise();
			}
		}
		int len = allMajorVersion.size();
		ICFIntMajorVersionObj arr[] = new ICFIntMajorVersionObj[len];
		Iterator<ICFIntMajorVersionObj> valIter = allMajorVersion.values().iterator();
		int idx = 0;
		while( ( idx < len ) && valIter.hasNext() ) {
			arr[idx++] = valIter.next();
		}
		if( idx < len ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				S_ProcName,
				0,
				"idx",
				idx,
				len );
		}
		else if( valIter.hasNext() ) {
			throw new CFLibArgumentOverflowException( getClass(),
					S_ProcName,
					0,
					"idx",
					idx,
					len );
		}
		ArrayList<ICFIntMajorVersionObj> arrayList = new ArrayList<ICFIntMajorVersionObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntMajorVersionObj> cmp = new Comparator<ICFIntMajorVersionObj>() {
			public int compare( ICFIntMajorVersionObj lhs, ICFIntMajorVersionObj rhs ) {
				if( lhs == null ) {
					if( rhs == null ) {
						return( 0 );
					}
					else {
						return( -1 );
					}
				}
				else if( rhs == null ) {
					return( 1 );
				}
				else {
					CFIntMajorVersionPKey lhsPKey = lhs.getPKey();
					CFIntMajorVersionPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntMajorVersionObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFIntMajorVersionObj> readCachedAllMajorVersion() {
		final String S_ProcName = "readCachedAllMajorVersion";
		ArrayList<ICFIntMajorVersionObj> arrayList = new ArrayList<ICFIntMajorVersionObj>();
		if( allMajorVersion != null ) {
			int len = allMajorVersion.size();
			ICFIntMajorVersionObj arr[] = new ICFIntMajorVersionObj[len];
			Iterator<ICFIntMajorVersionObj> valIter = allMajorVersion.values().iterator();
			int idx = 0;
			while( ( idx < len ) && valIter.hasNext() ) {
				arr[idx++] = valIter.next();
			}
			if( idx < len ) {
				throw new CFLibArgumentUnderflowException( getClass(),
					S_ProcName,
					0,
					"idx",
					idx,
					len );
			}
			else if( valIter.hasNext() ) {
				throw new CFLibArgumentOverflowException( getClass(),
						S_ProcName,
						0,
						"idx",
						idx,
						len );
			}
			for( idx = 0; idx < len; idx ++ ) {
				arrayList.add( arr[idx] );
			}
		}
		Comparator<ICFIntMajorVersionObj> cmp = new Comparator<ICFIntMajorVersionObj>() {
			public int compare( ICFIntMajorVersionObj lhs, ICFIntMajorVersionObj rhs ) {
				if( lhs == null ) {
					if( rhs == null ) {
						return( 0 );
					}
					else {
						return( -1 );
					}
				}
				else if( rhs == null ) {
					return( 1 );
				}
				else {
					CFIntMajorVersionPKey lhsPKey = lhs.getPKey();
					CFIntMajorVersionPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFIntMajorVersionObj readMajorVersionByIdIdx( long TenantId,
		long Id )
	{
		return( readMajorVersionByIdIdx( TenantId,
			Id,
			false ) );
	}

	public ICFIntMajorVersionObj readMajorVersionByIdIdx( long TenantId,
		long Id, boolean forceRead )
	{
		CFIntMajorVersionPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		ICFIntMajorVersionObj obj = readMajorVersion( pkey, forceRead );
		return( obj );
	}

	public List<ICFIntMajorVersionObj> readMajorVersionByTenantIdx( long TenantId )
	{
		return( readMajorVersionByTenantIdx( TenantId,
			false ) );
	}

	public List<ICFIntMajorVersionObj> readMajorVersionByTenantIdx( long TenantId,
		boolean forceRead )
	{
		final String S_ProcName = "readMajorVersionByTenantIdx";
		CFIntMajorVersionByTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj> dict;
		if( indexByTenantIdx == null ) {
			indexByTenantIdx = new HashMap< CFIntMajorVersionByTenantIdxKey,
				Map< CFIntMajorVersionPKey, ICFIntMajorVersionObj > >();
		}
		if( ( ! forceRead ) && indexByTenantIdx.containsKey( key ) ) {
			dict = indexByTenantIdx.get( key );
		}
		else {
			dict = new HashMap<CFIntMajorVersionPKey, ICFIntMajorVersionObj>();
			ICFIntMajorVersionObj obj;
			CFIntMajorVersionBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().readDerivedByTenantIdx( schema.getAuthorization(),
				TenantId );
			CFIntMajorVersionBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getMajorVersionTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newPKey() );
				obj.setBuff( buff );
				ICFIntMajorVersionObj realised = (ICFIntMajorVersionObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByTenantIdx.put( key, dict );
		}
		int len = dict.size();
		ICFIntMajorVersionObj arr[] = new ICFIntMajorVersionObj[len];
		Iterator<ICFIntMajorVersionObj> valIter = dict.values().iterator();
		int idx = 0;
		while( ( idx < len ) && valIter.hasNext() ) {
			arr[idx++] = valIter.next();
		}
		if( idx < len ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				S_ProcName,
				0,
				"idx",
				idx,
				len );
		}
		else if( valIter.hasNext() ) {
			throw new CFLibArgumentOverflowException( getClass(),
					S_ProcName,
					0,
					"idx",
					idx,
					len );
		}
		ArrayList<ICFIntMajorVersionObj> arrayList = new ArrayList<ICFIntMajorVersionObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntMajorVersionObj> cmp = new Comparator<ICFIntMajorVersionObj>() {
			public int compare( ICFIntMajorVersionObj lhs, ICFIntMajorVersionObj rhs ) {
				if( lhs == null ) {
					if( rhs == null ) {
						return( 0 );
					}
					else {
						return( -1 );
					}
				}
				else if( rhs == null ) {
					return( 1 );
				}
				else {
					CFIntMajorVersionPKey lhsPKey = lhs.getPKey();
					CFIntMajorVersionPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntMajorVersionObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFIntMajorVersionObj> readMajorVersionBySubProjectIdx( long TenantId,
		long SubProjectId )
	{
		return( readMajorVersionBySubProjectIdx( TenantId,
			SubProjectId,
			false ) );
	}

	public List<ICFIntMajorVersionObj> readMajorVersionBySubProjectIdx( long TenantId,
		long SubProjectId,
		boolean forceRead )
	{
		final String S_ProcName = "readMajorVersionBySubProjectIdx";
		CFIntMajorVersionBySubProjectIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newSubProjectIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj> dict;
		if( indexBySubProjectIdx == null ) {
			indexBySubProjectIdx = new HashMap< CFIntMajorVersionBySubProjectIdxKey,
				Map< CFIntMajorVersionPKey, ICFIntMajorVersionObj > >();
		}
		if( ( ! forceRead ) && indexBySubProjectIdx.containsKey( key ) ) {
			dict = indexBySubProjectIdx.get( key );
		}
		else {
			dict = new HashMap<CFIntMajorVersionPKey, ICFIntMajorVersionObj>();
			ICFIntMajorVersionObj obj;
			CFIntMajorVersionBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().readDerivedBySubProjectIdx( schema.getAuthorization(),
				TenantId,
				SubProjectId );
			CFIntMajorVersionBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getMajorVersionTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newPKey() );
				obj.setBuff( buff );
				ICFIntMajorVersionObj realised = (ICFIntMajorVersionObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexBySubProjectIdx.put( key, dict );
		}
		int len = dict.size();
		ICFIntMajorVersionObj arr[] = new ICFIntMajorVersionObj[len];
		Iterator<ICFIntMajorVersionObj> valIter = dict.values().iterator();
		int idx = 0;
		while( ( idx < len ) && valIter.hasNext() ) {
			arr[idx++] = valIter.next();
		}
		if( idx < len ) {
			throw new CFLibArgumentUnderflowException( getClass(),
				S_ProcName,
				0,
				"idx",
				idx,
				len );
		}
		else if( valIter.hasNext() ) {
			throw new CFLibArgumentOverflowException( getClass(),
					S_ProcName,
					0,
					"idx",
					idx,
					len );
		}
		ArrayList<ICFIntMajorVersionObj> arrayList = new ArrayList<ICFIntMajorVersionObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntMajorVersionObj> cmp = new Comparator<ICFIntMajorVersionObj>() {
			public int compare( ICFIntMajorVersionObj lhs, ICFIntMajorVersionObj rhs ) {
				if( lhs == null ) {
					if( rhs == null ) {
						return( 0 );
					}
					else {
						return( -1 );
					}
				}
				else if( rhs == null ) {
					return( 1 );
				}
				else {
					CFIntMajorVersionPKey lhsPKey = lhs.getPKey();
					CFIntMajorVersionPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntMajorVersionObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFIntMajorVersionObj readMajorVersionByNameIdx( long TenantId,
		long SubProjectId,
		String Name )
	{
		return( readMajorVersionByNameIdx( TenantId,
			SubProjectId,
			Name,
			false ) );
	}

	public ICFIntMajorVersionObj readMajorVersionByNameIdx( long TenantId,
		long SubProjectId,
		String Name, boolean forceRead )
	{
		if( indexByNameIdx == null ) {
			indexByNameIdx = new HashMap< CFIntMajorVersionByNameIdxKey,
				ICFIntMajorVersionObj >();
		}
		CFIntMajorVersionByNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		key.setRequiredName( Name );
		ICFIntMajorVersionObj obj = null;
		if( ( ! forceRead ) && indexByNameIdx.containsKey( key ) ) {
			obj = indexByNameIdx.get( key );
		}
		else {
			CFIntMajorVersionBuff buff = ((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().readDerivedByNameIdx( schema.getAuthorization(),
				TenantId,
				SubProjectId,
				Name );
			if( buff != null ) {
				obj = schema.getMajorVersionTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newPKey() );
				obj.setBuff( buff );
				obj = (ICFIntMajorVersionObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFIntMajorVersionObj readCachedMajorVersionByIdIdx( long TenantId,
		long Id )
	{
		ICFIntMajorVersionObj obj = null;
		CFIntMajorVersionPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		obj = readCachedMajorVersion( pkey );
		return( obj );
	}

	public List<ICFIntMajorVersionObj> readCachedMajorVersionByTenantIdx( long TenantId )
	{
		final String S_ProcName = "readCachedMajorVersionByTenantIdx";
		CFIntMajorVersionByTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		ArrayList<ICFIntMajorVersionObj> arrayList = new ArrayList<ICFIntMajorVersionObj>();
		if( indexByTenantIdx != null ) {
			Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj> dict;
			if( indexByTenantIdx.containsKey( key ) ) {
				dict = indexByTenantIdx.get( key );
				int len = dict.size();
				ICFIntMajorVersionObj arr[] = new ICFIntMajorVersionObj[len];
				Iterator<ICFIntMajorVersionObj> valIter = dict.values().iterator();
				int idx = 0;
				while( ( idx < len ) && valIter.hasNext() ) {
					arr[idx++] = valIter.next();
				}
				if( idx < len ) {
					throw new CFLibArgumentUnderflowException( getClass(),
						S_ProcName,
						0,
						"idx",
						idx,
						len );
				}
				else if( valIter.hasNext() ) {
					throw new CFLibArgumentOverflowException( getClass(),
							S_ProcName,
							0,
							"idx",
							idx,
							len );
				}
				for( idx = 0; idx < len; idx ++ ) {
					arrayList.add( arr[idx] );
				}
			}
		}
		else {
			ICFIntMajorVersionObj obj;
			Iterator<ICFIntMajorVersionObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFIntMajorVersionObj> cmp = new Comparator<ICFIntMajorVersionObj>() {
			public int compare( ICFIntMajorVersionObj lhs, ICFIntMajorVersionObj rhs ) {
				if( lhs == null ) {
					if( rhs == null ) {
						return( 0 );
					}
					else {
						return( -1 );
					}
				}
				else if( rhs == null ) {
					return( 1 );
				}
				else {
					CFIntMajorVersionPKey lhsPKey = lhs.getPKey();
					CFIntMajorVersionPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFIntMajorVersionObj> readCachedMajorVersionBySubProjectIdx( long TenantId,
		long SubProjectId )
	{
		final String S_ProcName = "readCachedMajorVersionBySubProjectIdx";
		CFIntMajorVersionBySubProjectIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newSubProjectIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		ArrayList<ICFIntMajorVersionObj> arrayList = new ArrayList<ICFIntMajorVersionObj>();
		if( indexBySubProjectIdx != null ) {
			Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj> dict;
			if( indexBySubProjectIdx.containsKey( key ) ) {
				dict = indexBySubProjectIdx.get( key );
				int len = dict.size();
				ICFIntMajorVersionObj arr[] = new ICFIntMajorVersionObj[len];
				Iterator<ICFIntMajorVersionObj> valIter = dict.values().iterator();
				int idx = 0;
				while( ( idx < len ) && valIter.hasNext() ) {
					arr[idx++] = valIter.next();
				}
				if( idx < len ) {
					throw new CFLibArgumentUnderflowException( getClass(),
						S_ProcName,
						0,
						"idx",
						idx,
						len );
				}
				else if( valIter.hasNext() ) {
					throw new CFLibArgumentOverflowException( getClass(),
							S_ProcName,
							0,
							"idx",
							idx,
							len );
				}
				for( idx = 0; idx < len; idx ++ ) {
					arrayList.add( arr[idx] );
				}
			}
		}
		else {
			ICFIntMajorVersionObj obj;
			Iterator<ICFIntMajorVersionObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFIntMajorVersionObj> cmp = new Comparator<ICFIntMajorVersionObj>() {
			public int compare( ICFIntMajorVersionObj lhs, ICFIntMajorVersionObj rhs ) {
				if( lhs == null ) {
					if( rhs == null ) {
						return( 0 );
					}
					else {
						return( -1 );
					}
				}
				else if( rhs == null ) {
					return( 1 );
				}
				else {
					CFIntMajorVersionPKey lhsPKey = lhs.getPKey();
					CFIntMajorVersionPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFIntMajorVersionObj readCachedMajorVersionByNameIdx( long TenantId,
		long SubProjectId,
		String Name )
	{
		ICFIntMajorVersionObj obj = null;
		CFIntMajorVersionByNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		key.setRequiredName( Name );
		if( indexByNameIdx != null ) {
			if( indexByNameIdx.containsKey( key ) ) {
				obj = indexByNameIdx.get( key );
			}
			else {
				Iterator<ICFIntMajorVersionObj> valIter = members.values().iterator();
				while( ( obj == null ) && valIter.hasNext() ) {
					obj = valIter.next();
					if( obj != null ) {
						if( obj.getBuff().compareTo( key ) != 0 ) {
							obj = null;
						}
					}
				}
			}
		}
		else {
			Iterator<ICFIntMajorVersionObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) != 0 ) {
						obj = null;
					}
				}
			}
		}
		return( obj );
	}

	public void deepDisposeMajorVersionByIdIdx( long TenantId,
		long Id )
	{
		ICFIntMajorVersionObj obj = readCachedMajorVersionByIdIdx( TenantId,
				Id );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeMajorVersionByTenantIdx( long TenantId )
	{
		final String S_ProcName = "deepDisposeMajorVersionByTenantIdx";
		ICFIntMajorVersionObj obj;
		List<ICFIntMajorVersionObj> arrayList = readCachedMajorVersionByTenantIdx( TenantId );
		if( arrayList != null )  {
			Iterator<ICFIntMajorVersionObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeMajorVersionBySubProjectIdx( long TenantId,
		long SubProjectId )
	{
		final String S_ProcName = "deepDisposeMajorVersionBySubProjectIdx";
		ICFIntMajorVersionObj obj;
		List<ICFIntMajorVersionObj> arrayList = readCachedMajorVersionBySubProjectIdx( TenantId,
				SubProjectId );
		if( arrayList != null )  {
			Iterator<ICFIntMajorVersionObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeMajorVersionByNameIdx( long TenantId,
		long SubProjectId,
		String Name )
	{
		ICFIntMajorVersionObj obj = readCachedMajorVersionByNameIdx( TenantId,
				SubProjectId,
				Name );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFIntMajorVersionObj updateMajorVersion( ICFIntMajorVersionObj Obj ) {
		ICFIntMajorVersionObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().updateMajorVersion( schema.getAuthorization(),
			Obj.getMajorVersionBuff() );
		obj = (ICFIntMajorVersionObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteMajorVersion( ICFIntMajorVersionObj Obj ) {
		ICFIntMajorVersionObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().deleteMajorVersion( schema.getAuthorization(),
			obj.getMajorVersionBuff() );
		Obj.forget();
	}

	public void deleteMajorVersionByIdIdx( long TenantId,
		long Id )
	{
		CFIntMajorVersionPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		ICFIntMajorVersionObj obj = readMajorVersion( pkey );
		if( obj != null ) {
			ICFIntMajorVersionEditObj editObj = (ICFIntMajorVersionEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFIntMajorVersionEditObj)obj.beginEdit();
				if( editObj != null ) {
					editStarted = true;
				}
				else {
					editStarted = false;
				}
			}
			else {
				editStarted = false;
			}
			if( editObj != null ) {
				editObj.deleteInstance();
				if( editStarted ) {
					editObj.endEdit();
				}
			}
			obj.forget();
		}
		deepDisposeMajorVersionByIdIdx( TenantId,
				Id );
	}

	public void deleteMajorVersionByTenantIdx( long TenantId )
	{
		CFIntMajorVersionByTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		if( indexByTenantIdx == null ) {
			indexByTenantIdx = new HashMap< CFIntMajorVersionByTenantIdxKey,
				Map< CFIntMajorVersionPKey, ICFIntMajorVersionObj > >();
		}
		if( indexByTenantIdx.containsKey( key ) ) {
			Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj> dict = indexByTenantIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().deleteMajorVersionByTenantIdx( schema.getAuthorization(),
				TenantId );
			Iterator<ICFIntMajorVersionObj> iter = dict.values().iterator();
			ICFIntMajorVersionObj obj;
			List<ICFIntMajorVersionObj> toForget = new LinkedList<ICFIntMajorVersionObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByTenantIdx.remove( key );
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().deleteMajorVersionByTenantIdx( schema.getAuthorization(),
				TenantId );
		}
		deepDisposeMajorVersionByTenantIdx( TenantId );
	}

	public void deleteMajorVersionBySubProjectIdx( long TenantId,
		long SubProjectId )
	{
		CFIntMajorVersionBySubProjectIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newSubProjectIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		if( indexBySubProjectIdx == null ) {
			indexBySubProjectIdx = new HashMap< CFIntMajorVersionBySubProjectIdxKey,
				Map< CFIntMajorVersionPKey, ICFIntMajorVersionObj > >();
		}
		if( indexBySubProjectIdx.containsKey( key ) ) {
			Map<CFIntMajorVersionPKey, ICFIntMajorVersionObj> dict = indexBySubProjectIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().deleteMajorVersionBySubProjectIdx( schema.getAuthorization(),
				TenantId,
				SubProjectId );
			Iterator<ICFIntMajorVersionObj> iter = dict.values().iterator();
			ICFIntMajorVersionObj obj;
			List<ICFIntMajorVersionObj> toForget = new LinkedList<ICFIntMajorVersionObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexBySubProjectIdx.remove( key );
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().deleteMajorVersionBySubProjectIdx( schema.getAuthorization(),
				TenantId,
				SubProjectId );
		}
		deepDisposeMajorVersionBySubProjectIdx( TenantId,
				SubProjectId );
	}

	public void deleteMajorVersionByNameIdx( long TenantId,
		long SubProjectId,
		String Name )
	{
		if( indexByNameIdx == null ) {
			indexByNameIdx = new HashMap< CFIntMajorVersionByNameIdxKey,
				ICFIntMajorVersionObj >();
		}
		CFIntMajorVersionByNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMajorVersion().newNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredSubProjectId( SubProjectId );
		key.setRequiredName( Name );
		ICFIntMajorVersionObj obj = null;
		if( indexByNameIdx.containsKey( key ) ) {
			obj = indexByNameIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().deleteMajorVersionByNameIdx( schema.getAuthorization(),
				TenantId,
				SubProjectId,
				Name );
			obj.forget();
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableMajorVersion().deleteMajorVersionByNameIdx( schema.getAuthorization(),
				TenantId,
				SubProjectId,
				Name );
		}
		deepDisposeMajorVersionByNameIdx( TenantId,
				SubProjectId,
				Name );
	}
}