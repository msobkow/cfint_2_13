#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for MimeType.

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
#include <cfintsaxloader/CFIntSaxLoader.hpp>

namespace cfint {

	class CFIntRamMimeTypeTable
	: public virtual cfint::ICFIntMimeTypeTable
	{
	protected:
		cfint::ICFIntSchema* schema;
		std::map<cfint::CFIntMimeTypePKey,
			cfint::CFIntMimeTypeBuff*>* dictByPKey;
		std::map<cfint::CFIntMimeTypeByUNameIdxKey,
			cfint::CFIntMimeTypeBuff*>* dictByUNameIdx;
	public:
		static const std::string CLASS_NAME;
		CFIntRamMimeTypeTable( cfint::ICFIntSchema* argSchema );

		virtual ~CFIntRamMimeTypeTable();

		virtual cfint::CFIntMimeTypeBuff* createMimeType( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMimeTypeBuff* Buff );

		virtual cfint::CFIntMimeTypeBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypePKey* PKey );

		virtual cfint::CFIntMimeTypeBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypePKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntMimeTypeBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual cfint::CFIntMimeTypeBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t MimeTypeId );

		virtual cfint::CFIntMimeTypeBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypePKey* PKey );

		virtual cfint::CFIntMimeTypeBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypePKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntMimeTypeBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntMimeTypeBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t MimeTypeId );

		virtual cfint::CFIntMimeTypeBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual cfint::CFIntMimeTypeBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntMimeTypeBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntMimeTypeBuff* updateMimeType( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMimeTypeBuff* Buff );

		virtual void deleteMimeType( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntMimeTypeBuff* Buff );
		virtual void deleteMimeTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argMimeTypeId );

		virtual void deleteMimeTypeByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypePKey* argKey );

		virtual void deleteMimeTypeByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName );

		virtual void deleteMimeTypeByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntMimeTypeByUNameIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
