
// Description: Java 11 XML Message message formatter for CFInt.MimeType

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
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;

/*
 *	CFIntXMsgMimeTypeMessageFormatter XML message formatter
 *	for CFInt.MimeType.
 */
public class CFIntXMsgMimeTypeMessageFormatter
{
	public CFIntXMsgMimeTypeMessageFormatter() {
	}

	public static String formatMimeTypePKeyAttributes( String separator, CFIntMimeTypePKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt32( null,
				"MimeTypeId",
				pkey.getRequiredMimeTypeId() );
		return( retval );
	}

	public static String formatMimeTypePKeyAttributes( String separator, CFIntMimeTypeBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt32( separator,
					"MimeTypeId",
					buff.getRequiredMimeTypeId() );
		return( retval );
	}

	public static String formatMimeTypeBuffAttributes( String separator, CFIntMimeTypeBuff buff ) {
		String retval = CFIntXMsgMimeTypeMessageFormatter.formatMimeTypePKeyAttributes( separator, buff )
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
					"FileTypes",
					buff.getOptionalFileTypes() );
		return( retval );
	}

	public static String formatMimeTypeRqstCreate( String separator, CFIntMimeTypeBuff buff ) {
		String retval = "<RqstMimeTypeCreate "
			+	formatMimeTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstRead( String separator, CFIntMimeTypePKey pkey ) {
		String retval = "<RqstMimeTypeRead "
			+	formatMimeTypePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstRead( String separator, CFIntMimeTypeBuff buff ) {
		String retval = "<RqstMimeTypeRead "
			+	formatMimeTypePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstRead( String separator,
		int argMimeTypeId )
	{
		String retval = "<RqstMimeTypeRead "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"MimeTypeId",
					argMimeTypeId )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstReadAll( String separator ) {
		String retval = "<RqstMimeTypeReadAll />";
		return( retval );
	}

	public static String formatMimeTypeRqstRdByIdIdx( String separator,
		int argMimeTypeId )
	{
		String retval = "<RqstMimeTypeRead "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"MimeTypeId",
					argMimeTypeId )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstRdByUNameIdx( String separator,
		String argName )
	{
		String retval = "<RqstMimeTypeRdByUNameIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstLock( String separator, CFIntMimeTypePKey pkey ) {
		String retval = "<RqstMimeTypeLock "
			+	formatMimeTypePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstLock( String separator, CFIntMimeTypeBuff buff ) {
		String retval = "<RqstMimeTypeLock "
			+	formatMimeTypePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstLock( String separator,
		int argMimeTypeId )
	{
		String retval = "<RqstMimeTypeLock "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"MimeTypeId",
					argMimeTypeId )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstUpdate( String separator, CFIntMimeTypeBuff buff ) {
		String retval = "<RqstMimeTypeUpdate "
			+	formatMimeTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstDelete( String separator, CFIntMimeTypeBuff buff ) {
		String retval = "<RqstMimeTypeDelete "
				+	formatMimeTypePKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstDelByIdIdx( String separator,
		int argMimeTypeId )
	{
		String retval = "<RqstMimeTypeDelete "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"MimeTypeId",
					argMimeTypeId )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRqstDelByUNameIdx( String separator,
		String argName )
	{
		String retval = "<RqstMimeTypeDelByUNameIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRspnSingleOpenTag() {
		String retval = "<RspnMimeTypeReadSingle>";
		return( retval );
	}

	public static String formatMimeTypeRspnSingleCloseTag() {
		String retval = "</RspnMimeTypeReadSingle>";
		return( retval );
	}

	public static String formatMimeTypeRspnListOpenTag() {
		String retval = "<RspnMimeTypeReadList>";
		return( retval );
	}

	public static String formatMimeTypeRspnListCloseTag() {
		String retval = "</RspnMimeTypeReadList>";
		return( retval );
	}

	public static String formatMimeTypeRspnRec( String separator, CFIntMimeTypeBuff buff ) {
		String retval = "<MimeType "
			+	formatMimeTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRspnDerivedRec( String separator, CFIntMimeTypeBuff buff ) {
		String retval;
		retval = formatMimeTypeRspnRec( separator, buff );
		return( retval );
	}

	public static String formatMimeTypeRspnCreated( String separator, CFIntMimeTypeBuff buff ) {
		String retval = "<RspnMimeTypeCreated "
			+	formatMimeTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRspnLocked( String separator, CFIntMimeTypeBuff buff ) {
		String retval = "<RspnMimeTypeLocked "
			+	formatMimeTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRspnUpdated( String separator, CFIntMimeTypeBuff buff ) {
		String retval = "<RspnMimeTypeUpdated "
			+	formatMimeTypeBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatMimeTypeRspnDeleted() {
		String retval = "<RspnMimeTypeDeleted />";
		return( retval );
	}
}
