#!/bin/bash
Revision=$1
if [ "$Revision" == "" ]; then
	echo "ERROR: Revision (argument 1) not specified" 1>&2
else
	export Revision
	cd $MSSCFHOME/cfint_2_13/cplus
	if [ ! -d ../installer ]; then
		mkdir ../installer
	fi
	chmod 755 ../installer
	ZipFile="../installer/cfint_2_13_${Revision}-wsl-debug-installer.zip"
	export ZipFile
	rm -f ${ZipFile}
	rm -Rf cfint-2.13.${Revision}-wsl
	mkdir cfint-2.13.${Revision}-wsl
	chmod 755 cfint-2.13.${Revision}-wsl
	echo "Preparing cfint-2.13.${Revision}-wsl ..."
	pushd cfint-2.13.${Revision}-wsl
		cp ../Apache-V2.txt ../LICENSE .
		git log 2>&1 >ChangeLog
		mkdir bin
		chmod 755 bin
		mkdir bin/msobkow
		chmod 755 bin/msobkow
		mkdir bin/msobkow/2.0.13
		chmod 755 bin/msobkow/2.0.13
		cp ../Apache-V2.txt ../LICENSE bin/msobkow/2.0.13
		chmod 644 bin/msobkow/2.0.13/*
		cp /usr/bin/msobkow/2.0.13/cfint* bin/msobkow/2.0.13
		chmod 755 bin/msobkow/2.0.13/cfint*
		mkdir lib
		chmod 755 lib
		cp /usr/lib/libcfint.la /usr/lib/libcfint.so.2.0.13 lib
		cp /usr/lib/libcfintsaxloader.la /usr/lib/libcfintsaxloader.so.2.0.13 lib
		cp /usr/lib/libcfintram.la /usr/lib/libcfintram.so.2.0.13 lib
		chmod 755 lib/*.so.*
		chmod 644 lib/*.la
		strip bin/msobkow/2.0.13/*cf* lib/*.so.*
		mkdir include
		chmod 755 include
		mkdir include/msobkow
		chmod 755 include/msobkow
		mkdir include/msobkow/2.0.13
		chmod 755 include/msobkow/2.0.13
		cp ../Apache-V2.txt ../LICENSE include/msobkow/2.0.13
		chmod 644 include/msobkow/2.0.13/*
		mkdir include/msobkow/2.0.13/cfint
		chmod 755 include/msobkow/2.0.13/cfint
		cp /usr/include/msobkow/2.0.13/cfint/*.hpp include/msobkow/2.0.13/cfint
		chmod 644 include/msobkow/2.0.13/cfint*/*.hpp
		mkdir include/msobkow/2.0.13/cfintsaxloader
		chmod 755 include/msobkow/2.0.13/cfintsaxloader
		cp /usr/include/msobkow/2.0.13/cfintsaxloader/*.hpp include/msobkow/2.0.13/cfintsaxloader
		chmod 644 include/msobkow/2.0.13/cfintsaxloader*/*.hpp
		mkdir include/msobkow/2.0.13/cfintram
		chmod 755 include/msobkow/2.0.13/cfintram
		cp /usr/include/msobkow/2.0.13/cfintram/*.hpp include/msobkow/2.0.13/cfintram
		chmod 644 include/msobkow/2.0.13/cfintram*/*.hpp
		mkdir share
		chmod 755 share
		mkdir share/msobkow
		chmod 755 share/msobkow
		mkdir share/msobkow/2.0.13
		chmod 755 share/msobkow/2.0.13
		cp ../Apache-V2.txt ../LICENSE share/msobkow/2.0.13
		chmod 644 share/msobkow/2.0.13/*
		mkdir share/msobkow/2.0.13/xsd
		chmod 755 share/msobkow/2.0.13/xsd
		cp /usr/share/msobkow/2.0.13/xsd/cfint*.xsd share/msobkow/2.0.13/xsd
		chmod 644 share/msobkow/2.0.13/xsd/*.xsd
	popd
	echo "Packaging cfint-2.13.${Revision}-wsl ..."
	zip -q9r ${ZipFile} cfint-2.13.${Revision}-wsl
	rm -Rf cfint-2.13.${Revision}-wsl
	echo "Packaged ${ZipFile}"
	ls -l ${ZipFile}
fi
