#pragma once

// Description: C++18 specification for a MinorVersion buffer object.

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

#include <cfint/ICFIntSchema.hpp>

namespace cfint {

	class CFIntMinorVersionPKey;
	class CFIntMinorVersionHPKey;
	class CFIntMinorVersionHBuff;
	class CFIntMinorVersionByTenantIdxKey;
	class CFIntMinorVersionByMajorVerIdxKey;
	class CFIntMinorVersionByNameIdxKey;

	class CFIntMinorVersionBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_TENANTID;
		static const std::string COLNAME_ID;
		static const std::string COLNAME_MAJORVERSIONID;
		static const std::string COLNAME_NAME;
		static const std::string COLNAME_DESCRIPTION;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int64_t TENANTID_INIT_VALUE;
		static const int64_t ID_INIT_VALUE;
		static const int64_t MAJORVERSIONID_INIT_VALUE;
		static const std::string NAME_INIT_VALUE;
		static const std::string DESCRIPTION_INIT_VALUE;
		static const int64_t TENANTID_MIN_VALUE;
		static const int64_t ID_MIN_VALUE;
		static const int64_t MAJORVERSIONID_MIN_VALUE;
		static const std::string::size_type NAME_MAX_LEN;
		static const std::string::size_type DESCRIPTION_MAX_LEN;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int64_t requiredTenantId;
		int64_t requiredId;
		int64_t requiredMajorVersionId;
		std::string* requiredName;
		std::string* optionalDescription;
		int32_t requiredRevision;
	public:
		CFIntMinorVersionBuff();

		CFIntMinorVersionBuff( const CFIntMinorVersionBuff& src );

		virtual ~CFIntMinorVersionBuff();

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

		virtual const int64_t getRequiredMajorVersionId() const;
		virtual const int64_t* getRequiredMajorVersionIdReference() const;
		virtual void setRequiredMajorVersionId( const int64_t value );

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

		bool operator <( const CFIntMinorVersionByTenantIdxKey& rhs );
		bool operator <( const CFIntMinorVersionByMajorVerIdxKey& rhs );
		bool operator <( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator <( const CFIntMinorVersionPKey& rhs );
		bool operator <( const CFIntMinorVersionHPKey& rhs );
		bool operator <( const CFIntMinorVersionHBuff& rhs );
		bool operator <( const CFIntMinorVersionBuff& rhs );

		bool operator <=( const CFIntMinorVersionByTenantIdxKey& rhs );
		bool operator <=( const CFIntMinorVersionByMajorVerIdxKey& rhs );
		bool operator <=( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator <=( const CFIntMinorVersionPKey& rhs );
		bool operator <=( const CFIntMinorVersionHPKey& rhs );
		bool operator <=( const CFIntMinorVersionHBuff& rhs );
		bool operator <=( const CFIntMinorVersionBuff& rhs );

		bool operator ==( const CFIntMinorVersionByTenantIdxKey& rhs );
		bool operator ==( const CFIntMinorVersionByMajorVerIdxKey& rhs );
		bool operator ==( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator ==( const CFIntMinorVersionPKey& rhs );
		bool operator ==( const CFIntMinorVersionHPKey& rhs );
		bool operator ==( const CFIntMinorVersionHBuff& rhs );
		bool operator ==( const CFIntMinorVersionBuff& rhs );

		bool operator !=( const CFIntMinorVersionByTenantIdxKey& rhs );
		bool operator !=( const CFIntMinorVersionByMajorVerIdxKey& rhs );
		bool operator !=( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator !=( const CFIntMinorVersionPKey& rhs );
		bool operator !=( const CFIntMinorVersionHPKey& rhs );
		bool operator !=( const CFIntMinorVersionHBuff& rhs );
		bool operator !=( const CFIntMinorVersionBuff& rhs );

		bool operator >=( const CFIntMinorVersionByTenantIdxKey& rhs );
		bool operator >=( const CFIntMinorVersionByMajorVerIdxKey& rhs );
		bool operator >=( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator >=( const CFIntMinorVersionPKey& rhs );
		bool operator >=( const CFIntMinorVersionHPKey& rhs );
		bool operator >=( const CFIntMinorVersionHBuff& rhs );
		bool operator >=( const CFIntMinorVersionBuff& rhs );

		bool operator >( const CFIntMinorVersionByTenantIdxKey& rhs );
		bool operator >( const CFIntMinorVersionByMajorVerIdxKey& rhs );
		bool operator >( const CFIntMinorVersionByNameIdxKey& rhs );
		bool operator >( const CFIntMinorVersionPKey& rhs );
		bool operator >( const CFIntMinorVersionHPKey& rhs );
		bool operator >( const CFIntMinorVersionHBuff& rhs );
		bool operator >( const CFIntMinorVersionBuff& rhs );
		cfint::CFIntMinorVersionBuff operator =( cfint::CFIntMinorVersionBuff& src );
		cfint::CFIntMinorVersionBuff operator =( cfint::CFIntMinorVersionHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );
	bool operator <(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );
	bool operator <(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator <(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator <(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator <(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator <=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator ==(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator !=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator >=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator >(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );

	bool operator >(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );

	bool operator >(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );

	bool operator >(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator >(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator >(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator >(const  cfint::CFIntMinorVersionBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	template<> struct hash<cfint::CFIntMinorVersionBuff> {
		typedef cfint::CFIntMinorVersionBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

