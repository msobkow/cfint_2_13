#pragma once

// Description: C++18 specification for a License by UNameIdx index key object.

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

	class CFIntLicenseBuff;
	class CFIntLicenseHBuff;

	class CFIntLicenseByUNameIdxKey
	{
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
	protected:
		int64_t requiredTenantId;
		int64_t requiredTopDomainId;
		std::string* requiredName;
	public:
		CFIntLicenseByUNameIdxKey();
		CFIntLicenseByUNameIdxKey( const CFIntLicenseByUNameIdxKey& src );
		virtual ~CFIntLicenseByUNameIdxKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredTopDomainId() const;
		virtual const int64_t* getRequiredTopDomainIdReference() const;
		virtual void setRequiredTopDomainId( const int64_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual size_t hashCode() const;

		std::string toString();

		bool operator <( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator <( const CFIntLicenseHBuff& rhs );
		bool operator <( const CFIntLicenseBuff& rhs );

		bool operator <=( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator <=( const CFIntLicenseHBuff& rhs );
		bool operator <=( const CFIntLicenseBuff& rhs );

		bool operator ==( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator ==( const CFIntLicenseHBuff& rhs );
		bool operator ==( const CFIntLicenseBuff& rhs );

		bool operator !=( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator !=( const CFIntLicenseHBuff& rhs );
		bool operator !=( const CFIntLicenseBuff& rhs );

		bool operator >=( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator >=( const CFIntLicenseHBuff& rhs );
		bool operator >=( const CFIntLicenseBuff& rhs );

		bool operator >( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator >( const CFIntLicenseHBuff& rhs );
		bool operator >( const CFIntLicenseBuff& rhs );
		cfint::CFIntLicenseByUNameIdxKey operator =( cfint::CFIntLicenseByUNameIdxKey& src );
		cfint::CFIntLicenseByUNameIdxKey operator =( cfint::CFIntLicenseBuff& src );
		cfint::CFIntLicenseByUNameIdxKey operator =( cfint::CFIntLicenseHBuff& src );
};
}

namespace std {

	bool operator <(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator <(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator <=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator <=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator ==(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator ==(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator !=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator !=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator >=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator >=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator >(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator >(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator >(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs );

	template<> struct hash<cfint::CFIntLicenseByUNameIdxKey> {
		typedef cfint::CFIntLicenseByUNameIdxKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

