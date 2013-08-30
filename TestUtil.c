/**
 * File     : TestUtil.c
 * Type     : Internal Test Implementation
 * Comment  : Helper utilties for test cases status printing :-)
 */
#include <stdio.h>
#include <stdlib.h>
#include "TestUtil.h"

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
    exit( -1 );
}

