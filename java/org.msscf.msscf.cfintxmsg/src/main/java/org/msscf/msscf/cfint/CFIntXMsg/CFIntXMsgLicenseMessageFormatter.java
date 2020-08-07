
// Description: Java 11 XML Message message formatter for CFInt.License

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
