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
    Vehicle*    pTmpVehcls  = NULL;
    Driver*     pDrivers    = NULL;
    Driver*     pTmpDrvs    = NULL;
    int         count       = 0;
    RevokeList* pRevoked    = NULL;

    pVehicles   = populateVehicles( "owners.txt" );
    if ( pVehicles == NULL ) {
        failure( __FUNCTION__, TESTED_API,
                 "Unable to construct vehicle list. Test populateVehicles" );
    }

    pTmpVehcls = pVehicles;
    printf( "OWNERS LIST:\n===========\n" );
    while ( pTmpVehcls != NULL  ) {
        printf( "DRIVER: %s VEHICLE: %s\n", pTmpVehcls->ownerUID,
                pTmpVehcls->vehicleNum );
        pTmpVehcls = pTmpVehcls->pNextVehicle;
    }
    pTmpVehcls = pVehicles;

    pDrivers    = populateDrivers( "drivers.txt" );
    if ( pDrivers == NULL ) {
        failure( __FUNCTION__, TESTED_API,
                 "Unable to construct driver list. Test populateDrivers" );
    }

    pTmpDrvs = pDrivers;
    count    = 0;
    printf( "INITIAL SCORE LIST:\n==================\n" );
    while ( pTmpDrvs != NULL ) {
        printf( "DRIVER: %s LICENSE: %s SCORE: %d\n", pTmpDrvs->ownerUID,
                pTmpDrvs->licenseNum, pTmpDrvs->score );
        pTmpDrvs = pTmpDrvs->pNextDriver;
        count++;
    }
    pTmpDrvs = pDrivers;

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
    count    = 0;
    printf( "SCORE AFTER OFFENSE:\n===================\n" );
    while ( pTmpDrvs != NULL ) {
        printf( "DRIVER: %s LICENSE: %s SCORE: %d\n", pTmpDrvs->ownerUID,
                pTmpDrvs->licenseNum, pTmpDrvs->score );
        pTmpDrvs = pTmpDrvs->pNextDriver;
        count++;
    }
    pTmpDrvs = pDrivers;

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
    printf( "REVOKE LIST:\n===========\n" );
    while ( pRevoked != NULL ) {
        printf( "REVOKE DRIVER: %s LICENSE: %s VEHICLE: %s\n",
                pRevoked->ownerUID, pRevoked->licenseNum,
                pRevoked->vehicleNum );
        pRevoked = pRevoked->pNext;
        count++;
    }
    success( __FUNCTION__, TESTED_API, "Revoke list passed all tests" );
}
