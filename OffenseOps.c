#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Offense.h"
#include "OffenseOps.h"
#include "HelperUtil.h"
#include "OffenseConfig.h"


Vehicle* populateVehicles( char* apOwnersFile ) {
    char*       pOwnerFile    = NULL;
    char*       pFileBuffer   = NULL;
    char*       pLineBuffer   = NULL;
    char*       pOwnerUID     = NULL;
    char*       pVehicleNum   = NULL;
    Vehicle*    pVehicleList  = NULL;

    pOwnerFile      = apOwnersFile == NULL ? DEFAULT_OWNERS_FILE : apOwnersFile;
    pFileBuffer     = readEntireFile( pOwnerFile );
    if ( pFileBuffer == NULL ) {
        perror( "Vehicle list construction failed" );
        return NULL;
    }

    while ( ( pLineBuffer = strsep( &pFileBuffer, "\n" ) ) != NULL ) {
        if ( isEmptyLine( pLineBuffer ) ) {
            continue;
        }

        pOwnerUID   = strsep( &pLineBuffer, "," );
        pVehicleNum = strsep( &pLineBuffer, "," );

        if ( !validateOwnerUID( pOwnerUID ) ||
             !validateVehicleNum( pVehicleNum ) ) {
            continue;
        }

        pVehicleList = insertVehicle( pVehicleList, pOwnerUID, pVehicleNum );
    }

    free( pFileBuffer );

    return pVehicleList;
}


Driver* populateDrivers( char* apDriversFile ) {
    char*       pDriversFile    = NULL;
    char*       pFileBuffer     = NULL;
    char*       pLineBuffer     = NULL;
    char*       pOwnerUID       = NULL;
    char*       pLicenseNum     = NULL;
    Driver*     pDriversList    = NULL;

    pDriversFile = apDriversFile == NULL ? DEFAULT_DRIVERS_FILE : apDriversFile;
    pFileBuffer  = readEntireFile( pDriversFile );
    if ( pFileBuffer == NULL ) {
        perror( "Drivers list construction failed" );
        return NULL;
    }

    while ( ( pLineBuffer = strsep( &pFileBuffer, "\n" ) ) != NULL ) {
        if ( isEmptyLine( pLineBuffer ) ) {
            continue;
        }

        pOwnerUID   = strsep( &pLineBuffer, "," );
        pLicenseNum = strsep( &pLineBuffer, "," );

        if ( !validateOwnerUID( pOwnerUID ) ||
             !validateLicenseNum( pLicenseNum ) ) {
            continue;
        }

        pDriversList = insertDriver( pDriversList, pOwnerUID, pLicenseNum );
    }

    free( pFileBuffer );

    return pDriversList;
}

void updateOffenses( char*      apOffensesFile,
                     Driver*    apDrivers,
                     Vehicle*   apVehicles ) {
    char*       pOffensesFile       = NULL;
    char*       pFileBuffer         = NULL;
    char*       pLineBuffer         = NULL;
    char*       pVehicleNum         = NULL;
    char*       pOffenseCode        = NULL;
    char*       pOwnerUID           = NULL;
    int         offenseScore        = 0;
    int         retCode             = 0;

    pOffensesFile = apOffensesFile == NULL ? DEFAULT_OFFENSES_FILE : apOffensesFile;
    pFileBuffer   = readEntireFile( pOffensesFile );
    if ( pFileBuffer == NULL ) {
        perror( "Offenses list reading failed" );
        return;
    }

    while ( ( pLineBuffer = strsep( &pFileBuffer, "\n" ) ) != NULL ) {
        if ( isEmptyLine( pLineBuffer ) ) {
            continue;
        }

        pVehicleNum     = strsep( &pLineBuffer, " " );
        pOffenseCode    = strsep( &pLineBuffer, " " );
        offenseScore    = codeToScore( pOffenseCode );

        pOwnerUID       = lookupUID( pVehicleNum, apVehicles );
        if ( pOwnerUID == NULL ) {
            perror( "Cannot update offense, vehicle has no owner" );
            continue;
        }
        retCode         = updateOffense( pOwnerUID, apDrivers, offenseScore );
        if ( retCode == FAILURE ) {
            perror( "Cannot update offense, owner not found with license" );
        }
    }
}

RevokeList* markRevokedDrivers( Driver*     apDrivers,
                                Vehicle*    apVehicles ) {
    RevokeList*     pRevokeList     = NULL;
    Driver*         pRunner         = apDrivers;

    while ( pRunner != NULL ) {
        if ( pRunner->score <= REVOKE_CUTOFF_SCORE ) {
            pRevokeList = insertRevoked( pRevokeList, pRunner, apVehicles );
        }
        pRunner = pRunner->pNext;
    }

    return pRevokeList;
}
