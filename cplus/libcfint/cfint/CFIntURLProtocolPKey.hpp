#pragma once

// Description: C++18 specification of a URLProtocol primary key object.

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
#include <cfint/ICFIntSchema.hpp>

namespace cfint {

	class CFIntURLProtocolBuff;
	class CFIntURLProtocolHPKey;
	class CFIntURLProtocolHBuff;

	class CFIntURLProtocolPKey
	{
	protected:

		int32_t requiredURLProtocolId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFIntURLProtocolPKey();
		CFIntURLProtocolPKey( const CFIntURLProtocolPKey& src );
		virtual ~CFIntURLProtocolPKey();

		virtual const int32_t getRequiredURLProtocolId() const;
		virtual const int32_t* getRequiredURLProtocolIdReference() const;
		virtual void setRequiredURLProtocolId( const int32_t value );

		bool operator <( const CFIntURLProtocolHPKey& rhs );
		bool operator <( const CFIntURLProtocolPKey& rhs );
		bool operator <( const CFIntURLProtocolHBuff& rhs );
		bool operator <( const CFIntURLProtocolBuff& rhs );

		bool operator <=( const CFIntURLProtocolHPKey& rhs );
		bool operator <=( const CFIntURLProtocolPKey& rhs );
		bool operator <=( const CFIntURLProtocolHBuff& rhs );
		bool operator <=( const CFIntURLProtocolBuff& rhs );

		bool operator ==( const CFIntURLProtocolHPKey& rhs );
		bool operator ==( const CFIntURLProtocolPKey& rhs );
		bool operator ==( const CFIntURLProtocolHBuff& rhs );
		bool operator ==( const CFIntURLProtocolBuff& rhs );

		bool operator !=( const CFIntURLProtocolHPKey& rhs );
		bool operator !=( const CFIntURLProtocolPKey& rhs );
		bool operator !=( const CFIntURLProtocolHBuff& rhs );
		bool operator !=( const CFIntURLProtocolBuff& rhs );

		bool operator >=( const CFIntURLProtocolHPKey& rhs );
		bool operator >=( const CFIntURLProtocolPKey& rhs );
		bool operator >=( const CFIntURLProtocolHBuff& rhs );
		bool operator >=( const CFIntURLProtocolBuff& rhs );

		bool operator >( const CFIntURLProtocolHPKey& rhs );
		bool operator >( const CFIntURLProtocolPKey& rhs );
		bool operator >( const CFIntURLProtocolHBuff& rhs );
		bool operator >( const CFIntURLProtocolBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfint::CFIntURLProtocolPKey operator =( cfint::CFIntURLProtocolPKey& src );
		cfint::CFIntURLProtocolPKey operator =( cfint::CFIntURLProtocolHPKey& src );
		cfint::CFIntURLProtocolPKey operator =( cfint::CFIntURLProtocolBuff& src );
		cfint::CFIntURLProtocolPKey operator =( cfint::CFIntURLProtocolHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator <(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator <=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator ==(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator !=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator >=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator >(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator >(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator >(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator >(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	template<> struct hash<cfint::CFIntURLProtocolPKey> {
		typedef cfint::CFIntURLProtocolPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

