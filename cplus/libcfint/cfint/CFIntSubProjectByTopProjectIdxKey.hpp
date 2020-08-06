#pragma once

// Description: C++18 specification for a SubProject by TopProjectIdx index key object.

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

	class CFIntSubProjectBuff;
	class CFIntSubProjectHBuff;

	class CFIntSubProjectByTopProjectIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredTenantId;
		int64_t requiredTopProjectId;
	public:
		CFIntSubProjectByTopProjectIdxKey();
		CFIntSubProjectByTopProjectIdxKey( const CFIntSubProjectByTopProjectIdxKey& src );
		virtual ~CFIntSubProjectByTopProjectIdxKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredTopProjectId() const;
		virtual const int64_t* getRequiredTopProjectIdReference() const;
		virtual void setRequiredTopProjectId( const int64_t value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator <( const CFIntSubProjectHBuff& rhs );
		bool operator <( const CFIntSubProjectBuff& rhs );

		bool operator <=( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator <=( const CFIntSubProjectHBuff& rhs );
		bool operator <=( const CFIntSubProjectBuff& rhs );

		bool operator ==( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator ==( const CFIntSubProjectHBuff& rhs );
		bool operator ==( const CFIntSubProjectBuff& rhs );

		bool operator !=( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator !=( const CFIntSubProjectHBuff& rhs );
		bool operator !=( const CFIntSubProjectBuff& rhs );

		bool operator >=( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator >=( const CFIntSubProjectHBuff& rhs );
		bool operator >=( const CFIntSubProjectBuff& rhs );

		bool operator >( const CFIntSubProjectByTopProjectIdxKey& rhs );
		bool operator >( const CFIntSubProjectHBuff& rhs );
		bool operator >( const CFIntSubProjectBuff& rhs );
		cfint::CFIntSubProjectByTopProjectIdxKey operator =( cfint::CFIntSubProjectByTopProjectIdxKey& src );
		cfint::CFIntSubProjectByTopProjectIdxKey operator =( cfint::CFIntSubProjectBuff& src );
		cfint::CFIntSubProjectByTopProjectIdxKey operator =( cfint::CFIntSubProjectHBuff& src );
};
}

namespace std {

	bool operator <(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator <(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator <(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator <=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator <=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator <=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator ==(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator ==(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator ==(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator !=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator !=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator !=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator >=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator >=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator >=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	bool operator >(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs );
	bool operator >(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs );
	bool operator >(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs );

	template<> struct hash<cfint::CFIntSubProjectByTopProjectIdxKey> {
		typedef cfint::CFIntSubProjectByTopProjectIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

