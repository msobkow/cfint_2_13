// Description: C++18 Command Line Object Implementation for CFInt RAM Loader

/*
 *	org.msscf.msscf.CFInt
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

#include <cflib/ICFLibPublic.hpp>
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintobj/CFIntSchemaObj.hpp>
#include <cfintsaxloader/CFIntSaxLoaderPublic.hpp>
#include <cfintram/CFIntRamSchema.hpp>
#include <CFIntRamLdr.hpp>

using namespace std;

namespace cfint {

	cflib::ICFLibMessageLog* CFIntRamLdr::log = new cflib::CFLibConsoleMessageLog();

	CFIntRamLdr::CFIntRamLdr()
	: cfint::CFIntSaxLdr( log )
	{
	}

	CFIntRamLdr::~CFIntRamLdr() {
	}


	void CFIntRamLdr::evaluateRemainingArgs( size_t argc, char* argv[], size_t consumed ) {
		// There are no extra arguments for the RAM "database" instance
		if( argc > consumed ) {
			if( log != NULL ) {
				log->message( "CFIntRamLdr.evaluateRemainingArgs() WARNING No extra arguments are expected for a RAM database instance, but "
					+ cflib::CFLibXmlUtil::formatInt64( (int64_t)( argc - consumed ) )
					+ " extra arguments were specified.  Extra arguments ignored." );
			}
			else {
				std::cerr << "CFIntRamLdr.evaluateRemainingArgs() WARNING No extra arguments are expected for a RAM database instance, but "
					+ cflib::CFLibXmlUtil::formatInt64( (int64_t)( argc - consumed ) )
					+ " extra arguments were specified.  Extra arguments ignored.\n";
			}
		}
	}

}
