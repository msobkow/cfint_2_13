// Description: C++18 implementation for a TopDomain by NameIdx index key object.

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

#include <cfint/CFIntTopDomainByNameIdxKey.hpp>
#include <cfint/CFIntTopDomainBuff.hpp>
#include <cfint/CFIntTopDomainHBuff.hpp>

namespace cfint {
	const std::string CFIntTopDomainByNameIdxKey::CLASS_NAME( "CFIntTopDomainByNameIdxKey" );
	const std::string CFIntTopDomainByNameIdxKey::S_VALUE( "value" );
	const std::string CFIntTopDomainByNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntTopDomainByNameIdxKey::CFIntTopDomainByNameIdxKey() {
		requiredTenantId = cfint::CFIntTopDomainBuff::TENANTID_INIT_VALUE;
		requiredTldId = cfint::CFIntTopDomainBuff::TLDID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntTopDomainBuff::NAME_INIT_VALUE );
	}

	CFIntTopDomainByNameIdxKey::CFIntTopDomainByNameIdxKey( const CFIntTopDomainByNameIdxKey& src ) {
		requiredTenantId = cfint::CFIntTopDomainBuff::TENANTID_INIT_VALUE;
		requiredTldId = cfint::CFIntTopDomainBuff::TLDID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntTopDomainBuff::NAME_INIT_VALUE );
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTldId( src.getRequiredTldId() );
		setRequiredName( src.getRequiredName() );
	}

	CFIntTopDomainByNameIdxKey::~CFIntTopDomainByNameIdxKey() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
	}

	const int64_t CFIntTopDomainByNameIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntTopDomainByNameIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntTopDomainByNameIdxKey::setRequiredTenantId( const int64_t value ) {
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

	const int64_t CFIntTopDomainByNameIdxKey::getRequiredTldId() const {
		return( requiredTldId );
	}

	const int64_t* CFIntTopDomainByNameIdxKey::getRequiredTldIdReference() const {
		return( &requiredTldId );
	}

	void CFIntTopDomainByNameIdxKey::setRequiredTldId( const int64_t value ) {
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

	const std::string& CFIntTopDomainByNameIdxKey::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntTopDomainByNameIdxKey::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntTopDomainByNameIdxKey::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFIntTopDomainBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntTopDomainBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	size_t CFIntTopDomainByNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredTldId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		return( hashCode );
	}

	std::string CFIntTopDomainByNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntTopDomainByNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TldId( "TldId" );
		static const std::string S_Name( "Name" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TldId, getRequiredTldId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntTopDomainByNameIdxKey::operator <( const CFIntTopDomainByNameIdxKey& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByNameIdxKey::operator <( const CFIntTopDomainHBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByNameIdxKey::operator <( const CFIntTopDomainBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByNameIdxKey::operator <=( const CFIntTopDomainByNameIdxKey& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByNameIdxKey::operator <=( const CFIntTopDomainHBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByNameIdxKey::operator <=( const CFIntTopDomainBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByNameIdxKey::operator ==( const CFIntTopDomainByNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTopDomainByNameIdxKey::operator ==( const CFIntTopDomainHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTopDomainByNameIdxKey::operator ==( const CFIntTopDomainBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntTopDomainByNameIdxKey::operator !=( const CFIntTopDomainByNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByNameIdxKey::operator !=( const CFIntTopDomainHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByNameIdxKey::operator !=( const CFIntTopDomainBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByNameIdxKey::operator >=( const CFIntTopDomainByNameIdxKey& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByNameIdxKey::operator >=( const CFIntTopDomainHBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByNameIdxKey::operator >=( const CFIntTopDomainBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntTopDomainByNameIdxKey::operator >( const CFIntTopDomainByNameIdxKey& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByNameIdxKey::operator >( const CFIntTopDomainHBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntTopDomainByNameIdxKey::operator >( const CFIntTopDomainBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
	CFIntTopDomainByNameIdxKey CFIntTopDomainByNameIdxKey::operator =( cfint::CFIntTopDomainByNameIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTldId( src.getRequiredTldId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntTopDomainByNameIdxKey CFIntTopDomainByNameIdxKey::operator =( cfint::CFIntTopDomainBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTldId( src.getRequiredTldId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntTopDomainByNameIdxKey CFIntTopDomainByNameIdxKey::operator =( cfint::CFIntTopDomainHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTldId( src.getRequiredTldId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTldId() != rhs.getRequiredTldId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainHBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntTopDomainByNameIdxKey& lhs, const cfint::CFIntTopDomainBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
}

