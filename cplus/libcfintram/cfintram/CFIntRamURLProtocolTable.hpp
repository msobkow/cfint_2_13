#pragma once

// Description: C++18 Interface for an in-memory RAM DbIO declementation for URLProtocol.

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

	class CFIntRamURLProtocolTable
	: public virtual cfint::ICFIntURLProtocolTable
	{
	protected:
		cfint::ICFIntSchema* schema;
		std::map<cfint::CFIntURLProtocolPKey,
			cfint::CFIntURLProtocolBuff*>* dictByPKey;
		std::map<cfint::CFIntURLProtocolByUNameIdxKey,
			cfint::CFIntURLProtocolBuff*>* dictByUNameIdx;
		std::map<cfint::CFIntURLProtocolByIsSecureIdxKey,
			std::map<cfint::CFIntURLProtocolPKey,
				cfint::CFIntURLProtocolBuff*>*>* dictByIsSecureIdx;
	public:
		static const std::string CLASS_NAME;
		CFIntRamURLProtocolTable( cfint::ICFIntSchema* argSchema );

		virtual ~CFIntRamURLProtocolTable();

		virtual cfint::CFIntURLProtocolBuff* createURLProtocol( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntURLProtocolBuff* Buff );

		virtual cfint::CFIntURLProtocolBuff* readDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolPKey* PKey );

		virtual cfint::CFIntURLProtocolBuff* lockDerived( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> readAllDerived( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntURLProtocolBuff* readDerivedByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> readDerivedByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
			const bool IsSecure );

		virtual cfint::CFIntURLProtocolBuff* readDerivedByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t URLProtocolId );

		virtual cfint::CFIntURLProtocolBuff* readBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolPKey* PKey );

		virtual cfint::CFIntURLProtocolBuff* lockBuff( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolPKey* PKey );

		virtual std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> readAllBuff( const cfsec::CFSecAuthorization* Authorization );

		virtual cfint::CFIntURLProtocolBuff* readBuffByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t URLProtocolId );

		virtual cfint::CFIntURLProtocolBuff* readBuffByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& Name );

		virtual std::TCFLibOwningVector<cfint::CFIntURLProtocolBuff*> readBuffByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
			const bool IsSecure );

		virtual cfint::CFIntURLProtocolBuff* readBuffByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntURLProtocolBuff* readDerivedByLookupUNameIdx( const cfsec::CFSecAuthorization* Authorization, const std::string& Name,
			bool forceRead = false );

		virtual cfint::CFIntURLProtocolBuff* updateURLProtocol( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntURLProtocolBuff* Buff );

		virtual void deleteURLProtocol( const cfsec::CFSecAuthorization* Authorization,
			cfint::CFIntURLProtocolBuff* Buff );
		virtual void deleteURLProtocolByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const int32_t argURLProtocolId );

		virtual void deleteURLProtocolByIdIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolPKey* argKey );

		virtual void deleteURLProtocolByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const std::string& argName );

		virtual void deleteURLProtocolByUNameIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolByUNameIdxKey* argKey );

		virtual void deleteURLProtocolByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
			const bool argIsSecure );

		virtual void deleteURLProtocolByIsSecureIdx( const cfsec::CFSecAuthorization* Authorization,
			const cfint::CFIntURLProtocolByIsSecureIdxKey* argKey );


		virtual void releasePreparedStatements();

	};
}
