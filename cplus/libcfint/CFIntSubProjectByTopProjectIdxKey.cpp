// Description: C++18 implementation for a SubProject by TopProjectIdx index key object.

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

#include <cfint/CFIntSubProjectByTopProjectIdxKey.hpp>
#include <cfint/CFIntSubProjectBuff.hpp>
#include <cfint/CFIntSubProjectHBuff.hpp>

namespace cfint {
	const std::string CFIntSubProjectByTopProjectIdxKey::CLASS_NAME( "CFIntSubProjectByTopProjectIdxKey" );
	const std::string CFIntSubProjectByTopProjectIdxKey::S_VALUE( "value" );
	const std::string CFIntSubProjectByTopProjectIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntSubProjectByTopProjectIdxKey::CFIntSubProjectByTopProjectIdxKey() {
		requiredTenantId = cfint::CFIntSubProjectBuff::TENANTID_INIT_VALUE;
		requiredTopProjectId = cfint::CFIntSubProjectBuff::TOPPROJECTID_INIT_VALUE;
	}

	CFIntSubProjectByTopProjectIdxKey::CFIntSubProjectByTopProjectIdxKey( const CFIntSubProjectByTopProjectIdxKey& src ) {
		requiredTenantId = cfint::CFIntSubProjectBuff::TENANTID_INIT_VALUE;
		requiredTopProjectId = cfint::CFIntSubProjectBuff::TOPPROJECTID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopProjectId( src.getRequiredTopProjectId() );
	}

	CFIntSubProjectByTopProjectIdxKey::~CFIntSubProjectByTopProjectIdxKey() {
	}

	const int64_t CFIntSubProjectByTopProjectIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntSubProjectByTopProjectIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntSubProjectByTopProjectIdxKey::setRequiredTenantId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTenantId" );
		if( value < cfint::CFIntSubProjectBuff::TENANTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntSubProjectBuff::TENANTID_MIN_VALUE );
		}
		requiredTenantId = value;
	}

	const int64_t CFIntSubProjectByTopProjectIdxKey::getRequiredTopProjectId() const {
		return( requiredTopProjectId );
	}

	const int64_t* CFIntSubProjectByTopProjectIdxKey::getRequiredTopProjectIdReference() const {
		return( &requiredTopProjectId );
	}

	void CFIntSubProjectByTopProjectIdxKey::setRequiredTopProjectId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredTopProjectId" );
		if( value < cfint::CFIntSubProjectBuff::TOPPROJECTID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntSubProjectBuff::TOPPROJECTID_MIN_VALUE );
		}
		requiredTopProjectId = value;
	}

	size_t CFIntSubProjectByTopProjectIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredTopProjectId() );
		return( hashCode );
	}

	std::string CFIntSubProjectByTopProjectIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSubProjectByTopProjectIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TopProjectId( "TopProjectId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopProjectId, getRequiredTopProjectId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator <( const CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator <( const CFIntSubProjectHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator <( const CFIntSubProjectBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator <=( const CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator <=( const CFIntSubProjectHBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator <=( const CFIntSubProjectBuff& rhs ) {
		if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator ==( const CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator ==( const CFIntSubProjectHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator ==( const CFIntSubProjectBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator !=( const CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator !=( const CFIntSubProjectHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator !=( const CFIntSubProjectBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator >=( const CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator >=( const CFIntSubProjectHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator >=( const CFIntSubProjectBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator >( const CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator >( const CFIntSubProjectHBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByTopProjectIdxKey::operator >( const CFIntSubProjectBuff& rhs ) {
		if( getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}
	CFIntSubProjectByTopProjectIdxKey CFIntSubProjectByTopProjectIdxKey::operator =( cfint::CFIntSubProjectByTopProjectIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopProjectId( src.getRequiredTopProjectId() );
		return( *this );
	}

	CFIntSubProjectByTopProjectIdxKey CFIntSubProjectByTopProjectIdxKey::operator =( cfint::CFIntSubProjectBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopProjectId( src.getRequiredTopProjectId() );
		return( *this );
	}

	CFIntSubProjectByTopProjectIdxKey CFIntSubProjectByTopProjectIdxKey::operator =( cfint::CFIntSubProjectHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopProjectId( src.getRequiredTopProjectId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
		if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectByTopProjectIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntSubProjectByTopProjectIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
		if( lhs.getRequiredTenantId() < rhs.getRequiredTenantId() ) {
			return( false );
		}
		else if( lhs.getRequiredTenantId() > rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() < rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		else if( lhs.getRequiredTopProjectId() > rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		return( false );
	}
}

