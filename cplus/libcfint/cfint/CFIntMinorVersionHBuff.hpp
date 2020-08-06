#pragma once

// Description: C++18 specification of a MinorVersion history buffer object.

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

#include <cfint/CFIntHPKey.hpp>

#include <cfint/ICFIntSchema.hpp>
namespace cfint {

	class CFIntMinorVersionBuff;
	class CFIntMinorVersionPKey;
	class CFIntMinorVersionHPKey;
	class CFIntMinorVersionByTenantIdxKey;
	class CFIntMinorVersionByMajorVerIdxKey;
	class CFIntMinorVersionByNameIdxKey;

	class CFIntMinorVersionHBuff : public CFIntHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int64_t requiredTenantId;
		int64_t requiredId;
		int64_t requiredMajorVersionId;
		std::string* requiredName;
		std::string* optionalDescription;		classcode_t classCode;

	public:
		CFIntMinorVersionHBuff();
		CFIntMinorVersionHBuff( const CFIntMinorVersionHBuff& src );
		virtual ~CFIntMinorVersionHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
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
		cfint::CFIntMinorVersionHBuff operator =( cfint::CFIntMinorVersionBuff& src );
		cfint::CFIntMinorVersionHBuff operator =( cfint::CFIntMinorVersionHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );
	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );
	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs );
	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs );
	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs );
	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs );
	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs );
	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs );
	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs );

	template<> struct hash<cfint::CFIntMinorVersionHBuff> {
		typedef cfint::CFIntMinorVersionHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

