#pragma once

// Description: C++18 edit object instance specification for CFInt MimeType.

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

	class CFIntMimeTypeEditObj
	: public virtual ICFIntMimeTypeEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfint::ICFIntMimeTypeObj* orig;
		cfint::CFIntMimeTypeBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFIntMimeTypeEditObj( cfint::ICFIntMimeTypeObj* argOrig );
		virtual ~CFIntMimeTypeEditObj();

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

		virtual ICFIntMimeTypeObj* realize();

		virtual cfint::ICFIntMimeTypeObj* read( bool forceRead = false );

		virtual ICFIntMimeTypeObj* create();

		virtual ICFIntMimeTypeEditObj* update();

		virtual ICFIntMimeTypeEditObj* deleteInstance();

		virtual cfint::ICFIntMimeTypeTableObj* getMimeTypeTable();

		virtual cfint::ICFIntMimeTypeEditObj* getEdit();

		virtual cfint::ICFIntMimeTypeEditObj* getMimeTypeEdit();

		virtual ICFIntMimeTypeEditObj* beginEdit();

		virtual void endEdit();

		virtual cfint::ICFIntMimeTypeObj* getOrig();

		virtual cfint::ICFIntMimeTypeObj* getOrigAsMimeType();

		virtual cfint::ICFIntSchemaObj* getSchema();

		virtual cfint::CFIntMimeTypeBuff* getBuff();
		virtual void setBuff( cfint::CFIntMimeTypeBuff* value );

		inline cfint::CFIntMimeTypeBuff* getMimeTypeBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfint::CFIntMimeTypeBuff*>( buff ) );
		};

		inline cfint::CFIntMimeTypeBuff* getMimeTypeEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfint::CFIntMimeTypeBuff*>( buff ) );
		};

		virtual cfint::CFIntMimeTypePKey* getPKey();
		virtual void setPKey( cfint::CFIntMimeTypePKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int32_t getRequiredMimeTypeId();
		virtual const int32_t* getRequiredMimeTypeIdReference();

		virtual const std::string& getRequiredName();
		virtual const std::string* getRequiredNameReference();
		virtual void setRequiredName( const std::string& value );

		virtual bool isOptionalFileTypesNull();
		virtual const std::string& getOptionalFileTypesValue();
		virtual const std::string* getOptionalFileTypesReference();
		virtual void setOptionalFileTypesNull();
		virtual void setOptionalFileTypesValue( const std::string& value );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
