#pragma once

// Description: C++18 edit object instance specification for CFInt MajorVersion.

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

	class CFIntMajorVersionEditObj
	: public virtual ICFIntMajorVersionEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfint::ICFIntMajorVersionObj* orig;
		cfint::CFIntMajorVersionBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFIntMajorVersionEditObj( cfint::ICFIntMajorVersionObj* argOrig );
		virtual ~CFIntMajorVersionEditObj();

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

		virtual ICFIntMajorVersionObj* realize();

		virtual cfint::ICFIntMajorVersionObj* read( bool forceRead = false );

		virtual ICFIntMajorVersionObj* create();

		virtual ICFIntMajorVersionEditObj* update();

		virtual ICFIntMajorVersionEditObj* deleteInstance();

		virtual cfint::ICFIntMajorVersionTableObj* getMajorVersionTable();

		virtual cfint::ICFIntMajorVersionEditObj* getEdit();

		virtual cfint::ICFIntMajorVersionEditObj* getMajorVersionEdit();

		virtual ICFIntMajorVersionEditObj* beginEdit();

		virtual void endEdit();

		virtual cfint::ICFIntMajorVersionObj* getOrig();

		virtual cfint::ICFIntMajorVersionObj* getOrigAsMajorVersion();

		virtual cfint::ICFIntSchemaObj* getSchema();

		virtual cfint::CFIntMajorVersionBuff* getBuff();
		virtual void setBuff( cfint::CFIntMajorVersionBuff* value );

		inline cfint::CFIntMajorVersionBuff* getMajorVersionBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfint::CFIntMajorVersionBuff*>( buff ) );
		};

		inline cfint::CFIntMajorVersionBuff* getMajorVersionEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfint::CFIntMajorVersionBuff*>( buff ) );
		};

		virtual cfint::CFIntMajorVersionPKey* getPKey();
		virtual void setPKey( cfint::CFIntMajorVersionPKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int64_t getRequiredTenantId();
		virtual const int64_t* getRequiredTenantIdReference();

		virtual const int64_t getRequiredId();
		virtual const int64_t* getRequiredIdReference();

		virtual const int64_t getRequiredSubProjectId();
		virtual const int64_t* getRequiredSubProjectIdReference();

		virtual const std::string& getRequiredName();
		virtual const std::string* getRequiredNameReference();
		virtual void setRequiredName( const std::string& value );

		virtual bool isOptionalDescriptionNull();
		virtual const std::string& getOptionalDescriptionValue();
		virtual const std::string* getOptionalDescriptionReference();
		virtual void setOptionalDescriptionNull();
		virtual void setOptionalDescriptionValue( const std::string& value );

		virtual cfsec::ICFSecTenantObj* getRequiredOwnerTenant( bool forceRead = false );
		virtual void setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value );

		virtual cfint::ICFIntSubProjectObj* getRequiredContainerParentSPrj( bool forceRead = false );
		virtual void setRequiredContainerParentSPrj( cfint::ICFIntSubProjectObj* value );

		virtual std::vector<cfint::ICFIntMinorVersionObj*> getOptionalComponentsMinorVer( bool forceRead = false );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
