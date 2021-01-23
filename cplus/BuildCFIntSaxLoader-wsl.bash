#!/bin/bash
#
#	org.msscf.msscf.CFInt
#
#	Copyright (c) 2020 Mark Stephen Sobkow
#	
#	MSS Code Factory CFInt 2.13 Internet Essentials
#	
#	Copyright 2020-2021 Mark Stephen Sobkow
#	
#		This file is part of MSS Code Factory.
#	
#		MSS Code Factory is available under dual commercial license from Mark Stephen
#		Sobkow, or under the terms of the GNU General Public License, Version 3
#		or later.
#	
#	    MSS Code Factory is free software: you can redistribute it and/or modify
#	    it under the terms of the GNU General Public License as published by
#	    the Free Software Foundation, either version 3 of the License, or
#	    (at your option) any later version.
#	
#	    MSS Code Factory is distributed in the hope that it will be useful,
#	    but WITHOUT ANY WARRANTY; without even the implied warranty of
#	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	    GNU General Public License for more details.
#	
#	    You should have received a copy of the GNU General Public License
#	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
#	
#	Donations to support MSS Code Factory can be made at
#	https://www.paypal.com/paypalme2/MarkSobkow
#	
#	Please contact Mark Stephen Sobkow at mark.sobkow@gmail.com for commercial licensing.
#
#	Manufactured by MSS Code Factory 2.12
#
Revision=$1
MAJOR_VERSION=2
MINOR_VERSION=13
rm -f libcfintsaxloader*.gz *.deb *.build *.dsc *.log *.changes ex.cmd
pushd libcfintsaxloader
	if [ -f Makefile ]; then
		make distclean
	fi
popd
pushd libcfintsaxloader
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
	if [ ! -d /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintsaxloader ]; then
		sudo mkdir /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintsaxloader
	fi
	sudo chmod 755 /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintsaxloader
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
	sudo chmod 755 /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintsaxloader
	sudo sh -c "cd /usr/include/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/cfintsaxloader && chmod 644 *.hpp"
	#sudo chmod 755 /usr/bin/*cfint*saxloader
	sudo chmod 755 /usr/lib/*cfintsaxloader.la
	sudo chmod 755 /usr/lib/*cfintsaxloader.so*
	sudo chmod 755 /opt/msscf
	sudo chmod 755 /opt/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}
	sudo chmod 755 /opt/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/xsd
	sudo chmod 644 /opt/msscf/${MAJOR_VERSION}.0.${MINOR_VERSION}/xsd/*cfint*.xsd
	sudo ldconfig
popd
