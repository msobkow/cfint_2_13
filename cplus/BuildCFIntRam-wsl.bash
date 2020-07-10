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
Revision=$1
MAJOR_VERSION=2
MINOR_VERSION=13
rm -f libcfintram*.gz *.deb *.build *.dsc *.log *.changes ex.cmd
pushd libcfintram
	if [ -f Makefile ]; then
		make distclean
	fi
popd
pushd libcfintram
	if [ ! -d /usr/bin/msscf ]; then
		sudo mkdir /usr/include/msscf
	fi
	sudo chmod 755 /usr/bin/msscf
	if [ ! -d /usr/bin/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION} ]; then
		sudo mkdir /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}
	fi
	sudo chmod 755 /usr/bin/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}
	if [ ! -d /usr/include/msscf ]; then
		sudo mkdir /usr/include/msscf
	fi
	sudo chmod 755 /usr/include/msscf
	if [ ! -d /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION} ]; then
		sudo mkdir /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}
	fi
	sudo chmod 755 /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}
	if [ ! -d /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintram ]; then
		sudo mkdir /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintram
	fi
	sudo chmod 755 /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintram
	autoreconf -fi
	aclocal
	autoconf
	automake
	./configure --prefix=/usr --disable-static CFLAGS='-g3 -Og -D_DEBUG' CXXFLAGS='-g3 -Og -D_DEBUG -std=c++2a -I/usr/include/msscf/${MAJOR_VERSION).0.${MINOR_VERSION} -I/usr/include/msscf/${MAJOR_VERSION).0.${MINOR_VERSION} '
	#./configure --prefix=/usr --disable-static CFLAGS='-O2 -DNDEBUG' CXXFLAGS='-O2 -DNDEBUG -std=c++2a -I/usr/include/msscf/${MAJOR_VERSION).0.${MINOR_VERSION} -I/usr/include/msscf/${MAJOR_VERSION).0.${MINOR_VERSION} '
	make clean
	time make
	sudo make install
	sudo rm -Rf /usr/include/cfint*
	sudo chmod 755 /usr/include/msscf
	sudo chmod 755 /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}
	sudo chmod 755 /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintram
	sudo sh -c "cd /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintram && chmod 644 *.hpp"
	#sudo chmod 755 /usr/bin/*cfint*ram
	sudo chmod 755 /usr/lib/*cfintram.la
	sudo chmod 755 /usr/lib/*cfintram.so*
	sudo chmod 755 /opt/msscf
	sudo chmod 755 /opt/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}
	sudo ldconfig
popd
