#pragma once

// Description: C++18 specification for a MinorVersion by NameIdx index key object.

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

	class CFIntMinorVersionBuff;
	class CFIntMinorVersionHBuff;

	class CFIntMinorVersionByNameIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredTenantId;
		int64_t requiredMajorVersionId;
		std::string* requiredName;
	public:
		CFIntMinorVersionByNameIdxKey();
		CFIntMinorVersionByNameIdxKey( const CFIntMinorVersionByNameIdxKey& src );
		virtual ~CFIntMinorVersionByNameIdxKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredMajorVersionId() const;
		virtual const int64_t* getRequiredMajorVersionIdReference() const;
		virtual void setRequiredMajorVersionId( const int64_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator <( const CFIntMinorVersionHBuff& rhs );
		bool operator <( const CFIntMinorVersionBuff& rhs );

		bool operator <=( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator <=( const CFIntMinorVersionHBuff& rhs );
		bool operator <=( const CFIntMinorVersionBuff& rhs );

		bool operator ==( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator ==( const CFIntMinorVersionHBuff& rhs );
		bool operator ==( const CFIntMinorVersionBuff& rhs );

		bool operator !=( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator !=( const CFIntMinorVersionHBuff& rhs );
		bool operator !=( const CFIntMinorVersionBuff& rhs );

		bool operator >=( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator >=( const CFIntMinorVersionHBuff& rhs );
		bool operator >=( const CFIntMinorVersionBuff& rhs );

		bool operator >( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator >( const CFIntMinorVersionHBuff& rhs );
		bool operator >( const CFIntMinorVersionBuff& rhs );
		cfint::CFIntMinorVersionByNameIdxKey operator =( cfint::CFIntMinorVersionByNameIdxKey& src );
		cfint::CFIntMinorVersionByNameIdxKey operator =( cfint::CFIntMinorVersionBuff& src );
		cfint::CFIntMinorVersionByNameIdxKey operator =( cfint::CFIntMinorVersionHBuff& src );
};
}

namespace std {

	bool operator <(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator <(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator <=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator ==(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator !=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator >=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator >(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator >(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator >(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	template<> struct hash<cfint::CFIntMinorVersionByNameIdxKey> {
		typedef cfint::CFIntMinorVersionByNameIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

