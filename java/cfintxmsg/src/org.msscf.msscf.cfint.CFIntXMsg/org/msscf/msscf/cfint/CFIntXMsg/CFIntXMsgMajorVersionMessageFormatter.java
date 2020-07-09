
// Description: Java 11 XML Message message formatter for CFInt.MajorVersion

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

package org.msscf.msscf.cfint.CFIntXMsg;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import com.github.msobkow.cflib.CFLib.*;
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
