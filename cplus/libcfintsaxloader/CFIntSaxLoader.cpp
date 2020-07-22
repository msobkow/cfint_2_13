// Description: C++18 XML SAX Parser implementation for CFInt.

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
#include <fstream>
#include <cflib/ICFLibPublic.hpp>
#include <cfint/ICFIntPublic.hpp>
#include <cfintobj/ICFIntObjPublic.hpp>
#include <cfsecsaxloader/CFSecSaxLoader.hpp>
#include <cfintsaxloader/CFIntSaxLoader.hpp>
#include <cfintsaxloader/CFIntSaxLoaderClusterHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderHostNodeHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderISOCcyHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderISOCtryHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderISOCtryCcyHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderISOCtryLangHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderISOLangHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderISOTZoneHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderLicenseHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderMajorVersionHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderMimeTypeHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderMinorVersionHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSecAppHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSecDeviceHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSecFormHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSecGroupHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSecGroupFormHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSecGrpIncHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSecGrpMembHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSecSessionHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSecUserHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderServiceHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderServiceTypeHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSubProjectHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderSysClusterHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderTSecGroupHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderTSecGrpIncHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderTSecGrpMembHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderTenantHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderTldHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderTopDomainHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderTopProjectHandler.hpp>
#include <cfintsaxloader/CFIntSaxLoaderURLProtocolHandler.hpp>

using namespace std;

namespace cfint {

	CFIntSaxRootHandler::CFIntSaxRootHandler( cfint::CFIntSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFIntSaxRootHandler::~CFIntSaxRootHandler() {
	}

	/**
	 * Receive notification of the beginning of an element.
	 *
	 * <p>The Parser will invoke this method at the beginning of every
	 * element in the XML document; there will be a corresponding
	 * endElement() event for every startElement() event (even when the
	 * element is empty). All of the element's content will be
	 * reported, in order, before the corresponding endElement()
	 * event.</p>
	 *
	 * <p>Note that the attribute list provided will
	 * contain only attributes with explicit values (specified or
	 * defaulted): \#IMPLIED attributes will be omitted.</p>
	 *
	 * @param uri The URI of the associated namespace for this element
	 * @param localname The local part of the element name
	 * @param qname The QName of this element
	 * @param attrs The attributes attached to the element, if any.
	 * @exception SAXException Any SAX exception, possibly
	 *			wrapping another exception.
	 * @see #endElement
	 * @see Attributes#Attributes
	 */
	void CFIntSaxRootHandler::startElement (
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname,
		const xercesc::Attributes& attrs )
	{
	}

	/**
	 * Receive notification of the end of an element.
	 *
	 * <p>The SAX parser will invoke this method at the end of every
	 * element in the XML document; there will be a corresponding
	 * startElement() event for every endElement() event (even when the
	 * element is empty).</p>
	 *
	 * @param uri The URI of the associated namespace for this element
	 * @param localname The local part of the element name
	 * @param qname The QName of this element
	 * @exception SAXException Any SAX exception, possibly
	 *			wrapping another exception.
	 */
	void CFIntSaxRootHandler::endElement (
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}


	CFIntSaxDocHandler::CFIntSaxDocHandler( cfint::CFIntSaxLoader* saxLoader )
	: cflib::CFLibXmlCoreElementHandler( saxLoader )
	{
	}

	CFIntSaxDocHandler::~CFIntSaxDocHandler() {
	}

	/**
	 * Receive notification of the beginning of an element.
	 *
	 * <p>The Parser will invoke this method at the beginning of every
	 * element in the XML document; there will be a corresponding
	 * endElement() event for every startElement() event (even when the
	 * element is empty). All of the element's content will be
	 * reported, in order, before the corresponding endElement()
	 * event.</p>
	 *
	 * <p>Note that the attribute list provided will
	 * contain only attributes with explicit values (specified or
	 * defaulted): \#IMPLIED attributes will be omitted.</p>
	 *
	 * @param uri The URI of the associated namespace for this element
	 * @param localname The local part of the element name
	 * @param qname The QName of this element
	 * @param attrs The attributes attached to the element, if any.
	 * @exception SAXException Any SAX exception, possibly
	 *			wrapping another exception.
	 * @see #endElement
	 * @see Attributes#Attributes
	 */
	void CFIntSaxDocHandler::startElement (
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname,
		const xercesc::Attributes& attrs )
	{
	}

	/**
	 * Receive notification of the end of an element.
	 *
	 * <p>The SAX parser will invoke this method at the end of every
	 * element in the XML document; there will be a corresponding
	 * startElement() event for every endElement() event (even when the
	 * element is empty).</p>
	 *
	 * @param uri The URI of the associated namespace for this element
	 * @param localname The local part of the element name
	 * @param qname The QName of this element
	 * @exception SAXException Any SAX exception, possibly
	 *			wrapping another exception.
	 */
	void CFIntSaxDocHandler::endElement (
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname )
	{
	}

	const std::string CFIntSaxLoader::CLASS_NAME( "CFIntSaxLoader" );
	const std::string CFIntSaxLoader::SCHEMA_XMLNS( "uri://org.msscf/msscf/2.0.13/cfintloader" );
	const std::string CFIntSaxLoader::SCHEMA_URI( "/opt/msscf/2.0.13/xsd/cfint-structured.xsd" );
	bool CFIntSaxLoader::grammarLoaded = false;

	CFIntSaxLoader::CFIntSaxLoader()
	: cflib::CFLibXmlCoreSaxParser()
	{
		schemaObj = NULL;
		saxRootHandler = NULL;
		saxDocHandler = NULL;
		clusterHandler = NULL;
		hostNodeHandler = NULL;
		iSOCcyHandler = NULL;
		iSOCtryHandler = NULL;
		iSOCtryCcyHandler = NULL;
		iSOCtryLangHandler = NULL;
		iSOLangHandler = NULL;
		iSOTZoneHandler = NULL;
		licenseHandler = NULL;
		majorVersionHandler = NULL;
		mimeTypeHandler = NULL;
		minorVersionHandler = NULL;
		secAppHandler = NULL;
		secDeviceHandler = NULL;
		secFormHandler = NULL;
		secGroupHandler = NULL;
		secGroupFormHandler = NULL;
		secGrpIncHandler = NULL;
		secGrpMembHandler = NULL;
		secSessionHandler = NULL;
		secUserHandler = NULL;
		serviceHandler = NULL;
		serviceTypeHandler = NULL;
		subProjectHandler = NULL;
		sysClusterHandler = NULL;
		tSecGroupHandler = NULL;
		tSecGrpIncHandler = NULL;
		tSecGrpMembHandler = NULL;
		tenantHandler = NULL;
		tldHandler = NULL;
		topDomainHandler = NULL;
		topProjectHandler = NULL;
		uRLProtocolHandler = NULL;
		useCluster = NULL;
		useTenant = NULL;
		setRootElementHandler( getSaxRootHandler() );
		verifyGrammarInstallation();
		initParser();
	}

	CFIntSaxLoader::CFIntSaxLoader( cflib::ICFLibMessageLog* logger )
	: cflib::CFLibXmlCoreSaxParser( logger )
	{
		saxRootHandler = NULL;
		saxDocHandler = NULL;
		clusterHandler = NULL;
		hostNodeHandler = NULL;
		iSOCcyHandler = NULL;
		iSOCtryHandler = NULL;
		iSOCtryCcyHandler = NULL;
		iSOCtryLangHandler = NULL;
		iSOLangHandler = NULL;
		iSOTZoneHandler = NULL;
		licenseHandler = NULL;
		majorVersionHandler = NULL;
		mimeTypeHandler = NULL;
		minorVersionHandler = NULL;
		secAppHandler = NULL;
		secDeviceHandler = NULL;
		secFormHandler = NULL;
		secGroupHandler = NULL;
		secGroupFormHandler = NULL;
		secGrpIncHandler = NULL;
		secGrpMembHandler = NULL;
		secSessionHandler = NULL;
		secUserHandler = NULL;
		serviceHandler = NULL;
		serviceTypeHandler = NULL;
		subProjectHandler = NULL;
		sysClusterHandler = NULL;
		tSecGroupHandler = NULL;
		tSecGrpIncHandler = NULL;
		tSecGrpMembHandler = NULL;
		tenantHandler = NULL;
		tldHandler = NULL;
		topDomainHandler = NULL;
		topProjectHandler = NULL;
		uRLProtocolHandler = NULL;
		useCluster = NULL;
		useTenant = NULL;
		setRootElementHandler( getSaxRootHandler() );
		verifyGrammarInstallation();
		initParser();
	}

	CFIntSaxLoader::~CFIntSaxLoader() {
		if( clusterHandler != NULL ) {
			delete clusterHandler;
			clusterHandler = NULL;
		}
		if( hostNodeHandler != NULL ) {
			delete hostNodeHandler;
			hostNodeHandler = NULL;
		}
		if( iSOCcyHandler != NULL ) {
			delete iSOCcyHandler;
			iSOCcyHandler = NULL;
		}
		if( iSOCtryHandler != NULL ) {
			delete iSOCtryHandler;
			iSOCtryHandler = NULL;
		}
		if( iSOCtryCcyHandler != NULL ) {
			delete iSOCtryCcyHandler;
			iSOCtryCcyHandler = NULL;
		}
		if( iSOCtryLangHandler != NULL ) {
			delete iSOCtryLangHandler;
			iSOCtryLangHandler = NULL;
		}
		if( iSOLangHandler != NULL ) {
			delete iSOLangHandler;
			iSOLangHandler = NULL;
		}
		if( iSOTZoneHandler != NULL ) {
			delete iSOTZoneHandler;
			iSOTZoneHandler = NULL;
		}
		if( licenseHandler != NULL ) {
			delete licenseHandler;
			licenseHandler = NULL;
		}
		if( majorVersionHandler != NULL ) {
			delete majorVersionHandler;
			majorVersionHandler = NULL;
		}
		if( mimeTypeHandler != NULL ) {
			delete mimeTypeHandler;
			mimeTypeHandler = NULL;
		}
		if( minorVersionHandler != NULL ) {
			delete minorVersionHandler;
			minorVersionHandler = NULL;
		}
		if( secAppHandler != NULL ) {
			delete secAppHandler;
			secAppHandler = NULL;
		}
		if( secDeviceHandler != NULL ) {
			delete secDeviceHandler;
			secDeviceHandler = NULL;
		}
		if( secFormHandler != NULL ) {
			delete secFormHandler;
			secFormHandler = NULL;
		}
		if( secGroupHandler != NULL ) {
			delete secGroupHandler;
			secGroupHandler = NULL;
		}
		if( secGroupFormHandler != NULL ) {
			delete secGroupFormHandler;
			secGroupFormHandler = NULL;
		}
		if( secGrpIncHandler != NULL ) {
			delete secGrpIncHandler;
			secGrpIncHandler = NULL;
		}
		if( secGrpMembHandler != NULL ) {
			delete secGrpMembHandler;
			secGrpMembHandler = NULL;
		}
		if( secSessionHandler != NULL ) {
			delete secSessionHandler;
			secSessionHandler = NULL;
		}
		if( secUserHandler != NULL ) {
			delete secUserHandler;
			secUserHandler = NULL;
		}
		if( serviceHandler != NULL ) {
			delete serviceHandler;
			serviceHandler = NULL;
		}
		if( serviceTypeHandler != NULL ) {
			delete serviceTypeHandler;
			serviceTypeHandler = NULL;
		}
		if( subProjectHandler != NULL ) {
			delete subProjectHandler;
			subProjectHandler = NULL;
		}
		if( sysClusterHandler != NULL ) {
			delete sysClusterHandler;
			sysClusterHandler = NULL;
		}
		if( tSecGroupHandler != NULL ) {
			delete tSecGroupHandler;
			tSecGroupHandler = NULL;
		}
		if( tSecGrpIncHandler != NULL ) {
			delete tSecGrpIncHandler;
			tSecGrpIncHandler = NULL;
		}
		if( tSecGrpMembHandler != NULL ) {
			delete tSecGrpMembHandler;
			tSecGrpMembHandler = NULL;
		}
		if( tenantHandler != NULL ) {
			delete tenantHandler;
			tenantHandler = NULL;
		}
		if( tldHandler != NULL ) {
			delete tldHandler;
			tldHandler = NULL;
		}
		if( topDomainHandler != NULL ) {
			delete topDomainHandler;
			topDomainHandler = NULL;
		}
		if( topProjectHandler != NULL ) {
			delete topProjectHandler;
			topProjectHandler = NULL;
		}
		if( uRLProtocolHandler != NULL ) {
			delete uRLProtocolHandler;
			uRLProtocolHandler = NULL;
		}
		if( saxDocHandler != NULL ) {
			delete saxDocHandler;
			saxDocHandler = NULL;
		}
		if( saxRootHandler != NULL ) {
			delete saxRootHandler;
			saxRootHandler = NULL;
		}
	}

	void CFIntSaxLoader::initParser() {
		if( saxXmlReader != NULL ) {
			return;
		}
		cflib::CFLibXmlCoreSaxParser::initParser();
		loadGrammar( cfsec::CFSecSaxLoader::SCHEMA_URI );
		loadGrammar( SCHEMA_URI );
	}

	cfsec::ICFSecClusterObj* CFIntSaxLoader::getUseCluster() const {
		return( useCluster );
	}

	void CFIntSaxLoader::setUseCluster( cfsec::ICFSecClusterObj* value ) {
		useCluster = value;
	}

	cfsec::ICFSecTenantObj* CFIntSaxLoader::getUseTenant() {
		return( useTenant );
	}

	void CFIntSaxLoader::setUseTenant( cfsec::ICFSecTenantObj* value ) {
		useTenant = value;
	}

	// SchemaObj accessors

	cfint::ICFIntSchemaObj* CFIntSaxLoader::getSchemaObj() const {
		return( schemaObj );
	}

	void CFIntSaxLoader::setSchemaObj( cfint::ICFIntSchemaObj* value ) {
		schemaObj = value;
	}

	void CFIntSaxLoader::verifyGrammarInstallation() {
		static const std::string S_ProcName( "verifyGrammarInstallation" );
		static const std::string S_MsgMustInstallXsdFirst( "The XSD file " + SCHEMA_URI + " must be installed first" );
		if( grammarLoaded ) {
			return;
		}
		cfsec::CFSecSaxLoader::verifyGrammarInstallation();
		std::ifstream xsdfile( SCHEMA_URI.data() );
		if( ! xsdfile ) {
			throw cflib::CFLibUsageException( CLASS_NAME,
				S_ProcName,
				S_MsgMustInstallXsdFirst );
		}
		grammarLoaded = true;
	}

	cfint::CFIntSaxLoaderClusterHandler* CFIntSaxLoader::getClusterHandler() {
		if( clusterHandler == NULL ) {
			clusterHandler = new cfint::CFIntSaxLoaderClusterHandler( this );
			clusterHandler->addElementHandler( cfsec::CFSecHostNodeBuff::GENDEFNAME, getHostNodeHandler() );
			clusterHandler->addElementHandler( cfsec::CFSecTenantBuff::GENDEFNAME, getTenantHandler() );
			clusterHandler->addElementHandler( cfsec::CFSecSecAppBuff::GENDEFNAME, getSecAppHandler() );
			clusterHandler->addElementHandler( cfsec::CFSecSecGroupBuff::GENDEFNAME, getSecGroupHandler() );
			clusterHandler->addElementHandler( cfsec::CFSecSysClusterBuff::GENDEFNAME, getSysClusterHandler() );
		}
		return( clusterHandler );
	}

	cfint::CFIntSaxLoaderHostNodeHandler* CFIntSaxLoader::getHostNodeHandler() {
		if( hostNodeHandler == NULL ) {
			hostNodeHandler = new cfint::CFIntSaxLoaderHostNodeHandler( this );
			hostNodeHandler->addElementHandler( cfsec::CFSecServiceBuff::GENDEFNAME, getServiceHandler() );
		}
		return( hostNodeHandler );
	}

	cfint::CFIntSaxLoaderISOCcyHandler* CFIntSaxLoader::getISOCcyHandler() {
		if( iSOCcyHandler == NULL ) {
			iSOCcyHandler = new cfint::CFIntSaxLoaderISOCcyHandler( this );
		}
		return( iSOCcyHandler );
	}

	cfint::CFIntSaxLoaderISOCtryHandler* CFIntSaxLoader::getISOCtryHandler() {
		if( iSOCtryHandler == NULL ) {
			iSOCtryHandler = new cfint::CFIntSaxLoaderISOCtryHandler( this );
			iSOCtryHandler->addElementHandler( cfsec::CFSecISOCtryCcyBuff::GENDEFNAME, getISOCtryCcyHandler() );
			iSOCtryHandler->addElementHandler( cfsec::CFSecISOCtryLangBuff::GENDEFNAME, getISOCtryLangHandler() );
		}
		return( iSOCtryHandler );
	}

	cfint::CFIntSaxLoaderISOCtryCcyHandler* CFIntSaxLoader::getISOCtryCcyHandler() {
		if( iSOCtryCcyHandler == NULL ) {
			iSOCtryCcyHandler = new cfint::CFIntSaxLoaderISOCtryCcyHandler( this );
		}
		return( iSOCtryCcyHandler );
	}

	cfint::CFIntSaxLoaderISOCtryLangHandler* CFIntSaxLoader::getISOCtryLangHandler() {
		if( iSOCtryLangHandler == NULL ) {
			iSOCtryLangHandler = new cfint::CFIntSaxLoaderISOCtryLangHandler( this );
		}
		return( iSOCtryLangHandler );
	}

	cfint::CFIntSaxLoaderISOLangHandler* CFIntSaxLoader::getISOLangHandler() {
		if( iSOLangHandler == NULL ) {
			iSOLangHandler = new cfint::CFIntSaxLoaderISOLangHandler( this );
		}
		return( iSOLangHandler );
	}

	cfint::CFIntSaxLoaderISOTZoneHandler* CFIntSaxLoader::getISOTZoneHandler() {
		if( iSOTZoneHandler == NULL ) {
			iSOTZoneHandler = new cfint::CFIntSaxLoaderISOTZoneHandler( this );
		}
		return( iSOTZoneHandler );
	}

	cfint::CFIntSaxLoaderLicenseHandler* CFIntSaxLoader::getLicenseHandler() {
		if( licenseHandler == NULL ) {
			licenseHandler = new cfint::CFIntSaxLoaderLicenseHandler( this );
		}
		return( licenseHandler );
	}

	cfint::CFIntSaxLoaderMajorVersionHandler* CFIntSaxLoader::getMajorVersionHandler() {
		if( majorVersionHandler == NULL ) {
			majorVersionHandler = new cfint::CFIntSaxLoaderMajorVersionHandler( this );
			majorVersionHandler->addElementHandler( cfint::CFIntMinorVersionBuff::GENDEFNAME, getMinorVersionHandler() );
		}
		return( majorVersionHandler );
	}

	cfint::CFIntSaxLoaderMimeTypeHandler* CFIntSaxLoader::getMimeTypeHandler() {
		if( mimeTypeHandler == NULL ) {
			mimeTypeHandler = new cfint::CFIntSaxLoaderMimeTypeHandler( this );
		}
		return( mimeTypeHandler );
	}

	cfint::CFIntSaxLoaderMinorVersionHandler* CFIntSaxLoader::getMinorVersionHandler() {
		if( minorVersionHandler == NULL ) {
			minorVersionHandler = new cfint::CFIntSaxLoaderMinorVersionHandler( this );
		}
		return( minorVersionHandler );
	}

	cfint::CFIntSaxLoaderSecAppHandler* CFIntSaxLoader::getSecAppHandler() {
		if( secAppHandler == NULL ) {
			secAppHandler = new cfint::CFIntSaxLoaderSecAppHandler( this );
			secAppHandler->addElementHandler( cfsec::CFSecSecFormBuff::GENDEFNAME, getSecFormHandler() );
		}
		return( secAppHandler );
	}

	cfint::CFIntSaxLoaderSecDeviceHandler* CFIntSaxLoader::getSecDeviceHandler() {
		if( secDeviceHandler == NULL ) {
			secDeviceHandler = new cfint::CFIntSaxLoaderSecDeviceHandler( this );
		}
		return( secDeviceHandler );
	}

	cfint::CFIntSaxLoaderSecFormHandler* CFIntSaxLoader::getSecFormHandler() {
		if( secFormHandler == NULL ) {
			secFormHandler = new cfint::CFIntSaxLoaderSecFormHandler( this );
		}
		return( secFormHandler );
	}

	cfint::CFIntSaxLoaderSecGroupHandler* CFIntSaxLoader::getSecGroupHandler() {
		if( secGroupHandler == NULL ) {
			secGroupHandler = new cfint::CFIntSaxLoaderSecGroupHandler( this );
			secGroupHandler->addElementHandler( cfsec::CFSecSecGrpIncBuff::GENDEFNAME, getSecGrpIncHandler() );
			secGroupHandler->addElementHandler( cfsec::CFSecSecGrpMembBuff::GENDEFNAME, getSecGrpMembHandler() );
			secGroupHandler->addElementHandler( cfsec::CFSecSecGroupFormBuff::GENDEFNAME, getSecGroupFormHandler() );
		}
		return( secGroupHandler );
	}

	cfint::CFIntSaxLoaderSecGroupFormHandler* CFIntSaxLoader::getSecGroupFormHandler() {
		if( secGroupFormHandler == NULL ) {
			secGroupFormHandler = new cfint::CFIntSaxLoaderSecGroupFormHandler( this );
		}
		return( secGroupFormHandler );
	}

	cfint::CFIntSaxLoaderSecGrpIncHandler* CFIntSaxLoader::getSecGrpIncHandler() {
		if( secGrpIncHandler == NULL ) {
			secGrpIncHandler = new cfint::CFIntSaxLoaderSecGrpIncHandler( this );
		}
		return( secGrpIncHandler );
	}

	cfint::CFIntSaxLoaderSecGrpMembHandler* CFIntSaxLoader::getSecGrpMembHandler() {
		if( secGrpMembHandler == NULL ) {
			secGrpMembHandler = new cfint::CFIntSaxLoaderSecGrpMembHandler( this );
		}
		return( secGrpMembHandler );
	}

	cfint::CFIntSaxLoaderSecSessionHandler* CFIntSaxLoader::getSecSessionHandler() {
		if( secSessionHandler == NULL ) {
			secSessionHandler = new cfint::CFIntSaxLoaderSecSessionHandler( this );
		}
		return( secSessionHandler );
	}

	cfint::CFIntSaxLoaderSecUserHandler* CFIntSaxLoader::getSecUserHandler() {
		if( secUserHandler == NULL ) {
			secUserHandler = new cfint::CFIntSaxLoaderSecUserHandler( this );
			secUserHandler->addElementHandler( cfsec::CFSecSecDeviceBuff::GENDEFNAME, getSecDeviceHandler() );
			secUserHandler->addElementHandler( cfsec::CFSecSecSessionBuff::GENDEFNAME, getSecSessionHandler() );
		}
		return( secUserHandler );
	}

	cfint::CFIntSaxLoaderServiceHandler* CFIntSaxLoader::getServiceHandler() {
		if( serviceHandler == NULL ) {
			serviceHandler = new cfint::CFIntSaxLoaderServiceHandler( this );
		}
		return( serviceHandler );
	}

	cfint::CFIntSaxLoaderServiceTypeHandler* CFIntSaxLoader::getServiceTypeHandler() {
		if( serviceTypeHandler == NULL ) {
			serviceTypeHandler = new cfint::CFIntSaxLoaderServiceTypeHandler( this );
		}
		return( serviceTypeHandler );
	}

	cfint::CFIntSaxLoaderSubProjectHandler* CFIntSaxLoader::getSubProjectHandler() {
		if( subProjectHandler == NULL ) {
			subProjectHandler = new cfint::CFIntSaxLoaderSubProjectHandler( this );
			subProjectHandler->addElementHandler( cfint::CFIntMajorVersionBuff::GENDEFNAME, getMajorVersionHandler() );
		}
		return( subProjectHandler );
	}

	cfint::CFIntSaxLoaderSysClusterHandler* CFIntSaxLoader::getSysClusterHandler() {
		if( sysClusterHandler == NULL ) {
			sysClusterHandler = new cfint::CFIntSaxLoaderSysClusterHandler( this );
		}
		return( sysClusterHandler );
	}

	cfint::CFIntSaxLoaderTSecGroupHandler* CFIntSaxLoader::getTSecGroupHandler() {
		if( tSecGroupHandler == NULL ) {
			tSecGroupHandler = new cfint::CFIntSaxLoaderTSecGroupHandler( this );
			tSecGroupHandler->addElementHandler( cfsec::CFSecTSecGrpIncBuff::GENDEFNAME, getTSecGrpIncHandler() );
			tSecGroupHandler->addElementHandler( cfsec::CFSecTSecGrpMembBuff::GENDEFNAME, getTSecGrpMembHandler() );
		}
		return( tSecGroupHandler );
	}

	cfint::CFIntSaxLoaderTSecGrpIncHandler* CFIntSaxLoader::getTSecGrpIncHandler() {
		if( tSecGrpIncHandler == NULL ) {
			tSecGrpIncHandler = new cfint::CFIntSaxLoaderTSecGrpIncHandler( this );
		}
		return( tSecGrpIncHandler );
	}

	cfint::CFIntSaxLoaderTSecGrpMembHandler* CFIntSaxLoader::getTSecGrpMembHandler() {
		if( tSecGrpMembHandler == NULL ) {
			tSecGrpMembHandler = new cfint::CFIntSaxLoaderTSecGrpMembHandler( this );
		}
		return( tSecGrpMembHandler );
	}

	cfint::CFIntSaxLoaderTenantHandler* CFIntSaxLoader::getTenantHandler() {
		if( tenantHandler == NULL ) {
			tenantHandler = new cfint::CFIntSaxLoaderTenantHandler( this );
			tenantHandler->addElementHandler( cfsec::CFSecTSecGroupBuff::GENDEFNAME, getTSecGroupHandler() );
			tenantHandler->addElementHandler( cfint::CFIntTldBuff::GENDEFNAME, getTldHandler() );
		}
		return( tenantHandler );
	}

	cfint::CFIntSaxLoaderTldHandler* CFIntSaxLoader::getTldHandler() {
		if( tldHandler == NULL ) {
			tldHandler = new cfint::CFIntSaxLoaderTldHandler( this );
			tldHandler->addElementHandler( cfint::CFIntTopDomainBuff::GENDEFNAME, getTopDomainHandler() );
		}
		return( tldHandler );
	}

	cfint::CFIntSaxLoaderTopDomainHandler* CFIntSaxLoader::getTopDomainHandler() {
		if( topDomainHandler == NULL ) {
			topDomainHandler = new cfint::CFIntSaxLoaderTopDomainHandler( this );
			topDomainHandler->addElementHandler( cfint::CFIntLicenseBuff::GENDEFNAME, getLicenseHandler() );
			topDomainHandler->addElementHandler( cfint::CFIntTopProjectBuff::GENDEFNAME, getTopProjectHandler() );
		}
		return( topDomainHandler );
	}

	cfint::CFIntSaxLoaderTopProjectHandler* CFIntSaxLoader::getTopProjectHandler() {
		if( topProjectHandler == NULL ) {
			topProjectHandler = new cfint::CFIntSaxLoaderTopProjectHandler( this );
			topProjectHandler->addElementHandler( cfint::CFIntSubProjectBuff::GENDEFNAME, getSubProjectHandler() );
		}
		return( topProjectHandler );
	}

	cfint::CFIntSaxLoaderURLProtocolHandler* CFIntSaxLoader::getURLProtocolHandler() {
		if( uRLProtocolHandler == NULL ) {
			uRLProtocolHandler = new cfint::CFIntSaxLoaderURLProtocolHandler( this );
		}
		return( uRLProtocolHandler );
	}

	cfint::CFIntSaxRootHandler* CFIntSaxLoader::getSaxRootHandler() {
		const static std::string S_SchemaName( "CFInt" );
		const static std::string S_CFSec( "CFSec" );
		if( saxRootHandler == NULL ) {
			saxRootHandler = new cfint::CFIntSaxRootHandler( this );
			saxRootHandler->addElementHandler( S_SchemaName, getSaxDocHandler() );
			saxRootHandler->addElementHandler( S_CFSec, getSaxDocHandler() );
		}
		return( saxRootHandler );
	}

	cfint::CFIntSaxDocHandler* CFIntSaxLoader::getSaxDocHandler() {
		if( saxDocHandler == NULL ) {
			saxDocHandler = new CFIntSaxDocHandler( this );
			saxDocHandler->addElementHandler( cfsec::CFSecClusterBuff::GENDEFNAME, getClusterHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecISOCcyBuff::GENDEFNAME, getISOCcyHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecISOCtryBuff::GENDEFNAME, getISOCtryHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecISOLangBuff::GENDEFNAME, getISOLangHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecISOTZoneBuff::GENDEFNAME, getISOTZoneHandler() );
			saxDocHandler->addElementHandler( cfint::CFIntMimeTypeBuff::GENDEFNAME, getMimeTypeHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecSecUserBuff::GENDEFNAME, getSecUserHandler() );
			saxDocHandler->addElementHandler( cfsec::CFSecServiceTypeBuff::GENDEFNAME, getServiceTypeHandler() );
			saxDocHandler->addElementHandler( cfint::CFIntURLProtocolBuff::GENDEFNAME, getURLProtocolHandler() );
		}
		return( saxDocHandler );
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getClusterLoaderBehaviour() const {
		return( clusterLoaderBehaviour );
	}

	void CFIntSaxLoader::setClusterLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		clusterLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getHostNodeLoaderBehaviour() const {
		return( hostNodeLoaderBehaviour );
	}

	void CFIntSaxLoader::setHostNodeLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		hostNodeLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getISOCcyLoaderBehaviour() const {
		return( iSOCcyLoaderBehaviour );
	}

	void CFIntSaxLoader::setISOCcyLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		iSOCcyLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getISOCtryLoaderBehaviour() const {
		return( iSOCtryLoaderBehaviour );
	}

	void CFIntSaxLoader::setISOCtryLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		iSOCtryLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getISOCtryCcyLoaderBehaviour() const {
		return( iSOCtryCcyLoaderBehaviour );
	}

	void CFIntSaxLoader::setISOCtryCcyLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		iSOCtryCcyLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getISOCtryLangLoaderBehaviour() const {
		return( iSOCtryLangLoaderBehaviour );
	}

	void CFIntSaxLoader::setISOCtryLangLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		iSOCtryLangLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getISOLangLoaderBehaviour() const {
		return( iSOLangLoaderBehaviour );
	}

	void CFIntSaxLoader::setISOLangLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		iSOLangLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getISOTZoneLoaderBehaviour() const {
		return( iSOTZoneLoaderBehaviour );
	}

	void CFIntSaxLoader::setISOTZoneLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		iSOTZoneLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getLicenseLoaderBehaviour() const {
		return( licenseLoaderBehaviour );
	}

	void CFIntSaxLoader::setLicenseLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		licenseLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getMajorVersionLoaderBehaviour() const {
		return( majorVersionLoaderBehaviour );
	}

	void CFIntSaxLoader::setMajorVersionLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		majorVersionLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getMimeTypeLoaderBehaviour() const {
		return( mimeTypeLoaderBehaviour );
	}

	void CFIntSaxLoader::setMimeTypeLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		mimeTypeLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getMinorVersionLoaderBehaviour() const {
		return( minorVersionLoaderBehaviour );
	}

	void CFIntSaxLoader::setMinorVersionLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		minorVersionLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getSecAppLoaderBehaviour() const {
		return( secAppLoaderBehaviour );
	}

	void CFIntSaxLoader::setSecAppLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		secAppLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getSecDeviceLoaderBehaviour() const {
		return( secDeviceLoaderBehaviour );
	}

	void CFIntSaxLoader::setSecDeviceLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		secDeviceLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getSecFormLoaderBehaviour() const {
		return( secFormLoaderBehaviour );
	}

	void CFIntSaxLoader::setSecFormLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		secFormLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getSecGroupLoaderBehaviour() const {
		return( secGroupLoaderBehaviour );
	}

	void CFIntSaxLoader::setSecGroupLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		secGroupLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getSecGroupFormLoaderBehaviour() const {
		return( secGroupFormLoaderBehaviour );
	}

	void CFIntSaxLoader::setSecGroupFormLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		secGroupFormLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getSecGrpIncLoaderBehaviour() const {
		return( secGrpIncLoaderBehaviour );
	}

	void CFIntSaxLoader::setSecGrpIncLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		secGrpIncLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getSecGrpMembLoaderBehaviour() const {
		return( secGrpMembLoaderBehaviour );
	}

	void CFIntSaxLoader::setSecGrpMembLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		secGrpMembLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getSecSessionLoaderBehaviour() const {
		return( secSessionLoaderBehaviour );
	}

	void CFIntSaxLoader::setSecSessionLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		secSessionLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getSecUserLoaderBehaviour() const {
		return( secUserLoaderBehaviour );
	}

	void CFIntSaxLoader::setSecUserLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		secUserLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getServiceLoaderBehaviour() const {
		return( serviceLoaderBehaviour );
	}

	void CFIntSaxLoader::setServiceLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		serviceLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getServiceTypeLoaderBehaviour() const {
		return( serviceTypeLoaderBehaviour );
	}

	void CFIntSaxLoader::setServiceTypeLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		serviceTypeLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getSubProjectLoaderBehaviour() const {
		return( subProjectLoaderBehaviour );
	}

	void CFIntSaxLoader::setSubProjectLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		subProjectLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getSysClusterLoaderBehaviour() const {
		return( sysClusterLoaderBehaviour );
	}

	void CFIntSaxLoader::setSysClusterLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		sysClusterLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getTSecGroupLoaderBehaviour() const {
		return( tSecGroupLoaderBehaviour );
	}

	void CFIntSaxLoader::setTSecGroupLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		tSecGroupLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getTSecGrpIncLoaderBehaviour() const {
		return( tSecGrpIncLoaderBehaviour );
	}

	void CFIntSaxLoader::setTSecGrpIncLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		tSecGrpIncLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getTSecGrpMembLoaderBehaviour() const {
		return( tSecGrpMembLoaderBehaviour );
	}

	void CFIntSaxLoader::setTSecGrpMembLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		tSecGrpMembLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getTenantLoaderBehaviour() const {
		return( tenantLoaderBehaviour );
	}

	void CFIntSaxLoader::setTenantLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		tenantLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getTldLoaderBehaviour() const {
		return( tldLoaderBehaviour );
	}

	void CFIntSaxLoader::setTldLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		tldLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getTopDomainLoaderBehaviour() const {
		return( topDomainLoaderBehaviour );
	}

	void CFIntSaxLoader::setTopDomainLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		topDomainLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getTopProjectLoaderBehaviour() const {
		return( topProjectLoaderBehaviour );
	}

	void CFIntSaxLoader::setTopProjectLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		topProjectLoaderBehaviour = value;
	}

	const cfint::CFIntSaxLoader::LoaderBehaviourEnum CFIntSaxLoader::getURLProtocolLoaderBehaviour() const {
		return( uRLProtocolLoaderBehaviour );
	}

	void CFIntSaxLoader::setURLProtocolLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value ) {
		uRLProtocolLoaderBehaviour = value;
	}

	void CFIntSaxLoader::parseFile( const std::string& url ) {
		parse( url.data() );
	}

}
