#pragma once

// Description: C++18 specification for a TopDomain buffer object.

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

	class CFIntTopDomainPKey;
	class CFIntTopDomainHPKey;
	class CFIntTopDomainHBuff;
	class CFIntTopDomainByTenantIdxKey;
	class CFIntTopDomainByTldIdxKey;
	class CFIntTopDomainByNameIdxKey;

	class CFIntTopDomainBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_TENANTID;
		static const std::string COLNAME_ID;
		static const std::string COLNAME_TLDID;
		static const std::string COLNAME_NAME;
		static const std::string COLNAME_DESCRIPTION;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int64_t TENANTID_INIT_VALUE;
		static const int64_t ID_INIT_VALUE;
		static const int64_t TLDID_INIT_VALUE;
		static const std::string NAME_INIT_VALUE;
		static const std::string DESCRIPTION_INIT_VALUE;
		static const int64_t TENANTID_MIN_VALUE;
		static const int64_t ID_MIN_VALUE;
		static const int64_t TLDID_MIN_VALUE;
		static const std::string::size_type NAME_MAX_LEN;
		static const std::string::size_type DESCRIPTION_MAX_LEN;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int64_t requiredTenantId;
		int64_t requiredId;
		int64_t requiredTldId;
		std::string* requiredName;
		std::string* optionalDescription;
		int32_t requiredRevision;
	public:
		CFIntTopDomainBuff();

		CFIntTopDomainBuff( const CFIntTopDomainBuff& src );

		virtual ~CFIntTopDomainBuff();

		virtual const std::string& getClassName() const;
		virtual cflib::ICFLibCloneableObj* clone();
		virtual const classcode_t getClassCode() const;

		virtual bool implementsClassCode( const classcode_t argClassCode );
		virtual const uuid_ptr_t getCreatedByUserId() const;
		virtual void setCreatedByUserId( const uuid_ptr_t value );
		virtual const std::chrono::system_clock::time_point& getCreatedAt() const;
		virtual void setCreatedAt( const std::chrono::system_clock::time_point& value );
		virtual const uuid_ptr_t getUpdatedByUserId() const;
		virtual void setUpdatedByUserId( const uuid_ptr_t value );
		virtual const std::chrono::system_clock::time_point& getUpdatedAt() const;
		virtual void setUpdatedAt( const std::chrono::system_clock::time_point& value );
		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		virtual const int64_t getRequiredTldId() const;
		virtual const int64_t* getRequiredTldIdReference() const;
		virtual void setRequiredTldId( const int64_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const std::string& getOptionalDescriptionValue() const;
		virtual const std::string* getOptionalDescriptionReference() const;
		virtual const bool isOptionalDescriptionNull() const;
		virtual void setOptionalDescriptionNull();
		virtual void setOptionalDescriptionValue( const std::string& value );

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

		virtual size_t hashCode() const;

		bool operator <( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator <( const CFIntTopDomainByTldIdxKey& rhs );
		bool operator <( const CFIntTopDomainByNameIdxKey& rhs );
		bool operator <( const CFIntTopDomainPKey& rhs );
		bool operator <( const CFIntTopDomainHPKey& rhs );
		bool operator <( const CFIntTopDomainHBuff& rhs );
		bool operator <( const CFIntTopDomainBuff& rhs );

		bool operator <=( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator <=( const CFIntTopDomainByTldIdxKey& rhs );
		bool operator <=( const CFIntTopDomainByNameIdxKey& rhs );
		bool operator <=( const CFIntTopDomainPKey& rhs );
		bool operator <=( const CFIntTopDomainHPKey& rhs );
		bool operator <=( const CFIntTopDomainHBuff& rhs );
		bool operator <=( const CFIntTopDomainBuff& rhs );

		bool operator ==( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator ==( const CFIntTopDomainByTldIdxKey& rhs );
		bool operator ==( const CFIntTopDomainByNameIdxKey& rhs );
		bool operator ==( const CFIntTopDomainPKey& rhs );
		bool operator ==( const CFIntTopDomainHPKey& rhs );
		bool operator ==( const CFIntTopDomainHBuff& rhs );
		bool operator ==( const CFIntTopDomainBuff& rhs );

		bool operator !=( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator !=( const CFIntTopDomainByTldIdxKey& rhs );
		bool operator !=( const CFIntTopDomainByNameIdxKey& rhs );
		bool operator !=( const CFIntTopDomainPKey& rhs );
		bool operator !=( const CFIntTopDomainHPKey& rhs );
		bool operator !=( const CFIntTopDomainHBuff& rhs );
		bool operator !=( const CFIntTopDomainBuff& rhs );

		bool operator >=( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator >=( const CFIntTopDomainByTldIdxKey& rhs );
		bool operator >=( const CFIntTopDomainByNameIdxKey& rhs );
		bool operator >=( const CFIntTopDomainPKey& rhs );
		bool operator >=( const CFIntTopDomainHPKey& rhs );
		bool operator >=( const CFIntTopDomainHBuff& rhs );
		bool operator >=( const CFIntTopDomainBuff& rhs );

		bool operator >( const CFIntTopDomainByTenantIdxKey& rhs );
		bool operator >( const CFIntTopDomainByTldIdxKey& rhs );
		bool operator >( const CFIntTopDomainByNameIdxKey& rhs );
		bool operator >( const CFIntTopDomainPKey& rhs );
		bool operator >( const CFIntTopDomainHPKey& rhs );
		bool operator >( const CFIntTopDomainHBuff& rhs );
		bool operator >( const CFIntTopDomainBuff& rhs );
		cfint::CFIntTopDomainBuff operator =( cfint::CFIntTopDomainBuff& src );
		cfint::CFIntTopDomainBuff operator =( cfint::CFIntTopDomainHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );
	bool operator <(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs );
	bool operator <(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainPKey& rhs );
	bool operator <(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHPKey& rhs );
	bool operator <(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator <(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainBuff& rhs );

	bool operator <=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );
	bool operator <=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs );
	bool operator <=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainPKey& rhs );
	bool operator <=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHPKey& rhs );
	bool operator <=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator <=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainBuff& rhs );

	bool operator ==(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );
	bool operator ==(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs );
	bool operator ==(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainPKey& rhs );
	bool operator ==(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHPKey& rhs );
	bool operator ==(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator ==(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainBuff& rhs );

	bool operator !=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );
	bool operator !=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs );
	bool operator !=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainPKey& rhs );
	bool operator !=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHPKey& rhs );
	bool operator !=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator !=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainBuff& rhs );

	bool operator >=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );
	bool operator >=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs );
	bool operator >=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainPKey& rhs );
	bool operator >=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHPKey& rhs );
	bool operator >=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator >=(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainBuff& rhs );

	bool operator >(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTenantIdxKey& rhs );

	bool operator >(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs );

	bool operator >(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs );

	bool operator >(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainPKey& rhs );
	bool operator >(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHPKey& rhs );
	bool operator >(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainHBuff& rhs );
	bool operator >(const  cfint::CFIntTopDomainBuff& lhs, const cfint::CFIntTopDomainBuff& rhs );

	template<> struct hash<cfint::CFIntTopDomainBuff> {
		typedef cfint::CFIntTopDomainBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

