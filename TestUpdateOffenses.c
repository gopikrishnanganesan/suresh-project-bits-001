#include <stdio.h>
#include <stdlib.h>
#include "Offense.h"
#include "OffenseOps.h"
#include "TestUtil.h"

#define TESTED_API  "updateOffenses"


void testCase01();

int main( int argc, char* argv [] )
{
    testCase01();
    return 0;
}

void testCase01() {

    Vehicle*    pVehicles   = NULL;
    Driver*     pDrivers    = NULL;
    int         count       = 0;

    pVehicles   = populateVehicles( "owners.txt" );
    if ( pVehicles == NULL ) {
        failure( __FUNCTION__, TESTED_API,
                 "Unable to construct vehicle list. Test populateVehicles" );
    }

    pDrivers    = populateDrivers( "drivers.txt" );
    if ( pDrivers == NULL ) {
        failure( __FUNCTION__, TESTED_API,
                 "Unable to construct driver list. Test populateDrivers" );
    }

    updateOffenses( "offenses.txt", pDrivers, pVehicles );

    if ( pVehicles == NULL ) {
        failure( __FUNCTION__, TESTED_API,
                 "Vehicle list destroyed after updating offense" );
    }

    if ( pDrivers == NULL ) {
        failure( __FUNCTION__, TESTED_API,
                 "Driver list destroyed after updating offense" );
    }

    while ( pDrivers != NULL ) {
        printf( "DRIVER: %s LICENSE: %s SCORE: %d\n", pDrivers->ownerUID,
                pDrivers->licenseNum, pDrivers->score );
        pDrivers = pDrivers->pNext;
        count++;
    }
    if ( count == 50 ) {
        success( __FUNCTION__, TESTED_API,
                 "Score updating success" );
    } else {
        failure( __FUNCTION__, TESTED_API,
                 "Score updation failure" );
    }
}
