AM_CPPFLAGS = -I$(top_srcdir)

h_sources = omnia.h

c_sources = trig.c rounding.c gcdlcm.c kiss.c logtools.c statistics.c sinusoid.c

lib_LTLIBRARIES = libomnia.la

libomnia_la_SOURCES = $(h_sources) $(c_sources)
libomnia_la_LDFLAGS= -version-info $(GENERIC_LIBRARY_VERSION) -release $(GENERIC_RELEASE)

library_includedir=$(includedir)/$(GENERIC_LIBRARY_NAME)
library_include_HEADERS = $(h_sources)

AM_CFLAGS = -O3 -std=gnu99 -pedantic -Wall -Wno-format -mtune=native
DEFS = -I. -I$(srcdir)
