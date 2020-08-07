// Description: Java 11 XMsg Client DbIO implementation for Cluster.

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

package org.msscf.msscf.cfint.CFIntXMsgClnt;

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
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.Tip.*;
import org.apache.commons.codec.binary.Base64;

import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;
import org.msscf.msscf.cfint.CFIntXMsg.*;
import org.msscf.msscf.cfint.CFIntXMsgRspn.*;

/*
 *	CFIntXMsgClntCluster XMsg Client DbIO implementation
 *	for Cluster.
 */
public class CFIntXMsgClntCluster
	implements ICFIntClusterTable
{
	private CFIntXMsgClntSchema schema;

	public CFIntXMsgClntCluster( CFIntXMsgClntSchema argSchema ) {
		schema = argSchema;
	}

	public int nextSecAppIdGen( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecAppIdGen" );
	}

	public int nextSecAppIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecAppIdGen" );
	}

	public int nextSecFormIdGen( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecFormIdGen" );
	}

	public int nextSecFormIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecFormIdGen" );
	}

	public int nextSecGroupIdGen( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecGroupIdGen" );
	}

	public int nextSecGroupIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecGroupIdGen" );
	}

	public long nextHostNodeIdGen( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextHostNodeIdGen" );
	}

	public long nextHostNodeIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextHostNodeIdGen" );
	}

	public long nextSecGroupFormIdGen( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecGroupFormIdGen" );
	}

	public long nextSecGroupFormIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecGroupFormIdGen" );
	}

	public long nextSecGrpIncIdGen( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecGrpIncIdGen" );
	}

	public long nextSecGrpIncIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecGrpIncIdGen" );
	}

	public long nextSecGrpMembIdGen( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecGrpMembIdGen" );
	}

	public long nextSecGrpMembIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextSecGrpMembIdGen" );
	}

	public long nextServiceIdGen( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextServiceIdGen" );
	}

	public long nextServiceIdGen( CFSecAuthorization Authorization,
		long argId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"nextServiceIdGen" );
	}

	public void createCluster( CFSecAuthorization Authorization,
		CFSecClusterBuff Buff )
	{
		final String S_ProcName = "createCluster";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstCreate( "\n\t\t\t", Buff )
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
			ICFIntClusterObj realised = null;
			if( lastObjectProcessed instanceof ICFIntClusterObj ) {
				realised = (ICFIntClusterObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntClusterObj" );
			}
			if( realised != null ) {
				Buff.set( realised.getClusterBuff() );
			}
		}
		else {
			throw new CFLibNullArgumentException( getClass(),
				S_ProcName,
				0,
				"responseHandler.getLastObjectProcessed()" );
		}
	}

	public CFSecClusterBuff readDerived( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		final String S_ProcName = "readDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstRead( "\n\t\t\t", PKey )
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
		CFSecClusterBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntClusterObj realised = null;
			if( lastObjectProcessed instanceof ICFIntClusterObj ) {
				realised = (ICFIntClusterObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntClusterObj" );
			}
			if( realised != null ) {
				buff = realised.getClusterBuff();
			}
		}
		return( buff );
	}

	public CFSecClusterBuff lockDerived( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		final String S_ProcName = "lockDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstLock( "\n\t\t\t", PKey )
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
		CFSecClusterBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntClusterObj realised = null;
			if( lastObjectProcessed instanceof ICFIntClusterObj ) {
				realised = (ICFIntClusterObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntClusterObj" );
			}
			if( realised != null ) {
				buff = realised.getClusterBuff();
			}
		}
		return( buff );
	}

	public CFSecClusterBuff[] readAllDerived( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllDerived";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstReadAll( "\n\t\t\t" )
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
		List<ICFSecClusterObj> sortedList =
			(List<ICFSecClusterObj>)sortedListObj;
		CFSecClusterBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecClusterBuff[ sz ];
			Iterator<ICFSecClusterObj> iter = sortedList.iterator();
			ICFSecClusterObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecClusterObj)iter.next();
				arr[idx] = cur.getClusterBuff();
			}
		}
		else {
			arr = new CFSecClusterBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecClusterBuff readDerivedByIdIdx( CFSecAuthorization Authorization,
		long argId )
	{
		final String S_ProcName = "readDerivedByIdIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstRdByIdIdx( "\n\t\t\t",
							argId )
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
		CFSecClusterBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntClusterObj realised = null;
			if( lastObjectProcessed instanceof ICFIntClusterObj ) {
				realised = (ICFIntClusterObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntClusterObj" );
			}
			if( realised != null ) {
				buff = realised.getClusterBuff();
			}
		}
		return( buff );
	}

	public CFSecClusterBuff readDerivedByUDomNameIdx( CFSecAuthorization Authorization,
		String argFullDomName )
	{
		final String S_ProcName = "readDerivedByUDomNameIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstRdByUDomNameIdx( "\n\t\t\t",
							argFullDomName )
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
		CFSecClusterBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntClusterObj realised = null;
			if( lastObjectProcessed instanceof ICFIntClusterObj ) {
				realised = (ICFIntClusterObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntClusterObj" );
			}
			if( realised != null ) {
				buff = realised.getClusterBuff();
			}
		}
		return( buff );
	}

	public CFSecClusterBuff readDerivedByUDescrIdx( CFSecAuthorization Authorization,
		String argDescription )
	{
		final String S_ProcName = "readDerivedByUDescrIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstRdByUDescrIdx( "\n\t\t\t",
							argDescription )
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
		CFSecClusterBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntClusterObj realised = null;
			if( lastObjectProcessed instanceof ICFIntClusterObj ) {
				realised = (ICFIntClusterObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntClusterObj" );
			}
			if( realised != null ) {
				buff = realised.getClusterBuff();
			}
		}
		return( buff );
	}

	public CFSecClusterBuff readBuff( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuff" );
	}

	public CFSecClusterBuff lockBuff( CFSecAuthorization Authorization,
		CFSecClusterPKey PKey )
	{
		throw new CFLibNotSupportedException( getClass(),
			"lockBuff" );
	}

	public CFSecClusterBuff[] readAllBuff( CFSecAuthorization Authorization ) {
		final String S_ProcName = "readAllBuff";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstReadAll( "\n\t\t\t" )
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
		List<ICFSecClusterObj> sortedList =
			(List<ICFSecClusterObj>)sortedListObj;
		CFSecClusterBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecClusterBuff[ sz ];
			Iterator<ICFSecClusterObj> iter = sortedList.iterator();
			ICFSecClusterObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecClusterObj)iter.next();
				arr[idx] = cur.getClusterBuff();
			}
		}
		else {
			arr = new CFSecClusterBuff[ 0 ];
		}
		return( arr );
	}

	/**
	 *	Read a page of all the specific Cluster buffer instances.
	 *
	 *	@param	Authorization	The session authorization information.
	 *
	 *	@return All the specific Cluster instances in the database accessible for the Authorization.
	 */
	public CFSecClusterBuff[] pageAllBuff( CFSecAuthorization Authorization,
		Long priorId )
	{
		final String S_ProcName = "pageAllBuff";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstPageAll( "\n\t\t\t",
							priorId )
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
		List<ICFSecClusterObj> sortedList =
			(List<ICFSecClusterObj>)sortedListObj;
		CFSecClusterBuff arr[];
		if( sortedList != null ) {
			int sz = sortedList.size();
			arr = new CFSecClusterBuff[ sz ];
			Iterator<ICFSecClusterObj> iter = sortedList.iterator();
			ICFSecClusterObj cur;
			for( int idx = 0; idx < sz; idx ++ ) {
				cur = (ICFSecClusterObj)iter.next();
				arr[idx] = cur.getClusterBuff();
			}
		}
		else {
			arr = new CFSecClusterBuff[ 0 ];
		}
		return( arr );
	}

	public CFSecClusterBuff readBuffByIdIdx( CFSecAuthorization Authorization,
		long argId )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByIdIdx" );
	}

	public CFSecClusterBuff readBuffByUDomNameIdx( CFSecAuthorization Authorization,
		String argFullDomName )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByUDomNameIdx" );
	}

	public CFSecClusterBuff readBuffByUDescrIdx( CFSecAuthorization Authorization,
		String argDescription )
	{
		throw new CFLibNotSupportedException( getClass(),
			"readBuffByUDescrIdx" );
	}

	public void updateCluster( CFSecAuthorization Authorization,
		CFSecClusterBuff Buff )
	{
		final String S_ProcName = "updateCluster";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstUpdate( "\n\t\t\t", Buff )
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
		CFSecClusterBuff buff = null;
		Object lastObjectProcessed = responseHandler.getLastObjectProcessed();
		if( lastObjectProcessed != null ) {
			ICFIntClusterObj realised = null;
			if( lastObjectProcessed instanceof ICFIntClusterObj ) {
				realised = (ICFIntClusterObj)lastObjectProcessed;
			}
			else {
				throw new CFLibUnsupportedClassException( getClass(),
					S_ProcName,
					"lastObjectProcessed",
					lastObjectProcessed,
					"ICFIntClusterObj" );
			}
			if( realised != null ) {
				buff = realised.getClusterBuff();
			}
		}
		if( buff != null ) {
			Buff.set( buff );
		}
	}

	public void deleteCluster( CFSecAuthorization Authorization,
		CFSecClusterBuff Buff )
	{
		final String S_ProcName = "deleteCluster";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstDelete( "\n\t\t\t", Buff )
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

	public void deleteClusterByIdIdx( CFSecAuthorization Authorization,
		long argId )
	{
		final String S_ProcName = "deleteClusterByIdIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstDelByIdIdx( "\n\t\t\t",
							argId )
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

	public void deleteClusterByIdIdx( CFSecAuthorization Authorization,
		CFSecClusterPKey argKey )
	{
		deleteClusterByIdIdx( Authorization,
			argKey.getRequiredId() );
	}
	public void deleteClusterByUDomNameIdx( CFSecAuthorization Authorization,
		String argFullDomName )
	{
		final String S_ProcName = "deleteClusterByUDomNameIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstDelByUDomNameIdx( "\n\t\t\t",
							argFullDomName )
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

	public void deleteClusterByUDomNameIdx( CFSecAuthorization Authorization,
		CFSecClusterByUDomNameIdxKey argKey )
	{
		deleteClusterByUDomNameIdx( Authorization,
			argKey.getRequiredFullDomName() );
	}
	public void deleteClusterByUDescrIdx( CFSecAuthorization Authorization,
		String argDescription )
	{
		final String S_ProcName = "deleteClusterByUDescrIdx";
		String rqst = CFIntXMsgSchemaMessageFormatter.formatRqstXmlPreamble() + "\n"
			+	"\t" + CFIntXMsgClusterMessageFormatter.formatClusterRqstDelByUDescrIdx( "\n\t\t\t",
							argDescription )
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

	public void deleteClusterByUDescrIdx( CFSecAuthorization Authorization,
		CFSecClusterByUDescrIdxKey argKey )
	{
		deleteClusterByUDescrIdx( Authorization,
			argKey.getRequiredDescription() );
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