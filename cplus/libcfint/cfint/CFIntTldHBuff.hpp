#pragma once

// Description: C++18 specification of a Tld history buffer object.

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

#include <cfint/CFIntHPKey.hpp>

#include <cfint/ICFIntSchema.hpp>
namespace cfint {

	class CFIntTldBuff;
	class CFIntTldPKey;
	class CFIntTldHPKey;
	class CFIntTldByTenantIdxKey;
	class CFIntTldByNameIdxKey;

	class CFIntTldHBuff : public CFIntHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredTenantId;
		int64_t requiredId;
		std::string* requiredName;
		std::string* optionalDescription;		classcode_t classCode;

	public:
		CFIntTldHBuff();
		CFIntTldHBuff( const CFIntTldHBuff& src );
		virtual ~CFIntTldHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const std::string& getOptionalDescriptionValue() const;
		virtual const std::string* getOptionalDescriptionReference() const;
		virtual const bool isOptionalDescriptionNull() const;
		virtual void setOptionalDescriptionNull();
		virtual void setOptionalDescriptionValue( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFIntTldByTenantIdxKey& rhs );
		bool operator <( const CFIntTldByNameIdxKey& rhs );
		bool operator <( const CFIntTldPKey& rhs );
		bool operator <( const CFIntTldHPKey& rhs );
		bool operator <( const CFIntTldHBuff& rhs );
		bool operator <( const CFIntTldBuff& rhs );

		bool operator <=( const CFIntTldByTenantIdxKey& rhs );
		bool operator <=( const CFIntTldByNameIdxKey& rhs );
		bool operator <=( const CFIntTldPKey& rhs );
		bool operator <=( const CFIntTldHPKey& rhs );
		bool operator <=( const CFIntTldHBuff& rhs );
		bool operator <=( const CFIntTldBuff& rhs );

		bool operator ==( const CFIntTldByTenantIdxKey& rhs );
		bool operator ==( const CFIntTldByNameIdxKey& rhs );
		bool operator ==( const CFIntTldPKey& rhs );
		bool operator ==( const CFIntTldHPKey& rhs );
		bool operator ==( const CFIntTldHBuff& rhs );
		bool operator ==( const CFIntTldBuff& rhs );

		bool operator !=( const CFIntTldByTenantIdxKey& rhs );
		bool operator !=( const CFIntTldByNameIdxKey& rhs );
		bool operator !=( const CFIntTldPKey& rhs );
		bool operator !=( const CFIntTldHPKey& rhs );
		bool operator !=( const CFIntTldHBuff& rhs );
		bool operator !=( const CFIntTldBuff& rhs );

		bool operator >=( const CFIntTldByTenantIdxKey& rhs );
		bool operator >=( const CFIntTldByNameIdxKey& rhs );
		bool operator >=( const CFIntTldPKey& rhs );
		bool operator >=( const CFIntTldHPKey& rhs );
		bool operator >=( const CFIntTldHBuff& rhs );
		bool operator >=( const CFIntTldBuff& rhs );

		bool operator >( const CFIntTldByTenantIdxKey& rhs );
		bool operator >( const CFIntTldByNameIdxKey& rhs );
		bool operator >( const CFIntTldPKey& rhs );
		bool operator >( const CFIntTldHPKey& rhs );
		bool operator >( const CFIntTldHBuff& rhs );
		bool operator >( const CFIntTldBuff& rhs );
		cfint::CFIntTldHBuff operator =( cfint::CFIntTldBuff& src );
		cfint::CFIntTldHBuff operator =( cfint::CFIntTldHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs );
	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs );
	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs );
	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs );
	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs );
	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs );

	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs );
	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs );
	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs );
	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs );
	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs );
	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs );

	template<> struct hash<cfint::CFIntTldHBuff> {
		typedef cfint::CFIntTldHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

