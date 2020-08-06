#pragma once

// Description: C++18 DbIO interface for MimeType.

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
#include <cfsec/CFSecAuthorization.hpp>
#include <cfint/CFIntHPKey.hpp>
#include <cfint/CFIntMimeTypeBuff.hpp>
#include <cfint/CFIntMimeTypePKey.hpp>
#include <cfint/CFIntMimeTypeHBuff.hpp>
#include <cfint/CFIntMimeTypeHPKey.hpp>
#include <cfint/CFIntMimeTypeByUNameIdxKey.hpp>

namespace cfint {
	class ICFIntSchemaObj;
}

namespace cfint {
	class ICFIntMimeTypeObj;

	class ICFIntMimeTypeTable
	{
	public:
		ICFIntMimeTypeTable();
		virtual ~ICFIntMimeTypeTable();

		virtual cfint::CFIntMimeTypeBuff* createMimeType( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMimeTypeBuff* Buff ) = 0;

		virtual cfint::CFIntMimeTypeBuff* updateMimeType( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMimeTypeBuff* Buff ) = 0;

		virtual void deleteMimeType( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMimeTypeBuff* Buff ) = 0;
		virtual void deleteMimeTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argMimeTypeId ) = 0;

		virtual void deleteMimeTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypePKey* argKey ) = 0;
		virtual void deleteMimeTypeByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName ) = 0;

		virtual void deleteMimeTypeByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypeByUNameIdxKey* argKey ) = 0;

		virtual cfint::CFIntMimeTypeBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypePKey* PKey ) = 0;

		virtual cfint::CFIntMimeTypeBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntMimeTypeBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t MimeTypeId ) = 0;

		virtual cfint::CFIntMimeTypeBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name ) = 0;

		virtual cfint::CFIntMimeTypeBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypePKey* PKey ) = 0;

		virtual cfint::CFIntMimeTypeBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypePKey* PKey ) = 0;

		virtual std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization ) = 0;

		virtual cfint::CFIntMimeTypeBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t MimeTypeId ) = 0;

		virtual cfint::CFIntMimeTypeBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name ) = 0;

		virtual cfint::CFIntMimeTypeBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual cfint::CFIntMimeTypeBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
			bool forceRead = false ) = 0;

		virtual void releasePreparedStatements() = 0;
	};
}
