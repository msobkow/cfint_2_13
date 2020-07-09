// Description: C++18 implementation for a MajorVersion by SubProjectIdx index key object.

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

#include <cfint/CFIntMajorVersionBySubProjectIdxKey.hpp>
#include <cfint/CFIntMajorVersionBuff.hpp>
#include <cfint/CFIntMajorVersionHBuff.hpp>

namespace cfint {
	const std::string CFIntMajorVersionBySubProjectIdxKey::CLASS_NAME( "CFIntMajorVersionBySubProjectIdxKey" );
	const std::string CFIntMajorVersionBySubProjectIdxKey::S_VALUE( "value" );
	const std::string CFIntMajorVersionBySubProjectIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntMajorVersionBySubProjectIdxKey::CFIntMajorVersionBySubProjectIdxKey() {
		requiredTenantId = cfint::CFIntMajorVersionBuff::TENANTID_INIT_VALUE;
		requiredSubProjectId = cfint::CFIntMajorVersionBuff::SUBPROJECTID_INIT_VALUE;
	}

	CFIntMajorVersionBySubProjectIdxKey::CFIntMajorVersionBySubProjectIdxKey( const CFIntMajorVersionBySubProjectIdxKey& src ) {
		requiredTenantId = cfint::CFIntMajorVersionBuff::TENANTID_INIT_VALUE;
		requiredSubProjectId = cfint::CFIntMajorVersionBuff::SUBPROJECTID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredSubProjectId( src.getRequiredSubProjectId() );
	}

	CFIntMajorVersionBySubProjectIdxKey::~CFIntMajorVersionBySubProjectIdxKey() {
	}

	const int64_t CFIntMajorVersionBySubProjectIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntMajorVersionBySubProjectIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntMajorVersionBySubProjectIdxKey::setRequiredTenantId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTenantId" );
		if( value < cfint::CFIntMajorVersionBuff::TENANTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntMajorVersionBuff::TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	const int64_t CFIntMajorVersionBySubProjectIdxKey::getRequiredSubProjectId() const {
		return( requiredSubProjectId );
	}

	const int64_t* CFIntMajorVersionBySubProjectIdxKey::getRequiredSubProjectIdReference() const {
		return( &requiredSubProjectId );
	}

	void CFIntMajorVersionBySubProjectIdxKey::setRequiredSubProjectId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredSubProjectId" );
		if( value < cfint::CFIntMajorVersionBuff::SUBPROJECTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntMajorVersionBuff::SUBPROJECTID_MIN_VALUE );
		}
		requiredSubProjectId = value;
	}

	size_t CFIntMajorVersionBySubProjectIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredSubProjectId() );
		return( hashCode );
	}

	std::string CFIntMajorVersionBySubProjectIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMajorVersionBySubProjectIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_SubProjectId( "SubProjectId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SubProjectId, getRequiredSubProjectId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator <( const CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator <( const CFIntMajorVersionHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator <( const CFIntMajorVersionBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator <=( const CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator <=( const CFIntMajorVersionHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator <=( const CFIntMajorVersionBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator ==( const CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator ==( const CFIntMajorVersionHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator ==( const CFIntMajorVersionBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator !=( const CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator !=( const CFIntMajorVersionHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator !=( const CFIntMajorVersionBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator >=( const CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator >=( const CFIntMajorVersionHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator >=( const CFIntMajorVersionBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator >( const CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator >( const CFIntMajorVersionHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionBySubProjectIdxKey::operator >( const CFIntMajorVersionBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}
	CFIntMajorVersionBySubProjectIdxKey CFIntMajorVersionBySubProjectIdxKey::operator =( cfint::CFIntMajorVersionBySubProjectIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredSubProjectId( src.getRequiredSubProjectId() );
		return( *this );
	}

	CFIntMajorVersionBySubProjectIdxKey CFIntMajorVersionBySubProjectIdxKey::operator =( cfint::CFIntMajorVersionBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredSubProjectId( src.getRequiredSubProjectId() );
		return( *this );
	}

	CFIntMajorVersionBySubProjectIdxKey CFIntMajorVersionBySubProjectIdxKey::operator =( cfint::CFIntMajorVersionHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredSubProjectId( src.getRequiredSubProjectId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBySubProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMajorVersionBySubProjectIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() < rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredSubProjectId() > rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		return( false );
	}
}

