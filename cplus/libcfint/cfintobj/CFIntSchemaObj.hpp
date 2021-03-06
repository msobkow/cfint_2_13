#pragma once

// Description: C++18 Schema Object specification for CFInt.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>
#include <cfint/ICFIntPublic.hpp>

namespace cfint {
	class ICFIntSchemaObj;
}

namespace cfsec {
	class ICFSecClusterObj;
	class ICFSecClusterEditObj;
	class ICFSecClusterTableObj;
}

namespace cfint { 
	class ICFIntClusterObj;
	class ICFIntClusterEditObj;
	class ICFIntClusterTableObj;
}

namespace cfsec {
	class ICFSecHostNodeObj;
	class ICFSecHostNodeEditObj;
	class ICFSecHostNodeTableObj;
}

namespace cfint { 
	class ICFIntHostNodeObj;
	class ICFIntHostNodeEditObj;
	class ICFIntHostNodeTableObj;
}

namespace cfsec {
	class ICFSecISOCcyObj;
	class ICFSecISOCcyEditObj;
	class ICFSecISOCcyTableObj;
}

namespace cfint { 
	class ICFIntISOCcyObj;
	class ICFIntISOCcyEditObj;
	class ICFIntISOCcyTableObj;
}

namespace cfsec {
	class ICFSecISOCtryObj;
	class ICFSecISOCtryEditObj;
	class ICFSecISOCtryTableObj;
}

namespace cfint { 
	class ICFIntISOCtryObj;
	class ICFIntISOCtryEditObj;
	class ICFIntISOCtryTableObj;
}

namespace cfsec {
	class ICFSecISOCtryCcyObj;
	class ICFSecISOCtryCcyEditObj;
	class ICFSecISOCtryCcyTableObj;
}

namespace cfint { 
	class ICFIntISOCtryCcyObj;
	class ICFIntISOCtryCcyEditObj;
	class ICFIntISOCtryCcyTableObj;
}

namespace cfsec {
	class ICFSecISOCtryLangObj;
	class ICFSecISOCtryLangEditObj;
	class ICFSecISOCtryLangTableObj;
}

namespace cfint { 
	class ICFIntISOCtryLangObj;
	class ICFIntISOCtryLangEditObj;
	class ICFIntISOCtryLangTableObj;
}

namespace cfsec {
	class ICFSecISOLangObj;
	class ICFSecISOLangEditObj;
	class ICFSecISOLangTableObj;
}

namespace cfint { 
	class ICFIntISOLangObj;
	class ICFIntISOLangEditObj;
	class ICFIntISOLangTableObj;
}

namespace cfsec {
	class ICFSecISOTZoneObj;
	class ICFSecISOTZoneEditObj;
	class ICFSecISOTZoneTableObj;
}

namespace cfint { 
	class ICFIntISOTZoneObj;
	class ICFIntISOTZoneEditObj;
	class ICFIntISOTZoneTableObj;
	class ICFIntLicenseObj;
	class ICFIntLicenseEditObj;
	class ICFIntLicenseTableObj;
	class ICFIntMajorVersionObj;
	class ICFIntMajorVersionEditObj;
	class ICFIntMajorVersionTableObj;
	class ICFIntMimeTypeObj;
	class ICFIntMimeTypeEditObj;
	class ICFIntMimeTypeTableObj;
	class ICFIntMinorVersionObj;
	class ICFIntMinorVersionEditObj;
	class ICFIntMinorVersionTableObj;
}

namespace cfsec {
	class ICFSecSecAppObj;
	class ICFSecSecAppEditObj;
	class ICFSecSecAppTableObj;
}

namespace cfint { 
	class ICFIntSecAppObj;
	class ICFIntSecAppEditObj;
	class ICFIntSecAppTableObj;
}

namespace cfsec {
	class ICFSecSecDeviceObj;
	class ICFSecSecDeviceEditObj;
	class ICFSecSecDeviceTableObj;
}

namespace cfint { 
	class ICFIntSecDeviceObj;
	class ICFIntSecDeviceEditObj;
	class ICFIntSecDeviceTableObj;
}

namespace cfsec {
	class ICFSecSecFormObj;
	class ICFSecSecFormEditObj;
	class ICFSecSecFormTableObj;
}

namespace cfint { 
	class ICFIntSecFormObj;
	class ICFIntSecFormEditObj;
	class ICFIntSecFormTableObj;
}

namespace cfsec {
	class ICFSecSecGroupObj;
	class ICFSecSecGroupEditObj;
	class ICFSecSecGroupTableObj;
}

namespace cfint { 
	class ICFIntSecGroupObj;
	class ICFIntSecGroupEditObj;
	class ICFIntSecGroupTableObj;
}

namespace cfsec {
	class ICFSecSecGroupFormObj;
	class ICFSecSecGroupFormEditObj;
	class ICFSecSecGroupFormTableObj;
}

namespace cfint { 
	class ICFIntSecGroupFormObj;
	class ICFIntSecGroupFormEditObj;
	class ICFIntSecGroupFormTableObj;
}

namespace cfsec {
	class ICFSecSecGrpIncObj;
	class ICFSecSecGrpIncEditObj;
	class ICFSecSecGrpIncTableObj;
}

namespace cfint { 
	class ICFIntSecGrpIncObj;
	class ICFIntSecGrpIncEditObj;
	class ICFIntSecGrpIncTableObj;
}

namespace cfsec {
	class ICFSecSecGrpMembObj;
	class ICFSecSecGrpMembEditObj;
	class ICFSecSecGrpMembTableObj;
}

namespace cfint { 
	class ICFIntSecGrpMembObj;
	class ICFIntSecGrpMembEditObj;
	class ICFIntSecGrpMembTableObj;
}

namespace cfsec {
	class ICFSecSecSessionObj;
	class ICFSecSecSessionEditObj;
	class ICFSecSecSessionTableObj;
}

namespace cfint { 
	class ICFIntSecSessionObj;
	class ICFIntSecSessionEditObj;
	class ICFIntSecSessionTableObj;
}

namespace cfsec {
	class ICFSecSecUserObj;
	class ICFSecSecUserEditObj;
	class ICFSecSecUserTableObj;
}

namespace cfint { 
	class ICFIntSecUserObj;
	class ICFIntSecUserEditObj;
	class ICFIntSecUserTableObj;
}

namespace cfsec {
	class ICFSecServiceObj;
	class ICFSecServiceEditObj;
	class ICFSecServiceTableObj;
}

namespace cfint { 
	class ICFIntServiceObj;
	class ICFIntServiceEditObj;
	class ICFIntServiceTableObj;
}

namespace cfsec {
	class ICFSecServiceTypeObj;
	class ICFSecServiceTypeEditObj;
	class ICFSecServiceTypeTableObj;
}

namespace cfint { 
	class ICFIntServiceTypeObj;
	class ICFIntServiceTypeEditObj;
	class ICFIntServiceTypeTableObj;
	class ICFIntSubProjectObj;
	class ICFIntSubProjectEditObj;
	class ICFIntSubProjectTableObj;
}

namespace cfsec {
	class ICFSecSysClusterObj;
	class ICFSecSysClusterEditObj;
	class ICFSecSysClusterTableObj;
}

namespace cfint { 
	class ICFIntSysClusterObj;
	class ICFIntSysClusterEditObj;
	class ICFIntSysClusterTableObj;
}

namespace cfsec {
	class ICFSecTSecGroupObj;
	class ICFSecTSecGroupEditObj;
	class ICFSecTSecGroupTableObj;
}

namespace cfint { 
	class ICFIntTSecGroupObj;
	class ICFIntTSecGroupEditObj;
	class ICFIntTSecGroupTableObj;
}

namespace cfsec {
	class ICFSecTSecGrpIncObj;
	class ICFSecTSecGrpIncEditObj;
	class ICFSecTSecGrpIncTableObj;
}

namespace cfint { 
	class ICFIntTSecGrpIncObj;
	class ICFIntTSecGrpIncEditObj;
	class ICFIntTSecGrpIncTableObj;
}

namespace cfsec {
	class ICFSecTSecGrpMembObj;
	class ICFSecTSecGrpMembEditObj;
	class ICFSecTSecGrpMembTableObj;
}

namespace cfint { 
	class ICFIntTSecGrpMembObj;
	class ICFIntTSecGrpMembEditObj;
	class ICFIntTSecGrpMembTableObj;
}

namespace cfsec {
	class ICFSecTenantObj;
	class ICFSecTenantEditObj;
	class ICFSecTenantTableObj;
}

namespace cfint { 
	class ICFIntTenantObj;
	class ICFIntTenantEditObj;
	class ICFIntTenantTableObj;
	class ICFIntTldObj;
	class ICFIntTldEditObj;
	class ICFIntTldTableObj;
	class ICFIntTopDomainObj;
	class ICFIntTopDomainEditObj;
	class ICFIntTopDomainTableObj;
	class ICFIntTopProjectObj;
	class ICFIntTopProjectEditObj;
	class ICFIntTopProjectTableObj;
	class ICFIntURLProtocolObj;
	class ICFIntURLProtocolEditObj;
	class ICFIntURLProtocolTableObj;
}

#include <cfintobj/ICFIntSchemaObj.hpp>

namespace cfint {

	class CFIntSchemaObj
	: public virtual ICFIntSchemaObj
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string SCHEMA_NAME;
		static const std::string SCHEMA_DBNAME;
		static const std::string S_System;
	protected:
		cfsec::CFSecAuthorization* authorization;
		cfsec::ICFSecSchema* backingStore;
		std::string* secClusterName;
		std::string* secTenantName;
		std::string* secUserName;
		cfsec::ICFSecClusterObj* secCluster;
		long secClusterId;
		cfsec::ICFSecTenantObj* secTenant;
		long secTenantId;
		cfsec::ICFSecSecUserObj* secUser;
		uuid_t secSessionUserId;
		cfsec::ICFSecSecSessionObj* secSession;
		uuid_t secSessionSessionId;
		std::string* schemaDbName;
		std::string* lowerDbSchemaName;
		ICFIntClusterTableObj* clusterTableObj;
		ICFIntHostNodeTableObj* hostNodeTableObj;
		ICFIntISOCcyTableObj* iSOCcyTableObj;
		ICFIntISOCtryTableObj* iSOCtryTableObj;
		ICFIntISOCtryCcyTableObj* iSOCtryCcyTableObj;
		ICFIntISOCtryLangTableObj* iSOCtryLangTableObj;
		ICFIntISOLangTableObj* iSOLangTableObj;
		ICFIntISOTZoneTableObj* iSOTZoneTableObj;
		ICFIntLicenseTableObj* licenseTableObj;
		ICFIntMajorVersionTableObj* majorVersionTableObj;
		ICFIntMimeTypeTableObj* mimeTypeTableObj;
		ICFIntMinorVersionTableObj* minorVersionTableObj;
		ICFIntSecAppTableObj* secAppTableObj;
		ICFIntSecDeviceTableObj* secDeviceTableObj;
		ICFIntSecFormTableObj* secFormTableObj;
		ICFIntSecGroupTableObj* secGroupTableObj;
		ICFIntSecGroupFormTableObj* secGroupFormTableObj;
		ICFIntSecGrpIncTableObj* secGrpIncTableObj;
		ICFIntSecGrpMembTableObj* secGrpMembTableObj;
		ICFIntSecSessionTableObj* secSessionTableObj;
		ICFIntSecUserTableObj* secUserTableObj;
		ICFIntServiceTableObj* serviceTableObj;
		ICFIntServiceTypeTableObj* serviceTypeTableObj;
		ICFIntSubProjectTableObj* subProjectTableObj;
		ICFIntSysClusterTableObj* sysClusterTableObj;
		ICFIntTSecGroupTableObj* tSecGroupTableObj;
		ICFIntTSecGrpIncTableObj* tSecGrpIncTableObj;
		ICFIntTSecGrpMembTableObj* tSecGrpMembTableObj;
		ICFIntTenantTableObj* tenantTableObj;
		ICFIntTldTableObj* tldTableObj;
		ICFIntTopDomainTableObj* topDomainTableObj;
		ICFIntTopProjectTableObj* topProjectTableObj;
		ICFIntURLProtocolTableObj* uRLProtocolTableObj;
	public:
		CFIntSchemaObj();

		virtual ~CFIntSchemaObj();

		virtual void setSecClusterName( const std::string& value );
		virtual std::string getSecClusterName();
		virtual cfsec::ICFSecClusterObj* getSecCluster();
		virtual void setSecCluster( cfsec::ICFSecClusterObj* value );
		virtual long getSecClusterId();

		virtual void setSecTenantName( const std::string& value );
		virtual std::string getSecTenantName();
		virtual cfsec::ICFSecTenantObj* getSecTenant();
		virtual void setSecTenant( cfsec::ICFSecTenantObj* value );
		virtual long getSecTenantId();

		virtual void setSecUserName( const std::string& value );
		virtual std::string getSecUserName();
		virtual cfsec::ICFSecSecUserObj* getSecUser();
		virtual void setSecUser( cfsec::ICFSecSecUserObj* value );

		virtual cfsec::ICFSecSecSessionObj* getSecSession();
		virtual void setSecSession( cfsec::ICFSecSecSessionObj* value );
		virtual void setSecSessionId( const uuid_ptr_t value );
		virtual uuid_ptr_t getSecSessionSessionId();
		virtual uuid_ptr_t getSecSessionUserId();

		virtual std::string getDbSchemaName();
		virtual std::string getLowerDbSchemaName();

		virtual void setDbSchemaName( const std::string& argDbSchemaName );

		virtual std::string fileImport( const std::string& fileName, const std::string& fileContent );

		/**
		 *	Release any prepared statements acquired by this connection.
		 *	<p>
		 *	Resets the prepared statements so they can acquire the new value of
		 *	<tt>setDbSchemaName()</tt>.
		 */
		virtual void releasePreparedStatements();

		virtual cfsec::CFSecAuthorization* getAuthorization() const;
		virtual void setAuthorization( cfsec::CFSecAuthorization* value );
		virtual cfsec::ICFSecSchema* getBackingStore();
		virtual void setBackingStore( cfsec::ICFSecSchema* value );
		virtual std::string getSchemaName();
		virtual bool isConnected();
		virtual bool connect();
		virtual bool connect( const std::string& username, const std::string& password );
		virtual bool connect( const std::string& clusterName, const std::string& tenantName, const std::string& secUserName, const std::string& password );
		virtual void disconnect( bool doCommit );
		virtual void logout();
		virtual void minimizeMemory();
		virtual bool isTransactionOpen();
		virtual bool beginTransaction();
		virtual void commit();
		virtual void rollback();

		virtual cfsec::ICFSecClusterTableObj* getClusterTableObj();

		virtual cfsec::ICFSecHostNodeTableObj* getHostNodeTableObj();

		virtual cfsec::ICFSecISOCcyTableObj* getISOCcyTableObj();

		virtual cfsec::ICFSecISOCtryTableObj* getISOCtryTableObj();

		virtual cfsec::ICFSecISOCtryCcyTableObj* getISOCtryCcyTableObj();

		virtual cfsec::ICFSecISOCtryLangTableObj* getISOCtryLangTableObj();

		virtual cfsec::ICFSecISOLangTableObj* getISOLangTableObj();

		virtual cfsec::ICFSecISOTZoneTableObj* getISOTZoneTableObj();

		virtual cfint::ICFIntLicenseTableObj* getLicenseTableObj();

		virtual cfint::ICFIntMajorVersionTableObj* getMajorVersionTableObj();

		virtual cfint::ICFIntMimeTypeTableObj* getMimeTypeTableObj();

		virtual cfint::ICFIntMinorVersionTableObj* getMinorVersionTableObj();

		virtual cfsec::ICFSecSecAppTableObj* getSecAppTableObj();

		virtual cfsec::ICFSecSecDeviceTableObj* getSecDeviceTableObj();

		virtual cfsec::ICFSecSecFormTableObj* getSecFormTableObj();

		virtual cfsec::ICFSecSecGroupTableObj* getSecGroupTableObj();

		virtual cfsec::ICFSecSecGroupFormTableObj* getSecGroupFormTableObj();

		virtual cfsec::ICFSecSecGrpIncTableObj* getSecGrpIncTableObj();

		virtual cfsec::ICFSecSecGrpMembTableObj* getSecGrpMembTableObj();

		virtual cfsec::ICFSecSecSessionTableObj* getSecSessionTableObj();

		virtual cfsec::ICFSecSecUserTableObj* getSecUserTableObj();

		virtual cfsec::ICFSecServiceTableObj* getServiceTableObj();

		virtual cfsec::ICFSecServiceTypeTableObj* getServiceTypeTableObj();

		virtual cfint::ICFIntSubProjectTableObj* getSubProjectTableObj();

		virtual cfsec::ICFSecSysClusterTableObj* getSysClusterTableObj();

		virtual cfsec::ICFSecTSecGroupTableObj* getTSecGroupTableObj();

		virtual cfsec::ICFSecTSecGrpIncTableObj* getTSecGrpIncTableObj();

		virtual cfsec::ICFSecTSecGrpMembTableObj* getTSecGrpMembTableObj();

		virtual cfsec::ICFSecTenantTableObj* getTenantTableObj();

		virtual cfint::ICFIntTldTableObj* getTldTableObj();

		virtual cfint::ICFIntTopDomainTableObj* getTopDomainTableObj();

		virtual cfint::ICFIntTopProjectTableObj* getTopProjectTableObj();

		virtual cfint::ICFIntURLProtocolTableObj* getURLProtocolTableObj();

	};

}
