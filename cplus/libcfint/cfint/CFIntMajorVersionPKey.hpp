#pragma once

// Description: C++18 specification of a MajorVersion primary key object.

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

	class CFIntMajorVersionBuff;
	class CFIntMajorVersionHPKey;
	class CFIntMajorVersionHBuff;

	class CFIntMajorVersionPKey
	{
	protected:

		int64_t requiredTenantId;
		int64_t requiredId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFIntMajorVersionPKey();
		CFIntMajorVersionPKey( const CFIntMajorVersionPKey& src );
		virtual ~CFIntMajorVersionPKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		bool operator <( const CFIntMajorVersionHPKey& rhs );
		bool operator <( const CFIntMajorVersionPKey& rhs );
		bool operator <( const CFIntMajorVersionHBuff& rhs );
		bool operator <( const CFIntMajorVersionBuff& rhs );

		bool operator <=( const CFIntMajorVersionHPKey& rhs );
		bool operator <=( const CFIntMajorVersionPKey& rhs );
		bool operator <=( const CFIntMajorVersionHBuff& rhs );
		bool operator <=( const CFIntMajorVersionBuff& rhs );

		bool operator ==( const CFIntMajorVersionHPKey& rhs );
		bool operator ==( const CFIntMajorVersionPKey& rhs );
		bool operator ==( const CFIntMajorVersionHBuff& rhs );
		bool operator ==( const CFIntMajorVersionBuff& rhs );

		bool operator !=( const CFIntMajorVersionHPKey& rhs );
		bool operator !=( const CFIntMajorVersionPKey& rhs );
		bool operator !=( const CFIntMajorVersionHBuff& rhs );
		bool operator !=( const CFIntMajorVersionBuff& rhs );

		bool operator >=( const CFIntMajorVersionHPKey& rhs );
		bool operator >=( const CFIntMajorVersionPKey& rhs );
		bool operator >=( const CFIntMajorVersionHBuff& rhs );
		bool operator >=( const CFIntMajorVersionBuff& rhs );

		bool operator >( const CFIntMajorVersionHPKey& rhs );
		bool operator >( const CFIntMajorVersionPKey& rhs );
		bool operator >( const CFIntMajorVersionHBuff& rhs );
		bool operator >( const CFIntMajorVersionBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfint::CFIntMajorVersionPKey operator =( cfint::CFIntMajorVersionPKey& src );
		cfint::CFIntMajorVersionPKey operator =( cfint::CFIntMajorVersionHPKey& src );
		cfint::CFIntMajorVersionPKey operator =( cfint::CFIntMajorVersionBuff& src );
		cfint::CFIntMajorVersionPKey operator =( cfint::CFIntMajorVersionHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator <(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator <(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator <(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator <=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator <=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator <=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator <=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator ==(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator ==(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator ==(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator ==(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator !=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator !=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator !=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator !=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator >=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator >=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator >=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator >=(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	bool operator >(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHPKey& rhs );
	bool operator >(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionPKey& rhs );
	bool operator >(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs );
	bool operator >(const  cfint::CFIntMajorVersionPKey& lhs, const cfint::CFIntMajorVersionBuff& rhs );

	template<> struct hash<cfint::CFIntMajorVersionPKey> {
		typedef cfint::CFIntMajorVersionPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

