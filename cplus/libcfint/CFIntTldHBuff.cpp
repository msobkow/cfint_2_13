// Description: C++18 implementation of a Tld history buffer object.

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

using namespace std;

#include <cfint/CFIntHPKey.hpp>
#include <cfint/CFIntTldPKey.hpp>
#include <cfint/CFIntTldBuff.hpp>
#include <cfint/CFIntTldHPKey.hpp>
#include <cfint/CFIntTldHBuff.hpp>
#include <cfint/CFIntTldByTenantIdxKey.hpp>
#include <cfint/CFIntTldByNameIdxKey.hpp>

namespace cfint {

	const std::string CFIntTldHBuff::CLASS_NAME( "CFIntTldHBuff" );
	CFIntTldHBuff::CFIntTldHBuff()
	: CFIntHPKey(), cflib::ICFLibCloneableObj() {
		requiredTenantId = cfint::CFIntTldBuff::TENANTID_INIT_VALUE;
		requiredId = cfint::CFIntTldBuff::ID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntTldBuff::NAME_INIT_VALUE );
		optionalDescription = NULL;
	}

	CFIntTldHBuff::CFIntTldHBuff( const CFIntTldHBuff& src )
	: CFIntHPKey(), cflib::ICFLibCloneableObj() {
		requiredTenantId = cfint::CFIntTldBuff::TENANTID_INIT_VALUE;
		requiredId = cfint::CFIntTldBuff::ID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntTldBuff::NAME_INIT_VALUE );
		optionalDescription = NULL;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredId( src.getRequiredId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalDescriptionNull() ) {
			setOptionalDescriptionNull();
		}
		else {
			setOptionalDescriptionValue( src.getOptionalDescriptionValue() );
		}
	}

	CFIntTldHBuff::~CFIntTldHBuff() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		if( optionalDescription != NULL ) {
			delete optionalDescription;
			optionalDescription = NULL;
		}
	}

	cflib::ICFLibCloneableObj* CFIntTldHBuff::clone() {
		CFIntTldHBuff* copy = new CFIntTldHBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const int64_t CFIntTldHBuff::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntTldHBuff::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntTldHBuff::setRequiredTenantId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTenantId" );
		if( value < cfint::CFIntTldBuff::TENANTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntTldBuff::TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	const int64_t CFIntTldHBuff::getRequiredId() const {
		return( requiredId );
	}

	const int64_t* CFIntTldHBuff::getRequiredIdReference() const {
		return( &requiredId );
	}

	void CFIntTldHBuff::setRequiredId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredId" );
		if( value < cfint::CFIntTldBuff::ID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntTldBuff::ID_MIN_VALUE );
		}
		requiredId = value;
	}

	const std::string& CFIntTldHBuff::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntTldHBuff::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntTldHBuff::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFIntTldBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntTldBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	const std::string& CFIntTldHBuff::getOptionalDescriptionValue() const {
		static const std::string S_ProcName( "getOptionalDescriptionValue" );
		if( optionalDescription == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalDescription );
	}

	const std::string* CFIntTldHBuff::getOptionalDescriptionReference() const {
		return( optionalDescription );
	}

	const bool CFIntTldHBuff::isOptionalDescriptionNull() const {
		return( optionalDescription == NULL );
	}

	void CFIntTldHBuff::setOptionalDescriptionNull() {
		if( optionalDescription != NULL ) {
			delete optionalDescription;
			optionalDescription = NULL;
		}
	}

	void CFIntTldHBuff::setOptionalDescriptionValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalDescriptionValue" );
		if( value.length() > CFIntTldBuff::DESCRIPTION_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntTldBuff::DESCRIPTION_MAX_LEN );
		}
		if( optionalDescription != NULL ) {
			delete optionalDescription;
			optionalDescription = NULL;
		}
		optionalDescription = new std::string( value );
	}

	size_t CFIntTldHBuff::hashCode() const {
		size_t hashCode = CFIntHPKey::hashCode();
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		if( ! isOptionalDescriptionNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalDescriptionValue() );
		}
		return( hashCode );
	}

	CFIntTldHBuff CFIntTldHBuff::operator =( cfint::CFIntTldBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredId( src.getRequiredId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalDescriptionNull() ) {
			setOptionalDescriptionNull();
		}
		else {
			setOptionalDescriptionValue( src.getOptionalDescriptionValue() );
		}
		return( *this );
	}

	CFIntTldHBuff CFIntTldHBuff::operator =( cfint::CFIntTldHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredId( src.getRequiredId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalDescriptionNull() ) {
			setOptionalDescriptionNull();
		}
		else {
			setOptionalDescriptionValue( src.getOptionalDescriptionValue() );
		}
		return( *this );
	}

	bool CFIntTldHBuff::operator <( const CFIntTldByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTldHBuff::operator <( const CFIntTldByNameIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
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

	bool CFIntTldHBuff::operator <( const CFIntTldPKey& rhs ) {
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

	bool CFIntTldHBuff::operator <( const CFIntTldHPKey& rhs ) {
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

	bool CFIntTldHBuff::operator <( const CFIntTldHBuff& rhs ) {
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

	bool CFIntTldHBuff::operator <( const CFIntTldBuff& rhs ) {
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

	bool CFIntTldHBuff::operator <=( const CFIntTldByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTldHBuff::operator <=( const CFIntTldByNameIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
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

	bool CFIntTldHBuff::operator <=( const CFIntTldPKey& rhs ) {
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

	bool CFIntTldHBuff::operator <=( const CFIntTldHPKey& rhs ) {
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

	bool CFIntTldHBuff::operator <=( const CFIntTldHBuff& rhs ) {
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

	bool CFIntTldHBuff::operator <=( const CFIntTldBuff& rhs ) {
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

	bool CFIntTldHBuff::operator ==( const CFIntTldByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTldHBuff::operator ==( const CFIntTldByNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTldHBuff::operator ==( const CFIntTldPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTldHBuff::operator ==( const CFIntTldHPKey& rhs ) {
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

	bool CFIntTldHBuff::operator ==( const CFIntTldHBuff& rhs ) {
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

	bool CFIntTldHBuff::operator ==( const CFIntTldBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
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

	bool CFIntTldHBuff::operator !=( const CFIntTldByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTldHBuff::operator !=( const CFIntTldByNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTldHBuff::operator !=( const CFIntTldPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTldHBuff::operator !=( const CFIntTldHPKey& rhs ) {
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

	bool CFIntTldHBuff::operator !=( const CFIntTldHBuff& rhs ) {
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

	bool CFIntTldHBuff::operator !=( const CFIntTldBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
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

	bool CFIntTldHBuff::operator >=( const CFIntTldByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTldHBuff::operator >=( const CFIntTldByNameIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
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

	bool CFIntTldHBuff::operator >=( const CFIntTldPKey& rhs ) {
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

	bool CFIntTldHBuff::operator >=( const CFIntTldHPKey& rhs ) {
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

	bool CFIntTldHBuff::operator >=( const CFIntTldHBuff& rhs ) {
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

	bool CFIntTldHBuff::operator >=( const CFIntTldBuff& rhs ) {
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

	bool CFIntTldHBuff::operator >( const CFIntTldByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTldHBuff::operator >( const CFIntTldByNameIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
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

	bool CFIntTldHBuff::operator >( const CFIntTldPKey& rhs ) {
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

	bool CFIntTldHBuff::operator >( const CFIntTldHPKey& rhs ) {
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

	bool CFIntTldHBuff::operator >( const CFIntTldHBuff& rhs ) {
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

	bool CFIntTldHBuff::operator >( const CFIntTldBuff& rhs ) {
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

	std::string CFIntTldHBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTldHBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
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
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		if( ! isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, getOptionalDescriptionValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
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

	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs ) {
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

	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs ) {
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

	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs ) {
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

	bool operator <(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
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

	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs ) {
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

	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs ) {
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

	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs ) {
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

	bool operator ==(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
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

	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs ) {
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

	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs ) {
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

	bool operator !=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
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

	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
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

	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs ) {
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

	bool operator >=(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
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

	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldPKey& rhs ) {
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

	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHPKey& rhs ) {
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

	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldHBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntTldHBuff& lhs, const cfint::CFIntTldBuff& rhs ) {
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

