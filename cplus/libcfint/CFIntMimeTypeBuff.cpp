// Description: C++18 implementation for a MimeType buffer object.

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

using namespace std;

#include <cfint/ICFIntPublic.hpp>

#include <cfint/CFIntMimeTypeByUNameIdxKey.hpp>
#include <cfint/CFIntSchema.hpp>

namespace cfint {

	const std::string CFIntMimeTypeBuff::S_VALUE( "value" );
	const std::string CFIntMimeTypeBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFIntMimeTypeBuff::GENDEFNAME( "MimeType" );
	const classcode_t CFIntMimeTypeBuff::CLASS_CODE = 0xa103L;
	const std::string CFIntMimeTypeBuff::CLASS_NAME( "CFIntMimeTypeBuff" );
		const std::string CFIntMimeTypeBuff::COLNAME_MIMETYPEID( "MimeTypeId" );
		const std::string CFIntMimeTypeBuff::COLNAME_NAME( "Name" );
		const std::string CFIntMimeTypeBuff::COLNAME_FILETYPES( "FileTypes" );
	const char* CFIntMimeTypeBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFIntMimeTypeBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int CFIntMimeTypeBuff::MIMETYPEID_INIT_VALUE = 0L;
	const std::string CFIntMimeTypeBuff::NAME_INIT_VALUE( "" );
	const std::string CFIntMimeTypeBuff::FILETYPES_INIT_VALUE( "" );
	const int CFIntMimeTypeBuff::MIMETYPEID_MIN_VALUE = 0L;
	const std::string::size_type CFIntMimeTypeBuff::NAME_MAX_LEN = 128;
	const std::string::size_type CFIntMimeTypeBuff::FILETYPES_MAX_LEN = 128;

	CFIntMimeTypeBuff::CFIntMimeTypeBuff()
	: cflib::ICFLibCloneableObj()
	{
		requiredRevision = 1;
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		createdAt = cflib::CFLib::getUTCTimestampInstance();
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
		updatedAt = cflib::CFLib::getUTCTimestampInstance();
		requiredMimeTypeId = cfint::CFIntMimeTypeBuff::MIMETYPEID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntMimeTypeBuff::NAME_INIT_VALUE );
		optionalFileTypes = NULL;
	}

	CFIntMimeTypeBuff::CFIntMimeTypeBuff( const CFIntMimeTypeBuff& src )
	: cflib::ICFLibCloneableObj()
	{
		requiredRevision = 1;
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		createdAt = cflib::CFLib::getUTCTimestampInstance();
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
		updatedAt = cflib::CFLib::getUTCTimestampInstance();
		requiredMimeTypeId = cfint::CFIntMimeTypeBuff::MIMETYPEID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntMimeTypeBuff::NAME_INIT_VALUE );
		optionalFileTypes = NULL;
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalFileTypesNull() ) {
			setOptionalFileTypesNull();
		}
		else {
			setOptionalFileTypesValue( src.getOptionalFileTypesValue() );
		}
	}

	CFIntMimeTypeBuff::~CFIntMimeTypeBuff() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		if( optionalFileTypes != NULL ) {
			delete optionalFileTypes;
			optionalFileTypes = NULL;
		}
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFIntMimeTypeBuff::clone() {
		CFIntMimeTypeBuff* copy = new CFIntMimeTypeBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFIntMimeTypeBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntMimeTypeBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntMimeTypeBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFIntMimeTypeBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFIntMimeTypeBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFIntMimeTypeBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFIntMimeTypeBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFIntMimeTypeBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFIntMimeTypeBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFIntMimeTypeBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFIntMimeTypeBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int32_t CFIntMimeTypeBuff::getRequiredMimeTypeId() const {
		return( requiredMimeTypeId );
	}

	const int32_t* CFIntMimeTypeBuff::getRequiredMimeTypeIdReference() const {
		return( &requiredMimeTypeId );
	}

	void CFIntMimeTypeBuff::setRequiredMimeTypeId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredMimeTypeId" );
		if( value < cfint::CFIntMimeTypeBuff::MIMETYPEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntMimeTypeBuff::MIMETYPEID_MIN_VALUE );
		}
		requiredMimeTypeId = value;
	}

	const std::string& CFIntMimeTypeBuff::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntMimeTypeBuff::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntMimeTypeBuff::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFIntMimeTypeBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntMimeTypeBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	const bool CFIntMimeTypeBuff::isOptionalFileTypesNull() const {
		return( optionalFileTypes == NULL );
	}

	const std::string& CFIntMimeTypeBuff::getOptionalFileTypesValue() const {
		static const std::string S_ProcName( "getOptionalFileTypesValue" );
		if( optionalFileTypes == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalFileTypes );
	}

	const std::string* CFIntMimeTypeBuff::getOptionalFileTypesReference() const {
		return( optionalFileTypes );
	}

	void CFIntMimeTypeBuff::setOptionalFileTypesNull() {
		if( optionalFileTypes != NULL ) {
			delete optionalFileTypes;
			optionalFileTypes = NULL;
		}
	}

	void CFIntMimeTypeBuff::setOptionalFileTypesValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalFileTypesValue" );
		if( value.length() > CFIntMimeTypeBuff::FILETYPES_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntMimeTypeBuff::FILETYPES_MAX_LEN );
		}
		if( optionalFileTypes != NULL ) {
			delete optionalFileTypes;
			optionalFileTypes = NULL;
		}
		optionalFileTypes = new std::string( value );
	}

	int32_t CFIntMimeTypeBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFIntMimeTypeBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFIntMimeTypeBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + getRequiredMimeTypeId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		if( ! isOptionalFileTypesNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalFileTypesValue() );
		}
		return( hashCode );
	}

	CFIntMimeTypeBuff CFIntMimeTypeBuff::operator =( cfint::CFIntMimeTypeBuff& src ) {
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalFileTypesNull() ) {
			setOptionalFileTypesNull();
		}
		else {
			setOptionalFileTypesValue( src.getOptionalFileTypesValue() );
		}
		return( *this );
	}

	CFIntMimeTypeBuff CFIntMimeTypeBuff::operator =( cfint::CFIntMimeTypeHBuff& src ) {
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalFileTypesNull() ) {
			setOptionalFileTypesNull();
		}
		else {
			setOptionalFileTypesValue( src.getOptionalFileTypesValue() );
		}
		return( *this );
	}

	bool CFIntMimeTypeBuff::operator <( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator <( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator <( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator <( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
			if( getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator <( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
			if( getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator <=( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator <=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator <=( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator <=( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
			if( getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator <=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
			if( getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator ==( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator ==( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator ==( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator ==( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( ! rhs.isOptionalFileTypesNull() ) {
				if( getOptionalFileTypesValue() != rhs.getOptionalFileTypesValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator ==( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( ! rhs.isOptionalFileTypesNull() ) {
				if( getOptionalFileTypesValue() != rhs.getOptionalFileTypesValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator !=( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator !=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator !=( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator !=( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( getOptionalFileTypesValue() != rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator !=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( getOptionalFileTypesValue() != rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator >=( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator >=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator >=( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator >=( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator >=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntMimeTypeBuff::operator >( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator >( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator >( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator >( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFIntMimeTypeBuff::operator >( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	std::string CFIntMimeTypeBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMimeTypeBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_MimeTypeId( "MimeTypeId" );
		static const std::string S_Name( "Name" );
		static const std::string S_FileTypes( "FileTypes" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_MimeTypeId, getRequiredMimeTypeId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		if( ! isOptionalFileTypesNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_FileTypes, getOptionalFileTypesValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
			if( lhs.getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
			if( lhs.getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
			if( lhs.getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
			if( lhs.getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( ! rhs.isOptionalFileTypesNull() ) {
				if( lhs.getOptionalFileTypesValue() != rhs.getOptionalFileTypesValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( ! rhs.isOptionalFileTypesNull() ) {
				if( lhs.getOptionalFileTypesValue() != rhs.getOptionalFileTypesValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( lhs.getOptionalFileTypesValue() != rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( lhs.getOptionalFileTypesValue() != rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( lhs.getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( lhs.getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( lhs.getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalFileTypesNull() ) {
			if( rhs.isOptionalFileTypesNull() ) {
				return( true );
			}
			if( lhs.getOptionalFileTypesValue() < rhs.getOptionalFileTypesValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFileTypesValue() > rhs.getOptionalFileTypesValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFileTypesNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

