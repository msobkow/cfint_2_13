// Description: C++18 implementation of a URLProtocol history primary key object.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>

using namespace std;

#include <cfint/CFIntHPKey.hpp>
#include <cfint/CFIntURLProtocolPKey.hpp>
#include <cfint/CFIntURLProtocolHPKey.hpp>
#include <cfint/CFIntURLProtocolBuff.hpp>
#include <cfint/CFIntURLProtocolHBuff.hpp>

namespace cfint {

	const std::string CFIntURLProtocolHPKey::CLASS_NAME( "CFIntURLProtocolHPKey" );
	const std::string CFIntURLProtocolHPKey::S_VALUE( "value" );

	CFIntURLProtocolHPKey::CFIntURLProtocolHPKey()
	: CFIntHPKey()
	{
		requiredURLProtocolId = cfint::CFIntURLProtocolBuff::URLPROTOCOLID_INIT_VALUE;
	}

	CFIntURLProtocolHPKey::CFIntURLProtocolHPKey( const CFIntURLProtocolHPKey& src )
	: CFIntHPKey()
	{
		requiredURLProtocolId = cfint::CFIntURLProtocolBuff::URLPROTOCOLID_INIT_VALUE;
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
	}

	CFIntURLProtocolHPKey::~CFIntURLProtocolHPKey() {
	}

	const int32_t CFIntURLProtocolHPKey::getRequiredURLProtocolId() const {
		return( requiredURLProtocolId );
	}

	const int32_t* CFIntURLProtocolHPKey::getRequiredURLProtocolIdReference() const {
		return( &requiredURLProtocolId );
	}

	void CFIntURLProtocolHPKey::setRequiredURLProtocolId( const int32_t value ) {
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

	size_t CFIntURLProtocolHPKey::hashCode() const {
		size_t hashCode = CFIntHPKey::hashCode();
		hashCode = hashCode + getRequiredURLProtocolId();
		return( hashCode );
	}

	std::string CFIntURLProtocolHPKey::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntHPKey" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_AuditClusterId( "AuditClusterId" );
		static const std::string S_AuditStamp( "AuditStamp" );
		static const std::string S_AuditActionId( "AuditActionId" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_AuditSessionId( "AuditSessionId" );
		static const std::string S_URLProtocolId( "URLProtocolId" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_AuditClusterId, auditClusterId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredTZTimestamp( &S_Space, S_AuditClusterId, auditStamp ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt16( &S_Space, S_AuditActionId, auditActionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, requiredRevision ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredUuid( &S_Space, S_AuditSessionId, auditSessionId ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_URLProtocolId, getRequiredURLProtocolId() ) );
		ret.append( S_Postamble );
		return( ret );
	}

	bool CFIntURLProtocolHPKey::operator <( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHPKey::operator <( const CFIntURLProtocolHPKey& rhs ) {
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

	bool CFIntURLProtocolHPKey::operator <( const CFIntURLProtocolHBuff& rhs ) {
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

	bool CFIntURLProtocolHPKey::operator <( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHPKey::operator <=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHPKey::operator <=( const CFIntURLProtocolHPKey& rhs ) {
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

	bool CFIntURLProtocolHPKey::operator <=( const CFIntURLProtocolHBuff& rhs ) {
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

	bool CFIntURLProtocolHPKey::operator <=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHPKey::operator ==( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHPKey::operator ==( const CFIntURLProtocolHPKey& rhs ) {
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
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHPKey::operator ==( const CFIntURLProtocolHBuff& rhs ) {
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
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHPKey::operator ==( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHPKey::operator !=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHPKey::operator !=( const CFIntURLProtocolHPKey& rhs ) {
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

	bool CFIntURLProtocolHPKey::operator !=( const CFIntURLProtocolHBuff& rhs ) {
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

	bool CFIntURLProtocolHPKey::operator !=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHPKey::operator >=( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHPKey::operator >=( const CFIntURLProtocolHPKey& rhs ) {
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

	bool CFIntURLProtocolHPKey::operator >=( const CFIntURLProtocolHBuff& rhs ) {
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

	bool CFIntURLProtocolHPKey::operator >=( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool CFIntURLProtocolHPKey::operator >( const CFIntURLProtocolPKey& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool CFIntURLProtocolHPKey::operator >( const CFIntURLProtocolHPKey& rhs ) {
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

	bool CFIntURLProtocolHPKey::operator >( const CFIntURLProtocolHBuff& rhs ) {
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

	bool CFIntURLProtocolHPKey::operator >( const CFIntURLProtocolBuff& rhs ) {
		if( getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	CFIntURLProtocolHPKey CFIntURLProtocolHPKey::operator =( cfint::CFIntURLProtocolPKey& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		return( *this );
	}

	CFIntURLProtocolHPKey CFIntURLProtocolHPKey::operator =( cfint::CFIntURLProtocolHPKey& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		return( *this );
	}

	CFIntURLProtocolHPKey CFIntURLProtocolHPKey::operator =( cfint::CFIntURLProtocolBuff& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		return( *this );
	}

	CFIntURLProtocolHPKey CFIntURLProtocolHPKey::operator =( cfint::CFIntURLProtocolHBuff& src ) {
		setRequiredURLProtocolId( src.getRequiredURLProtocolId() );
		return( *this );
	}
}

namespace std {

	bool operator <(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
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

	bool operator <(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
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

	bool operator <(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator <=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator <=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
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

	bool operator <=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
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

	bool operator <=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool operator ==(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
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

	bool operator ==(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
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

	bool operator ==(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		return( true );
	}

	bool operator !=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator !=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
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

	bool operator !=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
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

	bool operator !=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() != rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
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

	bool operator >=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
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

	bool operator >=(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( true );
	}

	bool operator >(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolPKey& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}

	bool operator >(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHPKey& rhs ) {
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

	bool operator >(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolHBuff& rhs ) {
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

	bool operator >(const  cfint::CFIntURLProtocolHPKey& lhs, const cfint::CFIntURLProtocolBuff& rhs ) {
		if( lhs.getRequiredURLProtocolId() < rhs.getRequiredURLProtocolId() ) {
			return( false );
		}
		else if( lhs.getRequiredURLProtocolId() > rhs.getRequiredURLProtocolId() ) {
			return( true );
		}
		return( false );
	}
}

