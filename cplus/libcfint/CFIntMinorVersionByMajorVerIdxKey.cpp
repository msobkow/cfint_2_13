// Description: C++18 implementation for a MinorVersion by MajorVerIdx index key object.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfint/CFIntMinorVersionByMajorVerIdxKey.hpp>
#include <cfint/CFIntMinorVersionBuff.hpp>
#include <cfint/CFIntMinorVersionHBuff.hpp>

namespace cfint {
	const std::string CFIntMinorVersionByMajorVerIdxKey::CLASS_NAME( "CFIntMinorVersionByMajorVerIdxKey" );
	const std::string CFIntMinorVersionByMajorVerIdxKey::S_VALUE( "value" );
	const std::string CFIntMinorVersionByMajorVerIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntMinorVersionByMajorVerIdxKey::CFIntMinorVersionByMajorVerIdxKey() {
		requiredTenantId = cfint::CFIntMinorVersionBuff::TENANTID_INIT_VALUE;
		requiredMajorVersionId = cfint::CFIntMinorVersionBuff::MAJORVERSIONID_INIT_VALUE;
	}

	CFIntMinorVersionByMajorVerIdxKey::CFIntMinorVersionByMajorVerIdxKey( const CFIntMinorVersionByMajorVerIdxKey& src ) {
		requiredTenantId = cfint::CFIntMinorVersionBuff::TENANTID_INIT_VALUE;
		requiredMajorVersionId = cfint::CFIntMinorVersionBuff::MAJORVERSIONID_INIT_VALUE;
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredMajorVersionId( src.getRequiredMajorVersionId() );
	}

	CFIntMinorVersionByMajorVerIdxKey::~CFIntMinorVersionByMajorVerIdxKey() {
	}

	const int64_t CFIntMinorVersionByMajorVerIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntMinorVersionByMajorVerIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntMinorVersionByMajorVerIdxKey::setRequiredTenantId( const int64_t value ) {
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

	const int64_t CFIntMinorVersionByMajorVerIdxKey::getRequiredMajorVersionId() const {
		return( requiredMajorVersionId );
	}

	const int64_t* CFIntMinorVersionByMajorVerIdxKey::getRequiredMajorVersionIdReference() const {
		return( &requiredMajorVersionId );
	}

	void CFIntMinorVersionByMajorVerIdxKey::setRequiredMajorVersionId( const int64_t value ) {
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

	size_t CFIntMinorVersionByMajorVerIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredMajorVersionId() );
		return( hashCode );
	}

	std::string CFIntMinorVersionByMajorVerIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMinorVersionByMajorVerIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_MajorVersionId( "MajorVersionId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_MajorVersionId, getRequiredMajorVersionId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator <( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
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
		return( false );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator <( const CFIntMinorVersionHBuff& rhs ) {
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
		return( false );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator <( const CFIntMinorVersionBuff& rhs ) {
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
		return( false );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator <=( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
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
		return( true );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator <=( const CFIntMinorVersionHBuff& rhs ) {
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
		return( true );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator <=( const CFIntMinorVersionBuff& rhs ) {
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
		return( true );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator ==( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator ==( const CFIntMinorVersionHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator ==( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator !=( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator !=( const CFIntMinorVersionHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator !=( const CFIntMinorVersionBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator >=( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
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
		return( true );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator >=( const CFIntMinorVersionHBuff& rhs ) {
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
		return( true );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator >=( const CFIntMinorVersionBuff& rhs ) {
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
		return( true );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator >( const CFIntMinorVersionByMajorVerIdxKey& rhs ) {
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
		return( false );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator >( const CFIntMinorVersionHBuff& rhs ) {
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
		return( false );
	}

	bool CFIntMinorVersionByMajorVerIdxKey::operator >( const CFIntMinorVersionBuff& rhs ) {
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
		return( false );
	}
	CFIntMinorVersionByMajorVerIdxKey CFIntMinorVersionByMajorVerIdxKey::operator =( cfint::CFIntMinorVersionByMajorVerIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredMajorVersionId( src.getRequiredMajorVersionId() );
		return( *this );
	}

	CFIntMinorVersionByMajorVerIdxKey CFIntMinorVersionByMajorVerIdxKey::operator =( cfint::CFIntMinorVersionBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredMajorVersionId( src.getRequiredMajorVersionId() );
		return( *this );
	}

	CFIntMinorVersionByMajorVerIdxKey CFIntMinorVersionByMajorVerIdxKey::operator =( cfint::CFIntMinorVersionHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredMajorVersionId( src.getRequiredMajorVersionId() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
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
		return( false );
	}

	bool operator <(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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
		return( false );
	}

	bool operator <(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
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
		return( false );
	}

	bool operator <=(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
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
		return( true );
	}

	bool operator <=(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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
		return( true );
	}

	bool operator <=(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
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
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredMajorVersionId() != rhs.getRequiredMajorVersionId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
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
		return( true );
	}

	bool operator >=(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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
		return( true );
	}

	bool operator >=(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
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
		return( true );
	}

	bool operator >(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionByMajorVerIdxKey& rhs ) {
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
		return( false );
	}

	bool operator >(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionHBuff& rhs ) {
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
		return( false );
	}

	bool operator >(const  cfint::CFIntMinorVersionByMajorVerIdxKey& lhs, const cfint::CFIntMinorVersionBuff& rhs ) {
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
		return( false );
	}
}

