#pragma once

// Description: C++18 specification of a Tld primary key object.

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

	class CFIntTldBuff;
	class CFIntTldHPKey;
	class CFIntTldHBuff;

	class CFIntTldPKey
	{
	protected:

		int64_t requiredTenantId;
		int64_t requiredId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFIntTldPKey();
		CFIntTldPKey( const CFIntTldPKey& src );
		virtual ~CFIntTldPKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		bool operator <( const CFIntTldHPKey& rhs );
		bool operator <( const CFIntTldPKey& rhs );
		bool operator <( const CFIntTldHBuff& rhs );
		bool operator <( const CFIntTldBuff& rhs );

		bool operator <=( const CFIntTldHPKey& rhs );
		bool operator <=( const CFIntTldPKey& rhs );
		bool operator <=( const CFIntTldHBuff& rhs );
		bool operator <=( const CFIntTldBuff& rhs );

		bool operator ==( const CFIntTldHPKey& rhs );
		bool operator ==( const CFIntTldPKey& rhs );
		bool operator ==( const CFIntTldHBuff& rhs );
		bool operator ==( const CFIntTldBuff& rhs );

		bool operator !=( const CFIntTldHPKey& rhs );
		bool operator !=( const CFIntTldPKey& rhs );
		bool operator !=( const CFIntTldHBuff& rhs );
		bool operator !=( const CFIntTldBuff& rhs );

		bool operator >=( const CFIntTldHPKey& rhs );
		bool operator >=( const CFIntTldPKey& rhs );
		bool operator >=( const CFIntTldHBuff& rhs );
		bool operator >=( const CFIntTldBuff& rhs );

		bool operator >( const CFIntTldHPKey& rhs );
		bool operator >( const CFIntTldPKey& rhs );
		bool operator >( const CFIntTldHBuff& rhs );
		bool operator >( const CFIntTldBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfint::CFIntTldPKey operator =( cfint::CFIntTldPKey& src );
		cfint::CFIntTldPKey operator =( cfint::CFIntTldHPKey& src );
		cfint::CFIntTldPKey operator =( cfint::CFIntTldBuff& src );
		cfint::CFIntTldPKey operator =( cfint::CFIntTldHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator <(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator <(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator <(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator <=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator <=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator <=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator <=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator ==(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator ==(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator ==(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator ==(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator !=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator !=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator !=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator !=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator >=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator >=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator >=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator >=(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator >(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator >(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator >(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator >(const  cfint::CFIntTldPKey& lhs, const cfint::CFIntTldBuff& rhs );

	template<> struct hash<cfint::CFIntTldPKey> {
		typedef cfint::CFIntTldPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

