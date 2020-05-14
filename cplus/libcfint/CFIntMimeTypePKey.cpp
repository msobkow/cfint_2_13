// Description: C++18 implementation of a MimeType primary key object.

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

#include <cfint/CFIntMimeTypePKey.hpp>
#include <cfint/CFIntMimeTypeBuff.hpp>
#include <cfint/CFIntMimeTypeHPKey.hpp>
#include <cfint/CFIntMimeTypeHBuff.hpp>

namespace cfint {

	const std::string CFIntMimeTypePKey::CLASS_NAME( "CFIntMimeTypePKey" );
	const std::string CFIntMimeTypePKey::S_VALUE( "value" );
	const std::string CFIntMimeTypePKey::S_VALUE_LENGTH( "value.length()" );

	CFIntMimeTypePKey::CFIntMimeTypePKey() {
		requiredMimeTypeId = cfint::CFIntMimeTypeBuff::MIMETYPEID_INIT_VALUE;
	}

	CFIntMimeTypePKey::CFIntMimeTypePKey( const CFIntMimeTypePKey& src ) {
		requiredMimeTypeId = cfint::CFIntMimeTypeBuff::MIMETYPEID_INIT_VALUE;
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
	}

	CFIntMimeTypePKey::~CFIntMimeTypePKey() {
	}

	const int32_t CFIntMimeTypePKey::getRequiredMimeTypeId() const {
		return( requiredMimeTypeId );
	}

	const int32_t* CFIntMimeTypePKey::getRequiredMimeTypeIdReference() const {
		return( &requiredMimeTypeId );
	}

	void CFIntMimeTypePKey::setRequiredMimeTypeId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredMimeTypeId" );
		if( value < cfint::CFIntMimeTypeBuff::MIMETYPEID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntMimeTypeBuff::MIMETYPEID_MIN_VALUE );
		}
		requiredMimeTypeId = value;
	}

	bool CFIntMimeTypePKey::operator <( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypePKey::operator <( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypePKey::operator <( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypePKey::operator <( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypePKey::operator <=( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator <=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator <=( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator <=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator ==( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator ==( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator ==( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator ==( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator !=( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypePKey::operator !=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypePKey::operator !=( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypePKey::operator !=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypePKey::operator >=( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator >=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator >=( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator >=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypePKey::operator >( const CFIntMimeTypeHPKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypePKey::operator >( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypePKey::operator >( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypePKey::operator >( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	CFIntMimeTypePKey CFIntMimeTypePKey::operator =( cfint::CFIntMimeTypePKey& src ) {
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		return( *this );
	}

	CFIntMimeTypePKey CFIntMimeTypePKey::operator =( cfint::CFIntMimeTypeHPKey& src ) {
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		return( *this );
	}

	CFIntMimeTypePKey CFIntMimeTypePKey::operator =( cfint::CFIntMimeTypeBuff& src ) {
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		return( *this );
	}

	CFIntMimeTypePKey CFIntMimeTypePKey::operator =( cfint::CFIntMimeTypeHBuff& src ) {
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		return( *this );
	}

	size_t CFIntMimeTypePKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + getRequiredMimeTypeId();
		return( hashCode );
	}

	std::string CFIntMimeTypePKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMimeTypePKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_MimeTypeId( "MimeTypeId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_MimeTypeId, getRequiredMimeTypeId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypePKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}
}

