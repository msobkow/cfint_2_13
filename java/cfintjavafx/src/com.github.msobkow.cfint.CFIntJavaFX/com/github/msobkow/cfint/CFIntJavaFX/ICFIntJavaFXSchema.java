// Description: Java 11 JavaFX Schema Interface for CFInt.

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

package com.github.msobkow.cfint.CFIntJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import java.security.KeyStore;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfint.CFInt.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFIntObj.*;
import com.github.msobkow.cfsec.CFSecJavaFX.*;

/**
 *	The ICFIntJavaFXSchema defines the factory interface for the
 *	for the various panes and components used to construct a GUI interface
 *	using the JavaFX framework.
 */
public interface ICFIntJavaFXSchema
	extends ICFSecJavaFXSchema
{
	CFSecClientConfigurationFile getClientConfigurationFile();
	void setClientConfigurationFile( CFSecClientConfigurationFile value );

	KeyStore getKeyStore();
	void setKeyStore( KeyStore value );

	ICFSecSchemaObj getSchema();
	void setSchema( ICFSecSchemaObj argSchema );

	String getClusterName();
	void setClusterName( String argClusterName );
	ICFSecClusterObj getClusterObj();

	String getTenantName();
	void setTenantName( String argTenantName );
	ICFSecTenantObj getTenantObj();

	String getSecUserName();
	void setSecUserName( String argSecUserName );
	ICFSecSecUserObj getSecUserObj();

	ICFSecSecSessionObj getSecSessionObj();

	public ICFSecJavaFXClusterFactory getClusterFactory();

	public ICFSecJavaFXHostNodeFactory getHostNodeFactory();

	public ICFSecJavaFXISOCcyFactory getISOCcyFactory();

	public ICFSecJavaFXISOCtryFactory getISOCtryFactory();

	public ICFSecJavaFXISOCtryCcyFactory getISOCtryCcyFactory();

	public ICFSecJavaFXISOCtryLangFactory getISOCtryLangFactory();

	public ICFSecJavaFXISOLangFactory getISOLangFactory();

	public ICFSecJavaFXISOTZoneFactory getISOTZoneFactory();

	public ICFIntJavaFXLicenseFactory getLicenseFactory();

	public ICFIntJavaFXMajorVersionFactory getMajorVersionFactory();

	public ICFIntJavaFXMimeTypeFactory getMimeTypeFactory();

	public ICFIntJavaFXMinorVersionFactory getMinorVersionFactory();

	public ICFSecJavaFXSecAppFactory getSecAppFactory();

	public ICFSecJavaFXSecDeviceFactory getSecDeviceFactory();

	public ICFSecJavaFXSecFormFactory getSecFormFactory();

	public ICFSecJavaFXSecGroupFactory getSecGroupFactory();

	public ICFSecJavaFXSecGroupFormFactory getSecGroupFormFactory();

	public ICFSecJavaFXSecGrpIncFactory getSecGrpIncFactory();

	public ICFSecJavaFXSecGrpMembFactory getSecGrpMembFactory();

	public ICFSecJavaFXSecSessionFactory getSecSessionFactory();

	public ICFSecJavaFXSecUserFactory getSecUserFactory();

	public ICFSecJavaFXServiceFactory getServiceFactory();

	public ICFSecJavaFXServiceTypeFactory getServiceTypeFactory();

	public ICFIntJavaFXSubProjectFactory getSubProjectFactory();

	public ICFSecJavaFXSysClusterFactory getSysClusterFactory();

	public ICFSecJavaFXTSecGroupFactory getTSecGroupFactory();

	public ICFSecJavaFXTSecGrpIncFactory getTSecGrpIncFactory();

	public ICFSecJavaFXTSecGrpMembFactory getTSecGrpMembFactory();

	public ICFSecJavaFXTenantFactory getTenantFactory();

	public ICFIntJavaFXTldFactory getTldFactory();

	public ICFIntJavaFXTopDomainFactory getTopDomainFactory();

	public ICFIntJavaFXTopProjectFactory getTopProjectFactory();

	public ICFIntJavaFXURLProtocolFactory getURLProtocolFactory();
}
