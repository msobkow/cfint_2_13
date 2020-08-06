// Description: Java 11 JavaFX Schema Interface for CFInt.

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

package org.msscf.msscf.cfint.CFIntJavaFX;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import java.security.KeyStore;
import org.msscf.msscf.cflib.CFLib.*;
import org.msscf.msscf.cflib.CFLib.JavaFX.*;
import org.apache.commons.codec.binary.Base64;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfint.CFInt.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFIntObj.*;
import org.msscf.msscf.cfsec.CFSecJavaFX.*;

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
