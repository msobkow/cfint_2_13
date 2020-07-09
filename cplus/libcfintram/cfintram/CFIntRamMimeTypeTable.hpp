#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for MimeType.

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
