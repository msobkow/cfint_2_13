#pragma once

// Description: C++18 specification of a MimeType primary key object.

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
#include <cfint/ICFIntSchema.hpp>

namespace cfint {

	class CFIntMimeTypeBuff;
	class CFIntMimeTypeHPKey;
	class CFIntMimeTypeHBuff;

	class CFIntMimeTypePKey
	{
	protected:

		int32_t requiredMimeTypeId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;

		CFIntMimeTypePKey();
		CFIntMimeTypePKey( const CFIntMimeTypePKey& src );
		virtual ~CFIntMimeTypePKey();

		virtual const int32_t getRequiredMimeTypeId() const;
		virtual const int32_t* getRequiredMimeTypeIdReference() const;
		virtual void setRequiredMimeTypeId( const int32_t value );

		bool operator <( const CFIntMimeTypeHPKey& rhs );
		bool operator <( const CFIntMimeTypePKey& rhs );
		bool operator <( const CFIntMimeTypeHBuff& rhs );
		bool operator <( const CFIntMimeTypeBuff& rhs );

		bool operator <=( const CFIntMimeTypeHPKey& rhs );
		bool operator <=( const CFIntMimeTypePKey& rhs );
		bool operator <=( const CFIntMimeTypeHBuff& rhs );
		bool operator <=( const CFIntMimeTypeBuff& rhs );

		bool operator ==( const CFIntMimeTypeHPKey& rhs );
		bool operator ==( const CFIntMimeTypePKey& rhs );
		bool operator ==( const CFIntMimeTypeHBuff& rhs );
		bool operator ==( const CFIntMimeTypeBuff& rhs );

		bool operator !=( const CFIntMimeTypeHPKey& rhs );
		bool operator !=( const CFIntMimeTypePKey& rhs );
		bool operator !=( const CFIntMimeTypeHBuff& rhs );
		bool operator !=( const CFIntMimeTypeBuff& rhs );

		bool operator >=( const CFIntMimeTypeHPKey& rhs );
		bool operator >=( const CFIntMimeTypePKey& rhs );
		bool operator >=( const CFIntMimeTypeHBuff& rhs );
		bool operator >=( const CFIntMimeTypeBuff& rhs );

		bool operator >( const CFIntMimeTypeHPKey& rhs );
		bool operator >( const CFIntMimeTypePKey& rhs );
		bool operator >( const CFIntMimeTypeHBuff& rhs );
		bool operator >( const CFIntMimeTypeBuff& rhs );
		virtual size_t hashCode() const;

		virtual std::string toString();

		cfint::CFIntMimeTypePKey operator =( cfint::CFIntMimeTypePKey& src );
		cfint::CFIntMimeTypePKey operator =( cfint::CFIntMimeTypeHPKey& src );
		cfint::CFIntMimeTypePKey operator =( cfint::CFIntMimeTypeBuff& src );
		cfint::CFIntMimeTypePKey operator =( cfint::CFIntMimeTypeHBuff& src );
	};
}

namespace std {

	bool operator <(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator <(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator <(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator <(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator <=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator <=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator <=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator <=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator ==(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator ==(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator ==(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator ==(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator !=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator !=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator !=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator !=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator >=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator >=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator >=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator >=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator >(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator >(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator >(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator >(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	template<> struct hash<cfint::CFIntMimeTypePKey> {
		typedef cfint::CFIntMimeTypePKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

