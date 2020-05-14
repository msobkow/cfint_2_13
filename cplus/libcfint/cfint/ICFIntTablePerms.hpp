#pragma once

// Description: C++18 CFInt Table Permissions Interface.

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

#include <uuid/uuid.h>

#include <array>
#include <cassert>
#include <cstddef>
#include <chrono>
#include <ctime>
#include <functional>
#include <list>
#include <string>

#include <cfsec/ICFSecTablePerms.hpp>

namespace cfint {

	class CFIntAuthorization;

	class ICFIntTablePerms
	: public virtual cfsec::ICFSecTablePerms
	{
	public:
		ICFIntTablePerms();
		virtual ~ICFIntTablePerms();

		virtual bool allowCreateLicense( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadLicense( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateLicense( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteLicense( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateMajorVersion( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadMajorVersion( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateMajorVersion( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteMajorVersion( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateMimeType( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadMimeType( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateMimeType( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteMimeType( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateMinorVersion( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadMinorVersion( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateMinorVersion( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteMinorVersion( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateSubProject( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadSubProject( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateSubProject( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteSubProject( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateTld( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadTld( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateTld( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteTld( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateTopDomain( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadTopDomain( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateTopDomain( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteTopDomain( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateTopProject( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadTopProject( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateTopProject( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteTopProject( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual bool allowCreateURLProtocol( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowReadURLProtocol( const cfsec::CFSecAuthorization Authorization ) = 0;
		virtual bool allowUpdateURLProtocol( const cfsec::CFSecAuthorization* Authorization ) = 0;
		virtual bool allowDeleteURLProtocol( const cfsec::CFSecAuthorization* Authorization ) = 0;
	};
}
