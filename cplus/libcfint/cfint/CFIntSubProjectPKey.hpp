#pragma once

// Description: C++18 specification of a SubProject primary key object.

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

	class CFIntSubProjectBuff;
	class CFIntSubProjectHPKey;
	class CFIntSubProjectHBuff;

	class CFIntSubProjectPKey
	{
	protected:

		int64_t requiredTenantId;
		int64_t requiredId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFIntSubProjectPKey();
		CFIntSubProjectPKey( const CFIntSubProjectPKey& src );
		virtual ~CFIntSubProjectPKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		bool operator <( const CFIntSubProjectHPKey& rhs );
		bool operator <( const CFIntSubProjectPKey& rhs );
		bool operator <( const CFIntSubProjectHBuff& rhs );
		bool operator <( const CFIntSubProjectBuff& rhs );

		bool operator <=( const CFIntSubProjectHPKey& rhs );
		bool operator <=( const CFIntSubProjectPKey& rhs );
		bool operator <=( const CFIntSubProjectHBuff& rhs );
		bool operator <=( const CFIntSubProjectBuff& rhs );

		bool operator ==( const CFIntSubProjectHPKey& rhs );
		bool operator ==( const CFIntSubProjectPKey& rhs );
		bool operator ==( const CFIntSubProjectHBuff& rhs );
		bool operator ==( const CFIntSubProjectBuff& rhs );

		bool operator !=( const CFIntSubProjectHPKey& rhs );
		bool operator !=( const CFIntSubProjectPKey& rhs );
		bool operator !=( const CFIntSubProjectHBuff& rhs );
		bool operator !=( const CFIntSubProjectBuff& rhs );

		bool operator >=( const CFIntSubProjectHPKey& rhs );
		bool operator >=( const CFIntSubProjectPKey& rhs );
		bool operator >=( const CFIntSubProjectHBuff& rhs );
		bool operator >=( const CFIntSubProjectBuff& rhs );

		bool operator >( const CFIntSubProjectHPKey& rhs );
		bool operator >( const CFIntSubProjectPKey& rhs );
		bool operator >( const CFIntSubProjectHBuff& rhs );
		bool operator >( const CFIntSubProjectBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfint::CFIntSubProjectPKey operator =( cfint::CFIntSubProjectPKey& src );
		cfint::CFIntSubProjectPKey operator =( cfint::CFIntSubProjectHPKey& src );
		cfint::CFIntSubProjectPKey operator =( cfint::CFIntSubProjectBuff& src );
		cfint::CFIntSubProjectPKey operator =( cfint::CFIntSubProjectHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator <(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator <(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator <(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator <=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator <=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator <=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator <=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator ==(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator ==(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator ==(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator ==(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator !=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator !=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator !=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator !=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator >=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator >=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator >=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator >=(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator >(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator >(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator >(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator >(const  cfint::CFIntSubProjectPKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	template<> struct hash<cfint::CFIntSubProjectPKey> {
		typedef cfint::CFIntSubProjectPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

