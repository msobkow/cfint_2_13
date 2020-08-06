// Description: Java 11 MySQL Jdbc DbIO implementation for License.

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

package org.msscf.msscf.cfint.CFIntMySql;

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
 *	CFIntMySqlLicenseTable MySQL Jdbc DbIO implementation
 *	for License.
 */
public class CFIntMySqlLicenseTable
	implements ICFIntLicenseTable
{
	private CFIntMySqlSchema schema;
	protected PreparedStatement stmtReadBuffByPKey = null;
	protected PreparedStatement stmtLockBuffByPKey = null;
	protected PreparedStatement stmtCreateByPKey = null;
	protected PreparedStatement stmtUpdateByPKey = null;
	protected PreparedStatement stmtDeleteByPKey = null;
	protected PreparedStatement stmtReadAllBuff = null;
	protected PreparedStatement stmtReadBuffByIdIdx = null;
	protected PreparedStatement stmtReadBuffByLicnTenantIdx = null;
	protected PreparedStatement stmtReadBuffByDomainIdx = null;
	protected PreparedStatement stmtReadBuffByUNameIdx = null;
	protected PreparedStatement stmtDeleteByIdIdx = null;
	protected PreparedStatement stmtDeleteByLicnTenantIdx = null;
	protected PreparedStatement stmtDeleteByDomainIdx = null;
	protected PreparedStatement stmtDeleteByUNameIdx = null;

	public CFIntMySqlLicenseTable( CFIntMySqlSchema argSchema ) {
		schema = argSchema;
	}

	public void createLicense( CFSecAuthorization Authorization,
		CFIntLicenseBuff Buff )
	{
		final String S_ProcName = "createLicense";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			long TenantId = Buff.getRequiredTenantId();
			long TopDomainId = Buff.getRequiredTopDomainId();
			String Name = Buff.getRequiredName();
			String Description = Buff.getOptionalDescription();
			String EmbeddedText = Buff.getOptionalEmbeddedText();
			String FullText = Buff.getOptionalFullText();
			Connection cnx = schema.getCnx();
			String sql =
				"call " + schema.getLowerDbSchemaName() + ".sp_create_licn( ?, ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + ", "
				+		"?" + ", "
				+		"?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtCreateByPKey == null ) {
				stmtCreateByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtCreateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtCreateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtCreateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtCreateByPKey.setString( argIdx++, "a101" );
			stmtCreateByPKey.setLong( argIdx++, TenantId );
			stmtCreateByPKey.setLong( argIdx++, TopDomainId );
			stmtCreateByPKey.setString( argIdx++, Name );
			if( Description != null ) {
				stmtCreateByPKey.setString( argIdx++, Description );
			}
			else {
				stmtCreateByPKey.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			if( EmbeddedText != null ) {
				stmtCreateByPKey.setString( argIdx++, EmbeddedText );
			}
			else {
				stmtCreateByPKey.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			if( FullText != null ) {
				stmtCreateByPKey.setString( argIdx++, FullText );
			}
			else {
				stmtCreateByPKey.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			try {
				resultSet = stmtCreateByPKey.executeQuery();
			}
			catch( SQLException e ) {
				if( e.getErrorCode() != 1329 ) {
					throw e;
				}
				resultSet = null;
			}
			if( ( resultSet != null ) && resultSet.next() ) {
				CFIntLicenseBuff createdBuff = unpackLicenseResultSetToBuff( resultSet );
				if( ( resultSet != null ) && resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				Buff.setRequiredTenantId( createdBuff.getRequiredTenantId() );
				Buff.setRequiredId( createdBuff.getRequiredId() );
				Buff.setRequiredTopDomainId( createdBuff.getRequiredTopDomainId() );
				Buff.setRequiredName( createdBuff.getRequiredName() );
				Buff.setOptionalDescription( createdBuff.getOptionalDescription() );
				Buff.setOptionalEmbeddedText( createdBuff.getOptionalEmbeddedText() );
				Buff.setOptionalFullText( createdBuff.getOptionalFullText() );
				Buff.setRequiredRevision( createdBuff.getRequiredRevision() );
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

	protected static String S_sqlSelectLicenseDistinctClassCode = null;

	public String getSqlSelectLicenseDistinctClassCode() {
		if( S_sqlSelectLicenseDistinctClassCode == null ) {
			S_sqlSelectLicenseDistinctClassCode =
					"SELECT "
				+		"DISTINCT a101.ClassCode "
				+	"FROM " + schema.getLowerDbSchemaName() + ".licn AS a101 ";
		}
		return( S_sqlSelectLicenseDistinctClassCode );
	}

	protected static String S_sqlSelectLicenseBuff = null;

	public String getSqlSelectLicenseBuff() {
		if( S_sqlSelectLicenseBuff == null ) {
			S_sqlSelectLicenseBuff =
					"SELECT "
				+		"a101.TenantId, "
				+		"a101.Id, "
				+		"a101.TopDomainId, "
				+		"a101.safe_name, "
				+		"a101.descr, "
				+		"a101.EmbeddedText, "
				+		"a101.FullTxt, "
				+		"a101.Revision "
				+	"FROM " + schema.getLowerDbSchemaName() + ".licn AS a101 ";
		}
		return( S_sqlSelectLicenseBuff );
	}

	protected CFIntLicenseBuff unpackLicenseResultSetToBuff( ResultSet resultSet )
	throws SQLException
	{
		final String S_ProcName = "unpackLicenseResultSetToBuff";
		int idxcol = 1;
		CFIntLicenseBuff buff = schema.getFactoryLicense().newBuff();		buff.setRequiredTenantId( resultSet.getLong( idxcol ) );
		idxcol++;
		buff.setRequiredId( resultSet.getLong( idxcol ) );
		idxcol++;
		buff.setRequiredTopDomainId( resultSet.getLong( idxcol ) );
		idxcol++;
		buff.setRequiredName( resultSet.getString( idxcol ) );
		idxcol++;
		{
			String colVal = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setOptionalDescription( null );
			}
			else {
				buff.setOptionalDescription( colVal );
			}
		}
		idxcol++;
		{
			String colVal = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setOptionalEmbeddedText( null );
			}
			else {
				buff.setOptionalEmbeddedText( colVal );
			}
		}
		idxcol++;
		{
			String colVal = resultSet.getString( idxcol );
			if( resultSet.wasNull() ) {
				buff.setOptionalFullText( null );
			}
			else {
				buff.setOptionalFullText( colVal );
			}
		}
		idxcol++;

		buff.setRequiredRevision( resultSet.getInt( idxcol ) );
		return( buff );
	}

	public CFIntLicenseBuff readDerived( CFSecAuthorization Authorization,
		CFIntLicensePKey PKey )
	{
		final String S_ProcName = "readDerived";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFIntLicenseBuff buff;
		buff = readBuff( Authorization, PKey );
		return( buff );
	}

	public CFIntLicenseBuff lockDerived( CFSecAuthorization Authorization,
		CFIntLicensePKey PKey )
	{
		final String S_ProcName = "lockDerived";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFIntLicenseBuff buff;
		buff = lockBuff( Authorization, PKey );
		return( buff );
	}

	public CFIntLicenseBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllDerived";
		CFIntLicenseBuff[] buffArray;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buffArray = readAllBuff( Authorization );
		return( buffArray );
	}

	public CFIntLicenseBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		long TenantId,
		long Id )
	{
		final String S_ProcName = "CFIntMySqlLicenseTable.readDerivedByIdIdx() ";
		CFIntLicenseBuff buff;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buff = readBuffByIdIdx( Authorization,
				TenantId,
				Id );
		return( buff );
	}

	public CFIntLicenseBuff[] readDerivedByLicnTenantIdx( CFSecAuthorization Authorization,
		long TenantId )
	{
		final String S_ProcName = "readDerivedByLicnTenantIdx";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFIntLicenseBuff[] buffList = readBuffByLicnTenantIdx( Authorization,
				TenantId );
		return( buffList );

	}

	public CFIntLicenseBuff[] readDerivedByDomainIdx( CFSecAuthorization Authorization,
		long TenantId,
		long TopDomainId )
	{
		final String S_ProcName = "readDerivedByDomainIdx";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		CFIntLicenseBuff[] buffList = readBuffByDomainIdx( Authorization,
				TenantId,
				TopDomainId );
		return( buffList );

	}

	public CFIntLicenseBuff readDerivedByUNameIdx( CFSecAuthorization Authorization,
		long TenantId,
		long TopDomainId,
		String Name )
	{
		final String S_ProcName = "CFIntMySqlLicenseTable.readDerivedByUNameIdx() ";
		CFIntLicenseBuff buff;
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		buff = readBuffByUNameIdx( Authorization,
				TenantId,
				TopDomainId,
				Name );
		return( buff );
	}

	public CFIntLicenseBuff readBuff( CFSecAuthorization Authorization,
		CFIntLicensePKey PKey )
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
			long TenantId = PKey.getRequiredTenantId();
			long Id = PKey.getRequiredId();
			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_read_licn( ?, ?, ?, ?, ?" + ", "
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
			stmtReadBuffByPKey.setLong( argIdx++, TenantId );
			stmtReadBuffByPKey.setLong( argIdx++, Id );
			try {
				resultSet = stmtReadBuffByPKey.executeQuery();
			}
			catch( SQLException e ) {
				if( e.getErrorCode() != 1329 ) {
					throw e;
				}
				resultSet = null;
			}
			if( ( resultSet != null ) && resultSet.next() ) {
				CFIntLicenseBuff buff = unpackLicenseResultSetToBuff( resultSet );
				if( ( resultSet != null ) && resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
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

	public CFIntLicenseBuff lockBuff( CFSecAuthorization Authorization,
		CFIntLicensePKey PKey )
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
			long TenantId = PKey.getRequiredTenantId();
			long Id = PKey.getRequiredId();
			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_lock_licn( ?, ?, ?, ?, ?" + ", "
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
			stmtLockBuffByPKey.setLong( argIdx++, TenantId );
			stmtLockBuffByPKey.setLong( argIdx++, Id );
			try {
				resultSet = stmtLockBuffByPKey.executeQuery();
			}
			catch( SQLException e ) {
				if( e.getErrorCode() != 1329 ) {
					throw e;
				}
				resultSet = null;
			}
			if( ( resultSet != null ) && resultSet.next() ) {
				CFIntLicenseBuff buff = unpackLicenseResultSetToBuff( resultSet );
				if( ( resultSet != null ) && resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
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

	public CFIntLicenseBuff[] readAllBuff( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllBuff";
		if( ! schema.isTransactionOpen() ) {
			throw new CFLibUsageException( getClass(),
				S_ProcName,
				"Transaction not open" );
		}
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_read_licn_all( ?, ?, ?, ?, ? )";
			if( stmtReadAllBuff == null ) {
				stmtReadAllBuff = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadAllBuff.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadAllBuff.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadAllBuff.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadAllBuff.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadAllBuff.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			try {
				resultSet = stmtReadAllBuff.executeQuery();
			}
			catch( SQLException e ) {
				if( e.getErrorCode() != 1329 ) {
					throw e;
				}
				resultSet = null;
			}
			List<CFIntLicenseBuff> buffList = new LinkedList<CFIntLicenseBuff>();
			while( ( resultSet != null ) && resultSet.next() ) {
				CFIntLicenseBuff buff = unpackLicenseResultSetToBuff( resultSet );
				buffList.add( buff );
			}
			int idx = 0;
			CFIntLicenseBuff[] retBuff = new CFIntLicenseBuff[ buffList.size() ];
			Iterator<CFIntLicenseBuff> iter = buffList.iterator();
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

	public CFIntLicenseBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		long TenantId,
		long Id )
	{
		final String S_ProcName = "readBuffByIdIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_read_licn_by_ididx( ?, ?, ?, ?, ?" + ", "
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
			stmtReadBuffByIdIdx.setLong( argIdx++, TenantId );
			stmtReadBuffByIdIdx.setLong( argIdx++, Id );
			try {
				resultSet = stmtReadBuffByIdIdx.executeQuery();
			}
			catch( SQLException e ) {
				if( e.getErrorCode() != 1329 ) {
					throw e;
				}
				resultSet = null;
			}
			if( ( resultSet != null ) && resultSet.next() ) {
				CFIntLicenseBuff buff = unpackLicenseResultSetToBuff( resultSet );
				if( ( resultSet != null ) && resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
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

	public CFIntLicenseBuff[] readBuffByLicnTenantIdx( CFSecAuthorization Authorization,
		long TenantId )
	{
		final String S_ProcName = "readBuffByLicnTenantIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_read_licn_by_licntenantidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + " )";
			if( stmtReadBuffByLicnTenantIdx == null ) {
				stmtReadBuffByLicnTenantIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByLicnTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByLicnTenantIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByLicnTenantIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByLicnTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByLicnTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByLicnTenantIdx.setLong( argIdx++, TenantId );
			try {
				resultSet = stmtReadBuffByLicnTenantIdx.executeQuery();
			}
			catch( SQLException e ) {
				if( e.getErrorCode() != 1329 ) {
					throw e;
				}
				resultSet = null;
			}
			List<CFIntLicenseBuff> buffList = new LinkedList<CFIntLicenseBuff>();
			while( ( resultSet != null ) && resultSet.next() ) {
				CFIntLicenseBuff buff = unpackLicenseResultSetToBuff( resultSet );
				buffList.add( buff );
			}
			int idx = 0;
			CFIntLicenseBuff[] retBuff = new CFIntLicenseBuff[ buffList.size() ];
			Iterator<CFIntLicenseBuff> iter = buffList.iterator();
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

	public CFIntLicenseBuff[] readBuffByDomainIdx( CFSecAuthorization Authorization,
		long TenantId,
		long TopDomainId )
	{
		final String S_ProcName = "readBuffByDomainIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_read_licn_by_domainidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtReadBuffByDomainIdx == null ) {
				stmtReadBuffByDomainIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByDomainIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByDomainIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByDomainIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByDomainIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByDomainIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByDomainIdx.setLong( argIdx++, TenantId );
			stmtReadBuffByDomainIdx.setLong( argIdx++, TopDomainId );
			try {
				resultSet = stmtReadBuffByDomainIdx.executeQuery();
			}
			catch( SQLException e ) {
				if( e.getErrorCode() != 1329 ) {
					throw e;
				}
				resultSet = null;
			}
			List<CFIntLicenseBuff> buffList = new LinkedList<CFIntLicenseBuff>();
			while( ( resultSet != null ) && resultSet.next() ) {
				CFIntLicenseBuff buff = unpackLicenseResultSetToBuff( resultSet );
				buffList.add( buff );
			}
			int idx = 0;
			CFIntLicenseBuff[] retBuff = new CFIntLicenseBuff[ buffList.size() ];
			Iterator<CFIntLicenseBuff> iter = buffList.iterator();
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

	public CFIntLicenseBuff readBuffByUNameIdx( CFSecAuthorization Authorization,
		long TenantId,
		long TopDomainId,
		String Name )
	{
		final String S_ProcName = "readBuffByUNameIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_read_licn_by_unameidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtReadBuffByUNameIdx == null ) {
				stmtReadBuffByUNameIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtReadBuffByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByUNameIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtReadBuffByUNameIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtReadBuffByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtReadBuffByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtReadBuffByUNameIdx.setLong( argIdx++, TenantId );
			stmtReadBuffByUNameIdx.setLong( argIdx++, TopDomainId );
			stmtReadBuffByUNameIdx.setString( argIdx++, Name );
			try {
				resultSet = stmtReadBuffByUNameIdx.executeQuery();
			}
			catch( SQLException e ) {
				if( e.getErrorCode() != 1329 ) {
					throw e;
				}
				resultSet = null;
			}
			if( ( resultSet != null ) && resultSet.next() ) {
				CFIntLicenseBuff buff = unpackLicenseResultSetToBuff( resultSet );
				if( ( resultSet != null ) && resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
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

	public void updateLicense( CFSecAuthorization Authorization,
		CFIntLicenseBuff Buff )
	{
		final String S_ProcName = "updateLicense";
		ResultSet resultSet = null;
		try {
			long TenantId = Buff.getRequiredTenantId();
			long Id = Buff.getRequiredId();
			long TopDomainId = Buff.getRequiredTopDomainId();
			String Name = Buff.getRequiredName();
			String Description = Buff.getOptionalDescription();
			String EmbeddedText = Buff.getOptionalEmbeddedText();
			String FullText = Buff.getOptionalFullText();
			int Revision = Buff.getRequiredRevision();
			Connection cnx = schema.getCnx();
			String sql =
				"call " + schema.getLowerDbSchemaName() + ".sp_update_licn( ?, ?, ?, ?, ?, ?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+	"?" + ", "
					+ "?" + " )";
			if( stmtUpdateByPKey == null ) {
				stmtUpdateByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtUpdateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtUpdateByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtUpdateByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtUpdateByPKey.setString( argIdx++, "a101" );
			stmtUpdateByPKey.setLong( argIdx++, TenantId );
			stmtUpdateByPKey.setLong( argIdx++, Id );
			stmtUpdateByPKey.setLong( argIdx++, TopDomainId );
			stmtUpdateByPKey.setString( argIdx++, Name );
			if( Description != null ) {
				stmtUpdateByPKey.setString( argIdx++, Description );
			}
			else {
				stmtUpdateByPKey.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			if( EmbeddedText != null ) {
				stmtUpdateByPKey.setString( argIdx++, EmbeddedText );
			}
			else {
				stmtUpdateByPKey.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			if( FullText != null ) {
				stmtUpdateByPKey.setString( argIdx++, FullText );
			}
			else {
				stmtUpdateByPKey.setNull( argIdx++, java.sql.Types.VARCHAR );
			}
			stmtUpdateByPKey.setInt( argIdx++, Revision );
			try {
				resultSet = stmtUpdateByPKey.executeQuery();
			}
			catch( SQLException e ) {
				if( e.getErrorCode() != 1329 ) {
					throw e;
				}
				resultSet = null;
			}
			if( ( resultSet != null ) && resultSet.next() ) {
				CFIntLicenseBuff updatedBuff = unpackLicenseResultSetToBuff( resultSet );
				if( ( resultSet != null ) && resultSet.next() ) {
					resultSet.last();
					throw new CFLibRuntimeException( getClass(),
						S_ProcName,
						"Did not expect multi-record response, " + resultSet.getRow() + " rows selected" );
				}
				Buff.setRequiredTopDomainId( updatedBuff.getRequiredTopDomainId() );
				Buff.setRequiredName( updatedBuff.getRequiredName() );
				Buff.setOptionalDescription( updatedBuff.getOptionalDescription() );
				Buff.setOptionalEmbeddedText( updatedBuff.getOptionalEmbeddedText() );
				Buff.setOptionalFullText( updatedBuff.getOptionalFullText() );
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

	public void deleteLicense( CFSecAuthorization Authorization,
		CFIntLicenseBuff Buff )
	{
		final String S_ProcName = "deleteLicense";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			long TenantId = Buff.getRequiredTenantId();
			long Id = Buff.getRequiredId();

			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_delete_licn( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtDeleteByPKey == null ) {
				stmtDeleteByPKey = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByPKey.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByPKey.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByPKey.setLong( argIdx++, TenantId );
			stmtDeleteByPKey.setLong( argIdx++, Id );
			stmtDeleteByPKey.setInt( argIdx++, Buff.getRequiredRevision() );;
			stmtDeleteByPKey.executeUpdate();
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

	public void deleteLicenseByIdIdx( CFSecAuthorization Authorization,
		long argTenantId,
		long argId )
	{
		final String S_ProcName = "deleteLicenseByIdIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_delete_licn_by_ididx( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtDeleteByIdIdx == null ) {
				stmtDeleteByIdIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByIdIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByIdIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByIdIdx.setLong( argIdx++, argTenantId );
			stmtDeleteByIdIdx.setLong( argIdx++, argId );
			stmtDeleteByIdIdx.executeUpdate();
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

	public void deleteLicenseByIdIdx( CFSecAuthorization Authorization,
		CFIntLicensePKey argKey )
	{
		deleteLicenseByIdIdx( Authorization,
			argKey.getRequiredTenantId(),
			argKey.getRequiredId() );
	}

	public void deleteLicenseByLicnTenantIdx( CFSecAuthorization Authorization,
		long argTenantId )
	{
		final String S_ProcName = "deleteLicenseByLicnTenantIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_delete_licn_by_licntenantidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + " )";
			if( stmtDeleteByLicnTenantIdx == null ) {
				stmtDeleteByLicnTenantIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByLicnTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByLicnTenantIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByLicnTenantIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByLicnTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByLicnTenantIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByLicnTenantIdx.setLong( argIdx++, argTenantId );
			stmtDeleteByLicnTenantIdx.executeUpdate();
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

	public void deleteLicenseByLicnTenantIdx( CFSecAuthorization Authorization,
		CFIntLicenseByLicnTenantIdxKey argKey )
	{
		deleteLicenseByLicnTenantIdx( Authorization,
			argKey.getRequiredTenantId() );
	}

	public void deleteLicenseByDomainIdx( CFSecAuthorization Authorization,
		long argTenantId,
		long argTopDomainId )
	{
		final String S_ProcName = "deleteLicenseByDomainIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_delete_licn_by_domainidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtDeleteByDomainIdx == null ) {
				stmtDeleteByDomainIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByDomainIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByDomainIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByDomainIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByDomainIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByDomainIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByDomainIdx.setLong( argIdx++, argTenantId );
			stmtDeleteByDomainIdx.setLong( argIdx++, argTopDomainId );
			stmtDeleteByDomainIdx.executeUpdate();
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

	public void deleteLicenseByDomainIdx( CFSecAuthorization Authorization,
		CFIntLicenseByDomainIdxKey argKey )
	{
		deleteLicenseByDomainIdx( Authorization,
			argKey.getRequiredTenantId(),
			argKey.getRequiredTopDomainId() );
	}

	public void deleteLicenseByUNameIdx( CFSecAuthorization Authorization,
		long argTenantId,
		long argTopDomainId,
		String argName )
	{
		final String S_ProcName = "deleteLicenseByUNameIdx";
		ResultSet resultSet = null;
		try {
			Connection cnx = schema.getCnx();
			String sql = "call " + schema.getLowerDbSchemaName() + ".sp_delete_licn_by_unameidx( ?, ?, ?, ?, ?" + ", "
				+		"?" + ", "
				+		"?" + ", "
				+		"?" + " )";
			if( stmtDeleteByUNameIdx == null ) {
				stmtDeleteByUNameIdx = cnx.prepareStatement( sql );
			}
			int argIdx = 1;
			stmtDeleteByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByUNameIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecUserId().toString() );
			stmtDeleteByUNameIdx.setString( argIdx++, ( Authorization == null ) ? "" : Authorization.getSecSessionId().toString() );
			stmtDeleteByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecClusterId() );
			stmtDeleteByUNameIdx.setLong( argIdx++, ( Authorization == null ) ? 0 : Authorization.getSecTenantId() );
			stmtDeleteByUNameIdx.setLong( argIdx++, argTenantId );
			stmtDeleteByUNameIdx.setLong( argIdx++, argTopDomainId );
			stmtDeleteByUNameIdx.setString( argIdx++, argName );
			stmtDeleteByUNameIdx.executeUpdate();
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

	public void deleteLicenseByUNameIdx( CFSecAuthorization Authorization,
		CFIntLicenseByUNameIdxKey argKey )
	{
		deleteLicenseByUNameIdx( Authorization,
			argKey.getRequiredTenantId(),
			argKey.getRequiredTopDomainId(),
			argKey.getRequiredName() );
	}

	/**
	 *	Release the prepared statements.
	 *	<p>
	 *	When the schema changes connections, the prepared statements
	 *	have to be released because they contain connection-specific
	 *	information for most databases.
	 */
	public void releasePreparedStatements() {
		S_sqlSelectLicenseDistinctClassCode = null;
		S_sqlSelectLicenseBuff = null;
		if( stmtReadBuffByPKey != null ) {
			try {
				stmtReadBuffByPKey.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByPKey = null;
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
		if( stmtDeleteByLicnTenantIdx != null ) {
			try {
				stmtDeleteByLicnTenantIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByLicnTenantIdx = null;
		}
		if( stmtDeleteByDomainIdx != null ) {
			try {
				stmtDeleteByDomainIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByDomainIdx = null;
		}
		if( stmtDeleteByUNameIdx != null ) {
			try {
				stmtDeleteByUNameIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtDeleteByUNameIdx = null;
		}
		if( stmtReadAllBuff != null ) {
			try {
				stmtReadAllBuff .close();
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
		if( stmtReadBuffByLicnTenantIdx != null ) {
			try {
				stmtReadBuffByLicnTenantIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByLicnTenantIdx = null;
		}
		if( stmtReadBuffByDomainIdx != null ) {
			try {
				stmtReadBuffByDomainIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByDomainIdx = null;
		}
		if( stmtReadBuffByUNameIdx != null ) {
			try {
				stmtReadBuffByUNameIdx.close();
			}
			catch( SQLException e ) {
			}
			stmtReadBuffByUNameIdx = null;
		}
	}
}
