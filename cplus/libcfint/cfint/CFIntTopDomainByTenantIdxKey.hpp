#pragma once

// Description: C++18 specification for a TopDomain by TenantIdx index key object.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
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

