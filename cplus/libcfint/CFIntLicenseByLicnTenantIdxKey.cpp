// Description: C++18 implementation for a License by LicnTenantIdx index key object.

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

#include <cfint/CFIntLicenseByLicnTenantIdxKey.hpp>
#include <cfint/CFIntLicenseBuff.hpp>
#include <cfint/CFIntLicenseHBuff.hpp>

namespace cfint {
	const std::string CFIntLicenseByLicnTenantIdxKey::CLASS_NAME( "CFIntLicenseByLicnTenantIdxKey" );
	const std::string CFIntLicenseByLicnTenantIdxKey::S_VALUE( "value" );
	const std::string CFIntLicenseByLicnTenantIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntLicenseByLicnTenantIdxKey::CFIntLicenseByLicnTenantIdxKey() {
		requiredTenantId = cfint::CFIntLicenseBuff::TENANTID_INIT_VALUE;
	}

	CFIntLicenseByLicnTenantIdxKey::CFIntLicenseByLicnTenantIdxKey( const CFIntLicenseByLicnTenantIdxKey& src ) {
		requiredTenantId = cfint::CFIntLicenseBuff::TENANTID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
	}

	CFIntLicenseByLicnTenantIdxKey::~CFIntLicenseByLicnTenantIdxKey() {
	}

	const int64_t CFIntLicenseByLicnTenantIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntLicenseByLicnTenantIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntLicenseByLicnTenantIdxKey::setRequiredTenantId( const int64_t value ) {
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

	size_t CFIntLicenseByLicnTenantIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		return( hashCode );
	}

	std::string CFIntLicenseByLicnTenantIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntLicenseByLicnTenantIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator <( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator <( const CFIntLicenseHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator <( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator <=( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator <=( const CFIntLicenseHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator <=( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator ==( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator ==( const CFIntLicenseHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator ==( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator !=( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator !=( const CFIntLicenseHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator !=( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator >=( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator >=( const CFIntLicenseHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator >=( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator >( const CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator >( const CFIntLicenseHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByLicnTenantIdxKey::operator >( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}
	CFIntLicenseByLicnTenantIdxKey CFIntLicenseByLicnTenantIdxKey::operator =( cfint::CFIntLicenseByLicnTenantIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		return( *this );
	}

	CFIntLicenseByLicnTenantIdxKey CFIntLicenseByLicnTenantIdxKey::operator =( cfint::CFIntLicenseBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		return( *this );
	}

	CFIntLicenseByLicnTenantIdxKey CFIntLicenseByLicnTenantIdxKey::operator =( cfint::CFIntLicenseHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseByLicnTenantIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntLicenseByLicnTenantIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		return( false );
	}
}

