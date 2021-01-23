#pragma once

// Description: C++18 specification of a TopProject history buffer object.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
 *	
 *		This file is part of MSS Code Factory.
 *	
 *		MSS Code Factory is available under dual commercial license from Mark Stephen
 *		Sobkow, or under the terms of the GNU General Public License, Version 3
 *		or later.
 *	
 *	    MSS Code Factory is free software: you can redistribute it and/or modify
 *	    it under the terms of the GNU General Public License as published by
 *	    the Free Software Foundation, either version 3 of the License, or
 *	    (at your option) any later version.
 *	
 *	    MSS Code Factory is distributed in the hope that it will be useful,
 *	    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	    GNU General Public License for more details.
 *	
 *	    You should have received a copy of the GNU General Public License
 *	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
 *	
 *	Donations to support MSS Code Factory can be made at
 *	https://www.paypal.com/paypalme2/MarkSobkow
 *	
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
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

