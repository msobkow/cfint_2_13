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

public class CFIntSubProjectTableObj
	implements ICFIntSubProjectTableObj
{
	protected ICFIntSchemaObj schema;
	private Map<CFIntSubProjectPKey, ICFIntSubProjectObj> members;
	private Map<CFIntSubProjectPKey, ICFIntSubProjectObj> allSubProject;
	private Map< CFIntSubProjectByTenantIdxKey,
		Map<CFIntSubProjectPKey, ICFIntSubProjectObj > > indexByTenantIdx;
	private Map< CFIntSubProjectByTopProjectIdxKey,
		Map<CFIntSubProjectPKey, ICFIntSubProjectObj > > indexByTopProjectIdx;
	private Map< CFIntSubProjectByNameIdxKey,
		ICFIntSubProjectObj > indexByNameIdx;
	public static String TABLE_NAME = "SubProject";
	public static String TABLE_DBNAME = "sprjdef";

	public CFIntSubProjectTableObj() {
		schema = null;
		members = new HashMap<CFIntSubProjectPKey, ICFIntSubProjectObj>();
		allSubProject = null;
		indexByTenantIdx = null;
		indexByTopProjectIdx = null;
		indexByNameIdx = null;
	}

	public CFIntSubProjectTableObj( ICFIntSchemaObj argSchema ) {
		schema = (ICFIntSchemaObj)argSchema;
		members = new HashMap<CFIntSubProjectPKey, ICFIntSubProjectObj>();
		allSubProject = null;
		indexByTenantIdx = null;
		indexByTopProjectIdx = null;
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
		allSubProject = null;
		indexByTenantIdx = null;
		indexByTopProjectIdx = null;
		indexByNameIdx = null;
		List<ICFIntSubProjectObj> toForget = new LinkedList<ICFIntSubProjectObj>();
		ICFIntSubProjectObj cur = null;
		Iterator<ICFIntSubProjectObj> iter = members.values().iterator();
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
	 *	CFIntSubProjectObj.
	 */
	public ICFIntSubProjectObj newInstance() {
		ICFIntSubProjectObj inst = new CFIntSubProjectObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFIntSubProjectObj.
	 */
	public ICFIntSubProjectEditObj newEditInstance( ICFIntSubProjectObj orig ) {
		ICFIntSubProjectEditObj edit = new CFIntSubProjectEditObj( orig );
		return( edit );
	}

	public ICFIntSubProjectObj realiseSubProject( ICFIntSubProjectObj Obj ) {
		ICFIntSubProjectObj obj = Obj;
		CFIntSubProjectPKey pkey = obj.getPKey();
		ICFIntSubProjectObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFIntSubProjectObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByTenantIdx != null ) {
				CFIntSubProjectByTenantIdxKey keyTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntSubProjectPKey, ICFIntSubProjectObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.remove( keepObj.getPKey() );
					if( mapTenantIdx.size() <= 0 ) {
						indexByTenantIdx.remove( keyTenantIdx );
					}
				}
			}

			if( indexByTopProjectIdx != null ) {
				CFIntSubProjectByTopProjectIdxKey keyTopProjectIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTopProjectIdxKey();
				keyTopProjectIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyTopProjectIdx.setRequiredTopProjectId( keepObj.getRequiredTopProjectId() );
				Map<CFIntSubProjectPKey, ICFIntSubProjectObj > mapTopProjectIdx = indexByTopProjectIdx.get( keyTopProjectIdx );
				if( mapTopProjectIdx != null ) {
					mapTopProjectIdx.remove( keepObj.getPKey() );
					if( mapTopProjectIdx.size() <= 0 ) {
						indexByTopProjectIdx.remove( keyTopProjectIdx );
					}
				}
			}

			if( indexByNameIdx != null ) {
				CFIntSubProjectByNameIdxKey keyNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newNameIdxKey();
				keyNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyNameIdx.setRequiredTopProjectId( keepObj.getRequiredTopProjectId() );
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.remove( keyNameIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByTenantIdx != null ) {
				CFIntSubProjectByTenantIdxKey keyTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntSubProjectPKey, ICFIntSubProjectObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByTopProjectIdx != null ) {
				CFIntSubProjectByTopProjectIdxKey keyTopProjectIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTopProjectIdxKey();
				keyTopProjectIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyTopProjectIdx.setRequiredTopProjectId( keepObj.getRequiredTopProjectId() );
				Map<CFIntSubProjectPKey, ICFIntSubProjectObj > mapTopProjectIdx = indexByTopProjectIdx.get( keyTopProjectIdx );
				if( mapTopProjectIdx != null ) {
					mapTopProjectIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByNameIdx != null ) {
				CFIntSubProjectByNameIdxKey keyNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newNameIdxKey();
				keyNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyNameIdx.setRequiredTopProjectId( keepObj.getRequiredTopProjectId() );
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.put( keyNameIdx, keepObj );
			}

			if( allSubProject != null ) {
				allSubProject.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allSubProject != null ) {
				allSubProject.put( keepObj.getPKey(), keepObj );
			}

			if( indexByTenantIdx != null ) {
				CFIntSubProjectByTenantIdxKey keyTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTenantIdxKey();
				keyTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntSubProjectPKey, ICFIntSubProjectObj > mapTenantIdx = indexByTenantIdx.get( keyTenantIdx );
				if( mapTenantIdx != null ) {
					mapTenantIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByTopProjectIdx != null ) {
				CFIntSubProjectByTopProjectIdxKey keyTopProjectIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTopProjectIdxKey();
				keyTopProjectIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyTopProjectIdx.setRequiredTopProjectId( keepObj.getRequiredTopProjectId() );
				Map<CFIntSubProjectPKey, ICFIntSubProjectObj > mapTopProjectIdx = indexByTopProjectIdx.get( keyTopProjectIdx );
				if( mapTopProjectIdx != null ) {
					mapTopProjectIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByNameIdx != null ) {
				CFIntSubProjectByNameIdxKey keyNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newNameIdxKey();
				keyNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyNameIdx.setRequiredTopProjectId( keepObj.getRequiredTopProjectId() );
				keyNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByNameIdx.put( keyNameIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFIntSubProjectObj createSubProject( ICFIntSubProjectObj Obj ) {
		ICFIntSubProjectObj obj = Obj;
		CFIntSubProjectBuff buff = obj.getSubProjectBuff();
		((ICFIntSchema)schema.getBackingStore()).getTableSubProject().createSubProject(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFIntSubProjectObj readSubProject( CFIntSubProjectPKey pkey ) {
		return( readSubProject( pkey, false ) );
	}

	public ICFIntSubProjectObj readSubProject( CFIntSubProjectPKey pkey, boolean forceRead ) {
		ICFIntSubProjectObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFIntSubProjectBuff readBuff = ((ICFIntSchema)schema.getBackingStore()).getTableSubProject().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredTenantId(),
				pkey.getRequiredId() );
			if( readBuff != null ) {
				obj = schema.getSubProjectTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFIntSubProjectObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFIntSubProjectObj readCachedSubProject( CFIntSubProjectPKey pkey ) {
		ICFIntSubProjectObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeSubProject( ICFIntSubProjectObj obj )
	{
		final String S_ProcName = "CFIntSubProjectTableObj.reallyDeepDisposeSubProject() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFIntSubProjectPKey pkey = obj.getPKey();
		ICFIntSubProjectObj existing = readCachedSubProject( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFIntSubProjectByTenantIdxKey keyTenantIdx = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTenantIdxKey();
		keyTenantIdx.setRequiredTenantId( existing.getRequiredTenantId() );

		CFIntSubProjectByTopProjectIdxKey keyTopProjectIdx = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTopProjectIdxKey();
		keyTopProjectIdx.setRequiredTenantId( existing.getRequiredTenantId() );
		keyTopProjectIdx.setRequiredTopProjectId( existing.getRequiredTopProjectId() );

		CFIntSubProjectByNameIdxKey keyNameIdx = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newNameIdxKey();
		keyNameIdx.setRequiredTenantId( existing.getRequiredTenantId() );
		keyNameIdx.setRequiredTopProjectId( existing.getRequiredTopProjectId() );
		keyNameIdx.setRequiredName( existing.getRequiredName() );


					schema.getMajorVersionTableObj().deepDisposeMajorVersionBySubProjectIdx( existing.getRequiredTenantId(),
						existing.getRequiredId() );

		if( indexByTenantIdx != null ) {
			if( indexByTenantIdx.containsKey( keyTenantIdx ) ) {
				indexByTenantIdx.get( keyTenantIdx ).remove( pkey );
				if( indexByTenantIdx.get( keyTenantIdx ).size() <= 0 ) {
					indexByTenantIdx.remove( keyTenantIdx );
				}
			}
		}

		if( indexByTopProjectIdx != null ) {
			if( indexByTopProjectIdx.containsKey( keyTopProjectIdx ) ) {
				indexByTopProjectIdx.get( keyTopProjectIdx ).remove( pkey );
				if( indexByTopProjectIdx.get( keyTopProjectIdx ).size() <= 0 ) {
					indexByTopProjectIdx.remove( keyTopProjectIdx );
				}
			}
		}

		if( indexByNameIdx != null ) {
			indexByNameIdx.remove( keyNameIdx );
		}


	}
	public void deepDisposeSubProject( CFIntSubProjectPKey pkey ) {
		ICFIntSubProjectObj obj = readCachedSubProject( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFIntSubProjectObj lockSubProject( CFIntSubProjectPKey pkey ) {
		ICFIntSubProjectObj locked = null;
		CFIntSubProjectBuff lockBuff = ((ICFIntSchema)schema.getBackingStore()).getTableSubProject().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getSubProjectTableObj().newInstance();
			locked.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFIntSubProjectObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockSubProject", pkey );
		}
		return( locked );
	}

	public List<ICFIntSubProjectObj> readAllSubProject() {
		return( readAllSubProject( false ) );
	}

	public List<ICFIntSubProjectObj> readAllSubProject( boolean forceRead ) {
		final String S_ProcName = "readAllSubProject";
		if( ( allSubProject == null ) || forceRead ) {
			Map<CFIntSubProjectPKey, ICFIntSubProjectObj> map = new HashMap<CFIntSubProjectPKey,ICFIntSubProjectObj>();
			allSubProject = map;
			CFIntSubProjectBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableSubProject().readAllDerived( schema.getAuthorization() );
			CFIntSubProjectBuff buff;
			ICFIntSubProjectObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newPKey() );
				obj.setBuff( buff );
				ICFIntSubProjectObj realised = (ICFIntSubProjectObj)obj.realise();
			}
		}
		int len = allSubProject.size();
		ICFIntSubProjectObj arr[] = new ICFIntSubProjectObj[len];
		Iterator<ICFIntSubProjectObj> valIter = allSubProject.values().iterator();
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
		ArrayList<ICFIntSubProjectObj> arrayList = new ArrayList<ICFIntSubProjectObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntSubProjectObj> cmp = new Comparator<ICFIntSubProjectObj>() {
			public int compare( ICFIntSubProjectObj lhs, ICFIntSubProjectObj rhs ) {
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
					CFIntSubProjectPKey lhsPKey = lhs.getPKey();
					CFIntSubProjectPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntSubProjectObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFIntSubProjectObj> readCachedAllSubProject() {
		final String S_ProcName = "readCachedAllSubProject";
		ArrayList<ICFIntSubProjectObj> arrayList = new ArrayList<ICFIntSubProjectObj>();
		if( allSubProject != null ) {
			int len = allSubProject.size();
			ICFIntSubProjectObj arr[] = new ICFIntSubProjectObj[len];
			Iterator<ICFIntSubProjectObj> valIter = allSubProject.values().iterator();
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
		Comparator<ICFIntSubProjectObj> cmp = new Comparator<ICFIntSubProjectObj>() {
			public int compare( ICFIntSubProjectObj lhs, ICFIntSubProjectObj rhs ) {
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
					CFIntSubProjectPKey lhsPKey = lhs.getPKey();
					CFIntSubProjectPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFIntSubProjectObj readSubProjectByIdIdx( long TenantId,
		long Id )
	{
		return( readSubProjectByIdIdx( TenantId,
			Id,
			false ) );
	}

	public ICFIntSubProjectObj readSubProjectByIdIdx( long TenantId,
		long Id, boolean forceRead )
	{
		CFIntSubProjectPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		ICFIntSubProjectObj obj = readSubProject( pkey, forceRead );
		return( obj );
	}

	public List<ICFIntSubProjectObj> readSubProjectByTenantIdx( long TenantId )
	{
		return( readSubProjectByTenantIdx( TenantId,
			false ) );
	}

	public List<ICFIntSubProjectObj> readSubProjectByTenantIdx( long TenantId,
		boolean forceRead )
	{
		final String S_ProcName = "readSubProjectByTenantIdx";
		CFIntSubProjectByTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		Map<CFIntSubProjectPKey, ICFIntSubProjectObj> dict;
		if( indexByTenantIdx == null ) {
			indexByTenantIdx = new HashMap< CFIntSubProjectByTenantIdxKey,
				Map< CFIntSubProjectPKey, ICFIntSubProjectObj > >();
		}
		if( ( ! forceRead ) && indexByTenantIdx.containsKey( key ) ) {
			dict = indexByTenantIdx.get( key );
		}
		else {
			dict = new HashMap<CFIntSubProjectPKey, ICFIntSubProjectObj>();
			ICFIntSubProjectObj obj;
			CFIntSubProjectBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableSubProject().readDerivedByTenantIdx( schema.getAuthorization(),
				TenantId );
			CFIntSubProjectBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getSubProjectTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newPKey() );
				obj.setBuff( buff );
				ICFIntSubProjectObj realised = (ICFIntSubProjectObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByTenantIdx.put( key, dict );
		}
		int len = dict.size();
		ICFIntSubProjectObj arr[] = new ICFIntSubProjectObj[len];
		Iterator<ICFIntSubProjectObj> valIter = dict.values().iterator();
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
		ArrayList<ICFIntSubProjectObj> arrayList = new ArrayList<ICFIntSubProjectObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntSubProjectObj> cmp = new Comparator<ICFIntSubProjectObj>() {
			public int compare( ICFIntSubProjectObj lhs, ICFIntSubProjectObj rhs ) {
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
					CFIntSubProjectPKey lhsPKey = lhs.getPKey();
					CFIntSubProjectPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntSubProjectObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFIntSubProjectObj> readSubProjectByTopProjectIdx( long TenantId,
		long TopProjectId )
	{
		return( readSubProjectByTopProjectIdx( TenantId,
			TopProjectId,
			false ) );
	}

	public List<ICFIntSubProjectObj> readSubProjectByTopProjectIdx( long TenantId,
		long TopProjectId,
		boolean forceRead )
	{
		final String S_ProcName = "readSubProjectByTopProjectIdx";
		CFIntSubProjectByTopProjectIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTopProjectIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		Map<CFIntSubProjectPKey, ICFIntSubProjectObj> dict;
		if( indexByTopProjectIdx == null ) {
			indexByTopProjectIdx = new HashMap< CFIntSubProjectByTopProjectIdxKey,
				Map< CFIntSubProjectPKey, ICFIntSubProjectObj > >();
		}
		if( ( ! forceRead ) && indexByTopProjectIdx.containsKey( key ) ) {
			dict = indexByTopProjectIdx.get( key );
		}
		else {
			dict = new HashMap<CFIntSubProjectPKey, ICFIntSubProjectObj>();
			ICFIntSubProjectObj obj;
			CFIntSubProjectBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableSubProject().readDerivedByTopProjectIdx( schema.getAuthorization(),
				TenantId,
				TopProjectId );
			CFIntSubProjectBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getSubProjectTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newPKey() );
				obj.setBuff( buff );
				ICFIntSubProjectObj realised = (ICFIntSubProjectObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByTopProjectIdx.put( key, dict );
		}
		int len = dict.size();
		ICFIntSubProjectObj arr[] = new ICFIntSubProjectObj[len];
		Iterator<ICFIntSubProjectObj> valIter = dict.values().iterator();
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
		ArrayList<ICFIntSubProjectObj> arrayList = new ArrayList<ICFIntSubProjectObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntSubProjectObj> cmp = new Comparator<ICFIntSubProjectObj>() {
			public int compare( ICFIntSubProjectObj lhs, ICFIntSubProjectObj rhs ) {
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
					CFIntSubProjectPKey lhsPKey = lhs.getPKey();
					CFIntSubProjectPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntSubProjectObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFIntSubProjectObj readSubProjectByNameIdx( long TenantId,
		long TopProjectId,
		String Name )
	{
		return( readSubProjectByNameIdx( TenantId,
			TopProjectId,
			Name,
			false ) );
	}

	public ICFIntSubProjectObj readSubProjectByNameIdx( long TenantId,
		long TopProjectId,
		String Name, boolean forceRead )
	{
		if( indexByNameIdx == null ) {
			indexByNameIdx = new HashMap< CFIntSubProjectByNameIdxKey,
				ICFIntSubProjectObj >();
		}
		CFIntSubProjectByNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		key.setRequiredName( Name );
		ICFIntSubProjectObj obj = null;
		if( ( ! forceRead ) && indexByNameIdx.containsKey( key ) ) {
			obj = indexByNameIdx.get( key );
		}
		else {
			CFIntSubProjectBuff buff = ((ICFIntSchema)schema.getBackingStore()).getTableSubProject().readDerivedByNameIdx( schema.getAuthorization(),
				TenantId,
				TopProjectId,
				Name );
			if( buff != null ) {
				obj = schema.getSubProjectTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newPKey() );
				obj.setBuff( buff );
				obj = (ICFIntSubProjectObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFIntSubProjectObj readCachedSubProjectByIdIdx( long TenantId,
		long Id )
	{
		ICFIntSubProjectObj obj = null;
		CFIntSubProjectPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		obj = readCachedSubProject( pkey );
		return( obj );
	}

	public List<ICFIntSubProjectObj> readCachedSubProjectByTenantIdx( long TenantId )
	{
		final String S_ProcName = "readCachedSubProjectByTenantIdx";
		CFIntSubProjectByTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		ArrayList<ICFIntSubProjectObj> arrayList = new ArrayList<ICFIntSubProjectObj>();
		if( indexByTenantIdx != null ) {
			Map<CFIntSubProjectPKey, ICFIntSubProjectObj> dict;
			if( indexByTenantIdx.containsKey( key ) ) {
				dict = indexByTenantIdx.get( key );
				int len = dict.size();
				ICFIntSubProjectObj arr[] = new ICFIntSubProjectObj[len];
				Iterator<ICFIntSubProjectObj> valIter = dict.values().iterator();
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
			ICFIntSubProjectObj obj;
			Iterator<ICFIntSubProjectObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFIntSubProjectObj> cmp = new Comparator<ICFIntSubProjectObj>() {
			public int compare( ICFIntSubProjectObj lhs, ICFIntSubProjectObj rhs ) {
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
					CFIntSubProjectPKey lhsPKey = lhs.getPKey();
					CFIntSubProjectPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFIntSubProjectObj> readCachedSubProjectByTopProjectIdx( long TenantId,
		long TopProjectId )
	{
		final String S_ProcName = "readCachedSubProjectByTopProjectIdx";
		CFIntSubProjectByTopProjectIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTopProjectIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		ArrayList<ICFIntSubProjectObj> arrayList = new ArrayList<ICFIntSubProjectObj>();
		if( indexByTopProjectIdx != null ) {
			Map<CFIntSubProjectPKey, ICFIntSubProjectObj> dict;
			if( indexByTopProjectIdx.containsKey( key ) ) {
				dict = indexByTopProjectIdx.get( key );
				int len = dict.size();
				ICFIntSubProjectObj arr[] = new ICFIntSubProjectObj[len];
				Iterator<ICFIntSubProjectObj> valIter = dict.values().iterator();
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
			ICFIntSubProjectObj obj;
			Iterator<ICFIntSubProjectObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFIntSubProjectObj> cmp = new Comparator<ICFIntSubProjectObj>() {
			public int compare( ICFIntSubProjectObj lhs, ICFIntSubProjectObj rhs ) {
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
					CFIntSubProjectPKey lhsPKey = lhs.getPKey();
					CFIntSubProjectPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFIntSubProjectObj readCachedSubProjectByNameIdx( long TenantId,
		long TopProjectId,
		String Name )
	{
		ICFIntSubProjectObj obj = null;
		CFIntSubProjectByNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		key.setRequiredName( Name );
		if( indexByNameIdx != null ) {
			if( indexByNameIdx.containsKey( key ) ) {
				obj = indexByNameIdx.get( key );
			}
			else {
				Iterator<ICFIntSubProjectObj> valIter = members.values().iterator();
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
			Iterator<ICFIntSubProjectObj> valIter = members.values().iterator();
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

	public void deepDisposeSubProjectByIdIdx( long TenantId,
		long Id )
	{
		ICFIntSubProjectObj obj = readCachedSubProjectByIdIdx( TenantId,
				Id );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeSubProjectByTenantIdx( long TenantId )
	{
		final String S_ProcName = "deepDisposeSubProjectByTenantIdx";
		ICFIntSubProjectObj obj;
		List<ICFIntSubProjectObj> arrayList = readCachedSubProjectByTenantIdx( TenantId );
		if( arrayList != null )  {
			Iterator<ICFIntSubProjectObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeSubProjectByTopProjectIdx( long TenantId,
		long TopProjectId )
	{
		final String S_ProcName = "deepDisposeSubProjectByTopProjectIdx";
		ICFIntSubProjectObj obj;
		List<ICFIntSubProjectObj> arrayList = readCachedSubProjectByTopProjectIdx( TenantId,
				TopProjectId );
		if( arrayList != null )  {
			Iterator<ICFIntSubProjectObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeSubProjectByNameIdx( long TenantId,
		long TopProjectId,
		String Name )
	{
		ICFIntSubProjectObj obj = readCachedSubProjectByNameIdx( TenantId,
				TopProjectId,
				Name );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFIntSubProjectObj updateSubProject( ICFIntSubProjectObj Obj ) {
		ICFIntSubProjectObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableSubProject().updateSubProject( schema.getAuthorization(),
			Obj.getSubProjectBuff() );
		obj = (ICFIntSubProjectObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteSubProject( ICFIntSubProjectObj Obj ) {
		ICFIntSubProjectObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableSubProject().deleteSubProject( schema.getAuthorization(),
			obj.getSubProjectBuff() );
		Obj.forget();
	}

	public void deleteSubProjectByIdIdx( long TenantId,
		long Id )
	{
		CFIntSubProjectPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		ICFIntSubProjectObj obj = readSubProject( pkey );
		if( obj != null ) {
			ICFIntSubProjectEditObj editObj = (ICFIntSubProjectEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFIntSubProjectEditObj)obj.beginEdit();
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
		deepDisposeSubProjectByIdIdx( TenantId,
				Id );
	}

	public void deleteSubProjectByTenantIdx( long TenantId )
	{
		CFIntSubProjectByTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		if( indexByTenantIdx == null ) {
			indexByTenantIdx = new HashMap< CFIntSubProjectByTenantIdxKey,
				Map< CFIntSubProjectPKey, ICFIntSubProjectObj > >();
		}
		if( indexByTenantIdx.containsKey( key ) ) {
			Map<CFIntSubProjectPKey, ICFIntSubProjectObj> dict = indexByTenantIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableSubProject().deleteSubProjectByTenantIdx( schema.getAuthorization(),
				TenantId );
			Iterator<ICFIntSubProjectObj> iter = dict.values().iterator();
			ICFIntSubProjectObj obj;
			List<ICFIntSubProjectObj> toForget = new LinkedList<ICFIntSubProjectObj>();
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
			((ICFIntSchema)schema.getBackingStore()).getTableSubProject().deleteSubProjectByTenantIdx( schema.getAuthorization(),
				TenantId );
		}
		deepDisposeSubProjectByTenantIdx( TenantId );
	}

	public void deleteSubProjectByTopProjectIdx( long TenantId,
		long TopProjectId )
	{
		CFIntSubProjectByTopProjectIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newTopProjectIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		if( indexByTopProjectIdx == null ) {
			indexByTopProjectIdx = new HashMap< CFIntSubProjectByTopProjectIdxKey,
				Map< CFIntSubProjectPKey, ICFIntSubProjectObj > >();
		}
		if( indexByTopProjectIdx.containsKey( key ) ) {
			Map<CFIntSubProjectPKey, ICFIntSubProjectObj> dict = indexByTopProjectIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableSubProject().deleteSubProjectByTopProjectIdx( schema.getAuthorization(),
				TenantId,
				TopProjectId );
			Iterator<ICFIntSubProjectObj> iter = dict.values().iterator();
			ICFIntSubProjectObj obj;
			List<ICFIntSubProjectObj> toForget = new LinkedList<ICFIntSubProjectObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByTopProjectIdx.remove( key );
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableSubProject().deleteSubProjectByTopProjectIdx( schema.getAuthorization(),
				TenantId,
				TopProjectId );
		}
		deepDisposeSubProjectByTopProjectIdx( TenantId,
				TopProjectId );
	}

	public void deleteSubProjectByNameIdx( long TenantId,
		long TopProjectId,
		String Name )
	{
		if( indexByNameIdx == null ) {
			indexByNameIdx = new HashMap< CFIntSubProjectByNameIdxKey,
				ICFIntSubProjectObj >();
		}
		CFIntSubProjectByNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactorySubProject().newNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopProjectId( TopProjectId );
		key.setRequiredName( Name );
		ICFIntSubProjectObj obj = null;
		if( indexByNameIdx.containsKey( key ) ) {
			obj = indexByNameIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableSubProject().deleteSubProjectByNameIdx( schema.getAuthorization(),
				TenantId,
				TopProjectId,
				Name );
			obj.forget();
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableSubProject().deleteSubProjectByNameIdx( schema.getAuthorization(),
				TenantId,
				TopProjectId,
				Name );
		}
		deepDisposeSubProjectByNameIdx( TenantId,
				TopProjectId,
				Name );
	}
}