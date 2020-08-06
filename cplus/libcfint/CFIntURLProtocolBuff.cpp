// Description: C++18 implementation for a URLProtocol buffer object.

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

using namespace std;

#include <cfint/ICFIntPublic.hpp>

#include <cfint/CFIntURLProtocolByUNameIdxKey.hpp>
#include <cfint/CFIntURLProtocolByIsSecureIdxKey.hpp>
#include <cfint/CFIntSchema.hpp>

namespace cfint {

	const std::string CFIntURLProtocolBuff::S_VALUE( "value" );
	const std::string CFIntURLProtocolBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFIntURLProtocolBuff::GENDEFNAME( "URLProtocol" );
	const classcode_t CFIntURLProtocolBuff::CLASS_CODE = 0xa109L;
	const std::string CFIntURLProtocolBuff::CLASS_NAME( "CFIntURLProtocolBuff" );
		const std::string CFIntURLProtocolBuff::COLNAME_URLPROTOCOLID( "URLProtocolId" );
		const std::string CFIntURLProtocolBuff::COLNAME_NAME( "Name" );
		const std::string CFIntURLProtocolBuff::COLNAME_DESCRIPTION( "Description" );
		const std::string CFIntURLProtocolBuff::COLNAME_ISSECURE( "IsSecure" );
	const char* CFIntURLProtocolBuff::S_INIT_CREATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const char* CFIntURLProtocolBuff::S_INIT_UPDATEDBY = "654dbba0-eda7-11e1-aff1-0800200c9a66";
	const int CFIntURLProtocolBuff::URLPROTOCOLID_INIT_VALUE = 0L;
	const std::string CFIntURLProtocolBuff::NAME_INIT_VALUE( "" );
	const std::string CFIntURLProtocolBuff::DESCRIPTION_INIT_VALUE( "" );
	const bool CFIntURLProtocolBuff::ISSECURE_INIT_VALUE = false;
	const int CFIntURLProtocolBuff::URLPROTOCOLID_MIN_VALUE = 0L;
	const std::string::size_type CFIntURLProtocolBuff::NAME_MAX_LEN = 16;
	const std::string::size_type CFIntURLProtocolBuff::DESCRIPTION_MAX_LEN = 50;

	CFIntURLProtocolBuff::CFIntURLProtocolBuff()
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
		requiredURLProtocolId = cfint::CFIntURLProtocolBuff::URLPROTOCOLID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntURLProtocolBuff::NAME_INIT_VALUE );
		requiredDescription = new std::string( cfint::CFIntURLProtocolBuff::DESCRIPTION_INIT_VALUE );
		requiredIsSecure = cfint::CFIntURLProtocolBuff::ISSECURE_INIT_VALUE;
	}

	CFIntURLProtocolBuff::CFIntURLProtocolBuff( const CFIntURLProtocolBuff& src )
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
		requiredURLProtocolId = cfint::CFIntURLProtocolBuff::URLPROTOCOLID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntURLProtocolBuff::NAME_INIT_VALUE );
		requiredDescription = new std::string( cfint::CFIntURLProtocolBuff::DESCRIPTION_INIT_VALUE );
		requiredIsSecure = cfint::CFIntURLProtocolBuff::ISSECURE_INIT_VALUE;
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredIsSecure( src.getRequiredIsSecure() );
	}

	CFIntURLProtocolBuff::~CFIntURLProtocolBuff() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		for( int i = 0; i < 16; i++ ) {
			createdByUserId[i] = 0;
		}
		for( int i = 0; i < 16; i++ ) {
			updatedByUserId[i] = 0;
		}
	}

	cflib::ICFLibCloneableObj* CFIntURLProtocolBuff::clone() {
		CFIntURLProtocolBuff* copy = new CFIntURLProtocolBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFIntURLProtocolBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntURLProtocolBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntURLProtocolBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const uuid_ptr_t CFIntURLProtocolBuff::getCreatedByUserId() const {
		return( createdByUserId );
	}

	void CFIntURLProtocolBuff::setCreatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( createdByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFIntURLProtocolBuff::getCreatedAt() const {
		return( createdAt );
	}

	void CFIntURLProtocolBuff::setCreatedAt( const std::chrono::system_clock::time_point& value ) {
		createdAt = value;
	}

	const uuid_ptr_t CFIntURLProtocolBuff::getUpdatedByUserId() const {
		return( updatedByUserId );
	}

	void CFIntURLProtocolBuff::setUpdatedByUserId( const uuid_ptr_t value ) {
		uuid_copy( updatedByUserId, value );
	}

	const std::chrono::system_clock::time_point& CFIntURLProtocolBuff::getUpdatedAt() const {
		return( updatedAt );
	}

	void CFIntURLProtocolBuff::setUpdatedAt( const std::chrono::system_clock::time_point& value ) {
		updatedAt = value;
	}
	const int32_t CFIntURLProtocolBuff::getRequiredURLProtocolId() const {
		return( requiredURLProtocolId );
	}

	const int32_t* CFIntURLProtocolBuff::getRequiredURLProtocolIdReference() const {
		return( &requiredURLProtocolId );
	}

	void CFIntURLProtocolBuff::setRequiredURLProtocolId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredURLProtocolId" );
		if( value < cfint::CFIntURLProtocolBuff::URLPROTOCOLID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntURLProtocolBuff::URLPROTOCOLID_MIN_VALUE );
		}
		requiredURLProtocolId = value;
	}

	const std::string& CFIntURLProtocolBuff::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntURLProtocolBuff::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntURLProtocolBuff::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFIntURLProtocolBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntURLProtocolBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	const std::string& CFIntURLProtocolBuff::getRequiredDescription() const {
		return( *requiredDescription );
	}

	const std::string* CFIntURLProtocolBuff::getRequiredDescriptionReference() const {
		return( requiredDescription );
	}

	void CFIntURLProtocolBuff::setRequiredDescription( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredDescription" );
		if( value.length() > CFIntURLProtocolBuff::DESCRIPTION_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntURLProtocolBuff::DESCRIPTION_MAX_LEN );
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		requiredDescription = new std::string( value );
	}

	const bool CFIntURLProtocolBuff::getRequiredIsSecure() const {
		return( requiredIsSecure );
	}

	const bool* CFIntURLProtocolBuff::getRequiredIsSecureReference() const {
		return( &requiredIsSecure );
	}

	void CFIntURLProtocolBuff::setRequiredIsSecure( const bool value ) {
		requiredIsSecure = value;
	}

	int32_t CFIntURLProtocolBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFIntURLProtocolBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFIntURLProtocolBuff::hashCode() const {
		size_t hashCode = 0L;
		hashCode = hashCode + getRequiredURLProtocolId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredDescription() );
		if( getRequiredIsSecure() ) {
			hashCode = ( hashCode * 2 ) + 1;
		}
		else {
			hashCode = hashCode * 2;
		}
		return( hashCode );
	}

	CFIntURLProtocolBuff CFIntURLProtocolBuff::operator =( cfint::CFIntURLProtocolBuff& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		setCreatedByUserId( src.getCreatedByUserId() );
		setCreatedAt( src.getCreatedAt() );
		setUpdatedByUserId( src.getUpdatedByUserId() );
		setUpdatedAt( src.getUpdatedAt() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredIsSecure( src.getRequiredIsSecure() );
		return( *this );
	}

	CFIntURLProtocolBuff CFIntURLProtocolBuff::operator =( cfint::CFIntURLProtocolHBuff& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredIsSecure( src.getRequiredIsSecure() );
		return( *this );
	}

	bool CFIntURLProtocolBuff::operator <( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator <( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator <( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator <( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator <( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator <( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator <=( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator <=( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator <=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator <=( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator <=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator <=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator ==( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator ==( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator ==( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator ==( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator ==( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator ==( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator !=( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator !=( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator !=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator !=( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator !=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator !=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator >=( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator >=( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator >=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator >=( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator >=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator >=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolBuff::operator >( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator >( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator >( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator >( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator >( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolBuff::operator >( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	std::string CFIntURLProtocolBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntURLProtocolBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_CreatedBy( "CreatedBy" );
		static const std::string S_CreatedAt( "CreatedAt" );
		static const std::string S_UpdatedBy( "UpdatedBy" );
		static const std::string S_UpdatedAt( "UpdatedAt" );
		static const std::string S_URLProtocolId( "URLProtocolId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		static const std::string S_IsSecure( "IsSecure" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_URLProtocolId, getRequiredURLProtocolId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_CreatedBy, getCreatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_CreatedAt, getCreatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_UpdatedBy, getUpdatedByUserId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_UpdatedAt, getUpdatedAt() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, getRequiredDescription() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsSecure, getRequiredIsSecure() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}
}

