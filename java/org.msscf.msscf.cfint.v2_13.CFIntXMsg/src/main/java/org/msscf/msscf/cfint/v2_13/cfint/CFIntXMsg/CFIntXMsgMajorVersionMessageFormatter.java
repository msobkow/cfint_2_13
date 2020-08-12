
// Description: Java 11 XML Message message formatter for CFInt.MajorVersion

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
 *	CFIntXMsgMajorVersionMessageFormatter XML message formatter
 *	for CFInt.MajorVersion.
 */
public class CFIntXMsgMajorVersionMessageFormatter
{
	public CFIntXMsgMajorVersionMessageFormatter() {
	}

	public static String formatMajorVersionPKeyAttributes( String separator, CFIntMajorVersionPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"TenantId",
				pkey.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"Id",
				pkey.getRequiredId() );
		return( retval );
	}

	public static String formatMajorVersionPKeyAttributes( String separator, CFIntMajorVersionBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"TenantId",
					buff.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					buff.getRequiredId() );
		return( retval );
	}

	public static String formatMajorVersionBuffAttributes( String separator, CFIntMajorVersionBuff buff ) {
		String retval = CFIntXMsgMajorVersionMessageFormatter.formatMajorVersionPKeyAttributes( separator, buff )
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
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SubProjectId",
					buff.getRequiredSubProjectId() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					buff.getRequiredName() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"Description",
					buff.getOptionalDescription() );
		return( retval );
	}

	public static String formatMajorVersionRqstCreate( String separator, CFIntMajorVersionBuff buff ) {
		String retval = "<RqstMajorVersionCreate "
			+	formatMajorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstRead( String separator, CFIntMajorVersionPKey pkey ) {
		String retval = "<RqstMajorVersionRead "
			+	formatMajorVersionPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstRead( String separator, CFIntMajorVersionBuff buff ) {
		String retval = "<RqstMajorVersionRead "
			+	formatMajorVersionPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstRead( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstMajorVersionRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstReadAll( String separator ) {
		String retval = "<RqstMajorVersionReadAll />";
		return( retval );
	}

	public static String formatMajorVersionRqstRdByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstMajorVersionRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstRdByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstMajorVersionRdByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstRdBySubProjectIdx( String separator,
		long argTenantId,
		long argSubProjectId )
	{
		String retval = "<RqstMajorVersionRdBySubProjectIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SubProjectId",
					argSubProjectId )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstRdByNameIdx( String separator,
		long argTenantId,
		long argSubProjectId,
		String argName )
	{
		String retval = "<RqstMajorVersionRdByNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SubProjectId",
					argSubProjectId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstLock( String separator, CFIntMajorVersionPKey pkey ) {
		String retval = "<RqstMajorVersionLock "
			+	formatMajorVersionPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstLock( String separator, CFIntMajorVersionBuff buff ) {
		String retval = "<RqstMajorVersionLock "
			+	formatMajorVersionPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstLock( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstMajorVersionLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstUpdate( String separator, CFIntMajorVersionBuff buff ) {
		String retval = "<RqstMajorVersionUpdate "
			+	formatMajorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstDelete( String separator, CFIntMajorVersionBuff buff ) {
		String retval = "<RqstMajorVersionDelete "
				+	formatMajorVersionPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstDelByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstMajorVersionDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstDelByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstMajorVersionDelByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstDelBySubProjectIdx( String separator,
		long argTenantId,
		long argSubProjectId )
	{
		String retval = "<RqstMajorVersionDelBySubProjectIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SubProjectId",
					argSubProjectId )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRqstDelByNameIdx( String separator,
		long argTenantId,
		long argSubProjectId,
		String argName )
	{
		String retval = "<RqstMajorVersionDelByNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"SubProjectId",
					argSubProjectId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRspnSingleOpenTag() {
		String retval = "<RspnMajorVersionReadSingle>";
		return( retval );
	}

	public static String formatMajorVersionRspnSingleCloseTag() {
		String retval = "</RspnMajorVersionReadSingle>";
		return( retval );
	}

	public static String formatMajorVersionRspnListOpenTag() {
		String retval = "<RspnMajorVersionReadList>";
		return( retval );
	}

	public static String formatMajorVersionRspnListCloseTag() {
		String retval = "</RspnMajorVersionReadList>";
		return( retval );
	}

	public static String formatMajorVersionRspnRec( String separator, CFIntMajorVersionBuff buff ) {
		String retval = "<MajorVersion "
			+	formatMajorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRspnDerivedRec( String separator, CFIntMajorVersionBuff buff ) {
		String retval;
		retval = formatMajorVersionRspnRec( separator, buff );
		return( retval );
	}

	public static String formatMajorVersionRspnCreated( String separator, CFIntMajorVersionBuff buff ) {
		String retval = "<RspnMajorVersionCreated "
			+	formatMajorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRspnLocked( String separator, CFIntMajorVersionBuff buff ) {
		String retval = "<RspnMajorVersionLocked "
			+	formatMajorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRspnUpdated( String separator, CFIntMajorVersionBuff buff ) {
		String retval = "<RspnMajorVersionUpdated "
			+	formatMajorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMajorVersionRspnDeleted() {
		String retval = "<RspnMajorVersionDeleted />";
		return( retval );
	}
}
