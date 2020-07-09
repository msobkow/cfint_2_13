// Description: C++18 implementation for a TopDomain by TldIdx index key object.

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

#include <cfint/CFIntTopDomainByTldIdxKey.hpp>
#include <cfint/CFIntTopDomainBuff.hpp>
#include <cfint/CFIntTopDomainHBuff.hpp>

namespace cfint {
	const std::string CFIntTopDomainByTldIdxKey::CLASS_NAME( "CFIntTopDomainByTldIdxKey" );
	const std::string CFIntTopDomainByTldIdxKey::S_VALUE( "value" );
	const std::string CFIntTopDomainByTldIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntTopDomainByTldIdxKey::CFIntTopDomainByTldIdxKey() {
		requiredTenantId = cfint::CFIntTopDomainBuff::TENANTID_INIT_VALUE;
		requiredTldId = cfint::CFIntTopDomainBuff::TLDID_INIT_VALUE;
	}

	CFIntTopDomainByTldIdxKey::CFIntTopDomainByTldIdxKey( const CFIntTopDomainByTldIdxKey& src ) {
		requiredTenantId = cfint::CFIntTopDomainBuff::TENANTID_INIT_VALUE;
		requiredTldId = cfint::CFIntTopDomainBuff::TLDID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTldId( src.getRequiredTldId() );
	}

	CFIntTopDomainByTldIdxKey::~CFIntTopDomainByTldIdxKey() {
	}

	const int64_t CFIntTopDomainByTldIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntTopDomainByTldIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntTopDomainByTldIdxKey::setRequiredTenantId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTenantId" );
		if( value < cfint::CFIntTopDomainBuff::TENANTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntTopDomainBuff::TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	const int64_t CFIntTopDomainByTldIdxKey::getRequiredTldId() const {
		return( requiredTldId );
	}

	const int64_t* CFIntTopDomainByTldIdxKey::getRequiredTldIdReference() const {
		return( &requiredTldId );
	}

	void CFIntTopDomainByTldIdxKey::setRequiredTldId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTldId" );
		if( value < cfint::CFIntTopDomainBuff::TLDID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntTopDomainBuff::TLDID_MIN_VALUE );
		}
		requiredTldId = value;
	}

	size_t CFIntTopDomainByTldIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredTldId() );
		return( hashCode );
	}

	std::string CFIntTopDomainByTldIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTopDomainByTldIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TldId( "TldId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TldId, getRequiredTldId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntTopDomainByTldIdxKey::operator <( const CFIntTopDomainByTldIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByTldIdxKey::operator <( const CFIntTopDomainHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByTldIdxKey::operator <( const CFIntTopDomainBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByTldIdxKey::operator <=( const CFIntTopDomainByTldIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByTldIdxKey::operator <=( const CFIntTopDomainHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByTldIdxKey::operator <=( const CFIntTopDomainBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByTldIdxKey::operator ==( const CFIntTopDomainByTldIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTopDomainByTldIdxKey::operator ==( const CFIntTopDomainHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTopDomainByTldIdxKey::operator ==( const CFIntTopDomainBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTopDomainByTldIdxKey::operator !=( const CFIntTopDomainByTldIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByTldIdxKey::operator !=( const CFIntTopDomainHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByTldIdxKey::operator !=( const CFIntTopDomainBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByTldIdxKey::operator >=( const CFIntTopDomainByTldIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByTldIdxKey::operator >=( const CFIntTopDomainHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByTldIdxKey::operator >=( const CFIntTopDomainBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByTldIdxKey::operator >( const CFIntTopDomainByTldIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByTldIdxKey::operator >( const CFIntTopDomainHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByTldIdxKey::operator >( const CFIntTopDomainBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}
	CFIntTopDomainByTldIdxKey CFIntTopDomainByTldIdxKey::operator =( cfint::CFIntTopDomainByTldIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTldId( src.getRequiredTldId() );
		return( *this );
	}

	CFIntTopDomainByTldIdxKey CFIntTopDomainByTldIdxKey::operator =( cfint::CFIntTopDomainBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTldId( src.getRequiredTldId() );
		return( *this );
	}

	CFIntTopDomainByTldIdxKey CFIntTopDomainByTldIdxKey::operator =( cfint::CFIntTopDomainHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTldId( src.getRequiredTldId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainByTldIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntTopDomainByTldIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() < rhs.getRequiredTldId() ) {
			return( false );
		}
		else if( lhs.getRequiredTldId() > rhs.getRequiredTldId() ) {
			return( true );
		}
		return( false );
	}
}

