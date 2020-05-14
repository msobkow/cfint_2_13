#pragma once

// Description: C++18 specification of a TopProject history primary key object.

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

#include <cfint/CFIntHPKey.hpp>
#include <cfint/ICFIntSchema.hpp>

namespace cfint {

	class CFIntTopProjectPKey;
	class CFIntTopProjectBuff;
	class CFIntTopProjectHBuff;

	class CFIntTopProjectHPKey : public CFIntHPKey
	{
	protected:

		int64_t requiredTenantId;
		int64_t requiredId;
	public:
		static const std::string CLASS_NAME;
		static const std::string S_VALUE;

		CFIntTopProjectHPKey();
		CFIntTopProjectHPKey( const CFIntTopProjectHPKey& src );
		virtual ~CFIntTopProjectHPKey();

		virtual const int64_t getRequiredTenantId() const;
		virtual const int64_t* getRequiredTenantIdReference() const;
		virtual void setRequiredTenantId( const int64_t value );

		virtual const int64_t getRequiredId() const;
		virtual const int64_t* getRequiredIdReference() const;
		virtual void setRequiredId( const int64_t value );

		virtual size_t hashCode() const;

		virtual std::string toString();

		bool operator <( const CFIntTopProjectPKey& rhs );
		bool operator <( const CFIntTopProjectHPKey& rhs );
		bool operator <( const CFIntTopProjectHBuff& rhs );
		bool operator <( const CFIntTopProjectBuff& rhs );


		bool operator <=( const CFIntTopProjectPKey& rhs );
		bool operator <=( const CFIntTopProjectHPKey& rhs );
		bool operator <=( const CFIntTopProjectHBuff& rhs );
		bool operator <=( const CFIntTopProjectBuff& rhs );


		bool operator ==( const CFIntTopProjectPKey& rhs );
		bool operator ==( const CFIntTopProjectHPKey& rhs );
		bool operator ==( const CFIntTopProjectHBuff& rhs );
		bool operator ==( const CFIntTopProjectBuff& rhs );


		bool operator !=( const CFIntTopProjectPKey& rhs );
		bool operator !=( const CFIntTopProjectHPKey& rhs );
		bool operator !=( const CFIntTopProjectHBuff& rhs );
		bool operator !=( const CFIntTopProjectBuff& rhs );


		bool operator >=( const CFIntTopProjectPKey& rhs );
		bool operator >=( const CFIntTopProjectHPKey& rhs );
		bool operator >=( const CFIntTopProjectHBuff& rhs );
		bool operator >=( const CFIntTopProjectBuff& rhs );


		bool operator >( const CFIntTopProjectPKey& rhs );
		bool operator >( const CFIntTopProjectHPKey& rhs );
		bool operator >( const CFIntTopProjectHBuff& rhs );
		bool operator >( const CFIntTopProjectBuff& rhs );

		cfint::CFIntTopProjectHPKey operator =( cfint::CFIntTopProjectPKey& src );
		cfint::CFIntTopProjectHPKey operator =( cfint::CFIntTopProjectHPKey& src );
		cfint::CFIntTopProjectHPKey operator =( cfint::CFIntTopProjectBuff& src );
		cfint::CFIntTopProjectHPKey operator =( cfint::CFIntTopProjectHBuff& src );

	};
}


namespace std {

	bool operator <(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator <(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator <(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator <(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectBuff& rhs );


	bool operator <=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator <=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator <=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator <=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectBuff& rhs );


	bool operator ==(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator ==(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator ==(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator ==(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectBuff& rhs );


	bool operator !=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator !=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator !=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator !=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectBuff& rhs );


	bool operator >=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator >=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator >=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator >=(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectBuff& rhs );


	bool operator >(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectPKey& rhs );
	bool operator >(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHPKey& rhs );
	bool operator >(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectHBuff& rhs );
	bool operator >(const  cfint::CFIntTopProjectHPKey& lhs, const cfint::CFIntTopProjectBuff& rhs );


	template<> struct hash<cfint::CFIntTopProjectHPKey> {
		typedef cfint::CFIntTopProjectHPKey argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const {
			return( s.hashCode() );
		}
	};

}

