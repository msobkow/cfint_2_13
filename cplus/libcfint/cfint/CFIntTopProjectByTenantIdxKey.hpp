#pragma once

// Description: C++18 specification for a TopProject by TenantIdx index key object.

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

	class CFIntTopProjectBuff;
	class CFIntTopProjectHBuff;

	class CFIntTopProjectByTenantIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredTenantId;
	public:
		CFIntTopProjectByTenantIdxKey();
		CFIntTopProjectByTenantIdxKey( const CFIntTopProjectByTenantIdxKey& src );
		virtual ~CFIntTopProjectByTenantIdxKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator <( const CFIntTopProjectHBuff& rhs );
		bool operator <( const CFIntTopProjectBuff& rhs );

		bool operator <=( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator <=( const CFIntTopProjectHBuff& rhs );
		bool operator <=( const CFIntTopProjectBuff& rhs );

		bool operator ==( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator ==( const CFIntTopProjectHBuff& rhs );
		bool operator ==( const CFIntTopProjectBuff& rhs );

		bool operator !=( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator !=( const CFIntTopProjectHBuff& rhs );
		bool operator !=( const CFIntTopProjectBuff& rhs );

		bool operator >=( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator >=( const CFIntTopProjectHBuff& rhs );
		bool operator >=( const CFIntTopProjectBuff& rhs );

		bool operator >( const CFIntTopProjectByTenantIdxKey& rhs );
		bool operator >( const CFIntTopProjectHBuff& rhs );
		bool operator >( const CFIntTopProjectBuff& rhs );
		cfint::CFIntTopProjectByTenantIdxKey operator =( cfint::CFIntTopProjectByTenantIdxKey& src );
		cfint::CFIntTopProjectByTenantIdxKey operator =( cfint::CFIntTopProjectBuff& src );
		cfint::CFIntTopProjectByTenantIdxKey operator =( cfint::CFIntTopProjectHBuff& src );
};
}

namespace std {

	bool operator <(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator <(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator <(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs );

	bool operator <=(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator <=(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator <=(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs );

	bool operator ==(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator ==(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator ==(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs );

	bool operator !=(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator !=(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator !=(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs );

	bool operator >=(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator >=(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator >=(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs );

	bool operator >(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectByTenantIdxKey& rhs );
	bool operator >(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator >(const  cfint::CFIntTopProjectByTenantIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs );

	template<> struct hash<cfint::CFIntTopProjectByTenantIdxKey> {
		typedef cfint::CFIntTopProjectByTenantIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

