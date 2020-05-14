// Description: Java 11 XMsg Client DbIO implementation for ISOCtry.

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
 *	CFIntXMsgClntISOCtry XMsg Client DbIO implementation
 *	for ISOCtry.
 */
public class CFIntXMsgClntISOCtry
	implements ICFIntISOCtryTable
{
	private CFIntXMsgClntSchema schema;

	public CFIntXMsgClntISOCtry( CFIntXMsgClntSchema argSchema ) {
		schema = argSchema;
	}

	public void createISOCtry( CFSecAuthorization Authorization,
		CFSecISOCtryBuff Buff )
	{
		final String S_ProcName = "createISOCtry";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstCreate( "\n\t\t\t", Buff )
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
			ICFIntISOCtryObj realised = null;
			if( lastObjectProcessed instanceof ICFIntISOCtryObj ) {
				realised = (ICFIntISOCtryObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntISOCtryObj" );
			}
			if( realised != null ) {
				Buff.set( realised.getISOCtryBuff() );
			}
		}
		else {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				0,
				"responseHandler.getLastObjectProcessed()" );
		}
	}

	public CFSecISOCtryBuff readDerived( CFSecAuthorization Authorization,
		CFSecISOCtryPKey PKey )
	{
		final String S_ProcName = "readDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstRead( "\n\t\t\t", PKey )
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
		CFSecISOCtryBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntISOCtryObj realised = null;
			if( lastObjectProcessed instanceof ICFIntISOCtryObj ) {
				realised = (ICFIntISOCtryObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntISOCtryObj" );
			}
			if( realised != null ) {
				buff = realised.getISOCtryBuff();
			}
		}
		return( buff );
	}

	public CFSecISOCtryBuff lockDerived( CFSecAuthorization Authorization,
		CFSecISOCtryPKey PKey )
	{
		final String S_ProcName = "lockDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstLock( "\n\t\t\t", PKey )
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
		CFSecISOCtryBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntISOCtryObj realised = null;
			if( lastObjectProcessed instanceof ICFIntISOCtryObj ) {
				realised = (ICFIntISOCtryObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntISOCtryObj" );
			}
			if( realised != null ) {
				buff = realised.getISOCtryBuff();
			}
		}
		return( buff );
	}

	public CFSecISOCtryBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstReadAll( "\n\t\t\t" )
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
		List<ICFSecISOCtryObj> sortedList =
			(List<ICFSecISOCtryObj>)sortedListObj;
		CFSecISOCtryBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecISOCtryBuff[ sz ];
			Iterator<ICFSecISOCtryObj> iter = sortedList.iterator();
			ICFSecISOCtryObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecISOCtryObj)iter.next();
				arr[idx] = cur.getISOCtryBuff();
			}
		}
		else {
			arr = new CFSecISOCtryBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecISOCtryBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		short argISOCtryId )
	{
		final String S_ProcName = "readDerivedByIdIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstRdByIdIdx( "\n\t\t\t",
							argISOCtryId )
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
		CFSecISOCtryBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntISOCtryObj realised = null;
			if( lastObjectProcessed instanceof ICFIntISOCtryObj ) {
				realised = (ICFIntISOCtryObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntISOCtryObj" );
			}
			if( realised != null ) {
				buff = realised.getISOCtryBuff();
			}
		}
		return( buff );
	}

	public CFSecISOCtryBuff readDerivedByISOCodeIdx( CFSecAuthorization Authorization,
		String argISOCode )
	{
		final String S_ProcName = "readDerivedByISOCodeIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstRdByISOCodeIdx( "\n\t\t\t",
							argISOCode )
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
		CFSecISOCtryBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntISOCtryObj realised = null;
			if( lastObjectProcessed instanceof ICFIntISOCtryObj ) {
				realised = (ICFIntISOCtryObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntISOCtryObj" );
			}
			if( realised != null ) {
				buff = realised.getISOCtryBuff();
			}
		}
		return( buff );
	}

	public CFSecISOCtryBuff readDerivedByNameIdx( CFSecAuthorization Authorization,
		String argName )
	{
		final String S_ProcName = "readDerivedByNameIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstRdByNameIdx( "\n\t\t\t",
							argName )
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
		CFSecISOCtryBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntISOCtryObj realised = null;
			if( lastObjectProcessed instanceof ICFIntISOCtryObj ) {
				realised = (ICFIntISOCtryObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntISOCtryObj" );
			}
			if( realised != null ) {
				buff = realised.getISOCtryBuff();
			}
		}
		return( buff );
	}

	public CFSecISOCtryBuff readBuff( CFSecAuthorization Authorization,
		CFSecISOCtryPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuff" );
	}

	public CFSecISOCtryBuff lockBuff( CFSecAuthorization Authorization,
		CFSecISOCtryPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"lockBuff" );
	}

	public CFSecISOCtryBuff[] readAllBuff( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllBuff";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstReadAll( "\n\t\t\t" )
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
		List<ICFSecISOCtryObj> sortedList =
			(List<ICFSecISOCtryObj>)sortedListObj;
		CFSecISOCtryBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecISOCtryBuff[ sz ];
			Iterator<ICFSecISOCtryObj> iter = sortedList.iterator();
			ICFSecISOCtryObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecISOCtryObj)iter.next();
				arr[idx] = cur.getISOCtryBuff();
			}
		}
		else {
			arr = new CFSecISOCtryBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecISOCtryBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		short argISOCtryId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByIdIdx" );
	}

	public CFSecISOCtryBuff readBuffByISOCodeIdx( CFSecAuthorization Authorization,
		String argISOCode )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByISOCodeIdx" );
	}

	public CFSecISOCtryBuff readBuffByNameIdx( CFSecAuthorization Authorization,
		String argName )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByNameIdx" );
	}

	public void updateISOCtry( CFSecAuthorization Authorization,
		CFSecISOCtryBuff Buff )
	{
		final String S_ProcName = "updateISOCtry";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstUpdate( "\n\t\t\t", Buff )
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
		CFSecISOCtryBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntISOCtryObj realised = null;
			if( lastObjectProcessed instanceof ICFIntISOCtryObj ) {
				realised = (ICFIntISOCtryObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntISOCtryObj" );
			}
			if( realised != null ) {
				buff = realised.getISOCtryBuff();
			}
		}
		if( buff != null ) {
			Buff.set( buff );
		}
	}

	public void deleteISOCtry( CFSecAuthorization Authorization,
		CFSecISOCtryBuff Buff )
	{
		final String S_ProcName = "deleteISOCtry";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstDelete( "\n\t\t\t", Buff )
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

	public void deleteISOCtryByIdIdx( CFSecAuthorization Authorization,
		short argISOCtryId )
	{
		final String S_ProcName = "deleteISOCtryByIdIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstDelByIdIdx( "\n\t\t\t",
							argISOCtryId )
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

	public void deleteISOCtryByIdIdx( CFSecAuthorization Authorization,
		CFSecISOCtryPKey argKey )
	{
		deleteISOCtryByIdIdx( Authorization,
			argKey.getRequiredISOCtryId() );
	}
	public void deleteISOCtryByISOCodeIdx( CFSecAuthorization Authorization,
		String argISOCode )
	{
		final String S_ProcName = "deleteISOCtryByISOCodeIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstDelByISOCodeIdx( "\n\t\t\t",
							argISOCode )
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

	public void deleteISOCtryByISOCodeIdx( CFSecAuthorization Authorization,
		CFSecISOCtryByISOCodeIdxKey argKey )
	{
		deleteISOCtryByISOCodeIdx( Authorization,
			argKey.getRequiredISOCode() );
	}
	public void deleteISOCtryByNameIdx( CFSecAuthorization Authorization,
		String argName )
	{
		final String S_ProcName = "deleteISOCtryByNameIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgISOCtryMessageFormatter.formatISOCtryRqstDelByNameIdx( "\n\t\t\t",
							argName )
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

	public void deleteISOCtryByNameIdx( CFSecAuthorization Authorization,
		CFSecISOCtryByNameIdxKey argKey )
	{
		deleteISOCtryByNameIdx( Authorization,
			argKey.getRequiredName() );
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
