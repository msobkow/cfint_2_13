#pragma once

// Description: C++18 edit object instance specification for CFInt TopProject.

/*
 *	org.msscf.msscf.CFInt
 *
 *	Copyright (c) 2020 Mark Stephen Sobkow
 *	
 *	MSS Code Factory CFInt 2.13 Internet Essentials
 *	
 *	Copyright 2020-2021 Mark Stephen Sobkow
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
 *	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
 *
 *	Manufactured by MSS Code Factory 2.12
 */

#include <cflib/ICFLibPublic.hpp>
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>

namespace cfint {

	class CFIntTopProjectEditObj
	: public virtual ICFIntTopProjectEditObj
	{
	public:
		static const std::string CLASS_NAME;
	protected:
		cfint::ICFIntTopProjectObj* orig;
		cfint::CFIntTopProjectBuff* buff;
		cfsec::ICFSecSecUserObj* createdBy = NULL;
		cfsec::ICFSecSecUserObj* updatedBy = NULL;
	public:
		CFIntTopProjectEditObj( cfint::ICFIntTopProjectObj* argOrig );
		virtual ~CFIntTopProjectEditObj();

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

		virtual ICFIntTopProjectObj* realize();

		virtual cfint::ICFIntTopProjectObj* read( bool forceRead = false );

		virtual ICFIntTopProjectObj* create();

		virtual ICFIntTopProjectEditObj* update();

		virtual ICFIntTopProjectEditObj* deleteInstance();

		virtual cfint::ICFIntTopProjectTableObj* getTopProjectTable();

		virtual cfint::ICFIntTopProjectEditObj* getEdit();

		virtual cfint::ICFIntTopProjectEditObj* getTopProjectEdit();

		virtual ICFIntTopProjectEditObj* beginEdit();

		virtual void endEdit();

		virtual cfint::ICFIntTopProjectObj* getOrig();

		virtual cfint::ICFIntTopProjectObj* getOrigAsTopProject();

		virtual cfint::ICFIntSchemaObj* getSchema();

		virtual cfint::CFIntTopProjectBuff* getBuff();
		virtual void setBuff( cfint::CFIntTopProjectBuff* value );

		inline cfint::CFIntTopProjectBuff* getTopProjectBuff() {
			// Buff is always instantiated when constructed over an original object
			return( static_cast<cfint::CFIntTopProjectBuff*>( buff ) );
		};

		inline cfint::CFIntTopProjectBuff* getTopProjectEditBuff() {
			// Buff is always instantiated when constructed over an original object
			return( dynamic_cast<cfint::CFIntTopProjectBuff*>( buff ) );
		};

		virtual cfint::CFIntTopProjectPKey* getPKey();
		virtual void setPKey( cfint::CFIntTopProjectPKey* value );

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

		virtual cfsec::ICFSecTenantObj* getRequiredOwnerTenant( bool forceRead = false );
		virtual void setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value );

		virtual cfint::ICFIntTopDomainObj* getRequiredContainerParentSDom( bool forceRead = false );
		virtual void setRequiredContainerParentSDom( cfint::ICFIntTopDomainObj* value );

		virtual std::vector<cfint::ICFIntSubProjectObj*> getOptionalComponentsSubProject( bool forceRead = false );

		virtual void copyPKeyToBuff();

		virtual void copyBuffToPKey();

		virtual void copyBuffToOrig();

		virtual void copyOrigToBuff();

	};
}
