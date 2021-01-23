// Description: C++18 implementation of a CFInt schema pool.

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

using namespace std;

#include <cfint/CFIntSchemaPool.hpp>

namespace cfint {

	const std::string CFIntSchemaPool::CLASS_NAME( "CFIntSchemaPool" );
	CFIntSchemaPool::CFIntSchemaPool()
	: cfsec::CFSecSchemaPool()
	{
	}

	CFIntSchemaPool::~CFIntSchemaPool() {
	}

	void CFIntSchemaPool::setConfigurationFile( cfsec::CFSecConfigurationFile* value ) {
		
		if( configFile != NULL ) {
			delete configFile;
			configFile = NULL;
		}
		configFile = value;
	}

	void CFIntSchemaPool::setSchemaPool( cfsec::CFSecSchemaPool* pool ) {
		if( getSetStaticSchemaPool( NULL ) == NULL ) {
			getSetStaticSchemaPool( pool );
		}

	}

}
