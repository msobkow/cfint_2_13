// Description: C++18 edit object instance implementation for CFInt License.

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

using namespace std;

#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfintobj/CFIntLicenseObj.hpp>
#include <cfintobj/CFIntLicenseEditObj.hpp>


namespace cfint {

	const std::string CFIntLicenseEditObj::CLASS_NAME( "CFIntLicenseEditObj" );

	CFIntLicenseEditObj::CFIntLicenseEditObj( cfint::ICFIntLicenseObj* argOrig )
	: ICFIntLicenseEditObj()
	{
		static const std::string S_ProcName( "CFIntLicenseEditObj-construct" );
		static const std::string S_OrigBuff( "origBuff" );
		orig = argOrig;
		cfint::CFIntLicenseBuff* origBuff = orig->getBuff();
		if( origBuff == NULL ) {
			throw cflib::CFLibNullArgumentException( CLASS_NAME,
				S_ProcName,
				0,
				S_OrigBuff );
		}
		buff = dynamic_cast<cfint::CFIntLicenseBuff*>( origBuff->clone() );
	}

	CFIntLicenseEditObj::~CFIntLicenseEditObj() {
		orig = NULL;
		if( buff != NULL ) {
			delete buff;
			buff = NULL;
		}

	}

	const std::string& CFIntLicenseEditObj::getClassName() const {
		return( CLASS_NAME );
	}

	const classcode_t CFIntLicenseEditObj::getClassCode() const {
		return( cfint::CFIntLicenseBuff::CLASS_CODE );
	}

	bool CFIntLicenseEditObj::implementsClassCode( const classcode_t value ) const {
		if( value == cfint::CFIntLicenseBuff::CLASS_CODE ) {
			return( true );
		}
		else {
			return( false );
		}
	}

	std::string CFIntLicenseEditObj::toString() {
		static const std::string S_Space( " " );
		static const std::string S_Preamble( "<CFIntLicenseEditObj" );
		static const std::string S_Postamble( "/>" );
		static const std::string S_Revision( "Revision" );
		static const std::string S_TenantId( "TenantId" );
		static const std::string S_Id( "Id" );
		static const std::string S_TopDomainId( "TopDomainId" );
		static const std::string S_Name( "Name" );
		static const std::string S_Description( "Description" );
		static const std::string S_EmbeddedText( "EmbeddedText" );
		static const std::string S_FullText( "FullText" );
		std::string ret( S_Preamble );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt32( &S_Space, S_Revision, CFIntLicenseEditObj::getRequiredRevision() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TenantId, CFIntLicenseEditObj::getRequiredTenantId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_Id, CFIntLicenseEditObj::getRequiredId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredInt64( &S_Space, S_TopDomainId, CFIntLicenseEditObj::getRequiredTopDomainId() ) );
		ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Name, CFIntLicenseEditObj::getRequiredName() ) );
		if( ! CFIntLicenseEditObj::isOptionalDescriptionNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_Description, CFIntLicenseEditObj::getOptionalDescriptionValue() ) );
		}
		if( ! CFIntLicenseEditObj::isOptionalEmbeddedTextNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_EmbeddedText, CFIntLicenseEditObj::getOptionalEmbeddedTextValue() ) );
		}
		if( ! CFIntLicenseEditObj::isOptionalFullTextNull() ) {
			ret.append( cflib::CFLibXmlUtil::formatRequiredXmlString( &S_Space, S_FullText, CFIntLicenseEditObj::getOptionalFullTextValue() ) );
		}
		ret.append( S_Postamble );
		return( ret );
	}

	int32_t CFIntLicenseEditObj::getRequiredRevision() const {
		return( buff->getRequiredRevision() );
	}

	void CFIntLicenseEditObj::setRequiredRevision( int32_t value ) {
		getLicenseEditBuff()->setRequiredRevision( value );
	}

	std::string CFIntLicenseEditObj::getObjName() {
		std::string objName( CLASS_NAME ); objName;
		objName.clear();
		objName.append( getRequiredName() );
		return( objName );
	}

	const std::string CFIntLicenseEditObj::getGenDefName() {
		return( cfint::CFIntLicenseBuff::GENDEFNAME );
	}

	cflib::ICFLibAnyObj* CFIntLicenseEditObj::getScope() {
		cfint::ICFIntTopDomainObj* scope = getRequiredContainerTopDomain();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntLicenseEditObj::getObjScope() {
		cfint::ICFIntTopDomainObj* scope = getRequiredContainerTopDomain();
		return( scope );
	}

	cflib::ICFLibAnyObj* CFIntLicenseEditObj::getObjQualifier( const classcode_t* qualifyingClass ) {
		cflib::ICFLibAnyObj* container = this;
		if( qualifyingClass != NULL ) {
			while( container != NULL ) {
				if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					break;
				}
				else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
					break;
				}
				else if( container->implementsClassCode( *qualifyingClass ) ) {
					break;
				}
				container = container->getObjScope();
			}
		}
		else {
			while( container != NULL ) {
				if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
					break;
				}
				else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
					break;
				}
				container = container->getObjScope();
			}
		}
		return( container );
	}

	cflib::ICFLibAnyObj* CFIntLicenseEditObj::getNamedObject( const classcode_t* qualifyingClass, const std::string& objName ) {
		cflib::ICFLibAnyObj* topContainer = getObjQualifier( qualifyingClass );
		if( topContainer == NULL ) {
			return( NULL );
		}
		cflib::ICFLibAnyObj* namedObject = topContainer->getNamedObject( objName );
		return( namedObject );
	}

	cflib::ICFLibAnyObj* CFIntLicenseEditObj::getNamedObject( const std::string& objName ) {
		std::string nextName;
		std::string remainingName;
		cflib::ICFLibAnyObj* subObj = NULL;
		cflib::ICFLibAnyObj* retObj;
		int32_t nextDot = objName.find( '.' );
		if( nextDot >= 0 ) {
			nextName = objName.substr( 0, nextDot );
			remainingName = objName.substr( nextDot + 1 );
		}
		else {
			nextName.clear();
			nextName.append( objName );
			remainingName.clear();
		}
		if( remainingName.length() <= 0 ) {
			retObj = subObj;
		}
		else if( subObj == NULL ) {
			retObj = NULL;
		}
		else {
			retObj = subObj->getNamedObject( remainingName );
		}
		return( retObj );
	}

	std::string CFIntLicenseEditObj::getObjQualifiedName() {
		const static std::string S_Dot( "." );
		std::string qualName( getObjName() );
		cflib::ICFLibAnyObj* container = getObjScope();
		std::string containerName;
		std::string buildName;
		while( container != NULL ) {
			if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
				container = NULL;
			}
			else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
				container = NULL;
			}
			else if( container->implementsClassCode( cfsec::CFSecTenantBuff::CLASS_CODE ) ) {
				container = NULL;
			}
			else {
				containerName = container->getObjName();
				buildName.clear();
				buildName.append( containerName );
				buildName.append( S_Dot );
				buildName.append( qualName );
				qualName.clear();
				qualName.append( buildName );
				container = container->getObjScope();
			}
		}
		return( qualName );
	}

	std::string CFIntLicenseEditObj::getObjFullName() {
		const static std::string S_Dot( "." );
		std::string fullName = getObjName();
		cflib::ICFLibAnyObj* container = getObjScope();
		std::string containerName;
		std::string buildName;
		while( container != NULL ) {
			if( container->getClassCode() == cfsec::CFSecClusterBuff::CLASS_CODE ) {
				container = NULL;
			}
			else if( container->getClassCode() == cfsec::CFSecTenantBuff::CLASS_CODE ) {
				container = NULL;
			}
			else {
				containerName = container->getObjName();
				buildName.clear();
				buildName.append( containerName );
				buildName.append( S_Dot );
				buildName.append( fullName );
				fullName.clear();
				fullName.append( buildName );
				container = container->getObjScope();
			}
		}
		return( fullName );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseEditObj::realize() {
		// We realize this so that it's buffer will get copied to orig during realization
		cfint::ICFIntLicenseObj* retobj = getSchema()->getLicenseTableObj()->realizeLicense( dynamic_cast<cfint::ICFIntLicenseObj*>( this ) );
		return( retobj );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseEditObj::read( bool forceRead ) {
		cfint::ICFIntLicenseObj* retval = getOrigAsLicense()->read( forceRead );
		if( retval != orig ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				"read",
				"retval != orig" );
		}
		copyOrigToBuff();
		return( retval );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseEditObj::create() {
		cfint::ICFIntLicenseObj* retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsLicense()->getSchema() )->getLicenseTableObj()->createLicense( this );
		// Note that this instance is usually discarded during the creation process,
		// and retobj now references the cached instance of the created object.
		return( retobj );
	}

	cfint::ICFIntLicenseEditObj* CFIntLicenseEditObj::update() {
		getSchema()->getLicenseTableObj()->updateLicense( this );
		return( NULL );
	}

	cfint::ICFIntLicenseEditObj* CFIntLicenseEditObj::deleteInstance() {
		static const std::string S_MethodName( "deleteInstance" );
		static const std::string S_CannotDeleteNewInstance( "Cannot delete a new instance" );
		if( getIsNew() ) {
			throw cflib::CFLibUsageException( CLASS_NAME, S_MethodName, S_CannotDeleteNewInstance );
		}
		getSchema()->getLicenseTableObj()->deleteLicense( this );
		return( NULL );
	}

	cfint::ICFIntLicenseTableObj* CFIntLicenseEditObj::getLicenseTable() {
		return( orig->getSchema()->getLicenseTableObj() );
	}

	cfint::ICFIntLicenseEditObj* CFIntLicenseEditObj::getEdit() {
		return( this );
	}

	cfint::ICFIntLicenseEditObj* CFIntLicenseEditObj::getLicenseEdit() {
		return( (cfint::ICFIntLicenseEditObj*)this );
	}

	cfint::ICFIntLicenseEditObj* CFIntLicenseEditObj::beginEdit() {
		static const std::string S_ProcName( "beginEdit" );
		static const std::string S_Message( "Cannot edit an edition" );
		throw cflib::CFLibUsageException( CLASS_NAME,
			S_ProcName,
			S_Message );
	}

	void CFIntLicenseEditObj::endEdit() {
		orig->endEdit();
	}

	cfint::ICFIntLicenseObj* CFIntLicenseEditObj::getOrig() {
		return( orig );
	}

	cfint::ICFIntLicenseObj* CFIntLicenseEditObj::getOrigAsLicense() {
		return( dynamic_cast<cfint::ICFIntLicenseObj*>( orig ) );
	}

	cfint::ICFIntSchemaObj* CFIntLicenseEditObj::getSchema() {
		return( orig->getSchema() );
	}

	cfint::CFIntLicenseBuff* CFIntLicenseEditObj::getBuff() {
		return( buff );
	}

	void CFIntLicenseEditObj::setBuff( cfint::CFIntLicenseBuff* value ) {
		if( buff != value ) {
			if( ( buff != NULL ) && ( buff != value ) ) {
				delete buff;
				buff = NULL;
			}
			buff = value;
		}
	}

	cfint::CFIntLicensePKey* CFIntLicenseEditObj::getPKey() {
		return( orig->getPKey() );
	}

	void CFIntLicenseEditObj::setPKey( cfint::CFIntLicensePKey* value ) {
		if( orig->getPKey() != value ) {
			orig->setPKey( value );
		}
		copyPKeyToBuff();
	}

	bool CFIntLicenseEditObj::getIsNew() {
		return( orig->getIsNew() );
	}

	void CFIntLicenseEditObj::setIsNew( bool value ) {
		orig->setIsNew( value );
	}

	const int64_t CFIntLicenseEditObj::getRequiredTenantId() {
		return( getPKey()->getRequiredTenantId() );
	}

	const int64_t* CFIntLicenseEditObj::getRequiredTenantIdReference() {
		return( getPKey()->getRequiredTenantIdReference() );
	}

	const int64_t CFIntLicenseEditObj::getRequiredId() {
		return( getPKey()->getRequiredId() );
	}

	const int64_t* CFIntLicenseEditObj::getRequiredIdReference() {
		return( getPKey()->getRequiredIdReference() );
	}

	const int64_t CFIntLicenseEditObj::getRequiredTopDomainId() {
		return( getLicenseBuff()->getRequiredTopDomainId() );
	}

	const int64_t* CFIntLicenseEditObj::getRequiredTopDomainIdReference() {
		return( getLicenseBuff()->getRequiredTopDomainIdReference() );
	}

	const std::string& CFIntLicenseEditObj::getRequiredName() {
		return( getLicenseBuff()->getRequiredName() );
	}

	const std::string* CFIntLicenseEditObj::getRequiredNameReference() {
		return( getLicenseBuff()->getRequiredNameReference() );
	}

	void CFIntLicenseEditObj::setRequiredName( const std::string& value ) {
		if( getLicenseBuff()->getRequiredName() != value ) {
			getLicenseEditBuff()->setRequiredName( value );
		}
	}

	bool CFIntLicenseEditObj::isOptionalDescriptionNull() {
		return( getLicenseBuff()->isOptionalDescriptionNull() );
	}

	const std::string& CFIntLicenseEditObj::getOptionalDescriptionValue() {
		return( getLicenseBuff()->getOptionalDescriptionValue() );
	}

	const std::string* CFIntLicenseEditObj::getOptionalDescriptionReference() {
		return( getLicenseBuff()->getOptionalDescriptionReference() );
	}

	void CFIntLicenseEditObj::setOptionalDescriptionNull() {
		if( ! getLicenseBuff()->isOptionalDescriptionNull() ) {
			getLicenseEditBuff()->setOptionalDescriptionNull();
		}
	}

	void CFIntLicenseEditObj::setOptionalDescriptionValue( const std::string& value ) {
		if( getLicenseBuff()->isOptionalDescriptionNull() ) {
			getLicenseEditBuff()->setOptionalDescriptionValue( value );
		}
		else if( getLicenseBuff()->getOptionalDescriptionValue() != value ) {
			getLicenseEditBuff()->setOptionalDescriptionValue( value );
		}
	}

	bool CFIntLicenseEditObj::isOptionalEmbeddedTextNull() {
		return( getLicenseBuff()->isOptionalEmbeddedTextNull() );
	}

	const std::string& CFIntLicenseEditObj::getOptionalEmbeddedTextValue() {
		return( getLicenseBuff()->getOptionalEmbeddedTextValue() );
	}

	const std::string* CFIntLicenseEditObj::getOptionalEmbeddedTextReference() {
		return( getLicenseBuff()->getOptionalEmbeddedTextReference() );
	}

	void CFIntLicenseEditObj::setOptionalEmbeddedTextNull() {
		if( ! getLicenseBuff()->isOptionalEmbeddedTextNull() ) {
			getLicenseEditBuff()->setOptionalEmbeddedTextNull();
		}
	}

	void CFIntLicenseEditObj::setOptionalEmbeddedTextValue( const std::string& value ) {
		if( getLicenseBuff()->isOptionalEmbeddedTextNull() ) {
			getLicenseEditBuff()->setOptionalEmbeddedTextValue( value );
		}
		else if( getLicenseBuff()->getOptionalEmbeddedTextValue() != value ) {
			getLicenseEditBuff()->setOptionalEmbeddedTextValue( value );
		}
	}

	bool CFIntLicenseEditObj::isOptionalFullTextNull() {
		return( getLicenseBuff()->isOptionalFullTextNull() );
	}

	const std::string& CFIntLicenseEditObj::getOptionalFullTextValue() {
		return( getLicenseBuff()->getOptionalFullTextValue() );
	}

	const std::string* CFIntLicenseEditObj::getOptionalFullTextReference() {
		return( getLicenseBuff()->getOptionalFullTextReference() );
	}

	void CFIntLicenseEditObj::setOptionalFullTextNull() {
		if( ! getLicenseBuff()->isOptionalFullTextNull() ) {
			getLicenseEditBuff()->setOptionalFullTextNull();
		}
	}

	void CFIntLicenseEditObj::setOptionalFullTextValue( const std::string& value ) {
		if( getLicenseBuff()->isOptionalFullTextNull() ) {
			getLicenseEditBuff()->setOptionalFullTextValue( value );
		}
		else if( getLicenseBuff()->getOptionalFullTextValue() != value ) {
			getLicenseEditBuff()->setOptionalFullTextValue( value );
		}
	}

	cfsec::ICFSecTenantObj* CFIntLicenseEditObj::getRequiredOwnerTenant( bool forceRead ) {
		cfsec::ICFSecTenantObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsLicense()->getSchema() )->getTenantTableObj()->readTenantByIdIdx( getPKey()->getRequiredTenantId() );
		}
		return( retobj );
	}

	void CFIntLicenseEditObj::setRequiredOwnerTenant( cfsec::ICFSecTenantObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredId() );
				getLicenseEditBuff()->setRequiredTenantId( value->getRequiredId() );
			}
		}

	cfint::ICFIntTopDomainObj* CFIntLicenseEditObj::getRequiredContainerTopDomain( bool forceRead ) {
		cfint::ICFIntTopDomainObj* retobj = NULL;
		bool anyMissing = false;
		if( ! anyMissing ) {
			retobj = dynamic_cast<cfint::ICFIntSchemaObj*>( getOrigAsLicense()->getSchema() )->getTopDomainTableObj()->readTopDomainByIdIdx( getPKey()->getRequiredTenantId(),
					getLicenseBuff()->getRequiredTopDomainId() );
		}
		return( retobj );
	}

	void CFIntLicenseEditObj::setRequiredContainerTopDomain( cfint::ICFIntTopDomainObj* value ) {
			
			if( value != NULL ) {
				getPKey()->setRequiredTenantId
( value->getRequiredTenantId() );
				getLicenseEditBuff()->setRequiredTenantId( value->getRequiredTenantId() );
				getLicenseEditBuff()->setRequiredTopDomainId( value->getRequiredId() );
			}
		}

	void CFIntLicenseEditObj::copyPKeyToBuff() {
		cfint::CFIntLicensePKey* tablePKey = getPKey();
		cfint::CFIntLicenseBuff* tableBuff = getLicenseEditBuff();
		tableBuff->setRequiredTenantId( tablePKey->getRequiredTenantId() );
		tableBuff->setRequiredId( tablePKey->getRequiredId() );
	}

	void CFIntLicenseEditObj::copyBuffToPKey() {
		cfint::CFIntLicensePKey* tablePKey = getPKey();
		cfint::CFIntLicenseBuff* tableBuff = getLicenseBuff();
		tablePKey->setRequiredTenantId( tableBuff->getRequiredTenantId() );
		tablePKey->setRequiredId( tableBuff->getRequiredId() );
	}

	void CFIntLicenseEditObj::copyBuffToOrig() {
		cfint::CFIntLicenseBuff* origBuff = getOrigAsLicense()->getLicenseEditBuff();
		cfint::CFIntLicenseBuff* myBuff = getLicenseBuff();
		if( origBuff != myBuff ) {
			*origBuff = *myBuff;
		}
	}

	void CFIntLicenseEditObj::copyOrigToBuff() {
		cfint::CFIntLicenseBuff* origBuff = getOrigAsLicense()->getLicenseBuff();
		cfint::CFIntLicenseBuff* myBuff = getLicenseEditBuff();
		if( origBuff != myBuff ) {
			*myBuff = *origBuff;
		}
	}

}
