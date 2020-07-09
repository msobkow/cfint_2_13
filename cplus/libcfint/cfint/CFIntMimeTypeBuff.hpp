#pragma once

// Description: C++18 specification for a MimeType buffer object.

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

	class CFIntMimeTypePKey;
	class CFIntMimeTypeHPKey;
	class CFIntMimeTypeHBuff;
	class CFIntMimeTypeByUNameIdxKey;

	class CFIntMimeTypeBuff : public cflib::ICFLibCloneableObj
	{
	public:
		static const std::string GENDEFNAME;
		static const classcode_t CLASS_CODE;
		static const std::string CLASS_NAME;
		static const std::string COLNAME_MIMETYPEID;
		static const std::string COLNAME_NAME;
		static const std::string COLNAME_FILETYPES;
		static const char* S_INIT_CREATEDBY;
		static const char* S_INIT_UPDATEDBY;
		static const std::string S_VALUE;
		static const std::string S_VALUE_LENGTH;
		static const int MIMETYPEID_INIT_VALUE;
		static const std::string NAME_INIT_VALUE;
		static const std::string FILETYPES_INIT_VALUE;
		static const int MIMETYPEID_MIN_VALUE;
		static const std::string::size_type NAME_MAX_LEN;
		static const std::string::size_type FILETYPES_MAX_LEN;
	protected:
		uuid_t createdByUserId;
		std::chrono::system_clock::time_point createdAt;
		uuid_t updatedByUserId;
		std::chrono::system_clock::time_point updatedAt;
		int32_t requiredMimeTypeId;
		std::string* requiredName;
		std::string* optionalFileTypes;
		int32_t requiredRevision;
	public:
		CFIntMimeTypeBuff();

		CFIntMimeTypeBuff( const CFIntMimeTypeBuff& src );

		virtual ~CFIntMimeTypeBuff();

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

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );

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
		cfint::CFIntMimeTypeBuff operator =( cfint::CFIntMimeTypeBuff& src );
		cfint::CFIntMimeTypeBuff operator =( cfint::CFIntMimeTypeHBuff& src );

		virtual std::string toString();
	};
}

namespace std {

	bool operator <(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );
	bool operator <(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator <(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator <(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator <(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator <=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );
	bool operator <=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator <=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator <=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator <=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator ==(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );
	bool operator ==(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator ==(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator ==(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator ==(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator !=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );
	bool operator !=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator !=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator !=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator !=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator >=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );
	bool operator >=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator >=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator >=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator >=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	bool operator >(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs );

	bool operator >(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs );
	bool operator >(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs );
	bool operator >(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs );
	bool operator >(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs );

	template<> struct hash<cfint::CFIntMimeTypeBuff> {
		typedef cfint::CFIntMimeTypeBuff argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

