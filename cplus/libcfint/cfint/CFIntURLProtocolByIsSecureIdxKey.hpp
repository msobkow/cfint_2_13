#pragma once

// Description: C++18 specification for a URLProtocol by IsSecureIdx index key object.

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
#include <cfint/ICFIntSchema.hpp>

namespace cfint {

	class CFIntURLProtocolBuff;
	class CFIntURLProtocolHBuff;

	class CFIntURLProtocolByIsSecureIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		bool requiredIsSecure;
	public:
		CFIntURLProtocolByIsSecureIdxKey();
		CFIntURLProtocolByIsSecureIdxKey( const CFIntURLProtocolByIsSecureIdxKey& src );
		virtual ~CFIntURLProtocolByIsSecureIdxKey();

		virtual const bool getRequiredIsSecure() const;
		virtual const bool* getRequiredIsSecureReference() const;
		virtual void setRequiredIsSecure( const bool value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator <( const CFIntURLProtocolHBuff& rhs );
		bool operator <( const CFIntURLProtocolBuff& rhs );

		bool operator <=( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator <=( const CFIntURLProtocolHBuff& rhs );
		bool operator <=( const CFIntURLProtocolBuff& rhs );

		bool operator ==( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator ==( const CFIntURLProtocolHBuff& rhs );
		bool operator ==( const CFIntURLProtocolBuff& rhs );

		bool operator !=( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator !=( const CFIntURLProtocolHBuff& rhs );
		bool operator !=( const CFIntURLProtocolBuff& rhs );

		bool operator >=( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator >=( const CFIntURLProtocolHBuff& rhs );
		bool operator >=( const CFIntURLProtocolBuff& rhs );

		bool operator >( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator >( const CFIntURLProtocolHBuff& rhs );
		bool operator >( const CFIntURLProtocolBuff& rhs );
		cfint::CFIntURLProtocolByIsSecureIdxKey operator =( cfint::CFIntURLProtocolByIsSecureIdxKey& src );
		cfint::CFIntURLProtocolByIsSecureIdxKey operator =( cfint::CFIntURLProtocolBuff& src );
		cfint::CFIntURLProtocolByIsSecureIdxKey operator =( cfint::CFIntURLProtocolHBuff& src );
};
}

namespace std {

	bool operator <(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator <(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator <=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator ==(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator !=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator >=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator >(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator >(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator >(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	template<> struct hash<cfint::CFIntURLProtocolByIsSecureIdxKey> {
		typedef cfint::CFIntURLProtocolByIsSecureIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

