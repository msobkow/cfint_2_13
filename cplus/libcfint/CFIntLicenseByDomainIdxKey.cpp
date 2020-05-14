// Description: C++18 implementation for a License by DomainIdx index key object.

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

#include <cfint/CFIntLicenseByDomainIdxKey.hpp>
#include <cfint/CFIntLicenseBuff.hpp>
#include <cfint/CFIntLicenseHBuff.hpp>

namespace cfint {
	const std::string CFIntLicenseByDomainIdxKey::CLASS_NAME( "CFIntLicenseByDomainIdxKey" );
	const std::string CFIntLicenseByDomainIdxKey::S_VALUE( "value" );
	const std::string CFIntLicenseByDomainIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntLicenseByDomainIdxKey::CFIntLicenseByDomainIdxKey() {
		requiredTenantId = cfint::CFIntLicenseBuff::TENANTID_INIT_VALUE;
		requiredTopDomainId = cfint::CFIntLicenseBuff::TOPDOMAINID_INIT_VALUE;
	}

	CFIntLicenseByDomainIdxKey::CFIntLicenseByDomainIdxKey( const CFIntLicenseByDomainIdxKey& src ) {
		requiredTenantId = cfint::CFIntLicenseBuff::TENANTID_INIT_VALUE;
		requiredTopDomainId = cfint::CFIntLicenseBuff::TOPDOMAINID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
	}

	CFIntLicenseByDomainIdxKey::~CFIntLicenseByDomainIdxKey() {
	}

	const int64_t CFIntLicenseByDomainIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntLicenseByDomainIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntLicenseByDomainIdxKey::setRequiredTenantId( const int64_t value ) {
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

	const int64_t CFIntLicenseByDomainIdxKey::getRequiredTopDomainId() const {
		return( requiredTopDomainId );
	}

	const int64_t* CFIntLicenseByDomainIdxKey::getRequiredTopDomainIdReference() const {
		return( &requiredTopDomainId );
	}

	void CFIntLicenseByDomainIdxKey::setRequiredTopDomainId( const int64_t value ) {
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

	size_t CFIntLicenseByDomainIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredTopDomainId() );
		return( hashCode );
	}

	std::string CFIntLicenseByDomainIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntLicenseByDomainIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TopDomainId( "TopDomainId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopDomainId, getRequiredTopDomainId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntLicenseByDomainIdxKey::operator <( const CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool CFIntLicenseByDomainIdxKey::operator <( const CFIntLicenseHBuff& rhs ) {
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

	bool CFIntLicenseByDomainIdxKey::operator <( const CFIntLicenseBuff& rhs ) {
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

	bool CFIntLicenseByDomainIdxKey::operator <=( const CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool CFIntLicenseByDomainIdxKey::operator <=( const CFIntLicenseHBuff& rhs ) {
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

	bool CFIntLicenseByDomainIdxKey::operator <=( const CFIntLicenseBuff& rhs ) {
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

	bool CFIntLicenseByDomainIdxKey::operator ==( const CFIntLicenseByDomainIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseByDomainIdxKey::operator ==( const CFIntLicenseHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseByDomainIdxKey::operator ==( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseByDomainIdxKey::operator !=( const CFIntLicenseByDomainIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByDomainIdxKey::operator !=( const CFIntLicenseHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByDomainIdxKey::operator !=( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByDomainIdxKey::operator >=( const CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool CFIntLicenseByDomainIdxKey::operator >=( const CFIntLicenseHBuff& rhs ) {
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

	bool CFIntLicenseByDomainIdxKey::operator >=( const CFIntLicenseBuff& rhs ) {
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

	bool CFIntLicenseByDomainIdxKey::operator >( const CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool CFIntLicenseByDomainIdxKey::operator >( const CFIntLicenseHBuff& rhs ) {
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

	bool CFIntLicenseByDomainIdxKey::operator >( const CFIntLicenseBuff& rhs ) {
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
	CFIntLicenseByDomainIdxKey CFIntLicenseByDomainIdxKey::operator =( cfint::CFIntLicenseByDomainIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		return( *this );
	}

	CFIntLicenseByDomainIdxKey CFIntLicenseByDomainIdxKey::operator =( cfint::CFIntLicenseBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		return( *this );
	}

	CFIntLicenseByDomainIdxKey CFIntLicenseByDomainIdxKey::operator =( cfint::CFIntLicenseHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool operator <(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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

	bool operator <(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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

	bool operator ==(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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

	bool operator >=(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseByDomainIdxKey& rhs ) {
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

	bool operator >(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntLicenseByDomainIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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

