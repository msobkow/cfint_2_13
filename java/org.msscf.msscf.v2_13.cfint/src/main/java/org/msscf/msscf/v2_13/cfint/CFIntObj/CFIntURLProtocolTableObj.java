// Description: Java 11 Table Object implementation for CFInt.

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

public class CFIntURLProtocolTableObj
	implements ICFIntURLProtocolTableObj
{
	protected ICFIntSchemaObj schema;
	private Map<CFIntURLProtocolPKey, ICFIntURLProtocolObj> members;
	private Map<CFIntURLProtocolPKey, ICFIntURLProtocolObj> allURLProtocol;
	private Map< CFIntURLProtocolByUNameIdxKey,
		ICFIntURLProtocolObj > indexByUNameIdx;
	private Map< CFIntURLProtocolByIsSecureIdxKey,
		Map<CFIntURLProtocolPKey, ICFIntURLProtocolObj > > indexByIsSecureIdx;
	public static String TABLE_NAME = "URLProtocol";
	public static String TABLE_DBNAME = "urlproto";

	public CFIntURLProtocolTableObj() {
		schema = null;
		members = new HashMap<CFIntURLProtocolPKey, ICFIntURLProtocolObj>();
		allURLProtocol = null;
		indexByUNameIdx = null;
		indexByIsSecureIdx = null;
	}

	public CFIntURLProtocolTableObj( ICFIntSchemaObj argSchema ) {
		schema = (ICFIntSchemaObj)argSchema;
		members = new HashMap<CFIntURLProtocolPKey, ICFIntURLProtocolObj>();
		allURLProtocol = null;
		indexByUNameIdx = null;
		indexByIsSecureIdx = null;
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
		return( null );
	}


	public void minimizeMemory() {
		allURLProtocol = null;
		indexByUNameIdx = null;
		indexByIsSecureIdx = null;
		List<ICFIntURLProtocolObj> toForget = new LinkedList<ICFIntURLProtocolObj>();
		ICFIntURLProtocolObj cur = null;
		Iterator<ICFIntURLProtocolObj> iter = members.values().iterator();
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
	 *	CFIntURLProtocolObj.
	 */
	public ICFIntURLProtocolObj newInstance() {
		ICFIntURLProtocolObj inst = new CFIntURLProtocolObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFIntURLProtocolObj.
	 */
	public ICFIntURLProtocolEditObj newEditInstance( ICFIntURLProtocolObj orig ) {
		ICFIntURLProtocolEditObj edit = new CFIntURLProtocolEditObj( orig );
		return( edit );
	}

	public ICFIntURLProtocolObj realiseURLProtocol( ICFIntURLProtocolObj Obj ) {
		ICFIntURLProtocolObj obj = Obj;
		CFIntURLProtocolPKey pkey = obj.getPKey();
		ICFIntURLProtocolObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFIntURLProtocolObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByUNameIdx != null ) {
				CFIntURLProtocolByUNameIdxKey keyUNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newUNameIdxKey();
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.remove( keyUNameIdx );
			}

			if( indexByIsSecureIdx != null ) {
				CFIntURLProtocolByIsSecureIdxKey keyIsSecureIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newIsSecureIdxKey();
				keyIsSecureIdx.setRequiredIsSecure( keepObj.getRequiredIsSecure() );
				Map<CFIntURLProtocolPKey, ICFIntURLProtocolObj > mapIsSecureIdx = indexByIsSecureIdx.get( keyIsSecureIdx );
				if( mapIsSecureIdx != null ) {
					mapIsSecureIdx.remove( keepObj.getPKey() );
					if( mapIsSecureIdx.size() <= 0 ) {
						indexByIsSecureIdx.remove( keyIsSecureIdx );
					}
				}
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByUNameIdx != null ) {
				CFIntURLProtocolByUNameIdxKey keyUNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newUNameIdxKey();
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.put( keyUNameIdx, keepObj );
			}

			if( indexByIsSecureIdx != null ) {
				CFIntURLProtocolByIsSecureIdxKey keyIsSecureIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newIsSecureIdxKey();
				keyIsSecureIdx.setRequiredIsSecure( keepObj.getRequiredIsSecure() );
				Map<CFIntURLProtocolPKey, ICFIntURLProtocolObj > mapIsSecureIdx = indexByIsSecureIdx.get( keyIsSecureIdx );
				if( mapIsSecureIdx != null ) {
					mapIsSecureIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( allURLProtocol != null ) {
				allURLProtocol.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allURLProtocol != null ) {
				allURLProtocol.put( keepObj.getPKey(), keepObj );
			}

			if( indexByUNameIdx != null ) {
				CFIntURLProtocolByUNameIdxKey keyUNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newUNameIdxKey();
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.put( keyUNameIdx, keepObj );
			}

			if( indexByIsSecureIdx != null ) {
				CFIntURLProtocolByIsSecureIdxKey keyIsSecureIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newIsSecureIdxKey();
				keyIsSecureIdx.setRequiredIsSecure( keepObj.getRequiredIsSecure() );
				Map<CFIntURLProtocolPKey, ICFIntURLProtocolObj > mapIsSecureIdx = indexByIsSecureIdx.get( keyIsSecureIdx );
				if( mapIsSecureIdx != null ) {
					mapIsSecureIdx.put( keepObj.getPKey(), keepObj );
				}
			}

		}
		return( keepObj );
	}

	public ICFIntURLProtocolObj createURLProtocol( ICFIntURLProtocolObj Obj ) {
		ICFIntURLProtocolObj obj = Obj;
		CFIntURLProtocolBuff buff = obj.getURLProtocolBuff();
		((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().createURLProtocol(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFIntURLProtocolObj readURLProtocol( CFIntURLProtocolPKey pkey ) {
		return( readURLProtocol( pkey, false ) );
	}

	public ICFIntURLProtocolObj readURLProtocol( CFIntURLProtocolPKey pkey, boolean forceRead ) {
		ICFIntURLProtocolObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFIntURLProtocolBuff readBuff = ((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredURLProtocolId() );
			if( readBuff != null ) {
				obj = schema.getURLProtocolTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFIntURLProtocolObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFIntURLProtocolObj readCachedURLProtocol( CFIntURLProtocolPKey pkey ) {
		ICFIntURLProtocolObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeURLProtocol( ICFIntURLProtocolObj obj )
	{
		final String S_ProcName = "CFIntURLProtocolTableObj.reallyDeepDisposeURLProtocol() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFIntURLProtocolPKey pkey = obj.getPKey();
		ICFIntURLProtocolObj existing = readCachedURLProtocol( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFIntURLProtocolByUNameIdxKey keyUNameIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newUNameIdxKey();
		keyUNameIdx.setRequiredName( existing.getRequiredName() );

		CFIntURLProtocolByIsSecureIdxKey keyIsSecureIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newIsSecureIdxKey();
		keyIsSecureIdx.setRequiredIsSecure( existing.getRequiredIsSecure() );



		if( indexByUNameIdx != null ) {
			indexByUNameIdx.remove( keyUNameIdx );
		}

		if( indexByIsSecureIdx != null ) {
			if( indexByIsSecureIdx.containsKey( keyIsSecureIdx ) ) {
				indexByIsSecureIdx.get( keyIsSecureIdx ).remove( pkey );
				if( indexByIsSecureIdx.get( keyIsSecureIdx ).size() <= 0 ) {
					indexByIsSecureIdx.remove( keyIsSecureIdx );
				}
			}
		}


	}
	public void deepDisposeURLProtocol( CFIntURLProtocolPKey pkey ) {
		ICFIntURLProtocolObj obj = readCachedURLProtocol( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFIntURLProtocolObj lockURLProtocol( CFIntURLProtocolPKey pkey ) {
		ICFIntURLProtocolObj locked = null;
		CFIntURLProtocolBuff lockBuff = ((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getURLProtocolTableObj().newInstance();
			locked.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFIntURLProtocolObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockURLProtocol", pkey );
		}
		return( locked );
	}

	public List<ICFIntURLProtocolObj> readAllURLProtocol() {
		return( readAllURLProtocol( false ) );
	}

	public List<ICFIntURLProtocolObj> readAllURLProtocol( boolean forceRead ) {
		final String S_ProcName = "readAllURLProtocol";
		if( ( allURLProtocol == null ) || forceRead ) {
			Map<CFIntURLProtocolPKey, ICFIntURLProtocolObj> map = new HashMap<CFIntURLProtocolPKey,ICFIntURLProtocolObj>();
			allURLProtocol = map;
			CFIntURLProtocolBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().readAllDerived( schema.getAuthorization() );
			CFIntURLProtocolBuff buff;
			ICFIntURLProtocolObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newPKey() );
				obj.setBuff( buff );
				ICFIntURLProtocolObj realised = (ICFIntURLProtocolObj)obj.realise();
			}
		}
		int len = allURLProtocol.size();
		ICFIntURLProtocolObj arr[] = new ICFIntURLProtocolObj[len];
		Iterator<ICFIntURLProtocolObj> valIter = allURLProtocol.values().iterator();
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
		ArrayList<ICFIntURLProtocolObj> arrayList = new ArrayList<ICFIntURLProtocolObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntURLProtocolObj> cmp = new Comparator<ICFIntURLProtocolObj>() {
			public int compare( ICFIntURLProtocolObj lhs, ICFIntURLProtocolObj rhs ) {
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
					CFIntURLProtocolPKey lhsPKey = lhs.getPKey();
					CFIntURLProtocolPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntURLProtocolObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFIntURLProtocolObj> readCachedAllURLProtocol() {
		final String S_ProcName = "readCachedAllURLProtocol";
		ArrayList<ICFIntURLProtocolObj> arrayList = new ArrayList<ICFIntURLProtocolObj>();
		if( allURLProtocol != null ) {
			int len = allURLProtocol.size();
			ICFIntURLProtocolObj arr[] = new ICFIntURLProtocolObj[len];
			Iterator<ICFIntURLProtocolObj> valIter = allURLProtocol.values().iterator();
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
		Comparator<ICFIntURLProtocolObj> cmp = new Comparator<ICFIntURLProtocolObj>() {
			public int compare( ICFIntURLProtocolObj lhs, ICFIntURLProtocolObj rhs ) {
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
					CFIntURLProtocolPKey lhsPKey = lhs.getPKey();
					CFIntURLProtocolPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFIntURLProtocolObj readURLProtocolByIdIdx( int URLProtocolId )
	{
		return( readURLProtocolByIdIdx( URLProtocolId,
			false ) );
	}

	public ICFIntURLProtocolObj readURLProtocolByIdIdx( int URLProtocolId, boolean forceRead )
	{
		CFIntURLProtocolPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newPKey();
		pkey.setRequiredURLProtocolId( URLProtocolId );
		ICFIntURLProtocolObj obj = readURLProtocol( pkey, forceRead );
		return( obj );
	}

	public ICFIntURLProtocolObj readURLProtocolByUNameIdx( String Name )
	{
		return( readURLProtocolByUNameIdx( Name,
			false ) );
	}

	public ICFIntURLProtocolObj readURLProtocolByUNameIdx( String Name, boolean forceRead )
	{
		if( indexByUNameIdx == null ) {
			indexByUNameIdx = new HashMap< CFIntURLProtocolByUNameIdxKey,
				ICFIntURLProtocolObj >();
		}
		CFIntURLProtocolByUNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newUNameIdxKey();
		key.setRequiredName( Name );
		ICFIntURLProtocolObj obj = null;
		if( ( ! forceRead ) && indexByUNameIdx.containsKey( key ) ) {
			obj = indexByUNameIdx.get( key );
		}
		else {
			CFIntURLProtocolBuff buff = ((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().readDerivedByUNameIdx( schema.getAuthorization(),
				Name );
			if( buff != null ) {
				obj = schema.getURLProtocolTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newPKey() );
				obj.setBuff( buff );
				obj = (ICFIntURLProtocolObj)obj.realise();
			}
		}
		return( obj );
	}

	public List<ICFIntURLProtocolObj> readURLProtocolByIsSecureIdx( boolean IsSecure )
	{
		return( readURLProtocolByIsSecureIdx( IsSecure,
			false ) );
	}

	public List<ICFIntURLProtocolObj> readURLProtocolByIsSecureIdx( boolean IsSecure,
		boolean forceRead )
	{
		final String S_ProcName = "readURLProtocolByIsSecureIdx";
		CFIntURLProtocolByIsSecureIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newIsSecureIdxKey();
		key.setRequiredIsSecure( IsSecure );
		Map<CFIntURLProtocolPKey, ICFIntURLProtocolObj> dict;
		if( indexByIsSecureIdx == null ) {
			indexByIsSecureIdx = new HashMap< CFIntURLProtocolByIsSecureIdxKey,
				Map< CFIntURLProtocolPKey, ICFIntURLProtocolObj > >();
		}
		if( ( ! forceRead ) && indexByIsSecureIdx.containsKey( key ) ) {
			dict = indexByIsSecureIdx.get( key );
		}
		else {
			dict = new HashMap<CFIntURLProtocolPKey, ICFIntURLProtocolObj>();
			ICFIntURLProtocolObj obj;
			CFIntURLProtocolBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().readDerivedByIsSecureIdx( schema.getAuthorization(),
				IsSecure );
			CFIntURLProtocolBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getURLProtocolTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newPKey() );
				obj.setBuff( buff );
				ICFIntURLProtocolObj realised = (ICFIntURLProtocolObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByIsSecureIdx.put( key, dict );
		}
		int len = dict.size();
		ICFIntURLProtocolObj arr[] = new ICFIntURLProtocolObj[len];
		Iterator<ICFIntURLProtocolObj> valIter = dict.values().iterator();
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
		ArrayList<ICFIntURLProtocolObj> arrayList = new ArrayList<ICFIntURLProtocolObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntURLProtocolObj> cmp = new Comparator<ICFIntURLProtocolObj>() {
			public int compare( ICFIntURLProtocolObj lhs, ICFIntURLProtocolObj rhs ) {
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
					CFIntURLProtocolPKey lhsPKey = lhs.getPKey();
					CFIntURLProtocolPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntURLProtocolObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFIntURLProtocolObj readCachedURLProtocolByIdIdx( int URLProtocolId )
	{
		ICFIntURLProtocolObj obj = null;
		CFIntURLProtocolPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newPKey();
		pkey.setRequiredURLProtocolId( URLProtocolId );
		obj = readCachedURLProtocol( pkey );
		return( obj );
	}

	public ICFIntURLProtocolObj readCachedURLProtocolByUNameIdx( String Name )
	{
		ICFIntURLProtocolObj obj = null;
		CFIntURLProtocolByUNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newUNameIdxKey();
		key.setRequiredName( Name );
		if( indexByUNameIdx != null ) {
			if( indexByUNameIdx.containsKey( key ) ) {
				obj = indexByUNameIdx.get( key );
			}
			else {
				Iterator<ICFIntURLProtocolObj> valIter = members.values().iterator();
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
			Iterator<ICFIntURLProtocolObj> valIter = members.values().iterator();
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

	public List<ICFIntURLProtocolObj> readCachedURLProtocolByIsSecureIdx( boolean IsSecure )
	{
		final String S_ProcName = "readCachedURLProtocolByIsSecureIdx";
		CFIntURLProtocolByIsSecureIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newIsSecureIdxKey();
		key.setRequiredIsSecure( IsSecure );
		ArrayList<ICFIntURLProtocolObj> arrayList = new ArrayList<ICFIntURLProtocolObj>();
		if( indexByIsSecureIdx != null ) {
			Map<CFIntURLProtocolPKey, ICFIntURLProtocolObj> dict;
			if( indexByIsSecureIdx.containsKey( key ) ) {
				dict = indexByIsSecureIdx.get( key );
				int len = dict.size();
				ICFIntURLProtocolObj arr[] = new ICFIntURLProtocolObj[len];
				Iterator<ICFIntURLProtocolObj> valIter = dict.values().iterator();
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
			ICFIntURLProtocolObj obj;
			Iterator<ICFIntURLProtocolObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFIntURLProtocolObj> cmp = new Comparator<ICFIntURLProtocolObj>() {
			public int compare( ICFIntURLProtocolObj lhs, ICFIntURLProtocolObj rhs ) {
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
					CFIntURLProtocolPKey lhsPKey = lhs.getPKey();
					CFIntURLProtocolPKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public void deepDisposeURLProtocolByIdIdx( int URLProtocolId )
	{
		ICFIntURLProtocolObj obj = readCachedURLProtocolByIdIdx( URLProtocolId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeURLProtocolByUNameIdx( String Name )
	{
		ICFIntURLProtocolObj obj = readCachedURLProtocolByUNameIdx( Name );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeURLProtocolByIsSecureIdx( boolean IsSecure )
	{
		final String S_ProcName = "deepDisposeURLProtocolByIsSecureIdx";
		ICFIntURLProtocolObj obj;
		List<ICFIntURLProtocolObj> arrayList = readCachedURLProtocolByIsSecureIdx( IsSecure );
		if( arrayList != null )  {
			Iterator<ICFIntURLProtocolObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public ICFIntURLProtocolObj updateURLProtocol( ICFIntURLProtocolObj Obj ) {
		ICFIntURLProtocolObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().updateURLProtocol( schema.getAuthorization(),
			Obj.getURLProtocolBuff() );
		obj = (ICFIntURLProtocolObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteURLProtocol( ICFIntURLProtocolObj Obj ) {
		ICFIntURLProtocolObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().deleteURLProtocol( schema.getAuthorization(),
			obj.getURLProtocolBuff() );
		Obj.forget();
	}

	public void deleteURLProtocolByIdIdx( int URLProtocolId )
	{
		CFIntURLProtocolPKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newPKey();
		pkey.setRequiredURLProtocolId( URLProtocolId );
		ICFIntURLProtocolObj obj = readURLProtocol( pkey );
		if( obj != null ) {
			ICFIntURLProtocolEditObj editObj = (ICFIntURLProtocolEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFIntURLProtocolEditObj)obj.beginEdit();
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
		deepDisposeURLProtocolByIdIdx( URLProtocolId );
	}

	public void deleteURLProtocolByUNameIdx( String Name )
	{
		if( indexByUNameIdx == null ) {
			indexByUNameIdx = new HashMap< CFIntURLProtocolByUNameIdxKey,
				ICFIntURLProtocolObj >();
		}
		CFIntURLProtocolByUNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newUNameIdxKey();
		key.setRequiredName( Name );
		ICFIntURLProtocolObj obj = null;
		if( indexByUNameIdx.containsKey( key ) ) {
			obj = indexByUNameIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().deleteURLProtocolByUNameIdx( schema.getAuthorization(),
				Name );
			obj.forget();
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().deleteURLProtocolByUNameIdx( schema.getAuthorization(),
				Name );
		}
		deepDisposeURLProtocolByUNameIdx( Name );
	}

	public void deleteURLProtocolByIsSecureIdx( boolean IsSecure )
	{
		CFIntURLProtocolByIsSecureIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryURLProtocol().newIsSecureIdxKey();
		key.setRequiredIsSecure( IsSecure );
		if( indexByIsSecureIdx == null ) {
			indexByIsSecureIdx = new HashMap< CFIntURLProtocolByIsSecureIdxKey,
				Map< CFIntURLProtocolPKey, ICFIntURLProtocolObj > >();
		}
		if( indexByIsSecureIdx.containsKey( key ) ) {
			Map<CFIntURLProtocolPKey, ICFIntURLProtocolObj> dict = indexByIsSecureIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().deleteURLProtocolByIsSecureIdx( schema.getAuthorization(),
				IsSecure );
			Iterator<ICFIntURLProtocolObj> iter = dict.values().iterator();
			ICFIntURLProtocolObj obj;
			List<ICFIntURLProtocolObj> toForget = new LinkedList<ICFIntURLProtocolObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByIsSecureIdx.remove( key );
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableURLProtocol().deleteURLProtocolByIsSecureIdx( schema.getAuthorization(),
				IsSecure );
		}
		deepDisposeURLProtocolByIsSecureIdx( IsSecure );
	}
}
