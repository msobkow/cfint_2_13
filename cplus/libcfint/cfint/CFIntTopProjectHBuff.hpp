#pragma once

// Description: C++18 specification of a TopProject history buffer object.

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

	class CFIntTopProjectBuff;
	class CFIntTopProjectPKey;
	class CFIntTopProjectHPKey;
	class CFIntTopProjectByTenantIdxKey;
	class CFIntTopProjectByTopDomainIdxKey;
	class CFIntTopProjectByNameIdxKey;

	class CFIntTopProjectHBuff : public CFIntHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredTenantId;
		int64_t requiredId;
		int64_t requiredTopDomainId;
		std::string* requiredName;
		std::string* optionalDescription;		classcode_t classCode;

	public:
		CFIntTopProjectHBuff();
		CFIntTopProjectHBuff( const CFIntTopProjectHBuff& src );
		virtual ~CFIntTopProjectHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		virtual const int64_t getRequiredTopDomainId() const;
		virtual const int64_t* getRequiredTopDomainIdReference() const;
		virtual void setRequiredTopDomainId( const int64_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const std::string& getOptionalDescriptionValue() const;
		virtual const std::string* getOptionalDescriptionReference() const;
		virtual const bool isOptionalDescriptionNull() const;
		virtual void setOptionalDescriptionNull();
		virtual void setOptionalDescriptionValue( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator <( const CFIntTopProjectByTopDomainIdxKey& rhs );
		bool operator <( const CFIntTopProjectByNameIdxKey& rhs );
		bool operator <( const CFIntTopProjectPKey& rhs );
		bool operator <( const CFIntTopProjectHPKey& rhs );
		bool operator <( const CFIntTopProjectHBuff& rhs );
		bool operator <( const CFIntTopProjectBuff& rhs );

		bool operator <=( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator <=( const CFIntTopProjectByTopDomainIdxKey& rhs );
		bool operator <=( const CFIntTopProjectByNameIdxKey& rhs );
		bool operator <=( const CFIntTopProjectPKey& rhs );
		bool operator <=( const CFIntTopProjectHPKey& rhs );
		bool operator <=( const CFIntTopProjectHBuff& rhs );
		bool operator <=( const CFIntTopProjectBuff& rhs );

		bool operator ==( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator ==( const CFIntTopProjectByTopDomainIdxKey& rhs );
		bool operator ==( const CFIntTopProjectByNameIdxKey& rhs );
		bool operator ==( const CFIntTopProjectPKey& rhs );
		bool operator ==( const CFIntTopProjectHPKey& rhs );
		bool operator ==( const CFIntTopProjectHBuff& rhs );
		bool operator ==( const CFIntTopProjectBuff& rhs );

		bool operator !=( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator !=( const CFIntTopProjectByTopDomainIdxKey& rhs );
		bool operator !=( const CFIntTopProjectByNameIdxKey& rhs );
		bool operator !=( const CFIntTopProjectPKey& rhs );
		bool operator !=( const CFIntTopProjectHPKey& rhs );
		bool operator !=( const CFIntTopProjectHBuff& rhs );
		bool operator !=( const CFIntTopProjectBuff& rhs );

		bool operator >=( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator >=( const CFIntTopProjectByTopDomainIdxKey& rhs );
		bool operator >=( const CFIntTopProjectByNameIdxKey& rhs );
		bool operator >=( const CFIntTopProjectPKey& rhs );
		bool operator >=( const CFIntTopProjectHPKey& rhs );
		bool operator >=( const CFIntTopProjectHBuff& rhs );
		bool operator >=( const CFIntTopProjectBuff& rhs );

		bool operator >( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator >( const CFIntTopProjectByTopDomainIdxKey& rhs );
		bool operator >( const CFIntTopProjectByNameIdxKey& rhs );
		bool operator >( const CFIntTopProjectPKey& rhs );
		bool operator >( const CFIntTopProjectHPKey& rhs );
		bool operator >( const CFIntTopProjectHBuff& rhs );
		bool operator >( const CFIntTopProjectBuff& rhs );
		cfint::CFIntTopProjectHBuff operator =( cfint::CFIntTopProjectBuff& src );
		cfint::CFIntTopProjectHBuff operator =( cfint::CFIntTopProjectHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator <(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs );
	bool operator <(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator <(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator <(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator <(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectBuff& rhs );

	bool operator <=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator <=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs );
	bool operator <=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator <=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator <=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator <=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectBuff& rhs );

	bool operator ==(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator ==(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs );
	bool operator ==(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator ==(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator ==(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator ==(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectBuff& rhs );

	bool operator !=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator !=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs );
	bool operator !=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator !=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator !=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator !=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectBuff& rhs );

	bool operator >=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator >=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs );
	bool operator >=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator >=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator >=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator >=(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectBuff& rhs );

	bool operator >(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator >(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs );
	bool operator >(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectByNameIdxKey& rhs );
	bool operator >(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator >(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator >(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator >(const  cfint::CFIntTopProjectHBuff& lhs, const cfint::CFIntTopProjectBuff& rhs );

	template<> struct hash<cfint::CFIntTopProjectHBuff> {
		typedef cfint::CFIntTopProjectHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

