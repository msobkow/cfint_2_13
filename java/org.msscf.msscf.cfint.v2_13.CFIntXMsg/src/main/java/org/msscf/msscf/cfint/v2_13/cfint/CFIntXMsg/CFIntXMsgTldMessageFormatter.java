
// Description: Java 11 XML Message message formatter for CFInt.Tld

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

package org.msscf.msscf.cfint.v2_13.cfint.CFIntXMsg;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/*
 *	CFIntXMsgTldMessageFormatter XML message formatter
 *	for CFInt.Tld.
 */
public class CFIntXMsgTldMessageFormatter
{
	public CFIntXMsgTldMessageFormatter() {
	}

	public static String formatTldPKeyAttributes( String separator, CFIntTldPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"TenantId",
				pkey.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"Id",
				pkey.getRequiredId() );
		return( retval );
	}

	public static String formatTldPKeyAttributes( String separator, CFIntTldBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"TenantId",
					buff.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					buff.getRequiredId() );
		return( retval );
	}

	public static String formatTldBuffAttributes( String separator, CFIntTldBuff buff ) {
		String retval = CFIntXMsgTldMessageFormatter.formatTldPKeyAttributes( separator, buff )
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
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					buff.getRequiredName() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"Description",
					buff.getOptionalDescription() );
		return( retval );
	}

	public static String formatTldRqstCreate( String separator, CFIntTldBuff buff ) {
		String retval = "<RqstTldCreate "
			+	formatTldBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstRead( String separator, CFIntTldPKey pkey ) {
		String retval = "<RqstTldRead "
			+	formatTldPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstRead( String separator, CFIntTldBuff buff ) {
		String retval = "<RqstTldRead "
			+	formatTldPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstRead( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTldRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstReadAll( String separator ) {
		String retval = "<RqstTldReadAll />";
		return( retval );
	}

	public static String formatTldRqstRdByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTldRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstRdByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTldRdByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstRdByNameIdx( String separator,
		long argTenantId,
		String argName )
	{
		String retval = "<RqstTldRdByNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstLock( String separator, CFIntTldPKey pkey ) {
		String retval = "<RqstTldLock "
			+	formatTldPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstLock( String separator, CFIntTldBuff buff ) {
		String retval = "<RqstTldLock "
			+	formatTldPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstLock( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTldLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstUpdate( String separator, CFIntTldBuff buff ) {
		String retval = "<RqstTldUpdate "
			+	formatTldBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstDelete( String separator, CFIntTldBuff buff ) {
		String retval = "<RqstTldDelete "
				+	formatTldPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatTldRqstDelByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTldDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstDelByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTldDelByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTldRqstDelByNameIdx( String separator,
		long argTenantId,
		String argName )
	{
		String retval = "<RqstTldDelByNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatTldRspnSingleOpenTag() {
		String retval = "<RspnTldReadSingle>";
		return( retval );
	}

	public static String formatTldRspnSingleCloseTag() {
		String retval = "</RspnTldReadSingle>";
		return( retval );
	}

	public static String formatTldRspnListOpenTag() {
		String retval = "<RspnTldReadList>";
		return( retval );
	}

	public static String formatTldRspnListCloseTag() {
		String retval = "</RspnTldReadList>";
		return( retval );
	}

	public static String formatTldRspnRec( String separator, CFIntTldBuff buff ) {
		String retval = "<Tld "
			+	formatTldBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTldRspnDerivedRec( String separator, CFIntTldBuff buff ) {
		String retval;
		retval = formatTldRspnRec( separator, buff );
		return( retval );
	}

	public static String formatTldRspnCreated( String separator, CFIntTldBuff buff ) {
		String retval = "<RspnTldCreated "
			+	formatTldBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTldRspnLocked( String separator, CFIntTldBuff buff ) {
		String retval = "<RspnTldLocked "
			+	formatTldBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTldRspnUpdated( String separator, CFIntTldBuff buff ) {
		String retval = "<RspnTldUpdated "
			+	formatTldBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTldRspnDeleted() {
		String retval = "<RspnTldDeleted />";
		return( retval );
	}
}
