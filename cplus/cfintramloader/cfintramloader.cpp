// Description: C++18 Implementation of a RAM CFInt loader.

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
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintobj/CFIntSchemaObj.hpp>
#include <cfintsaxloader/CFIntSaxLoaderPublic.hpp>
#include <cfintram/CFIntRamSchema.hpp>
#include <CFIntRamLdr.hpp>

static const std::string CLASS_NAME( "CFIntRamLoader" );

int main( int argc, char* argv[] ) {

	if( argc < 1 ) {
		std::cerr << CLASS_NAME + " ERROR: Program name is not available\n";
		return( 1 );
	}
	std::string S_ProcName( argv[0] );
	static const std::string S_System( "system" );
	CFLIB_EXCEPTION_DECLINFO

	cflib::CFLib::init();

	int retval = 0;

	cfint::ICFIntSchema* cFIntSchema = NULL;
	cfint::ICFIntSchemaObj* cFIntSchemaObj = NULL;
	cfint::CFIntRamLdr* cli = NULL;
	cfint::CFIntSaxLoader* loader = NULL;
	cfsec::CFSecAuthorization* auth = NULL;
	std::string* loaderOpts = NULL;
	std::string* url = NULL;
	if( argc >= 3 ) {
		try {
			cFIntSchema = new cfint::CFIntRamSchema();
			cFIntSchemaObj = new cfint::CFIntSchemaObj();
			cFIntSchemaObj->setBackingStore( cFIntSchema );
			cli = new cfint::CFIntRamLdr();
			loader = cli->getSaxLoader();
			loader->setSchemaObj( cFIntSchemaObj );
			loaderOpts = new std::string( argv[1] );
			url = new std::string( argv[2] );
			cFIntSchema->connect( S_System, S_System, S_System, S_System );
			cFIntSchema->rollback();
			cFIntSchema->beginTransaction();
			cFIntSchemaObj->setSecCluster( cFIntSchemaObj->getClusterTableObj()->getSystemCluster() );
			cFIntSchemaObj->setSecTenant( cFIntSchemaObj->getTenantTableObj()->getSystemTenant() );
			cFIntSchemaObj->setSecSession( cFIntSchemaObj->getSecSessionTableObj()->getSystemSession() );
			auth = new cfsec::CFSecAuthorization();
			auth->setSecCluster( *(cFIntSchemaObj->getSecCluster()) );
			auth->setSecTenant( *(cFIntSchemaObj->getSecTenant()) );
			auth->setSecSession( cFIntSchemaObj->getSecSession() );
			cFIntSchemaObj->setAuthorization( auth );
			cli->applyLoaderOptions( loader, *loaderOpts );
			cli->evaluateRemainingArgs( argc, argv, 3 );
			loader->setUseCluster( cFIntSchemaObj->getSecCluster() );
			loader->setUseTenant( cFIntSchemaObj->getSecTenant() );
			loader->parseFile( *url );
			cFIntSchema->commit();
			cFIntSchema->disconnect( true );
		}
		CFLIB_EXCEPTION_CATCH_FALLTHROUGH
		if( ! CFLIB_EXCEPTION_EMPTY ) {
			std::cerr << S_ProcName + " SAXParseException : Could not parse XML file \"" + *url + "\": " + CFLIB_EXCEPTION_FORMATTEDMESSAGE + "\n";
		}
		if( ( cFIntSchema != NULL ) && cFIntSchema->isConnected() ) {
			try {
				cFIntSchema->rollback();
			}
			catch ( ... ) {
			}
			try {
				cFIntSchema->disconnect( false );
			}
			catch( ... ) {
			}
		}
		if( loader != NULL ) {
			loader->setSchemaObj( NULL );
			loader = NULL;
		}
		if( cli != NULL ) {
			delete cli;
			cli = NULL;
		}
		if( cFIntSchemaObj != NULL ) {
			cFIntSchemaObj->setBackingStore( NULL );
			try {
				delete cFIntSchemaObj;
			}
			catch( ... ) {
			}
			cFIntSchemaObj = NULL;
		}
		if( cFIntSchema != NULL ) {
			if( cFIntSchema->isConnected() ) {
				try {
					cFIntSchema->rollback();
				}
				catch ( ... ) {
				}
				try {
					cFIntSchema->disconnect( false );
				}
				catch( ... ) {
				}
			}
			try {
				delete cFIntSchema;
			}
			catch( ... ) {
			}
			cFIntSchema = NULL;
		}
	}
	else {
		std::cerr << S_ProcName + " ERROR: Expected at least two argument specifying the loader options and the name of the XML file to parse.  The first argument may be empty.\n";
	}

	if( auth != NULL ) {
		delete auth;
		auth = NULL;
	}

	if( url != NULL ) {
		delete url;
		url = NULL;
	}

	if( loaderOpts != NULL ) {
		delete loaderOpts;
		loaderOpts = NULL;
	}

	try {
		cflib::CFLib::release();
	}
	catch( ... ) {
	}

	return( retval );
}
