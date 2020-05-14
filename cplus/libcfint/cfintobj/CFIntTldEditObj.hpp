#pragma once

// Description: C++18 edit object instance specification for CFInt Tld.

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
#include <cfintobj/ICFIntObjPublic.hpp>

namespace cfint {

	class CFIntTldEditObj
	: public virtual ICFIntTldEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfint::ICFIntTldObj* orig;
		cfint::CFIntTldBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFIntTldEditObj( cfint::ICFIntTldObj* argOrig );
		virtual ~CFIntTldEditObj();

		virtual const std::string& getClassName() const;

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );
		virtual cfsec::ICFSecSecUserObj* getCreatedBy();
		virtual const std::chrono::system_clock::time_point& getCreatedAt();
		virtual cfsec::ICFSecSecUserObj* getUpdatedBy();
		virtual const std::chrono::system_clock::time_point& getUpdatedAt();

		virtual void setCreatedBy( cfsec::ICFSecSecUserObj* value );
		virtual void setCreatedAt( const std::chrono::system_clock::time_point& value );
		virtual void setUpdatedBy( cfsec::ICFSecSecUserObj* value );
		virtual void setUpdatedAt( const std::chrono::system_clock::time_point& value );

		virtual const classcode_t getClassCode() const;
		virtual bool implementsClassCode( const classcode_t value ) const;
		virtual std::string toString();

		virtual std::string getObjName();

		virtual const std::string getGenDefName();

		virtual cflib::ICFLibAnyObj* getScope();
		virtual cflib::ICFLibAnyObj* getObjScope();

		virtual cflib::ICFLibAnyObj* getObjQualifier( const classcode_t* qualifyingClass );

		virtual cflib::ICFLibAnyObj* getNamedObject( const classcode_t* qualifyingClass, const std::string& objName );

		virtual cflib::ICFLibAnyObj* getNamedObject( const std::string& objName );

		virtual std::string getObjQualifiedName();

		virtual std::string getObjFullName();

		virtual ICFIntTldObj* realize();

		virtual cfint::ICFIntTldObj* read( bool forceRead = false );

		virtual ICFIntTldObj* create();

		virtual ICFIntTldEditObj* update();

		virtual ICFIntTldEditObj* deleteInstance();

		virtual cfint::ICFIntTldTableObj* getTldTable();

		virtual cfint::ICFIntTldEditObj* getEdit();

		virtual cfint::ICFIntTldEditObj* getTldEdit();

		virtual ICFIntTldEditObj* beginEdit();

		virtual void endEdit();

		virtual cfint::ICFIntTldObj* getOrig();

		virtual cfint::ICFIntTldObj* getOrigAsTld();

		virtual cfint::ICFIntSchemaObj* getSchema();

		virtual cfint::CFIntTldBuff* getBuff();
		virtual void setBuff( cfint::CFIntTldBuff* value );

		inline cfint::CFIntTldBuff* getTldBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfint::CFIntTldBuff*>( buff ) );
		};

		inline cfint::CFIntTldBuff* getTldEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfint::CFIntTldBuff*>( buff ) );
		};

		virtual cfint::CFIntTldPKey* getPKey();
		virtual void setPKey( cfint::CFIntTldPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int64_t getRequiredTenantId();
		virtual const int64_t* getRequiredTenantIdReference();

		virtual const int64_t getRequiredId();
		virtual const int64_t* getRequiredIdReference();

		virtual const std::string& getRequiredName();
		virtual const std::string* getRequiredNameReference();
		virtual void setRequiredName( const std::string& value );

		virtual bool isOptionalDescriptionNull();
		virtual const std::string& getOptionalDescriptionValue();
		virtual const std::string* getOptionalDescriptionReference();
		virtual void setOptionalDescriptionNull();
		virtual void setOptionalDescriptionValue( const std::string& value );

		virtual cfsec::ICFSecTenantObj* getRequiredContainerTenant( bool forceRead = false );
		virtual void setRequiredContainerTenant( cfsec::ICFSecTenantObj* value );

		virtual std::vector<cfint::ICFIntTopDomainObj*> getOptionalComponentsTopDomain( bool forceRead = false );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}