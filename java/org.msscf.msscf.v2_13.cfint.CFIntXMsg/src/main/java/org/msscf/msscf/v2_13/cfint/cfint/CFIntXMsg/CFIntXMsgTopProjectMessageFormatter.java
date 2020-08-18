
// Description: Java 11 XML Message message formatter for CFInt.TopProject

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

package org.msscf.msscf.v2_13.cfint.cfint.CFIntXMsg;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.apache.commons.codec.binary.Base64;
import org.xml.sax.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/*
 *	CFIntXMsgTopProjectMessageFormatter XML message formatter
 *	for CFInt.TopProject.
 */
public class CFIntXMsgTopProjectMessageFormatter
{
	public CFIntXMsgTopProjectMessageFormatter() {
	}

	public static String formatTopProjectPKeyAttributes( String separator, CFIntTopProjectPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"TenantId",
				pkey.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"Id",
				pkey.getRequiredId() );
		return( retval );
	}

	public static String formatTopProjectPKeyAttributes( String separator, CFIntTopProjectBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"TenantId",
					buff.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					buff.getRequiredId() );
		return( retval );
	}

	public static String formatTopProjectBuffAttributes( String separator, CFIntTopProjectBuff buff ) {
		String retval = CFIntXMsgTopProjectMessageFormatter.formatTopProjectPKeyAttributes( separator, buff )
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
					"TopDomainId",
					buff.getRequiredTopDomainId() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					buff.getRequiredName() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"Description",
					buff.getOptionalDescription() );
		return( retval );
	}

	public static String formatTopProjectRqstCreate( String separator, CFIntTopProjectBuff buff ) {
		String retval = "<RqstTopProjectCreate "
			+	formatTopProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstRead( String separator, CFIntTopProjectPKey pkey ) {
		String retval = "<RqstTopProjectRead "
			+	formatTopProjectPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstRead( String separator, CFIntTopProjectBuff buff ) {
		String retval = "<RqstTopProjectRead "
			+	formatTopProjectPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstRead( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTopProjectRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstReadAll( String separator ) {
		String retval = "<RqstTopProjectReadAll />";
		return( retval );
	}

	public static String formatTopProjectRqstRdByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTopProjectRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstRdByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTopProjectRdByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstRdByTopDomainIdx( String separator,
		long argTenantId,
		long argTopDomainId )
	{
		String retval = "<RqstTopProjectRdByTopDomainIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TopDomainId",
					argTopDomainId )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstRdByNameIdx( String separator,
		long argTenantId,
		long argTopDomainId,
		String argName )
	{
		String retval = "<RqstTopProjectRdByNameIdx "
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

	public static String formatTopProjectRqstLock( String separator, CFIntTopProjectPKey pkey ) {
		String retval = "<RqstTopProjectLock "
			+	formatTopProjectPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstLock( String separator, CFIntTopProjectBuff buff ) {
		String retval = "<RqstTopProjectLock "
			+	formatTopProjectPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstLock( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTopProjectLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstUpdate( String separator, CFIntTopProjectBuff buff ) {
		String retval = "<RqstTopProjectUpdate "
			+	formatTopProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstDelete( String separator, CFIntTopProjectBuff buff ) {
		String retval = "<RqstTopProjectDelete "
				+	formatTopProjectPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstDelByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstTopProjectDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstDelByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstTopProjectDelByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstDelByTopDomainIdx( String separator,
		long argTenantId,
		long argTopDomainId )
	{
		String retval = "<RqstTopProjectDelByTopDomainIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TopDomainId",
					argTopDomainId )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRqstDelByNameIdx( String separator,
		long argTenantId,
		long argTopDomainId,
		String argName )
	{
		String retval = "<RqstTopProjectDelByNameIdx "
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

	public static String formatTopProjectRspnSingleOpenTag() {
		String retval = "<RspnTopProjectReadSingle>";
		return( retval );
	}

	public static String formatTopProjectRspnSingleCloseTag() {
		String retval = "</RspnTopProjectReadSingle>";
		return( retval );
	}

	public static String formatTopProjectRspnListOpenTag() {
		String retval = "<RspnTopProjectReadList>";
		return( retval );
	}

	public static String formatTopProjectRspnListCloseTag() {
		String retval = "</RspnTopProjectReadList>";
		return( retval );
	}

	public static String formatTopProjectRspnRec( String separator, CFIntTopProjectBuff buff ) {
		String retval = "<TopProject "
			+	formatTopProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRspnDerivedRec( String separator, CFIntTopProjectBuff buff ) {
		String retval;
		retval = formatTopProjectRspnRec( separator, buff );
		return( retval );
	}

	public static String formatTopProjectRspnCreated( String separator, CFIntTopProjectBuff buff ) {
		String retval = "<RspnTopProjectCreated "
			+	formatTopProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRspnLocked( String separator, CFIntTopProjectBuff buff ) {
		String retval = "<RspnTopProjectLocked "
			+	formatTopProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRspnUpdated( String separator, CFIntTopProjectBuff buff ) {
		String retval = "<RspnTopProjectUpdated "
			+	formatTopProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatTopProjectRspnDeleted() {
		String retval = "<RspnTopProjectDeleted />";
		return( retval );
	}
}
