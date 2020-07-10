// Description: Java 11 Table Object implementation for CFInt.

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
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFInt.*;

public class CFIntLicenseTableObj
	implements ICFIntLicenseTableObj
{
	protected ICFIntSchemaObj schema;
	private Map<CFIntLicensePKey, ICFIntLicenseObj> members;
	private Map<CFIntLicensePKey, ICFIntLicenseObj> allLicense;
	private Map< CFIntLicenseByLicnTenantIdxKey,
		Map<CFIntLicensePKey, ICFIntLicenseObj > > indexByLicnTenantIdx;
	private Map< CFIntLicenseByDomainIdxKey,
		Map<CFIntLicensePKey, ICFIntLicenseObj > > indexByDomainIdx;
	private Map< CFIntLicenseByUNameIdxKey,
		ICFIntLicenseObj > indexByUNameIdx;
	public static String TABLE_NAME = "License";
	public static String TABLE_DBNAME = "licn";

	public CFIntLicenseTableObj() {
		schema = null;
		members = new HashMap<CFIntLicensePKey, ICFIntLicenseObj>();
		allLicense = null;
		indexByLicnTenantIdx = null;
		indexByDomainIdx = null;
		indexByUNameIdx = null;
	}

	public CFIntLicenseTableObj( ICFIntSchemaObj argSchema ) {
		schema = (ICFIntSchemaObj)argSchema;
		members = new HashMap<CFIntLicensePKey, ICFIntLicenseObj>();
		allLicense = null;
		indexByLicnTenantIdx = null;
		indexByDomainIdx = null;
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
		return( ICFIntTenantObj.class );
	}


	public void minimizeMemory() {
		allLicense = null;
		indexByLicnTenantIdx = null;
		indexByDomainIdx = null;
		indexByUNameIdx = null;
		List<ICFIntLicenseObj> toForget = new LinkedList<ICFIntLicenseObj>();
		ICFIntLicenseObj cur = null;
		Iterator<ICFIntLicenseObj> iter = members.values().iterator();
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
	 *	CFIntLicenseObj.
	 */
	public ICFIntLicenseObj newInstance() {
		ICFIntLicenseObj inst = new CFIntLicenseObj( schema );
		return( inst );
	}

	/**
	 *	If your implementation subclasses the objects,
	 *	you'll want to overload the constructByClassCode()
	 *	implementation to return your implementation's
	 *	instances instead of the base implementation.
	 *
	 *	This is the sole factory for instances derived from
	 *	CFIntLicenseObj.
	 */
	public ICFIntLicenseEditObj newEditInstance( ICFIntLicenseObj orig ) {
		ICFIntLicenseEditObj edit = new CFIntLicenseEditObj( orig );
		return( edit );
	}

	public ICFIntLicenseObj realiseLicense( ICFIntLicenseObj Obj ) {
		ICFIntLicenseObj obj = Obj;
		CFIntLicensePKey pkey = obj.getPKey();
		ICFIntLicenseObj keepObj = null;
		if( members.containsKey( pkey ) && ( null != members.get( pkey ) ) ) {
			ICFIntLicenseObj existingObj = members.get( pkey );
			keepObj = existingObj;

			/*
			 *	We always rebind the data because if we're being called, some index has
			 *	been updated and is refreshing it's data, which may or may not have changed
			 */

			// Detach object from alternate and duplicate indexes, leave PKey alone

			if( indexByLicnTenantIdx != null ) {
				CFIntLicenseByLicnTenantIdxKey keyLicnTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newLicnTenantIdxKey();
				keyLicnTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntLicensePKey, ICFIntLicenseObj > mapLicnTenantIdx = indexByLicnTenantIdx.get( keyLicnTenantIdx );
				if( mapLicnTenantIdx != null ) {
					mapLicnTenantIdx.remove( keepObj.getPKey() );
					if( mapLicnTenantIdx.size() <= 0 ) {
						indexByLicnTenantIdx.remove( keyLicnTenantIdx );
					}
				}
			}

			if( indexByDomainIdx != null ) {
				CFIntLicenseByDomainIdxKey keyDomainIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newDomainIdxKey();
				keyDomainIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyDomainIdx.setRequiredTopDomainId( keepObj.getRequiredTopDomainId() );
				Map<CFIntLicensePKey, ICFIntLicenseObj > mapDomainIdx = indexByDomainIdx.get( keyDomainIdx );
				if( mapDomainIdx != null ) {
					mapDomainIdx.remove( keepObj.getPKey() );
					if( mapDomainIdx.size() <= 0 ) {
						indexByDomainIdx.remove( keyDomainIdx );
					}
				}
			}

			if( indexByUNameIdx != null ) {
				CFIntLicenseByUNameIdxKey keyUNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newUNameIdxKey();
				keyUNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyUNameIdx.setRequiredTopDomainId( keepObj.getRequiredTopDomainId() );
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.remove( keyUNameIdx );
			}

			keepObj.setBuff( Obj.getBuff() );
			// Attach new object to alternate and duplicate indexes -- PKey stay stable

			if( indexByLicnTenantIdx != null ) {
				CFIntLicenseByLicnTenantIdxKey keyLicnTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newLicnTenantIdxKey();
				keyLicnTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntLicensePKey, ICFIntLicenseObj > mapLicnTenantIdx = indexByLicnTenantIdx.get( keyLicnTenantIdx );
				if( mapLicnTenantIdx != null ) {
					mapLicnTenantIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByDomainIdx != null ) {
				CFIntLicenseByDomainIdxKey keyDomainIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newDomainIdxKey();
				keyDomainIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyDomainIdx.setRequiredTopDomainId( keepObj.getRequiredTopDomainId() );
				Map<CFIntLicensePKey, ICFIntLicenseObj > mapDomainIdx = indexByDomainIdx.get( keyDomainIdx );
				if( mapDomainIdx != null ) {
					mapDomainIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUNameIdx != null ) {
				CFIntLicenseByUNameIdxKey keyUNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newUNameIdxKey();
				keyUNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyUNameIdx.setRequiredTopDomainId( keepObj.getRequiredTopDomainId() );
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.put( keyUNameIdx, keepObj );
			}

			if( allLicense != null ) {
				allLicense.put( keepObj.getPKey(), keepObj );
			}
		}
		else {
			keepObj = obj;
			keepObj.setIsNew( false );

			// Attach new object to PKey, all, alternate, and duplicate indexes
			members.put( keepObj.getPKey(), keepObj );
			if( allLicense != null ) {
				allLicense.put( keepObj.getPKey(), keepObj );
			}

			if( indexByLicnTenantIdx != null ) {
				CFIntLicenseByLicnTenantIdxKey keyLicnTenantIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newLicnTenantIdxKey();
				keyLicnTenantIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				Map<CFIntLicensePKey, ICFIntLicenseObj > mapLicnTenantIdx = indexByLicnTenantIdx.get( keyLicnTenantIdx );
				if( mapLicnTenantIdx != null ) {
					mapLicnTenantIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByDomainIdx != null ) {
				CFIntLicenseByDomainIdxKey keyDomainIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newDomainIdxKey();
				keyDomainIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyDomainIdx.setRequiredTopDomainId( keepObj.getRequiredTopDomainId() );
				Map<CFIntLicensePKey, ICFIntLicenseObj > mapDomainIdx = indexByDomainIdx.get( keyDomainIdx );
				if( mapDomainIdx != null ) {
					mapDomainIdx.put( keepObj.getPKey(), keepObj );
				}
			}

			if( indexByUNameIdx != null ) {
				CFIntLicenseByUNameIdxKey keyUNameIdx =
					((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newUNameIdxKey();
				keyUNameIdx.setRequiredTenantId( keepObj.getRequiredTenantId() );
				keyUNameIdx.setRequiredTopDomainId( keepObj.getRequiredTopDomainId() );
				keyUNameIdx.setRequiredName( keepObj.getRequiredName() );
				indexByUNameIdx.put( keyUNameIdx, keepObj );
			}

		}
		return( keepObj );
	}

	public ICFIntLicenseObj createLicense( ICFIntLicenseObj Obj ) {
		ICFIntLicenseObj obj = Obj;
		CFIntLicenseBuff buff = obj.getLicenseBuff();
		((ICFIntSchema)schema.getBackingStore()).getTableLicense().createLicense(
			schema.getAuthorization(),
			buff );
		obj.copyBuffToPKey();
		obj = obj.realise();
		obj.endEdit();
		return( obj );
	}

	public ICFIntLicenseObj readLicense( CFIntLicensePKey pkey ) {
		return( readLicense( pkey, false ) );
	}

	public ICFIntLicenseObj readLicense( CFIntLicensePKey pkey, boolean forceRead ) {
		ICFIntLicenseObj obj = null;
		if( ( ! forceRead ) && members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		else {
			CFIntLicenseBuff readBuff = ((ICFIntSchema)schema.getBackingStore()).getTableLicense().readDerivedByIdIdx( schema.getAuthorization(),
				pkey.getRequiredTenantId(),
				pkey.getRequiredId() );
			if( readBuff != null ) {
				obj = schema.getLicenseTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newPKey() );
				obj.setBuff( readBuff );
				obj = (ICFIntLicenseObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFIntLicenseObj readCachedLicense( CFIntLicensePKey pkey ) {
		ICFIntLicenseObj obj = null;
		if( members.containsKey( pkey ) ) {
			obj = members.get( pkey );
		}
		return( obj );
	}

	public void reallyDeepDisposeLicense( ICFIntLicenseObj obj )
	{
		final String S_ProcName = "CFIntLicenseTableObj.reallyDeepDisposeLicense() ";
		String classCode;
		if( obj == null ) {
			return;
		}
		CFIntLicensePKey pkey = obj.getPKey();
		ICFIntLicenseObj existing = readCachedLicense( pkey );
		if( existing == null ) {
			return;
		}
		members.remove( pkey );
		CFIntLicenseByLicnTenantIdxKey keyLicnTenantIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newLicnTenantIdxKey();
		keyLicnTenantIdx.setRequiredTenantId( existing.getRequiredTenantId() );

		CFIntLicenseByDomainIdxKey keyDomainIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newDomainIdxKey();
		keyDomainIdx.setRequiredTenantId( existing.getRequiredTenantId() );
		keyDomainIdx.setRequiredTopDomainId( existing.getRequiredTopDomainId() );

		CFIntLicenseByUNameIdxKey keyUNameIdx = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newUNameIdxKey();
		keyUNameIdx.setRequiredTenantId( existing.getRequiredTenantId() );
		keyUNameIdx.setRequiredTopDomainId( existing.getRequiredTopDomainId() );
		keyUNameIdx.setRequiredName( existing.getRequiredName() );



		if( indexByLicnTenantIdx != null ) {
			if( indexByLicnTenantIdx.containsKey( keyLicnTenantIdx ) ) {
				indexByLicnTenantIdx.get( keyLicnTenantIdx ).remove( pkey );
				if( indexByLicnTenantIdx.get( keyLicnTenantIdx ).size() <= 0 ) {
					indexByLicnTenantIdx.remove( keyLicnTenantIdx );
				}
			}
		}

		if( indexByDomainIdx != null ) {
			if( indexByDomainIdx.containsKey( keyDomainIdx ) ) {
				indexByDomainIdx.get( keyDomainIdx ).remove( pkey );
				if( indexByDomainIdx.get( keyDomainIdx ).size() <= 0 ) {
					indexByDomainIdx.remove( keyDomainIdx );
				}
			}
		}

		if( indexByUNameIdx != null ) {
			indexByUNameIdx.remove( keyUNameIdx );
		}


	}
	public void deepDisposeLicense( CFIntLicensePKey pkey ) {
		ICFIntLicenseObj obj = readCachedLicense( pkey );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFIntLicenseObj lockLicense( CFIntLicensePKey pkey ) {
		ICFIntLicenseObj locked = null;
		CFIntLicenseBuff lockBuff = ((ICFIntSchema)schema.getBackingStore()).getTableLicense().lockDerived( schema.getAuthorization(), pkey );
		if( lockBuff != null ) {
				locked = schema.getLicenseTableObj().newInstance();
			locked.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newPKey() );
			locked.setBuff( lockBuff );
			locked = (ICFIntLicenseObj)locked.realise();
		}
		else {
			throw new CFLibCollisionDetectedException( getClass(), "lockLicense", pkey );
		}
		return( locked );
	}

	public List<ICFIntLicenseObj> readAllLicense() {
		return( readAllLicense( false ) );
	}

	public List<ICFIntLicenseObj> readAllLicense( boolean forceRead ) {
		final String S_ProcName = "readAllLicense";
		if( ( allLicense == null ) || forceRead ) {
			Map<CFIntLicensePKey, ICFIntLicenseObj> map = new HashMap<CFIntLicensePKey,ICFIntLicenseObj>();
			allLicense = map;
			CFIntLicenseBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableLicense().readAllDerived( schema.getAuthorization() );
			CFIntLicenseBuff buff;
			ICFIntLicenseObj obj;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newPKey() );
				obj.setBuff( buff );
				ICFIntLicenseObj realised = (ICFIntLicenseObj)obj.realise();
			}
		}
		int len = allLicense.size();
		ICFIntLicenseObj arr[] = new ICFIntLicenseObj[len];
		Iterator<ICFIntLicenseObj> valIter = allLicense.values().iterator();
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
		ArrayList<ICFIntLicenseObj> arrayList = new ArrayList<ICFIntLicenseObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntLicenseObj> cmp = new Comparator<ICFIntLicenseObj>() {
			public int compare( ICFIntLicenseObj lhs, ICFIntLicenseObj rhs ) {
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
					CFIntLicensePKey lhsPKey = lhs.getPKey();
					CFIntLicensePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntLicenseObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFIntLicenseObj> readCachedAllLicense() {
		final String S_ProcName = "readCachedAllLicense";
		ArrayList<ICFIntLicenseObj> arrayList = new ArrayList<ICFIntLicenseObj>();
		if( allLicense != null ) {
			int len = allLicense.size();
			ICFIntLicenseObj arr[] = new ICFIntLicenseObj[len];
			Iterator<ICFIntLicenseObj> valIter = allLicense.values().iterator();
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
		Comparator<ICFIntLicenseObj> cmp = new Comparator<ICFIntLicenseObj>() {
			public int compare( ICFIntLicenseObj lhs, ICFIntLicenseObj rhs ) {
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
					CFIntLicensePKey lhsPKey = lhs.getPKey();
					CFIntLicensePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFIntLicenseObj readLicenseByIdIdx( long TenantId,
		long Id )
	{
		return( readLicenseByIdIdx( TenantId,
			Id,
			false ) );
	}

	public ICFIntLicenseObj readLicenseByIdIdx( long TenantId,
		long Id, boolean forceRead )
	{
		CFIntLicensePKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		ICFIntLicenseObj obj = readLicense( pkey, forceRead );
		return( obj );
	}

	public List<ICFIntLicenseObj> readLicenseByLicnTenantIdx( long TenantId )
	{
		return( readLicenseByLicnTenantIdx( TenantId,
			false ) );
	}

	public List<ICFIntLicenseObj> readLicenseByLicnTenantIdx( long TenantId,
		boolean forceRead )
	{
		final String S_ProcName = "readLicenseByLicnTenantIdx";
		CFIntLicenseByLicnTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newLicnTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		Map<CFIntLicensePKey, ICFIntLicenseObj> dict;
		if( indexByLicnTenantIdx == null ) {
			indexByLicnTenantIdx = new HashMap< CFIntLicenseByLicnTenantIdxKey,
				Map< CFIntLicensePKey, ICFIntLicenseObj > >();
		}
		if( ( ! forceRead ) && indexByLicnTenantIdx.containsKey( key ) ) {
			dict = indexByLicnTenantIdx.get( key );
		}
		else {
			dict = new HashMap<CFIntLicensePKey, ICFIntLicenseObj>();
			ICFIntLicenseObj obj;
			CFIntLicenseBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableLicense().readDerivedByLicnTenantIdx( schema.getAuthorization(),
				TenantId );
			CFIntLicenseBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getLicenseTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newPKey() );
				obj.setBuff( buff );
				ICFIntLicenseObj realised = (ICFIntLicenseObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByLicnTenantIdx.put( key, dict );
		}
		int len = dict.size();
		ICFIntLicenseObj arr[] = new ICFIntLicenseObj[len];
		Iterator<ICFIntLicenseObj> valIter = dict.values().iterator();
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
		ArrayList<ICFIntLicenseObj> arrayList = new ArrayList<ICFIntLicenseObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntLicenseObj> cmp = new Comparator<ICFIntLicenseObj>() {
			public int compare( ICFIntLicenseObj lhs, ICFIntLicenseObj rhs ) {
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
					CFIntLicensePKey lhsPKey = lhs.getPKey();
					CFIntLicensePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntLicenseObj> sortedList = arrayList;
		return( sortedList );
	}

	public List<ICFIntLicenseObj> readLicenseByDomainIdx( long TenantId,
		long TopDomainId )
	{
		return( readLicenseByDomainIdx( TenantId,
			TopDomainId,
			false ) );
	}

	public List<ICFIntLicenseObj> readLicenseByDomainIdx( long TenantId,
		long TopDomainId,
		boolean forceRead )
	{
		final String S_ProcName = "readLicenseByDomainIdx";
		CFIntLicenseByDomainIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newDomainIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		Map<CFIntLicensePKey, ICFIntLicenseObj> dict;
		if( indexByDomainIdx == null ) {
			indexByDomainIdx = new HashMap< CFIntLicenseByDomainIdxKey,
				Map< CFIntLicensePKey, ICFIntLicenseObj > >();
		}
		if( ( ! forceRead ) && indexByDomainIdx.containsKey( key ) ) {
			dict = indexByDomainIdx.get( key );
		}
		else {
			dict = new HashMap<CFIntLicensePKey, ICFIntLicenseObj>();
			ICFIntLicenseObj obj;
			CFIntLicenseBuff[] buffList = ((ICFIntSchema)schema.getBackingStore()).getTableLicense().readDerivedByDomainIdx( schema.getAuthorization(),
				TenantId,
				TopDomainId );
			CFIntLicenseBuff buff;
			for( int idx = 0; idx < buffList.length; idx ++ ) {
				buff = buffList[ idx ];
				obj = schema.getLicenseTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newPKey() );
				obj.setBuff( buff );
				ICFIntLicenseObj realised = (ICFIntLicenseObj)obj.realise();
				dict.put( realised.getPKey(), realised );
			}
			indexByDomainIdx.put( key, dict );
		}
		int len = dict.size();
		ICFIntLicenseObj arr[] = new ICFIntLicenseObj[len];
		Iterator<ICFIntLicenseObj> valIter = dict.values().iterator();
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
		ArrayList<ICFIntLicenseObj> arrayList = new ArrayList<ICFIntLicenseObj>(len);
		for( idx = 0; idx < len; idx ++ ) {
			arrayList.add( arr[idx] );
		}

		Comparator<ICFIntLicenseObj> cmp = new Comparator<ICFIntLicenseObj>() {
			public int compare( ICFIntLicenseObj lhs, ICFIntLicenseObj rhs ) {
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
					CFIntLicensePKey lhsPKey = lhs.getPKey();
					CFIntLicensePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		List<ICFIntLicenseObj> sortedList = arrayList;
		return( sortedList );
	}

	public ICFIntLicenseObj readLicenseByUNameIdx( long TenantId,
		long TopDomainId,
		String Name )
	{
		return( readLicenseByUNameIdx( TenantId,
			TopDomainId,
			Name,
			false ) );
	}

	public ICFIntLicenseObj readLicenseByUNameIdx( long TenantId,
		long TopDomainId,
		String Name, boolean forceRead )
	{
		if( indexByUNameIdx == null ) {
			indexByUNameIdx = new HashMap< CFIntLicenseByUNameIdxKey,
				ICFIntLicenseObj >();
		}
		CFIntLicenseByUNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newUNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		ICFIntLicenseObj obj = null;
		if( ( ! forceRead ) && indexByUNameIdx.containsKey( key ) ) {
			obj = indexByUNameIdx.get( key );
		}
		else {
			CFIntLicenseBuff buff = ((ICFIntSchema)schema.getBackingStore()).getTableLicense().readDerivedByUNameIdx( schema.getAuthorization(),
				TenantId,
				TopDomainId,
				Name );
			if( buff != null ) {
				obj = schema.getLicenseTableObj().newInstance();
				obj.setPKey( ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newPKey() );
				obj.setBuff( buff );
				obj = (ICFIntLicenseObj)obj.realise();
			}
		}
		return( obj );
	}

	public ICFIntLicenseObj readCachedLicenseByIdIdx( long TenantId,
		long Id )
	{
		ICFIntLicenseObj obj = null;
		CFIntLicensePKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		obj = readCachedLicense( pkey );
		return( obj );
	}

	public List<ICFIntLicenseObj> readCachedLicenseByLicnTenantIdx( long TenantId )
	{
		final String S_ProcName = "readCachedLicenseByLicnTenantIdx";
		CFIntLicenseByLicnTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newLicnTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		ArrayList<ICFIntLicenseObj> arrayList = new ArrayList<ICFIntLicenseObj>();
		if( indexByLicnTenantIdx != null ) {
			Map<CFIntLicensePKey, ICFIntLicenseObj> dict;
			if( indexByLicnTenantIdx.containsKey( key ) ) {
				dict = indexByLicnTenantIdx.get( key );
				int len = dict.size();
				ICFIntLicenseObj arr[] = new ICFIntLicenseObj[len];
				Iterator<ICFIntLicenseObj> valIter = dict.values().iterator();
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
			ICFIntLicenseObj obj;
			Iterator<ICFIntLicenseObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFIntLicenseObj> cmp = new Comparator<ICFIntLicenseObj>() {
			public int compare( ICFIntLicenseObj lhs, ICFIntLicenseObj rhs ) {
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
					CFIntLicensePKey lhsPKey = lhs.getPKey();
					CFIntLicensePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public List<ICFIntLicenseObj> readCachedLicenseByDomainIdx( long TenantId,
		long TopDomainId )
	{
		final String S_ProcName = "readCachedLicenseByDomainIdx";
		CFIntLicenseByDomainIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newDomainIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		ArrayList<ICFIntLicenseObj> arrayList = new ArrayList<ICFIntLicenseObj>();
		if( indexByDomainIdx != null ) {
			Map<CFIntLicensePKey, ICFIntLicenseObj> dict;
			if( indexByDomainIdx.containsKey( key ) ) {
				dict = indexByDomainIdx.get( key );
				int len = dict.size();
				ICFIntLicenseObj arr[] = new ICFIntLicenseObj[len];
				Iterator<ICFIntLicenseObj> valIter = dict.values().iterator();
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
			ICFIntLicenseObj obj;
			Iterator<ICFIntLicenseObj> valIter = members.values().iterator();
			while( valIter.hasNext() ) {
				obj = valIter.next();
				if( obj != null ) {
					if( obj.getBuff().compareTo( key ) == 0 ) {
						arrayList.add( obj );
					}
				}
			}
		}
		Comparator<ICFIntLicenseObj> cmp = new Comparator<ICFIntLicenseObj>() {
			public int compare( ICFIntLicenseObj lhs, ICFIntLicenseObj rhs ) {
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
					CFIntLicensePKey lhsPKey = lhs.getPKey();
					CFIntLicensePKey rhsPKey = rhs.getPKey();
					int ret = lhsPKey.compareTo( rhsPKey );
					return( ret );
				}
			}
		};
		Collections.sort( arrayList, cmp );
		return( arrayList );
	}

	public ICFIntLicenseObj readCachedLicenseByUNameIdx( long TenantId,
		long TopDomainId,
		String Name )
	{
		ICFIntLicenseObj obj = null;
		CFIntLicenseByUNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newUNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		if( indexByUNameIdx != null ) {
			if( indexByUNameIdx.containsKey( key ) ) {
				obj = indexByUNameIdx.get( key );
			}
			else {
				Iterator<ICFIntLicenseObj> valIter = members.values().iterator();
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
			Iterator<ICFIntLicenseObj> valIter = members.values().iterator();
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

	public void deepDisposeLicenseByIdIdx( long TenantId,
		long Id )
	{
		ICFIntLicenseObj obj = readCachedLicenseByIdIdx( TenantId,
				Id );
		if( obj != null ) {
			obj.forget();
		}
	}

	public void deepDisposeLicenseByLicnTenantIdx( long TenantId )
	{
		final String S_ProcName = "deepDisposeLicenseByLicnTenantIdx";
		ICFIntLicenseObj obj;
		List<ICFIntLicenseObj> arrayList = readCachedLicenseByLicnTenantIdx( TenantId );
		if( arrayList != null )  {
			Iterator<ICFIntLicenseObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeLicenseByDomainIdx( long TenantId,
		long TopDomainId )
	{
		final String S_ProcName = "deepDisposeLicenseByDomainIdx";
		ICFIntLicenseObj obj;
		List<ICFIntLicenseObj> arrayList = readCachedLicenseByDomainIdx( TenantId,
				TopDomainId );
		if( arrayList != null )  {
			Iterator<ICFIntLicenseObj> arrayIter = arrayList.iterator();
			while( arrayIter.hasNext() ) {
				obj = arrayIter.next();
				if( obj != null ) {
					obj.forget();
				}
			}
		}
	}

	public void deepDisposeLicenseByUNameIdx( long TenantId,
		long TopDomainId,
		String Name )
	{
		ICFIntLicenseObj obj = readCachedLicenseByUNameIdx( TenantId,
				TopDomainId,
				Name );
		if( obj != null ) {
			obj.forget();
		}
	}

	public ICFIntLicenseObj updateLicense( ICFIntLicenseObj Obj ) {
		ICFIntLicenseObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableLicense().updateLicense( schema.getAuthorization(),
			Obj.getLicenseBuff() );
		obj = (ICFIntLicenseObj)Obj.realise();
		obj.endEdit();
		return( obj );
	}

	public void deleteLicense( ICFIntLicenseObj Obj ) {
		ICFIntLicenseObj obj = Obj;
		((ICFIntSchema)schema.getBackingStore()).getTableLicense().deleteLicense( schema.getAuthorization(),
			obj.getLicenseBuff() );
		Obj.forget();
	}

	public void deleteLicenseByIdIdx( long TenantId,
		long Id )
	{
		CFIntLicensePKey pkey = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newPKey();
		pkey.setRequiredTenantId( TenantId );
		pkey.setRequiredId( Id );
		ICFIntLicenseObj obj = readLicense( pkey );
		if( obj != null ) {
			ICFIntLicenseEditObj editObj = (ICFIntLicenseEditObj)obj.getEdit();
			boolean editStarted;
			if( editObj == null ) {
				editObj = (ICFIntLicenseEditObj)obj.beginEdit();
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
		deepDisposeLicenseByIdIdx( TenantId,
				Id );
	}

	public void deleteLicenseByLicnTenantIdx( long TenantId )
	{
		CFIntLicenseByLicnTenantIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newLicnTenantIdxKey();
		key.setRequiredTenantId( TenantId );
		if( indexByLicnTenantIdx == null ) {
			indexByLicnTenantIdx = new HashMap< CFIntLicenseByLicnTenantIdxKey,
				Map< CFIntLicensePKey, ICFIntLicenseObj > >();
		}
		if( indexByLicnTenantIdx.containsKey( key ) ) {
			Map<CFIntLicensePKey, ICFIntLicenseObj> dict = indexByLicnTenantIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableLicense().deleteLicenseByLicnTenantIdx( schema.getAuthorization(),
				TenantId );
			Iterator<ICFIntLicenseObj> iter = dict.values().iterator();
			ICFIntLicenseObj obj;
			List<ICFIntLicenseObj> toForget = new LinkedList<ICFIntLicenseObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByLicnTenantIdx.remove( key );
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableLicense().deleteLicenseByLicnTenantIdx( schema.getAuthorization(),
				TenantId );
		}
		deepDisposeLicenseByLicnTenantIdx( TenantId );
	}

	public void deleteLicenseByDomainIdx( long TenantId,
		long TopDomainId )
	{
		CFIntLicenseByDomainIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newDomainIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		if( indexByDomainIdx == null ) {
			indexByDomainIdx = new HashMap< CFIntLicenseByDomainIdxKey,
				Map< CFIntLicensePKey, ICFIntLicenseObj > >();
		}
		if( indexByDomainIdx.containsKey( key ) ) {
			Map<CFIntLicensePKey, ICFIntLicenseObj> dict = indexByDomainIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableLicense().deleteLicenseByDomainIdx( schema.getAuthorization(),
				TenantId,
				TopDomainId );
			Iterator<ICFIntLicenseObj> iter = dict.values().iterator();
			ICFIntLicenseObj obj;
			List<ICFIntLicenseObj> toForget = new LinkedList<ICFIntLicenseObj>();
			while( iter.hasNext() ) {
				obj = iter.next();
				toForget.add( obj );
			}
			iter = toForget.iterator();
			while( iter.hasNext() ) {
				obj = iter.next();
				obj.forget();
			}
			indexByDomainIdx.remove( key );
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableLicense().deleteLicenseByDomainIdx( schema.getAuthorization(),
				TenantId,
				TopDomainId );
		}
		deepDisposeLicenseByDomainIdx( TenantId,
				TopDomainId );
	}

	public void deleteLicenseByUNameIdx( long TenantId,
		long TopDomainId,
		String Name )
	{
		if( indexByUNameIdx == null ) {
			indexByUNameIdx = new HashMap< CFIntLicenseByUNameIdxKey,
				ICFIntLicenseObj >();
		}
		CFIntLicenseByUNameIdxKey key = ((ICFIntSchema)schema.getBackingStore()).getFactoryLicense().newUNameIdxKey();
		key.setRequiredTenantId( TenantId );
		key.setRequiredTopDomainId( TopDomainId );
		key.setRequiredName( Name );
		ICFIntLicenseObj obj = null;
		if( indexByUNameIdx.containsKey( key ) ) {
			obj = indexByUNameIdx.get( key );
			((ICFIntSchema)schema.getBackingStore()).getTableLicense().deleteLicenseByUNameIdx( schema.getAuthorization(),
				TenantId,
				TopDomainId,
				Name );
			obj.forget();
		}
		else {
			((ICFIntSchema)schema.getBackingStore()).getTableLicense().deleteLicenseByUNameIdx( schema.getAuthorization(),
				TenantId,
				TopDomainId,
				Name );
		}
		deepDisposeLicenseByUNameIdx( TenantId,
				TopDomainId,
				Name );
	}
}