#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Offense.h"
#include "OffenseOps.h"
#include "OffenseConfig.h"


Vehicle*
createVehicle( char*    apOwnerUID,
               char*    apVehicleNum ) {

    Vehicle* pVehicle = ( Vehicle* ) malloc ( sizeof ( Vehicle ) );

    if ( pVehicle == NULL ) {
        perror( "Cannot allocate memory for vehicle" );
        return NULL;
    }

    strcpy( pVehicle->ownerUID , apOwnerUID );
    strcpy( pVehicle->vehicleNum, apVehicleNum );
    pVehicle->pNextVehicle = NULL;

    return pVehicle;
}

Vehicle*
insertVehicle( Vehicle* apVehicles,
               char*    apOwnerUID,
               char*    apVehicleNum ) {
    Vehicle* startNode = apVehicles;
    if ( apVehicles == NULL ) {
        apVehicles = createVehicle( apOwnerUID, apVehicleNum );
        return apVehicles;
    } else {
        // TODO: Ordered Insertion Logic for the linked list
        while ( apVehicles->pNextVehicle != NULL ) {
            apVehicles = apVehicles->pNextVehicle;
        }
        apVehicles->pNextVehicle = createVehicle( apOwnerUID, apVehicleNum );
        return startNode;
    }
}

Driver*
insertDriver( Driver*   apDrivers,
              char*     apOwnerUID,
              char*     apLicenseNum ) {
    Driver* startNode = apDrivers;
    if ( apDrivers == NULL ) {
        apDrivers = createDriver( apOwnerUID, apLicenseNum );
        return apDrivers;
    } else {
        // TODO: Ordered Insertion Logic for the linked list;
        while ( apDrivers->pNextDriver != NULL ) {
            apDrivers = apDrivers->pNextDriver;
        }
        apDrivers->pNextDriver = createDriver( apOwnerUID, apLicenseNum );
        return startNode;
    }
}

Driver*
createDriver( char*     apOwnerUID,
              char*     apLicenseNum ) {
    Driver* pDriver = ( Driver* ) malloc ( sizeof ( Driver ) );

    if ( pDriver == NULL ) {
        perror( "Cannot allocate memory for driver" );
        return NULL;
    }
    strcpy( pDriver->ownerUID , apOwnerUID );
    strcpy( pDriver->licenseNum, apLicenseNum );
    pDriver->score          = INITIAL_DRIVER_SCORE;
    pDriver->pNextDriver    = NULL;

    return pDriver;
}

char*
lookupUID( char*    apVehicleNum,
           Vehicle* apVehicles ) {
    Vehicle* pRunner    = apVehicles;
    if ( apVehicles == NULL || apVehicleNum == NULL ) {
        return NULL;
    }
    while ( pRunner != NULL ) {
        if ( strcmp( apVehicleNum, pRunner->vehicleNum ) == 0 ) {
            return pRunner->ownerUID;
        }
        pRunner = pRunner->pNextVehicle;
    }
    return NULL;
}

char*
lookupVehicle( char*    apOwnerUID,
               Vehicle* apVehicles ) {
    Vehicle* pRunner    = apVehicles;
    if ( apVehicles == NULL || apOwnerUID == NULL ) {
        return NULL;
    }
    while ( pRunner != NULL ) {
        if ( strcmp( apOwnerUID, pRunner->ownerUID ) == 0 ) {
            return pRunner->ownerUID;
        }
        pRunner = pRunner->pNextVehicle;
    }
    return NULL;
}


int updateOffense( char*    apOwnerUID,
                   Driver*  apDrivers,
                   int      aOffenseScore ) {
    Driver* pRunner     = apDrivers;
    if ( apOwnerUID == NULL || apDrivers == NULL ) {
        return FAILURE;
    }
    while ( pRunner != NULL ) {
        if ( strcmp( apOwnerUID, pRunner->ownerUID ) == 0 ) {
            pRunner->score = pRunner->score + aOffenseScore;
            return SUCCESS;
        }
        pRunner = pRunner->pNextDriver;
    }
    return FAILURE;
}

RevokeList*
insertRevoked( RevokeList*  apRevokeList,
               Driver*      apDriver,
               Vehicle*     apVehicles ) {
    RevokeList* startNode = apRevokeList;

    if ( apDriver == NULL || apVehicles == NULL ) {
        return apRevokeList;
    }

    if ( apRevokeList == NULL ) {
        apRevokeList = createRevoked( apDriver, apVehicles );
        return apRevokeList;
    } else {
        while ( apRevokeList->pNext != NULL ) {
            apRevokeList = apRevokeList->pNext;
        }
        apRevokeList->pNext = createRevoked( apDriver, apVehicles );
    }

    return startNode;
}

RevokeList*
createRevoked( Driver*      apDriver,
               Vehicle*     apVehicles ) {
    RevokeList* pRevoked = ( RevokeList* ) malloc ( sizeof ( RevokeList ) );
    if ( pRevoked == NULL ) {
        perror( "Cannot allocate memory for revoked list" );
        return NULL;
    }

    strcpy( pRevoked->ownerUID, apDriver->ownerUID );
    strcpy( pRevoked->licenseNum, apDriver->licenseNum );
    strcpy( pRevoked->vehicleNum,
            lookupVehicle( apDriver->ownerUID, apVehicles ) );

    return pRevoked;
}

