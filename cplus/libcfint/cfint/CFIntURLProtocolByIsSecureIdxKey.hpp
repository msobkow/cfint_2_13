#pragma once

// Description: C++18 specification for a URLProtocol by IsSecureIdx index key object.

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

	class CFIntURLProtocolBuff;
	class CFIntURLProtocolHBuff;

	class CFIntURLProtocolByIsSecureIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		bool requiredIsSecure;
	public:
		CFIntURLProtocolByIsSecureIdxKey();
		CFIntURLProtocolByIsSecureIdxKey( const CFIntURLProtocolByIsSecureIdxKey& src );
		virtual ~CFIntURLProtocolByIsSecureIdxKey();

		virtual const bool getRequiredIsSecure() const;
		virtual const bool* getRequiredIsSecureReference() const;
		virtual void setRequiredIsSecure( const bool value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator <( const CFIntURLProtocolHBuff& rhs );
		bool operator <( const CFIntURLProtocolBuff& rhs );

		bool operator <=( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator <=( const CFIntURLProtocolHBuff& rhs );
		bool operator <=( const CFIntURLProtocolBuff& rhs );

		bool operator ==( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator ==( const CFIntURLProtocolHBuff& rhs );
		bool operator ==( const CFIntURLProtocolBuff& rhs );

		bool operator !=( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator !=( const CFIntURLProtocolHBuff& rhs );
		bool operator !=( const CFIntURLProtocolBuff& rhs );

		bool operator >=( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator >=( const CFIntURLProtocolHBuff& rhs );
		bool operator >=( const CFIntURLProtocolBuff& rhs );

		bool operator >( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator >( const CFIntURLProtocolHBuff& rhs );
		bool operator >( const CFIntURLProtocolBuff& rhs );
		cfint::CFIntURLProtocolByIsSecureIdxKey operator =( cfint::CFIntURLProtocolByIsSecureIdxKey& src );
		cfint::CFIntURLProtocolByIsSecureIdxKey operator =( cfint::CFIntURLProtocolBuff& src );
		cfint::CFIntURLProtocolByIsSecureIdxKey operator =( cfint::CFIntURLProtocolHBuff& src );
};
}

namespace std {

	bool operator <(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator <(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator <=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator ==(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator !=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator >=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator >(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator >(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator >(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	template<> struct hash<cfint::CFIntURLProtocolByIsSecureIdxKey> {
		typedef cfint::CFIntURLProtocolByIsSecureIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

