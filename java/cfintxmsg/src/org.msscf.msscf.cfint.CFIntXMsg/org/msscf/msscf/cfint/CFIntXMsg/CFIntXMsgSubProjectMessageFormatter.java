
// Description: Java 11 XML Message message formatter for CFInt.SubProject

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
 *	CFIntXMsgSubProjectMessageFormatter XML message formatter
 *	for CFInt.SubProject.
 */
public class CFIntXMsgSubProjectMessageFormatter
{
	public CFIntXMsgSubProjectMessageFormatter() {
	}

	public static String formatSubProjectPKeyAttributes( String separator, CFIntSubProjectPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( null,
				"TenantId",
				pkey.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
				"Id",
				pkey.getRequiredId() );
		return( retval );
	}

	public static String formatSubProjectPKeyAttributes( String separator, CFIntSubProjectBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt64( separator,
					"TenantId",
					buff.getRequiredTenantId() )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					buff.getRequiredId() );
		return( retval );
	}

	public static String formatSubProjectBuffAttributes( String separator, CFIntSubProjectBuff buff ) {
		String retval = CFIntXMsgSubProjectMessageFormatter.formatSubProjectPKeyAttributes( separator, buff )
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
					"TopProjectId",
					buff.getRequiredTopProjectId() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					buff.getRequiredName() )
			+	CFLibXmlUtil.formatOptionalXmlString( separator,
					"Description",
					buff.getOptionalDescription() );
		return( retval );
	}

	public static String formatSubProjectRqstCreate( String separator, CFIntSubProjectBuff buff ) {
		String retval = "<RqstSubProjectCreate "
			+	formatSubProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstRead( String separator, CFIntSubProjectPKey pkey ) {
		String retval = "<RqstSubProjectRead "
			+	formatSubProjectPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstRead( String separator, CFIntSubProjectBuff buff ) {
		String retval = "<RqstSubProjectRead "
			+	formatSubProjectPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstRead( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstSubProjectRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstReadAll( String separator ) {
		String retval = "<RqstSubProjectReadAll />";
		return( retval );
	}

	public static String formatSubProjectRqstRdByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstSubProjectRead "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstRdByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstSubProjectRdByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstRdByTopProjectIdx( String separator,
		long argTenantId,
		long argTopProjectId )
	{
		String retval = "<RqstSubProjectRdByTopProjectIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TopProjectId",
					argTopProjectId )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstRdByNameIdx( String separator,
		long argTenantId,
		long argTopProjectId,
		String argName )
	{
		String retval = "<RqstSubProjectRdByNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TopProjectId",
					argTopProjectId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstLock( String separator, CFIntSubProjectPKey pkey ) {
		String retval = "<RqstSubProjectLock "
			+	formatSubProjectPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstLock( String separator, CFIntSubProjectBuff buff ) {
		String retval = "<RqstSubProjectLock "
			+	formatSubProjectPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstLock( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstSubProjectLock "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstUpdate( String separator, CFIntSubProjectBuff buff ) {
		String retval = "<RqstSubProjectUpdate "
			+	formatSubProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstDelete( String separator, CFIntSubProjectBuff buff ) {
		String retval = "<RqstSubProjectDelete "
				+	formatSubProjectPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstDelByIdIdx( String separator,
		long argTenantId,
		long argId )
	{
		String retval = "<RqstSubProjectDelete "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"Id",
					argId )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstDelByTenantIdx( String separator,
		long argTenantId )
	{
		String retval = "<RqstSubProjectDelByTenantIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstDelByTopProjectIdx( String separator,
		long argTenantId,
		long argTopProjectId )
	{
		String retval = "<RqstSubProjectDelByTopProjectIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TopProjectId",
					argTopProjectId )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRqstDelByNameIdx( String separator,
		long argTenantId,
		long argTopProjectId,
		String argName )
	{
		String retval = "<RqstSubProjectDelByNameIdx "
			+	CFLibXmlUtil.formatRequiredInt64( null,
					"TenantId",
					argTenantId )
			+	CFLibXmlUtil.formatRequiredInt64( separator,
					"TopProjectId",
					argTopProjectId )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRspnSingleOpenTag() {
		String retval = "<RspnSubProjectReadSingle>";
		return( retval );
	}

	public static String formatSubProjectRspnSingleCloseTag() {
		String retval = "</RspnSubProjectReadSingle>";
		return( retval );
	}

	public static String formatSubProjectRspnListOpenTag() {
		String retval = "<RspnSubProjectReadList>";
		return( retval );
	}

	public static String formatSubProjectRspnListCloseTag() {
		String retval = "</RspnSubProjectReadList>";
		return( retval );
	}

	public static String formatSubProjectRspnRec( String separator, CFIntSubProjectBuff buff ) {
		String retval = "<SubProject "
			+	formatSubProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRspnDerivedRec( String separator, CFIntSubProjectBuff buff ) {
		String retval;
		retval = formatSubProjectRspnRec( separator, buff );
		return( retval );
	}

	public static String formatSubProjectRspnCreated( String separator, CFIntSubProjectBuff buff ) {
		String retval = "<RspnSubProjectCreated "
			+	formatSubProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRspnLocked( String separator, CFIntSubProjectBuff buff ) {
		String retval = "<RspnSubProjectLocked "
			+	formatSubProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRspnUpdated( String separator, CFIntSubProjectBuff buff ) {
		String retval = "<RspnSubProjectUpdated "
			+	formatSubProjectBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatSubProjectRspnDeleted() {
		String retval = "<RspnSubProjectDeleted />";
		return( retval );
	}
}
