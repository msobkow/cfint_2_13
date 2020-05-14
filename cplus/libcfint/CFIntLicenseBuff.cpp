// Description: C++18 implementation for a License buffer object.

/*
 *	com.github.msobkow.CFInt
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

#include <cfint/ICFIntPublic.hpp>

#include <cfint/CFIntLicenseByLicnTenantIdxKey.hpp>
#include <cfint/CFIntLicenseByDomainIdxKey.hpp>
#include <cfint/CFIntLicenseByUNameIdxKey.hpp>
#include <cfint/CFIntSchema.hpp>

namespace cfint {

	const std::string CFIntLicenseBuff::S_VALUE( "value" );
	const std::string CFIntLicenseBuff::S_VALUE_LENGTH( "value.length()" );

	const std::string CFIntLicenseBuff::GENDEFNAME( "License" );
	const classcode_t CFIntLicenseBuff::CLASS_CODE = 0xa101L;
	const std::string CFIntLicenseBuff::CLASS_NAME( "CFIntLicenseBuff" );
		const std::string CFIntLicenseBuff::COLNAME_TENANTID( "TenantId" );
		const std::string CFIntLicenseBuff::COLNAME_ID( "Id" );
		const std::string CFIntLicenseBuff::COLNAME_TOPDOMAINID( "TopDomainId" );
		const std::string CFIntLicenseBuff::COLNAME_NAME( "Name" );
		const std::string CFIntLicenseBuff::COLNAME_DESCRIPTION( "Description" );
		const std::string CFIntLicenseBuff::COLNAME_EMBEDDEDTEXT( "EmbeddedText" );
		const std::string CFIntLicenseBuff::COLNAME_FULLTEXT( "FullText" );
	const int64_t CFIntLicenseBuff::TENANTID_INIT_VALUE = 0LL;
	const int64_t CFIntLicenseBuff::ID_INIT_VALUE = 0LL;
	const int64_t CFIntLicenseBuff::TOPDOMAINID_INIT_VALUE = 0LL;
	const std::string CFIntLicenseBuff::NAME_INIT_VALUE( "" );
	const std::string CFIntLicenseBuff::DESCRIPTION_INIT_VALUE( "" );
	const std::string CFIntLicenseBuff::EMBEDDEDTEXT_INIT_VALUE( "" );
	const std::string CFIntLicenseBuff::FULLTEXT_INIT_VALUE( "" );
	const int64_t CFIntLicenseBuff::TENANTID_MIN_VALUE = 0LL;
	const int64_t CFIntLicenseBuff::ID_MIN_VALUE = 0LL;
	const int64_t CFIntLicenseBuff::TOPDOMAINID_MIN_VALUE = 0LL;
	const std::string::size_type CFIntLicenseBuff::NAME_MAX_LEN = 64;
	const std::string::size_type CFIntLicenseBuff::DESCRIPTION_MAX_LEN = 1024;
	const std::string::size_type CFIntLicenseBuff::EMBEDDEDTEXT_MAX_LEN = 8000;
	const std::string::size_type CFIntLicenseBuff::FULLTEXT_MAX_LEN = 8000;

	CFIntLicenseBuff::CFIntLicenseBuff()
	: cflib::ICFLibCloneableObj()
	{
		requiredRevision = 1;
		requiredTenantId = cfint::CFIntLicenseBuff::TENANTID_INIT_VALUE;
		requiredId = cfint::CFIntLicenseBuff::ID_INIT_VALUE;
		requiredTopDomainId = cfint::CFIntLicenseBuff::TOPDOMAINID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntLicenseBuff::NAME_INIT_VALUE );
		optionalDescription = NULL;
		optionalEmbeddedText = NULL;
		optionalFullText = NULL;
	}

	CFIntLicenseBuff::CFIntLicenseBuff( const CFIntLicenseBuff& src )
	: cflib::ICFLibCloneableObj()
	{
		requiredRevision = 1;
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

	CFIntLicenseBuff::~CFIntLicenseBuff() {
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

	cflib::ICFLibCloneableObj* CFIntLicenseBuff::clone() {
		CFIntLicenseBuff* copy = new CFIntLicenseBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const std::string& CFIntLicenseBuff::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntLicenseBuff::getClassCode() const {
		return( CLASS_CODE );
	}

	bool CFIntLicenseBuff::implementsClassCode( const classcode_t argClassCode ) {
		if( argClassCode == CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	const int64_t CFIntLicenseBuff::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntLicenseBuff::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntLicenseBuff::setRequiredTenantId( const int64_t value ) {
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

	const int64_t CFIntLicenseBuff::getRequiredId() const {
		return( requiredId );
	}

	const int64_t* CFIntLicenseBuff::getRequiredIdReference() const {
		return( &requiredId );
	}

	void CFIntLicenseBuff::setRequiredId( const int64_t value ) {
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

	const int64_t CFIntLicenseBuff::getRequiredTopDomainId() const {
		return( requiredTopDomainId );
	}

	const int64_t* CFIntLicenseBuff::getRequiredTopDomainIdReference() const {
		return( &requiredTopDomainId );
	}

	void CFIntLicenseBuff::setRequiredTopDomainId( const int64_t value ) {
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

	const std::string& CFIntLicenseBuff::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntLicenseBuff::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntLicenseBuff::setRequiredName( const std::string& value ) {
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

	const bool CFIntLicenseBuff::isOptionalDescriptionNull() const {
		return( optionalDescription == NULL );
	}

	const std::string& CFIntLicenseBuff::getOptionalDescriptionValue() const {
		static const std::string S_ProcName( "getOptionalDescriptionValue" );
		if( optionalDescription == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalDescription );
	}

	const std::string* CFIntLicenseBuff::getOptionalDescriptionReference() const {
		return( optionalDescription );
	}

	void CFIntLicenseBuff::setOptionalDescriptionNull() {
		if( optionalDescription != NULL ) {
			delete optionalDescription;
			optionalDescription = NULL;
		}
	}

	void CFIntLicenseBuff::setOptionalDescriptionValue( const std::string& value ) {
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

	const bool CFIntLicenseBuff::isOptionalEmbeddedTextNull() const {
		return( optionalEmbeddedText == NULL );
	}

	const std::string& CFIntLicenseBuff::getOptionalEmbeddedTextValue() const {
		static const std::string S_ProcName( "getOptionalEmbeddedTextValue" );
		if( optionalEmbeddedText == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalEmbeddedText );
	}

	const std::string* CFIntLicenseBuff::getOptionalEmbeddedTextReference() const {
		return( optionalEmbeddedText );
	}

	void CFIntLicenseBuff::setOptionalEmbeddedTextNull() {
		if( optionalEmbeddedText != NULL ) {
			delete optionalEmbeddedText;
			optionalEmbeddedText = NULL;
		}
	}

	void CFIntLicenseBuff::setOptionalEmbeddedTextValue( const std::string& value ) {
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

	const bool CFIntLicenseBuff::isOptionalFullTextNull() const {
		return( optionalFullText == NULL );
	}

	const std::string& CFIntLicenseBuff::getOptionalFullTextValue() const {
		static const std::string S_ProcName( "getOptionalFullTextValue" );
		if( optionalFullText == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_VALUE );
		}
		return( *optionalFullText );
	}

	const std::string* CFIntLicenseBuff::getOptionalFullTextReference() const {
		return( optionalFullText );
	}

	void CFIntLicenseBuff::setOptionalFullTextNull() {
		if( optionalFullText != NULL ) {
			delete optionalFullText;
			optionalFullText = NULL;
		}
	}

	void CFIntLicenseBuff::setOptionalFullTextValue( const std::string& value ) {
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

	int32_t CFIntLicenseBuff::getRequiredRevision() const {
		return( requiredRevision );
	}

	void CFIntLicenseBuff::setRequiredRevision( int32_t value ) {
		requiredRevision = value;
	}

	size_t CFIntLicenseBuff::hashCode() const {
		size_t hashCode = 0L;
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

	CFIntLicenseBuff CFIntLicenseBuff::operator =( cfint::CFIntLicenseBuff& src ) {
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

	CFIntLicenseBuff CFIntLicenseBuff::operator =( cfint::CFIntLicenseHBuff& src ) {
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

	bool CFIntLicenseBuff::operator <( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseBuff::operator <( const CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool CFIntLicenseBuff::operator <( const CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool CFIntLicenseBuff::operator <( const CFIntLicensePKey& rhs ) {
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

	bool CFIntLicenseBuff::operator <( const CFIntLicenseHPKey& rhs ) {
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

	bool CFIntLicenseBuff::operator <( const CFIntLicenseHBuff& rhs ) {
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

	bool CFIntLicenseBuff::operator <( const CFIntLicenseBuff& rhs ) {
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

	bool CFIntLicenseBuff::operator <=( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseBuff::operator <=( const CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool CFIntLicenseBuff::operator <=( const CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool CFIntLicenseBuff::operator <=( const CFIntLicensePKey& rhs ) {
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

	bool CFIntLicenseBuff::operator <=( const CFIntLicenseHPKey& rhs ) {
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

	bool CFIntLicenseBuff::operator <=( const CFIntLicenseHBuff& rhs ) {
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

	bool CFIntLicenseBuff::operator <=( const CFIntLicenseBuff& rhs ) {
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

	bool CFIntLicenseBuff::operator ==( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseBuff::operator ==( const CFIntLicenseByDomainIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseBuff::operator ==( const CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool CFIntLicenseBuff::operator ==( const CFIntLicensePKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseBuff::operator ==( const CFIntLicenseHPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseBuff::operator ==( const CFIntLicenseHBuff& rhs ) {
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

	bool CFIntLicenseBuff::operator ==( const CFIntLicenseBuff& rhs ) {
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

	bool CFIntLicenseBuff::operator !=( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseBuff::operator !=( const CFIntLicenseByDomainIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseBuff::operator !=( const CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool CFIntLicenseBuff::operator !=( const CFIntLicensePKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseBuff::operator !=( const CFIntLicenseHPKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseBuff::operator !=( const CFIntLicenseHBuff& rhs ) {
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

	bool CFIntLicenseBuff::operator !=( const CFIntLicenseBuff& rhs ) {
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

	bool CFIntLicenseBuff::operator >=( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseBuff::operator >=( const CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool CFIntLicenseBuff::operator >=( const CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool CFIntLicenseBuff::operator >=( const CFIntLicensePKey& rhs ) {
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

	bool CFIntLicenseBuff::operator >=( const CFIntLicenseHPKey& rhs ) {
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

	bool CFIntLicenseBuff::operator >=( const CFIntLicenseHBuff& rhs ) {
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

	bool CFIntLicenseBuff::operator >=( const CFIntLicenseBuff& rhs ) {
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

	bool CFIntLicenseBuff::operator >( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseBuff::operator >( const CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool CFIntLicenseBuff::operator >( const CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool CFIntLicenseBuff::operator >( const CFIntLicensePKey& rhs ) {
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

	bool CFIntLicenseBuff::operator >( const CFIntLicenseHPKey& rhs ) {
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

	bool CFIntLicenseBuff::operator >( const CFIntLicenseHBuff& rhs ) {
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

	bool CFIntLicenseBuff::operator >( const CFIntLicenseBuff& rhs ) {
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

	std::string CFIntLicenseBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntLicenseBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_TopDomainId( "TopDomainId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		static const std::string S_EmbeddedText( "EmbeddedText" );
		static const std::string S_FullText( "FullText" );
		std::string ret( S_Preamble );
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

	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
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

	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
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

	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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

	bool operator <(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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

	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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

	bool operator ==(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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

	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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

	bool operator !=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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

	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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

	bool operator >=(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
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

	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicensePKey& rhs ) {
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

	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHPKey& rhs ) {
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

	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntLicenseBuff& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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

