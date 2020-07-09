
// Description: Java 11 XML Message message formatter for CFInt.MinorVersion

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
 *	CFIntXMsgMinorVersionMessageFormatter XML message formatter
 *	for CFInt.MinorVersion.
 */
public class CFIntXMsgMinorVersionMessageFormatter
{
	public CFIntXMsgMinorVersionMessageFormatter() {
	}

	public static String formatMinorVersionPKeyAttributes( String separator, CFIntMinorVersionPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"TenantId",
				pkey.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"Id",
				pkey.getRequiredId() );
		return( retval );
	}

	public static String formatMinorVersionPKeyAttributes( String separator, CFIntMinorVersionBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"TenantId",
					buff.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					buff.getRequiredId() );
		return( retval );
	}

	public static String formatMinorVersionBuffAttributes( String separator, CFIntMinorVersionBuff buff ) {
		String retval = CFIntXMsgMinorVersionMessageFormatter.formatMinorVersionPKeyAttributes( separator, buff )
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
					"MajorVersionId",
					buff.getRequiredMajorVersionId() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					buff.getRequiredName() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"Description",
					buff.getOptionalDescription() );
		return( retval );
	}

	public static String formatMinorVersionRqstCreate( String separator, CFIntMinorVersionBuff buff ) {
		String retval = "<RqstMinorVersionCreate "
			+	formatMinorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstRead( String separator, CFIntMinorVersionPKey pkey ) {
		String retval = "<RqstMinorVersionRead "
			+	formatMinorVersionPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstRead( String separator, CFIntMinorVersionBuff buff ) {
		String retval = "<RqstMinorVersionRead "
			+	formatMinorVersionPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstRead( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstMinorVersionRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstReadAll( String separator ) {
		String retval = "<RqstMinorVersionReadAll />";
		return( retval );
	}

	public static String formatMinorVersionRqstRdByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstMinorVersionRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstRdByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstMinorVersionRdByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstRdByMajorVerIdx( String separator,
		long argTenantId,
		long argMajorVersionId )
	{
		String retval = "<RqstMinorVersionRdByMajorVerIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"MajorVersionId",
					argMajorVersionId )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstRdByNameIdx( String separator,
		long argTenantId,
		long argMajorVersionId,
		String argName )
	{
		String retval = "<RqstMinorVersionRdByNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"MajorVersionId",
					argMajorVersionId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstLock( String separator, CFIntMinorVersionPKey pkey ) {
		String retval = "<RqstMinorVersionLock "
			+	formatMinorVersionPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstLock( String separator, CFIntMinorVersionBuff buff ) {
		String retval = "<RqstMinorVersionLock "
			+	formatMinorVersionPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstLock( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstMinorVersionLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstUpdate( String separator, CFIntMinorVersionBuff buff ) {
		String retval = "<RqstMinorVersionUpdate "
			+	formatMinorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstDelete( String separator, CFIntMinorVersionBuff buff ) {
		String retval = "<RqstMinorVersionDelete "
				+	formatMinorVersionPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstDelByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstMinorVersionDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstDelByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstMinorVersionDelByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstDelByMajorVerIdx( String separator,
		long argTenantId,
		long argMajorVersionId )
	{
		String retval = "<RqstMinorVersionDelByMajorVerIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"MajorVersionId",
					argMajorVersionId )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRqstDelByNameIdx( String separator,
		long argTenantId,
		long argMajorVersionId,
		String argName )
	{
		String retval = "<RqstMinorVersionDelByNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"MajorVersionId",
					argMajorVersionId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRspnSingleOpenTag() {
		String retval = "<RspnMinorVersionReadSingle>";
		return( retval );
	}

	public static String formatMinorVersionRspnSingleCloseTag() {
		String retval = "</RspnMinorVersionReadSingle>";
		return( retval );
	}

	public static String formatMinorVersionRspnListOpenTag() {
		String retval = "<RspnMinorVersionReadList>";
		return( retval );
	}

	public static String formatMinorVersionRspnListCloseTag() {
		String retval = "</RspnMinorVersionReadList>";
		return( retval );
	}

	public static String formatMinorVersionRspnRec( String separator, CFIntMinorVersionBuff buff ) {
		String retval = "<MinorVersion "
			+	formatMinorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRspnDerivedRec( String separator, CFIntMinorVersionBuff buff ) {
		String retval;
		retval = formatMinorVersionRspnRec( separator, buff );
		return( retval );
	}

	public static String formatMinorVersionRspnCreated( String separator, CFIntMinorVersionBuff buff ) {
		String retval = "<RspnMinorVersionCreated "
			+	formatMinorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRspnLocked( String separator, CFIntMinorVersionBuff buff ) {
		String retval = "<RspnMinorVersionLocked "
			+	formatMinorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRspnUpdated( String separator, CFIntMinorVersionBuff buff ) {
		String retval = "<RspnMinorVersionUpdated "
			+	formatMinorVersionBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMinorVersionRspnDeleted() {
		String retval = "<RspnMinorVersionDeleted />";
		return( retval );
	}
}
