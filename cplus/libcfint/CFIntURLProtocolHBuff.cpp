// Description: C++18 implementation of a URLProtocol history buffer object.

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

#include <cfint/CFIntHPKey.hpp>
#include <cfint/CFIntURLProtocolPKey.hpp>
#include <cfint/CFIntURLProtocolBuff.hpp>
#include <cfint/CFIntURLProtocolHPKey.hpp>
#include <cfint/CFIntURLProtocolHBuff.hpp>
#include <cfint/CFIntURLProtocolByUNameIdxKey.hpp>
#include <cfint/CFIntURLProtocolByIsSecureIdxKey.hpp>

namespace cfint {

	const std::string CFIntURLProtocolHBuff::CLASS_NAME( "CFIntURLProtocolHBuff" );
	CFIntURLProtocolHBuff::CFIntURLProtocolHBuff()
	: CFIntHPKey(), cflib::ICFLibCloneableObj() {
		requiredURLProtocolId = cfint::CFIntURLProtocolBuff::URLPROTOCOLID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntURLProtocolBuff::NAME_INIT_VALUE );
		requiredDescription = new std::string( cfint::CFIntURLProtocolBuff::DESCRIPTION_INIT_VALUE );
		requiredIsSecure = cfint::CFIntURLProtocolBuff::ISSECURE_INIT_VALUE;
	}

	CFIntURLProtocolHBuff::CFIntURLProtocolHBuff( const CFIntURLProtocolHBuff& src )
	: CFIntHPKey(), cflib::ICFLibCloneableObj() {
		requiredURLProtocolId = cfint::CFIntURLProtocolBuff::URLPROTOCOLID_INIT_VALUE;
		requiredName = new std::string( cfint::CFIntURLProtocolBuff::NAME_INIT_VALUE );
		requiredDescription = new std::string( cfint::CFIntURLProtocolBuff::DESCRIPTION_INIT_VALUE );
		requiredIsSecure = cfint::CFIntURLProtocolBuff::ISSECURE_INIT_VALUE;
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredIsSecure( src.getRequiredIsSecure() );
	}

	CFIntURLProtocolHBuff::~CFIntURLProtocolHBuff() {
		if( requiredName != NULL ) {
			delete requiredName;
			requiredName = NULL;
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
	}

	cflib::ICFLibCloneableObj* CFIntURLProtocolHBuff::clone() {
		CFIntURLProtocolHBuff* copy = new CFIntURLProtocolHBuff();
		*copy = *this;
		cflib::ICFLibCloneableObj* retval = dynamic_cast<cflib::ICFLibCloneableObj*>( copy );
		return( retval );
	}

	const int32_t CFIntURLProtocolHBuff::getRequiredURLProtocolId() const {
		return( requiredURLProtocolId );
	}

	const int32_t* CFIntURLProtocolHBuff::getRequiredURLProtocolIdReference() const {
		return( &requiredURLProtocolId );
	}

	void CFIntURLProtocolHBuff::setRequiredURLProtocolId( const int32_t value ) {
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

	const std::string& CFIntURLProtocolHBuff::getRequiredName() const {
		return( *requiredName );
	}

	const std::string* CFIntURLProtocolHBuff::getRequiredNameReference() const {
		return( requiredName );
	}

	void CFIntURLProtocolHBuff::setRequiredName( const std::string& value ) {
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

	const std::string& CFIntURLProtocolHBuff::getRequiredDescription() const {
		return( *requiredDescription );
	}

	const std::string* CFIntURLProtocolHBuff::getRequiredDescriptionReference() const {
		return( requiredDescription );
	}

	void CFIntURLProtocolHBuff::setRequiredDescription( const std::string& value ) {
		static const std::string S_ProcName( "setRequiredDescription" );
		if( value.length() > CFIntURLProtocolBuff::DESCRIPTION_MAX_LEN ) {
			throw cflib::CFLibArgumentOverflowException( CLASS_NAME,
				S_ProcName,
				1,
				S_VALUE_LENGTH,
				value.length(),
				CFIntURLProtocolBuff::DESCRIPTION_MAX_LEN );
		}
		if( requiredDescription != NULL ) {
			delete requiredDescription;
			requiredDescription = NULL;
		}
		requiredDescription = new std::string( value );
	}

	const bool CFIntURLProtocolHBuff::getRequiredIsSecure() const {
		return( requiredIsSecure );
	}

	const bool* CFIntURLProtocolHBuff::getRequiredIsSecureReference() const {
		return( &requiredIsSecure );
	}

	void CFIntURLProtocolHBuff::setRequiredIsSecure( const bool value ) {
		requiredIsSecure = value;
	}

	size_t CFIntURLProtocolHBuff::hashCode() const {
		size_t hashCode = CFIntHPKey::hashCode();
		hashCode = hashCode + getRequiredURLProtocolId();
		hashCode = hashCode + cflib::CFLib::hash( getRequiredName() );
		hashCode = hashCode + cflib::CFLib::hash( getRequiredDescription() );
		if( getRequiredIsSecure() ) {
			hashCode = ( hashCode * 2 ) + 1;
		}
		else {
			hashCode = hashCode * 2;
		}
		return( hashCode );
	}

	CFIntURLProtocolHBuff CFIntURLProtocolHBuff::operator =( cfint::CFIntURLProtocolBuff& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredIsSecure( src.getRequiredIsSecure() );
		return( *this );
	}

	CFIntURLProtocolHBuff CFIntURLProtocolHBuff::operator =( cfint::CFIntURLProtocolHBuff& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		setRequiredRevision( src.getRequiredRevision() );
		setRequiredName( src.getRequiredName() );
		setRequiredDescription( src.getRequiredDescription() );
		setRequiredIsSecure( src.getRequiredIsSecure() );
		return( *this );
	}

	bool CFIntURLProtocolHBuff::operator <( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator <( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator <( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator <( const CFIntURLProtocolHPKey& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() >= rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() <= rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() >= rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() <= rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator <( const CFIntURLProtocolHBuff& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() >= rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() <= rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() >= rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() <= rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator <( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator <=( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator <=( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator <=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator <=( const CFIntURLProtocolHPKey& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator <=( const CFIntURLProtocolHBuff& rhs ) {
		if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator <=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator ==( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator ==( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator ==( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator ==( const CFIntURLProtocolHPKey& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator ==( const CFIntURLProtocolHBuff& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator ==( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator !=( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator !=( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator !=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator !=( const CFIntURLProtocolHPKey& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator !=( const CFIntURLProtocolHBuff& rhs ) {
		if( getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator !=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator >=( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator >=( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator >=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator >=( const CFIntURLProtocolHPKey& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator >=( const CFIntURLProtocolHBuff& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator >=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHBuff::operator >( const CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator >( const CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator >( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator >( const CFIntURLProtocolHPKey& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator >( const CFIntURLProtocolHBuff& rhs ) {
		if( getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHBuff::operator >( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	std::string CFIntURLProtocolHBuff::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntURLProtocolHBuff" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_URLProtocolId( "URLProtocolId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		static const std::string S_IsSecure( "IsSecure" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_URLProtocolId, getRequiredURLProtocolId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, getRequiredName() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, getRequiredDescription() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredBoolean( &S_Space, S_IsSecure, getRequiredIsSecure() ) );
		ret.append( S_Postamble );
		return( ret );
	}
}

namespace std {

	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( false );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( false );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( false );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( false );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( false );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( false );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( false );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( false );
		}
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getAuditClusterId() != rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() != rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() != rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() != rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) != 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( true );
			}
		}
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() != rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() != rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() != rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByUNameIdxKey& rhs ) {
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolByIsSecureIdxKey& rhs ) {
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
		if( lhs.getAuditClusterId() < rhs.getAuditClusterId() ) {
			return( false );
		}
		else if( lhs.getAuditClusterId() > rhs.getAuditClusterId() ) {
			return( true );
		}
		if( lhs.getAuditStamp() < rhs.getAuditStamp() ) {
			return( false );
		}
		else if( lhs.getAuditStamp() > rhs.getAuditStamp() ) {
			return( true );
		}
		if( lhs.getAuditActionId() < rhs.getAuditActionId() ) {
			return( false );
		}
		else if( lhs.getAuditActionId() > rhs.getAuditActionId() ) {
			return( true );
		}
		if( lhs.getRequiredRevision() < rhs.getRequiredRevision() ) {
			return( false );
		}
		else if( lhs.getRequiredRevision() > rhs.getRequiredRevision() ) {
			return( true );
		}
		if( lhs.getAuditSessionId() != NULL ) {
			if( rhs.getAuditSessionId() == NULL ) {
				return( true );
			}
			const uuid_ptr_t lhuuid = lhs.getAuditSessionId();
			const uuid_ptr_t rhuuid = rhs.getAuditSessionId();
			if( uuid_compare( lhuuid, rhuuid ) < 0 ) {
				return( false );
			}
			else if( uuid_compare( lhuuid, rhuuid ) > 0 ) {
				return( true );
			}
		}
		else {
			if( rhs.getAuditSessionId() != NULL ) {
				return( false );
			}
		}
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolHBuff& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		if( lhs.getRequiredName() < rhs.getRequiredName() ) {
			return( false );
		}
		else if( lhs.getRequiredName() > rhs.getRequiredName() ) {
			return( true );
		}
		if( lhs.getRequiredDescription() < rhs.getRequiredDescription() ) {
			return( false );
		}
		else if( lhs.getRequiredDescription() > rhs.getRequiredDescription() ) {
			return( true );
		}
		if( lhs.getRequiredIsSecure() < rhs.getRequiredIsSecure() ) {
			return( false );
		}
		else if( lhs.getRequiredIsSecure() > rhs.getRequiredIsSecure() ) {
			return( true );
		}
		return( false );
	}
}

