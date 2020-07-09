#pragma once

// Description: C++18 specification of a MimeType history buffer object.

/*
 *	org.msscf.msscf.CFInt
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

	class CFIntMimeTypeBuff;
	class CFIntMimeTypePKey;
	class CFIntMimeTypeHPKey;
	class CFIntMimeTypeByUNameIdxKey;

	class CFIntMimeTypeHBuff : public CFIntHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int32_t requiredMimeTypeId;
		std::string* requiredName;
		std::string* optionalFileTypes;		classcode_t classCode;

	public:
		CFIntMimeTypeHBuff();
		CFIntMimeTypeHBuff( const CFIntMimeTypeHBuff& src );
		virtual ~CFIntMimeTypeHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int32_t getRequiredMimeTypeId() const;
		virtual const int32_t* getRequiredMimeTypeIdReference() const;
		virtual void setRequiredMimeTypeId( const int32_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const std::string& getOptionalFileTypesValue() const;
		virtual const std::string* getOptionalFileTypesReference() const;
		virtual const bool isOptionalFileTypesNull() const;
		virtual void setOptionalFileTypesNull();
		virtual void setOptionalFileTypesValue( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFIntMimeTypeByUNameIdxKey& rhs );
		bool operator <( const CFIntMimeTypePKey& rhs );
		bool operator <( const CFIntMimeTypeHPKey& rhs );
		bool operator <( const CFIntMimeTypeHBuff& rhs );
		bool operator <( const CFIntMimeTypeBuff& rhs );

		bool operator <=( const CFIntMimeTypeByUNameIdxKey& rhs );
		bool operator <=( const CFIntMimeTypePKey& rhs );
		bool operator <=( const CFIntMimeTypeHPKey& rhs );
		bool operator <=( const CFIntMimeTypeHBuff& rhs );
		bool operator <=( const CFIntMimeTypeBuff& rhs );

		bool operator ==( const CFIntMimeTypeByUNameIdxKey& rhs );
		bool operator ==( const CFIntMimeTypePKey& rhs );
		bool operator ==( const CFIntMimeTypeHPKey& rhs );
		bool operator ==( const CFIntMimeTypeHBuff& rhs );
		bool operator ==( const CFIntMimeTypeBuff& rhs );

		bool operator !=( const CFIntMimeTypeByUNameIdxKey& rhs );
		bool operator !=( const CFIntMimeTypePKey& rhs );
		bool operator !=( const CFIntMimeTypeHPKey& rhs );
		bool operator !=( const CFIntMimeTypeHBuff& rhs );
		bool operator !=( const CFIntMimeTypeBuff& rhs );

		bool operator >=( const CFIntMimeTypeByUNameIdxKey& rhs );
		bool operator >=( const CFIntMimeTypePKey& rhs );
		bool operator >=( const CFIntMimeTypeHPKey& rhs );
		bool operator >=( const CFIntMimeTypeHBuff& rhs );
		bool operator >=( const CFIntMimeTypeBuff& rhs );

		bool operator >( const CFIntMimeTypeByUNameIdxKey& rhs );
		bool operator >( const CFIntMimeTypePKey& rhs );
		bool operator >( const CFIntMimeTypeHPKey& rhs );
		bool operator >( const CFIntMimeTypeHBuff& rhs );
		bool operator >( const CFIntMimeTypeBuff& rhs );
		cfint::CFIntMimeTypeHBuff operator =( cfint::CFIntMimeTypeBuff& src );
		cfint::CFIntMimeTypeHBuff operator =( cfint::CFIntMimeTypeHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator <(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator <(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator <(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator <=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator <=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator <=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator <=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator ==(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator ==(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator ==(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator ==(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator !=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator !=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator !=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator !=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator >=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator >=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator >=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator >=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator >(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );
	bool operator >(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator >(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator >(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator >(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	template<> struct hash<cfint::CFIntMimeTypeHBuff> {
		typedef cfint::CFIntMimeTypeHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

