// Description: C++18 implementation for a URLProtocol by UNameIdx index key object.

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

#include <cfint/CFIntURLProtocolByUNameIdxKey.hpp>
#include <cfint/CFIntURLProtocolBuff.hpp>
#include <cfint/CFIntURLProtocolHBuff.hpp>

namespace cfint {
	const std::string CFIntURLProtocolByUNameIdxKey::CLASS_NAME( "CFIntURLProtocolByUNameIdxKey" );
	const std::string CFIntURLProtocolByUNameIdxKey::S_VALUE( "value" );
	const std::string CFIntURLProtocolByUNameIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntURLProtocolByUNameIdxKey::CFIntURLProtocolByUNameIdxKey() {
		requiredName = new std::string( cfint::CFIntURLProtocolBuff::NAME_INIT_VALUE );
	}

	CFIntURLProtocolByUNameIdxKey::CFIntURLProtocolByUNameIdxKey( const CFIntURLProtocolByUNameIdxKey& src ) {
		requiredName = new std::string( cfint::CFIntURLProtocolBuff::NAME_INIT_VALUE );
		setRequiredName( src.getRequiredName() );
	}

	CFIntURLProtocolByUNameIdxKey::~CFIntURLProtocolByUNameIdxKey() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
	}

	const std::string& CFIntURLProtocolByUNameIdxKey::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntURLProtocolByUNameIdxKey::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntURLProtocolByUNameIdxKey::setRequiredName( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredName" );
		if( value.length() > CFIntURLProtocolBuff::NAME_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntURLProtocolBuff::NAME_MAX_LEN );
		}
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		requiredName = new std::string( value );
	}

	size_t CFIntURLProtocolByUNameIdxKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		return( hashCode );
	}

	std::string CFIntURLProtocolByUNameIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntURLProtocolByUNameIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Name( "Name" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator <( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator <( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator <( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator <=( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator <=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator <=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator ==( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator ==( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator ==( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator !=( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator !=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator !=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator >=( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator >=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator >=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator >( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator >( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByUNameIdxKey::operator >( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
	CFIntURLProtocolByUNameIdxKey CFIntURLProtocolByUNameIdxKey::operator =( cfint::CFIntURLProtocolByUNameIdxKey& src ) {
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntURLProtocolByUNameIdxKey CFIntURLProtocolByUNameIdxKey::operator =( cfint::CFIntURLProtocolBuff& src ) {
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

	CFIntURLProtocolByUNameIdxKey CFIntURLProtocolByUNameIdxKey::operator =( cfint::CFIntURLProtocolHBuff& src ) {
		setRequiredName( src.getRequiredName() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolByUNameIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}
}

