// Description: Java 11 Instance Edit Object interface for CFInt TSecGrpMemb.

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

public interface ICFIntTSecGrpMembEditObj
	extends ICFIntTSecGrpMembObj,
		ICFSecTSecGrpMembEditObj
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
	ICFSecTSecGrpMembObj create();

	/*
	 *	Update the instance.
	 */
	CFSecTSecGrpMembEditObj update();

	/**
	 *	Get the ICFSecTenantObj instance referenced by the Tenant key.
	 *
	 *	@return	The ICFSecTenantObj instance referenced by the Tenant key.
	 */
	ICFSecTenantObj getRequiredOwnerTenant();

	/**
	 *	Set the ICFSecTenantObj instance referenced by the Tenant key.
	 *
	 *	@param	value	the ICFSecTenantObj instance to be referenced by the Tenant key.
	 */
	void setRequiredOwnerTenant( ICFSecTenantObj value );

	/**
	 *	Get the ICFSecTSecGroupObj instance referenced by the Group key.
	 *
	 *	@return	The ICFSecTSecGroupObj instance referenced by the Group key.
	 */
	ICFSecTSecGroupObj getRequiredContainerGroup();

	/**
	 *	Set the ICFSecTSecGroupObj instance referenced by the Group key.
	 *
	 *	@param	value	the ICFSecTSecGroupObj instance to be referenced by the Group key.
	 */
	void setRequiredContainerGroup( ICFSecTSecGroupObj value );

	/**
	 *	Get the ICFSecSecUserObj instance referenced by the User key.
	 *
	 *	@return	The ICFSecSecUserObj instance referenced by the User key.
	 */
	ICFSecSecUserObj getRequiredParentUser();

	/**
	 *	Set the ICFSecSecUserObj instance referenced by the User key.
	 *
	 *	@param	value	the ICFSecSecUserObj instance to be referenced by the User key.
	 */
	void setRequiredParentUser( ICFSecSecUserObj value );
}
