#pragma once

// Description: C++18 specification of a URLProtocol history buffer object.

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

	class CFIntURLProtocolBuff;
	class CFIntURLProtocolPKey;
	class CFIntURLProtocolHPKey;
	class CFIntURLProtocolByUNameIdxKey;
	class CFIntURLProtocolByIsSecureIdxKey;

	class CFIntURLProtocolHBuff : public CFIntHPKey, public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		int32_t requiredURLProtocolId;
		std::string* requiredName;
		std::string* requiredDescription;
		bool requiredIsSecure;		classcode_t classCode;

	public:
		CFIntURLProtocolHBuff();
		CFIntURLProtocolHBuff( const CFIntURLProtocolHBuff& src );
		virtual ~CFIntURLProtocolHBuff();

		virtual cflib::ICFLibCloneableObj* clone();
		virtual const int32_t getRequiredURLProtocolId() const;
		virtual const int32_t* getRequiredURLProtocolIdReference() const;
		virtual void setRequiredURLProtocolId( const int32_t value );

		virtual const std::string& getRequiredName() const;
		virtual const std::string* getRequiredNameReference() const;
		virtual void setRequiredName( const std::string& value );

		virtual const std::string& getRequiredDescription() const;
		virtual const std::string* getRequiredDescriptionReference() const;
		virtual void setRequiredDescription( const std::string& value );

		virtual const bool getRequiredIsSecure() const;
		virtual const bool* getRequiredIsSecureReference() const;
		virtual void setRequiredIsSecure( const bool value );

		virtual size_t hashCode() const;

		bool operator <( const CFIntURLProtocolByUNameIdxKey& rhs );
		bool operator <( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator <( const CFIntURLProtocolPKey& rhs );
		bool operator <( const CFIntURLProtocolHPKey& rhs );
		bool operator <( const CFIntURLProtocolHBuff& rhs );
		bool operator <( const CFIntURLProtocolBuff& rhs );

		bool operator <=( const CFIntURLProtocolByUNameIdxKey& rhs );
		bool operator <=( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator <=( const CFIntURLProtocolPKey& rhs );
		bool operator <=( const CFIntURLProtocolHPKey& rhs );
		bool operator <=( const CFIntURLProtocolHBuff& rhs );
		bool operator <=( const CFIntURLProtocolBuff& rhs );

		bool operator ==( const CFIntURLProtocolByUNameIdxKey& rhs );
		bool operator ==( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator ==( const CFIntURLProtocolPKey& rhs );
		bool operator ==( const CFIntURLProtocolHPKey& rhs );
		bool operator ==( const CFIntURLProtocolHBuff& rhs );
		bool operator ==( const CFIntURLProtocolBuff& rhs );

		bool operator !=( const CFIntURLProtocolByUNameIdxKey& rhs );
		bool operator !=( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator !=( const CFIntURLProtocolPKey& rhs );
		bool operator !=( const CFIntURLProtocolHPKey& rhs );
		bool operator !=( const CFIntURLProtocolHBuff& rhs );
		bool operator !=( const CFIntURLProtocolBuff& rhs );

		bool operator >=( const CFIntURLProtocolByUNameIdxKey& rhs );
		bool operator >=( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator >=( const CFIntURLProtocolPKey& rhs );
		bool operator >=( const CFIntURLProtocolHPKey& rhs );
		bool operator >=( const CFIntURLProtocolHBuff& rhs );
		bool operator >=( const CFIntURLProtocolBuff& rhs );

		bool operator >( const CFIntURLProtocolByUNameIdxKey& rhs );
		bool operator >( const CFIntURLProtocolByIsSecureIdxKey& rhs );
		bool operator >( const CFIntURLProtocolPKey& rhs );
		bool operator >( const CFIntURLProtocolHPKey& rhs );
		bool operator >( const CFIntURLProtocolHBuff& rhs );
		bool operator >( const CFIntURLProtocolBuff& rhs );
		cfint::CFIntURLProtocolHBuff operator =( cfint::CFIntURLProtocolBuff& src );
		cfint::CFIntURLProtocolHBuff operator =( cfint::CFIntURLProtocolHBuff& src );

		virtual std::string toString();

	};
}

namespace std {

	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );
	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	template<> struct hash<cfint::CFIntURLProtocolHBuff> {
		typedef cfint::CFIntURLProtocolHBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

