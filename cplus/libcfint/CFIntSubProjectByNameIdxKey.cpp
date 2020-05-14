// Description: C++18 implementation for a SubProject by NameIdx index key object.

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

#include <cfint/CFIntSubProjectByNameIdxKey.hpp>
#include <cfint/CFIntSubProjectBuff.hpp>
#include <cfint/CFIntSubProjectHBuff.hpp>

namespace cfint {
	const std::string CFIntSubProjectByNameIdxKey::CLASS_NAME( "CFIntSubProjectByNameIdxKey" );
	const std::string CFIntSubProjectByNameIdxKey::S_VALUE( "value" );
	const std::string CFIntSubProjectByNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntSubProjectByNameIdxKey::CFIntSubProjectByNameIdxKey() {
		requiredTenantId = cfint::CFIntSubProjectBuff::TENANTID_INIT_VALUE;
		requiredTopProjectId = cfint::CFIntSubProjectBuff::TOPPROJECTID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntSubProjectBuff::NAME_INIT_VALUE );
	}

	CFIntSubProjectByNameIdxKey::CFIntSubProjectByNameIdxKey( const CFIntSubProjectByNameIdxKey& src ) {
		requiredTenantId = cfint::CFIntSubProjectBuff::TENANTID_INIT_VALUE;
		requiredTopProjectId = cfint::CFIntSubProjectBuff::TOPPROJECTID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntSubProjectBuff::NAME_INIT_VALUE );
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopProjectId( src.getRequiredTopProjectId() );
		setRequiredName( src.getRequiredName() );
	}

	CFIntSubProjectByNameIdxKey::~CFIntSubProjectByNameIdxKey() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
	}

	const int64_t CFIntSubProjectByNameIdxKey::getRequiredTenantId() const {
		return( requiredTenantId );
	}

	const int64_t* CFIntSubProjectByNameIdxKey::getRequiredTenantIdReference() const {
		return( &requiredTenantId );
	}

	void CFIntSubProjectByNameIdxKey::setRequiredTenantId( const int64_t value ) {
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

	const int64_t CFIntSubProjectByNameIdxKey::getRequiredTopProjectId() const {
		return( requiredTopProjectId );
	}

	const int64_t* CFIntSubProjectByNameIdxKey::getRequiredTopProjectIdReference() const {
		return( &requiredTopProjectId );
	}

	void CFIntSubProjectByNameIdxKey::setRequiredTopProjectId( const int64_t value ) {
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

	const std::string& CFIntSubProjectByNameIdxKey::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntSubProjectByNameIdxKey::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntSubProjectByNameIdxKey::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFIntSubProjectBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntSubProjectBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	size_t CFIntSubProjectByNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredTenantId() );
		hashCode = hashCode + (int)( getRequiredTopProjectId() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		return( hashCode );
	}

	std::string CFIntSubProjectByNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntSubProjectByNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_TopProjectId( "TopProjectId" );
		static const std::string S_Name( "Name" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopProjectId, getRequiredTopProjectId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntSubProjectByNameIdxKey::operator <( const CFIntSubProjectByNameIdxKey& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByNameIdxKey::operator <( const CFIntSubProjectHBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByNameIdxKey::operator <( const CFIntSubProjectBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByNameIdxKey::operator <=( const CFIntSubProjectByNameIdxKey& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByNameIdxKey::operator <=( const CFIntSubProjectHBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByNameIdxKey::operator <=( const CFIntSubProjectBuff& rhs ) {
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
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByNameIdxKey::operator ==( const CFIntSubProjectByNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntSubProjectByNameIdxKey::operator ==( const CFIntSubProjectHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntSubProjectByNameIdxKey::operator ==( const CFIntSubProjectBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntSubProjectByNameIdxKey::operator !=( const CFIntSubProjectByNameIdxKey& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByNameIdxKey::operator !=( const CFIntSubProjectHBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByNameIdxKey::operator !=( const CFIntSubProjectBuff& rhs ) {
		if( getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByNameIdxKey::operator >=( const CFIntSubProjectByNameIdxKey& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByNameIdxKey::operator >=( const CFIntSubProjectHBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByNameIdxKey::operator >=( const CFIntSubProjectBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntSubProjectByNameIdxKey::operator >( const CFIntSubProjectByNameIdxKey& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByNameIdxKey::operator >( const CFIntSubProjectHBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntSubProjectByNameIdxKey::operator >( const CFIntSubProjectBuff& rhs ) {
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
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
	CFIntSubProjectByNameIdxKey CFIntSubProjectByNameIdxKey::operator =( cfint::CFIntSubProjectByNameIdxKey& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopProjectId( src.getRequiredTopProjectId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntSubProjectByNameIdxKey CFIntSubProjectByNameIdxKey::operator =( cfint::CFIntSubProjectBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopProjectId( src.getRequiredTopProjectId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntSubProjectByNameIdxKey CFIntSubProjectByNameIdxKey::operator =( cfint::CFIntSubProjectHBuff& src ) {
		setRequiredTenantId( src.getRequiredTenantId() );
		setRequiredTopProjectId( src.getRequiredTopProjectId() );
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
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
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( false );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
		if( lhs.getRequiredTenantId() != rhs.getRequiredTenantId() ) {
			return( true );
		}
		if( lhs.getRequiredTopProjectId() != rhs.getRequiredTopProjectId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectByNameIdxKey& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectHBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntSubProjectByNameIdxKey& lhs, const cfint::CFIntSubProjectBuff& rhs ) {
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
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
}

