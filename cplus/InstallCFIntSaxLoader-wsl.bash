#!/bin/bash
#
#	org.msscf.msscf.CFInt
#
#	Copyright (c) 2020 Mark Stephen Sobkow
#	
#	This file is part of MSS Code Factory.
#	
#	Licensed under the Apache License, Version 2.0 (the "License");
#	you may not use this file except in compliance with the License.
#	You may obtain a copy of the License at
#	
#	    http://www.apache.org/licenses/LICENSE-2.0
#	
#	Unless required by applicable law or agreed to in writing, software
#	distributed under the License is distributed on an "AS IS" BASIS,
#	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#	See the License for the specific language governing permissions and
#	limitations under the License.
#	
#	Donations to support MSS Code Factory can be made at
#	https://www.paypal.com/paypalme2/MarkSobkow
#
#	Manufactured by MSS Code Factory 2.12
#
MAJOR_VERSION=2
MINOR_VERSION=13
pushd libcfintsaxloader
	sudo make install
	sudo chmod 755 /usr/include/msscf
	sudo chmod 755 /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}
	sudo chmod 755 /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintsaxloader
	sudo sh -c "cd /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintsaxloader && chmod 644 *.hpp"
	#sudo chmod 755 /usr/bin/*cfint*saxloader
	sudo chmod 755 /usr/lib/*cfintsaxloader.la
	sudo chmod 755 /usr/lib/*cfintsaxloader.so*
	sudo chmod 755 /usr/share/msscf
	sudo chmod 755 /usr/share/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}
	sudo chmod 755 /usr/share/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/xsd
	sudo chmod 644 /usr/share/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/xsd/*cfint*.xsd
	sudo ldconfig
popd
