// Description: Java 11 Instance Edit Object interface for CFInt Service.

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

package org.msscf.msscf.cfint.v2_13.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.cflib.v2_13.CFLib.*;
import org.msscf.msscf.cfsec.CFSec.*;
import org.msscf.msscf.cfsec.CFSecObj.*;
import org.msscf.msscf.cfint.CFInt.*;

public interface ICFIntServiceEditObj
	extends ICFIntServiceObj,
		ICFSecServiceEditObj
{
	/*
	 *	create() may return a different instance than the
	 *	one used to invoke the operation.  All future references
	 *	should be to the returned instance, not the original
	 *	invoker.  You should lose all references to the original
	 *	invoker.
	 *
	 *	@return The created instance.
	 */
	ICFSecServiceObj create();

	/*
	 *	Update the instance.
	 */
	CFSecServiceEditObj update();

	/**
	 *	Get the ICFSecClusterObj instance referenced by the Cluster key.
	 *
	 *	@return	The ICFSecClusterObj instance referenced by the Cluster key.
	 */
	ICFSecClusterObj getRequiredOwnerCluster();

	/**
	 *	Set the ICFSecClusterObj instance referenced by the Cluster key.
	 *
	 *	@param	value	the ICFSecClusterObj instance to be referenced by the Cluster key.
	 */
	void setRequiredOwnerCluster( ICFSecClusterObj value );

	/**
	 *	Get the ICFSecHostNodeObj instance referenced by the Host key.
	 *
	 *	@return	The ICFSecHostNodeObj instance referenced by the Host key.
	 */
	ICFSecHostNodeObj getOptionalContainerHost();

	/**
	 *	Set the ICFSecHostNodeObj instance referenced by the Host key.
	 *
	 *	@param	value	the ICFSecHostNodeObj instance to be referenced by the Host key.
	 */
	void setOptionalContainerHost( ICFSecHostNodeObj value );

	/**
	 *	Get the ICFSecServiceTypeObj instance referenced by the ServiceType key.
	 *
	 *	@return	The ICFSecServiceTypeObj instance referenced by the ServiceType key.
	 */
	ICFSecServiceTypeObj getOptionalParentServiceType();

	/**
	 *	Set the ICFSecServiceTypeObj instance referenced by the ServiceType key.
	 *
	 *	@param	value	the ICFSecServiceTypeObj instance to be referenced by the ServiceType key.
	 */
	void setOptionalParentServiceType( ICFSecServiceTypeObj value );
}
