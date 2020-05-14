// Description: C++18 implementation of a MimeType history primary key object.

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
#include <cfint/CFIntMimeTypePKey.hpp>
#include <cfint/CFIntMimeTypeHPKey.hpp>
#include <cfint/CFIntMimeTypeBuff.hpp>
#include <cfint/CFIntMimeTypeHBuff.hpp>

namespace cfint {

	const std::string CFIntMimeTypeHPKey::CLASS_NAME( "CFIntMimeTypeHPKey" );
	const std::string CFIntMimeTypeHPKey::S_VALUE( "value" );

	CFIntMimeTypeHPKey::CFIntMimeTypeHPKey()
	: CFIntHPKey()
	{
		requiredMimeTypeId = cfint::CFIntMimeTypeBuff::MIMETYPEID_INIT_VALUE;
	}

	CFIntMimeTypeHPKey::CFIntMimeTypeHPKey( const CFIntMimeTypeHPKey& src )
	: CFIntHPKey()
	{
		requiredMimeTypeId = cfint::CFIntMimeTypeBuff::MIMETYPEID_INIT_VALUE;
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
	}

	CFIntMimeTypeHPKey::~CFIntMimeTypeHPKey() {
	}

	const int32_t CFIntMimeTypeHPKey::getRequiredMimeTypeId() const {
		return( requiredMimeTypeId );
	}

	const int32_t* CFIntMimeTypeHPKey::getRequiredMimeTypeIdReference() const {
		return( &requiredMimeTypeId );
	}

	void CFIntMimeTypeHPKey::setRequiredMimeTypeId( const int32_t value ) {
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

	size_t CFIntMimeTypeHPKey::hashCode() const {
		size_t hashCode = CFIntHPKey::hashCode();
		hashCode = hashCode + getRequiredMimeTypeId();
		return( hashCode );
	}

	std::string CFIntMimeTypeHPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntHPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_MimeTypeId( "MimeTypeId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, requiredRevision ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_MimeTypeId, getRequiredMimeTypeId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntMimeTypeHPKey::operator <( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHPKey::operator <( const CFIntMimeTypeHPKey& rhs ) {
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
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHPKey::operator <( const CFIntMimeTypeHBuff& rhs ) {
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
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHPKey::operator <( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHPKey::operator <=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator <=( const CFIntMimeTypeHPKey& rhs ) {
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
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator <=( const CFIntMimeTypeHBuff& rhs ) {
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
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator <=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator ==( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator ==( const CFIntMimeTypeHPKey& rhs ) {
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
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator ==( const CFIntMimeTypeHBuff& rhs ) {
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
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator ==( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator !=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHPKey::operator !=( const CFIntMimeTypeHPKey& rhs ) {
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
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHPKey::operator !=( const CFIntMimeTypeHBuff& rhs ) {
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
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHPKey::operator !=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHPKey::operator >=( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator >=( const CFIntMimeTypeHPKey& rhs ) {
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
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator >=( const CFIntMimeTypeHBuff& rhs ) {
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
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator >=( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntMimeTypeHPKey::operator >( const CFIntMimeTypePKey& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHPKey::operator >( const CFIntMimeTypeHPKey& rhs ) {
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
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHPKey::operator >( const CFIntMimeTypeHBuff& rhs ) {
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
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntMimeTypeHPKey::operator >( const CFIntMimeTypeBuff& rhs ) {
		if( getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	CFIntMimeTypeHPKey CFIntMimeTypeHPKey::operator =( cfint::CFIntMimeTypePKey& src ) {
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		return( *this );
	}

	CFIntMimeTypeHPKey CFIntMimeTypeHPKey::operator =( cfint::CFIntMimeTypeHPKey& src ) {
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		return( *this );
	}

	CFIntMimeTypeHPKey CFIntMimeTypeHPKey::operator =( cfint::CFIntMimeTypeBuff& src ) {
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		return( *this );
	}

	CFIntMimeTypeHPKey CFIntMimeTypeHPKey::operator =( cfint::CFIntMimeTypeHBuff& src ) {
		setRequiredMimeTypeId( src.getRequiredMimeTypeId() );
		return( *this );
	}
}

namespace std {

	bool operator <(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() != rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypePKey& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHPKey& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeHBuff& rhs ) {
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
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntMimeTypeHPKey& lhs, const cfint::CFIntMimeTypeBuff& rhs ) {
		if( lhs.getRequiredMimeTypeId() < rhs.getRequiredMimeTypeId() ) {
			return( false );
		}
		else if( lhs.getRequiredMimeTypeId() > rhs.getRequiredMimeTypeId() ) {
			return( true );
		}
		return( false );
	}
}

