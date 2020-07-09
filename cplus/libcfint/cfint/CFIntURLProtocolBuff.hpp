#pragma once

// Description: C++18 specification for a URLProtocol buffer object.

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

#include <cfint/ICFIntSchema.hpp>

namespace cfint {

	class CFIntURLProtocolPKey;
	class CFIntURLProtocolHPKey;
	class CFIntURLProtocolHBuff;
	class CFIntURLProtocolByUNameIdxKey;
	class CFIntURLProtocolByIsSecureIdxKey;

	class CFIntURLProtocolBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_URLPROTOCOLID;
		static const std::string COLNAME_NAME;
		static const std::string COLNAME_DESCRIPTION;
		static const std::string COLNAME_ISSECURE;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int URLPROTOCOLID_INIT_VALUE;
		static const std::string NAME_INIT_VALUE;
		static const std::string DESCRIPTION_INIT_VALUE;
		static const bool ISSECURE_INIT_VALUE;
		static const int URLPROTOCOLID_MIN_VALUE;
		static const std::string::size_type NAME_MAX_LEN;
		static const std::string::size_type DESCRIPTION_MAX_LEN;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int32_t requiredURLProtocolId;
		std::string* requiredName;
		std::string* requiredDescription;
		bool requiredIsSecure;
		int32_t requiredRevision;
	public:
		CFIntURLProtocolBuff();

		CFIntURLProtocolBuff( const CFIntURLProtocolBuff& src );

		virtual ~CFIntURLProtocolBuff();

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

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

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
		cfint::CFIntURLProtocolBuff operator =( cfint::CFIntURLProtocolBuff& src );
		cfint::CFIntURLProtocolBuff operator =( cfint::CFIntURLProtocolHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs );

	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs );

	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs );
	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs );
	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs );
	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs );

	template<> struct hash<cfint::CFIntURLProtocolBuff> {
		typedef cfint::CFIntURLProtocolBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

