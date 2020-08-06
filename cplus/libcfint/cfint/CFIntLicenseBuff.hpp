#pragma once

// Description: C++18 specification for a License buffer object.

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

	class CFIntLicensePKey;
	class CFIntLicenseHPKey;
	class CFIntLicenseHBuff;
	class CFIntLicenseByLicnTenantIdxKey;
	class CFIntLicenseByDomainIdxKey;
	class CFIntLicenseByUNameIdxKey;

	class CFIntLicenseBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_TENANTID;
		static const std::string COLNAME_ID;
		static const std::string COLNAME_TOPDOMAINID;
		static const std::string COLNAME_NAME;
		static const std::string COLNAME_DESCRIPTION;
		static const std::string COLNAME_EMBEDDEDTEXT;
		static const std::string COLNAME_FULLTEXT;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int64_t TENANTID_INIT_VALUE;
		static const int64_t ID_INIT_VALUE;
		static const int64_t TOPDOMAINID_INIT_VALUE;
		static const std::string NAME_INIT_VALUE;
		static const std::string DESCRIPTION_INIT_VALUE;
		static const std::string EMBEDDEDTEXT_INIT_VALUE;
		static const std::string FULLTEXT_INIT_VALUE;
		static const int64_t TENANTID_MIN_VALUE;
		static const int64_t ID_MIN_VALUE;
		static const int64_t TOPDOMAINID_MIN_VALUE;
		static const std::string::size_type NAME_MAX_LEN;
		static const std::string::size_type DESCRIPTION_MAX_LEN;
		static const std::string::size_type EMBEDDEDTEXT_MAX_LEN;
		static const std::string::size_type FULLTEXT_MAX_LEN;
	protected:
		int64_t requiredTenantId;
		int64_t requiredId;
		int64_t requiredTopDomainId;
		std::string* requiredName;
		std::string* optionalDescription;
		std::string* optionalEmbeddedText;
		std::string* optionalFullText;
		int32_t requiredRevision;
	public:
		CFIntLicenseBuff();

		CFIntLicenseBuff( const CFIntLicenseBuff& src );

		virtual ~CFIntLicenseBuff();

		virtual const std::string& getClassName() const;
		virtual cflib::ICFLibCloneableObj* clone();
		virtual const classcode_t getClassCode() const;

		virtual bool implementsClassCode( const classcode_t argClassCode );
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

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

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
		cfint::CFIntLicenseBuff operator =( cfint::CFIntLicenseBuff& src );
		cfint::CFIntLicenseBuff operator =( cfint::CFIntLicenseHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );
	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );
	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );
	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );
	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );
	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );
	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );
	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );
	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );
	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );
	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs );

	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs );

	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs );

	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs );
	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs );
	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs );
	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs );

	template<> struct hash<cfint::CFIntLicenseBuff> {
		typedef cfint::CFIntLicenseBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

