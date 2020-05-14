// Description: C++18 implementation of a URLProtocol primary key object.

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

#include <cfint/CFIntURLProtocolPKey.hpp>
#include <cfint/CFIntURLProtocolBuff.hpp>
#include <cfint/CFIntURLProtocolHPKey.hpp>
#include <cfint/CFIntURLProtocolHBuff.hpp>

namespace cfint {

	const std::string CFIntURLProtocolPKey::CLASS_NAME( "CFIntURLProtocolPKey" );
	const std::string CFIntURLProtocolPKey::S_VALUE( "value" );
	const std::string CFIntURLProtocolPKey::S_VALUE_LENGTH( "value.length()" );

	CFIntURLProtocolPKey::CFIntURLProtocolPKey() {
		requiredURLProtocolId = cfint::CFIntURLProtocolBuff::URLPROTOCOLID_INIT_VALUE;
	}

	CFIntURLProtocolPKey::CFIntURLProtocolPKey( const CFIntURLProtocolPKey& src ) {
		requiredURLProtocolId = cfint::CFIntURLProtocolBuff::URLPROTOCOLID_INIT_VALUE;
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
	}

	CFIntURLProtocolPKey::~CFIntURLProtocolPKey() {
	}

	const int32_t CFIntURLProtocolPKey::getRequiredURLProtocolId() const {
		return( requiredURLProtocolId );
	}

	const int32_t* CFIntURLProtocolPKey::getRequiredURLProtocolIdReference() const {
		return( &requiredURLProtocolId );
	}

	void CFIntURLProtocolPKey::setRequiredURLProtocolId( const int32_t value ) {
		static const std::string S_ProcName( "setRequiredURLProtocolId" );
		if( value < cfint::CFIntURLProtocolBuff::URLPROTOCOLID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfint::CFIntURLProtocolBuff::URLPROTOCOLID_MIN_VALUE );
		}
		requiredURLProtocolId = value;
	}

	bool CFIntURLProtocolPKey::operator <( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolPKey::operator <( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolPKey::operator <( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolPKey::operator <( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolPKey::operator <=( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator <=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator <=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator <=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator ==( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator ==( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator ==( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator ==( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator !=( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolPKey::operator !=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolPKey::operator !=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolPKey::operator !=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolPKey::operator >=( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator >=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator >=( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator >=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolPKey::operator >( const CFIntURLProtocolHPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolPKey::operator >( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolPKey::operator >( const CFIntURLProtocolHBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolPKey::operator >( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	CFIntURLProtocolPKey CFIntURLProtocolPKey::operator =( cfint::CFIntURLProtocolPKey& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		return( *this );
	}

	CFIntURLProtocolPKey CFIntURLProtocolPKey::operator =( cfint::CFIntURLProtocolHPKey& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		return( *this );
	}

	CFIntURLProtocolPKey CFIntURLProtocolPKey::operator =( cfint::CFIntURLProtocolBuff& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		return( *this );
	}

	CFIntURLProtocolPKey CFIntURLProtocolPKey::operator =( cfint::CFIntURLProtocolHBuff& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		return( *this );
	}

	size_t CFIntURLProtocolPKey::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + getRequiredURLProtocolId();
		return( hashCode );
	}

	std::string CFIntURLProtocolPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntURLProtocolPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_URLProtocolId( "URLProtocolId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_URLProtocolId, getRequiredURLProtocolId() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}
}

