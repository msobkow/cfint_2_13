
// Description: Java 11 XML Message message formatter for CFInt.TSecGrpInc

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

package org.msscf.msscf.cfint.CFIntXMsg;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/*
 *	CFIntXMsgTSecGrpIncMessageFormatter XML message formatter
 *	for CFInt.TSecGrpInc.
 */
public class CFIntXMsgTSecGrpIncMessageFormatter
{
	public CFIntXMsgTSecGrpIncMessageFormatter() {
	}

	public static String formatTSecGrpIncPKeyAttributes( String separator, CFSecTSecGrpIncPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"TenantId",
				pkey.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"TSecGrpIncId",
				pkey.getRequiredTSecGrpIncId() );
		return( retval );
	}

	public static String formatTSecGrpIncPKeyAttributes( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"TenantId",
					buff.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TSecGrpIncId",
					buff.getRequiredTSecGrpIncId() );
		return( retval );
	}

	public static String formatTSecGrpIncBuffAttributes( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval = CFIntXMsgTSecGrpIncMessageFormatter.formatTSecGrpIncPKeyAttributes( separator, buff )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"Revision",
					buff.getRequiredRevision() )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"CreatedBy",
					buff.getCreatedByUserId() )
			+	CFLibXmlUtil.formatOptionalTimestamp( separator,
					"CreatedAt",
					buff.getCreatedAt() )
			+	CFLibXmlUtil.formatOptionalUuid( separator,
					"UpdatedBy",
					buff.getUpdatedByUserId() )
			+	CFLibXmlUtil.formatOptionalTimestamp( separator,
					"UpdatedAt",
					buff.getUpdatedAt() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					buff.getRequiredTSecGroupId() )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"IncludeGroupId",
					buff.getRequiredIncludeGroupId() );
		return( retval );
	}

	public static String formatTSecGrpIncRqstCreate( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval = "<RqstTSecGrpIncCreate "
			+	formatTSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstRead( String separator, CFSecTSecGrpIncPKey pkey ) {
		String retval = "<RqstTSecGrpIncRead "
			+	formatTSecGrpIncPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstRead( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval = "<RqstTSecGrpIncRead "
			+	formatTSecGrpIncPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstRead( String separator,
		long argTenantId,
		long argTSecGrpIncId )
	{
		String retval = "<RqstTSecGrpIncRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TSecGrpIncId",
					argTSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstReadAll( String separator ) {
		String retval = "<RqstTSecGrpIncReadAll />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstPageAll( String separator,
		Long priorTenantId,
		Long priorTSecGrpIncId ) {
		String retval = "<RqstTSecGrpIncPageAll "
			+	CFLibXmlUtil.formatOptionalInt64( null,
					"PriorTenantId",
					priorTenantId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTSecGrpIncId",
					priorTSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstRdByIdIdx( String separator,
		long argTenantId,
		long argTSecGrpIncId )
	{
		String retval = "<RqstTSecGrpIncRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TSecGrpIncId",
					argTSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstRdByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTSecGrpIncRdByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstRdByGroupIdx( String separator,
		long argTenantId,
		int argTSecGroupId )
	{
		String retval = "<RqstTSecGrpIncRdByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstRdByIncludeIdx( String separator,
		long argTenantId,
		int argIncludeGroupId )
	{
		String retval = "<RqstTSecGrpIncRdByIncludeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"IncludeGroupId",
					argIncludeGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstRdByUIncludeIdx( String separator,
		long argTenantId,
		int argTSecGroupId,
		int argIncludeGroupId )
	{
		String retval = "<RqstTSecGrpIncRdByUIncludeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"IncludeGroupId",
					argIncludeGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstPageByTenantIdx( String separator,
		long argTenantId,
		Long priorTenantId,
		Long priorTSecGrpIncId )
	{
		String retval = "<RqstTSecGrpIncPageByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTenantId",
					priorTenantId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTSecGrpIncId",
					priorTSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstPageByGroupIdx( String separator,
		long argTenantId,
		int argTSecGroupId,
		Long priorTenantId,
		Long priorTSecGrpIncId )
	{
		String retval = "<RqstTSecGrpIncPageByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTenantId",
					priorTenantId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTSecGrpIncId",
					priorTSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstPageByIncludeIdx( String separator,
		long argTenantId,
		int argIncludeGroupId,
		Long priorTenantId,
		Long priorTSecGrpIncId )
	{
		String retval = "<RqstTSecGrpIncPageByIncludeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"IncludeGroupId",
					argIncludeGroupId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTenantId",
					priorTenantId )
			+	CFLibXmlUtil.formatOptionalInt64( separator,
					"PriorTSecGrpIncId",
					priorTSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstLock( String separator, CFSecTSecGrpIncPKey pkey ) {
		String retval = "<RqstTSecGrpIncLock "
			+	formatTSecGrpIncPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstLock( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval = "<RqstTSecGrpIncLock "
			+	formatTSecGrpIncPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstLock( String separator,
		long argTenantId,
		long argTSecGrpIncId )
	{
		String retval = "<RqstTSecGrpIncLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TSecGrpIncId",
					argTSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstUpdate( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval = "<RqstTSecGrpIncUpdate "
			+	formatTSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstDelete( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval = "<RqstTSecGrpIncDelete "
				+	formatTSecGrpIncPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstDelByIdIdx( String separator,
		long argTenantId,
		long argTSecGrpIncId )
	{
		String retval = "<RqstTSecGrpIncDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TSecGrpIncId",
					argTSecGrpIncId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstDelByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTSecGrpIncDelByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstDelByGroupIdx( String separator,
		long argTenantId,
		int argTSecGroupId )
	{
		String retval = "<RqstTSecGrpIncDelByGroupIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstDelByIncludeIdx( String separator,
		long argTenantId,
		int argIncludeGroupId )
	{
		String retval = "<RqstTSecGrpIncDelByIncludeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"IncludeGroupId",
					argIncludeGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRqstDelByUIncludeIdx( String separator,
		long argTenantId,
		int argTSecGroupId,
		int argIncludeGroupId )
	{
		String retval = "<RqstTSecGrpIncDelByUIncludeIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"TSecGroupId",
					argTSecGroupId )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"IncludeGroupId",
					argIncludeGroupId )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRspnSingleOpenTag() {
		String retval = "<RspnTSecGrpIncReadSingle>";
		return( retval );
	}

	public static String formatTSecGrpIncRspnSingleCloseTag() {
		String retval = "</RspnTSecGrpIncReadSingle>";
		return( retval );
	}

	public static String formatTSecGrpIncRspnListOpenTag() {
		String retval = "<RspnTSecGrpIncReadList>";
		return( retval );
	}

	public static String formatTSecGrpIncRspnListCloseTag() {
		String retval = "</RspnTSecGrpIncReadList>";
		return( retval );
	}

	public static String formatTSecGrpIncRspnRec( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval = "<TSecGrpInc "
			+	formatTSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRspnDerivedRec( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval;
		retval = formatTSecGrpIncRspnRec( separator, buff );
		return( retval );
	}

	public static String formatTSecGrpIncRspnCreated( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval = "<RspnTSecGrpIncCreated "
			+	formatTSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRspnLocked( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval = "<RspnTSecGrpIncLocked "
			+	formatTSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRspnUpdated( String separator, CFSecTSecGrpIncBuff buff ) {
		String retval = "<RspnTSecGrpIncUpdated "
			+	formatTSecGrpIncBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTSecGrpIncRspnDeleted() {
		String retval = "<RspnTSecGrpIncDeleted />";
		return( retval );
	}
}
