#pragma once

// Description: C++18 specification for a TopDomain by TenantIdx index key object.

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

	class CFIntTopDomainBuff;
	class CFIntTopDomainHBuff;

	class CFIntTopDomainByTenantIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredTenantId;
	public:
		CFIntTopDomainByTenantIdxKey();
		CFIntTopDomainByTenantIdxKey( const CFIntTopDomainByTenantIdxKey& src );
		virtual ~CFIntTopDomainByTenantIdxKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator <( const CFIntTopDomainHBuff& rhs );
		bool operator <( const CFIntTopDomainBuff& rhs );

		bool operator <=( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator <=( const CFIntTopDomainHBuff& rhs );
		bool operator <=( const CFIntTopDomainBuff& rhs );

		bool operator ==( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator ==( const CFIntTopDomainHBuff& rhs );
		bool operator ==( const CFIntTopDomainBuff& rhs );

		bool operator !=( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator !=( const CFIntTopDomainHBuff& rhs );
		bool operator !=( const CFIntTopDomainBuff& rhs );

		bool operator >=( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator >=( const CFIntTopDomainHBuff& rhs );
		bool operator >=( const CFIntTopDomainBuff& rhs );

		bool operator >( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator >( const CFIntTopDomainHBuff& rhs );
		bool operator >( const CFIntTopDomainBuff& rhs );
		cfint::CFIntTopDomainByTenantIdxKey operator =( cfint::CFIntTopDomainByTenantIdxKey& src );
		cfint::CFIntTopDomainByTenantIdxKey operator =( cfint::CFIntTopDomainBuff& src );
		cfint::CFIntTopDomainByTenantIdxKey operator =( cfint::CFIntTopDomainHBuff& src );
};
}

namespace std {

	bool operator <(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );
	bool operator <(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator <(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs );

	bool operator <=(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );
	bool operator <=(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator <=(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs );

	bool operator ==(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );
	bool operator ==(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator ==(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs );

	bool operator !=(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );
	bool operator !=(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator !=(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs );

	bool operator >=(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );
	bool operator >=(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator >=(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs );

	bool operator >(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );
	bool operator >(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator >(const  cfint::CFIntTopDomainByTenantIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs );

	template<> struct hash<cfint::CFIntTopDomainByTenantIdxKey> {
		typedef cfint::CFIntTopDomainByTenantIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

