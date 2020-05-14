#pragma once

// Description: C++18 specification of a License history buffer object.

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

#include <cfint/CFIntHPKey.hpp>

#include <cfint/ICFIntSchema.hpp>
namespace cfint {

	class CFIntLicenseBuff;
	class CFIntLicensePKey;
	class CFIntLicenseHPKey;
	class CFIntLicenseByLicnTenantIdxKey;
	class CFIntLicenseByDomainIdxKey;
	class CFIntLicenseByUNameIdxKey;

	class CFIntLicenseHBuff : public CFIntHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredTenantId;
		int64_t requiredId;
		int64_t requiredTopDomainId;
		std::string* requiredName;
		std::string* optionalDescription;
		std::string* optionalEmbeddedText;
		std::string* optionalFullText;		classcode_t classCode;

	public:
		CFIntLicenseHBuff();
		CFIntLicenseHBuff( const CFIntLicenseHBuff& src );
		virtual ~CFIntLicenseHBuff();

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

		virtual const std::string& getOptionalEmbeddedTextValue() const;
		virtual const std::string* getOptionalEmbeddedTextReference() const;
		virtual const bool isOptionalEmbeddedTextNull() const;
		virtual void setOptionalEmbeddedTextNull();
		virtual void setOptionalEmbeddedTextValue( const std::string& value );

		virtual const std::string& getOptionalFullTextValue() const;
		virtual const std::string* getOptionalFullTextReference() const;
		virtual const bool isOptionalFullTextNull() const;
		virtual void setOptionalFullTextNull();
		virtual void setOptionalFullTextValue( const std::string& value );

		virtual size_t hashCode() const;

		bool operator <( const CFIntLicenseByLicnTenantIdxKey& rhs );
		bool operator <( const CFIntLicenseByDomainIdxKey& rhs );
		bool operator <( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator <( const CFIntLicensePKey& rhs );
		bool operator <( const CFIntLicenseHPKey& rhs );
		bool operator <( const CFIntLicenseHBuff& rhs );
		bool operator <( const CFIntLicenseBuff& rhs );

		bool operator <=( const CFIntLicenseByLicnTenantIdxKey& rhs );
		bool operator <=( const CFIntLicenseByDomainIdxKey& rhs );
		bool operator <=( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator <=( const CFIntLicensePKey& rhs );
		bool operator <=( const CFIntLicenseHPKey& rhs );
		bool operator <=( const CFIntLicenseHBuff& rhs );
		bool operator <=( const CFIntLicenseBuff& rhs );

		bool operator ==( const CFIntLicenseByLicnTenantIdxKey& rhs );
		bool operator ==( const CFIntLicenseByDomainIdxKey& rhs );
		bool operator ==( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator ==( const CFIntLicensePKey& rhs );
		bool operator ==( const CFIntLicenseHPKey& rhs );
		bool operator ==( const CFIntLicenseHBuff& rhs );
		bool operator ==( const CFIntLicenseBuff& rhs );

		bool operator !=( const CFIntLicenseByLicnTenantIdxKey& rhs );
		bool operator !=( const CFIntLicenseByDomainIdxKey& rhs );
		bool operator !=( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator !=( const CFIntLicensePKey& rhs );
		bool operator !=( const CFIntLicenseHPKey& rhs );
		bool operator !=( const CFIntLicenseHBuff& rhs );
		bool operator !=( const CFIntLicenseBuff& rhs );

		bool operator >=( const CFIntLicenseByLicnTenantIdxKey& rhs );
		bool operator >=( const CFIntLicenseByDomainIdxKey& rhs );
		bool operator >=( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator >=( const CFIntLicensePKey& rhs );
		bool operator >=( const CFIntLicenseHPKey& rhs );
		bool operator >=( const CFIntLicenseHBuff& rhs );
		bool operator >=( const CFIntLicenseBuff& rhs );

		bool operator >( const CFIntLicenseByLicnTenantIdxKey& rhs );
		bool operator >( const CFIntLicenseByDomainIdxKey& rhs );
		bool operator >( const CFIntLicenseByUNameIdxKey& rhs );
		bool operator >( const CFIntLicensePKey& rhs );
		bool operator >( const CFIntLicenseHPKey& rhs );
		bool operator >( const CFIntLicenseHBuff& rhs );
		bool operator >( const CFIntLicenseBuff& rhs );
		cfint::CFIntLicenseHBuff operator =( cfint::CFIntLicenseBuff& src );
		cfint::CFIntLicenseHBuff operator =( cfint::CFIntLicenseHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );
	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );
	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );
	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );
	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );
	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );
	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );
	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );
	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );
	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );
	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );
	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );
	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	template<> struct hash<cfint::CFIntLicenseHBuff> {
		typedef cfint::CFIntLicenseHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

