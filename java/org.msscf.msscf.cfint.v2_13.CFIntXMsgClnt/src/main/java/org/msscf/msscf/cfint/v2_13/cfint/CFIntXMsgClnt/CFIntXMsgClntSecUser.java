// Description: Java 11 XMsg Client DbIO implementation for SecUser.

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

package org.msscf.msscf.cfint.v2_13.cfint.CFIntXMsgClnt;

import java.lang.reflect.*;
import java.math.*;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.sql.*;
import java.text.*;
import java.util.*;
import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.naming.*;
import javax.sql.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cflib.v2_13.CFLib.Tip.*;
import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;
import org.msscf.msscf.cfint.v2_13.cfint.CFIntXMsg.*;
import org.msscf.msscf.cfint.v2_13.cfint.CFIntXMsgRspn.*;

/*
 *	CFIntXMsgClntSecUser XMsg Client DbIO implementation
 *	for SecUser.
 */
public class CFIntXMsgClntSecUser
	implements ICFIntSecUserTable
{
	private CFIntXMsgClntSchema schema;

	public CFIntXMsgClntSecUser( CFIntXMsgClntSchema argSchema ) {
		schema = argSchema;
	}

	public void createSecUser( CFSecAuthorization Authorization,
		CFSecSecUserBuff Buff )
	{
		final String S_ProcName = "createSecUser";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstCreate( "\n\t\t\t", Buff )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntSecUserObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecUserObj ) {
				realised = (ICFIntSecUserObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecUserObj" );
			}
			if( realised != null ) {
				Buff.set( realised.getSecUserBuff() );
			}
		}
		else {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				0,
				"responseHandler.getLastObjectProcessed()" );
		}
	}

	public CFSecSecUserBuff readDerived( CFSecAuthorization Authorization,
		CFSecSecUserPKey PKey )
	{
		final String S_ProcName = "readDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstRead( "\n\t\t\t", PKey )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		CFSecSecUserBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntSecUserObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecUserObj ) {
				realised = (ICFIntSecUserObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecUserObj" );
			}
			if( realised != null ) {
				buff = realised.getSecUserBuff();
			}
		}
		return( buff );
	}

	public CFSecSecUserBuff lockDerived( CFSecAuthorization Authorization,
		CFSecSecUserPKey PKey )
	{
		final String S_ProcName = "lockDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstLock( "\n\t\t\t", PKey )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		CFSecSecUserBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntSecUserObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecUserObj ) {
				realised = (ICFIntSecUserObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecUserObj" );
			}
			if( realised != null ) {
				buff = realised.getSecUserBuff();
			}
		}
		return( buff );
	}

	public CFSecSecUserBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstReadAll( "\n\t\t\t" )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecSecUserObj> sortedList =
			(List<ICFSecSecUserObj>)sortedListObj;
		CFSecSecUserBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecUserBuff[ sz ];
			Iterator<ICFSecSecUserObj> iter = sortedList.iterator();
			ICFSecSecUserObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecUserObj)iter.next();
				arr[idx] = cur.getSecUserBuff();
			}
		}
		else {
			arr = new CFSecSecUserBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecSecUserBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		UUID argSecUserId )
	{
		final String S_ProcName = "readDerivedByIdIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstRdByIdIdx( "\n\t\t\t",
							argSecUserId )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		CFSecSecUserBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntSecUserObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecUserObj ) {
				realised = (ICFIntSecUserObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecUserObj" );
			}
			if( realised != null ) {
				buff = realised.getSecUserBuff();
			}
		}
		return( buff );
	}

	public CFSecSecUserBuff readDerivedByULoginIdx( CFSecAuthorization Authorization,
		String argLoginId )
	{
		final String S_ProcName = "readDerivedByULoginIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstRdByULoginIdx( "\n\t\t\t",
							argLoginId )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		CFSecSecUserBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntSecUserObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecUserObj ) {
				realised = (ICFIntSecUserObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecUserObj" );
			}
			if( realised != null ) {
				buff = realised.getSecUserBuff();
			}
		}
		return( buff );
	}

	public CFSecSecUserBuff[] readDerivedByEMConfIdx( CFSecAuthorization Authorization,
		UUID argEMailConfirmUuid )
	{
		final String S_ProcName = "readDerivedByEMConfIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstRdByEMConfIdx( "\n\t\t\t",
							argEMailConfirmUuid )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecSecUserObj> sortedList =
			(List<ICFSecSecUserObj>)sortedListObj;
		CFSecSecUserBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecUserBuff[ sz ];
			Iterator<ICFSecSecUserObj> iter = sortedList.iterator();
			ICFSecSecUserObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecUserObj)iter.next();
				arr[idx] = cur.getSecUserBuff();
			}
		}
		else {
			arr = new CFSecSecUserBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecSecUserBuff[] readDerivedByPwdResetIdx( CFSecAuthorization Authorization,
		UUID argPasswordResetUuid )
	{
		final String S_ProcName = "readDerivedByPwdResetIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstRdByPwdResetIdx( "\n\t\t\t",
							argPasswordResetUuid )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecSecUserObj> sortedList =
			(List<ICFSecSecUserObj>)sortedListObj;
		CFSecSecUserBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecUserBuff[ sz ];
			Iterator<ICFSecSecUserObj> iter = sortedList.iterator();
			ICFSecSecUserObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecUserObj)iter.next();
				arr[idx] = cur.getSecUserBuff();
			}
		}
		else {
			arr = new CFSecSecUserBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecSecUserBuff[] readDerivedByDefDevIdx( CFSecAuthorization Authorization,
		UUID argDfltDevUserId,
		String argDfltDevName )
	{
		final String S_ProcName = "readDerivedByDefDevIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstRdByDefDevIdx( "\n\t\t\t",
							argDfltDevUserId,
							argDfltDevName )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecSecUserObj> sortedList =
			(List<ICFSecSecUserObj>)sortedListObj;
		CFSecSecUserBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecUserBuff[ sz ];
			Iterator<ICFSecSecUserObj> iter = sortedList.iterator();
			ICFSecSecUserObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecUserObj)iter.next();
				arr[idx] = cur.getSecUserBuff();
			}
		}
		else {
			arr = new CFSecSecUserBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecSecUserBuff readBuff( CFSecAuthorization Authorization,
		CFSecSecUserPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuff" );
	}

	public CFSecSecUserBuff lockBuff( CFSecAuthorization Authorization,
		CFSecSecUserPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"lockBuff" );
	}

	public CFSecSecUserBuff[] readAllBuff( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllBuff";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstReadAll( "\n\t\t\t" )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecSecUserObj> sortedList =
			(List<ICFSecSecUserObj>)sortedListObj;
		CFSecSecUserBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecUserBuff[ sz ];
			Iterator<ICFSecSecUserObj> iter = sortedList.iterator();
			ICFSecSecUserObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecUserObj)iter.next();
				arr[idx] = cur.getSecUserBuff();
			}
		}
		else {
			arr = new CFSecSecUserBuff[ 0 ];
		}
		return( arr );
	}

	/**
	 *	Read a page of all the specific SecUser buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific SecUser instances in the database accessible for the Authorization.
	 */
	public CFSecSecUserBuff[] pageAllBuff( CFSecAuthorization Authorization,
		UUID priorSecUserId )
	{
		final String S_ProcName = "pageAllBuff";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstPageAll( "\n\t\t\t",
							priorSecUserId )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecSecUserObj> sortedList =
			(List<ICFSecSecUserObj>)sortedListObj;
		CFSecSecUserBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecUserBuff[ sz ];
			Iterator<ICFSecSecUserObj> iter = sortedList.iterator();
			ICFSecSecUserObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecUserObj)iter.next();
				arr[idx] = cur.getSecUserBuff();
			}
		}
		else {
			arr = new CFSecSecUserBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecSecUserBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		UUID argSecUserId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByIdIdx" );
	}

	public CFSecSecUserBuff readBuffByULoginIdx( CFSecAuthorization Authorization,
		String argLoginId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByULoginIdx" );
	}

	public CFSecSecUserBuff[] readBuffByEMConfIdx( CFSecAuthorization Authorization,
		UUID argEMailConfirmUuid )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByEMConfIdx" );
	}

	public CFSecSecUserBuff[] readBuffByPwdResetIdx( CFSecAuthorization Authorization,
		UUID argPasswordResetUuid )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByPwdResetIdx" );
	}

	public CFSecSecUserBuff[] readBuffByDefDevIdx( CFSecAuthorization Authorization,
		UUID argDfltDevUserId,
		String argDfltDevName )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByDefDevIdx" );
	}

	/**
	 *	Read a page array of the specific SecUser buffer instances identified by the duplicate key EMConfIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argEMailConfirmUuid	The SecUser key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	public CFSecSecUserBuff[] pageBuffByEMConfIdx( CFSecAuthorization Authorization,
		UUID EMailConfirmUuid,
		UUID priorSecUserId )
	{
		final String S_ProcName = "pageBuffByEMConfIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstPageByEMConfIdx( "\n\t\t\t",
						EMailConfirmUuid,
							priorSecUserId )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecSecUserObj> sortedList =
			(List<ICFSecSecUserObj>)sortedListObj;
		CFSecSecUserBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecUserBuff[ sz ];
			Iterator<ICFSecSecUserObj> iter = sortedList.iterator();
			ICFSecSecUserObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecUserObj)iter.next();
				arr[idx] = cur.getSecUserBuff();
			}
		}
		else {
			arr = new CFSecSecUserBuff[ 0 ];
		}
		return( arr );
	}

	/**
	 *	Read a page array of the specific SecUser buffer instances identified by the duplicate key PwdResetIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argPasswordResetUuid	The SecUser key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	public CFSecSecUserBuff[] pageBuffByPwdResetIdx( CFSecAuthorization Authorization,
		UUID PasswordResetUuid,
		UUID priorSecUserId )
	{
		final String S_ProcName = "pageBuffByPwdResetIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstPageByPwdResetIdx( "\n\t\t\t",
						PasswordResetUuid,
							priorSecUserId )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecSecUserObj> sortedList =
			(List<ICFSecSecUserObj>)sortedListObj;
		CFSecSecUserBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecUserBuff[ sz ];
			Iterator<ICFSecSecUserObj> iter = sortedList.iterator();
			ICFSecSecUserObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecUserObj)iter.next();
				arr[idx] = cur.getSecUserBuff();
			}
		}
		else {
			arr = new CFSecSecUserBuff[ 0 ];
		}
		return( arr );
	}

	/**
	 *	Read a page array of the specific SecUser buffer instances identified by the duplicate key DefDevIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argDfltDevUserId	The SecUser key attribute of the instance generating the id.
	 *
	 *	@param	argDfltDevName	The SecUser key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	public CFSecSecUserBuff[] pageBuffByDefDevIdx( CFSecAuthorization Authorization,
		UUID DfltDevUserId,
		String DfltDevName,
		UUID priorSecUserId )
	{
		final String S_ProcName = "pageBuffByDefDevIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstPageByDefDevIdx( "\n\t\t\t",
						DfltDevUserId,
						DfltDevName,
							priorSecUserId )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		Object sortedListObj = responseHandler.getListOfObjects();
		@SuppressWarnings("unchecked")
		List<ICFSecSecUserObj> sortedList =
			(List<ICFSecSecUserObj>)sortedListObj;
		CFSecSecUserBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecUserBuff[ sz ];
			Iterator<ICFSecSecUserObj> iter = sortedList.iterator();
			ICFSecSecUserObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecUserObj)iter.next();
				arr[idx] = cur.getSecUserBuff();
			}
		}
		else {
			arr = new CFSecSecUserBuff[ 0 ];
		}
		return( arr );
	}

	public void updateSecUser( CFSecAuthorization Authorization,
		CFSecSecUserBuff Buff )
	{
		final String S_ProcName = "updateSecUser";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstUpdate( "\n\t\t\t", Buff )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		CFSecSecUserBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntSecUserObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecUserObj ) {
				realised = (ICFIntSecUserObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecUserObj" );
			}
			if( realised != null ) {
				buff = realised.getSecUserBuff();
			}
		}
		if( buff != null ) {
			Buff.set( buff );
		}
	}

	public void deleteSecUser( CFSecAuthorization Authorization,
		CFSecSecUserBuff Buff )
	{
		final String S_ProcName = "deleteSecUser";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstDelete( "\n\t\t\t", Buff )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		boolean deleted = responseHandler.getDeleted();
		if( ! deleted ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Server did not respond with a Deleted message" );
		}
	}

	public void deleteSecUserByIdIdx( CFSecAuthorization Authorization,
		UUID argSecUserId )
	{
		final String S_ProcName = "deleteSecUserByIdIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstDelByIdIdx( "\n\t\t\t",
							argSecUserId )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		boolean deleted = responseHandler.getDeleted();
		if( ! deleted ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Server did not respond with a Deleted message" );
		}
	}

	public void deleteSecUserByIdIdx( CFSecAuthorization Authorization,
		CFSecSecUserPKey argKey )
	{
		deleteSecUserByIdIdx( Authorization,
			argKey.getRequiredSecUserId() );
	}
	public void deleteSecUserByULoginIdx( CFSecAuthorization Authorization,
		String argLoginId )
	{
		final String S_ProcName = "deleteSecUserByULoginIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstDelByULoginIdx( "\n\t\t\t",
							argLoginId )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		boolean deleted = responseHandler.getDeleted();
		if( ! deleted ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Server did not respond with a Deleted message" );
		}
	}

	public void deleteSecUserByULoginIdx( CFSecAuthorization Authorization,
		CFSecSecUserByULoginIdxKey argKey )
	{
		deleteSecUserByULoginIdx( Authorization,
			argKey.getRequiredLoginId() );
	}
	public void deleteSecUserByEMConfIdx( CFSecAuthorization Authorization,
		UUID argEMailConfirmUuid )
	{
		final String S_ProcName = "deleteSecUserByEMConfIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstDelByEMConfIdx( "\n\t\t\t",
							argEMailConfirmUuid )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		boolean deleted = responseHandler.getDeleted();
		if( ! deleted ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Server did not respond with a Deleted message" );
		}
	}

	public void deleteSecUserByEMConfIdx( CFSecAuthorization Authorization,
		CFSecSecUserByEMConfIdxKey argKey )
	{
		deleteSecUserByEMConfIdx( Authorization,
			argKey.getOptionalEMailConfirmUuid() );
	}
	public void deleteSecUserByPwdResetIdx( CFSecAuthorization Authorization,
		UUID argPasswordResetUuid )
	{
		final String S_ProcName = "deleteSecUserByPwdResetIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstDelByPwdResetIdx( "\n\t\t\t",
							argPasswordResetUuid )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		boolean deleted = responseHandler.getDeleted();
		if( ! deleted ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Server did not respond with a Deleted message" );
		}
	}

	public void deleteSecUserByPwdResetIdx( CFSecAuthorization Authorization,
		CFSecSecUserByPwdResetIdxKey argKey )
	{
		deleteSecUserByPwdResetIdx( Authorization,
			argKey.getOptionalPasswordResetUuid() );
	}
	public void deleteSecUserByDefDevIdx( CFSecAuthorization Authorization,
		UUID argDfltDevUserId,
		String argDfltDevName )
	{
		final String S_ProcName = "deleteSecUserByDefDevIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecUserMessageFormatter.formatSecUserRqstDelByDefDevIdx( "\n\t\t\t",
							argDfltDevUserId,
							argDfltDevName )
			+	"\n"
			+	CFIntXMsgSchemaMessageFormatter.formatRqstXmlPostamble();
		try {
			schema.getCFTipClientHandler().issueAppRequest( rqst );
		}
		catch( BadPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught BadPaddingException - " + e.getMessage(),
				e );
		}
		catch( IllegalBlockSizeException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught IllegalBlockSizeException - " + e.getMessage(),
				e );
		}
		catch( InvalidKeyException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidKeyException - " + e.getMessage(),
				e );
		}
		catch( NoSuchAlgorithmException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchAlgorithmException - " + e.getMessage(),
				e );
		}
		catch( InvalidAlgorithmParameterException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught InvalidAlgorithmParameterException - " + e.getMessage(),
				e );
		}
		catch( NoSuchPaddingException e ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Caught NoSuchPaddingException - " + e.getMessage(),
				e );
		}
		ICFTipResponseHandler responseHandler = schema.getCFTipClientHandler().getResponseHandler();
		RuntimeException exceptionRaised = responseHandler.getExceptionRaised();
		if( exceptionRaised != null ) {
			throw exceptionRaised;
		}
		boolean deleted = responseHandler.getDeleted();
		if( ! deleted ) {
			throw new CFLibRuntimeException( getClass(),
				S_ProcName,
				"Server did not respond with a Deleted message" );
		}
	}

	public void deleteSecUserByDefDevIdx( CFSecAuthorization Authorization,
		CFSecSecUserByDefDevIdxKey argKey )
	{
		deleteSecUserByDefDevIdx( Authorization,
			argKey.getOptionalDfltDevUserId(),
			argKey.getOptionalDfltDevName() );
	}
	/**
	 *	Release the prepared statements.
	 *	<p>
	 *	When the schema changes connections, the prepared statements
	 *	have to be released because they contain connection-specific
	 *	information for most databases.
	 */
	public void releasePreparedStatements() {
		throw new CFLibNotSupportedException( getClass(),
			"releasePreparedStatements" );
	}
}
