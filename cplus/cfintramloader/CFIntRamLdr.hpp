#pragma once

// Description: C++18 Command Line Object Interface for CFInt RAM Loader

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

#include <cflib/ICFLibPublic.hpp>
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintsaxloader/CFIntSaxLdr.hpp>
#include <cfintsaxloader/CFIntSaxLoader.hpp>
#include <cfintram/CFIntRamSchema.hpp>

namespace cfint {

	class CFIntRamLdr
	: public cfint::CFIntSaxLdr
	{
	private:
		static cflib::ICFLibMessageLog* log;

	public:

	CFIntRamLdr();
	virtual ~CFIntRamLdr();


	void evaluateRemainingArgs( size_t argc, char* argv[], size_t consumed );

	};
}
