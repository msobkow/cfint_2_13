
// Description: Java 11 XML Message message formatter for CFInt.TopDomain

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
