#pragma once

// Description: C++18 specification of a MimeType history primary key object.

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

	class CFIntMimeTypePKey;
	class CFIntMimeTypeBuff;
	class CFIntMimeTypeHBuff;

	class CFIntMimeTypeHPKey : public CFIntHPKey
	{
	protected:

		int32_t requiredMimeTypeId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFIntMimeTypeHPKey();
		CFIntMimeTypeHPKey( const CFIntMimeTypeHPKey& src );
		virtual ~CFIntMimeTypeHPKey();

		virtual const int32_t getRequiredMimeTypeId() const;
		virtual const int32_t* getRequiredMimeTypeIdReference() const;
		virtual void setRequiredMimeTypeId( const int32_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFIntMimeTypePKey& rhs );
		bool operator <( const CFIntMimeTypeHPKey& rhs );
		bool operator <( const CFIntMimeTypeHBuff& rhs );
		bool operator <( const CFIntMimeTypeBuff& rhs );


		bool operator <=( const CFIntMimeTypePKey& rhs );
		bool operator <=( const CFIntMimeTypeHPKey& rhs );
		bool operator <=( const CFIntMimeTypeHBuff& rhs );
		bool operator <=( const CFIntMimeTypeBuff& rhs );


		bool operator ==( const CFIntMimeTypePKey& rhs );
		bool operator ==( const CFIntMimeTypeHPKey& rhs );
		bool operator ==( const CFIntMimeTypeHBuff& rhs );
		bool operator ==( const CFIntMimeTypeBuff& rhs );


		bool operator !=( const CFIntMimeTypePKey& rhs );
		bool operator !=( const CFIntMimeTypeHPKey& rhs );
		bool operator !=( const CFIntMimeTypeHBuff& rhs );
		bool operator !=( const CFIntMimeTypeBuff& rhs );


		bool operator >=( const CFIntMimeTypePKey& rhs );
		bool operator >=( const CFIntMimeTypeHPKey& rhs );
		bool operator >=( const CFIntMimeTypeHBuff& rhs );
		bool operator >=( const CFIntMimeTypeBuff& rhs );


		bool operator >( const CFIntMimeTypePKey& rhs );
		bool operator >( const CFIntMimeTypeHPKey& rhs );
		bool operator >( const CFIntMimeTypeHBuff& rhs );
		bool operator >( const CFIntMimeTypeBuff& rhs );

		cfint::CFIntMimeTypeHPKey operator =( cfint::CFIntMimeTypePKey& src );
		cfint::CFIntMimeTypeHPKey operator =( cfint::CFIntMimeTypeHPKey& src );
		cfint::CFIntMimeTypeHPKey operator =( cfint::CFIntMimeTypeBuff& src );
		cfint::CFIntMimeTypeHPKey operator =( cfint::CFIntMimeTypeHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator <(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator <(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator <(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );


	bool operator <=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator <=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator <=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator <=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );


	bool operator ==(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator ==(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator ==(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator ==(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );


	bool operator !=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator !=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator !=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator !=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );


	bool operator >=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator >=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator >=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator >=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );


	bool operator >(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator >(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator >(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator >(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );


	template<> struct hash<cfint::CFIntMimeTypeHPKey> {
		typedef cfint::CFIntMimeTypeHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

