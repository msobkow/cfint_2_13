// Description: Java 11 XMsg Client DbIO implementation for SecApp.

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

package com.github.msobkow.cfint.CFIntXMsgClnt;

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
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.Tip.*;
import org.apache.commons.codec.binary.Base64;

import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfint.CFInt.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFIntObj.*;
import com.github.msobkow.cfint.CFIntXMsg.*;
import com.github.msobkow.cfint.CFIntXMsgRspn.*;

/*
 *	CFIntXMsgClntSecApp XMsg Client DbIO implementation
 *	for SecApp.
 */
public class CFIntXMsgClntSecApp
	implements ICFIntSecAppTable
{
	private CFIntXMsgClntSchema schema;

	public CFIntXMsgClntSecApp( CFIntXMsgClntSchema argSchema ) {
		schema = argSchema;
	}

	public void createSecApp( CFSecAuthorization Authorization,
		CFSecSecAppBuff Buff )
	{
		final String S_ProcName = "createSecApp";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstCreate( "\n\t\t\t", Buff )
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
			ICFIntSecAppObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecAppObj ) {
				realised = (ICFIntSecAppObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecAppObj" );
			}
			if( realised != null ) {
				Buff.set( realised.getSecAppBuff() );
			}
		}
		else {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				0,
				"responseHandler.getLastObjectProcessed()" );
		}
	}

	public CFSecSecAppBuff readDerived( CFSecAuthorization Authorization,
		CFSecSecAppPKey PKey )
	{
		final String S_ProcName = "readDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstRead( "\n\t\t\t", PKey )
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
		CFSecSecAppBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntSecAppObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecAppObj ) {
				realised = (ICFIntSecAppObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecAppObj" );
			}
			if( realised != null ) {
				buff = realised.getSecAppBuff();
			}
		}
		return( buff );
	}

	public CFSecSecAppBuff lockDerived( CFSecAuthorization Authorization,
		CFSecSecAppPKey PKey )
	{
		final String S_ProcName = "lockDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstLock( "\n\t\t\t", PKey )
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
		CFSecSecAppBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntSecAppObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecAppObj ) {
				realised = (ICFIntSecAppObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecAppObj" );
			}
			if( realised != null ) {
				buff = realised.getSecAppBuff();
			}
		}
		return( buff );
	}

	public CFSecSecAppBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstReadAll( "\n\t\t\t" )
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
		List<ICFSecSecAppObj> sortedList =
			(List<ICFSecSecAppObj>)sortedListObj;
		CFSecSecAppBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecAppBuff[ sz ];
			Iterator<ICFSecSecAppObj> iter = sortedList.iterator();
			ICFSecSecAppObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecAppObj)iter.next();
				arr[idx] = cur.getSecAppBuff();
			}
		}
		else {
			arr = new CFSecSecAppBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecSecAppBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		long argClusterId,
		int argSecAppId )
	{
		final String S_ProcName = "readDerivedByIdIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstRdByIdIdx( "\n\t\t\t",
							argClusterId,
							argSecAppId )
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
		CFSecSecAppBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntSecAppObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecAppObj ) {
				realised = (ICFIntSecAppObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecAppObj" );
			}
			if( realised != null ) {
				buff = realised.getSecAppBuff();
			}
		}
		return( buff );
	}

	public CFSecSecAppBuff[] readDerivedByClusterIdx( CFSecAuthorization Authorization,
		long argClusterId )
	{
		final String S_ProcName = "readDerivedByClusterIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstRdByClusterIdx( "\n\t\t\t",
							argClusterId )
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
		List<ICFSecSecAppObj> sortedList =
			(List<ICFSecSecAppObj>)sortedListObj;
		CFSecSecAppBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecAppBuff[ sz ];
			Iterator<ICFSecSecAppObj> iter = sortedList.iterator();
			ICFSecSecAppObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecAppObj)iter.next();
				arr[idx] = cur.getSecAppBuff();
			}
		}
		else {
			arr = new CFSecSecAppBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecSecAppBuff readDerivedByUJEEMountIdx( CFSecAuthorization Authorization,
		long argClusterId,
		String argJEEMountName )
	{
		final String S_ProcName = "readDerivedByUJEEMountIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstRdByUJEEMountIdx( "\n\t\t\t",
							argClusterId,
							argJEEMountName )
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
		CFSecSecAppBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntSecAppObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecAppObj ) {
				realised = (ICFIntSecAppObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecAppObj" );
			}
			if( realised != null ) {
				buff = realised.getSecAppBuff();
			}
		}
		return( buff );
	}

	public CFSecSecAppBuff readBuff( CFSecAuthorization Authorization,
		CFSecSecAppPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuff" );
	}

	public CFSecSecAppBuff lockBuff( CFSecAuthorization Authorization,
		CFSecSecAppPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"lockBuff" );
	}

	public CFSecSecAppBuff[] readAllBuff( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllBuff";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstReadAll( "\n\t\t\t" )
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
		List<ICFSecSecAppObj> sortedList =
			(List<ICFSecSecAppObj>)sortedListObj;
		CFSecSecAppBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecAppBuff[ sz ];
			Iterator<ICFSecSecAppObj> iter = sortedList.iterator();
			ICFSecSecAppObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecAppObj)iter.next();
				arr[idx] = cur.getSecAppBuff();
			}
		}
		else {
			arr = new CFSecSecAppBuff[ 0 ];
		}
		return( arr );
	}

	/**
	 *	Read a page of all the specific SecApp buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific SecApp instances in the database accessible for the Authorization.
	 */
	public CFSecSecAppBuff[] pageAllBuff( CFSecAuthorization Authorization,
		Long priorClusterId,
		Integer priorSecAppId )
	{
		final String S_ProcName = "pageAllBuff";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstPageAll( "\n\t\t\t",
							priorClusterId,
							priorSecAppId )
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
		List<ICFSecSecAppObj> sortedList =
			(List<ICFSecSecAppObj>)sortedListObj;
		CFSecSecAppBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecAppBuff[ sz ];
			Iterator<ICFSecSecAppObj> iter = sortedList.iterator();
			ICFSecSecAppObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecAppObj)iter.next();
				arr[idx] = cur.getSecAppBuff();
			}
		}
		else {
			arr = new CFSecSecAppBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecSecAppBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		long argClusterId,
		int argSecAppId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByIdIdx" );
	}

	public CFSecSecAppBuff[] readBuffByClusterIdx( CFSecAuthorization Authorization,
		long argClusterId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByClusterIdx" );
	}

	public CFSecSecAppBuff readBuffByUJEEMountIdx( CFSecAuthorization Authorization,
		long argClusterId,
		String argJEEMountName )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByUJEEMountIdx" );
	}

	/**
	 *	Read a page array of the specific SecApp buffer instances identified by the duplicate key ClusterIdx.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@param	argClusterId	The SecApp key attribute of the instance generating the id.
	 *
	 *	@return An array of derived buffer instances for the specified key, potentially with 0 elements in the set.
	 *
	 *	@throws	CFLibNotSupportedException thrown by client-side implementations.
	 */
	public CFSecSecAppBuff[] pageBuffByClusterIdx( CFSecAuthorization Authorization,
		long ClusterId,
		Long priorClusterId,
		Integer priorSecAppId )
	{
		final String S_ProcName = "pageBuffByClusterIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstPageByClusterIdx( "\n\t\t\t",
						ClusterId,
							priorClusterId,
							priorSecAppId )
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
		List<ICFSecSecAppObj> sortedList =
			(List<ICFSecSecAppObj>)sortedListObj;
		CFSecSecAppBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecSecAppBuff[ sz ];
			Iterator<ICFSecSecAppObj> iter = sortedList.iterator();
			ICFSecSecAppObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecSecAppObj)iter.next();
				arr[idx] = cur.getSecAppBuff();
			}
		}
		else {
			arr = new CFSecSecAppBuff[ 0 ];
		}
		return( arr );
	}

	public void updateSecApp( CFSecAuthorization Authorization,
		CFSecSecAppBuff Buff )
	{
		final String S_ProcName = "updateSecApp";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstUpdate( "\n\t\t\t", Buff )
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
		CFSecSecAppBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntSecAppObj realised = null;
			if( lastObjectProcessed instanceof ICFIntSecAppObj ) {
				realised = (ICFIntSecAppObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntSecAppObj" );
			}
			if( realised != null ) {
				buff = realised.getSecAppBuff();
			}
		}
		if( buff != null ) {
			Buff.set( buff );
		}
	}

	public void deleteSecApp( CFSecAuthorization Authorization,
		CFSecSecAppBuff Buff )
	{
		final String S_ProcName = "deleteSecApp";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstDelete( "\n\t\t\t", Buff )
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

	public void deleteSecAppByIdIdx( CFSecAuthorization Authorization,
		long argClusterId,
		int argSecAppId )
	{
		final String S_ProcName = "deleteSecAppByIdIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstDelByIdIdx( "\n\t\t\t",
							argClusterId,
							argSecAppId )
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

	public void deleteSecAppByIdIdx( CFSecAuthorization Authorization,
		CFSecSecAppPKey argKey )
	{
		deleteSecAppByIdIdx( Authorization,
			argKey.getRequiredClusterId(),
			argKey.getRequiredSecAppId() );
	}
	public void deleteSecAppByClusterIdx( CFSecAuthorization Authorization,
		long argClusterId )
	{
		final String S_ProcName = "deleteSecAppByClusterIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstDelByClusterIdx( "\n\t\t\t",
							argClusterId )
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

	public void deleteSecAppByClusterIdx( CFSecAuthorization Authorization,
		CFSecSecAppByClusterIdxKey argKey )
	{
		deleteSecAppByClusterIdx( Authorization,
			argKey.getRequiredClusterId() );
	}
	public void deleteSecAppByUJEEMountIdx( CFSecAuthorization Authorization,
		long argClusterId,
		String argJEEMountName )
	{
		final String S_ProcName = "deleteSecAppByUJEEMountIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgSecAppMessageFormatter.formatSecAppRqstDelByUJEEMountIdx( "\n\t\t\t",
							argClusterId,
							argJEEMountName )
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

	public void deleteSecAppByUJEEMountIdx( CFSecAuthorization Authorization,
		CFSecSecAppByUJEEMountIdxKey argKey )
	{
		deleteSecAppByUJEEMountIdx( Authorization,
			argKey.getRequiredClusterId(),
			argKey.getRequiredJEEMountName() );
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
