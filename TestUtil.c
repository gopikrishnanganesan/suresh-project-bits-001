#include "TestUtil.h"
#include <stdio.h>

void success( const char* apTestName,
              const char* apAPIName,
              const char* apMessage ) {
    printf( "==>[PASSED] Test: %s API: %s Desc: %s\n", apTestName, apAPIName,
            apMessage );
}

void failure( const char* apTestName,
              const char* apAPIName,
              const char* apMessage ) {
    printf( "==>[FAILED] Test: %s API: %s Desc: %s\n", apTestName, apAPIName,
            apMessage );
}

