#include <stdio.h>
#include <stdlib.h>
#include "Offense.h"
#include "OffenseOps.h"
#include "TestUtil.h"

#define TESTED_API  "populateDrivers"


void testCase01();
void testCase02();
void testCase03();
void testCase04();


int main( int argc, char* argv [] )
{
    testCase01();
    testCase02();
    testCase03();
    testCase04();
    return 0;
}

void testCase01() {

    Driver* pDrivers = NULL;
    pDrivers = populateDrivers( "drivers.txt" );

    if ( pDrivers != NULL ) {
        success( __FUNCTION__, TESTED_API,
                 "Driver list file is read" );
    } else {
        failure( __FUNCTION__, TESTED_API,
                 "Driver list file not read" );
    }
}

void testCase02() {

    Driver* pDrivers = NULL;
    pDrivers = populateDrivers( "nonexistent.txt" );

    if ( pDrivers != NULL ) {
        success( __FUNCTION__, TESTED_API,
                 "Driver list is not empty for invalid file" );
    } else {
        failure( __FUNCTION__, TESTED_API,
                 "Driver list is empty for invalid file" );
    }
}

void testCase03() {

    Driver* pDrivers = NULL;
    pDrivers = populateDrivers( NULL );

    if ( pDrivers != NULL ) {
        success( __FUNCTION__, TESTED_API,
                 "Default driver list file is being read" );
    } else {
        failure( __FUNCTION__, TESTED_API,
                 "Default driver list file is not being read" );
    }
}


void testCase04() {

    Driver* pDrivers = NULL;
    int     count    = 0;
    pDrivers = populateDrivers( "drivers.txt" );

    while ( pDrivers != NULL ) {
        printf( "DRIVER: %s, LICENSE: %s", pDrivers->ownerUID,
                pDrivers->licenseNum );
        pDrivers = pDrivers->pNextDriver;
        count++;
    }

    if ( count == 50 ) {
        success( __FUNCTION__, TESTED_API,
                 "Driver list is completely being read" );
    } else {
        failure( __FUNCTION__, TESTED_API,
                 "Driver list is not being completely read" );
    }
}
