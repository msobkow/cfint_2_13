#pragma once

// Description: C++18 XML SAX Parser specification for CFInt.

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
#include <xercesc/sax2/Attributes.hpp>

#include <cfsecsaxloader/CFSecSaxLoader.hpp>

namespace cfint {
	class ICFIntSchemaObj;
	class ICFIntClusterObj;
	class ICFIntClusterEditObj;
	class ICFIntClusterTableObj;
	class CFIntSaxLoaderClusterHandler;
	class ICFIntHostNodeObj;
	class ICFIntHostNodeEditObj;
	class ICFIntHostNodeTableObj;
	class CFIntSaxLoaderHostNodeHandler;
	class ICFIntISOCcyObj;
	class ICFIntISOCcyEditObj;
	class ICFIntISOCcyTableObj;
	class CFIntSaxLoaderISOCcyHandler;
	class ICFIntISOCtryObj;
	class ICFIntISOCtryEditObj;
	class ICFIntISOCtryTableObj;
	class CFIntSaxLoaderISOCtryHandler;
	class ICFIntISOCtryCcyObj;
	class ICFIntISOCtryCcyEditObj;
	class ICFIntISOCtryCcyTableObj;
	class CFIntSaxLoaderISOCtryCcyHandler;
	class ICFIntISOCtryLangObj;
	class ICFIntISOCtryLangEditObj;
	class ICFIntISOCtryLangTableObj;
	class CFIntSaxLoaderISOCtryLangHandler;
	class ICFIntISOLangObj;
	class ICFIntISOLangEditObj;
	class ICFIntISOLangTableObj;
	class CFIntSaxLoaderISOLangHandler;
	class ICFIntISOTZoneObj;
	class ICFIntISOTZoneEditObj;
	class ICFIntISOTZoneTableObj;
	class CFIntSaxLoaderISOTZoneHandler;
	class ICFIntLicenseObj;
	class ICFIntLicenseEditObj;
	class ICFIntLicenseTableObj;
	class CFIntSaxLoaderLicenseHandler;
	class ICFIntMajorVersionObj;
	class ICFIntMajorVersionEditObj;
	class ICFIntMajorVersionTableObj;
	class CFIntSaxLoaderMajorVersionHandler;
	class ICFIntMimeTypeObj;
	class ICFIntMimeTypeEditObj;
	class ICFIntMimeTypeTableObj;
	class CFIntSaxLoaderMimeTypeHandler;
	class ICFIntMinorVersionObj;
	class ICFIntMinorVersionEditObj;
	class ICFIntMinorVersionTableObj;
	class CFIntSaxLoaderMinorVersionHandler;
	class ICFIntSecAppObj;
	class ICFIntSecAppEditObj;
	class ICFIntSecAppTableObj;
	class CFIntSaxLoaderSecAppHandler;
	class ICFIntSecDeviceObj;
	class ICFIntSecDeviceEditObj;
	class ICFIntSecDeviceTableObj;
	class CFIntSaxLoaderSecDeviceHandler;
	class ICFIntSecFormObj;
	class ICFIntSecFormEditObj;
	class ICFIntSecFormTableObj;
	class CFIntSaxLoaderSecFormHandler;
	class ICFIntSecGroupObj;
	class ICFIntSecGroupEditObj;
	class ICFIntSecGroupTableObj;
	class CFIntSaxLoaderSecGroupHandler;
	class ICFIntSecGroupFormObj;
	class ICFIntSecGroupFormEditObj;
	class ICFIntSecGroupFormTableObj;
	class CFIntSaxLoaderSecGroupFormHandler;
	class ICFIntSecGrpIncObj;
	class ICFIntSecGrpIncEditObj;
	class ICFIntSecGrpIncTableObj;
	class CFIntSaxLoaderSecGrpIncHandler;
	class ICFIntSecGrpMembObj;
	class ICFIntSecGrpMembEditObj;
	class ICFIntSecGrpMembTableObj;
	class CFIntSaxLoaderSecGrpMembHandler;
	class ICFIntSecSessionObj;
	class ICFIntSecSessionEditObj;
	class ICFIntSecSessionTableObj;
	class CFIntSaxLoaderSecSessionHandler;
	class ICFIntSecUserObj;
	class ICFIntSecUserEditObj;
	class ICFIntSecUserTableObj;
	class CFIntSaxLoaderSecUserHandler;
	class ICFIntServiceObj;
	class ICFIntServiceEditObj;
	class ICFIntServiceTableObj;
	class CFIntSaxLoaderServiceHandler;
	class ICFIntServiceTypeObj;
	class ICFIntServiceTypeEditObj;
	class ICFIntServiceTypeTableObj;
	class CFIntSaxLoaderServiceTypeHandler;
	class ICFIntSubProjectObj;
	class ICFIntSubProjectEditObj;
	class ICFIntSubProjectTableObj;
	class CFIntSaxLoaderSubProjectHandler;
	class ICFIntSysClusterObj;
	class ICFIntSysClusterEditObj;
	class ICFIntSysClusterTableObj;
	class CFIntSaxLoaderSysClusterHandler;
	class ICFIntTSecGroupObj;
	class ICFIntTSecGroupEditObj;
	class ICFIntTSecGroupTableObj;
	class CFIntSaxLoaderTSecGroupHandler;
	class ICFIntTSecGrpIncObj;
	class ICFIntTSecGrpIncEditObj;
	class ICFIntTSecGrpIncTableObj;
	class CFIntSaxLoaderTSecGrpIncHandler;
	class ICFIntTSecGrpMembObj;
	class ICFIntTSecGrpMembEditObj;
	class ICFIntTSecGrpMembTableObj;
	class CFIntSaxLoaderTSecGrpMembHandler;
	class ICFIntTenantObj;
	class ICFIntTenantEditObj;
	class ICFIntTenantTableObj;
	class CFIntSaxLoaderTenantHandler;
	class ICFIntTldObj;
	class ICFIntTldEditObj;
	class ICFIntTldTableObj;
	class CFIntSaxLoaderTldHandler;
	class ICFIntTopDomainObj;
	class ICFIntTopDomainEditObj;
	class ICFIntTopDomainTableObj;
	class CFIntSaxLoaderTopDomainHandler;
	class ICFIntTopProjectObj;
	class ICFIntTopProjectEditObj;
	class ICFIntTopProjectTableObj;
	class CFIntSaxLoaderTopProjectHandler;
	class ICFIntURLProtocolObj;
	class ICFIntURLProtocolEditObj;
	class ICFIntURLProtocolTableObj;
	class CFIntSaxLoaderURLProtocolHandler;
	class CFIntSaxLoader;

	class CFIntSaxRootHandler
	: public cflib::CFLibXmlCoreElementHandler
	{
	public:
		CFIntSaxRootHandler( CFIntSaxLoader* saxLoader );
		virtual ~CFIntSaxRootHandler();

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
		virtual void startElement (
			const XMLCh* const uri,
			const XMLCh* const localname,
			const XMLCh* const qname,
			const xercesc::Attributes& attrs );

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
		virtual void endElement (
			const XMLCh* const uri,
			const XMLCh* const localname,
			const XMLCh* const qname );

	};


	class CFIntSaxDocHandler
	: public cflib::CFLibXmlCoreElementHandler
	{
	public:
		CFIntSaxDocHandler( cfint::CFIntSaxLoader* saxLoader );
		virtual ~CFIntSaxDocHandler();

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
		virtual void startElement (
			const XMLCh* const uri,
			const XMLCh* const localname,
			const XMLCh* const qname,
			const xercesc::Attributes& attrs );

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
		virtual void endElement (
			const XMLCh* const uri,
			const XMLCh* const localname,
			const XMLCh* const qname );

	};

	class CFIntSaxLoader
	: public cflib::CFLibXmlCoreSaxParser
	{
	public:
		const static std::string CLASS_NAME;

		// The namespace URI of the supported schema
		const static std::string SCHEMA_XMLNS;

		// The source for loading the supported schema
		const static std::string SCHEMA_URI;

	protected:
		static bool grammarLoaded;
		cfint::ICFIntSchemaObj* schemaObj;
		cfsec::ICFSecClusterObj* useCluster;
		cfsec::ICFSecTenantObj* useTenant;

	public:
		enum LoaderBehaviourEnum {
			Insert,
			Update,
			Replace
		};

	protected:
		cfint::CFIntSaxLoader::LoaderBehaviourEnum clusterLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum hostNodeLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum iSOCcyLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum iSOCtryLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum iSOCtryCcyLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum iSOCtryLangLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum iSOLangLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum iSOTZoneLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum licenseLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum majorVersionLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum mimeTypeLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum minorVersionLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum secAppLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum secDeviceLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum secFormLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum secGroupLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum secGroupFormLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum secGrpIncLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum secGrpMembLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum secSessionLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum secUserLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum serviceLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum serviceTypeLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum subProjectLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum sysClusterLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum tSecGroupLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum tSecGrpIncLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum tSecGrpMembLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum tenantLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Insert;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum tldLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum topDomainLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum topProjectLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;
		cfint::CFIntSaxLoader::LoaderBehaviourEnum uRLProtocolLoaderBehaviour = cfint::CFIntSaxLoader::LoaderBehaviourEnum::Update;


		cfint::CFIntSaxLoaderClusterHandler* clusterHandler;
		cfint::CFIntSaxLoaderHostNodeHandler* hostNodeHandler;
		cfint::CFIntSaxLoaderISOCcyHandler* iSOCcyHandler;
		cfint::CFIntSaxLoaderISOCtryHandler* iSOCtryHandler;
		cfint::CFIntSaxLoaderISOCtryCcyHandler* iSOCtryCcyHandler;
		cfint::CFIntSaxLoaderISOCtryLangHandler* iSOCtryLangHandler;
		cfint::CFIntSaxLoaderISOLangHandler* iSOLangHandler;
		cfint::CFIntSaxLoaderISOTZoneHandler* iSOTZoneHandler;
		cfint::CFIntSaxLoaderLicenseHandler* licenseHandler;
		cfint::CFIntSaxLoaderMajorVersionHandler* majorVersionHandler;
		cfint::CFIntSaxLoaderMimeTypeHandler* mimeTypeHandler;
		cfint::CFIntSaxLoaderMinorVersionHandler* minorVersionHandler;
		cfint::CFIntSaxLoaderSecAppHandler* secAppHandler;
		cfint::CFIntSaxLoaderSecDeviceHandler* secDeviceHandler;
		cfint::CFIntSaxLoaderSecFormHandler* secFormHandler;
		cfint::CFIntSaxLoaderSecGroupHandler* secGroupHandler;
		cfint::CFIntSaxLoaderSecGroupFormHandler* secGroupFormHandler;
		cfint::CFIntSaxLoaderSecGrpIncHandler* secGrpIncHandler;
		cfint::CFIntSaxLoaderSecGrpMembHandler* secGrpMembHandler;
		cfint::CFIntSaxLoaderSecSessionHandler* secSessionHandler;
		cfint::CFIntSaxLoaderSecUserHandler* secUserHandler;
		cfint::CFIntSaxLoaderServiceHandler* serviceHandler;
		cfint::CFIntSaxLoaderServiceTypeHandler* serviceTypeHandler;
		cfint::CFIntSaxLoaderSubProjectHandler* subProjectHandler;
		cfint::CFIntSaxLoaderSysClusterHandler* sysClusterHandler;
		cfint::CFIntSaxLoaderTSecGroupHandler* tSecGroupHandler;
		cfint::CFIntSaxLoaderTSecGrpIncHandler* tSecGrpIncHandler;
		cfint::CFIntSaxLoaderTSecGrpMembHandler* tSecGrpMembHandler;
		cfint::CFIntSaxLoaderTenantHandler* tenantHandler;
		cfint::CFIntSaxLoaderTldHandler* tldHandler;
		cfint::CFIntSaxLoaderTopDomainHandler* topDomainHandler;
		cfint::CFIntSaxLoaderTopProjectHandler* topProjectHandler;
		cfint::CFIntSaxLoaderURLProtocolHandler* uRLProtocolHandler;
		cfint::CFIntSaxRootHandler* saxRootHandler;
		cfint::CFIntSaxDocHandler* saxDocHandler;
	public:

		CFIntSaxLoader();
		virtual ~CFIntSaxLoader();

		CFIntSaxLoader( cflib::ICFLibMessageLog* logger );


		virtual void initParser();


		cfsec::ICFSecClusterObj* getUseCluster() const;
		void setUseCluster( cfsec::ICFSecClusterObj* value );

		cfsec::ICFSecTenantObj* getUseTenant();
		void setUseTenant( cfsec::ICFSecTenantObj* value );


		cfint::ICFIntSchemaObj* getSchemaObj() const;
		void setSchemaObj( cfint::ICFIntSchemaObj* value );


		static void verifyGrammarInstallation();

	protected:

		cfint::CFIntSaxLoaderClusterHandler* getClusterHandler();

		cfint::CFIntSaxLoaderHostNodeHandler* getHostNodeHandler();

		cfint::CFIntSaxLoaderISOCcyHandler* getISOCcyHandler();

		cfint::CFIntSaxLoaderISOCtryHandler* getISOCtryHandler();

		cfint::CFIntSaxLoaderISOCtryCcyHandler* getISOCtryCcyHandler();

		cfint::CFIntSaxLoaderISOCtryLangHandler* getISOCtryLangHandler();

		cfint::CFIntSaxLoaderISOLangHandler* getISOLangHandler();

		cfint::CFIntSaxLoaderISOTZoneHandler* getISOTZoneHandler();

		cfint::CFIntSaxLoaderLicenseHandler* getLicenseHandler();

		cfint::CFIntSaxLoaderMajorVersionHandler* getMajorVersionHandler();

		cfint::CFIntSaxLoaderMimeTypeHandler* getMimeTypeHandler();

		cfint::CFIntSaxLoaderMinorVersionHandler* getMinorVersionHandler();

		cfint::CFIntSaxLoaderSecAppHandler* getSecAppHandler();

		cfint::CFIntSaxLoaderSecDeviceHandler* getSecDeviceHandler();

		cfint::CFIntSaxLoaderSecFormHandler* getSecFormHandler();

		cfint::CFIntSaxLoaderSecGroupHandler* getSecGroupHandler();

		cfint::CFIntSaxLoaderSecGroupFormHandler* getSecGroupFormHandler();

		cfint::CFIntSaxLoaderSecGrpIncHandler* getSecGrpIncHandler();

		cfint::CFIntSaxLoaderSecGrpMembHandler* getSecGrpMembHandler();

		cfint::CFIntSaxLoaderSecSessionHandler* getSecSessionHandler();

		cfint::CFIntSaxLoaderSecUserHandler* getSecUserHandler();

		cfint::CFIntSaxLoaderServiceHandler* getServiceHandler();

		cfint::CFIntSaxLoaderServiceTypeHandler* getServiceTypeHandler();

		cfint::CFIntSaxLoaderSubProjectHandler* getSubProjectHandler();

		cfint::CFIntSaxLoaderSysClusterHandler* getSysClusterHandler();

		cfint::CFIntSaxLoaderTSecGroupHandler* getTSecGroupHandler();

		cfint::CFIntSaxLoaderTSecGrpIncHandler* getTSecGrpIncHandler();

		cfint::CFIntSaxLoaderTSecGrpMembHandler* getTSecGrpMembHandler();

		cfint::CFIntSaxLoaderTenantHandler* getTenantHandler();

		cfint::CFIntSaxLoaderTldHandler* getTldHandler();

		cfint::CFIntSaxLoaderTopDomainHandler* getTopDomainHandler();

		cfint::CFIntSaxLoaderTopProjectHandler* getTopProjectHandler();

		cfint::CFIntSaxLoaderURLProtocolHandler* getURLProtocolHandler();


		cfint::CFIntSaxRootHandler* getSaxRootHandler();


		cfint::CFIntSaxDocHandler* getSaxDocHandler();

	public:

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getClusterLoaderBehaviour() const;
		void setClusterLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getHostNodeLoaderBehaviour() const;
		void setHostNodeLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getISOCcyLoaderBehaviour() const;
		void setISOCcyLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getISOCtryLoaderBehaviour() const;
		void setISOCtryLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getISOCtryCcyLoaderBehaviour() const;
		void setISOCtryCcyLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getISOCtryLangLoaderBehaviour() const;
		void setISOCtryLangLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getISOLangLoaderBehaviour() const;
		void setISOLangLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getISOTZoneLoaderBehaviour() const;
		void setISOTZoneLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getLicenseLoaderBehaviour() const;
		void setLicenseLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getMajorVersionLoaderBehaviour() const;
		void setMajorVersionLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getMimeTypeLoaderBehaviour() const;
		void setMimeTypeLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getMinorVersionLoaderBehaviour() const;
		void setMinorVersionLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getSecAppLoaderBehaviour() const;
		void setSecAppLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getSecDeviceLoaderBehaviour() const;
		void setSecDeviceLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getSecFormLoaderBehaviour() const;
		void setSecFormLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getSecGroupLoaderBehaviour() const;
		void setSecGroupLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getSecGroupFormLoaderBehaviour() const;
		void setSecGroupFormLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getSecGrpIncLoaderBehaviour() const;
		void setSecGrpIncLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getSecGrpMembLoaderBehaviour() const;
		void setSecGrpMembLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getSecSessionLoaderBehaviour() const;
		void setSecSessionLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getSecUserLoaderBehaviour() const;
		void setSecUserLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getServiceLoaderBehaviour() const;
		void setServiceLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getServiceTypeLoaderBehaviour() const;
		void setServiceTypeLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getSubProjectLoaderBehaviour() const;
		void setSubProjectLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getSysClusterLoaderBehaviour() const;
		void setSysClusterLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getTSecGroupLoaderBehaviour() const;
		void setTSecGroupLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getTSecGrpIncLoaderBehaviour() const;
		void setTSecGrpIncLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getTSecGrpMembLoaderBehaviour() const;
		void setTSecGrpMembLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getTenantLoaderBehaviour() const;
		void setTenantLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getTldLoaderBehaviour() const;
		void setTldLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getTopDomainLoaderBehaviour() const;
		void setTopDomainLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getTopProjectLoaderBehaviour() const;
		void setTopProjectLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );

		const cfint::CFIntSaxLoader::LoaderBehaviourEnum getURLProtocolLoaderBehaviour() const;
		void setURLProtocolLoaderBehaviour( const cfint::CFIntSaxLoader::LoaderBehaviourEnum value );


		void parseFile( const std::string& url );

	};
}
