// Description: C++18 implementation for a MimeType by UNameIdx index key object.

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

#include <cfint/CFIntMimeTypeByUNameIdxKey.hpp>
#include <cfint/CFIntMimeTypeBuff.hpp>
#include <cfint/CFIntMimeTypeHBuff.hpp>

namespace cfint {
	const std::string CFIntMimeTypeByUNameIdxKey::CLASS_NAME( "CFIntMimeTypeByUNameIdxKey" );
	const std::string CFIntMimeTypeByUNameIdxKey::S_VALUE( "value" );
	const std::string CFIntMimeTypeByUNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntMimeTypeByUNameIdxKey::CFIntMimeTypeByUNameIdxKey() {
		requiredName = new std::string( cfint::CFIntMimeTypeBuff::NAME_INIT_VALUE );
	}

	CFIntMimeTypeByUNameIdxKey::CFIntMimeTypeByUNameIdxKey( const CFIntMimeTypeByUNameIdxKey& src ) {
		requiredName = new std::string( cfint::CFIntMimeTypeBuff::NAME_INIT_VALUE );
		setRequiredName( src.getRequiredName() );
	}

	CFIntMimeTypeByUNameIdxKey::~CFIntMimeTypeByUNameIdxKey() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
	}

	const std::string& CFIntMimeTypeByUNameIdxKey::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntMimeTypeByUNameIdxKey::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntMimeTypeByUNameIdxKey::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFIntMimeTypeBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntMimeTypeBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	size_t CFIntMimeTypeByUNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		return( hashCode );
	}

	std::string CFIntMimeTypeByUNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntMimeTypeByUNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Name( "Name" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator <( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator <( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator <( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator <=( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator <=( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator <=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator ==( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator ==( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator ==( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator !=( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator !=( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator !=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator >=( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator >=( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator >=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator >( const CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator >( const CFIntMimeTypeHBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeByUNameIdxKey::operator >( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
	CFIntMimeTypeByUNameIdxKey CFIntMimeTypeByUNameIdxKey::operator =( cfint::CFIntMimeTypeByUNameIdxKey& src ) {
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntMimeTypeByUNameIdxKey CFIntMimeTypeByUNameIdxKey::operator =( cfint::CFIntMimeTypeBuff& src ) {
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntMimeTypeByUNameIdxKey CFIntMimeTypeByUNameIdxKey::operator =( cfint::CFIntMimeTypeHBuff& src ) {
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeByUNameIdxKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
}

