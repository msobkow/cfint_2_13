#pragma once

// Description: C++18 CFInt Table Permissions Interface.

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
