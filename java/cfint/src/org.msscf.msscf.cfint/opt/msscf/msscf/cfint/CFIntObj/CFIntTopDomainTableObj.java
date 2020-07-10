// Description: Java 11 Table Object implementation for CFInt.

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

public class CFIntTopDomainTableObj
	implements ICFIntTopDomainTableObj
{
	protected ICFIntSchemaObj schema;
	private Map<CFIntTopDomainPKey, ICFIntTopDomainObj> members;
	private Map<CFIntTopDomainPKey, ICFIntTopDomainObj> allTopDomain;
	private Map< CFIntTopDomainByTenantIdxKey,
		Map<CFIntTopDomainPKey, ICFIntTopDomainObj > > indexByTenantIdx;
	private Map< CFIntTopDomainByTldIdxKey,
		Map<CFIntTopDomainPKey, ICFIntTopDomainObj > > indexByTldIdx;
	private Map< CFIntTopDomainByNameIdxKey,
		ICFIntTopDomainObj > indexByNameIdx;
	public static String TABLE_NAME = "TopDomain";
	public static String TABLE_DBNAME = "tdomdef";

	public CFIntTopDomainTableObj() {
		schema = null;
		members = new HashMap<CFIntTopDomainPKey, ICFIntTopDomainObj>();
		allTopDomain = null;
		indexByTenantIdx = null;
		indexByTldIdx = null;
		indexByNameIdx = null;
	}

	public CFIntTopDomainTableObj( ICFIntSchemaObj argSchema ) {
		schema = (ICFIntSchemaObj)argSchema;
		members = new HashMap<CFIntTopDomainPKey, ICFIntTopDomainObj>();
		allTopDomain = null;
		indexByTenantIdx = null;
		indexByTldIdx = null;
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
		allTopDomain = null;
		indexByTenantIdx = null;
		indexByTldIdx = null;
		indexByNameIdx = null;
		List<ICFIntTopDomainObj> toForget = new LinkedList<ICFIntTopDomainObj>();
		ICFIntTopDomainObj cur = null;
		Iterator<ICFIntTopDomainObj> iter = members.values().iterator();
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
	 *	CFIntTopDomainObj.
	 */
	public ICFIntTopDomainObj newInstance() {
		ICFIntTopDomainObj inst = new CFIntTopDomainObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFIntTopDomainObj.
	 */
	public ICFIntTopDomainEditObj newEditInstance( ICFIntTopDomainObj orig ) {
		ICFIntTopDomainEditObj edit = new CFIntTopDomainEditObj( orig );
		return( edit );
	}

	public ICFIntTopDomainObj realiseTopDomain( ICFIntTopDomainObj Obj ) {
		ICFIntTopDomainObj obj = Obj;
		CFIntTopDomainPKey pkey = obj.getPKey();
		ICFIntTopDomainObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFIntTopDomainObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByTenantIdx != null ) {
				CFIntTopDomainByTenantIdxKey keyTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntTopDomainPKey, ICFIntTopDomainObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.remove( keepObj.getPKey() );
					if( mapTenantIdx.size() <= 0 ) {
						indexByTenantIdx.remove( keyTenantIdx );
					}
				}
			}

			if( indexByTldIdx != null ) {
				CFIntTopDomainByTldIdxKey keyTldIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTldIdxKey();
				keyTldIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyTldIdx.setRequiredTldId( keepObj.getRequiredTldId() );
				Map<CFIntTopDomainPKey, ICFIntTopDomainObj > mapTldIdx = indexByTldIdx.get( keyTldIdx );
				if( mapTldIdx != null ) {
					mapTldIdx.remove( keepObj.getPKey() );
					if( mapTldIdx.size() <= 0 ) {
						indexByTldIdx.remove( keyTldIdx );
					}
				}
			}

			if( indexByNameIdx != null ) {
				CFIntTopDomainByNameIdxKey keyNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newNameIdxKey();
				keyNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyNameIdx.setRequiredTldId( keepObj.getRequiredTldId() );
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.remove( keyNameIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != null ) {
				CFIntTopDomainByTenantIdxKey keyTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntTopDomainPKey, ICFIntTopDomainObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByTldIdx != null ) {
				CFIntTopDomainByTldIdxKey keyTldIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTldIdxKey();
				keyTldIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyTldIdx.setRequiredTldId( keepObj.getRequiredTldId() );
				Map<CFIntTopDomainPKey, ICFIntTopDomainObj > mapTldIdx = indexByTldIdx.get( keyTldIdx );
				if( mapTldIdx != null ) {
					mapTldIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByNameIdx != null ) {
				CFIntTopDomainByNameIdxKey keyNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newNameIdxKey();
				keyNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyNameIdx.setRequiredTldId( keepObj.getRequiredTldId() );
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.put( keyNameIdx, keepObj );
			}

			if( allTopDomain != null ) {
				allTopDomain.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allTopDomain != null ) {
				allTopDomain.put( keepObj.getPKey(), keepObj );
			}

			if( indexByTenantIdx != null ) {
				CFIntTopDomainByTenantIdxKey keyTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntTopDomainPKey, ICFIntTopDomainObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByTldIdx != null ) {
				CFIntTopDomainByTldIdxKey keyTldIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTldIdxKey();
				keyTldIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyTldIdx.setRequiredTldId( keepObj.getRequiredTldId() );
				Map<CFIntTopDomainPKey, ICFIntTopDomainObj > mapTldIdx = indexByTldIdx.get( keyTldIdx );
				if( mapTldIdx != null ) {
					mapTldIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByNameIdx != null ) {
				CFIntTopDomainByNameIdxKey keyNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newNameIdxKey();
				keyNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyNameIdx.setRequiredTldId( keepObj.getRequiredTldId() );
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.put( keyNameIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFIntTopDomainObj createTopDomain( ICFIntTopDomainObj Obj ) {
		ICFIntTopDomainObj obj = Obj;
		CFIntTopDomainBuff buff = obj.getTopDomainBuff();
		((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().createTopDomain(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFIntTopDomainObj readTopDomain( CFIntTopDomainPKey pkey ) {
		return( readTopDomain( pkey, false ) );
	}

	public ICFIntTopDomainObj readTopDomain( CFIntTopDomainPKey pkey, boolean forceRead ) {
		ICFIntTopDomainObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFIntTopDomainBuff readBuff = ((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredTenantId(),
				pkey.getRequiredId() );
			if( readBuff != null ) {
				obj = schema.getTopDomainTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFIntTopDomainObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFIntTopDomainObj readCachedTopDomain( CFIntTopDomainPKey pkey ) {
		ICFIntTopDomainObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeTopDomain( ICFIntTopDomainObj obj )
	{
		final String S_ProcName = "CFIntTopDomainTableObj.reallyDeepDisposeTopDomain() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFIntTopDomainPKey pkey = obj.getPKey();
		ICFIntTopDomainObj existing = readCachedTopDomain( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFIntTopDomainByTenantIdxKey keyTenantIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTenantIdxKey();
		keyTenantIdx.setRequiredTenantId( existing.getRequiredTenantId() );

		CFIntTopDomainByTldIdxKey keyTldIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTldIdxKey();
		keyTldIdx.setRequiredTenantId( existing.getRequiredTenantId() );
		keyTldIdx.setRequiredTldId( existing.getRequiredTldId() );

		CFIntTopDomainByNameIdxKey keyNameIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newNameIdxKey();
		keyNameIdx.setRequiredTenantId( existing.getRequiredTenantId() );
		keyNameIdx.setRequiredTldId( existing.getRequiredTldId() );
		keyNameIdx.setRequiredName( existing.getRequiredName() );


					schema.getTopProjectTableObj().deepDisposeTopProjectByTopDomainIdx( existing.getRequiredTenantId(),
						existing.getRequiredId() );
					schema.getLicenseTableObj().deepDisposeLicenseByDomainIdx( existing.getRequiredTenantId(),
						existing.getRequiredId() );

		if( indexByTenantIdx != null ) {
			if( indexByTenantIdx.containsKey( keyTenantIdx ) ) {
				indexByTenantIdx.get( keyTenantIdx ).remove( pkey );
				if( indexByTenantIdx.get( keyTenantIdx ).size() <= 0 ) {
					indexByTenantIdx.remove( keyTenantIdx );
				}
			}
		}

		if( indexByTldIdx != null ) {
			if( indexByTldIdx.containsKey( keyTldIdx ) ) {
				indexByTldIdx.get( keyTldIdx ).remove( pkey );
				if( indexByTldIdx.get( keyTldIdx ).size() <= 0 ) {
					indexByTldIdx.remove( keyTldIdx );
				}
			}
		}

		if( indexByNameIdx != null ) {
			indexByNameIdx.remove( keyNameIdx );
		}


	}
	public void deepDisposeTopDomain( CFIntTopDomainPKey pkey ) {
		ICFIntTopDomainObj obj = readCachedTopDomain( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFIntTopDomainObj lockTopDomain( CFIntTopDomainPKey pkey ) {
		ICFIntTopDomainObj locked = null;
		CFIntTopDomainBuff lockBuff = ((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getTopDomainTableObj().newInstance();
			locked.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFIntTopDomainObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockTopDomain", pkey );
		}
		return( locked );
	}

	public List<ICFIntTopDomainObj> readAllTopDomain() {
		return( readAllTopDomain( false ) );
	}

	public List<ICFIntTopDomainObj> readAllTopDomain( boolean forceRead ) {
		final String S_ProcName = "readAllTopDomain";
		if( ( allTopDomain == null ) || forceRead ) {
			Map<CFIntTopDomainPKey, ICFIntTopDomainObj> map = new HashMap<CFIntTopDomainPKey,ICFIntTopDomainObj>();
			allTopDomain = map;
			CFIntTopDomainBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().readAllDerived( schema.getAuthorization() );
			CFIntTopDomainBuff buff;
			ICFIntTopDomainObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newPKey() );
				obj.setBuff( buff );
				ICFIntTopDomainObj realised = (ICFIntTopDomainObj)obj.realise();
			}
		}
		int len = allTopDomain.size();
		ICFIntTopDomainObj arr[] = new ICFIntTopDomainObj[len];
		Iterator<ICFIntTopDomainObj> valIter = allTopDomain.values().iterator();
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
		ArrayList<ICFIntTopDomainObj> arrayList = new ArrayList<ICFIntTopDomainObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntTopDomainObj> cmp = new Comparator<ICFIntTopDomainObj>() {
			public int compare( ICFIntTopDomainObj lhs, ICFIntTopDomainObj rhs ) {
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
					CFIntTopDomainPKey lhsPKey = lhs.getPKey();
					CFIntTopDomainPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntTopDomainObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFIntTopDomainObj> readCachedAllTopDomain() {
		final String S_ProcName = "readCachedAllTopDomain";
		ArrayList<ICFIntTopDomainObj> arrayList = new ArrayList<ICFIntTopDomainObj>();
		if( allTopDomain != null ) {
			int len = allTopDomain.size();
			ICFIntTopDomainObj arr[] = new ICFIntTopDomainObj[len];
			Iterator<ICFIntTopDomainObj> valIter = allTopDomain.values().iterator();
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
		Comparator<ICFIntTopDomainObj> cmp = new Comparator<ICFIntTopDomainObj>() {
			public int compare( ICFIntTopDomainObj lhs, ICFIntTopDomainObj rhs ) {
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
					CFIntTopDomainPKey lhsPKey = lhs.getPKey();
					CFIntTopDomainPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFIntTopDomainObj readTopDomainByIdIdx( long TenantId,
		long Id )
	{
		return( readTopDomainByIdIdx( TenantId,
			Id,
			false ) );
	}

	public ICFIntTopDomainObj readTopDomainByIdIdx( long TenantId,
		long Id, boolean forceRead )
	{
		CFIntTopDomainPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		ICFIntTopDomainObj obj = readTopDomain( pkey, forceRead );
		return( obj );
	}

	public List<ICFIntTopDomainObj> readTopDomainByTenantIdx( long TenantId )
	{
		return( readTopDomainByTenantIdx( TenantId,
			false ) );
	}

	public List<ICFIntTopDomainObj> readTopDomainByTenantIdx( long TenantId,
		boolean forceRead )
	{
		final String S_ProcName = "readTopDomainByTenantIdx";
		CFIntTopDomainByTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		Map<CFIntTopDomainPKey, ICFIntTopDomainObj> dict;
		if( indexByTenantIdx == null ) {
			indexByTenantIdx = new HashMap< CFIntTopDomainByTenantIdxKey,
				Map< CFIntTopDomainPKey, ICFIntTopDomainObj > >();
		}
		if( ( ! forceRead ) && indexByTenantIdx.containsKey( key ) ) {
			dict = indexByTenantIdx.get( key );
		}
		else {
			dict = new HashMap<CFIntTopDomainPKey, ICFIntTopDomainObj>();
			ICFIntTopDomainObj obj;
			CFIntTopDomainBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().readDerivedByTenantIdx( schema.getAuthorization(),
				TenantId );
			CFIntTopDomainBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getTopDomainTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newPKey() );
				obj.setBuff( buff );
				ICFIntTopDomainObj realised = (ICFIntTopDomainObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByTenantIdx.put( key, dict );
		}
		int len = dict.size();
		ICFIntTopDomainObj arr[] = new ICFIntTopDomainObj[len];
		Iterator<ICFIntTopDomainObj> valIter = dict.values().iterator();
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
		ArrayList<ICFIntTopDomainObj> arrayList = new ArrayList<ICFIntTopDomainObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntTopDomainObj> cmp = new Comparator<ICFIntTopDomainObj>() {
			public int compare( ICFIntTopDomainObj lhs, ICFIntTopDomainObj rhs ) {
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
					CFIntTopDomainPKey lhsPKey = lhs.getPKey();
					CFIntTopDomainPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntTopDomainObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFIntTopDomainObj> readTopDomainByTldIdx( long TenantId,
		long TldId )
	{
		return( readTopDomainByTldIdx( TenantId,
			TldId,
			false ) );
	}

	public List<ICFIntTopDomainObj> readTopDomainByTldIdx( long TenantId,
		long TldId,
		boolean forceRead )
	{
		final String S_ProcName = "readTopDomainByTldIdx";
		CFIntTopDomainByTldIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTldIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		Map<CFIntTopDomainPKey, ICFIntTopDomainObj> dict;
		if( indexByTldIdx == null ) {
			indexByTldIdx = new HashMap< CFIntTopDomainByTldIdxKey,
				Map< CFIntTopDomainPKey, ICFIntTopDomainObj > >();
		}
		if( ( ! forceRead ) && indexByTldIdx.containsKey( key ) ) {
			dict = indexByTldIdx.get( key );
		}
		else {
			dict = new HashMap<CFIntTopDomainPKey, ICFIntTopDomainObj>();
			ICFIntTopDomainObj obj;
			CFIntTopDomainBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().readDerivedByTldIdx( schema.getAuthorization(),
				TenantId,
				TldId );
			CFIntTopDomainBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getTopDomainTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newPKey() );
				obj.setBuff( buff );
				ICFIntTopDomainObj realised = (ICFIntTopDomainObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByTldIdx.put( key, dict );
		}
		int len = dict.size();
		ICFIntTopDomainObj arr[] = new ICFIntTopDomainObj[len];
		Iterator<ICFIntTopDomainObj> valIter = dict.values().iterator();
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
		ArrayList<ICFIntTopDomainObj> arrayList = new ArrayList<ICFIntTopDomainObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntTopDomainObj> cmp = new Comparator<ICFIntTopDomainObj>() {
			public int compare( ICFIntTopDomainObj lhs, ICFIntTopDomainObj rhs ) {
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
					CFIntTopDomainPKey lhsPKey = lhs.getPKey();
					CFIntTopDomainPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntTopDomainObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFIntTopDomainObj readTopDomainByNameIdx( long TenantId,
		long TldId,
		String Name )
	{
		return( readTopDomainByNameIdx( TenantId,
			TldId,
			Name,
			false ) );
	}

	public ICFIntTopDomainObj readTopDomainByNameIdx( long TenantId,
		long TldId,
		String Name, boolean forceRead )
	{
		if( indexByNameIdx == null ) {
			indexByNameIdx = new HashMap< CFIntTopDomainByNameIdxKey,
				ICFIntTopDomainObj >();
		}
		CFIntTopDomainByNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		key.setRequiredName( Name );
		ICFIntTopDomainObj obj = null;
		if( ( ! forceRead ) && indexByNameIdx.containsKey( key ) ) {
			obj = indexByNameIdx.get( key );
		}
		else {
			CFIntTopDomainBuff buff = ((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().readDerivedByNameIdx( schema.getAuthorization(),
				TenantId,
				TldId,
				Name );
			if( buff != null ) {
				obj = schema.getTopDomainTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newPKey() );
				obj.setBuff( buff );
				obj = (ICFIntTopDomainObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFIntTopDomainObj readCachedTopDomainByIdIdx( long TenantId,
		long Id )
	{
		ICFIntTopDomainObj obj = null;
		CFIntTopDomainPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		obj = readCachedTopDomain( pkey );
		return( obj );
	}

	public List<ICFIntTopDomainObj> readCachedTopDomainByTenantIdx( long TenantId )
	{
		final String S_ProcName = "readCachedTopDomainByTenantIdx";
		CFIntTopDomainByTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		ArrayList<ICFIntTopDomainObj> arrayList = new ArrayList<ICFIntTopDomainObj>();
		if( indexByTenantIdx != null ) {
			Map<CFIntTopDomainPKey, ICFIntTopDomainObj> dict;
			if( indexByTenantIdx.containsKey( key ) ) {
				dict = indexByTenantIdx.get( key );
				int len = dict.size();
				ICFIntTopDomainObj arr[] = new ICFIntTopDomainObj[len];
				Iterator<ICFIntTopDomainObj> valIter = dict.values().iterator();
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
			ICFIntTopDomainObj obj;
			Iterator<ICFIntTopDomainObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFIntTopDomainObj> cmp = new Comparator<ICFIntTopDomainObj>() {
			public int compare( ICFIntTopDomainObj lhs, ICFIntTopDomainObj rhs ) {
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
					CFIntTopDomainPKey lhsPKey = lhs.getPKey();
					CFIntTopDomainPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFIntTopDomainObj> readCachedTopDomainByTldIdx( long TenantId,
		long TldId )
	{
		final String S_ProcName = "readCachedTopDomainByTldIdx";
		CFIntTopDomainByTldIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTldIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		ArrayList<ICFIntTopDomainObj> arrayList = new ArrayList<ICFIntTopDomainObj>();
		if( indexByTldIdx != null ) {
			Map<CFIntTopDomainPKey, ICFIntTopDomainObj> dict;
			if( indexByTldIdx.containsKey( key ) ) {
				dict = indexByTldIdx.get( key );
				int len = dict.size();
				ICFIntTopDomainObj arr[] = new ICFIntTopDomainObj[len];
				Iterator<ICFIntTopDomainObj> valIter = dict.values().iterator();
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
			ICFIntTopDomainObj obj;
			Iterator<ICFIntTopDomainObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFIntTopDomainObj> cmp = new Comparator<ICFIntTopDomainObj>() {
			public int compare( ICFIntTopDomainObj lhs, ICFIntTopDomainObj rhs ) {
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
					CFIntTopDomainPKey lhsPKey = lhs.getPKey();
					CFIntTopDomainPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFIntTopDomainObj readCachedTopDomainByNameIdx( long TenantId,
		long TldId,
		String Name )
	{
		ICFIntTopDomainObj obj = null;
		CFIntTopDomainByNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		key.setRequiredName( Name );
		if( indexByNameIdx != null ) {
			if( indexByNameIdx.containsKey( key ) ) {
				obj = indexByNameIdx.get( key );
			}
			else {
				Iterator<ICFIntTopDomainObj> valIter = members.values().iterator();
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
			Iterator<ICFIntTopDomainObj> valIter = members.values().iterator();
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

	public void deepDisposeTopDomainByIdIdx( long TenantId,
		long Id )
	{
		ICFIntTopDomainObj obj = readCachedTopDomainByIdIdx( TenantId,
				Id );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeTopDomainByTenantIdx( long TenantId )
	{
		final String S_ProcName = "deepDisposeTopDomainByTenantIdx";
		ICFIntTopDomainObj obj;
		List<ICFIntTopDomainObj> arrayList = readCachedTopDomainByTenantIdx( TenantId );
		if( arrayList != null )  {
			Iterator<ICFIntTopDomainObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeTopDomainByTldIdx( long TenantId,
		long TldId )
	{
		final String S_ProcName = "deepDisposeTopDomainByTldIdx";
		ICFIntTopDomainObj obj;
		List<ICFIntTopDomainObj> arrayList = readCachedTopDomainByTldIdx( TenantId,
				TldId );
		if( arrayList != null )  {
			Iterator<ICFIntTopDomainObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeTopDomainByNameIdx( long TenantId,
		long TldId,
		String Name )
	{
		ICFIntTopDomainObj obj = readCachedTopDomainByNameIdx( TenantId,
				TldId,
				Name );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFIntTopDomainObj updateTopDomain( ICFIntTopDomainObj Obj ) {
		ICFIntTopDomainObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().updateTopDomain( schema.getAuthorization(),
			Obj.getTopDomainBuff() );
		obj = (ICFIntTopDomainObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteTopDomain( ICFIntTopDomainObj Obj ) {
		ICFIntTopDomainObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().deleteTopDomain( schema.getAuthorization(),
			obj.getTopDomainBuff() );
		Obj.forget();
	}

	public void deleteTopDomainByIdIdx( long TenantId,
		long Id )
	{
		CFIntTopDomainPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		ICFIntTopDomainObj obj = readTopDomain( pkey );
		if( obj != null ) {
			ICFIntTopDomainEditObj editObj = (ICFIntTopDomainEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFIntTopDomainEditObj)obj.beginEdit();
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
		deepDisposeTopDomainByIdIdx( TenantId,
				Id );
	}

	public void deleteTopDomainByTenantIdx( long TenantId )
	{
		CFIntTopDomainByTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		if( indexByTenantIdx == null ) {
			indexByTenantIdx = new HashMap< CFIntTopDomainByTenantIdxKey,
				Map< CFIntTopDomainPKey, ICFIntTopDomainObj > >();
		}
		if( indexByTenantIdx.containsKey( key ) ) {
			Map<CFIntTopDomainPKey, ICFIntTopDomainObj> dict = indexByTenantIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().deleteTopDomainByTenantIdx( schema.getAuthorization(),
				TenantId );
			Iterator<ICFIntTopDomainObj> iter = dict.values().iterator();
			ICFIntTopDomainObj obj;
			List<ICFIntTopDomainObj> toForget = new LinkedList<ICFIntTopDomainObj>();
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
			((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().deleteTopDomainByTenantIdx( schema.getAuthorization(),
				TenantId );
		}
		deepDisposeTopDomainByTenantIdx( TenantId );
	}

	public void deleteTopDomainByTldIdx( long TenantId,
		long TldId )
	{
		CFIntTopDomainByTldIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newTldIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		if( indexByTldIdx == null ) {
			indexByTldIdx = new HashMap< CFIntTopDomainByTldIdxKey,
				Map< CFIntTopDomainPKey, ICFIntTopDomainObj > >();
		}
		if( indexByTldIdx.containsKey( key ) ) {
			Map<CFIntTopDomainPKey, ICFIntTopDomainObj> dict = indexByTldIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().deleteTopDomainByTldIdx( schema.getAuthorization(),
				TenantId,
				TldId );
			Iterator<ICFIntTopDomainObj> iter = dict.values().iterator();
			ICFIntTopDomainObj obj;
			List<ICFIntTopDomainObj> toForget = new LinkedList<ICFIntTopDomainObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByTldIdx.remove( key );
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().deleteTopDomainByTldIdx( schema.getAuthorization(),
				TenantId,
				TldId );
		}
		deepDisposeTopDomainByTldIdx( TenantId,
				TldId );
	}

	public void deleteTopDomainByNameIdx( long TenantId,
		long TldId,
		String Name )
	{
		if( indexByNameIdx == null ) {
			indexByNameIdx = new HashMap< CFIntTopDomainByNameIdxKey,
				ICFIntTopDomainObj >();
		}
		CFIntTopDomainByNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryTopDomain().newNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTldId( TldId );
		key.setRequiredName( Name );
		ICFIntTopDomainObj obj = null;
		if( indexByNameIdx.containsKey( key ) ) {
			obj = indexByNameIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().deleteTopDomainByNameIdx( schema.getAuthorization(),
				TenantId,
				TldId,
				Name );
			obj.forget();
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableTopDomain().deleteTopDomainByNameIdx( schema.getAuthorization(),
				TenantId,
				TldId,
				Name );
		}
		deepDisposeTopDomainByNameIdx( TenantId,
				TldId,
				Name );
	}
}