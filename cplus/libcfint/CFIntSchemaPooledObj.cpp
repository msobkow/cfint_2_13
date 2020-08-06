// Description: C++18 Schema Pooled Object implementation for CFInt.

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

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfintobj/CFIntSchemaObj.hpp>
#include <cfintobj/CFIntSchemaPooledObj.hpp>

#include <cfintobj/ICFIntClusterObj.hpp>
#include <cfintobj/ICFIntHostNodeObj.hpp>
#include <cfintobj/ICFIntISOCcyObj.hpp>
#include <cfintobj/ICFIntISOCtryObj.hpp>
#include <cfintobj/ICFIntISOCtryCcyObj.hpp>
#include <cfintobj/ICFIntISOCtryLangObj.hpp>
#include <cfintobj/ICFIntISOLangObj.hpp>
#include <cfintobj/ICFIntISOTZoneObj.hpp>
#include <cfintobj/ICFIntSecAppObj.hpp>
#include <cfintobj/ICFIntSecDeviceObj.hpp>
#include <cfintobj/ICFIntSecFormObj.hpp>
#include <cfintobj/ICFIntSecGroupObj.hpp>
#include <cfintobj/ICFIntSecGroupFormObj.hpp>
#include <cfintobj/ICFIntSecGrpIncObj.hpp>
#include <cfintobj/ICFIntSecGrpMembObj.hpp>
#include <cfintobj/ICFIntSecSessionObj.hpp>
#include <cfintobj/ICFIntSecUserObj.hpp>
#include <cfintobj/ICFIntServiceObj.hpp>
#include <cfintobj/ICFIntServiceTypeObj.hpp>
#include <cfintobj/ICFIntSysClusterObj.hpp>
#include <cfintobj/ICFIntTenantObj.hpp>
#include <cfintobj/ICFIntTSecGroupObj.hpp>
#include <cfintobj/ICFIntTSecGrpIncObj.hpp>
#include <cfintobj/ICFIntTSecGrpMembObj.hpp>
#include <cfintobj/ICFIntLicenseObj.hpp>
#include <cfintobj/ICFIntMajorVersionObj.hpp>
#include <cfintobj/ICFIntMimeTypeObj.hpp>
#include <cfintobj/ICFIntMinorVersionObj.hpp>
#include <cfintobj/ICFIntSubProjectObj.hpp>
#include <cfintobj/ICFIntTldObj.hpp>
#include <cfintobj/ICFIntTopDomainObj.hpp>
#include <cfintobj/ICFIntTopProjectObj.hpp>
#include <cfintobj/ICFIntURLProtocolObj.hpp>

#include <cfintobj/ICFIntClusterTableObj.hpp>
#include <cfintobj/ICFIntHostNodeTableObj.hpp>
#include <cfintobj/ICFIntISOCcyTableObj.hpp>
#include <cfintobj/ICFIntISOCtryTableObj.hpp>
#include <cfintobj/ICFIntISOCtryCcyTableObj.hpp>
#include <cfintobj/ICFIntISOCtryLangTableObj.hpp>
#include <cfintobj/ICFIntISOLangTableObj.hpp>
#include <cfintobj/ICFIntISOTZoneTableObj.hpp>
#include <cfintobj/ICFIntSecAppTableObj.hpp>
#include <cfintobj/ICFIntSecDeviceTableObj.hpp>
#include <cfintobj/ICFIntSecFormTableObj.hpp>
#include <cfintobj/ICFIntSecGroupTableObj.hpp>
#include <cfintobj/ICFIntSecGroupFormTableObj.hpp>
#include <cfintobj/ICFIntSecGrpIncTableObj.hpp>
#include <cfintobj/ICFIntSecGrpMembTableObj.hpp>
#include <cfintobj/ICFIntSecSessionTableObj.hpp>
#include <cfintobj/ICFIntSecUserTableObj.hpp>
#include <cfintobj/ICFIntServiceTableObj.hpp>
#include <cfintobj/ICFIntServiceTypeTableObj.hpp>
#include <cfintobj/ICFIntSysClusterTableObj.hpp>
#include <cfintobj/ICFIntTenantTableObj.hpp>
#include <cfintobj/ICFIntTSecGroupTableObj.hpp>
#include <cfintobj/ICFIntTSecGrpIncTableObj.hpp>
#include <cfintobj/ICFIntTSecGrpMembTableObj.hpp>
#include <cfintobj/ICFIntLicenseTableObj.hpp>
#include <cfintobj/ICFIntMajorVersionTableObj.hpp>
#include <cfintobj/ICFIntMimeTypeTableObj.hpp>
#include <cfintobj/ICFIntMinorVersionTableObj.hpp>
#include <cfintobj/ICFIntSubProjectTableObj.hpp>
#include <cfintobj/ICFIntTldTableObj.hpp>
#include <cfintobj/ICFIntTopDomainTableObj.hpp>
#include <cfintobj/ICFIntTopProjectTableObj.hpp>
#include <cfintobj/ICFIntURLProtocolTableObj.hpp>

namespace cfint {

	const std::string CFIntSchemaPooledObj::CLASS_NAME( "CFIntSchemaPooledObj" );

	CFIntSchemaPooledObj::CFIntSchemaPooledObj()
	: cfint::CFIntSchemaObj()
	{
	}

	CFIntSchemaPooledObj::~CFIntSchemaPooledObj() {
	}

	bool CFIntSchemaPooledObj::isConnected() {
		if( backingStore == NULL ) {
			return( false );
		}
		else {
			return( true );
		}
	}

	void CFIntSchemaPooledObj::disconnect( bool doCommit ) {
		static const std::string S_ProcName( "disconnect" );
		static const std::string S_Message( "Schema objects over pooled storage cannot be explicitly disconnected" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntSchemaPooledObj::logout() {
		if( ( authorization == NULL ) || ( backingStore == NULL ) ) {
			return;
		}
		try {
			bool transactionStarted = beginTransaction();
			if( ! transactionStarted ) {
				rollback();
				transactionStarted = beginTransaction();
				if( ! transactionStarted ) {
					setAuthorization( NULL );
					return;
				}
			}
			const uuid_ptr_t secSessionId = authorization->getSecSessionId();
			if( ( secSessionId[0] != 0 )
				|| ( secSessionId[1] != 0 )
				|| ( secSessionId[2] != 0 )
				|| ( secSessionId[3] != 0 )
				|| ( secSessionId[4] != 0 )
				|| ( secSessionId[5] != 0 )
				|| ( secSessionId[6] != 0 )
				|| ( secSessionId[7] != 0 )
				|| ( secSessionId[8] != 0 )
				|| ( secSessionId[9] != 0 )
				|| ( secSessionId[10] != 0 )
				|| ( secSessionId[11] != 0 )
				|| ( secSessionId[12] != 0 )
				|| ( secSessionId[13] != 0 )
				|| ( secSessionId[14] != 0 )
				|| ( secSessionId[15] != 0 ) )
			{
				cfsec::ICFSecSecSessionObj* secSession = getSecSessionTableObj()->readSecSessionByIdIdx( secSessionId );
				if( secSession != NULL ) {
					if( secSession->isOptionalFinishNull() ) {
						cfsec::ICFSecSecSessionEditObj* editSecSession = secSession->beginEdit();
						std::chrono::system_clock::time_point timestamp = cflib::CFLib::getUTCTimestampInstance();
						editSecSession->setOptionalFinishValue( timestamp );
						editSecSession->update();
						editSecSession = NULL;
					}
				}
			}
			commit();
		}
		catch( xercesc::SAXNotRecognizedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( xercesc::SAXNotSupportedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( xercesc::SAXParseException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( xercesc::SAXException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibArgumentOverflowException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibArgumentRangeException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibArgumentUnderflowException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibCollisionDetectedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibDbException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibDependentsDetectedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibEmptyArgumentException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibInvalidArgumentException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibMathException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibMustOverrideException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibNotImplementedYetException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibNotSupportedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibNullArgumentException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibPrimaryKeyNotNewException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibStaleCacheDetectedException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibSubroutineException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibUniqueIndexViolationException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibUnrecognizedAttributeException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibUnresolvedRelationException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibUnsupportedClassException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibUsageException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibArgumentException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( cflib::CFLibRuntimeException x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
		catch( std::exception x ) {
			setAuthorization( NULL );
			minimizeMemory();
			throw x;
		}
	}

}

