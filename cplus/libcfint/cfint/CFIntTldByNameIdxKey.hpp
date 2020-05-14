#pragma once

// Description: C++18 specification for a Tld by NameIdx index key object.

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

	class CFIntTldBuff;
	class CFIntTldHBuff;

	class CFIntTldByNameIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredTenantId;
		std::string* requiredName;
	public:
		CFIntTldByNameIdxKey();
		CFIntTldByNameIdxKey( const CFIntTldByNameIdxKey& src );
		virtual ~CFIntTldByNameIdxKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFIntTldByNameIdxKey& rhs );
		bool operator <( const CFIntTldHBuff& rhs );
		bool operator <( const CFIntTldBuff& rhs );

		bool operator <=( const CFIntTldByNameIdxKey& rhs );
		bool operator <=( const CFIntTldHBuff& rhs );
		bool operator <=( const CFIntTldBuff& rhs );

		bool operator ==( const CFIntTldByNameIdxKey& rhs );
		bool operator ==( const CFIntTldHBuff& rhs );
		bool operator ==( const CFIntTldBuff& rhs );

		bool operator !=( const CFIntTldByNameIdxKey& rhs );
		bool operator !=( const CFIntTldHBuff& rhs );
		bool operator !=( const CFIntTldBuff& rhs );

		bool operator >=( const CFIntTldByNameIdxKey& rhs );
		bool operator >=( const CFIntTldHBuff& rhs );
		bool operator >=( const CFIntTldBuff& rhs );

		bool operator >( const CFIntTldByNameIdxKey& rhs );
		bool operator >( const CFIntTldHBuff& rhs );
		bool operator >( const CFIntTldBuff& rhs );
		cfint::CFIntTldByNameIdxKey operator =( cfint::CFIntTldByNameIdxKey& src );
		cfint::CFIntTldByNameIdxKey operator =( cfint::CFIntTldBuff& src );
		cfint::CFIntTldByNameIdxKey operator =( cfint::CFIntTldHBuff& src );
};
}

namespace std {

	bool operator <(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator <(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator <=(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator <=(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator ==(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator ==(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator !=(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator !=(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator >=(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator >=(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator >(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator >(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator >(const  cfint::CFIntTldByNameIdxKey& lhs, const cfint::CFIntTldBuff& rhs );

	template<> struct hash<cfint::CFIntTldByNameIdxKey> {
		typedef cfint::CFIntTldByNameIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

