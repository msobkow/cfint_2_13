// Description: C++18 implementation of a License history buffer object.

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
#include <cfint/CFIntLicensePKey.hpp>
#include <cfint/CFIntLicenseBuff.hpp>
#include <cfint/CFIntLicenseHPKey.hpp>
#include <cfint/CFIntLicenseHBuff.hpp>
#include <cfint/CFIntLicenseByLicnTenantIdxKey.hpp>
#include <cfint/CFIntLicenseByDomainIdxKey.hpp>
#include <cfint/CFIntLicenseByUNameIdxKey.hpp>

namespace cfint {

	const std::string CFIntLicenseHBuff::CLASS_NAME( "CFIntLicenseHBuff" );
	CFIntLicenseHBuff::CFIntLicenseHBuff()
	: CFIntHPKey(), cflib::ICFLibCloneableObj() {
		requiredTenantId = cfint::CFIntLicenseBuff::TENANTID_INIT_VALUE;
		requiredId = cfint::CFIntLicenseBuff::ID_INIT_VALUE;
		requiredTopDomainId = cfint::CFIntLicenseBuff::TOPDOMAINID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntLicenseBuff::NAME_INIT_VALUE );
		optionalDescription = NULL;
		optionalEmbeddedText = NULL;
		optionalFullText = NULL;
	}

	CFIntLicenseHBuff::CFIntLicenseHBuff( const CFIntLicenseHBuff& src )
	: CFIntHPKey(), cflib::ICFLibCloneableObj() {
		requiredTenantId = cfint::CFIntLicenseBuff::TENANTID_INIT_VALUE;
		requiredId = cfint::CFIntLicenseBuff::ID_INIT_VALUE;
		requiredTopDomainId = cfint::CFIntLicenseBuff::TOPDOMAINID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntLicenseBuff::NAME_INIT_VALUE );
		optionalDescription = NULL;
		optionalEmbeddedText = NULL;
		optionalFullText = NULL;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredId( src.getRequiredId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalDescriptionNull() ) {
			setOptionalDescriptionNull();
		}
		else {
			setOptionalDescriptionValue( src.getOptionalDescriptionValue() );
		}
		if( src.isOptionalEmbeddedTextNull() ) {
			setOptionalEmbeddedTextNull();
		}
		else {
			setOptionalEmbeddedTextValue( src.getOptionalEmbeddedTextValue() );
		}
		if( src.isOptionalFullTextNull() ) {
			setOptionalFullTextNull();
		}
		else {
			setOptionalFullTextValue( src.getOptionalFullTextValue() );
		}
	}

	CFIntLicenseHBuff::~CFIntLicenseHBuff() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		if( optionalDescription != NULL ) {
			delete optionalDescription;
			optionalDescription = NULL;
		}
		if( optionalEmbeddedText != NULL ) {
			delete optionalEmbeddedText;
			optionalEmbeddedText = NULL;
		}
		if( optionalFullText != NULL ) {
			delete optionalFullText;
			optionalFullText = NULL;
		}
	}

	cflib::ICFLibCloneableObj* CFIntLicenseHBuff::clone() {
		CFIntLicenseHBuff* copy = new CFIntLicenseHBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const int64_t CFIntLicenseHBuff::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntLicenseHBuff::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntLicenseHBuff::setRequiredTenantId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTenantId" );
		if( value < cfint::CFIntLicenseBuff::TENANTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntLicenseBuff::TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	const int64_t CFIntLicenseHBuff::getRequiredId() const {
		return( requiredId );
	}

	const int64_t* CFIntLicenseHBuff::getRequiredIdReference() const {
		return( &requiredId );
	}

	void CFIntLicenseHBuff::setRequiredId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredId" );
		if( value < cfint::CFIntLicenseBuff::ID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntLicenseBuff::ID_MIN_VALUE );
		}
		requiredId = value;
	}

	const int64_t CFIntLicenseHBuff::getRequiredTopDomainId() const {
		return( requiredTopDomainId );
	}

	const int64_t* CFIntLicenseHBuff::getRequiredTopDomainIdReference() const {
		return( &requiredTopDomainId );
	}

	void CFIntLicenseHBuff::setRequiredTopDomainId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTopDomainId" );
		if( value < cfint::CFIntLicenseBuff::TOPDOMAINID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntLicenseBuff::TOPDOMAINID_MIN_VALUE );
		}
		requiredTopDomainId = value;
	}

	const std::string& CFIntLicenseHBuff::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntLicenseHBuff::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntLicenseHBuff::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFIntLicenseBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntLicenseBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	const std::string& CFIntLicenseHBuff::getOptionalDescriptionValue() const {
		static const std::string S_ProcName( "getOptionalDescriptionValue" );
		if( optionalDescription == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalDescription );
	}

	const std::string* CFIntLicenseHBuff::getOptionalDescriptionReference() const {
		return( optionalDescription );
	}

	const bool CFIntLicenseHBuff::isOptionalDescriptionNull() const {
		return( optionalDescription == NULL );
	}

	void CFIntLicenseHBuff::setOptionalDescriptionNull() {
		if( optionalDescription != NULL ) {
			delete optionalDescription;
			optionalDescription = NULL;
		}
	}

	void CFIntLicenseHBuff::setOptionalDescriptionValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalDescriptionValue" );
		if( value.length() > CFIntLicenseBuff::DESCRIPTION_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntLicenseBuff::DESCRIPTION_MAX_LEN );
		}
		if( optionalDescription != NULL ) {
			delete optionalDescription;
			optionalDescription = NULL;
		}
		optionalDescription = new std::string( value );
	}

	const std::string& CFIntLicenseHBuff::getOptionalEmbeddedTextValue() const {
		static const std::string S_ProcName( "getOptionalEmbeddedTextValue" );
		if( optionalEmbeddedText == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalEmbeddedText );
	}

	const std::string* CFIntLicenseHBuff::getOptionalEmbeddedTextReference() const {
		return( optionalEmbeddedText );
	}

	const bool CFIntLicenseHBuff::isOptionalEmbeddedTextNull() const {
		return( optionalEmbeddedText == NULL );
	}

	void CFIntLicenseHBuff::setOptionalEmbeddedTextNull() {
		if( optionalEmbeddedText != NULL ) {
			delete optionalEmbeddedText;
			optionalEmbeddedText = NULL;
		}
	}

	void CFIntLicenseHBuff::setOptionalEmbeddedTextValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalEmbeddedTextValue" );
		if( value.length() > CFIntLicenseBuff::EMBEDDEDTEXT_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntLicenseBuff::EMBEDDEDTEXT_MAX_LEN );
		}
		if( optionalEmbeddedText != NULL ) {
			delete optionalEmbeddedText;
			optionalEmbeddedText = NULL;
		}
		optionalEmbeddedText = new std::string( value );
	}

	const std::string& CFIntLicenseHBuff::getOptionalFullTextValue() const {
		static const std::string S_ProcName( "getOptionalFullTextValue" );
		if( optionalFullText == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalFullText );
	}

	const std::string* CFIntLicenseHBuff::getOptionalFullTextReference() const {
		return( optionalFullText );
	}

	const bool CFIntLicenseHBuff::isOptionalFullTextNull() const {
		return( optionalFullText == NULL );
	}

	void CFIntLicenseHBuff::setOptionalFullTextNull() {
		if( optionalFullText != NULL ) {
			delete optionalFullText;
			optionalFullText = NULL;
		}
	}

	void CFIntLicenseHBuff::setOptionalFullTextValue( const std::string& value ) {
		static const std::string S_ProcName( "setOptionalFullTextValue" );
		if( value.length() > CFIntLicenseBuff::FULLTEXT_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntLicenseBuff::FULLTEXT_MAX_LEN );
		}
		if( optionalFullText != NULL ) {
			delete optionalFullText;
			optionalFullText = NULL;
		}
		optionalFullText = new std::string( value );
	}

	size_t CFIntLicenseHBuff::hashCode() const {
		size_t hashCode = CFIntHPKey::hashCode();
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredId() );
		hashCode = hashCode + (int)( getRequiredTopDomainId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		if( ! isOptionalDescriptionNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalDescriptionValue() );
		}
		if( ! isOptionalEmbeddedTextNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalEmbeddedTextValue() );
		}
		if( ! isOptionalFullTextNull() ) {
			hashCode = hashCode + cflib::CFLib::hash( getOptionalFullTextValue() );
		}
		return( hashCode );
	}

	CFIntLicenseHBuff CFIntLicenseHBuff::operator =( cfint::CFIntLicenseBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredId( src.getRequiredId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalDescriptionNull() ) {
			setOptionalDescriptionNull();
		}
		else {
			setOptionalDescriptionValue( src.getOptionalDescriptionValue() );
		}
		if( src.isOptionalEmbeddedTextNull() ) {
			setOptionalEmbeddedTextNull();
		}
		else {
			setOptionalEmbeddedTextValue( src.getOptionalEmbeddedTextValue() );
		}
		if( src.isOptionalFullTextNull() ) {
			setOptionalFullTextNull();
		}
		else {
			setOptionalFullTextValue( src.getOptionalFullTextValue() );
		}
		return( *this );
	}

	CFIntLicenseHBuff CFIntLicenseHBuff::operator =( cfint::CFIntLicenseHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredId( src.getRequiredId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		setRequiredName( src.getRequiredName() );
		if( src.isOptionalDescriptionNull() ) {
			setOptionalDescriptionNull();
		}
		else {
			setOptionalDescriptionValue( src.getOptionalDescriptionValue() );
		}
		if( src.isOptionalEmbeddedTextNull() ) {
			setOptionalEmbeddedTextNull();
		}
		else {
			setOptionalEmbeddedTextValue( src.getOptionalEmbeddedTextValue() );
		}
		if( src.isOptionalFullTextNull() ) {
			setOptionalFullTextNull();
		}
		else {
			setOptionalFullTextValue( src.getOptionalFullTextValue() );
		}
		return( *this );
	}

	bool CFIntLicenseHBuff::operator <( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator <( const CFIntLicenseByDomainIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator <( const CFIntLicenseByUNameIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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

	bool CFIntLicenseHBuff::operator <( const CFIntLicensePKey& rhs ) {
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

	bool CFIntLicenseHBuff::operator <( const CFIntLicenseHPKey& rhs ) {
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

	bool CFIntLicenseHBuff::operator <( const CFIntLicenseHBuff& rhs ) {
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
		if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
			if( getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
		}
		if( ! isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
			if( getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator <( const CFIntLicenseBuff& rhs ) {
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
		if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
			if( getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
		}
		if( ! isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
			if( getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator <=( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator <=( const CFIntLicenseByDomainIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator <=( const CFIntLicenseByUNameIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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

	bool CFIntLicenseHBuff::operator <=( const CFIntLicensePKey& rhs ) {
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

	bool CFIntLicenseHBuff::operator <=( const CFIntLicenseHPKey& rhs ) {
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

	bool CFIntLicenseHBuff::operator <=( const CFIntLicenseHBuff& rhs ) {
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
		if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
			if( getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
		}
		if( ! isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
			if( getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator <=( const CFIntLicenseBuff& rhs ) {
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
		if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
			if( getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
		}
		if( ! isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
			if( getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator ==( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator ==( const CFIntLicenseByDomainIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator ==( const CFIntLicenseByUNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator ==( const CFIntLicensePKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator ==( const CFIntLicenseHPKey& rhs ) {
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

	bool CFIntLicenseHBuff::operator ==( const CFIntLicenseHBuff& rhs ) {
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
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				if( getOptionalEmbeddedTextValue() != rhs.getOptionalEmbeddedTextValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! isOptionalFullTextNull() ) {
			if( ! rhs.isOptionalFullTextNull() ) {
				if( getOptionalFullTextValue() != rhs.getOptionalFullTextValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator ==( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				if( getOptionalEmbeddedTextValue() != rhs.getOptionalEmbeddedTextValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! isOptionalFullTextNull() ) {
			if( ! rhs.isOptionalFullTextNull() ) {
				if( getOptionalFullTextValue() != rhs.getOptionalFullTextValue() ) {
					return( false );
				}
			}
			else {
				return( false );
			}
		}
		else {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator !=( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator !=( const CFIntLicenseByDomainIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator !=( const CFIntLicenseByUNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator !=( const CFIntLicensePKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator !=( const CFIntLicenseHPKey& rhs ) {
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

	bool CFIntLicenseHBuff::operator !=( const CFIntLicenseHBuff& rhs ) {
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
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( getOptionalEmbeddedTextValue() != rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
		}
		if( ! isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( getOptionalFullTextValue() != rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator !=( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( getOptionalEmbeddedTextValue() != rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
		}
		if( ! isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( getOptionalFullTextValue() != rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator >=( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator >=( const CFIntLicenseByDomainIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator >=( const CFIntLicenseByUNameIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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

	bool CFIntLicenseHBuff::operator >=( const CFIntLicensePKey& rhs ) {
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

	bool CFIntLicenseHBuff::operator >=( const CFIntLicenseHPKey& rhs ) {
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

	bool CFIntLicenseHBuff::operator >=( const CFIntLicenseHBuff& rhs ) {
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
		if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator >=( const CFIntLicenseBuff& rhs ) {
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
		if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool CFIntLicenseHBuff::operator >( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator >( const CFIntLicenseByDomainIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator >( const CFIntLicenseByUNameIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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

	bool CFIntLicenseHBuff::operator >( const CFIntLicensePKey& rhs ) {
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

	bool CFIntLicenseHBuff::operator >( const CFIntLicenseHPKey& rhs ) {
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

	bool CFIntLicenseHBuff::operator >( const CFIntLicenseHBuff& rhs ) {
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
		if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( ! isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	bool CFIntLicenseHBuff::operator >( const CFIntLicenseBuff& rhs ) {
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
		if( getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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
		if( ! isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		if( ! isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			return( false );
		}
		return( false );
	}

	std::string CFIntLicenseHBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntLicenseHBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_TopDomainId( "TopDomainId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		static const std::string S_EmbeddedText( "EmbeddedText" );
		static const std::string S_FullText( "FullText" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopDomainId, getRequiredTopDomainId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		if( ! isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, getOptionalDescriptionValue() ) );
		}
		if( ! isOptionalEmbeddedTextNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EmbeddedText, getOptionalEmbeddedTextValue() ) );
		}
		if( ! isOptionalFullTextNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_FullText, getOptionalFullTextValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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

	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
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

	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
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

	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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
		if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
			if( lhs.getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
			if( lhs.getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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
		if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
			if( lhs.getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
			if( lhs.getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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

	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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
		if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
			if( lhs.getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
			if( lhs.getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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
		if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
			if( lhs.getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( false );
			}
			if( lhs.getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( true );
			}
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
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

	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				if( lhs.getOptionalEmbeddedTextValue() != rhs.getOptionalEmbeddedTextValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( ! rhs.isOptionalFullTextNull() ) {
				if( lhs.getOptionalFullTextValue() != rhs.getOptionalFullTextValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				if( lhs.getOptionalEmbeddedTextValue() != rhs.getOptionalEmbeddedTextValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( ! rhs.isOptionalFullTextNull() ) {
				if( lhs.getOptionalFullTextValue() != rhs.getOptionalFullTextValue() ) {
					return( false );
				}
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
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

	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalEmbeddedTextValue() != rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalFullTextValue() != rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalEmbeddedTextValue() != rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalFullTextValue() != rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( true );
			}
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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

	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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
		if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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
		if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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

	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
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

	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
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

	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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
		if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntLicenseHBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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
		if( lhs.getRequiredTopDomainId() < rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopDomainId() > rhs.getRequiredTopDomainId() ) {
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
		if( ! lhs.isOptionalEmbeddedTextNull() ) {
			if( rhs.isOptionalEmbeddedTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalEmbeddedTextValue() < rhs.getOptionalEmbeddedTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalEmbeddedTextValue() > rhs.getOptionalEmbeddedTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalEmbeddedTextNull() ) {
				return( false );
			}
		}
		if( ! lhs.isOptionalFullTextNull() ) {
			if( rhs.isOptionalFullTextNull() ) {
				return( true );
			}
			if( lhs.getOptionalFullTextValue() < rhs.getOptionalFullTextValue() ) {
				return( false );
			}
			else if( lhs.getOptionalFullTextValue() > rhs.getOptionalFullTextValue() ) {
				return( true );
			}
		}
		else {
			if( ! rhs.isOptionalFullTextNull() ) {
				return( false );
			}
		}
		return( false );
	}
}

