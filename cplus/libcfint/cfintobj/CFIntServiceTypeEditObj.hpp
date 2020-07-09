#pragma once

// Description: C++18 edit object instance specification for CFInt ServiceType.

/*
 *	org.msscf.msscf.CFInt
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

	class CFIntServiceTypeEditObj
	: public virtual ICFIntServiceTypeEditObj,
	  public virtual cfsec::ICFSecServiceTypeEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfsec::ICFSecServiceTypeObj* orig;
		cfsec::CFSecServiceTypeBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFIntServiceTypeEditObj( cfsec::ICFSecServiceTypeObj* argOrig );
		virtual ~CFIntServiceTypeEditObj();

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

		virtual ICFSecServiceTypeObj* realize();

		virtual cfsec::ICFSecServiceTypeObj* read( bool forceRead = false );

		virtual ICFSecServiceTypeObj* create();

		virtual ICFSecServiceTypeEditObj* update();

		virtual ICFSecServiceTypeEditObj* deleteInstance();

		virtual cfsec::ICFSecServiceTypeTableObj* getServiceTypeTable();

		virtual cfsec::ICFSecServiceTypeEditObj* getEdit();

		virtual cfsec::ICFSecServiceTypeEditObj* getServiceTypeEdit();

		virtual ICFSecServiceTypeEditObj* beginEdit();

		virtual void endEdit();

		virtual cfsec::ICFSecServiceTypeObj* getOrig();

		virtual cfsec::ICFSecServiceTypeObj* getOrigAsServiceType();

		virtual cfsec::ICFSecSchemaObj* getSchema();

		virtual cfsec::CFSecServiceTypeBuff* getBuff();
		virtual void setBuff( cfsec::CFSecServiceTypeBuff* value );

		inline cfsec::CFSecServiceTypeBuff* getServiceTypeBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
		};

		inline cfsec::CFSecServiceTypeBuff* getServiceTypeEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfsec::CFSecServiceTypeBuff*>( buff ) );
		};

		virtual cfsec::CFSecServiceTypePKey* getPKey();
		virtual void setPKey( cfsec::CFSecServiceTypePKey* value );

		virtual bool getIsNew();
		virtual void setIsNew( bool value );

		virtual const int32_t getRequiredServiceTypeId();
		virtual const int32_t* getRequiredServiceTypeIdReference();

		virtual const std::string& getRequiredDescription();
		virtual const std::string* getRequiredDescriptionReference();
		virtual void setRequiredDescription( const std::string& value );

		virtual std::vector<cfsec::ICFSecServiceObj*> getOptionalChildrenDeployed( bool forceRead = false );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
