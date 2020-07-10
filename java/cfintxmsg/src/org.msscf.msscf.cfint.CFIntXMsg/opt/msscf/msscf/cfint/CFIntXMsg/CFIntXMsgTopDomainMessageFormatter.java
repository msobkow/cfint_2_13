
// Description: Java 11 XML Message message formatter for CFInt.TopDomain

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
 *	CFIntXMsgTopDomainMessageFormatter XML message formatter
 *	for CFInt.TopDomain.
 */
public class CFIntXMsgTopDomainMessageFormatter
{
	public CFIntXMsgTopDomainMessageFormatter() {
	}

	public static String formatTopDomainPKeyAttributes( String separator, CFIntTopDomainPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"TenantId",
				pkey.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"Id",
				pkey.getRequiredId() );
		return( retval );
	}

	public static String formatTopDomainPKeyAttributes( String separator, CFIntTopDomainBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"TenantId",
					buff.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					buff.getRequiredId() );
		return( retval );
	}

	public static String formatTopDomainBuffAttributes( String separator, CFIntTopDomainBuff buff ) {
		String retval = CFIntXMsgTopDomainMessageFormatter.formatTopDomainPKeyAttributes( separator, buff )
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
					"TldId",
					buff.getRequiredTldId() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					buff.getRequiredName() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"Description",
					buff.getOptionalDescription() );
		return( retval );
	}

	public static String formatTopDomainRqstCreate( String separator, CFIntTopDomainBuff buff ) {
		String retval = "<RqstTopDomainCreate "
			+	formatTopDomainBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstRead( String separator, CFIntTopDomainPKey pkey ) {
		String retval = "<RqstTopDomainRead "
			+	formatTopDomainPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstRead( String separator, CFIntTopDomainBuff buff ) {
		String retval = "<RqstTopDomainRead "
			+	formatTopDomainPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstRead( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTopDomainRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstReadAll( String separator ) {
		String retval = "<RqstTopDomainReadAll />";
		return( retval );
	}

	public static String formatTopDomainRqstRdByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTopDomainRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstRdByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTopDomainRdByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstRdByTldIdx( String separator,
		long argTenantId,
		long argTldId )
	{
		String retval = "<RqstTopDomainRdByTldIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TldId",
					argTldId )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstRdByNameIdx( String separator,
		long argTenantId,
		long argTldId,
		String argName )
	{
		String retval = "<RqstTopDomainRdByNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TldId",
					argTldId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstLock( String separator, CFIntTopDomainPKey pkey ) {
		String retval = "<RqstTopDomainLock "
			+	formatTopDomainPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstLock( String separator, CFIntTopDomainBuff buff ) {
		String retval = "<RqstTopDomainLock "
			+	formatTopDomainPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstLock( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTopDomainLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstUpdate( String separator, CFIntTopDomainBuff buff ) {
		String retval = "<RqstTopDomainUpdate "
			+	formatTopDomainBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstDelete( String separator, CFIntTopDomainBuff buff ) {
		String retval = "<RqstTopDomainDelete "
				+	formatTopDomainPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstDelByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTopDomainDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstDelByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTopDomainDelByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstDelByTldIdx( String separator,
		long argTenantId,
		long argTldId )
	{
		String retval = "<RqstTopDomainDelByTldIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TldId",
					argTldId )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRqstDelByNameIdx( String separator,
		long argTenantId,
		long argTldId,
		String argName )
	{
		String retval = "<RqstTopDomainDelByNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TldId",
					argTldId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRspnSingleOpenTag() {
		String retval = "<RspnTopDomainReadSingle>";
		return( retval );
	}

	public static String formatTopDomainRspnSingleCloseTag() {
		String retval = "</RspnTopDomainReadSingle>";
		return( retval );
	}

	public static String formatTopDomainRspnListOpenTag() {
		String retval = "<RspnTopDomainReadList>";
		return( retval );
	}

	public static String formatTopDomainRspnListCloseTag() {
		String retval = "</RspnTopDomainReadList>";
		return( retval );
	}

	public static String formatTopDomainRspnRec( String separator, CFIntTopDomainBuff buff ) {
		String retval = "<TopDomain "
			+	formatTopDomainBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRspnDerivedRec( String separator, CFIntTopDomainBuff buff ) {
		String retval;
		retval = formatTopDomainRspnRec( separator, buff );
		return( retval );
	}

	public static String formatTopDomainRspnCreated( String separator, CFIntTopDomainBuff buff ) {
		String retval = "<RspnTopDomainCreated "
			+	formatTopDomainBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRspnLocked( String separator, CFIntTopDomainBuff buff ) {
		String retval = "<RspnTopDomainLocked "
			+	formatTopDomainBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRspnUpdated( String separator, CFIntTopDomainBuff buff ) {
		String retval = "<RspnTopDomainUpdated "
			+	formatTopDomainBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopDomainRspnDeleted() {
		String retval = "<RspnTopDomainDeleted />";
		return( retval );
	}
}
