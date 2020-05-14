// Description: C++18 implementation for a MinorVersion by NameIdx index key object.

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

#include <cfint/CFIntMinorVersionByNameIdxKey.hpp>
#include <cfint/CFIntMinorVersionBuff.hpp>
#include <cfint/CFIntMinorVersionHBuff.hpp>

namespace cfint {
	const std::string CFIntMinorVersionByNameIdxKey::CLASS_NAME( "CFIntMinorVersionByNameIdxKey" );
	const std::string CFIntMinorVersionByNameIdxKey::S_VALUE( "value" );
	const std::string CFIntMinorVersionByNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntMinorVersionByNameIdxKey::CFIntMinorVersionByNameIdxKey() {
		requiredTenantId = cfint::CFIntMinorVersionBuff::TENANTID_INIT_VALUE;
		requiredMajorVersionId = cfint::CFIntMinorVersionBuff::MAJORVERSIONID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntMinorVersionBuff::NAME_INIT_VALUE );
	}

	CFIntMinorVersionByNameIdxKey::CFIntMinorVersionByNameIdxKey( const CFIntMinorVersionByNameIdxKey& src ) {
		requiredTenantId = cfint::CFIntMinorVersionBuff::TENANTID_INIT_VALUE;
		requiredMajorVersionId = cfint::CFIntMinorVersionBuff::MAJORVERSIONID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntMinorVersionBuff::NAME_INIT_VALUE );
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredMajorVersionId( src.getRequiredMajorVersionId() );
		setRequiredName( src.getRequiredName() );
	}

	CFIntMinorVersionByNameIdxKey::~CFIntMinorVersionByNameIdxKey() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
	}

	const int64_t CFIntMinorVersionByNameIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntMinorVersionByNameIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntMinorVersionByNameIdxKey::setRequiredTenantId( const int64_t value ) {
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

	const int64_t CFIntMinorVersionByNameIdxKey::getRequiredMajorVersionId() const {
		return( requiredMajorVersionId );
	}

	const int64_t* CFIntMinorVersionByNameIdxKey::getRequiredMajorVersionIdReference() const {
		return( &requiredMajorVersionId );
	}

	void CFIntMinorVersionByNameIdxKey::setRequiredMajorVersionId( const int64_t value ) {
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

	const std::string& CFIntMinorVersionByNameIdxKey::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntMinorVersionByNameIdxKey::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntMinorVersionByNameIdxKey::setRequiredName( const std::string& value ) {
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

	size_t CFIntMinorVersionByNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredMajorVersionId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		return( hashCode );
	}

	std::string CFIntMinorVersionByNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMinorVersionByNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_MajorVersionId( "MajorVersionId" );
		static const std::string S_Name( "Name" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_MajorVersionId, getRequiredMajorVersionId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntMinorVersionByNameIdxKey::operator <( const CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator <( const CFIntMinorVersionHBuff& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator <( const CFIntMinorVersionBuff& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator <=( const CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator <=( const CFIntMinorVersionHBuff& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator <=( const CFIntMinorVersionBuff& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator ==( const CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator ==( const CFIntMinorVersionHBuff& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator ==( const CFIntMinorVersionBuff& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator !=( const CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator !=( const CFIntMinorVersionHBuff& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator !=( const CFIntMinorVersionBuff& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator >=( const CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator >=( const CFIntMinorVersionHBuff& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator >=( const CFIntMinorVersionBuff& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator >( const CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator >( const CFIntMinorVersionHBuff& rhs ) {
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

	bool CFIntMinorVersionByNameIdxKey::operator >( const CFIntMinorVersionBuff& rhs ) {
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
	CFIntMinorVersionByNameIdxKey CFIntMinorVersionByNameIdxKey::operator =( cfint::CFIntMinorVersionByNameIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredMajorVersionId( src.getRequiredMajorVersionId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntMinorVersionByNameIdxKey CFIntMinorVersionByNameIdxKey::operator =( cfint::CFIntMinorVersionBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredMajorVersionId( src.getRequiredMajorVersionId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntMinorVersionByNameIdxKey CFIntMinorVersionByNameIdxKey::operator =( cfint::CFIntMinorVersionHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredMajorVersionId( src.getRequiredMajorVersionId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool operator <(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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

	bool operator <(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
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

	bool operator ==(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool operator ==(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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

	bool operator ==(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
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

	bool operator !=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool operator !=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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

	bool operator !=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
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

	bool operator >=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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

	bool operator >=(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionByNameIdxKey& rhs ) {
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

	bool operator >(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntMinorVersionByNameIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
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
}
