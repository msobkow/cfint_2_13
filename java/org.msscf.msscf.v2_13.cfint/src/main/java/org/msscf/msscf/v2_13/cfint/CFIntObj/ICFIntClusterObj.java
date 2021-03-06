// Description: Java 11 Object interface for CFInt Cluster.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFSec 2.13 Security Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow mark.sobkow@gmail.com
 *	
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *	http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

package org.msscf.msscf.v2_13.cfint.CFIntObj;

import java.math.*;
import java.sql.*;
import java.text.*;
import java.util.*;
import org.msscf.msscf.v2_13.cfint.CFInt.*;
import org.msscf.msscf.v2_13.cflib.CFLib.*;
import org.msscf.msscf.v2_13.cfsec.CFSec.*;
import org.msscf.msscf.v2_13.cfsec.CFSecObj.*;
import org.msscf.msscf.v2_13.cfint.CFInt.*;

public interface ICFIntClusterObj
	extends ICFSecClusterObj
{
	String getClassCode();
	/**
	 *	Get the user who created this instance.
	 *
	 *	@return	The ICFSecSecUserObj instance who created this instance.
	 */
	ICFSecSecUserObj getCreatedBy();

	/**
	 *	Get the Calendar date-time this instance was created.
	 *
	 *	@return	The Calendar value for the create time of the instance.
	 */
	Calendar getCreatedAt();

	/**
	 *	Get the user who updated this instance.
	 *
	 *	@return	The ICFSecSecUserObj instance who updated this instance.
	 */
	ICFSecSecUserObj getUpdatedBy();

	/**
	 *	Get the Calendar date-time this instance was updated.
	 *
	 *	@return	The Calendar value for the create time of the instance.
	 */
	Calendar getUpdatedAt();
	/**
	 *	Realise this instance of a Cluster.
	 *
	 *	@return	CFSecClusterObj instance which should be subsequently referenced.
	 */
	ICFSecClusterObj realise();

	/**
	 *	Forget this instance from the cache.
	 *	<p>
	 *	This method should only be invoked by implementation internals.
	 */
	void forget();

	/**
	 *	Re-read this instance by it's primary key.
	 *
	 *	@return	ICFSecClusterObj the reference to the cached or read (realised) instance.
	 */
	ICFSecClusterObj read();

	/**
	 *	Re-read this instance by it's primary key.
	 *
	 *	@return	ICFSecClusterObj the reference to the cached or read (realised) instance.
	 */
	ICFSecClusterObj read( boolean forceRead );

	/**
	 *	Initialize and return a locked edition of this Cluster instance.
	 *
	 *	@return	The newly locked ICFSecClusterEditObj edition of this instance.
	 */
	ICFSecClusterEditObj beginEdit();

	/**
	 *	End this edition of this Cluster instance.
	 *
	 *	@throws	CFLibNotSupportedException if you try to end a read-only view.
	 */
	void endEdit();

	/**
	 *	Get the current edition of this Cluster instance.
	 *
	 *	@return	The ICFSecClusterEditObj edition of this instance.
	 */
	ICFSecClusterEditObj getEdit();

	/**
	 *	Get the current edition of this Cluster instance as a ICFSecClusterEditObj.
	 *
	 *	@return	The ICFSecClusterEditObj edition of this instance.
	 */
	ICFSecClusterEditObj getEditAsCluster();

	/**
	 *	Get the ICFSecClusterTableObj table cache which manages this instance.
	 *
	 *	@return	ICFSecClusterTableObj table cache which manages this instance.
	 */
	ICFSecClusterTableObj getClusterTable();

	/**
	 *	Get the ICFSecSchemaObj schema cache which manages this instance.
	 *
	 *	@return	ICFSecSchemaObj schema cache which manages this instance.
	 */
	ICFSecSchemaObj getSchema();

	/**
	 *	Get the CFSecClusterBuff instance which currently backs this instance.
	 *	<p>
	 *	This value <i>will</i> change for read-only instances, so you should
	 *	not hold on to the value as a reference anywhere outside the current call stack.
	 *
	 *	@return	CFSecClusterBuff instance which currently backs this object.
	 */
	CFSecClusterBuff getBuff();

	/**
	 *	Internal use only.
	 */
	void setBuff( CFSecClusterBuff value );

	/**
	 *	Get the CFSecClusterBuff instance which currently backs this instance.
	 *	<p>
	 *	This value <i>will</i> change for read-only instances, so you should
	 *	not hold on to the value as a reference anywhere outside the current call stack.
	 *
	 *	@return	CFSecClusterBuff instance which currently backs this object.
	 */
	CFSecClusterBuff getClusterBuff();

	/**
	 *	Is this a new instance?
	 *
	 *	@return	True if this is a new instance, otherwise false if it has
	 *		been read, locked, or created.
	 */
	boolean getIsNew();

	/**
	 *	Indicate whether this is a new instance.
	 *	<p>
	 *	This method should only be used by implementation internals.
	 *
	 *	@param	True if this is a new instance, otherwise false.
	 */
	void setIsNew( boolean value );

	/**
	 *	Get the required long attribute Id.
	 *
	 *	@return	The required long attribute Id.
	 */
	long getRequiredId();

	/**
	 *	Get the required String attribute FullDomName.
	 *
	 *	@return	The required String attribute FullDomName.
	 */
	String getRequiredFullDomName();

	/**
	 *	Get the required String attribute Description.
	 *
	 *	@return	The required String attribute Description.
	 */
	String getRequiredDescription();

	/**
	 *	Get the array of optional ICFSecHostNodeObj array of instances referenced by the HostNode key.
	 *
	 *	@return	The optional ICFSecHostNodeObj[] array of instances referenced by the HostNode key.
	 */
	List<ICFSecHostNodeObj> getOptionalComponentsHostNode();

	/**
	 *	Get the array of optional ICFSecHostNodeObj array of instances referenced by the HostNode key.
	 *
	 *	@return	The optional ICFSecHostNodeObj[] array of instances referenced by the HostNode key.
	 */
	List<ICFSecHostNodeObj> getOptionalComponentsHostNode( boolean forceRead );

	/**
	 *	Get the array of optional ICFSecTenantObj array of instances referenced by the Tenant key.
	 *
	 *	@return	The optional ICFSecTenantObj[] array of instances referenced by the Tenant key.
	 */
	List<ICFSecTenantObj> getOptionalComponentsTenant();

	/**
	 *	Get the array of optional ICFSecTenantObj array of instances referenced by the Tenant key.
	 *
	 *	@return	The optional ICFSecTenantObj[] array of instances referenced by the Tenant key.
	 */
	List<ICFSecTenantObj> getOptionalComponentsTenant( boolean forceRead );

	/**
	 *	Get the array of optional ICFSecSecAppObj array of instances referenced by the SecApp key.
	 *
	 *	@return	The optional ICFSecSecAppObj[] array of instances referenced by the SecApp key.
	 */
	List<ICFSecSecAppObj> getOptionalComponentsSecApp();

	/**
	 *	Get the array of optional ICFSecSecAppObj array of instances referenced by the SecApp key.
	 *
	 *	@return	The optional ICFSecSecAppObj[] array of instances referenced by the SecApp key.
	 */
	List<ICFSecSecAppObj> getOptionalComponentsSecApp( boolean forceRead );

	/**
	 *	Get the array of optional ICFSecSecGroupObj array of instances referenced by the SecGroup key.
	 *
	 *	@return	The optional ICFSecSecGroupObj[] array of instances referenced by the SecGroup key.
	 */
	List<ICFSecSecGroupObj> getOptionalComponentsSecGroup();

	/**
	 *	Get the array of optional ICFSecSecGroupObj array of instances referenced by the SecGroup key.
	 *
	 *	@return	The optional ICFSecSecGroupObj[] array of instances referenced by the SecGroup key.
	 */
	List<ICFSecSecGroupObj> getOptionalComponentsSecGroup( boolean forceRead );

	/**
	 *	Get the array of optional ICFSecSysClusterObj array of instances referenced by the SysCluster key.
	 *
	 *	@return	The optional ICFSecSysClusterObj[] array of instances referenced by the SysCluster key.
	 */
	List<ICFSecSysClusterObj> getOptionalComponentsSysCluster();

	/**
	 *	Get the array of optional ICFSecSysClusterObj array of instances referenced by the SysCluster key.
	 *
	 *	@return	The optional ICFSecSysClusterObj[] array of instances referenced by the SysCluster key.
	 */
	List<ICFSecSysClusterObj> getOptionalComponentsSysCluster( boolean forceRead );

	/**
	 *	Internal use only.
	 */
	void copyPKeyToBuff();

	/**
	 *	Internal use only.
	 */
	void copyBuffToPKey();

}
