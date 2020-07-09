#pragma once

// Description: C++18 specification for a MajorVersion by SubProjectIdx index key object.

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

	class CFIntMajorVersionBuff;
	class CFIntMajorVersionHBuff;

	class CFIntMajorVersionBySubProjectIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredTenantId;
		int64_t requiredSubProjectId;
	public:
		CFIntMajorVersionBySubProjectIdxKey();
		CFIntMajorVersionBySubProjectIdxKey( const CFIntMajorVersionBySubProjectIdxKey& src );
		virtual ~CFIntMajorVersionBySubProjectIdxKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredSubProjectId() const;
		virtual const int64_t* getRequiredSubProjectIdReference() const;
		virtual void setRequiredSubProjectId( const int64_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator <( const CFIntMajorVersionHBuff& rhs );
		bool operator <( const CFIntMajorVersionBuff& rhs );

		bool operator <=( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator <=( const CFIntMajorVersionHBuff& rhs );
		bool operator <=( const CFIntMajorVersionBuff& rhs );

		bool operator ==( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator ==( const CFIntMajorVersionHBuff& rhs );
		bool operator ==( const CFIntMajorVersionBuff& rhs );

		bool operator !=( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator !=( const CFIntMajorVersionHBuff& rhs );
		bool operator !=( const CFIntMajorVersionBuff& rhs );

		bool operator >=( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator >=( const CFIntMajorVersionHBuff& rhs );
		bool operator >=( const CFIntMajorVersionBuff& rhs );

		bool operator >( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator >( const CFIntMajorVersionHBuff& rhs );
		bool operator >( const CFIntMajorVersionBuff& rhs );
		cfint::CFIntMajorVersionBySubProjectIdxKey operator =( cfint::CFIntMajorVersionBySubProjectIdxKey& src );
		cfint::CFIntMajorVersionBySubProjectIdxKey operator =( cfint::CFIntMajorVersionBuff& src );
		cfint::CFIntMajorVersionBySubProjectIdxKey operator =( cfint::CFIntMajorVersionHBuff& src );
};
}

namespace std {

	bool operator <(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator <(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator <(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator <=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator <=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator ==(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator ==(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator !=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator !=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator >=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator >=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator >(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator >(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator >(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	template<> struct hash<cfint::CFIntMajorVersionBySubProjectIdxKey> {
		typedef cfint::CFIntMajorVersionBySubProjectIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

