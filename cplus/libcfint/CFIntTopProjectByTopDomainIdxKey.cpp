// Description: C++18 implementation for a TopProject by TopDomainIdx index key object.

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

#include <cfint/CFIntTopProjectByTopDomainIdxKey.hpp>
#include <cfint/CFIntTopProjectBuff.hpp>
#include <cfint/CFIntTopProjectHBuff.hpp>

namespace cfint {
	const std::string CFIntTopProjectByTopDomainIdxKey::CLASS_NAME( "CFIntTopProjectByTopDomainIdxKey" );
	const std::string CFIntTopProjectByTopDomainIdxKey::S_VALUE( "value" );
	const std::string CFIntTopProjectByTopDomainIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntTopProjectByTopDomainIdxKey::CFIntTopProjectByTopDomainIdxKey() {
		requiredTenantId = cfint::CFIntTopProjectBuff::TENANTID_INIT_VALUE;
		requiredTopDomainId = cfint::CFIntTopProjectBuff::TOPDOMAINID_INIT_VALUE;
	}

	CFIntTopProjectByTopDomainIdxKey::CFIntTopProjectByTopDomainIdxKey( const CFIntTopProjectByTopDomainIdxKey& src ) {
		requiredTenantId = cfint::CFIntTopProjectBuff::TENANTID_INIT_VALUE;
		requiredTopDomainId = cfint::CFIntTopProjectBuff::TOPDOMAINID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
	}

	CFIntTopProjectByTopDomainIdxKey::~CFIntTopProjectByTopDomainIdxKey() {
	}

	const int64_t CFIntTopProjectByTopDomainIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntTopProjectByTopDomainIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntTopProjectByTopDomainIdxKey::setRequiredTenantId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTenantId" );
		if( value < cfint::CFIntTopProjectBuff::TENANTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntTopProjectBuff::TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	const int64_t CFIntTopProjectByTopDomainIdxKey::getRequiredTopDomainId() const {
		return( requiredTopDomainId );
	}

	const int64_t* CFIntTopProjectByTopDomainIdxKey::getRequiredTopDomainIdReference() const {
		return( &requiredTopDomainId );
	}

	void CFIntTopProjectByTopDomainIdxKey::setRequiredTopDomainId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTopDomainId" );
		if( value < cfint::CFIntTopProjectBuff::TOPDOMAINID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntTopProjectBuff::TOPDOMAINID_MIN_VALUE );
		}
		requiredTopDomainId = value;
	}

	size_t CFIntTopProjectByTopDomainIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredTopDomainId() );
		return( hashCode );
	}

	std::string CFIntTopProjectByTopDomainIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTopProjectByTopDomainIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TopDomainId( "TopDomainId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopDomainId, getRequiredTopDomainId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntTopProjectByTopDomainIdxKey::operator <( const CFIntTopProjectByTopDomainIdxKey& rhs ) {
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

	bool CFIntTopProjectByTopDomainIdxKey::operator <( const CFIntTopProjectHBuff& rhs ) {
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

	bool CFIntTopProjectByTopDomainIdxKey::operator <( const CFIntTopProjectBuff& rhs ) {
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

	bool CFIntTopProjectByTopDomainIdxKey::operator <=( const CFIntTopProjectByTopDomainIdxKey& rhs ) {
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

	bool CFIntTopProjectByTopDomainIdxKey::operator <=( const CFIntTopProjectHBuff& rhs ) {
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

	bool CFIntTopProjectByTopDomainIdxKey::operator <=( const CFIntTopProjectBuff& rhs ) {
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

	bool CFIntTopProjectByTopDomainIdxKey::operator ==( const CFIntTopProjectByTopDomainIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTopProjectByTopDomainIdxKey::operator ==( const CFIntTopProjectHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTopProjectByTopDomainIdxKey::operator ==( const CFIntTopProjectBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTopProjectByTopDomainIdxKey::operator !=( const CFIntTopProjectByTopDomainIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopProjectByTopDomainIdxKey::operator !=( const CFIntTopProjectHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopProjectByTopDomainIdxKey::operator !=( const CFIntTopProjectBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopProjectByTopDomainIdxKey::operator >=( const CFIntTopProjectByTopDomainIdxKey& rhs ) {
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

	bool CFIntTopProjectByTopDomainIdxKey::operator >=( const CFIntTopProjectHBuff& rhs ) {
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

	bool CFIntTopProjectByTopDomainIdxKey::operator >=( const CFIntTopProjectBuff& rhs ) {
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

	bool CFIntTopProjectByTopDomainIdxKey::operator >( const CFIntTopProjectByTopDomainIdxKey& rhs ) {
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

	bool CFIntTopProjectByTopDomainIdxKey::operator >( const CFIntTopProjectHBuff& rhs ) {
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

	bool CFIntTopProjectByTopDomainIdxKey::operator >( const CFIntTopProjectBuff& rhs ) {
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
	CFIntTopProjectByTopDomainIdxKey CFIntTopProjectByTopDomainIdxKey::operator =( cfint::CFIntTopProjectByTopDomainIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		return( *this );
	}

	CFIntTopProjectByTopDomainIdxKey CFIntTopProjectByTopDomainIdxKey::operator =( cfint::CFIntTopProjectBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		return( *this );
	}

	CFIntTopProjectByTopDomainIdxKey CFIntTopProjectByTopDomainIdxKey::operator =( cfint::CFIntTopProjectHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs ) {
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

	bool operator <(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs ) {
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

	bool operator <(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs ) {
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

	bool operator ==(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs ) {
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

	bool operator >=(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectByTopDomainIdxKey& rhs ) {
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

	bool operator >(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectHBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntTopProjectByTopDomainIdxKey& lhs, const cfint::CFIntTopProjectBuff& rhs ) {
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
}

