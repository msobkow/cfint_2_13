#pragma once

// Description: C++18 edit object instance specification for CFInt License.

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

	class CFIntLicenseEditObj
	: public virtual ICFIntLicenseEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfint::ICFIntLicenseObj* orig;
		cfint::CFIntLicenseBuff* buff;
	public:
		CFIntLicenseEditObj( cfint::ICFIntLicenseObj* argOrig );
		virtual ~CFIntLicenseEditObj();

		virtual const std::string& getClassName() const;

		virtual int32_t getRequiredRevision() const;
		virtual void setRequiredRevision( int32_t value );
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

		virtual ICFIntLicenseObj* realize();

		virtual cfint::ICFIntLicenseObj* read( bool forceRead = false );

		virtual ICFIntLicenseObj* create();

		virtual ICFIntLicenseEditObj* update();

		virtual ICFIntLicenseEditObj* deleteInstance();

		virtual cfint::ICFIntLicenseTableObj* getLicenseTable();

		virtual cfint::ICFIntLicenseEditObj* getEdit();

		virtual cfint::ICFIntLicenseEditObj* getLicenseEdit();

		virtual ICFIntLicenseEditObj* beginEdit();

		virtual void endEdit();

		virtual cfint::ICFIntLicenseObj* getOrig();

		virtual cfint::ICFIntLicenseObj* getOrigAsLicense();

		virtual cfint::ICFIntSchemaObj* getSchema();

		virtual cfint::CFIntLicenseBuff* getBuff();
		virtual void setBuff( cfint::CFIntLicenseBuff* value );

		inline cfint::CFIntLicenseBuff* getLicenseBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfint::CFIntLicenseBuff*>( buff ) );
		};

		inline cfint::CFIntLicenseBuff* getLicenseEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfint::CFIntLicenseBuff*>( buff ) );
		};

		virtual cfint::CFIntLicensePKey* getPKey();
		virtual void setPKey( cfint::CFIntLicensePKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int64_t getRequiredTenantId();
		virtual const int64_t* getRequiredTenantIdReference();

		virtual const int64_t getRequiredId();
		virtual const int64_t* getRequiredIdReference();

		virtual const int64_t getRequiredTopDomainId();
		virtual const int64_t* getRequiredTopDomainIdReference();

		virtual const std::string& getRequiredName();
		virtual const std::string* getRequiredNameReference();
		virtual void setRequiredName( const std::string& value );

		virtual bool isOptionalDescriptionNull();
		virtual const std::string& getOptionalDescriptionValue();
		virtual const std::string* getOptionalDescriptionReference();
		virtual void setOptionalDescriptionNull();
		virtual void setOptionalDescriptionValue( const std::string& value );

		virtual bool isOptionalEmbeddedTextNull();
		virtual const std::string& getOptionalEmbeddedTextValue();
		virtual const std::string* getOptionalEmbeddedTextReference();
		virtual void setOptionalEmbeddedTextNull();
		virtual void setOptionalEmbeddedTextValue( const std::string& value );

		virtual bool isOptionalFullTextNull();
		virtual const std::string& getOptionalFullTextValue();
		virtual const std::string* getOptionalFullTextReference();
		virtual void setOptionalFullTextNull();
		virtual void setOptionalFullTextValue( const std::string& value );

		virtual cfsec::ICFSecTenantObj* getRequiredOwnerTenant( bool forceRead = false );
		virtual void setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value );

		virtual cfint::ICFIntTopDomainObj* getRequiredContainerTopDomain( bool forceRead = false );
		virtual void setRequiredContainerTopDomain( cfint::ICFIntTopDomainObj* value );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
