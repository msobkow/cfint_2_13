// Description: C++18 implementation for a URLProtocol by IsSecureIdx index key object.

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

#include <cfint/CFIntURLProtocolByIsSecureIdxKey.hpp>
#include <cfint/CFIntURLProtocolBuff.hpp>
#include <cfint/CFIntURLProtocolHBuff.hpp>

namespace cfint {
	const std::string CFIntURLProtocolByIsSecureIdxKey::CLASS_NAME( "CFIntURLProtocolByIsSecureIdxKey" );
	const std::string CFIntURLProtocolByIsSecureIdxKey::S_VALUE( "value" );
	const std::string CFIntURLProtocolByIsSecureIdxKey::S_VALUE_LENGTH( "value.length()" );


	CFIntURLProtocolByIsSecureIdxKey::CFIntURLProtocolByIsSecureIdxKey() {
		requiredIsSecure = cfint::CFIntURLProtocolBuff::ISSECURE_INIT_VALUE;
	}

	CFIntURLProtocolByIsSecureIdxKey::CFIntURLProtocolByIsSecureIdxKey( const CFIntURLProtocolByIsSecureIdxKey& src ) {
		requiredIsSecure = cfint::CFIntURLProtocolBuff::ISSECURE_INIT_VALUE;
		setRequiredIsSecure( src.getRequiredIsSecure() );
	}

	CFIntURLProtocolByIsSecureIdxKey::~CFIntURLProtocolByIsSecureIdxKey() {
	}

	const bool CFIntURLProtocolByIsSecureIdxKey::getRequiredIsSecure() const {
		return( requiredIsSecure );
	}

	const bool* CFIntURLProtocolByIsSecureIdxKey::getRequiredIsSecureReference() const {
		return( &requiredIsSecure );
	}

	void CFIntURLProtocolByIsSecureIdxKey::setRequiredIsSecure( const bool value ) {
		requiredIsSecure = value;
	}

	size_t CFIntURLProtocolByIsSecureIdxKey::hashCode() const {
		size_t hashCode = 0;
		if( getRequiredIsSecure() ) {
			hashCode = ( hashCode * 2 ) + 1;
		}
		else {
			hashCode = hashCode * 2;
		}
		return( hashCode );
	}

	std::string CFIntURLProtocolByIsSecureIdxKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntURLProtocolByIsSecureIdxKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_IsSecure( "IsSecure" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsSecure, getRequiredIsSecure() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator <( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator <( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator <( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator <=( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator <=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator <=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator ==( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator ==( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator ==( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator !=( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator !=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator !=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator >=( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator >=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator >=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator >( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator >( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolByIsSecureIdxKey::operator >( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}
	CFIntURLProtocolByIsSecureIdxKey CFIntURLProtocolByIsSecureIdxKey::operator =( cfint::CFIntURLProtocolByIsSecureIdxKey& src ) {
		setRequiredIsSecure( src.getRequiredIsSecure() );
		return( *this );
	}

	CFIntURLProtocolByIsSecureIdxKey CFIntURLProtocolByIsSecureIdxKey::operator =( cfint::CFIntURLProtocolBuff& src ) {
		setRequiredIsSecure( src.getRequiredIsSecure() );
		return( *this );
	}

	CFIntURLProtocolByIsSecureIdxKey CFIntURLProtocolByIsSecureIdxKey::operator =( cfint::CFIntURLProtocolHBuff& src ) {
		setRequiredIsSecure( src.getRequiredIsSecure() );
		return( *this );
	}

}

namespace std {

	bool operator <(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolByIsSecureIdxKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}
}

