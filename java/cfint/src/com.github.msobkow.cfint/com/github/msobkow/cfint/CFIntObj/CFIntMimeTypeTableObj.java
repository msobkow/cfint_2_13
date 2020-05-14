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

public class CFIntMimeTypeTableObj
	implements ICFIntMimeTypeTableObj
{
	protected ICFIntSchemaObj schema;
	private Map<CFIntMimeTypePKey, ICFIntMimeTypeObj> members;
	private Map<CFIntMimeTypePKey, ICFIntMimeTypeObj> allMimeType;
	private Map< CFIntMimeTypeByUNameIdxKey,
		ICFIntMimeTypeObj > indexByUNameIdx;
	public static String TABLE_NAME = "MimeType";
	public static String TABLE_DBNAME = "mimetype";

	public CFIntMimeTypeTableObj() {
		schema = null;
		members = new HashMap<CFIntMimeTypePKey, ICFIntMimeTypeObj>();
		allMimeType = null;
		indexByUNameIdx = null;
	}

	public CFIntMimeTypeTableObj( ICFIntSchemaObj argSchema ) {
		schema = (ICFIntSchemaObj)argSchema;
		members = new HashMap<CFIntMimeTypePKey, ICFIntMimeTypeObj>();
		allMimeType = null;
		indexByUNameIdx = null;
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
		allMimeType = null;
		indexByUNameIdx = null;
		List<ICFIntMimeTypeObj> toForget = new LinkedList<ICFIntMimeTypeObj>();
		ICFIntMimeTypeObj cur = null;
		Iterator<ICFIntMimeTypeObj> iter = members.values().iterator();
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
	 *	CFIntMimeTypeObj.
	 */
	public ICFIntMimeTypeObj newInstance() {
		ICFIntMimeTypeObj inst = new CFIntMimeTypeObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFIntMimeTypeObj.
	 */
	public ICFIntMimeTypeEditObj newEditInstance( ICFIntMimeTypeObj orig ) {
		ICFIntMimeTypeEditObj edit = new CFIntMimeTypeEditObj( orig );
		return( edit );
	}

	public ICFIntMimeTypeObj realiseMimeType( ICFIntMimeTypeObj Obj ) {
		ICFIntMimeTypeObj obj = Obj;
		CFIntMimeTypePKey pkey = obj.getPKey();
		ICFIntMimeTypeObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFIntMimeTypeObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByUNameIdx != null ) {
				CFIntMimeTypeByUNameIdxKey keyUNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newUNameIdxKey();
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.remove( keyUNameIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByUNameIdx != null ) {
				CFIntMimeTypeByUNameIdxKey keyUNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newUNameIdxKey();
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.put( keyUNameIdx, keepObj );
			}

			if( allMimeType != null ) {
				allMimeType.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allMimeType != null ) {
				allMimeType.put( keepObj.getPKey(), keepObj );
			}

			if( indexByUNameIdx != null ) {
				CFIntMimeTypeByUNameIdxKey keyUNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newUNameIdxKey();
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.put( keyUNameIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFIntMimeTypeObj createMimeType( ICFIntMimeTypeObj Obj ) {
		ICFIntMimeTypeObj obj = Obj;
		CFIntMimeTypeBuff buff = obj.getMimeTypeBuff();
		((ICFIntSchema)schema.getBackingStore()).getTableMimeType().createMimeType(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFIntMimeTypeObj readMimeType( CFIntMimeTypePKey pkey ) {
		return( readMimeType( pkey, false ) );
	}

	public ICFIntMimeTypeObj readMimeType( CFIntMimeTypePKey pkey, boolean forceRead ) {
		ICFIntMimeTypeObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFIntMimeTypeBuff readBuff = ((ICFIntSchema)schema.getBackingStore()).getTableMimeType().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredMimeTypeId() );
			if( readBuff != null ) {
				obj = schema.getMimeTypeTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFIntMimeTypeObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFIntMimeTypeObj readCachedMimeType( CFIntMimeTypePKey pkey ) {
		ICFIntMimeTypeObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeMimeType( ICFIntMimeTypeObj obj )
	{
		final String S_ProcName = "CFIntMimeTypeTableObj.reallyDeepDisposeMimeType() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFIntMimeTypePKey pkey = obj.getPKey();
		ICFIntMimeTypeObj existing = readCachedMimeType( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFIntMimeTypeByUNameIdxKey keyUNameIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newUNameIdxKey();
		keyUNameIdx.setRequiredName( existing.getRequiredName() );



		if( indexByUNameIdx != null ) {
			indexByUNameIdx.remove( keyUNameIdx );
		}


	}
	public void deepDisposeMimeType( CFIntMimeTypePKey pkey ) {
		ICFIntMimeTypeObj obj = readCachedMimeType( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFIntMimeTypeObj lockMimeType( CFIntMimeTypePKey pkey ) {
		ICFIntMimeTypeObj locked = null;
		CFIntMimeTypeBuff lockBuff = ((ICFIntSchema)schema.getBackingStore()).getTableMimeType().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getMimeTypeTableObj().newInstance();
			locked.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFIntMimeTypeObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockMimeType", pkey );
		}
		return( locked );
	}

	public List<ICFIntMimeTypeObj> readAllMimeType() {
		return( readAllMimeType( false ) );
	}

	public List<ICFIntMimeTypeObj> readAllMimeType( boolean forceRead ) {
		final String S_ProcName = "readAllMimeType";
		if( ( allMimeType == null ) || forceRead ) {
			Map<CFIntMimeTypePKey, ICFIntMimeTypeObj> map = new HashMap<CFIntMimeTypePKey,ICFIntMimeTypeObj>();
			allMimeType = map;
			CFIntMimeTypeBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableMimeType().readAllDerived( schema.getAuthorization() );
			CFIntMimeTypeBuff buff;
			ICFIntMimeTypeObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newPKey() );
				obj.setBuff( buff );
				ICFIntMimeTypeObj realised = (ICFIntMimeTypeObj)obj.realise();
			}
		}
		int len = allMimeType.size();
		ICFIntMimeTypeObj arr[] = new ICFIntMimeTypeObj[len];
		Iterator<ICFIntMimeTypeObj> valIter = allMimeType.values().iterator();
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
		ArrayList<ICFIntMimeTypeObj> arrayList = new ArrayList<ICFIntMimeTypeObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntMimeTypeObj> cmp = new Comparator<ICFIntMimeTypeObj>() {
			public int compare( ICFIntMimeTypeObj lhs, ICFIntMimeTypeObj rhs ) {
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
					CFIntMimeTypePKey lhsPKey = lhs.getPKey();
					CFIntMimeTypePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntMimeTypeObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFIntMimeTypeObj> readCachedAllMimeType() {
		final String S_ProcName = "readCachedAllMimeType";
		ArrayList<ICFIntMimeTypeObj> arrayList = new ArrayList<ICFIntMimeTypeObj>();
		if( allMimeType != null ) {
			int len = allMimeType.size();
			ICFIntMimeTypeObj arr[] = new ICFIntMimeTypeObj[len];
			Iterator<ICFIntMimeTypeObj> valIter = allMimeType.values().iterator();
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
		Comparator<ICFIntMimeTypeObj> cmp = new Comparator<ICFIntMimeTypeObj>() {
			public int compare( ICFIntMimeTypeObj lhs, ICFIntMimeTypeObj rhs ) {
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
					CFIntMimeTypePKey lhsPKey = lhs.getPKey();
					CFIntMimeTypePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFIntMimeTypeObj readMimeTypeByIdIdx( int MimeTypeId )
	{
		return( readMimeTypeByIdIdx( MimeTypeId,
			false ) );
	}

	public ICFIntMimeTypeObj readMimeTypeByIdIdx( int MimeTypeId, boolean forceRead )
	{
		CFIntMimeTypePKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newPKey();
		pkey.setRequiredMimeTypeId( MimeTypeId );
		ICFIntMimeTypeObj obj = readMimeType( pkey, forceRead );
		return( obj );
	}

	public ICFIntMimeTypeObj readMimeTypeByUNameIdx( String Name )
	{
		return( readMimeTypeByUNameIdx( Name,
			false ) );
	}

	public ICFIntMimeTypeObj readMimeTypeByUNameIdx( String Name, boolean forceRead )
	{
		if( indexByUNameIdx == null ) {
			indexByUNameIdx = new HashMap< CFIntMimeTypeByUNameIdxKey,
				ICFIntMimeTypeObj >();
		}
		CFIntMimeTypeByUNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newUNameIdxKey();
		key.setRequiredName( Name );
		ICFIntMimeTypeObj obj = null;
		if( ( ! forceRead ) && indexByUNameIdx.containsKey( key ) ) {
			obj = indexByUNameIdx.get( key );
		}
		else {
			CFIntMimeTypeBuff buff = ((ICFIntSchema)schema.getBackingStore()).getTableMimeType().readDerivedByUNameIdx( schema.getAuthorization(),
				Name );
			if( buff != null ) {
				obj = schema.getMimeTypeTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newPKey() );
				obj.setBuff( buff );
				obj = (ICFIntMimeTypeObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFIntMimeTypeObj readCachedMimeTypeByIdIdx( int MimeTypeId )
	{
		ICFIntMimeTypeObj obj = null;
		CFIntMimeTypePKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newPKey();
		pkey.setRequiredMimeTypeId( MimeTypeId );
		obj = readCachedMimeType( pkey );
		return( obj );
	}

	public ICFIntMimeTypeObj readCachedMimeTypeByUNameIdx( String Name )
	{
		ICFIntMimeTypeObj obj = null;
		CFIntMimeTypeByUNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newUNameIdxKey();
		key.setRequiredName( Name );
		if( indexByUNameIdx != null ) {
			if( indexByUNameIdx.containsKey( key ) ) {
				obj = indexByUNameIdx.get( key );
			}
			else {
				Iterator<ICFIntMimeTypeObj> valIter = members.values().iterator();
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
			Iterator<ICFIntMimeTypeObj> valIter = members.values().iterator();
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

	public void deepDisposeMimeTypeByIdIdx( int MimeTypeId )
	{
		ICFIntMimeTypeObj obj = readCachedMimeTypeByIdIdx( MimeTypeId );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeMimeTypeByUNameIdx( String Name )
	{
		ICFIntMimeTypeObj obj = readCachedMimeTypeByUNameIdx( Name );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFIntMimeTypeObj updateMimeType( ICFIntMimeTypeObj Obj ) {
		ICFIntMimeTypeObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableMimeType().updateMimeType( schema.getAuthorization(),
			Obj.getMimeTypeBuff() );
		obj = (ICFIntMimeTypeObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteMimeType( ICFIntMimeTypeObj Obj ) {
		ICFIntMimeTypeObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableMimeType().deleteMimeType( schema.getAuthorization(),
			obj.getMimeTypeBuff() );
		Obj.forget();
	}

	public void deleteMimeTypeByIdIdx( int MimeTypeId )
	{
		CFIntMimeTypePKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newPKey();
		pkey.setRequiredMimeTypeId( MimeTypeId );
		ICFIntMimeTypeObj obj = readMimeType( pkey );
		if( obj != null ) {
			ICFIntMimeTypeEditObj editObj = (ICFIntMimeTypeEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFIntMimeTypeEditObj)obj.beginEdit();
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
		deepDisposeMimeTypeByIdIdx( MimeTypeId );
	}

	public void deleteMimeTypeByUNameIdx( String Name )
	{
		if( indexByUNameIdx == null ) {
			indexByUNameIdx = new HashMap< CFIntMimeTypeByUNameIdxKey,
				ICFIntMimeTypeObj >();
		}
		CFIntMimeTypeByUNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryMimeType().newUNameIdxKey();
		key.setRequiredName( Name );
		ICFIntMimeTypeObj obj = null;
		if( indexByUNameIdx.containsKey( key ) ) {
			obj = indexByUNameIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableMimeType().deleteMimeTypeByUNameIdx( schema.getAuthorization(),
				Name );
			obj.forget();
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableMimeType().deleteMimeTypeByUNameIdx( schema.getAuthorization(),
				Name );
		}
		deepDisposeMimeTypeByUNameIdx( Name );
	}
}