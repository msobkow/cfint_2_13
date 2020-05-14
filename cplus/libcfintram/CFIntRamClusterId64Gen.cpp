// Description: C++18 Implementation of a Cluster 64-bit in-memory RAM Id Generator object.

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
#include <cfint/ICFIntPublic.hpp>
#include <cfintram/CFIntRamClusterId64Gen.hpp>

using namespace std;

namespace cfint {

	const std::string CFIntRamClusterId64Gen::CLASS_NAME( "CFIntRamClusterId64Gen" );
	const std::string CFIntRamClusterId64Gen::S_VALUE( "value" );

	CFIntRamClusterId64Gen::CFIntRamClusterId64Gen() {
		requiredId = cfsec::CFSecClusterBuff::ID_INIT_VALUE;
		sliceId = 0;
		nextId = 1L;
	}

	CFIntRamClusterId64Gen::~CFIntRamClusterId64Gen() {
	}

	int64_t CFIntRamClusterId64Gen::getNextId() {
		int64_t retNext = nextId ++;
		return( retNext );
	}

	const int64_t CFIntRamClusterId64Gen::getRequiredId() const {
		return( requiredId );
	}

	const int64_t* CFIntRamClusterId64Gen::getRequiredIdReference() const {
		return( &requiredId );
	}

	void CFIntRamClusterId64Gen::setRequiredId( const int64_t value ) {
		static const std::string S_ProcName( "setRequiredId" );
		if( value < cfsec::CFSecClusterBuff::ID_MIN_VALUE ) {
			throw cflib::CFLibArgumentUnderflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE,
				value,
				cfsec::CFSecClusterBuff::ID_MIN_VALUE );
		}
		requiredId = value;
	}

	int16_t CFIntRamClusterId64Gen::getRequiredSliceId() const {
		return( sliceId );
	}

	void CFIntRamClusterId64Gen::setRequiredSliceId( int16_t value ) {
		sliceId = value;
	}

	size_t CFIntRamClusterId64Gen::hashCode() const {
		size_t hashCode = 0;
		hashCode = hashCode + (int)( getRequiredId() );
		return( hashCode );
	}

	bool CFIntRamClusterId64Gen::operator <( const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntRamClusterId64Gen::operator <=( const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntRamClusterId64Gen::operator ==( const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntRamClusterId64Gen::operator !=( const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntRamClusterId64Gen::operator >=( const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntRamClusterId64Gen::operator >( const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	CFIntRamClusterId64Gen CFIntRamClusterId64Gen::operator =( CFIntRamClusterId64Gen& src ) {
		setRequiredId( src.getRequiredId() );
		// Don't bother copying the id generation value; only the map keys make copies of id generators, so they never use them
		return( *this );
	}

}

namespace std {

	bool operator <(const cfint::CFIntRamClusterId64Gen& lhs, const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const cfint::CFIntRamClusterId64Gen& lhs, const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const cfint::CFIntRamClusterId64Gen& lhs, const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const cfint::CFIntRamClusterId64Gen& lhs, const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( lhs.getRequiredId() != rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const cfint::CFIntRamClusterId64Gen& lhs, const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const cfint::CFIntRamClusterId64Gen& lhs, const cfint::CFIntRamClusterId64Gen& rhs ) {
		if( lhs.getRequiredId() < rhs.getRequiredId() ) {
			return( false );
		}
		else if( lhs.getRequiredId() > rhs.getRequiredId() ) {
			return( true );
		}
		return( false );
	}


}
