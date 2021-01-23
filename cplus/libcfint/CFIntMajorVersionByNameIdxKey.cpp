// Description: C++18 implementation for a MajorVersion by NameIdx index key object.

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

#include <cfint/CFIntMajorVersionByNameIdxKey.hpp>
#include <cfint/CFIntMajorVersionBuff.hpp>
#include <cfint/CFIntMajorVersionHBuff.hpp>

namespace cfint {
	const std::string CFIntMajorVersionByNameIdxKey::CLASS_NAME( "CFIntMajorVersionByNameIdxKey" );
	const std::string CFIntMajorVersionByNameIdxKey::S_VALUE( "value" );
	const std::string CFIntMajorVersionByNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntMajorVersionByNameIdxKey::CFIntMajorVersionByNameIdxKey() {
		requiredTenantId = cfint::CFIntMajorVersionBuff::TENANTID_INIT_VALUE;
		requiredSubProjectId = cfint::CFIntMajorVersionBuff::SUBPROJECTID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntMajorVersionBuff::NAME_INIT_VALUE );
	}

	CFIntMajorVersionByNameIdxKey::CFIntMajorVersionByNameIdxKey( const CFIntMajorVersionByNameIdxKey& src ) {
		requiredTenantId = cfint::CFIntMajorVersionBuff::TENANTID_INIT_VALUE;
		requiredSubProjectId = cfint::CFIntMajorVersionBuff::SUBPROJECTID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntMajorVersionBuff::NAME_INIT_VALUE );
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredSubProjectId( src.getRequiredSubProjectId() );
		setRequiredName( src.getRequiredName() );
	}

	CFIntMajorVersionByNameIdxKey::~CFIntMajorVersionByNameIdxKey() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
	}

	const int64_t CFIntMajorVersionByNameIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntMajorVersionByNameIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntMajorVersionByNameIdxKey::setRequiredTenantId( const int64_t value ) {
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

	const int64_t CFIntMajorVersionByNameIdxKey::getRequiredSubProjectId() const {
		return( requiredSubProjectId );
	}

	const int64_t* CFIntMajorVersionByNameIdxKey::getRequiredSubProjectIdReference() const {
		return( &requiredSubProjectId );
	}

	void CFIntMajorVersionByNameIdxKey::setRequiredSubProjectId( const int64_t value ) {
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

	const std::string& CFIntMajorVersionByNameIdxKey::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntMajorVersionByNameIdxKey::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntMajorVersionByNameIdxKey::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFIntMajorVersionBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntMajorVersionBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	size_t CFIntMajorVersionByNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredSubProjectId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		return( hashCode );
	}

	std::string CFIntMajorVersionByNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMajorVersionByNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_SubProjectId( "SubProjectId" );
		static const std::string S_Name( "Name" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_SubProjectId, getRequiredSubProjectId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntMajorVersionByNameIdxKey::operator <( const CFIntMajorVersionByNameIdxKey& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionByNameIdxKey::operator <( const CFIntMajorVersionHBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionByNameIdxKey::operator <( const CFIntMajorVersionBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionByNameIdxKey::operator <=( const CFIntMajorVersionByNameIdxKey& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionByNameIdxKey::operator <=( const CFIntMajorVersionHBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionByNameIdxKey::operator <=( const CFIntMajorVersionBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionByNameIdxKey::operator ==( const CFIntMajorVersionByNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMajorVersionByNameIdxKey::operator ==( const CFIntMajorVersionHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMajorVersionByNameIdxKey::operator ==( const CFIntMajorVersionBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMajorVersionByNameIdxKey::operator !=( const CFIntMajorVersionByNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionByNameIdxKey::operator !=( const CFIntMajorVersionHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionByNameIdxKey::operator !=( const CFIntMajorVersionBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionByNameIdxKey::operator >=( const CFIntMajorVersionByNameIdxKey& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionByNameIdxKey::operator >=( const CFIntMajorVersionHBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionByNameIdxKey::operator >=( const CFIntMajorVersionBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMajorVersionByNameIdxKey::operator >( const CFIntMajorVersionByNameIdxKey& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionByNameIdxKey::operator >( const CFIntMajorVersionHBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMajorVersionByNameIdxKey::operator >( const CFIntMajorVersionBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
	CFIntMajorVersionByNameIdxKey CFIntMajorVersionByNameIdxKey::operator =( cfint::CFIntMajorVersionByNameIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredSubProjectId( src.getRequiredSubProjectId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntMajorVersionByNameIdxKey CFIntMajorVersionByNameIdxKey::operator =( cfint::CFIntMajorVersionBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredSubProjectId( src.getRequiredSubProjectId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntMajorVersionByNameIdxKey CFIntMajorVersionByNameIdxKey::operator =( cfint::CFIntMajorVersionHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredSubProjectId( src.getRequiredSubProjectId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredSubProjectId() != rhs.getRequiredSubProjectId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionHBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMajorVersionByNameIdxKey& lhs, const cfint::CFIntMajorVersionBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
}

