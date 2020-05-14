// Description: Java 11 Instance Edit Object interface for CFInt SecGroupForm.

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

package com.github.msobkow.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import com.github.msobkow.cflib.CFLib.*;
import com.github.msobkow.cfsec.CFSec.*;
import com.github.msobkow.cfsec.CFSecObj.*;
import com.github.msobkow.cfint.CFInt.*;

public interface ICFIntSecGroupFormEditObj
	extends ICFIntSecGroupFormObj,
		ICFSecSecGroupFormEditObj
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
	ICFSecSecGroupFormObj create();

	/*
	 *	Update the instance.
	 */
	CFSecSecGroupFormEditObj update();

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
	 *	Get the ICFSecSecGroupObj instance referenced by the Group key.
	 *
	 *	@return	The ICFSecSecGroupObj instance referenced by the Group key.
	 */
	ICFSecSecGroupObj getRequiredContainerGroup();

	/**
	 *	Set the ICFSecSecGroupObj instance referenced by the Group key.
	 *
	 *	@param	value	the ICFSecSecGroupObj instance to be referenced by the Group key.
	 */
	void setRequiredContainerGroup( ICFSecSecGroupObj value );

	/**
	 *	Get the ICFSecSecAppObj instance referenced by the App key.
	 *
	 *	@return	The ICFSecSecAppObj instance referenced by the App key.
	 */
	ICFSecSecAppObj getRequiredParentApp();

	/**
	 *	Set the ICFSecSecAppObj instance referenced by the App key.
	 *
	 *	@param	value	the ICFSecSecAppObj instance to be referenced by the App key.
	 */
	void setRequiredParentApp( ICFSecSecAppObj value );

	/**
	 *	Get the ICFSecSecFormObj instance referenced by the Form key.
	 *
	 *	@return	The ICFSecSecFormObj instance referenced by the Form key.
	 */
	ICFSecSecFormObj getRequiredParentForm();

	/**
	 *	Set the ICFSecSecFormObj instance referenced by the Form key.
	 *
	 *	@param	value	the ICFSecSecFormObj instance to be referenced by the Form key.
	 */
	void setRequiredParentForm( ICFSecSecFormObj value );
}
