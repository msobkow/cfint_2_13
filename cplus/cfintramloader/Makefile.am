MAJOR_VERSION=2

MINOR_VERSION=13

BUILD_NUMBER=11192

RELEASE=$(MAJOR_VERSION).$(MINOR_VERSION).$(BUILD_NUMBER)

SUB_RELEASE=$(MAJOR_VERSION).$(MINOR_VERSION)

MAIN_RELEASE=$(MAJOR_VERSION)

DEPDIR=debug

LT_OBJDIR=.libs

BIN=$(prefix)/bin/msscf/$(MAJOR_VERSION).0.$(MINOR_VERSION)

bindir=$(prefix)/bin/msscf/$(MAJOR_VERSION).0.$(MINOR_VERSION)

bin_PROGRAMS = cfintramloader

cfintramloader_SOURCES = cfintramloader.cpp CFIntRamLdr.cpp

cfintramloader_LDFLAGS= -lmpfr -lxerces-c -luuid -l:libcflib.so.$(MAJOR_VERSION).0.$(MINOR_VERSION) -l:libcfint.so.$(MAJOR_VERSION).0.$(MINOR_VERSION) -l:libcfintsaxloader.so.$(MAJOR_VERSION).0.$(MINOR_VERSION) -l:libcfsec.so.$(MAJOR_VERSION).0.$(MINOR_VERSION) -l:libcfsecsaxloader.so.$(MAJOR_VERSION).0.$(MINOR_VERSION) -l:libcfintram.so.$(MAJOR_VERSION).0.$(MINOR_VERSION) -lstdc++fs

cfintramloader_CXXFLAGS= -I$(top_srcdir) -I$(prefix)/include/msscf/$(MAJOR_VERSION).0.$(MINOR_VERSION) -I$(prefix)/include/msscf/$(MAJOR_VERSION).0.$(MINOR_VERSION)

ACLOCAL_AMFLAGS= -Im4
