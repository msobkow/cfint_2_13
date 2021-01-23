// Description: C++18 implementation of a MimeType history buffer object.

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

#include <cfint/CFIntHPKey.hpp>
#include <cfint/CFIntMimeTypePKey.hpp>
#include <cfint/CFIntMimeTypeBuff.hpp>
#include <cfint/CFIntMimeTypeHPKey.hpp>
#include <cfint/CFIntMimeTypeHBuff.hpp>
#include <cfint/CFIntMimeTypeByUNameIdxKey.hpp>

namespace cfint {

	const std::string CFIntMimeTypeHBuff::CLASS_NAME( "CFIntMimeTypeHBuff" );
	CFIntMimeTypeHBuff::CFIntMimeTypeHBuff()
	: CFIntHPKey(), cflib::ICFLibCloneableObj() {
		requiredMimeTypeId = cfint::CFIntMimeTypeBuff::MIMETYPEID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntMimeTypeBuff::NAME_INIT_VALUE );
		optionalFileTypes = NULL;
	}

	CFIntMimeTypeHBuff::CFIntMimeTypeHBuff( const CFIntMimeTypeHBuff& src )
	: CFIntHPKey(), cflib::ICFLibCloneableObj() {
		requiredMimeTypeId = cfint::CFIntMimeTypeBuff::MIMETYPEID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntMimeTypeBuff::NAME_INIT_VALUE );
		optionalFileTypes = NULL;
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalFileTypesNull() ) {
			setOptionalFileTypesNull();
		}
		else {
			setOptionalFileTypesValue( src.getOptionalFileTypesValue() );
		}
	}

	CFIntMimeTypeHBuff::~CFIntMimeTypeHBuff() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		if( optionalFileTypes != NULL ) {
			delete optionalFileTypes;
			optionalFileTypes = NULL;
		}
	}

	cflib::ICFLibCloneableObj* CFIntMimeTypeHBuff::clone() {
		CFIntMimeTypeHBuff* copy = new CFIntMimeTypeHBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const int32_t CFIntMimeTypeHBuff::getRequiredMimeTypeId() const {
		return( requiredMimeTypeId );
	}

	const int32_t* CFIntMimeTypeHBuff::getRequiredMimeTypeIdReference() const {
		return( &requiredMimeTypeId );
	}

	void CFIntMimeTypeHBuff::setRequiredMimeTypeId( const int32_t value ) {
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

	const std::string& CFIntMimeTypeHBuff::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntMimeTypeHBuff::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntMimeTypeHBuff::setRequiredName( const std::string& value ) {
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

	const std::string& CFIntMimeTypeHBuff::getOptionalFileTypesValue() const {
		static const std::string S_ProcName( "getOptionalFileTypesValue" );
		if( optionalFileTypes == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalFileTypes );
	}

	const std::string* CFIntMimeTypeHBuff::getOptionalFileTypesReference() const {
		return( optionalFileTypes );
	}

	const bool CFIntMimeTypeHBuff::isOptionalFileTypesNull() const {
		return( optionalFileTypes == NULL );
	}

	void CFIntMimeTypeHBuff::setOptionalFileTypesNull() {
		if( optionalFileTypes != NULL ) {
			delete optionalFileTypes;
			optionalFileTypes = NULL;
		}
	}

	void CFIntMimeTypeHBuff::setOptionalFileTypesValue( const std::string& value ) {
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

	size_t CFIntMimeTypeHBuff::hashCode() const {
		size_t hashCode = CFIntHPKey::hashCode();
		hashCode = hashCode + getRequiredMimeTypeId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		if( ! isOptionalFileTypesNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalFileTypesValue() );
		}
		return( hashCode );
	}

	CFIntMimeTypeHBuff CFIntMimeTypeHBuff::operator =( cfint::CFIntMimeTypeBuff& src ) {
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

	CFIntMimeTypeHBuff CFIntMimeTypeHBuff::operator =( cfint::CFIntMimeTypeHBuff& src ) {
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

	bool CFIntMimeTypeHBuff::operator <( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHBuff::operator <( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHBuff::operator <( const CFIntMimeTypeHPKey& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() >= rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() <= rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() >= rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() <= rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHBuff::operator <( const CFIntMimeTypeHBuff& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() >= rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() <= rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() >= rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() <= rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool CFIntMimeTypeHBuff::operator <( const CFIntMimeTypeBuff& rhs ) {
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

	bool CFIntMimeTypeHBuff::operator <=( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHBuff::operator <=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHBuff::operator <=( const CFIntMimeTypeHPKey& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHBuff::operator <=( const CFIntMimeTypeHBuff& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool CFIntMimeTypeHBuff::operator <=( const CFIntMimeTypeBuff& rhs ) {
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

	bool CFIntMimeTypeHBuff::operator ==( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypeHBuff::operator ==( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypeHBuff::operator ==( const CFIntMimeTypeHPKey& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypeHBuff::operator ==( const CFIntMimeTypeHBuff& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool CFIntMimeTypeHBuff::operator ==( const CFIntMimeTypeBuff& rhs ) {
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

	bool CFIntMimeTypeHBuff::operator !=( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHBuff::operator !=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHBuff::operator !=( const CFIntMimeTypeHPKey& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHBuff::operator !=( const CFIntMimeTypeHBuff& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
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

	bool CFIntMimeTypeHBuff::operator !=( const CFIntMimeTypeBuff& rhs ) {
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

	bool CFIntMimeTypeHBuff::operator >=( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHBuff::operator >=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHBuff::operator >=( const CFIntMimeTypeHPKey& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHBuff::operator >=( const CFIntMimeTypeHBuff& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool CFIntMimeTypeHBuff::operator >=( const CFIntMimeTypeBuff& rhs ) {
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

	bool CFIntMimeTypeHBuff::operator >( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHBuff::operator >( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHBuff::operator >( const CFIntMimeTypeHPKey& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHBuff::operator >( const CFIntMimeTypeHBuff& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool CFIntMimeTypeHBuff::operator >( const CFIntMimeTypeBuff& rhs ) {
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

	std::string CFIntMimeTypeHBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMimeTypeHBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_MimeTypeId( "MimeTypeId" );
		static const std::string S_Name( "Name" );
		static const std::string S_FileTypes( "FileTypes" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_MimeTypeId, getRequiredMimeTypeId() ) );
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

	bool operator <(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool operator <(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool operator <=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
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

	bool operator ==(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool operator ==(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
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

	bool operator !=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
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

	bool operator !=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
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

	bool operator >=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool operator >=(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
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

	bool operator >(const  cfint::CFIntMimeTypeHBuff& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
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

