bin_PROGRAMS = omnia_test_kiss omnia_test_trig omnia_test_rounding omnia_test_gcflcm

omnia_test_kiss_SOURCES = omnia_test_kiss.c
omnia_test_trig_SOURCES = omnia_test_trig.c
omnia_test_rounding_SOURCES = omnia_test_rounding.c
omnia_test_gcflcm_SOURCES = omnia_test_gcflcm.c

LIBS = -L../src -lomnia -lm -lrt
AM_CFLAGS = -O3 -std=gnu99 -pedantic -Wall -Wno-format -mtune=native
