#pragma once

// Description: C++18 DbIO interface for URLProtocol.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfint/CFIntHPKey.hpp>
#include <cfint/CFIntURLProtocolBuff.hpp>
#include <cfint/CFIntURLProtocolPKey.hpp>
#include <cfint/CFIntURLProtocolHBuff.hpp>
#include <cfint/CFIntURLProtocolHPKey.hpp>
#include <cfint/CFIntURLProtocolByUNameIdxKey.hpp>
#include <cfint/CFIntURLProtocolByIsSecureIdxKey.hpp>

namespace cfint {
	class ICFIntSchemaObj;
}

namespace cfint {
	class ICFIntURLProtocolObj;

	class ICFIntURLProtocolTable
	{
	public:
		ICFIntURLProtocolTable();
		virtual ~ICFIntURLProtocolTable();

		virtual cfint::CFIntURLProtocolBuff* createURLProtocol( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntURLProtocolBuff* Buff ) = 0;

		virtual cfint::CFIntURLProtocolBuff* updateURLProtocol( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntURLProtocolBuff* Buff ) = 0;

		virtual void deleteURLProtocol( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntURLProtocolBuff* Buff ) = 0;
		virtual void deleteURLProtocolByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argURLProtocolId ) = 0;

		virtual void deleteURLProtocolByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolPKey* argKey ) = 0;
		virtual void deleteURLProtocolByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName ) = 0;

		virtual void deleteURLProtocolByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolByUNameIdxKey* argKey ) = 0;
		virtual void deleteURLProtocolByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
			const bool argIsSecure ) = 0;

		virtual void deleteURLProtocolByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolByIsSecureIdxKey* argKey ) = 0;

		virtual cfint::CFIntURLProtocolBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolPKey* PKey ) = 0;

		virtual cfint::CFIntURLProtocolBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntURLProtocolBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t URLProtocolId ) = 0;

		virtual cfint::CFIntURLProtocolBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> readDerivedByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
			const bool IsSecure ) = 0;

		virtual cfint::CFIntURLProtocolBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolPKey* PKey ) = 0;

		virtual cfint::CFIntURLProtocolBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolPKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntURLProtocolBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t URLProtocolId ) = 0;

		virtual cfint::CFIntURLProtocolBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> readBuffByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
			const bool IsSecure ) = 0;

		virtual cfint::CFIntURLProtocolBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::CFIntURLProtocolBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
