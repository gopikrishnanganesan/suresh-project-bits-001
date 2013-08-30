#include <stdio.h>
#include "Offense.h"
#include "OffenseOps.h"

int main( int argc, char* argv[] ) {

    char*       pVehiclesFile   = NULL;
    char*       pDriversFile    = NULL;
    char*       pOffensesFile   = NULL;
    Vehicle*    pVehicles       = NULL;
    Driver*     pDrivers        = NULL;
    RevokeList* pRevoked        = NULL;
    RevokeList* pRunner         = NULL;
    FILE*       pOutputFile     = NULL;

    if ( argc != 4 && argc != 1 ) {
        printf( "Usage: revoke <owners_file> <drivers_file> <offenses_file>\n"
                "  or : revoke\n"
                "where\n"
                "owners_file  : text file with owners & vehicles information\n"
                "drivers_file : text file with owners & licenses information\n"
                "offenses_file: text file with offenses information\n"
                "Note: supplying without any command line arguments will\n"
                "default to owners.txt, drivers.txt and offenses.txt in the\n"
                "current directory. More information could be found in the\n"
                "README.txt file\n" );
    }

    if ( argc == 4 ) {
        pVehiclesFile   = argv[1];
        pDriversFile    = argv[2];
        pOffensesFile   = argv[3];
    }

    pVehicles   = populateVehicles( pVehiclesFile );
    pDrivers    = populateDrivers( pDriversFile );

    if ( pVehicles == NULL || pDrivers == NULL ) {
        perror( "Cannot construct vechicles and drivers list\n" );
        return -1;
    }

    updateOffenses( pOffensesFile, pDrivers, pVehicles );
    pRevoked    = markRevokedDrivers( pDrivers, pVehicles );
    pRunner     = pRevoked;

    pOutputFile = fopen( "revoke.txt", "w" );

    while( pRunner != NULL ) {
        fprintf( pOutputFile, "%s,%s,%s\n", pRunner->ownerUID,
                 pRunner->licenseNum, pRunner->vehicleNum );
        pRunner = pRunner->pNext;
    }

    fclose( pOutputFile );

    return 0;
}
