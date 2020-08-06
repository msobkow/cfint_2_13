// Description: C++18 Command Line Object Implementation for CFInt RAM Loader

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
