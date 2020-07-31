// Description: Java 11 PostgreSQL Jdbc DbIO implementation for ISOCtryCcy.

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

package org.msscf.msscf.cfint.CFIntPgSql;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/*
 *	CFIntPgSqlISOCtryCcyTable PostgreSQL Jdbc DbIO implementation
 *	for ISOCtryCcy.
 */
public class CFIntPgSqlISOCtryCcyTable
	implements ICFIntISOCtryCcyTable
{
	private CFIntPgSqlSchema schema;
	protected PreparedStatement stmtReadBuffByPKey = null;
	protected PreparedStatement stmtReadBuffAll = null;
	protected PreparedStatement stmtLockBuffByPKey = null;
	protected PreparedStatement stmtCreateByPKey = null;
	protected PreparedStatement stmtUpdateByPKey = null;
	protected PreparedStatement stmtDeleteByPKey = null;
	protected PreparedStatement stmtReadAllBuff = null;
	protected PreparedStatement stmtReadBuffByIdIdx = null;
	protected PreparedStatement stmtReadBuffByCtryIdx = null;
	protected PreparedStatement stmtReadBuffByCcyIdx = null;
	protected PreparedStatement stmtDeleteByIdIdx = null;
	protected PreparedStatement stmtDeleteByCtryIdx = null;
	protected PreparedStatement stmtDeleteByCcyIdx = null;

	public CFIntPgSqlISOCtryCcyTable( CFIntPgSqlSchema argSchema ) {
		schema = argSchema;
	}

	public void createISOCtryCcy( CFSecAuthorization Authorization,
		CFSecISOCtryCcyBuff Buff )
	{
		final String S_ProcName = "createISOCtryCcy";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			short ISOCtryId = Buff.getRequiredISOCtryId();
			short ISOCcyId = Buff.getRequiredISOCcyId();
			Connection cnx = schema.getCnx();
			String sql =
				"select * from " + schema.getLowerDbSchemaName() + ".sp_create_iso_cntryccy( ?, ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtCreateByPKey == null ) {
				stmtCreateByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtCreateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtCreateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtCreateByPKey.setString( argIdx++, "a005" );
			stmtCreateByPKey.setShort( argIdx++, ISOCtryId );
			stmtCreateByPKey.setShort( argIdx++, ISOCcyId );
			resultSet = stmtCreateByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCtryCcyBuff createdBuff = unpackISOCtryCcyResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response" );
				}
				Buff.setRequiredISOCtryId( createdBuff.getRequiredISOCtryId() );
				Buff.setRequiredISOCcyId( createdBuff.getRequiredISOCcyId() );
				Buff.setRequiredRevision( createdBuff.getRequiredRevision() );
				Buff.setCreatedByUserId( createdBuff.getCreatedByUserId() );
				Buff.setCreatedAt( createdBuff.getCreatedAt() );
				Buff.setUpdatedByUserId( createdBuff.getUpdatedByUserId() );
				Buff.setUpdatedAt( createdBuff.getUpdatedAt() );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Expected a single-record response, " + resultSet.getRow() + " rows selected" );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public String S_sqlSelectISOCtryCcyDistinctClassCode = null;

	public String getSqlSelectISOCtryCcyDistinctClassCode() {
		if( S_sqlSelectISOCtryCcyDistinctClassCode == null ) {
			S_sqlSelectISOCtryCcyDistinctClassCode =
					"SELECT "
					+		"DISTINCT a005.ClassCode "
					+	"FROM " + schema.getLowerDbSchemaName() + ".iso_cntryccy AS a005 ";
		}
		return( S_sqlSelectISOCtryCcyDistinctClassCode );
	}

	public String S_sqlSelectISOCtryCcyBuff = null;

	public String getSqlSelectISOCtryCcyBuff() {
		if( S_sqlSelectISOCtryCcyBuff == null ) {
			S_sqlSelectISOCtryCcyBuff =
					"SELECT "
					+		"a005.ISOCtryId, "
					+		"a005.ISOCcyId, "
					+		"a005.Revision "
				+	"FROM " + schema.getLowerDbSchemaName() + ".iso_cntryccy AS a005 ";
		}
		return( S_sqlSelectISOCtryCcyBuff );
	}

	protected CFSecISOCtryCcyBuff unpackISOCtryCcyResultSetToBuff( ResultSet resultSet )
	throws SQLException
	{
		final String S_ProcName = "unpackISOCtryCcyResultSetToBuff";
		int idxcol = 1;
		CFSecISOCtryCcyBuff buff = schema.getFactoryISOCtryCcy().newBuff();
		{
			String colString = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setCreatedByUserId( null );
			}
			else if( ( colString == null ) || ( colString.length() <= 0 ) ) {
				buff.setCreatedByUserId( null );
			}
			else {
				buff.setCreatedByUserId( UUID.fromString( colString ) );
			}
			idxcol ++;

			colString = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setCreatedAt( null );
			}
			else if( ( colString == null ) || ( colString.length() <= 0 ) ) {
				buff.setCreatedAt( null );
			}
			else {
				buff.setCreatedAt( CFIntPgSqlSchema.convertTimestampString( colString ) );
			}
			idxcol++;
			colString = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setUpdatedByUserId( null );
			}
			else if( ( colString == null ) || ( colString.length() <= 0 ) ) {
				buff.setUpdatedByUserId( null );
			}
			else {
				buff.setUpdatedByUserId( UUID.fromString( colString ) );
			}
			idxcol ++;

			colString = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setUpdatedAt( null );
			}
			else if( ( colString == null ) || ( colString.length() <= 0 ) ) {
				buff.setUpdatedAt( null );
			}
			else {
				buff.setUpdatedAt( CFIntPgSqlSchema.convertTimestampString( colString ) );
			}
			idxcol++;
		}
		buff.setRequiredISOCtryId( resultSet.getShort( idxcol ) );
		idxcol++;
		buff.setRequiredISOCcyId( resultSet.getShort( idxcol ) );
		idxcol++;

		buff.setRequiredRevision( resultSet.getInt( idxcol ) );
		return( buff );
	}

	public CFSecISOCtryCcyBuff readDerived( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey )
	{
		final String S_ProcName = "readDerived";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecISOCtryCcyBuff buff;

		buff = readBuff( Authorization, PKey );
		return( buff );
	}

	public CFSecISOCtryCcyBuff lockDerived( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey )
	{
		final String S_ProcName = "lockDerived";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecISOCtryCcyBuff buff;

		buff = lockBuff( Authorization, PKey );
		return( buff );
	}

	public CFSecISOCtryCcyBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllDerived";
		CFSecISOCtryCcyBuff[] buffArray;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buffArray = readAllBuff( Authorization );
		return( buffArray );
	}

	public CFSecISOCtryCcyBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		short ISOCtryId,
		short ISOCcyId )
	{
		final String S_ProcName = "CFIntPgSqlISOCtryCcyTable.readDerivedByIdIdx() ";
		CFSecISOCtryCcyBuff buff;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buff = readBuffByIdIdx( Authorization,
				ISOCtryId,
				ISOCcyId );
		return( buff );
	}

	public CFSecISOCtryCcyBuff[] readDerivedByCtryIdx( CFSecAuthorization Authorization,
		short ISOCtryId )
	{
		final String S_ProcName = "readDerivedByCtryIdx";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecISOCtryCcyBuff[] buffList = readBuffByCtryIdx( Authorization,
				ISOCtryId );
		return( buffList );

	}

	public CFSecISOCtryCcyBuff[] readDerivedByCcyIdx( CFSecAuthorization Authorization,
		short ISOCcyId )
	{
		final String S_ProcName = "readDerivedByCcyIdx";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFSecISOCtryCcyBuff[] buffList = readBuffByCcyIdx( Authorization,
				ISOCcyId );
		return( buffList );

	}

	public CFSecISOCtryCcyBuff readBuff( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey )
	{
		final String S_ProcName = "readBuff";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			short ISOCtryId = PKey.getRequiredISOCtryId();
			short ISOCcyId = PKey.getRequiredISOCcyId();
			String sql = "SELECT * FROM " + schema.getLowerDbSchemaName() + ".sp_read_iso_cntryccy( ?, ?, ?, ?, ?" + ", "
					+		"?" + ", "
					+		"?" + " )";
			if( stmtReadBuffByPKey == null ) {
				stmtReadBuffByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByPKey.setShort( argIdx++, ISOCtryId );
			stmtReadBuffByPKey.setShort( argIdx++, ISOCcyId );
			resultSet = stmtReadBuffByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCtryCcyBuff buff = unpackISOCtryCcyResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response" );
				}
				return( buff );
			}
			else {
				return( null );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public CFSecISOCtryCcyBuff lockBuff( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey PKey )
	{
		final String S_ProcName = "lockBuff";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			short ISOCtryId = PKey.getRequiredISOCtryId();
			short ISOCcyId = PKey.getRequiredISOCcyId();
			String sql = "SELECT * FROM " + schema.getLowerDbSchemaName() + ".sp_lock_iso_cntryccy( ?, ?, ?, ?, ?" + ", "
					+		"?" + ", "
					+		"?" + " )";
			if( stmtLockBuffByPKey == null ) {
				stmtLockBuffByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtLockBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtLockBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtLockBuffByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtLockBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtLockBuffByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtLockBuffByPKey.setShort( argIdx++, ISOCtryId );
			stmtLockBuffByPKey.setShort( argIdx++, ISOCcyId );
			resultSet = stmtLockBuffByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCtryCcyBuff buff = unpackISOCtryCcyResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response" );
				}
				return( buff );
			}
			else {
				return( null );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public CFSecISOCtryCcyBuff[] readAllBuff( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllBuff";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "SELECT * FROM " + schema.getLowerDbSchemaName() + ".sp_read_iso_cntryccy_all( ?, ?, ?, ?, ? )";
			if( stmtReadAllBuff == null ) {
				stmtReadAllBuff = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadAllBuff.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadAllBuff.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadAllBuff.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadAllBuff.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadAllBuff.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			resultSet = stmtReadAllBuff.executeQuery();
			List<CFSecISOCtryCcyBuff> buffList = new LinkedList<CFSecISOCtryCcyBuff>();
			while( resultSet.next() ) {
				CFSecISOCtryCcyBuff buff = unpackISOCtryCcyResultSetToBuff( resultSet );
				buffList.add( buff );
			}
			int idx = 0;
			CFSecISOCtryCcyBuff[] retBuff = new CFSecISOCtryCcyBuff[ buffList.size() ];
			Iterator<CFSecISOCtryCcyBuff> iter = buffList.iterator();
			while( iter.hasNext() ) {
				retBuff[idx++] = iter.next();
			}
			return( retBuff );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public CFSecISOCtryCcyBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		short ISOCtryId,
		short ISOCcyId )
	{
		final String S_ProcName = "readBuffByIdIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "SELECT * FROM " + schema.getLowerDbSchemaName() + ".sp_read_iso_cntryccy_by_ididx( ?, ?, ?, ?, ?" + ", "
					+		"?" + ", "
					+		"?" + " )";
			if( stmtReadBuffByIdIdx == null ) {
				stmtReadBuffByIdIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByIdIdx.setShort( argIdx++, ISOCtryId );
			stmtReadBuffByIdIdx.setShort( argIdx++, ISOCcyId );
			resultSet = stmtReadBuffByIdIdx.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCtryCcyBuff buff = unpackISOCtryCcyResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response" );
				}
				return( buff );
			}
			else {
				return( null );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public CFSecISOCtryCcyBuff[] readBuffByCtryIdx( CFSecAuthorization Authorization,
		short ISOCtryId )
	{
		final String S_ProcName = "readBuffByCtryIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "SELECT * FROM " + schema.getLowerDbSchemaName() + ".sp_read_iso_cntryccy_by_ctryidx( ?, ?, ?, ?, ?" + ", "
					+		"?" + " )";
			if( stmtReadBuffByCtryIdx == null ) {
				stmtReadBuffByCtryIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByCtryIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCtryIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByCtryIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByCtryIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCtryIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByCtryIdx.setShort( argIdx++, ISOCtryId );
			resultSet = stmtReadBuffByCtryIdx.executeQuery();
			List<CFSecISOCtryCcyBuff> buffList = new LinkedList<CFSecISOCtryCcyBuff>();
			while( resultSet.next() ) {
				CFSecISOCtryCcyBuff buff = unpackISOCtryCcyResultSetToBuff( resultSet );
				buffList.add( buff );
			}
			int idx = 0;
			CFSecISOCtryCcyBuff[] retBuff = new CFSecISOCtryCcyBuff[ buffList.size() ];
			Iterator<CFSecISOCtryCcyBuff> iter = buffList.iterator();
			while( iter.hasNext() ) {
				retBuff[idx++] = iter.next();
			}
			return( retBuff );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public CFSecISOCtryCcyBuff[] readBuffByCcyIdx( CFSecAuthorization Authorization,
		short ISOCcyId )
	{
		final String S_ProcName = "readBuffByCcyIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "SELECT * FROM " + schema.getLowerDbSchemaName() + ".sp_read_iso_cntryccy_by_ccyidx( ?, ?, ?, ?, ?" + ", "
					+		"?" + " )";
			if( stmtReadBuffByCcyIdx == null ) {
				stmtReadBuffByCcyIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByCcyIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCcyIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByCcyIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByCcyIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByCcyIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByCcyIdx.setShort( argIdx++, ISOCcyId );
			resultSet = stmtReadBuffByCcyIdx.executeQuery();
			List<CFSecISOCtryCcyBuff> buffList = new LinkedList<CFSecISOCtryCcyBuff>();
			while( resultSet.next() ) {
				CFSecISOCtryCcyBuff buff = unpackISOCtryCcyResultSetToBuff( resultSet );
				buffList.add( buff );
			}
			int idx = 0;
			CFSecISOCtryCcyBuff[] retBuff = new CFSecISOCtryCcyBuff[ buffList.size() ];
			Iterator<CFSecISOCtryCcyBuff> iter = buffList.iterator();
			while( iter.hasNext() ) {
				retBuff[idx++] = iter.next();
			}
			return( retBuff );
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public void updateISOCtryCcy( CFSecAuthorization Authorization,
		CFSecISOCtryCcyBuff Buff )
	{
		final String S_ProcName = "updateISOCtryCcy";
		ResultSet resultSet = null;
		try {
			short ISOCtryId = Buff.getRequiredISOCtryId();
			short ISOCcyId = Buff.getRequiredISOCcyId();
			int Revision = Buff.getRequiredRevision();
			Connection cnx = schema.getCnx();
			String sql =
				"select * from " + schema.getLowerDbSchemaName() + ".sp_update_iso_cntryccy( ?, ?, ?, ?, ?, ?" + ", "
						+	"?" + ", "
						+	"?" + ", "
						+	"?" + " )";
			if( stmtUpdateByPKey == null ) {
				stmtUpdateByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtUpdateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtUpdateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtUpdateByPKey.setString( argIdx++, "a005" );
			stmtUpdateByPKey.setShort( argIdx++, ISOCtryId );
			stmtUpdateByPKey.setShort( argIdx++, ISOCcyId );
			stmtUpdateByPKey.setInt( argIdx++, Revision );
			resultSet = stmtUpdateByPKey.executeQuery();
			if( resultSet.next() ) {
				CFSecISOCtryCcyBuff updatedBuff = unpackISOCtryCcyResultSetToBuff( resultSet );
				if( resultSet.next() ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response" );
				}
				Buff.setRequiredRevision( updatedBuff.getRequiredRevision() );
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Expected a single-record response, " + resultSet.getRow() + " rows selected" );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public void deleteISOCtryCcy( CFSecAuthorization Authorization,
		CFSecISOCtryCcyBuff Buff )
	{
		final String S_ProcName = "deleteISOCtryCcy";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			short ISOCtryId = Buff.getRequiredISOCtryId();
			short ISOCcyId = Buff.getRequiredISOCcyId();

			String sql = "SELECT " + schema.getLowerDbSchemaName() + ".sp_delete_iso_cntryccy( ?, ?, ?, ?, ?" + ", "
					+		"?" + ", "
					+		"?" + ", "
					+		"?" + " ) as DeletedFlag";
			if( stmtDeleteByPKey == null ) {
				stmtDeleteByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByPKey.setShort( argIdx++, ISOCtryId );
			stmtDeleteByPKey.setShort( argIdx++, ISOCcyId );
			stmtDeleteByPKey.setInt( argIdx++, Buff.getRequiredRevision() );;
			resultSet = stmtDeleteByPKey.executeQuery();
			if( resultSet.next() ) {
				boolean deleteFlag = resultSet.getBoolean( 1 );
				if( resultSet.next() ) {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response" );
				}
			}
			else {
				throw new CFLibRuntimeException( getClass(),
					S_ProcName,
					"Expected 1 record result set to be returned by delete, not 0 rows" );
			}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public void deleteISOCtryCcyByIdIdx( CFSecAuthorization Authorization,
		short argISOCtryId,
		short argISOCcyId )
	{
		final String S_ProcName = "deleteISOCtryCcyByIdIdx";
		ResultSet resultSet = null;
		try {
				Connection cnx = schema.getCnx();
				String sql = "SELECT " + schema.getLowerDbSchemaName() + ".sp_delete_iso_cntryccy_by_ididx( ?, ?, ?, ?, ?" + ", "
					+		"?" + ", "
					+		"?" + " ) as DeletedFlag";
				if( stmtDeleteByIdIdx == null ) {
					stmtDeleteByIdIdx = cnx.prepareStatement( sql );
				}
				int argIdx = 1;
				stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
				stmtDeleteByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
				stmtDeleteByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
				stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
				stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
				stmtDeleteByIdIdx.setShort( argIdx++, argISOCtryId );
				stmtDeleteByIdIdx.setShort( argIdx++, argISOCcyId );
				resultSet = stmtDeleteByIdIdx.executeQuery();
				if( resultSet.next() ) {
					boolean deleteFlag = resultSet.getBoolean( 1 );
					if( resultSet.next() ) {
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Did not expect multi-record response" );
					}
				}
				else {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Expected 1 record result set to be returned by delete, not 0 rows" );
				}
			}
			catch( SQLException e ) {
				throw new CFLibDbException( getClass(),
					S_ProcName,
					e );
			}
			finally {
				if( resultSet != null ) {
					try {
						resultSet.close();
					}
					catch( SQLException e ) {
					}
					resultSet = null;
				}
			}
	}

	public void deleteISOCtryCcyByIdIdx( CFSecAuthorization Authorization,
		CFSecISOCtryCcyPKey argKey )
	{
		deleteISOCtryCcyByIdIdx( Authorization,
			argKey.getRequiredISOCtryId(),
			argKey.getRequiredISOCcyId() );
	}

	public void deleteISOCtryCcyByCtryIdx( CFSecAuthorization Authorization,
		short argISOCtryId )
	{
		final String S_ProcName = "deleteISOCtryCcyByCtryIdx";
		ResultSet resultSet = null;
		try {
				Connection cnx = schema.getCnx();
				String sql = "SELECT " + schema.getLowerDbSchemaName() + ".sp_delete_iso_cntryccy_by_ctryidx( ?, ?, ?, ?, ?" + ", "
					+		"?" + " ) as DeletedFlag";
				if( stmtDeleteByCtryIdx == null ) {
					stmtDeleteByCtryIdx = cnx.prepareStatement( sql );
				}
				int argIdx = 1;
				stmtDeleteByCtryIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
				stmtDeleteByCtryIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
				stmtDeleteByCtryIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
				stmtDeleteByCtryIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
				stmtDeleteByCtryIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
				stmtDeleteByCtryIdx.setShort( argIdx++, argISOCtryId );
				resultSet = stmtDeleteByCtryIdx.executeQuery();
				if( resultSet.next() ) {
					boolean deleteFlag = resultSet.getBoolean( 1 );
					if( resultSet.next() ) {
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Did not expect multi-record response" );
					}
				}
				else {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Expected 1 record result set to be returned by delete, not 0 rows" );
				}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public void deleteISOCtryCcyByCtryIdx( CFSecAuthorization Authorization,
		CFSecISOCtryCcyByCtryIdxKey argKey )
	{
		deleteISOCtryCcyByCtryIdx( Authorization,
			argKey.getRequiredISOCtryId() );
	}

	public void deleteISOCtryCcyByCcyIdx( CFSecAuthorization Authorization,
		short argISOCcyId )
	{
		final String S_ProcName = "deleteISOCtryCcyByCcyIdx";
		ResultSet resultSet = null;
		try {
				Connection cnx = schema.getCnx();
				String sql = "SELECT " + schema.getLowerDbSchemaName() + ".sp_delete_iso_cntryccy_by_ccyidx( ?, ?, ?, ?, ?" + ", "
					+		"?" + " ) as DeletedFlag";
				if( stmtDeleteByCcyIdx == null ) {
					stmtDeleteByCcyIdx = cnx.prepareStatement( sql );
				}
				int argIdx = 1;
				stmtDeleteByCcyIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
				stmtDeleteByCcyIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
				stmtDeleteByCcyIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
				stmtDeleteByCcyIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
				stmtDeleteByCcyIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
				stmtDeleteByCcyIdx.setShort( argIdx++, argISOCcyId );
				resultSet = stmtDeleteByCcyIdx.executeQuery();
				if( resultSet.next() ) {
					boolean deleteFlag = resultSet.getBoolean( 1 );
					if( resultSet.next() ) {
						throw new CFLibRuntimeException( getClass(),
							S_ProcName,
							"Did not expect multi-record response" );
					}
				}
				else {
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Expected 1 record result set to be returned by delete, not 0 rows" );
				}
		}
		catch( SQLException e ) {
			throw new CFLibDbException( getClass(),
				S_ProcName,
				e );
		}
		finally {
			if( resultSet != null ) {
				try {
					resultSet.close();
				}
				catch( SQLException e ) {
				}
				resultSet = null;
			}
		}
	}

	public void deleteISOCtryCcyByCcyIdx( CFSecAuthorization Authorization,
		CFSecISOCtryCcyByCcyIdxKey argKey )
	{
		deleteISOCtryCcyByCcyIdx( Authorization,
			argKey.getRequiredISOCcyId() );
	}

	/**
	 *	Release the prepared statements.
	 *	<p>
	 *	When the schema changes connections, the prepared statements
	 *	have to be released because they contain connection-specific
	 *	information for most databases.
	 */
	public void releasePreparedStatements() {
		final String S_ProcName = "releasePreparedStatements";
		S_sqlSelectISOCtryCcyDistinctClassCode = null;
		S_sqlSelectISOCtryCcyBuff = null;

		if( stmtReadBuffByPKey != null ) {
			try {
				stmtReadBuffByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByPKey = null;
		}
		if( stmtReadBuffAll != null ) {
			try {
				stmtReadBuffAll.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffAll = null;
		}
		if( stmtLockBuffByPKey != null ) {
			try {
				stmtLockBuffByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtLockBuffByPKey = null;
		}
		if( stmtCreateByPKey != null ) {
			try {
				stmtCreateByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtCreateByPKey = null;
		}
		if( stmtUpdateByPKey != null ) {
			try {
				stmtUpdateByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtUpdateByPKey = null;
		}
		if( stmtDeleteByPKey != null ) {
			try {
				stmtDeleteByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByPKey = null;
		}
		if( stmtDeleteByIdIdx != null ) {
			try {
				stmtDeleteByIdIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByIdIdx = null;
		}
		if( stmtDeleteByCtryIdx != null ) {
			try {
				stmtDeleteByCtryIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByCtryIdx = null;
		}
		if( stmtDeleteByCcyIdx != null ) {
			try {
				stmtDeleteByCcyIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByCcyIdx = null;
		}
		if( stmtReadAllBuff != null ) {
			try {
				stmtReadAllBuff.close();
			}
			catch( SQLException e ) {
			}
			stmtReadAllBuff = null;
		}
		if( stmtReadBuffByIdIdx != null ) {
			try {
				stmtReadBuffByIdIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByIdIdx = null;
		}
		if( stmtReadBuffByCtryIdx != null ) {
			try {
				stmtReadBuffByCtryIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByCtryIdx = null;
		}
		if( stmtReadBuffByCcyIdx != null ) {
			try {
				stmtReadBuffByCcyIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByCcyIdx = null;
		}
	}
}