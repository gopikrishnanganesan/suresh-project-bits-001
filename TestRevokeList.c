#include <stdio.h>
#include <stdlib.h>
#include "Offense.h"
#include "OffenseOps.h"
#include "TestUtil.h"

#define TESTED_API  "markRevokedDrivers"


void testCase01();

int main( int argc, char* argv [] )
{
    testCase01();
    return 0;
}

void testCase01() {

    Vehicle*    pVehicles   = NULL;
    Driver*     pDrivers    = NULL;
    Driver*     pTmpDrvs    = NULL;
    int         count       = 0;
    RevokeList* pRevoked    = NULL;

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

    pTmpDrvs = pDrivers;
    while ( pDrivers != NULL ) {
        printf( "DRIVER: %s LICENSE: %s SCORE: %d\n", pDrivers->ownerUID,
                pDrivers->licenseNum, pDrivers->score );
        pDrivers = pDrivers->pNextDriver;
        count++;
    }
    pDrivers = pTmpDrvs;

    if ( count != 50 ) {
        failure( __FUNCTION__, TESTED_API,
                 "Score updation failure" );
    }

    pRevoked = markRevokedDrivers( pDrivers, pVehicles );
    if ( pRevoked == NULL ) {
        failure( __FUNCTION__, TESTED_API,
                 "Revoke list empty" );
    }

    count = 0;
    while ( pRevoked != NULL ) {
        printf( "REVOKE DRIVER: %s LICENSE: %s VEHICLE: %s\n",
                pRevoked->ownerUID, pRevoked->licenseNum,
                pRevoked->vehicleNum );
        pRevoked = pRevoked->pNext;
        count++;
    }
    success( __FUNCTION__, TESTED_API, "Revoke list passed all tests" );
}
