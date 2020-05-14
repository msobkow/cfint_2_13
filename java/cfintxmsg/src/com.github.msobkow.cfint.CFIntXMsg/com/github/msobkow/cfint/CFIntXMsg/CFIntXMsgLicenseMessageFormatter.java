
// Description: Java 11 XML Message message formatter for CFInt.License

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

package com.github.msobkow.cfint.CFIntXMsg;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfint.CFInt.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFIntObj.*;

/*
 *	CFIntXMsgLicenseMessageFormatter XML message formatter
 *	for CFInt.License.
 */
public class CFIntXMsgLicenseMessageFormatter
{
	public CFIntXMsgLicenseMessageFormatter() {
	}

	public static String formatLicensePKeyAttributes( String separator, CFIntLicensePKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"TenantId",
				pkey.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"Id",
				pkey.getRequiredId() );
		return( retval );
	}

	public static String formatLicensePKeyAttributes( String separator, CFIntLicenseBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"TenantId",
					buff.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					buff.getRequiredId() );
		return( retval );
	}

	public static String formatLicenseBuffAttributes( String separator, CFIntLicenseBuff buff ) {
		String retval = CFIntXMsgLicenseMessageFormatter.formatLicensePKeyAttributes( separator, buff )
			+	CFLibXmlUtil.formatRequiredInt32( separator,
					"Revision",
					buff.getRequiredRevision() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TopDomainId",
					buff.getRequiredTopDomainId() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					buff.getRequiredName() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"Description",
					buff.getOptionalDescription() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"EmbeddedText",
					buff.getOptionalEmbeddedText() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"FullText",
					buff.getOptionalFullText() );
		return( retval );
	}

	public static String formatLicenseRqstCreate( String separator, CFIntLicenseBuff buff ) {
		String retval = "<RqstLicenseCreate "
			+	formatLicenseBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstRead( String separator, CFIntLicensePKey pkey ) {
		String retval = "<RqstLicenseRead "
			+	formatLicensePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstRead( String separator, CFIntLicenseBuff buff ) {
		String retval = "<RqstLicenseRead "
			+	formatLicensePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstRead( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstLicenseRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstReadAll( String separator ) {
		String retval = "<RqstLicenseReadAll />";
		return( retval );
	}

	public static String formatLicenseRqstRdByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstLicenseRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstRdByLicnTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstLicenseRdByLicnTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstRdByDomainIdx( String separator,
		long argTenantId,
		long argTopDomainId )
	{
		String retval = "<RqstLicenseRdByDomainIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TopDomainId",
					argTopDomainId )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstRdByUNameIdx( String separator,
		long argTenantId,
		long argTopDomainId,
		String argName )
	{
		String retval = "<RqstLicenseRdByUNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TopDomainId",
					argTopDomainId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstLock( String separator, CFIntLicensePKey pkey ) {
		String retval = "<RqstLicenseLock "
			+	formatLicensePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstLock( String separator, CFIntLicenseBuff buff ) {
		String retval = "<RqstLicenseLock "
			+	formatLicensePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstLock( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstLicenseLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstUpdate( String separator, CFIntLicenseBuff buff ) {
		String retval = "<RqstLicenseUpdate "
			+	formatLicenseBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstDelete( String separator, CFIntLicenseBuff buff ) {
		String retval = "<RqstLicenseDelete "
				+	formatLicensePKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatLicenseRqstDelByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstLicenseDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstDelByLicnTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstLicenseDelByLicnTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstDelByDomainIdx( String separator,
		long argTenantId,
		long argTopDomainId )
	{
		String retval = "<RqstLicenseDelByDomainIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TopDomainId",
					argTopDomainId )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRqstDelByUNameIdx( String separator,
		long argTenantId,
		long argTopDomainId,
		String argName )
	{
		String retval = "<RqstLicenseDelByUNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TopDomainId",
					argTopDomainId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRspnSingleOpenTag() {
		String retval = "<RspnLicenseReadSingle>";
		return( retval );
	}

	public static String formatLicenseRspnSingleCloseTag() {
		String retval = "</RspnLicenseReadSingle>";
		return( retval );
	}

	public static String formatLicenseRspnListOpenTag() {
		String retval = "<RspnLicenseReadList>";
		return( retval );
	}

	public static String formatLicenseRspnListCloseTag() {
		String retval = "</RspnLicenseReadList>";
		return( retval );
	}

	public static String formatLicenseRspnRec( String separator, CFIntLicenseBuff buff ) {
		String retval = "<License "
			+	formatLicenseBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRspnDerivedRec( String separator, CFIntLicenseBuff buff ) {
		String retval;
		retval = formatLicenseRspnRec( separator, buff );
		return( retval );
	}

	public static String formatLicenseRspnCreated( String separator, CFIntLicenseBuff buff ) {
		String retval = "<RspnLicenseCreated "
			+	formatLicenseBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRspnLocked( String separator, CFIntLicenseBuff buff ) {
		String retval = "<RspnLicenseLocked "
			+	formatLicenseBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRspnUpdated( String separator, CFIntLicenseBuff buff ) {
		String retval = "<RspnLicenseUpdated "
			+	formatLicenseBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatLicenseRspnDeleted() {
		String retval = "<RspnLicenseDeleted />";
		return( retval );
	}
}