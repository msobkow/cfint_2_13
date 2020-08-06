
// Description: Java 11 XML Message message formatter for CFInt.ISOTZone

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
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
 *	CFIntXMsgISOTZoneMessageFormatter XML message formatter
 *	for CFInt.ISOTZone.
 */
public class CFIntXMsgISOTZoneMessageFormatter
{
	public CFIntXMsgISOTZoneMessageFormatter() {
	}

	public static String formatISOTZonePKeyAttributes( String separator, CFSecISOTZonePKey pkey ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( null,
				"ISOTZoneId",
				pkey.getRequiredISOTZoneId() );
		return( retval );
	}

	public static String formatISOTZonePKeyAttributes( String separator, CFSecISOTZoneBuff buff ) {
		String retval = CFLibXmlUtil.formatRequiredInt16( separator,
					"ISOTZoneId",
					buff.getRequiredISOTZoneId() );
		return( retval );
	}

	public static String formatISOTZoneBuffAttributes( String separator, CFSecISOTZoneBuff buff ) {
		String retval = CFIntXMsgISOTZoneMessageFormatter.formatISOTZonePKeyAttributes( separator, buff )
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
					"Iso8601",
					buff.getRequiredIso8601() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"TZName",
					buff.getRequiredTZName() )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"TZHourOffset",
					buff.getRequiredTZHourOffset() )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"TZMinOffset",
					buff.getRequiredTZMinOffset() )
			+	CFLibXmlUtil.formatRequiredXmlString( separator,
					"Description",
					buff.getRequiredDescription() )
			+	CFLibXmlUtil.formatRequiredBoolean( separator,
					"Visible",
					buff.getRequiredVisible() );
		return( retval );
	}

	public static String formatISOTZoneRqstCreate( String separator, CFSecISOTZoneBuff buff ) {
		String retval = "<RqstISOTZoneCreate "
			+	formatISOTZoneBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstRead( String separator, CFSecISOTZonePKey pkey ) {
		String retval = "<RqstISOTZoneRead "
			+	formatISOTZonePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstRead( String separator, CFSecISOTZoneBuff buff ) {
		String retval = "<RqstISOTZoneRead "
			+	formatISOTZonePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstRead( String separator,
		short argISOTZoneId )
	{
		String retval = "<RqstISOTZoneRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOTZoneId",
					argISOTZoneId )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstReadAll( String separator ) {
		String retval = "<RqstISOTZoneReadAll />";
		return( retval );
	}

	public static String formatISOTZoneRqstRdByIdIdx( String separator,
		short argISOTZoneId )
	{
		String retval = "<RqstISOTZoneRead "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOTZoneId",
					argISOTZoneId )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstRdByOffsetIdx( String separator,
		short argTZHourOffset,
		short argTZMinOffset )
	{
		String retval = "<RqstISOTZoneRdByOffsetIdx "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"TZHourOffset",
					argTZHourOffset )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"TZMinOffset",
					argTZMinOffset )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstRdByUTZNameIdx( String separator,
		String argTZName )
	{
		String retval = "<RqstISOTZoneRdByUTZNameIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"TZName",
					argTZName )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstRdByIso8601Idx( String separator,
		String argIso8601 )
	{
		String retval = "<RqstISOTZoneRdByIso8601Idx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Iso8601",
					argIso8601 )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstLock( String separator, CFSecISOTZonePKey pkey ) {
		String retval = "<RqstISOTZoneLock "
			+	formatISOTZonePKeyAttributes( separator, pkey )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstLock( String separator, CFSecISOTZoneBuff buff ) {
		String retval = "<RqstISOTZoneLock "
			+	formatISOTZonePKeyAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstLock( String separator,
		short argISOTZoneId )
	{
		String retval = "<RqstISOTZoneLock "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOTZoneId",
					argISOTZoneId )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstUpdate( String separator, CFSecISOTZoneBuff buff ) {
		String retval = "<RqstISOTZoneUpdate "
			+	formatISOTZoneBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstDelete( String separator, CFSecISOTZoneBuff buff ) {
		String retval = "<RqstISOTZoneDelete "
				+	formatISOTZonePKeyAttributes( separator, buff )
				+	CFLibXmlUtil.formatRequiredInt32( separator,
						"Revision",
						buff.getRequiredRevision() )
				+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstDelByIdIdx( String separator,
		short argISOTZoneId )
	{
		String retval = "<RqstISOTZoneDelete "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"ISOTZoneId",
					argISOTZoneId )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstDelByOffsetIdx( String separator,
		short argTZHourOffset,
		short argTZMinOffset )
	{
		String retval = "<RqstISOTZoneDelByOffsetIdx "
			+	CFLibXmlUtil.formatRequiredInt16( null,
					"TZHourOffset",
					argTZHourOffset )
			+	CFLibXmlUtil.formatRequiredInt16( separator,
					"TZMinOffset",
					argTZMinOffset )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstDelByUTZNameIdx( String separator,
		String argTZName )
	{
		String retval = "<RqstISOTZoneDelByUTZNameIdx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"TZName",
					argTZName )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRqstDelByIso8601Idx( String separator,
		String argIso8601 )
	{
		String retval = "<RqstISOTZoneDelByIso8601Idx "
			+	CFLibXmlUtil.formatRequiredXmlString( null,
					"Iso8601",
					argIso8601 )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRspnSingleOpenTag() {
		String retval = "<RspnISOTZoneReadSingle>";
		return( retval );
	}

	public static String formatISOTZoneRspnSingleCloseTag() {
		String retval = "</RspnISOTZoneReadSingle>";
		return( retval );
	}

	public static String formatISOTZoneRspnListOpenTag() {
		String retval = "<RspnISOTZoneReadList>";
		return( retval );
	}

	public static String formatISOTZoneRspnListCloseTag() {
		String retval = "</RspnISOTZoneReadList>";
		return( retval );
	}

	public static String formatISOTZoneRspnRec( String separator, CFSecISOTZoneBuff buff ) {
		String retval = "<ISOTZone "
			+	formatISOTZoneBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRspnDerivedRec( String separator, CFSecISOTZoneBuff buff ) {
		String retval;
		retval = formatISOTZoneRspnRec( separator, buff );
		return( retval );
	}

	public static String formatISOTZoneRspnCreated( String separator, CFSecISOTZoneBuff buff ) {
		String retval = "<RspnISOTZoneCreated "
			+	formatISOTZoneBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRspnLocked( String separator, CFSecISOTZoneBuff buff ) {
		String retval = "<RspnISOTZoneLocked "
			+	formatISOTZoneBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRspnUpdated( String separator, CFSecISOTZoneBuff buff ) {
		String retval = "<RspnISOTZoneUpdated "
			+	formatISOTZoneBuffAttributes( separator, buff )
			+	" />";
		return( retval );
	}

	public static String formatISOTZoneRspnDeleted() {
		String retval = "<RspnISOTZoneDeleted />";
		return( retval );
	}
}
