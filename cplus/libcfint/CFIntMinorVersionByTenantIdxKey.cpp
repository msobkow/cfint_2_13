// Description: C++18 implementation for a MinorVersion by TenantIdx index key object.

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

#include <cfint/CFIntMinorVersionByTenantIdxKey.hpp>
#include <cfint/CFIntMinorVersionBuff.hpp>
#include <cfint/CFIntMinorVersionHBuff.hpp>

namespace cfint {
	const std::string CFIntMinorVersionByTenantIdxKey::CLASS_NAME( "CFIntMinorVersionByTenantIdxKey" );
	const std::string CFIntMinorVersionByTenantIdxKey::S_VALUE( "value" );
	const std::string CFIntMinorVersionByTenantIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntMinorVersionByTenantIdxKey::CFIntMinorVersionByTenantIdxKey() {
		requiredTenantId = cfint::CFIntMinorVersionBuff::TENANTID_INIT_VALUE;
	}

	CFIntMinorVersionByTenantIdxKey::CFIntMinorVersionByTenantIdxKey( const CFIntMinorVersionByTenantIdxKey& src ) {
		requiredTenantId = cfint::CFIntMinorVersionBuff::TENANTID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
	}

	CFIntMinorVersionByTenantIdxKey::~CFIntMinorVersionByTenantIdxKey() {
	}

	const int64_t CFIntMinorVersionByTenantIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntMinorVersionByTenantIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntMinorVersionByTenantIdxKey::setRequiredTenantId( const int64_t value ) {
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

	size_t CFIntMinorVersionByTenantIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		return( hashCode );
	}

	std::string CFIntMinorVersionByTenantIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMinorVersionByTenantIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator <( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator <( const CFIntMinorVersionHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator <( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator <=( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator <=( const CFIntMinorVersionHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator <=( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator ==( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator ==( const CFIntMinorVersionHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator ==( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator !=( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator !=( const CFIntMinorVersionHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator !=( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator >=( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator >=( const CFIntMinorVersionHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator >=( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator >( const CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator >( const CFIntMinorVersionHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionByTenantIdxKey::operator >( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}
	CFIntMinorVersionByTenantIdxKey CFIntMinorVersionByTenantIdxKey::operator =( cfint::CFIntMinorVersionByTenantIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		return( *this );
	}

	CFIntMinorVersionByTenantIdxKey CFIntMinorVersionByTenantIdxKey::operator =( cfint::CFIntMinorVersionBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		return( *this );
	}

	CFIntMinorVersionByTenantIdxKey CFIntMinorVersionByTenantIdxKey::operator =( cfint::CFIntMinorVersionHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionByTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMinorVersionByTenantIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}
}

