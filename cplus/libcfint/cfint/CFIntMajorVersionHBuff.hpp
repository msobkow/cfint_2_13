#pragma once

// Description: C++18 specification of a MajorVersion history buffer object.

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

	class CFIntMajorVersionBuff;
	class CFIntMajorVersionPKey;
	class CFIntMajorVersionHPKey;
	class CFIntMajorVersionByTenantIdxKey;
	class CFIntMajorVersionBySubProjectIdxKey;
	class CFIntMajorVersionByNameIdxKey;

	class CFIntMajorVersionHBuff : public CFIntHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredTenantId;
		int64_t requiredId;
		int64_t requiredSubProjectId;
		std::string* requiredName;
		std::string* optionalDescription;		classcode_t classCode;

	public:
		CFIntMajorVersionHBuff();
		CFIntMajorVersionHBuff( const CFIntMajorVersionHBuff& src );
		virtual ~CFIntMajorVersionHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		virtual const int64_t getRequiredSubProjectId() const;
		virtual const int64_t* getRequiredSubProjectIdReference() const;
		virtual void setRequiredSubProjectId( const int64_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const std::string& getOptionalDescriptionValue() const;
		virtual const std::string* getOptionalDescriptionReference() const;
		virtual const bool isOptionalDescriptionNull() const;
		virtual void setOptionalDescriptionNull();
		virtual void setOptionalDescriptionValue( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFIntMajorVersionByTenantIdxKey& rhs );
		bool operator <( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator <( const CFIntMajorVersionByNameIdxKey& rhs );
		bool operator <( const CFIntMajorVersionPKey& rhs );
		bool operator <( const CFIntMajorVersionHPKey& rhs );
		bool operator <( const CFIntMajorVersionHBuff& rhs );
		bool operator <( const CFIntMajorVersionBuff& rhs );

		bool operator <=( const CFIntMajorVersionByTenantIdxKey& rhs );
		bool operator <=( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator <=( const CFIntMajorVersionByNameIdxKey& rhs );
		bool operator <=( const CFIntMajorVersionPKey& rhs );
		bool operator <=( const CFIntMajorVersionHPKey& rhs );
		bool operator <=( const CFIntMajorVersionHBuff& rhs );
		bool operator <=( const CFIntMajorVersionBuff& rhs );

		bool operator ==( const CFIntMajorVersionByTenantIdxKey& rhs );
		bool operator ==( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator ==( const CFIntMajorVersionByNameIdxKey& rhs );
		bool operator ==( const CFIntMajorVersionPKey& rhs );
		bool operator ==( const CFIntMajorVersionHPKey& rhs );
		bool operator ==( const CFIntMajorVersionHBuff& rhs );
		bool operator ==( const CFIntMajorVersionBuff& rhs );

		bool operator !=( const CFIntMajorVersionByTenantIdxKey& rhs );
		bool operator !=( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator !=( const CFIntMajorVersionByNameIdxKey& rhs );
		bool operator !=( const CFIntMajorVersionPKey& rhs );
		bool operator !=( const CFIntMajorVersionHPKey& rhs );
		bool operator !=( const CFIntMajorVersionHBuff& rhs );
		bool operator !=( const CFIntMajorVersionBuff& rhs );

		bool operator >=( const CFIntMajorVersionByTenantIdxKey& rhs );
		bool operator >=( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator >=( const CFIntMajorVersionByNameIdxKey& rhs );
		bool operator >=( const CFIntMajorVersionPKey& rhs );
		bool operator >=( const CFIntMajorVersionHPKey& rhs );
		bool operator >=( const CFIntMajorVersionHBuff& rhs );
		bool operator >=( const CFIntMajorVersionBuff& rhs );

		bool operator >( const CFIntMajorVersionByTenantIdxKey& rhs );
		bool operator >( const CFIntMajorVersionBySubProjectIdxKey& rhs );
		bool operator >( const CFIntMajorVersionByNameIdxKey& rhs );
		bool operator >( const CFIntMajorVersionPKey& rhs );
		bool operator >( const CFIntMajorVersionHPKey& rhs );
		bool operator >( const CFIntMajorVersionHBuff& rhs );
		bool operator >( const CFIntMajorVersionBuff& rhs );
		cfint::CFIntMajorVersionHBuff operator =( cfint::CFIntMajorVersionBuff& src );
		cfint::CFIntMajorVersionHBuff operator =( cfint::CFIntMajorVersionHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByTenantIdxKey& rhs );
	bool operator <(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator <(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator <(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator <(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator <(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator <=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByTenantIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator <=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator <=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator <=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator ==(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByTenantIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator ==(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator ==(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator ==(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator !=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByTenantIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator !=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator !=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator !=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator >=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByTenantIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator >=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator >=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator >=(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator >(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByTenantIdxKey& rhs );
	bool operator >(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs );
	bool operator >(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs );
	bool operator >(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator >(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator >(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator >(const  cfint::CFIntMajorVersionHBuff& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	template<> struct hash<cfint::CFIntMajorVersionHBuff> {
		typedef cfint::CFIntMajorVersionHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

