// Description: C++18 implementation of a MinorVersion history buffer object.

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

#include <cfint/CFIntHPKey.hpp>
#include <cfint/CFIntMinorVersionPKey.hpp>
#include <cfint/CFIntMinorVersionBuff.hpp>
#include <cfint/CFIntMinorVersionHPKey.hpp>
#include <cfint/CFIntMinorVersionHBuff.hpp>
#include <cfint/CFIntMinorVersionByTenantIdxKey.hpp>
#include <cfint/CFIntMinorVersionByMajorVerIdxKey.hpp>
#include <cfint/CFIntMinorVersionByNameIdxKey.hpp>

namespace cfint {

	const std::string CFIntMinorVersionHBuff::CLASS_NAME( "CFIntMinorVersionHBuff" );
	CFIntMinorVersionHBuff::CFIntMinorVersionHBuff()
	: CFIntHPKey(), cflib::ICFLibCloneableObj() {
		requiredTenantId = cfint::CFIntMinorVersionBuff::TENANTID_INIT_VALUE;
		requiredId = cfint::CFIntMinorVersionBuff::ID_INIT_VALUE;
		requiredMajorVersionId = cfint::CFIntMinorVersionBuff::MAJORVERSIONID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntMinorVersionBuff::NAME_INIT_VALUE );
		optionalDescription = NULL;
	}

	CFIntMinorVersionHBuff::CFIntMinorVersionHBuff( const CFIntMinorVersionHBuff& src )
	: CFIntHPKey(), cflib::ICFLibCloneableObj() {
		requiredTenantId = cfint::CFIntMinorVersionBuff::TENANTID_INIT_VALUE;
		requiredId = cfint::CFIntMinorVersionBuff::ID_INIT_VALUE;
		requiredMajorVersionId = cfint::CFIntMinorVersionBuff::MAJORVERSIONID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntMinorVersionBuff::NAME_INIT_VALUE );
		optionalDescription = NULL;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredId( src.getRequiredId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredMajorVersionId( src.getRequiredMajorVersionId() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalDescriptionNull() ) {
			setOptionalDescriptionNull();
		}
		else {
			setOptionalDescriptionValue( src.getOptionalDescriptionValue() );
		}
	}

	CFIntMinorVersionHBuff::~CFIntMinorVersionHBuff() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		if( optionalDescription != NULL ) {
			delete optionalDescription;
			optionalDescription = NULL;
		}
	}

	cflib::ICFLibCloneableObj* CFIntMinorVersionHBuff::clone() {
		CFIntMinorVersionHBuff* copy = new CFIntMinorVersionHBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const int64_t CFIntMinorVersionHBuff::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntMinorVersionHBuff::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntMinorVersionHBuff::setRequiredTenantId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTenantId" );
		if( value < cfint::CFIntMinorVersionBuff::TENANTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntMinorVersionBuff::TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	const int64_t CFIntMinorVersionHBuff::getRequiredId() const {
		return( requiredId );
	}

	const int64_t* CFIntMinorVersionHBuff::getRequiredIdReference() const {
		return( &requiredId );
	}

	void CFIntMinorVersionHBuff::setRequiredId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredId" );
		if( value < cfint::CFIntMinorVersionBuff::ID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntMinorVersionBuff::ID_MIN_VALUE );
		}
		requiredId = value;
	}

	const int64_t CFIntMinorVersionHBuff::getRequiredMajorVersionId() const {
		return( requiredMajorVersionId );
	}

	const int64_t* CFIntMinorVersionHBuff::getRequiredMajorVersionIdReference() const {
		return( &requiredMajorVersionId );
	}

	void CFIntMinorVersionHBuff::setRequiredMajorVersionId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredMajorVersionId" );
		if( value < cfint::CFIntMinorVersionBuff::MAJORVERSIONID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntMinorVersionBuff::MAJORVERSIONID_MIN_VALUE );
		}
		requiredMajorVersionId = value;
	}

	const std::string& CFIntMinorVersionHBuff::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntMinorVersionHBuff::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntMinorVersionHBuff::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFIntMinorVersionBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntMinorVersionBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	const std::string& CFIntMinorVersionHBuff::getOptionalDescriptionValue() const {
		static const std::string S_ProcName( "getOptionalDescriptionValue" );
		if( optionalDescription == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalDescription );
	}

	const std::string* CFIntMinorVersionHBuff::getOptionalDescriptionReference() const {
		return( optionalDescription );
	}

	const bool CFIntMinorVersionHBuff::isOptionalDescriptionNull() const {
		return( optionalDescription == NULL );
	}

	void CFIntMinorVersionHBuff::setOptionalDescriptionNull() {
		if( optionalDescription != NULL ) {
			delete optionalDescription;
			optionalDescription = NULL;
		}
	}

	void CFIntMinorVersionHBuff::setOptionalDescriptionValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalDescriptionValue" );
		if( value.length() > CFIntMinorVersionBuff::DESCRIPTION_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntMinorVersionBuff::DESCRIPTION_MAX_LEN );
		}
		if( optionalDescription != NULL ) {
			delete optionalDescription;
			optionalDescription = NULL;
		}
		optionalDescription = new std::string( value );
	}

	size_t CFIntMinorVersionHBuff::hashCode() const {
		size_t hashCode = CFIntHPKey::hashCode();
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredId() );
		hashCode = hashCode + (int)( getRequiredMajorVersionId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		if( ! isOptionalDescriptionNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalDescriptionValue() );
		}
		return( hashCode );
	}

	CFIntMinorVersionHBuff CFIntMinorVersionHBuff::operator =( cfint::CFIntMinorVersionBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredId( src.getRequiredId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredMajorVersionId( src.getRequiredMajorVersionId() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalDescriptionNull() ) {
			setOptionalDescriptionNull();
		}
		else {
			setOptionalDescriptionValue( src.getOptionalDescriptionValue() );
		}
		return( *this );
	}

	CFIntMinorVersionHBuff CFIntMinorVersionHBuff::operator =( cfint::CFIntMinorVersionHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredId( src.getRequiredId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredMajorVersionId( src.getRequiredMajorVersionId() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalDescriptionNull() ) {
			setOptionalDescriptionNull();
		}
		else {
			setOptionalDescriptionValue( src.getOptionalDescriptionValue() );
		}
		return( *this );
	}

	bool CFIntMinorVersionHBuff::operator <( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator <( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator <( const CFIntMinorVersionByNameIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator <( const CFIntMinorVersionPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator <( const CFIntMinorVersionHPKey& rhs ) {
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
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator <( const CFIntMinorVersionHBuff& rhs ) {
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
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
			if( getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator <( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
			if( getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator <=( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator <=( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator <=( const CFIntMinorVersionByNameIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator <=( const CFIntMinorVersionPKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator <=( const CFIntMinorVersionHPKey& rhs ) {
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
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator <=( const CFIntMinorVersionHBuff& rhs ) {
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
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
			if( getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator <=( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
			if( getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator ==( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator ==( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator ==( const CFIntMinorVersionByNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator ==( const CFIntMinorVersionPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator ==( const CFIntMinorVersionHPKey& rhs ) {
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
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator ==( const CFIntMinorVersionHBuff& rhs ) {
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
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( ! rhs.isOptionalDescriptionNull() ) {
				if( getOptionalDescriptionValue() != rhs.getOptionalDescriptionValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator ==( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( ! rhs.isOptionalDescriptionNull() ) {
				if( getOptionalDescriptionValue() != rhs.getOptionalDescriptionValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator !=( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator !=( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator !=( const CFIntMinorVersionByNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator !=( const CFIntMinorVersionPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator !=( const CFIntMinorVersionHPKey& rhs ) {
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
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator !=( const CFIntMinorVersionHBuff& rhs ) {
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
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( getOptionalDescriptionValue() != rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator !=( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( getOptionalDescriptionValue() != rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator >=( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator >=( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator >=( const CFIntMinorVersionByNameIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator >=( const CFIntMinorVersionPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator >=( const CFIntMinorVersionHPKey& rhs ) {
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
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator >=( const CFIntMinorVersionHBuff& rhs ) {
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
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator >=( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntMinorVersionHBuff::operator >( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator >( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator >( const CFIntMinorVersionByNameIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator >( const CFIntMinorVersionPKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator >( const CFIntMinorVersionHPKey& rhs ) {
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
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator >( const CFIntMinorVersionHBuff& rhs ) {
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
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFIntMinorVersionHBuff::operator >( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	std::string CFIntMinorVersionHBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMinorVersionHBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_MajorVersionId( "MajorVersionId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_MajorVersionId, getRequiredMajorVersionId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		if( ! isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs ) {
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
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
			if( lhs.getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
			if( lhs.getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs ) {
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
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
			if( lhs.getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
			if( lhs.getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs ) {
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
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( ! rhs.isOptionalDescriptionNull() ) {
				if( lhs.getOptionalDescriptionValue() != rhs.getOptionalDescriptionValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( ! rhs.isOptionalDescriptionNull() ) {
				if( lhs.getOptionalDescriptionValue() != rhs.getOptionalDescriptionValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs ) {
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
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( lhs.getOptionalDescriptionValue() != rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( lhs.getOptionalDescriptionValue() != rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs ) {
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
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( lhs.getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( lhs.getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionPKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHPKey& rhs ) {
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
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( lhs.getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMinorVersionHBuff& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() < rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		else if( lhs.getRequiredMajorVersionId() > rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( ! lhs.isOptionalDescriptionNull() ) {
			if( rhs.isOptionalDescriptionNull() ) {
				return( true );
			}
			if( lhs.getOptionalDescriptionValue() < rhs.getOptionalDescriptionValue() ) {
				return( false );
			}
			else if( lhs.getOptionalDescriptionValue() > rhs.getOptionalDescriptionValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalDescriptionNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

