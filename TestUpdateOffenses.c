#include <stdio.h>
#include <stdlib.h>
#include "Offense.h"
#include "OffenseOps.h"
#include "TestUtil.h"

#define TESTED_API  "updateOffenses"


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
    Vehicle* pVehicles = NULL;
    pVehicles = populateVehicles( "owners.txt" );
    if ( pVehicles == NULL ) {
        printf( "==>%s on %s Failed. Vehicle list is empty for valid file\n",
                __FUNCTION__, TESTED_API );
    } else {
        printf( "==>%s on %s Passed. Vehicle list is not empty for valid file\n",
                __FUNCTION__, TESTED_API );
    }
}

void testCase02() {
    Vehicle* pVehicles = NULL;
    pVehicles = populateVehicles( "nonexistent.txt" );
    if ( pVehicles != NULL ) {
        printf( "==>%s on %s Failed. Vehicle list is not empty for invalid file\n",
                __FUNCTION__, TESTED_API );
    } else {
        printf( "==>%s on %s Passed. Vehicle list is empty for invalid file\n",
                __FUNCTION__, TESTED_API );
    }
}

void testCase03() {
    Vehicle* pVehicles = NULL;
    pVehicles = populateVehicles( NULL );
    if ( pVehicles == NULL ) {
        printf( "==>%s on %s Failed. Default file being read correctly\n",
                __FUNCTION__, TESTED_API );
    } else {
        printf( "==>%s on %s Passed. Default file is not being read correctly\n",
                __FUNCTION__, TESTED_API );
    }
}


void testCase04() {
    Vehicle* pVehicles = NULL;
    int      count     = 0;
    pVehicles = populateVehicles( "owners.txt" );
    while ( pVehicles != NULL ) {
        printf( "OWNER: %s, VEHICLE: %s\n", pVehicles->ownerUID,
                pVehicles->vehicleNum );
        pVehicles = pVehicles->pNextVehicle;
        count++;
    }
    if ( count != 50 ) {
        printf( "==>%s on %s Failed. Vehicle file is not read completely\n",
                __FUNCTION__, TESTED_API );
    } else {
        printf( "==>%s on %s Passed. Vehicle file is read completely\n",
                __FUNCTION__, TESTED_API );
    }

}
