// Description: C++18 implementation for a License by UNameIdx index key object.

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

#include <cfint/CFIntLicenseByUNameIdxKey.hpp>
#include <cfint/CFIntLicenseBuff.hpp>
#include <cfint/CFIntLicenseHBuff.hpp>

namespace cfint {
	const std::string CFIntLicenseByUNameIdxKey::CLASS_NAME( "CFIntLicenseByUNameIdxKey" );
	const std::string CFIntLicenseByUNameIdxKey::S_VALUE( "value" );
	const std::string CFIntLicenseByUNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntLicenseByUNameIdxKey::CFIntLicenseByUNameIdxKey() {
		requiredTenantId = cfint::CFIntLicenseBuff::TENANTID_INIT_VALUE;
		requiredTopDomainId = cfint::CFIntLicenseBuff::TOPDOMAINID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntLicenseBuff::NAME_INIT_VALUE );
	}

	CFIntLicenseByUNameIdxKey::CFIntLicenseByUNameIdxKey( const CFIntLicenseByUNameIdxKey& src ) {
		requiredTenantId = cfint::CFIntLicenseBuff::TENANTID_INIT_VALUE;
		requiredTopDomainId = cfint::CFIntLicenseBuff::TOPDOMAINID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntLicenseBuff::NAME_INIT_VALUE );
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		setRequiredName( src.getRequiredName() );
	}

	CFIntLicenseByUNameIdxKey::~CFIntLicenseByUNameIdxKey() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
	}

	const int64_t CFIntLicenseByUNameIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntLicenseByUNameIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntLicenseByUNameIdxKey::setRequiredTenantId( const int64_t value ) {
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

	const int64_t CFIntLicenseByUNameIdxKey::getRequiredTopDomainId() const {
		return( requiredTopDomainId );
	}

	const int64_t* CFIntLicenseByUNameIdxKey::getRequiredTopDomainIdReference() const {
		return( &requiredTopDomainId );
	}

	void CFIntLicenseByUNameIdxKey::setRequiredTopDomainId( const int64_t value ) {
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

	const std::string& CFIntLicenseByUNameIdxKey::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntLicenseByUNameIdxKey::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntLicenseByUNameIdxKey::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFIntLicenseBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntLicenseBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	size_t CFIntLicenseByUNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredTopDomainId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		return( hashCode );
	}

	std::string CFIntLicenseByUNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntLicenseByUNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TopDomainId( "TopDomainId" );
		static const std::string S_Name( "Name" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopDomainId, getRequiredTopDomainId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntLicenseByUNameIdxKey::operator <( const CFIntLicenseByUNameIdxKey& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByUNameIdxKey::operator <( const CFIntLicenseHBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByUNameIdxKey::operator <( const CFIntLicenseBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByUNameIdxKey::operator <=( const CFIntLicenseByUNameIdxKey& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByUNameIdxKey::operator <=( const CFIntLicenseHBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByUNameIdxKey::operator <=( const CFIntLicenseBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByUNameIdxKey::operator ==( const CFIntLicenseByUNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseByUNameIdxKey::operator ==( const CFIntLicenseHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseByUNameIdxKey::operator ==( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntLicenseByUNameIdxKey::operator !=( const CFIntLicenseByUNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByUNameIdxKey::operator !=( const CFIntLicenseHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByUNameIdxKey::operator !=( const CFIntLicenseBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByUNameIdxKey::operator >=( const CFIntLicenseByUNameIdxKey& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByUNameIdxKey::operator >=( const CFIntLicenseHBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByUNameIdxKey::operator >=( const CFIntLicenseBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntLicenseByUNameIdxKey::operator >( const CFIntLicenseByUNameIdxKey& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByUNameIdxKey::operator >( const CFIntLicenseHBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntLicenseByUNameIdxKey::operator >( const CFIntLicenseBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
	CFIntLicenseByUNameIdxKey CFIntLicenseByUNameIdxKey::operator =( cfint::CFIntLicenseByUNameIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntLicenseByUNameIdxKey CFIntLicenseByUNameIdxKey::operator =( cfint::CFIntLicenseBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntLicenseByUNameIdxKey CFIntLicenseByUNameIdxKey::operator =( cfint::CFIntLicenseHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopDomainId( src.getRequiredTopDomainId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopDomainId() != rhs.getRequiredTopDomainId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseByUNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseHBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntLicenseByUNameIdxKey& lhs, const cfint::CFIntLicenseBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
}

