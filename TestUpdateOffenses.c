#include <stdio.h>
#include <stdlib.h>
#include "Offense.h"
#include "OffenseOps.h"

#define TESTED_API  "populateVehicles"


void testCase01();
void testCase02();
void testCase03();


int main( int argc, char* argv [] )
{
    testCase01();
    testCase02();
    testCase03();
    return 0;
}

void testCase01() {
    Vehicle* pVehicles = NULL;
    pVehicles = populateVehicles( "owners.txt" );
    if ( pVehicles == NULL ) {
        printf( "%s on %s Failed. Vehicle list is empty for valid file\n",
                __FUNCTION__, TESTED_API );
    } else {
        printf( "%s on %s Passed. Vehicle list is not empty for valid file\n",
                __FUNCTION__, TESTED_API );
    }
}

void testCase02() {
    Vehicle* pVehicles = NULL;
    pVehicles = populateVehicles( "nonexistent.txt" );
    if ( pVehicles != NULL ) {
        printf( "%s on %s Failed. Vehicle list is not empty for invalid file\n",
                __FUNCTION__, TESTED_API );
    } else {
        printf( "%s on %s Passed. Vehicle list is empty for invalid file\n",
                __FUNCTION__, TESTED_API );
    }
}

void testCase03() {
    Vehicle* pVehicles = NULL;
    pVehicles = populateVehicles( NULL );
    if ( pVehicles == NULL ) {
        printf( "%s on %s Failed. Default file being read correctly\n",
                __FUNCTION__, TESTED_API );
    } else {
        printf( "%s on %s Passed. Default file is not being read correctly\n",
                __FUNCTION__, TESTED_API );
    }
}
