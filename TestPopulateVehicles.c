/**
 * File     : TestPopulateVehicles.c
 * Type     : Internal Unit Test
 * Comment  : Test case for populateVehicles API
 */
#include <stdio.h>
#include <stdlib.h>
#include "Offense.h"
#include "OffenseOps.h"
#include "TestUtil.h"

#define TESTED_API  "populateVehicles"

void testCase01();
void testCase02();
void testCase03();
void testCase04();

int main() {
    testCase01();
    testCase02();
    testCase03();
    testCase04();
    return 0;
}

void testCase01() {

    Vehicle* pVehicles = NULL;
    pVehicles = populateVehicles( "owner.txt" );

    if ( pVehicles != NULL ) {
        success( __FUNCTION__, TESTED_API,
                 "Vehicle list file is read" );
    } else {
        failure( __FUNCTION__, TESTED_API,
                 "Vehicle list file not read" );
    }

    freeVehicleList( pVehicles );

}

void testCase02() {

    Vehicle* pVehicles = NULL;
    pVehicles = populateVehicles( "nonexistent.txt" );

    if ( pVehicles == NULL ) {
        success( __FUNCTION__, TESTED_API,
                 "Vehicle list empty for an invalid file" );
    } else {
        failure( __FUNCTION__, TESTED_API,
                 "Vehicle list not empty for an invalid file" );
    }

    freeVehicleList( pVehicles );
}

void testCase03() {

    Vehicle* pVehicles = NULL;
    pVehicles = populateVehicles( NULL );

    if ( pVehicles != NULL ) {
        success( __FUNCTION__, TESTED_API,
                 "Default vehicle list file is being read" );
    } else {
        failure( __FUNCTION__, TESTED_API,
                 "Default vehicle list file is not being read" );
    }

    freeVehicleList( pVehicles );
}


void testCase04() {

    Vehicle* pVehicles = NULL;
    int      count     = 0;
    pVehicles = populateVehicles( "owner.txt" );

    while ( pVehicles != NULL ) {
        printf( "OWNER: %s, VEHICLE: %s\n", pVehicles->ownerUID,
                pVehicles->vehicleNum );
        pVehicles = pVehicles->pNext;
        count++;
    }

    if ( count == 50 ) {
        success( __FUNCTION__, TESTED_API,
                 "Vehicle list file is being read completely" );
    } else {
        failure( __FUNCTION__, TESTED_API,
                 "Vehicle list file was not read completely" );
    }

    freeVehicleList( pVehicles );
}
