
// Description: Java 11 XML Message message formatter for CFInt.URLProtocol

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
 *	CFIntXMsgURLProtocolMessageFormatter XML message formatter
 *	for CFInt.URLProtocol.
 */
public class CFIntXMsgURLProtocolMessageFormatter
{
	public CFIntXMsgURLProtocolMessageFormatter() {
	}

	public static String formatURLProtocolPKeyAttributes( String separator, CFIntURLProtocolPKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt32( null,
				"URLProtocolId",
				pkey.getRequiredURLProtocolId() );
		return( retval );
	}

	public static String formatURLProtocolPKeyAttributes( String separator, CFIntURLProtocolBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt32( separator,
					"URLProtocolId",
					buff.getRequiredURLProtocolId() );
		return( retval );
	}

	public static String formatURLProtocolBuffAttributes( String separator, CFIntURLProtocolBuff buff ) {
		String retval = CFIntXMsgURLProtocolMessageFormatter.formatURLProtocolPKeyAttributes( separator, buff )
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
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Description",
					buff.getRequiredDescription() )
			+	CFLibXmlUtil.formatRequiredBoolean( separator,
					"IsSecure",
					buff.getRequiredIsSecure() );
		return( retval );
	}

	public static String formatURLProtocolRqstCreate( String separator, CFIntURLProtocolBuff buff ) {
		String retval = "<RqstURLProtocolCreate "
			+	formatURLProtocolBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstRead( String separator, CFIntURLProtocolPKey pkey ) {
		String retval = "<RqstURLProtocolRead "
			+	formatURLProtocolPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstRead( String separator, CFIntURLProtocolBuff buff ) {
		String retval = "<RqstURLProtocolRead "
			+	formatURLProtocolPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstRead( String separator,
		int argURLProtocolId )
	{
		String retval = "<RqstURLProtocolRead "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"URLProtocolId",
					argURLProtocolId )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstReadAll( String separator ) {
		String retval = "<RqstURLProtocolReadAll />";
		return( retval );
	}

	public static String formatURLProtocolRqstRdByIdIdx( String separator,
		int argURLProtocolId )
	{
		String retval = "<RqstURLProtocolRead "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"URLProtocolId",
					argURLProtocolId )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstRdByUNameIdx( String separator,
		String argName )
	{
		String retval = "<RqstURLProtocolRdByUNameIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstRdByIsSecureIdx( String separator,
		boolean argIsSecure )
	{
		String retval = "<RqstURLProtocolRdByIsSecureIdx "
			+	CFLibXmlUtil.formatRequiredBoolean( null,
					"IsSecure",
					argIsSecure )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstLock( String separator, CFIntURLProtocolPKey pkey ) {
		String retval = "<RqstURLProtocolLock "
			+	formatURLProtocolPKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstLock( String separator, CFIntURLProtocolBuff buff ) {
		String retval = "<RqstURLProtocolLock "
			+	formatURLProtocolPKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstLock( String separator,
		int argURLProtocolId )
	{
		String retval = "<RqstURLProtocolLock "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"URLProtocolId",
					argURLProtocolId )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstUpdate( String separator, CFIntURLProtocolBuff buff ) {
		String retval = "<RqstURLProtocolUpdate "
			+	formatURLProtocolBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstDelete( String separator, CFIntURLProtocolBuff buff ) {
		String retval = "<RqstURLProtocolDelete "
				+	formatURLProtocolPKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstDelByIdIdx( String separator,
		int argURLProtocolId )
	{
		String retval = "<RqstURLProtocolDelete "
			+	CFLibXmlUtil.formatRequiredInt32( null,
					"URLProtocolId",
					argURLProtocolId )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstDelByUNameIdx( String separator,
		String argName )
	{
		String retval = "<RqstURLProtocolDelByUNameIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Name",
					argName )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRqstDelByIsSecureIdx( String separator,
		boolean argIsSecure )
	{
		String retval = "<RqstURLProtocolDelByIsSecureIdx "
			+	CFLibXmlUtil.formatRequiredBoolean( null,
					"IsSecure",
					argIsSecure )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRspnSingleOpenTag() {
		String retval = "<RspnURLProtocolReadSingle>";
		return( retval );
	}

	public static String formatURLProtocolRspnSingleCloseTag() {
		String retval = "</RspnURLProtocolReadSingle>";
		return( retval );
	}

	public static String formatURLProtocolRspnListOpenTag() {
		String retval = "<RspnURLProtocolReadList>";
		return( retval );
	}

	public static String formatURLProtocolRspnListCloseTag() {
		String retval = "</RspnURLProtocolReadList>";
		return( retval );
	}

	public static String formatURLProtocolRspnRec( String separator, CFIntURLProtocolBuff buff ) {
		String retval = "<URLProtocol "
			+	formatURLProtocolBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRspnDerivedRec( String separator, CFIntURLProtocolBuff buff ) {
		String retval;
		retval = formatURLProtocolRspnRec( separator, buff );
		return( retval );
	}

	public static String formatURLProtocolRspnCreated( String separator, CFIntURLProtocolBuff buff ) {
		String retval = "<RspnURLProtocolCreated "
			+	formatURLProtocolBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRspnLocked( String separator, CFIntURLProtocolBuff buff ) {
		String retval = "<RspnURLProtocolLocked "
			+	formatURLProtocolBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRspnUpdated( String separator, CFIntURLProtocolBuff buff ) {
		String retval = "<RspnURLProtocolUpdated "
			+	formatURLProtocolBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatURLProtocolRspnDeleted() {
		String retval = "<RspnURLProtocolDeleted />";
		return( retval );
	}
}
