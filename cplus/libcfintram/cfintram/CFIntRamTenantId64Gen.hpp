#pragma once

// Description: C++18 Interface of a Tenant 64-bit in-memory RAM Id Generator object.

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
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>

namespace cfint {

	class CFIntRamTenantId64Gen
	{
	protected:
		int64_t requiredId;
		int16_t sliceId = 0;
		int64_t nextId = 1;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
	CFIntRamTenantId64Gen();
	~CFIntRamTenantId64Gen();

		int64_t getNextId();
		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

	int16_t getRequiredSliceId() const;
	void setRequiredSliceId( int16_t value );

	size_t hashCode() const;

		bool operator <( const cfint::CFIntRamTenantId64Gen& rhs );

		bool operator <=( const cfint::CFIntRamTenantId64Gen& rhs );

		bool operator ==( const cfint::CFIntRamTenantId64Gen& rhs );

		bool operator !=( const cfint::CFIntRamTenantId64Gen& rhs );

		bool operator >=( const cfint::CFIntRamTenantId64Gen& rhs );

		bool operator >( const cfint::CFIntRamTenantId64Gen& rhs );
		CFIntRamTenantId64Gen operator =( CFIntRamTenantId64Gen& src );

	};
}

namespace std {

	bool operator <(const cfint::CFIntRamTenantId64Gen& lhs, const cfint::CFIntRamTenantId64Gen& rhs );

	bool operator <=(const cfint::CFIntRamTenantId64Gen& lhs, const cfint::CFIntRamTenantId64Gen& rhs );

	bool operator ==(const cfint::CFIntRamTenantId64Gen& lhs, const cfint::CFIntRamTenantId64Gen& rhs );

	bool operator !=(const cfint::CFIntRamTenantId64Gen& lhs, const cfint::CFIntRamTenantId64Gen& rhs );

	bool operator >=(const cfint::CFIntRamTenantId64Gen& lhs, const cfint::CFIntRamTenantId64Gen& rhs );

	bool operator >(const cfint::CFIntRamTenantId64Gen& lhs, const cfint::CFIntRamTenantId64Gen& rhs );

	template<> struct hash<cfint::CFIntRamTenantId64Gen> {
		typedef cfint::CFIntRamTenantId64Gen argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};


}
