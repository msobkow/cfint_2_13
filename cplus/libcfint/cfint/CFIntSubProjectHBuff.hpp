#pragma once

// Description: C++18 specification of a SubProject history buffer object.

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

	class CFIntSubProjectBuff;
	class CFIntSubProjectPKey;
	class CFIntSubProjectHPKey;
	class CFIntSubProjectByTenantIdxKey;
	class CFIntSubProjectByTopProjectIdxKey;
	class CFIntSubProjectByNameIdxKey;

	class CFIntSubProjectHBuff : public CFIntHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredTenantId;
		int64_t requiredId;
		int64_t requiredTopProjectId;
		std::string* requiredName;
		std::string* optionalDescription;		classcode_t classCode;

	public:
		CFIntSubProjectHBuff();
		CFIntSubProjectHBuff( const CFIntSubProjectHBuff& src );
		virtual ~CFIntSubProjectHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		virtual const int64_t getRequiredTopProjectId() const;
		virtual const int64_t* getRequiredTopProjectIdReference() const;
		virtual void setRequiredTopProjectId( const int64_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const std::string& getOptionalDescriptionValue() const;
		virtual const std::string* getOptionalDescriptionReference() const;
		virtual const bool isOptionalDescriptionNull() const;
		virtual void setOptionalDescriptionNull();
		virtual void setOptionalDescriptionValue( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFIntSubProjectByTenantIdxKey& rhs );
		bool operator <( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator <( const CFIntSubProjectByNameIdxKey& rhs );
		bool operator <( const CFIntSubProjectPKey& rhs );
		bool operator <( const CFIntSubProjectHPKey& rhs );
		bool operator <( const CFIntSubProjectHBuff& rhs );
		bool operator <( const CFIntSubProjectBuff& rhs );

		bool operator <=( const CFIntSubProjectByTenantIdxKey& rhs );
		bool operator <=( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator <=( const CFIntSubProjectByNameIdxKey& rhs );
		bool operator <=( const CFIntSubProjectPKey& rhs );
		bool operator <=( const CFIntSubProjectHPKey& rhs );
		bool operator <=( const CFIntSubProjectHBuff& rhs );
		bool operator <=( const CFIntSubProjectBuff& rhs );

		bool operator ==( const CFIntSubProjectByTenantIdxKey& rhs );
		bool operator ==( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator ==( const CFIntSubProjectByNameIdxKey& rhs );
		bool operator ==( const CFIntSubProjectPKey& rhs );
		bool operator ==( const CFIntSubProjectHPKey& rhs );
		bool operator ==( const CFIntSubProjectHBuff& rhs );
		bool operator ==( const CFIntSubProjectBuff& rhs );

		bool operator !=( const CFIntSubProjectByTenantIdxKey& rhs );
		bool operator !=( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator !=( const CFIntSubProjectByNameIdxKey& rhs );
		bool operator !=( const CFIntSubProjectPKey& rhs );
		bool operator !=( const CFIntSubProjectHPKey& rhs );
		bool operator !=( const CFIntSubProjectHBuff& rhs );
		bool operator !=( const CFIntSubProjectBuff& rhs );

		bool operator >=( const CFIntSubProjectByTenantIdxKey& rhs );
		bool operator >=( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator >=( const CFIntSubProjectByNameIdxKey& rhs );
		bool operator >=( const CFIntSubProjectPKey& rhs );
		bool operator >=( const CFIntSubProjectHPKey& rhs );
		bool operator >=( const CFIntSubProjectHBuff& rhs );
		bool operator >=( const CFIntSubProjectBuff& rhs );

		bool operator >( const CFIntSubProjectByTenantIdxKey& rhs );
		bool operator >( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator >( const CFIntSubProjectByNameIdxKey& rhs );
		bool operator >( const CFIntSubProjectPKey& rhs );
		bool operator >( const CFIntSubProjectHPKey& rhs );
		bool operator >( const CFIntSubProjectHBuff& rhs );
		bool operator >( const CFIntSubProjectBuff& rhs );
		cfint::CFIntSubProjectHBuff operator =( cfint::CFIntSubProjectBuff& src );
		cfint::CFIntSubProjectHBuff operator =( cfint::CFIntSubProjectHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTenantIdxKey& rhs );
	bool operator <(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator <(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator <(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator <(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator <(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator <=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTenantIdxKey& rhs );
	bool operator <=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator <=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator <=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator <=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator <=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator ==(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTenantIdxKey& rhs );
	bool operator ==(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator ==(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator ==(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator ==(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator ==(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator !=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTenantIdxKey& rhs );
	bool operator !=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator !=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator !=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator !=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator !=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator >=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTenantIdxKey& rhs );
	bool operator >=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator >=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator >=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator >=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator >=(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator >(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTenantIdxKey& rhs );
	bool operator >(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator >(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs );
	bool operator >(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectPKey& rhs );
	bool operator >(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHPKey& rhs );
	bool operator >(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator >(const  cfint::CFIntSubProjectHBuff& lhs, const cfint::CFIntSubProjectBuff& rhs );

	template<> struct hash<cfint::CFIntSubProjectHBuff> {
		typedef cfint::CFIntSubProjectHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

